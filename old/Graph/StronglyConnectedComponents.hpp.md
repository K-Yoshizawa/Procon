---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: old/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\
      \u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"old/Graph/StronglyConnectedComponents.hpp\"\n\n/**\n * @brief\
    \ Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n\
    \ */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"old/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 2.2\n * @date 2023-10-02\n */\n\n#line 12 \"old/Graph/GraphTemplate.hpp\"\n\
    using namespace std;\n\nusing Vertex = int;\nusing EdgeID = int;\nusing EdgeIndex\
    \ = int;\n\ntemplate<typename CostType>\nstruct Edge{\n    EdgeID ID{-1};\n  \
    \  Vertex src{-1}, to{-1};\n    CostType cost, cap;\n    EdgeIndex sidx, tidx;\n\
    \n    Edge() = default;\n    Edge(EdgeID ID, Vertex src, Vertex to, CostType cost,\
    \ CostType cap, EdgeIndex sidx, EdgeIndex tidx) :\n        ID(ID), src(src), to(to),\
    \ cost(cost), cap(cap), sidx(sidx), tidx(tidx){}\n\n    void print(){\n      \
    \  cerr << \"Edge \" << ID << \" : (\" << src << \" -> \" << to << \"), Cost =\
    \ \" << cost << \", Capacity = \" << cap << \", Place = [\" << sidx << \", \"\
    \ << tidx << \"]\" << endl;\n    }\n};\n\ntemplate<typename CostType>\nusing EdgeSet\
    \ = vector<Edge<CostType>>;\ntemplate<typename CostType>\nusing IncidentList =\
    \ vector<vector<Edge<CostType>>>;\nusing AdjacentList = vector<vector<Vertex>>;\n\
    \ntemplate<typename CostType>\nstruct Graph{\n    protected:\n    int __CntVertex,\
    \ __CntEdge;\n    bool __isDirected;\n    EdgeSet<CostType> __ES, __RES;\n   \
    \ IncidentList<CostType> __IL;\n    AdjacentList __AL;\n\n    public:\n    CostType\
    \ INF;\n\n    Graph(int VertexSize, bool isDirected = false) : __CntVertex(VertexSize),\
    \ __isDirected(isDirected), __CntEdge(0), __IL(VertexSize), __AL(VertexSize),\
    \ INF(numeric_limits<CostType>::max() / 2){}\n\n    Graph() = default;\n\n   \
    \ void add(Vertex Source, Vertex To, CostType Cost = 1){\n        assert(0 <=\
    \ Source && Source < __CntVertex);\n        assert(0 <= To && To < __CntVertex);\n\
    \        EdgeIndex sidx = __IL[Source].size(), tidx = __IL[To].size();\n     \
    \   Edge<CostType> es{__CntEdge, Source, To, Cost, 1, sidx, tidx};\n        Edge<CostType>\
    \ et{__CntEdge, To, Source, Cost, 1, tidx, sidx};\n        __ES.push_back(es);\n\
    \        __RES.push_back(et);\n        __IL[Source].push_back(es), __AL[Source].push_back(To);\n\
    \        if(!__isDirected) __IL[To].push_back(et), __AL[To].push_back(Source);\n\
    \        ++__CntEdge;\n    }\n\n    vector<vector<CostType>> matrix(CostType NotAdjacent\
    \ = numeric_limits<CostType>::max() / 2){\n        vector ret(__CntVertex, vector(__CntVertex,\
    \ NotAdjacent));\n        for(Vertex v = 0; v < __CntVertex; ++v){\n         \
    \   ret[v][v] = 0;\n            for(auto e : __IL[v]){\n                ret[v][e.to]\
    \ = e.cost;\n            }\n        }\n        return ret;\n    }\n\n    inline\
    \ int vsize(){\n        return __CntVertex;\n    }\n\n    inline int esize(){\n\
    \        return __CntEdge;\n    }\n\n    inline int incsize(Vertex v){\n     \
    \   return __IL[v].size();\n    }\n\n    bool directed(){\n        return __isDirected;\n\
    \    }\n\n    inline EdgeSet<CostType> &get_edgeset(){\n        return __ES;\n\
    \    }\n\n    inline IncidentList<CostType> &get_incidentlist(){\n        return\
    \ __IL;\n    }\n\n    inline vector<Edge<CostType>> &get_incident(Vertex v){\n\
    \        assert(0 <= v && v < __CntVertex);\n        return __IL[v];\n    }\n\n\
    \    inline AdjacentList &get_adjacentlist(){\n        return __AL;\n    }\n\n\
    \    inline vector<Vertex> &get_adjacent(Vertex v){\n        assert(0 <= v &&\
    \ v < __CntVertex);\n        return __AL[v];\n    }\n\n    vector<Edge<CostType>>\
    \ operator[](Vertex v){\n        return get_incident(v);\n    }\n\n    void print_edgeset(bool\
    \ OneIndex = true){\n        for(int e = 0; e < __CntEdge; ++e){\n           \
    \ cout << e + OneIndex << \" : (\" << __ES[e].from + OneIndex << (__isDirected\
    \ ? \" -> \" : \" <-> \") << __ES[e].to + OneIndex << \") = \" << __ES[e].cost\
    \ << \" (\" << __ES[e].cap << \")\" << endl;\n        }\n    }\n\n    void print_incidentlist(bool\
    \ OneIndex = true){\n        for(int i = 0; i < __CntVertex; ++i){\n         \
    \   cout << i + OneIndex << \" :\";\n            for(int j = 0; j < __IL[i].size();\
    \ ++j){\n                cout << \" (\" << __IL[i][j].to << \" / \" << __IL[i][j].cost\
    \ << \", \" << __IL[i][j].cap << \")\";\n            }\n            cout << endl;\n\
    \        }\n    }\n\n    void print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max()\
    \ / 2, bool DisplayINF = true){\n        auto mat = matrix(NotAdjacent);\n   \
    \     for(int i = 0; i < __CntVertex; ++i){\n            cout << (DisplayINF &&\
    \ mat[i][0] == NotAdjacent ? \"INF\" : to_string(mat[i][0]));\n            for(int\
    \ j = 1; j < __CntVertex; ++j){\n                cout << \" \" << (DisplayINF\
    \ && mat[i][j] == NotAdjacent ? \"INF\" : to_string(mat[i][j]));\n           \
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 11 \"old/Graph/StronglyConnectedComponents.hpp\"\
    \n\n/**\n * @brief  \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u3092\u884C\u3046\
    \u3002\n */\ntemplate<typename CostType>\nstruct StronglyConnectedComponents{\n\
    \    vector<int> belong; // \u9802\u70B9\u304C\u3069\u306E\u5F37\u9023\u7D50\u6210\
    \u5206\u306B\u6240\u5C5E\u3059\u308B\u304B\n    vector<vector<Vertex>> sc; //\
    \ \u5404\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u9802\u70B9\
    \n\n    private:\n    Graph<CostType> &G, rG;\n    vector<int> order, visited;\n\
    \    vector<int> tmp;\n\n    void dfs(int v){\n        visited[v] = 1;\n     \
    \   for(auto &e : G.get_edges(v)){\n            if(visited[e.to] == 0) dfs(e.to);\n\
    \        }\n        order.push_back(v);\n    }\n\n    void rdfs(int v, int k){\n\
    \        visited[v] = 0;\n        belong[v] = k;\n        tmp.push_back(v);\n\
    \        for(auto &e : rG.get_edges(v)){\n            if(visited[e.to] == 1) rdfs(e.to,\
    \ k);\n        }\n    }\n\n    public:\n    StronglyConnectedComponents(Graph<CostType>\
    \ &G) : G(G){\n        rG = G.reverse();\n        visited.resize(G.size(), 0);\n\
    \        belong.resize(G.size(), -1);\n        for(int i = 0; i < G.size(); ++i){\n\
    \            if(visited[i] == 0) dfs(i);\n        }\n        int k = 0;\n    \
    \    for(int i = order.size() - 1; i >= 0; --i){\n            if(visited[order[i]]\
    \ == 1){\n                rdfs(order[i], k++);\n                sc.push_back(tmp);\n\
    \                tmp.clear();\n            }\n        }\n    }\n\n    /**\n  \
    \   * @brief  2\u3064\u306E\u9802\u70B9\u304C\u540C\u3058\u5F37\u9023\u7D50\u6210\
    \u5206\u306B\u6240\u5C5E\u3059\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\
    \n     * @param  u: \u5224\u5B9A\u3057\u305F\u3044\u9802\u70B9u\n     * @param\
    \  v: \u5224\u5B9A\u3057\u305F\u3044\u9802\u70B9v\n     * @retval \u540C\u3058\
    \u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u306A\u3089true\u3001\
    \u305D\u3046\u3067\u306A\u3051\u308C\u3070false\n     */\n    bool same(Vertex\
    \ u, Vertex v){\n        return belong[u] == belong[v];\n    }\n\n    /**\n  \
    \   * @brief \u9802\u70B9v\u304C\u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\
    \u3092\u8FD4\u3059\u3002\n     * @param v \u8ABF\u3079\u305F\u3044\u9802\u70B9\
    v\n     * @return vector<Vertex> \u9802\u70B9v\u304C\u5C5E\u3059\u308B\u5F37\u9023\
    \u7D50\u6210\u5206\n     */\n    vector<Vertex> get(Vertex v){\n        return\
    \ sc[belong[v]];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Strongly Connected Components - \u5F37\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\n */\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#include \"GraphTemplate.hpp\"\n\n/**\n * @brief  \u5F37\u9023\u7D50\
    \u6210\u5206\u5206\u89E3\u3092\u884C\u3046\u3002\n */\ntemplate<typename CostType>\n\
    struct StronglyConnectedComponents{\n    vector<int> belong; // \u9802\u70B9\u304C\
    \u3069\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u304B\
    \n    vector<vector<Vertex>> sc; // \u5404\u5F37\u9023\u7D50\u6210\u5206\u306B\
    \u6240\u5C5E\u3059\u308B\u9802\u70B9\n\n    private:\n    Graph<CostType> &G,\
    \ rG;\n    vector<int> order, visited;\n    vector<int> tmp;\n\n    void dfs(int\
    \ v){\n        visited[v] = 1;\n        for(auto &e : G.get_edges(v)){\n     \
    \       if(visited[e.to] == 0) dfs(e.to);\n        }\n        order.push_back(v);\n\
    \    }\n\n    void rdfs(int v, int k){\n        visited[v] = 0;\n        belong[v]\
    \ = k;\n        tmp.push_back(v);\n        for(auto &e : rG.get_edges(v)){\n \
    \           if(visited[e.to] == 1) rdfs(e.to, k);\n        }\n    }\n\n    public:\n\
    \    StronglyConnectedComponents(Graph<CostType> &G) : G(G){\n        rG = G.reverse();\n\
    \        visited.resize(G.size(), 0);\n        belong.resize(G.size(), -1);\n\
    \        for(int i = 0; i < G.size(); ++i){\n            if(visited[i] == 0) dfs(i);\n\
    \        }\n        int k = 0;\n        for(int i = order.size() - 1; i >= 0;\
    \ --i){\n            if(visited[order[i]] == 1){\n                rdfs(order[i],\
    \ k++);\n                sc.push_back(tmp);\n                tmp.clear();\n  \
    \          }\n        }\n    }\n\n    /**\n     * @brief  2\u3064\u306E\u9802\u70B9\
    \u304C\u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\
    \u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     * @param  u: \u5224\u5B9A\u3057\
    \u305F\u3044\u9802\u70B9u\n     * @param  v: \u5224\u5B9A\u3057\u305F\u3044\u9802\
    \u70B9v\n     * @retval \u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\
    \u5C5E\u3059\u308B\u306A\u3089true\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070\
    false\n     */\n    bool same(Vertex u, Vertex v){\n        return belong[u] ==\
    \ belong[v];\n    }\n\n    /**\n     * @brief \u9802\u70B9v\u304C\u5C5E\u3059\u308B\
    \u5F37\u9023\u7D50\u6210\u5206\u3092\u8FD4\u3059\u3002\n     * @param v \u8ABF\
    \u3079\u305F\u3044\u9802\u70B9v\n     * @return vector<Vertex> \u9802\u70B9v\u304C\
    \u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\n     */\n    vector<Vertex>\
    \ get(Vertex v){\n        return sc[belong[v]];\n    }\n};"
  dependsOn:
  - old/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: old/Graph/StronglyConnectedComponents.hpp
  requiredBy: []
  timestamp: '2024-01-09 23:25:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/Graph/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/old/Graph/StronglyConnectedComponents.hpp
- /library/old/Graph/StronglyConnectedComponents.hpp.html
title: "Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
