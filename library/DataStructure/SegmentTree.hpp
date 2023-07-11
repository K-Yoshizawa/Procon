#pragma once

/**
 * @brief Segment Tree - セグメント木
 */

#include <bits/stdc++.h>
using namespace std;

template<typename Monoid>
struct SegmentTree{
    private:
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> data;
    const F f; // 2つの区間をマージする二項演算
    const Monoid M1; // セグメント木の各要素の単位元

    public:
    /**
     * @brief Construct a new Segment Tree object
     * @param N セグメント木のサイズ
     * @param f 2要素をマージする演算子
     * @param M1 単位元
     * @note 各要素の初期値はM1になる。初期値を別で設定したい場合はset関数を使う。
     */
    SegmentTree(int N, const F f, const Monoid &M1) : f(f), M1(M1){
        sz = 1;
        while(sz < N) sz <<= 1;
        data.resize(2 * sz, M1);
    }

    SegmentTree() = default;

    /**
     * @brief 指定した要素に初期値を設定する。
     * @note この関数はbuild関数呼び出し前に行うこと。
     * @attention 1-indexで指定すること！
     * @param k 設定したい要素番号（1-index）
     * @param x 設定したい値
     */
    void set(int k, const Monoid &x){
        data[k + sz] = x;
    }

    /**
     * @brief セグメント木を構築する。
     * @note 初期値の設定はこの関数を呼び出す前にset関数で行うこと。
     */
    void build(){
        for(int k = sz - 1; k > 0; --k){
            data[k] = f(data[2 * k], data[2 * k + 1]);
        }
    }

    /**
     * @brief 1点更新クエリを処理する。
     * @attention 1-indexで指定すること！
     * @param k 更新したい要素番号（1-index）
     * @param x 更新したい値
     */
    void update(int k, const Monoid &x){
        k += sz;
        data[k] = x;
        while(k >>= 1){
            data[k] = f(data[2 * k], data[2 * k + 1]);
        }
    }

    /**
     * @brief 区間取得クエリを処理する。
     * @attention 1-index・半開区間で指定すること！
     * @param left 半開区間始点（1-index）
     * @param right 半開区間終点（1-index）
     * @return Monoid クエリ処理結果
     */
    Monoid query(int left, int right){
        Monoid L = M1, R = M1;
        for(left += sz, right += sz; left < right; left >>= 1, right >>= 1){
            if(left & 1) L = f(L, data[left++]);
            if(right & 1) R = f(data[--right], R);
        }
        return f(L, R);
    }

    /**
     * @brief 指定した要素の値を取得する。
     * @attention 1-indexで指定すること！
     * @param k 取得したい要素番号（1-index）
     * @return Monoid 取得結果
     */
    Monoid get(int k){
        return data[k + sz];
    }

    /**
     * @brief 全要素の値を取得する。
     * @param length 元配列の長さ
     * @return vector<Monoid> 全要素の値
     */
    vector<Monoid> get_list(int length){
        vector<Monoid> ret(length);
        for(int i = 0; i < length; ++i){
            ret[i] = get(i);
        }
        return ret;
    }
};

template<typename T>
const function<T(T, T)> SEG_MIN = [](T x, T y){return min(x, y);};
template<typename T>
const function<T(T, T)> SEG_MAX = [](T x, T y){return max(x, y);};
template<typename T>
const function<T(T, T)> SEG_SUM = [](T x, T y){return x + y;};