---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/DataStructure/SegmentTree.hpp
    title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: Library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':x:'
    path: Library/Tree/EulerTour.hpp
    title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  - icon: ':question:'
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line\
    \ 2 \"Library/Template.hpp\"\n\n/**\n * @file Template.hpp\n * @author log K (lX57)\n\
    \ * @brief Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 1.10\n\
    \ * @date 2025-03-16\n */\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n\
    \ */\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 12 \"Library/Template.hpp\"\n\ninline bool YnPrint(bool flag){cout\
    \ << (flag ? \"Yes\" : \"No\") << '\\n'; return flag;}\ninline bool YNPrint(bool\
    \ flag){cout << (flag ? \"YES\" : \"NO\") << '\\n'; return flag;}\ntemplate<typename\
    \ Container>\ninline void Sort(Container &container){sort(container.begin(), container.end());}\n\
    template<typename Container>\ninline void ReverseSort(Container &container){sort(container.rbegin(),\
    \ container.rend());}\ntemplate<typename Container>\ninline void Reverse(Container\
    \ &container){reverse(container.begin(), container.end());}\ntemplate<typename\
    \ Value>\ninline int PopCount(const Value &value){return __builtin_popcount(value);}\n\
    template<typename Value>\ninline Value Floor(Value numerator, Value denominator){if(denominator\
    \ < 0) numerator *= -1, denominator *= -1; return numerator < 0 ? (numerator +\
    \ 1) / denominator - 1 : numerator / denominator;}\ntemplate<typename Value>\n\
    inline Value Ceil(Value numerator, Value denominator){if(denominator < 0) numerator\
    \ *= -1, denominator *= -1; return numerator > 0 ? (numerator - 1) / denominator\
    \ + 1 : numerator / denominator;}\ntemplate<typename Value>\ninline int LowerBoundIndex(const\
    \ vector<Value> &container, const Value &value){return distance(container.begin(),\
    \ lower_bound(container.begin(), container.end(), value));}\ntemplate<typename\
    \ Value>\ninline int UpperBoundIndex(const vector<Value> &container, const Value\
    \ &value){return distance(container.begin(), upper_bound(container.begin(), container.end(),\
    \ value));}\ntemplate<typename Value>\ninline bool Between(const Value &lower,\
    \ const Value &x, const Value &higher){return lower <= x && x <= higher;}\ntemplate<typename\
    \ Value>\ninline bool InGrid(const Value &y, const Value &x, const Value &ymax,\
    \ const Value &xmax){return Between(0, y, ymax - 1) && Between(0, x, xmax - 1);}\n\
    template<typename Value>\ninline Value Median(const Value &a, const Value &b,\
    \ const Value &c){return Between(b, a, c) || Between(c, a, b) ? a : (Between(a,\
    \ b, c) || Between(c, b, a) ? b : c);}\ntemplate<typename Value>\ninline Value\
    \ Except(Value &src, Value &cond, Value &excp){return (src == cond ? excp : src);}\n\
    \ntemplate<class Value>\nbool chmin(Value &src, const Value &cmp){if(src > cmp){src\
    \ = cmp; return true;} return false;}\ntemplate<class Value>\nbool chmax(Value\
    \ &src, const Value &cmp){if(src < cmp){src = cmp; return true;} return false;}\n\
    template<typename Value>\ninline Value min(vector<Value> &v){return *min_element((v).begin(),\
    \ (v).end());}\ntemplate<typename Value>\ninline Value max(vector<Value> &v){return\
    \ *max_element((v).begin(), (v).end());}\n\nconst int dx4[4] = {1, 0, -1, 0};\n\
    const int dy4[4] = {0, -1, 0, 1};\nconst int dx8[8] = {1, 1, 0, -1, -1, -1, 0,\
    \ 1};\nconst int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};\n\nvector<pair<int, int>>\
    \ adjacent(int current_y, int current_x, int max_y, int max_x, bool dir_8 = false){\n\
    \    vector<pair<int, int>> ret;\n    for(int d = 0; d < 4 * (1 + dir_8); ++d){\n\
    \        int next_y = current_y + (dir_8 ? dy8[d] : dy4[d]);\n        int next_x\
    \ = current_x + (dir_8 ? dx8[d] : dx4[d]);\n        if(InGrid(next_y, next_x,\
    \ max_y, max_x)){\n            ret.emplace_back(next_y, next_x);\n        }\n\
    \    }\n    return ret;\n}\n\ntemplate <typename T1, typename T2>\nostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p){\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\n\ntemplate <typename T1, typename T2>\nistream &operator>>(istream &is,\
    \ pair<T1, T2> &p){\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, vector<T> &v){\n    for (int\
    \ i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1 != v.size() ? \" \"\
    \ : \"\");\n    }\n    return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, vector<vector<T>> &v){\n    for (int i = 0; i < v.size(); ++i){\n     \
    \   os << v[i] << (i + 1 != v.size() ? \"\\n\" : \"\");\n    }\n    return os;\n\
    }\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v){\n\
    \    for (int i = 0; i < v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, set<T> &v){\n    for (auto &u\
    \ : v){\n        os << u << \" \";\n    }\n    return os;\n}\n\ntemplate<typename\
    \ T1, typename T2>\nvector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2>\
    \ &v2){\n    assert(v1.size() == v2.size());\n    vector<pair<T1, T2>> v;\n  \
    \  for(int i = 0; i < v1.size(); ++i) v.push_back({v1[i], v2[i]});\n    return\
    \ v;\n}\n\ntemplate<typename T1, typename T2>\npair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1,\
    \ T2>> &v){\n    vector<T1> v1;\n    vector<T2> v2;\n    transform(v.begin(),\
    \ v.end(), back_inserter(v1), [](auto p){return p.first;});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v2), [](auto p){return p.second;});\n    return {v1,\
    \ v2};\n}\n\ntemplate<typename T1, typename T2, typename T3>\ntuple<vector<T1>,\
    \ vector<T2>, vector<T3>> DisassembleVectorTuple(vector<tuple<T1, T2, T3>> &v){\n\
    \    vector<T1> v1;\n    vector<T2> v2;\n    vector<T3> v3;\n    transform(v.begin(),\
    \ v.end(), back_inserter(v1), [](auto p){return get<0>(p);});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v2), [](auto p){return get<1>(p);});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v3), [](auto p){return get<2>(p);});\n    return {v1,\
    \ v2, v3};\n}\n\ntemplate<typename T1 = int, typename T2 = T1>\npair<vector<T1>,\
    \ vector<T2>> InputVectorPair(int size){\n    vector<pair<T1, T2>> v(size);\n\
    \    for(auto &[p, q] : v) cin >> p >> q;\n    return DisassembleVectorPair(v);\n\
    }\n\ntemplate<typename T1 = int, typename T2 = T1, typename T3 = T1>\ntuple<vector<T1>,\
    \ vector<T2>, vector<T3>> InputVectorTuple(int size){\n    vector<tuple<T1, T2,\
    \ T3>> v(size);\n    for(auto &[p, q, r] : v) cin >> p >> q >> r;\n    return\
    \ DisassembleVectorTuple(v);\n}\n#line 2 \"Library/Tree/EulerTour.hpp\"\n\n/**\n\
    \ * @file EulerTour.hpp\n * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\
    \u30A2\u30FC\n * @version 4.0\n * @date 2024-10-31\n */\n\n#line 2 \"Library/Tree/Tree.hpp\"\
    \n\n#line 2 \"Library/Graph/Graph.hpp\"\n\n#line 4 \"Library/Graph/Graph.hpp\"\
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
    \    dfs(c);\n        }\n        out_time_[v] = time_++;\n    }\n};\n#line 2 \"\
    Library/DataStructure/SegmentTree.hpp\"\n\ntemplate<typename Monoid>\nclass SegmentTree{\n\
    \    public:\n    using F = function<Monoid(Monoid, Monoid)>;\n\n    SegmentTree(\n\
    \        int n,\n        F merge,\n        const Monoid &e,\n        bool zero_index\
    \ = false\n    ) : f(merge), id_(e), zero_index_(zero_index){\n        size_ =\
    \ 1;\n        while(size_ < n) size_ <<= 1;\n        offset_ = size_ - 1;\n  \
    \      data_.resize(2 * size_, id_);\n    }\n    \n    SegmentTree(\n        vector<Monoid>\
    \ &A, \n        F merge, \n        const Monoid &e, \n        bool zero_index\
    \ = false\n    ) : f(merge), id_(e), zero_index_(zero_index){\n        size_ =\
    \ 1;\n        while(size_ < (int)A.size()) size_ <<= 1;\n        offset_ = size_\
    \ - 1;\n        data_.resize(2 * size_, id_);\n        for(int i = 0; i < (int)A.size();\
    \ ++i){\n            data_[size_ + i] = A[i];\n        }\n        Build();\n \
    \   }\n\n    void Build(){\n        for(int i = offset_; i >= 1; --i){\n     \
    \       data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n\
    \    void Set(int i, Monoid v){\n        Validate(i + zero_index_);\n        int\
    \ k = offset_ + i + zero_index_;\n        data_[k] = v;\n        while(k >>= 1){\n\
    \            data_[k] = f(data_[2 * k], data_[2 * k + 1]);\n        }\n    }\n\
    \n    Monoid Product(int l, int r){\n        if(l == r) return id_;\n        Validate(l\
    \ + zero_index_);\n        Validate(r + zero_index_ - 1);\n        int lh = l\
    \ + zero_index_ + offset_, rh = r + zero_index_ + offset_;\n        Monoid al\
    \ = id_, ar = id_;\n        while(lh < rh){\n            if(lh & 1) al = f(al,\
    \ data_[lh++]);\n            if(rh & 1) ar = f(data_[--rh], ar);\n           \
    \ lh >>= 1, rh >>= 1;\n        }\n        return f(al, ar);\n    }\n\n    Monoid\
    \ operator[](const int &i){\n        Validate(i + zero_index_);\n        return\
    \ data_[offset_ + i + zero_index_];\n    }\n\n    private:\n    int size_, offset_,\
    \ zero_index_;\n    vector<Monoid> data_;\n    const F f;\n    const Monoid id_;\n\
    \n    inline void Validate(int x) const {\n        assert(1 <= x && x <= size_);\n\
    \    }\n};\n#line 6 \"verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp\"\n\nint\
    \ main(){\n    cin.tie(0)->sync_with_stdio(false);\n    int N, Q; cin >> N >>\
    \ Q;\n    vector<ll> a(N); cin >> a;\n    RootedTree T(N);\n    T.InputRootedTreeFormat(false,\
    \ false);\n\n    EulerTour et(T);\n    auto A = et.ConvertVector(a, [](ll x){return\
    \ x;}, [](ll x){return 0;});\n    SegmentTree<ll> seg(A, [](ll l, ll r){return\
    \ l + r;}, 0LL, true);\n    while(Q--){\n        int t; cin >> t;\n        if(t\
    \ == 0){\n            int u, x; cin >> u >> x;\n            seg.Set(et.get_in(u),\
    \ seg[et.get_in(u)] + x);\n        }\n        else{\n            int u; cin >>\
    \ u;\n            auto [l, r] = et.get_pair(u);\n            cout << seg.Product(l,\
    \ r) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/Tree/EulerTour.hpp\"\
    \n#include \"../Library/DataStructure/SegmentTree.hpp\"\n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n\
    \    int N, Q; cin >> N >> Q;\n    vector<ll> a(N); cin >> a;\n    RootedTree\
    \ T(N);\n    T.InputRootedTreeFormat(false, false);\n\n    EulerTour et(T);\n\
    \    auto A = et.ConvertVector(a, [](ll x){return x;}, [](ll x){return 0;});\n\
    \    SegmentTree<ll> seg(A, [](ll l, ll r){return l + r;}, 0LL, true);\n    while(Q--){\n\
    \        int t; cin >> t;\n        if(t == 0){\n            int u, x; cin >> u\
    \ >> x;\n            seg.Set(et.get_in(u), seg[et.get_in(u)] + x);\n        }\n\
    \        else{\n            int u; cin >> u;\n            auto [l, r] = et.get_pair(u);\n\
    \            cout << seg.Product(l, r) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/Tree/EulerTour.hpp
  - Library/Tree/Tree.hpp
  - Library/Graph/Graph.hpp
  - Library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
  requiredBy: []
  timestamp: '2025-05-30 20:02:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
- /verify/verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp.html
title: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
---
