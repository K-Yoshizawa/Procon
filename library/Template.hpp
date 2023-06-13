#pragma once

/**
 * @brief Procon Template - テンプレート
 */

#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(RALL(x))
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
inline T median(T a, T b, T c){return between(b, a, c) || between(c, a, b) ? a : (between(a, b, c) || between(c, b, a) ? b : c);}

using ll = long long;
using ull = unsigned long long;

const int mod998 = 998244353;
const int mod107 = 1000000007;
const double PI = 3.141592653589793;
const double PI2 = PI * 2;
const double PI_2 = PI / 2;

template <typename T>
using vec = vector<T>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pd = pair<double, double>;
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

template <typename T1, typename T2>
pair<T1, T2> &operator+=(pair<T1, T2> &x, const pair<T1, T2> &y){
    x.first += y.first;
    x.second += y.second;
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

template <typename T1>
double dist(pair<T1, T1> &p){
    return sqrt((double)p.first * (double)p.first + (double)p.second * (double)p.second);
}

template <typename T1, typename T2>
double dist(pair<T1, T1> &p1, pair<T2, T2> &p2){
    double dx = (double)p1.first - (double)p2.first;
    double dy = (double)p1.second - (double)p2.second;
    return sqrt(dx * dx + dy * dy);
}

template <typename T1, typename T2>
long long dist2(pair<T1, T1> &p1, pair<T2, T2> &p2){
    long long dx = (long long)p1.first - (long long)p2.first;
    long long dy = (long long)p1.second - (long long)p2.second;
    return dx * dx + dy * dy;
}

double atan2_360(double y, double x){
    double res = atan2(y, x) / PI * 180.0;
    if(res < 0.0) res += 360.0;
    return res;
}

template <typename T>
T ceil(T x, T y){
    return (x + y - 1) / y;
}

template< int mod >
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        if(n == 0) return ModInt(1);
        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using modint998 = ModInt< mod998 >;
using modint107 = ModInt< mod107 >;

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