---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DSL-2-F.test.cpp
    title: verify_icpc/AOJ-DSL-2-F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
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
    \ k){\n        return query(k, k + 1);\n    }\n};\n"
  code: "#include \"Template.hpp\"\n\nstruct segtree{\n    int sz, ofs;\n    vl dat,\
    \ laz;\n    ll e, oe;\n\n    ll merge(ll x, ll y){\n        return min(x, y);\n\
    \    }\n\n    ll mapping(ll m, ll x){\n        return x;\n    }\n\n    ll composite(ll\
    \ x, ll y){\n        return y;\n    }\n\n    void eval(int i){\n        if(laz[i]\
    \ == oe) return;\n        if(i < sz){\n            laz[i * 2] = composite(laz[i\
    \ * 2], laz[i]);\n            laz[i * 2 + 1] = composite(laz[i * 2 + 1], laz[i]);\n\
    \        }\n        dat[i] = mapping(dat[i], laz[i]);\n        laz[i] = oe;\n\
    \    }\n\n    void subupdate(int ul, int ur, ll x, int l, int r, int i){\n   \
    \     eval(i);\n        if(ul <= l && r <= ur){\n            laz[i] = composite(laz[i],\
    \ x);\n            eval(i);\n        }\n        else if(ul < r && l < ur){\n \
    \           int m = (l + r) / 2;\n            subupdate(ul, ur, x, l, m, i * 2);\n\
    \            subupdate(ul, ur, x, m, r, i * 2 + 1);\n            dat[i] = merge(dat[i\
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
    \ k){\n        return query(k, k + 1);\n    }\n};"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2023-11-23 01:27:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-DSL-2-F.test.cpp
documentation_of: icpc/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/icpc/LazySegmentTree.hpp
- /library/icpc/LazySegmentTree.hpp.html
title: icpc/LazySegmentTree.hpp
---
