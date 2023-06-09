---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/AOJ-GRL-5-A.test.cpp
    title: verify/AOJ-GRL-5-A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Tree Diamiter - \u6728\u306E\u76F4\u5F84"
    links: []
  bundledCode: "#line 2 \"library/Tree/TreeDiamiter.hpp\"\n\n/**\n * @brief Tree Diamiter\
    \ - \u6728\u306E\u76F4\u5F84\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing EdgeNum\
    \ = int;\nusing Vertex = int;\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u8FBA\
    \n */\ntemplate<typename CostType = int>\nstruct Edge{\n    Vertex from, to;\n\
    \    CostType cost;\n\n    Edge(Vertex from, Vertex to, CostType cost) : from(from),\
    \ to(to), cost(cost){}\n};\n\n/**\n * @brief \u30B0\u30E9\u30D5\u3092\u8868\u3059\
    \u30AF\u30E9\u30B9\u3002\n * @note \u8FBA\u96C6\u5408\u306B\u3088\u3063\u3066\u5B9F\
    \u73FE\u3057\u3066\u3044\u308B\u3002\n * @tparam CostType \u8FBA\u306E\u91CD\u307F\
    \u306E\u578B\u3002\n */\ntemplate<typename CostType = int>\nclass Graph{\n   \
    \ private:\n    int sz;\n    bool dir;\n    vector<int> indegree;\n\n    public:\n\
    \    vector<Edge<CostType>> edges;\n    vector<vector<EdgeNum>> connect;\n   \
    \ CostType INF;\n\n    /**\n     * @brief Construct a new Graph object\n     *\
    \ @param VertexNum \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\n     * @param isDirected\
    \ \u6709\u5411\u30B0\u30E9\u30D5\u3068\u3057\u3066\u4F5C\u6210\u3059\u308B\u304B\
    \n     */\n    Graph(int VertexNum, bool isDirected = false) : sz(VertexNum),\
    \ dir(isDirected), connect(VertexNum), indegree(VertexNum), INF(numeric_limits<CostType>::max()){}\n\
    \n    Graph() = default;\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u306B\u9802\
    \u70B9s\u3068\u9802\u70B9t\u9593\u306E\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\
    \n     * @note \u6709\u5411\u30B0\u30E9\u30D5\u306A\u3089\u3070\u9802\u70B9s\u304B\
    \u3089\u9802\u70B9t\u3078\u306E\u6709\u5411\u8FBA\u3092\u3001\u7121\u5411\u30B0\
    \u30E9\u30D5\u306A\u3089\u3070\u9802\u70B9s\u3068\u9802\u70B9t\u3092\u7D50\u3076\
    \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\n     * @param s \u9802\
    \u70B9s\n     * @param t \u9802\u70B9t\n     * @param w \u8FBA\u306E\u91CD\u307F\
    \ (option, default = 1)\n     */\n    void add(Vertex s, Vertex t, CostType w\
    \ = 1){\n        assert(0 <= s && s < sz);\n        assert(0 <= t && t < sz);\n\
    \        EdgeNum e = edges.size();\n        edges.push_back(Edge<CostType>(s,\
    \ t, w));\n        connect[s].push_back(e);\n        ++indegree[t];\n        if(!dir){\n\
    \            edges.push_back(Edge<CostType>(t, s, w));\n            connect[t].push_back(e\
    \ + 1);\n        }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3057\u305F\u8FBA\
    \u756A\u53F7\u306E\u8FBA\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param idx\
    \ \u8FBA\u756A\u53F7\n     * @return Edge<CostType> \u8FBA\u60C5\u5831\n     */\n\
    \    Edge<CostType> get_edge(EdgeNum idx){\n        int e = edges.size();\n  \
    \      assert(0 <= idx && idx < e);\n        return edges[idx];\n    }\n\n   \
    \ /**\n     * @brief \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\u63A5\
    \u7D9A\u3059\u308B\u8FBA\u306E\u4E00\u89A7\u3092\u53D6\u5F97\u3059\u308B\u3002\
    \n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return vector<Edge<CostType>>\
    \ \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\
    \u8FBA\u306E\u4E00\u89A7\n     */\n    vector<Edge<CostType>> get_edges(Vertex\
    \ v){\n        assert(0 <= v && v < sz);\n        vector<Edge<CostType>> ret;\n\
    \        for(auto &idx : connect[v]) ret.push_back(get_edge(idx));\n        return\
    \ ret;\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\
    \u53F7\u306B\u63A5\u7D9A\u3059\u308B\u8FBA\u756A\u53F7\u306E\u4E00\u89A7\u3092\
    \u53D6\u5F97\u3059\u308B\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\n   \
    \  * @return vector<EdgeNum> \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\
    \u63A5\u7D9A\u3059\u308B\u8FBA\u756A\u53F7\u306E\u4E00\u89A7\n     */\n    vector<EdgeNum>\
    \ get_list(Vertex v){\n        assert(0 <= v && v < sz);\n        return connect[v];\n\
    \    }\n\n    /**\n     * @brief \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\
    \u30D5\u3092\u4F5C\u6210\u3059\u308B\u3002\n     * @attention \u3053\u306E\u64CD\
    \u4F5C\u306F\u6709\u5411\u30B0\u30E9\u30D5\u306B\u306E\u307F\u53EF\u80FD\u3067\
    \u3042\u308B\u3002\n     * @return Graph<CostType> \u9006\u8FBA\u3092\u5F35\u3063\
    \u305F\u30B0\u30E9\u30D5\n     */\n    Graph<CostType> reverse(){\n        assert(dir);\n\
    \        Graph<CostType> ret(sz, true);\n        for(auto &e : edges){\n     \
    \       ret.add(e.to, e.from, e.cost);\n        }\n        return ret;\n    }\n\
    \n    inline size_t size(){\n        return sz;\n    }\n\n    inline bool directed(){\n\
    \        return dir;\n    }\n\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\
    \u306E\u6B21\u6570(\u51FA\u6B21\u6570)\u3092\u53D6\u5F97\u3059\u308B\u3002\n \
    \    * @note \u6709\u5411\u30B0\u30E9\u30D5\u306B\u304A\u3044\u3066\u3001\u7B2C\
    2\u5F15\u6570\u3092true\u306B\u3059\u308C\u3070\u5165\u6B21\u6570\u3092\u5F97\u308B\
    \u3053\u3068\u304C\u3067\u304D\u308B\u3002\n     * @param v \u9802\u70B9\u756A\
    \u53F7\n     * @param isIn (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u3068\u304D\u306E\
    \u307F\u6709\u52B9)\u5165\u6B21\u6570\u3092\u53D6\u5F97\u3059\u308B\u304B (option,\
    \ default = false)\n     * @return int \u9802\u70B9v\u306E\u6307\u5B9A\u3057\u305F\
    \u5024\n     */\n    inline int degree(Vertex v, bool isIn = false){\n       \
    \ if(dir && isIn) return indegree[v];\n        return (int)connect[v].size();\n\
    \    }\n};\n#line 8 \"library/Tree/TreeDiamiter.hpp\"\n\ntemplate<typename CostType>\n\
    struct TreeDiamiter{\n    private:\n    Graph<CostType> &G;\n    vector<CostType>\
    \ dist;\n\n    void bfs(Vertex s){\n        queue<Vertex> que;\n        dist.assign(G.size(),\
    \ G.INF);\n        dist[s] = 0;\n        que.push(s);\n        while(!que.empty()){\n\
    \            Vertex v = que.front();\n            que.pop();\n            for(EdgeNum\
    \ &i : G.connect[v]){\n                Vertex u = G.edges[i].to;\n           \
    \     CostType w = G.edges[i].cost;\n                if(dist[v] + w < dist[u]){\n\
    \                    dist[u] = dist[v] + w;\n                    que.push(u);\n\
    \                }\n            }\n        }\n    }\n\n    public:\n    pair<Vertex,\
    \ Vertex> EdgeVertex;\n    CostType diamiter;\n\n    TreeDiamiter(Graph<CostType>\
    \ &G) : G(G), dist(G.size()){\n        bfs(0);\n        int v = 0;\n        CostType\
    \ d = 0;\n        for(int i = 0; i < G.size(); ++i){\n            if(dist[i] <\
    \ d){\n                v = i, d = dist[i];\n            }\n        }\n       \
    \ EdgeVertex.first = v;\n        bfs(v);\n        v = 0, d = 0;\n        for(int\
    \ i = 0; i < G.size(); ++i){\n            if(dist[i] < d){\n                v\
    \ = i, d = dist[i];\n            }\n        }\n        EdgeVertex.second = v;\n\
    \        diamiter = d;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Tree Diamiter - \u6728\u306E\u76F4\u5F84\n\
    \ */\n\n#include \"../Graph/GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct TreeDiamiter{\n    private:\n    Graph<CostType> &G;\n    vector<CostType>\
    \ dist;\n\n    void bfs(Vertex s){\n        queue<Vertex> que;\n        dist.assign(G.size(),\
    \ G.INF);\n        dist[s] = 0;\n        que.push(s);\n        while(!que.empty()){\n\
    \            Vertex v = que.front();\n            que.pop();\n            for(EdgeNum\
    \ &i : G.connect[v]){\n                Vertex u = G.edges[i].to;\n           \
    \     CostType w = G.edges[i].cost;\n                if(dist[v] + w < dist[u]){\n\
    \                    dist[u] = dist[v] + w;\n                    que.push(u);\n\
    \                }\n            }\n        }\n    }\n\n    public:\n    pair<Vertex,\
    \ Vertex> EdgeVertex;\n    CostType diamiter;\n\n    TreeDiamiter(Graph<CostType>\
    \ &G) : G(G), dist(G.size()){\n        bfs(0);\n        int v = 0;\n        CostType\
    \ d = 0;\n        for(int i = 0; i < G.size(); ++i){\n            if(dist[i] <\
    \ d){\n                v = i, d = dist[i];\n            }\n        }\n       \
    \ EdgeVertex.first = v;\n        bfs(v);\n        v = 0, d = 0;\n        for(int\
    \ i = 0; i < G.size(); ++i){\n            if(dist[i] < d){\n                v\
    \ = i, d = dist[i];\n            }\n        }\n        EdgeVertex.second = v;\n\
    \        diamiter = d;\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Tree/TreeDiamiter.hpp
  requiredBy: []
  timestamp: '2023-06-09 17:48:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/AOJ-GRL-5-A.test.cpp
documentation_of: library/Tree/TreeDiamiter.hpp
layout: document
redirect_from:
- /library/library/Tree/TreeDiamiter.hpp
- /library/library/Tree/TreeDiamiter.hpp.html
title: "Tree Diamiter - \u6728\u306E\u76F4\u5F84"
---
