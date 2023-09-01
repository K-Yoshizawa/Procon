---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/PrimalDual.hpp
    title: "Primal Dual - \u6700\u5C0F\u8CBB\u7528\u6D41"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify_latest/AOJ-GRL-1-A.test.cpp
    title: verify_latest/AOJ-GRL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-1-B-Dijkstra.test.cpp
    title: verify_latest/AOJ-GRL-1-B-Dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-6-B.test.cpp
    title: verify_latest/AOJ-GRL-6-B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
    links: []
  bundledCode: "#line 1 \"latest/Graph/Dijkstra.hpp\"\n/**\n * @file Dijkstra.hpp\n\
    \ * @author log_K (lX57)\n * @brief Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\
    \u8DDD\u96E2\n * @version 2.1\n * @date 2023-08-31\n */\n\n#line 2 \"latest/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 2.1\n * @date 2023-08-31\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing Vertex = int;\nusing EdgeID = int;\n\ntemplate<typename CostType>\nstruct\
    \ Edge{\n    Vertex from, to;\n    CostType cost, cap;\n\n    Edge(Vertex from,\
    \ Vertex to, CostType cost) : from(from), to(to), cost(cost), cap(1){}\n    Edge(Vertex\
    \ from, Vertex to, CostType cap, CostType cost) : from(from), to(to), cost(cost),\
    \ cap(cap){}\n\n    Vertex getto(Vertex v){\n        assert(v == from || v ==\
    \ to);\n        return from ^ to ^ v;\n    }\n};\n\ntemplate<typename CostType>\n\
    struct Graph{\n    private:\n    int __CntVertex, __CntEdge;\n    bool __isDirected;\n\
    \    vector<Edge<CostType>> __EdgeSet, __RevEdgeSet;\n    vector<vector<pair<EdgeID,\
    \ bool>>> __IncidentList;\n\n    public:\n    CostType INF;\n\n    Graph(int VertexSize,\
    \ bool isDirected = false) : __CntVertex(VertexSize), __isDirected(isDirected),\
    \ __CntEdge(0), __IncidentList(VertexSize), INF(numeric_limits<CostType>::max()\
    \ / 2){}\n\n    Graph() = default;\n\n    void add(Vertex s, Vertex t, CostType\
    \ w = 1){\n        assert(0 <= s && s < __CntVertex);\n        assert(0 <= t &&\
    \ t < __CntVertex);\n        __EdgeSet.push_back(Edge<CostType>(s, t, w));\n \
    \       __IncidentList[s].push_back({__CntEdge, false});\n        __RevEdgeSet.push_back(Edge<CostType>(t,\
    \ s, w));\n        if(!__isDirected) __IncidentList[t].push_back({__CntEdge, true});\n\
    \        ++__CntEdge;\n    }\n\n    void add_flow(Vertex Source, Vertex Sink,\
    \ CostType Capacity, CostType Cost = 1){\n        assert(0 <= Source && Source\
    \ < __CntVertex);\n        assert(0 <= Sink && Sink < __CntVertex);\n        __EdgeSet.push_back(Edge<CostType>(Source,\
    \ Sink, Capacity, Cost));\n        __IncidentList[Source].push_back({__CntEdge,\
    \ false});\n        __RevEdgeSet.push_back(Edge<CostType>(Sink, Source, 0, -Cost));\n\
    \        __IncidentList[Sink].push_back({__CntEdge, true});\n        ++__CntEdge;\n\
    \    }\n\n    void update_flow(EdgeID edge_id, bool isReverse, CostType Decrease){\n\
    \        if(isReverse) Decrease *= -1;\n        __EdgeSet[edge_id].cap -= Decrease;\n\
    \        __RevEdgeSet[edge_id].cap += Decrease;\n    }\n\n    vector<vector<CostType>>\
    \ matrix(CostType NotAdjacent = numeric_limits<CostType>::max() / 2){\n      \
    \  vector ret(__CntVertex, vector(__CntVertex, NotAdjacent));\n        for(Vertex\
    \ v = 0; v < __CntVertex; ++v){\n            ret[v][v] = 0;\n            for(auto\
    \ [eid, rev] : __IncidentList[v]){\n                if(!rev) ret[v][__EdgeSet[eid].to]\
    \ = __EdgeSet[eid].cost;\n                else ret[v][__RevEdgeSet[eid].to] =\
    \ __RevEdgeSet[eid].cost;\n            }\n        }\n        return ret;\n   \
    \ }\n\n    inline int vsize(){\n        return __CntVertex;\n    }\n\n    inline\
    \ int esize(){\n        return __CntEdge;\n    }\n\n    inline Edge<CostType>\
    \ get_edge(EdgeID edge_id, bool isReverse){\n        return (isReverse ? __RevEdgeSet[edge_id]\
    \ : __EdgeSet[edge_id]);\n    }\n\n    inline vector<Edge<CostType>>& get_edgeset(){\n\
    \        return __EdgeSet;\n    }\n\n    vector<Edge<CostType>> get_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        vector<Edge<CostType>>\
    \ ret;\n        for(auto [eid, rev] : __IncidentList[v]){\n            Edge<CostType>\
    \ e = __EdgeSet[eid];\n            if(rev) e = __RevEdgeSet[eid];\n          \
    \  ret.push_back(e);\n        }\n        return ret;\n    }\n\n    vector<pair<EdgeID,\
    \ bool>> get_raw_incident(Vertex v){\n        assert(0 <= v && v < __CntVertex);\n\
    \        return __IncidentList[v];\n    }\n\n    void print_edgeset(bool OneIndex\
    \ = true){\n        for(int e = 0; e < __CntEdge; ++e){\n            cout << e\
    \ + OneIndex << \" : (\" << __EdgeSet[e].from + OneIndex << (__isDirected ? \"\
    \ -> \" : \" <-> \") << __EdgeSet[e].to + OneIndex << \") = \" << __EdgeSet[e].cost\
    \ << \" (\" << __EdgeSet[e].cap << \")\" << endl;\n        }\n    }\n\n    void\
    \ print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max() / 2, bool\
    \ DisplayINF = true){\n        auto mat = matrix(NotAdjacent);\n        for(int\
    \ i = 0; i < __CntVertex; ++i){\n            cout << (DisplayINF && mat[i][0]\
    \ == NotAdjacent ? \"INF\" : to_string(mat[i][0]));\n            for(int j = 1;\
    \ j < __CntVertex; ++j){\n                cout << \" \" << (DisplayINF && mat[i][j]\
    \ == NotAdjacent ? \"INF\" : to_string(mat[i][j]));\n            }\n         \
    \   cout << endl;\n        }\n    }\n};\n#line 10 \"latest/Graph/Dijkstra.hpp\"\
    \n\ntemplate<typename CostType>\nstruct Dijkstra{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<CostType> __Dist, __Potential;\n    vector<Vertex> __PrevVertex;\n\
    \    vector<pair<EdgeID, bool>> __PrevEdge;\n    Vertex __Start;\n\n    void __solve(){\n\
    \        __Dist.assign(G.vsize(), G.INF);\n        __PrevVertex.assign(G.vsize(),\
    \ -1);\n        __PrevEdge.assign(G.vsize(), {-1, false});\n        using p =\
    \ pair<CostType, Vertex>;\n        priority_queue<p, vector<p>, greater<p>> que;\n\
    \        que.emplace(__Potential[__Start], __Start);\n        __Dist[__Start]\
    \ = __Potential[__Start];\n        while(que.size()){\n            auto [d, v]\
    \ = que.top(); que.pop();\n            if(__Dist[v] < d) continue;\n         \
    \   for(auto [eid, rev] : G.get_raw_incident(v)){\n                Edge<CostType>\
    \ e = G.get_edge(eid, rev);\n                if(e.cap > 0 && d + e.cost + __Potential[e.from]\
    \ - __Potential[e.to] < __Dist[e.to]){\n                    __Dist[e.to] = d +\
    \ e.cost + __Potential[e.from] - __Potential[e.to];\n                    __PrevVertex[e.to]\
    \ = v;\n                    __PrevEdge[e.to] = {eid, rev};\n                 \
    \   que.emplace(__Dist[e.to], e.to);\n                }\n            }\n     \
    \   }\n        for(Vertex i = 0; i < G.vsize(); ++i){\n            if(__Dist[i]\
    \ != G.INF) __Dist[i] += __Potential[i] - __Potential[__Start];\n        }\n \
    \   }\n\n    public:\n    Dijkstra(Graph<CostType> &G) : G(G), __Dist(G.vsize()),\
    \ __Potential(G.vsize(), 0), __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Start(-1){}\n\
    \    \n    Dijkstra(Graph<CostType> &G, Vertex Start) : G(G), __Dist(G.vsize()),\
    \ __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Start(Start){\n        __solve();\n\
    \    }\n\n    void update_potential(vector<CostType> Potential){\n        assert(__Potential.size()\
    \ == Potential.size());\n        __Potential = Potential;\n    }\n\n    void rebuild(){\n\
    \        __solve();\n    }\n\n    void build(Vertex Start){\n        assert(0\
    \ <= Start && Start < G.vsize());\n        if(Start != __Start){\n           \
    \ __Start = Start;\n            __solve();\n        }\n    }\n\n    vector<CostType>\
    \ all(Vertex Start){\n        assert(0 <= Start && Start < G.vsize());\n     \
    \   if(Start != __Start) build(Start);\n        return __Dist;\n    }\n\n    CostType\
    \ dist(Vertex Start, Vertex Goal){\n        assert(0 <= Start && Start < G.vsize());\n\
    \        assert(0 <= Goal && Goal < G.vsize());\n        if(Start != __Start){\n\
    \            __Start = Start;\n            __solve();\n        }\n        return\
    \ __Dist[Goal];\n    }\n\n    vector<pair<CostType, bool>> restore_edge(Vertex\
    \ Goal){\n        vector<pair<CostType, bool>> ret;\n        Vertex now = Goal;\n\
    \        while(__PrevEdge[now].first != -1){\n            ret.push_back(__PrevEdge[now]);\n\
    \            auto [eid, rev] = __PrevEdge[now];\n            now = G.get_edge(eid,\
    \ rev).from;\n        }\n        reverse(ret.begin(), ret.end());\n        return\
    \ ret;\n    }\n\n    void print(bool DisplayINF = true, char Delimiter = ' '){\n\
    \        cout << (DisplayINF && __Dist[0] == G.INF ? \"INF\" : to_string(__Dist[0]));\n\
    \        for(int i = 1; i < (int)__Dist.size(); ++i){\n            cout << Delimiter\
    \ << (DisplayINF && __Dist[i] == G.INF ? \"INF\" : to_string(__Dist[i]));\n  \
    \      }\n        cout << endl;\n    }\n};\n"
  code: "/**\n * @file Dijkstra.hpp\n * @author log_K (lX57)\n * @brief Dijkstra -\
    \ \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2\n * @version 2.1\n * @date\
    \ 2023-08-31\n */\n\n#include \"GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct Dijkstra{\n    private:\n    Graph<CostType> &G;\n    vector<CostType>\
    \ __Dist, __Potential;\n    vector<Vertex> __PrevVertex;\n    vector<pair<EdgeID,\
    \ bool>> __PrevEdge;\n    Vertex __Start;\n\n    void __solve(){\n        __Dist.assign(G.vsize(),\
    \ G.INF);\n        __PrevVertex.assign(G.vsize(), -1);\n        __PrevEdge.assign(G.vsize(),\
    \ {-1, false});\n        using p = pair<CostType, Vertex>;\n        priority_queue<p,\
    \ vector<p>, greater<p>> que;\n        que.emplace(__Potential[__Start], __Start);\n\
    \        __Dist[__Start] = __Potential[__Start];\n        while(que.size()){\n\
    \            auto [d, v] = que.top(); que.pop();\n            if(__Dist[v] < d)\
    \ continue;\n            for(auto [eid, rev] : G.get_raw_incident(v)){\n     \
    \           Edge<CostType> e = G.get_edge(eid, rev);\n                if(e.cap\
    \ > 0 && d + e.cost + __Potential[e.from] - __Potential[e.to] < __Dist[e.to]){\n\
    \                    __Dist[e.to] = d + e.cost + __Potential[e.from] - __Potential[e.to];\n\
    \                    __PrevVertex[e.to] = v;\n                    __PrevEdge[e.to]\
    \ = {eid, rev};\n                    que.emplace(__Dist[e.to], e.to);\n      \
    \          }\n            }\n        }\n        for(Vertex i = 0; i < G.vsize();\
    \ ++i){\n            if(__Dist[i] != G.INF) __Dist[i] += __Potential[i] - __Potential[__Start];\n\
    \        }\n    }\n\n    public:\n    Dijkstra(Graph<CostType> &G) : G(G), __Dist(G.vsize()),\
    \ __Potential(G.vsize(), 0), __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Start(-1){}\n\
    \    \n    Dijkstra(Graph<CostType> &G, Vertex Start) : G(G), __Dist(G.vsize()),\
    \ __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Start(Start){\n        __solve();\n\
    \    }\n\n    void update_potential(vector<CostType> Potential){\n        assert(__Potential.size()\
    \ == Potential.size());\n        __Potential = Potential;\n    }\n\n    void rebuild(){\n\
    \        __solve();\n    }\n\n    void build(Vertex Start){\n        assert(0\
    \ <= Start && Start < G.vsize());\n        if(Start != __Start){\n           \
    \ __Start = Start;\n            __solve();\n        }\n    }\n\n    vector<CostType>\
    \ all(Vertex Start){\n        assert(0 <= Start && Start < G.vsize());\n     \
    \   if(Start != __Start) build(Start);\n        return __Dist;\n    }\n\n    CostType\
    \ dist(Vertex Start, Vertex Goal){\n        assert(0 <= Start && Start < G.vsize());\n\
    \        assert(0 <= Goal && Goal < G.vsize());\n        if(Start != __Start){\n\
    \            __Start = Start;\n            __solve();\n        }\n        return\
    \ __Dist[Goal];\n    }\n\n    vector<pair<CostType, bool>> restore_edge(Vertex\
    \ Goal){\n        vector<pair<CostType, bool>> ret;\n        Vertex now = Goal;\n\
    \        while(__PrevEdge[now].first != -1){\n            ret.push_back(__PrevEdge[now]);\n\
    \            auto [eid, rev] = __PrevEdge[now];\n            now = G.get_edge(eid,\
    \ rev).from;\n        }\n        reverse(ret.begin(), ret.end());\n        return\
    \ ret;\n    }\n\n    void print(bool DisplayINF = true, char Delimiter = ' '){\n\
    \        cout << (DisplayINF && __Dist[0] == G.INF ? \"INF\" : to_string(__Dist[0]));\n\
    \        for(int i = 1; i < (int)__Dist.size(); ++i){\n            cout << Delimiter\
    \ << (DisplayINF && __Dist[i] == G.INF ? \"INF\" : to_string(__Dist[i]));\n  \
    \      }\n        cout << endl;\n    }\n};"
  dependsOn:
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: latest/Graph/Dijkstra.hpp
  requiredBy:
  - latest/Graph/PrimalDual.hpp
  timestamp: '2023-09-01 21:17:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify_latest/AOJ-GRL-1-A.test.cpp
  - verify_latest/AOJ-GRL-1-B-Dijkstra.test.cpp
  - verify_latest/AOJ-GRL-6-B.test.cpp
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
負辺がある場合でも、ポテンシャルを適切に与えることで求めることが可能。

