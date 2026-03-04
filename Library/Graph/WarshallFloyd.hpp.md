---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u69CB\u9020"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/GraphMisc.hpp
    title: "Graph Utilities - \u30B0\u30E9\u30D5\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\
      \u30A3"
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
    \ const ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 4 \"Library/Graph/Graph.hpp\"\
    \n\nusing Vertex = int;\n\ntemplate<typename WeightType = int32_t>\nstruct Edge{\n\
    \    public:\n    Edge() = default;\n\n    Edge(Vertex from_, Vertex to_, WeightType\
    \ weight_ = 1, int idx_ = -1) :\n        from(from_), to(to_), cost(weight_),\
    \ idx(idx_){}\n    \n    bool operator<(const Edge<WeightType> &e) const {return\
    \ cost < e.cost;}\n\n    operator int() const {return to;}\n\n    Vertex from,\
    \ to;\n    WeightType cost;\n    int idx;\n};\n\ntemplate<typename WeightType\
    \ = int32_t>\nclass Graph{\n    public:\n    Graph() = default;\n\n    Graph(int\
    \ V) : edge_size_(0), adjacent_list_(V){}\n    \n    inline void AddUndirectedEdge(Vertex\
    \ u, Vertex v, WeightType w = 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<WeightType>(u,\
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
    #line 2 \"Library/Graph/GraphMisc.hpp\"\n\n#line 4 \"Library/Graph/GraphMisc.hpp\"\
    \n\ntemplate<typename WeightType>\nvector<Edge<WeightType>> ConvertEdgeSet(const\
    \ Graph<WeightType> &G){\n    vector<Edge<WeightType>> ret;\n    vector<bool>\
    \ check(G.EdgeSize(), false);\n    int n = G.VertexSize();\n    for(int u = 0;\
    \ u < n; ++u){\n        for(const Edge<WeightType> &e : G[u]){\n            if(check[e.idx])\
    \ continue;\n            check[e.idx] = true;\n            ret.push_back(e);\n\
    \        }\n    }\n    return ret;\n}\n\ntemplate<typename WeightType>\nvector<vector<WeightType>>\
    \ ConvertDistanceMatrix(const Graph<WeightType> &G){\n    int n = G.VertexSize();\n\
    \    vector<vector<WeightType>> ret(n, vector<WeightType>(n, WeightType(INF)));\n\
    \    for(int u = 0; u < n; ++u){\n        ret[u][u] = WeightType(0);\n       \
    \ for(const Edge<WeightType> &e : G[u]){\n            ret[u][e.to] = e.cost;\n\
    \        }\n    }\n    return ret;\n}\n\ntemplate<typename WeightType>\nGraph<WeightType>\
    \ ReverseGraph(const Graph<WeightType> &G){\n    int n = G.VertexSize();\n   \
    \ Graph<WeightType> ret(n);\n    for(int u = 0; u < n; ++u){\n        for(const\
    \ Edge<WeightType> &e : G[u]){\n            ret.AddDirectedEdge(e.to, e.from,\
    \ e.cost);\n        }\n    }\n    return ret;\n}\n#line 3 \"Library/Graph/WarshallFloyd.hpp\"\
    \n\ntemplate<typename WeightType>\nclass WarshallFloyd{\n    public:\n    WarshallFloyd(Graph<WeightType>\
    \ &graph) :\n        V(graph.VertexSize()), dist_(ConvertDistanceMatrix(graph)){\n\
    \        Solve();\n    }\n\n    WarshallFloyd(vector<vector<WeightType>> &A) :\n\
    \        V((int)A.size()), dist_(A){\n        Solve();\n    }\n\n    inline bool\
    \ Reachable(const Vertex &s, const Vertex &t) const {\n        return dist_[s][t]\
    \ != inf;\n    }\n\n    inline WeightType Distance(const Vertex &s, const Vertex\
    \ &t) const {\n        return dist_[s][t];\n    }\n\n    inline bool NegativeCycle()\
    \ const {\n        return negative_cycle_;\n    }\n\n    inline vector<WeightType>\
    \ &operator[](const Vertex &s){\n        return dist_[s];\n    }\n\n    inline\
    \ const vector<WeightType> &operator[](const Vertex &s) const {\n        return\
    \ dist_[s];\n    }\n\n    private:\n    int V;\n    WeightType inf{WeightType(INF)};\n\
    \    bool negative_cycle_{false};\n    vector<vector<WeightType>> dist_;\n\n \
    \   void Solve(){\n        for(int i = 0; i < V; ++i) dist_[i][i] = min(dist_[i][i],\
    \ WeightType(0));\n        for(int k = 0; k < V; ++k){\n            for(int i\
    \ = 0; i < V; ++i){\n                for(int j = 0; j < V; ++j){\n           \
    \         if(dist_[i][k] == inf || dist_[k][j] == inf) continue;\n           \
    \         dist_[i][j] = min(dist_[i][j], dist_[i][k] + dist_[k][j]);\n       \
    \         }\n            }\n        }\n        for(int i = 0; i < V; ++i) negative_cycle_\
    \ |= dist_[i][i] < 0;\n    }\n};\n"
  code: "#include \"Graph.hpp\"\n#include \"GraphMisc.hpp\"\n\ntemplate<typename WeightType>\n\
    class WarshallFloyd{\n    public:\n    WarshallFloyd(Graph<WeightType> &graph)\
    \ :\n        V(graph.VertexSize()), dist_(ConvertDistanceMatrix(graph)){\n   \
    \     Solve();\n    }\n\n    WarshallFloyd(vector<vector<WeightType>> &A) :\n\
    \        V((int)A.size()), dist_(A){\n        Solve();\n    }\n\n    inline bool\
    \ Reachable(const Vertex &s, const Vertex &t) const {\n        return dist_[s][t]\
    \ != inf;\n    }\n\n    inline WeightType Distance(const Vertex &s, const Vertex\
    \ &t) const {\n        return dist_[s][t];\n    }\n\n    inline bool NegativeCycle()\
    \ const {\n        return negative_cycle_;\n    }\n\n    inline vector<WeightType>\
    \ &operator[](const Vertex &s){\n        return dist_[s];\n    }\n\n    inline\
    \ const vector<WeightType> &operator[](const Vertex &s) const {\n        return\
    \ dist_[s];\n    }\n\n    private:\n    int V;\n    WeightType inf{WeightType(INF)};\n\
    \    bool negative_cycle_{false};\n    vector<vector<WeightType>> dist_;\n\n \
    \   void Solve(){\n        for(int i = 0; i < V; ++i) dist_[i][i] = min(dist_[i][i],\
    \ WeightType(0));\n        for(int k = 0; k < V; ++k){\n            for(int i\
    \ = 0; i < V; ++i){\n                for(int j = 0; j < V; ++j){\n           \
    \         if(dist_[i][k] == inf || dist_[k][j] == inf) continue;\n           \
    \         dist_[i][j] = min(dist_[i][j], dist_[i][k] + dist_[k][j]);\n       \
    \         }\n            }\n        }\n        for(int i = 0; i < V; ++i) negative_cycle_\
    \ |= dist_[i][i] < 0;\n    }\n};"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  - Library/Graph/GraphMisc.hpp
  isVerificationFile: false
  path: Library/Graph/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2026-02-13 15:23:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-C.test.cpp
