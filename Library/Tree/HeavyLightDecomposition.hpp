/**
 * @file HeavyLightDecomposition.hpp
 * @author log K (lX57)
 * @brief Heavy Light Decomposition - HL分解
 * @version 4.0
 * @date 2024-09-04
 */

#include "Tree.hpp"

struct PathSegment{
    PathSegment() = default;
    Vertex head_vertex; // `head_vertex` : パスの最も根に近い頂点の頂点番号
    Vertex tail_vertex; // `tail_vertex` : パスの最も葉に近い頂点の頂点番号
    int head_index; // `head_index` : `head_vertex` の行きかけ順のインデックス番号 (0-index, 半開区間)
    int tail_index; // `tail_index` : `tail_vertex` の行きかけ順のインデックス番号 (0-index, 半開区間)
    bool highest; // この `PathSegment` が最も根に近い(つまり LCA を含んでいる)パスであることを表す。辺属性のクエリで LCA を除くために使用。
    bool reverse; // クエリで投げた `from -> to` に対して、`from` 側が `tail_vertex` であることを表す。可逆性のないクエリで使用。
    friend ostream &operator<<(ostream &os, const PathSegment &p){
        return os << "# Path (" << p.head_vertex << " -> " << p.tail_vertex << ", " << p.head_index << " -> " << p.tail_index << ", " << boolalpha << p.highest << ", " << p.reverse << ")";
    }
};

template<typename CostType>
class HeavyLightDecomposition{
    public:
    HeavyLightDecomposition(RootedTree<CostType> &tree) : tree_(tree){
        vertex_size_ = tree_.get_vertex_size();
        vector<int> subtree_size = CalculateSubtreeSize(tree_);
        vertex_depth_ = CalculateTreeDepth(tree_);
        for(int i = 0; i < vertex_size_; ++i){
            auto &children = tree_.get_child(i);
            nth_element(children.begin(), children.begin(), children.end(), [&](Vertex i, Vertex j){
                return subtree_size[i] > subtree_size[j];
            });
        }
        Vertex root = tree_.get_root();
        heavy_path_head_.push_back(root);
        heavy_path_depth_.push_back(0);
        belong_heavy_path_index_.resize(vertex_size_, -1);
        belong_heavy_path_index_[root] = 0;
        preorder_index_.resize(vertex_size_, -1);
        postorder_index_.resize(vertex_size_, -1);
        vertex_order_.resize(vertex_size_);
        int timer = 0;
        dfs(root, 0, 0, timer);
    }

    /**
     * @brief 頂点 `u` と頂点 `v` の最小共通祖先を返す。
     * @param u 頂点番号 (0-index)
     * @param v 頂点番号 (0-index)
     * @return Vertex 最小共通祖先の頂点番号 (0-index)
     */
    Vertex LowestCommonAncestor(Vertex u, Vertex v){
        if(path_depth(u) < path_depth(v)) swap(u, v);
        while(path_depth(u) != path_depth(v)){
            u = tree_.get_parent(head(u));
        }
        while(belong(u) != belong(v)){
            u = tree_.get_parent(head(u));
            v = tree_.get_parent(head(v));
        }
        return vertex_depth(u) < vertex_depth(v) ? u : v;
    }

    /**
     * @brief 頂点 `v` の祖先であって、深さが `level` である頂点を返す。
     * @note そのような頂点が存在しないとき、`-1` を返す。
     * @param v 頂点番号 (0-index)
     * @param level 深さ (0-index)
     * @return Vertex 答えとなる頂点 (または `-1`)
     */
    Vertex LevelAncestor(Vertex v, int level){
        if(level < 0 || vertex_depth(v) < level) return -1;
        Vertex u = head(v);
        while(1){
            if(vertex_depth(u) <= level){
                int delta = level - vertex_depth(u);
                return order(preorder(u) + delta);
            }
            u = tree_.get_parent(u);
        }
    }

    /**
     * @brief 頂点 `from` から頂点 `to` への最短路において、`from` から `dist` 個移動した頂点番号を求める。
     * @note 最短路の長さを `k` として、`dist < 0` または `k < dist` のとき `-1` を返す。
     * @param from 始点の頂点番号 (0-index)
     * @param to 終点の頂点番号 (0-index)
     * @param dist 移動する頂点数
     * @return Vertex 答えの頂点番号 (0-index) または `-1`
     */
    Vertex Jump(Vertex from, Vertex to, int dist){
        Vertex lca = LowestCommonAncestor(from, to);
        int dist_from_lca = vertex_depth(from) - vertex_depth(lca);
        int dist_lca_to = vertex_depth(to) - vertex_depth(lca);
        if(dist < 0 or dist > dist_from_lca + dist_lca_to) return -1;
        if(dist <= dist_from_lca){
            return LevelAncestor(from, vertex_depth(from) - dist);
        }
        else{
            return LevelAncestor(to, vertex_depth(lca) + dist - dist_from_lca);
        }
    }

