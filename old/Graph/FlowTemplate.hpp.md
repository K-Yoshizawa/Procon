---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: old/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: old/Graph/BipartiteMatching.hpp
    title: "Bipartite Matching - \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\
      \u30C3\u30C1\u30F3\u30B0"
  - icon: ':heavy_check_mark:'
    path: old/Graph/Dinic.hpp
    title: "Dinic - \u6700\u5927\u6D41"
  - icon: ':heavy_check_mark:'
    path: old/Graph/FordFulkerson.hpp
    title: "Ford-Fulkerson - \u6700\u5927\u6D41"
  - icon: ':heavy_check_mark:'
    path: old/Graph/PrimalDual.hpp
    title: "Primal Dual - \u6700\u5C0F\u8CBB\u7528\u6D41"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_old/AOJ-GRL-6-A-Dinic.test.cpp
    title: verify_old/AOJ-GRL-6-A-Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_old/AOJ-GRL-6-A.test.cpp
    title: verify_old/AOJ-GRL-6-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_old/AOJ-GRL-6-B.test.cpp
    title: verify_old/AOJ-GRL-6-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_old/AOJ-GRL-7-A.test.cpp
    title: verify_old/AOJ-GRL-7-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Flow Template - \u30D5\u30ED\u30FC\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8"
    links: []
  bundledCode: "#line 2 \"old/Graph/FlowTemplate.hpp\"\n\n/**\n * @file FlowTemplate.hpp\n\
    \ * @author log K (lX57)\n * @brief Flow Template - \u30D5\u30ED\u30FC\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\n * @version 1.0\n * @date 2023-09-29\n */\n\n#line 2\
    \ \"old/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n * @author\
    \ log K (lX57)\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n * @version 2.2\n * @date 2023-10-02\n */\n\n#include <bits/stdc++.h>\n\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 12 \"old/Graph/FlowTemplate.hpp\"\
    \n\n#define LOGK_FLOW\n\ntemplate<typename CostType>\nstruct Flow : public Graph<CostType>{\n\
    \    using Graph<CostType>::Graph;\n\n    vector<vector<int>> __Rev;\n\n    public:\n\
    \    void add(Vertex Source, Vertex To, CostType Capacity = 1, CostType Cost =\
    \ 1){\n        assert(0 <= Source && Source < this->__CntVertex);\n        assert(0\
    \ <= To && To < this->__CntVertex);\n        EdgeIndex sidx = this->__IL[Source].size(),\
    \ tidx = this->__IL[To].size();\n        Edge<CostType> es(this->__CntEdge, Source,\
    \ To, Cost, Capacity, sidx, tidx);\n        Edge<CostType> et(this->__CntEdge,\
    \ To, Source, -Cost, 0, tidx, sidx);\n        this->__ES.push_back(es);\n    \
    \    this->__RES.push_back(et);\n        this->__IL[Source].push_back(es), this->__AL[Source].push_back(To);\n\
    \        this->__IL[To].push_back(et), this->__AL[To].push_back(Source);\n   \
    \     ++this->__CntEdge;\n        if(__Rev.empty()) __Rev.resize(this->__CntVertex);\n\
    \        __Rev[Source].push_back(0), __Rev[To].push_back(1);\n    }\n\n    void\
    \ update(Vertex Source, EdgeIndex Index, CostType Amount){\n        Vertex To\
    \ = this->__IL[Source][Index].to;\n        EdgeIndex RIndex = this->__IL[Source][Index].tidx;\n\
    \        EdgeID eid = this->__IL[Source][Index].ID;\n        this->__IL[Source][Index].cap\
    \ -= Amount;\n        this->__IL[To][RIndex].cap += Amount;\n        if(this->__ES[eid].src\
    \ != Source) Amount *= -1;\n        this->__ES[eid].cap -= Amount;\n        this->__RES[eid].cap\
    \ += Amount;\n    }\n\n    EdgeSet<CostType> restore_cut(Vertex Source){\n   \
    \     EdgeSet<CostType> ret;\n        vector<int> arrive(this->vsize(), 0);\n\
    \        queue<Vertex> que; que.push(Source);\n        while(que.size()){\n  \
    \          Vertex now = que.front(); que.pop();\n            if(arrive[now]) continue;\
    \ arrive[now] = 1;\n            for(auto e : this->get_incident(now)){\n     \
    \           if(e.cap <= 0 || arrive[e.to]) continue;\n                que.push(e.to);\n\
    \            }\n        }\n        for(int i = 0; i < this->esize(); ++i){\n \
    \           Edge<CostType> e = this->__ES[i], re = this->__RES[i];\n         \
    \   // cerr << \"[\" << e.src << \", \" << e.to << \"] Cap = \" << e.cap << endl;\n\
    \            if(e.cap == 0 && arrive[e.src] && !arrive[e.to]){\n             \
    \   Edge<CostType> ne = e;\n                ne.cap = re.cap;\n               \
    \ ret.push_back(ne);\n            }\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file FlowTemplate.hpp\n * @author log K (lX57)\n\
    \ * @brief Flow Template - \u30D5\u30ED\u30FC\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @version 1.0\n * @date 2023-09-29\n */\n\n#include \"GraphTemplate.hpp\"\n\
    \n#define LOGK_FLOW\n\ntemplate<typename CostType>\nstruct Flow : public Graph<CostType>{\n\
    \    using Graph<CostType>::Graph;\n\n    vector<vector<int>> __Rev;\n\n    public:\n\
    \    void add(Vertex Source, Vertex To, CostType Capacity = 1, CostType Cost =\
    \ 1){\n        assert(0 <= Source && Source < this->__CntVertex);\n        assert(0\
    \ <= To && To < this->__CntVertex);\n        EdgeIndex sidx = this->__IL[Source].size(),\
    \ tidx = this->__IL[To].size();\n        Edge<CostType> es(this->__CntEdge, Source,\
    \ To, Cost, Capacity, sidx, tidx);\n        Edge<CostType> et(this->__CntEdge,\
    \ To, Source, -Cost, 0, tidx, sidx);\n        this->__ES.push_back(es);\n    \
    \    this->__RES.push_back(et);\n        this->__IL[Source].push_back(es), this->__AL[Source].push_back(To);\n\
    \        this->__IL[To].push_back(et), this->__AL[To].push_back(Source);\n   \
    \     ++this->__CntEdge;\n        if(__Rev.empty()) __Rev.resize(this->__CntVertex);\n\
    \        __Rev[Source].push_back(0), __Rev[To].push_back(1);\n    }\n\n    void\
    \ update(Vertex Source, EdgeIndex Index, CostType Amount){\n        Vertex To\
    \ = this->__IL[Source][Index].to;\n        EdgeIndex RIndex = this->__IL[Source][Index].tidx;\n\
    \        EdgeID eid = this->__IL[Source][Index].ID;\n        this->__IL[Source][Index].cap\
    \ -= Amount;\n        this->__IL[To][RIndex].cap += Amount;\n        if(this->__ES[eid].src\
    \ != Source) Amount *= -1;\n        this->__ES[eid].cap -= Amount;\n        this->__RES[eid].cap\
    \ += Amount;\n    }\n\n    EdgeSet<CostType> restore_cut(Vertex Source){\n   \
    \     EdgeSet<CostType> ret;\n        vector<int> arrive(this->vsize(), 0);\n\
    \        queue<Vertex> que; que.push(Source);\n        while(que.size()){\n  \
    \          Vertex now = que.front(); que.pop();\n            if(arrive[now]) continue;\
    \ arrive[now] = 1;\n            for(auto e : this->get_incident(now)){\n     \
    \           if(e.cap <= 0 || arrive[e.to]) continue;\n                que.push(e.to);\n\
    \            }\n        }\n        for(int i = 0; i < this->esize(); ++i){\n \
    \           Edge<CostType> e = this->__ES[i], re = this->__RES[i];\n         \
    \   // cerr << \"[\" << e.src << \", \" << e.to << \"] Cap = \" << e.cap << endl;\n\
    \            if(e.cap == 0 && arrive[e.src] && !arrive[e.to]){\n             \
    \   Edge<CostType> ne = e;\n                ne.cap = re.cap;\n               \
    \ ret.push_back(ne);\n            }\n        }\n        return ret;\n    }\n};"
  dependsOn:
  - old/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: old/Graph/FlowTemplate.hpp
  requiredBy:
  - old/Graph/PrimalDual.hpp
  - old/Graph/Dinic.hpp
  - old/Graph/FordFulkerson.hpp
  - old/Graph/BipartiteMatching.hpp
  timestamp: '2024-01-09 23:25:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_old/AOJ-GRL-6-A-Dinic.test.cpp
  - verify_old/AOJ-GRL-7-A.test.cpp
  - verify_old/AOJ-GRL-6-A.test.cpp
  - verify_old/AOJ-GRL-6-B.test.cpp
documentation_of: old/Graph/FlowTemplate.hpp
layout: document
redirect_from:
- /library/old/Graph/FlowTemplate.hpp
- /library/old/Graph/FlowTemplate.hpp.html
title: "Flow Template - \u30D5\u30ED\u30FC\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
