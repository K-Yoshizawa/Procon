---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':question:'
    path: library/DataStructure/BinaryIndexedTreeDouble.hpp
    title: "Binary Indexed Tree (Double) - Range Add Query\u5BFE\u5FDC\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"verify/AOJ/AOJ-DSL-2-G.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#line 2 \"library/DataStructure/BinaryIndexedTreeDouble.hpp\"\n\n/**\n * @brief\
    \ Binary Indexed Tree (Double) - Range Add Query\u5BFE\u5FDC\u7248\n */\n\n#line\
    \ 2 \"library/DataStructure/BinaryIndexedTree.hpp\"\n\n/**\n * @brief Binary Indexed\
    \ Tree\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n/**\n * @brief\
    \ \u533A\u9593\u306B\u5BFE\u3059\u308B\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\
    \u548C\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u3057\u3066\u9AD8\u901F\u304B\u3064\
    \u7C21\u6613\u306B\u5B9F\u88C5\u3067\u304D\u308B\u30C7\u30FC\u30BF\u69CB\u9020\
    \u3002 \n */\ntemplate<typename T>\nstruct BinaryIndexedTree{\n    private:\n\
    \    vector<T> data;\n\n    public:\n    /**\n     * @brief Binary Indexed Tree\u3092\
    \u8981\u7D20\u6570size\u3001\u50240\u3067\u521D\u671F\u5316\u3059\u308B\u3002\n\
    \     * @param size \u914D\u5217\u306E\u8981\u7D20\u6570\n     */\n    BinaryIndexedTree(int\
    \ size){\n        data.resize(++size, 0);\n    }\n\n    BinaryIndexedTree() =\
    \ default;\n\n    /**\n     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u756A\
    \u53F7i\u306B\u5BFE\u3057\u3066\u3001\u914D\u5217\u306E\u6700\u521D\u304B\u3089\
    i\u307E\u3067\u306E\u9589\u533A\u9593\u306E\u548C\u3092\u6C42\u3081\u308B\u3002\
    \n     * @param i \u6C42\u3081\u305F\u3044\u9589\u533A\u9593\u53F3\u7AEF(1-index)\n\
    \     * @return T \u533A\u9593\u548C\n     */\n    T sum(int i){\n        T ret\
    \ = 0;\n        while(i > 0){\n            ret += data[i];\n            i -= i\
    \ & -i;\n        }\n        return ret;\n    }\n\n    /**\n     * @brief 1-index\u3067\
    \u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\u5BFE\u3057\u3066\u3001data[i]\u306B\
    x\u3092\u52A0\u3048\u308B\u3002\n     * @param i \u52A0\u3048\u308B\u5834\u6240\
    \n     * @param x \u52A0\u3048\u308B\u5024\n     */\n    void add(int i, T x){\n\
    \        while(i < data.size()){\n            data[i] += x;\n            i +=\
    \ i & -i;\n        }\n    }\n\n    /**\n     * @brief 0-index\u3067\u8868\u3055\
    \u308C\u308B\u534A\u958B\u533A\u9593[l, r)\u306E\u533A\u9593\u548C\u3092\u6C42\
    \u3081\u308B\u3002\n     * @param l \u533A\u9593\u306E\u5DE6\u7AEF\n     * @param\
    \ r \u533A\u9593\u306E\u53F3\u7AEF\n     * @return T \u533A\u9593\u548C\n    \
    \ */\n    T query(int l, int r){\n        return sum(r) - sum(l);\n    }\n};\n\
    #line 8 \"library/DataStructure/BinaryIndexedTreeDouble.hpp\"\n\ntemplate<typename\
    \ T>\nstruct BinaryIndexedTreeDouble{\n    private:\n    int sz;\n    BinaryIndexedTree<T>\
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
    \ i){\n        return BIT0.sum(i) + BIT1.sum(i) * (T)i;\n    }\n\n    /**\n  \
    \   * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u534A\u958B\u533A\u9593[left,\
    \ right)\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n     * @param left \u534A\u958B\u533A\
    \u9593\u5DE6\u7AEF\n     * @param right \u534A\u958B\u533A\u9593\u53F3\u7AEF\n\
    \     * @return T \u533A\u9593[left, right)\u306E\u7DCF\u548C\n     */\n    T\
    \ query(int left, int right){\n        return sum(right - 1) - sum(left - 1);\n\
    \    }\n};\n#line 4 \"verify/AOJ/AOJ-DSL-2-G.test.cpp\"\n\nint main(){\n    int\
    \ n, q;\n    cin >> n >> q;\n    BinaryIndexedTreeDouble<long long> bit(n);\n\
    \    while(q--){\n        int query;\n        cin >> query;\n        if(query\
    \ == 0){\n            int s, t, x;\n            cin >> s >> t >> x;\n        \
    \    bit.add(s, t + 1, x);\n        }\n        else{\n            int s, t;\n\
    \            cin >> s >> t;\n            cout << bit.query(s, t + 1) << endl;\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#include \"../../library/DataStructure/BinaryIndexedTreeDouble.hpp\"\n\nint\
    \ main(){\n    int n, q;\n    cin >> n >> q;\n    BinaryIndexedTreeDouble<long\
    \ long> bit(n);\n    while(q--){\n        int query;\n        cin >> query;\n\
    \        if(query == 0){\n            int s, t, x;\n            cin >> s >> t\
    \ >> x;\n            bit.add(s, t + 1, x);\n        }\n        else{\n       \
    \     int s, t;\n            cin >> s >> t;\n            cout << bit.query(s,\
    \ t + 1) << endl;\n        }\n    }\n}"
  dependsOn:
  - library/DataStructure/BinaryIndexedTreeDouble.hpp
  - library/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: verify/AOJ/AOJ-DSL-2-G.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 12:21:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ/AOJ-DSL-2-G.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ/AOJ-DSL-2-G.test.cpp
- /verify/verify/AOJ/AOJ-DSL-2-G.test.cpp.html
title: verify/AOJ/AOJ-DSL-2-G.test.cpp
---
