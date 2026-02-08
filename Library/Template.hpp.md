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
  - icon: ':warning:'
    path: Library/origin.cpp
    title: Library/origin.cpp
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
    path: verify/AOJ-GRL-4-A.test.cpp
    title: verify/AOJ-GRL-4-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-CycleDetection.test.cpp
    title: verify/LC-CycleDetection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-CycleDetectionUndirected.test.cpp
    title: verify/LC-CycleDetectionUndirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-LongestIncreasingSubsequence.test.cpp
    title: verify/LC-LongestIncreasingSubsequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-LowestCommonAncestor-HLD.test.cpp
    title: verify/LC-LowestCommonAncestor-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-MinimumSpanningTree.test.cpp
    title: verify/LC-MinimumSpanningTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-PointAddRangeSum.test.cpp
    title: verify/LC-PointAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-PointAddRangeSum_BIT.test.cpp
    title: verify/LC-PointAddRangeSum_BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-PointSetRangeComposite.test.cpp
    title: verify/LC-PointSetRangeComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-RangeAffinePointGet.test.cpp
    title: verify/LC-RangeAffinePointGet.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-RangeAffineRangeSum.test.cpp
    title: verify/LC-RangeAffineRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-ShortestPath.test.cpp
    title: verify/LC-ShortestPath.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-StronglyConnectedComponents.test.cpp
    title: verify/LC-StronglyConnectedComponents.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-TreePathCompositeSum.test.cpp
    title: verify/LC-TreePathCompositeSum.test.cpp
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
    links: []
  bundledCode: "#line 2 \"Library/Template.hpp\"\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr\
    \ const ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 4 \"Library/Template.hpp\"\
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
    \ DisassembleVectorTuple(v);\n}\n"
  code: "#pragma once\n\n#include \"Common.hpp\"\n\ninline bool YnPrint(bool flag){cout\
    \ << (flag ? \"Yes\" : \"No\") << '\\n'; return flag;}\ninline bool YNPrint(bool\
    \ flag){cout << (flag ? \"YES\" : \"NO\") << '\\n'; return flag;}\ntemplate<typename\
    \ Container>\ninline void Sort(Container &container){sort(container.begin(), container.end());}\n\
    template<typename Container>\ninline void ReverseSort(Container &container){sort(container.rbegin(),\
    \ container.rend());}\ntemplate<typename Container>\ninline void Reverse(Container\
    \ &container){reverse(container.begin(), container.end());}\ntemplate<typename\
    \ Value>\ninline int PopCount(const Value &value){return __builtin_popcount(value);}\n\
    template<typename Value>\ninline Value Floor(Value numerator, Value denominator){if(denominator\
    \ < 0) numerator *= -1, denominator *= -1; return numerator < 0 ? (numerator +\
    \ 1) / denominator - 1 : numerator / denominator;}\ntemplate<typename Value>\n\
    inline Value Ceil(Value numerator, Value denominator){if(denominator < 0) numerator\
    \ *= -1, denominator *= -1; return numerator > 0 ? (numerator - 1) / denominator\
    \ + 1 : numerator / denominator;}\ntemplate<typename Value>\ninline int LowerBoundIndex(const\
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
    \ DisassembleVectorTuple(v);\n}\n"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Template.hpp
  requiredBy:
  - Library/origin.cpp
  - Library/TemplateExtend.hpp
  timestamp: '2026-02-08 19:40:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-TreePathCompositeSum.test.cpp
  - verify/LC-CycleDetectionUndirected.test.cpp
  - verify/AOJ-GRL-3-A.test.cpp
  - verify/LC-RangeAffineRangeSum.test.cpp
  - verify/AOJ-GRL-1-B.test.cpp
  - verify/AOJ-GRL-4-A.test.cpp
  - verify/AOJ-DSL-1-B.test.cpp
  - verify/AOJ-DSL-5-B.test.cpp
  - verify/LC-PointSetRangeComposite.test.cpp
  - verify/AOJ-GRL-3-B.test.cpp
  - verify/LC-VertexAddSubtreeSum.test.cpp
  - verify/LC-VertexAddPathSum.test.cpp
  - verify/AOJ-DSL-2-B.test.cpp
  - verify/LC-VertexSetPathComposite.test.cpp
  - verify/AOJ-ALDS1-7-A.test.cpp
  - verify/AOJ-GRL-1-C.test.cpp
  - verify/LC-LongestIncreasingSubsequence.test.cpp
  - verify/LC-CycleDetection.test.cpp
  - verify/AOJ-GRL-3-C.test.cpp
  - verify/LC-StronglyConnectedComponents.test.cpp
  - verify/AOJ-DSL-2-A.test.cpp
  - verify/LC-RangeAffinePointGet.test.cpp
  - verify/AOJ-GRL-1-A.test.cpp
  - verify/LC-LowestCommonAncestor-HLD.test.cpp
  - verify/LC-MinimumSpanningTree.test.cpp
  - verify/AOJ-0560.test.cpp
  - verify/LC-ShortestPath.test.cpp
  - verify/LC-PointAddRangeSum_BIT.test.cpp
  - verify/LC-PointAddRangeSum.test.cpp
