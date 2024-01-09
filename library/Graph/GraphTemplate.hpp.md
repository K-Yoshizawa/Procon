---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/Graph/BellmanFord.hpp
    title: "BellmanFord - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: library/Graph/Dijkstra.hpp
    title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
  - icon: ':warning:'
    path: library/Graph/LongestDistance.hpp
    title: ''
  - icon: ':heavy_check_mark:'
    path: library/Graph/StronglyConnectedComponents.hpp
    title: "Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/AOJ-ALDS1-11-A.test.cpp
    title: verify/AOJ-ALDS1-11-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-A.test.cpp
    title: verify/AOJ-GRL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-B.test.cpp
    title: verify/AOJ-GRL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-3-C.test.cpp
    title: verify/AOJ-GRL-3-C.test.cpp
  - icon: ':x:'
    path: verify/AOJ-GRL-4-B.test.cpp
    title: verify/AOJ-GRL-4-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-ShortestPath.test.cpp
    title: verify/LC-ShortestPath.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-StronglyConnectedComponents.test.cpp
    title: verify/LC-StronglyConnectedComponents.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8"
    links: []
  bundledCode: "#line 2 \"library/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
    \ * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @version 3.0\n * @date 2024-01-09\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing Vertex = int;\nusing EdgeIndex = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    public:\n    Vertex from, to;\n    CostType cost;\n\
    \    EdgeIndex idx{-1};\n\n    Edge() = default;\n    Edge(Vertex from, Vertex\
    \ to, CostType cost) : from(from), to(to), cost(cost){}\n\n    operator int(){\n\
    \        return to;\n    }\n};\n\ntemplate<typename CostType = int>\nstruct GraphV{\n\
    \    private:\n    int m_vertex_size{0}, m_edge_size{0};\n    bool m_is_directed{false};\n\
    \    vector<vector<Edge<CostType>>> m_adj;\n    vector<int> m_indegree;\n\n  \
    \  public:\n    CostType INF{numeric_limits<CostType>::max() >> 2};\n\n    GraphV()\
    \ = default;\n    GraphV(int vertex_size, bool directed = false) : m_vertex_size(vertex_size),\
    \ m_is_directed(directed){\n        m_adj.resize(vertex_size);\n        m_indegree.resize(vertex_size,\
    \ 0);\n    }\n\n    void add(Vertex from, Vertex to, CostType cost = 1){\n   \
    \     assert(0 <= from and from < m_vertex_size);\n        assert(0 <= to and\
    \ to < m_vertex_size);\n        Edge<CostType> e1(from, to, cost);\n        e1.idx\
    \ = m_adj[from].size();\n        m_adj[from].push_back(e1);\n        if(m_is_directed){\n\
    \            ++m_indegree[to];\n            return;\n        }\n        Edge<CostType>\
    \ e2(to, from, cost);\n        e2.idx = m_adj[to].size();\n        m_adj[to].push_back(e2);\n\
    \        ++m_edge_size;\n    }\n\n    void input(int edge_size, bool weighted\
    \ = false, bool zero_index = false){\n        for(int i = 0; i < edge_size; ++i){\n\
    \            Vertex s, t; cin >> s >> t;\n            if(!zero_index) --s, --t;\n\
    \            CostType c = 1;\n            if(weighted) cin >> c;\n           \
    \ add(s, t, c);\n        }\n    }\n\n    size_t size(){\n        return m_vertex_size;\n\
    \    }\n\n    int outdegree(Vertex v){\n        return (int)m_adj.at(v).size();\n\
    \    }\n\n    int indegree(Vertex v){\n        if(m_is_directed) return m_indegree.at(v);\n\
    \        else return (int)m_adj.at(v).size();\n    }\n\n    vector<Vertex> source(){\n\
    \        assert(m_is_directed);\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 0) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Vertex> sink(){\n       \
    \ vector<Vertex> ret;\n        for(int i = 0; i < m_vertex_size; ++i){\n     \
    \       if(outdegree(i) == 0) ret.push_back(i);\n        }\n        return ret;\n\
    \    }\n\n    vector<Vertex> leaf(){\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 1) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Edge<CostType>> &get_adj(Vertex\
    \ v){\n        return m_adj.at(v);\n    }\n\n    GraphV<CostType> reverse(){\n\
    \        assert(m_is_directed);\n        GraphV ret(m_vertex_size, true);\n  \
    \      for(auto es : m_adj){\n            for(auto e : es){\n                ret.add(e.to,\
    \ e.from, e.cost);\n            }\n        }\n        return ret;\n    }\n\n \
    \   vector<Vertex> sort(){\n        assert(m_is_directed);\n        vector<Vertex>\
    \ ret;\n        queue<Vertex> que;\n        vector<int> cnt(m_vertex_size, 0);\n\
    \        for(auto v : source()) que.push(v);\n        while(que.size()){\n   \
    \         Vertex v = que.front(); que.pop();\n            ret.push_back(v);\n\
    \            for(int u : m_adj[v]){\n                if(++cnt[u] == indegree(u))\
    \ que.push(u);\n            }\n        }\n        return ret;\n    }\n\n    void\
    \ print(){\n        for(int i = 0; i < m_vertex_size; ++i){\n            cout\
    \ << \"Vertex \" << i << \" : \";\n            for(auto &e : m_adj[i]){\n    \
    \            cout << \"{\" << e.to << \", \" << e.cost << \"} \";\n          \
    \  }\n            cout << endl;\n        }\n    }\n\n    vector<Edge<CostType>>\
    \ &operator[](Vertex v){\n        return get_adj(v);\n    }\n};\n\ntemplate<typename\
    \ CostType>\nstruct GraphE{\n    private:\n    int m_vertex_size{0}, m_edge_size{0};\n\
    \    bool m_is_directed{false};\n    vector<Edge<CostType>> m_es, m_res;\n   \
    \ vector<int> m_indegree, m_outdegree;\n\n    public:\n    CostType INF{numeric_limits<CostType>::max()\
    \ >> 2};\n\n    GraphE() = default;\n    GraphE(int vertex_size, bool directed\
    \ = false) : m_vertex_size(vertex_size), m_is_directed(directed){\n        m_indegree.resize(vertex_size,\
    \ 0);\n        m_outdegree.resize(vertex_size, 0);\n    }\n\n    void add(Vertex\
    \ from, Vertex to, CostType cost = 1){\n        assert(0 <= from and from < m_vertex_size);\n\
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
    \        return m_es;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file GraphTemplate.hpp\n * @brief Graph Template\
    \ - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 3.0\n\
    \ * @date 2024-01-09\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    using Vertex = int;\nusing EdgeIndex = int;\n\ntemplate<typename CostType>\nstruct\
    \ Edge{\n    public:\n    Vertex from, to;\n    CostType cost;\n    EdgeIndex\
    \ idx{-1};\n\n    Edge() = default;\n    Edge(Vertex from, Vertex to, CostType\
    \ cost) : from(from), to(to), cost(cost){}\n\n    operator int(){\n        return\
    \ to;\n    }\n};\n\ntemplate<typename CostType = int>\nstruct GraphV{\n    private:\n\
    \    int m_vertex_size{0}, m_edge_size{0};\n    bool m_is_directed{false};\n \
    \   vector<vector<Edge<CostType>>> m_adj;\n    vector<int> m_indegree;\n\n   \
    \ public:\n    CostType INF{numeric_limits<CostType>::max() >> 2};\n\n    GraphV()\
    \ = default;\n    GraphV(int vertex_size, bool directed = false) : m_vertex_size(vertex_size),\
    \ m_is_directed(directed){\n        m_adj.resize(vertex_size);\n        m_indegree.resize(vertex_size,\
    \ 0);\n    }\n\n    void add(Vertex from, Vertex to, CostType cost = 1){\n   \
    \     assert(0 <= from and from < m_vertex_size);\n        assert(0 <= to and\
    \ to < m_vertex_size);\n        Edge<CostType> e1(from, to, cost);\n        e1.idx\
    \ = m_adj[from].size();\n        m_adj[from].push_back(e1);\n        if(m_is_directed){\n\
    \            ++m_indegree[to];\n            return;\n        }\n        Edge<CostType>\
    \ e2(to, from, cost);\n        e2.idx = m_adj[to].size();\n        m_adj[to].push_back(e2);\n\
    \        ++m_edge_size;\n    }\n\n    void input(int edge_size, bool weighted\
    \ = false, bool zero_index = false){\n        for(int i = 0; i < edge_size; ++i){\n\
    \            Vertex s, t; cin >> s >> t;\n            if(!zero_index) --s, --t;\n\
    \            CostType c = 1;\n            if(weighted) cin >> c;\n           \
    \ add(s, t, c);\n        }\n    }\n\n    size_t size(){\n        return m_vertex_size;\n\
    \    }\n\n    int outdegree(Vertex v){\n        return (int)m_adj.at(v).size();\n\
    \    }\n\n    int indegree(Vertex v){\n        if(m_is_directed) return m_indegree.at(v);\n\
    \        else return (int)m_adj.at(v).size();\n    }\n\n    vector<Vertex> source(){\n\
    \        assert(m_is_directed);\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 0) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Vertex> sink(){\n       \
    \ vector<Vertex> ret;\n        for(int i = 0; i < m_vertex_size; ++i){\n     \
    \       if(outdegree(i) == 0) ret.push_back(i);\n        }\n        return ret;\n\
    \    }\n\n    vector<Vertex> leaf(){\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 1) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Edge<CostType>> &get_adj(Vertex\
    \ v){\n        return m_adj.at(v);\n    }\n\n    GraphV<CostType> reverse(){\n\
    \        assert(m_is_directed);\n        GraphV ret(m_vertex_size, true);\n  \
    \      for(auto es : m_adj){\n            for(auto e : es){\n                ret.add(e.to,\
    \ e.from, e.cost);\n            }\n        }\n        return ret;\n    }\n\n \
    \   vector<Vertex> sort(){\n        assert(m_is_directed);\n        vector<Vertex>\
    \ ret;\n        queue<Vertex> que;\n        vector<int> cnt(m_vertex_size, 0);\n\
    \        for(auto v : source()) que.push(v);\n        while(que.size()){\n   \
    \         Vertex v = que.front(); que.pop();\n            ret.push_back(v);\n\
    \            for(int u : m_adj[v]){\n                if(++cnt[u] == indegree(u))\
    \ que.push(u);\n            }\n        }\n        return ret;\n    }\n\n    void\
    \ print(){\n        for(int i = 0; i < m_vertex_size; ++i){\n            cout\
    \ << \"Vertex \" << i << \" : \";\n            for(auto &e : m_adj[i]){\n    \
    \            cout << \"{\" << e.to << \", \" << e.cost << \"} \";\n          \
    \  }\n            cout << endl;\n        }\n    }\n\n    vector<Edge<CostType>>\
    \ &operator[](Vertex v){\n        return get_adj(v);\n    }\n};\n\ntemplate<typename\
    \ CostType>\nstruct GraphE{\n    private:\n    int m_vertex_size{0}, m_edge_size{0};\n\
    \    bool m_is_directed{false};\n    vector<Edge<CostType>> m_es, m_res;\n   \
    \ vector<int> m_indegree, m_outdegree;\n\n    public:\n    CostType INF{numeric_limits<CostType>::max()\
    \ >> 2};\n\n    GraphE() = default;\n    GraphE(int vertex_size, bool directed\
    \ = false) : m_vertex_size(vertex_size), m_is_directed(directed){\n        m_indegree.resize(vertex_size,\
    \ 0);\n        m_outdegree.resize(vertex_size, 0);\n    }\n\n    void add(Vertex\
    \ from, Vertex to, CostType cost = 1){\n        assert(0 <= from and from < m_vertex_size);\n\
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
    \        return m_es;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/Graph/GraphTemplate.hpp
  requiredBy:
  - library/Graph/StronglyConnectedComponents.hpp
  - library/Graph/Dijkstra.hpp
  - library/Graph/LongestDistance.hpp
  - library/Graph/BellmanFord.hpp
  timestamp: '2024-01-09 23:25:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/LC-ShortestPath.test.cpp
  - verify/AOJ-GRL-3-C.test.cpp
  - verify/AOJ-GRL-1-B.test.cpp
  - verify/LC-StronglyConnectedComponents.test.cpp
  - verify/AOJ-GRL-1-A.test.cpp
  - verify/AOJ-GRL-4-B.test.cpp
  - verify/AOJ-ALDS1-11-A.test.cpp
documentation_of: library/Graph/GraphTemplate.hpp
layout: document
title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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

グラフを扱うための基本テンプレート。

## Variable

- private
    - `CntVertex, CntEdge` : 頂点数、辺数
    - `isDirected` : 有向グラフか否か
    - `ES, RES` : 辺集合、逆辺集合
    - `IL` : 接続リスト　各頂点に対して接続している辺を持つ
    - `AL` : 隣接リスト　各頂点に対して隣接している頂点を持つ
- public
    - `INF` : 無限大、自動で`numeric_limits<CostType>::max() / 2`となる

## Function

- `Graph(int VertexSize, bool isDirected)` : 頂点数 `VertexSize` で初期化する。このとき有向グラフとして作成するかを選択できる。デフォルトでは無向グラフを生成する。
- `add(Vertex Source, Vertex To, CostType Cost)` : 頂点 `Source` から頂点 `To` に重み `Cost` の辺を追加する。`Cost` は省略可能で、省略すると `1` になる。
- `matrix(CostType NotAdjacent)` : 隣接行列を生成して返す。隣接していない頂点への距離を`NotAdjacent`で指定可能。$O(E)$
- `vsize(), esize()` : 頂点数、辺数を返す。
- `incsize(Vertex v)` : 頂点 `v` の次数(出次数)を返す。
- `get_edgeset()` : 辺集合を返す。
- `get_incidentlist()` : 接続リストを返す。
- `get_incident(Vertex v)` : 頂点 `v` の接続リストを返す。
- `get_adjacentlist()` : 隣接リストを返す。
- `get_adjacent(Vertex v)` : 頂点 `v` の隣接リストを返す。
- `print_edgeset(bool OneIndex)` : 主にデバッグ用。辺集合の中身を出力する。$O(E)$
- `print_incidentlist(bool OneIndex)` : 主にデバッグ用。接続リストの中身を出力する。$O(E)$
- `print_matrix(CostType NotAdjacent, bool DisplayINF)` : 隣接行列を出力する。隣接していない頂点への距離を `INF` として表示することも可能。$O(V^2)$
