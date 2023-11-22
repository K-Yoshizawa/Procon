---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DSL-2-A.test.cpp
    title: verify_icpc/AOJ-DSL-2-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/SegmentTree.hpp\"\
    \n\nstruct segtree{\n    int sz, ofs;\n    vl dat;\n    ll e;\n\n    ll merge(ll\
    \ x, ll y){\n        return min(x, y);\n    }\n\n    ll subquery(int ql, int qr,\
    \ int l, int r, int i){\n        if(qr <= l || r <= ql) return e;\n        if(ql\
    \ <= l && r <= qr) return dat[i];\n        int m = (l + r) / 2;\n        ll al\
    \ = subquery(ql, qr, l, m, i * 2);\n        ll ar = subquery(ql, qr, m, r, i *\
    \ 2 + 1);\n        return merge(al, ar);\n    }\n    \n    segtree(vl &init) :\
    \ e((1LL << 31) - 1){\n        sz = 1;\n        while(sz < init.size()) sz <<=\
    \ 1;\n        ofs = sz - 1;\n        dat.resize(sz * 2, e);\n        for(int i\
    \ = 0; i < init.size(); ++i) dat[sz + i] = init[i];\n        for(int i = ofs;\
    \ i >= 1; --i) dat[i] = merge(dat[i * 2], dat[i * 2 + 1]);\n    }\n\n    void\
    \ update(int k, ll v){\n        k += ofs;\n        dat[k] = v;\n        while(k\
    \ >>= 1) dat[k] = merge(dat[k * 2], dat[k * 2 + 1]);\n    }\n\n    ll query(int\
    \ l, int r){\n        return subquery(l, r, 1, sz + 1, 1);\n    }\n\n    ll get(int\
    \ k){\n        return dat[k + ofs];\n    }\n};\n"
  code: "#include \"Template.hpp\"\n\nstruct segtree{\n    int sz, ofs;\n    vl dat;\n\
    \    ll e;\n\n    ll merge(ll x, ll y){\n        return min(x, y);\n    }\n\n\
    \    ll subquery(int ql, int qr, int l, int r, int i){\n        if(qr <= l ||\
    \ r <= ql) return e;\n        if(ql <= l && r <= qr) return dat[i];\n        int\
    \ m = (l + r) / 2;\n        ll al = subquery(ql, qr, l, m, i * 2);\n        ll\
    \ ar = subquery(ql, qr, m, r, i * 2 + 1);\n        return merge(al, ar);\n   \
    \ }\n    \n    segtree(vl &init) : e((1LL << 31) - 1){\n        sz = 1;\n    \
    \    while(sz < init.size()) sz <<= 1;\n        ofs = sz - 1;\n        dat.resize(sz\
    \ * 2, e);\n        for(int i = 0; i < init.size(); ++i) dat[sz + i] = init[i];\n\
    \        for(int i = ofs; i >= 1; --i) dat[i] = merge(dat[i * 2], dat[i * 2 +\
    \ 1]);\n    }\n\n    void update(int k, ll v){\n        k += ofs;\n        dat[k]\
    \ = v;\n        while(k >>= 1) dat[k] = merge(dat[k * 2], dat[k * 2 + 1]);\n \
    \   }\n\n    ll query(int l, int r){\n        return subquery(l, r, 1, sz + 1,\
    \ 1);\n    }\n\n    ll get(int k){\n        return dat[k + ofs];\n    }\n};"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/SegmentTree.hpp
  requiredBy: []
  timestamp: '2023-11-23 01:27:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-DSL-2-A.test.cpp
documentation_of: icpc/SegmentTree.hpp
layout: document
redirect_from:
- /library/icpc/SegmentTree.hpp
- /library/icpc/SegmentTree.hpp.html
title: icpc/SegmentTree.hpp
---