    /**
     * @brief 頂点 `from` から頂点 `to` へのパスを分解した結果を返す。
     * @note 可逆性のないクエリに対しても対応。詳しくは `PathSegment` の `reverse` を参照。
     * @param from 始点の頂点番号 (0-index)
     * @param to 終点の頂点番号 (0-index)
     * @return vector<PathSegment> 分解した結果
     */
    vector<PathSegment> PathQuery(Vertex from, Vertex to){
        vector<PathSegment> ret;
        Vertex lca = LowestCommonAncestor(from, to);
        while(belong(from) != belong(lca)){
            PathSegment path;
            Vertex h = head(from);
            path.head_vertex = h, path.tail_vertex = from;
            path.head_index = preorder(h), path.tail_index = preorder(from) + 1;
            path.highest = false, path.reverse = true;
            ret.push_back(path);
            from = tree_.get_parent(h);
        }
        if(from != lca){
            PathSegment path;
            path.head_vertex = lca, path.tail_vertex = from;
            path.head_index = preorder(lca), path.tail_index = preorder(from) + 1;
            path.highest = true, path.reverse = true;
            ret.push_back(path);
        }
        int size = ret.size();
        while(belong(to) != belong(lca)){
            PathSegment path;
            Vertex h = head(to);
            path.head_vertex = h, path.tail_vertex = to;
            path.head_index = preorder(h), path.tail_index = preorder(to) + 1;
            path.highest = false, path.reverse = false;
            ret.push_back(path);
            to = tree_.get_parent(h);
        }
        if(to != lca){
            PathSegment path;
            path.head_vertex = lca, path.tail_vertex = to;
            path.head_index = preorder(lca), path.tail_index = preorder(to) + 1;
            path.highest = true, path.reverse = false;
            ret.push_back(path);
        }
        if(from == lca && to == lca){
            PathSegment path;
            path.head_vertex = path.tail_vertex = lca;
            path.head_index = preorder(lca), path.tail_index = preorder(lca) + 1;
            path.highest = true, path.reverse = false;
            ret.push_back(path);
        }
        reverse(ret.begin() + size, ret.end());
        return ret;
    }

    /**
     * @brief 頂点 `v` を根とする部分木に対応したインデックスを半開区間で返す。
     * @param v 頂点番号 (0-index)
     * @return pair<int, int> インデックス (0-index, 半開区間)
     */
    pair<int, int> SubtreeQuery(Vertex v) const {
        return make_pair(preorder(v), postorder(v) + 1);
    }

    /**
     * @brief 頂点 `i` に載せるデータを格納した配列 `data[i]` を、頂点の行きかけ順になるように並べ替える。
     * @note セグメント木などに載せる前に使用する。
     * @param data 各頂点に載せるデータ
     */
    template<typename T>
    void SortVertex(vector<T> &data){
        assert(data.size() == vertex_size_);
        vector<T> sub(data.size());
        for(int i = 0; i < vertex_size_; ++i){
            sub[preorder(i)] = data[i];
        }
        swap(data, sub);
    }

    int operator[](Vertex v){
        return preorder(v);
    }

    const int operator[](Vertex v) const {
        return preorder(v);
    }

    private:
    int dfs(Vertex v, int h, int d, int &t){
        preorder_index_[v] = t;
        vertex_order_[t] = v;
        int ret = t;
        ++t;
        auto cs = tree_.get_child(v);
        if(!cs.empty()){
            int c = cs.size();
            belong_heavy_path_index_[cs.front()] = h;
            ret = max(ret, dfs(cs.front(), h, d, t));
            for(int i = 1; i < c; ++i){
                int nh = (int)heavy_path_head_.size();
                heavy_path_head_.push_back(cs[i]);
                heavy_path_depth_.push_back(d + 1);
                belong_heavy_path_index_[cs[i]] = nh;
                ret = max(ret, dfs(cs[i], nh, d + 1, t));
            }
        }
        postorder_index_[v] = ret;
        return ret;
    }

    Vertex head(Vertex v) const {
        return heavy_path_head_[belong_heavy_path_index_[v]];
    }

    int path_depth(Vertex v) const {
        return heavy_path_depth_[belong_heavy_path_index_[v]];
    }

    int vertex_depth(Vertex v) const {
        return vertex_depth_[v];
    }

    int belong(Vertex v) const {
        return belong_heavy_path_index_[v];
    }

    Vertex order(int idx) const {
        return vertex_order_[idx];
    }

    int preorder(Vertex v) const {
        return preorder_index_[v];
    }

    int postorder(Vertex v) const {
        return postorder_index_[v];
    }

    RootedTree<CostType> &tree_;

    int vertex_size_;
    vector<Vertex> heavy_path_head_, vertex_order_;
    vector<int> belong_heavy_path_index_, belong_heavy_path_order_, heavy_path_depth_;
    vector<int> preorder_index_, postorder_index_;
    vector<int> vertex_depth_;
};