---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Dijkstra.hpp
    title: icpc/Dijkstra.hpp
  - icon: ':question:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"verify_icpc/AOJ-GRL-1-A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/Dijkstra.hpp\"\
    \n\nusing Edge = pair<int, ll>;\nusing GR = vector<vector<Edge>>;\n\nll INF =\
    \ (1LL << 31) - 1;\n\nvl dijkstra(GR &g, int s){\n    using p = pair<ll, int>;\n\
    \    vl ret(g.size(), INF);\n    ret[s] = 0;\n    priority_queue<p, vector<p>,\
    \ greater<p>> que;\n    que.push({0, s});\n    while(que.size()){\n        auto\
    \ [d, v] = que.top(); que.pop();\n        if(ret[v] < d) continue;\n        for(auto\
    \ [t, c] : g[v]){\n            if(d + c < ret[t]){\n                ret[t] = d\
    \ + c;\n                que.push({ret[t], t});\n            }\n        }\n   \
    \ }\n    return ret;\n}\n#line 4 \"verify_icpc/AOJ-GRL-1-A.test.cpp\"\n\nint main(){\n\
    \    int V, E, r; cin >> V >> E >> r;\n    GR g(V);\n    for(int i = 0; i < E;\
    \ ++i){\n        int s, t, d; cin >> s >> t >> d;\n        g[s].push_back({t,\
    \ d});\n    }\n\n    auto dist = dijkstra(g, r);\n    for(auto d : dist){\n  \
    \      (d == INF ? cout << \"INF\" << endl : cout << d << endl);\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../icpc/Dijkstra.hpp\"\n\nint main(){\n    int V, E, r; cin >>\
    \ V >> E >> r;\n    GR g(V);\n    for(int i = 0; i < E; ++i){\n        int s,\
    \ t, d; cin >> s >> t >> d;\n        g[s].push_back({t, d});\n    }\n\n    auto\
    \ dist = dijkstra(g, r);\n    for(auto d : dist){\n        (d == INF ? cout <<\
    \ \"INF\" << endl : cout << d << endl);\n    }\n}"
  dependsOn:
  - icpc/Dijkstra.hpp
  - icpc/Template.hpp
  isVerificationFile: true
  path: verify_icpc/AOJ-GRL-1-A.test.cpp
  requiredBy: []
  timestamp: '2023-11-23 01:27:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_icpc/AOJ-GRL-1-A.test.cpp
layout: document
redirect_from:
- /verify/verify_icpc/AOJ-GRL-1-A.test.cpp
- /verify/verify_icpc/AOJ-GRL-1-A.test.cpp.html
title: verify_icpc/AOJ-GRL-1-A.test.cpp
---
