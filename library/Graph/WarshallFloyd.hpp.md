---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/AOJ-GRL-1-C.test.cpp
    title: verify/AOJ-GRL-1-C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Warshall-Floyd - \u5168\u70B9\u9593\u6700\u77ED\u8DDD\u96E2"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/Graph/GraphTemplate.hpp: line 9: #pragma once found in a non-first line\n"
  code: "#pragma once\n\n/**\n * @brief Warshall-Floyd - \u5168\u70B9\u9593\u6700\u77ED\
    \u8DDD\u96E2\n */\n\n#include <bits/stdc++.h>\n\n#include \"GraphTemplate.hpp\"\
    \n\nusing namespace std;\n\ntemplate<typename CostType>\nstruct WarshallFloyd{\n\
    \    bool negative;\n    vector<vector<CostType>> dist;\n\n    WarshallFloyd(Graph<CostType>\
    \ &G){\n        int V = G.size();\n        \n        dist.resize(V, vector<CostType>(V,\
    \ G.INF));\n        for(int i = 0; i < V; ++i) dist[i][i] = 0;\n        for(auto\
    \ &e : G.edges){\n            dist[e.from][e.to] = e.cost;\n        }\n\n    \
    \    for(int k = 0; k < V; ++k){\n            for(int i = 0; i < V; ++i){\n  \
    \              for(int j = 0; j < V; ++j){\n                    if(dist[i][k]\
    \ == G.INF || dist[k][j] == G.INF) continue;\n                    dist[i][j] =\
    \ min(dist[i][j], dist[i][k] + dist[k][j]);\n                }\n            }\n\
    \        }\n\n        negative = false;\n        for(int i = 0; i < V; ++i) negative\
    \ |= dist[i][i] < 0;\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/AOJ-GRL-1-C.test.cpp
documentation_of: library/Graph/WarshallFloyd.hpp
layout: document
redirect_from:
- /library/library/Graph/WarshallFloyd.hpp
- /library/library/Graph/WarshallFloyd.hpp.html
title: "Warshall-Floyd - \u5168\u70B9\u9593\u6700\u77ED\u8DDD\u96E2"
---
