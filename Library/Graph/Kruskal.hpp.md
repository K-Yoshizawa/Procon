---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/UnionFind.hpp
    title: "Union-Find - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/GraphMisc.hpp
    title: Library/Graph/GraphMisc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-MinimumSpanningTree.test.cpp
    title: verify/LC-MinimumSpanningTree.test.cpp
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
    \  return ret;\n}\n#line 2 \"Library/DataStructure/UnionFind.hpp\"\n\n#line 4\
    \ \"Library/DataStructure/UnionFind.hpp\"\n\nclass UnionFind{\n    public:\n \
    \   UnionFind(size_t n) : data_(n, -1){}\n\n    int Find(const int k){\n     \
    \   if(data_[k] < 0) return k;\n        int r = Find(data_[k]);\n        return\
    \ data_[k] = r;\n    }\n\n    bool Same(const int x, const int y){\n        return\
    \ Find(x) == Find(y);\n    }\n\n    bool Unite(int x, int y){\n        x = Find(x),\
    \ y = Find(y);\n        if(x == y) return false;\n        if(data_[x] > data_[y])\
    \ swap(x, y);\n        data_[x] += data_[y];\n        data_[y] = x;\n        return\
    \ true;\n    }\n    \n    size_t Size(int k){\n        int v = Find(k);\n    \
    \    return -data_[v];\n    }\n\n    vector<vector<int>> Group(){\n        vector<vector<int>>\
    \ ret(data_.size());\n        for(int i = 0; i < data_.size(); ++i){\n       \
    \     ret[Find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](vector<int> &v){\n            return v.empty();\n        }), end(ret));\n\
    \        return ret;\n    }\n\n    private:\n    vector<int> data_;\n};\n#line\
    \ 4 \"Library/Graph/Kruskal.hpp\"\n\ntemplate<typename CostType>\nclass Kruskal{\n\
    \    public:\n    Kruskal(Graph<CostType> &graph) : G(graph), cost_(0){\n    \
    \    int N = G.VertexSize();\n        auto E = ConvertEdgeSet(G);\n        sort(E.begin(),\
    \ E.end());\n        UnionFind uf(N);\n        for(const Edge<CostType> &e : E){\n\
    \            if(uf.Unite(e.from, e.to)){\n                cost_ += e.cost;\n \
    \               edges_.push_back(e);\n            }\n        }\n    }\n\n    inline\
    \ vector<Edge<CostType>> &GetEdgeSet(){\n        return edges_;\n    }\n\n   \
    \ inline CostType GetCost() const {\n        return cost_;\n    }\n\n    private:\n\
    \    Graph<CostType> &G;\n    vector<Edge<CostType>> edges_;\n    CostType cost_;\n\
    };\n"
  code: "#include \"Graph.hpp\"\n#include \"GraphMisc.hpp\"\n#include \"../DataStructure/UnionFind.hpp\"\
    \n\ntemplate<typename CostType>\nclass Kruskal{\n    public:\n    Kruskal(Graph<CostType>\
    \ &graph) : G(graph), cost_(0){\n        int N = G.VertexSize();\n        auto\
    \ E = ConvertEdgeSet(G);\n        sort(E.begin(), E.end());\n        UnionFind\
    \ uf(N);\n        for(const Edge<CostType> &e : E){\n            if(uf.Unite(e.from,\
    \ e.to)){\n                cost_ += e.cost;\n                edges_.push_back(e);\n\
    \            }\n        }\n    }\n\n    inline vector<Edge<CostType>> &GetEdgeSet(){\n\
    \        return edges_;\n    }\n\n    inline CostType GetCost() const {\n    \
    \    return cost_;\n    }\n\n    private:\n    Graph<CostType> &G;\n    vector<Edge<CostType>>\
    \ edges_;\n    CostType cost_;\n};"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  - Library/Graph/GraphMisc.hpp
  - Library/DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: Library/Graph/Kruskal.hpp
  requiredBy: []
  timestamp: '2025-03-23 23:54:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-MinimumSpanningTree.test.cpp
documentation_of: Library/Graph/Kruskal.hpp
layout: document
redirect_from:
- /library/Library/Graph/Kruskal.hpp
- /library/Library/Graph/Kruskal.hpp.html
title: Library/Graph/Kruskal.hpp
---
