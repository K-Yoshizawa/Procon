---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u69CB\u9020"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/String/Trie.hpp
    title: "Trie - \u30C8\u30E9\u30A4\u6728"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/HeavyLightDecomposition.hpp
    title: "Heavy Light Decomposition - \u91CD\u8EFD\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/LowestCommonAncestor.hpp
    title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
  - icon: ':x:'
    path: Library/Tree/RerootingDP.hpp
    title: "Rerooting DP - \u5168\u65B9\u4F4D\u6728DP"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/TreeDiameter.hpp
    title: "Tree Diameter - \u6728\u306E\u76F4\u5F84"
  - icon: ':warning:'
    path: Library/unauthenticated/AuxiliaryTree.hpp
    title: Library/unauthenticated/AuxiliaryTree.hpp
  - icon: ':warning:'
    path: Library/unauthenticated/EulerTour.hpp
    title: Library/unauthenticated/EulerTour.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-ALDS1-7-A.test.cpp
    title: verify/AOJ-ALDS1-7-A.test.cpp
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
    path: verify/LC-JumponTree.test.cpp
    title: verify/LC-JumponTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-LowestCommonAncestor-HLD.test.cpp
    title: verify/LC-LowestCommonAncestor-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-LowestCommonAncestor.test.cpp
    title: verify/LC-LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-TreeDiameter.test.cpp
    title: verify/LC-TreeDiameter.test.cpp
  - icon: ':x:'
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    #line 4 \"Library/Tree/Tree.hpp\"\n\ntemplate<typename WeightType = int32_t>\n\
    Graph<WeightType> InputTree(int V, int padding = -1, bool weighted = false){\n\
    \    Graph<WeightType> G(V);\n    for(int i = 0; i < V - 1; ++i){\n        Vertex\
    \ u, v; WeightType w = 1;\n        cin >> u >> v, u += padding, v += padding;\n\
    \        if(weighted) cin >> w;\n        G.AddUndirectedEdge(u, v, w);\n    }\n\
    \    return G;\n}\n\ntemplate<typename WeightType = int32_t>\nGraph<WeightType>\
    \ InputRootedTreeChild(int V, int padding = -1){\n    Graph<WeightType> G(V);\n\
    \    for(Vertex u = 0; u < V; ++u){\n        int k; cin >> k;\n        for(int\
    \ i = 0; i < k; ++i){\n            Vertex v; cin >> v, v += padding;\n       \
    \     G.AddUndirectedEdge(u, v);\n        }\n    }\n    return G;\n}\n\ntemplate<typename\
    \ WeightType = int32_t>\nGraph<WeightType> InputRootedTreeParent(int V, int padding\
    \ = -1){\n    Graph<WeightType> G(V);\n    for(Vertex u = 1; u < V; ++u){\n  \
    \      Vertex v; cin >> v, v += padding;\n        G.AddUndirectedEdge(u, v);\n\
    \    }\n    return G;\n}\n\ntemplate<typename WeightType = int32_t>\nvector<vector<Vertex>>\
    \ RootedTreeAdjacentList(const Graph<WeightType> &T, const Vertex r = 0){\n  \
    \  int V = T.VertexSize();\n    vector<vector<Vertex>> ret(V);\n    auto rec =\
    \ [&](auto &self, Vertex u, Vertex p) -> void {\n        for(Vertex v : T[u]){\n\
    \            if(v == p) continue;\n            ret[u].push_back(v);\n        \
    \    self(self, v, u);\n        }\n    };\n    rec(rec, r, -1);\n    return ret;\n\
    }\n\ntemplate<typename WeightType>\nvector<Vertex> CalculateTreeParent(Graph<WeightType>\
    \ &T, Vertex r = 0){\n    int V = T.VertexSize();\n    vector<Vertex> ret(V, -1);\n\
    \    auto rec = [&](auto &self, Vertex u) -> void {\n        for(Vertex v : T[u]){\n\
    \            if(v == ret[u]) continue;\n            ret[v] = u;\n            self(self,\
    \ v);\n        }\n    };\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ WeightType>\nvector<WeightType> CalculateTreeCost(Graph<WeightType> &T, Vertex\
    \ r = 0){\n    int V = T.VertexSize();\n    vector<WeightType> ret(V);\n    auto\
    \ rec = [&](auto &self, Vertex u, Vertex p) -> void {\n        for(const Edge<WeightType>\
    \ &e : T[u]){\n            Vertex v = e.to;\n            if(v == p) continue;\n\
    \            ret[v] = e.cost;\n            self(self, v, u);\n        }\n    };\n\
    \    rec(rec, r, -1);\n    return ret;\n}\n\ntemplate<typename WeightType>\nvector<int>\
    \ CalculateTreeDepth(Graph<WeightType> &T, Vertex r = 0){\n    int V = T.VertexSize();\n\
    \    vector<int> ret(V, 0);\n    auto rec = [&](auto &self, Vertex u, Vertex p,\
    \ int d) -> void {\n        ret[u] = d;\n        for(Vertex v : T[u]){\n     \
    \       if(v == p) continue;\n            self(self, v, u, d + 1);\n        }\n\
    \    };\n    rec(rec, r, -1, 0);\n    return ret;\n}\n\ntemplate<typename WeightType>\n\
    vector<WeightType> CalculateTreeDistance(Graph<WeightType> &T, Vertex r = 0){\n\
    \    int V = T.VertexSize();\n    vector<WeightType> ret(V, WeightType(INF));\n\
    \    auto rec = [&](auto &self, Vertex u) -> void {\n        for(const Edge<WeightType>\
    \ &e : T[u]){\n            if(ret[e.to] > ret[u] + e.cost){\n                ret[e.to]\
    \ = ret[u] + e.cost;\n                self(self, e.to);\n            }\n     \
    \   }\n    };\n    ret[r] = 0;\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ WeightType>\nvector<int> CalculateSubtreeSize(Graph<WeightType> &tree, Vertex\
    \ r = 0){\n    int V = tree.VertexSize();\n    vector<int> ret(V, 1);\n    auto\
    \ rec = [&](auto self, Vertex u, Vertex p) -> int {\n        for(const int v :\
    \ tree[u]){\n            if(v == p) continue;\n            ret[u] += self(self,\
    \ v, u);\n        }\n        return ret[u];\n    };\n    rec(rec, r, -1);\n  \
    \  return ret;\n}\n"
  code: "#pragma once\n\n#include \"../Graph/Graph.hpp\"\n\ntemplate<typename WeightType\
    \ = int32_t>\nGraph<WeightType> InputTree(int V, int padding = -1, bool weighted\
    \ = false){\n    Graph<WeightType> G(V);\n    for(int i = 0; i < V - 1; ++i){\n\
    \        Vertex u, v; WeightType w = 1;\n        cin >> u >> v, u += padding,\
    \ v += padding;\n        if(weighted) cin >> w;\n        G.AddUndirectedEdge(u,\
    \ v, w);\n    }\n    return G;\n}\n\ntemplate<typename WeightType = int32_t>\n\
    Graph<WeightType> InputRootedTreeChild(int V, int padding = -1){\n    Graph<WeightType>\
    \ G(V);\n    for(Vertex u = 0; u < V; ++u){\n        int k; cin >> k;\n      \
    \  for(int i = 0; i < k; ++i){\n            Vertex v; cin >> v, v += padding;\n\
    \            G.AddUndirectedEdge(u, v);\n        }\n    }\n    return G;\n}\n\n\
    template<typename WeightType = int32_t>\nGraph<WeightType> InputRootedTreeParent(int\
    \ V, int padding = -1){\n    Graph<WeightType> G(V);\n    for(Vertex u = 1; u\
    \ < V; ++u){\n        Vertex v; cin >> v, v += padding;\n        G.AddUndirectedEdge(u,\
    \ v);\n    }\n    return G;\n}\n\ntemplate<typename WeightType = int32_t>\nvector<vector<Vertex>>\
    \ RootedTreeAdjacentList(const Graph<WeightType> &T, const Vertex r = 0){\n  \
    \  int V = T.VertexSize();\n    vector<vector<Vertex>> ret(V);\n    auto rec =\
    \ [&](auto &self, Vertex u, Vertex p) -> void {\n        for(Vertex v : T[u]){\n\
    \            if(v == p) continue;\n            ret[u].push_back(v);\n        \
    \    self(self, v, u);\n        }\n    };\n    rec(rec, r, -1);\n    return ret;\n\
    }\n\ntemplate<typename WeightType>\nvector<Vertex> CalculateTreeParent(Graph<WeightType>\
    \ &T, Vertex r = 0){\n    int V = T.VertexSize();\n    vector<Vertex> ret(V, -1);\n\
    \    auto rec = [&](auto &self, Vertex u) -> void {\n        for(Vertex v : T[u]){\n\
    \            if(v == ret[u]) continue;\n            ret[v] = u;\n            self(self,\
    \ v);\n        }\n    };\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ WeightType>\nvector<WeightType> CalculateTreeCost(Graph<WeightType> &T, Vertex\
    \ r = 0){\n    int V = T.VertexSize();\n    vector<WeightType> ret(V);\n    auto\
    \ rec = [&](auto &self, Vertex u, Vertex p) -> void {\n        for(const Edge<WeightType>\
    \ &e : T[u]){\n            Vertex v = e.to;\n            if(v == p) continue;\n\
    \            ret[v] = e.cost;\n            self(self, v, u);\n        }\n    };\n\
    \    rec(rec, r, -1);\n    return ret;\n}\n\ntemplate<typename WeightType>\nvector<int>\
    \ CalculateTreeDepth(Graph<WeightType> &T, Vertex r = 0){\n    int V = T.VertexSize();\n\
    \    vector<int> ret(V, 0);\n    auto rec = [&](auto &self, Vertex u, Vertex p,\
    \ int d) -> void {\n        ret[u] = d;\n        for(Vertex v : T[u]){\n     \
    \       if(v == p) continue;\n            self(self, v, u, d + 1);\n        }\n\
    \    };\n    rec(rec, r, -1, 0);\n    return ret;\n}\n\ntemplate<typename WeightType>\n\
    vector<WeightType> CalculateTreeDistance(Graph<WeightType> &T, Vertex r = 0){\n\
    \    int V = T.VertexSize();\n    vector<WeightType> ret(V, WeightType(INF));\n\
    \    auto rec = [&](auto &self, Vertex u) -> void {\n        for(const Edge<WeightType>\
    \ &e : T[u]){\n            if(ret[e.to] > ret[u] + e.cost){\n                ret[e.to]\
    \ = ret[u] + e.cost;\n                self(self, e.to);\n            }\n     \
    \   }\n    };\n    ret[r] = 0;\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ WeightType>\nvector<int> CalculateSubtreeSize(Graph<WeightType> &tree, Vertex\
    \ r = 0){\n    int V = tree.VertexSize();\n    vector<int> ret(V, 1);\n    auto\
    \ rec = [&](auto self, Vertex u, Vertex p) -> int {\n        for(const int v :\
    \ tree[u]){\n            if(v == p) continue;\n            ret[u] += self(self,\
    \ v, u);\n        }\n        return ret[u];\n    };\n    rec(rec, r, -1);\n  \
    \  return ret;\n}"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Tree/Tree.hpp
  requiredBy:
  - Library/Tree/RerootingDP.hpp
  - Library/Tree/HeavyLightDecomposition.hpp
  - Library/Tree/TreeDiameter.hpp
  - Library/Tree/LowestCommonAncestor.hpp
  - Library/String/Trie.hpp
  - Library/unauthenticated/AuxiliaryTree.hpp
  - Library/unauthenticated/EulerTour.hpp
  timestamp: '2026-02-13 15:23:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/LC-JumponTree.test.cpp
  - verify/LC-LowestCommonAncestor-HLD.test.cpp
  - verify/AOJ-GRL-5-A.test.cpp
  - verify/LC-TreeDiameter.test.cpp
  - verify/LC-VertexAddPathSum.test.cpp
  - verify/LC-VertexAddSubtreeSum.test.cpp
  - verify/LC-VertexSetPathComposite.test.cpp
  - verify/AOJ-GRL-5-B.test.cpp
  - verify/LC-TreePathCompositeSum.test.cpp
  - verify/AOJ-ALDS1-7-A.test.cpp
  - verify/LC-LowestCommonAncestor.test.cpp
  - verify/AOJ-GRL-5-C.test.cpp
documentation_of: Library/Tree/Tree.hpp
layout: document
title: "Tree - \u6728"
---

# Tree - 木

グラフ $G$ が木構造のときに便利なライブラリ群です。

---

### InputTree

```
Graph<WeightType> InputTree(int V, int padding = -1, bool weighted = false)
```

- 木 $T$ を標準入力から読み込みます。
- 入力形式は以下の 2 つの形式のどちらかであることを想定しています。

```
u v
```

```
u v w
```

**制約**

- $0 \le V \le 10^{6}$

**計算量**

- $\textrm{O}(V)$

---

### InputRootedTreeChild

```
Graph<WeightType> InputRootedTreeChild(int V, int padding = -1)
```

- 木 $T$ を標準入力から読み込みます。
- 入力形式は以下の形式であることを想定しています。

```
k c_0 c_1 ... c_k
```

**制約**

- $0 \le V \le 10^{6}$

**計算量**

- $\textrm{O}(V)$

---

### InputRootedTreeParent

```
Graph<WeightType> InputRootedTreeParent(int V, int padding = -1)
```

- 木 $T$ を標準入力から読み込みます。
- 入力形式は以下の形式であることを想定しています。

```
p_1 p_2 ... p_{V - 1}
```

**制約**

- $0 \le V \le 10^{6}$

**計算量**

- $\textrm{O}(V)$

---

### RootedTreeAdjacentList

```
vector<vector<Vertex>> RootedTreeAdjacentList(const Graph<WeightType> &T, const Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の子の頂点の隣接リストを作成します。

**制約**

- $0 \le r \lt V$

**計算量**

- $\textrm{O}(V)$

---

### CalculateTreeParent

```
vector<Vertex> CalculateTreeParent(Graph<WeightType> &T, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の親を求めます。
- 頂点 $r$ の親は $-1$ とします。

**制約**

- $0 \le r \lt V$

**計算量**

- $\textrm{O}(V)$

---

### CalculateTreeCost

```
vector<WeightType> CalculateTreeCost(Graph<WeightType> &T, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の親と結ぶ辺の重みを求めます。
- 頂点 $r$ の重みについては未定義です。

**制約**

- $0 \le r \lt V$

**計算量**

- $\textrm{O}(V)$

---

### CalculateTreeDepth

```
vector<int> CalculateTreeDepth(Graph<WeightType> &T, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の深さを求めます。
- 頂点 $r$ の深さは $0$ とします。

**制約**

- $0 \le r \lt V$

**計算量**

- $\textrm{O}(V)$

---

### CalculateTreeDistance

```
vector<WeightType> CalculateTreeDistance(Graph<WeightType> &T, Vertex r = 0)
```

- 木 $T$ について、頂点 $r$ を始点としたときの各頂点までの距離を求めます。
- 頂点 $r$ の距離は $0$ とします。

**制約**

- $0 \le r \lt V$

**計算量**

- $\textrm{O}(V)$

---

### CalculateSubtreeSize

```
vector<int> CalculateSubtreeSize(Graph<WeightType> &tree, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点を根とする部分木の大きさを求めます。
- 葉を根とする部分木の大きさは $1$ とします。

**制約**

- $0 \le r \lt V$

**計算量**

- $\textrm{O}(V)$

---
