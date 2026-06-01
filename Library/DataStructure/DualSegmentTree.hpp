#include "../Common.hpp"

template<typename Monoid, typename OperatorMonoid>
class DualSegmentTree{
    public:
    using Mapping = function<Monoid(Monoid, OperatorMonoid)>;
    using Composite = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;
    
    DualSegmentTree(
        vector<Monoid> &A, 
        Mapping g, 
        Composite h, 
        const OperatorMonoid &e, 
        bool zero_index = false
    ) : g(g), h(h), e(e), zero_index_(zero_index){
        size_ = 1;
        while(size_ < (int)A.size()) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_);
        lazy_.resize(2 * size_, e);
        is_identity_.resize(2 * size_, true);
        for(int i = 0; i < (int)A.size(); ++i){
            data_[size_ + i] = A[i];
        }
    }

    void Apply(int l, int r, OperatorMonoid x){
        Validate(l + zero_index_);
        Validate(r + zero_index_ - 1);
        RecursiveApply(l + zero_index_, r + zero_index_, x, 1, size_ + 1, 1);
    }

    Monoid Fold(int k){
        Validate(k + zero_index_);
        return RecursiveFold(k + zero_index_, 1, size_ + 1, 1);
    }

    Monoid operator[](const int &k){
        Validate(k + zero_index_);
        return Fold(k);
    }

    private:
    int size_, offset_, zero_index_;
    vector<Monoid> data_;
    vector<OperatorMonoid> lazy_;
    vector<bool> is_identity_;
    const Mapping g;
    const Composite h;
    const OperatorMonoid e;

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
        }
        data_[k] = g(data_[k], lazy_[k]);
        lazy_[k] = e;
        is_identity_[k] = true;
    }

    void RecursiveApply(int ul, int ur, OperatorMonoid x, int left, int right, int cell){
        Evaluate(cell);
        if(ul <= left && right <= ur){
            lazy_[cell] = h(lazy_[cell], x);
            is_identity_[cell] = false;
            Evaluate(cell);
        }
        else if(ul < right && left < ur){
            int mid = (left + right) / 2;
            RecursiveApply(ul, ur, x, left, mid, cell * 2 + 0);
            RecursiveApply(ul, ur, x, mid, right, cell * 2 + 1);
        }
    }
    
    Monoid RecursiveFold(int q, int left, int right, int cell){
        Evaluate(cell);
        if(q == left && right - left == 1) return data_[cell];
        int mid = (left + right) / 2;
        if(q < mid) return RecursiveFold(q, left, mid, cell * 2 + 0);
        else return RecursiveFold(q, mid, right, cell * 2 + 1);
    }
};