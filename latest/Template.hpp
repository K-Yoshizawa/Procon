#pragma once

/**
 * @file Template.hpp
 * @author log K (lX57)
 * @brief Template - テンプレート
 * @version 2.0
 * @date 2023-08-30
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
#define LOWERBOUND_IDX(x,val) (int)(lower_bound((x).begin(), (x).end(), val) - (x).begin())
#define UPPERBOUND_IDX(x,val) (int)(upper_bound((x).begin(), (x).end(), val) - (x).begin())
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
template<typename T>
inline T except(T src, T cond, T excp){return (src == cond ? excp : src);}

using ll = long long;
using ull = unsigned long long;
using ld = long double;

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
using vs = vector<string>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<double, double>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using ti3 = tuple<int, int, int>;
using tl3 = tuple<ll, ll, ll>;
using ti4 = tuple<int, int, int, int>;
using tl4 = tuple<ll, ll, ll, ll>;
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using rpq = priority_queue<T, vec<T>, greater<T>>;

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

#ifndef ONLINE_JUDGE
void dprint(){
    cerr << '\n';
}

template<class T, class... Ts>
void dprint(const T& a, const Ts&... b){
    cerr << a;
    (cerr << ... << (cerr << ' ', b));
    cerr << '\n';
}
#else
#define dprint(...) 42
#endif

template <typename T>
T ceil(T x, T y){
    return (x + y - 1) / y;
}

// Usual Template End ==================================================================================