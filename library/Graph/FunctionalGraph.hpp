/**
 * @file FunctionalGraph.hpp
 * @brief Functional Graph
 * @version 0.1
 * @date 2024-06-16
 */

#include <bits/stdc++.h>
using namespace std;

using Vertex = int;

template<typename CostType = int32_t>
class FunctionalGraph{
    Vertex size_;
    vector<Vertex> to_;
    vector<CostType> cost_;

    const int kLog_{63};
    vector<vector<Vertex>> next_;
    vector<vector<CostType>> cost_sum_;

    vector<int> belong_cycle_;
    vector<vector<Vertex>> cycle_;

    void build(){
        next_.resize(size_, vector<Vertex>(kLog_, -1));
        cost_sum_.resize(size_, vector<CostType>(kLog_, 0));
        for(int v = 0; v < size_; ++v){
            next_[v][0] = to_[v];
            cost_sum_[v][0] = cost_[v];
        }
        for(int i = 0; i < kLog_ - 1; ++i){
            for(int v = 0; v < size_; ++v){
                next_[v][i + 1] = next_[next_[v][i]][i];
                cost_sum_[v][i + 1] = cost_sum_[next_[v][i]][i] + cost_sum_[v][i];
            }
        }
        belong_cycle_.resize(size_, -1);
        vector<int> state(size_, 0);
        vector<Vertex> history;
        auto dfs = [&](auto self, int v) -> void {
            if(state[v] == 2) return;
            history.push_back(v);
            state[v] = 1;
            int u = to_[v];
            if(state[u] == 1){
                int c = cycle_.size();
                cycle_.push_back(vector<Vertex>{});
                for(int i = history.size() - 1;; --i){
                    cycle_.back().push_back(history[i]);
                    belong_cycle_[history[i]] = c;
                    if(history[i] == u) break;
                }
                reverse(cycle_.back().begin(), cycle_.back().end());
            }
            else{
                self(self, u);
            }
            history.pop_back();
            state[v] = 2;
        };
        for(int v = 0; v < size_; ++v){
            dfs(dfs, v);
        }
    }

    public:
    FunctionalGraph(){}

    /**
     * @brief 重みなし Functional Graph の構築
     * @param to 各頂点 v が接続している頂点 u
     * @param one_index 頂点番号が 1-index であるか `(default = true)`
     */
    FunctionalGraph(vector<Vertex> &to, bool one_index = true) :
    size_(to.size()), to_(to), cost_(to.size(), 1){
        for(auto &u : to_) u -= (int)one_index;
        build();
    }

    /**
     * @brief 重みあり Functional Graph の構築
     * @param to 各頂点 v が接続している頂点 u
     * @param cost 各頂点 v が接続している頂点 u の辺の重み
     * @param one_index 頂点番号が 1-index であるか `(default = true)`
     */
    FunctionalGraph(vector<Vertex> &to, vector<CostType> &cost, bool one_index = true) :
    size_(to.size()), to_(to), cost_(cost){
        for(auto &u : to_) u -= (int)one_index;
        build();
    }

    /**
     * @brief 各サイクルを構成する頂点の一覧を返す。
     * @note サイクルが存在しない場合は空列が返るので、`size()` でサイクルの個数を取得できる。
     * @note verify : https://atcoder.jp/contests/abc311/submissions/54652396
     * @return vector<vector<Vertex>> 各サイクルを構成する頂点の一覧
     */
    vector<vector<Vertex>> get_cycle(){
        return cycle_;
    }

    /**
     * @brief 頂点 `start` から `step` 回移動する先の頂点を求める。
     * @note verify : https://atcoder.jp/contests/abc167/submissions/54652615
     * @param start 開始頂点
     * @param step 移動回数
     * @param one_index 頂点番号が 1-index であるか `(default = true)`
     * @return Vertex 移動先の頂点(`one_index` に応じて整形される)
     */
    Vertex warp_where(Vertex start, int64_t step, bool one_index = true){
        Vertex ret = start - one_index;
        int64_t n = step, i = 0;
        while(n){
            if(n & 1){
                ret = next_[ret][i];
            }
            n >>= 1, ++i;
        }
        return ret + one_index;
    }

    /**
     * @brief 頂点 `start` から `step` 回移動するときの辺の重みの総和を求める。
     * @note verify : https://atcoder.jp/contests/abc179/submissions/54652566
     * @param start 開始頂点
     * @param step 移動回数
     * @param one_index 頂点番号が 1-index であるか `(default = true)`
     * @return CostType 辺の重みの総和
     */
    CostType warp_distance(Vertex start, int64_t step, bool one_index = true){
        CostType ret = 0;
        int64_t n = step, i = 0;
        Vertex v = start - one_index;
        while(n){
            if(n & 1){
                ret += cost_sum_[v][i];
                v = next_[v][i];
            }
            n >>= 1, ++i;
        }
        return ret;
    }
};