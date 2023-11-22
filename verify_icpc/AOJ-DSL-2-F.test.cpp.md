---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/LazySegmentTree.hpp
    title: icpc/LazySegmentTree.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
  bundledCode: "#line 1 \"verify_icpc/AOJ-DSL-2-F.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\
    \n\n#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/LazySegmentTree.hpp\"\
    \n\nstruct segtree{\n    int sz, ofs;\n    vl dat, laz;\n    ll e, oe;\n\n   \
    \ ll merge(ll x, ll y){\n        return min(x, y);\n    }\n\n    ll mapping(ll\
    \ m, ll x){\n        return x;\n    }\n\n    ll composite(ll x, ll y){\n     \
    \   return y;\n    }\n\n    void eval(int i){\n        if(laz[i] == oe) return;\n\
    \        if(i < sz){\n            laz[i * 2] = composite(laz[i * 2], laz[i]);\n\
    \            laz[i * 2 + 1] = composite(laz[i * 2 + 1], laz[i]);\n        }\n\
    \        dat[i] = mapping(dat[i], laz[i]);\n        laz[i] = oe;\n    }\n\n  \
    \  void subupdate(int ul, int ur, ll x, int l, int r, int i){\n        eval(i);\n\
    \        if(ul <= l && r <= ur){\n            laz[i] = composite(laz[i], x);\n\
    \            eval(i);\n        }\n        else if(ul < r && l < ur){\n       \
    \     int m = (l + r) / 2;\n            subupdate(ul, ur, x, l, m, i * 2);\n \
    \           subupdate(ul, ur, x, m, r, i * 2 + 1);\n            dat[i] = merge(dat[i\
    \ * 2], dat[i * 2 + 1]);\n        }\n    }\n\n    ll subquery(int ql, int qr,\
    \ int l, int r, int i){\n        eval(i);\n        if(qr <= l || r <= ql) return\
    \ e;\n        if(ql <= l && r <= qr) return dat[i];\n        int m = (l + r) /\
    \ 2;\n        ll al = subquery(ql, qr, l, m, i * 2);\n        ll ar = subquery(ql,\
    \ qr, m, r, i * 2 + 1);\n        return merge(al, ar);\n    }\n\n    segtree(vl\
    \ &init) : e((1LL << 31) - 1), oe((1LL << 31) - 1){\n        sz = 1;\n       \
    \ while(sz < init.size()) sz <<= 1;\n        ofs = sz - 1;\n        dat.resize(sz\
    \ * 2, e);\n        laz.resize(sz * 2, oe);\n        for(int i = 0; i < init.size();\
    \ ++i) dat[sz + i] = init[i];\n        for(int i = ofs; i >= 1; --i) dat[i] =\
    \ merge(dat[i * 2], dat[i * 2 + 1]);\n    }\n\n    void update(int l, int r, ll\
    \ v){\n        subupdate(l, r, v, 1, sz + 1, 1);\n    }\n\n    ll query(int l,\
    \ int r){\n        return subquery(l, r, 1, sz + 1, 1);\n    }\n\n    ll get(int\
    \ k){\n        return query(k, k + 1);\n    }\n};\n#line 4 \"verify_icpc/AOJ-DSL-2-F.test.cpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    long long INF = (1LL << 31)\
    \ - 1;\n    vector<long long> Init_Data(n, INF);\n    segtree seg(Init_Data);\n\
    \    while(q--){\n        int com; cin >> com;\n        if(com == 0){\n      \
    \      int s, t, x; cin >> s >> t >> x, ++s, ++t;\n            seg.update(s, t\
    \ + 1, x);\n        }\n        if(com == 1){\n            int s, t; cin >> s >>\
    \ t, ++s, ++t;\n            cout << seg.query(s, t + 1) << endl;\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\
    \n\n#include \"../icpc/LazySegmentTree.hpp\"\n\nint main(){\n    int n, q; cin\
    \ >> n >> q;\n    long long INF = (1LL << 31) - 1;\n    vector<long long> Init_Data(n,\
    \ INF);\n    segtree seg(Init_Data);\n    while(q--){\n        int com; cin >>\
    \ com;\n        if(com == 0){\n            int s, t, x; cin >> s >> t >> x, ++s,\
    \ ++t;\n            seg.update(s, t + 1, x);\n        }\n        if(com == 1){\n\
    \            int s, t; cin >> s >> t, ++s, ++t;\n            cout << seg.query(s,\
    \ t + 1) << endl;\n        }\n    }\n}"
  dependsOn:
  - icpc/LazySegmentTree.hpp
  - icpc/Template.hpp
  isVerificationFile: true
  path: verify_icpc/AOJ-DSL-2-F.test.cpp
  requiredBy: []
  timestamp: '2023-11-23 01:45:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_icpc/AOJ-DSL-2-F.test.cpp
layout: document
redirect_from:
- /verify/verify_icpc/AOJ-DSL-2-F.test.cpp
- /verify/verify_icpc/AOJ-DSL-2-F.test.cpp.html
title: verify_icpc/AOJ-DSL-2-F.test.cpp
---
