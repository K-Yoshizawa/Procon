---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/String/Trie.hpp
    title: Library/String/Trie.hpp
  - icon: ':warning:'
    path: Library/Tree/AuxiliaryTree.hpp
    title: "Auxiliary Tree - \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\
      \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\
      \u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\
      \u6728"
  - icon: ':warning:'
    path: Library/Tree/EulerTour.hpp
    title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/HeavyLightDecomposition.hpp
    title: "Heavy Light Decomposition - \u91CD\u8EFD\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/LowestCommonAncestor.hpp
    title: "\u9802\u70B9 `u` \u3068\u9802\u70B9 `v` \u306E\u6700\u5C0F\u5171\u901A\
      \u7956\u5148\u3092\u8FD4\u3059\u3002"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/RerootingDP.hpp
    title: "Rerooting DP - \u5168\u65B9\u4F4D\u6728 DP"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/TreeDiameter.hpp
    title: "Tree Diameter - \u6728\u306E\u76F4\u5F84"
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
    document_title: "\u5404\u9802\u70B9\u3092\u884C\u304D\u304B\u3051\u9806\u306B\u4E26\
      \u3079\u305F\u3068\u304D\u306B\u4F55\u756A\u76EE\u306B\u76F8\u5F53\u3059\u308B\
      \u304B\u306E\u914D\u5217\u3092\u6C42\u3081\u308B\u3002"
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
    \  return ret;\n}\n\n// /**\n//  * @brief \u5404\u9802\u70B9\u3092\u884C\u304D\
    \u304B\u3051\u9806\u306B\u4E26\u3079\u305F\u3068\u304D\u306B\u4F55\u756A\u76EE\
    \u306B\u76F8\u5F53\u3059\u308B\u304B\u306E\u914D\u5217\u3092\u6C42\u3081\u308B\
    \u3002\n//  * @param tree \u6728\n//  * @return vector<int> \u5404\u9802\u70B9\
    \u304C\u884C\u304D\u304B\u3051\u9806\u3067\u4F55\u756A\u76EE\u306B\u306A\u308B\
    \u304B (0-index)\n//  */\n// template<typename CostType>\n// vector<int> CalculatePreOrder(RootedTree<CostType>\
    \ &tree){\n//     Vertex root = tree.get_root();\n//     int V = tree.get_vertex_size(),\
    \ time_stamp = 0;\n//     vector<int> ret(V, -1);\n//     auto rec = [&](auto\
    \ self, Vertex v) -> void {\n//         ret[v] = time_stamp++;\n//         for(Vertex\
    \ u : tree.get_child()){\n//             self(self, u);\n//         }\n//    \
    \ };\n//     rec(rec, root);\n//     return ret;\n// }\n"
  code: "#pragma once\n\n#include \"../Graph/Graph.hpp\"\n\ntemplate<typename CostType\
    \ = int32_t>\nGraph<CostType> InputTree(int N, int padding = -1, bool weighted\
    \ = false){\n    Graph<CostType> G(N);\n    for(int i = 0; i < N - 1; ++i){\n\
    \        Vertex u, v; CostType w = 1;\n        cin >> u >> v, u += padding, v\
    \ += padding;\n        if(weighted) cin >> w;\n        G.AddUndirectedEdge(u,\
    \ v, w);\n    }\n    return G;\n}\n\ntemplate<typename CostType = int32_t>\nGraph<CostType>\
    \ InputRootedTreeChild(int N, int padding = -1){\n    Graph<CostType> G(N);\n\
    \    for(Vertex u = 0; u < N; ++u){\n        int k; cin >> k;\n        for(int\
    \ i = 0; i < k; ++i){\n            Vertex v; cin >> v, v += padding;\n       \
    \     G.AddUndirectedEdge(u, v);\n        }\n    }\n    return G;\n}\n\ntemplate<typename\
    \ CostType = int32_t>\nGraph<CostType> InputRootedTreeParent(int N, int padding\
    \ = -1){\n    Graph<CostType> G(N);\n    for(Vertex u = 1; u < N; ++u){\n    \
    \    Vertex v; cin >> v, v += padding;\n        G.AddUndirectedEdge(u, v);\n \
    \   }\n    return G;\n}\n\ntemplate<typename CostType = int32_t>\nvector<vector<Vertex>>\
    \ RootedTreeAdjacentList(const Graph<CostType> &T, const Vertex r = 0){\n    int\
    \ n = T.VertexSize();\n    vector<vector<Vertex>> ret(n);\n    auto rec = [&](auto\
    \ &self, Vertex u, Vertex p) -> void {\n        for(Vertex v : T[u]){\n      \
    \      if(v == p) continue;\n            ret[u].push_back(v);\n            self(self,\
    \ v, u);\n        }\n    };\n    rec(rec, r, -1);\n    return ret;\n}\n\ntemplate<typename\
    \ CostType>\nvector<int> CalculateTreeParent(Graph<CostType> &T, Vertex r = 0){\n\
    \    int n = T.VertexSize();\n    vector<int> ret(n, -1);\n    auto rec = [&](auto\
    \ &self, Vertex u) -> void {\n        for(Vertex v : T[u]){\n            if(v\
    \ == ret[u]) continue;\n            ret[v] = u;\n            self(self, v);\n\
    \        }\n    };\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
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
    \  return ret;\n}\n\n// /**\n//  * @brief \u5404\u9802\u70B9\u3092\u884C\u304D\
    \u304B\u3051\u9806\u306B\u4E26\u3079\u305F\u3068\u304D\u306B\u4F55\u756A\u76EE\
    \u306B\u76F8\u5F53\u3059\u308B\u304B\u306E\u914D\u5217\u3092\u6C42\u3081\u308B\
    \u3002\n//  * @param tree \u6728\n//  * @return vector<int> \u5404\u9802\u70B9\
    \u304C\u884C\u304D\u304B\u3051\u9806\u3067\u4F55\u756A\u76EE\u306B\u306A\u308B\
    \u304B (0-index)\n//  */\n// template<typename CostType>\n// vector<int> CalculatePreOrder(RootedTree<CostType>\
    \ &tree){\n//     Vertex root = tree.get_root();\n//     int V = tree.get_vertex_size(),\
    \ time_stamp = 0;\n//     vector<int> ret(V, -1);\n//     auto rec = [&](auto\
    \ self, Vertex v) -> void {\n//         ret[v] = time_stamp++;\n//         for(Vertex\
    \ u : tree.get_child()){\n//             self(self, u);\n//         }\n//    \
    \ };\n//     rec(rec, root);\n//     return ret;\n// }"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Tree/Tree.hpp
  requiredBy:
  - Library/String/Trie.hpp
  - Library/Tree/HeavyLightDecomposition.hpp
  - Library/Tree/RerootingDP.hpp
  - Library/Tree/TreeDiameter.hpp
  - Library/Tree/AuxiliaryTree.hpp
  - Library/Tree/EulerTour.hpp
  - Library/Tree/LowestCommonAncestor.hpp
  timestamp: '2025-05-02 02:04:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-VertexAddPathSum.test.cpp
  - verify/AOJ-GRL-5-C.test.cpp
  - verify/LC-LowestCommonAncestor.test.cpp
  - verify/AOJ-GRL-5-B.test.cpp
  - verify/AOJ-ALDS1-7-A.test.cpp
  - verify/LC-JumponTree.test.cpp
  - verify/AOJ-GRL-5-A.test.cpp
  - verify/LC-VertexSetPathComposite.test.cpp
  - verify/LC-VertexAddSubtreeSum.test.cpp
  - verify/LC-TreePathCompositeSum.test.cpp
  - verify/LC-LowestCommonAncestor-HLD.test.cpp
  - verify/LC-TreeDiameter.test.cpp
