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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/LC/LC-PointAddRangeSum-ST.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"library/DataStructure/SegmentTree.hpp\"\n\n\
    /**\n * @brief Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#line\
    \ 8 \"library/DataStructure/SegmentTree.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ Monoid>\nstruct SegmentTree{\n    private:\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n\n    int sz;\n    vector<Monoid> data;\n    const F f; // 2\u3064\
    \u306E\u533A\u9593\u3092\u30DE\u30FC\u30B8\u3059\u308B\u4E8C\u9805\u6F14\u7B97\
    \n    const Monoid M1; // \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u5404\u8981\
    \u7D20\u306E\u5358\u4F4D\u5143\n\n    public:\n    /**\n     * @brief Construct\
    \ a new Segment Tree object\n     * @param N \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u306E\u30B5\u30A4\u30BA\n     * @param f 2\u8981\u7D20\u3092\u30DE\u30FC\u30B8\
    \u3059\u308B\u6F14\u7B97\u5B50\n     * @param M1 \u5358\u4F4D\u5143\n     * @note\
    \ \u5404\u8981\u7D20\u306E\u521D\u671F\u5024\u306FM1\u306B\u306A\u308B\u3002\u521D\
    \u671F\u5024\u3092\u5225\u3067\u8A2D\u5B9A\u3057\u305F\u3044\u5834\u5408\u306F\
    set\u95A2\u6570\u3092\u4F7F\u3046\u3002\n     */\n    SegmentTree(int N, const\
    \ F f, const Monoid &M1) : f(f), M1(M1){\n        sz = 1;\n        while(sz <\
    \ N) sz <<= 1;\n        data.resize(2 * sz, M1);\n    }\n\n    SegmentTree() =\
    \ default;\n\n    /**\n     * @brief \u6307\u5B9A\u3057\u305F\u8981\u7D20\u306B\
    \u521D\u671F\u5024\u3092\u8A2D\u5B9A\u3059\u308B\u3002\n     * @note \u3053\u306E\
    \u95A2\u6570\u306Fbuild\u95A2\u6570\u547C\u3073\u51FA\u3057\u524D\u306B\u884C\u3046\
    \u3053\u3068\u3002\n     * @attention 1-index\u3067\u6307\u5B9A\u3059\u308B\u3053\
    \u3068\uFF01\n     * @param k \u8A2D\u5B9A\u3057\u305F\u3044\u8981\u7D20\u756A\
    \u53F7\uFF081-index\uFF09\n     * @param x \u8A2D\u5B9A\u3057\u305F\u3044\u5024\
    \n     */\n    void set(int k, const Monoid &x){\n        data[k + sz] = x;\n\
    \    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\
    \u7BC9\u3059\u308B\u3002\n     * @note \u521D\u671F\u5024\u306E\u8A2D\u5B9A\u306F\
    \u3053\u306E\u95A2\u6570\u3092\u547C\u3073\u51FA\u3059\u524D\u306Bset\u95A2\u6570\
    \u3067\u884C\u3046\u3053\u3068\u3002\n     */\n    void build(){\n        for(int\
    \ k = sz - 1; k > 0; --k){\n            data[k] = f(data[2 * k], data[2 * k +\
    \ 1]);\n        }\n    }\n\n    /**\n     * @brief 1\u70B9\u66F4\u65B0\u30AF\u30A8\
    \u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\n     * @attention 1-index\u3067\u6307\
    \u5B9A\u3059\u308B\u3053\u3068\uFF01\n     * @param k \u66F4\u65B0\u3057\u305F\
    \u3044\u8981\u7D20\u756A\u53F7\uFF081-index\uFF09\n     * @param x \u66F4\u65B0\
    \u3057\u305F\u3044\u5024\n     */\n    void update(int k, const Monoid &x){\n\
    \        k += sz;\n        data[k] = x;\n        while(k >>= 1){\n           \
    \ data[k] = f(data[2 * k], data[2 * k + 1]);\n        }\n    }\n\n    /**\n  \
    \   * @brief \u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\
    \u308B\u3002\n     * @attention 1-index\u30FB\u534A\u958B\u533A\u9593\u3067\u6307\
    \u5B9A\u3059\u308B\u3053\u3068\uFF01\n     * @param left \u534A\u958B\u533A\u9593\
    \u59CB\u70B9\uFF081-index\uFF09\n     * @param right \u534A\u958B\u533A\u9593\u7D42\
    \u70B9\uFF081-index\uFF09\n     * @return Monoid \u30AF\u30A8\u30EA\u51E6\u7406\
    \u7D50\u679C\n     */\n    Monoid query(int left, int right){\n        Monoid\
    \ L = M1, R = M1;\n        for(left += sz, right += sz; left < right; left >>=\
    \ 1, right >>= 1){\n            if(left & 1) L = f(L, data[left++]);\n       \
    \     if(right & 1) R = f(data[--right], R);\n        }\n        return f(L, R);\n\
    \    }\n\n    /**\n     * @brief \u6307\u5B9A\u3057\u305F\u8981\u7D20\u306E\u5024\
    \u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @attention 1-index\u3067\u6307\u5B9A\
    \u3059\u308B\u3053\u3068\uFF01\n     * @param k \u53D6\u5F97\u3057\u305F\u3044\
    \u8981\u7D20\u756A\u53F7\uFF081-index\uFF09\n     * @return Monoid \u53D6\u5F97\
    \u7D50\u679C\n     */\n    Monoid get(int k){\n        return data[k + sz];\n\
    \    }\n\n    /**\n     * @brief \u5168\u8981\u7D20\u306E\u5024\u3092\u53D6\u5F97\
    \u3059\u308B\u3002\n     * @param length \u5143\u914D\u5217\u306E\u9577\u3055\n\
    \     * @return vector<Monoid> \u5168\u8981\u7D20\u306E\u5024\n     */\n    vector<Monoid>\
    \ get_list(int length){\n        vector<Monoid> ret(length);\n        for(int\
    \ i = 0; i < length; ++i){\n            ret[i] = get(i);\n        }\n        return\
    \ ret;\n    }\n};\n\ntemplate<typename T>\nconst function<T(T, T)> SEG_MIN = [](T\
    \ x, T y){return min(x, y);};\ntemplate<typename T>\nconst function<T(T, T)> SEG_MAX\
    \ = [](T x, T y){return max(x, y);};\ntemplate<typename T>\nconst function<T(T,\
    \ T)> SEG_SUM = [](T x, T y){return x + y;};\n#line 7 \"verify/LC/LC-PointAddRangeSum-ST.test.cpp\"\
    \n\nint main(){\n    int N, Q;\n    cin >> N >> Q;\n    SegmentTree<long long>\
    \ seg(N, [](auto x, auto y){return x + y;}, 0LL);\n    for(int i = 1; i <= N;\
    \ ++i){\n        long long a;\n        cin >> a;\n        seg.set(i, a);\n   \
    \ }\n    seg.build();\n    for(int i = 0; i < Q; ++i){\n        int q;\n     \
    \   cin >> q;\n        if(q == 0){\n            int p, x;\n            cin >>\
    \ p >> x;\n            seg.update(p + 1, seg.get(p + 1) + x);\n        }\n   \
    \     else{\n            int l, r;\n            cin >> l >> r;\n            cout\
    \ << seg.query(l + 1, r + 1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../library/DataStructure/SegmentTree.hpp\"\
    \n\nint main(){\n    int N, Q;\n    cin >> N >> Q;\n    SegmentTree<long long>\
    \ seg(N, [](auto x, auto y){return x + y;}, 0LL);\n    for(int i = 1; i <= N;\
    \ ++i){\n        long long a;\n        cin >> a;\n        seg.set(i, a);\n   \
    \ }\n    seg.build();\n    for(int i = 0; i < Q; ++i){\n        int q;\n     \
    \   cin >> q;\n        if(q == 0){\n            int p, x;\n            cin >>\
    \ p >> x;\n            seg.update(p + 1, seg.get(p + 1) + x);\n        }\n   \
    \     else{\n            int l, r;\n            cin >> l >> r;\n            cout\
    \ << seg.query(l + 1, r + 1) << endl;\n        }\n    }\n}"
  dependsOn:
  - library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify/LC/LC-PointAddRangeSum-ST.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 12:21:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC/LC-PointAddRangeSum-ST.test.cpp
layout: document
redirect_from:
- /verify/verify/LC/LC-PointAddRangeSum-ST.test.cpp
- /verify/verify/LC/LC-PointAddRangeSum-ST.test.cpp.html
title: verify/LC/LC-PointAddRangeSum-ST.test.cpp
---
