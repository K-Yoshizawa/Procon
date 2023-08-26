---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/LazySegmentTree.hpp
    title: "Lazy Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
  bundledCode: "#line 1 \"verify/AOJ/AOJ-DSL-2-H.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
    \n\n#line 2 \"library/DataStructure/LazySegmentTree.hpp\"\n\n/**\n * @brief Lazy\
    \ Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n\
    \ */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename Monoid,\
    \ typename OperatorMonoid = Monoid>\nstruct LazySegmentTree{\n    private:\n \
    \   using F = function<Monoid(Monoid, Monoid)>;\n    using G = function<Monoid(Monoid,\
    \ OperatorMonoid)>;\n    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n\
    \n    int sz, height;\n    vector<Monoid> data;\n    vector<OperatorMonoid> lazy;\n\
    \    const F f;\n    const G g;\n    const H h;\n    const Monoid M1;\n    const\
    \ OperatorMonoid OM0;\n\n    void propagate(int k){\n        if(lazy[k] != OM0){\n\
    \            lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);\n            lazy[2\
    \ * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n            data[k] = reflect(k);\n\
    \            lazy[k] = OM0;\n        }\n    }\n\n    Monoid reflect(int k){\n\
    \        return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);\n    }\n\n   \
    \ void recalc(int k){\n        while(k >>= 1) data[k] = f(reflect(2 * k + 0),\
    \ reflect(2 * k + 1));\n    }\n\n    void thrust(int k){\n        for(int i =\
    \ height; i > 0; --i) propagate(k >> i);\n    }\n\n    public:\n    /**\n    \
    \ * @brief Construct a new Lazy Segment Tree object\n     * @param n \u30BB\u30B0\
    \u6728\u306E\u30B5\u30A4\u30BA\n     * @param f \u533A\u9593\u53D6\u5F97\u306E\
    \u4E8C\u9805\u6F14\u7B97(Monoid - Monoid)\n     * @param g \u9045\u5EF6\u8A55\u4FA1\
    \u306E\u4E8C\u9805\u6F14\u7B97(Monoid - OperatorMonoid)\n     * @param h \u533A\
    \u9593\u66F4\u65B0\u306E\u4E8C\u9805\u6F14\u7B97(OperatorMonoid - OperatorMonoid)\n\
    \     * @param M1 \u533A\u9593\u53D6\u5F97\u306E\u5358\u4F4D\u5143\n     * @param\
    \ OM0 \u533A\u9593\u66F4\u65B0\u306E\u5358\u4F4D\u5143\n     */\n    LazySegmentTree(int\
    \ n, const F f, const G g, const H h, const Monoid &M1, const OperatorMonoid &OM0)\
    \ : f(f), g(g), h(h), M1(M1), OM0(OM0){\n        sz = 1, height = 0;\n       \
    \ while(sz < n) sz <<= 1, ++height;\n        data.assign(2 * sz, M1);\n      \
    \  lazy.assign(2 * sz, OM0);\n    }\n\n    /**\n     * @brief 0-index\u306Ek\u756A\
    \u76EE\u306E\u8981\u7D20\u306B\u5024x\u3092\u30BB\u30C3\u30C8\u3059\u308B\u3002\
    \n     * @attention build\u524D\u306B\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\
    \n     * @param k \u30BB\u30C3\u30C8\u3059\u308B\u8981\u7D20\u756A\u53F7\n   \
    \  * @param x \u30BB\u30C3\u30C8\u3059\u308B\u5024\n     */\n    void set(int\
    \ k, const Monoid &x){\n        data[k + sz] = x;\n    }\n\n    /**\n     * @brief\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n \
    \    * @attention set\u3067\u5404\u8981\u7D20\u306E\u521D\u671F\u5024\u306F\u30BB\
    \u30C3\u30C8\u3057\u307E\u3057\u305F\u304B\uFF1F\n     */\n    void build(){\n\
    \        for(int k = sz - 1; k > 0; --k){\n            data[k] = f(data[2 * k\
    \ + 0], data[2 * k + 1]);\n        }\n    }\n\n    /**\n     * @brief 0-index\u534A\
    \u958B\u533A\u9593[a, b)\u3092\u5024x\u3092\u66F4\u65B0\u51E6\u7406\u3059\u308B\
    \u3002\n     * @param a \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n     * @param\
    \ b \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @param x \u66F4\u65B0\u3059\
    \u308B\u5024x\n     */\n    void update(int a, int b, const OperatorMonoid &x){\n\
    \        thrust(a += sz);\n        thrust(b += sz - 1);\n        for(int l = a,\
    \ r = b + 1; l < r; l >>= 1, r >>= 1){\n            if(l & 1) lazy[l] = h(lazy[l],\
    \ x), ++l;\n            if(r & 1) --r, lazy[r] = h(lazy[r], x);\n        }\n \
    \       recalc(a);\n        recalc(b);\n    }\n\n    /**\n     * @brief 0-index\u534A\
    \u958B\u533A\u9593[a, b)\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\u51E6\
    \u7406\u3059\u308B\u3002\n     * @param a \u534A\u958B\u533A\u9593\u306E\u5DE6\
    \u7AEF\n     * @param b \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ Monoid \u30AF\u30A8\u30EA\u306E\u7D50\u679C\n     */\n    Monoid query(int a,\
    \ int b){\n        thrust(a += sz);\n        thrust(b += sz - 1);\n        Monoid\
    \ L = M1, R = M1;\n        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1){\n\
    \            if(l & 1) L = f(L, reflect(l++));\n            if(r & 1) R = f(reflect(--r),\
    \ R);\n        }\n        return f(L, R);\n    }\n\n    /**\n     * @brief 0-index\u306E\
    1\u70B9k\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\
    \u3002\n     * @param k \u53D6\u5F97\u3057\u305F\u3044\u8981\u7D20\n     * @return\
    \ Monoid \u30AF\u30A8\u30EA\u306E\u7D50\u679C\n     */\n    Monoid query(int k){\n\
    \        return query(k, k + 1);\n    }\n\n    /**\n     * @brief \u73FE\u5728\
    \u306E\u8981\u7D20k\u306E\u5024\u3092\u5F97\u308B\u3002\n     * @param k \u53D6\
    \u5F97\u3057\u305F\u3044\u8981\u7D20\n     * @return Monoid \u8981\u7D20\u306E\
    \u5024\n     */\n    Monoid operator[](const int &k){\n        return query(k);\n\
    \    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593[a, b)\u3092\u51FA\u529B\
    \u3059\u308B\u3002\n     * @param a \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\
    \n     * @param b \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     */\n    void\
    \ print(int a, int b){\n        cerr << \"LST Data [\" << a << \", \" << b <<\"\
    ) : [\";\n        for(int i = a; i < b; ++i) cerr << query(i) << \" ]\"[i == b\
    \ - 1];\n        cerr << endl;\n    }\n};\n#line 4 \"verify/AOJ/AOJ-DSL-2-H.test.cpp\"\
    \n\nint main(){\n    int n, q;\n    cin >> n >> q;\n    LazySegmentTree<int> lst(n,\
    \ [](int a, int b){return min(a, b);},\n                                [](int\
    \ a, int b){return a + b;},\n                                [](int a, int b){return\
    \ a + b;},\n                                numeric_limits<int>::max(), 0);\n\
    \    for(int i = 0; i < n; ++i) lst.set(i, 0);\n    lst.build();\n    while(q--){\n\
    \        int query;\n        cin >> query;\n        if(query == 0){\n        \
    \    int s, t, x;\n            cin >> s >> t >> x;\n            lst.update(s,\
    \ t + 1, x);\n        }\n        else{\n            int s, t;\n            cin\
    \ >> s >> t;\n            cout << lst.query(s, t + 1) << endl;\n        }\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
    \n\n#include \"../../library/DataStructure/LazySegmentTree.hpp\"\n\nint main(){\n\
    \    int n, q;\n    cin >> n >> q;\n    LazySegmentTree<int> lst(n, [](int a,\
    \ int b){return min(a, b);},\n                                [](int a, int b){return\
    \ a + b;},\n                                [](int a, int b){return a + b;},\n\
    \                                numeric_limits<int>::max(), 0);\n    for(int\
    \ i = 0; i < n; ++i) lst.set(i, 0);\n    lst.build();\n    while(q--){\n     \
    \   int query;\n        cin >> query;\n        if(query == 0){\n            int\
    \ s, t, x;\n            cin >> s >> t >> x;\n            lst.update(s, t + 1,\
    \ x);\n        }\n        else{\n            int s, t;\n            cin >> s >>\
    \ t;\n            cout << lst.query(s, t + 1) << endl;\n        }\n    }\n}"
  dependsOn:
  - library/DataStructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: verify/AOJ/AOJ-DSL-2-H.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 12:21:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ/AOJ-DSL-2-H.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ/AOJ-DSL-2-H.test.cpp
- /verify/verify/AOJ/AOJ-DSL-2-H.test.cpp.html
title: verify/AOJ/AOJ-DSL-2-H.test.cpp
---
