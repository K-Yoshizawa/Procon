---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-A.test.cpp
    title: verify/AOJ-GRL-1-A.test.cpp
  - icon: ':x:'
    path: verify/yuki-1995.test.cpp
    title: verify/yuki-1995.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2\uFF08\
      \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\uFF09"
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
  code: "#pragma once\n\n/**\n * @brief Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\
    \u8DDD\u96E2\uFF08\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\uFF09\n */\n\n#include\
    \ <bits/stdc++.h>\n#include \"GraphTemplate.hpp\"\nusing namespace std;\n\n/**\n\
    \ * @brief  \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u3067\u6700\u77ED\u8DDD\
    \u96E2\u3092\u6C42\u3081\u308B\u3002\n * @attention \u30B0\u30E9\u30D5\u306B\u8CA0\
    \u306E\u91CD\u307F\u306E\u8FBA\u304C\u306A\u3044\u5FC5\u8981\u304C\u3042\u308B\
    \u3002\n */\ntemplate<typename CostType>\nstruct Dijkstra{\n    private:\n   \
    \ Graph<CostType> &G;\n    vector<Vertex> prev_vertex;\n    vector<EdgeNum> prev_edge;\n\
    \n    public:\n    vector<CostType> dist;\n\n    Dijkstra(Graph<CostType> &G)\
    \ : G(G), dist(G.size()), prev_vertex(G.size()), prev_edge(G.size()){}\n\n   \
    \ /**\n     * @brief  \u9802\u70B9s\u3092\u59CB\u70B9\u3068\u3057\u3066\u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\u6CD5\u3092\u9069\u7528\u3059\u308B\u3002\n     * @param\
    \  s: \u59CB\u70B9\u3068\u306A\u308B\u9802\u70B9s\n     * @note   \u6C42\u3081\
    \u3089\u308C\u305F\u6700\u77ED\u8DDD\u96E2\u306Fdist\u306B\u683C\u7D0D\u3055\u308C\
    \u308B\u3002\n     */\n    void build(int s){\n        dist.assign(G.size(), G.INF);\n\
    \        prev_vertex.assign(G.size(), -1);\n        prev_edge.assign(G.size(),\
    \ -1);\n        using p = pair<CostType, Vertex>;\n        priority_queue<p, vector<p>,\
    \ greater<p>> que;\n        que.emplace(0, s);\n        dist[s] = 0;\n       \
    \ while(!que.empty()){\n            auto [d, v] = que.top();\n            que.pop();\n\
    \            if(dist[v] < d) continue;\n            for(auto &eidx : G.get_list(v)){\n\
    \                auto e = G.get_edge(eidx);\n                if(d + e.cost < dist[e.to]){\n\
    \                    dist[e.to] = d + e.cost;\n                    prev_vertex[e.to]\
    \ = v;\n                    prev_edge[e.to] = eidx;\n                    que.emplace(d\
    \ + e.cost, e.to);\n                }\n            }\n        }\n    }\n\n   \
    \ /**\n     * @brief  \u9802\u70B9s\u304B\u3089\u9802\u70B9t\u3078\u306E\u6700\
    \u77ED\u7D4C\u8DEF\u3092\u53D6\u5F97\u3059\u308B\n     * @attention \u4E88\u3081\
    build\u3067\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u5FC5\u8981\u304C\u3042\
    \u308B\u3002\n     * @param  t: \u7D42\u70B9\u3068\u306A\u308B\u9802\u70B9t\n\
    \     * @param  isEdge: \u9802\u70B9\u756A\u53F7\u306E\u4EE3\u308F\u308A\u306B\
    \u8FBA\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B(opt default = false)\n     *\
    \ @retval \u6700\u77ED\u7D4C\u8DEF\u306E\u9802\u70B9\u756A\u53F7 or \u8FBA\u756A\
    \u53F7\n     */\n    vector<int> restore(int t, bool isEdge = false){\n      \
    \  vector<int> ret;\n        int v = t;\n        while(v != -1){\n           \
    \ if(!isEdge) ret.push_back(v);\n            else if(prev_edge[v] != -1) ret.push_back(prev_edge[v]);\n\
    \            v = prev_vertex[v];\n        }\n        reverse(ret.begin(), ret.end());\n\
    \        return ret;\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yuki-1995.test.cpp
  - verify/AOJ-GRL-1-A.test.cpp
documentation_of: library/Graph/Dijkstra.hpp
layout: document
redirect_from:
- /library/library/Graph/Dijkstra.hpp
- /library/library/Graph/Dijkstra.hpp.html
title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2\uFF08\u30C0\u30A4\
  \u30AF\u30B9\u30C8\u30E9\u6CD5\uFF09"
---
