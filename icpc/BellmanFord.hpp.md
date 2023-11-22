---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-1-B.test.cpp
    title: verify_icpc/AOJ-GRL-1-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/BellmanFord.hpp\"\
    \n\nusing Edge = tuple<int, int, ll>;\nusing ES = vector<Edge>;\n\nll INF = (1LL\
    \ << 31) - 1;\n\nvl bellmanford(ES &e, int st, int v){\n    using p = pair<ll,\
    \ int>;\n    vl ret(v, INF);\n    ret[st] = 0;\n    int cnt = 0;\n    while(1){\n\
    \        if(cnt == v) return vl{};\n        bool f = false;\n        for(auto\
    \ [s, t, d] : e){\n            if(ret[s] == INF) continue;\n            if(ret[s]\
    \ + d < ret[t]){\n                ret[t] = ret[s] + d;\n                f = true;\n\
    \            }\n        }\n        if(!f) break;\n        ++cnt;\n    }\n    return\
    \ ret;\n}\n"
  code: "#include \"Template.hpp\"\n\nusing Edge = tuple<int, int, ll>;\nusing ES\
    \ = vector<Edge>;\n\nll INF = (1LL << 31) - 1;\n\nvl bellmanford(ES &e, int st,\
    \ int v){\n    using p = pair<ll, int>;\n    vl ret(v, INF);\n    ret[st] = 0;\n\
    \    int cnt = 0;\n    while(1){\n        if(cnt == v) return vl{};\n        bool\
    \ f = false;\n        for(auto [s, t, d] : e){\n            if(ret[s] == INF)\
    \ continue;\n            if(ret[s] + d < ret[t]){\n                ret[t] = ret[s]\
    \ + d;\n                f = true;\n            }\n        }\n        if(!f) break;\n\
    \        ++cnt;\n    }\n    return ret;\n}"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/BellmanFord.hpp
  requiredBy: []
  timestamp: '2023-11-23 01:27:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-GRL-1-B.test.cpp
documentation_of: icpc/BellmanFord.hpp
layout: document
redirect_from:
- /library/icpc/BellmanFord.hpp
- /library/icpc/BellmanFord.hpp.html
title: icpc/BellmanFord.hpp
---
