#pragma once

/**
 * @brief Binary Indexed Tree
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 区間に対する一点更新・区間和のクエリに対して高速かつ簡易に実装できるデータ構造。 
 */
template<typename T>
struct BinaryIndexedTree{
    private:
    vector<T> data;

    public:
    /**
     * @brief Binary Indexed Treeを要素数size、値0で初期化する。
     * @param size 配列の要素数
     */
    BinaryIndexedTree(int size){
        data.assign(++size, 0);
    }

    /**
     * @brief 1-indexで表される番号iに対して、配列の最初からiまでの閉区間の和を求める。
     * @param i 求めたい閉区間右端(1-index)
     * @return T 区間和
     */
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i & -i;
        }
        return ret;
    }

    /**
     * @brief 1-indexで表される番号iに対して、data[i]にxを加える。
     * @param i 加える場所
     * @param x 加える値
     */
    void add(int i, T x){
        while(i <= data.size()){
            data[i] += x;
            i += i & -i;
        }
    }

    /**
     * @brief 0-indexで表される半開区間[l, r)の区間和を求める。
     * @param l 区間の左端
     * @param r 区間の右端
     * @return T 区間和
     */
    T query(int l, int r){
        return sum(r) - sum(l);
    }
};