## Variable

- private
    - `Dist` : 始点`Start`からの距離(存在しない場合は`G.INF`)
    - `Potential` : ポテンシャル(初期値`0`)
    - `PrevVertex` : 各頂点の最短経路上における前の頂点(存在しない場合は`-1`)
    - `PrevEdge` : 各頂点の最短経路上における前の辺(存在しない場合は`-1`)
    - `Start` : 始点

## Function

- `Dijkstra(Graph G)` : `Graph`で初期化する。
- `Dijkstra(Graph G, Vertex Start)` : `Graph`で初期化し、頂点`Start`を始点として単一始点最短距離問題を解く。$O(E \log V)$
- `update_potential(vector<CostType> Potential)` : グラフのポテンシャル値を`Potential`で更新する。$O(V)$
- `build(Vertex Start)` : 頂点`Start`を始点として単一始点最短距離問題を解く。$O(E \log V)$
- `all(Vertex Start)` : 頂点`Start`を始点としたときの各頂点への最短経路を返す。$O(E \log V)$
- `dist(Vertex Start, Vertex Goal)` : 頂点`Start`から頂点`Goal`への最短距離を求める。頂点`Start`を始点とした最短距離が残っているなら$O(1)$、そうでなければ$O(E \log V)$
- `restore_edge(Vertex Goal)` : 頂点`Goal`から頂点`Start`への最短経路の辺を復元して返す。$O(V)$
- `print(bool DisplayINF, char Delimiter)` : 最短距離を文字`Delimiter`を区切り文字として出力する。$O(V)$
