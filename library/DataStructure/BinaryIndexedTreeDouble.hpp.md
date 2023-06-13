---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/AOJ-DSL-2-G.test.cpp
    title: verify/AOJ-DSL-2-G.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Binary Indexed Tree (Double) - Range Add Query\u5BFE\u5FDC\u7248"
    links: []
  bundledCode: "#line 2 \"library/DataStructure/BinaryIndexedTreeDouble.hpp\"\n\n\
    /**\n * @brief Binary Indexed Tree (Double) - Range Add Query\u5BFE\u5FDC\u7248\
    \n */\n\n#line 2 \"library/DataStructure/BinaryIndexedTree.hpp\"\n\n/**\n * @brief\
    \ Binary Indexed Tree\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n/**\n * @brief \u533A\u9593\u306B\u5BFE\u3059\u308B\u4E00\u70B9\u66F4\u65B0\u30FB\
    \u533A\u9593\u548C\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u3057\u3066\u9AD8\u901F\
    \u304B\u3064\u7C21\u6613\u306B\u5B9F\u88C5\u3067\u304D\u308B\u30C7\u30FC\u30BF\
    \u69CB\u9020\u3002 \n */\ntemplate<typename T>\nstruct BinaryIndexedTree{\n  \
    \  private:\n    vector<T> data;\n\n    public:\n    /**\n     * @brief Binary\
    \ Indexed Tree\u3092\u8981\u7D20\u6570size\u3001\u50240\u3067\u521D\u671F\u5316\
    \u3059\u308B\u3002\n     * @param size \u914D\u5217\u306E\u8981\u7D20\u6570\n\
    \     */\n    BinaryIndexedTree(int size){\n        data.resize(++size, 0);\n\
    \    }\n\n    BinaryIndexedTree() = default;\n\n    /**\n     * @brief 1-index\u3067\
    \u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\u5BFE\u3057\u3066\u3001\u914D\u5217\
    \u306E\u6700\u521D\u304B\u3089i\u307E\u3067\u306E\u9589\u533A\u9593\u306E\u548C\
    \u3092\u6C42\u3081\u308B\u3002\n     * @param i \u6C42\u3081\u305F\u3044\u9589\
    \u533A\u9593\u53F3\u7AEF(1-index)\n     * @return T \u533A\u9593\u548C\n     */\n\
    \    T sum(int i){\n        T ret = 0;\n        while(i > 0){\n            ret\
    \ += data[i];\n            i -= i & -i;\n        }\n        return ret;\n    }\n\
    \n    /**\n     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\
    \u5BFE\u3057\u3066\u3001data[i]\u306Bx\u3092\u52A0\u3048\u308B\u3002\n     * @param\
    \ i \u52A0\u3048\u308B\u5834\u6240\n     * @param x \u52A0\u3048\u308B\u5024\n\
    \     */\n    void add(int i, T x){\n        while(i <= data.size()){\n      \
    \      data[i] += x;\n            i += i & -i;\n        }\n    }\n\n    /**\n\
    \     * @brief 0-index\u3067\u8868\u3055\u308C\u308B\u534A\u958B\u533A\u9593[l,\
    \ r)\u306E\u533A\u9593\u548C\u3092\u6C42\u3081\u308B\u3002\n     * @param l \u533A\
    \u9593\u306E\u5DE6\u7AEF\n     * @param r \u533A\u9593\u306E\u53F3\u7AEF\n   \
    \  * @return T \u533A\u9593\u548C\n     */\n    T query(int l, int r){\n     \
    \   return sum(r) - sum(l);\n    }\n};\n#line 8 \"library/DataStructure/BinaryIndexedTreeDouble.hpp\"\
    \n\ntemplate<typename T>\nstruct BinaryIndexedTreeDouble{\n    private:\n    int\
    \ sz;\n    BinaryIndexedTree<T> BIT0, BIT1;\n\n    public:\n    BinaryIndexedTreeDouble(int\
    \ size) : sz(size), BIT0(size), BIT1(size){}\n\n    /**\n     * @brief 1-index\u3067\
    \u8868\u3055\u308C\u308B\u534A\u958B\u533A\u9593[left, right)\u306B\u5024x\u3092\
    \u52A0\u7B97\u3059\u308B\n     * @param left \u534A\u958B\u533A\u9593\u5DE6\u7AEF\
    \n     * @param right \u534A\u958B\u533A\u9593\u53F3\u7AEF\n     * @param x \u52A0\
    \u7B97\u3059\u308B\u5024\n     */\n    void add(int left, int right, T x){\n \
    \       BIT0.add(left, -x * (left - 1));\n        BIT0.add(right, x * (right -\
    \ 1));\n        BIT1.add(left, x);\n        BIT1.add(right, -x);\n    }\n\n  \
    \  /**\n     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u8981\u7D20i\u306B\
    \u3064\u3044\u3066\u3001\u8981\u7D201\u304B\u3089\u8981\u7D20i\u307E\u3067\u306E\
    \u7DCF\u548C\u3092\u8FD4\u3059\n     * @param i \u9589\u533A\u9593[1, i]\u306E\
    \u53F3\u7AEF\n     * @return T \u533A\u9593[1, i]\u306E\u7DCF\u548C\n     */\n\
    \    T sum(int i){\n        return BIT0.sum(i) + BIT1.sum(i) * i;\n    }\n\n \
    \   /**\n     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u534A\u958B\u533A\
    \u9593[left, right)\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n     * @param left \u534A\
    \u958B\u533A\u9593\u5DE6\u7AEF\n     * @param right \u534A\u958B\u533A\u9593\u53F3\
    \u7AEF\n     * @return T \u533A\u9593[left, right)\u306E\u7DCF\u548C\n     */\n\
    \    T query(int left, int right){\n        return sum(right - 1) - sum(left -\
    \ 1);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Binary Indexed Tree (Double) - Range Add Query\u5BFE\
    \u5FDC\u7248\n */\n\n#include \"BinaryIndexedTree.hpp\"\n\ntemplate<typename T>\n\
    struct BinaryIndexedTreeDouble{\n    private:\n    int sz;\n    BinaryIndexedTree<T>\
    \ BIT0, BIT1;\n\n    public:\n    BinaryIndexedTreeDouble(int size) : sz(size),\
    \ BIT0(size), BIT1(size){}\n\n    /**\n     * @brief 1-index\u3067\u8868\u3055\
    \u308C\u308B\u534A\u958B\u533A\u9593[left, right)\u306B\u5024x\u3092\u52A0\u7B97\
    \u3059\u308B\n     * @param left \u534A\u958B\u533A\u9593\u5DE6\u7AEF\n     *\
    \ @param right \u534A\u958B\u533A\u9593\u53F3\u7AEF\n     * @param x \u52A0\u7B97\
    \u3059\u308B\u5024\n     */\n    void add(int left, int right, T x){\n       \
    \ BIT0.add(left, -x * (left - 1));\n        BIT0.add(right, x * (right - 1));\n\
    \        BIT1.add(left, x);\n        BIT1.add(right, -x);\n    }\n\n    /**\n\
    \     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u8981\u7D20i\u306B\u3064\u3044\
    \u3066\u3001\u8981\u7D201\u304B\u3089\u8981\u7D20i\u307E\u3067\u306E\u7DCF\u548C\
    \u3092\u8FD4\u3059\n     * @param i \u9589\u533A\u9593[1, i]\u306E\u53F3\u7AEF\
    \n     * @return T \u533A\u9593[1, i]\u306E\u7DCF\u548C\n     */\n    T sum(int\
    \ i){\n        return BIT0.sum(i) + BIT1.sum(i) * i;\n    }\n\n    /**\n     *\
    \ @brief 1-index\u3067\u8868\u3055\u308C\u308B\u534A\u958B\u533A\u9593[left, right)\u306E\
    \u7DCF\u548C\u3092\u8FD4\u3059\n     * @param left \u534A\u958B\u533A\u9593\u5DE6\
    \u7AEF\n     * @param right \u534A\u958B\u533A\u9593\u53F3\u7AEF\n     * @return\
    \ T \u533A\u9593[left, right)\u306E\u7DCF\u548C\n     */\n    T query(int left,\
    \ int right){\n        return sum(right - 1) - sum(left - 1);\n    }\n};"
  dependsOn:
  - library/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: false
  path: library/DataStructure/BinaryIndexedTreeDouble.hpp
  requiredBy: []
  timestamp: '2023-06-13 10:39:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/AOJ-DSL-2-G.test.cpp
documentation_of: library/DataStructure/BinaryIndexedTreeDouble.hpp
layout: document
redirect_from:
- /library/library/DataStructure/BinaryIndexedTreeDouble.hpp
- /library/library/DataStructure/BinaryIndexedTreeDouble.hpp.html
title: "Binary Indexed Tree (Double) - Range Add Query\u5BFE\u5FDC\u7248"
---
