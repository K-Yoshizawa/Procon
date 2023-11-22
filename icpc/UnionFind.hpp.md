---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DSL-1-A.test.cpp
    title: verify_icpc/AOJ-DSL-1-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/UnionFind.hpp\"\
    \n\nstruct unionfind{\n    vi dat;\n\n    unionfind(int sz):dat(sz,-1){}\n\n \
    \   int find(int k){\n        if(dat[k]<0)return k;\n        return dat[k]=find(dat[k]);\n\
    \    }\n\n    bool same(int x,int y){\n        return find(x)==find(y);\n    }\n\
    \n    bool unite(int x,int y){\n        x=find(x),y=find(y);\n        if(x==y)\
    \ return false;\n        if(dat[x]>dat[y]) swap(x,y);\n        dat[x]+=dat[y];\n\
    \        dat[y]=x;\n        return true;\n    }\n};\n"
  code: "#include \"Template.hpp\"\n\nstruct unionfind{\n    vi dat;\n\n    unionfind(int\
    \ sz):dat(sz,-1){}\n\n    int find(int k){\n        if(dat[k]<0)return k;\n  \
    \      return dat[k]=find(dat[k]);\n    }\n\n    bool same(int x,int y){\n   \
    \     return find(x)==find(y);\n    }\n\n    bool unite(int x,int y){\n      \
    \  x=find(x),y=find(y);\n        if(x==y) return false;\n        if(dat[x]>dat[y])\
    \ swap(x,y);\n        dat[x]+=dat[y];\n        dat[y]=x;\n        return true;\n\
    \    }\n};"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/UnionFind.hpp
  requiredBy: []
  timestamp: '2023-11-12 23:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-DSL-1-A.test.cpp
documentation_of: icpc/UnionFind.hpp
layout: document
redirect_from:
- /library/icpc/UnionFind.hpp
- /library/icpc/UnionFind.hpp.html
title: icpc/UnionFind.hpp
---