documentation_of: Library/Tree/Tree.hpp
layout: document
title: "Tree - \u6728"
---

# Tree - 木

グラフテンプレートを木として用いるときに便利なライブラリ群です。

本ドキュメントにおいて、木 $T$ の頂点数は $n$ とし、頂点は 0-index でラベリングされているものとします。

---

### InputTree

```
Graph<CostType> InputTree(int N, int padding = -1, bool weighted = false)
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

- $0 \le n \le 10^{6}$

**計算量**

- $\textrm{O}(n)$

---

### InputRootedTreeChild

```
Graph<CostType> InputRootedTreeChild(int N, int padding = -1)
```

- 木 $T$ を標準入力から読み込みます。
- 入力形式は以下の形式であることを想定しています。

```
k c_0 c_1 ... c_k
```

**制約**

- $0 \le n \le 10^{6}$

**計算量**

- $\textrm{O}(n)$

---

### InputRootedTreeParent

```
Graph<CostType> InputRootedTreeParent(int N, int padding = -1)
```

- 木 $T$ を標準入力から読み込みます。
- 入力形式は以下の形式であることを想定しています。

```
p_1 p_2 ... p_{N - 1}
```

**制約**

- $0 \le n \le 10^{6}$

**計算量**

- $\textrm{O}(n)$

---

### CalculateTreeParent

```
vector<int> CalculateTreeParent(Graph<CostType> &T, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の親を求めます。
- 頂点 $r$ の親は $-1$ とします。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---

### CalculateTreeCost

```
vector<CostType> CalculateTreeCost(Graph<CostType> &T, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の親と結ぶ辺の重みを求めます。
- 頂点 $r$ の重みについては未定義です。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---

### CalculateTreeDepth

```
vector<int> CalculateTreeDepth(Graph<CostType> &T, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の深さを求めます。
- 頂点 $r$ の深さは $0$ とします。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---

### CalculateTreeDistance

```
vector<CostType> CalculateTreeDistance(Graph<CostType> &T, Vertex r = 0)
```

- 木 $T$ について、頂点 $r$ を始点としたときの各頂点までの距離を求めます。
- 頂点 $r$ の距離は $0$ とします。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---

### CalculateSubtreeSize

```
vector<int> CalculateSubtreeSize(Graph<CostType> &tree, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点を根とする部分木の大きさを求めます。
- 葉を根とする部分木の大きさは $1$ とします。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---

### RootedTreeAdjacentList

```
vector<vector<Vertex>> RootedTreeAdjacentList(const Graph<CostType> &T, const Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の子の頂点の隣接リストを作成します。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---
