---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/AOJ-GRL-1-B.test.cpp
    title: verify/AOJ-GRL-1-B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Bellman Ford - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2\
      \uFF08\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\uFF09"
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
  code: "#pragma once\n\n/**\n * @brief Bellman Ford - \u5358\u4E00\u59CB\u70B9\u6700\
    \u77ED\u8DDD\u96E2\uFF08\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\
    \uFF09\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"GraphTemplate.hpp\"\
    \n\ntemplate<typename CostType>\nvector<CostType> BellmanFord(Graph<CostType>\
    \ &G, int s){\n    vector<CostType> ret(G.size(), G.INF);\n    ret[s] = 0;\n \
    \   int updatecount = 0;\n    while(1){\n        if(updatecount == G.size()){\n\
    \            ret[s] = -1;\n            return ret;\n        }\n        bool update\
    \ = false;\n        for(auto &e : G.edges){\n            Vertex from = e.from,\
    \ to = e.to;\n            CostType cost = e.cost;\n            if(ret[from] ==\
    \ G.INF) continue;\n            if(ret[to] > ret[from] + cost){\n            \
    \    ret[to] = ret[from] + cost;\n                update = true;\n           \
    \ }\n        }\n        if(!update) break;\n        ++updatecount;\n    }\n  \
    \  return ret;\n}"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/BellmanFord.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/AOJ-GRL-1-B.test.cpp
documentation_of: library/Graph/BellmanFord.hpp
layout: document
redirect_from:
- /library/library/Graph/BellmanFord.hpp
- /library/library/Graph/BellmanFord.hpp.html
title: "Bellman Ford - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2\uFF08\u30D9\
  \u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\uFF09"
---
