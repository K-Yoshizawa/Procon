/**
 * @file BinaryIndexedTree.hpp
 * @author log K (lX57)
 * @brief Binary Indexed Tree
 * @version 2.0
 * @date 2023-11-01
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BinaryIndexedTree{
    private:
    int size_;
    vector<T> data_;
    bool zeroindex_;

    public:
    /**
     * @brief Binary Indexed Tree を要素数 `Size` で初期化する
     * @param Size 要素数
     * @param ZeroIndex `0-index` で扱いたいか (default = `false`)
     */
    BinaryIndexedTree(int Size, bool ZeroIndex = false) : size_(Size), zeroindex_(ZeroIndex){
        data_.resize(size_ + 1, 0);
    }

    T sum(int i){
        T ret = 0;
        i += zeroindex_;
        for(; i > 0; i -= i & -i) ret += data_[i];
        return ret;
    }

    void add(int i, T x){
        i += zeroindex_;
        for(; i <= size_; i += i & -i) data_[i] += x;
    }

    T query(int l, int r){
        l += zeroindex_, r += zeroindex_;
        return sum(r) - sum(l - 1);
    }
};