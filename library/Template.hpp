#pragma once
/**
 * @file Template.hpp
 * @author log K (lX57)
 * @brief Template - テンプレート
 * @version 1.5
 * @date 2023-10-30
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
#define IOTA(x) iota((x).begin(), (x).end(), 0)
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
template<typename T>
inline T min(vector<T> &v){return *min_element((v).begin(), (v).end());}
template<typename T>
inline T max(vector<T> &v){return *max_element((v).begin(), (v).end());}
vector<int> make_sequence(int Size){
    vector<int> ret(Size);
    IOTA(ret);
    return ret;
}

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

#ifdef LOGK
void dprint(){
    cerr << '\n';
}

template<class T, class... Ts>
void dprint(const T& a, const Ts&... b){
    cerr << "Debug : " << a;
    (cerr << ... << (cerr << " ", b));
    cerr << '\n';
}
#else
#define dprint(...) 42
#endif

template <typename T>
T ceil(T x, T y){
    return (x + y - 1) / y;
}