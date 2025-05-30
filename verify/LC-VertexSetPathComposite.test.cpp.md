---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/SegmentTree.hpp
    title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: Library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/HeavyLightDecomposition.hpp
    title: "Heavy Light Decomposition - \u91CD\u8EFD\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728"
  - icon: ':heavy_check_mark:'
    path: Library/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"verify/LC-VertexSetPathComposite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n\n#line 2 \"\
    Library/Template.hpp\"\n\n/**\n * @file Template.hpp\n * @author log K (lX57)\n\
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
    \ DisassembleVectorTuple(v);\n}\n#line 2 \"Library/Tree/Tree.hpp\"\n\n#line 2\
    \ \"Library/Graph/Graph.hpp\"\n\n#line 4 \"Library/Graph/Graph.hpp\"\n\nusing\
    \ Vertex = int;\n\ntemplate<typename CostType = int32_t>\nstruct Edge{\n    public:\n\
    \    Edge() = default;\n\n    Edge(Vertex from_, Vertex to_, CostType cost_ =\
    \ 1, int idx_ = -1) :\n        from(from_), to(to_), cost(cost_), idx(idx_){}\n\
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
    };\n#line 2 \"Library/DataStructure/SegmentTree.hpp\"\n\ntemplate<typename Monoid>\n\
    class SegmentTree{\n    public:\n    using F = function<Monoid(Monoid, Monoid)>;\n\
    \n    SegmentTree(\n        int n,\n        F merge,\n        const Monoid &e,\n\
    \        bool zero_index = false\n    ) : f(merge), id_(e), zero_index_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < n) size_ <<= 1;\n        offset_ =\
    \ size_ - 1;\n        data_.resize(2 * size_, id_);\n    }\n    \n    SegmentTree(\n\
    \        vector<Monoid> &A, \n        F merge, \n        const Monoid &e, \n \
    \       bool zero_index = false\n    ) : f(merge), id_(e), zero_index_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < (int)A.size()) size_ <<= 1;\n     \
    \   offset_ = size_ - 1;\n        data_.resize(2 * size_, id_);\n        for(int\
    \ i = 0; i < (int)A.size(); ++i){\n            data_[size_ + i] = A[i];\n    \
    \    }\n        Build();\n    }\n\n    void Build(){\n        for(int i = offset_;\
    \ i >= 1; --i){\n            data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n\
    \        }\n    }\n\n    void Set(int i, Monoid v){\n        Validate(i + zero_index_);\n\
    \        int k = offset_ + i + zero_index_;\n        data_[k] = v;\n        while(k\
    \ >>= 1){\n            data_[k] = f(data_[2 * k], data_[2 * k + 1]);\n       \
    \ }\n    }\n\n    Monoid Product(int l, int r){\n        if(l == r) return id_;\n\
    \        Validate(l + zero_index_);\n        Validate(r + zero_index_ - 1);\n\
    \        int lh = l + zero_index_ + offset_, rh = r + zero_index_ + offset_;\n\
    \        Monoid al = id_, ar = id_;\n        while(lh < rh){\n            if(lh\
    \ & 1) al = f(al, data_[lh++]);\n            if(rh & 1) ar = f(data_[--rh], ar);\n\
    \            lh >>= 1, rh >>= 1;\n        }\n        return f(al, ar);\n    }\n\
    \n    Monoid operator[](const int &i){\n        Validate(i + zero_index_);\n \
    \       return data_[offset_ + i + zero_index_];\n    }\n\n    private:\n    int\
    \ size_, offset_, zero_index_;\n    vector<Monoid> data_;\n    const F f;\n  \
    \  const Monoid id_;\n\n    inline void Validate(int x) const {\n        assert(1\
    \ <= x && x <= size_);\n    }\n};\n#line 2 \"Library/modint.hpp\"\n\n/**\n * @file\
    \ modint.hpp\n * @author log K (lX57)\n * @brief modint\n * @version 1.0\n * @date\
    \ 2023-08-24\n */\n\n#line 12 \"Library/modint.hpp\"\nusing namespace std;\n\n\
    const int mod998 = 998244353;\nconst int mod107 = 1000000007;\n\ntemplate< int\
    \ mod >\nstruct ModInt {\n    int x;\n\n    ModInt() : x(0) {}\n\n    ModInt(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n    ModInt &operator+=(const\
    \ ModInt &p) {\n        if((x += p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n\n    ModInt &operator-=(const ModInt &p) {\n        if((x += mod - p.x)\
    \ >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (int) (1LL * x * p.x % mod);\n        return *this;\n\
    \    }\n\n    ModInt &operator/=(const ModInt &p) {\n        *this *= p.inverse();\n\
    \        return *this;\n    }\n\n    ModInt operator-() const { return ModInt(-x);\
    \ }\n\n    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p;\
    \ }\n\n    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p;\
    \ }\n\n    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p;\
    \ }\n\n    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p;\
    \ }\n\n    bool operator==(const ModInt &p) const { return x == p.x; }\n\n   \
    \ bool operator!=(const ModInt &p) const { return x != p.x; }\n\n    ModInt inverse()\
    \ const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while(b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return ModInt(u);\n    }\n\n    ModInt pow(int64_t\
    \ n) const {\n        if(n == 0) return ModInt(1);\n        ModInt ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, const ModInt &p) {\n        return os << p.x;\n\
    \    }\n\n    friend istream &operator>>(istream &is, ModInt &a) {\n        int64_t\
    \ t;\n        is >> t;\n        a = ModInt< mod >(t);\n        return (is);\n\
    \    }\n\n    static int get_mod() { return mod; }\n};\n\nusing mint = ModInt<mod998>;\n\
    using mint107 = ModInt<mod107>;\n\nusing vm = vector<mint>;\nusing vvm = vector<vector<mint>>;\n\
    using vm107 = vector<mint107>;\nusing vvm107 = vector<vector<mint107>>;\n#line\
    \ 7 \"verify/LC-VertexSetPathComposite.test.cpp\"\n\nstruct Affine{\n    Affine()\
    \ = default;\n    Affine(mint a, mint b) : a(a), b(b){}\n    mint a{1}, b{0};\n\
    \    static Affine left_merge(Affine l, Affine r){\n        return Affine(r.a\
    \ * l.a, r.a * l.b + r.b);\n    }\n    static Affine right_merge(Affine l, Affine\
    \ r){\n        return Affine(l.a * r.a, l.a * r.b + l.b);\n    }\n    friend ostream\
    \ &operator<<(ostream &os, const Affine &p) {\n        return os << \"{\" << p.a\
    \ << \", \" << p.b << \"}\";\n    }\n};\n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n\
    \    int N, Q; cin >> N >> Q;\n    vector<Affine> init_data;\n    for(int i =\
    \ 0; i < N; ++i){\n        mint a, b; cin >> a >> b;\n        init_data.push_back(Affine(a,\
    \ b));\n    }\n    auto T = InputTree(N, 0);\n\n    HeavyLightDecomposition hld(T);\n\
    \    hld.SortVertex(init_data);\n    SegmentTree<Affine> seg1(init_data, [](Affine\
    \ l, Affine r){return Affine::left_merge(l, r);}, Affine(), true);\n    SegmentTree<Affine>\
    \ seg2(init_data, [](Affine l, Affine r){return Affine::right_merge(l, r);}, Affine(),\
    \ true);\n    while(Q--){\n        int t; cin >> t;\n        if(t == 0){\n   \
    \         int p, c, d; cin >> p >> c >> d;\n            seg1.Set(hld[p], Affine(c,\
    \ d));\n            seg2.Set(hld[p], Affine(c, d));\n        }\n        else{\n\
    \            int u, v, x; cin >> u >> v >> x;\n            Affine ans;\n     \
    \       for(auto &path : hld.PathQuery(u, v)){\n                if(path.reverse)\
    \ ans = Affine::left_merge(ans, seg2.Product(path.head_index, path.tail_index));\n\
    \                else ans = Affine::left_merge(ans, seg1.Product(path.head_index,\
    \ path.tail_index));\n            }\n            cout << ans.a * x + ans.b <<\
    \ '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/Tree/HeavyLightDecomposition.hpp\"\
    \n#include \"../Library/DataStructure/SegmentTree.hpp\"\n#include \"../Library/modint.hpp\"\
    \n\nstruct Affine{\n    Affine() = default;\n    Affine(mint a, mint b) : a(a),\
    \ b(b){}\n    mint a{1}, b{0};\n    static Affine left_merge(Affine l, Affine\
    \ r){\n        return Affine(r.a * l.a, r.a * l.b + r.b);\n    }\n    static Affine\
    \ right_merge(Affine l, Affine r){\n        return Affine(l.a * r.a, l.a * r.b\
    \ + l.b);\n    }\n    friend ostream &operator<<(ostream &os, const Affine &p)\
    \ {\n        return os << \"{\" << p.a << \", \" << p.b << \"}\";\n    }\n};\n\
    \nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n    int N, Q; cin >> N\
    \ >> Q;\n    vector<Affine> init_data;\n    for(int i = 0; i < N; ++i){\n    \
    \    mint a, b; cin >> a >> b;\n        init_data.push_back(Affine(a, b));\n \
    \   }\n    auto T = InputTree(N, 0);\n\n    HeavyLightDecomposition hld(T);\n\
    \    hld.SortVertex(init_data);\n    SegmentTree<Affine> seg1(init_data, [](Affine\
    \ l, Affine r){return Affine::left_merge(l, r);}, Affine(), true);\n    SegmentTree<Affine>\
    \ seg2(init_data, [](Affine l, Affine r){return Affine::right_merge(l, r);}, Affine(),\
    \ true);\n    while(Q--){\n        int t; cin >> t;\n        if(t == 0){\n   \
    \         int p, c, d; cin >> p >> c >> d;\n            seg1.Set(hld[p], Affine(c,\
    \ d));\n            seg2.Set(hld[p], Affine(c, d));\n        }\n        else{\n\
    \            int u, v, x; cin >> u >> v >> x;\n            Affine ans;\n     \
    \       for(auto &path : hld.PathQuery(u, v)){\n                if(path.reverse)\
    \ ans = Affine::left_merge(ans, seg2.Product(path.head_index, path.tail_index));\n\
    \                else ans = Affine::left_merge(ans, seg1.Product(path.head_index,\
    \ path.tail_index));\n            }\n            cout << ans.a * x + ans.b <<\
    \ '\\n';\n        }\n    }\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/Tree/HeavyLightDecomposition.hpp
  - Library/Tree/Tree.hpp
  - Library/Graph/Graph.hpp
  - Library/DataStructure/SegmentTree.hpp
  - Library/modint.hpp
  isVerificationFile: true
  path: verify/LC-VertexSetPathComposite.test.cpp
  requiredBy: []
  timestamp: '2025-05-30 20:57:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-VertexSetPathComposite.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-VertexSetPathComposite.test.cpp
- /verify/verify/LC-VertexSetPathComposite.test.cpp.html
title: verify/LC-VertexSetPathComposite.test.cpp
---
