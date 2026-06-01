#include "Tree.hpp"

template<typename Ordered>
class TreeDiameter{
    public:
    TreeDiameter(Graph<Ordered> &T) : T(T){
        int V = T.VertexSize(), s = 0;
        dist_s_ = CalculateTreeDistance(T, s);
        s = distance(dist_s_.begin(), max_element(dist_s_.begin(), dist_s_.end()));
        dist_s_ = CalculateTreeDistance(T, s);
        vector<int> par = CalculateTreeParent(T, s);
        int t = distance(dist_s_.begin(), max_element(dist_s_.begin(), dist_s_.end()));
        diameter_ = dist_s_[t];
        dist_t_ = CalculateTreeDistance(T, t);
        int u = t;
        while(u != s){
            path_.emplace_back(u);
            u = par[u];
        }
        path_.emplace_back(s);
    }
    
    Ordered Diameter() const {
        return diameter_;
    }
    
    Ordered Height(Vertex v) const {
        return max(dist_s_[v], dist_t_[v]);
    }

    pair<Vertex, Vertex> EndPoints() const {
        return pair<Vertex, Vertex>(path_.front(), path_.back());
    }

    vector<Vertex> &Path(){
        return path_;
    }

    private:
    Graph<Ordered> &T;
    vector<Ordered> dist_s_, dist_t_;
    vector<Vertex> path_;
    Ordered diameter_;
};