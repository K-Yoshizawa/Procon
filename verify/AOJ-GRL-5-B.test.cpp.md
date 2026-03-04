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
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/TreeDiameter.hpp
    title: "Tree Diameter - \u6728\u306E\u76F4\u5F84"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B
  bundledCode: "#line 1 \"verify/AOJ-GRL-5-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B\"\
    \n\n#line 2 \"Library/Tree/Tree.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\n\
    \n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 4 \"Library/Graph/Graph.hpp\"\n\nusing Vertex = int;\n\ntemplate<typename\
    \ WeightType = int32_t>\nstruct Edge{\n    public:\n    Edge() = default;\n\n\
    \    Edge(Vertex from_, Vertex to_, WeightType weight_ = 1, int idx_ = -1) :\n\
    \        from(from_), to(to_), cost(weight_), idx(idx_){}\n    \n    bool operator<(const\
    \ Edge<WeightType> &e) const {return cost < e.cost;}\n\n    operator int() const\
    \ {return to;}\n\n    Vertex from, to;\n    WeightType cost;\n    int idx;\n};\n\
    \ntemplate<typename WeightType = int32_t>\nclass Graph{\n    public:\n    Graph()\
    \ = default;\n\n    Graph(int V) : edge_size_(0), adjacent_list_(V){}\n    \n\
    \    inline void AddUndirectedEdge(Vertex u, Vertex v, WeightType w = 1){\n  \
    \      int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<WeightType>(u,\
    \ v, w, idx));\n        adjacent_list_[v].push_back(Edge<WeightType>(v, u, w,\
    \ idx));\n    }\n    \n    inline void AddDirectedEdge(Vertex u, Vertex v, WeightType\
    \ w = 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<WeightType>(u,\
    \ v, w, idx));\n    }\n\n    inline size_t VertexSize() const {\n        return\
    \ adjacent_list_.size();\n    }\n\n    inline size_t EdgeSize() const {\n    \
    \    return edge_size_;\n    }\n\n    inline vector<Edge<WeightType>> &operator[](const\
    \ Vertex v){\n        return adjacent_list_[v];\n    }\n\n    inline const vector<Edge<WeightType>>\
    \ &operator[](const Vertex v) const {\n        return adjacent_list_[v];\n   \
    \ }\n    \n    private:\n    size_t edge_size_;\n    vector<vector<Edge<WeightType>>>\
    \ adjacent_list_;\n};\n\ntemplate<typename WeightType = int32_t>\nGraph<WeightType>\
    \ InputGraph(int N, int M, int padding = -1, bool weighted = false, bool directed\
    \ = false){\n    Graph<WeightType> G(N);\n    for(int i = 0; i < M; ++i){\n  \
    \      Vertex u, v; WeightType w = 1;\n        cin >> u >> v, u += padding, v\
    \ += padding;\n        if(weighted) cin >> w;\n        if(directed) G.AddDirectedEdge(u,\
    \ v, w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n\
    #line 4 \"Library/Tree/Tree.hpp\"\n\ntemplate<typename WeightType = int32_t>\n\
    Graph<WeightType> InputTree(int V, int padding = -1, bool weighted = false){\n\
    \    Graph<WeightType> G(V);\n    for(int i = 0; i < V - 1; ++i){\n        Vertex\
    \ u, v; WeightType w = 1;\n        cin >> u >> v, u += padding, v += padding;\n\
    \        if(weighted) cin >> w;\n        G.AddUndirectedEdge(u, v, w);\n    }\n\
    \    return G;\n}\n\ntemplate<typename WeightType = int32_t>\nGraph<WeightType>\
    \ InputRootedTreeChild(int V, int padding = -1){\n    Graph<WeightType> G(V);\n\
    \    for(Vertex u = 0; u < V; ++u){\n        int k; cin >> k;\n        for(int\
    \ i = 0; i < k; ++i){\n            Vertex v; cin >> v, v += padding;\n       \
    \     G.AddUndirectedEdge(u, v);\n        }\n    }\n    return G;\n}\n\ntemplate<typename\
    \ WeightType = int32_t>\nGraph<WeightType> InputRootedTreeParent(int V, int padding\
    \ = -1){\n    Graph<WeightType> G(V);\n    for(Vertex u = 1; u < V; ++u){\n  \
    \      Vertex v; cin >> v, v += padding;\n        G.AddUndirectedEdge(u, v);\n\
    \    }\n    return G;\n}\n\ntemplate<typename WeightType = int32_t>\nvector<vector<Vertex>>\
    \ RootedTreeAdjacentList(const Graph<WeightType> &T, const Vertex r = 0){\n  \
    \  int V = T.VertexSize();\n    vector<vector<Vertex>> ret(V);\n    auto rec =\
    \ [&](auto &self, Vertex u, Vertex p) -> void {\n        for(Vertex v : T[u]){\n\
    \            if(v == p) continue;\n            ret[u].push_back(v);\n        \
    \    self(self, v, u);\n        }\n    };\n    rec(rec, r, -1);\n    return ret;\n\
    }\n\ntemplate<typename WeightType>\nvector<Vertex> CalculateTreeParent(Graph<WeightType>\
    \ &T, Vertex r = 0){\n    int V = T.VertexSize();\n    vector<Vertex> ret(V, -1);\n\
    \    auto rec = [&](auto &self, Vertex u) -> void {\n        for(Vertex v : T[u]){\n\
    \            if(v == ret[u]) continue;\n            ret[v] = u;\n            self(self,\
    \ v);\n        }\n    };\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ WeightType>\nvector<WeightType> CalculateTreeCost(Graph<WeightType> &T, Vertex\
    \ r = 0){\n    int V = T.VertexSize();\n    vector<WeightType> ret(V);\n    auto\
    \ rec = [&](auto &self, Vertex u, Vertex p) -> void {\n        for(const Edge<WeightType>\
    \ &e : T[u]){\n            Vertex v = e.to;\n            if(v == p) continue;\n\
    \            ret[v] = e.cost;\n            self(self, v, u);\n        }\n    };\n\
    \    rec(rec, r, -1);\n    return ret;\n}\n\ntemplate<typename WeightType>\nvector<int>\
    \ CalculateTreeDepth(Graph<WeightType> &T, Vertex r = 0){\n    int V = T.VertexSize();\n\
    \    vector<int> ret(V, 0);\n    auto rec = [&](auto &self, Vertex u, Vertex p,\
    \ int d) -> void {\n        ret[u] = d;\n        for(Vertex v : T[u]){\n     \
    \       if(v == p) continue;\n            self(self, v, u, d + 1);\n        }\n\
    \    };\n    rec(rec, r, -1, 0);\n    return ret;\n}\n\ntemplate<typename WeightType>\n\
    vector<WeightType> CalculateTreeDistance(Graph<WeightType> &T, Vertex r = 0){\n\
    \    int V = T.VertexSize();\n    vector<WeightType> ret(V, WeightType(INF));\n\
    \    auto rec = [&](auto &self, Vertex u) -> void {\n        for(const Edge<WeightType>\
    \ &e : T[u]){\n            if(ret[e.to] > ret[u] + e.cost){\n                ret[e.to]\
    \ = ret[u] + e.cost;\n                self(self, e.to);\n            }\n     \
    \   }\n    };\n    ret[r] = 0;\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ WeightType>\nvector<int> CalculateSubtreeSize(Graph<WeightType> &tree, Vertex\
    \ r = 0){\n    int V = tree.VertexSize();\n    vector<int> ret(V, 1);\n    auto\
    \ rec = [&](auto self, Vertex u, Vertex p) -> int {\n        for(const int v :\
    \ tree[u]){\n            if(v == p) continue;\n            ret[u] += self(self,\
    \ v, u);\n        }\n        return ret[u];\n    };\n    rec(rec, r, -1);\n  \
    \  return ret;\n}\n#line 2 \"Library/Tree/TreeDiameter.hpp\"\n\ntemplate<typename\
    \ WeightType>\nclass TreeDiameter{\n    public:\n    TreeDiameter(Graph<WeightType>\
    \ &tree) : T(tree){\n        int V = T.VertexSize(), s = 0;\n        dist_s_ =\
    \ CalculateTreeDistance(T, s);\n        s = distance(dist_s_.begin(), max_element(dist_s_.begin(),\
    \ dist_s_.end()));\n        dist_s_ = CalculateTreeDistance(T, s);\n        vector<int>\
    \ par = CalculateTreeParent(T, s);\n        int t = distance(dist_s_.begin(),\
    \ max_element(dist_s_.begin(), dist_s_.end()));\n        diameter_ = dist_s_[t];\n\
    \        dist_t_ = CalculateTreeDistance(T, t);\n        int u = t;\n        while(u\
    \ != s){\n            path_.emplace_back(u);\n            u = par[u];\n      \
    \  }\n        path_.emplace_back(s);\n    }\n    \n    WeightType Diameter() const\
    \ {\n        return diameter_;\n    }\n    \n    WeightType Height(Vertex v) const\
    \ {\n        return max(dist_s_[v], dist_t_[v]);\n    }\n\n    pair<Vertex, Vertex>\
    \ EndPoints() const {\n        return pair<Vertex, Vertex>(path_.front(), path_.back());\n\
    \    }\n\n    vector<Vertex> &Path(){\n        return path_;\n    }\n\n    private:\n\
    \    Graph<WeightType> &T;\n    vector<WeightType> dist_s_, dist_t_;\n    vector<Vertex>\
    \ path_;\n    WeightType diameter_;\n};\n#line 4 \"verify/AOJ-GRL-5-B.test.cpp\"\
    \n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n    int n; cin >> n;\n\
    \    Graph<int> T = InputTree(n, 0, true);\n\n    TreeDiameter td(T);\n    for(int\
    \ i = 0; i < n; ++i){\n        cout << td.Height(i) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B\"\
    \n\n#include \"../Library/Tree/TreeDiameter.hpp\"\n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n\
    \    int n; cin >> n;\n    Graph<int> T = InputTree(n, 0, true);\n\n    TreeDiameter\
    \ td(T);\n    for(int i = 0; i < n; ++i){\n        cout << td.Height(i) << endl;\n\
    \    }\n}"
  dependsOn:
  - Library/Tree/TreeDiameter.hpp
  - Library/Tree/Tree.hpp
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-5-B.test.cpp
  requiredBy: []
  timestamp: '2026-02-13 15:23:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-GRL-5-B.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-5-B.test.cpp
- /verify/verify/AOJ-GRL-5-B.test.cpp.html
title: verify/AOJ-GRL-5-B.test.cpp
---
