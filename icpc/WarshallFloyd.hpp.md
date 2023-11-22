---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-1-C.test.cpp
    title: verify_icpc/AOJ-GRL-1-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/WarshallFloyd.hpp\"\
    \n\nll INF = (1LL << 31) - 1;\n\nbool warshallfloyd(vvl &g){\n    int v = g.size();\n\
    \    for(int i = 0; i < v; ++i) g[i][i] = 0;\n    for(int k = 0; k < v; ++k){\n\
    \        for(int i = 0; i < v; ++i){\n            for(int j = 0; j < v; ++j){\n\
    \                if(g[i][k] == INF || g[k][j] == INF) continue;\n            \
    \    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);\n            }\n        }\n  \
    \  }\n    bool f = false;\n    for(int i = 0; i < v; ++i) f |= g[i][i] < 0;\n\
    \    return f;\n}\n"
  code: "#include \"Template.hpp\"\n\nll INF = (1LL << 31) - 1;\n\nbool warshallfloyd(vvl\
    \ &g){\n    int v = g.size();\n    for(int i = 0; i < v; ++i) g[i][i] = 0;\n \
    \   for(int k = 0; k < v; ++k){\n        for(int i = 0; i < v; ++i){\n       \
    \     for(int j = 0; j < v; ++j){\n                if(g[i][k] == INF || g[k][j]\
    \ == INF) continue;\n                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);\n\
    \            }\n        }\n    }\n    bool f = false;\n    for(int i = 0; i <\
    \ v; ++i) f |= g[i][i] < 0;\n    return f;\n}"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2023-11-23 01:27:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-GRL-1-C.test.cpp
documentation_of: icpc/WarshallFloyd.hpp
layout: document
redirect_from:
- /library/icpc/WarshallFloyd.hpp
- /library/icpc/WarshallFloyd.hpp.html
title: icpc/WarshallFloyd.hpp
---
