---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify_latest/AOJ-ALDS1-11-A.test.cpp
    title: verify_latest/AOJ-ALDS1-11-A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8"
    links: []
  bundledCode: "#line 2 \"latest/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
    \ * @author log K (lX57)\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\n * @version 2.0\n * @date 2023-08-31\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\nusing EdgeID =\
    \ int;\n\ntemplate<typename CostType>\nstruct Edge{\n    Vertex from, to;\n  \
    \  CostType cost;\n\n    Edge(Vertex from, Vertex to, CostType cost) : from(from),\
    \ to(to), cost(cost){}\n\n    Vertex getto(Vertex v){\n        assert(v == from\
    \ || v == to);\n        return from ^ to ^ v;\n    }\n};\n\ntemplate<typename\
    \ CostType>\nstruct Graph{\n    private:\n    int __CntVertex, __CntEdge;\n  \
    \  bool __isDirected;\n    vector<Edge<CostType>> __EdgeSet, __RevEdgeSet;\n \
    \   vector<vector<EdgeID>> __IncidentList;\n\n    public:\n    CostType INF;\n\
    \n    Graph(int VertexSize, bool isDirected = false) : __CntVertex(VertexSize),\
    \ __isDirected(isDirected), __CntEdge(0), __IncidentList(VertexSize), INF(numeric_limits<CostType>::max()\
    \ / 2){}\n\n    Graph() = default;\n\n    void add(Vertex s, Vertex t, CostType\
    \ w = 1){\n        assert(0 <= s && s < __CntVertex);\n        assert(0 <= t &&\
    \ t < __CntVertex);\n        __EdgeSet.push_back(Edge<CostType>(s, t, w));\n \
    \       __IncidentList[s].push_back(__CntEdge);\n        __RevEdgeSet.push_back(Edge<CostType>(t,\
    \ s, w));\n        if(!__isDirected) __IncidentList[t].push_back(__CntEdge);\n\
    \        ++__CntEdge;\n    }\n\n    vector<vector<CostType>> matrix(CostType NotAdjacent\
    \ = numeric_limits<CostType>::max() / 2){\n        vector ret(__CntVertex, vector(__CntVertex,\
    \ NotAdjacent));\n        for(Vertex v = 0; v < __CntVertex; ++v){\n         \
    \   for(EdgeID &eid : __IncidentList[v]){\n                ret[v][__EdgeSet[eid].getto(v)]\
    \ = __EdgeSet[eid].cost;\n            }\n        }\n        return ret;\n    }\n\
    \n    void print_edgeset(bool OneIndex = true){\n        for(int e = 0; e < __CntEdge;\
    \ ++e){\n            cout << e + OneIndex << \" : (\" << __EdgeSet[e].from + OneIndex\
    \ << (__isDirected ? \" -> \" : \" <-> \") << __EdgeSet[e].to + OneIndex << \"\
    ) = \" << __EdgeSet[e].cost << endl;\n        }\n    }\n\n    void print_matrix(CostType\
    \ NotAdjacent = numeric_limits<CostType>::max() / 2, bool DisplayINF = true){\n\
    \        auto mat = matrix(NotAdjacent);\n        for(int i = 0; i < __CntVertex;\
    \ ++i){\n            cout << (DisplayINF && mat[i][j] == NotAdjacent ? \"INF\"\
    \ : to_string(mat[i][0]));\n            for(int j = 1; j < __CntVertex; ++j){\n\
    \                cout << \" \" << (DisplayINF && mat[i][j] == NotAdjacent ? \"\
    INF\" : to_string(mat[i][j]));\n            }\n            cout << endl;\n   \
    \     }\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n\
    \ * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @version 2.0\n * @date 2023-08-31\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing Vertex = int;\nusing EdgeID = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    Vertex from, to;\n    CostType cost;\n\n    Edge(Vertex\
    \ from, Vertex to, CostType cost) : from(from), to(to), cost(cost){}\n\n    Vertex\
    \ getto(Vertex v){\n        assert(v == from || v == to);\n        return from\
    \ ^ to ^ v;\n    }\n};\n\ntemplate<typename CostType>\nstruct Graph{\n    private:\n\
    \    int __CntVertex, __CntEdge;\n    bool __isDirected;\n    vector<Edge<CostType>>\
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
    \   for(EdgeID &eid : __IncidentList[v]){\n                ret[v][__EdgeSet[eid].getto(v)]\
    \ = __EdgeSet[eid].cost;\n            }\n        }\n        return ret;\n    }\n\
    \n    void print_edgeset(bool OneIndex = true){\n        for(int e = 0; e < __CntEdge;\
    \ ++e){\n            cout << e + OneIndex << \" : (\" << __EdgeSet[e].from + OneIndex\
    \ << (__isDirected ? \" -> \" : \" <-> \") << __EdgeSet[e].to + OneIndex << \"\
    ) = \" << __EdgeSet[e].cost << endl;\n        }\n    }\n\n    void print_matrix(CostType\
    \ NotAdjacent = numeric_limits<CostType>::max() / 2, bool DisplayINF = true){\n\
    \        auto mat = matrix(NotAdjacent);\n        for(int i = 0; i < __CntVertex;\
    \ ++i){\n            cout << (DisplayINF && mat[i][j] == NotAdjacent ? \"INF\"\
    \ : to_string(mat[i][0]));\n            for(int j = 1; j < __CntVertex; ++j){\n\
    \                cout << \" \" << (DisplayINF && mat[i][j] == NotAdjacent ? \"\
    INF\" : to_string(mat[i][j]));\n            }\n            cout << endl;\n   \
    \     }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: latest/Graph/GraphTemplate.hpp
  requiredBy: []
  timestamp: '2023-08-31 01:23:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify_latest/AOJ-ALDS1-11-A.test.cpp
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
    - `IncidentList` : 各頂点の接続リスト
- public
    - `INF` : 無限大、自動で`numeric_limits<CostType>::max() / 2`となる

## Function

- `Graph(int VertexSize, bool isDirected)` : 頂点数`VertexSize`で初期化する。このとき有向グラフとして作成するかを選択できる。デフォルトでは無向グラフを生成する。
- `add(Vertex s, Vertex t, CostType w)` : 頂点`s`から頂点`t`に重み`w`の辺を追加する。`w`は省略可能。
- `matrix(CostType NotAdjacent)` : 隣接行列を生成して返す。隣接していない頂点への距離を`NotAdjacent`で指定可能。$O(E)$
- `print_edgeset(bool OneIndex)` : 主にデバッグ用。辺集合の中身を出力する。$O(E)$
- `print_matrix(CostType NotAdjacent, bool DisplayINF)` : 隣接行列を出力する。隣接していない頂点への距離を`INF`として表示することも可能。$O(V^2)$
