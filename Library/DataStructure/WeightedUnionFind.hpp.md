---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-1-B.test.cpp
    title: verify/AOJ-DSL-1-B.test.cpp
  - icon: ':x:'
    path: verify/LC-UnionfindWithPotential.test.cpp
    title: verify/LC-UnionfindWithPotential.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cmath>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const\
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 2 \"Library/DataStructure/WeightedUnionFind.hpp\"\
    \n\ntemplate<typename Arithmetic = int32_t>\nclass WeightedUnionFind{\n    public:\n\
    \    WeightedUnionFind(int N) : data_(N, -1), weight_(N, Arithmetic{}){}\n\n \
    \   int Find(const int k){\n        if(data_[k] < 0) return k;\n        int r\
    \ = Find(data_[k]);\n        weight_[k] += weight_[data_[k]];\n        return\
    \ data_[k] = r;\n    }\n\n    Arithmetic Weight(const int k){\n        Find(k);\n\
    \        return weight_[k];\n    }\n\n    Arithmetic Diff(const int x, const int\
    \ y){\n        return Weight(y) - Weight(x);\n    }\n\n    bool Same(const int\
    \ x, const int y){\n        return Find(x) == Find(y);\n    }\n\n    bool Unite(int\
    \ x, int y, Arithmetic w){\n        w += Weight(x) - Weight(y);\n        x = Find(x),\
    \ y = Find(y);\n        if(x == y) return false;\n        if(data_[x] > data_[y])\
    \ swap(x, y), w = -w;\n        data_[x] += data_[y];\n        data_[y] = x;\n\
    \        weight_[y] = w;\n        return true;\n    }\n\n    private:\n    vector<int>\
    \ data_;\n    vector<Arithmetic> weight_;\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename Arithmetic = int32_t>\nclass\
    \ WeightedUnionFind{\n    public:\n    WeightedUnionFind(int N) : data_(N, -1),\
    \ weight_(N, Arithmetic{}){}\n\n    int Find(const int k){\n        if(data_[k]\
    \ < 0) return k;\n        int r = Find(data_[k]);\n        weight_[k] += weight_[data_[k]];\n\
    \        return data_[k] = r;\n    }\n\n    Arithmetic Weight(const int k){\n\
    \        Find(k);\n        return weight_[k];\n    }\n\n    Arithmetic Diff(const\
    \ int x, const int y){\n        return Weight(y) - Weight(x);\n    }\n\n    bool\
    \ Same(const int x, const int y){\n        return Find(x) == Find(y);\n    }\n\
    \n    bool Unite(int x, int y, Arithmetic w){\n        w += Weight(x) - Weight(y);\n\
    \        x = Find(x), y = Find(y);\n        if(x == y) return false;\n       \
    \ if(data_[x] > data_[y]) swap(x, y), w = -w;\n        data_[x] += data_[y];\n\
    \        data_[y] = x;\n        weight_[y] = w;\n        return true;\n    }\n\
    \n    private:\n    vector<int> data_;\n    vector<Arithmetic> weight_;\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/WeightedUnionFind.hpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/LC-UnionfindWithPotential.test.cpp
  - verify/AOJ-DSL-1-B.test.cpp
documentation_of: Library/DataStructure/WeightedUnionFind.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/WeightedUnionFind.hpp
- /library/Library/DataStructure/WeightedUnionFind.hpp.html
title: Library/DataStructure/WeightedUnionFind.hpp
---
