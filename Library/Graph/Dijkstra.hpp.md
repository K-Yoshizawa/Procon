---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-A.test.cpp
    title: verify/AOJ-GRL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-ShortestPath.test.cpp
    title: verify/LC-ShortestPath.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Dijkstra.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
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
    \ 4 \"Library/Graph/Dijkstra.hpp\"\n\ntemplate<typename CostType>\nclass Dijkstra{\n\
    \    public:\n    Dijkstra(Graph<CostType> &graph, Vertex s = -1) :\n        G(graph),\
    \ n(graph.VertexSize()), dist_(n), prev_edge_(n){\n        if(s != -1) Solve(s);\n\
    \    }\n\n    inline bool Reachable(const Vertex &t) const {\n        return dist_[t]\
    \ != inf;\n    }\n\n    inline CostType Distance(const Vertex &t) const {\n  \
    \      return dist_[t];\n    }\n\n    vector<Edge<CostType>> Path(const Vertex\
    \ &t) const {\n        if(!Reachable(t)) return vector<Edge<CostType>>{};\n  \
    \      vector<Edge<CostType>> ret;\n        int v = t;\n        while(1){\n  \
    \          if(prev_edge_[v].from == -1) break;\n            ret.push_back(prev_edge_[v]);\n\
    \            v = prev_edge_[v].from;\n        }\n        reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n    void Solve(Vertex s){\n     \
    \   using P = pair<CostType, Vertex>;\n        fill(dist_.begin(), dist_.end(),\
    \ inf);\n        dist_[s] = CostType(0);\n        fill(prev_edge_.begin(), prev_edge_.end(),\
    \ Edge<CostType>{});\n        prev_edge_[s] = Edge<CostType>(-1, -1);\n      \
    \  priority_queue<P, vector<P>, greater<P>> que;\n        que.emplace(CostType(0),\
    \ s);\n        while(que.size()){\n            auto [d, u] = que.top(); que.pop();\n\
    \            if(dist_[u] != d) continue;\n            for(const Edge<CostType>\
    \ &e : G[u]){\n                if(dist_[e.to] > d + e.cost){\n               \
    \     dist_[e.to] = d + e.cost;\n                    prev_edge_[e.to] = e;\n \
    \                   que.emplace(dist_[e.to], e.to);\n                }\n     \
    \       }\n        }\n    }\n\n    inline CostType operator[](const Vertex &t){\n\
    \        return dist_[t];\n    }\n\n    inline const CostType operator[](const\
    \ Vertex &t) const {\n        return dist_[t];\n    }\n\n    private:\n    Graph<CostType>\
    \ &G;\n    int n;\n    Vertex source_;\n    CostType inf{CostType(INF)};\n   \
    \ vector<CostType> dist_;\n    vector<Edge<CostType>> prev_edge_;\n};\n"
  code: "#pragma once\n\n#include \"Graph.hpp\"\n\ntemplate<typename CostType>\nclass\
    \ Dijkstra{\n    public:\n    Dijkstra(Graph<CostType> &graph, Vertex s = -1)\
    \ :\n        G(graph), n(graph.VertexSize()), dist_(n), prev_edge_(n){\n     \
    \   if(s != -1) Solve(s);\n    }\n\n    inline bool Reachable(const Vertex &t)\
    \ const {\n        return dist_[t] != inf;\n    }\n\n    inline CostType Distance(const\
    \ Vertex &t) const {\n        return dist_[t];\n    }\n\n    vector<Edge<CostType>>\
    \ Path(const Vertex &t) const {\n        if(!Reachable(t)) return vector<Edge<CostType>>{};\n\
    \        vector<Edge<CostType>> ret;\n        int v = t;\n        while(1){\n\
    \            if(prev_edge_[v].from == -1) break;\n            ret.push_back(prev_edge_[v]);\n\
    \            v = prev_edge_[v].from;\n        }\n        reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n    void Solve(Vertex s){\n     \
    \   using P = pair<CostType, Vertex>;\n        fill(dist_.begin(), dist_.end(),\
    \ inf);\n        dist_[s] = CostType(0);\n        fill(prev_edge_.begin(), prev_edge_.end(),\
    \ Edge<CostType>{});\n        prev_edge_[s] = Edge<CostType>(-1, -1);\n      \
    \  priority_queue<P, vector<P>, greater<P>> que;\n        que.emplace(CostType(0),\
    \ s);\n        while(que.size()){\n            auto [d, u] = que.top(); que.pop();\n\
    \            if(dist_[u] != d) continue;\n            for(const Edge<CostType>\
    \ &e : G[u]){\n                if(dist_[e.to] > d + e.cost){\n               \
    \     dist_[e.to] = d + e.cost;\n                    prev_edge_[e.to] = e;\n \
    \                   que.emplace(dist_[e.to], e.to);\n                }\n     \
    \       }\n        }\n    }\n\n    inline CostType operator[](const Vertex &t){\n\
    \        return dist_[t];\n    }\n\n    inline const CostType operator[](const\
    \ Vertex &t) const {\n        return dist_[t];\n    }\n\n    private:\n    Graph<CostType>\
    \ &G;\n    int n;\n    Vertex source_;\n    CostType inf{CostType(INF)};\n   \
    \ vector<CostType> dist_;\n    vector<Edge<CostType>> prev_edge_;\n};"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2025-04-30 01:32:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-A.test.cpp
  - verify/LC-ShortestPath.test.cpp
documentation_of: Library/Graph/Dijkstra.hpp
layout: document
title: "Dijkstra - \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---

# Dijkstra - ダイクストラ法

$N$ 頂点 $M$ 辺のグラフにおける単一始点最短経路問題をダイクストラ法を用いて解きます。

## Function

### Constructor

```
Dijkstra(Graph<CostType> &graph, Vertex s = -1)
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

### Path

```
vector<Edge<CostType>> Path(const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ への最短経路を辺の集合として返します。
- 頂点 $t$ に到達不能であるとき空列を返します。

**制約**

- $0 \le t \lt N$
- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(N)$

---

### Solve

```
void Solve(Vertex s)
```

- 頂点 $s$ を始点とした単一始点最短経路問題を解きます。

**制約**

- $0 \le s \lt N$

**計算量**

- $\textrm{O}((N + M) \log M)$

---

### operator[]

```
(1) CostType operator[](const Vertex &t)
(1) const CostType operator[](const Vertex &t) const 
```

- `Distance(t)` を返します。

**制約**

- $0 \le v \lt N$
- `Solve(s)` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

