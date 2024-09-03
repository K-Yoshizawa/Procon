#pragma once

/**
 * @file Tree.hpp
 * @brief Tree - 木テンプレート
 * @version 1.0
 * @date 2024-09-02
 */

#include "../Common.hpp"

using Vertex = int;

template<typename CostType = int32_t>
class RootedTree{
    public:
    struct Node{
        Node(Vertex parent = -1) : parent(parent){}

        Vertex parent{-1};
        CostType cost{};
        vector<Vertex> children{};
    };

    /**
     * @brief 頂点 `root_vertex` を根とする頂点数 `vertex_size` の根付き木を構築する。
     * @note 根が入力で与えられなれないが後で分かる、みたいな状況の時は `root_vertex = -1` とするとよい
     * @param vertex_size 頂点数
     * @param root_vertex 根とする頂点 (default = 0)
     */
    RootedTree(int vertex_size, Vertex root_vertex = 0) :
            vertex_size_(vertex_size), root_vertex_(root_vertex),
            node_(vertex_size){}

    /**
     * @brief 木の頂点数を返す。
     * @return int 木の頂点数
     */
    int get_vertex_size() const {
        return vertex_size_;
    }

    /**
     * @brief 木の根の頂点を返す。
     * @return Vertex 木の根の頂点番号 (0-index)
     */
    Vertex get_root() const {
        return root_vertex_;
    }

    /**
     * @brief 頂点 `v` の親の頂点番号を返す。
     * @note `v` が根の場合、`-1` が返される。
     * @param v 子の頂点番号 (0-index)
     * @return Vertex 親の頂点番号 (0-index)
     */
    Vertex get_parent(Vertex v) const {
        Validate(v);
        return node_[v].parent;
    }

    /**
     * @brief 頂点 `v` の子の頂点番号列を返す。
     * @note 頂点番号列は入力順に返される。
     * @param v 親の頂点番号 (0-index)
     * @return vector<Vertex> 子の頂点番号列 (0-index)
     */
    vector<Vertex> &get_child(Vertex v){
        Validate(v);
        return node_[v].children;
    }

    /**
     * @brief 頂点 `v` とその親を結ぶ辺の重みを返す。
     * @attention `v` が根の場合の返り値は未定義である。
     * @param v 頂点番号 (0-index)
     * @return CostType 辺の重み
     */
    CostType get_cost(Vertex v){
        Validate(v);
        return node_[v].cost;
    }

    /**
     * @brief 頂点 `parent` から頂点 `child` への重さ `cost` の辺を張る。
     * @note `cost` を省略することで重みなし辺を張ることができる。
     * @param parent 親の頂点番号 (0-index)
     * @param child 子の頂点番号 (0-index)
     * @param cost 辺の重み (default = 1)
     */
    void AddEdge(Vertex parent, Vertex child, CostType cost = 1){
        Validate(parent);
        Validate(child);
        node_[parent].children.push_back(child);
        node_[child].parent = parent;
        node_[child].cost = cost;
    }

