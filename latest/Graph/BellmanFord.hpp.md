---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-1-B-Dijkstra.test.cpp
    title: verify_latest/AOJ-GRL-1-B-Dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-1-B.test.cpp
    title: verify_latest/AOJ-GRL-1-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "BellmanFord - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
    links: []
  bundledCode: "#line 1 \"latest/Graph/BellmanFord.hpp\"\n/**\n * @file BellmanFord.hpp\n\
    \ * @author log_K (lX57)\n * @brief BellmanFord - \u5358\u4E00\u59CB\u70B9\u6700\
    \u77ED\u8DDD\u96E2\n * @version 2.0\n * @date 2023-08-31\n */\n\n#line 2 \"latest/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 2.1\n * @date 2023-08-31\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing Vertex = int;\nusing EdgeID = int;\n\ntemplate<typename CostType>\nstruct\
    \ Edge{\n    Vertex from, to;\n    CostType cost, cap;\n\n    Edge(Vertex from,\
    \ Vertex to, CostType cost) : from(from), to(to), cost(cost), cap(1){}\n    Edge(Vertex\
    \ from, Vertex to, CostType cap, CostType cost) : from(from), to(to), cost(cost),\
    \ cap(cap){}\n\n    Vertex getto(Vertex v){\n        assert(v == from || v ==\
    \ to);\n        return from ^ to ^ v;\n    }\n\n    void swap(){\n        Vertex\
    \ tmp = from;\n        from = to;\n        to = tmp;\n    }\n};\n\ntemplate<typename\
    \ CostType>\nstruct Graph{\n    private:\n    int __CntVertex, __CntEdge;\n  \
    \  bool __isDirected;\n    vector<Edge<CostType>> __EdgeSet, __RevEdgeSet;\n \
    \   vector<vector<pair<EdgeID, bool>>> __IncidentList;\n    vector<pair<int, int>>\
    \ __EdgePlace;\n\n    public:\n    CostType INF;\n\n    Graph(int VertexSize,\
    \ bool isDirected = false) : __CntVertex(VertexSize), __isDirected(isDirected),\
    \ __CntEdge(0), __IncidentList(VertexSize), INF(numeric_limits<CostType>::max()\
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
    \        return __IncidentList[v];\n    }\n\n    vector<pair<Vertex, EdgeID>>\
    \ convert_rootedtree(Vertex Root = 0){\n        assert(0 <= Root && Root < __CntVertex);\n\
    \        vector<pair<Vertex, EdgeID>> ret(__CntVertex, {-1, -1});\n        vector<int>\
    \ visited(__CntVertex, 0);\n        queue<Vertex> que;\n        que.push(Root);\n\
    \        while(que.size()){\n            Vertex now = que.front(); que.pop();\n\
    \            if(visited[now]) continue;\n            visited[now] = 1;\n     \
    \       for(int i = 0; i < __IncidentList[now].size(); ++i){\n               \
    \ auto [eid, rev] = __IncidentList[now][i];\n                Edge<CostType> e\
    \ = get_edge(eid, rev);\n                if(visited[e.to]) continue;\n       \
    \         que.push(e.to);\n                ret[e.to] = {now, eid};\n         \
    \       if(rev){\n                    __IncidentList[e.from][__EdgePlace[eid].second].second\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"latest/Graph/BellmanFord.hpp\"\
    \n\ntemplate<typename CostType>\nvector<CostType> BellmanFord(Graph<CostType>\
    \ &G, Vertex Start){\n    vector<CostType> ret(G.vsize(), G.INF);\n    ret[Start]\
    \ = 0;\n    int updatecount = 0;\n    while(1){\n        if(updatecount == G.vsize()){\n\
    \            return vector<CostType>{};\n        }\n        bool update = false;\n\
    \        for(Edge<CostType> &e : G.get_edgeset()){\n            if(ret[e.from]\
    \ == G.INF) continue;\n            if(ret[e.to] > ret[e.from] + e.cost){\n   \
    \             ret[e.to] = ret[e.from] + e.cost;\n                update = true;\n\
    \            }\n        }\n        if(!update) break;\n        ++updatecount;\n\
    \    }\n    return ret;\n}\n"
  code: "/**\n * @file BellmanFord.hpp\n * @author log_K (lX57)\n * @brief BellmanFord\
    \ - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2\n * @version 2.0\n * @date\
    \ 2023-08-31\n */\n\n#include \"GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    vector<CostType> BellmanFord(Graph<CostType> &G, Vertex Start){\n    vector<CostType>\
    \ ret(G.vsize(), G.INF);\n    ret[Start] = 0;\n    int updatecount = 0;\n    while(1){\n\
    \        if(updatecount == G.vsize()){\n            return vector<CostType>{};\n\
    \        }\n        bool update = false;\n        for(Edge<CostType> &e : G.get_edgeset()){\n\
    \            if(ret[e.from] == G.INF) continue;\n            if(ret[e.to] > ret[e.from]\
    \ + e.cost){\n                ret[e.to] = ret[e.from] + e.cost;\n            \
    \    update = true;\n            }\n        }\n        if(!update) break;\n  \
    \      ++updatecount;\n    }\n    return ret;\n}"
  dependsOn:
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: latest/Graph/BellmanFord.hpp
  requiredBy: []
  timestamp: '2023-09-02 20:49:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_latest/AOJ-GRL-1-B-Dijkstra.test.cpp
  - verify_latest/AOJ-GRL-1-B.test.cpp
documentation_of: latest/Graph/BellmanFord.hpp
layout: document
title: "BellmanFord - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
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

単一始点最短距離問題をBellmanFord法を用いて求める。

## Function

- `BellmanFord(Graph G, Vertex Start)` : 頂点`Start`を始点として単一始点最短距離問題を解く。$O(VE)$
    - 負閉路が存在する場合、空列を返す。
    - そうでない場合、各頂点への最短距離を返す。
