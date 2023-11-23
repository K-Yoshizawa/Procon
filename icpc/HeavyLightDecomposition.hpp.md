---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/HeavyLightDecomposition.hpp\"\
    \n\nusing Edge = pair<int, ll>;\nusing Graph = vector<vector<Edge>>;\n\nstruct\
    \ hld{\n    Graph &G;\n    vi subtree, depth;\n    \n    int dfs1(int v, int p){\n\
    \        int ret = 0;\n        for(auto [to, cost] : G[v]){\n            if(to\
    \ == p) continue;\n            \n        }\n    }\n};\n"
  code: "#include \"Template.hpp\"\n\nusing Edge = pair<int, ll>;\nusing Graph = vector<vector<Edge>>;\n\
    \nstruct hld{\n    Graph &G;\n    vi subtree, depth;\n    \n    int dfs1(int v,\
    \ int p){\n        int ret = 0;\n        for(auto [to, cost] : G[v]){\n      \
    \      if(to == p) continue;\n            \n        }\n    }\n};"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2023-11-24 03:01:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/icpc/HeavyLightDecomposition.hpp
- /library/icpc/HeavyLightDecomposition.hpp.html
title: icpc/HeavyLightDecomposition.hpp
---
