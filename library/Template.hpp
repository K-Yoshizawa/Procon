#pragma once
/**
 * @file Template.hpp
 * @author log K (lX57)
 * @brief Template - テンプレート
 * @version 1.8
 * @date 2024-06-16
 */

#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(RALL(x))
#define REVERSE(x) reverse(ALL(x))
#define SETPRE(digit) fixed << setprecision(digit)
#define POPCOUNT(x) __builtin_popcount(x)
#define SUM(x) reduce((x).begin(), (x).end())
#define CEIL(nume, deno) ((nume) + (deno) - 1) / (deno)
#define IOTA(x) iota((x).begin(), (x).end(), 0)
#define LOWERBOUND_IDX(arr, val) (int)(lower_bound((arr).begin(), (arr).end(), val) - (arr).begin())
#define UPPERBOUND_IDX(arr, val) (int)(upper_bound((arr).begin(), (arr).end(), val) - (arr).begin())
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
template<typename T>
inline T min(vector<T> &v){return *min_element((v).begin(), (v).end());}
template<typename T>
inline T max(vector<T> &v){return *max_element((v).begin(), (v).end());}
vector<int> make_sequence(int Size){
    vector<int> ret(Size);
    IOTA(ret);
    return ret;
}
template<typename T>
void make_unique(vector<T> &v){
    sort(v.begin(), v.end());
    auto itr = unique(v.begin(), v.end());
    v.erase(itr, v.end());
}

using ll = int64_t;
using ull = uint64_t;
using ld = long double;

const long double PI = acosl(-1);
const long double PI2 = PI * 2;
const long double PI_2 = PI / 2;

const int INF_INT = numeric_limits<int>::max() >> 2;
const ll INF_LL = numeric_limits<ll>::max() >> 2;

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
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<double, double>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvpi = vector<vpi>;
using vvpl = vector<vpl>;
using vvpd = vector<vpd>;
using ti3 = tuple<int, int, int>;
using tl3 = tuple<ll, ll, ll>;
using ti4 = tuple<int, int, int, int>;
using tl4 = tuple<ll, ll, ll, ll>;
using vs = vector<string>;
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
    os << p.first << " " << p.second;
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
        os << v[i] << (i + 1 != v.size() ? "\n" : "");
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v){
    for (int i = 0; i < v.size(); ++i) is >> v[i];
    return is;
}

template<typename T1, typename T2>
vector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2> &v2){
    assert(v1.size() == v2.size());
    vector<pair<T1, T2>> v;
    for(int i = 0; i < v1.size(); ++i) v.push_back({v1[i], v2[i]});
    return v;
}

template<typename T1, typename T2>
pair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1, T2>> &v){
    vector<T1> v1;
    vector<T2> v2;
    transform(v.begin(), v.end(), back_inserter(v1), [](auto p){return p.first;});
    transform(v.begin(), v.end(), back_inserter(v2), [](auto p){return p.second;});
    return {v1, v2};
}

template<typename T1, typename T2, typename T3>
void DisassembleVectorTuple(vector<tuple<T1, T2, T3>> &v, vector<T1> &v1, vector<T2> &v2, vector<T3> &v3){
    transform(v.begin(), v.end(), back_inserter(v1), [](auto p){return get<0>(p);});
    transform(v.begin(), v.end(), back_inserter(v2), [](auto p){return get<1>(p);});
    transform(v.begin(), v.end(), back_inserter(v3), [](auto p){return get<2>(p);});
}

template<typename T1 = ll, typename T2 = ll>
pair<vector<T1>, vector<T2>> InputVectorPair(int size){
    vector<pair<T1, T2>> v(size);
    for(auto &[p, q] : v) cin >> p >> q;
    return DisassembleVectorPair(v);
}

template<typename T1, typename T2, typename T3>
void InputVectorTuple(vector<T1> &v1, vector<T2> &v2, vector<T3> &v3, int size){
    vector<tuple<T1, T2, T3>> v(size);
    for(auto &[p, q, r] : v) cin >> p >> q >> r;
    DisassembleVectorTuple(v, v1, v2, v3);
}

#ifdef LOGK
#define DEBUG(fmt, ...) fprintf(stderr, "[Debug]    " fmt __VA_OPT__(,) __VA_ARGS__)
#else
#define DEBUG(fmt, ...) 42
#endif

// ==============================================================
// 
// Main Program Start
// 
// ==============================================================