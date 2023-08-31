---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-1-C.test.cpp
    title: verify_latest/AOJ-GRL-1-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "WarshallFloyd - \u5168\u70B9\u5BFE\u9593\u6700\u77ED\u7D4C\u8DEF"
    links: []
  bundledCode: "#line 1 \"latest/Graph/WarshallFloyd.hpp\"\n/**\n * @file WarshallFloyd.hpp\n\
    \ * @author log_K (lX57)\n * @brief WarshallFloyd - \u5168\u70B9\u5BFE\u9593\u6700\
    \u77ED\u7D4C\u8DEF\n * @version 2.0\n * @date 2023-08-31\n */\n\n#line 2 \"latest/Graph/GraphTemplate.hpp\"\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"latest/Graph/WarshallFloyd.hpp\"\
    \n\ntemplate<typename CostType>\nstruct WarshallFloyd{\n    private:\n    bool\
    \ __NegativeCycle;\n    int __Size;\n    CostType __INF;\n    vector<vector<CostType>>\
    \ __Dist;\n\n    void __solve(){\n        for(int k = 0; k < __Size; ++k){\n \
    \           for(int i = 0; i < __Size; ++i){\n                for(int j = 0; j\
    \ < __Size; ++j){\n                    if(__Dist[i][k] == __INF || __Dist[k][j]\
    \ == __INF) continue;\n                    __Dist[i][j] = min(__Dist[i][j], __Dist[i][k]\
    \ + __Dist[k][j]);\n                }\n            }\n        }\n        __NegativeCycle\
    \ = false;\n        for(int i = 0; i < __Size; ++i) __NegativeCycle |= __Dist[i][i]\
    \ < 0;\n    }\n\n    public:\n    WarshallFloyd(Graph<CostType> &G) : __Size(G.vsize()),\
    \ __INF(G.INF), __Dist(G.matrix()){\n        __solve();\n    }\n\n    WarshallFloyd(vector<vector<CostType>>\
    \ &M) : __Size((int)M.size()), __INF(numeric_limits<CostType>::max() / 2), __Dist(M){\n\
    \        __solve();\n    }\n\n    inline bool negative(){\n        return __NegativeCycle;\n\
    \    }\n\n    CostType dist(Vertex Start, Vertex Goal){\n        assert(0 <= Start\
    \ && Start < __Size);\n        assert(0 <= Goal && Goal < __Size);\n        return\
    \ __Dist[Start][Goal];\n    }\n    \n    void print(CostType NotAdjacent = numeric_limits<CostType>::max()\
    \ / 2, bool DisplayINF = true){\n        for(int i = 0; i < __Size; ++i){\n  \
    \          cout << (DisplayINF && __Dist[i][0] == NotAdjacent ? \"INF\" : to_string(__Dist[i][0]));\n\
    \            for(int j = 1; j < __Size; ++j){\n                cout << \" \" <<\
    \ (DisplayINF && __Dist[i][j] == NotAdjacent ? \"INF\" : to_string(__Dist[i][j]));\n\
    \            }\n            cout << endl;\n        }\n    }\n};\n"
  code: "/**\n * @file WarshallFloyd.hpp\n * @author log_K (lX57)\n * @brief WarshallFloyd\
    \ - \u5168\u70B9\u5BFE\u9593\u6700\u77ED\u7D4C\u8DEF\n * @version 2.0\n * @date\
    \ 2023-08-31\n */\n\n#include \"GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct WarshallFloyd{\n    private:\n    bool __NegativeCycle;\n    int __Size;\n\
    \    CostType __INF;\n    vector<vector<CostType>> __Dist;\n\n    void __solve(){\n\
    \        for(int k = 0; k < __Size; ++k){\n            for(int i = 0; i < __Size;\
    \ ++i){\n                for(int j = 0; j < __Size; ++j){\n                  \
    \  if(__Dist[i][k] == __INF || __Dist[k][j] == __INF) continue;\n            \
    \        __Dist[i][j] = min(__Dist[i][j], __Dist[i][k] + __Dist[k][j]);\n    \
    \            }\n            }\n        }\n        __NegativeCycle = false;\n \
    \       for(int i = 0; i < __Size; ++i) __NegativeCycle |= __Dist[i][i] < 0;\n\
    \    }\n\n    public:\n    WarshallFloyd(Graph<CostType> &G) : __Size(G.vsize()),\
    \ __INF(G.INF), __Dist(G.matrix()){\n        __solve();\n    }\n\n    WarshallFloyd(vector<vector<CostType>>\
    \ &M) : __Size((int)M.size()), __INF(numeric_limits<CostType>::max() / 2), __Dist(M){\n\
    \        __solve();\n    }\n\n    inline bool negative(){\n        return __NegativeCycle;\n\
    \    }\n\n    CostType dist(Vertex Start, Vertex Goal){\n        assert(0 <= Start\
    \ && Start < __Size);\n        assert(0 <= Goal && Goal < __Size);\n        return\
    \ __Dist[Start][Goal];\n    }\n    \n    void print(CostType NotAdjacent = numeric_limits<CostType>::max()\
    \ / 2, bool DisplayINF = true){\n        for(int i = 0; i < __Size; ++i){\n  \
    \          cout << (DisplayINF && __Dist[i][0] == NotAdjacent ? \"INF\" : to_string(__Dist[i][0]));\n\
    \            for(int j = 1; j < __Size; ++j){\n                cout << \" \" <<\
    \ (DisplayINF && __Dist[i][j] == NotAdjacent ? \"INF\" : to_string(__Dist[i][j]));\n\
    \            }\n            cout << endl;\n        }\n    }\n};"
  dependsOn:
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: latest/Graph/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2023-08-31 15:07:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_latest/AOJ-GRL-1-C.test.cpp
documentation_of: latest/Graph/WarshallFloyd.hpp
layout: document
title: "Warshall Floyd - \u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DDD\u96E2"
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

全点対間最短距離問題をWarshall Floyd法を用いて求める。

## Variable

- private
    - `NegativeCycle` : 負の閉路が存在するか
    - `Size` : 頂点数
    - `Dist` : 隣接行列形式で表された最短距離。`Dist[i][j]`は頂点`i`から頂点`j`への最短距離を表している。

## Function

- `WarshallFloyd(Graph G)` : `Graph`で初期化し、全点対間最短距離問題を解く。$O(V^3)$
- `WarshallFloyd(vector<vector<CostType>> M)` : 隣接行列`M`で初期化し、全点対間最短距離問題を解く。$O(V^3)$
- `negative()` : 負閉路を含むかを返す。
- `dist(Vertex Start, Vertex Goal)` : 頂点`Start`から頂点`Goal`への最短距離を返す。$O(1)$
- `print(CostType NotAdjacent, bool DisplayINF)` : 隣接行列を出力する。隣接していない頂点への距離を`INF`として表示することも可能。$O(V^2)$
