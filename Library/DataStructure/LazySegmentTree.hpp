#include "../Common.hpp"

template<typename Monoid, typename OperatorMonoid = Monoid>
class LazySegmentTree{
    public:
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    LazySegmentTree(
        vector<Monoid> &A,
        F merge,
        G mapping,
        H composite,
        const Monoid &e_m,
        const OperatorMonoid &e_o,
        bool zero_index = false
    ) : f(merge), g(mapping), h(composite), m1_(e_m), om1_(e_o), zero_index_(zero_index){
        size_ = 1;
        while(size_ < (int)A.size()) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, m1_);
        lazy_.resize(2 * size_, om1_);
        is_identity_.resize(2 * size_, true);
        for(int i = 0; i < (int)A.size(); ++i){
            data_[size_ + i] = A[i];
        }
        for(int i = offset_; i >= 1; --i){
            data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);
        }
    }

    void Apply(int l, int r, OperatorMonoid x){
        Validate(l + zero_index_);
        Validate(r + zero_index_ - 1);
        RecursiveApply(l + zero_index_, r + zero_index_, x, 1, size_ + 1, 1);
    }

    Monoid Fold(int l, int r){
        Validate(l + zero_index_);
        Validate(r + zero_index_ - 1);
        return RecursiveFold(l + zero_index_, r + zero_index_, 1, size_ + 1, 1);
    }

    Monoid operator[](const int &k){
        Validate(k + zero_index_);
        return Fold(k, k + 1);
    }

    private:
    int size_, offset_, zero_index_;
    vector<Monoid> data_;
    vector<OperatorMonoid> lazy_;
    vector<bool> is_identity_;
    const F f;
    const G g;
    const H h;
    const Monoid m1_;
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
        }
        data_[k] = g(data_[k], lazy_[k]);
        lazy_[k] = om1_;
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
            data_[cell] = f(data_[cell * 2 + 0], data_[cell * 2 + 1]);
        }
    }

    Monoid RecursiveFold(int ql, int qr, int left, int right, int cell){
        Evaluate(cell);
        if(qr <= left || right <= ql){
            return m1_;
        }
        if(ql <= left && right <= qr){
            return data_[cell];
        }
        int mid = (left + right) / 2;
        Monoid ans_left = RecursiveFold(ql, qr, left, mid, cell * 2 + 0);
        Monoid ans_right = RecursiveFold(ql, qr, mid, right, cell * 2 + 1);
        return f(ans_left, ans_right);
    }
};