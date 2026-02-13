#include "Graph.hpp"
#include "GraphMisc.hpp"

template<typename WeightType>
class WarshallFloyd{
    public:
    WarshallFloyd(Graph<WeightType> &graph) :
        V(graph.VertexSize()), dist_(ConvertDistanceMatrix(graph)){
        Solve();
    }

    WarshallFloyd(vector<vector<WeightType>> &A) :
        V((int)A.size()), dist_(A){
        Solve();
    }

    inline bool Reachable(const Vertex &s, const Vertex &t) const {
        return dist_[s][t] != inf;
    }

    inline WeightType Distance(const Vertex &s, const Vertex &t) const {
        return dist_[s][t];
    }

    inline bool NegativeCycle() const {
        return negative_cycle_;
    }

    inline vector<WeightType> &operator[](const Vertex &s){
        return dist_[s];
    }

    inline const vector<WeightType> &operator[](const Vertex &s) const {
        return dist_[s];
    }

    private:
    int V;
    WeightType inf{WeightType(INF)};
    bool negative_cycle_{false};
    vector<vector<WeightType>> dist_;

    void Solve(){
        for(int i = 0; i < V; ++i) dist_[i][i] = min(dist_[i][i], WeightType(0));
        for(int k = 0; k < V; ++k){
            for(int i = 0; i < V; ++i){
                for(int j = 0; j < V; ++j){
                    if(dist_[i][k] == inf || dist_[k][j] == inf) continue;
                    dist_[i][j] = min(dist_[i][j], dist_[i][k] + dist_[k][j]);
                }
            }
        }
        for(int i = 0; i < V; ++i) negative_cycle_ |= dist_[i][i] < 0;
    }
};