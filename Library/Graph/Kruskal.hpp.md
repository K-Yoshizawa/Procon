---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/DataStructure/UnionFind.hpp
    title: Library/DataStructure/UnionFind.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u69CB\u9020"
  - icon: ':question:'
    path: Library/Graph/GraphUtilities.hpp
    title: Library/Graph/GraphUtilities.hpp
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
    #include <bit>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 4 \"Library/Graph/Graph.hpp\"\n\nusing Vertex = int;\n\ntemplate<typename\
    \ Ordered = int32_t>\nstruct Edge{\n    public:\n    Edge() = default;\n\n   \
    \ Edge(Vertex from_, Vertex to_, Ordered weight_ = 1, int idx_ = -1) :\n     \
    \   from(from_), to(to_), cost(weight_), idx(idx_){}\n    \n    bool operator<(const\
    \ Edge<Ordered> &e) const {return cost < e.cost;}\n\n    operator int() const\
    \ {return to;}\n\n    Vertex from, to;\n    Ordered cost;\n    int idx;\n};\n\n\
    template<typename Ordered = int32_t>\nclass Graph{\n    public:\n    Graph() =\
    \ default;\n\n    Graph(int V) : edge_size_(0), adjacent_list_(V){}\n    \n  \
    \  inline void AddUndirectedEdge(Vertex u, Vertex v, Ordered w = 1){\n       \
    \ int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<Ordered>(u,\
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
    \ 2 \"Library/Graph/GraphUtilities.hpp\"\n\n#line 4 \"Library/Graph/GraphUtilities.hpp\"\
    \n\ntemplate<typename WeightType>\nvector<Edge<WeightType>> ConvertEdgeSet(const\
    \ Graph<WeightType> &G){\n    vector<Edge<WeightType>> ret;\n    vector<bool>\
    \ check(G.EdgeSize(), false);\n    int V = G.VertexSize();\n    for(int u = 0;\
    \ u < V; ++u){\n        for(const Edge<WeightType> &e : G[u]){\n            if(check[e.idx])\
    \ continue;\n            check[e.idx] = true;\n            ret.push_back(e);\n\
    \        }\n    }\n    return ret;\n}\n\ntemplate<typename WeightType>\nvector<vector<WeightType>>\
    \ ConvertDistanceMatrix(const Graph<WeightType> &G){\n    int V = G.VertexSize();\n\
    \    vector<vector<WeightType>> ret(V, vector<WeightType>(V, WeightType(INF)));\n\
    \    for(int u = 0; u < V; ++u){\n        ret[u][u] = WeightType(0);\n       \
    \ for(const Edge<WeightType> &e : G[u]){\n            ret[u][e.to] = e.cost;\n\
    \        }\n    }\n    return ret;\n}\n\ntemplate<typename WeightType>\nGraph<WeightType>\
    \ ReverseGraph(const Graph<WeightType> &G){\n    int V = G.VertexSize();\n   \
    \ Graph<WeightType> ret(V);\n    for(int u = 0; u < V; ++u){\n        for(const\
    \ Edge<WeightType> &e : G[u]){\n            ret.AddDirectedEdge(e.to, e.from,\
    \ e.cost);\n        }\n    }\n    return ret;\n}\n#line 2 \"Library/DataStructure/UnionFind.hpp\"\
    \n\n#line 4 \"Library/DataStructure/UnionFind.hpp\"\n\nclass UnionFind{\n    public:\n\
    \    UnionFind(size_t N) : data_(N, -1){}\n\n    int Find(const int k){\n    \
    \    if(data_[k] < 0) return k;\n        int r = Find(data_[k]);\n        return\
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
    \ 4 \"Library/Graph/Kruskal.hpp\"\n\ntemplate<typename Ordered>\nclass Kruskal{\n\
    \    public:\n    Kruskal(Graph<Ordered> &G) : G(G), cost_(0){\n        int V\
    \ = G.VertexSize();\n        auto Es = ConvertEdgeSet(G);\n        sort(Es.begin(),\
    \ Es.end());\n        UnionFind uf(V);\n        for(const Edge<Ordered> &e : Es){\n\
    \            if(uf.Unite(e.from, e.to)){\n                cost_ += e.cost;\n \
    \               edges_.push_back(e);\n            }\n        }\n    }\n\n    inline\
    \ vector<Edge<Ordered>> &GetEdgeSet(){\n        return edges_;\n    }\n\n    inline\
    \ Ordered GetCost() const {\n        return cost_;\n    }\n\n    private:\n  \
    \  Graph<Ordered> &G;\n    vector<Edge<Ordered>> edges_;\n    Ordered cost_;\n\
    };\n"
  code: "#include \"Graph.hpp\"\n#include \"GraphUtilities.hpp\"\n#include \"../DataStructure/UnionFind.hpp\"\
    \n\ntemplate<typename Ordered>\nclass Kruskal{\n    public:\n    Kruskal(Graph<Ordered>\
    \ &G) : G(G), cost_(0){\n        int V = G.VertexSize();\n        auto Es = ConvertEdgeSet(G);\n\
    \        sort(Es.begin(), Es.end());\n        UnionFind uf(V);\n        for(const\
    \ Edge<Ordered> &e : Es){\n            if(uf.Unite(e.from, e.to)){\n         \
    \       cost_ += e.cost;\n                edges_.push_back(e);\n            }\n\
    \        }\n    }\n\n    inline vector<Edge<Ordered>> &GetEdgeSet(){\n       \
    \ return edges_;\n    }\n\n    inline Ordered GetCost() const {\n        return\
    \ cost_;\n    }\n\n    private:\n    Graph<Ordered> &G;\n    vector<Edge<Ordered>>\
    \ edges_;\n    Ordered cost_;\n};"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  - Library/Graph/GraphUtilities.hpp
  - Library/DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: Library/Graph/Kruskal.hpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
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
