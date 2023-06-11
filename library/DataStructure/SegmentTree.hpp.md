---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-A.test.cpp
    title: verify/AOJ-DSL-2-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"library/DataStructure/SegmentTree.hpp\"\n\n/**\n * @brief\
    \ Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include <bits/stdc++.h>\n\
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
    \ T)> SEG_SUM = [](T x, T y){return x + y;};\n"
  code: "#pragma once\n\n/**\n * @brief Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename\
    \ Monoid>\nstruct SegmentTree{\n    private:\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n\n    int sz;\n    vector<Monoid> data;\n    const F f; // 2\u3064\
    \u306E\u533A\u9593\u3092\u30DE\u30FC\u30B8\u3059\u308B\u4E8C\u9805\u6F14\u7B97\
    \n    const Monoid M1; // \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u5404\u8981\
    \u7D20\u306E\u5358\u4F4D\u5143\n\n    public:\n    SegmentTree(int N, const F\
    \ f, const Monoid &M1) : f(f), M1(M1){\n        sz = 1;\n        while(sz < N)\
    \ sz <<= 1;\n        data.resize(2 * sz, M1);\n    }\n\n    SegmentTree() = default;\n\
    \n    void set(int k, const Monoid &x){\n        data[k + sz] = x;\n    }\n\n\
    \    void build(){\n        for(int k = sz - 1; k > 0; --k){\n            data[k]\
    \ = f(data[2 * k], data[2 * k + 1]);\n        }\n    }\n\n    void update(int\
    \ k, const Monoid &x){\n        k += sz;\n        data[k] = x;\n        while(k\
    \ >>= 1){\n            data[k] = f(data[2 * k], data[2 * k + 1]);\n        }\n\
    \    }\n\n    Monoid query(int left, int right){\n        Monoid L = M1, R = M1;\n\
    \        for(left += sz, right += sz; left < right; left >>= 1, right >>= 1){\n\
    \            if(left & 1) L = f(L, data[left++]);\n            if(right & 1) R\
    \ = f(data[--right], R);\n        }\n        return f(L, R);\n    }\n\n    Monoid\
    \ get(int k){\n        return data[k + sz];\n    }\n};\n\ntemplate<typename T>\n\
    const function<T(T, T)> SEG_MIN = [](T x, T y){return min(x, y);};\ntemplate<typename\
    \ T>\nconst function<T(T, T)> SEG_MAX = [](T x, T y){return max(x, y);};\ntemplate<typename\
    \ T>\nconst function<T(T, T)> SEG_SUM = [](T x, T y){return x + y;};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2023-06-12 01:07:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DSL-2-A.test.cpp
documentation_of: library/DataStructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/library/DataStructure/SegmentTree.hpp
- /library/library/DataStructure/SegmentTree.hpp.html
title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
