---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-PointAddRangeSum_BIT.test.cpp
    title: verify/LC-PointAddRangeSum_BIT.test.cpp
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
    \ 1;\n#line 2 \"Library/DataStructure/BinaryIndexedTree.hpp\"\n\ntemplate<typename\
    \ T>\nstruct BinaryIndexedTree{\n    public:\n    BinaryIndexedTree(int n) : size_(n){\n\
    \        data_.resize(size_ + 1, 0);\n    }\n\n    T Sum(int i){\n        T ret\
    \ = 0;\n        for(; i > 0; i -= i & -i) ret += data_[i];\n        return ret;\n\
    \    }\n    \n    T Sum(int l, int r){\n        return Sum(r) - Sum(l - 1);\n\
    \    }\n\n    void Add(int i, T v){\n        for(; i <= size_; i += i & -i) data_[i]\
    \ += v;\n    }\n\n    private:\n    int size_;\n    vector<T> data_;\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename T>\nstruct BinaryIndexedTree{\n\
    \    public:\n    BinaryIndexedTree(int n) : size_(n){\n        data_.resize(size_\
    \ + 1, 0);\n    }\n\n    T Sum(int i){\n        T ret = 0;\n        for(; i >\
    \ 0; i -= i & -i) ret += data_[i];\n        return ret;\n    }\n    \n    T Sum(int\
    \ l, int r){\n        return Sum(r) - Sum(l - 1);\n    }\n\n    void Add(int i,\
    \ T v){\n        for(; i <= size_; i += i & -i) data_[i] += v;\n    }\n\n    private:\n\
    \    int size_;\n    vector<T> data_;\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2025-05-30 15:31:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-PointAddRangeSum_BIT.test.cpp
documentation_of: Library/DataStructure/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/BinaryIndexedTree.hpp
- /library/Library/DataStructure/BinaryIndexedTree.hpp.html
title: Library/DataStructure/BinaryIndexedTree.hpp
---
