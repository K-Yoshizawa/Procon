#include "Tree.hpp"

template<typename WeightType>
class TreeDiameter{
    public:
    TreeDiameter(Graph<WeightType> &tree) : T(tree){
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
    
    WeightType Diameter() const {
        return diameter_;
    }
    
    WeightType Height(Vertex v) const {
        return max(dist_s_[v], dist_t_[v]);
    }

    pair<Vertex, Vertex> EndPoints() const {
        return pair<Vertex, Vertex>(path_.front(), path_.back());
    }

    vector<Vertex> &Path(){
        return path_;
    }

    private:
    Graph<WeightType> &T;
    vector<WeightType> dist_s_, dist_t_;
    vector<Vertex> path_;
    WeightType diameter_;
};