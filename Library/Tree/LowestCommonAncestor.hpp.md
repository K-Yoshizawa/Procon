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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/Tree/AuxiliaryTree.hpp
    title: "Auxiliary Tree - \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\
      \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\
      \u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\
      \u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-C.test.cpp
    title: verify/AOJ-GRL-5-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-LowestCommonAncestor.test.cpp
    title: verify/LC-LowestCommonAncestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Tree/LowestCommonAncestor.hpp\"\n\n#line 2 \"Library/Tree/Tree.hpp\"\
    \n\n#line 2 \"Library/Graph/Graph.hpp\"\n\n#line 2 \"Library/Common.hpp\"\n\n\
    /**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const\
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 4 \"Library/Graph/Graph.hpp\"\
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
    \  return ret;\n}\n#line 4 \"Library/Tree/LowestCommonAncestor.hpp\"\n\ntemplate<typename\
    \ CostType>\nstruct LowestCommonAncestor{\n    public:\n    LowestCommonAncestor(Graph<CostType>\
    \ &tree) : T(tree), depth_(CalculateTreeDepth(tree)){\n        int n = T.VertexSize();\n\
    \        height_ = 1;\n        while((1 << height_) < n) ++height_;\n        auto\
    \ par = CalculateTreeParent(T);\n        parent_.resize(height_, vector<Vertex>(n,\
    \ -1));\n        for(Vertex i = 0; i < n; ++i){\n            parent_[0][i] = par[i];\n\
    \        }\n        for(int k = 0; k + 1 < height_; ++k){\n            for(Vertex\
    \ i = 0; i < n; ++i){\n                if(parent_[k][i] < 0) parent_[k + 1][i]\
    \ = -1;\n                else parent_[k + 1][i] = parent_[k][parent_[k][i]];\n\
    \            }\n        }\n    }\n\n    Vertex Query(Vertex u, Vertex v){\n  \
    \      if(depth_[u] < depth_[v]) swap(u, v);\n        for(int k = 0; k < height_;\
    \ ++k){\n            if((depth_[u] - depth_[v]) >> k & 1){\n                u\
    \ = parent_[k][u];\n            }\n        }\n        if(u == v) return u;\n \
    \       for(int k = height_ - 1; k >= 0; --k){\n            if(parent_[k][u] !=\
    \ parent_[k][v]){\n                u = parent_[k][u];\n                v = parent_[k][v];\n\
    \            }\n        }\n        return parent_[0][u];\n    }\n\n    private:\n\
    \    Graph<CostType> &T;\n    int height_;\n    vector<int> depth_;\n    vector<vector<Vertex>>\
    \ parent_;\n};\n"
  code: "#pragma once\n\n#include \"Tree.hpp\"\n\ntemplate<typename CostType>\nstruct\
    \ LowestCommonAncestor{\n    public:\n    LowestCommonAncestor(Graph<CostType>\
    \ &tree) : T(tree), depth_(CalculateTreeDepth(tree)){\n        int n = T.VertexSize();\n\
    \        height_ = 1;\n        while((1 << height_) < n) ++height_;\n        auto\
    \ par = CalculateTreeParent(T);\n        parent_.resize(height_, vector<Vertex>(n,\
    \ -1));\n        for(Vertex i = 0; i < n; ++i){\n            parent_[0][i] = par[i];\n\
    \        }\n        for(int k = 0; k + 1 < height_; ++k){\n            for(Vertex\
    \ i = 0; i < n; ++i){\n                if(parent_[k][i] < 0) parent_[k + 1][i]\
    \ = -1;\n                else parent_[k + 1][i] = parent_[k][parent_[k][i]];\n\
    \            }\n        }\n    }\n\n    Vertex Query(Vertex u, Vertex v){\n  \
    \      if(depth_[u] < depth_[v]) swap(u, v);\n        for(int k = 0; k < height_;\
    \ ++k){\n            if((depth_[u] - depth_[v]) >> k & 1){\n                u\
    \ = parent_[k][u];\n            }\n        }\n        if(u == v) return u;\n \
    \       for(int k = height_ - 1; k >= 0; --k){\n            if(parent_[k][u] !=\
    \ parent_[k][v]){\n                u = parent_[k][u];\n                v = parent_[k][v];\n\
    \            }\n        }\n        return parent_[0][u];\n    }\n\n    private:\n\
    \    Graph<CostType> &T;\n    int height_;\n    vector<int> depth_;\n    vector<vector<Vertex>>\
    \ parent_;\n};"
  dependsOn:
  - Library/Tree/Tree.hpp
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Tree/LowestCommonAncestor.hpp
  requiredBy:
  - Library/Tree/AuxiliaryTree.hpp
  timestamp: '2026-02-08 19:12:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-LowestCommonAncestor.test.cpp
  - verify/AOJ-GRL-5-C.test.cpp
documentation_of: Library/Tree/LowestCommonAncestor.hpp
layout: document
title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
---

# Lowest Common Ancestor - 最小共通祖先

木上の2つの頂点の最小共通祖先（LCA）を効率的に求めるデータ構造です。

ダブリングを用いて前処理を行い、各クエリを高速に処理します。

## Function

### Constructor

```
LowestCommonAncestor(Graph<CostType> &tree)
```

- 木 `tree` に対して LCA を求めるための前処理を行います。

**制約**

- $1 \le N \le 10^5$

**計算量**

- $\textrm{O}(N \log N)$

---

### Query

```
Vertex Query(Vertex u, Vertex v)
```

- 頂点 $u$ と頂点 $v$ の最小共通祖先を返します。
- **0-index** で頂点を指定します。

**制約**

- $0 \le u, v < N$

**計算量**

- $\textrm{O}(\log N)$

---
