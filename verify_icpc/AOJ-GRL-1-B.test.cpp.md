---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/BellmanFord.hpp
    title: icpc/BellmanFord.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"verify_icpc/AOJ-GRL-1-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/BellmanFord.hpp\"\
    \n\nusing Edge = tuple<int, int, ll>;\nusing ES = vector<Edge>;\n\nll INF = (1LL\
    \ << 31) - 1;\n\nvl bellmanford(ES &e, int st, int v){\n    using p = pair<ll,\
    \ int>;\n    vl ret(v, INF);\n    ret[st] = 0;\n    int cnt = 0;\n    while(1){\n\
    \        if(cnt == v) return vl{};\n        bool f = false;\n        for(auto\
    \ [s, t, d] : e){\n            if(ret[s] == INF) continue;\n            if(ret[s]\
    \ + d < ret[t]){\n                ret[t] = ret[s] + d;\n                f = true;\n\
    \            }\n        }\n        if(!f) break;\n        ++cnt;\n    }\n    return\
    \ ret;\n}\n#line 4 \"verify_icpc/AOJ-GRL-1-B.test.cpp\"\n\nint main(){\n    int\
    \ V, E, r; cin >> V >> E >> r;\n    ES ed;\n    for(int i = 0; i < E; ++i){\n\
    \        int s, t, d; cin >> s >> t >> d;\n        ed.push_back({s, t, d});\n\
    \    }\n\n    auto dist = bellmanford(ed, r, V);\n    if(dist.empty()) cout <<\
    \ \"NEGATIVE CYCLE\" << endl;\n    else{\n        for(auto d : dist){\n      \
    \      (d == INF ? cout << \"INF\" << endl : cout << d << endl);\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include \"../icpc/BellmanFord.hpp\"\n\nint main(){\n    int V, E, r; cin\
    \ >> V >> E >> r;\n    ES ed;\n    for(int i = 0; i < E; ++i){\n        int s,\
    \ t, d; cin >> s >> t >> d;\n        ed.push_back({s, t, d});\n    }\n\n    auto\
    \ dist = bellmanford(ed, r, V);\n    if(dist.empty()) cout << \"NEGATIVE CYCLE\"\
    \ << endl;\n    else{\n        for(auto d : dist){\n            (d == INF ? cout\
    \ << \"INF\" << endl : cout << d << endl);\n        }\n    }\n}"
  dependsOn:
  - icpc/BellmanFord.hpp
  - icpc/Template.hpp
  isVerificationFile: true
  path: verify_icpc/AOJ-GRL-1-B.test.cpp
  requiredBy: []
  timestamp: '2023-11-23 01:27:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_icpc/AOJ-GRL-1-B.test.cpp
layout: document
redirect_from:
- /verify/verify_icpc/AOJ-GRL-1-B.test.cpp
- /verify/verify_icpc/AOJ-GRL-1-B.test.cpp.html
title: verify_icpc/AOJ-GRL-1-B.test.cpp
---
