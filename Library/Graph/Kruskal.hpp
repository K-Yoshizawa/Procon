#include "Graph.hpp"
#include "GraphMisc.hpp"
#include "../DataStructure/UnionFind.hpp"

template<typename CostType>
class Kruskal{
    public:
    Kruskal(Graph<CostType> &graph) : G(graph), cost_(0){
        int N = G.VertexSize();
        auto E = ConvertEdgeSet(G);
        sort(E.begin(), E.end());
        UnionFind uf(N);
        for(const Edge<CostType> &e : E){
            if(uf.Unite(e.from, e.to)){
                cost_ += e.cost;
                edges_.push_back(e);
            }
        }
    }

    inline vector<Edge<CostType>> &GetEdgeSet(){
        return edges_;
    }

    inline CostType GetCost() const {
        return cost_;
    }

    private:
    Graph<CostType> &G;
    vector<Edge<CostType>> edges_;
    CostType cost_;
};