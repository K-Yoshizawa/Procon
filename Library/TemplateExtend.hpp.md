---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Template.hpp\"\n\n/**\n * @file Template.hpp\n *\
    \ @author log K (lX57)\n * @brief Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @version 1.9\n * @date 2024-10-27\n */\n\n#line 2 \"Library/Common.hpp\"\n\
    \n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n#line 12 \"Library/Template.hpp\"\n#define ALL(x) (x).begin(),\
    \ (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define SORT(x) sort(ALL(x))\n\
    #define RSORT(x) sort(RALL(x))\n#define REVERSE(x) reverse(ALL(x))\n#define SETPRE(digit)\
    \ fixed << setprecision(digit)\n#define POPCOUNT(x) __builtin_popcount(x)\n#define\
    \ SUM(x) reduce((x).begin(), (x).end())\n#define CEIL(nume, deno) ((nume) + (deno)\
    \ - 1) / (deno)\n#define IOTA(x) iota((x).begin(), (x).end(), 0)\n#define LOWERBOUND_IDX(arr,\
    \ val) distance((arr).begin(), lower_bound((arr).begin(), (arr).end(), val))\n\
    #define UPPERBOUND_IDX(arr, val) distance((arr).begin(), upper_bound((arr).begin(),\
    \ (arr).end(), val))\n\ninline string Yn(bool flag){return (flag) ? \"Yes\" :\
    \ \"No\";}\ninline bool YnPrint(bool flag){cout << Yn(flag) << endl;return flag;}\n\
    inline string YN(bool flag){return (flag) ? \"YES\" : \"NO\";}\ninline bool YNPrint(bool\
    \ flag){cout << YN(flag) << endl;return flag;}\ntemplate<class T>\nbool chmin(T\
    \ &src, const T &cmp){if(src > cmp){src = cmp; return true;}return false;}\ntemplate<class\
    \ T>\nbool chmax(T &src, const T &cmp){if(src < cmp){src = cmp; return true;}return\
    \ false;}\ntemplate<typename T>\ninline bool between(T min, T x, T max){return\
    \ min <= x && x <= max;}\ntemplate<typename T>\ninline bool ingrid(T y, T x, T\
    \ ymax, T xmax){return between(0, y, ymax - 1) && between(0, x, xmax - 1);}\n\
    template<typename T>\ninline T median(T a, T b, T c){return between(b, a, c) ||\
    \ between(c, a, b) ? a : (between(a, b, c) || between(c, b, a) ? b : c);}\ntemplate<typename\
    \ T>\ninline T except(T src, T cond, T excp){return (src == cond ? excp : src);}\n\
    template<typename T>\ninline T min(vector<T> &v){return *min_element((v).begin(),\
    \ (v).end());}\ntemplate<typename T>\ninline T max(vector<T> &v){return *max_element((v).begin(),\
    \ (v).end());}\nvector<int> make_sequence(int Size){\n    vector<int> ret(Size);\n\
    \    IOTA(ret);\n    return ret;\n}\ntemplate<typename T>\nvoid make_unique(vector<T>\
    \ &v){\n    sort(v.begin(), v.end());\n    auto itr = unique(v.begin(), v.end());\n\
    \    v.erase(itr, v.end());\n}\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\
    using ld = long double;\n\nconst int INF_INT = numeric_limits<int>::max() >> 2;\n\
    const ll INF_LL = numeric_limits<ll>::max() >> 2;\n\nusing vi = vector<int>;\n\
    using vvi = vector<vi>;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing\
    \ pi = pair<int, int>;\nusing pl = pair<ll, ll>;\nusing vs = vector<string>;\n\
    template <typename T>\nusing pq = priority_queue<T>;\ntemplate <typename T>\n\
    using rpq = priority_queue<T, vector<T>, greater<T>>;\n\nconst int dx4[4] = {1,\
    \ 0, -1, 0};\nconst int dy4[4] = {0, -1, 0, 1};\nconst int dx8[8] = {1, 1, 0,\
    \ -1, -1, -1, 0, 1};\nconst int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};\n\nvector<pair<int,\
    \ int>> adjacent(int current_y, int current_x, int max_y, int max_x, bool dir_8\
    \ = false){\n    vector<pair<int, int>> ret;\n    for(int d = 0; d < 4 * (1 +\
    \ dir_8); ++d){\n        int next_y = current_y + (dir_8 ? dy8[d] : dy4[d]);\n\
    \        int next_x = current_x + (dir_8 ? dx8[d] : dx4[d]);\n        if(0 <=\
    \ next_y and next_y < max_y and 0 <= next_x and next_x < max_x){\n           \
    \ ret.emplace_back(next_y, next_x);\n        }\n    }\n    return ret;\n}\n\n\
    template <typename T1, typename T2>\nostream &operator<<(ostream &os, const pair<T1,\
    \ T2> &p){\n    os << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate\
    \ <typename T1, typename T2>\nistream &operator>>(istream &is, pair<T1, T2> &p){\n\
    \    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <typename T>\n\
    ostream &operator<<(ostream &os, vector<T> &v){\n    for (int i = 0; i < v.size();\
    \ ++i){\n        os << v[i] << (i + 1 != v.size() ? \" \" : \"\");\n    }\n  \
    \  return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, vector<vector<T>>\
    \ &v){\n    for (int i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1\
    \ != v.size() ? \"\\n\" : \"\");\n    }\n    return os;\n}\n\ntemplate <typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v){\n    for (int i = 0; i <\
    \ v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate <typename T>\nostream\
    \ &operator<<(ostream &os, set<T> &v){\n    for (auto &u : v){\n        os <<\
    \ u << \" \";\n    }\n    return os;\n}\n\ntemplate<typename T1, typename T2>\n\
    vector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2> &v2){\n   \
    \ assert(v1.size() == v2.size());\n    vector<pair<T1, T2>> v;\n    for(int i\
    \ = 0; i < v1.size(); ++i) v.push_back({v1[i], v2[i]});\n    return v;\n}\n\n\
    template<typename T1, typename T2>\npair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1,\
    \ T2>> &v){\n    vector<T1> v1;\n    vector<T2> v2;\n    transform(v.begin(),\
    \ v.end(), back_inserter(v1), [](auto p){return p.first;});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v2), [](auto p){return p.second;});\n    return {v1,\
    \ v2};\n}\n\ntemplate<typename T1, typename T2, typename T3>\ntuple<vector<T1>,\
    \ vector<T2>, vector<T3>> DisassembleVectorTuple(vector<tuple<T1, T2, T3>> &v){\n\
    \    vector<T1> v1;\n    vector<T2> v2;\n    vector<T3> v3;\n    transform(v.begin(),\
    \ v.end(), back_inserter(v1), [](auto p){return get<0>(p);});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v2), [](auto p){return get<1>(p);});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v3), [](auto p){return get<2>(p);});\n    return {v1,\
    \ v2, v3};\n}\n\ntemplate<typename T1 = int, typename T2 = T1>\npair<vector<T1>,\
    \ vector<T2>> InputVectorPair(int size){\n    vector<pair<T1, T2>> v(size);\n\
    \    for(auto &[p, q] : v) cin >> p >> q;\n    return DisassembleVectorPair(v);\n\
    }\n\ntemplate<typename T1 = int, typename T2 = T1, typename T3 = T1>\ntuple<vector<T1>,\
    \ vector<T2>, vector<T3>> InputVectorTuple(int size){\n    vector<tuple<T1, T2,\
    \ T3>> v(size);\n    for(auto &[p, q, r] : v) cin >> p >> q >> r;\n    return\
    \ DisassembleVectorTuple(v);\n}\n\nll modpow(ll a, ll x, ll m){\n    ll ret =\
    \ 1, cur = a % m, rem = x;\n    while(rem){\n        if(rem & 1) ret = (ret *\
    \ cur) % m;\n        rem >>= 1, cur = (cur * cur) % m;\n    }\n    return ret;\n\
    }\n\n#ifdef LOGK\n#define VARIABLE(var) cerr << \"# \" << #var << \" = \" << var\
    \ << endl;\n#else\n#define VARIABLE(...) 42\n#endif\n#line 2 \"Library/TemplateExtend.hpp\"\
    \n\ntemplate <typename T>\ninline long long EuclideanDist2(const pair<T, T> &p1,\
    \ const pair<T, T> &p2){\n    long long dx = (long long)p1.first - (long long)p2.first;\n\
    \    long long dy = (long long)p1.second - (long long)p2.second;\n    return dx\
    \ * dx + dy * dy;\n}\n\ntemplate <typename T>\ninline long long EuclideanDist2(const\
    \ pair<T, T> &p){\n    return EuclideanDist2(p, make_pair(0, 0));\n}\n\ntemplate\
    \ <typename T>\ninline long double EuclideanDist(const pair<T, T> &p1, const pair<T,\
    \ T> &p2){\n    return sqrtl((long double)EuclideanDist2(p1, p2));\n}\n\ntemplate\
    \ <typename T>\ninline long double EuclideanDist(const pair<T, T> &p){\n    return\
    \ sqrtl((long double)EuclideanDist2(p));\n}\n\ntemplate<typename T>\ninline long\
    \ long ManhattanDist(const pair<T, T> &p1, const pair<T, T> &p2){\n    return\
    \ abs(p1.first - p2.first) + abs(p1.second - p2.second);\n}\n\nll modpow(ll a,\
    \ ll b, ll m){\n    ll p = 1, q = a;\n    for (int i = 0; i < 63; ++i)\n    {\n\
    \        if ((b & (1LL << i)) != 0)\n        {\n            p *= q;\n        \
    \    p %= m;\n        }\n        q *= q;\n        q %= m;\n    }\n    return p;\n\
    }\n\ntemplate<typename T>\nT gcd(T a, T b) {\n    if(a < 0) a = -a;\n    if(b\
    \ < 0) b = -b;\n    if(b == 0) return a;\n    else return gcd(b, a % b);\n}\n\n\
    ull lcm(ull a, ull b) {\n    return a * b / gcd(a, b);\n}\n\nstring bitseq(long\
    \ long x, int mini_len = 1, bool rev = false){\n    string ret = \"\";\n    while(x){\n\
    \        ret.push_back('0' + (x & 1));\n        x >>= 1;\n    }\n    while(ret.size()<mini_len)\
    \ ret.push_back('0');\n    if(!rev) reverse(ret.begin(), ret.end());\n    return\
    \ ret;\n}\n"
  code: "#include \"Template.hpp\"\n\ntemplate <typename T>\ninline long long EuclideanDist2(const\
    \ pair<T, T> &p1, const pair<T, T> &p2){\n    long long dx = (long long)p1.first\
    \ - (long long)p2.first;\n    long long dy = (long long)p1.second - (long long)p2.second;\n\
    \    return dx * dx + dy * dy;\n}\n\ntemplate <typename T>\ninline long long EuclideanDist2(const\
    \ pair<T, T> &p){\n    return EuclideanDist2(p, make_pair(0, 0));\n}\n\ntemplate\
    \ <typename T>\ninline long double EuclideanDist(const pair<T, T> &p1, const pair<T,\
    \ T> &p2){\n    return sqrtl((long double)EuclideanDist2(p1, p2));\n}\n\ntemplate\
    \ <typename T>\ninline long double EuclideanDist(const pair<T, T> &p){\n    return\
    \ sqrtl((long double)EuclideanDist2(p));\n}\n\ntemplate<typename T>\ninline long\
    \ long ManhattanDist(const pair<T, T> &p1, const pair<T, T> &p2){\n    return\
    \ abs(p1.first - p2.first) + abs(p1.second - p2.second);\n}\n\nll modpow(ll a,\
    \ ll b, ll m){\n    ll p = 1, q = a;\n    for (int i = 0; i < 63; ++i)\n    {\n\
    \        if ((b & (1LL << i)) != 0)\n        {\n            p *= q;\n        \
    \    p %= m;\n        }\n        q *= q;\n        q %= m;\n    }\n    return p;\n\
    }\n\ntemplate<typename T>\nT gcd(T a, T b) {\n    if(a < 0) a = -a;\n    if(b\
    \ < 0) b = -b;\n    if(b == 0) return a;\n    else return gcd(b, a % b);\n}\n\n\
    ull lcm(ull a, ull b) {\n    return a * b / gcd(a, b);\n}\n\nstring bitseq(long\
    \ long x, int mini_len = 1, bool rev = false){\n    string ret = \"\";\n    while(x){\n\
    \        ret.push_back('0' + (x & 1));\n        x >>= 1;\n    }\n    while(ret.size()<mini_len)\
    \ ret.push_back('0');\n    if(!rev) reverse(ret.begin(), ret.end());\n    return\
    \ ret;\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/TemplateExtend.hpp
  requiredBy: []
  timestamp: '2024-11-11 17:34:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/TemplateExtend.hpp
layout: document
redirect_from:
- /library/Library/TemplateExtend.hpp
- /library/Library/TemplateExtend.hpp.html
title: Library/TemplateExtend.hpp
---
