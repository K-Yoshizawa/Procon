---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-1-B.test.cpp
    title: verify/AOJ-DSL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-UnionfindWithPotential.test.cpp
    title: verify/LC-UnionfindWithPotential.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (1LL << 30) -\
    \ 1;\n#line 2 \"Library/DataStructure/WeightedUnionFind.hpp\"\n\ntemplate<typename\
    \ Abel = int32_t>\nclass WeightedUnionFind{\n    public:\n    WeightedUnionFind(int\
    \ n) : data_(n, -1), weight_(n, Abel{}){}\n\n    int Find(const int k){\n    \
    \    if(data_[k] < 0) return k;\n        int r = Find(data_[k]);\n        weight_[k]\
    \ += weight_[data_[k]];\n        return data_[k] = r;\n    }\n\n    Abel Weight(const\
    \ int k){\n        Find(k);\n        return weight_[k];\n    }\n\n    Abel Diff(const\
    \ int x, const int y){\n        return Weight(y) - Weight(x);\n    }\n\n    bool\
    \ Same(const int x, const int y){\n        return Find(x) == Find(y);\n    }\n\
    \n    bool Unite(int x, int y, Abel w){\n        w += Weight(x) - Weight(y);\n\
    \        x = Find(x), y = Find(y);\n        if(x == y) return false;\n       \
    \ if(data_[x] > data_[y]) swap(x, y), w = -w;\n        data_[x] += data_[y];\n\
    \        data_[y] = x;\n        weight_[y] = w;\n        return true;\n    }\n\
    \n    private:\n    vector<int> data_;\n    vector<Abel> weight_;\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename Abel = int32_t>\nclass WeightedUnionFind{\n\
    \    public:\n    WeightedUnionFind(int n) : data_(n, -1), weight_(n, Abel{}){}\n\
    \n    int Find(const int k){\n        if(data_[k] < 0) return k;\n        int\
    \ r = Find(data_[k]);\n        weight_[k] += weight_[data_[k]];\n        return\
    \ data_[k] = r;\n    }\n\n    Abel Weight(const int k){\n        Find(k);\n  \
    \      return weight_[k];\n    }\n\n    Abel Diff(const int x, const int y){\n\
    \        return Weight(y) - Weight(x);\n    }\n\n    bool Same(const int x, const\
    \ int y){\n        return Find(x) == Find(y);\n    }\n\n    bool Unite(int x,\
    \ int y, Abel w){\n        w += Weight(x) - Weight(y);\n        x = Find(x), y\
    \ = Find(y);\n        if(x == y) return false;\n        if(data_[x] > data_[y])\
    \ swap(x, y), w = -w;\n        data_[x] += data_[y];\n        data_[y] = x;\n\
    \        weight_[y] = w;\n        return true;\n    }\n\n    private:\n    vector<int>\
    \ data_;\n    vector<Abel> weight_;\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/WeightedUnionFind.hpp
  requiredBy: []
  timestamp: '2025-03-20 00:50:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DSL-1-B.test.cpp
  - verify/LC-UnionfindWithPotential.test.cpp
documentation_of: Library/DataStructure/WeightedUnionFind.hpp
layout: document
title: "Weighted Union-Find - \u91CD\u307F\u4ED8\u304D\u7D20\u96C6\u5408\u30C7\u30FC\
  \u30BF\u69CB\u9020"
---

# Weighted Union-Find - 重み付き素集合データ構造

WIP

## Function

WIP