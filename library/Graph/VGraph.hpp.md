---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/Graph/CycleDetection.hpp
    title: Cycle Detection
  - icon: ':heavy_check_mark:'
    path: library/Graph/Dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: library/Graph/StronglyConnectedComponents.hpp
    title: StronglyConnectedComponents
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-A.test.cpp
    title: verify/AOJ-GRL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-C.test.cpp
    title: verify/AOJ-GRL-3-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-4-A.test.cpp
    title: verify/AOJ-GRL-4-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Vertex Graph
    links: []
  bundledCode: "#line 2 \"library/Graph/VGraph.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/**\n * @brief Vertex Graph\n */\n\n/**\n * @brief \u30B0\
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
    \            }\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n/**\n *\
    \ @brief Vertex Graph\n */\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u8FBA\n\
    \ */\ntemplate<typename T>\nstruct Edge{\n    int from, to;\n    T cost;\n\n \
    \   Edge(int from, int to, T cost) : from(from), to(to), cost(cost){}\n};\n\n\
    /**\n * @brief \u9802\u70B9\u96C6\u5408\u3067\u7BA1\u7406\u3059\u308B\u30B0\u30E9\
    \u30D5\n */\ntemplate<typename T>\nstruct VGraph{\n    int sz; // \u30B0\u30E9\
    \u30D5\u306E\u9802\u70B9\u6570\n    bool directed; // \u6709\u5411\u30B0\u30E9\
    \u30D5\u304B\n    vector<vector<Edge<T>>> vertex; // \u9802\u70B9\u96C6\u5408\n\
    \    vector<int> indegree, outdegree; // \u5165\u6B21\u6570\u3001\u51FA\u6B21\u6570\
    \n\n    VGraph(int size, bool directed = false) : sz(size), vertex(size), indegree(size,\
    \ 0), outdegree(size, 0), directed(directed){}\n    VGraph() = default;\n\n  \
    \  /**\n     * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306E\u5834\u5408\u306F\u9802\
    \u70B9s\u3068\u9802\u70B9t\u3092\u7D50\u3076\u7121\u5411\u8FBA\u3001\u6709\u5411\
    \u30B0\u30E9\u30D5\u306E\u5834\u5408\u306F\u9802\u70B9s\u304B\u3089\u9802\u70B9\
    t\u3078\u306E\u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\n     * \n\
    \     * @param s \u9802\u70B9s (0-index)\n     * @param t \u9802\u70B9t (0-index)\n\
    \     * @param w \u91CD\u307F (\u7701\u7565\u53EF\u3001\u7701\u7565\u6642\u306F\
    1)\n     */\n    void add(int s, int t, T w = 1){\n        vertex[s].push_back(Edge<T>(s,\
    \ t, w));\n        ++outdegree[s];\n        ++indegree[t];\n        if(!directed){\n\
    \            vertex[t].push_back(Edge<T>(t, s, w));\n            ++indegree[s];\n\
    \            ++outdegree[t];\n        }\n    }\n\n    /**\n     * @brief \u9006\
    \u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\u30D5\u3092\u8FD4\u3059\u3002\n   \
    \  * @attention \u30B0\u30E9\u30D5\u304C\u6709\u5411\u30B0\u30E9\u30D5\u3067\u306A\
    \u3051\u308C\u3070\u306A\u3089\u306A\u3044\u3002\n     * @return VGraph<T> \u9006\
    \u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\u30D5\n     */\n    VGraph<T> reverse(){\n\
    \        assert(directed == true);\n        VGraph<T> ret(sz, true);\n       \
    \ for(int s = 0; s < sz; ++s){\n            for(auto &e : vertex[s]){\n      \
    \          ret.add(e.to, s, e.cost);\n            }\n        }\n        return\
    \ ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/Graph/VGraph.hpp
  requiredBy:
  - library/Graph/CycleDetection.hpp
  - library/Graph/Dijkstra.hpp
  - library/Graph/StronglyConnectedComponents.hpp
  timestamp: '2023-06-08 13:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-A.test.cpp
  - verify/AOJ-GRL-4-A.test.cpp
  - verify/AOJ-GRL-3-C.test.cpp
documentation_of: library/Graph/VGraph.hpp
layout: document
redirect_from:
- /library/library/Graph/VGraph.hpp
- /library/library/Graph/VGraph.hpp.html
title: Vertex Graph
---
