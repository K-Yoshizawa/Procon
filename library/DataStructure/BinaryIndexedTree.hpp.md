---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-B.test.cpp
    title: verify/AOJ-DSL-2-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 1 \"library/DataStructure/BinaryIndexedTree.hpp\"\n/**\n * @file\
    \ BinaryIndexedTree.hpp\n * @author log K (lX57)\n * @brief Binary Indexed Tree\n\
    \ * @version 2.0\n * @date 2023-11-01\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate<typename T>\nstruct BinaryIndexedTree{\n    private:\n\
    \    int __Size;\n    vector<T> __Data;\n    bool __ZeroIndex;\n\n    public:\n\
    \    /**\n     * @brief Binary Indexed Tree \u3092\u8981\u7D20\u6570 `Size` \u3067\
    \u521D\u671F\u5316\u3059\u308B\n     * @param Size \u8981\u7D20\u6570\n     *\
    \ @param ZeroIndex `0-index` \u3067\u6271\u3044\u305F\u3044\u304B (default = `false`)\n\
    \     */\n    BinaryIndexedTree(int Size, bool ZeroIndex = false) : __Size(Size),\
    \ __ZeroIndex(ZeroIndex){\n        __Data.resize(__Size + 1, 0);\n    }\n\n  \
    \  T sum(int i){\n        T ret = 0;\n        i += __ZeroIndex;\n        for(;\
    \ i > 0; i -= i & -i) ret += __Data[i];\n        return ret;\n    }\n\n    void\
    \ add(int i, T x){\n        i += __ZeroIndex;\n        for(; i <= __Size; i +=\
    \ i & -i) __Data[i] += x;\n    }\n\n    T query(int l, int r){\n        l += __ZeroIndex,\
    \ r += __ZeroIndex;\n        return sum(r) - sum(l - 1);\n    }\n};\n"
  code: "/**\n * @file BinaryIndexedTree.hpp\n * @author log K (lX57)\n * @brief Binary\
    \ Indexed Tree\n * @version 2.0\n * @date 2023-11-01\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct BinaryIndexedTree{\n    private:\n\
    \    int __Size;\n    vector<T> __Data;\n    bool __ZeroIndex;\n\n    public:\n\
    \    /**\n     * @brief Binary Indexed Tree \u3092\u8981\u7D20\u6570 `Size` \u3067\
    \u521D\u671F\u5316\u3059\u308B\n     * @param Size \u8981\u7D20\u6570\n     *\
    \ @param ZeroIndex `0-index` \u3067\u6271\u3044\u305F\u3044\u304B (default = `false`)\n\
    \     */\n    BinaryIndexedTree(int Size, bool ZeroIndex = false) : __Size(Size),\
    \ __ZeroIndex(ZeroIndex){\n        __Data.resize(__Size + 1, 0);\n    }\n\n  \
    \  T sum(int i){\n        T ret = 0;\n        i += __ZeroIndex;\n        for(;\
    \ i > 0; i -= i & -i) ret += __Data[i];\n        return ret;\n    }\n\n    void\
    \ add(int i, T x){\n        i += __ZeroIndex;\n        for(; i <= __Size; i +=\
    \ i & -i) __Data[i] += x;\n    }\n\n    T query(int l, int r){\n        l += __ZeroIndex,\
    \ r += __ZeroIndex;\n        return sum(r) - sum(l - 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2023-11-02 01:25:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DSL-2-B.test.cpp
documentation_of: library/DataStructure/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/library/DataStructure/BinaryIndexedTree.hpp
- /library/library/DataStructure/BinaryIndexedTree.hpp.html
title: Binary Indexed Tree
---
