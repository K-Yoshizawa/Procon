---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u69CB\u9020"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/BellmanFord.hpp
    title: Library/Graph/BellmanFord.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Kruskal.hpp
    title: Library/Graph/Kruskal.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/StronglyConnectedComponents.hpp
    title: Library/Graph/StronglyConnectedComponents.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/WarshallFloyd.hpp
    title: Library/Graph/WarshallFloyd.hpp
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
  bundledCode: "#line 2 \"Library/Graph/GraphUtilities.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n#include <cassert>\n\
    #include <cmath>\n#include <cstdint>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const ll INF = (1LL\
    \ << 62) - (3LL << 30) - 1;\n#line 4 \"Library/Graph/Graph.hpp\"\n\nusing Vertex\
    \ = int;\n\ntemplate<typename Ordered = int32_t>\nstruct Edge{\n    public:\n\
    \    Edge() = default;\n\n    Edge(Vertex from_, Vertex to_, Ordered weight_ =\
    \ 1, int idx_ = -1) :\n        from(from_), to(to_), cost(weight_), idx(idx_){}\n\
    \    \n    bool operator<(const Edge<Ordered> &e) const {return cost < e.cost;}\n\
    \n    operator int() const {return to;}\n\n    Vertex from, to;\n    Ordered cost;\n\
    \    int idx;\n};\n\ntemplate<typename Ordered = int32_t>\nclass Graph{\n    public:\n\
    \    Graph() = default;\n\n    Graph(int V) : edge_size_(0), adjacent_list_(V){}\n\
    \    \n    inline void AddUndirectedEdge(Vertex u, Vertex v, Ordered w = 1){\n\
    \        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<Ordered>(u,\
    \ v, w, idx));\n        adjacent_list_[v].push_back(Edge<Ordered>(v, u, w, idx));\n\
    \    }\n    \n    inline void AddDirectedEdge(Vertex u, Vertex v, Ordered w =\
    \ 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<Ordered>(u,\
    \ v, w, idx));\n    }\n\n    inline size_t VertexSize() const {\n        return\
    \ adjacent_list_.size();\n    }\n\n    inline size_t EdgeSize() const {\n    \
    \    return edge_size_;\n    }\n\n    inline vector<Edge<Ordered>> &operator[](const\
    \ Vertex v){\n        return adjacent_list_[v];\n    }\n\n    inline const vector<Edge<Ordered>>\
    \ &operator[](const Vertex v) const {\n        return adjacent_list_[v];\n   \
    \ }\n    \n    private:\n    size_t edge_size_;\n    vector<vector<Edge<Ordered>>>\
    \ adjacent_list_;\n};\n\ntemplate<typename Ordered = int32_t>\nGraph<Ordered>\
    \ InputGraph(int V, int E, int padding = -1, bool weighted = false, bool directed\
    \ = false){\n    Graph<Ordered> G(V);\n    for(int i = 0; i < E; ++i){\n     \
    \   Vertex u, v; Ordered w = 1;\n        cin >> u >> v, u += padding, v += padding;\n\
    \        if(weighted) cin >> w;\n        if(directed) G.AddDirectedEdge(u, v,\
    \ w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n#line\
    \ 4 \"Library/Graph/GraphUtilities.hpp\"\n\ntemplate<typename WeightType>\nvector<Edge<WeightType>>\
    \ ConvertEdgeSet(const Graph<WeightType> &G){\n    vector<Edge<WeightType>> ret;\n\
    \    vector<bool> check(G.EdgeSize(), false);\n    int V = G.VertexSize();\n \
    \   for(int u = 0; u < V; ++u){\n        for(const Edge<WeightType> &e : G[u]){\n\
    \            if(check[e.idx]) continue;\n            check[e.idx] = true;\n  \
    \          ret.push_back(e);\n        }\n    }\n    return ret;\n}\n\ntemplate<typename\
    \ WeightType>\nvector<vector<WeightType>> ConvertDistanceMatrix(const Graph<WeightType>\
    \ &G){\n    int V = G.VertexSize();\n    vector<vector<WeightType>> ret(V, vector<WeightType>(V,\
    \ WeightType(INF)));\n    for(int u = 0; u < V; ++u){\n        ret[u][u] = WeightType(0);\n\
    \        for(const Edge<WeightType> &e : G[u]){\n            ret[u][e.to] = e.cost;\n\
    \        }\n    }\n    return ret;\n}\n\ntemplate<typename WeightType>\nGraph<WeightType>\
    \ ReverseGraph(const Graph<WeightType> &G){\n    int V = G.VertexSize();\n   \
    \ Graph<WeightType> ret(V);\n    for(int u = 0; u < V; ++u){\n        for(const\
    \ Edge<WeightType> &e : G[u]){\n            ret.AddDirectedEdge(e.to, e.from,\
    \ e.cost);\n        }\n    }\n    return ret;\n}\n"
  code: "#pragma once\n\n#include \"Graph.hpp\"\n\ntemplate<typename WeightType>\n\
    vector<Edge<WeightType>> ConvertEdgeSet(const Graph<WeightType> &G){\n    vector<Edge<WeightType>>\
    \ ret;\n    vector<bool> check(G.EdgeSize(), false);\n    int V = G.VertexSize();\n\
    \    for(int u = 0; u < V; ++u){\n        for(const Edge<WeightType> &e : G[u]){\n\
    \            if(check[e.idx]) continue;\n            check[e.idx] = true;\n  \
    \          ret.push_back(e);\n        }\n    }\n    return ret;\n}\n\ntemplate<typename\
    \ WeightType>\nvector<vector<WeightType>> ConvertDistanceMatrix(const Graph<WeightType>\
    \ &G){\n    int V = G.VertexSize();\n    vector<vector<WeightType>> ret(V, vector<WeightType>(V,\
    \ WeightType(INF)));\n    for(int u = 0; u < V; ++u){\n        ret[u][u] = WeightType(0);\n\
    \        for(const Edge<WeightType> &e : G[u]){\n            ret[u][e.to] = e.cost;\n\
    \        }\n    }\n    return ret;\n}\n\ntemplate<typename WeightType>\nGraph<WeightType>\
    \ ReverseGraph(const Graph<WeightType> &G){\n    int V = G.VertexSize();\n   \
    \ Graph<WeightType> ret(V);\n    for(int u = 0; u < V; ++u){\n        for(const\
    \ Edge<WeightType> &e : G[u]){\n            ret.AddDirectedEdge(e.to, e.from,\
    \ e.cost);\n        }\n    }\n    return ret;\n}"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Graph/GraphUtilities.hpp
  requiredBy:
  - Library/Graph/StronglyConnectedComponents.hpp
  - Library/Graph/Kruskal.hpp
  - Library/Graph/BellmanFord.hpp
  - Library/Graph/WarshallFloyd.hpp
  timestamp: '2026-06-01 14:23:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-C.test.cpp
  - verify/AOJ-GRL-1-B.test.cpp
  - verify/LC-StronglyConnectedComponents.test.cpp
  - verify/AOJ-GRL-3-C.test.cpp
  - verify/LC-MinimumSpanningTree.test.cpp
documentation_of: Library/Graph/GraphUtilities.hpp
layout: document
redirect_from:
- /library/Library/Graph/GraphUtilities.hpp
- /library/Library/Graph/GraphUtilities.hpp.html
title: Library/Graph/GraphUtilities.hpp
---
