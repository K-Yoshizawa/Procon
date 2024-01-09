---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/Dijkstra.hpp
    title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/LC-ShortestPath.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
    \n\n#line 1 \"library/Graph/Dijkstra.hpp\"\n/**\n * @file Dijkstra.hpp\n * @brief\
    \ Dijkstra - \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @version 3.0\n * @date\
    \ 2024-01-09\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\n\n/**\n * @file\
    \ GraphTemplate.hpp\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\n * @version 3.0\n * @date 2024-01-09\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\nusing EdgeIndex\
    \ = int;\n\ntemplate<typename CostType>\nstruct Edge{\n    public:\n    Vertex\
    \ from, to;\n    CostType cost;\n    EdgeIndex idx{-1};\n\n    Edge() = default;\n\
    \    Edge(Vertex from, Vertex to, CostType cost) : from(from), to(to), cost(cost){}\n\
    \n    operator int(){\n        return to;\n    }\n};\n\ntemplate<typename CostType\
    \ = int>\nstruct GraphV{\n    private:\n    int m_vertex_size{0}, m_edge_size{0};\n\
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
    \        return m_es;\n    }\n};\n#line 9 \"library/Graph/Dijkstra.hpp\"\n\ntemplate<typename\
    \ CostType>\nstruct Dijkstra{\n    private:\n    GraphV<CostType> &G;\n    vector<CostType>\
    \ m_dist, m_potential;\n    vector<Vertex> m_prev_vertex;\n\n    public:\n   \
    \ Dijkstra(GraphV<CostType> &G) : G(G){\n        m_dist.resize(G.size());\n  \
    \      m_potential.resize(G.size(), 0);\n        m_prev_vertex.resize(G.size(),\
    \ -1);\n    }\n\n    vector<CostType> &solve(Vertex s){\n        assert(0 <= s\
    \ and s < G.size());\n        m_dist.assign(G.size(), G.INF);\n        using p\
    \ = pair<CostType, Vertex>;\n        priority_queue<p, vector<p>, greater<p>>\
    \ que;\n        que.emplace(m_potential[s], s);\n        m_dist[s] = m_potential[s];\n\
    \        while(que.size()){\n            auto [d, v] = que.top(); que.pop();\n\
    \            if(m_dist[v] < d) continue;\n            for(auto &e : G[v]){\n \
    \               if(d + e.cost + m_potential[e.from] - m_potential[e.to] < m_dist[e.to]){\n\
    \                    m_dist[e.to] = d + e.cost + m_potential[e.from] - m_potential[e.to];\n\
    \                    m_prev_vertex[e.to] = v;\n                    que.emplace(m_dist[e.to],\
    \ e.to);\n                }\n            }\n        }\n        for(Vertex i =\
    \ 0; i < G.size(); ++i){\n            if(m_dist[i] != G.INF){\n              \
    \  m_dist[i] += m_potential[i] - m_potential[s];\n            }\n        }\n \
    \       return m_dist;\n    }\n\n    vector<CostType> &get(){\n        return\
    \ m_dist;\n    }\n\n    vector<CostType> shortest_path(Vertex t){\n        vector<CostType>\
    \ ret{t};\n        Vertex now = t;\n        while(m_prev_vertex[now] != -1){\n\
    \            ret.push_back(m_prev_vertex[now]);\n            now = m_prev_vertex[now];\n\
    \        }\n        reverse(ret.begin(), ret.end());\n        return ret;\n  \
    \  }\n\n    CostType operator[](Vertex v){\n        return m_dist.at(v);\n   \
    \ }\n};\n#line 4 \"verify/LC-ShortestPath.test.cpp\"\n\nint main(){\n    int N,\
    \ M, s, t; cin >> N >> M >> s >> t;\n    GraphV<long long> G(N, true);\n    G.input(M,\
    \ true, true);\n\n    Dijkstra dk(G);\n    if(dk.solve(s)[t] == G.INF){\n    \
    \    cout << -1 << endl;\n        return 0;\n    }\n    auto ans = dk.shortest_path(t);\n\
    \    cout << dk[t] << \" \" << ans.size() - 1 << endl;\n    for(int i = 0; i <\
    \ ans.size() - 1; ++i){\n        cout << ans[i] << \" \" << ans[i + 1] << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../library/Graph/Dijkstra.hpp\"\n\nint main(){\n    int N, M, s, t; cin >>\
    \ N >> M >> s >> t;\n    GraphV<long long> G(N, true);\n    G.input(M, true, true);\n\
    \n    Dijkstra dk(G);\n    if(dk.solve(s)[t] == G.INF){\n        cout << -1 <<\
    \ endl;\n        return 0;\n    }\n    auto ans = dk.shortest_path(t);\n    cout\
    \ << dk[t] << \" \" << ans.size() - 1 << endl;\n    for(int i = 0; i < ans.size()\
    \ - 1; ++i){\n        cout << ans[i] << \" \" << ans[i + 1] << endl;\n    }\n}"
  dependsOn:
  - library/Graph/Dijkstra.hpp
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify/LC-ShortestPath.test.cpp
  requiredBy: []
  timestamp: '2024-01-09 23:25:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-ShortestPath.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-ShortestPath.test.cpp
- /verify/verify/LC-ShortestPath.test.cpp.html
title: verify/LC-ShortestPath.test.cpp
---
