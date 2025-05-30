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
    \n * @version 1.10\n * @date 2025-03-16\n */\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr\
    \ const ll INF = (1LL << 62) - (1LL << 30) - 1;\n#line 12 \"Library/Template.hpp\"\
    \n\ninline bool YnPrint(bool flag){cout << (flag ? \"Yes\" : \"No\") << '\\n';\
    \ return flag;}\ninline bool YNPrint(bool flag){cout << (flag ? \"YES\" : \"NO\"\
    ) << '\\n'; return flag;}\ntemplate<typename Container>\ninline void Sort(Container\
    \ &container){sort(container.begin(), container.end());}\ntemplate<typename Container>\n\
    inline void ReverseSort(Container &container){sort(container.rbegin(), container.rend());}\n\
    template<typename Container>\ninline void Reverse(Container &container){reverse(container.begin(),\
    \ container.end());}\ntemplate<typename Value>\ninline int PopCount(const Value\
    \ &value){return __builtin_popcount(value);}\ntemplate<typename Value>\ninline\
    \ Value Floor(Value numerator, Value denominator){if(denominator < 0) numerator\
    \ *= -1, denominator *= -1; return numerator < 0 ? (numerator + 1) / denominator\
    \ - 1 : numerator / denominator;}\ntemplate<typename Value>\ninline Value Ceil(Value\
    \ numerator, Value denominator){if(denominator < 0) numerator *= -1, denominator\
    \ *= -1; return numerator > 0 ? (numerator - 1) / denominator + 1 : numerator\
    \ / denominator;}\ntemplate<typename Value>\ninline int LowerBoundIndex(const\
    \ vector<Value> &container, const Value &value){return distance(container.begin(),\
    \ lower_bound(container.begin(), container.end(), value));}\ntemplate<typename\
    \ Value>\ninline int UpperBoundIndex(const vector<Value> &container, const Value\
    \ &value){return distance(container.begin(), upper_bound(container.begin(), container.end(),\
    \ value));}\ntemplate<typename Value>\ninline bool Between(const Value &lower,\
    \ const Value &x, const Value &higher){return lower <= x && x <= higher;}\ntemplate<typename\
    \ Value>\ninline bool InGrid(const Value &y, const Value &x, const Value &ymax,\
    \ const Value &xmax){return Between(0, y, ymax - 1) && Between(0, x, xmax - 1);}\n\
    template<typename Value>\ninline Value Median(const Value &a, const Value &b,\
    \ const Value &c){return Between(b, a, c) || Between(c, a, b) ? a : (Between(a,\
    \ b, c) || Between(c, b, a) ? b : c);}\ntemplate<typename Value>\ninline Value\
    \ Except(Value &src, Value &cond, Value &excp){return (src == cond ? excp : src);}\n\
    \ntemplate<class Value>\nbool chmin(Value &src, const Value &cmp){if(src > cmp){src\
    \ = cmp; return true;} return false;}\ntemplate<class Value>\nbool chmax(Value\
    \ &src, const Value &cmp){if(src < cmp){src = cmp; return true;} return false;}\n\
    template<typename Value>\ninline Value min(vector<Value> &v){return *min_element((v).begin(),\
    \ (v).end());}\ntemplate<typename Value>\ninline Value max(vector<Value> &v){return\
    \ *max_element((v).begin(), (v).end());}\n\nconst int dx4[4] = {1, 0, -1, 0};\n\
    const int dy4[4] = {0, -1, 0, 1};\nconst int dx8[8] = {1, 1, 0, -1, -1, -1, 0,\
    \ 1};\nconst int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};\n\nvector<pair<int, int>>\
    \ adjacent(int current_y, int current_x, int max_y, int max_x, bool dir_8 = false){\n\
    \    vector<pair<int, int>> ret;\n    for(int d = 0; d < 4 * (1 + dir_8); ++d){\n\
    \        int next_y = current_y + (dir_8 ? dy8[d] : dy4[d]);\n        int next_x\
    \ = current_x + (dir_8 ? dx8[d] : dx4[d]);\n        if(InGrid(next_y, next_x,\
    \ max_y, max_x)){\n            ret.emplace_back(next_y, next_x);\n        }\n\
    \    }\n    return ret;\n}\n\ntemplate <typename T1, typename T2>\nostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p){\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\n\ntemplate <typename T1, typename T2>\nistream &operator>>(istream &is,\
    \ pair<T1, T2> &p){\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, vector<T> &v){\n    for (int\
    \ i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1 != v.size() ? \" \"\
    \ : \"\");\n    }\n    return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, vector<vector<T>> &v){\n    for (int i = 0; i < v.size(); ++i){\n     \
    \   os << v[i] << (i + 1 != v.size() ? \"\\n\" : \"\");\n    }\n    return os;\n\
    }\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v){\n\
    \    for (int i = 0; i < v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, set<T> &v){\n    for (auto &u\
    \ : v){\n        os << u << \" \";\n    }\n    return os;\n}\n\ntemplate<typename\
    \ T1, typename T2>\nvector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2>\
    \ &v2){\n    assert(v1.size() == v2.size());\n    vector<pair<T1, T2>> v;\n  \
    \  for(int i = 0; i < v1.size(); ++i) v.push_back({v1[i], v2[i]});\n    return\
    \ v;\n}\n\ntemplate<typename T1, typename T2>\npair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1,\
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
    \ DisassembleVectorTuple(v);\n}\n#line 2 \"Library/TemplateExtend.hpp\"\n\ntemplate\
    \ <typename T>\ninline long long EuclideanDist2(const pair<T, T> &p1, const pair<T,\
    \ T> &p2){\n    long long dx = (long long)p1.first - (long long)p2.first;\n  \
    \  long long dy = (long long)p1.second - (long long)p2.second;\n    return dx\
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
  timestamp: '2025-05-30 15:32:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/TemplateExtend.hpp
layout: document
redirect_from:
- /library/Library/TemplateExtend.hpp
- /library/Library/TemplateExtend.hpp.html
title: Library/TemplateExtend.hpp
---
