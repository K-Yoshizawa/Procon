---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-C.test.cpp
    title: verify/AOJ-GRL-5-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
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
  code: "#pragma once\n\n/**\n * @brief Lowest Common Ancestor - \u6700\u5C0F\u5171\
    \u901A\u7956\u5148\n */\n\n#include \"../Graph/GraphTemplate.hpp\"\n\nusing namespace\
    \ std;\n\ntemplate<typename CostType>\nstruct LowestCommonAncestor{\n    private:\n\
    \    Graph<CostType> &G;\n    int sz, LOG;\n    vector<int> depth;\n    vector<vector<Vertex>>\
    \ parent;\n\n    void dfs(Vertex v, Vertex p, int d){\n        parent[0][v] =\
    \ p;\n        depth[v] = d;\n        for(auto &e : G.get_edges(v)){\n        \
    \    if(e.to != p) dfs(e.to, v, d + 1);\n        }\n    }\n\n    public:\n   \
    \ LowestCommonAncestor(Graph<CostType> &G) : G(G), sz(G.size()), LOG(ceil(log2(G.size()))\
    \ + 1){\n        depth.resize(sz);\n        parent.resize(LOG, vector<Vertex>(sz,\
    \ 0));\n        dfs(0, -1, 0);\n        for(int k = 0; k + 1 < LOG; ++k){\n  \
    \          for(int v = 0; v < sz; ++v){\n                if(parent[k][v] < 0)\
    \ parent[k + 1][v] = -1;\n                else parent[k + 1][v] = parent[k][parent[k][v]];\n\
    \            }\n        }\n    }\n\n    Vertex query(Vertex u, Vertex v){\n  \
    \      if(depth[u] > depth[v]) swap(u, v);\n        for(int k = 0; k < LOG; ++k){\n\
    \            if((depth[v] - depth[u]) >> k & 1){\n                v = parent[k][v];\n\
    \            }\n        }\n        if(u == v) return u;\n        for(int k = LOG\
    \ - 1; k >= 0; --k){\n            if(parent[k][u] != parent[k][v]){\n        \
    \        u = parent[k][u];\n                v = parent[k][v];\n            }\n\
    \        }\n        return parent[0][u];\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Tree/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-5-C.test.cpp
documentation_of: library/Tree/LowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/library/Tree/LowestCommonAncestor.hpp
- /library/library/Tree/LowestCommonAncestor.hpp.html
title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
---
