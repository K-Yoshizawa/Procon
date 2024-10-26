---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/TemplateExtend.hpp
    title: Library/TemplateExtend.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-0560.test.cpp
    title: verify/AOJ-0560.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-ALDS1-7-A.test.cpp
    title: verify/AOJ-ALDS1-7-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-1-B.test.cpp
    title: verify/AOJ-DSL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-A.test.cpp
    title: verify/AOJ-DSL-2-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-B.test.cpp
    title: verify/AOJ-DSL-2-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-5-B.test.cpp
    title: verify/AOJ-DSL-5-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-A.test.cpp
    title: verify/AOJ-GRL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-B.test.cpp
    title: verify/AOJ-GRL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-C.test.cpp
    title: verify/AOJ-GRL-1-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-A.test.cpp
    title: verify/AOJ-GRL-3-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-B.test.cpp
    title: verify/AOJ-GRL-3-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-C.test.cpp
    title: verify/AOJ-GRL-3-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-4-B.test.cpp
    title: verify/AOJ-GRL-4-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-A.test.cpp
    title: verify/AOJ-GRL-5-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-B.test.cpp
    title: verify/AOJ-GRL-5-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-C.test.cpp
    title: verify/AOJ-GRL-5-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-JumponTree.test.cpp
    title: verify/LC-JumponTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-LowestCommonAncestor-HLD.test.cpp
    title: verify/LC-LowestCommonAncestor-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-LowestCommonAncestor.test.cpp
    title: verify/LC-LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-MinimumSpanningTree.test.cpp
    title: verify/LC-MinimumSpanningTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-PointAddRangeSum.test.cpp
    title: verify/LC-PointAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-PointSetRangeComposite.test.cpp
    title: verify/LC-PointSetRangeComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-RangeAffineRangeSum.test.cpp
    title: verify/LC-RangeAffineRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-TreeDiameter.test.cpp
    title: verify/LC-TreeDiameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-TreePathCompositeSum.test.cpp
    title: verify/LC-TreePathCompositeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-TwoEdgeConnectedComponents.test.cpp
    title: verify/LC-TwoEdgeConnectedComponents.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexAddPathSum.test.cpp
    title: verify/LC-VertexAddPathSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexAddSubtreeSum.test.cpp
    title: verify/LC-VertexAddSubtreeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexSetPathComposite.test.cpp
    title: verify/LC-VertexSetPathComposite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    \ << endl;\n#else\n#define VARIABLE(...) 42\n#endif\n\n// ==============================================================\n\
    // \n// Main Program Start\n// \n// ==============================================================\n"
  code: "#pragma once\n\n/**\n * @file Template.hpp\n * @author log K (lX57)\n * @brief\
    \ Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 1.9\n * @date 2024-10-27\n\
    \ */\n\n#include \"Common.hpp\"\n#define ALL(x) (x).begin(), (x).end()\n#define\
    \ RALL(x) (x).rbegin(), (x).rend()\n#define SORT(x) sort(ALL(x))\n#define RSORT(x)\
    \ sort(RALL(x))\n#define REVERSE(x) reverse(ALL(x))\n#define SETPRE(digit) fixed\
    \ << setprecision(digit)\n#define POPCOUNT(x) __builtin_popcount(x)\n#define SUM(x)\
    \ reduce((x).begin(), (x).end())\n#define CEIL(nume, deno) ((nume) + (deno) -\
    \ 1) / (deno)\n#define IOTA(x) iota((x).begin(), (x).end(), 0)\n#define LOWERBOUND_IDX(arr,\
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
    \ << endl;\n#else\n#define VARIABLE(...) 42\n#endif\n\n// ==============================================================\n\
    // \n// Main Program Start\n// \n// =============================================================="
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Template.hpp
  requiredBy:
  - Library/TemplateExtend.hpp
  timestamp: '2024-10-27 03:42:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DSL-2-B.test.cpp
  - verify/AOJ-GRL-4-B.test.cpp
  - verify/AOJ-GRL-1-C.test.cpp
  - verify/LC-LowestCommonAncestor.test.cpp
  - verify/AOJ-GRL-5-B.test.cpp
  - verify/AOJ-GRL-1-B.test.cpp
  - verify/AOJ-GRL-1-A.test.cpp
  - verify/AOJ-GRL-5-C.test.cpp
  - verify/AOJ-GRL-3-A.test.cpp
  - verify/LC-TreeDiameter.test.cpp
  - verify/LC-VertexAddSubtreeSum.test.cpp
  - verify/AOJ-ALDS1-7-A.test.cpp
  - verify/AOJ-GRL-5-A.test.cpp
  - verify/LC-PointSetRangeComposite.test.cpp
  - verify/LC-MinimumSpanningTree.test.cpp
  - verify/AOJ-0560.test.cpp
  - verify/AOJ-DSL-2-A.test.cpp
  - verify/AOJ-GRL-3-B.test.cpp
  - verify/AOJ-GRL-3-C.test.cpp
  - verify/LC-TwoEdgeConnectedComponents.test.cpp
  - verify/LC-PointAddRangeSum.test.cpp
  - verify/LC-VertexAddPathSum.test.cpp
  - verify/LC-RangeAffineRangeSum.test.cpp
  - verify/LC-LowestCommonAncestor-HLD.test.cpp
  - verify/LC-TreePathCompositeSum.test.cpp
  - verify/LC-VertexSetPathComposite.test.cpp
  - verify/LC-JumponTree.test.cpp
  - verify/AOJ-DSL-1-B.test.cpp
  - verify/AOJ-DSL-5-B.test.cpp
documentation_of: Library/Template.hpp
layout: document
redirect_from:
- /library/Library/Template.hpp
- /library/Library/Template.hpp.html
title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
