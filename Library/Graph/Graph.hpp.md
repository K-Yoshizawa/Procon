---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/BellmanFord.hpp
    title: Library/Graph/BellmanFord.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/CycleDetection.hpp
    title: Library/Graph/CycleDetection.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Dijkstra.hpp
    title: Library/Graph/Dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/GraphUtilities.hpp
    title: Library/Graph/GraphUtilities.hpp
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
    title: Library/Graph/WarshallFloyd.hpp
  - icon: ':warning:'
    path: Library/String/Trie.hpp
    title: Library/String/Trie.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Tree/HeavyLightDecomposition.hpp
    title: Library/Tree/HeavyLightDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Tree/LowestCommonAncestor.hpp
    title: Library/Tree/LowestCommonAncestor.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Tree/RerootingDP.hpp
    title: Library/Tree/RerootingDP.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Tree/Tree.hpp
    title: Library/Tree/Tree.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Tree/TreeDiameter.hpp
    title: Library/Tree/TreeDiameter.hpp
  - icon: ':warning:'
    path: Library/Tree/tmp.hpp
    title: Library/Tree/tmp.hpp
  - icon: ':warning:'
    path: Library/unauthenticated/AuxiliaryTree.hpp
    title: Library/unauthenticated/AuxiliaryTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-ALDS1-7-A.test.cpp
    title: verify/AOJ-ALDS1-7-A.test.cpp
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
    path: verify/AOJ-GRL-5-A.test.cpp
    title: verify/AOJ-GRL-5-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-B.test.cpp
    title: verify/AOJ-GRL-5-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-C.test.cpp
    title: verify/AOJ-GRL-5-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-CycleDetection.test.cpp
    title: verify/LC-CycleDetection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-CycleDetectionUndirected.test.cpp
    title: verify/LC-CycleDetectionUndirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-JumponTree.test.cpp
    title: verify/LC-JumponTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-LowestCommonAncestor-HLD.test.cpp
    title: verify/LC-LowestCommonAncestor-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-LowestCommonAncestor.test.cpp
    title: verify/LC-LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-MinimumSpanningTree.test.cpp
    title: verify/LC-MinimumSpanningTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-ShortestPath.test.cpp
    title: verify/LC-ShortestPath.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-StronglyConnectedComponents.test.cpp
    title: verify/LC-StronglyConnectedComponents.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-TreeDiameter.test.cpp
    title: verify/LC-TreeDiameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-TreePathCompositeSum.test.cpp
    title: verify/LC-TreePathCompositeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexAddPathSum.test.cpp
    title: verify/LC-VertexAddPathSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexAddSubtreeSum.test.cpp
    title: verify/LC-VertexAddSubtreeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexSetPathComposite.test.cpp
    title: verify/LC-VertexSetPathComposite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Graph.hpp\"\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bit>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 4 \"Library/Graph/Graph.hpp\"\n\nusing Vertex = int;\n\ntemplate<typename\
    \ Ordered = int32_t>\nstruct Edge{\n    public:\n    Edge() = default;\n\n   \
    \ Edge(Vertex from_, Vertex to_, Ordered weight_ = 1, int idx_ = -1) :\n     \
    \   from(from_), to(to_), cost(weight_), idx(idx_){}\n    \n    bool operator<(const\
    \ Edge<Ordered> &e) const {return cost < e.cost;}\n\n    operator int() const\
    \ {return to;}\n\n    Vertex from, to;\n    Ordered cost;\n    int idx;\n};\n\n\
    template<typename Ordered = int32_t>\nclass Graph{\n    public:\n    Graph() =\
    \ default;\n\n    Graph(int V) : edge_size_(0), adjacent_list_(V){}\n    \n  \
    \  inline void AddUndirectedEdge(Vertex u, Vertex v, Ordered w = 1){\n       \
    \ int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<Ordered>(u,\
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
    \ w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n"
  code: "#pragma once\n\n#include \"../Common.hpp\"\n\nusing Vertex = int;\n\ntemplate<typename\
    \ Ordered = int32_t>\nstruct Edge{\n    public:\n    Edge() = default;\n\n   \
    \ Edge(Vertex from_, Vertex to_, Ordered weight_ = 1, int idx_ = -1) :\n     \
    \   from(from_), to(to_), cost(weight_), idx(idx_){}\n    \n    bool operator<(const\
    \ Edge<Ordered> &e) const {return cost < e.cost;}\n\n    operator int() const\
    \ {return to;}\n\n    Vertex from, to;\n    Ordered cost;\n    int idx;\n};\n\n\
    template<typename Ordered = int32_t>\nclass Graph{\n    public:\n    Graph() =\
    \ default;\n\n    Graph(int V) : edge_size_(0), adjacent_list_(V){}\n    \n  \
    \  inline void AddUndirectedEdge(Vertex u, Vertex v, Ordered w = 1){\n       \
    \ int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<Ordered>(u,\
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
    \ w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Graph/Graph.hpp
  requiredBy:
  - Library/Tree/Tree.hpp
  - Library/Tree/HeavyLightDecomposition.hpp
  - Library/Tree/tmp.hpp
  - Library/Tree/TreeDiameter.hpp
  - Library/Tree/RerootingDP.hpp
  - Library/Tree/LowestCommonAncestor.hpp
  - Library/String/Trie.hpp
  - Library/Graph/StronglyConnectedComponents.hpp
  - Library/Graph/LowLink.hpp
  - Library/Graph/Kruskal.hpp
  - Library/Graph/Dijkstra.hpp
  - Library/Graph/BellmanFord.hpp
  - Library/Graph/CycleDetection.hpp
  - Library/Graph/GraphUtilities.hpp
  - Library/Graph/WarshallFloyd.hpp
  - Library/unauthenticated/AuxiliaryTree.hpp
  timestamp: '2026-06-01 14:23:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-5-B.test.cpp
  - verify/LC-CycleDetection.test.cpp
  - verify/AOJ-GRL-4-A.test.cpp
  - verify/AOJ-ALDS1-7-A.test.cpp
  - verify/LC-TreePathCompositeSum.test.cpp
  - verify/AOJ-GRL-1-C.test.cpp
  - verify/AOJ-GRL-1-A.test.cpp
  - verify/LC-LowestCommonAncestor-HLD.test.cpp
  - verify/LC-VertexAddPathSum.test.cpp
  - verify/AOJ-GRL-3-B.test.cpp
  - verify/LC-ShortestPath.test.cpp
  - verify/LC-LowestCommonAncestor.test.cpp
  - verify/AOJ-GRL-1-B.test.cpp
  - verify/LC-StronglyConnectedComponents.test.cpp
  - verify/LC-CycleDetectionUndirected.test.cpp
  - verify/AOJ-GRL-5-C.test.cpp
  - verify/AOJ-GRL-3-C.test.cpp
  - verify/LC-TreeDiameter.test.cpp
  - verify/LC-VertexSetPathComposite.test.cpp
  - verify/LC-VertexAddSubtreeSum.test.cpp
  - verify/LC-JumponTree.test.cpp
  - verify/LC-MinimumSpanningTree.test.cpp
  - verify/AOJ-GRL-3-A.test.cpp
  - verify/AOJ-GRL-5-A.test.cpp
