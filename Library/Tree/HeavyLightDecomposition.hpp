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
    HeavyLightDecomposition(Graph<CostType> &tree, Vertex r = 0) :
        T(tree), parent(CalculateTreeParent(tree, r)), child(RootedTreeAdjacentList(tree, r)), n((int)tree.VertexSize()), euler_tour_(n), rev_order_(n), depth_(CalculateTreeDepth(tree, r)), belong_hp_id_(n){
        vector<int> ss = CalculateSubtreeSize(T, r);
        for(int i = 0; i < n; ++i){
            if(child[i].empty()) continue;
            // cerr << "# i = " << i << endl;
            // cerr << "#   (old) -> " << child[i] << endl;
            nth_element(child[i].begin(), child[i].begin() + 1, child[i].end(), [&](Vertex i, Vertex j){
                return ss[i] > ss[j];
            });
            // cerr << "#   (new) -> " << child[i] << endl;
        }
        hp_head_.push_back(r);
        hp_depth_.push_back(0);
        belong_hp_id_[r] = 0;
        timer_ = 0;
        dfs(r, 0, 0);

        // debug ---
        // vector<vector<Vertex>> hp(hp_head_.size());
        // for(int i = 0; i < n; ++i){
        //     hp[belong_hp_id_[i]].push_back(i);
        // }
        // for(int i = 0; i < hp_head_.size(); ++i){
        //     sort(hp[i].begin(), hp[i].end(), [&](int x, int y){
        //         return euler_tour_[x].first < euler_tour_[y].first;
        //     });
        //     cerr << "# Heavy Path " << i << " = [";
        //     for(int j = 0; j < hp[i].size(); ++j){
        //         cerr << hp[i][j] << ",]"[j + 1 == hp[i].size()] << ' ';
        //     }
        //     cerr << endl;
        // }
        // ---------
    }

    Vertex LowestCommonAncestor(Vertex u, Vertex v) const {
        if(PathDepth(u) < PathDepth(v)) swap(u, v);
        while(PathDepth(u) != PathDepth(v)){
            u = parent[Head(u)];
        }
        while(Belong(u) != Belong(v)){
            u = parent[Head(u)];
            v = parent[Head(v)];
        }
        return depth_[u] < depth_[v] ? u : v;
    }

    /**
     * @brief 頂点 `v` の祖先であって、深さが `level` である頂点を返す。
     * @note そのような頂点が存在しないとき、`-1` を返す。
     * @param v 頂点番号 (0-index)
     * @param level 深さ (0-index)
     * @return Vertex 答えとなる頂点 (または `-1`)
     */
    Vertex LevelAncestor(Vertex v, int level){
        if(level < 0 || depth_[v] < level) return -1;
        Vertex u = Head(v);
        while(1){
            if(depth_[u] <= level){
                int delta = level - depth_[u];
                return RevOrder(PreOrder(u) + delta);
            }
            u = parent[u];
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
        int dist_from_lca = depth_[from] - depth_[lca];
        int dist_lca_to = depth_[to] - depth_[lca];
        if(dist < 0 or dist > dist_from_lca + dist_lca_to) return -1;
        if(dist <= dist_from_lca){
            return LevelAncestor(from, depth_[from] - dist);
        }
        else{
            return LevelAncestor(to, depth_[lca] + dist - dist_from_lca);
        }
    }

    /**
     * @brief 頂点 `from` から頂点 `to` へのパスを分解した結果を返す。
     * @note 可逆性のないクエリに対しても対応。詳しくは `PathSegment` の `reverse` を参照。
     * @param from 始点の頂点番号 (0-index)
     * @param to 終点の頂点番号 (0-index)
     * @return vector<PathSegment> 分解した結果
     */
    vector<PathSegment> PathQuery(Vertex u, Vertex v){
        vector<PathSegment> ret;
        Vertex lca = LowestCommonAncestor(u, v);
        while(Belong(u) != Belong(lca)){
            PathSegment path;
            Vertex h = Head(u);
            path.head_vertex = h, path.tail_vertex = u;
            path.head_index = PreOrder(h), path.tail_index = PreOrder(u) + 1;
            path.highest = false, path.reverse = true;
            ret.push_back(path);
            u = parent[h];
        }
        if(u != lca){
            PathSegment path;
            path.head_vertex = lca, path.tail_vertex = u;
            path.head_index = PreOrder(lca), path.tail_index = PreOrder(u) + 1;
            path.highest = true, path.reverse = true;
            ret.push_back(path);
        }
        int size = ret.size();
        while(Belong(v) != Belong(lca)){
            PathSegment path;
            Vertex h = Head(v);
            path.head_vertex = h, path.tail_vertex = v;
            path.head_index = PreOrder(h), path.tail_index = PreOrder(v) + 1;
            path.highest = false, path.reverse = false;
            ret.push_back(path);
            v = parent[h];
        }
        if(v != lca){
            PathSegment path;
            path.head_vertex = lca, path.tail_vertex = v;
            path.head_index = PreOrder(lca), path.tail_index = PreOrder(v) + 1;
            path.highest = true, path.reverse = false;
            ret.push_back(path);
        }
        if(u == lca && v == lca){
            PathSegment path;
            path.head_vertex = path.tail_vertex = lca;
            path.head_index = PreOrder(lca), path.tail_index = PreOrder(lca) + 1;
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
        return euler_tour_[v];
    }

    /**
     * @brief 頂点 `i` に載せるデータを格納した配列 `data[i]` を、頂点の行きかけ順になるように並べ替える。
     * @note セグメント木などに載せる前に使用する。
     * @param data 各頂点に載せるデータ
     */
    template<typename T>
    void SortVertex(vector<T> &A){
        assert(A.size() == n);
        vector<T> sub(n);
        for(int i = 0; i < n; ++i){
            sub[PreOrder(i)] = A[i];
        }
        swap(A, sub);
    }

    int operator[](Vertex v){
        return PreOrder(v);
    }

    const int operator[](Vertex v) const {
        return PreOrder(v);
    }

    private:
    int dfs(Vertex v, int h, int d){
        // cerr << "# v = " << v << endl;
        euler_tour_[v].first = timer_;
        rev_order_[timer_] = v;
        ++timer_;
        int ret = timer_;
        if(!child[v].empty()){
            int c = child[v].size();
            belong_hp_id_[child[v].front()] = h;
            ret = max(ret, dfs(child[v].front(), h, d));
            for(int i = 1; i < c; ++i){
                int nh = (int)hp_head_.size();
                hp_head_.push_back(child[v][i]);
                hp_depth_.push_back(d + 1);
                belong_hp_id_[child[v][i]] = nh;
                ret = max(ret, dfs(child[v][i], nh, d + 1));
            }
        }
        euler_tour_[v].second = ret;
        // cerr << "# Euler Tour of " << v << " -> [" << euler_tour_[v].first << ", " << euler_tour_[v].second << ")" << endl;
        return ret;
    }

    Vertex Head(Vertex v) const {
        return hp_head_[belong_hp_id_[v]];
    }

    int PathDepth(Vertex v) const {
        return hp_depth_[belong_hp_id_[v]];
    }

    int Belong(Vertex v) const {
        return belong_hp_id_[v];
    }

    Vertex RevOrder(int idx) const {
        return rev_order_[idx];
    }

    int PreOrder(Vertex v) const {
        return euler_tour_[v].first;
    }

    int PostOrder(Vertex v) const {
        return euler_tour_[v].second;
    }

    Graph<CostType> &T;
    vector<Vertex> parent;
    vector<vector<Vertex>> child;
    int n, timer_;

    vector<pair<int, int>> euler_tour_;
    vector<Vertex> rev_order_;
    vector<int> depth_;

    vector<Vertex> hp_head_; // 各 heavy path の最も根に近い頂点
    vector<int> hp_depth_; // 各 heavy path の深さ
    vector<int> belong_hp_id_; // 各頂点が属する heavy path の番号
    vector<int> belong_heavy_path_order_;
};