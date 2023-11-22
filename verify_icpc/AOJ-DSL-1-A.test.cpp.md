---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/UnionFind.hpp
    title: icpc/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"verify_icpc/AOJ-DSL-1-A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/UnionFind.hpp\"\
    \n\nstruct unionfind{\n    vi dat;\n\n    unionfind(int sz):dat(sz,-1){}\n\n \
    \   int find(int k){\n        if(dat[k]<0)return k;\n        return dat[k]=find(dat[k]);\n\
    \    }\n\n    bool same(int x,int y){\n        return find(x)==find(y);\n    }\n\
    \n    bool unite(int x,int y){\n        x=find(x),y=find(y);\n        if(x==y)\
    \ return false;\n        if(dat[x]>dat[y]) swap(x,y);\n        dat[x]+=dat[y];\n\
    \        dat[y]=x;\n        return true;\n    }\n};\n#line 4 \"verify_icpc/AOJ-DSL-1-A.test.cpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n\n    unionfind uf(n);\n    while(q--){\n\
    \        int com, x, y; cin >> com >> x >> y;\n        if(com == 0) uf.unite(x,\
    \ y);\n        else cout << (uf.same(x, y) ? 1 : 0) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include \"../icpc/UnionFind.hpp\"\n\nint main(){\n    int n, q; cin >> n\
    \ >> q;\n\n    unionfind uf(n);\n    while(q--){\n        int com, x, y; cin >>\
    \ com >> x >> y;\n        if(com == 0) uf.unite(x, y);\n        else cout << (uf.same(x,\
    \ y) ? 1 : 0) << endl;\n    }\n}"
  dependsOn:
  - icpc/UnionFind.hpp
  - icpc/Template.hpp
  isVerificationFile: true
  path: verify_icpc/AOJ-DSL-1-A.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 23:20:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_icpc/AOJ-DSL-1-A.test.cpp
layout: document
redirect_from:
- /verify/verify_icpc/AOJ-DSL-1-A.test.cpp
- /verify/verify_icpc/AOJ-DSL-1-A.test.cpp.html
title: verify_icpc/AOJ-DSL-1-A.test.cpp
---
