#include "../Common.hpp"

template<typename Monoid>
class SegmentTree{
    public:
    using F = function<Monoid(Monoid, Monoid)>;
    
    SegmentTree(const int n, F merge, const Monoid &monoid_identity) :
        f(merge), id_(monoid_identity){
        size_ = 1;
        while(size_ < n) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, id_);
    }

    SegmentTree(vector<Monoid> &a, F merge, const Monoid &monoid_identity) :
        f(merge), id_(monoid_identity){
        size_ = 1;
        while(size_ < (int)a.size()) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, id_);
        for(int i = 0; i < (int)a.size(); ++i){
            data_[size_ + i] = a[i];
        }
        for(int i = offset_; i >= 1; --i){
            data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);
        }
    }

    void Set(int k, Monoid x){
        ++k;
        Validate(k);
        int i = offset_ + k;
        data_[i] = x;
        while(i >>= 1){
            data_[i] = f(data_[2 * i], data_[2 * i + 1]);
        }
    }

    Monoid Product(int l, int r){
        ++l, ++r;
        if(l == r) return id_;
        Validate(l);
        Validate(r - 1);
        l = l + offset_, r = r + offset_;
        Monoid al = id_, ar = id_;
        while(l < r){
            if(l & 1) al = f(al, data_[l++]);
            if(r & 1) ar = f(data_[--r], ar);
            l >>= 1, r >>= 1;
        }
        return f(al, ar);
    }

    Monoid Product(){
        return data_[1];
    }

    Monoid Get(int k){
        ++k;
        Validate(k);
        return data_[offset_ + k];
    }

    Monoid operator[](const int &k){
        return Get(k);
    }

    private:
    int size_, offset_;
    vector<Monoid> data_;
    const F f;
    const Monoid id_;

    inline void Validate(int x) const {
        assert(1 <= x && x <= size_);
    }
};