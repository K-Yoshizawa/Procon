#pragma once

#include "../Common.hpp"
#include "ModInt.hpp"

template<typename T = mint>
class FactorialTable{
    public:
    FactorialTable(int N) : fact_(N + 1), ifact_(N + 1), inv_(N + 1){
        fact_[0] = ifact_[N] = inv_[0] = 1;
        for(int i = 1; i <= N; ++i) fact_[i] = fact_[i - 1] * i;
        ifact_[N] /= fact_[N];
        for(int i = N - 1; i >= 0; --i) ifact_[i] = ifact_[i + 1] * (i + 1);
        for(int i = 1; i <= N; ++i) inv_[i] = ifact_[i] * fact_[i - 1];
    }

    inline T Factorial(int x) const {
        return fact_.at(x);
    }

    inline T InverseFactorial(int x) const {
        return ifact_.at(x);
    }

    inline T Inverse(int x) const {
        return inv_.at(x);
    }

    private:
    vector<T> fact_, ifact_, inv_;
};