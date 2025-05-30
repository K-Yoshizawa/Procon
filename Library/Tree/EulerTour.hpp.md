---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/Tree/AuxiliaryTree.hpp
    title: "Auxiliary Tree - \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\
      \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\
      \u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\
      \u6728"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
    title: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
    links: []
  bundledCode: "#line 2 \"Library/Tree/EulerTour.hpp\"\n\n/**\n * @file EulerTour.hpp\n\
    \ * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\n * @version\
    \ 4.0\n * @date 2024-10-31\n */\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file\
    \ Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cstdint>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const ll INF = (1LL\
    \ << 62) - (3LL << 30) - 1;\n#line 2 \"Library/Tree/Tree.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n\n#line 4 \"Library/Graph/Graph.hpp\"\n\nusing Vertex = int;\n\ntemplate<typename\
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
    \ };\n//     rec(rec, root);\n//     return ret;\n// }\n#line 12 \"Library/Tree/EulerTour.hpp\"\
    \n\ntemplate<typename CostType>\nclass EulerTour{\n    public:\n    using F =\
    \ function<CostType(CostType)>;\n\n    EulerTour(){}\n\n    /**\n     * @brief\
    \ \u6728 `T` \u306B\u304A\u3051\u308B\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
    \u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @param one_index `1-index` \u3068\
    \u3057\u3066\u6271\u3044\u305F\u3044\u304B `(default = false)`\n     */\n    EulerTour(RootedTree<CostType>\
    \ &T, bool one_index = false) :\n            T(T),\n            vertex_size_(T.get_vertex_size()),\n\
    \            in_time_(T.get_vertex_size()),\n            out_time_(T.get_vertex_size()),\n\
    \            one_index_(one_index){\n        dfs(T.get_root());\n    }\n\n   \
    \ /**\n     * @brief \u9802\u70B9 `v` \u306B\u5165\u3063\u305F\u6642\u523B\u3092\
    \u8FD4\u3059\u3002\n     * @note \u6642\u523B\u306F `0-index` \u3067\u8FD4\u308B\
    \u3002\n     * @return int \u9802\u70B9 `v` \u306B\u5165\u3063\u305F\u6642\u523B\
    \n     */\n    int get_in(const Vertex v) const {\n        return in_time_.at(v\
    \ - one_index_);\n    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u304B\u3089\
    \u51FA\u305F\u6642\u523B\u3092\u8FD4\u3059\u3002\n     * @note \u6642\u523B\u306F\
    \ `0-index` \u3067\u8FD4\u308B\u3002\n     * @return int \u9802\u70B9 `v` \u304B\
    \u3089\u51FA\u305F\u6642\u523B\n     */\n    int get_out(const Vertex v) const\
    \ {\n        return out_time_.at(v - one_index_);\n    }\n\n    /**\n     * @brief\
    \ \u9802\u70B9 `v` \u306B\u5165\u3063\u305F\u6642\u523B\u3068\u51FA\u305F\u6642\
    \u523B\u306E\u4E21\u65B9\u3092\u8FD4\u3059\u3002\n     * @note \u6642\u523B\u306F\
    \ `0-index` \u3067\u8FD4\u308B\u3002\n     * @return pair<int, int> \u9802\u70B9\
    \ `v` \u306B\u5165\u3063\u305F\u6642\u523B\u3068\u51FA\u305F\u6642\u523B\n   \
    \  */\n    pair<int, int> get_pair(const Vertex v) const {\n        return make_pair(in_time_.at(v\
    \ - one_index_), out_time_.at(v - one_index_));\n    }\n\n    /**\n     * @brief\
    \ \u914D\u5217 `value` \u3092\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u306B\u57FA\
    \u3065\u3044\u3066\u5909\u63DB\u3057\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\
    \n     * @note \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\u306E\u521D\u671F\
    \u914D\u5217\u3068\u3057\u3066\u6E21\u3059\u5834\u5408\u306B\u306A\u3069\u306B\
    \u7528\u3044\u308B\u3002\n     * @tparam Type \u6E21\u3059\u30C7\u30FC\u30BF\u306E\
    \u578B\n     * @param value \u5909\u63DB\u3059\u308B\u914D\u5217\n     * @param\
    \ in_converter \u9802\u70B9 `v` \u306B\u5165\u308B\u6642\u523B\u306B\u5BFE\u3059\
    \u308B\u30C7\u30FC\u30BF\u3092\u5909\u63DB\u3059\u308B\u95A2\u6570\n     * @param\
    \ out_converter \u9802\u70B9 `v` \u304B\u3089\u51FA\u308B\u6642\u523B\u306B\u5BFE\
    \u3059\u308B\u30C7\u30FC\u30BF\u3092\u5909\u63DB\u3059\u308B\u95A2\u6570\n   \
    \  * @return vector<Type> \u5909\u63DB\u3057\u305F\u9577\u3055 `2 * |V|` \u306E\
    \u914D\u5217\n     */\n    template<typename Type>\n    vector<Type> ConvertVector(const\
    \ vector<Type> &value, const F in_converter, const F out_converter){\n       \
    \ vector<Type> ret(2 * vertex_size_);\n        for(int i = 0; i < vertex_size_;\
    \ ++i){\n            int in_idx = in_time_.at(i), out_idx = out_time_.at(i);\n\
    \            ret[in_idx] = in_converter(value.at(i));\n            ret[out_idx]\
    \ = out_converter(value.at(i));\n        }\n        return ret;\n    }\n\n   \
    \ private:\n    int time_{0}, one_index_, vertex_size_;\n\n    RootedTree<CostType>\
    \ &T;\n    vector<int> in_time_, out_time_;\n\n    void dfs(Vertex v){\n     \
    \   in_time_[v] = time_++;\n        for(Vertex c : T.get_child(v)){\n        \
    \    dfs(c);\n        }\n        out_time_[v] = time_++;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file EulerTour.hpp\n * @brief Euler Tour - \u30AA\
    \u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\n * @version 4.0\n * @date 2024-10-31\n */\n\
    \n#include \"../Common.hpp\"\n#include \"Tree.hpp\"\n\ntemplate<typename CostType>\n\
    class EulerTour{\n    public:\n    using F = function<CostType(CostType)>;\n\n\
    \    EulerTour(){}\n\n    /**\n     * @brief \u6728 `T` \u306B\u304A\u3051\u308B\
    \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u3092\u69CB\u7BC9\u3059\u308B\u3002\
    \n     * @param one_index `1-index` \u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B `(default = false)`\n     */\n    EulerTour(RootedTree<CostType> &T, bool\
    \ one_index = false) :\n            T(T),\n            vertex_size_(T.get_vertex_size()),\n\
    \            in_time_(T.get_vertex_size()),\n            out_time_(T.get_vertex_size()),\n\
    \            one_index_(one_index){\n        dfs(T.get_root());\n    }\n\n   \
    \ /**\n     * @brief \u9802\u70B9 `v` \u306B\u5165\u3063\u305F\u6642\u523B\u3092\
    \u8FD4\u3059\u3002\n     * @note \u6642\u523B\u306F `0-index` \u3067\u8FD4\u308B\
    \u3002\n     * @return int \u9802\u70B9 `v` \u306B\u5165\u3063\u305F\u6642\u523B\
    \n     */\n    int get_in(const Vertex v) const {\n        return in_time_.at(v\
    \ - one_index_);\n    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u304B\u3089\
    \u51FA\u305F\u6642\u523B\u3092\u8FD4\u3059\u3002\n     * @note \u6642\u523B\u306F\
    \ `0-index` \u3067\u8FD4\u308B\u3002\n     * @return int \u9802\u70B9 `v` \u304B\
    \u3089\u51FA\u305F\u6642\u523B\n     */\n    int get_out(const Vertex v) const\
    \ {\n        return out_time_.at(v - one_index_);\n    }\n\n    /**\n     * @brief\
    \ \u9802\u70B9 `v` \u306B\u5165\u3063\u305F\u6642\u523B\u3068\u51FA\u305F\u6642\
    \u523B\u306E\u4E21\u65B9\u3092\u8FD4\u3059\u3002\n     * @note \u6642\u523B\u306F\
    \ `0-index` \u3067\u8FD4\u308B\u3002\n     * @return pair<int, int> \u9802\u70B9\
    \ `v` \u306B\u5165\u3063\u305F\u6642\u523B\u3068\u51FA\u305F\u6642\u523B\n   \
    \  */\n    pair<int, int> get_pair(const Vertex v) const {\n        return make_pair(in_time_.at(v\
    \ - one_index_), out_time_.at(v - one_index_));\n    }\n\n    /**\n     * @brief\
    \ \u914D\u5217 `value` \u3092\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u306B\u57FA\
    \u3065\u3044\u3066\u5909\u63DB\u3057\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\
    \n     * @note \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\u306E\u521D\u671F\
    \u914D\u5217\u3068\u3057\u3066\u6E21\u3059\u5834\u5408\u306B\u306A\u3069\u306B\
    \u7528\u3044\u308B\u3002\n     * @tparam Type \u6E21\u3059\u30C7\u30FC\u30BF\u306E\
    \u578B\n     * @param value \u5909\u63DB\u3059\u308B\u914D\u5217\n     * @param\
    \ in_converter \u9802\u70B9 `v` \u306B\u5165\u308B\u6642\u523B\u306B\u5BFE\u3059\
    \u308B\u30C7\u30FC\u30BF\u3092\u5909\u63DB\u3059\u308B\u95A2\u6570\n     * @param\
    \ out_converter \u9802\u70B9 `v` \u304B\u3089\u51FA\u308B\u6642\u523B\u306B\u5BFE\
    \u3059\u308B\u30C7\u30FC\u30BF\u3092\u5909\u63DB\u3059\u308B\u95A2\u6570\n   \
    \  * @return vector<Type> \u5909\u63DB\u3057\u305F\u9577\u3055 `2 * |V|` \u306E\
    \u914D\u5217\n     */\n    template<typename Type>\n    vector<Type> ConvertVector(const\
    \ vector<Type> &value, const F in_converter, const F out_converter){\n       \
    \ vector<Type> ret(2 * vertex_size_);\n        for(int i = 0; i < vertex_size_;\
    \ ++i){\n            int in_idx = in_time_.at(i), out_idx = out_time_.at(i);\n\
    \            ret[in_idx] = in_converter(value.at(i));\n            ret[out_idx]\
    \ = out_converter(value.at(i));\n        }\n        return ret;\n    }\n\n   \
    \ private:\n    int time_{0}, one_index_, vertex_size_;\n\n    RootedTree<CostType>\
    \ &T;\n    vector<int> in_time_, out_time_;\n\n    void dfs(Vertex v){\n     \
    \   in_time_[v] = time_++;\n        for(Vertex c : T.get_child(v)){\n        \
    \    dfs(c);\n        }\n        out_time_[v] = time_++;\n    }\n};"
  dependsOn:
  - Library/Common.hpp
  - Library/Tree/Tree.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/Tree/EulerTour.hpp
  requiredBy:
  - Library/Tree/AuxiliaryTree.hpp
  timestamp: '2025-05-02 02:04:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
documentation_of: Library/Tree/EulerTour.hpp
layout: document
redirect_from:
- /library/Library/Tree/EulerTour.hpp
- /library/Library/Tree/EulerTour.hpp.html
title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
---
