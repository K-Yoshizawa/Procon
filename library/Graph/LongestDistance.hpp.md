---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Longest Distance - DAG\u306B\u304A\u3051\u308B\u6700\u9577\u8DDD\
      \u96E2"
    links: []
  bundledCode: "#line 1 \"library/Graph/LongestDistance.hpp\"\n/**\n * @file LongestDistance.hpp\n\
    \ * @author log K (lX57)\n * @brief Longest Distance - DAG\u306B\u304A\u3051\u308B\
    \u6700\u9577\u8DDD\u96E2\n * @version 1.0\n * @date 2024-02-11\n */\n\n#line 2\
    \ \"library/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n * @brief\
    \ Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n *\
    \ @version 3.0\n * @date 2024-01-09\n */\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing Vertex = int;\n\ntemplate<typename CostType>\nstruct Edge{\n \
    \   public:\n    Vertex from, to;\n    CostType cost;\n    int loc{-1}, id{-1};\n\
    \n    Edge() = default;\n    Edge(Vertex from, Vertex to, CostType cost) : from(from),\
    \ to(to), cost(cost){}\n\n    operator int(){\n        return to;\n    }\n};\n\
    \ntemplate<typename CostType = int>\nstruct Graph{\n    private:\n    int m_vertex_size{0},\
    \ m_edge_size{0};\n    bool m_is_directed{false};\n    vector<vector<Edge<CostType>>>\
    \ m_adj;\n    vector<int> m_indegree;\n\n    public:\n    CostType INF{numeric_limits<CostType>::max()\
    \ >> 2};\n\n    Graph() = default;\n    Graph(int vertex_size, bool directed =\
    \ false) : m_vertex_size(vertex_size), m_is_directed(directed){\n        m_adj.resize(vertex_size);\n\
    \        m_indegree.resize(vertex_size, 0);\n    }\n\n    void add(Vertex from,\
    \ Vertex to, CostType cost = 1){\n        assert(0 <= from and from < m_vertex_size);\n\
    \        assert(0 <= to and to < m_vertex_size);\n        Edge<CostType> e1(from,\
    \ to, cost);\n        e1.loc = m_adj[from].size();\n        e1.id = m_edge_size;\n\
    \        m_adj[from].push_back(e1);\n        if(m_is_directed){\n            ++m_indegree[to];\n\
    \            return;\n        }\n        Edge<CostType> e2(to, from, cost);\n\
    \        e2.loc = m_adj[to].size();\n        e2.id = m_edge_size;\n        m_adj[to].push_back(e2);\n\
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
    \ v){\n        return get_adj(v);\n    }\n};\n#line 10 \"library/Graph/LongestDistance.hpp\"\
    \n\ntemplate<typename CostType>\nvector<CostType> longestdistance(Graph<CostType>\
    \ &G, CostType INF, Vertex start = -1, CostType init = 0){\n    vector<CostType>\
    \ dp(G.size(), INF);\n    if(start == -1){\n        for(auto v : G.source()) dp[v]\
    \ = init;\n    }\n    else dp[start] = init;\n    for(int i : G.topological_sort()){\n\
    \        if(dp[i] == INF) continue;\n        for(auto &e : G[i]){\n          \
    \  dp[e.to] = max(dp[e.to], dp[i] + e.cost);\n        }\n    }\n    return dp;\n\
    }\n"
  code: "/**\n * @file LongestDistance.hpp\n * @author log K (lX57)\n * @brief Longest\
    \ Distance - DAG\u306B\u304A\u3051\u308B\u6700\u9577\u8DDD\u96E2\n * @version\
    \ 1.0\n * @date 2024-02-11\n */\n\n#include \"GraphTemplate.hpp\"\n\ntemplate<typename\
    \ CostType>\nvector<CostType> longestdistance(Graph<CostType> &G, CostType INF,\
    \ Vertex start = -1, CostType init = 0){\n    vector<CostType> dp(G.size(), INF);\n\
    \    if(start == -1){\n        for(auto v : G.source()) dp[v] = init;\n    }\n\
    \    else dp[start] = init;\n    for(int i : G.topological_sort()){\n        if(dp[i]\
    \ == INF) continue;\n        for(auto &e : G[i]){\n            dp[e.to] = max(dp[e.to],\
    \ dp[i] + e.cost);\n        }\n    }\n    return dp;\n}"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/LongestDistance.hpp
  requiredBy: []
  timestamp: '2024-02-11 13:53:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Graph/LongestDistance.hpp
layout: document
redirect_from:
- /library/library/Graph/LongestDistance.hpp
- /library/library/Graph/LongestDistance.hpp.html
title: "Longest Distance - DAG\u306B\u304A\u3051\u308B\u6700\u9577\u8DDD\u96E2"
---
