---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-A.test.cpp
    title: verify/AOJ-GRL-5-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Tree Diamiter - \u6728\u306E\u76F4\u5F84"
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
  code: "#pragma once\n\n/**\n * @brief Tree Diamiter - \u6728\u306E\u76F4\u5F84\n\
    \ */\n\n#include \"../Graph/GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct TreeDiamiter{\n    private:\n    Graph<CostType> &G;\n    vector<CostType>\
    \ dist;\n\n    void bfs(Vertex s){\n        queue<Vertex> que;\n        dist.assign(G.size(),\
    \ G.INF);\n        dist[s] = 0;\n        que.push(s);\n        while(!que.empty()){\n\
    \            Vertex v = que.front();\n            que.pop();\n            for(EdgeNum\
    \ &i : G.connect[v]){\n                Vertex u = G.edges[i].to;\n           \
    \     CostType w = G.edges[i].cost;\n                if(dist[v] + w < dist[u]){\n\
    \                    dist[u] = dist[v] + w;\n                    que.push(u);\n\
    \                }\n            }\n        }\n    }\n\n    public:\n    pair<Vertex,\
    \ Vertex> EdgeVertex;\n    CostType diamiter;\n\n    TreeDiamiter(Graph<CostType>\
    \ &G) : G(G), dist(G.size()){\n        bfs(0);\n        int v = 0;\n        CostType\
    \ d = 0;\n        for(int i = 0; i < G.size(); ++i){\n            if(dist[i] >\
    \ d){\n                v = i, d = dist[i];\n            }\n        }\n       \
    \ EdgeVertex.first = v;\n        bfs(v);\n        v = 0, d = 0;\n        for(int\
    \ i = 0; i < G.size(); ++i){\n            if(dist[i] > d){\n                v\
    \ = i, d = dist[i];\n            }\n        }\n        EdgeVertex.second = v;\n\
    \        diamiter = d;\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Tree/TreeDiamiter.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-5-A.test.cpp
documentation_of: library/Tree/TreeDiamiter.hpp
layout: document
redirect_from:
- /library/library/Tree/TreeDiamiter.hpp
- /library/library/Tree/TreeDiamiter.hpp.html
title: "Tree Diamiter - \u6728\u306E\u76F4\u5F84"
---
