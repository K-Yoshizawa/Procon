---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../DataStructure/UnionFind.hpp:\
    \ line -1: no such header\n"
  code: "/**\n * @file Kruskal.hpp\n * @author log K (lX57)\n * @brief Kruskal - \u6700\
    \u5C0F\u5168\u57DF\u6728\n * @version 2.0\n * @date 2023-11-01\n */\n\n#include\
    \ \"GraphTemplate.hpp\"\n#include \"../DataStructure/UnionFind.hpp\"\n\ntemplate<typename\
    \ CostType>\nstruct Kruskal{\n    private:\n    Graph<CostType> &G;\n    vector<EdgeID>\
    \ __RemainEdge;\n    CostType __Cost;\n\n    public:\n    Kruskal(Graph<CostType>\
    \ &G) : G(G), __Cost(0){\n        UnionFind uf(G.vsize());\n        auto es =\
    \ G.get_edgeset();\n        vector<EdgeID> eid(G.esize());\n        iota(eid.begin(),\
    \ eid.end(), 0);\n        sort(eid.begin(), eid.end(), [&](EdgeID l, EdgeID r){return\
    \ es[l].cost < es[r].cost;});\n        for(EdgeID i : eid){\n            if(uf.same(es[i].src,\
    \ es[i].to)) continue;\n            uf.unite(es[i].src, es[i].to);\n         \
    \   __RemainEdge.push_back(i);\n            __Cost += es[i].cost;\n        }\n\
    \    }\n\n    CostType get(){\n        return __Cost;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: old/Graph/Kruskal.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/Graph/Kruskal.hpp
layout: document
redirect_from:
- /library/old/Graph/Kruskal.hpp
- /library/old/Graph/Kruskal.hpp.html
title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
---
