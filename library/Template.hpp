#pragma once

/**
 * @brief Procon Template - テンプレート
 */

#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(RALL(x))
#define REVERSE(x) reverse(ALL(x))
#define SETPRE(digit) fixed << setprecision(digit)
#define popcount(x) __builtin_popcount(x)
#define ACC(x) accumulate((x).begin(), (x).end(), 0LL)
using namespace std;

#ifndef ONLINE_JUDGE
void dprint(){
    cerr << endl;
}
template<class Head, class... Tail>
void dprint(Head&& head, Tail&&... tail){
    cerr << head << " ";
    dprint(forward<Tail>(tail)...);
}
#else
template<class Head, class... Tail>
void dprint(Head&& head, Tail&&... tail){}
#endif

inline string Yn(bool flag){return (flag) ? "Yes" : "No";}
inline bool YnPrint(bool flag){cout << Yn(flag) << endl;return flag;}
inline string YN(bool flag){return (flag) ? "YES" : "NO";}
inline bool YNPrint(bool flag){cout << YN(flag) << endl;return flag;}
template<class T>
bool minin(T &src, const T &cmp){if(src > cmp){src = cmp; return true;}return false;}
template<class T>
bool maxin(T &src, const T &cmp){if(src < cmp){src = cmp; return true;}return false;}
template<typename T>
inline bool between(T min, T x, T max){return min <= x && x <= max;}
template<typename T>
inline bool ingrid(T y, T x, T ymax, T xmax){return between(0, y, ymax - 1) && between(0, x, xmax - 1);}
template<typename T>
inline T median(T a, T b, T c){return between(b, a, c) || between(c, a, b) ? a : (between(a, b, c) || between(c, b, a) ? b : c);}

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const long double PI = acosl(-1);
const long double PI2 = PI * 2;
const long double PI_2 = PI / 2;

const int INF_INT = numeric_limits<int>::max() / 2;
const long long INF_LL = numeric_limits<long long>::max() / 2LL;

template <typename T>
using vec = vector<T>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pd = pair<double, double>;
using ti3 = tuple<int, int, int>;
using tl3 = tuple<ll, ll, ll>;
using ti4 = tuple<int, int, int, int>;
using tl4 = tuple<ll, ll, ll, ll>;
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using rpq = priority_queue<T, vec<T>, greater<T>>;

const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, -1, 0, 1};
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p){
    os << "{" << p.first << " " << p.second << "}";
    return os;
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p){
    is >> p.first >> p.second;
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v){
    for (int i = 0; i < v.size(); ++i){
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> &v){
    for (int i = 0; i < v.size(); ++i){
        os << v[i] << "\n";
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v){
    for (int i = 0; i < v.size(); ++i) is >> v[i];
    return is;
}

template <typename T>
istream &operator>>(istream &is, valarray<T> &v){
    for (int i = 0; i < v.size(); ++i) is >> v[i];
    return is;
}

template <typename T1, typename T2, typename T3>
pair<T1, T2> &operator+=(pair<T1, T2> &x, const T3 &y){
    x.first += y;
    x.second += y;
    return x;
}

template <typename T1, typename T2, typename T3>
pair<T1, T2> &operator-=(pair<T1, T2> &x, const T3 &y){
    x.first -= y;
    x.second -= y;
    return x;
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
inline double EuclideanDist(const pair<T, T> &p1, const pair<T, T> &p2){
    return sqrt((double)EuclideanDist2(p1, p2));
}

template <typename T>
inline double EuclideanDist(const pair<T, T> &p){
    return sqrt((double)EuclideanDist2(p));
}

template<typename T>
inline long long ManhattanDist(const pair<T, T> &p1, const pair<T, T> &p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

template <typename T>
T ceil(T x, T y){
    return (x + y - 1) / y;
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

string bitseq(long long x){
    string ret = "";
    while(x){
        ret.push_back('0' + (x & 1));
        x >>= 1;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}