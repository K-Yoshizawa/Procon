/**
 * @file AuxiliaryTree.hpp
 * @brief Auxiliary Tree - 指定された頂点たちの最小共通祖先関係を保って木を圧縮してできる補助的な木
 * @version 2.0
 * @date 2024-10-31
 */

#include "Tree.hpp"
#include "EulerTour.hpp"
#include "LowestCommonAncestor.hpp"

template<typename CostType>
class AuxiliaryTree{
    public:
    /**
     * @brief 木 `tree` を元に補助木を定義する。
     * @param tree 頂点数 `U` の木
     */
    AuxiliaryTree(RootedTree<CostType> &tree) :
            T(tree), lca_(tree), et_(tree), edge_cum_(CalculateTreeCumlativeSum(tree)){
    }

    /**
     * @brief 構築する補助木に含む頂点集合をセットする。
     * @note 実際には、この頂点集合に LCA を加えた頂点集合が保存される。
     * @note 計算量 : O(V log V)
     * @param vertex_set 補助木に含む要素数 `V` の頂点集合 (0-index)
     */
    void Set(const vector<Vertex> &vertex_set){
        auxiliary_tree_vertex_set_ = vertex_set;
        auxiliary_tree_size_ = auxiliary_tree_vertex_set_.size();
        sort(auxiliary_tree_vertex_set_.begin(), auxiliary_tree_vertex_set_.end(), [&](int i, int j){
            return et_.get_in(i) < et_.get_in(j);
        });
        for(int i = 0; i < auxiliary_tree_size_ - 1; ++i){
            auxiliary_tree_vertex_set_.push_back(lca_.Query(auxiliary_tree_vertex_set_[i], auxiliary_tree_vertex_set_[i + 1]));
        }
        sort(auxiliary_tree_vertex_set_.begin(), auxiliary_tree_vertex_set_.end(), [&](int i, int j){
            return et_.get_in(i) < et_.get_in(j);
        });
        auxiliary_tree_vertex_set_.erase(unique(auxiliary_tree_vertex_set_.begin(), auxiliary_tree_vertex_set_.end()), auxiliary_tree_vertex_set_.end());
        auxiliary_tree_size_ = auxiliary_tree_vertex_set_.size();
    }

    /**
     * @brief 補助木を生成する。
     * @attention 予め頂点集合を `Set()` を用いてセットしておく必要がある。
     * @note 計算量 : O(V log V)
     * @return RootedTree<CostType> 生成された頂点数 
     */
    RootedTree<CostType> Build(){
        RootedTree<CostType> ret(auxiliary_tree_size_);
        stack<Vertex> st, idx;
        st.push(auxiliary_tree_vertex_set_.front());
        idx.push(0);
        for(int i = 1; i < auxiliary_tree_size_; ++i){
            while(et_.get_out(st.top()) < et_.get_in(auxiliary_tree_vertex_set_[i])) st.pop(), idx.pop();
            if(st.size()){
                CostType cost = edge_cum_[auxiliary_tree_vertex_set_[i]] - edge_cum_[st.top()];
                ret.AddEdge(idx.top(), i, cost);
            }
            st.push(auxiliary_tree_vertex_set_[i]);
            idx.push(i);
        }
        return ret;
    }

    /**
     * @brief 元の木と補助木にデータを対応させた配列を返す。
     * @tparam Type データの型
     * @param data 長さ `U` のデータ
     * @return vector<Type> 長さ `O(V log V)` の変換後のデータ
     */
    template<typename Type>
    vector<Type> ConvertData(const vector<Type> &data) const {
        vector<Type> ret(auxiliary_tree_size_);
        for(int i = 0; i < auxiliary_tree_size_; ++i){
            ret[i] = data[auxiliary_tree_vertex_set_[i]];
        }
        return ret;
    }

    private:
    RootedTree<CostType> &T;
    LowestCommonAncestor<CostType> lca_;
    EulerTour<CostType> et_;
    vector<CostType> edge_cum_;

    vector<Vertex> auxiliary_tree_vertex_set_;
    size_t auxiliary_tree_size_;
    vector<Vertex> convert_to_;
};