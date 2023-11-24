---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-6-B.test.cpp
    title: verify_icpc/AOJ-GRL-6-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\nusing pi = pair<int, int>;\n\
    #line 2 \"icpc/PrimalDual.hpp\"\n\nstruct Edge{\n    int to, rev;\n    ll cap,\
    \ cost;\n};\n\nstruct mincostflow{\n    vector<vector<Edge>> G;\n    vl pt, mc;\n\
    \    vi pv, pe;\n\n    mincostflow(int sz) : G(sz){}\n\n    void add(int s, int\
    \ t, ll cap, ll cost){\n        int cs = G[s].size(), ct = G[t].size();\n    \
    \    G[s].push_back(Edge{t, ct, cap, cost});\n        G[t].push_back(Edge{s, cs,\
    \ 0, -cost});\n    }\n\n    ll solve(int s, int t, ll f){\n        int V = G.size();\n\
    \        ll INF = numeric_limits<ll>::max() / 2;\n        ll ret = 0;\n      \
    \  using p = pair<ll, int>;\n        priority_queue<p, vector<p>, greater<p>>\
    \ que;\n        pt.assign(V, 0);\n        pv.assign(V, -1);\n        pe.assign(V,\
    \ -1);\n        while(f){\n            mc.assign(V, INF);\n            que.emplace(0,\
    \ s);\n            mc[s] = 0;\n            while(que.size()){\n              \
    \  auto [d, v] = que.top();\n                que.pop();\n                if(mc[v]\
    \ < d) continue;\n                for(int i = 0; i < G[v].size(); ++i){\n    \
    \                auto &e = G[v][i];\n                    ll nc = mc[v] + e.cost\
    \ + pt[v] - pt[e.to];\n                    if(e.cap and mc[e.to] > nc){\n    \
    \                    mc[e.to] = nc;\n                        pv[e.to] = v, pe[e.to]\
    \ = i;\n                        que.emplace(mc[e.to], e.to);\n               \
    \     }\n                }\n            }\n            if(mc[t] == INF) return\
    \ -1;\n            for(int i = 0; i < V; ++i) pt[i] += mc[i];\n            ll\
    \ af = f;\n            for(int i = t; i != s; i = pv[i]){\n                af\
    \ = min(af, G[pv[i]][pe[i]].cap);\n            }\n            f -= af;\n     \
    \       ret += af * pt[t];\n            for(int i = t; i != s; i = pv[i]){\n \
    \               auto &e = G[pv[i]][pe[i]];\n                e.cap -= af;\n   \
    \             G[i][e.rev].cap += af;\n            }\n        }\n        return\
    \ ret;\n    }\n};\n"
  code: "#include \"Template.hpp\"\n\nstruct Edge{\n    int to, rev;\n    ll cap,\
    \ cost;\n};\n\nstruct mincostflow{\n    vector<vector<Edge>> G;\n    vl pt, mc;\n\
    \    vi pv, pe;\n\n    mincostflow(int sz) : G(sz){}\n\n    void add(int s, int\
    \ t, ll cap, ll cost){\n        int cs = G[s].size(), ct = G[t].size();\n    \
    \    G[s].push_back(Edge{t, ct, cap, cost});\n        G[t].push_back(Edge{s, cs,\
    \ 0, -cost});\n    }\n\n    ll solve(int s, int t, ll f){\n        int V = G.size();\n\
    \        ll INF = numeric_limits<ll>::max() / 2;\n        ll ret = 0;\n      \
    \  using p = pair<ll, int>;\n        priority_queue<p, vector<p>, greater<p>>\
    \ que;\n        pt.assign(V, 0);\n        pv.assign(V, -1);\n        pe.assign(V,\
    \ -1);\n        while(f){\n            mc.assign(V, INF);\n            que.emplace(0,\
    \ s);\n            mc[s] = 0;\n            while(que.size()){\n              \
    \  auto [d, v] = que.top();\n                que.pop();\n                if(mc[v]\
    \ < d) continue;\n                for(int i = 0; i < G[v].size(); ++i){\n    \
    \                auto &e = G[v][i];\n                    ll nc = mc[v] + e.cost\
    \ + pt[v] - pt[e.to];\n                    if(e.cap and mc[e.to] > nc){\n    \
    \                    mc[e.to] = nc;\n                        pv[e.to] = v, pe[e.to]\
    \ = i;\n                        que.emplace(mc[e.to], e.to);\n               \
    \     }\n                }\n            }\n            if(mc[t] == INF) return\
    \ -1;\n            for(int i = 0; i < V; ++i) pt[i] += mc[i];\n            ll\
    \ af = f;\n            for(int i = t; i != s; i = pv[i]){\n                af\
    \ = min(af, G[pv[i]][pe[i]].cap);\n            }\n            f -= af;\n     \
    \       ret += af * pt[t];\n            for(int i = t; i != s; i = pv[i]){\n \
    \               auto &e = G[pv[i]][pe[i]];\n                e.cap -= af;\n   \
    \             G[i][e.rev].cap += af;\n            }\n        }\n        return\
    \ ret;\n    }\n};"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/PrimalDual.hpp
  requiredBy: []
  timestamp: '2023-11-24 19:51:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-GRL-6-B.test.cpp
documentation_of: icpc/PrimalDual.hpp
layout: document
redirect_from:
- /library/icpc/PrimalDual.hpp
- /library/icpc/PrimalDual.hpp.html
title: icpc/PrimalDual.hpp
---
