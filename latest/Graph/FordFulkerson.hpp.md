---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-6-A.test.cpp
    title: verify_latest/AOJ-GRL-6-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Ford-Fulkerson - \u6700\u5927\u6D41"
    links: []
  bundledCode: "#line 1 \"latest/Graph/FordFulkerson.hpp\"\n/**\n * @file FordFulkerson.hpp\n\
    \ * @author log K (lX57)\n * @brief Ford-Fulkerson - \u6700\u5927\u6D41\n * @version\
    \ 2.0\n * @date 2023-09-01\n */\n\n#line 2 \"latest/Graph/GraphTemplate.hpp\"\n\
    \n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph Template\
    \ - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 2.1\n\
    \ * @date 2023-08-31\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    using Vertex = int;\nusing EdgeID = int;\n\ntemplate<typename CostType>\nstruct\
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
    \   cout << endl;\n        }\n    }\n};\n#line 10 \"latest/Graph/FordFulkerson.hpp\"\
    \n\ntemplate<typename CostType>\nstruct FordFulkerson{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<int> used;\n\n    CostType dfs(Vertex pos, Vertex goal, CostType\
    \ F){\n        if(pos == goal) return F;\n        used[pos] = 1;\n        for(auto\
    \ [eid, rev] : G.get_raw_incident(pos)){\n            auto e = G.get_edge(eid,\
    \ rev);\n            if(e.cap == 0 || used[e.to]) continue;\n            CostType\
    \ flow = dfs(e.to, goal, min(F, e.cap));\n            if(flow >= 1){\n       \
    \         G.update_flow(eid, rev, flow);\n                return flow;\n     \
    \       }\n        }\n        return 0;\n    }\n\n    public:\n    FordFulkerson(Graph<CostType>\
    \ &G) : G(G), used(G.vsize(), 0){}\n\n    CostType solve(Vertex Source, Vertex\
    \ Sink){\n        CostType ans = 0;\n        while(1){\n            used.assign(G.vsize(),\
    \ 0);\n            CostType F = dfs(Source, Sink, G.INF);\n            if(F ==\
    \ 0) break;\n            ans += F;\n        }\n        return ans;\n    }\n};\n"
  code: "/**\n * @file FordFulkerson.hpp\n * @author log K (lX57)\n * @brief Ford-Fulkerson\
    \ - \u6700\u5927\u6D41\n * @version 2.0\n * @date 2023-09-01\n */\n\n#include\
    \ \"GraphTemplate.hpp\"\n\ntemplate<typename CostType>\nstruct FordFulkerson{\n\
    \    private:\n    Graph<CostType> &G;\n    vector<int> used;\n\n    CostType\
    \ dfs(Vertex pos, Vertex goal, CostType F){\n        if(pos == goal) return F;\n\
    \        used[pos] = 1;\n        for(auto [eid, rev] : G.get_raw_incident(pos)){\n\
    \            auto e = G.get_edge(eid, rev);\n            if(e.cap == 0 || used[e.to])\
    \ continue;\n            CostType flow = dfs(e.to, goal, min(F, e.cap));\n   \
    \         if(flow >= 1){\n                G.update_flow(eid, rev, flow);\n   \
    \             return flow;\n            }\n        }\n        return 0;\n    }\n\
    \n    public:\n    FordFulkerson(Graph<CostType> &G) : G(G), used(G.vsize(), 0){}\n\
    \n    CostType solve(Vertex Source, Vertex Sink){\n        CostType ans = 0;\n\
    \        while(1){\n            used.assign(G.vsize(), 0);\n            CostType\
    \ F = dfs(Source, Sink, G.INF);\n            if(F == 0) break;\n            ans\
    \ += F;\n        }\n        return ans;\n    }\n};"
  dependsOn:
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: latest/Graph/FordFulkerson.hpp
  requiredBy: []
  timestamp: '2023-09-01 21:17:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_latest/AOJ-GRL-6-A.test.cpp
documentation_of: latest/Graph/FordFulkerson.hpp
layout: document
title: "Ford-Fulkerson - \u6700\u5927\u6D41"
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

最小費用流問題をPrimal Dual法を用いて求める。

## Variable



## Function

- `PrimalDual(Graph G)` : `Graph`で初期化する。
- `solve(Vertex Start, Vertex Goal, CostType F)` : 頂点`Start`から頂点`Goal`へ流量`F`を流した時の最小費用流を求める。流せない場合、`-1`を返す。$O(FE \log V)$