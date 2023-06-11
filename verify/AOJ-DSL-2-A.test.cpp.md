---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/SegmentTree.hpp
    title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"verify/AOJ-DSL-2-A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#line 2 \"library/DataStructure/SegmentTree.hpp\"\n\n/**\n * @brief Segment\
    \ Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename Monoid>\nstruct SegmentTree{\n    private:\n\
    \    using F = function<Monoid(Monoid, Monoid)>;\n\n    int sz;\n    vector<Monoid>\
    \ data;\n    const F f; // 2\u3064\u306E\u533A\u9593\u3092\u30DE\u30FC\u30B8\u3059\
    \u308B\u4E8C\u9805\u6F14\u7B97\n    const Monoid M1; // \u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\u306E\u5404\u8981\u7D20\u306E\u5358\u4F4D\u5143\n\n    public:\n\
    \    SegmentTree(int N, const F f, const Monoid &M1) : f(f), M1(M1){\n       \
    \ sz = 1;\n        while(sz < N) sz <<= 1;\n        data.resize(2 * sz, M1);\n\
    \    }\n\n    SegmentTree() = default;\n\n    void set(int k, const Monoid &x){\n\
    \        data[k + sz] = x;\n    }\n\n    void build(){\n        for(int k = sz\
    \ - 1; k > 0; --k){\n            data[k] = f(data[2 * k], data[2 * k + 1]);\n\
    \        }\n    }\n\n    void update(int k, const Monoid &x){\n        k += sz;\n\
    \        data[k] = x;\n        while(k >>= 1){\n            data[k] = f(data[2\
    \ * k], data[2 * k + 1]);\n        }\n    }\n\n    Monoid query(int left, int\
    \ right){\n        Monoid L = M1, R = M1;\n        for(left += sz, right += sz;\
    \ left < right; left >>= 1, right >>= 1){\n            if(left & 1) L = f(L, data[left++]);\n\
    \            if(right & 1) R = f(data[--right], R);\n        }\n        return\
    \ f(L, R);\n    }\n\n    Monoid get(int k){\n        return data[k + sz];\n  \
    \  }\n};\n\ntemplate<typename T>\nconst function<T(T, T)> SEG_MIN = [](T x, T\
    \ y){return min(x, y);};\ntemplate<typename T>\nconst function<T(T, T)> SEG_MAX\
    \ = [](T x, T y){return max(x, y);};\ntemplate<typename T>\nconst function<T(T,\
    \ T)> SEG_SUM = [](T x, T y){return x + y;};\n#line 4 \"verify/AOJ-DSL-2-A.test.cpp\"\
    \n\nint main(){\n    int n, q;\n    cin >> n >> q;\n\n    SegmentTree<int> RMQ(n,\
    \ SEG_MIN<int>, numeric_limits<int>::max());\n    RMQ.build();\n    while(q--){\n\
    \        int com, x, y;\n        cin >> com >> x >> y;\n        if(com == 0){\n\
    \            RMQ.update(x, y);\n        }\n        else{\n            cout <<\
    \ RMQ.query(x, y + 1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include \"../library/DataStructure/SegmentTree.hpp\"\n\nint main(){\n   \
    \ int n, q;\n    cin >> n >> q;\n\n    SegmentTree<int> RMQ(n, SEG_MIN<int>, numeric_limits<int>::max());\n\
    \    RMQ.build();\n    while(q--){\n        int com, x, y;\n        cin >> com\
    \ >> x >> y;\n        if(com == 0){\n            RMQ.update(x, y);\n        }\n\
    \        else{\n            cout << RMQ.query(x, y + 1) << endl;\n        }\n\
    \    }\n}"
  dependsOn:
  - library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-2-A.test.cpp
  requiredBy: []
  timestamp: '2023-06-12 01:07:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-2-A.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-2-A.test.cpp
- /verify/verify/AOJ-DSL-2-A.test.cpp.html
title: verify/AOJ-DSL-2-A.test.cpp
---
