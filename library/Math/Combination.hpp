/**
 * @file Combination.hpp
 * @author log K (lX57) (Original Author : ei1333)
 * @brief Combination - 組合せ
 * @version 1.0
 * @date 2023-10-31
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Combination{
    private:
    vector<T> __fact, __rfact, __inv;

    inline T fact(int k){return __fact[k];}

    inline T rfact(int k){return __rfact[k];}

    inline T inv(int k){return __inv[k];}

    public:
    Combination(int Size) : __fact(Size + 1), __rfact(Size + 1), __inv(Size + 1){
        __fact[0] = __rfact[Size] = __inv[0] = 1;
        for(int i = 1; i <= Size; ++i) __fact[i] = __fact[i - 1] * i;
        __rfact[Size] /= __fact[Size];
        for(int i = Size - 1; i >= 0; --i) __rfact[i] = __rfact[i + 1] * (i + 1);
        for(int i = 1; i <= Size; ++i) __inv[i] = __rfact[i] * __fact[i - 1];
    }

    T P(int n, int r){
        if(r < 0 or n < r) return 0;
        return fact(n) * rfact(n - r);
    }

    T C(int n, int r){
        if(r < 0 or n < r) return 0;
        return fact(n) * rfact(r) * rfact(n - r);
    }

    T H(int n, int r){
        if(n < 0 or r < 0) return 0;
        return r == 0 ? 1 : C(n + r - 1, r);
    }
};