documentation_of: Library/Template.hpp
layout: document
title: "Template - \u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\u30A3\u95A2\u6570\u7FA4"
---

# Template - ユーティリティ関数群

競技プログラミングで頻繁に使用するユーティリティ関数をまとめたテンプレートライブラリです。

## Function

### 出力関数

#### YnPrint

```
inline bool YnPrint(bool flag)
```

- `flag` が `true` のとき `Yes`、`false` のとき `No` を出力します。
- 戻り値として `flag` をそのまま返します。

**計算量**

- $\textrm{O}(1)$

---

#### YNPrint

```
inline bool YNPrint(bool flag)
```

- `flag` が `true` のとき `YES`、`false` のとき `NO` を出力します。
- 戻り値として `flag` をそのまま返します。

**計算量**

- $\textrm{O}(1)$

---

### コンテナ操作

#### Sort

```
template<typename Container>
inline void Sort(Container &container)
```

- コンテナを昇順にソートします。

**計算量**

- $\textrm{O}(N \log N)$

---

#### ReverseSort

```
template<typename Container>
inline void ReverseSort(Container &container)
```

- コンテナを降順にソートします。

**計算量**

- $\textrm{O}(N \log N)$

---

#### Reverse

```
template<typename Container>
inline void Reverse(Container &container)
```

- コンテナの要素を反転します。

**計算量**

- $\textrm{O}(N)$

---

### ビット操作

#### PopCount

```
template<typename Value>
inline int PopCount(const Value &value)
```

- `value` のビット表現において、`1` のビットの個数を返します。

**計算量**

- $\textrm{O}(1)$

---

### 除算操作

#### Floor

```
template<typename Value>
inline Value Floor(Value numerator, Value denominator)
```

- `numerator / denominator` の結果を負の無限大方向に切り捨てた値を返します。
- 負の数に対しても正しく動作します。

**計算量**

- $\textrm{O}(1)$

---

#### Ceil

```
template<typename Value>
inline Value Ceil(Value numerator, Value denominator)
```

- `numerator / denominator` の結果を正の無限大方向に切り上げた値を返します。
- 負の数に対しても正しく動作します。

**計算量**

- $\textrm{O}(1)$

---

### 二分探索

#### LowerBoundIndex

```
template<typename Value>
inline int LowerBoundIndex(const vector<Value> &container, const Value &value)
```

- ソート済みコンテナにおいて、`value` 以上の最小の要素のインデックスを返します。

**計算量**

- $\textrm{O}(\log N)$

---

#### UpperBoundIndex

```
template<typename Value>
inline int UpperBoundIndex(const vector<Value> &container, const Value &value)
```

- ソート済みコンテナにおいて、`value` より大きい最小の要素のインデックスを返します。

**計算量**

- $\textrm{O}(\log N)$

---

### 範囲チェック

#### Between

```
template<typename Value>
inline bool Between(const Value &lower, const Value &x, const Value &higher)
```

- $lower \le x \le higher$ が成り立つかを判定します。

**計算量**

- $\textrm{O}(1)$

---

#### InGrid

```
template<typename Value>
inline bool InGrid(const Value &y, const Value &x, const Value &ymax, const Value &xmax)
```

- 座標 $(y, x)$ が $[0, ymax) \times [0, xmax)$ の範囲内にあるかを判定します。

**計算量**

- $\textrm{O}(1)$

---

### その他のユーティリティ

#### Median

```
template<typename Value>
inline Value Median(const Value &a, const Value &b, const Value &c)
```

