---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/UnionFind.hpp
    title: "UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-2-A.test.cpp
    title: verify/AOJ-GRL-2-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
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
  code: "#pragma once\n\n/**\n * @brief Kruskal - \u6700\u5C0F\u5168\u57DF\u6728\n\
    \ */\n\n#include <bits/stdc++.h>\n\n#include \"GraphTemplate.hpp\"\n#include \"\
    ../DataStructure/UnionFind.hpp\"\n\nusing namespace std;\n\ntemplate<typename\
    \ CostType>\nstruct Kruskal{\n    int V;\n    vector<EdgeNum> MST;\n    CostType\
    \ Cost;\n\n    Kruskal(Graph<CostType> &G){\n        V = G.size();\n        UnionFind\
    \ uf(V);\n    \n        vector<pair<CostType, EdgeNum>> EL;\n        for(int i\
    \ = 0; i < G.edges.size(); ++i){\n            EL.emplace_back(G.edges[i].cost,\
    \ i);\n        }\n        sort(EL.begin(), EL.end());\n\n        Cost = 0;\n \
    \       for(auto &x : EL){\n            auto e = G.get_edge(x.second);\n     \
    \       if(!uf.same(e.from, e.to)){\n                uf.unite(e.from, e.to);\n\
    \                Cost += x.first;\n                MST.push_back(x.second);\n\
    \            }\n        }\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  - library/DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: library/Graph/Kruskal.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-2-A.test.cpp
documentation_of: library/Graph/Kruskal.hpp
layout: document
redirect_from:
- /library/library/Graph/Kruskal.hpp
- /library/library/Graph/Kruskal.hpp.html
title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
---
