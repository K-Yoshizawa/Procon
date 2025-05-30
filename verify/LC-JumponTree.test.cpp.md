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
    path: Library/Tree/HeavyLightDecomposition.hpp
    title: "Heavy Light Decomposition - \u91CD\u8EFD\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"verify/LC-JumponTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\
    \n\n#line 2 \"Library/Tree/Tree.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\n\
    \n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n#include\
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
    \  return ret;\n}\n\n// /**\n//  * @brief \u5404\u9802\u70B9\u3092\u884C\u304D\
    \u304B\u3051\u9806\u306B\u4E26\u3079\u305F\u3068\u304D\u306B\u4F55\u756A\u76EE\
    \u306B\u76F8\u5F53\u3059\u308B\u304B\u306E\u914D\u5217\u3092\u6C42\u3081\u308B\
    \u3002\n//  * @param tree \u6728\n//  * @return vector<int> \u5404\u9802\u70B9\
    \u304C\u884C\u304D\u304B\u3051\u9806\u3067\u4F55\u756A\u76EE\u306B\u306A\u308B\
    \u304B (0-index)\n//  */\n// template<typename CostType>\n// vector<int> CalculatePreOrder(RootedTree<CostType>\
    \ &tree){\n//     Vertex root = tree.get_root();\n//     int V = tree.get_vertex_size(),\
    \ time_stamp = 0;\n//     vector<int> ret(V, -1);\n//     auto rec = [&](auto\
    \ self, Vertex v) -> void {\n//         ret[v] = time_stamp++;\n//         for(Vertex\
    \ u : tree.get_child()){\n//             self(self, u);\n//         }\n//    \
    \ };\n//     rec(rec, root);\n//     return ret;\n// }\n#line 2 \"Library/Tree/HeavyLightDecomposition.hpp\"\
    \n\nstruct PathSegment{\n    PathSegment() = default;\n    Vertex head_vertex;\n\
    \    Vertex tail_vertex;\n    int head_index;\n    int tail_index;\n    bool highest;\n\
    \    bool reverse;\n    friend ostream &operator<<(ostream &os, const PathSegment\
    \ &p){\n        return os << \"# Path (\" << p.head_vertex << \" -> \" << p.tail_vertex\
    \ << \", \" << p.head_index << \" -> \" << p.tail_index << \", \" << boolalpha\
    \ << p.highest << \", \" << p.reverse << \")\";\n    }\n};\n\ntemplate<typename\
    \ CostType>\nclass HeavyLightDecomposition{\n    public:\n    HeavyLightDecomposition(Graph<CostType>\
    \ &tree, Vertex r = 0) :\n        T(tree), parent(CalculateTreeParent(tree, r)),\
    \ child(RootedTreeAdjacentList(tree, r)), n((int)tree.VertexSize()), euler_tour_(n),\
    \ rev_order_(n), depth_(CalculateTreeDepth(tree, r)), belong_hp_id_(n){\n    \
    \    vector<int> ss = CalculateSubtreeSize(T, r);\n        for(int i = 0; i <\
    \ n; ++i){\n            if(child[i].empty()) continue;\n            nth_element(child[i].begin(),\
    \ child[i].begin() + 1, child[i].end(), [&](Vertex i, Vertex j){\n           \
    \     return ss[i] > ss[j];\n            });\n        }\n        hp_head_.push_back(r);\n\
    \        hp_depth_.push_back(0);\n        belong_hp_id_[r] = 0;\n        timer_\
    \ = 0;\n        dfs(r, 0, 0);\n    }\n\n    Vertex LowestCommonAncestor(Vertex\
    \ u, Vertex v) const {\n        if(PathDepth(u) < PathDepth(v)) swap(u, v);\n\
    \        while(PathDepth(u) != PathDepth(v)){\n            u = parent[Head(u)];\n\
    \        }\n        while(Belong(u) != Belong(v)){\n            u = parent[Head(u)];\n\
    \            v = parent[Head(v)];\n        }\n        return depth_[u] < depth_[v]\
    \ ? u : v;\n    }\n\n    Vertex LevelAncestor(Vertex v, int k){\n        assert(k\
    \ <= depth_[v]);\n        Vertex ret = v;\n        while(1){\n            int\
    \ h = Head(ret);\n            int x = depth_[ret] - depth_[h];\n            if(k\
    \ <= x){\n                ret = RevOrder(PreOrder(ret) - k);\n               \
    \ break;\n            }\n            ret = parent[h];\n            k -= x + 1;\n\
    \        }\n        return ret;\n    }\n\n    int Jump(Vertex u, Vertex v, int\
    \ k){\n        Vertex w = LowestCommonAncestor(u, v);\n        int p = depth_[u]\
    \ - depth_[w], q = depth_[v] - depth_[w];\n        if(p + q < k || k < 0) return\
    \ -1;\n        if(k <= p) return LevelAncestor(u, k);\n        else return LevelAncestor(v,\
    \ p + q - k);\n    }\n\n    vector<PathSegment> PathQuery(Vertex u, Vertex v){\n\
    \        vector<PathSegment> ret;\n        Vertex lca = LowestCommonAncestor(u,\
    \ v);\n        while(Belong(u) != Belong(lca)){\n            PathSegment path;\n\
    \            Vertex h = Head(u);\n            path.head_vertex = h, path.tail_vertex\
    \ = u;\n            path.head_index = PreOrder(h), path.tail_index = PreOrder(u)\
    \ + 1;\n            path.highest = false, path.reverse = true;\n            ret.push_back(path);\n\
    \            u = parent[h];\n        }\n        if(u != lca){\n            PathSegment\
    \ path;\n            path.head_vertex = lca, path.tail_vertex = u;\n         \
    \   path.head_index = PreOrder(lca), path.tail_index = PreOrder(u) + 1;\n    \
    \        path.highest = true, path.reverse = true;\n            ret.push_back(path);\n\
    \        }\n        int size = ret.size();\n        while(Belong(v) != Belong(lca)){\n\
    \            PathSegment path;\n            Vertex h = Head(v);\n            path.head_vertex\
    \ = h, path.tail_vertex = v;\n            path.head_index = PreOrder(h), path.tail_index\
    \ = PreOrder(v) + 1;\n            path.highest = false, path.reverse = false;\n\
    \            ret.push_back(path);\n            v = parent[h];\n        }\n   \
    \     if(v != lca){\n            PathSegment path;\n            path.head_vertex\
    \ = lca, path.tail_vertex = v;\n            path.head_index = PreOrder(lca), path.tail_index\
    \ = PreOrder(v) + 1;\n            path.highest = true, path.reverse = false;\n\
    \            ret.push_back(path);\n        }\n        if(u == lca && v == lca){\n\
    \            PathSegment path;\n            path.head_vertex = path.tail_vertex\
    \ = lca;\n            path.head_index = PreOrder(lca), path.tail_index = PreOrder(lca)\
    \ + 1;\n            path.highest = true, path.reverse = false;\n            ret.push_back(path);\n\
    \        }\n        reverse(ret.begin() + size, ret.end());\n        return ret;\n\
    \    }\n\n    pair<int, int> SubtreeQuery(Vertex v) const {\n        return euler_tour_[v];\n\
    \    }\n\n    template<typename T>\n    void SortVertex(vector<T> &A){\n     \
    \   assert(A.size() == n);\n        vector<T> sub(n);\n        for(int i = 0;\
    \ i < n; ++i){\n            sub[PreOrder(i)] = A[i];\n        }\n        swap(A,\
    \ sub);\n    }\n\n    int operator[](Vertex v){\n        return PreOrder(v);\n\
    \    }\n\n    const int operator[](Vertex v) const {\n        return PreOrder(v);\n\
    \    }\n\n    private:\n    int dfs(Vertex v, int h, int d){\n        euler_tour_[v].first\
    \ = timer_;\n        rev_order_[timer_] = v;\n        ++timer_;\n        int ret\
    \ = timer_;\n        if(!child[v].empty()){\n            int c = child[v].size();\n\
    \            belong_hp_id_[child[v].front()] = h;\n            ret = max(ret,\
    \ dfs(child[v].front(), h, d));\n            for(int i = 1; i < c; ++i){\n   \
    \             int nh = (int)hp_head_.size();\n                hp_head_.push_back(child[v][i]);\n\
    \                hp_depth_.push_back(d + 1);\n                belong_hp_id_[child[v][i]]\
    \ = nh;\n                ret = max(ret, dfs(child[v][i], nh, d + 1));\n      \
    \      }\n        }\n        euler_tour_[v].second = ret;\n        return ret;\n\
    \    }\n\n    Vertex Head(Vertex v) const {\n        return hp_head_[belong_hp_id_[v]];\n\
    \    }\n\n    int PathDepth(Vertex v) const {\n        return hp_depth_[belong_hp_id_[v]];\n\
    \    }\n\n    int Belong(Vertex v) const {\n        return belong_hp_id_[v];\n\
    \    }\n\n    Vertex RevOrder(int idx) const {\n        return rev_order_[idx];\n\
    \    }\n\n    int PreOrder(Vertex v) const {\n        return euler_tour_[v].first;\n\
    \    }\n\n    int PostOrder(Vertex v) const {\n        return euler_tour_[v].second;\n\
    \    }\n\n    Graph<CostType> &T;\n    vector<Vertex> parent;\n    vector<vector<Vertex>>\
    \ child;\n    int n, timer_;\n\n    vector<pair<int, int>> euler_tour_;\n    vector<Vertex>\
    \ rev_order_;\n    vector<int> depth_;\n\n    vector<Vertex> hp_head_; // \u5404\
    \ heavy path \u306E\u6700\u3082\u6839\u306B\u8FD1\u3044\u9802\u70B9\n    vector<int>\
    \ hp_depth_; // \u5404 heavy path \u306E\u6DF1\u3055\n    vector<int> belong_hp_id_;\
    \ // \u5404\u9802\u70B9\u304C\u5C5E\u3059\u308B heavy path \u306E\u756A\u53F7\n\
    };\n#line 4 \"verify/LC-JumponTree.test.cpp\"\n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n\
    \    int N, Q; cin >> N >> Q;\n    Graph T = InputTree(N, 0);\n\n    HeavyLightDecomposition\
    \ hld(T);\n    while(Q--){\n        int s, t, i; cin >> s >> t >> i;\n       \
    \ cout << hld.Jump(s, t, i) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include\
    \ \"../Library/Tree/HeavyLightDecomposition.hpp\"\n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n\
    \    int N, Q; cin >> N >> Q;\n    Graph T = InputTree(N, 0);\n\n    HeavyLightDecomposition\
    \ hld(T);\n    while(Q--){\n        int s, t, i; cin >> s >> t >> i;\n       \
    \ cout << hld.Jump(s, t, i) << '\\n';\n    }\n}"
  dependsOn:
  - Library/Tree/HeavyLightDecomposition.hpp
  - Library/Tree/Tree.hpp
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: true
  path: verify/LC-JumponTree.test.cpp
  requiredBy: []
  timestamp: '2025-05-30 20:57:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-JumponTree.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-JumponTree.test.cpp
- /verify/verify/LC-JumponTree.test.cpp.html
title: verify/LC-JumponTree.test.cpp
---
