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
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-A.test.cpp
    title: verify/AOJ-GRL-5-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-B.test.cpp
    title: verify/AOJ-GRL-5-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-TreeDiameter.test.cpp
    title: verify/LC-TreeDiameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Tree/Tree.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\
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
    \ 4 \"Library/Tree/Tree.hpp\"\n\ntemplate<typename CostType = int32_t>\nGraph<CostType>\
    \ InputTree(int N, int padding = -1, bool weighted = false){\n    Graph<CostType>\
    \ G(N);\n    for(int i = 0; i < N - 1; ++i){\n        Vertex u, v; CostType w\
    \ = 1;\n        cin >> u >> v, u += padding, v += padding;\n        if(weighted)\
    \ cin >> w;\n        G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n\n\
    template<typename CostType = int32_t>\nGraph<CostType> InputRootedTreeChild(int\
    \ N, int padding = -1){\n    Graph<CostType> G(N);\n    for(Vertex u = 0; u <\
    \ N; ++u){\n        int k; cin >> k;\n        for(int i = 0; i < k; ++i){\n  \
    \          Vertex v; cin >> v, v += padding;\n            G.AddUndirectedEdge(u,\
    \ v);\n        }\n    }\n    return G;\n}\n\ntemplate<typename CostType = int32_t>\n\
    Graph<CostType> InputRootedTreeParent(int N, int padding = -1){\n    Graph<CostType>\
    \ G(N);\n    for(Vertex u = 1; u < N; ++u){\n        Vertex v; cin >> v, v +=\
    \ padding;\n        G.AddUndirectedEdge(u, v);\n    }\n    return G;\n}\n\ntemplate<typename\
    \ CostType = int32_t>\nvector<vector<Vertex>> RootedTreeAdjacentList(const Graph<CostType>\
    \ &T, const Vertex r = 0){\n    int n = T.VertexSize();\n    vector<vector<Vertex>>\
    \ ret(n);\n    auto rec = [&](auto &self, Vertex u, Vertex p) -> void {\n    \
    \    for(Vertex v : T[u]){\n            if(v == p) continue;\n            ret[u].push_back(v);\n\
    \            self(self, v, u);\n        }\n    };\n    rec(rec, r, -1);\n    return\
    \ ret;\n}\n\ntemplate<typename CostType>\nvector<int> CalculateTreeParent(Graph<CostType>\
    \ &T, Vertex r = 0){\n    int n = T.VertexSize();\n    vector<int> ret(n, -1);\n\
    \    auto rec = [&](auto &self, Vertex u) -> void {\n        for(Vertex v : T[u]){\n\
    \            if(v == ret[u]) continue;\n            ret[v] = u;\n            self(self,\
    \ v);\n        }\n    };\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ CostType>\nvector<CostType> CalculateTreeCost(Graph<CostType> &T, Vertex r =\
    \ 0){\n    int n = T.VertexSize();\n    vector<CostType> ret(n);\n    auto rec\
    \ = [&](auto &self, Vertex u, Vertex p) -> void {\n        for(const Edge<CostType>\
    \ &e : T[u]){\n            Vertex v = e.to;\n            if(v == p) continue;\n\
    \            ret[v] = e.cost;\n            self(self, v, u);\n        }\n    };\n\
    \    rec(rec, r, -1);\n    return ret;\n}\n\ntemplate<typename CostType>\nvector<int>\
    \ CalculateTreeDepth(Graph<CostType> &T, Vertex r = 0){\n    int n = T.VertexSize();\n\
    \    vector<int> ret(n, 0);\n    auto rec = [&](auto &self, Vertex u, Vertex p,\
    \ int d) -> void {\n        ret[u] = d;\n        for(Vertex v : T[u]){\n     \
    \       if(v == p) continue;\n            self(self, v, u, d + 1);\n        }\n\
    \    };\n    rec(rec, r, -1, 0);\n    return ret;\n}\n\ntemplate<typename CostType>\n\
    vector<CostType> CalculateTreeDistance(Graph<CostType> &T, Vertex r = 0){\n  \
    \  int n = T.VertexSize();\n    vector<CostType> ret(n, CostType(INF));\n    auto\
    \ rec = [&](auto &self, Vertex u) -> void {\n        for(const Edge<CostType>\
    \ &e : T[u]){\n            if(ret[e.to] > ret[u] + e.cost){\n                ret[e.to]\
    \ = ret[u] + e.cost;\n                self(self, e.to);\n            }\n     \
    \   }\n    };\n    ret[r] = 0;\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ CostType>\nvector<int> CalculateSubtreeSize(Graph<CostType> &tree, Vertex r\
    \ = 0){\n    int n = tree.VertexSize();\n    vector<int> ret(n, 1);\n    auto\
    \ rec = [&](auto self, Vertex u, Vertex p) -> int {\n        for(const int v :\
    \ tree[u]){\n            if(v == p) continue;\n            ret[u] += self(self,\
    \ v, u);\n        }\n        return ret[u];\n    };\n    rec(rec, r, -1);\n  \
    \  return ret;\n}\n#line 2 \"Library/Tree/TreeDiameter.hpp\"\n\ntemplate<typename\
    \ CostType>\nclass TreeDiameter{\n    public:\n    TreeDiameter(Graph<CostType>\
    \ &tree) : T(tree){\n        int n = T.VertexSize(), s = 0;\n        dist_s_ =\
    \ CalculateTreeDistance(T, s);\n        s = distance(dist_s_.begin(), max_element(dist_s_.begin(),\
    \ dist_s_.end()));\n        dist_s_ = CalculateTreeDistance(T, s);\n        vector<int>\
    \ par = CalculateTreeParent(T, s);\n        int t = distance(dist_s_.begin(),\
    \ max_element(dist_s_.begin(), dist_s_.end()));\n        diameter_ = dist_s_[t];\n\
    \        dist_t_ = CalculateTreeDistance(T, t);\n        int u = t;\n        while(u\
    \ != s){\n            path_.emplace_back(u);\n            u = par[u];\n      \
    \  }\n        path_.emplace_back(s);\n    }\n    \n    CostType Diameter() const\
    \ {\n        return diameter_;\n    }\n    \n    CostType Height(Vertex v) const\
    \ {\n        return max(dist_s_[v], dist_t_[v]);\n    }\n\n    pair<Vertex, Vertex>\
    \ EndPoints() const {\n        return pair<Vertex, Vertex>(path_.front(), path_.back());\n\
    \    }\n\n    vector<Vertex> &Path(){\n        return path_;\n    }\n\n    private:\n\
    \    Graph<CostType> &T;\n    vector<CostType> dist_s_, dist_t_;\n    vector<Vertex>\
    \ path_;\n    CostType diameter_;\n};\n"
  code: "#include \"Tree.hpp\"\n\ntemplate<typename CostType>\nclass TreeDiameter{\n\
    \    public:\n    TreeDiameter(Graph<CostType> &tree) : T(tree){\n        int\
    \ n = T.VertexSize(), s = 0;\n        dist_s_ = CalculateTreeDistance(T, s);\n\
    \        s = distance(dist_s_.begin(), max_element(dist_s_.begin(), dist_s_.end()));\n\
    \        dist_s_ = CalculateTreeDistance(T, s);\n        vector<int> par = CalculateTreeParent(T,\
    \ s);\n        int t = distance(dist_s_.begin(), max_element(dist_s_.begin(),\
    \ dist_s_.end()));\n        diameter_ = dist_s_[t];\n        dist_t_ = CalculateTreeDistance(T,\
    \ t);\n        int u = t;\n        while(u != s){\n            path_.emplace_back(u);\n\
    \            u = par[u];\n        }\n        path_.emplace_back(s);\n    }\n \
    \   \n    CostType Diameter() const {\n        return diameter_;\n    }\n    \n\
    \    CostType Height(Vertex v) const {\n        return max(dist_s_[v], dist_t_[v]);\n\
    \    }\n\n    pair<Vertex, Vertex> EndPoints() const {\n        return pair<Vertex,\
    \ Vertex>(path_.front(), path_.back());\n    }\n\n    vector<Vertex> &Path(){\n\
    \        return path_;\n    }\n\n    private:\n    Graph<CostType> &T;\n    vector<CostType>\
    \ dist_s_, dist_t_;\n    vector<Vertex> path_;\n    CostType diameter_;\n};"
  dependsOn:
  - Library/Tree/Tree.hpp
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Tree/TreeDiameter.hpp
  requiredBy: []
  timestamp: '2026-02-08 19:12:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-5-B.test.cpp
  - verify/LC-TreeDiameter.test.cpp
  - verify/AOJ-GRL-5-A.test.cpp
