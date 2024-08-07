/**
 * @file BellmanFord.hpp
 * @brief BellmanFord - ベルマンフォード法
 * @version 4.0
 * @date 2024-07-26
 */

#include "Graph.hpp"

template<typename CostType>
class BellmanFord{
    private:
    int vertex_size_;
    vector<Edge<CostType>> edge_set_;
    Vertex start_;
    CostType inf_;
    vector<CostType> dist_;
    bool negative_cycle_{false};

    inline void validate(int vertex){
        assert(0 <= vertex && vertex < vertex_size_);
    }

    public:
    /**
     * @brief グラフ G における負辺有り単一始点最短路問題を解く。
     * @note 計算量 : O(EV)
     * @param G 頂点数 V, 辺数 E のグラフ
     * @param start 始点の頂点 (0-index)
     */
    BellmanFord(Graph<CostType> &G, Vertex start) :
        vertex_size_(G.get_vertex_size()), edge_set_(convert_to_edge_set(G, false)),
        start_(start), inf_(G.get_inf()), dist_(vertex_size_, inf_){
        validate(start_);
        dist_[start_] = 0;
        int update_count = 0;
        while(1){
            if(update_count == vertex_size_){
                negative_cycle_ = true;
                break;
            }
            bool update_flag = false;
            for(Edge<CostType> &e : edge_set_){
                if(dist_[e.from] == inf_) continue;
                if(dist_[e.to] > dist_[e.from] + e.cost){
                    dist_[e.to] = dist_[e.from] + e.cost;
                    update_flag = true;
                }
            }
            if(!update_flag) break;
            ++update_count;
        }
    }

    /**
     * @brief グラフが負閉路を持つかを返す。
     */
    inline bool negative() const {
        return negative_cycle_;
    }

    /**
     * @brief 頂点 `start` から頂点 `goal` までの最短経路長を返す。
     * @param goal 終点の頂点 (0-index)
     * @attention 負閉路を持つときに返す値は未定義である。
     * @return CostType 頂点 `start` から頂点 `goal` までの最短経路長
     */
    CostType distance(Vertex goal) const {
        validate(goal);
        return dist_[goal];
    }

    /**
     * @brief 各頂点への最短経路長を出力する。負閉路を含むならその旨を出力する。
     * @note verify : https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
     * @param delimiter 区切り文字 `(default = ' ')`
     * @param negative_cycle_message 負閉路を持つとき、代わりに出力するメッセージ `(deafult = "NEGATIVE CYCLE")`
     */
    void print(char delimiter = ' ', string negative_cycle_message = "NEGATIVE CYCLE") const {
        if(negative()){
            cout << negative_cycle_message << endl;
            return;
        }
        for(int i = 0; i < vertex_size_; ++i){
            if(dist_[i] == inf_) cout << "INF";
            else cout << dist_[i];
            cout << (i + 1 == vertex_size_ ? '\n' : delimiter);
        }
    }
};