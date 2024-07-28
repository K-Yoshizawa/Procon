---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/SegmentTree.hpp
    title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph - \u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: library/Tree/EulerTour.hpp
    title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  - icon: ':heavy_check_mark:'
    path: library/Tree/LowestCommonAncestor.hpp
    title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"verify/LC-VertexAddPathSum-ET.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 1 \"library/Tree/EulerTour.hpp\"\
    \n/**\n * @file EulerTour.hpp\n * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\
    \u30C4\u30A2\u30FC\n * @version 3.0\n * @date 2024-02-11\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @brief Graph Template - \u30B0\u30E9\u30D5\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 3.0\n * @date 2024-01-09\n */\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    public:\n    Vertex from, to;\n    CostType cost;\n\
    \    int loc{-1}, id{-1};\n\n    Edge() = default;\n    Edge(Vertex from, Vertex\
    \ to, CostType cost) : from(from), to(to), cost(cost){}\n\n    operator int(){\n\
    \        return to;\n    }\n};\n\ntemplate<typename CostType = int>\nstruct Graph{\n\
    \    private:\n    int vertex_size_{0}, edge_size_{0};\n    bool is_directed_{false},\
    \ is_weighted_{false};\n    vector<vector<Edge<CostType>>> adj_;\n    vector<int>\
    \ indegree_;\n\n    public:\n    CostType INF{numeric_limits<CostType>::max()\
    \ >> 2};\n\n    Graph() = default;\n\n    /**\n     * @brief `vertex_size` \u9802\
    \u70B9 `0` \u8FBA\u306E\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\u3002\n\
    \     * @note `directed` \u3092 `true` \u306B\u3059\u308B\u3068\u6709\u5411\u30B0\
    \u30E9\u30D5\u306B\u306A\u308B\u3002\n     * @param vertex_size \u9802\u70B9\u6570\
    \n     * @param directed \u6709\u5411\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\
    \u308B\u304B (option, default = `false`)\n     */\n    Graph(int vertex_size,\
    \ bool directed = false) : vertex_size_(vertex_size), is_directed_(directed){\n\
    \        adj_.resize(vertex_size);\n        indegree_.resize(vertex_size, 0);\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `from` \u304B\u3089\u9802\u70B9\
    \ `to` \u306B\u8FBA\u3092\u5F35\u308B\u3002\n     * @note `cost` \u3092\u6307\u5B9A\
    \u3059\u308B\u3053\u3068\u3067\u91CD\u307F\u3092\u3064\u3051\u308B\u3053\u3068\
    \u304C\u3067\u304D\u308B\u3002\n     * @param from \u9802\u70B9\u756A\u53F7\n\
    \     * @param to \u9802\u70B9\u756A\u53F7\n     * @param cost \u91CD\u307F (option,\
    \ default = `1`)\n     */\n    void add(Vertex from, Vertex to, CostType cost\
    \ = 1){\n        assert(0 <= from and from < vertex_size_);\n        assert(0\
    \ <= to and to < vertex_size_);\n        is_weighted_ |= cost > 1;\n        Edge<CostType>\
    \ e1(from, to, cost);\n        e1.loc = adj_[from].size();\n        e1.id = edge_size_;\n\
    \        adj_[from].push_back(e1);\n        ++edge_size_;\n        if(is_directed_){\n\
    \            ++indegree_[to];\n            return;\n        }\n        Edge<CostType>\
    \ e2(to, from, cost);\n        e2.loc = adj_[to].size();\n        e2.id = e1.id;\n\
    \        adj_[to].push_back(e2);\n    }\n\n    /**\n     * @brief \u30B0\u30E9\
    \u30D5\u306B `edge_size` \u672C\u306E\u8FBA\u3092\u5165\u529B\u3055\u305B\u308B\
    \u3002\n     * @param edge_size \u5165\u529B\u3059\u308B\u8FBA\u6570\n     * @param\
    \ weighted \u91CD\u307F\u4ED8\u304D\u8FBA\u304B (option, default = `false`)\n\
    \     * @param zero_index \u5165\u529B\u306E\u9802\u70B9\u756A\u53F7\u304C 0-index\
    \ \u304B (option, default = `false`)\n     */\n    void input(int edge_size, bool\
    \ weighted = false, bool zero_index = false){\n        is_weighted_ = weighted;\n\
    \        for(int i = 0; i < edge_size; ++i){\n            Vertex s, t; cin >>\
    \ s >> t;\n            if(!zero_index) --s, --t;\n            CostType c = 1;\n\
    \            if(weighted) cin >> c;\n            add(s, t, c);\n        }\n  \
    \  }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\u3092\
    \u8FD4\u3059\u3002\n     * @return size_t \u9802\u70B9\u6570\n     */\n    size_t\
    \ size(){\n        return vertex_size_;\n    }\n\n    /**\n     * @brief \u9802\
    \u70B9 `v` \u306E\u51FA\u6B21\u6570\u3092\u8FD4\u3059\u3002\n     * @param v \u9802\
    \u70B9\u756A\u53F7\n     * @return int \u9802\u70B9 `v` \u306E\u51FA\u6B21\u6570\
    \n     */\n    int outdegree(Vertex v){\n        return (int)adj_.at(v).size();\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E\u5165\u6B21\u6570\u3092\
    \u8FD4\u3059\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return int\
    \ \u9802\u70B9 `v` \u306E\u5165\u6B21\u6570\n     */\n    int indegree(Vertex\
    \ v){\n        if(is_directed_) return indegree_.at(v);\n        else return (int)adj_.at(v).size();\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u304C\u6709\u5411\u30B0\u30E9\
    \u30D5\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\u3002\n     */\n    bool is_directed(){\n\
    \        return is_directed_;\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\
    \u304C\u91CD\u307F\u4ED8\u304D\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\u3002\
    \n     */\n    bool is_weighted(){\n        return is_weighted_;\n    }\n\n  \
    \  vector<Vertex> source(){\n        assert(is_directed_);\n        vector<Vertex>\
    \ ret;\n        for(int i = 0; i < vertex_size_; ++i){\n            if(indegree(i)\
    \ == 0) ret.push_back(i);\n        }\n        return ret;\n    }\n\n    vector<Vertex>\
    \ sink(){\n        vector<Vertex> ret;\n        for(int i = 0; i < vertex_size_;\
    \ ++i){\n            if(outdegree(i) == 0) ret.push_back(i);\n        }\n    \
    \    return ret;\n    }\n\n    vector<Vertex> leaf(){\n        vector<Vertex>\
    \ ret;\n        for(int i = 0; i < vertex_size_; ++i){\n            if(indegree(i)\
    \ == 1) ret.push_back(i);\n        }\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u9802\u70B9 `v` \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u3092\u8FD4\
    \u3059\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return vector<Edge<CostType>>&\
    \ \u9802\u70B9 `v` \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\n     */\n    vector<Edge<CostType>>\
    \ &get_adj(Vertex v){\n        return adj_.at(v);\n    }\n\n    /**\n     * @brief\
    \ \u8FBA\u306E\u5411\u304D\u3092\u3059\u3079\u3066\u9006\u306B\u3057\u305F\u30B0\
    \u30E9\u30D5\u3092\u8FD4\u3059\u3002\n     * @attention \u6709\u5411\u30B0\u30E9\
    \u30D5\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u4EF6\u3068\u3059\u308B\u3002\
    \n     * @return Graph<CostType> \u9006\u8FBA\u30B0\u30E9\u30D5\n     */\n   \
    \ Graph<CostType> reverse(){\n        assert(is_directed_);\n        Graph ret(vertex_size_,\
    \ true);\n        for(auto es : adj_){\n            for(auto e : es){\n      \
    \          ret.add(e.to, e.from, e.cost);\n            }\n        }\n        return\
    \ ret;\n    }\n\n    /**\n     * @brief \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8\u3057\u305F\u9802\u70B9\u5217\u3092\u8FD4\u3059\u3002\n     * @attention\
    \ \u6709\u5411\u30B0\u30E9\u30D5\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u4EF6\
    \u3068\u3059\u308B\u3002\n     * @return vector<Vertex> \u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8\u3057\u305F\u9802\u70B9\u5217\n     */\n    vector<Vertex>\
    \ topological_sort(){\n        assert(is_directed_);\n        vector<Vertex> ret;\n\
    \        queue<Vertex> que;\n        vector<int> cnt(vertex_size_, 0);\n     \
    \   for(auto v : source()) que.push(v);\n        while(que.size()){\n        \
    \    Vertex v = que.front(); que.pop();\n            ret.push_back(v);\n     \
    \       for(int u : adj_[v]){\n                if(++cnt[u] == indegree(u)) que.push(u);\n\
    \            }\n        }\n        return ret;\n    }\n\n    /**\n     * @brief\
    \ \u30B0\u30E9\u30D5\u304B\u3089\u8FBA\u96C6\u5408\u3092\u4F5C\u6210\u3059\u308B\
    \u3002\n     * @note \u8FBA\u96C6\u5408\u306F\u91CD\u307F\u3067\u6607\u9806\u30BD\
    \u30FC\u30C8\u3055\u308C\u305F\u72B6\u614B\u3067\u8FD4\u3055\u308C\u308B\u3002\
    \n     * @return vector<Edge<CostType>> \u8FBA\u96C6\u5408\n     */\n    vector<Edge<CostType>>\
    \ edge_set(){\n        vector<Edge<CostType>> ret;\n        vector<int> es(edge_size_,\
    \ 0);\n        for(int i = 0; i < vertex_size_; ++i){\n            for(auto e\
    \ : adj_[i]){\n                if(es[e.id]) continue;\n                es[e.id]\
    \ = 1;\n                ret.push_back(e);\n            }\n        }\n        sort(ret.begin(),\
    \ ret.end(), [&](Edge<CostType> &l, Edge<CostType> &r){\n            return l.cost\
    \ < r.cost;\n        });\n        return ret;\n    }\n\n    vector<vector<CostType>>\
    \ matrix(){\n        int n = vertex_size_;\n        vector<vector<CostType>> ret(n,\
    \ vector<CostType>(n, INF));\n        for(int i = 0; i < n; ++i) ret[i][i] = 0;\n\
    \        for(int v = 0; v < n; ++v){\n            for(auto &e : adj_[v]){\n  \
    \              ret[v][e.to] = e.cost;\n            }\n        }\n        return\
    \ ret;\n    }\n\n    friend ostream &operator<<(ostream &os, Graph<CostType> &G){\n\
    \        for(int i = 0; i < G.size(); ++i){\n            os << \"Vertex \" <<\
    \ i << \" : \";\n            if(G[i].empty()){\n                os << \"<none>\"\
    \ << endl;\n                continue;\n            }\n            for(auto &e\
    \ : G[i]){\n                if(G.is_weighted()) os << \"{\" << e.to << \", \"\
    \ << e.cost << \"} \";\n                else os << e.to << \" \";\n          \
    \  }\n            if(i + 1 < G.size()) os << endl;\n        }\n        return\
    \ os;\n    }\n\n    vector<Edge<CostType>> &operator[](Vertex v){\n        return\
    \ get_adj(v);\n    }\n};\n#line 9 \"library/Tree/EulerTour.hpp\"\n\ntemplate<typename\
    \ CostType>\nstruct EulerTour{\n    private:\n    Graph<CostType> &G;\n    vector<int>\
    \ in_, out_;\n\n    void dfs_(Vertex v, Vertex p, int &t){\n        in_[v] = t++;\n\
    \        for(auto &e : G[v]){\n            if(e.to == p) continue;\n         \
    \   dfs_(e.to, v, t);\n        }\n        out_[v] = t++;\n    }\n\n    public:\n\
    \    /**\n     * @brief Construct a new Euler Tour object\n     * @param G \u6728\
    \n     * @param Root \u6839\u306E\u9802\u70B9\u756A\u53F7(0-index)\n     * @param\
    \ Offset \u30BF\u30A4\u30E0\u30B9\u30BF\u30F3\u30D7\u306E\u521D\u671F\u5024\n\
    \     */\n    EulerTour(Graph<CostType> &G, Vertex Root = 0, int Offset = 0) :\
    \ G(G){\n        in_.resize(G.size());\n        out_.resize(G.size());\n     \
    \   dfs_(Root, -1, Offset);\n    }\n\n    int in(Vertex v){\n        assert(0\
    \ <= v && v < G.size());\n        return in_[v];\n    }\n\n    int out(Vertex\
    \ v){\n        assert(0 <= v && v < G.size());\n        return out_[v];\n    }\n\
    \n    pair<vector<int>, vector<int>> get(){\n        return make_pair(in_, out_);\n\
    \    }\n\n    pair<int, int> operator[](Vertex v){\n        return make_pair(in(v),\
    \ out(v));\n    }\n};\n#line 1 \"library/Tree/LowestCommonAncestor.hpp\"\n/**\n\
    \ * @file LowestCommonAncestor.hpp\n * @brief Lowest Common Ancestor - \u6700\u5C0F\
    \u5171\u901A\u7956\u5148\n * @version 3.0\n * @date 2024-02-11\n */\n\n#line 9\
    \ \"library/Tree/LowestCommonAncestor.hpp\"\n\ntemplate<typename CostType>\nstruct\
    \ LowestCommonAncestor{\n    private:\n    Graph<CostType> &G;\n    int height_;\n\
    \    vector<int> depth_;\n    vector<vector<Vertex>> parent_;\n    vector<CostType>\
    \ cum_;\n\n    void dfs_(Vertex v, Vertex p, int d){\n        parent_[0][v] =\
    \ p;\n        depth_[v] = d;\n        for(auto &e : G[v]){\n            if(e.to\
    \ != p){\n                cum_[e.to] = cum_[v] + e.cost;\n                dfs_(e.to,\
    \ v, d + 1);\n            }\n        }\n    }\n\n    public:\n    /**\n     *\
    \ @brief Construct a new Lowest Common Ancestor object\n     * @param G \u6728\
    \n     * @param Root \u6839\u306E\u9802\u70B9\u756A\u53F7(0-index)\n     */\n\
    \    LowestCommonAncestor(Graph<CostType> &G, Vertex Root = 0) : G(G), height_(32){\n\
    \        depth_.resize(G.size());\n        parent_.resize(height_, vector<Vertex>(G.size(),\
    \ -1));\n        cum_.resize(G.size(), 0);\n        dfs_(Root, -1, 0);\n     \
    \   for(int k = 0; k + 1 < height_; ++k){\n            for(Vertex v = 0; v < G.size();\
    \ ++v){\n                if(parent_[k][v] < 0) parent_[k + 1][v] = -1;\n     \
    \           else parent_[k + 1][v] = parent_[k][parent_[k][v]];\n            }\n\
    \        }\n    }\n\n    /**\n     * @brief \u9802\u70B9 `u` \u3068\u9802\u70B9\
    \ `v` \u306E LCA \u3092\u6C42\u3081\u308B\u3002\n     * @note \u9802\u70B9\u756A\
    \u53F7\u306F 0-index\n     * @return Vertex LCA\u306E\u9802\u70B9\u756A\u53F7\n\
    \     */\n    Vertex get(Vertex u, Vertex v){\n        if(depth_[u] > depth_[v])\
    \ swap(u, v);\n        for(int k = 0; k < height_; ++k){\n            if((depth_[v]\
    \ - depth_[u]) >> k & 1){\n                v = parent_[k][v];\n            }\n\
    \        }\n        if(u == v) return u;\n        for(int k = height_ - 1; k >=\
    \ 0; --k){\n            if(parent_[k][u] != parent_[k][v]){\n                u\
    \ = parent_[k][u];\n                v = parent_[k][v];\n            }\n      \
    \  }\n        return parent_[0][u];\n    }\n\n    /**\n     * @brief \u9802\u70B9\
    \ `u` \u3068\u9802\u70B9 `v` \u9593\u306E\u30B3\u30B9\u30C8\u3092\u6C42\u3081\u308B\
    \u3002\n     * @note \u9802\u70B9\u756A\u53F7\u306F 0-index\n     * @return CostType\
    \ \u30B3\u30B9\u30C8\n     */\n    CostType dist(Vertex u, Vertex v){\n      \
    \  return cum_[u] + cum_[v] - cum_[get(u, v)] * 2;\n    }\n};\n#line 1 \"library/DataStructure/SegmentTree.hpp\"\
    \n/**\n * @file SegmentTree.hpp\n * @author log K (lX57)\n * @brief Segment Tree\
    \ - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @version 2.2\n * @date 2023-10-02\n\
    \ */\n\n#line 10 \"library/DataStructure/SegmentTree.hpp\"\nusing namespace std;\n\
    \ntemplate<typename Monoid>\nstruct SegmentTree{\n    private:\n    using F =\
    \ function<Monoid(Monoid, Monoid)>;\n\n    int size_, offset_, zeroindex_;\n \
    \   vector<Monoid> data_;\n    const F f;\n    const Monoid m1_;\n\n    inline\
    \ void check_(int x){\n        assert(1 <= x && x <= size_);\n    }\n\n    public:\n\
    \    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\
    \u6570 `Size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Size \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\n     * @param Merge \u533A\
    \u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param Monoid_Identity\
    \ \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\
    \u3057\u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(int\
    \ Size, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\n    :\
    \ f(Merge), m1_(Monoid_Identity), zeroindex_(ZeroIndex){\n        size_ = 1;\n\
    \        while(size_ < Size) size_ <<= 1;\n        offset_ = size_ - 1;\n    \
    \    data_.resize(2 * size_, m1_);\n    }\n\n    /**\n     * @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention\
    \ \u5FC5\u305A `set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\
    \u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n     */\n    void build(){\n\
    \        for(int i = offset_; i >= 1; --i){\n            data_[i] = f(data_[i\
    \ * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\
    \u308B\u3002\n     * @param Index \u4EE3\u5165\u5148\u306E\u8981\u7D20\u756A\u53F7\
    \ (default = 1-index)\n     * @param Value \u4EE3\u5165\u3059\u308B\u5024\n  \
    \   */\n    void set(int Index, Monoid Value){\n        check_(Index + zeroindex_);\n\
    \        data_[offset_ + Index + zeroindex_] = Value;\n    }\n\n    /**\n    \
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u914D\u5217 `Init_Data`\
    \ \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Init_Data \u521D\u671F\
    \u30C7\u30FC\u30BF\u306E\u914D\u5217\n     * @param Merge \u533A\u9593\u53D6\u5F97\
    \u3092\u884C\u3046\u6F14\u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\
    \u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\
    \u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(vector<Monoid>\
    \ &Init_Data, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\n\
    \    : f(Merge), m1_(Monoid_Identity), zeroindex_(ZeroIndex){\n        size_ =\
    \ 1;\n        while(size_ < (int)Init_Data.size()) size_ <<= 1;\n        offset_\
    \ = size_ - 1;\n        data_.resize(2 * size_, m1_);\n        for(int i = 0;\
    \ i < (int)Init_Data.size(); ++i){\n            data_[size_ + i] = Init_Data[i];\n\
    \        }\n        build();\n    }\n\n    /**\n     * @brief \u4E00\u70B9\u66F4\
    \u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\n     * @param Index\
    \ \u66F4\u65B0\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     *\
    \ @param Value \u66F4\u65B0\u3059\u308B\u5024\n     */\n    void update(int Index,\
    \ Monoid Value){\n        check_(Index + zeroindex_);\n        int k = offset_\
    \ + Index + zeroindex_;\n        data_[k] = Value;\n        while(k >>= 1){\n\
    \            data_[k] = f(data_[2 * k], data_[2 * k + 1]);\n        }\n    }\n\
    \n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[Left, Right)` \u306B\u5BFE\
    \u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\u884C\u3046\u3002\
    \n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n     * @param\
    \ Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return Monoid \u53D6\
    \u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid query(int Left, int Right){\n\
    \        if(Left == Right) return m1_;\n        check_(Left + zeroindex_);\n \
    \       check_(Right + zeroindex_ - 1);\n        int l = Left + zeroindex_ + offset_,\
    \ r = Right + zeroindex_ + offset_;\n        Monoid al = m1_, ar = m1_;\n    \
    \    while(l < r){\n            if(l & 1) al = f(al, data_[l++]);\n          \
    \  if(r & 1) ar = f(data_[--r], ar);\n            l >>= 1, r >>= 1;\n        }\n\
    \        return f(al, ar);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u756A\
    \u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param\
    \ k \u53D6\u5F97\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n   \
    \  * @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid\
    \ get(int k){\n        check_(k + zeroindex_);\n        return data_[offset_ +\
    \ k + zeroindex_];\n    }\n\n    Monoid operator[](const int &k){\n        return\
    \ get(k);\n    }\n};\n#line 6 \"verify/LC-VertexAddPathSum-ET.test.cpp\"\n\nint\
    \ main(){\n    int N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n    for(auto\
    \ &ai : a) cin >> ai;\n    Graph<long long> G(N);\n    G.input(N - 1, false, true);\n\
    \n    EulerTour et(G);\n    auto [in, out] = et.get();\n    vector<long long>\
    \ b(N * 2, 0);\n    for(int i = 0; i < N; ++i){\n        b[in[i]] = a[i], b[out[i]]\
    \ = -a[i];\n    }\n    LowestCommonAncestor lca(G);\n    SegmentTree<long long>\
    \ seg(b, [&](long long l, long long r){return l + r;}, 0LL, true);\n\n    while(Q--){\n\
    \        int query; cin >> query;\n        if(query == 0){\n            long long\
    \ p, x; cin >> p >> x;\n            long long y = a[p] + x;\n            a[p]\
    \ += x;\n            seg.update(in[p], y);\n            seg.update(out[p], -y);\n\
    \        }\n        else{\n            int u, v; cin >> u >> v;\n            int\
    \ t = lca.get(u, v);\n            cout << seg.query(in[t], in[u] + 1) + seg.query(in[t],\
    \ in[v] + 1) - a[t] << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../library/Tree/EulerTour.hpp\"\n#include \"../library/Tree/LowestCommonAncestor.hpp\"\
    \n#include \"../library/DataStructure/SegmentTree.hpp\"\n\nint main(){\n    int\
    \ N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n    for(auto &ai : a) cin\
    \ >> ai;\n    Graph<long long> G(N);\n    G.input(N - 1, false, true);\n\n   \
    \ EulerTour et(G);\n    auto [in, out] = et.get();\n    vector<long long> b(N\
    \ * 2, 0);\n    for(int i = 0; i < N; ++i){\n        b[in[i]] = a[i], b[out[i]]\
    \ = -a[i];\n    }\n    LowestCommonAncestor lca(G);\n    SegmentTree<long long>\
    \ seg(b, [&](long long l, long long r){return l + r;}, 0LL, true);\n\n    while(Q--){\n\
    \        int query; cin >> query;\n        if(query == 0){\n            long long\
    \ p, x; cin >> p >> x;\n            long long y = a[p] + x;\n            a[p]\
    \ += x;\n            seg.update(in[p], y);\n            seg.update(out[p], -y);\n\
    \        }\n        else{\n            int u, v; cin >> u >> v;\n            int\
    \ t = lca.get(u, v);\n            cout << seg.query(in[t], in[u] + 1) + seg.query(in[t],\
    \ in[v] + 1) - a[t] << endl;\n        }\n    }\n}"
  dependsOn:
  - library/Tree/EulerTour.hpp
  - library/Graph/GraphTemplate.hpp
  - library/Tree/LowestCommonAncestor.hpp
  - library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify/LC-VertexAddPathSum-ET.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 19:12:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-VertexAddPathSum-ET.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-VertexAddPathSum-ET.test.cpp
- /verify/verify/LC-VertexAddPathSum-ET.test.cpp.html
title: verify/LC-VertexAddPathSum-ET.test.cpp
---
