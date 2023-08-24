---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/FordFulkerson.hpp
    title: "Ford-Fulkerson - \u6700\u5927\u30D5\u30ED\u30FC"
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-7-A.test.cpp
    title: verify/AOJ-GRL-7-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Bipartite Matching - \u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/Graph/GraphTemplate.hpp: line 9: #pragma once found in a non-first line\n"
  code: "#pragma once\n\n/**\n * @brief Bipartite Matching - \u4E8C\u90E8\u30DE\u30C3\
    \u30C1\u30F3\u30B0\n */\n\n#include <bits/stdc++.h>\n\n#include \"FordFulkerson.hpp\"\
    \n\nusing namespace std;\n\nstruct BipartiteMatching{\n    private:\n    Graph<int>\
    \ G;\n    int X, Y, s, t;\n\n    public:\n    BipartiteMatching(int X, int Y)\
    \ : X(X), Y(Y), s(X + Y), t(X + Y + 1){\n        G = Graph<int>(X + Y + 2, true);\n\
    \        for(Vertex x = 0; x < X; ++x) G.add(s, x);\n        for(Vertex y = X;\
    \ y < X + Y; ++y) G.add(y, t);\n    }\n\n    void add(int x, int y){\n       \
    \ G.add(x, X + y);\n    }\n\n    int solve(){\n        FordFulkerson<int> ff(G);\n\
    \        return ff.query(s, t);\n    }\n};"
  dependsOn:
  - library/Graph/FordFulkerson.hpp
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-7-A.test.cpp
documentation_of: library/Graph/BipartiteMatching.hpp
layout: document
redirect_from:
- /library/library/Graph/BipartiteMatching.hpp
- /library/library/Graph/BipartiteMatching.hpp.html
title: "Bipartite Matching - \u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0"
---
