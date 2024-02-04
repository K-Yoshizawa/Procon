---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: old/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: old/Graph/PrimalDual.hpp
    title: "Primal Dual - \u6700\u5C0F\u8CBB\u7528\u6D41"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_old/AOJ-GRL-1-A.test.cpp
    title: verify_old/AOJ-GRL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_old/AOJ-GRL-1-B-Dijkstra.test.cpp
    title: verify_old/AOJ-GRL-1-B-Dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_old/AOJ-GRL-6-B.test.cpp
    title: verify_old/AOJ-GRL-6-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
    links: []
  bundledCode: "#line 1 \"old/Graph/Dijkstra.hpp\"\n/**\n * @file Dijkstra.hpp\n *\
    \ @author log_K (lX57)\n * @brief Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\
    \u8DDD\u96E2\n * @version 2.2\n * @date 2023-10-02\n */\n\n#line 2 \"old/Graph/GraphTemplate.hpp\"\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"old/Graph/Dijkstra.hpp\"\
    \n\ntemplate<typename CostType>\nstruct Dijkstra{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<CostType> __Dist, __Potential;\n    vector<Vertex> __PrevVertex;\n\
    \    vector<Edge<CostType>> __PrevEdge;\n    Vertex __Start;\n\n    void __solve(){\n\
    \        __Dist.assign(G.vsize(), G.INF);\n        __PrevVertex.assign(G.vsize(),\
    \ -1);\n        __PrevEdge.assign(G.vsize(), Edge<CostType>());\n        using\
    \ p = pair<CostType, Vertex>;\n        priority_queue<p, vector<p>, greater<p>>\
    \ que;\n        que.emplace(__Potential[__Start], __Start);\n        __Dist[__Start]\
    \ = __Potential[__Start];\n        while(que.size()){\n            auto [d, v]\
    \ = que.top(); que.pop();\n            if(__Dist[v] < d) continue;\n         \
    \   for(auto e : G.get_incident(v)){\n                if(e.cap > 0 && d + e.cost\
    \ + __Potential[e.src] - __Potential[e.to] < __Dist[e.to]){\n                \
    \    __Dist[e.to] = d + e.cost + __Potential[e.src] - __Potential[e.to];\n   \
    \                 __PrevVertex[e.to] = v;\n                    __PrevEdge[e.to]\
    \ = e;\n                    que.emplace(__Dist[e.to], e.to);\n               \
    \ }\n            }\n        }\n        for(Vertex i = 0; i < G.vsize(); ++i){\n\
    \            if(__Dist[i] != G.INF) __Dist[i] += __Potential[i] - __Potential[__Start];\n\
    \        }\n    }\n\n    public:\n    Dijkstra(Graph<CostType> &G) : G(G), __Dist(G.vsize()),\
    \ __Potential(G.vsize(), 0), __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Start(-1){}\n\
    \    \n    Dijkstra(Graph<CostType> &G, Vertex Start) : G(G), __Dist(G.vsize()),\
    \ __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Potential(G.vsize(), 0), __Start(Start){\n\
    \        __solve();\n    }\n\n    void update_potential(vector<CostType> Potential){\n\
    \        assert(__Potential.size() == Potential.size());\n        __Potential\
    \ = Potential;\n    }\n\n    void rebuild(){\n        __solve();\n    }\n\n  \
    \  void build(Vertex Start){\n        assert(0 <= Start && Start < G.vsize());\n\
    \        if(Start != __Start){\n            __Start = Start;\n            __solve();\n\
    \        }\n    }\n\n    vector<CostType> &all(Vertex Start){\n        assert(0\
    \ <= Start && Start < G.vsize());\n        if(Start != __Start) build(Start);\n\
    \        return __Dist;\n    }\n\n    CostType dist(Vertex Start, Vertex Goal){\n\
    \        assert(0 <= Start && Start < G.vsize());\n        assert(0 <= Goal &&\
    \ Goal < G.vsize());\n        if(Start != __Start){\n            __Start = Start;\n\
    \            __solve();\n        }\n        return __Dist[Goal];\n    }\n\n  \
    \  EdgeSet<CostType> restore_edge(Vertex Goal){\n        EdgeSet<CostType> ret;\n\
    \        Vertex now = Goal;\n        while(__PrevEdge[now].ID != -1){\n      \
    \      ret.push_back(__PrevEdge[now]);\n            now = __PrevEdge[now].src;\n\
    \        }\n        reverse(ret.begin(), ret.end());\n        return ret;\n  \
    \  }\n\n    void print(bool DisplayINF = true, char Delimiter = ' '){\n      \
    \  cout << (DisplayINF && __Dist[0] == G.INF ? \"INF\" : to_string(__Dist[0]));\n\
    \        for(int i = 1; i < (int)__Dist.size(); ++i){\n            cout << Delimiter\
    \ << (DisplayINF && __Dist[i] == G.INF ? \"INF\" : to_string(__Dist[i]));\n  \
    \      }\n        cout << endl;\n    }\n};\n"
  code: "/**\n * @file Dijkstra.hpp\n * @author log_K (lX57)\n * @brief Dijkstra -\
    \ \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2\n * @version 2.2\n * @date\
    \ 2023-10-02\n */\n\n#include \"GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct Dijkstra{\n    private:\n    Graph<CostType> &G;\n    vector<CostType>\
    \ __Dist, __Potential;\n    vector<Vertex> __PrevVertex;\n    vector<Edge<CostType>>\
    \ __PrevEdge;\n    Vertex __Start;\n\n    void __solve(){\n        __Dist.assign(G.vsize(),\
    \ G.INF);\n        __PrevVertex.assign(G.vsize(), -1);\n        __PrevEdge.assign(G.vsize(),\
    \ Edge<CostType>());\n        using p = pair<CostType, Vertex>;\n        priority_queue<p,\
    \ vector<p>, greater<p>> que;\n        que.emplace(__Potential[__Start], __Start);\n\
    \        __Dist[__Start] = __Potential[__Start];\n        while(que.size()){\n\
    \            auto [d, v] = que.top(); que.pop();\n            if(__Dist[v] < d)\
    \ continue;\n            for(auto e : G.get_incident(v)){\n                if(e.cap\
    \ > 0 && d + e.cost + __Potential[e.src] - __Potential[e.to] < __Dist[e.to]){\n\
    \                    __Dist[e.to] = d + e.cost + __Potential[e.src] - __Potential[e.to];\n\
    \                    __PrevVertex[e.to] = v;\n                    __PrevEdge[e.to]\
    \ = e;\n                    que.emplace(__Dist[e.to], e.to);\n               \
    \ }\n            }\n        }\n        for(Vertex i = 0; i < G.vsize(); ++i){\n\
    \            if(__Dist[i] != G.INF) __Dist[i] += __Potential[i] - __Potential[__Start];\n\
    \        }\n    }\n\n    public:\n    Dijkstra(Graph<CostType> &G) : G(G), __Dist(G.vsize()),\
    \ __Potential(G.vsize(), 0), __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Start(-1){}\n\
    \    \n    Dijkstra(Graph<CostType> &G, Vertex Start) : G(G), __Dist(G.vsize()),\
    \ __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Potential(G.vsize(), 0), __Start(Start){\n\
    \        __solve();\n    }\n\n    void update_potential(vector<CostType> Potential){\n\
    \        assert(__Potential.size() == Potential.size());\n        __Potential\
    \ = Potential;\n    }\n\n    void rebuild(){\n        __solve();\n    }\n\n  \
    \  void build(Vertex Start){\n        assert(0 <= Start && Start < G.vsize());\n\
    \        if(Start != __Start){\n            __Start = Start;\n            __solve();\n\
    \        }\n    }\n\n    vector<CostType> &all(Vertex Start){\n        assert(0\
    \ <= Start && Start < G.vsize());\n        if(Start != __Start) build(Start);\n\
    \        return __Dist;\n    }\n\n    CostType dist(Vertex Start, Vertex Goal){\n\
    \        assert(0 <= Start && Start < G.vsize());\n        assert(0 <= Goal &&\
    \ Goal < G.vsize());\n        if(Start != __Start){\n            __Start = Start;\n\
    \            __solve();\n        }\n        return __Dist[Goal];\n    }\n\n  \
    \  EdgeSet<CostType> restore_edge(Vertex Goal){\n        EdgeSet<CostType> ret;\n\
    \        Vertex now = Goal;\n        while(__PrevEdge[now].ID != -1){\n      \
    \      ret.push_back(__PrevEdge[now]);\n            now = __PrevEdge[now].src;\n\
    \        }\n        reverse(ret.begin(), ret.end());\n        return ret;\n  \
    \  }\n\n    void print(bool DisplayINF = true, char Delimiter = ' '){\n      \
    \  cout << (DisplayINF && __Dist[0] == G.INF ? \"INF\" : to_string(__Dist[0]));\n\
    \        for(int i = 1; i < (int)__Dist.size(); ++i){\n            cout << Delimiter\
    \ << (DisplayINF && __Dist[i] == G.INF ? \"INF\" : to_string(__Dist[i]));\n  \
    \      }\n        cout << endl;\n    }\n};"
  dependsOn:
  - old/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: old/Graph/Dijkstra.hpp
  requiredBy:
  - old/Graph/PrimalDual.hpp
  timestamp: '2024-01-09 23:25:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_old/AOJ-GRL-1-B-Dijkstra.test.cpp
  - verify_old/AOJ-GRL-6-B.test.cpp
  - verify_old/AOJ-GRL-1-A.test.cpp
documentation_of: old/Graph/Dijkstra.hpp
layout: document
redirect_from:
- /library/old/Graph/Dijkstra.hpp
- /library/old/Graph/Dijkstra.hpp.html
title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
---
