---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
  bundledCode: "#line 1 \"verify/AOJ-GRL-4-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
    \n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
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
    \        return m_es;\n    }\n};\n#line 4 \"verify/AOJ-GRL-4-B.test.cpp\"\n\n\
    int main(){\n    int V, E; cin >> V >> E;\n    GraphV G(V, true);\n    G.input(E,\
    \ false, true);\n\n    for(auto &v : G.sort()){\n        cout << v << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
    \n\n#include \"../library/Graph/GraphTemplate.hpp\"\n\nint main(){\n    int V,\
    \ E; cin >> V >> E;\n    GraphV G(V, true);\n    G.input(E, false, true);\n\n\
    \    for(auto &v : G.sort()){\n        cout << v << endl;\n    }\n}"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-4-B.test.cpp
  requiredBy: []
  timestamp: '2024-01-09 23:25:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/AOJ-GRL-4-B.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-4-B.test.cpp
- /verify/verify/AOJ-GRL-4-B.test.cpp.html
title: verify/AOJ-GRL-4-B.test.cpp
---
