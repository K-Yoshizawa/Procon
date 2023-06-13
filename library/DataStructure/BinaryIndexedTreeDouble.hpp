#pragma once

/**
 * @brief Binary Indexed Tree (Double) - Range Add Query対応版
 */

#include "BinaryIndexedTree.hpp"

template<typename T>
struct BinaryIndexedTreeDouble{
    private:
    int sz;
    BinaryIndexedTree<T> BIT0, BIT1;

    public:
    BinaryIndexedTreeDouble(int size) : sz(size), BIT0(size), BIT1(size){}

    /**
     * @brief 1-indexで表される半開区間[left, right)に値xを加算する
     * @param left 半開区間左端
     * @param right 半開区間右端
     * @param x 加算する値
     */
    void add(int left, int right, T x){
        BIT0.add(left, -x * (left - 1));
        BIT0.add(right, x * (right - 1));
        BIT1.add(left, x);
        BIT1.add(right, -x);
    }

    /**
     * @brief 1-indexで表される要素iについて、要素1から要素iまでの総和を返す
     * @param i 閉区間[1, i]の右端
     * @return T 区間[1, i]の総和
     */
    T sum(int i){
        return BIT0.sum(i) + BIT1.sum(i) * (T)i;
    }

    /**
     * @brief 1-indexで表される半開区間[left, right)の総和を返す
     * @param left 半開区間左端
     * @param right 半開区間右端
     * @return T 区間[left, right)の総和
     */
    T query(int left, int right){
        return sum(right - 1) - sum(left - 1);
    }
};