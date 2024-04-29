---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"verify/AOJ-DSL-2-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#line 1 \"library/DataStructure/BinaryIndexedTree.hpp\"\n/**\n * @file BinaryIndexedTree.hpp\n\
    \ * @author log K (lX57)\n * @brief Binary Indexed Tree\n * @version 2.0\n * @date\
    \ 2023-11-01\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct BinaryIndexedTree{\n    private:\n    int size_;\n    vector<T> data_;\n\
    \    bool zeroindex_;\n\n    public:\n    /**\n     * @brief Binary Indexed Tree\
    \ \u3092\u8981\u7D20\u6570 `Size` \u3067\u521D\u671F\u5316\u3059\u308B\n     *\
    \ @param Size \u8981\u7D20\u6570\n     * @param ZeroIndex `0-index` \u3067\u6271\
    \u3044\u305F\u3044\u304B (default = `false`)\n     */\n    BinaryIndexedTree(int\
    \ Size, bool ZeroIndex = false) : size_(Size), zeroindex_(ZeroIndex){\n      \
    \  data_.resize(size_ + 1, 0);\n    }\n\n    T sum(int i){\n        T ret = 0;\n\
    \        i += zeroindex_;\n        for(; i > 0; i -= i & -i) ret += data_[i];\n\
    \        return ret;\n    }\n\n    void add(int i, T x){\n        i += zeroindex_;\n\
    \        for(; i <= size_; i += i & -i) data_[i] += x;\n    }\n\n    T query(int\
    \ l, int r){\n        l += zeroindex_, r += zeroindex_;\n        return sum(r)\
    \ - sum(l - 1);\n    }\n};\n#line 4 \"verify/AOJ-DSL-2-B.test.cpp\"\n\nint main(){\n\
    \    int n, q; cin >> n >> q;\n    vector<long long> Init_Data(n, 0);\n    BinaryIndexedTree<long\
    \ long> BIT(n);\n    while(q--){\n        int com, x, y; cin >> com >> x >> y;\n\
    \        if(com == 0){\n            BIT.add(x, y);\n        }\n        if(com\
    \ == 1){\n            cout << BIT.query(x, y) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include \"../library/DataStructure/BinaryIndexedTree.hpp\"\n\nint main(){\n\
    \    int n, q; cin >> n >> q;\n    vector<long long> Init_Data(n, 0);\n    BinaryIndexedTree<long\
    \ long> BIT(n);\n    while(q--){\n        int com, x, y; cin >> com >> x >> y;\n\
    \        if(com == 0){\n            BIT.add(x, y);\n        }\n        if(com\
    \ == 1){\n            cout << BIT.query(x, y) << endl;\n        }\n    }\n}"
  dependsOn:
  - library/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-2-B.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 18:47:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-2-B.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-2-B.test.cpp
- /verify/verify/AOJ-DSL-2-B.test.cpp.html
title: verify/AOJ-DSL-2-B.test.cpp
---
