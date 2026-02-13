#include "Graph.hpp"
#include "GraphMisc.hpp"

template<typename WeightType>
class BellmanFord{
    public:
    BellmanFord(Graph<WeightType> &graph, Vertex s = -1) :
        G(graph), V(graph.VertexSize()), dist_(V){
        if(s != -1) Solve(s);
    }

    inline bool Reachable(const Vertex &t) const {
        return dist_[t] != inf;
    }

    inline WeightType Distance(const Vertex &t) const {
        return dist_[t];
    }

    inline bool NegativeCycle() const {
        return negative_cycle_;
    }

    void Solve(Vertex s){
        fill(dist_.begin(), dist_.end(), inf);
        dist_[s] = WeightType(0);
        negative_cycle_ = false;
        int update_count = 0;
        auto E = ConvertEdgeSet(G);
        while(1){
            if(update_count == V){
                negative_cycle_ = true;
                break;
            }
            bool update_flag = false;
            for(const Edge<WeightType> &e : E){
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

    inline WeightType operator[](const Vertex &t){
        return dist_[t];
    }

    inline const WeightType operator[](const Vertex &t) const {
        return dist_[t];
    }

    private:
    Graph<WeightType> &G;
    int V;
    WeightType inf{WeightType(INF)};
    bool negative_cycle_;
    vector<WeightType> dist_;
};