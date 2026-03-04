---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u69CB\u9020"
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
    \ WeightType = int32_t>\nstruct Edge{\n    public:\n    Edge() = default;\n\n\
    \    Edge(Vertex from_, Vertex to_, WeightType weight_ = 1, int idx_ = -1) :\n\
    \        from(from_), to(to_), cost(weight_), idx(idx_){}\n    \n    bool operator<(const\
    \ Edge<WeightType> &e) const {return cost < e.cost;}\n\n    operator int() const\
    \ {return to;}\n\n    Vertex from, to;\n    WeightType cost;\n    int idx;\n};\n\
    \ntemplate<typename WeightType = int32_t>\nclass Graph{\n    public:\n    Graph()\
    \ = default;\n\n    Graph(int V) : edge_size_(0), adjacent_list_(V){}\n    \n\
    \    inline void AddUndirectedEdge(Vertex u, Vertex v, WeightType w = 1){\n  \
    \      int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<WeightType>(u,\
    \ v, w, idx));\n        adjacent_list_[v].push_back(Edge<WeightType>(v, u, w,\
    \ idx));\n    }\n    \n    inline void AddDirectedEdge(Vertex u, Vertex v, WeightType\
    \ w = 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<WeightType>(u,\
    \ v, w, idx));\n    }\n\n    inline size_t VertexSize() const {\n        return\
    \ adjacent_list_.size();\n    }\n\n    inline size_t EdgeSize() const {\n    \
    \    return edge_size_;\n    }\n\n    inline vector<Edge<WeightType>> &operator[](const\
    \ Vertex v){\n        return adjacent_list_[v];\n    }\n\n    inline const vector<Edge<WeightType>>\
    \ &operator[](const Vertex v) const {\n        return adjacent_list_[v];\n   \
    \ }\n    \n    private:\n    size_t edge_size_;\n    vector<vector<Edge<WeightType>>>\
    \ adjacent_list_;\n};\n\ntemplate<typename WeightType = int32_t>\nGraph<WeightType>\
    \ InputGraph(int N, int M, int padding = -1, bool weighted = false, bool directed\
    \ = false){\n    Graph<WeightType> G(N);\n    for(int i = 0; i < M; ++i){\n  \
    \      Vertex u, v; WeightType w = 1;\n        cin >> u >> v, u += padding, v\
    \ += padding;\n        if(weighted) cin >> w;\n        if(directed) G.AddDirectedEdge(u,\
    \ v, w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n\
    #line 4 \"Library/Graph/Dijkstra.hpp\"\n\ntemplate<typename WeightType>\nclass\
    \ Dijkstra{\n    public:\n    Dijkstra(Graph<WeightType> &graph, Vertex s = -1)\
    \ :\n        G(graph), V(graph.VertexSize()), dist_(V), prev_edge_(V){\n     \
    \   if(s != -1) Solve(s);\n    }\n\n    inline bool Reachable(const Vertex &t)\
    \ const {\n        return dist_[t] != inf;\n    }\n\n    inline WeightType Distance(const\
    \ Vertex &t) const {\n        return dist_[t];\n    }\n\n    vector<Edge<WeightType>>\
    \ Path(const Vertex &t) const {\n        if(!Reachable(t)) return vector<Edge<WeightType>>{};\n\
    \        vector<Edge<WeightType>> ret;\n        int v = t;\n        while(1){\n\
    \            if(prev_edge_[v].from == -1) break;\n            ret.push_back(prev_edge_[v]);\n\
    \            v = prev_edge_[v].from;\n        }\n        reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n    void Solve(Vertex s){\n     \
    \   using P = pair<WeightType, Vertex>;\n        fill(dist_.begin(), dist_.end(),\
    \ inf);\n        dist_[s] = WeightType(0);\n        fill(prev_edge_.begin(), prev_edge_.end(),\
    \ Edge<WeightType>{});\n        prev_edge_[s] = Edge<WeightType>(-1, -1);\n  \
    \      priority_queue<P, vector<P>, greater<P>> que;\n        que.emplace(WeightType(0),\
    \ s);\n        while(que.size()){\n            auto [d, u] = que.top(); que.pop();\n\
    \            if(dist_[u] != d) continue;\n            for(const Edge<WeightType>\
    \ &e : G[u]){\n                if(dist_[e.to] > d + e.cost){\n               \
    \     dist_[e.to] = d + e.cost;\n                    prev_edge_[e.to] = e;\n \
    \                   que.emplace(dist_[e.to], e.to);\n                }\n     \
    \       }\n        }\n    }\n\n    inline WeightType operator[](const Vertex &v){\n\
    \        return dist_[v];\n    }\n\n    inline const WeightType operator[](const\
    \ Vertex &v) const {\n        return dist_[v];\n    }\n\n    private:\n    Graph<WeightType>\
    \ &G;\n    int V;\n    Vertex source_;\n    WeightType inf{WeightType(INF)};\n\
    \    vector<WeightType> dist_;\n    vector<Edge<WeightType>> prev_edge_;\n};\n"
  code: "#pragma once\n\n#include \"Graph.hpp\"\n\ntemplate<typename WeightType>\n\
    class Dijkstra{\n    public:\n    Dijkstra(Graph<WeightType> &graph, Vertex s\
    \ = -1) :\n        G(graph), V(graph.VertexSize()), dist_(V), prev_edge_(V){\n\
    \        if(s != -1) Solve(s);\n    }\n\n    inline bool Reachable(const Vertex\
    \ &t) const {\n        return dist_[t] != inf;\n    }\n\n    inline WeightType\
    \ Distance(const Vertex &t) const {\n        return dist_[t];\n    }\n\n    vector<Edge<WeightType>>\
    \ Path(const Vertex &t) const {\n        if(!Reachable(t)) return vector<Edge<WeightType>>{};\n\
    \        vector<Edge<WeightType>> ret;\n        int v = t;\n        while(1){\n\
    \            if(prev_edge_[v].from == -1) break;\n            ret.push_back(prev_edge_[v]);\n\
    \            v = prev_edge_[v].from;\n        }\n        reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n    void Solve(Vertex s){\n     \
    \   using P = pair<WeightType, Vertex>;\n        fill(dist_.begin(), dist_.end(),\
    \ inf);\n        dist_[s] = WeightType(0);\n        fill(prev_edge_.begin(), prev_edge_.end(),\
    \ Edge<WeightType>{});\n        prev_edge_[s] = Edge<WeightType>(-1, -1);\n  \
    \      priority_queue<P, vector<P>, greater<P>> que;\n        que.emplace(WeightType(0),\
    \ s);\n        while(que.size()){\n            auto [d, u] = que.top(); que.pop();\n\
    \            if(dist_[u] != d) continue;\n            for(const Edge<WeightType>\
    \ &e : G[u]){\n                if(dist_[e.to] > d + e.cost){\n               \
    \     dist_[e.to] = d + e.cost;\n                    prev_edge_[e.to] = e;\n \
    \                   que.emplace(dist_[e.to], e.to);\n                }\n     \
    \       }\n        }\n    }\n\n    inline WeightType operator[](const Vertex &v){\n\
    \        return dist_[v];\n    }\n\n    inline const WeightType operator[](const\
    \ Vertex &v) const {\n        return dist_[v];\n    }\n\n    private:\n    Graph<WeightType>\
    \ &G;\n    int V;\n    Vertex source_;\n    WeightType inf{WeightType(INF)};\n\
    \    vector<WeightType> dist_;\n    vector<Edge<WeightType>> prev_edge_;\n};"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2026-02-13 15:23:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-A.test.cpp
  - verify/LC-ShortestPath.test.cpp
documentation_of: Library/Graph/Dijkstra.hpp
layout: document
title: "Dijkstra - \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---

# Dijkstra - ダイクストラ法

頂点数 $V$ 辺数 $E$ のグラフにおける単一始点最短経路問題をダイクストラ法を用いて解きます。

## Function

### Constructor

```
Dijkstra(Graph<WeightType> &graph, Vertex s = -1)
```

- グラフ $G$ を頂点数 $V$ 辺数 $E$ の `graph` で初期化します。
- 始点頂点 $s$ を指定すると、初期化後に `Solve(s)` を呼び出します。

**制約**

- $-1 \le s \lt V$

**計算量**

- $\textrm{O}(V)$

---

### Reachable

```
inline bool Reachable(const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ に到達可能であるかを判定します。

**制約**

- $0 \le t \lt V$
- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

---

### Distance

```
inline WeightType Distance(const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ への最短経路長を返します。
- 頂点 $t$ に到達不能であるとき、`INF` を返します。

**制約**

- $0 \le t \lt V$
- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

---

### Path

```
vector<Edge<WeightType>> Path(const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ への最短経路を辺の列として返します。
- 最短経路が複数ある場合、そのうちの $1$ つを返します。
- 頂点 $t$ に到達不能であるとき空列を返します。

**制約**

- $0 \le t \lt V$
- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(V)$

---

### Solve

```
void Solve(Vertex s)
```

- 頂点 $s$ を始点とした単一始点最短経路問題を解きます。

**制約**

- $0 \le s \lt V$

**計算量**

- $\textrm{O}((V + E) \log V)$

---

### operator[]

```
(1) WeightType operator[](const Vertex &t)
(2) const WeightType operator[](const Vertex &t) const 
```

- `Distance(t)` を返します。

**制約**

- $0 \le t \lt V$
- `Solve(s)` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

