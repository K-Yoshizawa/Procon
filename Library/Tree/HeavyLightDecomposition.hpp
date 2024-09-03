/**
 * @file HeavyLightDecomposition.hpp
 * @author log K (lX57)
 * @brief Heavy Light Decomposition - HL分解
 * @version 4.0
 * @date 2024-09-04
 */

#include "Tree.hpp"

struct PathSegment{
    Vertex head_vertex, tail_vertex;
    int head_index, tail_index;
    bool reverse;
};

template<typename CostType>
class HeavyLightDecomposition{
    public:
    HeavyLightDecomposition(RootedTree<CostType> &tree) : tree_(tree){
    }

    private:
    RootedTree<CostType> &tree_;
};