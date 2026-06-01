#include "Montgomery.hpp"

bool MillerRabin(const long long N){
    if(N <= 1) return false;
    if(N == 2) return true;
    if(!(N & 1)) return false;
    vector<long long> as;
    if(N < 4759123141LL) as = {2, 7, 61};
    else as = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    Montgomery::SetMod(N);
    long long s = 0, d = N - 1;
    while(!(d & 1)) ++s, d >>= 1;
    for(const auto &a : as){
        Montgomery x = Montgomery(a).Power(d);
        if(x != 1 && x != 0){
            long long t;
            for(t = 0; t < s; ++t){
                if(x == N - 1) break;
                x *= x;
            }
            if(t == s) return false;
        }
    }
    return true;
}