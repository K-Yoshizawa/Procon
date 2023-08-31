---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-1-A.test.cpp
    title: verify_latest/AOJ-GRL-1-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
    links: []
  bundledCode: "#line 1 \"latest/Graph/Dijkstra.hpp\"\n/**\n * @file Dijkstra.hpp\n\
    \ * @author log_K (lX57)\n * @brief Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\
    \u8DDD\u96E2\n * @version 2.0\n * @date 2023-08-31\n */\n\n#line 2 \"latest/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 2.0\n * @date 2023-08-31\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing Vertex = int;\nusing EdgeID = int;\n\ntemplate<typename CostType>\nstruct\
    \ Edge{\n    Vertex from, to;\n    CostType cost;\n\n    Edge(Vertex from, Vertex\
    \ to, CostType cost) : from(from), to(to), cost(cost){}\n\n    Vertex getto(Vertex\
    \ v){\n        assert(v == from || v == to);\n        return from ^ to ^ v;\n\
    \    }\n};\n\ntemplate<typename CostType>\nstruct Graph{\n    private:\n    int\
    \ __CntVertex, __CntEdge;\n    bool __isDirected;\n    vector<Edge<CostType>>\
    \ __EdgeSet, __RevEdgeSet;\n    vector<vector<EdgeID>> __IncidentList;\n\n   \
    \ public:\n    CostType INF;\n\n    Graph(int VertexSize, bool isDirected = false)\
    \ : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0), __IncidentList(VertexSize),\
    \ INF(numeric_limits<CostType>::max() / 2){}\n\n    Graph() = default;\n\n   \
    \ void add(Vertex s, Vertex t, CostType w = 1){\n        assert(0 <= s && s <\
    \ __CntVertex);\n        assert(0 <= t && t < __CntVertex);\n        __EdgeSet.push_back(Edge<CostType>(s,\
    \ t, w));\n        __IncidentList[s].push_back(__CntEdge);\n        __RevEdgeSet.push_back(Edge<CostType>(t,\
    \ s, w));\n        if(!__isDirected) __IncidentList[t].push_back(__CntEdge);\n\
    \        ++__CntEdge;\n    }\n\n    vector<vector<CostType>> matrix(CostType NotAdjacent\
    \ = numeric_limits<CostType>::max() / 2){\n        vector ret(__CntVertex, vector(__CntVertex,\
    \ NotAdjacent));\n        for(Vertex v = 0; v < __CntVertex; ++v){\n         \
    \   ret[v][v] = 0;\n            for(EdgeID &eid : __IncidentList[v]){\n      \
    \          ret[v][__EdgeSet[eid].getto(v)] = __EdgeSet[eid].cost;\n          \
    \  }\n        }\n        return ret;\n    }\n\n    inline int vsize(){\n     \
    \   return __CntVertex;\n    }\n\n    inline int esize(){\n        return __CntEdge;\n\
    \    }\n\n    inline vector<Edge<CostType>>& get_edgeset(){\n        return __EdgeSet;\n\
    \    }\n\n    vector<Edge<CostType>> get_incident(Vertex v){\n        assert(0\
    \ <= v && v < __CntVertex);\n        vector<Edge<CostType>> ret;\n        for(auto\
    \ &eid : __IncidentList[v]){\n            Edge<CostType> e = __EdgeSet[eid];\n\
    \            if(e.to == v) swap(e.from, e.to);\n            ret.push_back(e);\n\
    \        }\n        return ret;\n    }\n\n    void print_edgeset(bool OneIndex\
    \ = true){\n        for(int e = 0; e < __CntEdge; ++e){\n            cout << e\
    \ + OneIndex << \" : (\" << __EdgeSet[e].from + OneIndex << (__isDirected ? \"\
    \ -> \" : \" <-> \") << __EdgeSet[e].to + OneIndex << \") = \" << __EdgeSet[e].cost\
    \ << endl;\n        }\n    }\n\n    void print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max()\
    \ / 2, bool DisplayINF = true){\n        auto mat = matrix(NotAdjacent);\n   \
    \     for(int i = 0; i < __CntVertex; ++i){\n            cout << (DisplayINF &&\
    \ mat[i][0] == NotAdjacent ? \"INF\" : to_string(mat[i][0]));\n            for(int\
    \ j = 1; j < __CntVertex; ++j){\n                cout << \" \" << (DisplayINF\
    \ && mat[i][j] == NotAdjacent ? \"INF\" : to_string(mat[i][j]));\n           \
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"latest/Graph/Dijkstra.hpp\"\
    \n\ntemplate<typename CostType>\nstruct Dijkstra{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<CostType> __Dist;\n    vector<Vertex> __PrevVertex;\n    Vertex\
    \ __Start;\n\n    void __solve(){\n        __Dist.assign(G.vsize(), G.INF);\n\
    \        __PrevVertex.assign(G.vsize(), -1);\n        using p = pair<CostType,\
    \ Vertex>;\n        priority_queue<p, vector<p>, greater<p>> que;\n        que.emplace(0,\
    \ __Start);\n        __Dist[__Start] = 0;\n        while(que.size()){\n      \
    \      auto [d, v] = que.top(); que.pop();\n            if(__Dist[v] < d) continue;\n\
    \            for(Edge<CostType> &e : G.get_incident(v)){\n                if(d\
    \ + e.cost < __Dist[e.to]){\n                    __Dist[e.to] = d + e.cost;\n\
    \                    __PrevVertex[e.to] = v;\n                    que.emplace(d\
    \ + e.cost, e.to);\n                }\n            }\n        }\n    }\n\n   \
    \ public:\n    Dijkstra(Graph<CostType> &G) : G(G), __Dist(G.vsize()), __PrevVertex(G.vsize()),\
    \ __Start(-1){}\n    \n    Dijkstra(Graph<CostType> &G, Vertex Start) : G(G),\
    \ __Dist(G.vsize()), __PrevVertex(G.vsize()), __Start(Start){\n        __solve();\n\
    \    }\n\n    void build(Vertex Start){\n        assert(0 <= Start && Start <\
    \ G.vsize());\n        if(Start != __Start){\n            __Start = Start;\n \
    \           __solve();\n        }\n    }\n\n    CostType dist(Vertex Start, Vertex\
    \ Goal){\n        assert(0 <= Start && Start < G.vsize());\n        assert(0 <=\
    \ Goal && Goal < G.vsize());\n        if(Start != __Start){\n            __Start\
    \ = Start;\n            __solve();\n        }\n        return __Dist[Goal];\n\
    \    }\n\n    void print(bool DisplayINF = true, char Delimiter = ' '){\n    \
    \    cout << (DisplayINF && __Dist[0] == G.INF ? \"INF\" : to_string(__Dist[0]));\n\
    \        for(int i = 1; i < (int)__Dist.size(); ++i){\n            cout << Delimiter\
    \ << (DisplayINF && __Dist[i] == G.INF ? \"INF\" : to_string(__Dist[i]));\n  \
    \      }\n        cout << endl;\n    }\n};\n"
  code: "/**\n * @file Dijkstra.hpp\n * @author log_K (lX57)\n * @brief Dijkstra -\
    \ \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2\n * @version 2.0\n * @date\
    \ 2023-08-31\n */\n\n#include \"GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct Dijkstra{\n    private:\n    Graph<CostType> &G;\n    vector<CostType>\
    \ __Dist;\n    vector<Vertex> __PrevVertex;\n    Vertex __Start;\n\n    void __solve(){\n\
    \        __Dist.assign(G.vsize(), G.INF);\n        __PrevVertex.assign(G.vsize(),\
    \ -1);\n        using p = pair<CostType, Vertex>;\n        priority_queue<p, vector<p>,\
    \ greater<p>> que;\n        que.emplace(0, __Start);\n        __Dist[__Start]\
    \ = 0;\n        while(que.size()){\n            auto [d, v] = que.top(); que.pop();\n\
    \            if(__Dist[v] < d) continue;\n            for(Edge<CostType> &e :\
    \ G.get_incident(v)){\n                if(d + e.cost < __Dist[e.to]){\n      \
    \              __Dist[e.to] = d + e.cost;\n                    __PrevVertex[e.to]\
    \ = v;\n                    que.emplace(d + e.cost, e.to);\n                }\n\
    \            }\n        }\n    }\n\n    public:\n    Dijkstra(Graph<CostType>\
    \ &G) : G(G), __Dist(G.vsize()), __PrevVertex(G.vsize()), __Start(-1){}\n    \n\
    \    Dijkstra(Graph<CostType> &G, Vertex Start) : G(G), __Dist(G.vsize()), __PrevVertex(G.vsize()),\
    \ __Start(Start){\n        __solve();\n    }\n\n    void build(Vertex Start){\n\
    \        assert(0 <= Start && Start < G.vsize());\n        if(Start != __Start){\n\
    \            __Start = Start;\n            __solve();\n        }\n    }\n\n  \
    \  CostType dist(Vertex Start, Vertex Goal){\n        assert(0 <= Start && Start\
    \ < G.vsize());\n        assert(0 <= Goal && Goal < G.vsize());\n        if(Start\
    \ != __Start){\n            __Start = Start;\n            __solve();\n       \
    \ }\n        return __Dist[Goal];\n    }\n\n    void print(bool DisplayINF = true,\
    \ char Delimiter = ' '){\n        cout << (DisplayINF && __Dist[0] == G.INF ?\
    \ \"INF\" : to_string(__Dist[0]));\n        for(int i = 1; i < (int)__Dist.size();\
    \ ++i){\n            cout << Delimiter << (DisplayINF && __Dist[i] == G.INF ?\
    \ \"INF\" : to_string(__Dist[i]));\n        }\n        cout << endl;\n    }\n\
    };"
  dependsOn:
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: latest/Graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2023-08-31 15:07:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_latest/AOJ-GRL-1-A.test.cpp
documentation_of: latest/Graph/Dijkstra.hpp
layout: document
title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
---

<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [['$', '$'] ],
 displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
 }
 });
</script>

## Abstract

単一始点最短距離問題をDijkstra法を用いて求める。

## Variable

- private
    - `Dist` : 始点`Start`からの距離(存在しない場合は`G.INF`)
    - `PrevVertex` : 各頂点の最短経路上における前の頂点(存在しない場合は`-1`)
    - `Start` : 始点

## Function

- `Dijkstra(Graph G)` : `Graph`で初期化する。
- `Dijkstra(Graph G, Vertex Start)` : `Graph`で初期化し、頂点`Start`を始点として単一始点最短距離問題を解く。$O(E \log V)$
- `build(Vertex Start)` : 頂点`Start`を始点として単一始点最短距離問題を解く。$O(E \log V)$
- `dist(Vertex Start, Vertex Goal)` : 頂点`Start`から頂点`Goal`への最短距離を求める。頂点`Start`を始点とした最短距離が残っているなら$O(1)$、そうでなければ$O(E \log V)$
- `print(bool DisplayINF, char Delimiter)` : 最短距離を文字`Delimiter`を区切り文字として出力する。$O(V)$
