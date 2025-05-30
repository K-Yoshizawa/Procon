#include "../Common.hpp"

template<typename T>
struct BinaryIndexedTree{
    public:
    BinaryIndexedTree(int n) : size_(n){
        data_.resize(size_ + 1, 0);
    }

    T Sum(int i){
        T ret = 0;
        for(; i > 0; i -= i & -i) ret += data_[i];
        return ret;
    }
    
    T Sum(int l, int r){
        return Sum(r) - Sum(l - 1);
    }

    void Add(int i, T v){
        for(; i <= size_; i += i & -i) data_[i] += v;
    }

    private:
    int size_;
    vector<T> data_;
};