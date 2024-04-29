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
    \    private:\n    int m_vertex_size{0}, m_edge_size{0};\n    bool m_is_directed{false},\
    \ m_is_weighted{false};\n    vector<vector<Edge<CostType>>> m_adj;\n    vector<int>\
    \ m_indegree;\n\n    public:\n    CostType INF{numeric_limits<CostType>::max()\
    \ >> 2};\n\n    Graph() = default;\n\n    /**\n     * @brief `vertex_size` \u9802\
    \u70B9 `0` \u8FBA\u306E\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\u3002\n\
    \     * @note `directed` \u3092 `true` \u306B\u3059\u308B\u3068\u6709\u5411\u30B0\
    \u30E9\u30D5\u306B\u306A\u308B\u3002\n     * @param vertex_size \u9802\u70B9\u6570\
    \n     * @param directed \u6709\u5411\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\
    \u308B\u304B (option, default = `false`)\n     */\n    Graph(int vertex_size,\
    \ bool directed = false) : m_vertex_size(vertex_size), m_is_directed(directed){\n\
    \        m_adj.resize(vertex_size);\n        m_indegree.resize(vertex_size, 0);\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `from` \u304B\u3089\u9802\u70B9\
    \ `to` \u306B\u8FBA\u3092\u5F35\u308B\u3002\n     * @note `cost` \u3092\u6307\u5B9A\
    \u3059\u308B\u3053\u3068\u3067\u91CD\u307F\u3092\u3064\u3051\u308B\u3053\u3068\
    \u304C\u3067\u304D\u308B\u3002\n     * @param from \u9802\u70B9\u756A\u53F7\n\
    \     * @param to \u9802\u70B9\u756A\u53F7\n     * @param cost \u91CD\u307F (option,\
    \ default = `1`)\n     */\n    void add(Vertex from, Vertex to, CostType cost\
    \ = 1){\n        assert(0 <= from and from < m_vertex_size);\n        assert(0\
    \ <= to and to < m_vertex_size);\n        m_is_weighted |= cost > 1;\n       \
    \ Edge<CostType> e1(from, to, cost);\n        e1.loc = m_adj[from].size();\n \
    \       e1.id = m_edge_size;\n        m_adj[from].push_back(e1);\n        ++m_edge_size;\n\
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
    \ get_adj(v);\n    }\n};\n#line 9 \"library/Tree/EulerTour.hpp\"\n\ntemplate<typename\
    \ CostType>\nstruct EulerTour{\n    private:\n    Graph<CostType> &G;\n    vector<int>\
    \ m_in, m_out;\n\n    void m_dfs(Vertex v, Vertex p, int &t){\n        m_in[v]\
    \ = t++;\n        for(auto &e : G[v]){\n            if(e.to == p) continue;\n\
    \            m_dfs(e.to, v, t);\n        }\n        m_out[v] = t++;\n    }\n\n\
    \    public:\n    /**\n     * @brief Construct a new Euler Tour object\n     *\
    \ @param G \u6728\n     * @param Root \u6839\u306E\u9802\u70B9\u756A\u53F7(0-index)\n\
    \     * @param Offset \u30BF\u30A4\u30E0\u30B9\u30BF\u30F3\u30D7\u306E\u521D\u671F\
    \u5024\n     */\n    EulerTour(Graph<CostType> &G, Vertex Root = 0, int Offset\
    \ = 0) : G(G){\n        m_in.resize(G.size());\n        m_out.resize(G.size());\n\
    \        m_dfs(Root, -1, Offset);\n    }\n\n    int in(Vertex v){\n        assert(0\
    \ <= v && v < G.size());\n        return m_in[v];\n    }\n\n    int out(Vertex\
    \ v){\n        assert(0 <= v && v < G.size());\n        return m_out[v];\n   \
    \ }\n\n    pair<vector<int>, vector<int>> get(){\n        return make_pair(m_in,\
    \ m_out);\n    }\n\n    pair<int, int> operator[](Vertex v){\n        return make_pair(in(v),\
    \ out(v));\n    }\n};\n#line 1 \"library/Tree/LowestCommonAncestor.hpp\"\n/**\n\
    \ * @file LowestCommonAncestor.hpp\n * @brief Lowest Common Ancestor - \u6700\u5C0F\
    \u5171\u901A\u7956\u5148\n * @version 3.0\n * @date 2024-02-11\n */\n\n#line 9\
    \ \"library/Tree/LowestCommonAncestor.hpp\"\n\ntemplate<typename CostType>\nstruct\
    \ LowestCommonAncestor{\n    private:\n    Graph<CostType> &G;\n    int m_height;\n\
    \    vector<int> m_depth;\n    vector<vector<Vertex>> m_parent;\n    vector<CostType>\
    \ m_cum;\n\n    void m_dfs(Vertex v, Vertex p, int d){\n        m_parent[0][v]\
    \ = p;\n        m_depth[v] = d;\n        for(auto &e : G[v]){\n            if(e.to\
    \ != p){\n                m_cum[e.to] = m_cum[v] + e.cost;\n                m_dfs(e.to,\
    \ v, d + 1);\n            }\n        }\n    }\n\n    public:\n    /**\n     *\
    \ @brief Construct a new Lowest Common Ancestor object\n     * @param G \u6728\
    \n     * @param Root \u6839\u306E\u9802\u70B9\u756A\u53F7(0-index)\n     */\n\
    \    LowestCommonAncestor(Graph<CostType> &G, Vertex Root = 0) : G(G), m_height(32){\n\
    \        m_depth.resize(G.size());\n        m_parent.resize(m_height, vector<Vertex>(G.size(),\
    \ -1));\n        m_cum.resize(G.size(), 0);\n        m_dfs(Root, -1, 0);\n   \
    \     for(int k = 0; k + 1 < m_height; ++k){\n            for(Vertex v = 0; v\
    \ < G.size(); ++v){\n                if(m_parent[k][v] < 0) m_parent[k + 1][v]\
    \ = -1;\n                else m_parent[k + 1][v] = m_parent[k][m_parent[k][v]];\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief \u9802\u70B9 `u` \u3068\
    \u9802\u70B9 `v` \u306E LCA \u3092\u6C42\u3081\u308B\u3002\n     * @note \u9802\
    \u70B9\u756A\u53F7\u306F 0-index\n     * @return Vertex LCA\u306E\u9802\u70B9\u756A\
    \u53F7\n     */\n    Vertex get(Vertex u, Vertex v){\n        if(m_depth[u] >\
    \ m_depth[v]) swap(u, v);\n        for(int k = 0; k < m_height; ++k){\n      \
    \      if((m_depth[v] - m_depth[u]) >> k & 1){\n                v = m_parent[k][v];\n\
    \            }\n        }\n        if(u == v) return u;\n        for(int k = m_height\
    \ - 1; k >= 0; --k){\n            if(m_parent[k][u] != m_parent[k][v]){\n    \
    \            u = m_parent[k][u];\n                v = m_parent[k][v];\n      \
    \      }\n        }\n        return m_parent[0][u];\n    }\n\n    /**\n     *\
    \ @brief \u9802\u70B9 `u` \u3068\u9802\u70B9 `v` \u9593\u306E\u30B3\u30B9\u30C8\
    \u3092\u6C42\u3081\u308B\u3002\n     * @note \u9802\u70B9\u756A\u53F7\u306F 0-index\n\
    \     * @return CostType \u30B3\u30B9\u30C8\n     */\n    CostType dist(Vertex\
    \ u, Vertex v){\n        return m_cum[u] + m_cum[v] - m_cum[get(u, v)] * 2;\n\
    \    }\n};\n#line 1 \"library/DataStructure/SegmentTree.hpp\"\n/**\n * @file SegmentTree.hpp\n\
    \ * @author log K (lX57)\n * @brief Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n * @version 2.2\n * @date 2023-10-02\n */\n\n#line 10 \"library/DataStructure/SegmentTree.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Monoid>\nstruct SegmentTree{\n   \
    \ private:\n    using F = function<Monoid(Monoid, Monoid)>;\n\n    int m_size,\
    \ m_offset, m_zeroindex;\n    vector<Monoid> m_data;\n    const F f;\n    const\
    \ Monoid m_m1;\n\n    inline void m_check(int x){\n        assert(1 <= x && x\
    \ <= m_size);\n    }\n\n    public:\n    /**\n     * @brief \u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\u3092\u8981\u7D20\u6570 `Size` \u3067\u521D\u671F\u5316\u3059\
    \u308B\u3002\n     * @param Size \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\
    \u7D20\u6570\n     * @param Merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\
    \u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B (default = `false`)\n     */\n    SegmentTree(int Size, F Merge, const\
    \ Monoid &Monoid_Identity, bool ZeroIndex = false)\n    : f(Merge), m_m1(Monoid_Identity),\
    \ m_zeroindex(ZeroIndex){\n        m_size = 1;\n        while(m_size < Size) m_size\
    \ <<= 1;\n        m_offset = m_size - 1;\n        m_data.resize(2 * m_size, m_m1);\n\
    \    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\
    \u7BC9\u3059\u308B\u3002\n     * @attention \u5FC5\u305A `set()` \u3067\u521D\u671F\
    \u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\u3089\u547C\u3073\u51FA\u3059\u3053\
    \u3068\uFF01\n     */\n    void build(){\n        for(int i = m_offset; i >= 1;\
    \ --i){\n            m_data[i] = f(m_data[i * 2 + 0], m_data[i * 2 + 1]);\n  \
    \      }\n    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u306E\u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\u308B\u3002\n     * @param Index\
    \ \u4EE3\u5165\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     *\
    \ @param Value \u4EE3\u5165\u3059\u308B\u5024\n     */\n    void set(int Index,\
    \ Monoid Value){\n        m_check(Index + m_zeroindex);\n        m_data[m_offset\
    \ + Index + m_zeroindex] = Value;\n    }\n\n    /**\n     * @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u3092\u914D\u5217 `Init_Data` \u3067\u521D\u671F\u5316\
    \u3059\u308B\u3002\n     * @param Init_Data \u521D\u671F\u30C7\u30FC\u30BF\u306E\
    \u914D\u5217\n     * @param Merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\
    \u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B (default = `false`)\n     */\n    SegmentTree(vector<Monoid> &Init_Data,\
    \ F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\n    : f(Merge),\
    \ m_m1(Monoid_Identity), m_zeroindex(ZeroIndex){\n        m_size = 1;\n      \
    \  while(m_size < (int)Init_Data.size()) m_size <<= 1;\n        m_offset = m_size\
    \ - 1;\n        m_data.resize(2 * m_size, m_m1);\n        for(int i = 0; i < (int)Init_Data.size();\
    \ ++i){\n            m_data[m_size + i] = Init_Data[i];\n        }\n        build();\n\
    \    }\n\n    /**\n     * @brief \u4E00\u70B9\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\
    \u51E6\u7406\u3059\u308B\u3002\n     * @param Index \u66F4\u65B0\u5148\u306E\u8981\
    \u7D20\u756A\u53F7 (default = 1-index)\n     * @param Value \u66F4\u65B0\u3059\
    \u308B\u5024\n     */\n    void update(int Index, Monoid Value){\n        m_check(Index\
    \ + m_zeroindex);\n        int k = m_offset + Index + m_zeroindex;\n        m_data[k]\
    \ = Value;\n        while(k >>= 1){\n            m_data[k] = f(m_data[2 * k],\
    \ m_data[2 * k + 1]);\n        }\n    }\n\n    /**\n     * @brief \u534A\u958B\
    \u533A\u9593 `[Left, Right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\
    \u30A8\u30EA\u3092\u884C\u3046\u3002\n     * @param Left \u534A\u958B\u533A\u9593\
    \u306E\u5DE6\u7AEF\n     * @param Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\
    \n     * @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid\
    \ query(int Left, int Right){\n        if(Left == Right) return m_m1;\n      \
    \  m_check(Left + m_zeroindex);\n        m_check(Right + m_zeroindex - 1);\n \
    \       int l = Left + m_zeroindex + m_offset, r = Right + m_zeroindex + m_offset;\n\
    \        Monoid al = m_m1, ar = m_m1;\n        while(l < r){\n            if(l\
    \ & 1) al = f(al, m_data[l++]);\n            if(r & 1) ar = f(m_data[--r], ar);\n\
    \            l >>= 1, r >>= 1;\n        }\n        return f(al, ar);\n    }\n\n\
    \    /**\n     * @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\u3059\u308B\u3002\n     * @param k \u53D6\u5F97\u5148\u306E\u8981\u7D20\
    \u756A\u53F7 (default = 1-index)\n     * @return Monoid \u53D6\u5F97\u3057\u305F\
    \u7D50\u679C\n     */\n    Monoid get(int k){\n        m_check(k + m_zeroindex);\n\
    \        return m_data[m_offset + k + m_zeroindex];\n    }\n\n    Monoid operator[](const\
    \ int &k){\n        return get(k);\n    }\n};\n#line 6 \"verify/LC-VertexAddPathSum-ET.test.cpp\"\
    \n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n \
    \   for(auto &ai : a) cin >> ai;\n    Graph<long long> G(N);\n    G.input(N -\
    \ 1, false, true);\n\n    EulerTour et(G);\n    auto [in, out] = et.get();\n \
    \   vector<long long> b(N * 2, 0);\n    for(int i = 0; i < N; ++i){\n        b[in[i]]\
    \ = a[i], b[out[i]] = -a[i];\n    }\n    LowestCommonAncestor lca(G);\n    SegmentTree<long\
    \ long> seg(b, [&](long long l, long long r){return l + r;}, 0LL, true);\n\n \
    \   while(Q--){\n        int query; cin >> query;\n        if(query == 0){\n \
    \           long long p, x; cin >> p >> x;\n            long long y = a[p] + x;\n\
    \            a[p] += x;\n            seg.update(in[p], y);\n            seg.update(out[p],\
    \ -y);\n        }\n        else{\n            int u, v; cin >> u >> v;\n     \
    \       int t = lca.get(u, v);\n            cout << seg.query(in[t], in[u] + 1)\
    \ + seg.query(in[t], in[v] + 1) - a[t] << endl;\n        }\n    }\n}\n"
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
  timestamp: '2024-04-29 00:45:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-VertexAddPathSum-ET.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-VertexAddPathSum-ET.test.cpp
- /verify/verify/LC-VertexAddPathSum-ET.test.cpp.html
title: verify/LC-VertexAddPathSum-ET.test.cpp
---
