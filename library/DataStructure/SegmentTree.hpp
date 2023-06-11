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
    SegmentTree(int N, const F f, const Monoid &M1) : f(f), M1(M1){
        sz = 1;
        while(sz < N) sz <<= 1;
        data.resize(2 * sz, M1);
    }

    SegmentTree() = default;

    void set(int k, const Monoid &x){
        data[k + sz] = x;
    }

    void build(){
        for(int k = sz - 1; k > 0; --k){
            data[k] = f(data[2 * k], data[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x){
        k += sz;
        data[k] = x;
        while(k >>= 1){
            data[k] = f(data[2 * k], data[2 * k + 1]);
        }
    }

    Monoid query(int left, int right){
        Monoid L = M1, R = M1;
        for(left += sz, right += sz; left < right; left >>= 1, right >>= 1){
            if(left & 1) L = f(L, data[left++]);
            if(right & 1) R = f(data[--right], R);
        }
        return f(L, R);
    }

    Monoid get(int k){
        return data[k + sz];
    }
};

template<typename T>
const function<T(T, T)> SEG_MIN = [](T x, T y){return min(x, y);};
template<typename T>
const function<T(T, T)> SEG_MAX = [](T x, T y){return max(x, y);};
template<typename T>
const function<T(T, T)> SEG_SUM = [](T x, T y){return x + y;};