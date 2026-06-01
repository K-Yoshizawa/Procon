---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-PointAddRangeSum-FenwickTree.test.cpp
    title: verify/LC-PointAddRangeSum-FenwickTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cmath>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const\
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 2 \"Library/DataStructure/FenwickTree.hpp\"\
    \n\ntemplate<typename Ordered>\nstruct FenwickTree{\n    public:\n    FenwickTree(int\
    \ N) : size_(N){\n        data_.resize(size_ + 1, 0);\n    }\n\n    Ordered Sum(int\
    \ i){\n        Ordered ret = 0;\n        for(; i > 0; i -= i & -i) ret += data_[i];\n\
    \        return ret;\n    }\n    \n    Ordered Sum(int l, int r){\n        return\
    \ Sum(r) - Sum(l - 1);\n    }\n\n    void Add(int i, Ordered v){\n        for(;\
    \ i <= size_; i += i & -i) data_[i] += v;\n    }\n\n    private:\n    int size_;\n\
    \    vector<Ordered> data_;\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename Ordered>\nstruct FenwickTree{\n\
    \    public:\n    FenwickTree(int N) : size_(N){\n        data_.resize(size_ +\
    \ 1, 0);\n    }\n\n    Ordered Sum(int i){\n        Ordered ret = 0;\n       \
    \ for(; i > 0; i -= i & -i) ret += data_[i];\n        return ret;\n    }\n   \
    \ \n    Ordered Sum(int l, int r){\n        return Sum(r) - Sum(l - 1);\n    }\n\
    \n    void Add(int i, Ordered v){\n        for(; i <= size_; i += i & -i) data_[i]\
    \ += v;\n    }\n\n    private:\n    int size_;\n    vector<Ordered> data_;\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/FenwickTree.hpp
  requiredBy: []
  timestamp: '2026-06-01 14:08:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-PointAddRangeSum-FenwickTree.test.cpp
documentation_of: Library/DataStructure/FenwickTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/FenwickTree.hpp
- /library/Library/DataStructure/FenwickTree.hpp.html
title: Library/DataStructure/FenwickTree.hpp
---
