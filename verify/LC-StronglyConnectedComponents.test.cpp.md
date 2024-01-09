---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/Graph/StronglyConnectedComponents.hpp
    title: "Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/LC-StronglyConnectedComponents.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#line 1 \"library/Graph/StronglyConnectedComponents.hpp\"\
    \n/**\n * @file StronglyConnectedComponents.hpp\n * @brief Strongly Connected\
    \ Components - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @version 3.0\n *\
    \ @date 2024-01-09\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\n\n/**\n\
    \ * @file GraphTemplate.hpp\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 3.0\n * @date 2024-01-09\n */\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\nusing EdgeIndex\
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
    \        return m_es;\n    }\n};\n#line 9 \"library/Graph/StronglyConnectedComponents.hpp\"\
    \n\ntemplate<typename CostType>\nstruct StronglyConnectedComponents{\n    private:\n\
    \    GraphV<CostType> &G;\n    GraphV<CostType> rG;\n    vector<int> m_visited,\
    \ m_order, m_belong;\n    vector<vector<Vertex>> m_member;\n\n    void f_dfs(Vertex\
    \ v){\n        m_visited[v] = 1;\n        for(auto &e : G[v]){\n            if(!m_visited[e.to])\
    \ f_dfs(e.to);\n        }\n        m_order.push_back(v);\n    }\n\n    void f_rdfs(Vertex\
    \ v, int k){\n        m_visited[v] = 0;\n        m_belong[v] = k;\n        m_member[k].push_back(v);\n\
    \        for(auto &e : rG[v]){\n            if(m_visited[e.to]) f_rdfs(e.to, k);\n\
    \        }\n    }\n\n    public:\n    StronglyConnectedComponents(GraphV<CostType>\
    \ &G) : G(G){\n        rG = G.reverse();\n        m_visited.resize(G.size(), 0);\n\
    \        m_belong.resize(G.size(), -1);\n        for(int i = 0; i < G.size();\
    \ ++i){\n            if(!m_visited[i]) f_dfs(i);\n        }\n        int k = 0;\n\
    \        for(int i = m_order.size() - 1; i >= 0; --i){\n            if(m_visited[m_order[i]]){\n\
    \                m_member.push_back(vector<CostType>{});\n                f_rdfs(m_order[i],\
    \ k++);\n            }\n        }\n    }\n\n    int where(Vertex v){\n       \
    \ return m_belong.at(v);\n    }\n\n    bool same(Vertex u, Vertex v){\n      \
    \  return where(u) == where(v);\n    }\n\n    vector<vector<Vertex>> &get(){\n\
    \        return m_member;\n    }\n\n    GraphV<CostType> build(){\n        GraphV<CostType>\
    \ ret(m_member.size(), true);\n        for(int i = 0; i < G.size(); ++i){\n  \
    \          int from = where(i);\n            for(auto &e : G[i]){\n          \
    \      int to = where(e.to);\n                if(from == to) continue;\n     \
    \           ret.add(from, to, e.cost);\n            }\n        }\n        return\
    \ ret;\n    }\n\n    int operator[](Vertex v){\n        return where(v);\n   \
    \ }\n\n    void print(){\n        for(int i = 0; i < m_member.size(); ++i){\n\
    \            cout << \"Component \" << i << \" : \";\n            for(auto v :\
    \ m_member[i]){\n                cout << v << \" \";\n            }\n        \
    \    cout << endl;\n        }\n    }\n};\n#line 4 \"verify/LC-StronglyConnectedComponents.test.cpp\"\
    \n\nint main(){\n    int N, M; cin >> N >> M;\n    GraphV G(N, true);\n    G.input(M,\
    \ false, true);\n\n    StronglyConnectedComponents scc(G);\n    auto ans = scc.get();\n\
    \    cout << ans.size() << endl;\n    for(auto &vs : ans){\n        cout << vs.size();\n\
    \        for(auto &v : vs){\n            cout << \" \" << v;\n        }\n    \
    \    cout << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../library/Graph/StronglyConnectedComponents.hpp\"\
    \n\nint main(){\n    int N, M; cin >> N >> M;\n    GraphV G(N, true);\n    G.input(M,\
    \ false, true);\n\n    StronglyConnectedComponents scc(G);\n    auto ans = scc.get();\n\
    \    cout << ans.size() << endl;\n    for(auto &vs : ans){\n        cout << vs.size();\n\
    \        for(auto &v : vs){\n            cout << \" \" << v;\n        }\n    \
    \    cout << endl;\n    }\n}"
  dependsOn:
  - library/Graph/StronglyConnectedComponents.hpp
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify/LC-StronglyConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2024-01-09 23:25:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-StronglyConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-StronglyConnectedComponents.test.cpp
- /verify/verify/LC-StronglyConnectedComponents.test.cpp.html
title: verify/LC-StronglyConnectedComponents.test.cpp
---
