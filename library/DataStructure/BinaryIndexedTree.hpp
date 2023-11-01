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
    int __Size;
    vector<T> __Data;
    bool __ZeroIndex;

    public:
    /**
     * @brief Binary Indexed Tree を要素数 `Size` で初期化する
     * @param Size 要素数
     * @param ZeroIndex `0-index` で扱いたいか (default = `false`)
     */
    BinaryIndexedTree(int Size, bool ZeroIndex = false) : __Size(Size), __ZeroIndex(ZeroIndex){
        __Data.resize(__Size + 1, 0);
    }

    T sum(int i){
        T ret = 0;
        i += __ZeroIndex;
        for(; i > 0; i -= i & -i) ret += __Data[i];
        return ret;
    }

    void add(int i, T x){
        i += __ZeroIndex;
        for(; i <= __Size; i += i & -i) __Data[i] += x;
    }

    T query(int l, int r){
        l += __ZeroIndex, r += __ZeroIndex;
        return sum(r) - sum(l - 1);
    }
};