---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/Graph/Dijkstra.hpp
    title: Dijkstra
  - icon: ':warning:'
    path: library/Graph/VGraph.hpp
    title: Vertex Graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"verify/AOJ-GRL-1-A.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include <bits/stdc++.h>\n\n#line 2 \"library/Graph/VGraph.hpp\"\n\n#line\
    \ 4 \"library/Graph/VGraph.hpp\"\nusing namespace std;\n\n/**\n * @brief Vertex\
    \ Graph\n */\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u8FBA\n */\ntemplate<typename\
    \ T>\nstruct Edge{\n    int from, to;\n    T cost;\n\n    Edge(int from, int to,\
    \ T cost) : from(from), to(to), cost(cost){}\n};\n\n/**\n * @brief \u9802\u70B9\
    \u96C6\u5408\u3067\u7BA1\u7406\u3059\u308B\u30B0\u30E9\u30D5\n */\ntemplate<typename\
    \ T>\nstruct VGraph{\n    int sz; // \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\
    \n    bool directed; // \u6709\u5411\u30B0\u30E9\u30D5\u304B\n    vector<vector<Edge<T>>>\
    \ vertex; // \u9802\u70B9\u96C6\u5408\n    vector<int> indegree, outdegree; //\
    \ \u5165\u6B21\u6570\u3001\u51FA\u6B21\u6570\n\n    VGraph(int size, bool directed\
    \ = false) : sz(size), vertex(size), indegree(size, 0), outdegree(size, 0), directed(directed){}\n\
    \    VGraph() = default;\n\n    /**\n     * @brief \u7121\u5411\u30B0\u30E9\u30D5\
    \u306E\u5834\u5408\u306F\u9802\u70B9s\u3068\u9802\u70B9t\u3092\u7D50\u3076\u7121\
    \u5411\u8FBA\u3001\u6709\u5411\u30B0\u30E9\u30D5\u306E\u5834\u5408\u306F\u9802\
    \u70B9s\u304B\u3089\u9802\u70B9t\u3078\u306E\u6709\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\u3002\n     * \n     * @param s \u9802\u70B9s (0-index)\n     * @param\
    \ t \u9802\u70B9t (0-index)\n     * @param w \u91CD\u307F (\u7701\u7565\u53EF\u3001\
    \u7701\u7565\u6642\u306F1)\n     */\n    void add(int s, int t, T w = 1){\n  \
    \      vertex[s].push_back(Edge<T>(s, t, w));\n        ++outdegree[s];\n     \
    \   ++indegree[t];\n        if(!directed){\n            vertex[t].push_back(Edge<T>(t,\
    \ s, w));\n            ++indegree[s];\n            ++outdegree[t];\n        }\n\
    \    }\n\n    /**\n     * @brief \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\
    \u30D5\u3092\u8FD4\u3059\u3002\n     * @attention \u30B0\u30E9\u30D5\u304C\u6709\
    \u5411\u30B0\u30E9\u30D5\u3067\u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\
    \u3002\n     * @return VGraph<T> \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\
    \u30D5\n     */\n    VGraph<T> reverse(){\n        assert(directed == true);\n\
    \        VGraph<T> ret(sz, true);\n        for(int s = 0; s < sz; ++s){\n    \
    \        for(auto &e : vertex[s]){\n                ret.add(e.to, s, e.cost);\n\
    \            }\n        }\n        return ret;\n    }\n};\n#line 2 \"library/Graph/Dijkstra.hpp\"\
    \n\n#line 5 \"library/Graph/Dijkstra.hpp\"\nusing namespace std;\n\n/**\n * @brief\
    \ Dijkstra\n */\n\n/**\n * @brief  \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u3067\
    \u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u3002\n * @attention \u30B0\u30E9\
    \u30D5\u306B\u8CA0\u306E\u91CD\u307F\u306E\u8FBA\u304C\u306A\u3044\u5FC5\u8981\
    \u304C\u3042\u308B\u3002\n */\ntemplate<typename T>\nstruct Dijkstra{\n    private:\n\
    \    VGraph<T> &G;\n    vector<int> prev_vertex;\n\n    public:\n    vector<T>\
    \ dist;\n    T INF;\n\n    Dijkstra(VGraph<T> &G) : G(G), dist(G.sz), INF(numeric_limits<T>::max()),\
    \ prev_vertex(G.sz){}\n\n    /**\n     * @brief  \u9802\u70B9s\u3092\u59CB\u70B9\
    \u3068\u3057\u3066\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u3092\u9069\u7528\
    \u3059\u308B\u3002\n     * @param  s: \u59CB\u70B9\u3068\u306A\u308B\u9802\u70B9\
    s\n     * @note   \u6C42\u3081\u3089\u308C\u305F\u6700\u77ED\u8DDD\u96E2\u306F\
    dist\u306B\u683C\u7D0D\u3055\u308C\u308B\u3002\n     */\n    void build(int s){\n\
    \        dist.assign(G.sz, INF);\n        prev_vertex.assign(G.sz, -1);\n    \
    \    using p = pair<T, int>;\n        priority_queue<p, vector<p>, greater<p>>\
    \ que;\n        que.emplace(0, s);\n        dist[s] = 0;\n        while(!que.empty()){\n\
    \            auto [d, v] = que.top();\n            que.pop();\n            if(dist[v]\
    \ < d) continue;\n            for(auto &e : G.vertex[v]){\n                if(d\
    \ + e.cost < dist[e.to]){\n                    dist[e.to] = d + e.cost;\n    \
    \                prev_vertex[e.to] = v;\n                    que.emplace(d + e.cost,\
    \ e.to);\n                }\n            }\n        }\n    }\n\n    /**\n    \
    \ * @brief  \u9802\u70B9s\u304B\u3089\u9802\u70B9t\u3078\u306E\u6700\u77ED\u7D4C\
    \u8DEF\u3092\u53D6\u5F97\u3059\u308B\n     * @attention \u4E88\u3081build\u3067\
    \u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u5FC5\u8981\u304C\u3042\u308B\
    \u3002\n     * @param  t: \u7D42\u70B9\u3068\u306A\u308B\u9802\u70B9t\n     *\
    \ @retval \u6700\u77ED\u7D4C\u8DEF\n     */\n    vector<int> restore(int t){\n\
    \        vector<int> ret;\n        int v = t;\n        while(v != -1){\n     \
    \       ret.push_back(v);\n            v = prev_vertex[v];\n        }\n      \
    \  reverse(ret.begin(), ret.end());\n        return ret;\n    }\n};\n#line 7 \"\
    verify/AOJ-GRL-1-A.cpp\"\n\nusing namespace std;\n\n\nint main(){\n    int V,\
    \ E, r;\n    cin >> V >> E >> r;\n    VGraph<long long> G(V, true);\n    for(int\
    \ i = 0; i < E; ++i){\n        int s, t;\n        long long d;\n        cin >>\
    \ s >> t >> d;\n        G.add(s, t, d);\n    }\n\n    Dijkstra<long long> ds(G);\n\
    \    ds.build(r);\n    for(int i = 0; i < V; ++i){\n        if(ds.dist[i] == ds.INF){\n\
    \            cout << \"INF\" << endl;\n        }\n        else{\n            cout\
    \ << ds.dist[i] << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../library/Graph/VGraph.hpp\"\n#include\
    \ \"../library/Graph/Dijkstra.hpp\"\n\nusing namespace std;\n\n\nint main(){\n\
    \    int V, E, r;\n    cin >> V >> E >> r;\n    VGraph<long long> G(V, true);\n\
    \    for(int i = 0; i < E; ++i){\n        int s, t;\n        long long d;\n  \
    \      cin >> s >> t >> d;\n        G.add(s, t, d);\n    }\n\n    Dijkstra<long\
    \ long> ds(G);\n    ds.build(r);\n    for(int i = 0; i < V; ++i){\n        if(ds.dist[i]\
    \ == ds.INF){\n            cout << \"INF\" << endl;\n        }\n        else{\n\
    \            cout << ds.dist[i] << endl;\n        }\n    }\n}"
  dependsOn:
  - library/Graph/VGraph.hpp
  - library/Graph/Dijkstra.hpp
  isVerificationFile: false
  path: verify/AOJ-GRL-1-A.cpp
  requiredBy: []
  timestamp: '2023-06-08 14:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/AOJ-GRL-1-A.cpp
layout: document
redirect_from:
- /library/verify/AOJ-GRL-1-A.cpp
- /library/verify/AOJ-GRL-1-A.cpp.html
title: verify/AOJ-GRL-1-A.cpp
---
