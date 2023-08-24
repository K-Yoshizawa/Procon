---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/Graph/BipartiteMatching.hpp
    title: "Bipartite Matching - \u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-6-A.test.cpp
    title: verify/AOJ-GRL-6-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-7-A.test.cpp
    title: verify/AOJ-GRL-7-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Ford-Fulkerson - \u6700\u5927\u30D5\u30ED\u30FC"
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
  code: "#pragma once\n\n/**\n * @brief Ford-Fulkerson - \u6700\u5927\u30D5\u30ED\u30FC\
    \n */\n\n#include <bits/stdc++.h>\n\n#include \"GraphTemplate.hpp\"\n\nusing namespace\
    \ std;\n\ntemplate<typename CostType>\nstruct FordFulkerson{\n    int E;\n   \
    \ Graph<CostType> &G;\n    vector<EdgeNum> rev;\n\n    private:\n    vector<int>\
    \ used;\n\n    CostType dfs(Vertex pos, Vertex goal, CostType F){\n        if(pos\
    \ == goal) return F;\n        used[pos] = 1;\n        for(EdgeNum &i : G.connect[pos]){\n\
    \            if(G.edges[i].cost == 0) continue;\n            if(used[G.edges[i].to])\
    \ continue;\n            CostType flow = dfs(G.edges[i].to, goal, min(F, G.edges[i].cost));\n\
    \            if(flow >= 1){\n                G.edges[i].cost -= flow;\n      \
    \          G.edges[rev[i]].cost += flow;\n                return flow;\n     \
    \       }\n        }\n        return 0;\n    }\n\n    public:\n    FordFulkerson(Graph<CostType>\
    \ &G) : G(G), used(G.size(), 0){\n        E = G.edges.size();\n        rev.resize(2\
    \ * E);\n        for(int i = 0; i < E; ++i){\n            rev[i] = i + E;\n  \
    \          rev[i + E] = i;\n            Edge<CostType> e = G.get_edge(i);\n  \
    \          G.add(e.to, e.from, 0);\n        }\n    }\n\n    /**\n     * @brief\
    \  \u9802\u70B9s\u304B\u3089\u9802\u70B9t\u3078\u306E\u6700\u5927\u6D41\u3092\u6C42\
    \u3081\u308B\u3002\n     * @param  s: \u59CB\u70B9\u306E\u9802\u70B9s\n     *\
    \ @param  t: \u7D42\u70B9\u306E\u9802\u70B9t\n     * @retval \u6700\u5927\u6D41\
    \n     */\n    CostType query(Vertex s, Vertex t){\n        CostType ret = 0;\n\
    \        while(1){\n            used.assign(G.size(), 0);\n            CostType\
    \ F = dfs(s, t, G.INF);\n            if(F == 0) break;\n            ret += F;\n\
    \        }\n        return ret;\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/FordFulkerson.hpp
  requiredBy:
  - library/Graph/BipartiteMatching.hpp
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-6-A.test.cpp
  - verify/AOJ-GRL-7-A.test.cpp
documentation_of: library/Graph/FordFulkerson.hpp
layout: document
redirect_from:
- /library/library/Graph/FordFulkerson.hpp
- /library/library/Graph/FordFulkerson.hpp.html
title: "Ford-Fulkerson - \u6700\u5927\u30D5\u30ED\u30FC"
---
