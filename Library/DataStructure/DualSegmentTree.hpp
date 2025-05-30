/**
 * @file DualSegmentTree.hpp
 * @brief Dual Segment Tree - 双対セグメント木
 * @version 2.0
 * @date 2024-11-29
 */

#include "../Common.hpp"

template<typename OperatorMonoid>
class DualSegmentTree{
    public:
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;
    
    DualSegmentTree(int size, H composite, const OperatorMonoid &operator_identity, bool zero_index = false)
    : h(composite), om1_(operator_identity), zeroindex_(zero_index){
        size_ = 1;
        while(size_ < size) size_ <<= 1;
        offset_ = size_ - 1;
        lazy_.resize(2 * size_, om1_);
        is_identity_.resize(2 * size_, true);
    }

    void Set(int index, OperatorMonoid value){
        Validate(index + zeroindex_);
        lazy_[offset_ + index + zeroindex_] = value;
    }

    void Update(int left, int right, OperatorMonoid operation){
        Validate(left + zeroindex_);
        Validate(right + zeroindex_ - 1);
        RecursiveUpdate(left + zeroindex_, right + zeroindex_, operation, 1, size_ + 1, 1);
    }

    OperatorMonoid Product(int index){
        Validate(index + zeroindex_);
        return RecursiveProduct(index + zeroindex_, 1, size_ + 1, 1);
    }

    private:
    int size_, offset_, zeroindex_;
    vector<OperatorMonoid> lazy_;
    vector<bool> is_identity_;
    const H h;
    const OperatorMonoid om1_;

    inline void Validate(int x){
        assert(1 <= x && x <= size_);
    }

    void Evaluate(int k){
        if(is_identity_[k]) return;
        if(k < size_){
            lazy_[k * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);
            is_identity_[k * 2 + 0] = false;
            lazy_[k * 2 + 1] = h(lazy_[k * 2 + 1], lazy_[k]);
            is_identity_[k * 2 + 1] = false;
            lazy_[k] = om1_;
            is_identity_[k] = true;
        }
    }

    void RecursiveUpdate(int ul, int ur, OperatorMonoid x, int left, int right, int cell){
        Evaluate(cell);
        if(ul <= left && right <= ur){
            lazy_[cell] = h(lazy_[cell], x);
            is_identity_[cell] = false;
            Evaluate(cell);
        }
        else if(ul < right && left < ur){
            int mid = (left + right) / 2;
            RecursiveUpdate(ul, ur, x, left, mid, cell * 2 + 0);
            RecursiveUpdate(ul, ur, x, mid, right, cell * 2 + 1);
        }
    }
    
    OperatorMonoid RecursiveProduct(int q, int left, int right, int cell){
        Evaluate(cell);
        if(q == left && right - left == 1) return lazy_[cell];
        int mid = (left + right) / 2;
        if(q < mid) return RecursiveProduct(q, left, mid, cell * 2 + 0);
        else return RecursiveProduct(q, mid, right, cell * 2 + 1);
    }
};