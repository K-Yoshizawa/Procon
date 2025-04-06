---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/BellmanFord.hpp
    title: "Bellman Ford - \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/CycleDetection.hpp
    title: Library/Graph/CycleDetection.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Dijkstra.hpp
    title: "Dijkstra - \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/GraphMisc.hpp
    title: Library/Graph/GraphMisc.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Kruskal.hpp
    title: Library/Graph/Kruskal.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/LowLink.hpp
    title: Library/Graph/LowLink.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/StronglyConnectedComponents.hpp
    title: Library/Graph/StronglyConnectedComponents.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/WarshallFloyd.hpp
    title: "Warshall Floyd - \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\
      \u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-A.test.cpp
    title: verify/AOJ-GRL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-B.test.cpp
    title: verify/AOJ-GRL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-C.test.cpp
    title: verify/AOJ-GRL-1-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-A.test.cpp
    title: verify/AOJ-GRL-3-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-B.test.cpp
    title: verify/AOJ-GRL-3-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-C.test.cpp
    title: verify/AOJ-GRL-3-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-4-A.test.cpp
    title: verify/AOJ-GRL-4-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-CycleDetection.test.cpp
    title: verify/LC-CycleDetection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-CycleDetectionUndirected.test.cpp
    title: verify/LC-CycleDetectionUndirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-MinimumSpanningTree.test.cpp
    title: verify/LC-MinimumSpanningTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-ShortestPath.test.cpp
    title: verify/LC-ShortestPath.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-StronglyConnectedComponents.test.cpp
    title: verify/LC-StronglyConnectedComponents.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Graph.hpp\"\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr\
    \ const ll INF = (1LL << 62) - (1LL << 30) - 1;\n#line 4 \"Library/Graph/Graph.hpp\"\
    \n\nusing Vertex = int;\n\ntemplate<typename CostType = int32_t>\nstruct Edge{\n\
    \    public:\n    Edge() = default;\n\n    Edge(Vertex from_, Vertex to_, CostType\
    \ cost_ = 1, int idx_ = -1) :\n        from(from_), to(to_), cost(cost_), idx(idx_){}\n\
    \    \n    bool operator<(const Edge<CostType> &e) const {return cost < e.cost;}\n\
    \n    operator int() const {return to;}\n\n    Vertex from, to;\n    CostType\
    \ cost;\n    int idx;\n};\n\ntemplate<typename CostType = int32_t>\nclass Graph{\n\
    \    public:\n    Graph() = default;\n\n    Graph(int n) : vertex_size_(n), edge_size_(0),\
    \ adjacent_list_(n){}\n    \n    inline void AddUndirectedEdge(Vertex u, Vertex\
    \ v, CostType w = 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<CostType>(u,\
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
    \ w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n"
  code: "#pragma once\n\n#include \"../Common.hpp\"\n\nusing Vertex = int;\n\ntemplate<typename\
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
    \ w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Graph/Graph.hpp
  requiredBy:
  - Library/Graph/Dijkstra.hpp
  - Library/Graph/GraphMisc.hpp
  - Library/Graph/CycleDetection.hpp
  - Library/Graph/WarshallFloyd.hpp
  - Library/Graph/LowLink.hpp
  - Library/Graph/StronglyConnectedComponents.hpp
  - Library/Graph/BellmanFord.hpp
  - Library/Graph/Kruskal.hpp
  timestamp: '2025-03-20 23:31:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-B.test.cpp
  - verify/AOJ-GRL-3-A.test.cpp
  - verify/LC-CycleDetectionUndirected.test.cpp
  - verify/AOJ-GRL-3-C.test.cpp
  - verify/AOJ-GRL-1-C.test.cpp
  - verify/LC-ShortestPath.test.cpp
  - verify/AOJ-GRL-4-A.test.cpp
  - verify/AOJ-GRL-1-A.test.cpp
  - verify/LC-CycleDetection.test.cpp
  - verify/AOJ-GRL-3-B.test.cpp
  - verify/LC-MinimumSpanningTree.test.cpp
  - verify/LC-StronglyConnectedComponents.test.cpp
documentation_of: Library/Graph/Graph.hpp
layout: document
title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---

# Graph - グラフテンプレート

$n$ 頂点の無向 / 有向グラフを扱うテンプレートです。

## Function

### Constructor

```
Graph<CostType>(int n)
```

- $n$ 頂点 $0$ 辺のグラフを構築します。
- 頂点には $0, 1, \dots, n - 1$ の番号が振られているとします。
- `CostType` は辺の重みの型を表します。省略した場合は `int32_t` となります。

**制約**

- $0 \le n \le 10^6$

**計算量**

- $\textrm{O}(n)$

---

### AddUndirectedEdge

```
void AddUndirectedEdge(Vertex u, Vertex v, CostType w = 1)
```

- $2$ 頂点 $u, v$ 間に重み $w$ の無向辺を張ります。
- 重み $w$ は省略することが可能です。省略した場合は重みは $1$ となります。

**制約**

- $0 \le u, v \lt n$
- $w$ は `CostType` 型で表現できる値であること

**計算量**

- $\textrm{O}(1)$

---

### AddDirectedEdge

```
void AddDirectedEdge(Vertex u, Vertex v, CostType w = 1)
```

- 頂点 $u$ から頂点 $v$ に重み $w$ の有向辺を張ります。
- 重み $w$ は省略することが可能です。省略した場合は重みは $1$ となります。

**制約**

- $0 \le u, v \lt n$
- $w$ は `CostType` 型で表現できる値であること

**計算量**

- $\textrm{O}(1)$

---

### VertexSize

```
inline size_t VertexSize() const
```

- グラフ $G$ の頂点数を取得します。

**計算量**

- $\textrm{O}(1)$

---

### operator[]

```
(1) vector<Edge<CostType>> &operator[](const int v)
(1) const vector<Edge<CostType>> &operator[](const int v) const
```

- 頂点 $v$ から出次している辺の一覧を取得します。

```
(1) for(auto e : G[u])
(2) for(int v : G[u])
```

- (1) $G$ の頂点 $u$ から出次している**辺**の一覧(`std::vector<Edge<CostType>>`)を取得します。
- (2) $G$ の頂点 $u$ に隣接している頂点 $v$ の一覧(`std::vector<Vertex>`)を取得します。

**制約**

- $0 \le v \lt n$

**計算量**

- $\textrm{O}(1)$

