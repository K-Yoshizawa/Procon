---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/GraphMisc.hpp
    title: Library/Graph/GraphMisc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-B.test.cpp
    title: verify/AOJ-GRL-1-B.test.cpp
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
    \ const ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 4 \"Library/Graph/Graph.hpp\"\
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
    \ w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n#line\
    \ 2 \"Library/Graph/GraphMisc.hpp\"\n\n#line 4 \"Library/Graph/GraphMisc.hpp\"\
    \n\ntemplate<typename CostType>\nvector<Edge<CostType>> ConvertEdgeSet(const Graph<CostType>\
    \ &G){\n    vector<Edge<CostType>> ret;\n    vector<bool> check(G.EdgeSize(),\
    \ false);\n    int n = G.VertexSize();\n    for(int u = 0; u < n; ++u){\n    \
    \    for(const Edge<CostType> &e : G[u]){\n            if(check[e.idx]) continue;\n\
    \            check[e.idx] = true;\n            ret.push_back(e);\n        }\n\
    \    }\n    return ret;\n}\n\ntemplate<typename CostType>\nvector<vector<CostType>>\
    \ ConvertDistanceMatrix(const Graph<CostType> &G){\n    int n = G.VertexSize();\n\
    \    vector<vector<CostType>> ret(n, vector<CostType>(n, CostType(INF)));\n  \
    \  for(int u = 0; u < n; ++u){\n        ret[u][u] = CostType(0);\n        for(const\
    \ Edge<CostType> &e : G[u]){\n            ret[u][e.to] = e.cost;\n        }\n\
    \    }\n    return ret;\n}\n\ntemplate<typename CostType>\nGraph<CostType> ReverseGraph(const\
    \ Graph<CostType> &G){\n    int n = G.VertexSize();\n    Graph<CostType> ret(n);\n\
    \    for(int u = 0; u < n; ++u){\n        for(const Edge<CostType> &e : G[u]){\n\
    \            ret.AddDirectedEdge(e.to, e.from, e.cost);\n        }\n    }\n  \
    \  return ret;\n}\n#line 3 \"Library/Graph/BellmanFord.hpp\"\n\ntemplate<typename\
    \ CostType>\nclass BellmanFord{\n    public:\n    BellmanFord(Graph<CostType>\
    \ &graph, Vertex s = -1) :\n        G(graph), n(graph.VertexSize()), dist_(n){\n\
    \        if(s != -1) Solve(s);\n    }\n\n    inline bool Reachable(const Vertex\
    \ &t) const {\n        return dist_[t] != inf;\n    }\n\n    inline CostType Distance(const\
    \ Vertex &t) const {\n        return dist_[t];\n    }\n\n    inline bool Negative()\
    \ const {\n        return negative_cycle_;\n    }\n\n    void Solve(Vertex s){\n\
    \        fill(dist_.begin(), dist_.end(), inf);\n        dist_[s] = CostType(0);\n\
    \        negative_cycle_ = false;\n        int update_count = 0;\n        auto\
    \ E = ConvertEdgeSet(G);\n        while(1){\n            if(update_count == n){\n\
    \                negative_cycle_ = true;\n                break;\n           \
    \ }\n            bool update_flag = false;\n            for(const Edge<CostType>\
    \ &e : E){\n                if(dist_[e.from] == inf) continue;\n             \
    \   if(dist_[e.to] > dist_[e.from] + e.cost){\n                    dist_[e.to]\
    \ = dist_[e.from] + e.cost;\n                    update_flag = true;\n       \
    \         }\n            }\n            if(!update_flag) break;\n            ++update_count;\n\
    \        }\n    }\n\n    inline CostType operator[](const Vertex &t){\n      \
    \  return dist_[t];\n    }\n\n    inline const CostType operator[](const Vertex\
    \ &t) const {\n        return dist_[t];\n    }\n\n    private:\n    Graph<CostType>\
    \ &G;\n    int n;\n    CostType inf{CostType(INF)};\n    bool negative_cycle_;\n\
    \    vector<CostType> dist_;\n};\n"
  code: "#include \"Graph.hpp\"\n#include \"GraphMisc.hpp\"\n\ntemplate<typename CostType>\n\
    class BellmanFord{\n    public:\n    BellmanFord(Graph<CostType> &graph, Vertex\
    \ s = -1) :\n        G(graph), n(graph.VertexSize()), dist_(n){\n        if(s\
    \ != -1) Solve(s);\n    }\n\n    inline bool Reachable(const Vertex &t) const\
    \ {\n        return dist_[t] != inf;\n    }\n\n    inline CostType Distance(const\
    \ Vertex &t) const {\n        return dist_[t];\n    }\n\n    inline bool Negative()\
    \ const {\n        return negative_cycle_;\n    }\n\n    void Solve(Vertex s){\n\
    \        fill(dist_.begin(), dist_.end(), inf);\n        dist_[s] = CostType(0);\n\
    \        negative_cycle_ = false;\n        int update_count = 0;\n        auto\
    \ E = ConvertEdgeSet(G);\n        while(1){\n            if(update_count == n){\n\
    \                negative_cycle_ = true;\n                break;\n           \
    \ }\n            bool update_flag = false;\n            for(const Edge<CostType>\
    \ &e : E){\n                if(dist_[e.from] == inf) continue;\n             \
    \   if(dist_[e.to] > dist_[e.from] + e.cost){\n                    dist_[e.to]\
    \ = dist_[e.from] + e.cost;\n                    update_flag = true;\n       \
    \         }\n            }\n            if(!update_flag) break;\n            ++update_count;\n\
    \        }\n    }\n\n    inline CostType operator[](const Vertex &t){\n      \
    \  return dist_[t];\n    }\n\n    inline const CostType operator[](const Vertex\
    \ &t) const {\n        return dist_[t];\n    }\n\n    private:\n    Graph<CostType>\
    \ &G;\n    int n;\n    CostType inf{CostType(INF)};\n    bool negative_cycle_;\n\
    \    vector<CostType> dist_;\n};"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  - Library/Graph/GraphMisc.hpp
  isVerificationFile: false
  path: Library/Graph/BellmanFord.hpp
  requiredBy: []
  timestamp: '2025-04-30 01:32:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-B.test.cpp
