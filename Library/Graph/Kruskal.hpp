#include "Graph.hpp"
#include "GraphMisc.hpp"
#include "../DataStructure/UnionFind.hpp"

template<typename WeightType>
class Kruskal{
    public:
    Kruskal(Graph<WeightType> &graph) : G(graph), cost_(0){
        int V = G.VertexSize();
        auto Es = ConvertEdgeSet(G);
        sort(Es.begin(), Es.end());
        UnionFind uf(V);
        for(const Edge<WeightType> &e : Es){
            if(uf.Unite(e.from, e.to)){
                cost_ += e.cost;
                edges_.push_back(e);
            }
        }
    }

    inline vector<Edge<WeightType>> &GetEdgeSet(){
        return edges_;
    }

    inline WeightType GetCost() const {
        return cost_;
    }

    private:
    Graph<WeightType> &G;
    vector<Edge<WeightType>> edges_;
    WeightType cost_;
};