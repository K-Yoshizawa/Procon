---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-A.test.cpp
    title: verify/AOJ-GRL-3-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-B.test.cpp
    title: verify/AOJ-GRL-3-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/LowLink.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\
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
    \ 4 \"Library/Graph/LowLink.hpp\"\n\ntemplate<typename CostType>\nclass LowLink{\n\
    \    public:\n    LowLink(Graph<CostType> &graph) : G(graph), n(graph.VertexSize()),\
    \ ord_(n, -1), low_(n, -1), in_(n), out_(n){\n        for(int i = 0, k = 0, t\
    \ = 0; i < n; ++i){\n            if(ord_[i] == -1){\n                k = dfs(i,\
    \ -1, k, t);\n            }\n        }\n    }\n\n    vector<Vertex> &ArticulationVertex(){\n\
    \        return articulation_vertex_;\n    }\n\n    vector<pair<Vertex, Vertex>>\
    \ &Bridge(){\n        return bridge_;\n    }\n\n    pair<int, int> EulerTour(const\
    \ Vertex v) const {\n        return {in_[v], out_[v]};\n    }\n\n    private:\n\
    \    Graph<CostType> &G;\n    int n;\n    vector<int> ord_, low_, in_, out_;\n\
    \    vector<Vertex> articulation_vertex_;\n    vector<pair<Vertex, Vertex>> bridge_;\n\
    \n    int dfs(Vertex v, int p, int k, int &t){\n        in_[v] = t++;\n      \
    \  low_[v] = (ord_[v] = k++);\n        int cnt = 0;\n        bool is_articulation\
    \ = false, second = false;\n        for(int u : G[v]){\n            if(ord_[u]\
    \ == -1){\n                ++cnt;\n                k = dfs(u, v, k, t);\n    \
    \            low_[v] = min(low_[v], low_[u]);\n                is_articulation\
    \ |= (p != -1) && (low_[u] >= ord_[v]);\n                if(ord_[v] < low_[u]){\n\
    \                    bridge_.emplace_back(minmax(u, v));\n                }\n\
    \            }\n            else if(u != p || second){\n                low_[v]\
    \ = min(low_[v], ord_[u]);\n            }\n            else{\n               \
    \ second = true;\n            }\n        }\n        is_articulation |= (p == -1)\
    \ && (cnt > 1);\n        if(is_articulation) articulation_vertex_.emplace_back(v);\n\
    \        out_[v] = t;\n        return k;\n    }\n};\n"
  code: "#pragma once\n\n#include \"Graph.hpp\"\n\ntemplate<typename CostType>\nclass\
    \ LowLink{\n    public:\n    LowLink(Graph<CostType> &graph) : G(graph), n(graph.VertexSize()),\
    \ ord_(n, -1), low_(n, -1), in_(n), out_(n){\n        for(int i = 0, k = 0, t\
    \ = 0; i < n; ++i){\n            if(ord_[i] == -1){\n                k = dfs(i,\
    \ -1, k, t);\n            }\n        }\n    }\n\n    vector<Vertex> &ArticulationVertex(){\n\
    \        return articulation_vertex_;\n    }\n\n    vector<pair<Vertex, Vertex>>\
    \ &Bridge(){\n        return bridge_;\n    }\n\n    pair<int, int> EulerTour(const\
    \ Vertex v) const {\n        return {in_[v], out_[v]};\n    }\n\n    private:\n\
    \    Graph<CostType> &G;\n    int n;\n    vector<int> ord_, low_, in_, out_;\n\
    \    vector<Vertex> articulation_vertex_;\n    vector<pair<Vertex, Vertex>> bridge_;\n\
    \n    int dfs(Vertex v, int p, int k, int &t){\n        in_[v] = t++;\n      \
    \  low_[v] = (ord_[v] = k++);\n        int cnt = 0;\n        bool is_articulation\
    \ = false, second = false;\n        for(int u : G[v]){\n            if(ord_[u]\
    \ == -1){\n                ++cnt;\n                k = dfs(u, v, k, t);\n    \
    \            low_[v] = min(low_[v], low_[u]);\n                is_articulation\
    \ |= (p != -1) && (low_[u] >= ord_[v]);\n                if(ord_[v] < low_[u]){\n\
    \                    bridge_.emplace_back(minmax(u, v));\n                }\n\
    \            }\n            else if(u != p || second){\n                low_[v]\
    \ = min(low_[v], ord_[u]);\n            }\n            else{\n               \
    \ second = true;\n            }\n        }\n        is_articulation |= (p == -1)\
    \ && (cnt > 1);\n        if(is_articulation) articulation_vertex_.emplace_back(v);\n\
    \        out_[v] = t;\n        return k;\n    }\n};"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Graph/LowLink.hpp
  requiredBy: []
  timestamp: '2025-04-06 18:24:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-3-A.test.cpp
  - verify/AOJ-GRL-3-B.test.cpp
documentation_of: Library/Graph/LowLink.hpp
layout: document
redirect_from:
- /library/Library/Graph/LowLink.hpp
- /library/Library/Graph/LowLink.hpp.html
title: Library/Graph/LowLink.hpp
---
