#include "Montgomery.hpp"

bool MillerRabin(const long long n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(!(n & 1)) return false;
    vector<long long> as;
    if(n < 4759123141LL) as = {2, 7, 61};
    else as = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    Montgomery::SetMod(n);
    long long s = 0, d = n - 1;
    while(!(d & 1)) ++s, d >>= 1;
    for(const auto &a : as){
        Montgomery x = Montgomery(a).Power(d);
        if(x != 1 && x != 0){
            long long t;
            for(t = 0; t < s; ++t){
                if(x == n - 1) break;
                x *= x;
            }
            if(t == s) return false;
        }
    }
    return true;
}