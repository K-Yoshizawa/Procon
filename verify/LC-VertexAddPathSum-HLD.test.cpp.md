---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/SegmentTree.hpp
    title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/Tree/HeavyLightDecomposition.hpp
    title: "Heavy Light Decomposition - HL\u5206\u89E3"
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
  bundledCode: "#line 1 \"verify/LC-VertexAddPathSum-HLD.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 1 \"library/Tree/HeavyLightDecomposition.hpp\"\
    \n/**\n * @file HeavyLightDecomposition.hpp\n * @author log K (lX57)\n * @brief\
    \ Heavy Light Decomposition - HL\u5206\u89E3\n * @version 3.0\n * @date 2023-10-04\n\
    \ */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
    \ * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @version 3.0\n * @date 2024-01-09\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing Vertex = int;\n\ntemplate<typename CostType>\nstruct\
    \ Edge{\n    public:\n    Vertex from, to;\n    CostType cost;\n    int loc{-1},\
    \ id{-1};\n\n    Edge() = default;\n    Edge(Vertex from, Vertex to, CostType\
    \ cost) : from(from), to(to), cost(cost){}\n\n    operator int(){\n        return\
    \ to;\n    }\n};\n\ntemplate<typename CostType = int>\nstruct Graph{\n    private:\n\
    \    int m_vertex_size{0}, m_edge_size{0};\n    bool m_is_directed{false}, m_is_weighted{false};\n\
    \    vector<vector<Edge<CostType>>> m_adj;\n    vector<int> m_indegree;\n\n  \
    \  public:\n    CostType INF{numeric_limits<CostType>::max() >> 2};\n\n    Graph()\
    \ = default;\n\n    /**\n     * @brief `vertex_size` \u9802\u70B9 `0` \u8FBA\u306E\
    \u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\u3002\n     * @note `directed`\
    \ \u3092 `true` \u306B\u3059\u308B\u3068\u6709\u5411\u30B0\u30E9\u30D5\u306B\u306A\
    \u308B\u3002\n     * @param vertex_size \u9802\u70B9\u6570\n     * @param directed\
    \ \u6709\u5411\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\u304B (option,\
    \ default = `false`)\n     */\n    Graph(int vertex_size, bool directed = false)\
    \ : m_vertex_size(vertex_size), m_is_directed(directed){\n        m_adj.resize(vertex_size);\n\
    \        m_indegree.resize(vertex_size, 0);\n    }\n\n    /**\n     * @brief \u9802\
    \u70B9 `from` \u304B\u3089\u9802\u70B9 `to` \u306B\u8FBA\u3092\u5F35\u308B\u3002\
    \n     * @note `cost` \u3092\u6307\u5B9A\u3059\u308B\u3053\u3068\u3067\u91CD\u307F\
    \u3092\u3064\u3051\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\n     * @param\
    \ from \u9802\u70B9\u756A\u53F7\n     * @param to \u9802\u70B9\u756A\u53F7\n \
    \    * @param cost \u91CD\u307F (option, default = `1`)\n     */\n    void add(Vertex\
    \ from, Vertex to, CostType cost = 1){\n        assert(0 <= from and from < m_vertex_size);\n\
    \        assert(0 <= to and to < m_vertex_size);\n        m_is_weighted |= cost\
    \ > 1;\n        Edge<CostType> e1(from, to, cost);\n        e1.loc = m_adj[from].size();\n\
    \        e1.id = m_edge_size;\n        m_adj[from].push_back(e1);\n        ++m_edge_size;\n\
    \        if(m_is_directed){\n            ++m_indegree[to];\n            return;\n\
    \        }\n        Edge<CostType> e2(to, from, cost);\n        e2.loc = m_adj[to].size();\n\
    \        e2.id = e1.id;\n        m_adj[to].push_back(e2);\n    }\n\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u306B `edge_size` \u672C\u306E\u8FBA\u3092\u5165\
    \u529B\u3055\u305B\u308B\u3002\n     * @param edge_size \u5165\u529B\u3059\u308B\
    \u8FBA\u6570\n     * @param weighted \u91CD\u307F\u4ED8\u304D\u8FBA\u304B (option,\
    \ default = `false`)\n     * @param zero_index \u5165\u529B\u306E\u9802\u70B9\u756A\
    \u53F7\u304C 0-index \u304B (option, default = `false`)\n     */\n    void input(int\
    \ edge_size, bool weighted = false, bool zero_index = false){\n        m_is_weighted\
    \ = weighted;\n        for(int i = 0; i < edge_size; ++i){\n            Vertex\
    \ s, t; cin >> s >> t;\n            if(!zero_index) --s, --t;\n            CostType\
    \ c = 1;\n            if(weighted) cin >> c;\n            add(s, t, c);\n    \
    \    }\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\
    \u3092\u8FD4\u3059\u3002\n     * @return size_t \u9802\u70B9\u6570\n     */\n\
    \    size_t size(){\n        return m_vertex_size;\n    }\n\n    /**\n     * @brief\
    \ \u9802\u70B9 `v` \u306E\u51FA\u6B21\u6570\u3092\u8FD4\u3059\u3002\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7\n     * @return int \u9802\u70B9 `v` \u306E\u51FA\
    \u6B21\u6570\n     */\n    int outdegree(Vertex v){\n        return (int)m_adj.at(v).size();\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E\u5165\u6B21\u6570\u3092\
    \u8FD4\u3059\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return int\
    \ \u9802\u70B9 `v` \u306E\u5165\u6B21\u6570\n     */\n    int indegree(Vertex\
    \ v){\n        if(m_is_directed) return m_indegree.at(v);\n        else return\
    \ (int)m_adj.at(v).size();\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\
    \u304C\u6709\u5411\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\
    \u3002\n     */\n    bool is_directed(){\n        return m_is_directed;\n    }\n\
    \n    /**\n     * @brief \u30B0\u30E9\u30D5\u304C\u91CD\u307F\u4ED8\u304D\u304B\
    \u3069\u3046\u304B\u3092\u8FD4\u3059\u3002\n     */\n    bool is_weighted(){\n\
    \        return m_is_weighted;\n    }\n\n    vector<Vertex> source(){\n      \
    \  assert(m_is_directed);\n        vector<Vertex> ret;\n        for(int i = 0;\
    \ i < m_vertex_size; ++i){\n            if(indegree(i) == 0) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Vertex> sink(){\n       \
    \ vector<Vertex> ret;\n        for(int i = 0; i < m_vertex_size; ++i){\n     \
    \       if(outdegree(i) == 0) ret.push_back(i);\n        }\n        return ret;\n\
    \    }\n\n    vector<Vertex> leaf(){\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 1) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    /**\n     * @brief \u9802\u70B9\
    \ `v` \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\u3002\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7\n     * @return vector<Edge<CostType>>& \u9802\u70B9\
    \ `v` \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\n     */\n    vector<Edge<CostType>>\
    \ &get_adj(Vertex v){\n        return m_adj.at(v);\n    }\n\n    /**\n     * @brief\
    \ \u8FBA\u306E\u5411\u304D\u3092\u3059\u3079\u3066\u9006\u306B\u3057\u305F\u30B0\
    \u30E9\u30D5\u3092\u8FD4\u3059\u3002\n     * @attention \u6709\u5411\u30B0\u30E9\
    \u30D5\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u4EF6\u3068\u3059\u308B\u3002\
    \n     * @return Graph<CostType> \u9006\u8FBA\u30B0\u30E9\u30D5\n     */\n   \
    \ Graph<CostType> reverse(){\n        assert(m_is_directed);\n        Graph ret(m_vertex_size,\
    \ true);\n        for(auto es : m_adj){\n            for(auto e : es){\n     \
    \           ret.add(e.to, e.from, e.cost);\n            }\n        }\n       \
    \ return ret;\n    }\n\n    /**\n     * @brief \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u3057\u305F\u9802\u70B9\u5217\u3092\u8FD4\u3059\u3002\n   \
    \  * @attention \u6709\u5411\u30B0\u30E9\u30D5\u3067\u3042\u308B\u3053\u3068\u3092\
    \u8981\u4EF6\u3068\u3059\u308B\u3002\n     * @return vector<Vertex> \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3057\u305F\u9802\u70B9\u5217\n   \
    \  */\n    vector<Vertex> topological_sort(){\n        assert(m_is_directed);\n\
    \        vector<Vertex> ret;\n        queue<Vertex> que;\n        vector<int>\
    \ cnt(m_vertex_size, 0);\n        for(auto v : source()) que.push(v);\n      \
    \  while(que.size()){\n            Vertex v = que.front(); que.pop();\n      \
    \      ret.push_back(v);\n            for(int u : m_adj[v]){\n               \
    \ if(++cnt[u] == indegree(u)) que.push(u);\n            }\n        }\n       \
    \ return ret;\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u304B\u3089\u8FBA\
    \u96C6\u5408\u3092\u4F5C\u6210\u3059\u308B\u3002\n     * @note \u8FBA\u96C6\u5408\
    \u306F\u91CD\u307F\u3067\u6607\u9806\u30BD\u30FC\u30C8\u3055\u308C\u305F\u72B6\
    \u614B\u3067\u8FD4\u3055\u308C\u308B\u3002\n     * @return vector<Edge<CostType>>\
    \ \u8FBA\u96C6\u5408\n     */\n    vector<Edge<CostType>> edge_set(){\n      \
    \  vector<Edge<CostType>> ret;\n        vector<int> es(m_edge_size, 0);\n    \
    \    for(int i = 0; i < m_vertex_size; ++i){\n            for(auto e : m_adj[i]){\n\
    \                if(es[e.id]) continue;\n                es[e.id] = 1;\n     \
    \           ret.push_back(e);\n            }\n        }\n        sort(ret.begin(),\
    \ ret.end(), [&](Edge<CostType> &l, Edge<CostType> &r){\n            return l.cost\
    \ < r.cost;\n        });\n        return ret;\n    }\n\n    vector<vector<CostType>>\
    \ matrix(){\n        int n = m_vertex_size;\n        vector<vector<CostType>>\
    \ ret(n, vector<CostType>(n, INF));\n        for(int i = 0; i < n; ++i) ret[i][i]\
    \ = 0;\n        for(int v = 0; v < n; ++v){\n            for(auto &e : m_adj[v]){\n\
    \                ret[v][e.to] = e.cost;\n            }\n        }\n        return\
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
    \ = int;\n\n    private:\n    Vertex m_root;\n    int m_timer{0};\n\n    Graph<CostType>\
    \ &G;\n    vector<int> m_subtreesize; // \u9802\u70B9 `i` \u3092\u6839\u3068\u3059\
    \u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\n    vector<int> m_depth; //\
    \ \u9802\u70B9 `i` \u306E\u6839\u304B\u3089\u306E\u6DF1\u3055\n    vector<Vertex>\
    \ m_parentvertex; // \u9802\u70B9 `i` \u306E\u89AA\u306E\u9802\u70B9\uFF08\u6839\
    \u306E\u5834\u5408\u306F `-1` \uFF09\n    // vector<EdgeID> m_parentedge; // \u9802\
    \u70B9 `i` \u3068\u305D\u306E\u89AA\u3092\u7D50\u3076\u8FBA\u756A\u53F7\uFF08\u6839\
    \u306E\u5834\u5408\u306F `-1` \uFF09\n    vector<Vertex> m_childvertex; // \u8FBA\
    \ `i` \u304C\u7D50\u30762\u9802\u70B9\u306E\u3046\u3061\u3001\u5B50\u306E\u65B9\
    \u306E\u9802\u70B9\n    vector<int> m_in, m_out; // \u9802\u70B9 `i` \u306E\u884C\
    \u304D\u304C\u3051 / \u5E30\u308A\u304C\u3051\u306E\u9806\u756A (Euler-Tour)\n\
    \n    vector<vector<Vertex>> m_column; // \u5404\u5217\u306B\u542B\u307E\u308C\
    \u308B\u9802\u70B9\n    vector<pair<ColumnIndex, int>> m_vertexindex; // `Columns`\
    \ \u5185\u306B\u304A\u3051\u308B\u5404\u9802\u70B9\u306E\u4F4D\u7F6E\u60C5\u5831\
    \u300C\u5217 `first` \u306E\u6839\u304B\u3089 `second(0-index)` \u756A\u76EE\u306B\
    \u3042\u308B\u300D\n    vector<int> m_offset; // 1\u5217\u306B\u4E26\u3079\u305F\
    \u3068\u304D\u306E\u5404\u5217\u306E\u5148\u982D\u306E\u4F4D\u7F6E\uFF080-index\uFF09\
    \n\n    int m_dfs1(Vertex now, Vertex par){\n        int ret = 0;\n        for(Edge<CostType>\
    \ e : G[now]){\n            if(e.to == par) continue;\n            m_depth[e.to]\
    \ = m_depth[now] + 1;\n            m_parentvertex[e.to] = now;\n            //\
    \ m_parentedge[e.to] = e.ID;\n            // m_childvertex[e.ID] = e.to;\n   \
    \         ret += m_dfs1(e.to, now);\n        }\n        return m_subtreesize[now]\
    \ = ret + 1;\n    }\n\n    void m_dfs2(Vertex now, Vertex par, ColumnIndex col){\n\
    \        m_in[now] = m_timer++;\n\n        // \u65B0\u3057\u3044\u5217\u306E\u5834\
    \u5408\u306F\u5217\u3092\u5897\u3084\u3059\n        if(m_column.size() == col)\
    \ m_column.emplace_back(vector<Vertex>{});\n\n        // \u5217\u306B\u9802\u70B9\
    \u3092\u8FFD\u52A0\n        m_vertexindex[now] = {col, m_column[col].size()};\n\
    \        m_column[col].push_back(now);\n\n        // Heavy\u306A\u8FBA\u3092\u63A2\
    \u7D22\n        Edge<CostType> heavy;\n        int maxsubtree = 0;\n        for(Edge<CostType>\
    \ e : G[now]){\n            if(e.to == par) continue;\n            if(maxsubtree\
    \ < m_subtreesize[e.to]){\n                heavy = e;\n                maxsubtree\
    \ = m_subtreesize[e.to];\n            }\n        }\n\n        if(maxsubtree){\n\
    \            // Heavy\u306A\u8FBA\u304C\u5B58\u5728\u3059\u308B\u5834\u5408\u3001\
    \u4ECA\u306E\u5217\u306B\u8FFD\u52A0\u3059\u308B\u5F62\u3067\u518D\u5E30\u3092\
    \u884C\u3046\n            m_dfs2(heavy.to, now, col);\n        }\n\n        //\
    \ Light\u306A\u8FBA\u306B\u5BFE\u3057\u3066\u65B0\u3057\u3044\u5217\u3092\u751F\
    \u3084\u3057\u3064\u3064\u518D\u5E30\u3092\u884C\u3046\n        for(Edge<CostType>\
    \ e : G[now]){\n            if(e.to == par || e.to == heavy.to) continue;\n  \
    \          m_dfs2(e.to, now, m_column.size());\n        }\n\n        m_out[now]\
    \ = m_timer++;\n    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u304C\u5B58\u5728\
    \u3059\u308B\u5217\u306E\u5148\u982D\u306E\u9802\u70B9\n     */\n    Vertex m_head(Vertex\
    \ v){\n        auto [i, j] = m_vertexindex[v];\n        return m_column[i][0];\n\
    \    }\n\n    public:\n    HeavyLightDecomposition(Graph<CostType> &G, Vertex\
    \ Root = 0) : G(G), m_root(Root){\n        m_subtreesize.resize(G.size(), 0);\n\
    \        m_depth.resize(G.size(), 0);\n        m_parentvertex.resize(G.size(),\
    \ -1);\n        // m_parentedge.resize(G.size(), -1);\n        // m_childvertex.resize(G.esize(),\
    \ -1);\n        m_dfs1(m_root, -1);\n        m_vertexindex.resize(G.size());\n\
    \        m_in.resize(G.size());\n        m_out.resize(G.size());\n        m_dfs2(m_root,\
    \ -1, 0);\n        m_offset.resize(m_column.size(), 0);\n        for(int i = 1;\
    \ i < m_column.size(); ++i){\n            m_offset[i] = m_offset[i - 1] + m_column[i\
    \ - 1].size();\n        }\n    }\n\n    /**\n     * @brief \u6728\u306B\u542B\u307E\
    \u308C\u308B\u5168\u9802\u70B9\u306B\u3064\u3044\u3066\u3001HLD\u306E\u5217\u3092\
    1\u5217\u306B\u4E26\u3079\u305F\u5217 `L` \u5185\u306B\u304A\u3051\u308B\u4F4D\
    \u7F6E\u3092\u8FD4\u3059\u3002\n     * @return vector<int> \u300C\u9802\u70B9\
    \ `i` \u304C `L_{ret[i]}` \u306B\u3042\u308B\u300D\u3068\u3044\u3046\u60C5\u5831\
    \n     */\n    vector<int> get_vertex_locations(){\n        vector<int> ret(G.size(),\
    \ -1);\n        for(Vertex i = 0; i < G.size(); ++i){\n            ret[i] = m_offset[m_vertexindex[i].first]\
    \ + m_vertexindex[i].second;\n        }\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u9802\u70B9 `v` \u3068\u9802\u70B9 `u` \u306ELCA\u3092\u6C42\u3081\
    \u308B\u3002\n     */\n    Vertex lca(Vertex v, Vertex u){\n        while(1){\n\
    \            Vertex hv = m_head(v), hu = m_head(u);\n            if(m_depth[hv]\
    \ > m_depth[hu]) swap(v, u), swap(hv, hu);\n            if(hv == hu) return (m_depth[v]\
    \ < m_depth[u] ? v : u);\n            u = m_parentvertex[hu];\n        }\n   \
    \ }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u3068\u9802\u70B9 `u` \u3092\u7D50\
    \u3076\u30D1\u30B9\u306B\u8A72\u5F53\u3059\u308B\u533A\u9593\u3092\u8FD4\u3059\
    \u3002\n     * @param v \u9802\u70B9 `v`\n     * @param u \u9802\u70B9 `u` (option,\
    \ default = `root`)\n     * @return vector<pair<int, int>> \u533A\u9593\u306E\u4E00\
    \u89A7(\u534A\u958B\u533A\u9593, 0-index)\n     */\n    vector<pair<int, int>>\
    \ path_query(Vertex v, Vertex u = -1){\n        vector<pair<int, int>> ret;\n\
    \        if(u == -1) u = m_root;\n        while(1){\n            Vertex hv = m_head(v),\
    \ hu = m_head(u);\n            if(m_depth[hv] > m_depth[hu]) swap(v, u), swap(hv,\
    \ hu);\n            if(hv == hu){\n                if(m_depth[v] > m_depth[u])\
    \ swap(v, u);\n                auto [vc, vi] = m_vertexindex[v];\n           \
    \     auto [uc, ui] = m_vertexindex[u];\n                ret.push_back({m_offset[vc]\
    \ + vi, m_offset[uc] + ui + 1});\n                return ret;\n            }\n\
    \            auto [uc, ui] = m_vertexindex[u];\n            ret.push_back({m_offset[uc],\
    \ m_offset[uc] + ui + 1});\n            u = m_parentvertex[hu];\n        }\n \
    \   }\n\n    pair<int, int> subtree_query(Vertex v){\n        return {m_in[v],\
    \ m_out[v]};\n    }\n\n    void print_columns(){\n\n    }\n};\n#line 1 \"library/DataStructure/SegmentTree.hpp\"\
    \n/**\n * @file SegmentTree.hpp\n * @author log K (lX57)\n * @brief Segment Tree\
    \ - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @version 2.2\n * @date 2023-10-02\n\
    \ */\n\n#line 10 \"library/DataStructure/SegmentTree.hpp\"\nusing namespace std;\n\
    \ntemplate<typename Monoid>\nstruct SegmentTree{\n    private:\n    using F =\
    \ function<Monoid(Monoid, Monoid)>;\n\n    int m_size, m_offset, m_zeroindex;\n\
    \    vector<Monoid> m_data;\n    const F f;\n    const Monoid m_m1;\n\n    inline\
    \ void m_check(int x){\n        assert(1 <= x && x <= m_size);\n    }\n\n    public:\n\
    \    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\
    \u6570 `Size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Size \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\n     * @param Merge \u533A\
    \u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param Monoid_Identity\
    \ \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\
    \u3057\u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(int\
    \ Size, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\n    :\
    \ f(Merge), m_m1(Monoid_Identity), m_zeroindex(ZeroIndex){\n        m_size = 1;\n\
    \        while(m_size < Size) m_size <<= 1;\n        m_offset = m_size - 1;\n\
    \        m_data.resize(2 * m_size, m_m1);\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention\
    \ \u5FC5\u305A `set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\
    \u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n     */\n    void build(){\n\
    \        for(int i = m_offset; i >= 1; --i){\n            m_data[i] = f(m_data[i\
    \ * 2 + 0], m_data[i * 2 + 1]);\n        }\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\
    \u308B\u3002\n     * @param Index \u4EE3\u5165\u5148\u306E\u8981\u7D20\u756A\u53F7\
    \ (default = 1-index)\n     * @param Value \u4EE3\u5165\u3059\u308B\u5024\n  \
    \   */\n    void set(int Index, Monoid Value){\n        m_check(Index + m_zeroindex);\n\
    \        m_data[m_offset + Index + m_zeroindex] = Value;\n    }\n\n    /**\n \
    \    * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u914D\u5217 `Init_Data`\
    \ \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Init_Data \u521D\u671F\
    \u30C7\u30FC\u30BF\u306E\u914D\u5217\n     * @param Merge \u533A\u9593\u53D6\u5F97\
    \u3092\u884C\u3046\u6F14\u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\
    \u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\
    \u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(vector<Monoid>\
    \ &Init_Data, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\n\
    \    : f(Merge), m_m1(Monoid_Identity), m_zeroindex(ZeroIndex){\n        m_size\
    \ = 1;\n        while(m_size < (int)Init_Data.size()) m_size <<= 1;\n        m_offset\
    \ = m_size - 1;\n        m_data.resize(2 * m_size, m_m1);\n        for(int i =\
    \ 0; i < (int)Init_Data.size(); ++i){\n            m_data[m_size + i] = Init_Data[i];\n\
    \        }\n        build();\n    }\n\n    /**\n     * @brief \u4E00\u70B9\u66F4\
    \u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\n     * @param Index\
    \ \u66F4\u65B0\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     *\
    \ @param Value \u66F4\u65B0\u3059\u308B\u5024\n     */\n    void update(int Index,\
    \ Monoid Value){\n        m_check(Index + m_zeroindex);\n        int k = m_offset\
    \ + Index + m_zeroindex;\n        m_data[k] = Value;\n        while(k >>= 1){\n\
    \            m_data[k] = f(m_data[2 * k], m_data[2 * k + 1]);\n        }\n   \
    \ }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[Left, Right)` \u306B\u5BFE\
    \u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\u884C\u3046\u3002\
    \n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n     * @param\
    \ Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return Monoid \u53D6\
    \u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid query(int Left, int Right){\n\
    \        if(Left == Right) return m_m1;\n        m_check(Left + m_zeroindex);\n\
    \        m_check(Right + m_zeroindex - 1);\n        int l = Left + m_zeroindex\
    \ + m_offset, r = Right + m_zeroindex + m_offset;\n        Monoid al = m_m1, ar\
    \ = m_m1;\n        while(l < r){\n            if(l & 1) al = f(al, m_data[l++]);\n\
    \            if(r & 1) ar = f(m_data[--r], ar);\n            l >>= 1, r >>= 1;\n\
    \        }\n        return f(al, ar);\n    }\n\n    /**\n     * @brief \u8981\u7D20\
    \u756A\u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\u3002\n    \
    \ * @param k \u53D6\u5F97\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n\
    \     * @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid\
    \ get(int k){\n        m_check(k + m_zeroindex);\n        return m_data[m_offset\
    \ + k + m_zeroindex];\n    }\n\n    Monoid operator[](const int &k){\n       \
    \ return get(k);\n    }\n};\n#line 5 \"verify/LC-VertexAddPathSum-HLD.test.cpp\"\
    \n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n \
    \   for(auto &ai : a) cin >> ai;\n    Graph<long long> G(N);\n    G.input(N -\
    \ 1, false, true);\n\n    HeavyLightDecomposition<long long> hld(G);\n    vector<long\
    \ long> init(N * 2);\n    auto loc = hld.get_vertex_locations();\n    for(int\
    \ i = 0; i < N; ++i){\n        init[loc[i]] = a[i];\n    }\n    SegmentTree<long\
    \ long> seg(init,\n        [&](long long l, long long r){return l + r;},\n   \
    \     0, true);\n\n    while(Q--){\n        int query; cin >> query;\n       \
    \ if(query == 0){\n            long long p, x; cin >> p >> x;\n            seg.update(loc[p],\
    \ seg[loc[p]] + x);\n        }\n        else{\n            int u, v; cin >> u\
    \ >> v;\n            long long ans = 0;\n            for(auto [l, r] : hld.path_query(u,\
    \ v)){\n                ans += seg.query(l, r);\n            }\n            cout\
    \ << ans << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../library/Tree/HeavyLightDecomposition.hpp\"\n#include \"../library/DataStructure/SegmentTree.hpp\"\
    \n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n \
    \   for(auto &ai : a) cin >> ai;\n    Graph<long long> G(N);\n    G.input(N -\
    \ 1, false, true);\n\n    HeavyLightDecomposition<long long> hld(G);\n    vector<long\
    \ long> init(N * 2);\n    auto loc = hld.get_vertex_locations();\n    for(int\
    \ i = 0; i < N; ++i){\n        init[loc[i]] = a[i];\n    }\n    SegmentTree<long\
    \ long> seg(init,\n        [&](long long l, long long r){return l + r;},\n   \
    \     0, true);\n\n    while(Q--){\n        int query; cin >> query;\n       \
    \ if(query == 0){\n            long long p, x; cin >> p >> x;\n            seg.update(loc[p],\
    \ seg[loc[p]] + x);\n        }\n        else{\n            int u, v; cin >> u\
    \ >> v;\n            long long ans = 0;\n            for(auto [l, r] : hld.path_query(u,\
    \ v)){\n                ans += seg.query(l, r);\n            }\n            cout\
    \ << ans << endl;\n        }\n    }\n}"
  dependsOn:
  - library/Tree/HeavyLightDecomposition.hpp
  - library/Graph/GraphTemplate.hpp
  - library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify/LC-VertexAddPathSum-HLD.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 00:45:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-VertexAddPathSum-HLD.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-VertexAddPathSum-HLD.test.cpp
- /verify/verify/LC-VertexAddPathSum-HLD.test.cpp.html
title: verify/LC-VertexAddPathSum-HLD.test.cpp
---
