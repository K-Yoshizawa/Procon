---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-C.test.cpp
    title: verify/AOJ-GRL-3-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\
      \u5206\u89E3"
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
  code: "#pragma once\n\n/**\n * @brief Strongly Connected Components - \u5F37\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\n */\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#include \"GraphTemplate.hpp\"\n\n/**\n * @brief  \u5F37\u9023\u7D50\
    \u6210\u5206\u5206\u89E3\u3092\u884C\u3046\u3002\n */\ntemplate<typename CostType>\n\
    struct StronglyConnectedComponents{\n    vector<int> belong; // \u9802\u70B9\u304C\
    \u3069\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u304B\
    \n    vector<vector<Vertex>> sc; // \u5404\u5F37\u9023\u7D50\u6210\u5206\u306B\
    \u6240\u5C5E\u3059\u308B\u9802\u70B9\n\n    private:\n    Graph<CostType> &G,\
    \ rG;\n    vector<int> order, visited;\n    vector<int> tmp;\n\n    void dfs(int\
    \ v){\n        visited[v] = 1;\n        for(auto &e : G.get_edges(v)){\n     \
    \       if(visited[e.to] == 0) dfs(e.to);\n        }\n        order.push_back(v);\n\
    \    }\n\n    void rdfs(int v, int k){\n        visited[v] = 0;\n        belong[v]\
    \ = k;\n        tmp.push_back(v);\n        for(auto &e : rG.get_edges(v)){\n \
    \           if(visited[e.to] == 1) rdfs(e.to, k);\n        }\n    }\n\n    public:\n\
    \    StronglyConnectedComponents(Graph<CostType> &G) : G(G){\n        rG = G.reverse();\n\
    \        visited.resize(G.size(), 0);\n        belong.resize(G.size(), -1);\n\
    \        for(int i = 0; i < G.size(); ++i){\n            if(visited[i] == 0) dfs(i);\n\
    \        }\n        int k = 0;\n        for(int i = order.size() - 1; i >= 0;\
    \ --i){\n            if(visited[order[i]] == 1){\n                rdfs(order[i],\
    \ k++);\n                sc.push_back(tmp);\n                tmp.clear();\n  \
    \          }\n        }\n    }\n\n    /**\n     * @brief  2\u3064\u306E\u9802\u70B9\
    \u304C\u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\
    \u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     * @param  u: \u5224\u5B9A\u3057\
    \u305F\u3044\u9802\u70B9u\n     * @param  v: \u5224\u5B9A\u3057\u305F\u3044\u9802\
    \u70B9v\n     * @retval \u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\
    \u5C5E\u3059\u308B\u306A\u3089true\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070\
    false\n     */\n    bool same(Vertex u, Vertex v){\n        return belong[u] ==\
    \ belong[v];\n    }\n\n    /**\n     * @brief \u9802\u70B9v\u304C\u5C5E\u3059\u308B\
    \u5F37\u9023\u7D50\u6210\u5206\u3092\u8FD4\u3059\u3002\n     * @param v \u8ABF\
    \u3079\u305F\u3044\u9802\u70B9v\n     * @return vector<Vertex> \u9802\u70B9v\u304C\
    \u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\n     */\n    vector<Vertex>\
    \ get(Vertex v){\n        return sc[belong[v]];\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/StronglyConnectedComponents.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-3-C.test.cpp
documentation_of: library/Graph/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/library/Graph/StronglyConnectedComponents.hpp
- /library/library/Graph/StronglyConnectedComponents.hpp.html
title: "Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
