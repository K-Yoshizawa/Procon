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
    path: Library/Graph/GraphUtilities.hpp
    title: Library/Graph/GraphUtilities.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-B.test.cpp
    title: verify/AOJ-GRL-1-B.test.cpp
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
    \ e.cost);\n        }\n    }\n    return ret;\n}\n#line 3 \"Library/Graph/BellmanFord.hpp\"\
    \n\ntemplate<typename Ordered>\nclass BellmanFord{\n    public:\n    BellmanFord(Graph<Ordered>\
    \ &G, Vertex s = -1) : G(G), V(G.VertexSize()), dist_(V){\n        if(s != -1)\
    \ Solve(s);\n    }\n\n    inline bool Reachable(const Vertex &t) const {\n   \
    \     return dist_[t] != inf;\n    }\n\n    inline Ordered Distance(const Vertex\
    \ &t) const {\n        return dist_[t];\n    }\n\n    inline bool NegativeCycle()\
    \ const {\n        return negative_cycle_;\n    }\n\n    void Solve(Vertex s){\n\
    \        fill(dist_.begin(), dist_.end(), inf);\n        dist_[s] = Ordered(0);\n\
    \        negative_cycle_ = false;\n        int update_count = 0;\n        auto\
    \ E = ConvertEdgeSet(G);\n        while(1){\n            if(update_count == V){\n\
    \                negative_cycle_ = true;\n                break;\n           \
    \ }\n            bool update_flag = false;\n            for(const Edge<Ordered>\
    \ &e : E){\n                if(dist_[e.from] == inf) continue;\n             \
    \   if(dist_[e.to] > dist_[e.from] + e.cost){\n                    dist_[e.to]\
    \ = dist_[e.from] + e.cost;\n                    update_flag = true;\n       \
    \         }\n            }\n            if(!update_flag) break;\n            ++update_count;\n\
    \        }\n    }\n\n    inline Ordered operator[](const Vertex &t){\n       \
    \ return dist_[t];\n    }\n\n    inline const Ordered operator[](const Vertex\
    \ &t) const {\n        return dist_[t];\n    }\n\n    private:\n    Graph<Ordered>\
    \ &G;\n    int V;\n    Ordered inf{Ordered(INF)};\n    bool negative_cycle_;\n\
    \    vector<Ordered> dist_;\n};\n"
  code: "#include \"Graph.hpp\"\n#include \"GraphUtilities.hpp\"\n\ntemplate<typename\
    \ Ordered>\nclass BellmanFord{\n    public:\n    BellmanFord(Graph<Ordered> &G,\
    \ Vertex s = -1) : G(G), V(G.VertexSize()), dist_(V){\n        if(s != -1) Solve(s);\n\
    \    }\n\n    inline bool Reachable(const Vertex &t) const {\n        return dist_[t]\
    \ != inf;\n    }\n\n    inline Ordered Distance(const Vertex &t) const {\n   \
    \     return dist_[t];\n    }\n\n    inline bool NegativeCycle() const {\n   \
    \     return negative_cycle_;\n    }\n\n    void Solve(Vertex s){\n        fill(dist_.begin(),\
    \ dist_.end(), inf);\n        dist_[s] = Ordered(0);\n        negative_cycle_\
    \ = false;\n        int update_count = 0;\n        auto E = ConvertEdgeSet(G);\n\
    \        while(1){\n            if(update_count == V){\n                negative_cycle_\
    \ = true;\n                break;\n            }\n            bool update_flag\
    \ = false;\n            for(const Edge<Ordered> &e : E){\n                if(dist_[e.from]\
    \ == inf) continue;\n                if(dist_[e.to] > dist_[e.from] + e.cost){\n\
    \                    dist_[e.to] = dist_[e.from] + e.cost;\n                 \
    \   update_flag = true;\n                }\n            }\n            if(!update_flag)\
    \ break;\n            ++update_count;\n        }\n    }\n\n    inline Ordered\
    \ operator[](const Vertex &t){\n        return dist_[t];\n    }\n\n    inline\
    \ const Ordered operator[](const Vertex &t) const {\n        return dist_[t];\n\
    \    }\n\n    private:\n    Graph<Ordered> &G;\n    int V;\n    Ordered inf{Ordered(INF)};\n\
    \    bool negative_cycle_;\n    vector<Ordered> dist_;\n};"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  - Library/Graph/GraphUtilities.hpp
  isVerificationFile: false
  path: Library/Graph/BellmanFord.hpp
  requiredBy: []
  timestamp: '2026-06-01 14:23:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-B.test.cpp
documentation_of: Library/Graph/BellmanFord.hpp
layout: document
redirect_from:
- /library/Library/Graph/BellmanFord.hpp
- /library/Library/Graph/BellmanFord.hpp.html
title: Library/Graph/BellmanFord.hpp
---
