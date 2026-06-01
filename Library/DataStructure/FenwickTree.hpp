#include "../Common.hpp"

template<typename Ordered>
struct FenwickTree{
    public:
    FenwickTree(int N) : size_(N){
        data_.resize(size_ + 1, 0);
    }

    Ordered Sum(int i){
        Ordered ret = 0;
        for(; i > 0; i -= i & -i) ret += data_[i];
        return ret;
    }
    
    Ordered Sum(int l, int r){
        return Sum(r) - Sum(l - 1);
    }

    void Add(int i, Ordered v){
        for(; i <= size_; i += i & -i) data_[i] += v;
    }

    private:
    int size_;
    vector<Ordered> data_;
};