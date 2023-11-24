---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/SegmentTree.hpp
    title: icpc/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
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
  bundledCode: "#line 1 \"verify_icpc/AOJ-DSL-2-A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\nusing pi = pair<int, int>;\n\
    #line 2 \"icpc/SegmentTree.hpp\"\n\nstruct segtree{\n    int sz, ofs;\n    vl\
    \ dat;\n    ll e;\n\n    ll merge(ll x, ll y){\n        return min(x, y);\n  \
    \  }\n\n    ll subquery(int ql, int qr, int l, int r, int i){\n        if(qr <=\
    \ l || r <= ql) return e;\n        if(ql <= l && r <= qr) return dat[i];\n   \
    \     int m = (l + r) / 2;\n        ll al = subquery(ql, qr, l, m, i * 2);\n \
    \       ll ar = subquery(ql, qr, m, r, i * 2 + 1);\n        return merge(al, ar);\n\
    \    }\n    \n    segtree(vl &init) : e((1LL << 31) - 1){\n        sz = 1;\n \
    \       while(sz < init.size()) sz <<= 1;\n        ofs = sz - 1;\n        dat.resize(sz\
    \ * 2, e);\n        for(int i = 0; i < init.size(); ++i) dat[sz + i] = init[i];\n\
    \        for(int i = ofs; i >= 1; --i) dat[i] = merge(dat[i * 2], dat[i * 2 +\
    \ 1]);\n    }\n\n    void update(int k, ll v){\n        k += ofs;\n        dat[k]\
    \ = v;\n        while(k >>= 1) dat[k] = merge(dat[k * 2], dat[k * 2 + 1]);\n \
    \   }\n\n    ll query(int l, int r){\n        return subquery(l, r, 1, sz + 1,\
    \ 1);\n    }\n\n    ll get(int k){\n        return dat[k + ofs];\n    }\n};\n\
    #line 4 \"verify_icpc/AOJ-DSL-2-A.test.cpp\"\n\nint main(){\n    int n, q; cin\
    \ >> n >> q;\n    long long INF = (1LL << 31) - 1;\n    vector<long long> Init_Data(n,\
    \ INF);\n    segtree seg(Init_Data);\n    while(q--){\n        int com, x, y;\
    \ cin >> com >> x >> y;\n        if(com == 0){\n            ++x;\n           \
    \ seg.update(x, y);\n        }\n        if(com == 1){\n            ++x, ++y;\n\
    \            cout << seg.query(x, y + 1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include \"../icpc/SegmentTree.hpp\"\n\nint main(){\n    int n, q; cin >>\
    \ n >> q;\n    long long INF = (1LL << 31) - 1;\n    vector<long long> Init_Data(n,\
    \ INF);\n    segtree seg(Init_Data);\n    while(q--){\n        int com, x, y;\
    \ cin >> com >> x >> y;\n        if(com == 0){\n            ++x;\n           \
    \ seg.update(x, y);\n        }\n        if(com == 1){\n            ++x, ++y;\n\
    \            cout << seg.query(x, y + 1) << endl;\n        }\n    }\n}"
  dependsOn:
  - icpc/SegmentTree.hpp
  - icpc/Template.hpp
  isVerificationFile: true
  path: verify_icpc/AOJ-DSL-2-A.test.cpp
  requiredBy: []
  timestamp: '2023-11-24 19:51:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_icpc/AOJ-DSL-2-A.test.cpp
layout: document
redirect_from:
- /verify/verify_icpc/AOJ-DSL-2-A.test.cpp
- /verify/verify_icpc/AOJ-DSL-2-A.test.cpp.html
title: verify_icpc/AOJ-DSL-2-A.test.cpp
---
