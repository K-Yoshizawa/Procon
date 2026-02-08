#include "Tree.hpp"
#include "EulerTour.hpp"
#include "LowestCommonAncestor.hpp"

template<typename CostType>
class AuxiliaryTree{
    public:
    AuxiliaryTree(RootedTree<CostType> &tree) :
            T(tree), lca_(tree), et_(tree), edge_cum_(CalculateTreeCumlativeSum(tree)){
    }

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