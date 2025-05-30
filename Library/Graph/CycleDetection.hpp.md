---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-4-A.test.cpp
    title: verify/AOJ-GRL-4-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-CycleDetection.test.cpp
    title: verify/LC-CycleDetection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-CycleDetectionUndirected.test.cpp
    title: verify/LC-CycleDetectionUndirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/CycleDetection.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\
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
    \ 4 \"Library/Graph/CycleDetection.hpp\"\n\ntemplate<typename CostType>\nvector<Edge<CostType>>\
    \ CycleDetection(Graph<CostType> &G){\n    int N = G.VertexSize();\n    vector<Edge<CostType>>\
    \ history;\n    vector<int> state(N, 0);\n    vector<Edge<CostType>> ret;\n  \
    \  bool detected = false;\n    auto dfs = [&](auto &self, int v, int pre) -> void\
    \ {\n        state[v] = 1;\n        for(const Edge<CostType> &e : G[v]){\n   \
    \         if(e.idx == pre) continue;\n            if(state[e.to] == 2) continue;\n\
    \            else if(state[e.to] == 1){\n                ret.push_back(e);\n \
    \               for(int i = history.size() - 1; i >= 0 && history[i].to != e.to;\
    \ --i){\n                    ret.push_back(history[i]);\n                }\n \
    \               detected = true;\n            }\n            else{\n         \
    \       history.push_back(e);\n                self(self, e.to, e.idx);\n    \
    \            history.pop_back();\n            }\n            if(detected) return;\n\
    \        }\n        state[v] = 2;\n    };\n    for(int v = 0; v < N && !detected;\
    \ ++v){\n        if(state[v] == 0) dfs(dfs, v, -1);\n    }\n    reverse(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n"
  code: "#pragma once\n\n#include \"Graph.hpp\"\n\ntemplate<typename CostType>\nvector<Edge<CostType>>\
    \ CycleDetection(Graph<CostType> &G){\n    int N = G.VertexSize();\n    vector<Edge<CostType>>\
    \ history;\n    vector<int> state(N, 0);\n    vector<Edge<CostType>> ret;\n  \
    \  bool detected = false;\n    auto dfs = [&](auto &self, int v, int pre) -> void\
    \ {\n        state[v] = 1;\n        for(const Edge<CostType> &e : G[v]){\n   \
    \         if(e.idx == pre) continue;\n            if(state[e.to] == 2) continue;\n\
    \            else if(state[e.to] == 1){\n                ret.push_back(e);\n \
    \               for(int i = history.size() - 1; i >= 0 && history[i].to != e.to;\
    \ --i){\n                    ret.push_back(history[i]);\n                }\n \
    \               detected = true;\n            }\n            else{\n         \
    \       history.push_back(e);\n                self(self, e.to, e.idx);\n    \
    \            history.pop_back();\n            }\n            if(detected) return;\n\
    \        }\n        state[v] = 2;\n    };\n    for(int v = 0; v < N && !detected;\
    \ ++v){\n        if(state[v] == 0) dfs(dfs, v, -1);\n    }\n    reverse(ret.begin(),\
    \ ret.end());\n    return ret;\n}"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Graph/CycleDetection.hpp
  requiredBy: []
  timestamp: '2025-04-30 01:32:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-CycleDetectionUndirected.test.cpp
  - verify/AOJ-GRL-4-A.test.cpp
  - verify/LC-CycleDetection.test.cpp
documentation_of: Library/Graph/CycleDetection.hpp
layout: document
redirect_from:
- /library/Library/Graph/CycleDetection.hpp
- /library/Library/Graph/CycleDetection.hpp.html
title: Library/Graph/CycleDetection.hpp
---