documentation_of: Library/Graph/Graph.hpp
layout: document
title: "Graph - \u30B0\u30E9\u30D5\u69CB\u9020"
---

# Graph - グラフ構造

無向 / 有向グラフを扱うクラスです。

## Function

### Constructor

```
Graph<Ordered>(int V)
```

- $V$ 頂点 $0$ 辺のグラフを構築します。
- 頂点には $0, 1, \dots, V - 1$ の番号が振られているとします。
- `Ordered` は辺の重みの型を表します。省略した場合は `int32_t` となります。

**制約**

- $0 \le V \le 10^6$

**計算量**

- $\textrm{O}(V)$

---

### AddUndirectedEdge

```
void AddUndirectedEdge(Vertex u, Vertex v, Ordered w = 1)
```

- 頂点 $u, v$ 間に重み $w$ の無向辺を張ります。
- 重み $w$ は省略することが可能です。省略した場合の重みは $1$ となります。

**制約**

- $0 \le u, v \lt V$

**計算量**

- $\textrm{O}(1)$

---

### AddDirectedEdge

```
void AddDirectedEdge(Vertex u, Vertex v, Ordered w = 1)
```

- 頂点 $u$ から頂点 $v$ に重み $w$ の有向辺を張ります。
- 重み $w$ は省略することが可能です。省略した場合は重みは $1$ となります。

**制約**

- $0 \le u, v \lt V$

**計算量**

- $\textrm{O}(1)$

---

### VertexSize

```
inline size_t VertexSize() const
```

- グラフ $G$ の頂点数 $V$ を取得します。

**計算量**

- $\textrm{O}(1)$

---

### EdgeSize

```
inline size_t EdgeSize() const
```

- グラフ $G$ の辺数 $E$ を取得します。

**計算量**

- $\textrm{O}(1)$

---

### operator[]

```
(1) vector<Edge<Ordered>> &operator[](const Vertex v)
(1) const vector<Edge<Ordered>> &operator[](const Vertex v) const
```

- 頂点 $v$ から出次している辺の一覧を取得します。

```
(1) for(auto e : G[u])
(2) for(Vertex v : G[u])
```

- (1) $G$ の頂点 $u$ から出次している**辺**の一覧(`std::vector<Edge<Ordered>>`)を取得します。
- (2) $G$ の頂点 $u$ に隣接している頂点 $v$ の一覧(`std::vector<Vertex>`)を取得します。

**制約**

- $0 \le v \lt V$

**計算量**

- $\textrm{O}(1)$

---

最終更新 : Ver.6.0.0

---