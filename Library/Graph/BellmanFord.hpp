#include "Graph.hpp"
#include "GraphMisc.hpp"

template<typename CostType>
class BellmanFord{
    public:
    BellmanFord(Graph<CostType> &graph, Vertex s = -1) :
        G(graph), n(graph.VertexSize()), dist_(n){
        if(s != -1) Solve(s);
    }

    inline bool Reachable(const Vertex &t) const {
        return dist_[t] != inf;
    }

    inline CostType Distance(const Vertex &t) const {
        return dist_[t];
    }

    inline bool Negative() const {
        return negative_cycle_;
    }

    void Solve(Vertex s){
        fill(dist_.begin(), dist_.end(), inf);
        dist_[s] = CostType(0);
        negative_cycle_ = false;
        int update_count = 0;
        auto E = ConvertEdgeSet(G);
        while(1){
            if(update_count == n){
                negative_cycle_ = true;
                break;
            }
            bool update_flag = false;
            for(const Edge<CostType> &e : E){
                if(dist_[e.from] == inf) continue;
                if(dist_[e.to] > dist_[e.from] + e.cost){
                    dist_[e.to] = dist_[e.from] + e.cost;
                    update_flag = true;
                }
            }
            if(!update_flag) break;
            ++update_count;
        }
    }

    inline CostType operator[](const Vertex &t){
        return dist_[t];
    }

    inline const CostType operator[](const Vertex &t) const {
        return dist_[t];
    }

    private:
    Graph<CostType> &G;
    int n;
    CostType inf{CostType(INF)};
    bool negative_cycle_;
    vector<CostType> dist_;
};