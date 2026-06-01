---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u69CB\u9020"
  - icon: ':question:'
    path: Library/Graph/GraphUtilities.hpp
    title: Library/Graph/GraphUtilities.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-C.test.cpp
    title: verify/AOJ-GRL-1-C.test.cpp
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
    \ e.cost);\n        }\n    }\n    return ret;\n}\n#line 3 \"Library/Graph/WarshallFloyd.hpp\"\
    \n\ntemplate<typename Ordered>\nclass WarshallFloyd{\n    public:\n    WarshallFloyd(Graph<Ordered>\
    \ &G) : V(G.VertexSize()), dist_(ConvertDistanceMatrix(G)){\n        Solve();\n\
    \    }\n\n    WarshallFloyd(vector<vector<Ordered>> &A) :\n        V((int)A.size()),\
    \ dist_(A){\n        Solve();\n    }\n\n    inline bool Reachable(const Vertex\
    \ &s, const Vertex &t) const {\n        return dist_[s][t] != inf;\n    }\n\n\
    \    inline Ordered Distance(const Vertex &s, const Vertex &t) const {\n     \
    \   return dist_[s][t];\n    }\n\n    inline bool NegativeCycle() const {\n  \
    \      return negative_cycle_;\n    }\n\n    inline vector<Ordered> &operator[](const\
    \ Vertex &s){\n        return dist_[s];\n    }\n\n    inline const vector<Ordered>\
    \ &operator[](const Vertex &s) const {\n        return dist_[s];\n    }\n\n  \
    \  private:\n    int V;\n    Ordered inf{Ordered(INF)};\n    bool negative_cycle_{false};\n\
    \    vector<vector<Ordered>> dist_;\n\n    void Solve(){\n        for(int i =\
    \ 0; i < V; ++i) dist_[i][i] = min(dist_[i][i], Ordered(0));\n        for(int\
    \ k = 0; k < V; ++k){\n            for(int i = 0; i < V; ++i){\n             \
    \   for(int j = 0; j < V; ++j){\n                    if(dist_[i][k] == inf ||\
    \ dist_[k][j] == inf) continue;\n                    dist_[i][j] = min(dist_[i][j],\
    \ dist_[i][k] + dist_[k][j]);\n                }\n            }\n        }\n \
    \       for(int i = 0; i < V; ++i) negative_cycle_ |= dist_[i][i] < 0;\n    }\n\
    };\n"
  code: "#include \"Graph.hpp\"\n#include \"GraphUtilities.hpp\"\n\ntemplate<typename\
    \ Ordered>\nclass WarshallFloyd{\n    public:\n    WarshallFloyd(Graph<Ordered>\
    \ &G) : V(G.VertexSize()), dist_(ConvertDistanceMatrix(G)){\n        Solve();\n\
    \    }\n\n    WarshallFloyd(vector<vector<Ordered>> &A) :\n        V((int)A.size()),\
    \ dist_(A){\n        Solve();\n    }\n\n    inline bool Reachable(const Vertex\
    \ &s, const Vertex &t) const {\n        return dist_[s][t] != inf;\n    }\n\n\
    \    inline Ordered Distance(const Vertex &s, const Vertex &t) const {\n     \
    \   return dist_[s][t];\n    }\n\n    inline bool NegativeCycle() const {\n  \
    \      return negative_cycle_;\n    }\n\n    inline vector<Ordered> &operator[](const\
    \ Vertex &s){\n        return dist_[s];\n    }\n\n    inline const vector<Ordered>\
    \ &operator[](const Vertex &s) const {\n        return dist_[s];\n    }\n\n  \
    \  private:\n    int V;\n    Ordered inf{Ordered(INF)};\n    bool negative_cycle_{false};\n\
    \    vector<vector<Ordered>> dist_;\n\n    void Solve(){\n        for(int i =\
    \ 0; i < V; ++i) dist_[i][i] = min(dist_[i][i], Ordered(0));\n        for(int\
    \ k = 0; k < V; ++k){\n            for(int i = 0; i < V; ++i){\n             \
    \   for(int j = 0; j < V; ++j){\n                    if(dist_[i][k] == inf ||\
    \ dist_[k][j] == inf) continue;\n                    dist_[i][j] = min(dist_[i][j],\
    \ dist_[i][k] + dist_[k][j]);\n                }\n            }\n        }\n \
    \       for(int i = 0; i < V; ++i) negative_cycle_ |= dist_[i][i] < 0;\n    }\n\
    };"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  - Library/Graph/GraphUtilities.hpp
  isVerificationFile: false
  path: Library/Graph/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-C.test.cpp
documentation_of: Library/Graph/WarshallFloyd.hpp
layout: document
redirect_from:
- /library/Library/Graph/WarshallFloyd.hpp
- /library/Library/Graph/WarshallFloyd.hpp.html
title: Library/Graph/WarshallFloyd.hpp
---
