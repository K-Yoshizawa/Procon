---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-D.test.cpp
    title: verify/AOJ-GRL-5-D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
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
  code: "#pragma once\n\n/**\n * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\
    \u30A2\u30FC\n */\n\n#include \"../Graph/GraphTemplate.hpp\"\n#include \"../DataStructure/BinaryIndexedTree.hpp\"\
    \n\ntemplate<typename CostType>\nstruct EulerTour{\n    private:\n    int sz,\
    \ k;\n    using Tour = int;\n    Graph<CostType> &G;\n    vector<Tour> arrival,\
    \ departure; // \u9802\u70B9i\u306B\u8A2A\u308C\u305F\u6642\u9593 / \u9802\u70B9\
    i\u304B\u3089\u53BB\u308B\u6642\u9593 : BIT\u306B\u4E57\u305B\u308B\u3053\u3068\
    \u3092\u60F3\u5B9A\u3057\u3066\u3044\u308B\u305F\u3081\u3001\u30AF\u30A8\u30EA\
    \u51E6\u7406\u3092\u7C21\u6613\u306B\u3059\u308B\u305F\u3081\u306B1-index\u3067\
    \u8A18\u9332\u3059\u308B\n    BinaryIndexedTree<CostType> BIT;\n    vector<pair<Vertex,\
    \ EdgeNum>> relation;\n\n    void dfs1(int v, int pre){\n        arrival[v] =\
    \ k++;\n        for(auto &e : G.get_edges(v)){\n            if(e.to == pre) continue;\n\
    \            dfs1(e.to, v);\n        }\n        departure[v] = k++;\n    }\n\n\
    \    void dfs2(int v, int pre, CostType value){\n        BIT.add(arrival[v], value);\n\
    \        for(auto &e : G.get_edges(v)){\n            if(e.to == pre) continue;\n\
    \            dfs2(e.to, v, e.cost);\n        }\n        BIT.add(departure[v],\
    \ -value);\n    }\n\n    public:\n    /**\n     * @brief \u9802\u70B9root\u3092\
    \u6839\u3068\u3057\u305F\u6728G\u3067\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
    \u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention G\u304C\u6728\u3067\u306A\
    \u3044\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9\n     * @param G\
    \ \u6728\n     * @param root \u6839 (option, default = 0)\n     */\n    EulerTour(Graph<CostType>\
    \ &G, Vertex root = 0) : G(G), sz(G.size()), BIT(G.size() * 2), k(1){\n      \
    \  arrival.resize(sz, -1);\n        departure.resize(sz, -1);\n        dfs1(root,\
    \ -1);\n        dfs2(0, -1, 0);\n        relation = G.get_parent(root);\n    }\n\
    \n    /**\n     * @brief \u6839\u304B\u3089\u9802\u70B9v\u3078\u306E\u8DDD\u96E2\
    \u3092BIT\u3092\u7528\u3044\u3066\u53D6\u5F97\u3059\u308B\u3002\n     * @param\
    \ v \u53D6\u5F97\u3057\u305F\u3044\u9802\u70B9\u756A\u53F7v\n     * @return CostType\
    \ \u6839\u304B\u3089\u9802\u70B9v\u3078\u306E\u8DDD\u96E2\n     */\n    CostType\
    \ query(Vertex v){\n        return BIT.sum(arrival[v]);\n    }\n\n    /**\n  \
    \   * @brief \u9802\u70B9child\u3068\u305D\u306E\u89AA\u3092\u7D50\u3076\u8FBA\
    \u306E\u91CD\u307F\u3092x\u5897\u52A0\u3055\u305B\u308B\u4E00\u70B9\u66F4\u65B0\
    \u30AF\u30A8\u30EA\n     * @param child \u5B50\u306E\u9802\u70B9\u3092\u8868\u3059\
    \u9802\u70B9\u756A\u53F7\n     * @param x \u5897\u52A0\u3055\u305B\u308B\u91CD\
    \u307F\n     */\n    void add(Vertex child, CostType x){\n        auto [parent,\
    \ ed] = relation[child];\n        G.edges[ed].cost += x;\n        G.edges[G.rev[ed]].cost\
    \ += x;\n        BIT.add(arrival[child], x);\n        BIT.add(departure[child],\
    \ -x);\n    }\n\n    void update(Vertex child, CostType x){\n        auto [parent,\
    \ ed] = relation[child];\n        CostType diff = x - G.edges[ed].cost;\n    \
    \    G.edges[ed].cost += diff;\n        G.edges[G.rev[ed]].cost += diff;\n   \
    \     BIT.add(arrival[child], diff);\n        BIT.add(departure[child], -diff);\n\
    \    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  - library/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: false
  path: library/Tree/EulerTour.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-5-D.test.cpp
documentation_of: library/Tree/EulerTour.hpp
layout: document
redirect_from:
- /library/library/Tree/EulerTour.hpp
- /library/library/Tree/EulerTour.hpp.html
title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
---
