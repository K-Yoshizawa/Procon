#include "Tree.hpp"

template<typename CostType>
class TreeDiameter{
    public:
    TreeDiameter(Graph<CostType> &tree) : T(tree){
        int n = T.VertexSize(), s = 0;
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

    // /**
    //  * @brief 直径を構成するパスの端点を返す。
    //  * @return pair<Vertex, Vertex> 直径を構成するパスの端点 (0-index)
    //  */
    // pair<Vertex, Vertex> get_endpoints() const {
    //     return pair<Vertex, Vertex>(diameter_path_.front(), diameter_path_.end());
    // }

    // /**
    //  * @brief 直径を構成するパスを返す。
    //  * @return vector<Vertex>& 直径を構成するパスに含まれる頂点 (0-index)
    //  */
    // vector<Vertex> &get_diameter_path(){
    //     return diameter_path_;
    // }

    CostType Diameter() const {
        return diameter_;
    }

    CostType Height(Vertex v) const {
        return max(dist_s_[v], dist_t_[v]);
    }

    private:
    Graph<CostType> &T;
    vector<CostType> dist_s_, dist_t_;
    vector<Vertex> path_;
    CostType diameter_;
};