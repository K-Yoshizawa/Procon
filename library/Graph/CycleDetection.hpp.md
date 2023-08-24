---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-4-A.test.cpp
    title: verify/AOJ-GRL-4-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Cycle Detection (Directed) - \u9589\u8DEF\u691C\u51FA\uFF08\u6709\
      \u5411\u30B0\u30E9\u30D5\uFF09"
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
  code: "#pragma once\n\n/**\n * @brief Cycle Detection (Directed) - \u9589\u8DEF\u691C\
    \u51FA\uFF08\u6709\u5411\u30B0\u30E9\u30D5\uFF09\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"GraphTemplate.hpp\"\n\n/**\n * @brief \u6709\
    \u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u691C\u51FA\u3092\u884C\u3046\u3002\
    \n */\ntemplate<typename CostType>\nstruct CycleDetection{\n    vector<vector<Vertex>>\
    \ cycle;\n    \n    private:\n    Graph<CostType> &G;\n    vector<Vertex> visited,\
    \ history;\n    vector<Vertex> belong;\n    vector<Vertex> tmp;\n\n    void dfs(int\
    \ v){\n        visited[v] = 1;\n        history.push_back(v);\n        for(auto\
    \ &e : G.get_edges(v)){\n            if(visited[e.to] == 2) continue;\n      \
    \      if(visited[e.to] == 1){\n                for(int i = history.size() - 1;\
    \ ; --i){\n                    tmp.push_back(history[i]);\n                  \
    \  belong[history[i]] = cycle.size();\n                    if(history[i] == e.to)\
    \ break;\n                }\n                cycle.push_back(tmp);\n         \
    \       tmp.clear();\n            }\n            else{\n                dfs(e.to);\n\
    \            }\n        }\n        history.pop_back();\n        visited[v] = 2;\n\
    \    }\n\n    public:\n    CycleDetection(Graph<CostType> &G) : G(G), visited(G.size(),\
    \ 0), belong(G.size(), -1){\n        assert(G.directed());\n        for(int i\
    \ = 0; i < G.size(); ++i){\n            if(!visited[i]) dfs(i);\n        }\n \
    \   }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5G\u304C\u9589\u8DEF\u3092\u6301\
    \u3064\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool exist(){\n\
    \        return cycle.size() > 0;\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/CycleDetection.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-4-A.test.cpp
documentation_of: library/Graph/CycleDetection.hpp
layout: document
redirect_from:
- /library/library/Graph/CycleDetection.hpp
- /library/library/Graph/CycleDetection.hpp.html
title: "Cycle Detection (Directed) - \u9589\u8DEF\u691C\u51FA\uFF08\u6709\u5411\u30B0\
  \u30E9\u30D5\uFF09"
---
