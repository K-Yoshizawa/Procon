---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/BellmanFord.hpp
    title: "BellmanFord - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/BipartiteMatching.hpp
    title: "Bipartite Matching - \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\
      \u30C3\u30C1\u30F3\u30B0"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/Dijkstra.hpp
    title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/FlowTemplate.hpp
    title: "Flow Template - \u30D5\u30ED\u30FC\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
  - icon: ':heavy_check_mark:'
    path: latest/Tree/HeavyLightDecomposition.hpp
    title: "Heavy Light Decomposition - HL\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: latest/Tree/LowestCommonAncestor.hpp
    title: latest/Tree/LowestCommonAncestor.hpp
  - icon: ':warning:'
    path: latest/Tree/TreeDiamiter.hpp
    title: latest/Tree/TreeDiamiter.hpp
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
    path: verify_latest/AOJ-GRL-5-C-HLD.test.cpp
    title: verify_latest/AOJ-GRL-5-C-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-5-C.test.cpp
    title: verify_latest/AOJ-GRL-5-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-6-A.test.cpp
    title: verify_latest/AOJ-GRL-6-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-6-B.test.cpp
    title: verify_latest/AOJ-GRL-6-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-7-A.test.cpp
    title: verify_latest/AOJ-GRL-7-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/LC-VertexAddPathSum.test.cpp
    title: verify_latest/LC-VertexAddPathSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8"
    links: []
  bundledCode: "#line 2 \"latest/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
    \ * @author log K (lX57)\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\n * @version 2.2\n * @date 2023-10-02\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\nusing EdgeID =\
    \ int;\nusing EdgeIndex = int;\n\ntemplate<typename CostType>\nstruct Edge{\n\
    \    EdgeID ID{-1};\n    Vertex src, to;\n    CostType cost, cap;\n    EdgeIndex\
    \ sidx, tidx;\n\n    Edge() = default;\n\n    void print(){\n        cerr << \"\
    Edge \" << ID << \" : (\" << src << \" -> \" << to << \"), Cost = \" << cost <<\
    \ \", Capacity = \" << cap << \", Place = [\" << sidx << \", \" << tidx << \"\
    ]\" << endl;\n    }\n};\n\ntemplate<typename CostType>\nusing EdgeSet = vector<Edge<CostType>>;\n\
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
    \ int incsize(Vertex v){\n        return __IL[v].size();\n    }\n\n    inline\
    \ EdgeSet<CostType> get_edgeset(){\n        return __ES;\n    }\n\n    inline\
    \ IncidentList<CostType> get_incidentlist(){\n        return __IL;\n    }\n\n\
    \    inline vector<Edge<CostType>> get_incident(Vertex v){\n        assert(0 <=\
    \ v && v < __CntVertex);\n        return __IL[v];\n    }\n\n    inline AdjacentList\
    \ get_adjacentlist(){\n        return __AL;\n    }\n\n    inline vector<Vertex>\
    \ get_adjacent(Vertex v){\n        assert(0 <= v && v < __CntVertex);\n      \
    \  return __AL[v];\n    }\n\n    vector<Edge<CostType>> operator[](Vertex v){\n\
    \        return get_incident(v);\n    }\n\n    void print_edgeset(bool OneIndex\
    \ = true){\n        for(int e = 0; e < __CntEdge; ++e){\n            cout << e\
    \ + OneIndex << \" : (\" << __ES[e].from + OneIndex << (__isDirected ? \" -> \"\
    \ : \" <-> \") << __ES[e].to + OneIndex << \") = \" << __ES[e].cost << \" (\"\
    \ << __ES[e].cap << \")\" << endl;\n        }\n    }\n\n    void print_incidentlist(bool\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n\
    \ * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @version 2.2\n * @date 2023-10-02\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing Vertex = int;\nusing EdgeID = int;\nusing EdgeIndex\
    \ = int;\n\ntemplate<typename CostType>\nstruct Edge{\n    EdgeID ID{-1};\n  \
    \  Vertex src, to;\n    CostType cost, cap;\n    EdgeIndex sidx, tidx;\n\n   \
    \ Edge() = default;\n\n    void print(){\n        cerr << \"Edge \" << ID << \"\
    \ : (\" << src << \" -> \" << to << \"), Cost = \" << cost << \", Capacity = \"\
    \ << cap << \", Place = [\" << sidx << \", \" << tidx << \"]\" << endl;\n    }\n\
    };\n\ntemplate<typename CostType>\nusing EdgeSet = vector<Edge<CostType>>;\ntemplate<typename\
    \ CostType>\nusing IncidentList = vector<vector<Edge<CostType>>>;\nusing AdjacentList\
    \ = vector<vector<Vertex>>;\n\ntemplate<typename CostType>\nstruct Graph{\n  \
    \  protected:\n    int __CntVertex, __CntEdge;\n    bool __isDirected;\n    EdgeSet<CostType>\
    \ __ES, __RES;\n    IncidentList<CostType> __IL;\n    AdjacentList __AL;\n\n \
    \   public:\n    CostType INF;\n\n    Graph(int VertexSize, bool isDirected =\
    \ false) : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0), __IL(VertexSize),\
    \ __AL(VertexSize), INF(numeric_limits<CostType>::max() / 2){}\n\n    Graph()\
    \ = default;\n\n    void add(Vertex Source, Vertex To, CostType Cost = 1){\n \
    \       assert(0 <= Source && Source < __CntVertex);\n        assert(0 <= To &&\
    \ To < __CntVertex);\n        EdgeIndex sidx = __IL[Source].size(), tidx = __IL[To].size();\n\
    \        Edge<CostType> es{__CntEdge, Source, To, Cost, 1, sidx, tidx};\n    \
    \    Edge<CostType> et{__CntEdge, To, Source, Cost, 1, tidx, sidx};\n        __ES.push_back(es);\n\
    \        __RES.push_back(et);\n        __IL[Source].push_back(es), __AL[Source].push_back(To);\n\
    \        if(!__isDirected) __IL[To].push_back(et), __AL[To].push_back(Source);\n\
    \        ++__CntEdge;\n    }\n\n    vector<vector<CostType>> matrix(CostType NotAdjacent\
    \ = numeric_limits<CostType>::max() / 2){\n        vector ret(__CntVertex, vector(__CntVertex,\
    \ NotAdjacent));\n        for(Vertex v = 0; v < __CntVertex; ++v){\n         \
    \   ret[v][v] = 0;\n            for(auto e : __IL[v]){\n                ret[v][e.to]\
    \ = e.cost;\n            }\n        }\n        return ret;\n    }\n\n    inline\
    \ int vsize(){\n        return __CntVertex;\n    }\n\n    inline int esize(){\n\
    \        return __CntEdge;\n    }\n\n    inline int incsize(Vertex v){\n     \
    \   return __IL[v].size();\n    }\n\n    inline EdgeSet<CostType> get_edgeset(){\n\
    \        return __ES;\n    }\n\n    inline IncidentList<CostType> get_incidentlist(){\n\
    \        return __IL;\n    }\n\n    inline vector<Edge<CostType>> get_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        return __IL[v];\n \
    \   }\n\n    inline AdjacentList get_adjacentlist(){\n        return __AL;\n \
    \   }\n\n    inline vector<Vertex> get_adjacent(Vertex v){\n        assert(0 <=\
    \ v && v < __CntVertex);\n        return __AL[v];\n    }\n\n    vector<Edge<CostType>>\
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
    \ }\n            cout << endl;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: latest/Graph/GraphTemplate.hpp
  requiredBy:
  - latest/Graph/BipartiteMatching.hpp
  - latest/Graph/Dijkstra.hpp
  - latest/Graph/FordFulkerson.hpp
  - latest/Graph/WarshallFloyd.hpp
  - latest/Graph/BellmanFord.hpp
  - latest/Graph/PrimalDual.hpp
  - latest/Graph/FlowTemplate.hpp
  - latest/Tree/EulerTour.hpp
  - latest/Tree/LowestCommonAncestor.hpp
  - latest/Tree/HeavyLightDecomposition.hpp
  - latest/Tree/TreeDiamiter.hpp
  - verify_latest/pending/LC-BipartiteMatching.cpp
  timestamp: '2023-10-03 01:00:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_latest/AOJ-GRL-6-A.test.cpp
  - verify_latest/AOJ-GRL-1-B.test.cpp
  - verify_latest/AOJ-GRL-6-B.test.cpp
  - verify_latest/AOJ-GRL-1-A.test.cpp
  - verify_latest/AOJ-GRL-5-C.test.cpp
  - verify_latest/AOJ-GRL-7-A.test.cpp
  - verify_latest/LC-VertexAddPathSum.test.cpp
  - verify_latest/AOJ-GRL-5-C-HLD.test.cpp
  - verify_latest/AOJ-ALDS1-11-A.test.cpp
  - verify_latest/AOJ-GRL-1-B-Dijkstra.test.cpp
  - verify_latest/AOJ-GRL-1-C.test.cpp
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
