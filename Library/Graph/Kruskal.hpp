#include "Graph.hpp"
#include "GraphUtilities.hpp"
#include "../DataStructure/UnionFind.hpp"

template<typename Ordered>
class Kruskal{
    public:
    Kruskal(Graph<Ordered> &G) : G(G), cost_(0){
        int V = G.VertexSize();
        auto Es = ConvertEdgeSet(G);
        sort(Es.begin(), Es.end());
        UnionFind uf(V);
        for(const Edge<Ordered> &e : Es){
            if(uf.Unite(e.from, e.to)){
                cost_ += e.cost;
                edges_.push_back(e);
            }
        }
    }

    inline vector<Edge<Ordered>> &GetEdgeSet(){
        return edges_;
    }

    inline Ordered GetCost() const {
        return cost_;
    }

    private:
    Graph<Ordered> &G;
    vector<Edge<Ordered>> edges_;
    Ordered cost_;
};