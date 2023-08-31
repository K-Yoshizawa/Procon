/**
 * @file WarshallFloyd.hpp
 * @author log_K (lX57)
 * @brief WarshallFloyd - 全点対間最短経路
 * @version 2.0
 * @date 2023-08-31
 */

#include "GraphTemplate.hpp"

template<typename CostType>
struct WarshallFloyd{
    private:
    bool __NegativeCycle;
    int __Size;
    CostType __INF;
    vector<vector<CostType>> __Dist;

    void __solve(){
        for(int k = 0; k < __Size; ++k){
            for(int i = 0; i < __Size; ++i){
                for(int j = 0; j < __Size; ++j){
                    if(__Dist[i][k] == __INF || __Dist[k][j] == __INF) continue;
                    __Dist[i][j] = min(__Dist[i][j], __Dist[i][k] + __Dist[k][j]);
                }
            }
        }
        __NegativeCycle = false;
        for(int i = 0; i < __Size; ++i) __NegativeCycle |= __Dist[i][i] < 0;
    }

    public:
    WarshallFloyd(Graph<CostType> &G) : __Size(G.vsize()), __INF(G.INF), __Dist(G.matrix()){
        __solve();
    }

    WarshallFloyd(vector<vector<CostType>> &M) : __Size((int)M.size()), __INF(numeric_limits<CostType>::max() / 2), __Dist(M){
        __solve();
    }

    inline bool negative(){
        return __NegativeCycle;
    }

    CostType dist(Vertex Start, Vertex Goal){
        assert(0 <= Start && Start < __Size);
        assert(0 <= Goal && Goal < __Size);
        return __Dist[Start][Goal];
    }
    
    void print(CostType NotAdjacent = numeric_limits<CostType>::max() / 2, bool DisplayINF = true){
        for(int i = 0; i < __Size; ++i){
            cout << (DisplayINF && __Dist[i][0] == NotAdjacent ? "INF" : to_string(__Dist[i][0]));
            for(int j = 1; j < __Size; ++j){
                cout << " " << (DisplayINF && __Dist[i][j] == NotAdjacent ? "INF" : to_string(__Dist[i][j]));
            }
            cout << endl;
        }
    }
};