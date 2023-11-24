---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-3-C.test.cpp
    title: verify_icpc/AOJ-GRL-3-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\nusing pi = pair<int, int>;\n\
    #line 2 \"icpc/StronglyConnectedComponents.hpp\"\n\nusing Edge = pair<int, ll>;\n\
    using Graph = vector<vector<Edge>>;\n\npair<vi, vvi> scc(Graph &G, Graph &rG){\n\
    \    vi vis(G.size(), 0), ord;\n    vi belong(G.size(), -1);\n    vvi sc;\n  \
    \  auto dfs = [&](auto self, int v) -> void {\n        vis[v] = 1;\n        for(auto\
    \ [to, cost] : G[v]){\n            if(!vis[to]) self(self, to);\n        }\n \
    \       ord.push_back(v);\n    };\n    auto rdfs = [&](auto self, int v, int k)\
    \ -> void {\n        vis[v] = 0;\n        belong[v] = k;\n        if(sc.size()\
    \ == k) sc.push_back(vi{});\n        sc[k].push_back(v);\n        for(auto [to,\
    \ cost] : rG[v]){\n            if(vis[to]) self(self, to, k);\n        }\n   \
    \ };\n    for(int i = 0; i < G.size(); ++i){\n        if(!vis[i]) dfs(dfs, i);\n\
    \    }\n    while(ord.size()){\n        int i = ord.back();\n        ord.pop_back();\n\
    \        if(vis[i]){\n            rdfs(rdfs, i, sc.size());\n        }\n    }\n\
    \    return {belong, sc};\n}\n"
  code: "#include \"Template.hpp\"\n\nusing Edge = pair<int, ll>;\nusing Graph = vector<vector<Edge>>;\n\
    \npair<vi, vvi> scc(Graph &G, Graph &rG){\n    vi vis(G.size(), 0), ord;\n   \
    \ vi belong(G.size(), -1);\n    vvi sc;\n    auto dfs = [&](auto self, int v)\
    \ -> void {\n        vis[v] = 1;\n        for(auto [to, cost] : G[v]){\n     \
    \       if(!vis[to]) self(self, to);\n        }\n        ord.push_back(v);\n \
    \   };\n    auto rdfs = [&](auto self, int v, int k) -> void {\n        vis[v]\
    \ = 0;\n        belong[v] = k;\n        if(sc.size() == k) sc.push_back(vi{});\n\
    \        sc[k].push_back(v);\n        for(auto [to, cost] : rG[v]){\n        \
    \    if(vis[to]) self(self, to, k);\n        }\n    };\n    for(int i = 0; i <\
    \ G.size(); ++i){\n        if(!vis[i]) dfs(dfs, i);\n    }\n    while(ord.size()){\n\
    \        int i = ord.back();\n        ord.pop_back();\n        if(vis[i]){\n \
    \           rdfs(rdfs, i, sc.size());\n        }\n    }\n    return {belong, sc};\n\
    }"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/StronglyConnectedComponents.hpp
  requiredBy: []
  timestamp: '2023-11-24 19:51:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-GRL-3-C.test.cpp
documentation_of: icpc/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/icpc/StronglyConnectedComponents.hpp
- /library/icpc/StronglyConnectedComponents.hpp.html
title: icpc/StronglyConnectedComponents.hpp
---