- 3つの値 $a, b, c$ の中央値を返します。

**計算量**

- $\textrm{O}(1)$

---

#### Except

```
template<typename Value>
inline Value Except(Value &src, Value &cond, Value &excp)
```

- `src == cond` のとき `excp` を返し、そうでなければ `src` を返します。

**計算量**

- $\textrm{O}(1)$

---

### 更新系関数

#### chmin

```
template<class Value>
bool chmin(Value &src, const Value &cmp)
```

- `src > cmp` のとき、`src` を `cmp` で更新して `true` を返します。
- そうでなければ何もせず `false` を返します。

**計算量**

- $\textrm{O}(1)$

---

#### chmax

```
template<class Value>
bool chmax(Value &src, const Value &cmp)
```

- `src < cmp` のとき、`src` を `cmp` で更新して `true` を返します。
- そうでなければ何もせず `false` を返します。

**計算量**

- $\textrm{O}(1)$

---

### 最小値・最大値

#### min

```
template<typename Value>
inline Value min(vector<Value> &v)
```

- 配列 `v` の最小値を返します。

**計算量**

- $\textrm{O}(N)$

---

#### max

```
template<typename Value>
inline Value max(vector<Value> &v)
```

- 配列 `v` の最大値を返します。

**計算量**

- $\textrm{O}(N)$

---

## 定数

### 方向ベクトル

```
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, -1, 0, 1};
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
```

- グリッド上での4方向・8方向移動のための方向ベクトルです。
- 4方向: 右、上、左、下
- 8方向: 右、右上、上、左上、左、左下、下、右下

---

### adjacent

```
vector<pair<int, int>> adjacent(int current_y, int current_x, int max_y, int max_x, bool dir_8 = false)
```

- 座標 $(current\_y, current\_x)$ に隣接する有効な座標のリストを返します。
- `dir_8` が `true` のとき8方向、`false` のとき4方向の隣接座標を返します。
- グリッドサイズは $[0, max\_y) \times [0, max\_x)$ です。

**計算量**

- $\textrm{O}(1)$

---

## ストリーム演算子のオーバーロード

### pair の入出力

```
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
```

- `pair` の入出力を簡潔に記述できるようにします。
- 出力形式: `first second`
- 入力形式: `first second`

---

### vector の入出力

```
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)

template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> &v)

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
```

- `vector` の入出力を簡潔に記述できるようにします。
- 1次元ベクトル出力: 要素をスペース区切りで出力
- 2次元ベクトル出力: 各行を改行区切りで出力
- 入力: サイズ分の要素を読み込み

---

### set の出力

```
template <typename T>
ostream &operator<<(ostream &os, set<T> &v)
```

- `set` の要素をスペース区切りで出力します。

---

## ベクトル操作

### AssembleVectorPair

```
template<typename T1, typename T2>
vector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2> &v2)
```

- 2つのベクトル `v1`, `v2` を `pair` のベクトルに変換します。

**制約**

- `v1.size() == v2.size()`

**計算量**

- $\textrm{O}(N)$

---

### DisassembleVectorPair

```
template<typename T1, typename T2>
pair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1, T2>> &v)
```

- `pair` のベクトルを2つの独立したベクトルに分解します。

**計算量**

- $\textrm{O}(N)$

---

### DisassembleVectorTuple

```
template<typename T1, typename T2, typename T3>
tuple<vector<T1>, vector<T2>, vector<T3>> DisassembleVectorTuple(vector<tuple<T1, T2, T3>> &v)
```

- `tuple` のベクトルを3つの独立したベクトルに分解します。

**計算量**

- $\textrm{O}(N)$

---

## 入力補助

### InputVectorPair

```
template<typename T1 = int, typename T2 = T1>
pair<vector<T1>, vector<T2>> InputVectorPair(int size)
```

- `size` 個の `pair` を標準入力から読み込み、2つのベクトルとして返します。

**計算量**

- $\textrm{O}(N)$

---

### InputVectorTuple

```
template<typename T1 = int, typename T2 = T1, typename T3 = T1>
tuple<vector<T1>, vector<T2>, vector<T3>> InputVectorTuple(int size)
```

- `size` 個の `tuple` を標準入力から読み込み、3つのベクトルとして返します。

**計算量**

- $\textrm{O}(N)$

---