documentation_of: Library/Tree/TreeDiameter.hpp
layout: document
title: "Tree Diameter - \u6728\u306E\u76F4\u5F84"
---

# Tree Diameter - 木の直径

$n$ 頂点の木 $T$ の直径に関するライブラリです。

## Function

### Constructor

```
TreeDiameter(Graph<CostType> &tree)
```

- 木 $T =$ `tree` の直径を求めます。

**制約**

- `tree` は木

**計算量**

- $\textrm{O}(n)$

---

### Diameter

```
CostType Diameter() const
```

- 木 $T$ の直径を返します。

**計算量**

- $\textrm{O}(1)$

---

### Height

```
CostType Height(Vertex v) const
```

- 木 $T$ について、頂点 $v$ を根としたときの木の高さを返します。
  - 木の高さとは、根から最も遠い葉までの距離を指します。

**制約**

- $0 \le v \lt n$

**計算量**

- $\textrm{O}(1)$

---

### EndPoints

```
pair<Vertex, Vertex> EndPoints() const 
```

- 木 $T$ の直径の端点の頂点を返します。

**計算量**

- $\textrm{O}(1)$

---

### Path

```
vector<Vertex> &Path()
```

- 木 $T$ の直径を成すパスの頂点列を返します。

**計算量**

- $\textrm{O}(1)$

---
