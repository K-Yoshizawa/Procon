---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-4-A.test.cpp
    title: verify/AOJ-GRL-4-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Cycle Detection (Directed) - \u9589\u8DEF\u691C\u51FA\uFF08\u6709\
      \u5411\u30B0\u30E9\u30D5\uFF09"
    links: []
  bundledCode: "#line 2 \"library/Graph/CycleDetection.hpp\"\n\n/**\n * @brief Cycle\
    \ Detection (Directed) - \u9589\u8DEF\u691C\u51FA\uFF08\u6709\u5411\u30B0\u30E9\
    \u30D5\uFF09\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2\
    \ \"library/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n * @author\
    \ log K (lX57)\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n * @version 1.2\n * @date 2023-08-24\n */\n\n#line 12 \"library/Graph/GraphTemplate.hpp\"\
    \nusing namespace std;\n\nusing EdgeNum = int;\nusing Vertex = int;\n\n/**\n *\
    \ @brief \u30B0\u30E9\u30D5\u306E\u8FBA\n */\ntemplate<typename CostType = int>\n\
    struct Edge{\n    Vertex from, to;\n    CostType cost;\n\n    Edge(Vertex from,\
    \ Vertex to, CostType cost) : from(from), to(to), cost(cost){}\n};\n\n/**\n *\
    \ @brief \u30B0\u30E9\u30D5\u3092\u8868\u3059\u30AF\u30E9\u30B9\u3002\n * @note\
    \ \u8FBA\u96C6\u5408\u306B\u3088\u3063\u3066\u5B9F\u73FE\u3057\u3066\u3044\u308B\
    \u3002\n * @tparam CostType \u8FBA\u306E\u91CD\u307F\u306E\u578B\u3002\n */\n\
    template<typename CostType = int>\nclass Graph{\n    private:\n    int sz;\n \
    \   bool dir;\n    vector<int> indegree;\n\n    public:\n    vector<Edge<CostType>>\
    \ edges;\n    vector<vector<EdgeNum>> connect;\n    vector<EdgeNum> rev; // \u5F62\
    \u5F0F\u4E0A\u7121\u5411\u30B0\u30E9\u30D5\u3067\u3082\u6709\u5411\u8FBA\u3092\
    \u8FFD\u52A0\u3059\u308B\u306E\u3067\u3001\u8FBA\u306E\u8FFD\u52A0\u6642\u306B\
    \u9006\u8FBA\u306E\u8FBA\u756A\u53F7\u3092\u8A18\u9332\u3067\u304D\u308B\u3088\
    \u3046\u306B\u3059\u308B\n    CostType INF;\n\n    /**\n     * @brief Construct\
    \ a new Graph object\n     * @param VertexNum \u30B0\u30E9\u30D5\u306E\u9802\u70B9\
    \u6570\n     * @param isDirected \u6709\u5411\u30B0\u30E9\u30D5\u3068\u3057\u3066\
    \u4F5C\u6210\u3059\u308B\u304B\n     */\n    Graph(int VertexNum, bool isDirected\
    \ = false) : sz(VertexNum), dir(isDirected), connect(VertexNum), indegree(VertexNum),\
    \ INF(numeric_limits<CostType>::max() / 2){}\n\n    Graph() = default;\n\n   \
    \ /**\n     * @brief \u30B0\u30E9\u30D5\u306B\u9802\u70B9s\u3068\u9802\u70B9t\u9593\
    \u306E\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\n     * @note \u6709\u5411\u30B0\
    \u30E9\u30D5\u306A\u3089\u3070\u9802\u70B9s\u304B\u3089\u9802\u70B9t\u3078\u306E\
    \u6709\u5411\u8FBA\u3092\u3001\u7121\u5411\u30B0\u30E9\u30D5\u306A\u3089\u3070\
    \u9802\u70B9s\u3068\u9802\u70B9t\u3092\u7D50\u3076\u7121\u5411\u8FBA\u3092\u8FFD\
    \u52A0\u3059\u308B\u3002\n     * @param s \u9802\u70B9s\n     * @param t \u9802\
    \u70B9t\n     * @param w \u8FBA\u306E\u91CD\u307F (option, default = 1)\n    \
    \ */\n    void add(Vertex s, Vertex t, CostType w = 1){\n        assert(0 <= s\
    \ && s < sz);\n        assert(0 <= t && t < sz);\n        EdgeNum e = edges.size();\n\
    \        edges.push_back(Edge<CostType>(s, t, w));\n        connect[s].push_back(e);\n\
    \        ++indegree[t];\n        if(!dir){\n            edges.push_back(Edge<CostType>(t,\
    \ s, w));\n            connect[t].push_back(e + 1);\n            rev.emplace_back(e\
    \ + 1);\n            rev.emplace_back(e);\n        }\n    }\n\n    /**\n     *\
    \ @brief \u6307\u5B9A\u3057\u305F\u8FBA\u756A\u53F7\u306E\u8FBA\u3092\u53D6\u5F97\
    \u3059\u308B\u3002\n     * @param idx \u8FBA\u756A\u53F7\n     * @return Edge<CostType>\
    \ \u8FBA\u60C5\u5831\n     */\n    Edge<CostType> get_edge(EdgeNum idx){\n   \
    \     int e = edges.size();\n        assert(0 <= idx && idx < e);\n        return\
    \ edges[idx];\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3057\u305F\u9802\u70B9\
    \u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\u8FBA\u306E\u4E00\u89A7\u3092\u53D6\
    \u5F97\u3059\u308B\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return\
    \ vector<Edge<CostType>> \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\
    \u63A5\u7D9A\u3059\u308B\u8FBA\u306E\u4E00\u89A7\n     */\n    vector<Edge<CostType>>\
    \ get_edges(Vertex v){\n        assert(0 <= v && v < sz);\n        vector<Edge<CostType>>\
    \ ret;\n        for(auto &idx : connect[v]) ret.push_back(get_edge(idx));\n  \
    \      return ret;\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3057\u305F\u9802\
    \u70B9\u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\u8FBA\u756A\u53F7\u306E\u4E00\
    \u89A7\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param v \u9802\u70B9\u756A\
    \u53F7\n     * @return vector<EdgeNum> \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\
    \u53F7\u306B\u63A5\u7D9A\u3059\u308B\u8FBA\u756A\u53F7\u306E\u4E00\u89A7\n   \
    \  */\n    vector<EdgeNum> get_list(Vertex v){\n        assert(0 <= v && v < sz);\n\
    \        return connect[v];\n    }\n\n    /**\n     * @brief \u9006\u8FBA\u3092\
    \u5F35\u3063\u305F\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\u3002\n   \
    \  * @attention \u3053\u306E\u64CD\u4F5C\u306F\u6709\u5411\u30B0\u30E9\u30D5\u306B\
    \u306E\u307F\u53EF\u80FD\u3067\u3042\u308B\u3002\n     * @return Graph<CostType>\
    \ \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\u30D5\n     */\n    Graph<CostType>\
    \ reverse(){\n        assert(dir);\n        Graph<CostType> ret(sz, true);\n \
    \       for(auto &e : edges){\n            ret.add(e.to, e.from, e.cost);\n  \
    \      }\n        return ret;\n    }\n\n    inline size_t size(){\n        return\
    \ sz;\n    }\n\n    inline bool directed(){\n        return dir;\n    }\n\n  \
    \  /**\n     * @brief \u3042\u308B\u9802\u70B9\u306E\u6B21\u6570(\u51FA\u6B21\u6570\
    )\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @note \u6709\u5411\u30B0\u30E9\u30D5\
    \u306B\u304A\u3044\u3066\u3001\u7B2C2\u5F15\u6570\u3092true\u306B\u3059\u308C\u3070\
    \u5165\u6B21\u6570\u3092\u5F97\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\
    \n     * @param v \u9802\u70B9\u756A\u53F7\n     * @param isIn (\u6709\u5411\u30B0\
    \u30E9\u30D5\u306E\u3068\u304D\u306E\u307F\u6709\u52B9)\u5165\u6B21\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\u304B (option, default = false)\n     * @return int \u9802\
    \u70B9v\u306E\u6307\u5B9A\u3057\u305F\u5024\n     */\n    inline int degree(Vertex\
    \ v, bool isIn = false){\n        if(dir && isIn) return indegree[v];\n      \
    \  return (int)connect[v].size();\n    }\n\n    /**\n     * @brief \u30B0\u30E9\
    \u30D5\u3092\u9802\u70B9root\u3092\u6839\u3068\u3057\u305F\u7121\u5411\u6839\u4ED8\
    \u304D\u6728\u3068\u307F\u306A\u3057\u305F\u3068\u304D\u3001\u5404\u9802\u70B9\
    \u306E\u89AA\u9802\u70B9\u306E\u756A\u53F7\u3068\u3001\u305D\u308C\u3092\u7D50\
    \u3076\u8FBA\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @attention\
    \ \u30B0\u30E9\u30D5\u304C\u7121\u5411\u6728\u3067\u306A\u3044\u5834\u5408\u306E\
    \u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9\u3067\u3042\u308B\u3002\n     * @param root\
    \ \u6728\u306E\u6839\u3068\u3059\u308B\u9802\u70B9\u756A\u53F7\n     * @return\
    \ vector<pair<Vertex, EdgeNum>> \u5404\u9802\u70B9\u306E\u89AA\u306E\u9802\u70B9\
    \u756A\u53F7\u3068\u89AA\u3078\u306E\u8FBA\u756A\u53F7\uFF08\u9802\u70B9root\u306B\
    \u5BFE\u3057\u3066\u306F\u3069\u3061\u3089\u3082-1\u3068\u3059\u308B\uFF09\n \
    \    */\n    vector<pair<Vertex, EdgeNum>> get_parent(Vertex root){\n        vector<pair<Vertex,\
    \ EdgeNum>> ret(sz, pair<Vertex, EdgeNum>(-1, -1));\n        stack<pair<Vertex,\
    \ Vertex>> st;\n        st.emplace(root, -1);\n        while(!st.empty()){\n \
    \           auto [v, parent] = st.top();\n            st.pop();\n            for(auto\
    \ &idx : connect[v]){\n                if(edges[idx].to == parent) continue;\n\
    \                ret[edges[idx].to] = pair<Vertex, EdgeNum>(v, rev[idx]);\n  \
    \              st.emplace(edges[idx].to, v);\n            }\n        }\n     \
    \   return ret;\n    }\n};\n#line 11 \"library/Graph/CycleDetection.hpp\"\n\n\
    /**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u691C\u51FA\u3092\
    \u884C\u3046\u3002\n */\ntemplate<typename CostType>\nstruct CycleDetection{\n\
    \    vector<vector<Vertex>> cycle;\n    \n    private:\n    Graph<CostType> &G;\n\
    \    vector<Vertex> visited, history;\n    vector<Vertex> belong;\n    vector<Vertex>\
    \ tmp;\n\n    void dfs(int v){\n        visited[v] = 1;\n        history.push_back(v);\n\
    \        for(auto &e : G.get_edges(v)){\n            if(visited[e.to] == 2) continue;\n\
    \            if(visited[e.to] == 1){\n                for(int i = history.size()\
    \ - 1; ; --i){\n                    tmp.push_back(history[i]);\n             \
    \       belong[history[i]] = cycle.size();\n                    if(history[i]\
    \ == e.to) break;\n                }\n                cycle.push_back(tmp);\n\
    \                tmp.clear();\n            }\n            else{\n            \
    \    dfs(e.to);\n            }\n        }\n        history.pop_back();\n     \
    \   visited[v] = 2;\n    }\n\n    public:\n    CycleDetection(Graph<CostType>\
    \ &G) : G(G), visited(G.size(), 0), belong(G.size(), -1){\n        assert(G.directed());\n\
    \        for(int i = 0; i < G.size(); ++i){\n            if(!visited[i]) dfs(i);\n\
    \        }\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5G\u304C\u9589\u8DEF\
    \u3092\u6301\u3064\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool\
    \ exist(){\n        return cycle.size() > 0;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Cycle Detection (Directed) - \u9589\u8DEF\u691C\
    \u51FA\uFF08\u6709\u5411\u30B0\u30E9\u30D5\uFF09\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"GraphTemplate.hpp\"\n\n/**\n * @brief \u6709\
    \u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u691C\u51FA\u3092\u884C\u3046\u3002\
    \n */\ntemplate<typename CostType>\nstruct CycleDetection{\n    vector<vector<Vertex>>\
    \ cycle;\n    \n    private:\n    Graph<CostType> &G;\n    vector<Vertex> visited,\
    \ history;\n    vector<Vertex> belong;\n    vector<Vertex> tmp;\n\n    void dfs(int\
    \ v){\n        visited[v] = 1;\n        history.push_back(v);\n        for(auto\
    \ &e : G.get_edges(v)){\n            if(visited[e.to] == 2) continue;\n      \
    \      if(visited[e.to] == 1){\n                for(int i = history.size() - 1;\
    \ ; --i){\n                    tmp.push_back(history[i]);\n                  \
    \  belong[history[i]] = cycle.size();\n                    if(history[i] == e.to)\
    \ break;\n                }\n                cycle.push_back(tmp);\n         \
    \       tmp.clear();\n            }\n            else{\n                dfs(e.to);\n\
    \            }\n        }\n        history.pop_back();\n        visited[v] = 2;\n\
    \    }\n\n    public:\n    CycleDetection(Graph<CostType> &G) : G(G), visited(G.size(),\
    \ 0), belong(G.size(), -1){\n        assert(G.directed());\n        for(int i\
    \ = 0; i < G.size(); ++i){\n            if(!visited[i]) dfs(i);\n        }\n \
    \   }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5G\u304C\u9589\u8DEF\u3092\u6301\
    \u3064\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool exist(){\n\
    \        return cycle.size() > 0;\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/CycleDetection.hpp
  requiredBy: []
  timestamp: '2023-08-24 15:24:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-4-A.test.cpp
documentation_of: library/Graph/CycleDetection.hpp
layout: document
redirect_from:
- /library/library/Graph/CycleDetection.hpp
- /library/library/Graph/CycleDetection.hpp.html
title: "Cycle Detection (Directed) - \u9589\u8DEF\u691C\u51FA\uFF08\u6709\u5411\u30B0\
  \u30E9\u30D5\uFF09"
---
