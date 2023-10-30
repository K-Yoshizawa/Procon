#include "Template.hpp"

template <typename T>
inline long long EuclideanDist2(const pair<T, T> &p1, const pair<T, T> &p2){
    long long dx = (long long)p1.first - (long long)p2.first;
    long long dy = (long long)p1.second - (long long)p2.second;
    return dx * dx + dy * dy;
}

template <typename T>
inline long long EuclideanDist2(const pair<T, T> &p){
    return EuclideanDist2(p, make_pair(0, 0));
}

template <typename T>
inline long double EuclideanDist(const pair<T, T> &p1, const pair<T, T> &p2){
    return sqrtl((long double)EuclideanDist2(p1, p2));
}

template <typename T>
inline long double EuclideanDist(const pair<T, T> &p){
    return sqrtl((long double)EuclideanDist2(p));
}

template<typename T>
inline long long ManhattanDist(const pair<T, T> &p1, const pair<T, T> &p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

ll modpow(ll a, ll b, ll m){
    ll p = 1, q = a;
    for (int i = 0; i < 63; ++i)
    {
        if ((b & (1LL << i)) != 0)
        {
            p *= q;
            p %= m;
        }
        q *= q;
        q %= m;
    }
    return p;
}

template<typename T>
T gcd(T a, T b) {
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    if(b == 0) return a;
    else return gcd(b, a % b);
}

ull lcm(ull a, ull b) {
    return a * b / gcd(a, b);
}

string bitseq(long long x, int mini_len = 1, bool rev = false){
    string ret = "";
    while(x){
        ret.push_back('0' + (x & 1));
        x >>= 1;
    }
    while(ret.size()<mini_len) ret.push_back('0');
    if(!rev) reverse(ret.begin(), ret.end());
    return ret;
}