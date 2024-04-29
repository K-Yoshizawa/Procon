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
    vector<T> fact_, rfact_, inv_;

    inline T fact(int k){return fact_[k];}

    inline T rfact(int k){return rfact_[k];}

    inline T inv(int k){return inv_[k];}

    public:
    Combination(int Size) : fact_(Size + 1), rfact_(Size + 1), inv_(Size + 1){
        fact_[0] = rfact_[Size] = inv_[0] = 1;
        for(int i = 1; i <= Size; ++i) fact_[i] = fact_[i - 1] * i;
        rfact_[Size] /= fact_[Size];
        for(int i = Size - 1; i >= 0; --i) rfact_[i] = rfact_[i + 1] * (i + 1);
        for(int i = 1; i <= Size; ++i) inv_[i] = rfact_[i] * fact_[i - 1];
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