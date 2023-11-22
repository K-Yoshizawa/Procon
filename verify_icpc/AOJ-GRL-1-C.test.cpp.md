---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/WarshallFloyd.hpp
    title: icpc/WarshallFloyd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"verify_icpc/AOJ-GRL-1-C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/WarshallFloyd.hpp\"\
    \n\nll INF = (1LL << 31) - 1;\n\nbool warshallfloyd(vvl &g){\n    int v = g.size();\n\
    \    for(int i = 0; i < v; ++i) g[i][i] = 0;\n    for(int k = 0; k < v; ++k){\n\
    \        for(int i = 0; i < v; ++i){\n            for(int j = 0; j < v; ++j){\n\
    \                if(g[i][k] == INF || g[k][j] == INF) continue;\n            \
    \    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);\n            }\n        }\n  \
    \  }\n    bool f = false;\n    for(int i = 0; i < v; ++i) f |= g[i][i] < 0;\n\
    \    return f;\n}\n#line 4 \"verify_icpc/AOJ-GRL-1-C.test.cpp\"\n\nint main(){\n\
    \    int V, E; cin >> V >> E;\n    vvl g(V, vl(V, INF));\n    for(int i = 0; i\
    \ < E; ++i){\n        int s, t, d; cin >> s >> t >> d;\n        g[s][t] = d;\n\
    \    }\n\n    if(warshallfloyd(g)){\n        cout << \"NEGATIVE CYCLE\" << endl;\n\
    \    }\n    else{\n        for(auto i : g){\n            (i[0] == INF ? cout <<\
    \ \"INF\" : cout << i[0]);\n            for(int j = 1; j < V; ++j){\n        \
    \        cout << \" \";\n                (i[j] == INF ? cout << \"INF\" : cout\
    \ << i[j]);\n            }\n            cout << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include \"../icpc/WarshallFloyd.hpp\"\n\nint main(){\n    int V, E; cin >>\
    \ V >> E;\n    vvl g(V, vl(V, INF));\n    for(int i = 0; i < E; ++i){\n      \
    \  int s, t, d; cin >> s >> t >> d;\n        g[s][t] = d;\n    }\n\n    if(warshallfloyd(g)){\n\
    \        cout << \"NEGATIVE CYCLE\" << endl;\n    }\n    else{\n        for(auto\
    \ i : g){\n            (i[0] == INF ? cout << \"INF\" : cout << i[0]);\n     \
    \       for(int j = 1; j < V; ++j){\n                cout << \" \";\n        \
    \        (i[j] == INF ? cout << \"INF\" : cout << i[j]);\n            }\n    \
    \        cout << endl;\n        }\n    }\n}"
  dependsOn:
  - icpc/WarshallFloyd.hpp
  - icpc/Template.hpp
  isVerificationFile: true
  path: verify_icpc/AOJ-GRL-1-C.test.cpp
  requiredBy: []
  timestamp: '2023-11-23 01:27:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_icpc/AOJ-GRL-1-C.test.cpp
layout: document
redirect_from:
- /verify/verify_icpc/AOJ-GRL-1-C.test.cpp
- /verify/verify_icpc/AOJ-GRL-1-C.test.cpp.html
title: verify_icpc/AOJ-GRL-1-C.test.cpp
---
