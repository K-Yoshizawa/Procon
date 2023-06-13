---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Procon Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"library/Template.hpp\"\n\n/**\n * @brief Procon Template\
    \ - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n#include <bits/stdc++.h>\n#define\
    \ ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define\
    \ SORT(x) sort(ALL(x))\n#define RSORT(x) sort(RALL(x))\n#define SETPRE(digit)\
    \ fixed << setprecision(digit)\n#define popcount(x) __builtin_popcount(x)\n#define\
    \ ACC(x) accumulate((x).begin(), (x).end(), 0LL)\nusing namespace std;\n\ninline\
    \ string Yn(bool flag){return (flag) ? \"Yes\" : \"No\";}\ninline bool YnPrint(bool\
    \ flag){cout << Yn(flag) << endl;return flag;}\ninline string YN(bool flag){return\
    \ (flag) ? \"YES\" : \"NO\";}\ninline bool YNPrint(bool flag){cout << YN(flag)\
    \ << endl;return flag;}\ntemplate<class T>\nbool minin(T &src, const T &cmp){if(src\
    \ > cmp){src = cmp; return true;}return false;}\ntemplate<class T>\nbool maxin(T\
    \ &src, const T &cmp){if(src < cmp){src = cmp; return true;}return false;}\ntemplate<typename\
    \ T>\ninline bool between(T min, T x, T max){return min <= x && x <= max;}\ntemplate<typename\
    \ T>\ninline T median(T a, T b, T c){return between(b, a, c) || between(c, a,\
    \ b) ? a : (between(a, b, c) || between(c, b, a) ? b : c);}\n\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\n\nconst int mod998 = 998244353;\nconst\
    \ int mod107 = 1000000007;\nconst double PI = 3.141592653589793;\nconst double\
    \ PI2 = PI * 2;\nconst double PI_2 = PI / 2;\n\ntemplate <typename T>\nusing vec\
    \ = vector<T>;\nusing pi = pair<int, int>;\nusing pll = pair<ll, ll>;\nusing pd\
    \ = pair<double, double>;\ntemplate <typename T>\nusing pq = priority_queue<T>;\n\
    template <typename T>\nusing rpq = priority_queue<T, vec<T>, greater<T>>;\n\n\
    const int dx4[4] = {1, 0, -1, 0};\nconst int dy4[4] = {0, -1, 0, 1};\nconst int\
    \ dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};\nconst int dy8[8] = {0, -1, -1, -1, 0,\
    \ 1, 1, 1};\n\ntemplate <typename T1, typename T2>\nostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p){\n    os << \"{\" << p.first << \" \" << p.second\
    \ << \"}\";\n    return os;\n}\n\ntemplate <typename T1, typename T2>\nistream\
    \ &operator>>(istream &is, pair<T1, T2> &p){\n    is >> p.first >> p.second;\n\
    \    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os,\
    \ vector<T> &v){\n    for (int i = 0; i < v.size(); ++i){\n        os << v[i]\
    \ << (i + 1 != v.size() ? \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, vector<vector<T>> &v){\n    for\
    \ (int i = 0; i < v.size(); ++i){\n        os << v[i] << \"\\n\";\n    }\n   \
    \ return os;\n}\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T>\
    \ &v){\n    for (int i = 0; i < v.size(); ++i) is >> v[i];\n    return is;\n}\n\
    \ntemplate <typename T>\nistream &operator>>(istream &is, valarray<T> &v){\n \
    \   for (int i = 0; i < v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate\
    \ <typename T1, typename T2>\npair<T1, T2> &operator+=(pair<T1, T2> &x, const\
    \ pair<T1, T2> &y){\n    x.first += y.first;\n    x.second += y.second;\n    return\
    \ x;\n}\n\nll modpow(ll a, ll b, ll m){\n    ll p = 1, q = a;\n    for (int i\
    \ = 0; i < 63; ++i)\n    {\n        if ((b & (1LL << i)) != 0)\n        {\n  \
    \          p *= q;\n            p %= m;\n        }\n        q *= q;\n        q\
    \ %= m;\n    }\n    return p;\n}\n\ntemplate <typename T1>\ndouble dist(pair<T1,\
    \ T1> &p){\n    return sqrt((double)p.first * (double)p.first + (double)p.second\
    \ * (double)p.second);\n}\n\ntemplate <typename T1, typename T2>\ndouble dist(pair<T1,\
    \ T1> &p1, pair<T2, T2> &p2){\n    double dx = (double)p1.first - (double)p2.first;\n\
    \    double dy = (double)p1.second - (double)p2.second;\n    return sqrt(dx *\
    \ dx + dy * dy);\n}\n\ntemplate <typename T1, typename T2>\nlong long dist2(pair<T1,\
    \ T1> &p1, pair<T2, T2> &p2){\n    long long dx = (long long)p1.first - (long\
    \ long)p2.first;\n    long long dy = (long long)p1.second - (long long)p2.second;\n\
    \    return dx * dx + dy * dy;\n}\n\ndouble atan2_360(double y, double x){\n \
    \   double res = atan2(y, x) / PI * 180.0;\n    if(res < 0.0) res += 360.0;\n\
    \    return res;\n}\n\ntemplate <typename T>\nT ceil(T x, T y){\n    return (x\
    \ + y - 1) / y;\n}\n\ntemplate< int mod >\nstruct ModInt {\n    int x;\n\n   \
    \ ModInt() : x(0) {}\n\n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y)\
    \ % mod) % mod) {}\n\n    ModInt &operator+=(const ModInt &p) {\n        if((x\
    \ += p.x) >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator-=(const\
    \ ModInt &p) {\n        if((x += mod - p.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n\n    ModInt &operator*=(const ModInt &p) {\n        x = (int)\
    \ (1LL * x * p.x % mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n\n\
    \    ModInt operator-() const { return ModInt(-x); }\n\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n\n    bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n\n    bool operator!=(const ModInt &p)\
    \ const { return x != p.x; }\n\n    ModInt inverse() const {\n        int a =\
    \ x, b = mod, u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n\
    \            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n\
    \        return ModInt(u);\n    }\n\n    ModInt pow(int64_t n) const {\n     \
    \   if(n == 0) return ModInt(1);\n        ModInt ret(1), mul(x);\n        while(n\
    \ > 0) {\n            if(n & 1) ret *= mul;\n            mul *= mul;\n       \
    \     n >>= 1;\n        }\n        return ret;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, ModInt &a) {\n        int64_t t;\n        is >> t;\n\
    \        a = ModInt< mod >(t);\n        return (is);\n    }\n\n    static int\
    \ get_mod() { return mod; }\n};\n\nusing modint998 = ModInt< mod998 >;\nusing\
    \ modint107 = ModInt< mod107 >;\n\ntemplate<typename T>\nT gcd(T a, T b) {\n \
    \   if(a < 0) a = -a;\n    if(b < 0) b = -b;\n    if(b == 0) return a;\n    else\
    \ return gcd(b, a % b);\n}\n\null lcm(ull a, ull b) {\n    return a * b / gcd(a,\
    \ b);\n}\n"
  code: "#pragma once\n\n/**\n * @brief Procon Template - \u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n */\n\n#include <bits/stdc++.h>\n#define ALL(x) (x).begin(), (x).end()\n\
    #define RALL(x) (x).rbegin(), (x).rend()\n#define SORT(x) sort(ALL(x))\n#define\
    \ RSORT(x) sort(RALL(x))\n#define SETPRE(digit) fixed << setprecision(digit)\n\
    #define popcount(x) __builtin_popcount(x)\n#define ACC(x) accumulate((x).begin(),\
    \ (x).end(), 0LL)\nusing namespace std;\n\ninline string Yn(bool flag){return\
    \ (flag) ? \"Yes\" : \"No\";}\ninline bool YnPrint(bool flag){cout << Yn(flag)\
    \ << endl;return flag;}\ninline string YN(bool flag){return (flag) ? \"YES\" :\
    \ \"NO\";}\ninline bool YNPrint(bool flag){cout << YN(flag) << endl;return flag;}\n\
    template<class T>\nbool minin(T &src, const T &cmp){if(src > cmp){src = cmp; return\
    \ true;}return false;}\ntemplate<class T>\nbool maxin(T &src, const T &cmp){if(src\
    \ < cmp){src = cmp; return true;}return false;}\ntemplate<typename T>\ninline\
    \ bool between(T min, T x, T max){return min <= x && x <= max;}\ntemplate<typename\
    \ T>\ninline T median(T a, T b, T c){return between(b, a, c) || between(c, a,\
    \ b) ? a : (between(a, b, c) || between(c, b, a) ? b : c);}\n\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\n\nconst int mod998 = 998244353;\nconst\
    \ int mod107 = 1000000007;\nconst double PI = 3.141592653589793;\nconst double\
    \ PI2 = PI * 2;\nconst double PI_2 = PI / 2;\n\ntemplate <typename T>\nusing vec\
    \ = vector<T>;\nusing pi = pair<int, int>;\nusing pll = pair<ll, ll>;\nusing pd\
    \ = pair<double, double>;\ntemplate <typename T>\nusing pq = priority_queue<T>;\n\
    template <typename T>\nusing rpq = priority_queue<T, vec<T>, greater<T>>;\n\n\
    const int dx4[4] = {1, 0, -1, 0};\nconst int dy4[4] = {0, -1, 0, 1};\nconst int\
    \ dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};\nconst int dy8[8] = {0, -1, -1, -1, 0,\
    \ 1, 1, 1};\n\ntemplate <typename T1, typename T2>\nostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p){\n    os << \"{\" << p.first << \" \" << p.second\
    \ << \"}\";\n    return os;\n}\n\ntemplate <typename T1, typename T2>\nistream\
    \ &operator>>(istream &is, pair<T1, T2> &p){\n    is >> p.first >> p.second;\n\
    \    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os,\
    \ vector<T> &v){\n    for (int i = 0; i < v.size(); ++i){\n        os << v[i]\
    \ << (i + 1 != v.size() ? \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, vector<vector<T>> &v){\n    for\
    \ (int i = 0; i < v.size(); ++i){\n        os << v[i] << \"\\n\";\n    }\n   \
    \ return os;\n}\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T>\
    \ &v){\n    for (int i = 0; i < v.size(); ++i) is >> v[i];\n    return is;\n}\n\
    \ntemplate <typename T>\nistream &operator>>(istream &is, valarray<T> &v){\n \
    \   for (int i = 0; i < v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate\
    \ <typename T1, typename T2>\npair<T1, T2> &operator+=(pair<T1, T2> &x, const\
    \ pair<T1, T2> &y){\n    x.first += y.first;\n    x.second += y.second;\n    return\
    \ x;\n}\n\nll modpow(ll a, ll b, ll m){\n    ll p = 1, q = a;\n    for (int i\
    \ = 0; i < 63; ++i)\n    {\n        if ((b & (1LL << i)) != 0)\n        {\n  \
    \          p *= q;\n            p %= m;\n        }\n        q *= q;\n        q\
    \ %= m;\n    }\n    return p;\n}\n\ntemplate <typename T1>\ndouble dist(pair<T1,\
    \ T1> &p){\n    return sqrt((double)p.first * (double)p.first + (double)p.second\
    \ * (double)p.second);\n}\n\ntemplate <typename T1, typename T2>\ndouble dist(pair<T1,\
    \ T1> &p1, pair<T2, T2> &p2){\n    double dx = (double)p1.first - (double)p2.first;\n\
    \    double dy = (double)p1.second - (double)p2.second;\n    return sqrt(dx *\
    \ dx + dy * dy);\n}\n\ntemplate <typename T1, typename T2>\nlong long dist2(pair<T1,\
    \ T1> &p1, pair<T2, T2> &p2){\n    long long dx = (long long)p1.first - (long\
    \ long)p2.first;\n    long long dy = (long long)p1.second - (long long)p2.second;\n\
    \    return dx * dx + dy * dy;\n}\n\ndouble atan2_360(double y, double x){\n \
    \   double res = atan2(y, x) / PI * 180.0;\n    if(res < 0.0) res += 360.0;\n\
    \    return res;\n}\n\ntemplate <typename T>\nT ceil(T x, T y){\n    return (x\
    \ + y - 1) / y;\n}\n\ntemplate< int mod >\nstruct ModInt {\n    int x;\n\n   \
    \ ModInt() : x(0) {}\n\n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y)\
    \ % mod) % mod) {}\n\n    ModInt &operator+=(const ModInt &p) {\n        if((x\
    \ += p.x) >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator-=(const\
    \ ModInt &p) {\n        if((x += mod - p.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n\n    ModInt &operator*=(const ModInt &p) {\n        x = (int)\
    \ (1LL * x * p.x % mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n\n\
    \    ModInt operator-() const { return ModInt(-x); }\n\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n\n    bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n\n    bool operator!=(const ModInt &p)\
    \ const { return x != p.x; }\n\n    ModInt inverse() const {\n        int a =\
    \ x, b = mod, u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n\
    \            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n\
    \        return ModInt(u);\n    }\n\n    ModInt pow(int64_t n) const {\n     \
    \   if(n == 0) return ModInt(1);\n        ModInt ret(1), mul(x);\n        while(n\
    \ > 0) {\n            if(n & 1) ret *= mul;\n            mul *= mul;\n       \
    \     n >>= 1;\n        }\n        return ret;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, ModInt &a) {\n        int64_t t;\n        is >> t;\n\
    \        a = ModInt< mod >(t);\n        return (is);\n    }\n\n    static int\
    \ get_mod() { return mod; }\n};\n\nusing modint998 = ModInt< mod998 >;\nusing\
    \ modint107 = ModInt< mod107 >;\n\ntemplate<typename T>\nT gcd(T a, T b) {\n \
    \   if(a < 0) a = -a;\n    if(b < 0) b = -b;\n    if(b == 0) return a;\n    else\
    \ return gcd(b, a % b);\n}\n\null lcm(ull a, ull b) {\n    return a * b / gcd(a,\
    \ b);\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/Template.hpp
  requiredBy: []
  timestamp: '2023-06-13 11:03:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Template.hpp
layout: document
redirect_from:
- /library/library/Template.hpp
- /library/library/Template.hpp.html
title: "Procon Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
