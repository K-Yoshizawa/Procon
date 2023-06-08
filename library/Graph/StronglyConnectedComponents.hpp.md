---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/VGraph.hpp
    title: Vertex Graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-C.test.cpp
    title: verify/AOJ-GRL-3-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: StronglyConnectedComponents
    links: []
  bundledCode: "#line 2 \"library/Graph/StronglyConnectedComponents.hpp\"\n\n#include\
    \ <bits/stdc++.h>\n#line 2 \"library/Graph/VGraph.hpp\"\n\n#line 4 \"library/Graph/VGraph.hpp\"\
    \nusing namespace std;\n\n/**\n * @brief Vertex Graph\n */\n\n/**\n * @brief \u30B0\
    \u30E9\u30D5\u306E\u8FBA\n */\ntemplate<typename T>\nstruct Edge{\n    int from,\
    \ to;\n    T cost;\n\n    Edge(int from, int to, T cost) : from(from), to(to),\
    \ cost(cost){}\n};\n\n/**\n * @brief \u9802\u70B9\u96C6\u5408\u3067\u7BA1\u7406\
    \u3059\u308B\u30B0\u30E9\u30D5\n */\ntemplate<typename T>\nstruct VGraph{\n  \
    \  int sz; // \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\n    bool directed; //\
    \ \u6709\u5411\u30B0\u30E9\u30D5\u304B\n    vector<vector<Edge<T>>> vertex; //\
    \ \u9802\u70B9\u96C6\u5408\n    vector<int> indegree, outdegree; // \u5165\u6B21\
    \u6570\u3001\u51FA\u6B21\u6570\n\n    VGraph(int size, bool directed = false)\
    \ : sz(size), vertex(size), indegree(size, 0), outdegree(size, 0), directed(directed){}\n\
    \    VGraph() = default;\n\n    /**\n     * @brief \u7121\u5411\u30B0\u30E9\u30D5\
    \u306E\u5834\u5408\u306F\u9802\u70B9s\u3068\u9802\u70B9t\u3092\u7D50\u3076\u7121\
    \u5411\u8FBA\u3001\u6709\u5411\u30B0\u30E9\u30D5\u306E\u5834\u5408\u306F\u9802\
    \u70B9s\u304B\u3089\u9802\u70B9t\u3078\u306E\u6709\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\u3002\n     * \n     * @param s \u9802\u70B9s (0-index)\n     * @param\
    \ t \u9802\u70B9t (0-index)\n     * @param w \u91CD\u307F (\u7701\u7565\u53EF\u3001\
    \u7701\u7565\u6642\u306F1)\n     */\n    void add(int s, int t, T w = 1){\n  \
    \      vertex[s].push_back(Edge<T>(s, t, w));\n        ++outdegree[s];\n     \
    \   ++indegree[t];\n        if(!directed){\n            vertex[t].push_back(Edge<T>(t,\
    \ s, w));\n            ++indegree[s];\n            ++outdegree[t];\n        }\n\
    \    }\n\n    /**\n     * @brief \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\
    \u30D5\u3092\u8FD4\u3059\u3002\n     * @attention \u30B0\u30E9\u30D5\u304C\u6709\
    \u5411\u30B0\u30E9\u30D5\u3067\u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\
    \u3002\n     * @return VGraph<T> \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\
    \u30D5\n     */\n    VGraph<T> reverse(){\n        assert(directed == true);\n\
    \        VGraph<T> ret(sz, true);\n        for(int s = 0; s < sz; ++s){\n    \
    \        for(auto &e : vertex[s]){\n                ret.add(e.to, s, e.cost);\n\
    \            }\n        }\n        return ret;\n    }\n};\n#line 5 \"library/Graph/StronglyConnectedComponents.hpp\"\
    \nusing namespace std;\n\n/**\n * @brief StronglyConnectedComponents\n */\n\n\
    /**\n * @brief  \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u3092\u884C\u3046\u3002\
    \n */\ntemplate<typename T>\nstruct StronglyConnectedComponents{\n    VGraph<T>\
    \ &G, rG;\n    vector<int> belong; // \u9802\u70B9\u304C\u3069\u306E\u5F37\u9023\
    \u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u304B\n    vector<vector<int>>\
    \ sc; // \u5404\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u9802\
    \u70B9\n\n    private:\n    vector<int> order, visited;\n    vector<int> tmp;\n\
    \n    void dfs(int v){\n        visited[v] = 1;\n        for(auto &e : G.vertex[v]){\n\
    \            if(visited[e.to] == 0) dfs(e.to);\n        }\n        order.push_back(v);\n\
    \    }\n\n    void rdfs(int v, int k){\n        visited[v] = 0;\n        belong[v]\
    \ = k;\n        tmp.push_back(v);\n        for(auto &e : rG.vertex[v]){\n    \
    \        if(visited[e.to] == 1) rdfs(e.to, k);\n        }\n    }\n\n    public:\n\
    \    StronglyConnectedComponents(VGraph<T> &G) : G(G){\n        rG = G.reverse();\n\
    \        visited.resize(G.sz, 0);\n        belong.resize(G.sz, -1);\n        for(int\
    \ i = 0; i < G.sz; ++i){\n            if(visited[i] == 0) dfs(i);\n        }\n\
    \        int k = 0;\n        for(int i = order.size() - 1; i >= 0; --i){\n   \
    \         if(visited[order[i]] == 1){\n                rdfs(order[i], k++);\n\
    \                sc.push_back(tmp);\n                tmp.clear();\n          \
    \  }\n        }\n    }\n\n    /**\n     * @brief  2\u3064\u306E\u9802\u70B9\u304C\
    \u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u304B\
    \u3092\u5224\u5B9A\u3059\u308B\u3002\n     * @param  u: \u5224\u5B9A\u3057\u305F\
    \u3044\u9802\u70B9u\n     * @param  v: \u5224\u5B9A\u3057\u305F\u3044\u9802\u70B9\
    v\n     * @retval \u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\
    \u3059\u308B\u306A\u3089true\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070false\n\
    \     */\n    bool same(int u, int v){\n        return belong[u] == belong[v];\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\n#include \"VGraph.hpp\"\nusing\
    \ namespace std;\n\n/**\n * @brief StronglyConnectedComponents\n */\n\n/**\n *\
    \ @brief  \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u3092\u884C\u3046\u3002\n\
    \ */\ntemplate<typename T>\nstruct StronglyConnectedComponents{\n    VGraph<T>\
    \ &G, rG;\n    vector<int> belong; // \u9802\u70B9\u304C\u3069\u306E\u5F37\u9023\
    \u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u304B\n    vector<vector<int>>\
    \ sc; // \u5404\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u9802\
    \u70B9\n\n    private:\n    vector<int> order, visited;\n    vector<int> tmp;\n\
    \n    void dfs(int v){\n        visited[v] = 1;\n        for(auto &e : G.vertex[v]){\n\
    \            if(visited[e.to] == 0) dfs(e.to);\n        }\n        order.push_back(v);\n\
    \    }\n\n    void rdfs(int v, int k){\n        visited[v] = 0;\n        belong[v]\
    \ = k;\n        tmp.push_back(v);\n        for(auto &e : rG.vertex[v]){\n    \
    \        if(visited[e.to] == 1) rdfs(e.to, k);\n        }\n    }\n\n    public:\n\
    \    StronglyConnectedComponents(VGraph<T> &G) : G(G){\n        rG = G.reverse();\n\
    \        visited.resize(G.sz, 0);\n        belong.resize(G.sz, -1);\n        for(int\
    \ i = 0; i < G.sz; ++i){\n            if(visited[i] == 0) dfs(i);\n        }\n\
    \        int k = 0;\n        for(int i = order.size() - 1; i >= 0; --i){\n   \
    \         if(visited[order[i]] == 1){\n                rdfs(order[i], k++);\n\
    \                sc.push_back(tmp);\n                tmp.clear();\n          \
    \  }\n        }\n    }\n\n    /**\n     * @brief  2\u3064\u306E\u9802\u70B9\u304C\
    \u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u304B\
    \u3092\u5224\u5B9A\u3059\u308B\u3002\n     * @param  u: \u5224\u5B9A\u3057\u305F\
    \u3044\u9802\u70B9u\n     * @param  v: \u5224\u5B9A\u3057\u305F\u3044\u9802\u70B9\
    v\n     * @retval \u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\
    \u3059\u308B\u306A\u3089true\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070false\n\
    \     */\n    bool same(int u, int v){\n        return belong[u] == belong[v];\n\
    \    }\n};"
  dependsOn:
  - library/Graph/VGraph.hpp
  isVerificationFile: false
  path: library/Graph/StronglyConnectedComponents.hpp
  requiredBy: []
  timestamp: '2023-06-08 14:23:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-3-C.test.cpp
documentation_of: library/Graph/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/library/Graph/StronglyConnectedComponents.hpp
- /library/library/Graph/StronglyConnectedComponents.hpp.html
title: StronglyConnectedComponents
---
