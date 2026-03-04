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
    #line 4 \"Library/Graph/LowLink.hpp\"\n\ntemplate<typename WeightType>\nclass\
    \ LowLink{\n    public:\n    LowLink(Graph<WeightType> &graph) : G(graph), V(graph.VertexSize()),\
    \ ord_(V, -1), low_(V, -1), in_(V), out_(V){\n        for(int i = 0, k = 0, t\
    \ = 0; i < V; ++i){\n            if(ord_[i] == -1){\n                k = dfs(i,\
    \ -1, k, t);\n            }\n        }\n    }\n\n    vector<Vertex> &ArticulationPoint(){\n\
    \        return articulation_point_;\n    }\n\n    vector<pair<Vertex, Vertex>>\
    \ &Bridge(){\n        return bridge_;\n    }\n\n    pair<int, int> EulerTour(const\
    \ Vertex v) const {\n        return {in_[v], out_[v]};\n    }\n\n    private:\n\
    \    Graph<WeightType> &G;\n    int V;\n    vector<int> ord_, low_, in_, out_;\n\
    \    vector<Vertex> articulation_point_;\n    vector<pair<Vertex, Vertex>> bridge_;\n\
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
    \ && (cnt > 1);\n        if(is_articulation) articulation_point_.emplace_back(v);\n\
    \        out_[v] = t;\n        return k;\n    }\n};\n"
  code: "#pragma once\n\n#include \"Graph.hpp\"\n\ntemplate<typename WeightType>\n\
    class LowLink{\n    public:\n    LowLink(Graph<WeightType> &graph) : G(graph),\
    \ V(graph.VertexSize()), ord_(V, -1), low_(V, -1), in_(V), out_(V){\n        for(int\
    \ i = 0, k = 0, t = 0; i < V; ++i){\n            if(ord_[i] == -1){\n        \
    \        k = dfs(i, -1, k, t);\n            }\n        }\n    }\n\n    vector<Vertex>\
    \ &ArticulationPoint(){\n        return articulation_point_;\n    }\n\n    vector<pair<Vertex,\
    \ Vertex>> &Bridge(){\n        return bridge_;\n    }\n\n    pair<int, int> EulerTour(const\
    \ Vertex v) const {\n        return {in_[v], out_[v]};\n    }\n\n    private:\n\
    \    Graph<WeightType> &G;\n    int V;\n    vector<int> ord_, low_, in_, out_;\n\
    \    vector<Vertex> articulation_point_;\n    vector<pair<Vertex, Vertex>> bridge_;\n\
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
    \ && (cnt > 1);\n        if(is_articulation) articulation_point_.emplace_back(v);\n\
    \        out_[v] = t;\n        return k;\n    }\n};"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Graph/LowLink.hpp
  requiredBy: []
  timestamp: '2026-02-13 15:23:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-3-A.test.cpp
  - verify/AOJ-GRL-3-B.test.cpp
documentation_of: Library/Graph/LowLink.hpp
layout: document
title: "Low Link - \u95A2\u7BC0\u70B9\u3068\u6A4B"
---

# Low Link - 関節点と橋

頂点数 $V$ 辺数 $E$ の無向グラフの関節点と橋を検出します。

- **関節点**: その頂点を取り除くとグラフの連結成分数が増加する頂点
- **橋**: その辺を取り除くとグラフの連結成分数が増加する辺

## Function

### Constructor

```
LowLink(Graph<CostType> &graph)
```

- グラフ $G$ を頂点数 $V$ 辺数 $E$ の `graph` で初期化し、関節点と橋を事前計算します。

**制約**

- $G$ は無向グラフ

**計算量**

- $\textrm{O}(V + E)$

---

### ArticulationPoint

```
vector<Vertex> &ArticulationPoint()
```

- グラフに含まれるすべての関節点のリストを返します。

**計算量**

- $\textrm{O}(1)$

---

### Bridge

```
vector<pair<Vertex, Vertex>> &Bridge()
```

- グラフに含まれるすべての橋のリストを返します。
- 各橋は頂点ペア $(u, v)$ として表現され、$u < v$ となるように正規化されています。

**計算量**

- $\textrm{O}(1)$

---

### EulerTour

```
pair<int, int> EulerTour(const Vertex v) const
```

- DFS における頂点 $v$ の入時刻と出時刻を返します。

**計算量**

- $\textrm{O}(1)$

---
