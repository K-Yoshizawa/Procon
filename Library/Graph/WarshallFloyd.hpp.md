---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    path: verify/AOJ-GRL-1-C.test.cpp
    title: verify/AOJ-GRL-1-C.test.cpp
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
    \  return ret;\n}\n#line 3 \"Library/Graph/WarshallFloyd.hpp\"\n\ntemplate<typename\
    \ CostType>\nclass WarshallFloyd{\n    public:\n    WarshallFloyd(Graph<CostType>\
    \ &G) :\n        n(G.VertexSize()), dist_(ConvertDistanceMatrix(G)){\n       \
    \ Solve();\n    }\n\n    WarshallFloyd(vector<vector<CostType>> &D) :\n      \
    \  n((int)D.size()), dist_(D){\n        Solve();\n    }\n\n    inline bool Reachable(const\
    \ Vertex &s, const Vertex &t) const {\n        return dist_[s][t] != inf;\n  \
    \  }\n\n    inline CostType Distance(const Vertex &s, const Vertex &t) const {\n\
    \        return dist_[s][t];\n    }\n\n    inline bool Negative() const {\n  \
    \      return negative_cycle_;\n    }\n\n    inline vector<CostType> &operator[](const\
    \ Vertex &s){\n        return dist_[s];\n    }\n\n    inline const vector<CostType>\
    \ &operator[](const Vertex &s) const {\n        return dist_[s];\n    }\n\n  \
    \  private:\n    int n;\n    CostType inf{CostType(INF)};\n    bool negative_cycle_{false};\n\
    \    vector<vector<CostType>> dist_;\n\n    void Solve(){\n        for(int i =\
    \ 0; i < n; ++i) dist_[i][i] = min(dist_[i][i], CostType(0));\n        for(int\
    \ k = 0; k < n; ++k){\n            for(int i = 0; i < n; ++i){\n             \
    \   for(int j = 0; j < n; ++j){\n                    if(dist_[i][k] == inf ||\
    \ dist_[k][j] == inf) continue;\n                    dist_[i][j] = min(dist_[i][j],\
    \ dist_[i][k] + dist_[k][j]);\n                }\n            }\n        }\n \
    \       for(int i = 0; i < n; ++i) negative_cycle_ |= dist_[i][i] < 0;\n    }\n\
    };\n"
  code: "#include \"Graph.hpp\"\n#include \"GraphMisc.hpp\"\n\ntemplate<typename CostType>\n\
    class WarshallFloyd{\n    public:\n    WarshallFloyd(Graph<CostType> &G) :\n \
    \       n(G.VertexSize()), dist_(ConvertDistanceMatrix(G)){\n        Solve();\n\
    \    }\n\n    WarshallFloyd(vector<vector<CostType>> &D) :\n        n((int)D.size()),\
    \ dist_(D){\n        Solve();\n    }\n\n    inline bool Reachable(const Vertex\
    \ &s, const Vertex &t) const {\n        return dist_[s][t] != inf;\n    }\n\n\
    \    inline CostType Distance(const Vertex &s, const Vertex &t) const {\n    \
    \    return dist_[s][t];\n    }\n\n    inline bool Negative() const {\n      \
    \  return negative_cycle_;\n    }\n\n    inline vector<CostType> &operator[](const\
    \ Vertex &s){\n        return dist_[s];\n    }\n\n    inline const vector<CostType>\
    \ &operator[](const Vertex &s) const {\n        return dist_[s];\n    }\n\n  \
    \  private:\n    int n;\n    CostType inf{CostType(INF)};\n    bool negative_cycle_{false};\n\
    \    vector<vector<CostType>> dist_;\n\n    void Solve(){\n        for(int i =\
    \ 0; i < n; ++i) dist_[i][i] = min(dist_[i][i], CostType(0));\n        for(int\
    \ k = 0; k < n; ++k){\n            for(int i = 0; i < n; ++i){\n             \
    \   for(int j = 0; j < n; ++j){\n                    if(dist_[i][k] == inf ||\
    \ dist_[k][j] == inf) continue;\n                    dist_[i][j] = min(dist_[i][j],\
    \ dist_[i][k] + dist_[k][j]);\n                }\n            }\n        }\n \
    \       for(int i = 0; i < n; ++i) negative_cycle_ |= dist_[i][i] < 0;\n    }\n\
    };"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  - Library/Graph/GraphMisc.hpp
  isVerificationFile: false
  path: Library/Graph/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2025-03-23 23:54:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-C.test.cpp
documentation_of: Library/Graph/WarshallFloyd.hpp
layout: document
title: "Warshall Floyd - \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5"
---

# Warshall Floyd - ワーシャルフロイド法

$N$ 頂点 $M$ 辺のグラフにおける全点対最短経路問題をワーシャルフロイド法を用いて解きます。

## Function

### Constructor

```
(1) WarshallFloyd(Graph<CostType> &G)
(2) WarshallFloyd(vector<vector<CostType>> &D)
```

- (1) $N$ 頂点 $M$ 辺のグラフで初期化をします。
- (2) $N$ 頂点の隣接行列で初期化をします。
    - 厳密には、行列 $D$ は次の要件を満たす $N \times N$ 行列である必要があります。
    - $D_{i, j}$ は頂点 $i$ から頂点 $j$ に辺が存在するときその辺の重み、存在しないとき $\infty$

**制約**

**計算量**

- $\textrm{O}(N^3)$

---

### Reachable

```
inline bool Reachable(const Vertex &s, const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ に到達可能であるかを判定します。

**制約**

- $0 \le s, t \lt N$

**計算量**

- $\textrm{O}(1)$

---

### Distance

```
inline CostType Distance(const Vertex &s, const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ への最短経路長を返します。
- 頂点 $t$ に到達不能であるとき、`INF` を返します。

**制約**

- $0 \le s, t \lt N$

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

### operator[]

```
(1) vector<CostType> &operator[](const Vertex &s)
(1) const vector<CostType> &operator[](const Vertex &s) const 
```

- 頂点 $s$ を始点とする各頂点への最短経路長の配列を返します。
- `wf[s][t]` は `Distance(s, t)` と同値です。

**制約**

- $0 \le s \lt N$

**計算量**

- $\textrm{O}(1)$

