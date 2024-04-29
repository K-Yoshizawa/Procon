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
  bundledCode: "#line 1 \"verify/LC-PointAddRangeSum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 1 \"library/DataStructure/SegmentTree.hpp\"\
    \n/**\n * @file SegmentTree.hpp\n * @author log K (lX57)\n * @brief Segment Tree\
    \ - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @version 2.2\n * @date 2023-10-02\n\
    \ */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename Monoid>\n\
    struct SegmentTree{\n    private:\n    using F = function<Monoid(Monoid, Monoid)>;\n\
    \n    int m_size, m_offset, m_zeroindex;\n    vector<Monoid> m_data;\n    const\
    \ F f;\n    const Monoid m_m1;\n\n    inline void m_check(int x){\n        assert(1\
    \ <= x && x <= m_size);\n    }\n\n    public:\n    /**\n     * @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\u6570 `Size` \u3067\u521D\u671F\u5316\
    \u3059\u308B\u3002\n     * @param Size \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\
    \u8981\u7D20\u6570\n     * @param Merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\
    \u6F14\u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\
    \u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\u305F\
    \u3044\u304B (default = `false`)\n     */\n    SegmentTree(int Size, F Merge,\
    \ const Monoid &Monoid_Identity, bool ZeroIndex = false)\n    : f(Merge), m_m1(Monoid_Identity),\
    \ m_zeroindex(ZeroIndex){\n        m_size = 1;\n        while(m_size < Size) m_size\
    \ <<= 1;\n        m_offset = m_size - 1;\n        m_data.resize(2 * m_size, m_m1);\n\
    \    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\
    \u7BC9\u3059\u308B\u3002\n     * @attention \u5FC5\u305A `set()` \u3067\u521D\u671F\
    \u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\u3089\u547C\u3073\u51FA\u3059\u3053\
    \u3068\uFF01\n     */\n    void build(){\n        for(int i = m_offset; i >= 1;\
    \ --i){\n            m_data[i] = f(m_data[i * 2 + 0], m_data[i * 2 + 1]);\n  \
    \      }\n    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u306E\u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\u308B\u3002\n     * @param Index\
    \ \u4EE3\u5165\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     *\
    \ @param Value \u4EE3\u5165\u3059\u308B\u5024\n     */\n    void set(int Index,\
    \ Monoid Value){\n        m_check(Index + m_zeroindex);\n        m_data[m_offset\
    \ + Index + m_zeroindex] = Value;\n    }\n\n    /**\n     * @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u3092\u914D\u5217 `Init_Data` \u3067\u521D\u671F\u5316\
    \u3059\u308B\u3002\n     * @param Init_Data \u521D\u671F\u30C7\u30FC\u30BF\u306E\
    \u914D\u5217\n     * @param Merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\
    \u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B (default = `false`)\n     */\n    SegmentTree(vector<Monoid> &Init_Data,\
    \ F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\n    : f(Merge),\
    \ m_m1(Monoid_Identity), m_zeroindex(ZeroIndex){\n        m_size = 1;\n      \
    \  while(m_size < (int)Init_Data.size()) m_size <<= 1;\n        m_offset = m_size\
    \ - 1;\n        m_data.resize(2 * m_size, m_m1);\n        for(int i = 0; i < (int)Init_Data.size();\
    \ ++i){\n            m_data[m_size + i] = Init_Data[i];\n        }\n        build();\n\
    \    }\n\n    /**\n     * @brief \u4E00\u70B9\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\
    \u51E6\u7406\u3059\u308B\u3002\n     * @param Index \u66F4\u65B0\u5148\u306E\u8981\
    \u7D20\u756A\u53F7 (default = 1-index)\n     * @param Value \u66F4\u65B0\u3059\
    \u308B\u5024\n     */\n    void update(int Index, Monoid Value){\n        m_check(Index\
    \ + m_zeroindex);\n        int k = m_offset + Index + m_zeroindex;\n        m_data[k]\
    \ = Value;\n        while(k >>= 1){\n            m_data[k] = f(m_data[2 * k],\
    \ m_data[2 * k + 1]);\n        }\n    }\n\n    /**\n     * @brief \u534A\u958B\
    \u533A\u9593 `[Left, Right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\
    \u30A8\u30EA\u3092\u884C\u3046\u3002\n     * @param Left \u534A\u958B\u533A\u9593\
    \u306E\u5DE6\u7AEF\n     * @param Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\
    \n     * @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid\
    \ query(int Left, int Right){\n        if(Left == Right) return m_m1;\n      \
    \  m_check(Left + m_zeroindex);\n        m_check(Right + m_zeroindex - 1);\n \
    \       int l = Left + m_zeroindex + m_offset, r = Right + m_zeroindex + m_offset;\n\
    \        Monoid al = m_m1, ar = m_m1;\n        while(l < r){\n            if(l\
    \ & 1) al = f(al, m_data[l++]);\n            if(r & 1) ar = f(m_data[--r], ar);\n\
    \            l >>= 1, r >>= 1;\n        }\n        return f(al, ar);\n    }\n\n\
    \    /**\n     * @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\u3059\u308B\u3002\n     * @param k \u53D6\u5F97\u5148\u306E\u8981\u7D20\
    \u756A\u53F7 (default = 1-index)\n     * @return Monoid \u53D6\u5F97\u3057\u305F\
    \u7D50\u679C\n     */\n    Monoid get(int k){\n        m_check(k + m_zeroindex);\n\
    \        return m_data[m_offset + k + m_zeroindex];\n    }\n\n    Monoid operator[](const\
    \ int &k){\n        return get(k);\n    }\n};\n#line 4 \"verify/LC-PointAddRangeSum.test.cpp\"\
    \n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n \
    \   for(int i = 0; i < N; ++i) cin >> a[i];\n    SegmentTree<long long> seg(a,\
    \ [](long long x, long long y){return x + y;}, 0, true);\n    for(int query =\
    \ 0; query < Q; ++query){\n        int q; cin >> q;\n        if(q == 0){\n   \
    \         int p, x; cin >> p >> x;\n            seg.update(p, seg[p] + x);\n \
    \       }\n        else{\n            int l, r; cin >> l >> r;\n            cout\
    \ << seg.query(l, r) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../library/DataStructure/SegmentTree.hpp\"\n\nint main(){\n    int\
    \ N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n    for(int i = 0; i < N;\
    \ ++i) cin >> a[i];\n    SegmentTree<long long> seg(a, [](long long x, long long\
    \ y){return x + y;}, 0, true);\n    for(int query = 0; query < Q; ++query){\n\
    \        int q; cin >> q;\n        if(q == 0){\n            int p, x; cin >> p\
    \ >> x;\n            seg.update(p, seg[p] + x);\n        }\n        else{\n  \
    \          int l, r; cin >> l >> r;\n            cout << seg.query(l, r) << endl;\n\
    \        }\n    }\n}"
  dependsOn:
  - library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify/LC-PointAddRangeSum.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 00:45:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-PointAddRangeSum.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-PointAddRangeSum.test.cpp
- /verify/verify/LC-PointAddRangeSum.test.cpp.html
title: verify/LC-PointAddRangeSum.test.cpp
---
