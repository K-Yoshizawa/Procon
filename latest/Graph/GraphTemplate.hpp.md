---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/BellmanFord.hpp
    title: "BellmanFord - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/BipartiteMatching.hpp
    title: latest/Graph/BipartiteMatching.hpp
  - icon: ':heavy_check_mark:'
    path: latest/Graph/Dijkstra.hpp
    title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/FordFulkerson.hpp
    title: "Ford-Fulkerson - \u6700\u5927\u6D41"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/PrimalDual.hpp
    title: "Primal Dual - \u6700\u5C0F\u8CBB\u7528\u6D41"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/WarshallFloyd.hpp
    title: "Warshall Floyd - \u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DDD\u96E2"
  - icon: ':warning:'
    path: latest/Tree/EulerTour.hpp
    title: latest/Tree/EulerTour.hpp
  - icon: ':warning:'
    path: latest/Tree/LowestCommonAncestor.hpp
    title: latest/Tree/LowestCommonAncestor.hpp
  - icon: ':warning:'
    path: verify_latest/pending/LC-BipartiteMatching.cpp
    title: verify_latest/pending/LC-BipartiteMatching.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-ALDS1-11-A.test.cpp
    title: verify_latest/AOJ-ALDS1-11-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-1-A.test.cpp
    title: verify_latest/AOJ-GRL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-1-B-Dijkstra.test.cpp
    title: verify_latest/AOJ-GRL-1-B-Dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-1-B.test.cpp
    title: verify_latest/AOJ-GRL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-1-C.test.cpp
    title: verify_latest/AOJ-GRL-1-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-6-A.test.cpp
    title: verify_latest/AOJ-GRL-6-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-6-B.test.cpp
    title: verify_latest/AOJ-GRL-6-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-7-A.test.cpp
    title: verify_latest/AOJ-GRL-7-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8"
    links: []
  bundledCode: "#line 2 \"latest/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
    \ * @author log K (lX57)\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\n * @version 2.1\n * @date 2023-08-31\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\nusing EdgeID =\
    \ int;\n\ntemplate<typename CostType>\nstruct Edge{\n    Vertex from, to;\n  \
    \  CostType cost, cap;\n\n    Edge(Vertex from, Vertex to, CostType cost) : from(from),\
    \ to(to), cost(cost), cap(1){}\n    Edge(Vertex from, Vertex to, CostType cap,\
    \ CostType cost) : from(from), to(to), cost(cost), cap(cap){}\n\n    Vertex getto(Vertex\
    \ v){\n        assert(v == from || v == to);\n        return from ^ to ^ v;\n\
    \    }\n\n    void swap(){\n        Vertex tmp = from;\n        from = to;\n \
    \       to = tmp;\n    }\n};\n\ntemplate<typename CostType>\nstruct Graph{\n \
    \   private:\n    int __CntVertex, __CntEdge;\n    bool __isDirected;\n    vector<Edge<CostType>>\
    \ __EdgeSet, __RevEdgeSet;\n    vector<vector<pair<EdgeID, bool>>> __IncidentList;\n\
    \    vector<pair<int, int>> __EdgePlace;\n\n    vector<CostType> __Flow;\n\n \
    \   public:\n    CostType INF;\n\n    Graph(int VertexSize, bool isDirected =\
    \ false) : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0), __IncidentList(VertexSize),\
    \ INF(numeric_limits<CostType>::max() / 2){}\n\n    Graph() = default;\n\n   \
    \ void add(Vertex s, Vertex t, CostType w = 1){\n        assert(0 <= s && s <\
    \ __CntVertex);\n        assert(0 <= t && t < __CntVertex);\n        __EdgePlace.push_back({(int)__IncidentList[s].size(),\
    \ (int)__IncidentList[t].size()});\n        __EdgeSet.push_back(Edge<CostType>(s,\
    \ t, w));\n        __IncidentList[s].push_back({__CntEdge, false});\n        __RevEdgeSet.push_back(Edge<CostType>(t,\
    \ s, w));\n        if(!__isDirected) __IncidentList[t].push_back({__CntEdge, true});\n\
    \        ++__CntEdge;\n    }\n\n    void add_flow(Vertex Source, Vertex Sink,\
    \ CostType Capacity, CostType Cost = 1){\n        assert(0 <= Source && Source\
    \ < __CntVertex);\n        assert(0 <= Sink && Sink < __CntVertex);\n        __EdgeSet.push_back(Edge<CostType>(Source,\
    \ Sink, Capacity, Cost));\n        __IncidentList[Source].push_back({__CntEdge,\
    \ false});\n        __RevEdgeSet.push_back(Edge<CostType>(Sink, Source, 0, -Cost));\n\
    \        __IncidentList[Sink].push_back({__CntEdge, true});\n        __Flow.push_back(0);\n\
    \        ++__CntEdge;\n    }\n\n    void update_flow(EdgeID edge_id, bool isReverse,\
    \ CostType Decrease){\n        if(isReverse) Decrease *= -1;\n        __EdgeSet[edge_id].cap\
    \ -= Decrease;\n        __RevEdgeSet[edge_id].cap += Decrease;\n        __Flow[edge_id]\
    \ += Decrease;\n    }\n\n    vector<Edge<CostType>> get_flow(){\n        vector<Edge<CostType>>\
    \ ret;\n        for(EdgeID i = 0; i < __CntEdge; ++i){\n            if(__Flow[i]\
    \ > 0){\n                ret.push_back(__EdgeSet[i]);\n            }\n       \
    \ }\n        return ret;\n    }\n\n    vector<vector<CostType>> matrix(CostType\
    \ NotAdjacent = numeric_limits<CostType>::max() / 2){\n        vector ret(__CntVertex,\
    \ vector(__CntVertex, NotAdjacent));\n        for(Vertex v = 0; v < __CntVertex;\
    \ ++v){\n            ret[v][v] = 0;\n            for(auto [eid, rev] : __IncidentList[v]){\n\
    \                if(!rev) ret[v][__EdgeSet[eid].to] = __EdgeSet[eid].cost;\n \
    \               else ret[v][__RevEdgeSet[eid].to] = __RevEdgeSet[eid].cost;\n\
    \            }\n        }\n        return ret;\n    }\n\n    inline int vsize(){\n\
    \        return __CntVertex;\n    }\n\n    inline int esize(){\n        return\
    \ __CntEdge;\n    }\n\n    inline Edge<CostType> get_edge(EdgeID edge_id, bool\
    \ isReverse){\n        return (isReverse ? __RevEdgeSet[edge_id] : __EdgeSet[edge_id]);\n\
    \    }\n\n    inline vector<Edge<CostType>>& get_edgeset(){\n        return __EdgeSet;\n\
    \    }\n\n    vector<Edge<CostType>> get_incident(Vertex v){\n        assert(0\
    \ <= v && v < __CntVertex);\n        vector<Edge<CostType>> ret;\n        for(auto\
    \ [eid, rev] : __IncidentList[v]){\n            Edge<CostType> e = __EdgeSet[eid];\n\
    \            if(rev) e = __RevEdgeSet[eid];\n            ret.push_back(e);\n \
    \       }\n        return ret;\n    }\n\n    vector<pair<EdgeID, bool>> get_raw_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        return __IncidentList[v];\n\
    \    }\n\n    vector<pair<Vertex, EdgeID>> convert_rootedtree(Vertex Root = 0){\n\
    \        assert(0 <= Root && Root < __CntVertex);\n        vector<pair<Vertex,\
    \ EdgeID>> ret(__CntVertex, {-1, -1});\n        vector<int> visited(__CntVertex,\
    \ 0);\n        queue<Vertex> que;\n        que.push(Root);\n        while(que.size()){\n\
    \            Vertex now = que.front(); que.pop();\n            if(visited[now])\
    \ continue;\n            visited[now] = 1;\n            for(int i = 0; i < __IncidentList[now].size();\
    \ ++i){\n                auto [eid, rev] = __IncidentList[now][i];\n         \
    \       Edge<CostType> e = get_edge(eid, rev);\n                if(visited[e.to])\
    \ continue;\n                que.push(e.to);\n                ret[e.to] = {now,\
    \ eid};\n                if(rev){\n                    __IncidentList[e.from][__EdgePlace[eid].second].second\
    \ = false;\n                    __IncidentList[e.to][__EdgePlace[eid].first].second\
    \ = true;\n                    __EdgeSet[eid].swap();\n                    __RevEdgeSet[eid].swap();\n\
    \                    swap(__EdgePlace[eid].first, __EdgePlace[eid].second);\n\
    \                }\n            }\n        }\n        return ret;\n    }\n\n \
    \   vector<Edge<CostType>> operator[](Vertex v){\n        return get_incident(v);\n\
    \    }\n\n    void print_edgeset(bool OneIndex = true){\n        for(int e = 0;\
    \ e < __CntEdge; ++e){\n            cout << e + OneIndex << \" : (\" << __EdgeSet[e].from\
    \ + OneIndex << (__isDirected ? \" -> \" : \" <-> \") << __EdgeSet[e].to + OneIndex\
    \ << \") = \" << __EdgeSet[e].cost << \" (\" << __EdgeSet[e].cap << \")\" << endl;\n\
    \        }\n    }\n\n    void print_incidentlist(bool OneIndex = true){\n    \
    \    for(int i = 0; i < __CntVertex; ++i){\n            cout << i + OneIndex <<\
    \ \" :\";\n            for(int j = 0; j < __IncidentList[i].size(); ++j){\n  \
    \              cout << \" (\" << __IncidentList[i][j].first << \" / \" << __IncidentList[i][j].second\
    \ << \")\";\n            }\n            cout << endl;\n        }\n    }\n\n  \
    \  void print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max() /\
    \ 2, bool DisplayINF = true){\n        auto mat = matrix(NotAdjacent);\n     \
    \   for(int i = 0; i < __CntVertex; ++i){\n            cout << (DisplayINF &&\
    \ mat[i][0] == NotAdjacent ? \"INF\" : to_string(mat[i][0]));\n            for(int\
    \ j = 1; j < __CntVertex; ++j){\n                cout << \" \" << (DisplayINF\
    \ && mat[i][j] == NotAdjacent ? \"INF\" : to_string(mat[i][j]));\n           \
    \ }\n            cout << endl;\n        }\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n\
    \ * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @version 2.1\n * @date 2023-08-31\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing Vertex = int;\nusing EdgeID = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    Vertex from, to;\n    CostType cost, cap;\n\n \
    \   Edge(Vertex from, Vertex to, CostType cost) : from(from), to(to), cost(cost),\
    \ cap(1){}\n    Edge(Vertex from, Vertex to, CostType cap, CostType cost) : from(from),\
    \ to(to), cost(cost), cap(cap){}\n\n    Vertex getto(Vertex v){\n        assert(v\
    \ == from || v == to);\n        return from ^ to ^ v;\n    }\n\n    void swap(){\n\
    \        Vertex tmp = from;\n        from = to;\n        to = tmp;\n    }\n};\n\
    \ntemplate<typename CostType>\nstruct Graph{\n    private:\n    int __CntVertex,\
    \ __CntEdge;\n    bool __isDirected;\n    vector<Edge<CostType>> __EdgeSet, __RevEdgeSet;\n\
    \    vector<vector<pair<EdgeID, bool>>> __IncidentList;\n    vector<pair<int,\
    \ int>> __EdgePlace;\n\n    vector<CostType> __Flow;\n\n    public:\n    CostType\
    \ INF;\n\n    Graph(int VertexSize, bool isDirected = false) : __CntVertex(VertexSize),\
    \ __isDirected(isDirected), __CntEdge(0), __IncidentList(VertexSize), INF(numeric_limits<CostType>::max()\
    \ / 2){}\n\n    Graph() = default;\n\n    void add(Vertex s, Vertex t, CostType\
    \ w = 1){\n        assert(0 <= s && s < __CntVertex);\n        assert(0 <= t &&\
    \ t < __CntVertex);\n        __EdgePlace.push_back({(int)__IncidentList[s].size(),\
    \ (int)__IncidentList[t].size()});\n        __EdgeSet.push_back(Edge<CostType>(s,\
    \ t, w));\n        __IncidentList[s].push_back({__CntEdge, false});\n        __RevEdgeSet.push_back(Edge<CostType>(t,\
    \ s, w));\n        if(!__isDirected) __IncidentList[t].push_back({__CntEdge, true});\n\
    \        ++__CntEdge;\n    }\n\n    void add_flow(Vertex Source, Vertex Sink,\
    \ CostType Capacity, CostType Cost = 1){\n        assert(0 <= Source && Source\
    \ < __CntVertex);\n        assert(0 <= Sink && Sink < __CntVertex);\n        __EdgeSet.push_back(Edge<CostType>(Source,\
    \ Sink, Capacity, Cost));\n        __IncidentList[Source].push_back({__CntEdge,\
    \ false});\n        __RevEdgeSet.push_back(Edge<CostType>(Sink, Source, 0, -Cost));\n\
    \        __IncidentList[Sink].push_back({__CntEdge, true});\n        __Flow.push_back(0);\n\
    \        ++__CntEdge;\n    }\n\n    void update_flow(EdgeID edge_id, bool isReverse,\
    \ CostType Decrease){\n        if(isReverse) Decrease *= -1;\n        __EdgeSet[edge_id].cap\
    \ -= Decrease;\n        __RevEdgeSet[edge_id].cap += Decrease;\n        __Flow[edge_id]\
    \ += Decrease;\n    }\n\n    vector<Edge<CostType>> get_flow(){\n        vector<Edge<CostType>>\
    \ ret;\n        for(EdgeID i = 0; i < __CntEdge; ++i){\n            if(__Flow[i]\
    \ > 0){\n                ret.push_back(__EdgeSet[i]);\n            }\n       \
    \ }\n        return ret;\n    }\n\n    vector<vector<CostType>> matrix(CostType\
    \ NotAdjacent = numeric_limits<CostType>::max() / 2){\n        vector ret(__CntVertex,\
    \ vector(__CntVertex, NotAdjacent));\n        for(Vertex v = 0; v < __CntVertex;\
    \ ++v){\n            ret[v][v] = 0;\n            for(auto [eid, rev] : __IncidentList[v]){\n\
    \                if(!rev) ret[v][__EdgeSet[eid].to] = __EdgeSet[eid].cost;\n \
    \               else ret[v][__RevEdgeSet[eid].to] = __RevEdgeSet[eid].cost;\n\
    \            }\n        }\n        return ret;\n    }\n\n    inline int vsize(){\n\
    \        return __CntVertex;\n    }\n\n    inline int esize(){\n        return\
    \ __CntEdge;\n    }\n\n    inline Edge<CostType> get_edge(EdgeID edge_id, bool\
    \ isReverse){\n        return (isReverse ? __RevEdgeSet[edge_id] : __EdgeSet[edge_id]);\n\
    \    }\n\n    inline vector<Edge<CostType>>& get_edgeset(){\n        return __EdgeSet;\n\
    \    }\n\n    vector<Edge<CostType>> get_incident(Vertex v){\n        assert(0\
    \ <= v && v < __CntVertex);\n        vector<Edge<CostType>> ret;\n        for(auto\
    \ [eid, rev] : __IncidentList[v]){\n            Edge<CostType> e = __EdgeSet[eid];\n\
    \            if(rev) e = __RevEdgeSet[eid];\n            ret.push_back(e);\n \
    \       }\n        return ret;\n    }\n\n    vector<pair<EdgeID, bool>> get_raw_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        return __IncidentList[v];\n\
    \    }\n\n    vector<pair<Vertex, EdgeID>> convert_rootedtree(Vertex Root = 0){\n\
    \        assert(0 <= Root && Root < __CntVertex);\n        vector<pair<Vertex,\
    \ EdgeID>> ret(__CntVertex, {-1, -1});\n        vector<int> visited(__CntVertex,\
    \ 0);\n        queue<Vertex> que;\n        que.push(Root);\n        while(que.size()){\n\
    \            Vertex now = que.front(); que.pop();\n            if(visited[now])\
    \ continue;\n            visited[now] = 1;\n            for(int i = 0; i < __IncidentList[now].size();\
    \ ++i){\n                auto [eid, rev] = __IncidentList[now][i];\n         \
    \       Edge<CostType> e = get_edge(eid, rev);\n                if(visited[e.to])\
    \ continue;\n                que.push(e.to);\n                ret[e.to] = {now,\
    \ eid};\n                if(rev){\n                    __IncidentList[e.from][__EdgePlace[eid].second].second\
    \ = false;\n                    __IncidentList[e.to][__EdgePlace[eid].first].second\
    \ = true;\n                    __EdgeSet[eid].swap();\n                    __RevEdgeSet[eid].swap();\n\
    \                    swap(__EdgePlace[eid].first, __EdgePlace[eid].second);\n\
    \                }\n            }\n        }\n        return ret;\n    }\n\n \
    \   vector<Edge<CostType>> operator[](Vertex v){\n        return get_incident(v);\n\
    \    }\n\n    void print_edgeset(bool OneIndex = true){\n        for(int e = 0;\
    \ e < __CntEdge; ++e){\n            cout << e + OneIndex << \" : (\" << __EdgeSet[e].from\
    \ + OneIndex << (__isDirected ? \" -> \" : \" <-> \") << __EdgeSet[e].to + OneIndex\
    \ << \") = \" << __EdgeSet[e].cost << \" (\" << __EdgeSet[e].cap << \")\" << endl;\n\
    \        }\n    }\n\n    void print_incidentlist(bool OneIndex = true){\n    \
    \    for(int i = 0; i < __CntVertex; ++i){\n            cout << i + OneIndex <<\
    \ \" :\";\n            for(int j = 0; j < __IncidentList[i].size(); ++j){\n  \
    \              cout << \" (\" << __IncidentList[i][j].first << \" / \" << __IncidentList[i][j].second\
    \ << \")\";\n            }\n            cout << endl;\n        }\n    }\n\n  \
    \  void print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max() /\
    \ 2, bool DisplayINF = true){\n        auto mat = matrix(NotAdjacent);\n     \
    \   for(int i = 0; i < __CntVertex; ++i){\n            cout << (DisplayINF &&\
    \ mat[i][0] == NotAdjacent ? \"INF\" : to_string(mat[i][0]));\n            for(int\
    \ j = 1; j < __CntVertex; ++j){\n                cout << \" \" << (DisplayINF\
    \ && mat[i][j] == NotAdjacent ? \"INF\" : to_string(mat[i][j]));\n           \
    \ }\n            cout << endl;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: latest/Graph/GraphTemplate.hpp
  requiredBy:
  - latest/Graph/Dijkstra.hpp
  - latest/Graph/FordFulkerson.hpp
  - latest/Graph/PrimalDual.hpp
  - latest/Graph/BipartiteMatching.hpp
  - latest/Graph/BellmanFord.hpp
  - latest/Graph/WarshallFloyd.hpp
  - latest/Tree/EulerTour.hpp
  - latest/Tree/LowestCommonAncestor.hpp
  - verify_latest/pending/LC-BipartiteMatching.cpp
  timestamp: '2023-09-22 02:20:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_latest/AOJ-GRL-7-A.test.cpp
  - verify_latest/AOJ-GRL-1-B-Dijkstra.test.cpp
  - verify_latest/AOJ-GRL-6-B.test.cpp
  - verify_latest/AOJ-GRL-6-A.test.cpp
  - verify_latest/AOJ-GRL-1-C.test.cpp
  - verify_latest/AOJ-GRL-1-A.test.cpp
  - verify_latest/AOJ-ALDS1-11-A.test.cpp
  - verify_latest/AOJ-GRL-1-B.test.cpp
documentation_of: latest/Graph/GraphTemplate.hpp
layout: document
title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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

グラフを扱うための基本テンプレート。

## Variable

- private
    - `CntVertex, CntEdge` : 頂点数、辺数
    - `isDirected` : 有向グラフか否か
    - `EdgeSet, RevEdgeSet` : 辺集合、逆辺集合
    - `IncidentList` : 各頂点の接続リスト　辺番号と(グラフ上における)逆辺であるかのフラグを持つ
- public
    - `INF` : 無限大、自動で`numeric_limits<CostType>::max() / 2`となる

## Function

- `Graph(int VertexSize, bool isDirected)` : 頂点数`VertexSize`で初期化する。このとき有向グラフとして作成するかを選択できる。デフォルトでは無向グラフを生成する。
- `add(Vertex s, Vertex t, CostType w)` : 頂点`s`から頂点`t`に重み`w`の辺を追加する。`w`は省略可能。
- `add_flow(Vertex Source, Vertex Sink, CostType Capacity, CostType Cost)` : 頂点`Source`から頂点`Sink`に容量`Capacity`、重み`Cost`の有向辺を追加する。重みを省略した場合は自動的に`1`となる。
- `update_flow(EdgeID edge_id, bool isReverse, CostType Decrease)` : `{edge_id, isReverse}`の辺に対して容量を`Decrease`だけ減少させ、その逆辺の容量を`Decrease`だけ増加させる。
- `matrix(CostType NotAdjacent)` : 隣接行列を生成して返す。隣接していない頂点への距離を`NotAdjacent`で指定可能。$O(E)$
- `vsize(), esize()` : 頂点数、辺数を返す。
- `get_edge(EdgeID edge_id, bool isReverse)` : `{edge_id, isReverse}`の辺を返す。
- `get_edgeset()` : 辺集合を返す。
- `get_incident(Vertex v)` : 頂点`v`の接続リストを辺の`vector`で返す。
- `get_raw_incident(Vertex v)` : 頂点`v`の接続リストを辺の生データの`vector`で返す。
- `print_edgeset(bool OneIndex)` : 主にデバッグ用。辺集合の中身を出力する。$O(E)$
- `print_matrix(CostType NotAdjacent, bool DisplayINF)` : 隣接行列を出力する。隣接していない頂点への距離を`INF`として表示することも可能。$O(V^2)$
