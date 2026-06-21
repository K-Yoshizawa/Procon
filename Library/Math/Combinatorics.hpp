#pragma once

#include "../Common.hpp"
#include "FactorialTable.hpp"

template<typename T = mint>
class Combinatorics{
    public:
    Combinatorics(int N = 500010) : ft_(N){}

    inline T Permutation(int n, int r) const {
        if(r < 0 or n < r) return 0;
        return ft_.Factorial(n) * ft_.InverseFactorial(n - r);
    }

    inline T Combination(int n, int r) const {
        if(r < 0 or n < r) return 0;
        return ft_.Factorial(n) * ft_.InverseFactorial(r) * ft_.InverseFactorial(n - r);
    }

    inline T Homogeneous(int n, int r) const {
        if(n < 0 or r < 0) return 0;
        return r == 0 ? 1 : Combination(n + r - 1, r);
    }

    private:
    FactorialTable<T> ft_;
};