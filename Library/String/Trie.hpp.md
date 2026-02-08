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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 2 \"Library/Tree/Tree.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n\n#line 4 \"Library/Graph/Graph.hpp\"\n\nusing Vertex = int;\n\ntemplate<typename\
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
    \  return ret;\n}\n#line 3 \"Library/String/Trie.hpp\"\n\ntemplate<int MAXSIZE\
    \ = 500010>\nclass Trie{\n    public:\n    Trie(vector<string> &S_) : S(S_), n((int)S_.size()),\
    \ v(1), vertex_(n), child_(MAXSIZE){\n        for(int i = 0; i < MAXSIZE; ++i){\n\
    \            child_[i].fill(-1);\n        }\n        for(int i = 0; i < n; ++i){\n\
    \            int p = 0, m = S[i].size();\n            vertex_[i].resize(m + 1,\
    \ 0);\n            for(int j = 0; j < m; ++j){\n                int c = S[i][j]\
    \ - 'a';\n                if(child_[p][c] == -1){\n                    child_[p][c]\
    \ = v++;\n                }\n                p = child_[p][c];\n             \
    \   vertex_[i][j + 1] = p;\n            }\n        }\n    }\n\n    Graph<int32_t>\
    \ Build() const {\n        Graph<int32_t> ret(v);\n        for(int i = 0; i <\
    \ v; ++i){\n            for(int j = 0; j < 26; ++j){\n                if(child_[i][j]\
    \ == -1) continue;\n                ret.AddUndirectedEdge(i, child_[i][j]);\n\
    \            }\n        }\n        return ret;\n    }\n\n    vector<int> &operator[](const\
    \ int i){\n        return vertex_[i];\n    }\n\n    private:\n    vector<string>\
    \ &S;\n    int n, v;\n    vector<vector<int>> vertex_;\n    vector<array<int,\
    \ 26>> child_;\n};\n"
  code: "#include \"../Common.hpp\"\n#include \"../Tree/Tree.hpp\"\n\ntemplate<int\
    \ MAXSIZE = 500010>\nclass Trie{\n    public:\n    Trie(vector<string> &S_) :\
    \ S(S_), n((int)S_.size()), v(1), vertex_(n), child_(MAXSIZE){\n        for(int\
    \ i = 0; i < MAXSIZE; ++i){\n            child_[i].fill(-1);\n        }\n    \
    \    for(int i = 0; i < n; ++i){\n            int p = 0, m = S[i].size();\n  \
    \          vertex_[i].resize(m + 1, 0);\n            for(int j = 0; j < m; ++j){\n\
    \                int c = S[i][j] - 'a';\n                if(child_[p][c] == -1){\n\
    \                    child_[p][c] = v++;\n                }\n                p\
    \ = child_[p][c];\n                vertex_[i][j + 1] = p;\n            }\n   \
    \     }\n    }\n\n    Graph<int32_t> Build() const {\n        Graph<int32_t> ret(v);\n\
    \        for(int i = 0; i < v; ++i){\n            for(int j = 0; j < 26; ++j){\n\
    \                if(child_[i][j] == -1) continue;\n                ret.AddUndirectedEdge(i,\
    \ child_[i][j]);\n            }\n        }\n        return ret;\n    }\n\n   \
    \ vector<int> &operator[](const int i){\n        return vertex_[i];\n    }\n\n\
    \    private:\n    vector<string> &S;\n    int n, v;\n    vector<vector<int>>\
    \ vertex_;\n    vector<array<int, 26>> child_;\n};"
  dependsOn:
  - Library/Common.hpp
  - Library/Tree/Tree.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/String/Trie.hpp
  requiredBy: []
  timestamp: '2026-02-08 19:12:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/String/Trie.hpp
layout: document
title: "Trie - \u30C8\u30E9\u30A4\u6728"
---

# Trie - トライ木

文字列の集合を効率的に管理するデータ構造です。複数の文字列の共通接頭辞を共有することで省スペース化を図ります。

## Function

### Constructor

```
Trie(vector<string> &S_)
```

- 文字列の配列 $S$ からトライ木を構築します。
- 各文字列は英小文字のみで構成されている必要があります。

**制約**

- $1 \le \sum \lvert S_i \rvert \le 5 \times 10^5$
- 各文字列は英小文字のみで構成される

**計算量**

- $\textrm{O}(\sum \lvert S_i \rvert)$

---

### Build

```
Graph<int32_t> Build() const
```

- トライ木をグラフ構造として返します。
- 各ノードは頂点として、親子関係は辺として表現されます。
- 返されるグラフは無向グラフです。

**計算量**

- $\textrm{O}(V)$ （$V$ はトライ木の頂点数）

---

### operator[]

```
vector<int> &operator[](const int i)
```

- 文字列 $S_i$ に対応するトライ木上のノード列を返します。
- 返される配列の各要素は、文字列の各文字に対応するノード番号です。
- 配列のサイズは $\lvert S_i \rvert + 1$ で、最初の要素（インデックス0）は根ノード（0）です。

**制約**

- $0 \le i < \lvert S \rvert$

**計算量**

- $\textrm{O}(1)$

---
