---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-LowestCommonAncestor-HLD.test.cpp
    title: verify/LC-LowestCommonAncestor-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexAddPathSum-HLD.test.cpp
    title: verify/LC-VertexAddPathSum-HLD.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Heavy Light Decomposition - HL\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"library/Tree/HeavyLightDecomposition.hpp\"\n/**\n * @file\
    \ HeavyLightDecomposition.hpp\n * @author log K (lX57)\n * @brief Heavy Light\
    \ Decomposition - HL\u5206\u89E3\n * @version 3.0\n * @date 2023-10-04\n */\n\n\
    #line 2 \"library/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
    \ * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @version 3.0\n * @date 2024-01-09\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing Vertex = int;\n\ntemplate<typename CostType>\nstruct\
    \ Edge{\n    public:\n    Vertex from, to;\n    CostType cost;\n    int loc{-1},\
    \ id{-1};\n\n    Edge() = default;\n    Edge(Vertex from, Vertex to, CostType\
    \ cost) : from(from), to(to), cost(cost){}\n\n    operator int(){\n        return\
    \ to;\n    }\n};\n\ntemplate<typename CostType = int>\nstruct Graph{\n    private:\n\
    \    int vertex_size_{0}, edge_size_{0};\n    bool is_directed_{false}, is_weighted_{false};\n\
    \    vector<vector<Edge<CostType>>> adj_;\n    vector<int> indegree_;\n\n    public:\n\
    \    CostType INF{numeric_limits<CostType>::max() >> 2};\n\n    Graph() = default;\n\
    \n    /**\n     * @brief `vertex_size` \u9802\u70B9 `0` \u8FBA\u306E\u30B0\u30E9\
    \u30D5\u3092\u4F5C\u6210\u3059\u308B\u3002\n     * @note `directed` \u3092 `true`\
    \ \u306B\u3059\u308B\u3068\u6709\u5411\u30B0\u30E9\u30D5\u306B\u306A\u308B\u3002\
    \n     * @param vertex_size \u9802\u70B9\u6570\n     * @param directed \u6709\u5411\
    \u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\u304B (option, default = `false`)\n\
    \     */\n    Graph(int vertex_size, bool directed = false) : vertex_size_(vertex_size),\
    \ is_directed_(directed){\n        adj_.resize(vertex_size);\n        indegree_.resize(vertex_size,\
    \ 0);\n    }\n\n    /**\n     * @brief \u9802\u70B9 `from` \u304B\u3089\u9802\u70B9\
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
    \ get_adj(v);\n    }\n};\n#line 10 \"library/Tree/HeavyLightDecomposition.hpp\"\
    \n\ntemplate<typename CostType>\nstruct HeavyLightDecomposition{\n    using ColumnIndex\
    \ = int;\n\n    private:\n    Vertex root_;\n    int timer_{0};\n\n    Graph<CostType>\
    \ &G;\n    vector<int> subtree_size_; // \u9802\u70B9 `i` \u3092\u6839\u3068\u3059\
    \u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\n    vector<int> depth_; // \u9802\
    \u70B9 `i` \u306E\u6839\u304B\u3089\u306E\u6DF1\u3055\n    vector<Vertex> parent_vertex_;\
    \ // \u9802\u70B9 `i` \u306E\u89AA\u306E\u9802\u70B9\uFF08\u6839\u306E\u5834\u5408\
    \u306F `-1` \uFF09\n    // vector<EdgeID> m_parentedge; // \u9802\u70B9 `i` \u3068\
    \u305D\u306E\u89AA\u3092\u7D50\u3076\u8FBA\u756A\u53F7\uFF08\u6839\u306E\u5834\
    \u5408\u306F `-1` \uFF09\n    vector<Vertex> child_vertex_; // \u8FBA `i` \u304C\
    \u7D50\u30762\u9802\u70B9\u306E\u3046\u3061\u3001\u5B50\u306E\u65B9\u306E\u9802\
    \u70B9\n    vector<int> in_, out_; // \u9802\u70B9 `i` \u306E\u884C\u304D\u304C\
    \u3051 / \u5E30\u308A\u304C\u3051\u306E\u9806\u756A (Euler-Tour)\n\n    vector<vector<Vertex>>\
    \ column_; // \u5404\u5217\u306B\u542B\u307E\u308C\u308B\u9802\u70B9\n    vector<pair<ColumnIndex,\
    \ int>> vertex_index_; // `Columns` \u5185\u306B\u304A\u3051\u308B\u5404\u9802\
    \u70B9\u306E\u4F4D\u7F6E\u60C5\u5831\u300C\u5217 `first` \u306E\u6839\u304B\u3089\
    \ `second(0-index)` \u756A\u76EE\u306B\u3042\u308B\u300D\n    vector<int> offset_;\
    \ // 1\u5217\u306B\u4E26\u3079\u305F\u3068\u304D\u306E\u5404\u5217\u306E\u5148\
    \u982D\u306E\u4F4D\u7F6E\uFF080-index\uFF09\n\n    int dfs1_(Vertex now, Vertex\
    \ par){\n        int ret = 0;\n        for(Edge<CostType> e : G[now]){\n     \
    \       if(e.to == par) continue;\n            depth_[e.to] = depth_[now] + 1;\n\
    \            parent_vertex_[e.to] = now;\n            // m_parentedge[e.to] =\
    \ e.ID;\n            // child_vertex_[e.ID] = e.to;\n            ret += dfs1_(e.to,\
    \ now);\n        }\n        return subtree_size_[now] = ret + 1;\n    }\n\n  \
    \  void dfs2_(Vertex now, Vertex par, ColumnIndex col){\n        in_[now] = timer_++;\n\
    \n        // \u65B0\u3057\u3044\u5217\u306E\u5834\u5408\u306F\u5217\u3092\u5897\
    \u3084\u3059\n        if(column_.size() == col) column_.emplace_back(vector<Vertex>{});\n\
    \n        // \u5217\u306B\u9802\u70B9\u3092\u8FFD\u52A0\n        vertex_index_[now]\
    \ = {col, column_[col].size()};\n        column_[col].push_back(now);\n\n    \
    \    // Heavy\u306A\u8FBA\u3092\u63A2\u7D22\n        Edge<CostType> heavy;\n \
    \       int maxsubtree = 0;\n        for(Edge<CostType> e : G[now]){\n       \
    \     if(e.to == par) continue;\n            if(maxsubtree < subtree_size_[e.to]){\n\
    \                heavy = e;\n                maxsubtree = subtree_size_[e.to];\n\
    \            }\n        }\n\n        if(maxsubtree){\n            // Heavy\u306A\
    \u8FBA\u304C\u5B58\u5728\u3059\u308B\u5834\u5408\u3001\u4ECA\u306E\u5217\u306B\
    \u8FFD\u52A0\u3059\u308B\u5F62\u3067\u518D\u5E30\u3092\u884C\u3046\n         \
    \   dfs2_(heavy.to, now, col);\n        }\n\n        // Light\u306A\u8FBA\u306B\
    \u5BFE\u3057\u3066\u65B0\u3057\u3044\u5217\u3092\u751F\u3084\u3057\u3064\u3064\
    \u518D\u5E30\u3092\u884C\u3046\n        for(Edge<CostType> e : G[now]){\n    \
    \        if(e.to == par || e.to == heavy.to) continue;\n            dfs2_(e.to,\
    \ now, column_.size());\n        }\n\n        out_[now] = timer_++;\n    }\n\n\
    \    /**\n     * @brief \u9802\u70B9 `v` \u304C\u5B58\u5728\u3059\u308B\u5217\u306E\
    \u5148\u982D\u306E\u9802\u70B9\n     */\n    Vertex head_(Vertex v){\n       \
    \ auto [i, j] = vertex_index_[v];\n        return column_[i][0];\n    }\n\n  \
    \  public:\n    HeavyLightDecomposition(Graph<CostType> &G, Vertex Root = 0) :\
    \ G(G), root_(Root){\n        subtree_size_.resize(G.size(), 0);\n        depth_.resize(G.size(),\
    \ 0);\n        parent_vertex_.resize(G.size(), -1);\n        // m_parentedge.resize(G.size(),\
    \ -1);\n        // child_vertex_.resize(G.esize(), -1);\n        dfs1_(root_,\
    \ -1);\n        vertex_index_.resize(G.size());\n        in_.resize(G.size());\n\
    \        out_.resize(G.size());\n        dfs2_(root_, -1, 0);\n        offset_.resize(column_.size(),\
    \ 0);\n        for(int i = 1; i < column_.size(); ++i){\n            offset_[i]\
    \ = offset_[i - 1] + column_[i - 1].size();\n        }\n    }\n\n    /**\n   \
    \  * @brief \u6728\u306B\u542B\u307E\u308C\u308B\u5168\u9802\u70B9\u306B\u3064\
    \u3044\u3066\u3001HLD\u306E\u5217\u30921\u5217\u306B\u4E26\u3079\u305F\u5217 `L`\
    \ \u5185\u306B\u304A\u3051\u308B\u4F4D\u7F6E\u3092\u8FD4\u3059\u3002\n     * @return\
    \ vector<int> \u300C\u9802\u70B9 `i` \u304C `L_{ret[i]}` \u306B\u3042\u308B\u300D\
    \u3068\u3044\u3046\u60C5\u5831\n     */\n    vector<int> get_vertex_locations(){\n\
    \        vector<int> ret(G.size(), -1);\n        for(Vertex i = 0; i < G.size();\
    \ ++i){\n            ret[i] = offset_[vertex_index_[i].first] + vertex_index_[i].second;\n\
    \        }\n        return ret;\n    }\n\n    /**\n     * @brief \u9802\u70B9\
    \ `v` \u3068\u9802\u70B9 `u` \u306ELCA\u3092\u6C42\u3081\u308B\u3002\n     */\n\
    \    Vertex lca(Vertex v, Vertex u){\n        while(1){\n            Vertex hv\
    \ = head_(v), hu = head_(u);\n            if(depth_[hv] > depth_[hu]) swap(v,\
    \ u), swap(hv, hu);\n            if(hv == hu) return (depth_[v] < depth_[u] ?\
    \ v : u);\n            u = parent_vertex_[hu];\n        }\n    }\n\n    /**\n\
    \     * @brief \u9802\u70B9 `v` \u3068\u9802\u70B9 `u` \u3092\u7D50\u3076\u30D1\
    \u30B9\u306B\u8A72\u5F53\u3059\u308B\u533A\u9593\u3092\u8FD4\u3059\u3002\n   \
    \  * @param v \u9802\u70B9 `v`\n     * @param u \u9802\u70B9 `u` (option, default\
    \ = `root`)\n     * @return vector<pair<int, int>> \u533A\u9593\u306E\u4E00\u89A7\
    (\u534A\u958B\u533A\u9593, 0-index)\n     */\n    vector<pair<int, int>> path_query(Vertex\
    \ v, Vertex u = -1){\n        vector<pair<int, int>> ret;\n        if(u == -1)\
    \ u = root_;\n        while(1){\n            Vertex hv = head_(v), hu = head_(u);\n\
    \            if(depth_[hv] > depth_[hu]) swap(v, u), swap(hv, hu);\n         \
    \   if(hv == hu){\n                if(depth_[v] > depth_[u]) swap(v, u);\n   \
    \             auto [vc, vi] = vertex_index_[v];\n                auto [uc, ui]\
    \ = vertex_index_[u];\n                ret.push_back({offset_[vc] + vi, offset_[uc]\
    \ + ui + 1});\n                return ret;\n            }\n            auto [uc,\
    \ ui] = vertex_index_[u];\n            ret.push_back({offset_[uc], offset_[uc]\
    \ + ui + 1});\n            u = parent_vertex_[hu];\n        }\n    }\n\n    pair<int,\
    \ int> subtree_query(Vertex v){\n        return {in_[v], out_[v]};\n    }\n\n\
    \    void print_columns(){\n\n    }\n};\n"
  code: "/**\n * @file HeavyLightDecomposition.hpp\n * @author log K (lX57)\n * @brief\
    \ Heavy Light Decomposition - HL\u5206\u89E3\n * @version 3.0\n * @date 2023-10-04\n\
    \ */\n\n#include \"../Graph/GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct HeavyLightDecomposition{\n    using ColumnIndex = int;\n\n    private:\n\
    \    Vertex root_;\n    int timer_{0};\n\n    Graph<CostType> &G;\n    vector<int>\
    \ subtree_size_; // \u9802\u70B9 `i` \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\
    \u6728\u306E\u9802\u70B9\u6570\n    vector<int> depth_; // \u9802\u70B9 `i` \u306E\
    \u6839\u304B\u3089\u306E\u6DF1\u3055\n    vector<Vertex> parent_vertex_; // \u9802\
    \u70B9 `i` \u306E\u89AA\u306E\u9802\u70B9\uFF08\u6839\u306E\u5834\u5408\u306F\
    \ `-1` \uFF09\n    // vector<EdgeID> m_parentedge; // \u9802\u70B9 `i` \u3068\u305D\
    \u306E\u89AA\u3092\u7D50\u3076\u8FBA\u756A\u53F7\uFF08\u6839\u306E\u5834\u5408\
    \u306F `-1` \uFF09\n    vector<Vertex> child_vertex_; // \u8FBA `i` \u304C\u7D50\
    \u30762\u9802\u70B9\u306E\u3046\u3061\u3001\u5B50\u306E\u65B9\u306E\u9802\u70B9\
    \n    vector<int> in_, out_; // \u9802\u70B9 `i` \u306E\u884C\u304D\u304C\u3051\
    \ / \u5E30\u308A\u304C\u3051\u306E\u9806\u756A (Euler-Tour)\n\n    vector<vector<Vertex>>\
    \ column_; // \u5404\u5217\u306B\u542B\u307E\u308C\u308B\u9802\u70B9\n    vector<pair<ColumnIndex,\
    \ int>> vertex_index_; // `Columns` \u5185\u306B\u304A\u3051\u308B\u5404\u9802\
    \u70B9\u306E\u4F4D\u7F6E\u60C5\u5831\u300C\u5217 `first` \u306E\u6839\u304B\u3089\
    \ `second(0-index)` \u756A\u76EE\u306B\u3042\u308B\u300D\n    vector<int> offset_;\
    \ // 1\u5217\u306B\u4E26\u3079\u305F\u3068\u304D\u306E\u5404\u5217\u306E\u5148\
    \u982D\u306E\u4F4D\u7F6E\uFF080-index\uFF09\n\n    int dfs1_(Vertex now, Vertex\
    \ par){\n        int ret = 0;\n        for(Edge<CostType> e : G[now]){\n     \
    \       if(e.to == par) continue;\n            depth_[e.to] = depth_[now] + 1;\n\
    \            parent_vertex_[e.to] = now;\n            // m_parentedge[e.to] =\
    \ e.ID;\n            // child_vertex_[e.ID] = e.to;\n            ret += dfs1_(e.to,\
    \ now);\n        }\n        return subtree_size_[now] = ret + 1;\n    }\n\n  \
    \  void dfs2_(Vertex now, Vertex par, ColumnIndex col){\n        in_[now] = timer_++;\n\
    \n        // \u65B0\u3057\u3044\u5217\u306E\u5834\u5408\u306F\u5217\u3092\u5897\
    \u3084\u3059\n        if(column_.size() == col) column_.emplace_back(vector<Vertex>{});\n\
    \n        // \u5217\u306B\u9802\u70B9\u3092\u8FFD\u52A0\n        vertex_index_[now]\
    \ = {col, column_[col].size()};\n        column_[col].push_back(now);\n\n    \
    \    // Heavy\u306A\u8FBA\u3092\u63A2\u7D22\n        Edge<CostType> heavy;\n \
    \       int maxsubtree = 0;\n        for(Edge<CostType> e : G[now]){\n       \
    \     if(e.to == par) continue;\n            if(maxsubtree < subtree_size_[e.to]){\n\
    \                heavy = e;\n                maxsubtree = subtree_size_[e.to];\n\
    \            }\n        }\n\n        if(maxsubtree){\n            // Heavy\u306A\
    \u8FBA\u304C\u5B58\u5728\u3059\u308B\u5834\u5408\u3001\u4ECA\u306E\u5217\u306B\
    \u8FFD\u52A0\u3059\u308B\u5F62\u3067\u518D\u5E30\u3092\u884C\u3046\n         \
    \   dfs2_(heavy.to, now, col);\n        }\n\n        // Light\u306A\u8FBA\u306B\
    \u5BFE\u3057\u3066\u65B0\u3057\u3044\u5217\u3092\u751F\u3084\u3057\u3064\u3064\
    \u518D\u5E30\u3092\u884C\u3046\n        for(Edge<CostType> e : G[now]){\n    \
    \        if(e.to == par || e.to == heavy.to) continue;\n            dfs2_(e.to,\
    \ now, column_.size());\n        }\n\n        out_[now] = timer_++;\n    }\n\n\
    \    /**\n     * @brief \u9802\u70B9 `v` \u304C\u5B58\u5728\u3059\u308B\u5217\u306E\
    \u5148\u982D\u306E\u9802\u70B9\n     */\n    Vertex head_(Vertex v){\n       \
    \ auto [i, j] = vertex_index_[v];\n        return column_[i][0];\n    }\n\n  \
    \  public:\n    HeavyLightDecomposition(Graph<CostType> &G, Vertex Root = 0) :\
    \ G(G), root_(Root){\n        subtree_size_.resize(G.size(), 0);\n        depth_.resize(G.size(),\
    \ 0);\n        parent_vertex_.resize(G.size(), -1);\n        // m_parentedge.resize(G.size(),\
    \ -1);\n        // child_vertex_.resize(G.esize(), -1);\n        dfs1_(root_,\
    \ -1);\n        vertex_index_.resize(G.size());\n        in_.resize(G.size());\n\
    \        out_.resize(G.size());\n        dfs2_(root_, -1, 0);\n        offset_.resize(column_.size(),\
    \ 0);\n        for(int i = 1; i < column_.size(); ++i){\n            offset_[i]\
    \ = offset_[i - 1] + column_[i - 1].size();\n        }\n    }\n\n    /**\n   \
    \  * @brief \u6728\u306B\u542B\u307E\u308C\u308B\u5168\u9802\u70B9\u306B\u3064\
    \u3044\u3066\u3001HLD\u306E\u5217\u30921\u5217\u306B\u4E26\u3079\u305F\u5217 `L`\
    \ \u5185\u306B\u304A\u3051\u308B\u4F4D\u7F6E\u3092\u8FD4\u3059\u3002\n     * @return\
    \ vector<int> \u300C\u9802\u70B9 `i` \u304C `L_{ret[i]}` \u306B\u3042\u308B\u300D\
    \u3068\u3044\u3046\u60C5\u5831\n     */\n    vector<int> get_vertex_locations(){\n\
    \        vector<int> ret(G.size(), -1);\n        for(Vertex i = 0; i < G.size();\
    \ ++i){\n            ret[i] = offset_[vertex_index_[i].first] + vertex_index_[i].second;\n\
    \        }\n        return ret;\n    }\n\n    /**\n     * @brief \u9802\u70B9\
    \ `v` \u3068\u9802\u70B9 `u` \u306ELCA\u3092\u6C42\u3081\u308B\u3002\n     */\n\
    \    Vertex lca(Vertex v, Vertex u){\n        while(1){\n            Vertex hv\
    \ = head_(v), hu = head_(u);\n            if(depth_[hv] > depth_[hu]) swap(v,\
    \ u), swap(hv, hu);\n            if(hv == hu) return (depth_[v] < depth_[u] ?\
    \ v : u);\n            u = parent_vertex_[hu];\n        }\n    }\n\n    /**\n\
    \     * @brief \u9802\u70B9 `v` \u3068\u9802\u70B9 `u` \u3092\u7D50\u3076\u30D1\
    \u30B9\u306B\u8A72\u5F53\u3059\u308B\u533A\u9593\u3092\u8FD4\u3059\u3002\n   \
    \  * @param v \u9802\u70B9 `v`\n     * @param u \u9802\u70B9 `u` (option, default\
    \ = `root`)\n     * @return vector<pair<int, int>> \u533A\u9593\u306E\u4E00\u89A7\
    (\u534A\u958B\u533A\u9593, 0-index)\n     */\n    vector<pair<int, int>> path_query(Vertex\
    \ v, Vertex u = -1){\n        vector<pair<int, int>> ret;\n        if(u == -1)\
    \ u = root_;\n        while(1){\n            Vertex hv = head_(v), hu = head_(u);\n\
    \            if(depth_[hv] > depth_[hu]) swap(v, u), swap(hv, hu);\n         \
    \   if(hv == hu){\n                if(depth_[v] > depth_[u]) swap(v, u);\n   \
    \             auto [vc, vi] = vertex_index_[v];\n                auto [uc, ui]\
    \ = vertex_index_[u];\n                ret.push_back({offset_[vc] + vi, offset_[uc]\
    \ + ui + 1});\n                return ret;\n            }\n            auto [uc,\
    \ ui] = vertex_index_[u];\n            ret.push_back({offset_[uc], offset_[uc]\
    \ + ui + 1});\n            u = parent_vertex_[hu];\n        }\n    }\n\n    pair<int,\
    \ int> subtree_query(Vertex v){\n        return {in_[v], out_[v]};\n    }\n\n\
    \    void print_columns(){\n\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2024-04-29 19:12:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-LowestCommonAncestor-HLD.test.cpp
  - verify/LC-VertexAddPathSum-HLD.test.cpp
documentation_of: library/Tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/library/Tree/HeavyLightDecomposition.hpp
- /library/library/Tree/HeavyLightDecomposition.hpp.html
title: "Heavy Light Decomposition - HL\u5206\u89E3"
---
