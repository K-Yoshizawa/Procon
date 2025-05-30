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
    path: Library/Graph/GraphMisc.hpp
    title: Library/Graph/GraphMisc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-C.test.cpp
    title: verify/AOJ-GRL-3-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-StronglyConnectedComponents.test.cpp
    title: verify/LC-StronglyConnectedComponents.test.cpp
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
    \ const ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 4 \"Library/Graph/Graph.hpp\"\
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
    \  return ret;\n}\n#line 3 \"Library/Graph/StronglyConnectedComponents.hpp\"\n\
    \ntemplate<typename CostType>\nstruct StronglyConnectedComponents{\n    public:\n\
    \    StronglyConnectedComponents(Graph<CostType> &graph) :\n        G(graph),\
    \ RG(ReverseGraph(graph)), n(G.VertexSize()), belong_(n, -1){\n        vector<int>\
    \ label(n, -1);\n        vector<bool> state(n, false);\n        int nex = 0;\n\
    \        vector<Vertex> vs(n);\n        iota(vs.begin(), vs.end(), 0);\n     \
    \   for(auto v : vs){\n            if(!state[v]) dfs1(v, label, nex, state);\n\
    \        }\n        sort(vs.begin(), vs.end(), [&](Vertex u, Vertex v){\n    \
    \        return label[u] > label[v];\n        });\n        for(auto v : vs){\n\
    \            if(state[v]){\n                int c = components_.size();\n    \
    \            components_.push_back(vector<Vertex>{});\n                dfs2(v,\
    \ label, c, state);\n            }\n        }\n    }\n\n    inline vector<vector<Vertex>>\
    \ &Components(){\n        return components_;\n    }\n\n    inline int ComponentCount()\
    \ const {\n        return (int)components_.size();\n    }\n\n    inline int BelongComponent(const\
    \ Vertex &v) const {\n        return belong_[v];\n    }\n\n    vector<Vertex>\
    \ TopologicalSort() const {\n        vector<Vertex> ret;\n        for(const auto\
    \ &vs : components_){\n            for(const auto &v : vs){\n                ret.emplace_back(v);\n\
    \            }\n        }\n        return ret;\n    }\n    \n    Graph<CostType>\
    \ ContractedGraph() const {\n        int nn = ComponentCount();\n        Graph<CostType>\
    \ ret(nn);\n        for(int u = 0; u < n; ++u){\n            int nu = BelongComponent(u);\n\
    \            for(const Edge<CostType> &e : G[u]){\n                int nv = BelongComponent(e.to);\n\
    \                if(nu == nv) continue;\n                ret.AddDirectedEdge(nu,\
    \ nv, e.cost);\n            }\n        }\n        return ret;\n    }\n\n    inline\
    \ int operator[](const Vertex &v){\n        return BelongComponent(v);\n    }\n\
    \n    inline const int operator[](const Vertex &v) const {\n        return BelongComponent(v);\n\
    \    }\n\n    private:\n    Graph<CostType> &G;\n    Graph<CostType> RG;\n   \
    \ int n;\n    vector<vector<Vertex>> components_;\n    vector<int> belong_;\n\n\
    \    void dfs1(Vertex v, vector<int> &label, int &nex, vector<bool> &state){\n\
    \        state[v] = true;\n        for(const Edge<CostType> &e : G[v]){\n    \
    \        if(state[e.to]) continue;\n            dfs1(e.to, label, nex, state);\n\
    \        }\n        label[v] = nex++;\n        return;\n    }\n\n    void dfs2(Vertex\
    \ v, vector<int> &label, int component, vector<bool> &state){\n        components_[component].push_back(v);\n\
    \        belong_[v] = component;\n        state[v] = false;\n        for(const\
    \ Edge<CostType> &e : RG[v]){\n            if(!state[e.to]) continue;\n      \
    \      dfs2(e.to, label, component, state);\n        }\n        return;\n    }\n\
    };\n"
  code: "#include \"Graph.hpp\"\n#include \"GraphMisc.hpp\"\n\ntemplate<typename CostType>\n\
    struct StronglyConnectedComponents{\n    public:\n    StronglyConnectedComponents(Graph<CostType>\
    \ &graph) :\n        G(graph), RG(ReverseGraph(graph)), n(G.VertexSize()), belong_(n,\
    \ -1){\n        vector<int> label(n, -1);\n        vector<bool> state(n, false);\n\
    \        int nex = 0;\n        vector<Vertex> vs(n);\n        iota(vs.begin(),\
    \ vs.end(), 0);\n        for(auto v : vs){\n            if(!state[v]) dfs1(v,\
    \ label, nex, state);\n        }\n        sort(vs.begin(), vs.end(), [&](Vertex\
    \ u, Vertex v){\n            return label[u] > label[v];\n        });\n      \
    \  for(auto v : vs){\n            if(state[v]){\n                int c = components_.size();\n\
    \                components_.push_back(vector<Vertex>{});\n                dfs2(v,\
    \ label, c, state);\n            }\n        }\n    }\n\n    inline vector<vector<Vertex>>\
    \ &Components(){\n        return components_;\n    }\n\n    inline int ComponentCount()\
    \ const {\n        return (int)components_.size();\n    }\n\n    inline int BelongComponent(const\
    \ Vertex &v) const {\n        return belong_[v];\n    }\n\n    vector<Vertex>\
    \ TopologicalSort() const {\n        vector<Vertex> ret;\n        for(const auto\
    \ &vs : components_){\n            for(const auto &v : vs){\n                ret.emplace_back(v);\n\
    \            }\n        }\n        return ret;\n    }\n    \n    Graph<CostType>\
    \ ContractedGraph() const {\n        int nn = ComponentCount();\n        Graph<CostType>\
    \ ret(nn);\n        for(int u = 0; u < n; ++u){\n            int nu = BelongComponent(u);\n\
    \            for(const Edge<CostType> &e : G[u]){\n                int nv = BelongComponent(e.to);\n\
    \                if(nu == nv) continue;\n                ret.AddDirectedEdge(nu,\
    \ nv, e.cost);\n            }\n        }\n        return ret;\n    }\n\n    inline\
    \ int operator[](const Vertex &v){\n        return BelongComponent(v);\n    }\n\
    \n    inline const int operator[](const Vertex &v) const {\n        return BelongComponent(v);\n\
    \    }\n\n    private:\n    Graph<CostType> &G;\n    Graph<CostType> RG;\n   \
    \ int n;\n    vector<vector<Vertex>> components_;\n    vector<int> belong_;\n\n\
    \    void dfs1(Vertex v, vector<int> &label, int &nex, vector<bool> &state){\n\
    \        state[v] = true;\n        for(const Edge<CostType> &e : G[v]){\n    \
    \        if(state[e.to]) continue;\n            dfs1(e.to, label, nex, state);\n\
    \        }\n        label[v] = nex++;\n        return;\n    }\n\n    void dfs2(Vertex\
    \ v, vector<int> &label, int component, vector<bool> &state){\n        components_[component].push_back(v);\n\
    \        belong_[v] = component;\n        state[v] = false;\n        for(const\
    \ Edge<CostType> &e : RG[v]){\n            if(!state[e.to]) continue;\n      \
    \      dfs2(e.to, label, component, state);\n        }\n        return;\n    }\n\
    };"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  - Library/Graph/GraphMisc.hpp
  isVerificationFile: false
  path: Library/Graph/StronglyConnectedComponents.hpp
  requiredBy: []
  timestamp: '2025-04-30 01:32:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-3-C.test.cpp
  - verify/LC-StronglyConnectedComponents.test.cpp
documentation_of: Library/Graph/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/Library/Graph/StronglyConnectedComponents.hpp
- /library/Library/Graph/StronglyConnectedComponents.hpp.html
title: Library/Graph/StronglyConnectedComponents.hpp
---