documentation_of: Library/Graph/WarshallFloyd.hpp
layout: document
title: "Warshall Floyd - \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5"
---

# Warshall Floyd - ワーシャルフロイド法

頂点数 $V$ 辺数 $E$ のグラフにおける全点対最短経路問題をワーシャルフロイド法を用いて解きます。

## Function

### Constructor

```
(1) WarshallFloyd(Graph<WeightType> &graph)
(2) WarshallFloyd(vector<vector<WeightType>> &A)
```

- (1) グラフ $G$ を頂点数 $V$ 辺数 $E$ の `graph` で初期化します。
- (2) グラフ $G$ を $V \times V$ の隣接行列 $A$ で初期化をします。
    - 厳密には、行列 $A$ は次の要件を満たす $N \times N$ 行列である必要があります。
    - $A_{i, j}$ は頂点 $i$ から頂点 $j$ に辺が存在するときその辺の重み(重みなしグラフの場合は $1$)、存在しないとき $\infty$

**制約**

**計算量**

- $\textrm{O}(V^3)$

---

### Reachable

```
inline bool Reachable(const Vertex &s, const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ に到達可能であるかを判定します。

**制約**

- $0 \le s, t \lt V$

**計算量**

- $\textrm{O}(1)$

---

### Distance

```
inline WeightType Distance(const Vertex &s, const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ への最短経路長を返します。
- 頂点 $t$ に到達不能であるとき、`INF` を返します。

**制約**

- $0 \le s, t \lt V$

**計算量**

- $\textrm{O}(1)$

---

### NegativeCycle

```
inline bool NegativeCycle() const
```

- $G$ が負閉路を含むかを判定します。

**計算量**

- $\textrm{O}(1)$

---

### operator[]

```
(1) vector<WeightType> &operator[](const Vertex &s)
(1) const vector<WeightType> &operator[](const Vertex &s) const 
```

- 頂点 $s$ を始点とする各頂点への最短経路長の配列を返します。
- `wf[s][t]` は `Distance(s, t)` と同値です。

**制約**

- $0 \le s \lt V$

**計算量**

- $\textrm{O}(1)$

