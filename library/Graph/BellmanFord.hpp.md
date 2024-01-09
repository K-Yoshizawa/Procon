---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-B.test.cpp
    title: verify/AOJ-GRL-1-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "BellmanFord - \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\
      \u6CD5"
    links: []
  bundledCode: "#line 1 \"library/Graph/BellmanFord.hpp\"\n/**\n * @file BellmanFord.hpp\n\
    \ * @brief BellmanFord - \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\
    \n * @version 3.0\n * @date 2024-01-09\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @brief Graph Template - \u30B0\u30E9\u30D5\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 3.0\n * @date 2024-01-09\n */\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\nusing\
    \ EdgeIndex = int;\n\ntemplate<typename CostType>\nstruct Edge{\n    public:\n\
    \    Vertex from, to;\n    CostType cost;\n    EdgeIndex idx{-1};\n\n    Edge()\
    \ = default;\n    Edge(Vertex from, Vertex to, CostType cost) : from(from), to(to),\
    \ cost(cost){}\n\n    operator int(){\n        return to;\n    }\n};\n\ntemplate<typename\
    \ CostType = int>\nstruct GraphV{\n    private:\n    int m_vertex_size{0}, m_edge_size{0};\n\
    \    bool m_is_directed{false};\n    vector<vector<Edge<CostType>>> m_adj;\n \
    \   vector<int> m_indegree;\n\n    public:\n    CostType INF{numeric_limits<CostType>::max()\
    \ >> 2};\n\n    GraphV() = default;\n    GraphV(int vertex_size, bool directed\
    \ = false) : m_vertex_size(vertex_size), m_is_directed(directed){\n        m_adj.resize(vertex_size);\n\
    \        m_indegree.resize(vertex_size, 0);\n    }\n\n    void add(Vertex from,\
    \ Vertex to, CostType cost = 1){\n        assert(0 <= from and from < m_vertex_size);\n\
    \        assert(0 <= to and to < m_vertex_size);\n        Edge<CostType> e1(from,\
    \ to, cost);\n        e1.idx = m_adj[from].size();\n        m_adj[from].push_back(e1);\n\
    \        if(m_is_directed){\n            ++m_indegree[to];\n            return;\n\
    \        }\n        Edge<CostType> e2(to, from, cost);\n        e2.idx = m_adj[to].size();\n\
    \        m_adj[to].push_back(e2);\n        ++m_edge_size;\n    }\n\n    void input(int\
    \ edge_size, bool weighted = false, bool zero_index = false){\n        for(int\
    \ i = 0; i < edge_size; ++i){\n            Vertex s, t; cin >> s >> t;\n     \
    \       if(!zero_index) --s, --t;\n            CostType c = 1;\n            if(weighted)\
    \ cin >> c;\n            add(s, t, c);\n        }\n    }\n\n    size_t size(){\n\
    \        return m_vertex_size;\n    }\n\n    int outdegree(Vertex v){\n      \
    \  return (int)m_adj.at(v).size();\n    }\n\n    int indegree(Vertex v){\n   \
    \     if(m_is_directed) return m_indegree.at(v);\n        else return (int)m_adj.at(v).size();\n\
    \    }\n\n    vector<Vertex> source(){\n        assert(m_is_directed);\n     \
    \   vector<Vertex> ret;\n        for(int i = 0; i < m_vertex_size; ++i){\n   \
    \         if(indegree(i) == 0) ret.push_back(i);\n        }\n        return ret;\n\
    \    }\n\n    vector<Vertex> sink(){\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(outdegree(i) == 0) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Vertex> leaf(){\n       \
    \ vector<Vertex> ret;\n        for(int i = 0; i < m_vertex_size; ++i){\n     \
    \       if(indegree(i) == 1) ret.push_back(i);\n        }\n        return ret;\n\
    \    }\n\n    vector<Edge<CostType>> &get_adj(Vertex v){\n        return m_adj.at(v);\n\
    \    }\n\n    GraphV<CostType> reverse(){\n        assert(m_is_directed);\n  \
    \      GraphV ret(m_vertex_size, true);\n        for(auto es : m_adj){\n     \
    \       for(auto e : es){\n                ret.add(e.to, e.from, e.cost);\n  \
    \          }\n        }\n        return ret;\n    }\n\n    vector<Vertex> sort(){\n\
    \        assert(m_is_directed);\n        vector<Vertex> ret;\n        queue<Vertex>\
    \ que;\n        vector<int> cnt(m_vertex_size, 0);\n        for(auto v : source())\
    \ que.push(v);\n        while(que.size()){\n            Vertex v = que.front();\
    \ que.pop();\n            ret.push_back(v);\n            for(int u : m_adj[v]){\n\
    \                if(++cnt[u] == indegree(u)) que.push(u);\n            }\n   \
    \     }\n        return ret;\n    }\n\n    void print(){\n        for(int i =\
    \ 0; i < m_vertex_size; ++i){\n            cout << \"Vertex \" << i << \" : \"\
    ;\n            for(auto &e : m_adj[i]){\n                cout << \"{\" << e.to\
    \ << \", \" << e.cost << \"} \";\n            }\n            cout << endl;\n \
    \       }\n    }\n\n    vector<Edge<CostType>> &operator[](Vertex v){\n      \
    \  return get_adj(v);\n    }\n};\n\ntemplate<typename CostType>\nstruct GraphE{\n\
    \    private:\n    int m_vertex_size{0}, m_edge_size{0};\n    bool m_is_directed{false};\n\
    \    vector<Edge<CostType>> m_es, m_res;\n    vector<int> m_indegree, m_outdegree;\n\
    \n    public:\n    CostType INF{numeric_limits<CostType>::max() >> 2};\n\n   \
    \ GraphE() = default;\n    GraphE(int vertex_size, bool directed = false) : m_vertex_size(vertex_size),\
    \ m_is_directed(directed){\n        m_indegree.resize(vertex_size, 0);\n     \
    \   m_outdegree.resize(vertex_size, 0);\n    }\n\n    void add(Vertex from, Vertex\
    \ to, CostType cost = 1){\n        assert(0 <= from and from < m_vertex_size);\n\
    \        assert(0 <= to and to < m_vertex_size);\n        Edge<CostType> e1(from,\
    \ to, cost);\n        e1.idx = m_edge_size;\n        m_es.push_back(e1);\n   \
    \     ++m_outdegree[from];\n        if(m_is_directed){\n            ++m_indegree[to];\n\
    \            return;\n        }\n        Edge<CostType> e2(to, from, cost);\n\
    \        e2.idx = m_edge_size;\n        m_res.push_back(e2);\n        ++m_outdegree[to];\n\
    \        ++m_edge_size;\n    }\n\n    void input(int edge_size, bool weighted\
    \ = false, bool zero_index = false){\n        for(int i = 0; i < edge_size; ++i){\n\
    \            Vertex s, t; cin >> s >> t;\n            if(!zero_index) --s, --t;\n\
    \            CostType c = 1;\n            if(weighted) cin >> c;\n           \
    \ add(s, t, c);\n        }\n    }\n\n    size_t size(){\n        return m_vertex_size;\n\
    \    }\n\n    int outdegree(Vertex v){\n        return m_outdegree.at(v);\n  \
    \  }\n\n    int indegree(Vertex v){\n        if(m_is_directed) return m_indegree.at(v);\n\
    \        else return m_outdegree.at(v);\n    }\n\n    vector<Edge<CostType>> &get(){\n\
    \        return m_es;\n    }\n};\n#line 9 \"library/Graph/BellmanFord.hpp\"\n\n\
    template<typename CostType>\nvector<CostType> BellmanFord(GraphE<CostType> &G,\
    \ Vertex s){\n    vector<CostType> ret(G.size(), G.INF);\n    ret[s] = 0;\n  \
    \  int updatecount = 0;\n    while(1){\n        if(updatecount == G.size()){\n\
    \            return vector<CostType>{};\n        }\n        bool update = false;\n\
    \        for(auto e : G.get()){\n            if(ret[e.from] == G.INF) continue;\n\
    \            if(ret[e.to] > ret[e.from] + e.cost){\n                ret[e.to]\
    \ = ret[e.from] + e.cost;\n                update = true;\n            }\n   \
    \     }\n        if(!update) break;\n        ++updatecount;\n    }\n    return\
    \ ret;\n}\n"
  code: "/**\n * @file BellmanFord.hpp\n * @brief BellmanFord - \u30D9\u30EB\u30DE\
    \u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\n * @version 3.0\n * @date 2024-01-09\n */\n\
    \n#include \"GraphTemplate.hpp\"\n\ntemplate<typename CostType>\nvector<CostType>\
    \ BellmanFord(GraphE<CostType> &G, Vertex s){\n    vector<CostType> ret(G.size(),\
    \ G.INF);\n    ret[s] = 0;\n    int updatecount = 0;\n    while(1){\n        if(updatecount\
    \ == G.size()){\n            return vector<CostType>{};\n        }\n        bool\
    \ update = false;\n        for(auto e : G.get()){\n            if(ret[e.from]\
    \ == G.INF) continue;\n            if(ret[e.to] > ret[e.from] + e.cost){\n   \
    \             ret[e.to] = ret[e.from] + e.cost;\n                update = true;\n\
    \            }\n        }\n        if(!update) break;\n        ++updatecount;\n\
    \    }\n    return ret;\n}"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/BellmanFord.hpp
  requiredBy: []
  timestamp: '2024-01-09 23:25:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-B.test.cpp
documentation_of: library/Graph/BellmanFord.hpp
layout: document
title: "BellmanFord - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
---

<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [['$', '$'] ],
 displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
 }
 });
</script>

## Abstract

単一始点最短距離問題をBellmanFord法を用いて求める。

## Function

- `BellmanFord(Graph G, Vertex Start)` : 頂点 `Start` を始点として単一始点最短距離問題を解く。$O(VE)$
    - 負閉路が存在する場合、空列を返す。
    - そうでない場合、各頂点への最短距離を返す。
