#include "../Common.hpp"

template<typename Monoid>
class SegmentTree{
    public:
    using F = function<Monoid(Monoid, Monoid)>;

    SegmentTree(
        int n,
        F merge,
        const Monoid &e,
        bool zero_index = false
    ) : f(merge), id_(e), zero_index_(zero_index){
        size_ = 1;
        while(size_ < n) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, id_);
    }
    
    SegmentTree(
        vector<Monoid> &A, 
        F merge, 
        const Monoid &e, 
        bool zero_index = false
    ) : f(merge), id_(e), zero_index_(zero_index){
        size_ = 1;
        while(size_ < (int)A.size()) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, id_);
        for(int i = 0; i < (int)A.size(); ++i){
            data_[size_ + i] = A[i];
        }
        Build();
    }

    void Build(){
        for(int i = offset_; i >= 1; --i){
            data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);
        }
    }

    void Set(int i, Monoid v){
        Validate(i + zero_index_);
        int k = offset_ + i + zero_index_;
        data_[k] = v;
        while(k >>= 1){
            data_[k] = f(data_[2 * k], data_[2 * k + 1]);
        }
    }

    Monoid Product(int l, int r){
        if(l == r) return id_;
        Validate(l + zero_index_);
        Validate(r + zero_index_ - 1);
        int lh = l + zero_index_ + offset_, rh = r + zero_index_ + offset_;
        Monoid al = id_, ar = id_;
        while(lh < rh){
            if(lh & 1) al = f(al, data_[lh++]);
            if(rh & 1) ar = f(data_[--rh], ar);
            lh >>= 1, rh >>= 1;
        }
        return f(al, ar);
    }

    Monoid operator[](const int &i){
        Validate(i + zero_index_);
        return data_[offset_ + i + zero_index_];
    }

    private:
    int size_, offset_, zero_index_;
    vector<Monoid> data_;
    const F f;
    const Monoid id_;

    inline void Validate(int x) const {
        assert(1 <= x && x <= size_);
    }
};