---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/VGraph.hpp
    title: Vertex Graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-4-A.test.cpp
    title: verify/AOJ-GRL-4-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Cycle Detection
    links: []
  bundledCode: "#line 2 \"library/Graph/CycleDetection.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"library/Graph/VGraph.hpp\"\n\n#line 4 \"library/Graph/VGraph.hpp\"\
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
    \            }\n        }\n        return ret;\n    }\n};\n#line 7 \"library/Graph/CycleDetection.hpp\"\
    \n\n/**\n * @brief Cycle Detection\n */\n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\
    \u30D5\u306E\u9589\u8DEF\u691C\u51FA\u3092\u884C\u3046\u3002\n */\ntemplate<typename\
    \ T>\nstruct CycleDetection{\n    vector<vector<int>> cycle;\n    \n    private:\n\
    \    VGraph<T> &G;\n    vector<int> visited, history;\n    vector<int> belong;\n\
    \    vector<int> tmp;\n\n    void dfs(int v){\n        visited[v] = 1;\n     \
    \   history.push_back(v);\n        for(auto &e : G.vertex[v]){\n            if(visited[e.to]\
    \ == 2) continue;\n            if(visited[e.to] == 1){\n                for(int\
    \ i = history.size() - 1; ; --i){\n                    tmp.push_back(history[i]);\n\
    \                    belong[history[i]] = cycle.size();\n                    if(history[i]\
    \ == e.to) break;\n                }\n                cycle.push_back(tmp);\n\
    \                tmp.clear();\n            }\n            else{\n            \
    \    dfs(e.to);\n            }\n        }\n        history.pop_back();\n     \
    \   visited[v] = 2;\n    }\n\n    public:\n    CycleDetection(VGraph<T> &G) :\
    \ G(G), visited(G.sz, 0), belong(G.sz, -1){\n        assert(G.directed == true);\n\
    \        for(int i = 0; i < G.sz; ++i){\n            if(!visited[i]) dfs(i);\n\
    \        }\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5G\u304C\u9589\u8DEF\
    \u3092\u6301\u3064\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool\
    \ exist(){\n        return cycle.size() > 0;\n    }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"VGraph.hpp\"\n\n/**\n * @brief Cycle Detection\n */\n\n/**\n * @brief \u6709\
    \u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u691C\u51FA\u3092\u884C\u3046\u3002\
    \n */\ntemplate<typename T>\nstruct CycleDetection{\n    vector<vector<int>> cycle;\n\
    \    \n    private:\n    VGraph<T> &G;\n    vector<int> visited, history;\n  \
    \  vector<int> belong;\n    vector<int> tmp;\n\n    void dfs(int v){\n       \
    \ visited[v] = 1;\n        history.push_back(v);\n        for(auto &e : G.vertex[v]){\n\
    \            if(visited[e.to] == 2) continue;\n            if(visited[e.to] ==\
    \ 1){\n                for(int i = history.size() - 1; ; --i){\n             \
    \       tmp.push_back(history[i]);\n                    belong[history[i]] = cycle.size();\n\
    \                    if(history[i] == e.to) break;\n                }\n      \
    \          cycle.push_back(tmp);\n                tmp.clear();\n            }\n\
    \            else{\n                dfs(e.to);\n            }\n        }\n   \
    \     history.pop_back();\n        visited[v] = 2;\n    }\n\n    public:\n   \
    \ CycleDetection(VGraph<T> &G) : G(G), visited(G.sz, 0), belong(G.sz, -1){\n \
    \       assert(G.directed == true);\n        for(int i = 0; i < G.sz; ++i){\n\
    \            if(!visited[i]) dfs(i);\n        }\n    }\n\n    /**\n     * @brief\
    \ \u30B0\u30E9\u30D5G\u304C\u9589\u8DEF\u3092\u6301\u3064\u304B\u3092\u5224\u5B9A\
    \u3059\u308B\u3002\n     */\n    bool exist(){\n        return cycle.size() >\
    \ 0;\n    }\n};"
  dependsOn:
  - library/Graph/VGraph.hpp
  isVerificationFile: false
  path: library/Graph/CycleDetection.hpp
  requiredBy: []
  timestamp: '2023-06-08 15:30:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-4-A.test.cpp
documentation_of: library/Graph/CycleDetection.hpp
layout: document
redirect_from:
- /library/library/Graph/CycleDetection.hpp
- /library/library/Graph/CycleDetection.hpp.html
title: Cycle Detection
---
