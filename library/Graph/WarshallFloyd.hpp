/**
 * @file WarshallFloyd.hpp
 * @author log_K (lX57)
 * @brief WarshallFloyd - 全点対間最短経路
 * @version 2.2
 * @date 2023-10-02
 */

#include "GraphTemplate.hpp"

template<typename CostType>
struct WarshallFloyd{
    private:
    bool nc_;
    int size_;
    CostType inf_;
    vector<vector<CostType>> dist_;

    void solve_(){
        for(int k = 0; k < size_; ++k){
            for(int i = 0; i < size_; ++i){
                for(int j = 0; j < size_; ++j){
                    if(dist_[i][k] == inf_ || dist_[k][j] == inf_) continue;
                    dist_[i][j] = min(dist_[i][j], dist_[i][k] + dist_[k][j]);
                }
            }
        }
        nc_ = false;
        for(int i = 0; i < size_; ++i) nc_ |= dist_[i][i] < 0;
    }

    public:
    WarshallFloyd(Graph<CostType> &G) : size_(G.size()), inf_(G.INF), dist_(G.matrix()){
        solve_();
    }

    WarshallFloyd(vector<vector<CostType>> &M) : size_((int)M.size()), inf_(numeric_limits<CostType>::max() / 2), dist_(M){
        solve_();
    }

    inline bool negative(){
        return nc_;
    }

    CostType dist(Vertex Start, Vertex Goal){
        assert(0 <= Start && Start < size_);
        assert(0 <= Goal && Goal < size_);
        return dist_[Start][Goal];
    }
    
    void print(CostType NotAdjacent = numeric_limits<CostType>::max() >> 2, bool DisplayINF = true){
        for(int i = 0; i < size_; ++i){
            cout << (DisplayINF && dist_[i][0] == NotAdjacent ? "INF" : to_string(dist_[i][0]));
            for(int j = 1; j < size_; ++j){
                cout << " " << (DisplayINF && dist_[i][j] == NotAdjacent ? "INF" : to_string(dist_[i][j]));
            }
            cout << endl;
        }
    }
};