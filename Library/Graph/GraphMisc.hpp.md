---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/BellmanFord.hpp
    title: "Bellman Ford - \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Kruskal.hpp
    title: Library/Graph/Kruskal.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/StronglyConnectedComponents.hpp
    title: Library/Graph/StronglyConnectedComponents.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/WarshallFloyd.hpp
    title: "Warshall Floyd - \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\
      \u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-B.test.cpp
    title: verify/AOJ-GRL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-C.test.cpp
    title: verify/AOJ-GRL-1-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-C.test.cpp
    title: verify/AOJ-GRL-3-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-MinimumSpanningTree.test.cpp
    title: verify/LC-MinimumSpanningTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-StronglyConnectedComponents.test.cpp
    title: verify/LC-StronglyConnectedComponents.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/GraphMisc.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (1LL << 30) -\
    \ 1;\n#line 4 \"Library/Graph/Graph.hpp\"\n\nusing Vertex = int;\n\ntemplate<typename\
    \ CostType = int32_t>\nstruct Edge{\n    public:\n    Edge() = default;\n\n  \
    \  Edge(Vertex from_, Vertex to_, CostType cost_ = 1, int idx_ = -1) :\n     \
    \   from(from_), to(to_), cost(cost_), idx(idx_){}\n    \n    bool operator<(const\
    \ Edge<CostType> &e) const {return cost < e.cost;}\n\n    operator int() const\
    \ {return to;}\n\n    Vertex from, to;\n    CostType cost;\n    int idx;\n};\n\
    \ntemplate<typename CostType = int32_t>\nclass Graph{\n    public:\n    Graph()\
    \ = default;\n\n    Graph(int n) : vertex_size_(n), edge_size_(0), adjacent_list_(n){}\n\
    \    \n    inline void AddUndirectedEdge(Vertex u, Vertex v, CostType w = 1){\n\
    \        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<CostType>(u,\
    \ v, w, idx));\n        adjacent_list_[v].push_back(Edge<CostType>(v, u, w, idx));\n\
    \    }\n    \n    inline void AddDirectedEdge(Vertex u, Vertex v, CostType w =\
    \ 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<CostType>(u,\
    \ v, w, idx));\n    }\n\n    inline size_t VertexSize() const {\n        return\
    \ vertex_size_;\n    }\n\n    inline size_t EdgeSize() const {\n        return\
    \ edge_size_;\n    }\n\n    inline vector<Edge<CostType>> &operator[](const int\
    \ v){\n        return adjacent_list_[v];\n    }\n\n    inline const vector<Edge<CostType>>\
    \ &operator[](const int v) const {\n        return adjacent_list_[v];\n    }\n\
    \    \n    private:\n    size_t vertex_size_, edge_size_;\n    vector<vector<Edge<CostType>>>\
    \ adjacent_list_;\n};\n\ntemplate<typename CostType = int32_t>\nGraph<CostType>\
    \ InputGraph(int N, int M, int padding = -1, bool weighted = false, bool directed\
    \ = false){\n    Graph<CostType> G(N);\n    for(int i = 0; i < M; ++i){\n    \
    \    Vertex u, v; CostType w = 1;\n        cin >> u >> v, u += padding, v += padding;\n\
    \        if(weighted) cin >> w;\n        if(directed) G.AddDirectedEdge(u, v,\
    \ w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n#line\
    \ 4 \"Library/Graph/GraphMisc.hpp\"\n\ntemplate<typename CostType>\nvector<Edge<CostType>>\
    \ ConvertEdgeSet(const Graph<CostType> &G){\n    vector<Edge<CostType>> ret;\n\
    \    vector<bool> check(G.EdgeSize(), false);\n    int n = G.VertexSize();\n \
    \   for(int u = 0; u < n; ++u){\n        for(const Edge<CostType> &e : G[u]){\n\
    \            if(check[e.idx]) continue;\n            check[e.idx] = true;\n  \
    \          ret.push_back(e);\n        }\n    }\n    return ret;\n}\n\ntemplate<typename\
    \ CostType>\nvector<vector<CostType>> ConvertDistanceMatrix(const Graph<CostType>\
    \ &G){\n    int n = G.VertexSize();\n    vector<vector<CostType>> ret(n, vector<CostType>(n,\
    \ CostType(INF)));\n    for(int u = 0; u < n; ++u){\n        ret[u][u] = CostType(0);\n\
    \        for(const Edge<CostType> &e : G[u]){\n            ret[u][e.to] = e.cost;\n\
    \        }\n    }\n    return ret;\n}\n\ntemplate<typename CostType>\nGraph<CostType>\
    \ ReverseGraph(const Graph<CostType> &G){\n    int n = G.VertexSize();\n    Graph<CostType>\
    \ ret(n);\n    for(int u = 0; u < n; ++u){\n        for(const Edge<CostType> &e\
    \ : G[u]){\n            ret.AddDirectedEdge(e.to, e.from, e.cost);\n        }\n\
    \    }\n    return ret;\n}\n"
  code: "#pragma once\n\n#include \"Graph.hpp\"\n\ntemplate<typename CostType>\nvector<Edge<CostType>>\
    \ ConvertEdgeSet(const Graph<CostType> &G){\n    vector<Edge<CostType>> ret;\n\
    \    vector<bool> check(G.EdgeSize(), false);\n    int n = G.VertexSize();\n \
    \   for(int u = 0; u < n; ++u){\n        for(const Edge<CostType> &e : G[u]){\n\
    \            if(check[e.idx]) continue;\n            check[e.idx] = true;\n  \
    \          ret.push_back(e);\n        }\n    }\n    return ret;\n}\n\ntemplate<typename\
    \ CostType>\nvector<vector<CostType>> ConvertDistanceMatrix(const Graph<CostType>\
    \ &G){\n    int n = G.VertexSize();\n    vector<vector<CostType>> ret(n, vector<CostType>(n,\
    \ CostType(INF)));\n    for(int u = 0; u < n; ++u){\n        ret[u][u] = CostType(0);\n\
    \        for(const Edge<CostType> &e : G[u]){\n            ret[u][e.to] = e.cost;\n\
    \        }\n    }\n    return ret;\n}\n\ntemplate<typename CostType>\nGraph<CostType>\
    \ ReverseGraph(const Graph<CostType> &G){\n    int n = G.VertexSize();\n    Graph<CostType>\
    \ ret(n);\n    for(int u = 0; u < n; ++u){\n        for(const Edge<CostType> &e\
    \ : G[u]){\n            ret.AddDirectedEdge(e.to, e.from, e.cost);\n        }\n\
    \    }\n    return ret;\n}"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Graph/GraphMisc.hpp
  requiredBy:
  - Library/Graph/WarshallFloyd.hpp
  - Library/Graph/StronglyConnectedComponents.hpp
  - Library/Graph/BellmanFord.hpp
  - Library/Graph/Kruskal.hpp
  timestamp: '2025-03-23 23:54:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-B.test.cpp
  - verify/AOJ-GRL-3-C.test.cpp
  - verify/AOJ-GRL-1-C.test.cpp
  - verify/LC-MinimumSpanningTree.test.cpp
  - verify/LC-StronglyConnectedComponents.test.cpp
documentation_of: Library/Graph/GraphMisc.hpp
layout: document
redirect_from:
- /library/Library/Graph/GraphMisc.hpp
- /library/Library/Graph/GraphMisc.hpp.html
title: Library/Graph/GraphMisc.hpp
---
