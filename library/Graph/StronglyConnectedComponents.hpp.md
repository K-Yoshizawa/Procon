---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-C.test.cpp
    title: verify/AOJ-GRL-3-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-StronglyConnectedComponents.test.cpp
    title: verify/LC-StronglyConnectedComponents.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\
      \u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"library/Graph/StronglyConnectedComponents.hpp\"\n/**\n *\
    \ @file StronglyConnectedComponents.hpp\n * @brief Strongly Connected Components\
    \ - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @version 3.1\n * @date 2024-02-11\n\
    \ */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
    \ * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @version 3.0\n * @date 2024-01-09\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing Vertex = int;\n\ntemplate<typename CostType>\nstruct\
    \ Edge{\n    public:\n    Vertex from, to;\n    CostType cost;\n    int loc{-1},\
    \ id{-1};\n\n    Edge() = default;\n    Edge(Vertex from, Vertex to, CostType\
    \ cost) : from(from), to(to), cost(cost){}\n\n    operator int(){\n        return\
    \ to;\n    }\n};\n\ntemplate<typename CostType = int>\nstruct Graph{\n    private:\n\
    \    int m_vertex_size{0}, m_edge_size{0};\n    bool m_is_directed{false};\n \
    \   vector<vector<Edge<CostType>>> m_adj;\n    vector<int> m_indegree;\n\n   \
    \ public:\n    CostType INF{numeric_limits<CostType>::max() >> 2};\n\n    Graph()\
    \ = default;\n    Graph(int vertex_size, bool directed = false) : m_vertex_size(vertex_size),\
    \ m_is_directed(directed){\n        m_adj.resize(vertex_size);\n        m_indegree.resize(vertex_size,\
    \ 0);\n    }\n\n    void add(Vertex from, Vertex to, CostType cost = 1){\n   \
    \     assert(0 <= from and from < m_vertex_size);\n        assert(0 <= to and\
    \ to < m_vertex_size);\n        Edge<CostType> e1(from, to, cost);\n        e1.loc\
    \ = m_adj[from].size();\n        e1.id = m_edge_size;\n        m_adj[from].push_back(e1);\n\
    \        ++m_edge_size;\n        if(m_is_directed){\n            ++m_indegree[to];\n\
    \            return;\n        }\n        Edge<CostType> e2(to, from, cost);\n\
    \        e2.loc = m_adj[to].size();\n        e2.id = e1.id;\n        m_adj[to].push_back(e2);\n\
    \    }\n\n    void input(int edge_size, bool weighted = false, bool zero_index\
    \ = false){\n        for(int i = 0; i < edge_size; ++i){\n            Vertex s,\
    \ t; cin >> s >> t;\n            if(!zero_index) --s, --t;\n            CostType\
    \ c = 1;\n            if(weighted) cin >> c;\n            add(s, t, c);\n    \
    \    }\n    }\n\n    size_t size(){\n        return m_vertex_size;\n    }\n\n\
    \    int outdegree(Vertex v){\n        return (int)m_adj.at(v).size();\n    }\n\
    \n    int indegree(Vertex v){\n        if(m_is_directed) return m_indegree.at(v);\n\
    \        else return (int)m_adj.at(v).size();\n    }\n\n    vector<Vertex> source(){\n\
    \        assert(m_is_directed);\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 0) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Vertex> sink(){\n       \
    \ vector<Vertex> ret;\n        for(int i = 0; i < m_vertex_size; ++i){\n     \
    \       if(outdegree(i) == 0) ret.push_back(i);\n        }\n        return ret;\n\
    \    }\n\n    vector<Vertex> leaf(){\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 1) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Edge<CostType>> &get_adj(Vertex\
    \ v){\n        return m_adj.at(v);\n    }\n\n    Graph<CostType> reverse(){\n\
    \        assert(m_is_directed);\n        Graph ret(m_vertex_size, true);\n   \
    \     for(auto es : m_adj){\n            for(auto e : es){\n                ret.add(e.to,\
    \ e.from, e.cost);\n            }\n        }\n        return ret;\n    }\n\n \
    \   vector<Vertex> topological_sort(){\n        assert(m_is_directed);\n     \
    \   vector<Vertex> ret;\n        queue<Vertex> que;\n        vector<int> cnt(m_vertex_size,\
    \ 0);\n        for(auto v : source()) que.push(v);\n        while(que.size()){\n\
    \            Vertex v = que.front(); que.pop();\n            ret.push_back(v);\n\
    \            for(int u : m_adj[v]){\n                if(++cnt[u] == indegree(u))\
    \ que.push(u);\n            }\n        }\n        return ret;\n    }\n\n    vector<Edge<CostType>>\
    \ edge_set(){\n        vector<Edge<CostType>> ret;\n        vector<int> es(m_edge_size,\
    \ 0);\n        for(int i = 0; i < m_vertex_size; ++i){\n            for(auto e\
    \ : m_adj[i]){\n                if(es[e.id]) continue;\n                es[e.id]\
    \ = 1;\n                ret.push_back(e);\n            }\n        }\n        sort(ret.begin(),\
    \ ret.end(), [&](Edge<CostType> &l, Edge<CostType> &r){\n            return l.cost\
    \ < r.cost;\n        });\n        return ret;\n    }\n\n    void print(){\n  \
    \      for(int i = 0; i < m_vertex_size; ++i){\n            cout << \"Vertex \"\
    \ << i << \" : \";\n            for(auto &e : m_adj[i]){\n                cout\
    \ << \"{\" << e.to << \", \" << e.cost << \"} \";\n            }\n           \
    \ cout << endl;\n        }\n    }\n\n    vector<Edge<CostType>> &operator[](Vertex\
    \ v){\n        return get_adj(v);\n    }\n};\n#line 9 \"library/Graph/StronglyConnectedComponents.hpp\"\
    \n\ntemplate<typename CostType>\nstruct StronglyConnectedComponents{\n    private:\n\
    \    Graph<CostType> &G;\n    Graph<CostType> rG;\n    vector<int> m_visited,\
    \ m_order, m_belong;\n    vector<vector<Vertex>> m_member;\n\n    void f_dfs(Vertex\
    \ v){\n        m_visited[v] = 1;\n        for(auto &e : G[v]){\n            if(!m_visited[e.to])\
    \ f_dfs(e.to);\n        }\n        m_order.push_back(v);\n    }\n\n    void f_rdfs(Vertex\
    \ v, int k){\n        m_visited[v] = 0;\n        m_belong[v] = k;\n        m_member[k].push_back(v);\n\
    \        for(auto &e : rG[v]){\n            if(m_visited[e.to]) f_rdfs(e.to, k);\n\
    \        }\n    }\n\n    public:\n    StronglyConnectedComponents(Graph<CostType>\
    \ &G) : G(G){\n        rG = G.reverse();\n        m_visited.resize(G.size(), 0);\n\
    \        m_belong.resize(G.size(), -1);\n        for(int i = 0; i < G.size();\
    \ ++i){\n            if(!m_visited[i]) f_dfs(i);\n        }\n        int k = 0;\n\
    \        for(int i = m_order.size() - 1; i >= 0; --i){\n            if(m_visited[m_order[i]]){\n\
    \                m_member.push_back(vector<CostType>{});\n                f_rdfs(m_order[i],\
    \ k++);\n            }\n        }\n    }\n\n    int where(Vertex v){\n       \
    \ return m_belong.at(v);\n    }\n\n    bool same(Vertex u, Vertex v){\n      \
    \  return where(u) == where(v);\n    }\n\n    vector<vector<Vertex>> &get(){\n\
    \        return m_member;\n    }\n\n    Graph<CostType> build(){\n        Graph<CostType>\
    \ ret(m_member.size(), true);\n        for(int i = 0; i < G.size(); ++i){\n  \
    \          int from = where(i);\n            for(auto &e : G[i]){\n          \
    \      int to = where(e.to);\n                if(from == to) continue;\n     \
    \           ret.add(from, to, e.cost);\n            }\n        }\n        return\
    \ ret;\n    }\n\n    int operator[](Vertex v){\n        return where(v);\n   \
    \ }\n\n    void print(){\n        for(int i = 0; i < m_member.size(); ++i){\n\
    \            cout << \"Component \" << i << \" : \";\n            for(auto v :\
    \ m_member[i]){\n                cout << v << \" \";\n            }\n        \
    \    cout << endl;\n        }\n    }\n};\n"
  code: "/**\n * @file StronglyConnectedComponents.hpp\n * @brief Strongly Connected\
    \ Components - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @version 3.1\n *\
    \ @date 2024-02-11\n */\n\n#include \"GraphTemplate.hpp\"\n\ntemplate<typename\
    \ CostType>\nstruct StronglyConnectedComponents{\n    private:\n    Graph<CostType>\
    \ &G;\n    Graph<CostType> rG;\n    vector<int> m_visited, m_order, m_belong;\n\
    \    vector<vector<Vertex>> m_member;\n\n    void f_dfs(Vertex v){\n        m_visited[v]\
    \ = 1;\n        for(auto &e : G[v]){\n            if(!m_visited[e.to]) f_dfs(e.to);\n\
    \        }\n        m_order.push_back(v);\n    }\n\n    void f_rdfs(Vertex v,\
    \ int k){\n        m_visited[v] = 0;\n        m_belong[v] = k;\n        m_member[k].push_back(v);\n\
    \        for(auto &e : rG[v]){\n            if(m_visited[e.to]) f_rdfs(e.to, k);\n\
    \        }\n    }\n\n    public:\n    StronglyConnectedComponents(Graph<CostType>\
    \ &G) : G(G){\n        rG = G.reverse();\n        m_visited.resize(G.size(), 0);\n\
    \        m_belong.resize(G.size(), -1);\n        for(int i = 0; i < G.size();\
    \ ++i){\n            if(!m_visited[i]) f_dfs(i);\n        }\n        int k = 0;\n\
    \        for(int i = m_order.size() - 1; i >= 0; --i){\n            if(m_visited[m_order[i]]){\n\
    \                m_member.push_back(vector<CostType>{});\n                f_rdfs(m_order[i],\
    \ k++);\n            }\n        }\n    }\n\n    int where(Vertex v){\n       \
    \ return m_belong.at(v);\n    }\n\n    bool same(Vertex u, Vertex v){\n      \
    \  return where(u) == where(v);\n    }\n\n    vector<vector<Vertex>> &get(){\n\
    \        return m_member;\n    }\n\n    Graph<CostType> build(){\n        Graph<CostType>\
    \ ret(m_member.size(), true);\n        for(int i = 0; i < G.size(); ++i){\n  \
    \          int from = where(i);\n            for(auto &e : G[i]){\n          \
    \      int to = where(e.to);\n                if(from == to) continue;\n     \
    \           ret.add(from, to, e.cost);\n            }\n        }\n        return\
    \ ret;\n    }\n\n    int operator[](Vertex v){\n        return where(v);\n   \
    \ }\n\n    void print(){\n        for(int i = 0; i < m_member.size(); ++i){\n\
    \            cout << \"Component \" << i << \" : \";\n            for(auto v :\
    \ m_member[i]){\n                cout << v << \" \";\n            }\n        \
    \    cout << endl;\n        }\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/StronglyConnectedComponents.hpp
  requiredBy: []
  timestamp: '2024-02-11 14:19:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-StronglyConnectedComponents.test.cpp
  - verify/AOJ-GRL-3-C.test.cpp
documentation_of: library/Graph/StronglyConnectedComponents.hpp
layout: document
title: "Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---

<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [['$', '$'] ],
 inlineMath: [['$', '$'] ],
 }
 });
</script>

### Abstract

有向グラフ $G$ に対して強連結成分分解を行う。

### Variable

- private
    - `m_belong` : 各頂点が所属する連結成分番号を表す。
    - `m_member` : 各連結成分の持つ頂点列を表す。

### Function

- `StronglyConnectedComponents(GraphV &G)` : 有向グラフ $G$ に対して強連結成分分解を行う。
- `where(Vertex v)` : 頂点 `v` が所属する連結成分番号を返す。
- `same(Vertex u, Vertex v)` : 頂点 `u` と頂点 `v` が同じ連結成分に含まれるかを判定する。
- `get()` : `m_member` を返す。
- `build()` : 強連結成分分解を行って圧縮されたグラフを返す。
    - 計算量 : $\textrm{O}(V + E)$
    - 戻り値 : 圧縮されたグラフ。このグラフは頂点0を始点としてトポロジカルソートされている。
- `operator[]` : `where` と同じ働きをする。
