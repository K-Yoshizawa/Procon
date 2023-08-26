---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/LC/LC-PointAddRangeSum-BIT.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"library/DataStructure/BinaryIndexedTree.hpp\"\
    \n\n/**\n * @brief Binary Indexed Tree\n */\n\n#line 8 \"library/DataStructure/BinaryIndexedTree.hpp\"\
    \nusing namespace std;\n\n/**\n * @brief \u533A\u9593\u306B\u5BFE\u3059\u308B\u4E00\
    \u70B9\u66F4\u65B0\u30FB\u533A\u9593\u548C\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\
    \u3057\u3066\u9AD8\u901F\u304B\u3064\u7C21\u6613\u306B\u5B9F\u88C5\u3067\u304D\
    \u308B\u30C7\u30FC\u30BF\u69CB\u9020\u3002 \n */\ntemplate<typename T>\nstruct\
    \ BinaryIndexedTree{\n    private:\n    vector<T> data;\n\n    public:\n    /**\n\
    \     * @brief Binary Indexed Tree\u3092\u8981\u7D20\u6570size\u3001\u50240\u3067\
    \u521D\u671F\u5316\u3059\u308B\u3002\n     * @param size \u914D\u5217\u306E\u8981\
    \u7D20\u6570\n     */\n    BinaryIndexedTree(int size){\n        data.resize(++size,\
    \ 0);\n    }\n\n    BinaryIndexedTree() = default;\n\n    /**\n     * @brief 1-index\u3067\
    \u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\u5BFE\u3057\u3066\u3001\u914D\u5217\
    \u306E\u6700\u521D\u304B\u3089i\u307E\u3067\u306E\u9589\u533A\u9593\u306E\u548C\
    \u3092\u6C42\u3081\u308B\u3002\n     * @param i \u6C42\u3081\u305F\u3044\u9589\
    \u533A\u9593\u53F3\u7AEF(1-index)\n     * @return T \u533A\u9593\u548C\n     */\n\
    \    T sum(int i){\n        T ret = 0;\n        while(i > 0){\n            ret\
    \ += data[i];\n            i -= i & -i;\n        }\n        return ret;\n    }\n\
    \n    /**\n     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\
    \u5BFE\u3057\u3066\u3001data[i]\u306Bx\u3092\u52A0\u3048\u308B\u3002\n     * @param\
    \ i \u52A0\u3048\u308B\u5834\u6240\n     * @param x \u52A0\u3048\u308B\u5024\n\
    \     */\n    void add(int i, T x){\n        while(i < data.size()){\n       \
    \     data[i] += x;\n            i += i & -i;\n        }\n    }\n\n    /**\n \
    \    * @brief 0-index\u3067\u8868\u3055\u308C\u308B\u534A\u958B\u533A\u9593[l,\
    \ r)\u306E\u533A\u9593\u548C\u3092\u6C42\u3081\u308B\u3002\n     * @param l \u533A\
    \u9593\u306E\u5DE6\u7AEF\n     * @param r \u533A\u9593\u306E\u53F3\u7AEF\n   \
    \  * @return T \u533A\u9593\u548C\n     */\n    T query(int l, int r){\n     \
    \   return sum(r) - sum(l);\n    }\n};\n#line 7 \"verify/LC/LC-PointAddRangeSum-BIT.test.cpp\"\
    \n\nint main(){\n    int N, Q;\n    cin >> N >> Q;\n    BinaryIndexedTree<long\
    \ long> bit(N);\n    for(int i = 1; i <= N; ++i){\n        long long a;\n    \
    \    cin >> a;\n        bit.add(i, a);\n    }\n    for(int i = 0; i < Q; ++i){\n\
    \        int q;\n        cin >> q;\n        if(q == 0){\n            int p, x;\n\
    \            cin >> p >> x;\n            bit.add(p + 1, x);\n        }\n     \
    \   else{\n            int l, r;\n            cin >> l >> r;\n            cout\
    \ << bit.query(l, r) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../library/DataStructure/BinaryIndexedTree.hpp\"\
    \n\nint main(){\n    int N, Q;\n    cin >> N >> Q;\n    BinaryIndexedTree<long\
    \ long> bit(N);\n    for(int i = 1; i <= N; ++i){\n        long long a;\n    \
    \    cin >> a;\n        bit.add(i, a);\n    }\n    for(int i = 0; i < Q; ++i){\n\
    \        int q;\n        cin >> q;\n        if(q == 0){\n            int p, x;\n\
    \            cin >> p >> x;\n            bit.add(p + 1, x);\n        }\n     \
    \   else{\n            int l, r;\n            cin >> l >> r;\n            cout\
    \ << bit.query(l, r) << endl;\n        }\n    }\n}"
  dependsOn:
  - library/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: verify/LC/LC-PointAddRangeSum-BIT.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 12:21:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC/LC-PointAddRangeSum-BIT.test.cpp
layout: document
redirect_from:
- /verify/verify/LC/LC-PointAddRangeSum-BIT.test.cpp
- /verify/verify/LC/LC-PointAddRangeSum-BIT.test.cpp.html
title: verify/LC/LC-PointAddRangeSum-BIT.test.cpp
---
