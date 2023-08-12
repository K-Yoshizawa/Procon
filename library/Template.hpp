#pragma once

/**
 * @brief Procon Template - テンプレート
 */

#include <bits/stdc++.h>
#define overload2(_1, _2, _3, ...) _3
#define overload3(_1, _2, _3, _4, ...) _4
#define overload4(_1, _2, _3, _4, _5, ...) _5
#define rep1(loop_count) for(int i = 0; i < (loop_count); ++i)
#define rep2(loop_var, loop_count) for(int (loop_var) = 0; (loop_var) < (loop_count); ++(loop_var))
#define rep3(loop_var, loop_init, loop_count) for(int (loop_var) = (loop_init); (loop_var) < (loop_count); ++(loop_var))
#define rep4(loop_var, loop_init, loop_count, loop_add) for(int (loop_var) = 0; (loop_var) < (loop_count); (loop_var) += (loop_add))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(RALL(x))
#define REVERSE(x) reverse(ALL(x))
#define SETPRE(digit) fixed << setprecision(digit)
#define popcount(x) __builtin_popcount(x)
#define ACC(x) accumulate((x).begin(), (x).end(), 0LL)
using namespace std;

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
template <typename T>
using mat = vector<vector<T>>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
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

template<class... T>
void input(T&... vars){
    (cin >> ... >> vars);
}

void print(){
    cout << '\n';
}

template<class T, class... Ts>
void print(const T& a, const Ts&... b){
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << '\n';
}

#define INT(...) int __VA_ARGS__; input(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; input(__VA_ARGS__)

#ifndef ONLINE_JUDGE
#define dprint(...) print(__VA_ARGS__)
#else
#define dprint(...) print()
#endif

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