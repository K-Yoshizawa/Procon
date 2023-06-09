---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Warshall-Floyd - \u5168\u70B9\u9593\u6700\u77ED\u8DDD\u96E2"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../library/Graph/GraphTemplate.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n/**\n * @brief Warshall-Floyd - \u5168\u70B9\u9593\u6700\u77ED\
    \u8DDD\u96E2\n */\n\n#include <bits/stdc++.h>\n\n#include \"../library/Graph/GraphTemplate.hpp\"\
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
  dependsOn: []
  isVerificationFile: false
  path: library/Graph/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Graph/WarshallFloyd.hpp
layout: document
redirect_from:
- /library/library/Graph/WarshallFloyd.hpp
- /library/library/Graph/WarshallFloyd.hpp.html
title: "Warshall-Floyd - \u5168\u70B9\u9593\u6700\u77ED\u8DDD\u96E2"
---
