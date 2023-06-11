---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/Tree/EulerTour.hpp
    title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-B.test.cpp
    title: verify/AOJ-DSL-2-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-D.test.cpp
    title: verify/AOJ-GRL-5-D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 2 \"library/DataStructure/BinaryIndexedTree.hpp\"\n\n/**\n *\
    \ @brief Binary Indexed Tree\n */\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n/**\n * @brief \u533A\u9593\u306B\u5BFE\u3059\u308B\u4E00\u70B9\u66F4\
    \u65B0\u30FB\u533A\u9593\u548C\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u3057\u3066\
    \u9AD8\u901F\u304B\u3064\u7C21\u6613\u306B\u5B9F\u88C5\u3067\u304D\u308B\u30C7\
    \u30FC\u30BF\u69CB\u9020\u3002 \n */\ntemplate<typename T>\nstruct BinaryIndexedTree{\n\
    \    private:\n    vector<T> data;\n\n    public:\n    /**\n     * @brief Binary\
    \ Indexed Tree\u3092\u8981\u7D20\u6570size\u3001\u50240\u3067\u521D\u671F\u5316\
    \u3059\u308B\u3002\n     * @param size \u914D\u5217\u306E\u8981\u7D20\u6570\n\
    \     */\n    BinaryIndexedTree(int size){\n        data.assign(++size, 0);\n\
    \    }\n\n    /**\n     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u756A\u53F7\
    i\u306B\u5BFE\u3057\u3066\u3001\u914D\u5217\u306E\u6700\u521D\u304B\u3089i\u307E\
    \u3067\u306E\u9589\u533A\u9593\u306E\u548C\u3092\u6C42\u3081\u308B\u3002\n   \
    \  * @param i \u6C42\u3081\u305F\u3044\u9589\u533A\u9593\u53F3\u7AEF(1-index)\n\
    \     * @return T \u533A\u9593\u548C\n     */\n    T sum(int i){\n        T ret\
    \ = 0;\n        while(i > 0){\n            ret += data[i];\n            i -= i\
    \ & -i;\n        }\n        return ret;\n    }\n\n    /**\n     * @brief 1-index\u3067\
    \u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\u5BFE\u3057\u3066\u3001data[i]\u306B\
    x\u3092\u52A0\u3048\u308B\u3002\n     * @param i \u52A0\u3048\u308B\u5834\u6240\
    \n     * @param x \u52A0\u3048\u308B\u5024\n     */\n    void add(int i, T x){\n\
    \        while(i <= data.size()){\n            data[i] += x;\n            i +=\
    \ i & -i;\n        }\n    }\n\n    /**\n     * @brief 0-index\u3067\u8868\u3055\
    \u308C\u308B\u534A\u958B\u533A\u9593[l, r)\u306E\u533A\u9593\u548C\u3092\u6C42\
    \u3081\u308B\u3002\n     * @param l \u533A\u9593\u306E\u5DE6\u7AEF\n     * @param\
    \ r \u533A\u9593\u306E\u53F3\u7AEF\n     * @return T \u533A\u9593\u548C\n    \
    \ */\n    T query(int l, int r){\n        return sum(r) - sum(l);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Binary Indexed Tree\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/**\n * @brief \u533A\u9593\u306B\u5BFE\u3059\u308B\u4E00\
    \u70B9\u66F4\u65B0\u30FB\u533A\u9593\u548C\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\
    \u3057\u3066\u9AD8\u901F\u304B\u3064\u7C21\u6613\u306B\u5B9F\u88C5\u3067\u304D\
    \u308B\u30C7\u30FC\u30BF\u69CB\u9020\u3002 \n */\ntemplate<typename T>\nstruct\
    \ BinaryIndexedTree{\n    private:\n    vector<T> data;\n\n    public:\n    /**\n\
    \     * @brief Binary Indexed Tree\u3092\u8981\u7D20\u6570size\u3001\u50240\u3067\
    \u521D\u671F\u5316\u3059\u308B\u3002\n     * @param size \u914D\u5217\u306E\u8981\
    \u7D20\u6570\n     */\n    BinaryIndexedTree(int size){\n        data.assign(++size,\
    \ 0);\n    }\n\n    /**\n     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u756A\
    \u53F7i\u306B\u5BFE\u3057\u3066\u3001\u914D\u5217\u306E\u6700\u521D\u304B\u3089\
    i\u307E\u3067\u306E\u9589\u533A\u9593\u306E\u548C\u3092\u6C42\u3081\u308B\u3002\
    \n     * @param i \u6C42\u3081\u305F\u3044\u9589\u533A\u9593\u53F3\u7AEF(1-index)\n\
    \     * @return T \u533A\u9593\u548C\n     */\n    T sum(int i){\n        T ret\
    \ = 0;\n        while(i > 0){\n            ret += data[i];\n            i -= i\
    \ & -i;\n        }\n        return ret;\n    }\n\n    /**\n     * @brief 1-index\u3067\
    \u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\u5BFE\u3057\u3066\u3001data[i]\u306B\
    x\u3092\u52A0\u3048\u308B\u3002\n     * @param i \u52A0\u3048\u308B\u5834\u6240\
    \n     * @param x \u52A0\u3048\u308B\u5024\n     */\n    void add(int i, T x){\n\
    \        while(i <= data.size()){\n            data[i] += x;\n            i +=\
    \ i & -i;\n        }\n    }\n\n    /**\n     * @brief 0-index\u3067\u8868\u3055\
    \u308C\u308B\u534A\u958B\u533A\u9593[l, r)\u306E\u533A\u9593\u548C\u3092\u6C42\
    \u3081\u308B\u3002\n     * @param l \u533A\u9593\u306E\u5DE6\u7AEF\n     * @param\
    \ r \u533A\u9593\u306E\u53F3\u7AEF\n     * @return T \u533A\u9593\u548C\n    \
    \ */\n    T query(int l, int r){\n        return sum(r) - sum(l);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/BinaryIndexedTree.hpp
  requiredBy:
  - library/Tree/EulerTour.hpp
  timestamp: '2023-06-12 01:07:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DSL-2-B.test.cpp
  - verify/AOJ-GRL-5-D.test.cpp
documentation_of: library/DataStructure/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/library/DataStructure/BinaryIndexedTree.hpp
- /library/library/DataStructure/BinaryIndexedTree.hpp.html
title: Binary Indexed Tree
---
