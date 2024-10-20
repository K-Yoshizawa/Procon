/**
 * @file TreeDiameter.hpp
 * @brief Tree Diameter - 木の直径
 * @version 3.0
 * @date 2024-09-03
 */

#include "Tree.hpp"

template<typename CostType>
class TreeDiameter{
    public:
    TreeDiameter(RootedTree<CostType> &tree) : tree_(tree){
        dist_ = CalculateTreeCumlativeSum(tree);
        Vertex u = distance(dist_.begin(), max_element(dist_.begin(), dist_.end()));
        tree_.Rerooting(u);
        dist_ = CalculateTreeCumlativeSum(tree);
        auto itr = max_element(dist_.begin(), dist_.end());
        diameter_ = *itr;
        Vertex v = distance(dist_.begin(), itr);
        while(v != u){
            diameter_path_.push_back(v);
            v = tree.get_parent(v);
        }
        diameter_path_.push_back(u);
    }

    /**
     * @brief 直径を構成するパスの端点を返す。
     * @return pair<Vertex, Vertex> 直径を構成するパスの端点 (0-index)
     */
    pair<Vertex, Vertex> get_endpoints() const {
        return pair<Vertex, Vertex>(diameter_path_.front(), diameter_path_.end());
    }

    /**
     * @brief 直径を構成するパスを返す。
     * @return vector<Vertex>& 直径を構成するパスに含まれる頂点 (0-index)
     */
    vector<Vertex> &get_diameter_path(){
        return diameter_path_;
    }

    /**
     * @brief 直径を返す。
     * @return CostType 直径
     */
    CostType get_diameter() const {
        return diameter_;
    }

    private:
    RootedTree<CostType> &tree_;

    CostType diameter_;
    vector<Vertex> diameter_path_;
    vector<CostType> dist_;
};