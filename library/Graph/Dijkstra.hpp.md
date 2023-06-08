---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/Dijkstra.test.cpp
    title: verify/Dijkstra.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Dijkstra
    links: []
  bundledCode: "#line 2 \"library/Graph/Dijkstra.hpp\"\n\n/**\n * @brief Dijkstra\n\
    \ */\n\n/**\n * @brief  \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u3067\u6700\
    \u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u3002\n * @attention \u30B0\u30E9\u30D5\
    \u306B\u8CA0\u306E\u91CD\u307F\u306E\u8FBA\u304C\u306A\u3044\u5FC5\u8981\u304C\
    \u3042\u308B\u3002\n */\ntemplate<typename T>\nstruct Dijkstra{\n    private:\n\
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
    \  reverse(ret.begin(), ret.end());\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Dijkstra\n */\n\n/**\n * @brief  \u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\u6CD5\u3067\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\
    \u308B\u3002\n * @attention \u30B0\u30E9\u30D5\u306B\u8CA0\u306E\u91CD\u307F\u306E\
    \u8FBA\u304C\u306A\u3044\u5FC5\u8981\u304C\u3042\u308B\u3002\n */\ntemplate<typename\
    \ T>\nstruct Dijkstra{\n    private:\n    VGraph<T> &G;\n    vector<int> prev_vertex;\n\
    \n    public:\n    vector<T> dist;\n    T INF;\n\n    Dijkstra(VGraph<T> &G) :\
    \ G(G), dist(G.sz), INF(numeric_limits<T>::max()), prev_vertex(G.sz){}\n\n   \
    \ /**\n     * @brief  \u9802\u70B9s\u3092\u59CB\u70B9\u3068\u3057\u3066\u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\u6CD5\u3092\u9069\u7528\u3059\u308B\u3002\n     * @param\
    \  s: \u59CB\u70B9\u3068\u306A\u308B\u9802\u70B9s\n     * @note   \u6C42\u3081\
    \u3089\u308C\u305F\u6700\u77ED\u8DDD\u96E2\u306Fdist\u306B\u683C\u7D0D\u3055\u308C\
    \u308B\u3002\n     */\n    void build(int s){\n        dist.assign(G.sz, INF);\n\
    \        prev_vertex.assign(G.sz, -1);\n        using p = pair<T, int>;\n    \
    \    priority_queue<p, vector<p>, greater<p>> que;\n        que.emplace(0, s);\n\
    \        dist[s] = 0;\n        while(!que.empty()){\n            auto [d, v] =\
    \ que.top();\n            que.pop();\n            if(dist[v] < d) continue;\n\
    \            for(auto &e : G.vertex[v]){\n                if(d + e.cost < dist[e.to]){\n\
    \                    dist[e.to] = d + e.cost;\n                    prev_vertex[e.to]\
    \ = v;\n                    que.emplace(d + e.cost, e.to);\n                }\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief  \u9802\u70B9s\u304B\
    \u3089\u9802\u70B9t\u3078\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\u53D6\u5F97\u3059\
    \u308B\n     * @attention \u4E88\u3081build\u3067\u6700\u77ED\u8DDD\u96E2\u3092\
    \u6C42\u3081\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n     * @param  t: \u7D42\
    \u70B9\u3068\u306A\u308B\u9802\u70B9t\n     * @retval \u6700\u77ED\u7D4C\u8DEF\
    \n     */\n    vector<int> restore(int t){\n        vector<int> ret;\n       \
    \ int v = t;\n        while(v != -1){\n            ret.push_back(v);\n       \
    \     v = prev_vertex[v];\n        }\n        reverse(ret.begin(), ret.end());\n\
    \        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/Graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2023-06-08 13:21:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/Dijkstra.test.cpp
documentation_of: library/Graph/Dijkstra.hpp
layout: document
redirect_from:
- /library/library/Graph/Dijkstra.hpp
- /library/library/Graph/Dijkstra.hpp.html
title: Dijkstra
---
