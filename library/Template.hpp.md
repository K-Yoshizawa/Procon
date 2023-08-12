---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DPL-1-D.test.cpp
    title: verify/AOJ-DPL-1-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yuki-1995.test.cpp
    title: verify/yuki-1995.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Procon Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"library/Template.hpp\"\n\n/**\n * @brief Procon Template\
    \ - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n#include <bits/stdc++.h>\n#define\
    \ overload2(_1, _2, _3, ...) _3\n#define overload3(_1, _2, _3, _4, ...) _4\n#define\
    \ overload4(_1, _2, _3, _4, _5, ...) _5\n#define rep1(loop_count) for(int i =\
    \ 0; i < (loop_count); ++i)\n#define rep2(loop_var, loop_count) for(int (loop_var)\
    \ = 0; (loop_var) < (loop_count); ++(loop_var))\n#define rep3(loop_var, loop_init,\
    \ loop_count) for(int (loop_var) = (loop_init); (loop_var) < (loop_count); ++(loop_var))\n\
    #define rep4(loop_var, loop_init, loop_count, loop_add) for(int (loop_var) = 0;\
    \ (loop_var) < (loop_count); (loop_var) += (loop_add))\n#define rep(...) overload4(__VA_ARGS__,\
    \ rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define ALL(x) (x).begin(), (x).end()\n\
    #define RALL(x) (x).rbegin(), (x).rend()\n#define SORT(x) sort(ALL(x))\n#define\
    \ RSORT(x) sort(RALL(x))\n#define REVERSE(x) reverse(ALL(x))\n#define SETPRE(digit)\
    \ fixed << setprecision(digit)\n#define popcount(x) __builtin_popcount(x)\n#define\
    \ ACC(x) accumulate((x).begin(), (x).end(), 0LL)\nusing namespace std;\n\ninline\
    \ string Yn(bool flag){return (flag) ? \"Yes\" : \"No\";}\ninline bool YnPrint(bool\
    \ flag){cout << Yn(flag) << endl;return flag;}\ninline string YN(bool flag){return\
    \ (flag) ? \"YES\" : \"NO\";}\ninline bool YNPrint(bool flag){cout << YN(flag)\
    \ << endl;return flag;}\ntemplate<class T>\nbool minin(T &src, const T &cmp){if(src\
    \ > cmp){src = cmp; return true;}return false;}\ntemplate<class T>\nbool maxin(T\
    \ &src, const T &cmp){if(src < cmp){src = cmp; return true;}return false;}\ntemplate<typename\
    \ T>\ninline bool between(T min, T x, T max){return min <= x && x <= max;}\ntemplate<typename\
    \ T>\ninline bool ingrid(T y, T x, T ymax, T xmax){return between(0, y, ymax -\
    \ 1) && between(0, x, xmax - 1);}\ntemplate<typename T>\ninline T median(T a,\
    \ T b, T c){return between(b, a, c) || between(c, a, b) ? a : (between(a, b, c)\
    \ || between(c, b, a) ? b : c);}\n\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ld = long double;\n\nconst long double PI = acosl(-1);\nconst\
    \ long double PI2 = PI * 2;\nconst long double PI_2 = PI / 2;\n\nconst int INF_INT\
    \ = numeric_limits<int>::max() / 2;\nconst long long INF_LL = numeric_limits<long\
    \ long>::max() / 2LL;\n\ntemplate <typename T>\nusing vec = vector<T>;\ntemplate\
    \ <typename T>\nusing mat = vector<vector<T>>;\nusing vi = vector<int>;\nusing\
    \ vvi = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vl = vector<ll>;\nusing\
    \ vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing pi = pair<int, int>;\nusing\
    \ pll = pair<ll, ll>;\nusing pd = pair<double, double>;\nusing ti3 = tuple<int,\
    \ int, int>;\nusing tl3 = tuple<ll, ll, ll>;\nusing ti4 = tuple<int, int, int,\
    \ int>;\nusing tl4 = tuple<ll, ll, ll, ll>;\ntemplate <typename T>\nusing pq =\
    \ priority_queue<T>;\ntemplate <typename T>\nusing rpq = priority_queue<T, vec<T>,\
    \ greater<T>>;\n\nconst int dx4[4] = {1, 0, -1, 0};\nconst int dy4[4] = {0, -1,\
    \ 0, 1};\nconst int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};\nconst int dy8[8] =\
    \ {0, -1, -1, -1, 0, 1, 1, 1};\n\ntemplate <typename T1, typename T2>\nostream\
    \ &operator<<(ostream &os, const pair<T1, T2> &p){\n    os << \"{\" << p.first\
    \ << \" \" << p.second << \"}\";\n    return os;\n}\n\ntemplate <typename T1,\
    \ typename T2>\nistream &operator>>(istream &is, pair<T1, T2> &p){\n    is >>\
    \ p.first >> p.second;\n    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, vector<T> &v){\n    for (int i = 0; i < v.size(); ++i){\n        os <<\
    \ v[i] << (i + 1 != v.size() ? \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, vector<vector<T>> &v){\n    for\
    \ (int i = 0; i < v.size(); ++i){\n        os << v[i] << \"\\n\";\n    }\n   \
    \ return os;\n}\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T>\
    \ &v){\n    for (int i = 0; i < v.size(); ++i) is >> v[i];\n    return is;\n}\n\
    \ntemplate <typename T>\nistream &operator>>(istream &is, valarray<T> &v){\n \
    \   for (int i = 0; i < v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate<class...\
    \ T>\nvoid input(T&... vars){\n    (cin >> ... >> vars);\n}\n\nvoid print(){\n\
    \    cout << '\\n';\n}\n\ntemplate<class T, class... Ts>\nvoid print(const T&\
    \ a, const Ts&... b){\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n\
    \    cout << '\\n';\n}\n\n#define INT(...) int __VA_ARGS__; input(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__; input(__VA_ARGS__)\n\n#ifndef ONLINE_JUDGE\n#define\
    \ dprint(...) print(__VA_ARGS__)\n#else\n#define dprint(...) print()\n#endif\n\
    \ntemplate <typename T1, typename T2, typename T3>\npair<T1, T2> &operator+=(pair<T1,\
    \ T2> &x, const T3 &y){\n    x.first += y;\n    x.second += y;\n    return x;\n\
    }\n\ntemplate <typename T1, typename T2, typename T3>\npair<T1, T2> &operator-=(pair<T1,\
    \ T2> &x, const T3 &y){\n    x.first -= y;\n    x.second -= y;\n    return x;\n\
    }\n\nll modpow(ll a, ll b, ll m){\n    ll p = 1, q = a;\n    for (int i = 0; i\
    \ < 63; ++i)\n    {\n        if ((b & (1LL << i)) != 0)\n        {\n         \
    \   p *= q;\n            p %= m;\n        }\n        q *= q;\n        q %= m;\n\
    \    }\n    return p;\n}\n\ntemplate <typename T>\ninline long long EuclideanDist2(const\
    \ pair<T, T> &p1, const pair<T, T> &p2){\n    long long dx = (long long)p1.first\
    \ - (long long)p2.first;\n    long long dy = (long long)p1.second - (long long)p2.second;\n\
    \    return dx * dx + dy * dy;\n}\n\ntemplate <typename T>\ninline long long EuclideanDist2(const\
    \ pair<T, T> &p){\n    return EuclideanDist2(p, make_pair(0, 0));\n}\n\ntemplate\
    \ <typename T>\ninline double EuclideanDist(const pair<T, T> &p1, const pair<T,\
    \ T> &p2){\n    return sqrt((double)EuclideanDist2(p1, p2));\n}\n\ntemplate <typename\
    \ T>\ninline double EuclideanDist(const pair<T, T> &p){\n    return sqrt((double)EuclideanDist2(p));\n\
    }\n\ntemplate<typename T>\ninline long long ManhattanDist(const pair<T, T> &p1,\
    \ const pair<T, T> &p2){\n    return abs(p1.first - p2.first) + abs(p1.second\
    \ - p2.second);\n}\n\ntemplate <typename T>\nT ceil(T x, T y){\n    return (x\
    \ + y - 1) / y;\n}\n\ntemplate<typename T>\nT gcd(T a, T b) {\n    if(a < 0) a\
    \ = -a;\n    if(b < 0) b = -b;\n    if(b == 0) return a;\n    else return gcd(b,\
    \ a % b);\n}\n\null lcm(ull a, ull b) {\n    return a * b / gcd(a, b);\n}\n\n\
    string bitseq(long long x){\n    string ret = \"\";\n    while(x){\n        ret.push_back('0'\
    \ + (x & 1));\n        x >>= 1;\n    }\n    reverse(ret.begin(), ret.end());\n\
    \    return ret;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Procon Template - \u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n */\n\n#include <bits/stdc++.h>\n#define overload2(_1, _2, _3, ...)\
    \ _3\n#define overload3(_1, _2, _3, _4, ...) _4\n#define overload4(_1, _2, _3,\
    \ _4, _5, ...) _5\n#define rep1(loop_count) for(int i = 0; i < (loop_count); ++i)\n\
    #define rep2(loop_var, loop_count) for(int (loop_var) = 0; (loop_var) < (loop_count);\
    \ ++(loop_var))\n#define rep3(loop_var, loop_init, loop_count) for(int (loop_var)\
    \ = (loop_init); (loop_var) < (loop_count); ++(loop_var))\n#define rep4(loop_var,\
    \ loop_init, loop_count, loop_add) for(int (loop_var) = 0; (loop_var) < (loop_count);\
    \ (loop_var) += (loop_add))\n#define rep(...) overload4(__VA_ARGS__, rep4, rep3,\
    \ rep2, rep1)(__VA_ARGS__)\n#define ALL(x) (x).begin(), (x).end()\n#define RALL(x)\
    \ (x).rbegin(), (x).rend()\n#define SORT(x) sort(ALL(x))\n#define RSORT(x) sort(RALL(x))\n\
    #define REVERSE(x) reverse(ALL(x))\n#define SETPRE(digit) fixed << setprecision(digit)\n\
    #define popcount(x) __builtin_popcount(x)\n#define ACC(x) accumulate((x).begin(),\
    \ (x).end(), 0LL)\nusing namespace std;\n\ninline string Yn(bool flag){return\
    \ (flag) ? \"Yes\" : \"No\";}\ninline bool YnPrint(bool flag){cout << Yn(flag)\
    \ << endl;return flag;}\ninline string YN(bool flag){return (flag) ? \"YES\" :\
    \ \"NO\";}\ninline bool YNPrint(bool flag){cout << YN(flag) << endl;return flag;}\n\
    template<class T>\nbool minin(T &src, const T &cmp){if(src > cmp){src = cmp; return\
    \ true;}return false;}\ntemplate<class T>\nbool maxin(T &src, const T &cmp){if(src\
    \ < cmp){src = cmp; return true;}return false;}\ntemplate<typename T>\ninline\
    \ bool between(T min, T x, T max){return min <= x && x <= max;}\ntemplate<typename\
    \ T>\ninline bool ingrid(T y, T x, T ymax, T xmax){return between(0, y, ymax -\
    \ 1) && between(0, x, xmax - 1);}\ntemplate<typename T>\ninline T median(T a,\
    \ T b, T c){return between(b, a, c) || between(c, a, b) ? a : (between(a, b, c)\
    \ || between(c, b, a) ? b : c);}\n\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ld = long double;\n\nconst long double PI = acosl(-1);\nconst\
    \ long double PI2 = PI * 2;\nconst long double PI_2 = PI / 2;\n\nconst int INF_INT\
    \ = numeric_limits<int>::max() / 2;\nconst long long INF_LL = numeric_limits<long\
    \ long>::max() / 2LL;\n\ntemplate <typename T>\nusing vec = vector<T>;\ntemplate\
    \ <typename T>\nusing mat = vector<vector<T>>;\nusing vi = vector<int>;\nusing\
    \ vvi = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vl = vector<ll>;\nusing\
    \ vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing pi = pair<int, int>;\nusing\
    \ pll = pair<ll, ll>;\nusing pd = pair<double, double>;\nusing ti3 = tuple<int,\
    \ int, int>;\nusing tl3 = tuple<ll, ll, ll>;\nusing ti4 = tuple<int, int, int,\
    \ int>;\nusing tl4 = tuple<ll, ll, ll, ll>;\ntemplate <typename T>\nusing pq =\
    \ priority_queue<T>;\ntemplate <typename T>\nusing rpq = priority_queue<T, vec<T>,\
    \ greater<T>>;\n\nconst int dx4[4] = {1, 0, -1, 0};\nconst int dy4[4] = {0, -1,\
    \ 0, 1};\nconst int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};\nconst int dy8[8] =\
    \ {0, -1, -1, -1, 0, 1, 1, 1};\n\ntemplate <typename T1, typename T2>\nostream\
    \ &operator<<(ostream &os, const pair<T1, T2> &p){\n    os << \"{\" << p.first\
    \ << \" \" << p.second << \"}\";\n    return os;\n}\n\ntemplate <typename T1,\
    \ typename T2>\nistream &operator>>(istream &is, pair<T1, T2> &p){\n    is >>\
    \ p.first >> p.second;\n    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, vector<T> &v){\n    for (int i = 0; i < v.size(); ++i){\n        os <<\
    \ v[i] << (i + 1 != v.size() ? \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, vector<vector<T>> &v){\n    for\
    \ (int i = 0; i < v.size(); ++i){\n        os << v[i] << \"\\n\";\n    }\n   \
    \ return os;\n}\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T>\
    \ &v){\n    for (int i = 0; i < v.size(); ++i) is >> v[i];\n    return is;\n}\n\
    \ntemplate <typename T>\nistream &operator>>(istream &is, valarray<T> &v){\n \
    \   for (int i = 0; i < v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate<class...\
    \ T>\nvoid input(T&... vars){\n    (cin >> ... >> vars);\n}\n\nvoid print(){\n\
    \    cout << '\\n';\n}\n\ntemplate<class T, class... Ts>\nvoid print(const T&\
    \ a, const Ts&... b){\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n\
    \    cout << '\\n';\n}\n\n#define INT(...) int __VA_ARGS__; input(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__; input(__VA_ARGS__)\n\n#ifndef ONLINE_JUDGE\n#define\
    \ dprint(...) print(__VA_ARGS__)\n#else\n#define dprint(...) print()\n#endif\n\
    \ntemplate <typename T1, typename T2, typename T3>\npair<T1, T2> &operator+=(pair<T1,\
    \ T2> &x, const T3 &y){\n    x.first += y;\n    x.second += y;\n    return x;\n\
    }\n\ntemplate <typename T1, typename T2, typename T3>\npair<T1, T2> &operator-=(pair<T1,\
    \ T2> &x, const T3 &y){\n    x.first -= y;\n    x.second -= y;\n    return x;\n\
    }\n\nll modpow(ll a, ll b, ll m){\n    ll p = 1, q = a;\n    for (int i = 0; i\
    \ < 63; ++i)\n    {\n        if ((b & (1LL << i)) != 0)\n        {\n         \
    \   p *= q;\n            p %= m;\n        }\n        q *= q;\n        q %= m;\n\
    \    }\n    return p;\n}\n\ntemplate <typename T>\ninline long long EuclideanDist2(const\
    \ pair<T, T> &p1, const pair<T, T> &p2){\n    long long dx = (long long)p1.first\
    \ - (long long)p2.first;\n    long long dy = (long long)p1.second - (long long)p2.second;\n\
    \    return dx * dx + dy * dy;\n}\n\ntemplate <typename T>\ninline long long EuclideanDist2(const\
    \ pair<T, T> &p){\n    return EuclideanDist2(p, make_pair(0, 0));\n}\n\ntemplate\
    \ <typename T>\ninline double EuclideanDist(const pair<T, T> &p1, const pair<T,\
    \ T> &p2){\n    return sqrt((double)EuclideanDist2(p1, p2));\n}\n\ntemplate <typename\
    \ T>\ninline double EuclideanDist(const pair<T, T> &p){\n    return sqrt((double)EuclideanDist2(p));\n\
    }\n\ntemplate<typename T>\ninline long long ManhattanDist(const pair<T, T> &p1,\
    \ const pair<T, T> &p2){\n    return abs(p1.first - p2.first) + abs(p1.second\
    \ - p2.second);\n}\n\ntemplate <typename T>\nT ceil(T x, T y){\n    return (x\
    \ + y - 1) / y;\n}\n\ntemplate<typename T>\nT gcd(T a, T b) {\n    if(a < 0) a\
    \ = -a;\n    if(b < 0) b = -b;\n    if(b == 0) return a;\n    else return gcd(b,\
    \ a % b);\n}\n\null lcm(ull a, ull b) {\n    return a * b / gcd(a, b);\n}\n\n\
    string bitseq(long long x){\n    string ret = \"\";\n    while(x){\n        ret.push_back('0'\
    \ + (x & 1));\n        x >>= 1;\n    }\n    reverse(ret.begin(), ret.end());\n\
    \    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/Template.hpp
  requiredBy: []
  timestamp: '2023-08-12 20:13:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DPL-1-D.test.cpp
  - verify/yuki-1995.test.cpp
documentation_of: library/Template.hpp
layout: document
redirect_from:
- /library/library/Template.hpp
- /library/library/Template.hpp.html
title: "Procon Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
