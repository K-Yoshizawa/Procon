---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u69CB\u9020"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/Tree.hpp
    title: Library/Tree/Tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cmath>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const\
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 2 \"Library/Tree/Tree.hpp\"\n\
    \n#line 2 \"Library/Graph/Graph.hpp\"\n\n#line 4 \"Library/Graph/Graph.hpp\"\n\
    \nusing Vertex = int;\n\ntemplate<typename Ordered = int32_t>\nstruct Edge{\n\
    \    public:\n    Edge() = default;\n\n    Edge(Vertex from_, Vertex to_, Ordered\
    \ weight_ = 1, int idx_ = -1) :\n        from(from_), to(to_), cost(weight_),\
    \ idx(idx_){}\n    \n    bool operator<(const Edge<Ordered> &e) const {return\
    \ cost < e.cost;}\n\n    operator int() const {return to;}\n\n    Vertex from,\
    \ to;\n    Ordered cost;\n    int idx;\n};\n\ntemplate<typename Ordered = int32_t>\n\
    class Graph{\n    public:\n    Graph() = default;\n\n    Graph(int V) : edge_size_(0),\
    \ adjacent_list_(V){}\n    \n    inline void AddUndirectedEdge(Vertex u, Vertex\
    \ v, Ordered w = 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<Ordered>(u,\
    \ v, w, idx));\n        adjacent_list_[v].push_back(Edge<Ordered>(v, u, w, idx));\n\
    \    }\n    \n    inline void AddDirectedEdge(Vertex u, Vertex v, Ordered w =\
    \ 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<Ordered>(u,\
    \ v, w, idx));\n    }\n\n    inline size_t VertexSize() const {\n        return\
    \ adjacent_list_.size();\n    }\n\n    inline size_t EdgeSize() const {\n    \
    \    return edge_size_;\n    }\n\n    inline vector<Edge<Ordered>> &operator[](const\
    \ Vertex v){\n        return adjacent_list_[v];\n    }\n\n    inline const vector<Edge<Ordered>>\
    \ &operator[](const Vertex v) const {\n        return adjacent_list_[v];\n   \
    \ }\n    \n    private:\n    size_t edge_size_;\n    vector<vector<Edge<Ordered>>>\
    \ adjacent_list_;\n};\n\ntemplate<typename Ordered = int32_t>\nGraph<Ordered>\
    \ InputGraph(int V, int E, int padding = -1, bool weighted = false, bool directed\
    \ = false){\n    Graph<Ordered> G(V);\n    for(int i = 0; i < E; ++i){\n     \
    \   Vertex u, v; Ordered w = 1;\n        cin >> u >> v, u += padding, v += padding;\n\
    \        if(weighted) cin >> w;\n        if(directed) G.AddDirectedEdge(u, v,\
    \ w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n#line\
    \ 4 \"Library/Tree/Tree.hpp\"\n\ntemplate<typename Ordered = int32_t>\nGraph<Ordered>\
    \ InputTree(int V, int padding = -1, bool weighted = false){\n    Graph<Ordered>\
    \ G(V);\n    for(int i = 0; i < V - 1; ++i){\n        Vertex u, v; Ordered w =\
    \ 1;\n        cin >> u >> v, u += padding, v += padding;\n        if(weighted)\
    \ cin >> w;\n        G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n\n\
    template<typename Ordered = int32_t>\nGraph<Ordered> InputRootedTreeChild(int\
    \ V, int padding = -1){\n    Graph<Ordered> G(V);\n    for(Vertex u = 0; u < V;\
    \ ++u){\n        int k; cin >> k;\n        for(int i = 0; i < k; ++i){\n     \
    \       Vertex v; cin >> v, v += padding;\n            G.AddUndirectedEdge(u,\
    \ v);\n        }\n    }\n    return G;\n}\n\ntemplate<typename Ordered = int32_t>\n\
    Graph<Ordered> InputRootedTreeParent(int V, int padding = -1){\n    Graph<Ordered>\
    \ G(V);\n    for(Vertex u = 1; u < V; ++u){\n        Vertex v; cin >> v, v +=\
    \ padding;\n        G.AddUndirectedEdge(u, v);\n    }\n    return G;\n}\n\ntemplate<typename\
    \ Ordered = int32_t>\nvector<vector<Vertex>> RootedTreeAdjacentList(const Graph<Ordered>\
    \ &T, const Vertex r = 0){\n    int V = T.VertexSize();\n    vector<vector<Vertex>>\
    \ ret(V);\n    auto rec = [&](auto &self, Vertex u, Vertex p) -> void {\n    \
    \    for(Vertex v : T[u]){\n            if(v == p) continue;\n            ret[u].push_back(v);\n\
    \            self(self, v, u);\n        }\n    };\n    rec(rec, r, -1);\n    return\
    \ ret;\n}\n\ntemplate<typename Ordered>\nvector<Vertex> CalculateTreeParent(Graph<Ordered>\
    \ &T, Vertex r = 0){\n    int V = T.VertexSize();\n    vector<Vertex> ret(V, -1);\n\
    \    auto rec = [&](auto &self, Vertex u) -> void {\n        for(Vertex v : T[u]){\n\
    \            if(v == ret[u]) continue;\n            ret[v] = u;\n            self(self,\
    \ v);\n        }\n    };\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ Ordered>\nvector<Ordered> CalculateTreeCost(Graph<Ordered> &T, Vertex r = 0){\n\
    \    int V = T.VertexSize();\n    vector<Ordered> ret(V);\n    auto rec = [&](auto\
    \ &self, Vertex u, Vertex p) -> void {\n        for(const Edge<Ordered> &e : T[u]){\n\
    \            Vertex v = e.to;\n            if(v == p) continue;\n            ret[v]\
    \ = e.cost;\n            self(self, v, u);\n        }\n    };\n    rec(rec, r,\
    \ -1);\n    return ret;\n}\n\ntemplate<typename Ordered>\nvector<int> CalculateTreeDepth(Graph<Ordered>\
    \ &T, Vertex r = 0){\n    int V = T.VertexSize();\n    vector<int> ret(V, 0);\n\
    \    auto rec = [&](auto &self, Vertex u, Vertex p, int d) -> void {\n       \
    \ ret[u] = d;\n        for(Vertex v : T[u]){\n            if(v == p) continue;\n\
    \            self(self, v, u, d + 1);\n        }\n    };\n    rec(rec, r, -1,\
    \ 0);\n    return ret;\n}\n\ntemplate<typename Ordered>\nvector<Ordered> CalculateTreeDistance(Graph<Ordered>\
    \ &T, Vertex r = 0){\n    int V = T.VertexSize();\n    vector<Ordered> ret(V,\
    \ Ordered(INF));\n    auto rec = [&](auto &self, Vertex u) -> void {\n       \
    \ for(const Edge<Ordered> &e : T[u]){\n            if(ret[e.to] > ret[u] + e.cost){\n\
    \                ret[e.to] = ret[u] + e.cost;\n                self(self, e.to);\n\
    \            }\n        }\n    };\n    ret[r] = 0;\n    rec(rec, r);\n    return\
    \ ret;\n}\n\ntemplate<typename Ordered>\nvector<int> CalculateSubtreeSize(Graph<Ordered>\
    \ &tree, Vertex r = 0){\n    int V = tree.VertexSize();\n    vector<int> ret(V,\
    \ 1);\n    auto rec = [&](auto self, Vertex u, Vertex p) -> int {\n        for(const\
    \ int v : tree[u]){\n            if(v == p) continue;\n            ret[u] += self(self,\
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
  timestamp: '2026-06-01 14:23:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/String/Trie.hpp
layout: document
redirect_from:
- /library/Library/String/Trie.hpp
- /library/Library/String/Trie.hpp.html
title: Library/String/Trie.hpp
---
