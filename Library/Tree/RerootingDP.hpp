/**
 * @file RerootingDP.hpp
 * @brief Rerooting DP - 全方位木 DP
 * @version 1.0
 * @date 2024-09-03
 */

#include "Tree.hpp"

template<typename CostType, typename Monoid>
class RerootingDP{
    public:
    using F = function<Monoid(Monoid, Monoid, Vertex)>;
    using G = function<Monoid(Monoid, CostType, Vertex)>;
    using H = function<Monoid(Monoid, Vertex)>;
    using Fsub = function<Monoid(Monoid, Monoid)>;
    using Gsub = function<Monoid(Monoid, CostType)>;

    /**
     * @brief 木 `tree` に対して全方位木DPを行う。(辺属性のみ)
     * @param tree 根付き木
     * @param merge `(Monoid, Monoid) -> Monoid` : `Monoid` 同士に関する二項演算。
     * @param add `(Monoid, CostType) -> Monoid` : `Monoid` と `CostType` に関する二項演算。
     * @param monoid_identity `Monoid` の単位元。
     */
    RerootingDP(Graph<CostType> &tree, Fsub merge, Gsub add, const Monoid monoid_identity, Vertex r = 0) :
            T(tree), n(tree.VertexSize()), parent(CalculateTreeParent(tree, r)), cost(CalculateTreeCost(tree, r)), child(RootedTreeAdjacentList(tree, r)),
            merge_sub_(merge), add_sub_(add), id_(monoid_identity){
        merge_ = [&](Monoid x, Monoid y, Vertex i){return merge_sub_(x, y);};
        add_ = [&](Monoid x, CostType y, Vertex i){return add_sub_(x, y);};
        finalize_ = [](Monoid x, Vertex i){return x;};
        solve(r);
    }

    /**
     * @brief 木 `tree` に対して全方位木DPを行う。(頂点属性を含む)
     * @param tree 根付き木
     * @param merge `(Monoid, Monoid, Vertex) -> Monoid` : `Monoid` 同士に関する二項演算。
     * @param add `(Monoid, CostType, Vertex) -> Monoid` : `Monoid` と `CostType` に関する二項演算。
     * @param finalize `(Monoid, Vertex) -> Monoid` : `Monoid` に頂点 `Vertex` が根のときの処理。
     * @param monoid_identity `Monoid` の単位元。
     */
    RerootingDP(Graph<CostType> &tree, F merge, G add, H finalize, const Monoid monoid_identity, Vertex r = 0) :
            T(tree), n(tree.VertexSize()), parent(CalculateTreeParent(tree, r)), cost(CalculateTreeCost(tree, r)), child(RootedTreeAdjacentList(tree, r)),
            merge_(merge), add_(add), finalize_(finalize), id_(monoid_identity){
        solve(r);
    }

    /**
     * @brief 全頂点に関するDPの配列を取得する。
     */
    vector<Monoid> &get_all_answer(){
        return dp_;
    }

    Monoid operator[](Vertex v){
        return dp_[v];
    }

    const Monoid operator[](Vertex v) const {
        return dp_[v];
    }

    void Print() const {
        cerr << "# dp table :";
        for(int i = 0; i < n; ++i){
            cerr << " " << dp_[i];
        }
        cerr << '\n';
        cerr << "# subtree_dp table" << '\n';
        for(int i = 0; i < V; ++i){
            cerr << "# vertex " << i << '\n';
            cerr << "#    subtree_dp :";
            for(int j = 0; j < subtree_dp_[i].size(); ++j){
                cerr << " " << subtree_dp_[i][j];
            }
            cerr << '\n';
            cerr << "#    left_cum   :";
            for(int j = 0; j < left_cum_[i].size(); ++j){
                cerr << " " << left_cum_[i][j];
            }
            cerr << '\n';
            cerr << "#    right_cum  :";
            for(int j = 0; j < right_cum_[i].size(); ++j){
                cerr << " " << right_cum_[i][j];
            }
            cerr << '\n';
        }
    }

    private:
    Graph<CostType> &T;
    int n;
    vector<Vertex> parent;
    vector<CostType> cost;
    vector<vector<Vertex>> child;
    
    vector<Monoid> dp_;
    vector<vector<Monoid>> subtree_dp_, left_cum_, right_cum_;

    const Monoid id_;

    F merge_;
    G add_;
    H finalize_;
    const Fsub merge_sub_;
    const Gsub add_sub_;

    Monoid dfs(Vertex v, bool root = false){
        Monoid ret = id_;
        for(auto u : child[v]){
            Monoid res = dfs(u);
            subtree_dp_[v].push_back(res);
            ret = merge_(ret, res, v);
        }
        if(root) ret = finalize_(ret, v);
        else ret = add_(ret, cost[v], v);
        return ret;
    }

    void solve(Vertex r){
        dp_.resize(n, id_);
        subtree_dp_.resize(n, vector<Monoid>{id_});
        left_cum_.resize(n);
        right_cum_.resize(n);

        dp_[r] = dfs(r, true);
        int root_size = subtree_dp_[r].size();
        left_cum_[r].resize(root_size + 1);
        left_cum_[r].front() = id_;
        for(int i = 1; i < root_size; ++i){
            left_cum_[r][i] = merge_(left_cum_[r][i - 1], subtree_dp_[r][i], r);
        }
        right_cum_[r].resize(root_size + 1);
        right_cum_[r].back() = id_;
        for(int i = root_size - 1; i - 1 >= 0; --i){
            right_cum_[r][i] = merge_(right_cum_[r][i + 1], subtree_dp_[r][i], r);
        }

        queue<tuple<int, int, int>> que;
        for(int i = 0; i < child[r].size(); ++i){
            que.push({child[r][i], r, i + 1});
        }
        while(que.size()){
            auto [v, p, idx] = que.front(); que.pop();
            Monoid ret = id_;
            ret = merge_(ret, left_cum_[p][idx - 1], v);
            ret = merge_(ret, right_cum_[p][idx + 1], v);
            ret = add_(ret, cost[v], p);
            subtree_dp_[v].push_back(ret);
            for(int i = 1; i + 1 < subtree_dp_[v].size(); ++i){
                ret = merge_(ret, subtree_dp_[v][i], v);
            }
            dp_[v] = finalize_(ret, v);
            int c = subtree_dp_[v].size();
            left_cum_[v].resize(c + 1);
            left_cum_[v][0] = id_;
            for(int i = 1; i < c; ++i){
                left_cum_[v][i] = merge_(left_cum_[v][i - 1], subtree_dp_[v][i], v);
            }
            right_cum_[v].resize(c + 1);
            right_cum_[v].back() = id_;
            for(int i = c - 1; i - 1 >= 0; --i){
                right_cum_[v][i] = merge_(right_cum_[v][i + 1], subtree_dp_[v][i], v);
            }
            for(int i = 0; i < child[v].size(); ++i){
                que.push({child[v][i], v, i + 1});
            }
        }
    }
};