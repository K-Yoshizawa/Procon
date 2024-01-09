---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: latest/Graph/Dijkstra.hpp
    title: ''
  - icon: ':warning:'
    path: latest/Graph/LongestDistance.hpp
    title: ''
  - icon: ':warning:'
    path: latest/Graph/StronglyConnectedComponents.hpp
    title: ''
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: ''
    links: []
  bundledCode: "#line 2 \"latest/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
    \ * @author your name (you@domain.com)\n * @brief \n * @version 0.1\n * @date\
    \ 2024-01-09\n * \n * @copyright Copyright (c) 2024\n * \n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing Vertex = int;\nusing EdgeIndex = int;\n\ntemplate<typename\
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
    \    }\n\n    void input(int edge_size, bool weighted = false, bool zero_index\
    \ = false){\n        for(int i = 0; i < edge_size; ++i){\n            Vertex s,\
    \ t; cin >> s >> t;\n            if(!zero_index) --s, --t;\n            CostType\
    \ c = 1;\n            if(weighted) cin >> c;\n            add(s, t, c);\n    \
    \    }\n    }\n\n    size_t size(){\n        return m_vertex_size;\n    }\n\n\
    \    int outdegree(Vertex v){\n        return (int)m_adj.at(v).size();\n    }\n\
    \n    int indegree(Vertex v){\n        if(m_is_directed) return m_indegree.at(v);\n\
    \        else return (int)m_adj.at(v).size();\n    }\n\n    vector<Vertex> source(){\n\
    \        assert(m_is_directed)\n        vector<Vertex> ret;\n        for(int i\
    \ = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 0) ret.push_back(i);\n\
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
    \ &operator[](Vertex v){\n        return get_adj(v);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file GraphTemplate.hpp\n * @author your name (you@domain.com)\n\
    \ * @brief \n * @version 0.1\n * @date 2024-01-09\n * \n * @copyright Copyright\
    \ (c) 2024\n * \n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing\
    \ Vertex = int;\nusing EdgeIndex = int;\n\ntemplate<typename CostType>\nstruct\
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
    \    }\n\n    void input(int edge_size, bool weighted = false, bool zero_index\
    \ = false){\n        for(int i = 0; i < edge_size; ++i){\n            Vertex s,\
    \ t; cin >> s >> t;\n            if(!zero_index) --s, --t;\n            CostType\
    \ c = 1;\n            if(weighted) cin >> c;\n            add(s, t, c);\n    \
    \    }\n    }\n\n    size_t size(){\n        return m_vertex_size;\n    }\n\n\
    \    int outdegree(Vertex v){\n        return (int)m_adj.at(v).size();\n    }\n\
    \n    int indegree(Vertex v){\n        if(m_is_directed) return m_indegree.at(v);\n\
    \        else return (int)m_adj.at(v).size();\n    }\n\n    vector<Vertex> source(){\n\
    \        assert(m_is_directed)\n        vector<Vertex> ret;\n        for(int i\
    \ = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 0) ret.push_back(i);\n\
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
    \ &operator[](Vertex v){\n        return get_adj(v);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: latest/Graph/GraphTemplate.hpp
  requiredBy:
  - latest/Graph/StronglyConnectedComponents.hpp
  - latest/Graph/Dijkstra.hpp
  - latest/Graph/LongestDistance.hpp
  timestamp: '2024-01-09 13:51:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: latest/Graph/GraphTemplate.hpp
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

## GraphV - 頂点集合グラフ

### Abstract

グラフを頂点集合(隣接リスト)で表現するもの。

### Variable

- private
    - `m_vertex_size` : グラフの頂点数
    - `m_edge_size` : グラフの辺数
    - `m_is_directed` : 有向グラフであるかのフラグ
    - `m_adj` : 隣接リスト形式で表されたグラフ本体
    - `m_indegree` : 各頂点の入次数(有向グラフのみ利用可能)
- public
    - `INF` : 無限大を表す値で、デフォルトでは `numeric_limits<CostType>::max() >> 2` が入る

### Function

- `GraphV(int vertex_size, bool directed = false)` : 頂点数 $V$ = `vertex_size` のグラフ $G$ を作成する。 `directed` を `true` に設定すると有向グラフとして作成する。
- `add(Vertex from, Vertex to, CostType cost = 1)` : $G$ に頂点 `from` から頂点 `to` に重み `cost` の辺を張る。
    - 引数 :
        - `from` : 辺の始点
        - `to` : 辺の終点
        - `cost = 1` : 辺の重み、省略すれば重み1として扱われる。
    - 要件 : `from` および `to` は 0-index であること。
- `input(int edge_size, bool weighted = false, bool zero_index = false)` : $G$ に $E$ = `edge_size` 本の辺を入力させる。
    - 計算量 : $\textrm{O}(E)$
    - 引数 :
        - `weighted = false` : 読み込む辺が重み付きかを設定する。 `true` にすれば重み付き辺を読み込むことができる。
        - `zero_index = false` : 読み込む辺が 0-indexとして与えられるかを設定する。 `true` にすれば0-indexとして読み込む。
- `size()` : 頂点数 $V$ (= `m_vertex_size`)を返す。
- `outdegree(Vertex v)` : 頂点 `v` の出次数を返す。無向グラフの場合は単に頂点 `v` の次数を返す。
- `indegree(Vertex v)` : 頂点 `v` の入次数を返す。無向グラフの場合は単に頂点 `v` の次数を返す。
- `source()` : $G$ の源点(入次数が0である頂点)を返す。無向グラフの場合は $G$ の孤立点(次数が0である頂点)を返す。
    - 計算量 : $\textrm{O}(V)$
- `sink()` : $G$ の沈点(出次数が0である頂点)を返す。無向グラフの場合は $G$ の孤立点(次数が0である頂点)を返す。
    - 計算量 : $\textrm{O}(V)$
- `leaf()` : $G$ の葉頂点(次数が1である頂点)を返す。有向グラフの場合は入次数が1である頂点を返す。
    - 計算量 : $\textrm{O}(V)$
- `get_adj(Vertex v)` : 頂点 `v` の隣接リストを返す。
- `reverse()` : $G$ の有向辺をすべて反転させたグラフ $G^\prime$ を返す。
    - 計算量 : $\textrm{O}(E)$
    - 要件 : $G$ が有向グラフであること。
- `sort()` : $G$ をトポロジカルソートした頂点列を返す。
    - 計算量 : $\textrm{O}(V)$
    - 要件 : $G$ が有向グラフであること。   
- `operator[]` : `get_adj(v)` を返す。
