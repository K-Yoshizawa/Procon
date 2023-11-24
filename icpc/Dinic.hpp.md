---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-6-A.test.cpp
    title: verify_icpc/AOJ-GRL-6-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\nusing pi = pair<int, int>;\n\
    #line 2 \"icpc/Dinic.hpp\"\n\nstruct Edge{\n    int to, rev;\n    ll cap;\n};\n\
    \nstruct flow{\n    vector<vector<Edge>> G;\n    vi dist, iter;\n\n    void bfs(int\
    \ s){\n        dist.assign(G.size(), -1);\n        dist[s] = 0;\n        queue<int>\
    \ que;\n        que.push(s);\n        while(que.size()){\n            int v =\
    \ que.front();\n            que.pop();\n            for(auto e : G[v]){\n    \
    \            if(e.cap and dist[e.to] < 0){\n                    dist[e.to] = dist[v]\
    \ + 1;\n                    que.push(e.to);\n                }\n            }\n\
    \        }\n    }\n\n    ll dfs(int v, int t, ll f){\n        if(v == t) return\
    \ f;\n        for(int &i = iter[v]; i < G[v].size(); ++i){\n            auto &e\
    \ = G[v][i];\n            if(e.cap and dist[v] < dist[e.to]){\n              \
    \  ll d = dfs(e.to, t, min(f, e.cap));\n                if(d){\n             \
    \       e.cap -= d;\n                    G[e.to][e.rev].cap += d;\n          \
    \          return d;\n                }\n            }\n        }\n        return\
    \ 0;\n    }\n\n    flow(int sz) : G(sz), dist(sz), iter(sz){}\n\n    void add(int\
    \ s, int t, ll c){\n        int cs = G[s].size(), ct = G[t].size();\n        G[s].push_back(Edge{t,\
    \ ct, c});\n        G[t].push_back(Edge{s, cs, 0});\n    }\n\n    ll solve(int\
    \ s, int t){\n        ll ret = 0;\n        ll INF = numeric_limits<ll>::max()\
    \ / 2;\n        while(1){\n            bfs(s);\n            if(dist[t] < 0) return\
    \ ret;\n            iter.assign(G.size(), 0);\n            ll f;\n           \
    \ while(f = dfs(s, t, INF)) ret += f;\n        }\n    }\n};\n"
  code: "#include \"Template.hpp\"\n\nstruct Edge{\n    int to, rev;\n    ll cap;\n\
    };\n\nstruct flow{\n    vector<vector<Edge>> G;\n    vi dist, iter;\n\n    void\
    \ bfs(int s){\n        dist.assign(G.size(), -1);\n        dist[s] = 0;\n    \
    \    queue<int> que;\n        que.push(s);\n        while(que.size()){\n     \
    \       int v = que.front();\n            que.pop();\n            for(auto e :\
    \ G[v]){\n                if(e.cap and dist[e.to] < 0){\n                    dist[e.to]\
    \ = dist[v] + 1;\n                    que.push(e.to);\n                }\n   \
    \         }\n        }\n    }\n\n    ll dfs(int v, int t, ll f){\n        if(v\
    \ == t) return f;\n        for(int &i = iter[v]; i < G[v].size(); ++i){\n    \
    \        auto &e = G[v][i];\n            if(e.cap and dist[v] < dist[e.to]){\n\
    \                ll d = dfs(e.to, t, min(f, e.cap));\n                if(d){\n\
    \                    e.cap -= d;\n                    G[e.to][e.rev].cap += d;\n\
    \                    return d;\n                }\n            }\n        }\n\
    \        return 0;\n    }\n\n    flow(int sz) : G(sz), dist(sz), iter(sz){}\n\n\
    \    void add(int s, int t, ll c){\n        int cs = G[s].size(), ct = G[t].size();\n\
    \        G[s].push_back(Edge{t, ct, c});\n        G[t].push_back(Edge{s, cs, 0});\n\
    \    }\n\n    ll solve(int s, int t){\n        ll ret = 0;\n        ll INF = numeric_limits<ll>::max()\
    \ / 2;\n        while(1){\n            bfs(s);\n            if(dist[t] < 0) return\
    \ ret;\n            iter.assign(G.size(), 0);\n            ll f;\n           \
    \ while(f = dfs(s, t, INF)) ret += f;\n        }\n    }\n};"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/Dinic.hpp
  requiredBy: []
  timestamp: '2023-11-24 19:51:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-GRL-6-A.test.cpp
documentation_of: icpc/Dinic.hpp
layout: document
redirect_from:
- /library/icpc/Dinic.hpp
- /library/icpc/Dinic.hpp.html
title: icpc/Dinic.hpp
---
