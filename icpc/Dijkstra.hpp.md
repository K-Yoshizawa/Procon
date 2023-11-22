---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-1-A.test.cpp
    title: verify_icpc/AOJ-GRL-1-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/Dijkstra.hpp\"\
    \n\nusing Edge = pair<int, ll>;\nusing GR = vector<vector<Edge>>;\n\nll INF =\
    \ (1LL << 31) - 1;\n\nvl dijkstra(GR &g, int s){\n    using p = pair<ll, int>;\n\
    \    vl ret(g.size(), INF);\n    ret[s] = 0;\n    priority_queue<p, vector<p>,\
    \ greater<p>> que;\n    que.push({0, s});\n    while(que.size()){\n        auto\
    \ [d, v] = que.top(); que.pop();\n        if(ret[v] < d) continue;\n        for(auto\
    \ [t, c] : g[v]){\n            if(d + c < ret[t]){\n                ret[t] = d\
    \ + c;\n                que.push({ret[t], t});\n            }\n        }\n   \
    \ }\n    return ret;\n}\n"
  code: "#include \"Template.hpp\"\n\nusing Edge = pair<int, ll>;\nusing GR = vector<vector<Edge>>;\n\
    \nll INF = (1LL << 31) - 1;\n\nvl dijkstra(GR &g, int s){\n    using p = pair<ll,\
    \ int>;\n    vl ret(g.size(), INF);\n    ret[s] = 0;\n    priority_queue<p, vector<p>,\
    \ greater<p>> que;\n    que.push({0, s});\n    while(que.size()){\n        auto\
    \ [d, v] = que.top(); que.pop();\n        if(ret[v] < d) continue;\n        for(auto\
    \ [t, c] : g[v]){\n            if(d + c < ret[t]){\n                ret[t] = d\
    \ + c;\n                que.push({ret[t], t});\n            }\n        }\n   \
    \ }\n    return ret;\n}"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/Dijkstra.hpp
  requiredBy: []
  timestamp: '2023-11-23 01:27:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-GRL-1-A.test.cpp
documentation_of: icpc/Dijkstra.hpp
layout: document
redirect_from:
- /library/icpc/Dijkstra.hpp
- /library/icpc/Dijkstra.hpp.html
title: icpc/Dijkstra.hpp
---
