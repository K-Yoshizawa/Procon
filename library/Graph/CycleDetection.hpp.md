---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Cycle Detection (Directed) - \u9589\u8DEF\u691C\u51FA\uFF08\u6709\
      \u5411\u30B0\u30E9\u30D5\uFF09"
    links: []
  bundledCode: "#line 2 \"library/Graph/CycleDetection.hpp\"\n\n/**\n * @brief Cycle\
    \ Detection (Directed) - \u9589\u8DEF\u691C\u51FA\uFF08\u6709\u5411\u30B0\u30E9\
    \u30D5\uFF09\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2\
    \ \"library/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n * @author\
    \ log K (lX57)\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n * @version 2.2\n * @date 2023-10-02\n */\n\n#line 12 \"library/Graph/GraphTemplate.hpp\"\
    \nusing namespace std;\n\nusing Vertex = int;\nusing EdgeID = int;\nusing EdgeIndex\
    \ = int;\n\ntemplate<typename CostType>\nstruct Edge{\n    EdgeID ID{-1};\n  \
    \  Vertex src, to;\n    CostType cost, cap;\n    EdgeIndex sidx, tidx;\n\n   \
    \ Edge() = default;\n    Edge(EdgeID ID, Vertex src, Vertex to, CostType cost,\
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
    \   return __IL[v].size();\n    }\n\n    inline EdgeSet<CostType> &get_edgeset(){\n\
    \        return __ES;\n    }\n\n    inline IncidentList<CostType> &get_incidentlist(){\n\
    \        return __IL;\n    }\n\n    inline vector<Edge<CostType>> &get_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        return __IL[v];\n \
    \   }\n\n    inline AdjacentList &get_adjacentlist(){\n        return __AL;\n\
    \    }\n\n    inline vector<Vertex> &get_adjacent(Vertex v){\n        assert(0\
    \ <= v && v < __CntVertex);\n        return __AL[v];\n    }\n\n    vector<Edge<CostType>>\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 11 \"library/Graph/CycleDetection.hpp\"\
    \n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u691C\u51FA\
    \u3092\u884C\u3046\u3002\n */\ntemplate<typename CostType>\nstruct CycleDetection{\n\
    \    vector<vector<Vertex>> cycle;\n    \n    private:\n    Graph<CostType> &G;\n\
    \    vector<Vertex> visited, history;\n    vector<Vertex> belong;\n    vector<Vertex>\
    \ tmp;\n\n    void dfs(int v){\n        visited[v] = 1;\n        history.push_back(v);\n\
    \        for(auto &e : G.get_edges(v)){\n            if(visited[e.to] == 2) continue;\n\
    \            if(visited[e.to] == 1){\n                for(int i = history.size()\
    \ - 1; ; --i){\n                    tmp.push_back(history[i]);\n             \
    \       belong[history[i]] = cycle.size();\n                    if(history[i]\
    \ == e.to) break;\n                }\n                cycle.push_back(tmp);\n\
    \                tmp.clear();\n            }\n            else{\n            \
    \    dfs(e.to);\n            }\n        }\n        history.pop_back();\n     \
    \   visited[v] = 2;\n    }\n\n    public:\n    CycleDetection(Graph<CostType>\
    \ &G) : G(G), visited(G.size(), 0), belong(G.size(), -1){\n        assert(G.directed());\n\
    \        for(int i = 0; i < G.size(); ++i){\n            if(!visited[i]) dfs(i);\n\
    \        }\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5G\u304C\u9589\u8DEF\
    \u3092\u6301\u3064\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool\
    \ exist(){\n        return cycle.size() > 0;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Cycle Detection (Directed) - \u9589\u8DEF\u691C\
    \u51FA\uFF08\u6709\u5411\u30B0\u30E9\u30D5\uFF09\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"GraphTemplate.hpp\"\n\n/**\n * @brief \u6709\
    \u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u691C\u51FA\u3092\u884C\u3046\u3002\
    \n */\ntemplate<typename CostType>\nstruct CycleDetection{\n    vector<vector<Vertex>>\
    \ cycle;\n    \n    private:\n    Graph<CostType> &G;\n    vector<Vertex> visited,\
    \ history;\n    vector<Vertex> belong;\n    vector<Vertex> tmp;\n\n    void dfs(int\
    \ v){\n        visited[v] = 1;\n        history.push_back(v);\n        for(auto\
    \ &e : G.get_edges(v)){\n            if(visited[e.to] == 2) continue;\n      \
    \      if(visited[e.to] == 1){\n                for(int i = history.size() - 1;\
    \ ; --i){\n                    tmp.push_back(history[i]);\n                  \
    \  belong[history[i]] = cycle.size();\n                    if(history[i] == e.to)\
    \ break;\n                }\n                cycle.push_back(tmp);\n         \
    \       tmp.clear();\n            }\n            else{\n                dfs(e.to);\n\
    \            }\n        }\n        history.pop_back();\n        visited[v] = 2;\n\
    \    }\n\n    public:\n    CycleDetection(Graph<CostType> &G) : G(G), visited(G.size(),\
    \ 0), belong(G.size(), -1){\n        assert(G.directed());\n        for(int i\
    \ = 0; i < G.size(); ++i){\n            if(!visited[i]) dfs(i);\n        }\n \
    \   }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5G\u304C\u9589\u8DEF\u3092\u6301\
    \u3064\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool exist(){\n\
    \        return cycle.size() > 0;\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/CycleDetection.hpp
  requiredBy: []
  timestamp: '2023-10-10 14:21:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Graph/CycleDetection.hpp
layout: document
redirect_from:
- /library/library/Graph/CycleDetection.hpp
- /library/library/Graph/CycleDetection.hpp.html
title: "Cycle Detection (Directed) - \u9589\u8DEF\u691C\u51FA\uFF08\u6709\u5411\u30B0\
  \u30E9\u30D5\uFF09"
---
