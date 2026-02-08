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
    path: verify/LC-TreePathCompositeSum.test.cpp
    title: verify/LC-TreePathCompositeSum.test.cpp
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
    \  return ret;\n}\n#line 2 \"Library/Tree/RerootingDP.hpp\"\n\ntemplate<typename\
    \ CostType, typename Monoid>\nclass RerootingDP{\n    public:\n    using F = function<Monoid(Monoid,\
    \ Monoid, Vertex)>;\n    using G = function<Monoid(Monoid, CostType, Vertex)>;\n\
    \    using H = function<Monoid(Monoid, Vertex)>;\n    using Fsub = function<Monoid(Monoid,\
    \ Monoid)>;\n    using Gsub = function<Monoid(Monoid, CostType)>;\n\n    RerootingDP(Graph<CostType>\
    \ &tree, Fsub merge, Gsub add, const Monoid monoid_identity, Vertex r = 0) :\n\
    \            T(tree), n(tree.VertexSize()), parent(CalculateTreeParent(tree, r)),\
    \ cost(CalculateTreeCost(tree, r)), child(RootedTreeAdjacentList(tree, r)),\n\
    \            merge_sub_(merge), add_sub_(add), id_(monoid_identity){\n       \
    \ merge_ = [&](Monoid x, Monoid y, Vertex i){return merge_sub_(x, y);};\n    \
    \    add_ = [&](Monoid x, CostType y, Vertex i){return add_sub_(x, y);};\n   \
    \     finalize_ = [](Monoid x, Vertex i){return x;};\n        solve(r);\n    }\n\
    \n    RerootingDP(Graph<CostType> &tree, F merge, G add, H finalize, const Monoid\
    \ monoid_identity, Vertex r = 0) :\n            T(tree), n(tree.VertexSize()),\
    \ parent(CalculateTreeParent(tree, r)), cost(CalculateTreeCost(tree, r)), child(RootedTreeAdjacentList(tree,\
    \ r)),\n            merge_(merge), add_(add), finalize_(finalize), id_(monoid_identity){\n\
    \        solve(r);\n    }\n\n    vector<Monoid> &GetAllAnswer(){\n        return\
    \ dp_;\n    }\n\n    Monoid operator[](Vertex v){\n        return dp_[v];\n  \
    \  }\n\n    const Monoid operator[](Vertex v) const {\n        return dp_[v];\n\
    \    }\n\n    void Print() const {\n        cerr << \"# dp table :\";\n      \
    \  for(int i = 0; i < n; ++i){\n            cerr << \" \" << dp_[i];\n       \
    \ }\n        cerr << '\\n';\n        cerr << \"# subtree_dp table\" << '\\n';\n\
    \        for(int i = 0; i < n; ++i){\n            cerr << \"# vertex \" << i <<\
    \ '\\n';\n            cerr << \"#    subtree_dp :\";\n            for(int j =\
    \ 0; j < subtree_dp_[i].size(); ++j){\n                cerr << \" \" << subtree_dp_[i][j];\n\
    \            }\n            cerr << '\\n';\n            cerr << \"#    left_cum\
    \   :\";\n            for(int j = 0; j < left_cum_[i].size(); ++j){\n        \
    \        cerr << \" \" << left_cum_[i][j];\n            }\n            cerr <<\
    \ '\\n';\n            cerr << \"#    right_cum  :\";\n            for(int j =\
    \ 0; j < right_cum_[i].size(); ++j){\n                cerr << \" \" << right_cum_[i][j];\n\
    \            }\n            cerr << '\\n';\n        }\n    }\n\n    private:\n\
    \    Graph<CostType> &T;\n    int n;\n    vector<Vertex> parent;\n    vector<CostType>\
    \ cost;\n    vector<vector<Vertex>> child;\n    \n    vector<Monoid> dp_;\n  \
    \  vector<vector<Monoid>> subtree_dp_, left_cum_, right_cum_;\n\n    const Monoid\
    \ id_;\n\n    F merge_;\n    G add_;\n    H finalize_;\n    const Fsub merge_sub_;\n\
    \    const Gsub add_sub_;\n\n    Monoid dfs(Vertex v, bool root = false){\n  \
    \      Monoid ret = id_;\n        for(auto u : child[v]){\n            Monoid\
    \ res = dfs(u);\n            subtree_dp_[v].push_back(res);\n            ret =\
    \ merge_(ret, res, v);\n        }\n        if(root) ret = finalize_(ret, v);\n\
    \        else ret = add_(ret, cost[v], v);\n        return ret;\n    }\n\n   \
    \ void solve(Vertex r){\n        dp_.resize(n, id_);\n        subtree_dp_.resize(n,\
    \ vector<Monoid>{id_});\n        left_cum_.resize(n);\n        right_cum_.resize(n);\n\
    \n        dp_[r] = dfs(r, true);\n        int root_size = subtree_dp_[r].size();\n\
    \        left_cum_[r].resize(root_size + 1);\n        left_cum_[r].front() = id_;\n\
    \        for(int i = 1; i < root_size; ++i){\n            left_cum_[r][i] = merge_(left_cum_[r][i\
    \ - 1], subtree_dp_[r][i], r);\n        }\n        right_cum_[r].resize(root_size\
    \ + 1);\n        right_cum_[r].back() = id_;\n        for(int i = root_size -\
    \ 1; i - 1 >= 0; --i){\n            right_cum_[r][i] = merge_(right_cum_[r][i\
    \ + 1], subtree_dp_[r][i], r);\n        }\n\n        queue<tuple<int, int, int>>\
    \ que;\n        for(int i = 0; i < child[r].size(); ++i){\n            que.push({child[r][i],\
    \ r, i + 1});\n        }\n        while(que.size()){\n            auto [v, p,\
    \ idx] = que.front(); que.pop();\n            Monoid ret = id_;\n            ret\
    \ = merge_(ret, left_cum_[p][idx - 1], v);\n            ret = merge_(ret, right_cum_[p][idx\
    \ + 1], v);\n            ret = add_(ret, cost[v], p);\n            subtree_dp_[v].push_back(ret);\n\
    \            for(int i = 1; i + 1 < subtree_dp_[v].size(); ++i){\n           \
    \     ret = merge_(ret, subtree_dp_[v][i], v);\n            }\n            dp_[v]\
    \ = finalize_(ret, v);\n            int c = subtree_dp_[v].size();\n         \
    \   left_cum_[v].resize(c + 1);\n            left_cum_[v][0] = id_;\n        \
    \    for(int i = 1; i < c; ++i){\n                left_cum_[v][i] = merge_(left_cum_[v][i\
    \ - 1], subtree_dp_[v][i], v);\n            }\n            right_cum_[v].resize(c\
    \ + 1);\n            right_cum_[v].back() = id_;\n            for(int i = c -\
    \ 1; i - 1 >= 0; --i){\n                right_cum_[v][i] = merge_(right_cum_[v][i\
    \ + 1], subtree_dp_[v][i], v);\n            }\n            for(int i = 0; i <\
    \ child[v].size(); ++i){\n                que.push({child[v][i], v, i + 1});\n\
    \            }\n        }\n    }\n};\n"
  code: "#include \"Tree.hpp\"\n\ntemplate<typename CostType, typename Monoid>\nclass\
    \ RerootingDP{\n    public:\n    using F = function<Monoid(Monoid, Monoid, Vertex)>;\n\
    \    using G = function<Monoid(Monoid, CostType, Vertex)>;\n    using H = function<Monoid(Monoid,\
    \ Vertex)>;\n    using Fsub = function<Monoid(Monoid, Monoid)>;\n    using Gsub\
    \ = function<Monoid(Monoid, CostType)>;\n\n    RerootingDP(Graph<CostType> &tree,\
    \ Fsub merge, Gsub add, const Monoid monoid_identity, Vertex r = 0) :\n      \
    \      T(tree), n(tree.VertexSize()), parent(CalculateTreeParent(tree, r)), cost(CalculateTreeCost(tree,\
    \ r)), child(RootedTreeAdjacentList(tree, r)),\n            merge_sub_(merge),\
    \ add_sub_(add), id_(monoid_identity){\n        merge_ = [&](Monoid x, Monoid\
    \ y, Vertex i){return merge_sub_(x, y);};\n        add_ = [&](Monoid x, CostType\
    \ y, Vertex i){return add_sub_(x, y);};\n        finalize_ = [](Monoid x, Vertex\
    \ i){return x;};\n        solve(r);\n    }\n\n    RerootingDP(Graph<CostType>\
    \ &tree, F merge, G add, H finalize, const Monoid monoid_identity, Vertex r =\
    \ 0) :\n            T(tree), n(tree.VertexSize()), parent(CalculateTreeParent(tree,\
    \ r)), cost(CalculateTreeCost(tree, r)), child(RootedTreeAdjacentList(tree, r)),\n\
    \            merge_(merge), add_(add), finalize_(finalize), id_(monoid_identity){\n\
    \        solve(r);\n    }\n\n    vector<Monoid> &GetAllAnswer(){\n        return\
    \ dp_;\n    }\n\n    Monoid operator[](Vertex v){\n        return dp_[v];\n  \
    \  }\n\n    const Monoid operator[](Vertex v) const {\n        return dp_[v];\n\
    \    }\n\n    void Print() const {\n        cerr << \"# dp table :\";\n      \
    \  for(int i = 0; i < n; ++i){\n            cerr << \" \" << dp_[i];\n       \
    \ }\n        cerr << '\\n';\n        cerr << \"# subtree_dp table\" << '\\n';\n\
    \        for(int i = 0; i < n; ++i){\n            cerr << \"# vertex \" << i <<\
    \ '\\n';\n            cerr << \"#    subtree_dp :\";\n            for(int j =\
    \ 0; j < subtree_dp_[i].size(); ++j){\n                cerr << \" \" << subtree_dp_[i][j];\n\
    \            }\n            cerr << '\\n';\n            cerr << \"#    left_cum\
    \   :\";\n            for(int j = 0; j < left_cum_[i].size(); ++j){\n        \
    \        cerr << \" \" << left_cum_[i][j];\n            }\n            cerr <<\
    \ '\\n';\n            cerr << \"#    right_cum  :\";\n            for(int j =\
    \ 0; j < right_cum_[i].size(); ++j){\n                cerr << \" \" << right_cum_[i][j];\n\
    \            }\n            cerr << '\\n';\n        }\n    }\n\n    private:\n\
    \    Graph<CostType> &T;\n    int n;\n    vector<Vertex> parent;\n    vector<CostType>\
    \ cost;\n    vector<vector<Vertex>> child;\n    \n    vector<Monoid> dp_;\n  \
    \  vector<vector<Monoid>> subtree_dp_, left_cum_, right_cum_;\n\n    const Monoid\
    \ id_;\n\n    F merge_;\n    G add_;\n    H finalize_;\n    const Fsub merge_sub_;\n\
    \    const Gsub add_sub_;\n\n    Monoid dfs(Vertex v, bool root = false){\n  \
    \      Monoid ret = id_;\n        for(auto u : child[v]){\n            Monoid\
    \ res = dfs(u);\n            subtree_dp_[v].push_back(res);\n            ret =\
    \ merge_(ret, res, v);\n        }\n        if(root) ret = finalize_(ret, v);\n\
    \        else ret = add_(ret, cost[v], v);\n        return ret;\n    }\n\n   \
    \ void solve(Vertex r){\n        dp_.resize(n, id_);\n        subtree_dp_.resize(n,\
    \ vector<Monoid>{id_});\n        left_cum_.resize(n);\n        right_cum_.resize(n);\n\
    \n        dp_[r] = dfs(r, true);\n        int root_size = subtree_dp_[r].size();\n\
    \        left_cum_[r].resize(root_size + 1);\n        left_cum_[r].front() = id_;\n\
    \        for(int i = 1; i < root_size; ++i){\n            left_cum_[r][i] = merge_(left_cum_[r][i\
    \ - 1], subtree_dp_[r][i], r);\n        }\n        right_cum_[r].resize(root_size\
    \ + 1);\n        right_cum_[r].back() = id_;\n        for(int i = root_size -\
    \ 1; i - 1 >= 0; --i){\n            right_cum_[r][i] = merge_(right_cum_[r][i\
    \ + 1], subtree_dp_[r][i], r);\n        }\n\n        queue<tuple<int, int, int>>\
    \ que;\n        for(int i = 0; i < child[r].size(); ++i){\n            que.push({child[r][i],\
    \ r, i + 1});\n        }\n        while(que.size()){\n            auto [v, p,\
    \ idx] = que.front(); que.pop();\n            Monoid ret = id_;\n            ret\
    \ = merge_(ret, left_cum_[p][idx - 1], v);\n            ret = merge_(ret, right_cum_[p][idx\
    \ + 1], v);\n            ret = add_(ret, cost[v], p);\n            subtree_dp_[v].push_back(ret);\n\
    \            for(int i = 1; i + 1 < subtree_dp_[v].size(); ++i){\n           \
    \     ret = merge_(ret, subtree_dp_[v][i], v);\n            }\n            dp_[v]\
    \ = finalize_(ret, v);\n            int c = subtree_dp_[v].size();\n         \
    \   left_cum_[v].resize(c + 1);\n            left_cum_[v][0] = id_;\n        \
    \    for(int i = 1; i < c; ++i){\n                left_cum_[v][i] = merge_(left_cum_[v][i\
    \ - 1], subtree_dp_[v][i], v);\n            }\n            right_cum_[v].resize(c\
    \ + 1);\n            right_cum_[v].back() = id_;\n            for(int i = c -\
    \ 1; i - 1 >= 0; --i){\n                right_cum_[v][i] = merge_(right_cum_[v][i\
    \ + 1], subtree_dp_[v][i], v);\n            }\n            for(int i = 0; i <\
    \ child[v].size(); ++i){\n                que.push({child[v][i], v, i + 1});\n\
    \            }\n        }\n    }\n};"
  dependsOn:
  - Library/Tree/Tree.hpp
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Tree/RerootingDP.hpp
  requiredBy: []
  timestamp: '2026-02-08 19:36:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-TreePathCompositeSum.test.cpp
documentation_of: Library/Tree/RerootingDP.hpp
layout: document
title: "Rerooting DP - \u5168\u65B9\u4F4D\u6728DP"
---

# Rerooting DP - 全方位木DP

木のすべての頂点を根としたときの DP の値を効率的に計算するデータ構造です。

各頂点を根とした場合の DP を愚直に計算すると $\textrm{O}(N^2)$ かかりますが、全方位木 DP を用いることで $\textrm{O}(N)$ で計算できます。

## Function

### Constructor (辺属性のみ)

```
RerootingDP(Graph<CostType> &tree, Fsub merge, Gsub add, const Monoid monoid_identity, Vertex r = 0)
```

- 木 `tree` に対して全方位木 DP を行います（辺属性のみを考慮）。
- `merge`: `(Monoid, Monoid) -> Monoid` - モノイド同士の二項演算
- `add`: `(Monoid, CostType) -> Monoid` - モノイドと辺コストの二項演算
- `monoid_identity`: モノイドの単位元
- `r`: 初期の根（デフォルトは頂点 0）

**型定義**
- `Fsub = function<Monoid(Monoid, Monoid)>`
- `Gsub = function<Monoid(Monoid, CostType)>`

**制約**

- $1 \le N \le 10^5$
- `merge` と `add` はモノイドの演算を満たす

**計算量**

- $\textrm{O}(N)$

---

### Constructor (頂点属性を含む)

```
RerootingDP(Graph<CostType> &tree, F merge, G add, H finalize, const Monoid monoid_identity, Vertex r = 0)
```

- 木 `tree` に対して全方位木 DP を行います（頂点属性を含む）。
- `merge`: `(Monoid, Monoid, Vertex) -> Monoid` - モノイド同士の二項演算（頂点情報を利用）
- `add`: `(Monoid, CostType, Vertex) -> Monoid` - モノイドと辺コストの二項演算（頂点情報を利用）
- `finalize`: `(Monoid, Vertex) -> Monoid` - 頂点が根のときの最終処理
- `monoid_identity`: モノイドの単位元
- `r`: 初期の根（デフォルトは頂点 0）

**型定義**
- `F = function<Monoid(Monoid, Monoid, Vertex)>`
- `G = function<Monoid(Monoid, CostType, Vertex)>`
- `H = function<Monoid(Monoid, Vertex)>`

**制約**

- $1 \le N \le 10^5$
- `merge`, `add`, `finalize` はモノイドの演算を満たす

**計算量**

- $\textrm{O}(N)$

---

### GetAllAnswer

```
vector<Monoid> &GetAllAnswer()
```

- 全頂点に関する DP の結果の配列を取得します。
- 配列の $i$ 番目の要素は、頂点 $i$ を根としたときの DP の値です。

**計算量**

- $\textrm{O}(1)$

---

### operator[]

```
Monoid operator[](Vertex v)
const Monoid operator[](Vertex v) const
```

- 頂点 $v$ を根としたときの DP の値を返します。

**計算量**

- $\textrm{O}(1)$

---

### Print

```
void Print() const
```

- デバッグ用に DP テーブルの内容を標準エラー出力に出力します。

**計算量**

- $\textrm{O}(N)$

---
