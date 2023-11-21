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
    document_title: "Tree Diamiter - \u6728\u306E\u76F4\u5F84"
    links: []
  bundledCode: "#line 2 \"library/Tree/TreeDiamiter.hpp\"\n\n/**\n * @file TreeDiamiter.hpp\n\
    \ * @author log K (lX57)\n * @brief Tree Diamiter - \u6728\u306E\u76F4\u5F84\n\
    \ * @version 1.1\n * @date 2023-08-30\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 2.2\n * @date 2023-10-02\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing Vertex = int;\nusing EdgeID = int;\nusing EdgeIndex = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    EdgeID ID{-1};\n    Vertex src{-1}, to{-1};\n \
    \   CostType cost, cap;\n    EdgeIndex sidx, tidx;\n\n    Edge() = default;\n\
    \    Edge(EdgeID ID, Vertex src, Vertex to, CostType cost, CostType cap, EdgeIndex\
    \ sidx, EdgeIndex tidx) :\n        ID(ID), src(src), to(to), cost(cost), cap(cap),\
    \ sidx(sidx), tidx(tidx){}\n\n    void print(){\n        cerr << \"Edge \" <<\
    \ ID << \" : (\" << src << \" -> \" << to << \"), Cost = \" << cost << \", Capacity\
    \ = \" << cap << \", Place = [\" << sidx << \", \" << tidx << \"]\" << endl;\n\
    \    }\n};\n\ntemplate<typename CostType>\nusing EdgeSet = vector<Edge<CostType>>;\n\
    template<typename CostType>\nusing IncidentList = vector<vector<Edge<CostType>>>;\n\
    using AdjacentList = vector<vector<Vertex>>;\n\ntemplate<typename CostType>\n\
    struct Graph{\n    protected:\n    int __CntVertex, __CntEdge;\n    bool __isDirected;\n\
    \    EdgeSet<CostType> __ES, __RES;\n    IncidentList<CostType> __IL;\n    AdjacentList\
    \ __AL;\n\n    public:\n    CostType INF;\n\n    Graph(int VertexSize, bool isDirected\
    \ = false) : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0),\
    \ __IL(VertexSize), __AL(VertexSize), INF(numeric_limits<CostType>::max() / 2){}\n\
    \n    Graph() = default;\n\n    void add(Vertex Source, Vertex To, CostType Cost\
    \ = 1){\n        assert(0 <= Source && Source < __CntVertex);\n        assert(0\
    \ <= To && To < __CntVertex);\n        EdgeIndex sidx = __IL[Source].size(), tidx\
    \ = __IL[To].size();\n        Edge<CostType> es{__CntEdge, Source, To, Cost, 1,\
    \ sidx, tidx};\n        Edge<CostType> et{__CntEdge, To, Source, Cost, 1, tidx,\
    \ sidx};\n        __ES.push_back(es);\n        __RES.push_back(et);\n        __IL[Source].push_back(es),\
    \ __AL[Source].push_back(To);\n        if(!__isDirected) __IL[To].push_back(et),\
    \ __AL[To].push_back(Source);\n        ++__CntEdge;\n    }\n\n    vector<vector<CostType>>\
    \ matrix(CostType NotAdjacent = numeric_limits<CostType>::max() / 2){\n      \
    \  vector ret(__CntVertex, vector(__CntVertex, NotAdjacent));\n        for(Vertex\
    \ v = 0; v < __CntVertex; ++v){\n            ret[v][v] = 0;\n            for(auto\
    \ e : __IL[v]){\n                ret[v][e.to] = e.cost;\n            }\n     \
    \   }\n        return ret;\n    }\n\n    inline int vsize(){\n        return __CntVertex;\n\
    \    }\n\n    inline int esize(){\n        return __CntEdge;\n    }\n\n    inline\
    \ int incsize(Vertex v){\n        return __IL[v].size();\n    }\n\n    bool directed(){\n\
    \        return __isDirected;\n    }\n\n    inline EdgeSet<CostType> &get_edgeset(){\n\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 12 \"library/Tree/TreeDiamiter.hpp\"\
    \n\ntemplate<typename CostType>\nstruct TreeDiamiter{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<CostType> dist;\n\n    void bfs(Vertex s){\n        queue<Vertex>\
    \ que;\n        dist.assign(G.size(), G.INF);\n        dist[s] = 0;\n        que.push(s);\n\
    \        while(!que.empty()){\n            Vertex v = que.front();\n         \
    \   que.pop();\n            for(EdgeNum &i : G.connect[v]){\n                Vertex\
    \ u = G.edges[i].to;\n                CostType w = G.edges[i].cost;\n        \
    \        if(dist[v] + w < dist[u]){\n                    dist[u] = dist[v] + w;\n\
    \                    que.push(u);\n                }\n            }\n        }\n\
    \    }\n\n    void build(){\n        bfs(0);\n        int v = 0;\n        CostType\
    \ d = 0;\n        for(int i = 0; i < G.size(); ++i){\n            if(dist[i] >\
    \ d){\n                v = i, d = dist[i];\n            }\n        }\n       \
    \ EdgeVertex.first = v;\n        bfs(v);\n        v = 0, d = 0;\n        for(int\
    \ i = 0; i < G.size(); ++i){\n            if(dist[i] > d){\n                v\
    \ = i, d = dist[i];\n            }\n        }\n        EdgeVertex.second = v;\n\
    \        diamiter = d;\n    }\n\n    public:\n    pair<Vertex, Vertex> EdgeVertex;\n\
    \    CostType diamiter;\n\n    TreeDiamiter(Tree<CostType> &T) : G(T), dist(T.size()){\n\
    \        build();\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file TreeDiamiter.hpp\n * @author log K (lX57)\n\
    \ * @brief Tree Diamiter - \u6728\u306E\u76F4\u5F84\n * @version 1.1\n * @date\
    \ 2023-08-30\n */\n\n#include \"../Graph/GraphTemplate.hpp\"\n\ntemplate<typename\
    \ CostType>\nstruct TreeDiamiter{\n    private:\n    Graph<CostType> &G;\n   \
    \ vector<CostType> dist;\n\n    void bfs(Vertex s){\n        queue<Vertex> que;\n\
    \        dist.assign(G.size(), G.INF);\n        dist[s] = 0;\n        que.push(s);\n\
    \        while(!que.empty()){\n            Vertex v = que.front();\n         \
    \   que.pop();\n            for(EdgeNum &i : G.connect[v]){\n                Vertex\
    \ u = G.edges[i].to;\n                CostType w = G.edges[i].cost;\n        \
    \        if(dist[v] + w < dist[u]){\n                    dist[u] = dist[v] + w;\n\
    \                    que.push(u);\n                }\n            }\n        }\n\
    \    }\n\n    void build(){\n        bfs(0);\n        int v = 0;\n        CostType\
    \ d = 0;\n        for(int i = 0; i < G.size(); ++i){\n            if(dist[i] >\
    \ d){\n                v = i, d = dist[i];\n            }\n        }\n       \
    \ EdgeVertex.first = v;\n        bfs(v);\n        v = 0, d = 0;\n        for(int\
    \ i = 0; i < G.size(); ++i){\n            if(dist[i] > d){\n                v\
    \ = i, d = dist[i];\n            }\n        }\n        EdgeVertex.second = v;\n\
    \        diamiter = d;\n    }\n\n    public:\n    pair<Vertex, Vertex> EdgeVertex;\n\
    \    CostType diamiter;\n\n    TreeDiamiter(Tree<CostType> &T) : G(T), dist(T.size()){\n\
    \        build();\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Tree/TreeDiamiter.hpp
  requiredBy: []
  timestamp: '2023-11-21 13:10:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Tree/TreeDiamiter.hpp
layout: document
redirect_from:
- /library/library/Tree/TreeDiamiter.hpp
- /library/library/Tree/TreeDiamiter.hpp.html
title: "Tree Diamiter - \u6728\u306E\u76F4\u5F84"
---
