---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/DataStructure/SegmentTree.hpp
    title: latest/DataStructure/SegmentTree.hpp
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
  bundledCode: "#line 1 \"verify_latest/LC-PointAddRangeSum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 1 \"latest/DataStructure/SegmentTree.hpp\"\
    \n\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename Monoid>\n\
    struct SegmentTree{\n    private:\n    using F = function<Monoid(Monoid, Monoid)>;\n\
    \n    int __Size, __Offset, __ZeroIndex;\n    vector<Monoid> __Data;\n    const\
    \ F f;\n    const Monoid __M1;\n\n    inline void __Check(int x){\n        assert(1\
    \ <= x && x <= __Size);\n    }\n\n    Monoid __query(int ql, int qr, int left,\
    \ int right, int cell){\n        if(qr <= left || right <= ql){\n            return\
    \ __M1;\n        }\n        if(ql <= left && right <= qr){\n            return\
    \ __Data[cell];\n        }\n        int mid = (left + right) / 2;\n        Monoid\
    \ ans_left = __query(ql, qr, left, mid, 2 * cell);\n        Monoid ans_right =\
    \ __query(ql, qr, mid, right, 2 * cell + 1);\n        return f(ans_left, ans_right);\n\
    \    }\n\n    public:\n    SegmentTree(int Size, F Merge, const Monoid &Monoid_Identity,\
    \ bool ZeroIndex = false) : f(Merge), __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){\n\
    \        __Size = 1;\n        while(__Size < Size) __Size <<= 1;\n        __Offset\
    \ = __Size - 1;\n        __Data.resize(2 * __Size, __M1);\n    }\n\n    void build(){\n\
    \        for(int i = __Offset; i >= 1; --i){\n            __Data[i] = f(__Data[i\
    \ * 2 + 0], __Data[i * 2 + 1]);\n        }\n    }\n\n    void set(int Index, Monoid\
    \ Value){\n        __Check(Index + __ZeroIndex);\n        __Data[__Offset + Index\
    \ + __ZeroIndex] = Value;\n    }\n\n    SegmentTree(vector<Monoid> &Init_Data,\
    \ F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false) : f(Merge),\
    \ __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){\n        __Size = 1;\n      \
    \  while(__Size < (int)Init_Data.size()) __Size <<= 1;\n        __Offset = __Size\
    \ - 1;\n        __Data.resize(2 * __Size, __M1);\n        for(int i = 0; i < (int)Init_Data.size();\
    \ ++i){\n            __Data[__Size + i] = Init_Data[i];\n        }\n        build();\n\
    \    }\n\n    void update(int Index, Monoid Value){\n        __Check(Index + __ZeroIndex);\n\
    \        int k = __Offset + Index + __ZeroIndex;\n        __Data[k] = Value;\n\
    \        while(k >>= 1){\n            __Data[k] = f(__Data[2 * k], __Data[2 *\
    \ k + 1]);\n        }\n    }\n\n    Monoid query(int Left, int Right){\n     \
    \   __Check(Left + __ZeroIndex);\n        __Check(Right + __ZeroIndex - 1);\n\
    \        return __query(Left + __ZeroIndex, Right + __ZeroIndex, 1, __Size + 1,\
    \ 1);\n    }\n\n    Monoid get(int k){\n        __Check(k + __ZeroIndex);\n  \
    \      return __Data[__Offset + k + __ZeroIndex];\n    }\n\n    Monoid operator[](const\
    \ int &k){\n        return get(k);\n    }\n};\n#line 4 \"verify_latest/LC-PointAddRangeSum.test.cpp\"\
    \n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n \
    \   for(int i = 0; i < N; ++i) cin >> a[i];\n    SegmentTree<long long> seg(a,\
    \ [](long long x, long long y){return x + y;}, 0, true);\n    for(int query =\
    \ 0; query < Q; ++query){\n        int q; cin >> q;\n        if(q == 0){\n   \
    \         int p, x; cin >> p >> x;\n            seg.update(p, seg[p] + x);\n \
    \       }\n        else{\n            int l, r; cin >> l >> r;\n            cout\
    \ << seg.query(l, r) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../latest/DataStructure/SegmentTree.hpp\"\n\nint main(){\n    int\
    \ N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n    for(int i = 0; i < N;\
    \ ++i) cin >> a[i];\n    SegmentTree<long long> seg(a, [](long long x, long long\
    \ y){return x + y;}, 0, true);\n    for(int query = 0; query < Q; ++query){\n\
    \        int q; cin >> q;\n        if(q == 0){\n            int p, x; cin >> p\
    \ >> x;\n            seg.update(p, seg[p] + x);\n        }\n        else{\n  \
    \          int l, r; cin >> l >> r;\n            cout << seg.query(l, r) << endl;\n\
    \        }\n    }\n}"
  dependsOn:
  - latest/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify_latest/LC-PointAddRangeSum.test.cpp
  requiredBy: []
  timestamp: '2023-09-22 02:20:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_latest/LC-PointAddRangeSum.test.cpp
layout: document
redirect_from:
- /verify/verify_latest/LC-PointAddRangeSum.test.cpp
- /verify/verify_latest/LC-PointAddRangeSum.test.cpp.html
title: verify_latest/LC-PointAddRangeSum.test.cpp
---
