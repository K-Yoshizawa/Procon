---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-LowestCommonAncestor.test.cpp
    title: verify/LC-LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexAddPathSum.test.cpp
    title: verify/LC-VertexAddPathSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
    links: []
  bundledCode: "#line 1 \"library/Tree/LowestCommonAncestor.hpp\"\n/**\n * @file LowestCommonAncestor.hpp\n\
    \ * @author log K (lX57)\n * @brief Lowest Common Ancestor - \u6700\u5C0F\u5171\
    \u901A\u7956\u5148\n * @version 3.0\n * @date 2024-02-11\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @brief Graph Template - \u30B0\u30E9\u30D5\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 3.0\n * @date 2024-01-09\n */\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    public:\n    Vertex from, to;\n    CostType cost;\n\
    \    int loc{-1}, id{-1};\n\n    Edge() = default;\n    Edge(Vertex from, Vertex\
    \ to, CostType cost) : from(from), to(to), cost(cost){}\n\n    operator int(){\n\
    \        return to;\n    }\n};\n\ntemplate<typename CostType = int>\nstruct Graph{\n\
    \    private:\n    int m_vertex_size{0}, m_edge_size{0};\n    bool m_is_directed{false};\n\
    \    vector<vector<Edge<CostType>>> m_adj;\n    vector<int> m_indegree;\n\n  \
    \  public:\n    CostType INF{numeric_limits<CostType>::max() >> 2};\n\n    Graph()\
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
    \ << i << \" : \";\n            if(m_adj[i].empty()){\n                cout <<\
    \ \"<none>\" << endl;\n                continue;\n            }\n            for(auto\
    \ &e : m_adj[i]){\n                cout << \"{\" << e.to << \", \" << e.cost <<\
    \ \"} \";\n            }\n            cout << endl;\n        }\n    }\n\n    vector<Edge<CostType>>\
    \ &operator[](Vertex v){\n        return get_adj(v);\n    }\n};\n#line 10 \"library/Tree/LowestCommonAncestor.hpp\"\
    \n\ntemplate<typename CostType>\nstruct LowestCommonAncestor{\n    private:\n\
    \    Graph<CostType> &G;\n    int m_height;\n    vector<int> m_depth;\n    vector<vector<Vertex>>\
    \ m_parent;\n\n    void m_dfs(Vertex v, Vertex p, int d){\n        m_parent[0][v]\
    \ = p;\n        m_depth[v] = d;\n        for(auto &e : G[v]){\n            if(e.to\
    \ != p) m_dfs(e.to, v, d + 1);\n        }\n    }\n\n    public:\n    LowestCommonAncestor(Graph<CostType>\
    \ &G, Vertex Root = 0) : G(G), m_height(32){\n        m_depth.resize(G.size());\n\
    \        m_parent.resize(m_height, vector<Vertex>(G.size(), -1));\n        m_dfs(Root,\
    \ -1, 0);\n        for(int k = 0; k + 1 < m_height; ++k){\n            for(Vertex\
    \ v = 0; v < G.size(); ++v){\n                if(m_parent[k][v] < 0) m_parent[k\
    \ + 1][v] = -1;\n                else m_parent[k + 1][v] = m_parent[k][m_parent[k][v]];\n\
    \            }\n        }\n    }\n\n    Vertex get(Vertex u, Vertex v){\n    \
    \    if(m_depth[u] > m_depth[v]) swap(u, v);\n        for(int k = 0; k < m_height;\
    \ ++k){\n            if((m_depth[v] - m_depth[u]) >> k & 1){\n               \
    \ v = m_parent[k][v];\n            }\n        }\n        if(u == v) return u;\n\
    \        for(int k = m_height - 1; k >= 0; --k){\n            if(m_parent[k][u]\
    \ != m_parent[k][v]){\n                u = m_parent[k][u];\n                v\
    \ = m_parent[k][v];\n            }\n        }\n        return m_parent[0][u];\n\
    \    }\n};\n"
  code: "/**\n * @file LowestCommonAncestor.hpp\n * @author log K (lX57)\n * @brief\
    \ Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148\n * @version 3.0\n\
    \ * @date 2024-02-11\n */\n\n#include \"../Graph/GraphTemplate.hpp\"\n\ntemplate<typename\
    \ CostType>\nstruct LowestCommonAncestor{\n    private:\n    Graph<CostType> &G;\n\
    \    int m_height;\n    vector<int> m_depth;\n    vector<vector<Vertex>> m_parent;\n\
    \n    void m_dfs(Vertex v, Vertex p, int d){\n        m_parent[0][v] = p;\n  \
    \      m_depth[v] = d;\n        for(auto &e : G[v]){\n            if(e.to != p)\
    \ m_dfs(e.to, v, d + 1);\n        }\n    }\n\n    public:\n    LowestCommonAncestor(Graph<CostType>\
    \ &G, Vertex Root = 0) : G(G), m_height(32){\n        m_depth.resize(G.size());\n\
    \        m_parent.resize(m_height, vector<Vertex>(G.size(), -1));\n        m_dfs(Root,\
    \ -1, 0);\n        for(int k = 0; k + 1 < m_height; ++k){\n            for(Vertex\
    \ v = 0; v < G.size(); ++v){\n                if(m_parent[k][v] < 0) m_parent[k\
    \ + 1][v] = -1;\n                else m_parent[k + 1][v] = m_parent[k][m_parent[k][v]];\n\
    \            }\n        }\n    }\n\n    Vertex get(Vertex u, Vertex v){\n    \
    \    if(m_depth[u] > m_depth[v]) swap(u, v);\n        for(int k = 0; k < m_height;\
    \ ++k){\n            if((m_depth[v] - m_depth[u]) >> k & 1){\n               \
    \ v = m_parent[k][v];\n            }\n        }\n        if(u == v) return u;\n\
    \        for(int k = m_height - 1; k >= 0; --k){\n            if(m_parent[k][u]\
    \ != m_parent[k][v]){\n                u = m_parent[k][u];\n                v\
    \ = m_parent[k][v];\n            }\n        }\n        return m_parent[0][u];\n\
    \    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Tree/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2024-02-11 17:55:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-VertexAddPathSum.test.cpp
  - verify/LC-LowestCommonAncestor.test.cpp
documentation_of: library/Tree/LowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/library/Tree/LowestCommonAncestor.hpp
- /library/library/Tree/LowestCommonAncestor.hpp.html
title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
---
