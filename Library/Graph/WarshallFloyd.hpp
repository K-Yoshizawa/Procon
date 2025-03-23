#include "Graph.hpp"
#include "GraphMisc.hpp"

template<typename CostType>
class WarshallFloyd{
    public:
    WarshallFloyd(Graph<CostType> &G) :
        n(G.VertexSize()), dist_(ConvertDistanceMatrix(G)){
        Solve();
    }

    WarshallFloyd(vector<vector<CostType>> &D) :
        n((int)D.size()), dist_(D){
        Solve();
    }

    inline bool Reachable(const Vertex &s, const Vertex &t) const {
        return dist_[s][t] != inf;
    }

    inline CostType Distance(const Vertex &s, const Vertex &t) const {
        return dist_[s][t];
    }

    inline bool Negative() const {
        return negative_cycle_;
    }

    inline vector<CostType> &operator[](const Vertex &s){
        return dist_[s];
    }

    inline const vector<CostType> &operator[](const Vertex &s) const {
        return dist_[s];
    }

    private:
    int n;
    CostType inf{CostType(INF)};
    bool negative_cycle_{false};
    vector<vector<CostType>> dist_;

    void Solve(){
        for(int i = 0; i < n; ++i) dist_[i][i] = min(dist_[i][i], CostType(0));
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(dist_[i][k] == inf || dist_[k][j] == inf) continue;
                    dist_[i][j] = min(dist_[i][j], dist_[i][k] + dist_[k][j]);
                }
            }
        }
        for(int i = 0; i < n; ++i) negative_cycle_ |= dist_[i][i] < 0;
    }
};