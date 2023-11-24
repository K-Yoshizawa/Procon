---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/StronglyConnectedComponents.hpp
    title: icpc/StronglyConnectedComponents.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
  bundledCode: "#line 1 \"verify_icpc/AOJ-GRL-3-C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
    \n\n#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
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
    \    return {belong, sc};\n}\n#line 4 \"verify_icpc/AOJ-GRL-3-C.test.cpp\"\n\n\
    int main(){\n    int V, E; cin >> V >> E;\n    Graph G(V), rG(V);\n    for(int\
    \ i = 0; i < E; ++i){\n        int s, t; cin >> s >> t;\n        G[s].push_back({t,\
    \ 1});\n        rG[t].push_back({s, 1});\n    }\n\n    auto belong = scc(G, rG).first;\n\
    \    int Q; cin >> Q;\n    for(int i = 0; i < Q; ++i){\n        int u, v; cin\
    \ >> u >> v;\n        cout << (belong[u] == belong[v]) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
    \n\n#include \"../icpc/StronglyConnectedComponents.hpp\"\n\nint main(){\n    int\
    \ V, E; cin >> V >> E;\n    Graph G(V), rG(V);\n    for(int i = 0; i < E; ++i){\n\
    \        int s, t; cin >> s >> t;\n        G[s].push_back({t, 1});\n        rG[t].push_back({s,\
    \ 1});\n    }\n\n    auto belong = scc(G, rG).first;\n    int Q; cin >> Q;\n \
    \   for(int i = 0; i < Q; ++i){\n        int u, v; cin >> u >> v;\n        cout\
    \ << (belong[u] == belong[v]) << endl;\n    }\n}"
  dependsOn:
  - icpc/StronglyConnectedComponents.hpp
  - icpc/Template.hpp
  isVerificationFile: true
  path: verify_icpc/AOJ-GRL-3-C.test.cpp
  requiredBy: []
  timestamp: '2023-11-24 19:51:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_icpc/AOJ-GRL-3-C.test.cpp
layout: document
redirect_from:
- /verify/verify_icpc/AOJ-GRL-3-C.test.cpp
- /verify/verify_icpc/AOJ-GRL-3-C.test.cpp.html
title: verify_icpc/AOJ-GRL-3-C.test.cpp
---