documentation_of: Library/Graph/BellmanFord.hpp
layout: document
title: "Bellman Ford - \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5"
---

# Bellman Ford - ベルマンフォード法

$N$ 頂点 $M$ 辺のグラフにおける単一始点最短経路問題をベルマンフォード法を用いて解きます。

## Function

### Constructor

```
BellmanFord(Graph<CostType> &graph, Vertex s = -1)
```

- $N$ 頂点 $M$ 辺のグラフで初期化をします。
- `s` を指定すると、初期化後に `Solve(s)` を呼び出します。

**制約**

- $-1 \le s \le N$

**計算量**

- $\textrm{O}(N)$

---

### Reachable

```
inline bool Reachable(const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ に到達可能であるかを判定します。

**制約**

- $0 \le t \lt N$
- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

---

### Distance

```
inline CostType Distance(const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ への最短経路長を返します。
- 頂点 $t$ に到達不能であるとき、`INF` を返します。

**制約**

- $0 \le t \lt N$
- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

---

### Negative

```
inline bool Negative() const
```

- $G$ が負閉路を含むかを判定します。

**制約**

- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

---

### Solve

```
void Solve(Vertex s)
```

- 頂点 $s$ を始点とした単一始点最短経路問題を解きます。

**制約**

- $0 \le s \lt N$

**計算量**

- $\textrm{O}(NM)$

---

### operator[]

```
(1) CostType operator[](const Vertex &t)
(1) const CostType operator[](const Vertex &t) const 
```

- `Distance(t)` を返します。

**制約**

- $0 \le t \lt N$
- `Solve(s)` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

