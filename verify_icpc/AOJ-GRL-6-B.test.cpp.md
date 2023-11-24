---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/PrimalDual.hpp
    title: icpc/PrimalDual.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"verify_icpc/AOJ-GRL-6-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \n\n#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
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
    \ ret;\n    }\n};\n#line 4 \"verify_icpc/AOJ-GRL-6-B.test.cpp\"\n\nint main(){\n\
    \    int V, E, F; cin >> V >> E >> F;\n    mincostflow G(V);\n    for(int i =\
    \ 0; i < E; ++i){\n        int u, v, c, d; cin >> u >> v >> c >> d;\n        G.add(u,\
    \ v, c, d);\n    }\n    cout << G.solve(0, V - 1, F) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \n\n#include \"../icpc/PrimalDual.hpp\"\n\nint main(){\n    int V, E, F; cin >>\
    \ V >> E >> F;\n    mincostflow G(V);\n    for(int i = 0; i < E; ++i){\n     \
    \   int u, v, c, d; cin >> u >> v >> c >> d;\n        G.add(u, v, c, d);\n   \
    \ }\n    cout << G.solve(0, V - 1, F) << endl;\n}"
  dependsOn:
  - icpc/PrimalDual.hpp
  - icpc/Template.hpp
  isVerificationFile: true
  path: verify_icpc/AOJ-GRL-6-B.test.cpp
  requiredBy: []
  timestamp: '2023-11-24 19:51:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_icpc/AOJ-GRL-6-B.test.cpp
layout: document
redirect_from:
- /verify/verify_icpc/AOJ-GRL-6-B.test.cpp
- /verify/verify_icpc/AOJ-GRL-6-B.test.cpp.html
title: verify_icpc/AOJ-GRL-6-B.test.cpp
---
