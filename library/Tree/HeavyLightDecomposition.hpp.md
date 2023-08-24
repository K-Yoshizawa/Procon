---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/AOJ-GRL-5-E.test.cpp
    title: verify/AOJ-GRL-5-E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Heavy Light Decomposition - HL\u5206\u89E3"
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
  code: "#pragma once\n\n/**\n * @brief Heavy Light Decomposition - HL\u5206\u89E3\
    \n */\n\n#include \"../Graph/GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct HeavyLightDecompsition{\n    using Column = int;\n    \n    private:\n\
    \    int sz;\n    Vertex root;\n    Graph<CostType> &G;\n    vector<int> subtree_size;\
    \ // \u9802\u70B9i\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\
    \u70B9\u6570\n    vector<pair<Vertex, EdgeNum>> relation; // \u6728\u306E\u89AA\
    \u5B50\u95A2\u4FC2\n    vector<vector<Vertex>> column_vertex; // \u5404\u5217\u306B\
    \u542B\u307E\u308C\u308B\u9802\u70B9\u30EA\u30B9\u30C8\n    vector<pair<Column,\
    \ int>> column_index; // \u5404\u9802\u70B9\u306E\u9802\u70B9\u30EA\u30B9\u30C8\
    \u5185\u306E\u4F4D\u7F6E\n    vector<int> offset; // 1\u5217\u306B\u4E26\u3079\
    \u305F\u3068\u304D\u3001\u5404\u5217\u306E\u5148\u982D\u306E\u9802\u70B9\u306E\
    \u4F4D\u7F6E (0-index)\n\n    /**\n     * @brief \u9802\u70B9i\u3092\u6839\u3068\
    \u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\u3092\u6C42\u3081\u308B\
    DFS\n     * @param v \u6839\u3068\u306A\u308B\u9802\u70B9\u756A\u53F7\n     *\
    \ @param pre \u89AA\u306E\u9802\u70B9\n     * @return int \u9802\u70B9\u306E\u90E8\
    \u5206\u6728\u306E\u9802\u70B9\u6570\n     */\n    int dfs1(Vertex v, Vertex pre){\n\
    \        int res = 0;\n        for(auto &e : G.get_edges(v)){\n            if(e.to\
    \ == pre) continue;\n            res += dfs1(e.to, v);\n        }\n        return\
    \ subtree_size[v] = res + 1;\n    }\n\n    void dfs2(Vertex v, Vertex pre, Column\
    \ col){\n        if(column_vertex.size() == col) column_vertex.emplace_back(vector<Vertex>{});\n\
    \        column_index[v] = pair<Column, int>(col, column_vertex[col].size());\n\
    \        column_vertex[col].push_back(v);\n        Vertex next = -1;\n       \
    \ int max_subtree = 0;\n        for(auto &e : G.get_edges(v)){\n            if(e.to\
    \ == pre) continue;\n            if(max_subtree < subtree_size[e.to]){\n     \
    \           next = e.to;\n                max_subtree = subtree_size[e.to];\n\
    \            }\n        }\n        if(next != -1) dfs2(next, v, col);\n      \
    \  for(auto &e : G.get_edges(v)){\n            if(e.to == pre || e.to == next)\
    \ continue;\n            dfs2(e.to, v, column_vertex.size());\n        }\n   \
    \     return;\n    }\n\n    /**\n     * @brief 1\u5217\u306B\u4E26\u3079\u305F\
    \u3068\u304D\u306E\u9802\u70B9v\u306E\u4F4D\u7F6E\n     * @param v \u4F4D\u7F6E\
    \u3092\u77E5\u308A\u305F\u3044\u9802\u70B9\u756A\u53F7\n     * @return int \u5217\
    \u306B\u304A\u3051\u308B\u4F4D\u7F6E(0-index)\n     */\n    inline int locate(Vertex\
    \ v){\n        auto [i, j] = column_index[v];\n        return offset[i] + j;\n\
    \    }\n    \n    public:\n    HeavyLightDecompsition(Graph<CostType> &G, Vertex\
    \ root = 0) : G(G), sz(G.size()), root(root){\n        subtree_size.resize(sz,\
    \ -1);\n        dfs1(root, -1);\n        column_index.resize(sz, pair<Column,\
    \ int>(-1, -1));\n        dfs2(root, -1, 0);\n        offset.resize(column_vertex.size(),\
    \ 0);\n        for(int i = 1; i < column_vertex.size(); ++i){\n            offset[i]\
    \ = offset[i - 1] + column_vertex[i - 1].size();\n        }\n        relation\
    \ = G.get_parent(root);\n    }\n\n    /**\n     * @brief \u9802\u70B9u\u304B\u3089\
    \u9802\u70B9v\u307E\u3067\u306E\u533A\u9593\u306E\u4E00\u89A7\u3092\u53D6\u5F97\
    \u3059\u308B\u3002\n     * @note \u533A\u9593\u306F\u534A\u958B\u533A\u9593\u3068\
    \u3057\u3066\u4E0E\u3048\u3089\u308C\u3001\u9802\u70B9u\u3092\u7701\u7565\u3059\
    \u308B\u3068\u6839\u3068\u3059\u308B\n     * @param v: \u5B50\u306E\u65B9\u306E\
    \u9802\u70B9\u756A\u53F7(0-index)\n     * @param u: \u89AA\u306E\u65B9\u306E\u9802\
    \u70B9\u756A\u53F7(0-index, option default = root)\n     * @retval \u534A\u958B\
    \u533A\u9593\u306E\u4E00\u89A7\n     */\n    vector<pair<int, int>> get_segment(Vertex\
    \ v, Vertex u = -1){\n        if(u == -1) u = root;\n        auto [uc, ui] = column_index[u];\n\
    \        vector<pair<int, int>> ret;\n        Vertex now = v;\n        while(1){\n\
    \            auto [c, i] = column_index[now];\n            if(uc == c){\n    \
    \            ret.emplace_back(offset[uc] + ui, offset[c] + i + 1);\n         \
    \       break;\n            }\n            else ret.emplace_back(offset[c], offset[c]\
    \ + i + 1);\n            Vertex front = column_vertex[c][0];\n            now\
    \ = relation[front].first;\n        }\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u30921\u5217\u306B\u4E26\u3079\u305F\u3068\u304D\
    \u306E\u5404\u9802\u70B9\u306B\u5BFE\u5FDC\u3059\u308B\u5024\u306E\u914D\u5217\
    \u3092\u8FD4\u3059\n     * @note \u30BB\u30B0\u6728\u3068\u304B\u306E\u521D\u671F\
    \u914D\u5217\n     * @return vector<CostType> \n     */\n    vector<CostType>\
    \ get_data(){\n        vector<CostType> ret(sz, 0);\n        for(int i = 0; i\
    \ < column_vertex.size(); ++i){\n            for(int j = 0; j < column_vertex[i].size();\
    \ ++j){\n                Vertex v = column_vertex[i][j];\n                EdgeNum\
    \ e = relation[v].second;\n                if(e == -1) continue;\n           \
    \     ret[locate(v)] = G.get_edge(e).cost;\n            }\n        }\n       \
    \ return ret;\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/AOJ-GRL-5-E.test.cpp
documentation_of: library/Tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/library/Tree/HeavyLightDecomposition.hpp
- /library/library/Tree/HeavyLightDecomposition.hpp.html
title: "Heavy Light Decomposition - HL\u5206\u89E3"
---
