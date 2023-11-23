#include "Template.hpp"

template<typename T>
struct combination{
    vector<T> fn, rn, in;

    combination(int sz) : fn(sz + 1), rn(sz + 1), in(sz + 1){
        fn[0] = rn[sz] = in[0] = 1;
        for(int i = 1; i <= sz; ++i) fn[i] = fn[i - 1] * i;
        rn[sz] /= fn[sz];
        for(int i = sz - 1; i >= 0; --i) rn[i] = rn[i + 1] * (i + 1);
        for(int i = 1; i <= sz; ++i) in[i] = rn[i] * fn[i - 1];
    }

    T fact(int k){return fn[k];}
    T rfact(int k){return rn[k];}
    T inv(int k){return in[k];}

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