    /**
     * @brief `u v w` のような入力形式を受け取る。
     * @param weighted 重み付きの木であるか (default = true)
     * @param one_index 入力される頂点番号が 1-index かどうか (default = true)
     */
    void InputGraphFormat(bool weighted = true, bool one_index = true){
        vector<vector<pair<Vertex, CostType>>> graph(vertex_size_);
        for(int i = 0; i < vertex_size_ - 1; ++i){
            int u, v; cin >> u >> v;
            if(one_index) --u, --v;
            CostType w = 1;
            if(weighted) cin >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        auto rec = [&](auto self, Vertex v, Vertex p) -> void {
            for(auto [u, w] : graph[v]){
                if(u == p) continue;
                AddEdge(v, u, w);
                self(self, u, v);
            }
        };
        rec(rec, root_vertex_, -1);
    }

    /**
     * @brief `p_1 p_2 ... p_N` のような入力形式を受け取る。
     * @attention weighted の処理を書いていないので、`weighted` のパラメータに意味はない
     * @param weighted 重み付きの木であるか (default = true)
     * @param one_index 入力される頂点番号が 1-index かどうか (default = true)
     */
    void InputRootedTreeFormat(bool weighted = true, bool one_index = true){
        assert(root_vertex_ == 0);
        for(int i = 1; i < vertex_size_; ++i){
            int p; cin >> p;
            if(one_index) --p;
            AddEdge(p, i);
        }
    }

    /**
     * @brief 頂点 `v` が根の頂点か判定する。
     * @param v 判定する頂点番号 (0-index)
     */
    bool RootVertex(Vertex v){
        Validate(v);
        return node_[v].parent == -1;
    }
    
    /**
     * @brief 頂点 `v` が葉の頂点か判定する。
     * @param v 判定する頂点番号 (0-index)
     */
    bool LeafVertex(Vertex v){
        Validate(v);
        return node_[v].children.empty();
    }

    /**
     * @brief 木の根の頂点を求める。
     * @attention 基本的には不要で、根の頂点番号が与えられていない場合に用いる。
     * @note Verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A
     * @return Vertex 根の頂点番号
     */
    Vertex FindRoot(){
        for(int i = 0; i < vertex_size_; ++i){
            if(RootVertex(i)){
                root_vertex_ = i;
                return i;
            }
        }
        assert(false);
    }

    /**
     * @brief 木の根を変更して再構築する。
     * @param root 新しい根の頂点番号 (0-index)
     */
    void Rerooting(Vertex root){
        if(root == root_vertex_) return;
        vector<Node> new_node_(vertex_size_);
        auto rec = [&](auto self, Vertex v, Vertex p, CostType c) -> void {
            new_node_[v].parent = p;
            new_node_[v].cost = c;
            if(node_[v].parent != p && node_[v].parent != -1){
                new_node_[v].children.push_back(node_[v].parent);
                self(self, node_[v].parent, v, node_[v].cost);
            }
            for(Vertex u : node_[v].children){
                if(u != p){
                    new_node_[v].children.push_back(u);
                    self(self, u, v, node_[u].cost);
                }
            }
        };
        rec(rec, root, -1, 0);
        swap(new_node_, node_);
        root_vertex_ = root;
    }

    void Print(bool one_index = true) const {
        for(int i = 0; i < vertex_size_; ++i){
            // fprintf(stderr, "# Vertex %d : parent = %d (cost = %d), children = [", i + int(one_index), get_parent(i) + int(one_index), node_[i].cost);
            fprintf(stderr, "# Vertex %d : parent = %d (cost = ", i + int(one_index), get_parent(i) + int(one_index));
            cerr << node_[i].cost;
            fprintf(stderr, "), children = [");
            for(int j = 0; j < node_[i].children.size(); ++j){
                fprintf(stderr, "%d", node_[i].children[j]);
                if(j + 1 < node_[i].children.size()){
                    fprintf(stderr, ", ");
                }
            }
            fprintf(stderr, "]\n");
        }
    }

    private:
    inline void Validate(Vertex v) const {
        assert(0 <= v && v < vertex_size_);
    }

    int vertex_size_, root_vertex_{-1};
    vector<Node> node_;
};

/**
 * @brief 木 `tree` の各頂点の深さを求める。
 * @note 根の頂点は深さ 0 である。
 * @note Verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A
 * @param tree 木
 * @param root 根の頂点番号 (default = 0)
 * @return vector<int> 各頂点の深さ
 */
template<typename CostType>
vector<int> CalculateTreeDepth(RootedTree<CostType> &tree){
    int V = tree.get_vertex_size();
    vector<int> ret(V, 0);
    auto rec = [&](auto self, Vertex v, int d) -> void {
        ret[v] = d;
        for(Vertex u : tree.get_child(v)){
            self(self, u, d + 1);
        }
    };
    Vertex root = tree.get_root();
    if(root < 0) root = tree.FindRoot();
    rec(rec, root, 0);
    return ret;
}

/**
 * @brief 木の根から各頂点への辺の重みの累積和を計算する。
 * @param tree 木
 * @return vector<CostType> 根から各頂点への重みの累積和
 */
template<typename CostType>
vector<CostType> CalculateTreeCumlativeSum(RootedTree<CostType> &tree){
    Vertex root = tree.get_root();
    int V = tree.get_vertex_size();
    vector<CostType> ret(V, 0);
    auto rec = [&](auto self, Vertex v, CostType s) -> void {
        ret[v] = s + tree.get_cost(v);
        for(Vertex u : tree.get_child(v)){
            self(self, u, ret[v]);
        }
    };
    rec(rec, root, 0);
    return ret;
}

template<typename CostType>
vector<int> CalculateSubtreeSize(RootedTree<CostType> &tree){
    Vertex root = tree.get_root();
    int V = tree.get_vertex_size();
    vector<int> ret(V, 1);
    auto rec = [&](auto self, Vertex v) -> int {
        for(Vertex u : tree.get_child(v)){
            ret[v] += self(self, u);
        }
        return ret[v];
    };
    rec(rec, root);
    return ret;
}