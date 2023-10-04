---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ/AOJ-GRL-3-C.test.cpp
    title: verify/AOJ/AOJ-GRL-3-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\
      \u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"library/Graph/StronglyConnectedComponents.hpp\"\n\n/**\n\
    \ * @brief Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\u5206\
    \u89E3\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 1.2\n * @date 2023-08-24\n */\n\n#line 12 \"library/Graph/GraphTemplate.hpp\"\
    \nusing namespace std;\n\nusing EdgeNum = int;\nusing Vertex = int;\n\n/**\n *\
    \ @brief \u30B0\u30E9\u30D5\u306E\u8FBA\n */\ntemplate<typename CostType = int>\n\
    struct Edge{\n    Vertex from, to;\n    CostType cost;\n\n    Edge(Vertex from,\
    \ Vertex to, CostType cost) : from(from), to(to), cost(cost){}\n};\n\n/**\n *\
    \ @brief \u30B0\u30E9\u30D5\u3092\u8868\u3059\u30AF\u30E9\u30B9\u3002\n * @note\
    \ \u8FBA\u96C6\u5408\u306B\u3088\u3063\u3066\u5B9F\u73FE\u3057\u3066\u3044\u308B\
    \u3002\n * @tparam CostType \u8FBA\u306E\u91CD\u307F\u306E\u578B\u3002\n */\n\
    template<typename CostType = int>\nclass Graph{\n    private:\n    int sz;\n \
    \   bool isDirected, isTree;\n    vector<int> indegree;\n\n    public:\n    vector<Edge<CostType>>\
    \ edges; // \u30B0\u30E9\u30D5\u306E\u8FBA\u96C6\u5408\n    vector<vector<EdgeNum>>\
    \ connect; // \u5404\u9802\u70B9\u3092\u7AEF\u70B9\u3068\u3059\u308B\u8FBA\u306E\
    \u756A\u53F7\u4E00\u89A7\n    vector<EdgeNum> rev; // \u7121\u5411\u30B0\u30E9\
    \u30D5\u3092\u6709\u5411\u8FBA*2\u3068\u3057\u3066\u8FFD\u52A0\u3059\u308B\u306E\
    \u3067\u3001\u8FBA\u306E\u8FFD\u52A0\u6642\u306B\u9006\u8FBA\u306E\u8FBA\u756A\
    \u53F7\u3092\u8A18\u9332\u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\n   \
    \ CostType INF;\n\n    /**\n     * @brief Construct a new Graph object\n     *\
    \ @param VertexNum \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\n     * @param isDirected\
    \ \u6709\u5411\u30B0\u30E9\u30D5\u3068\u3057\u3066\u4F5C\u6210\u3059\u308B\u304B\
    (default = false)\n     * @param isTree \u6728\u3068\u3057\u3066\u4F5C\u6210\u3059\
    \u308B\u304B(default = false)\n     */\n    Graph(int VertexNum, bool isDirected\
    \ = false, bool isTree = false) : sz(VertexNum), isDirected(isDirected), isTree(isTree),\
    \ connect(VertexNum), indegree(VertexNum), INF(numeric_limits<CostType>::max()\
    \ / 2){}\n\n    Graph() = default;\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\
    \u306B\u9802\u70B9s\u3068\u9802\u70B9t\u9593\u306E\u8FBA\u3092\u8FFD\u52A0\u3059\
    \u308B\u3002\n     * @note \u6709\u5411\u30B0\u30E9\u30D5\u306A\u3089\u3070\u9802\
    \u70B9s\u304B\u3089\u9802\u70B9t\u3078\u306E\u6709\u5411\u8FBA\u3092\u3001\u7121\
    \u5411\u30B0\u30E9\u30D5\u306A\u3089\u3070\u9802\u70B9s\u3068\u9802\u70B9t\u3092\
    \u7D50\u3076\u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\n     * @param\
    \ s \u9802\u70B9s\n     * @param t \u9802\u70B9t\n     * @param w \u8FBA\u306E\
    \u91CD\u307F (option, default = 1)\n     */\n    void add(Vertex s, Vertex t,\
    \ CostType w = 1){\n        assert(0 <= s && s < sz);\n        assert(0 <= t &&\
    \ t < sz);\n        EdgeNum e = edges.size();\n        edges.push_back(Edge<CostType>(s,\
    \ t, w));\n        connect[s].push_back(e);\n        ++indegree[t];\n        if(!isDirected){\n\
    \            edges.push_back(Edge<CostType>(t, s, w));\n            connect[t].push_back(e\
    \ + 1);\n            rev.emplace_back(e + 1);\n            rev.emplace_back(e);\n\
    \        }\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u3078\u306E\u5165\
    \u529B\u51E6\u7406\u3092\u884C\u3046\u3002\n     * @param amount \u8FBA\u306E\u6570\
    \n     * @param isWeighted \u91CD\u307F\u3064\u304D\u30B0\u30E9\u30D5\u304B\uFF1F\
    (default = true)\n     * @param isOne_index 1-index\u304B\uFF1F(default = true)\n\
    \     */\n    void input(int amount, bool isWeighted = true, bool isOne_index\
    \ = true){\n        for(int i = 0; i < amount; ++i){\n            Vertex s, t;\
    \ cin >> s >> t;\n            if(isOne_index) --s, --t;\n            CostType\
    \ w = 1;\n            if(isWeighted) cin >> w;\n            add(s, t, w);\n  \
    \      }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3057\u305F\u8FBA\u756A\
    \u53F7\u306E\u8FBA\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param idx \u8FBA\
    \u756A\u53F7\n     * @return Edge<CostType> \u8FBA\u60C5\u5831\n     */\n    Edge<CostType>\
    \ get_edge(EdgeNum idx){\n        int e = edges.size();\n        assert(0 <= idx\
    \ && idx < e);\n        return edges[idx];\n    }\n\n    /**\n     * @brief \u6307\
    \u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\u8FBA\
    \u306E\u4E00\u89A7\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param v \u9802\
    \u70B9\u756A\u53F7\n     * @return vector<Edge<CostType>> \u6307\u5B9A\u3057\u305F\
    \u9802\u70B9\u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\u8FBA\u306E\u4E00\u89A7\
    \n     */\n    vector<Edge<CostType>> get_edges(Vertex v){\n        assert(0 <=\
    \ v && v < sz);\n        vector<Edge<CostType>> ret;\n        for(auto &idx :\
    \ connect[v]) ret.push_back(get_edge(idx));\n        return ret;\n    }\n\n  \
    \  /**\n     * @brief \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\u63A5\
    \u7D9A\u3059\u308B\u8FBA\u756A\u53F7\u306E\u4E00\u89A7\u3092\u53D6\u5F97\u3059\
    \u308B\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return vector<EdgeNum>\
    \ \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\
    \u8FBA\u756A\u53F7\u306E\u4E00\u89A7\n     */\n    vector<EdgeNum> get_list(Vertex\
    \ v){\n        assert(0 <= v && v < sz);\n        return connect[v];\n    }\n\n\
    \    /**\n     * @brief \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\u30D5\
    \u3092\u4F5C\u6210\u3059\u308B\u3002\n     * @attention \u3053\u306E\u64CD\u4F5C\
    \u306F\u6709\u5411\u30B0\u30E9\u30D5\u306B\u306E\u307F\u53EF\u80FD\u3067\u3042\
    \u308B\u3002\n     * @return Graph<CostType> \u9006\u8FBA\u3092\u5F35\u3063\u305F\
    \u30B0\u30E9\u30D5\n     */\n    Graph<CostType> reverse(){\n        assert(isDirected);\n\
    \        Graph<CostType> ret(sz, true, isTree);\n        for(auto &e : edges){\n\
    \            ret.add(e.to, e.from, e.cost);\n        }\n        return ret;\n\
    \    }\n\n    inline size_t size(){\n        return sz;\n    }\n\n    inline bool\
    \ directed(){\n        return isDirected;\n    }\n\n    /**\n     * @brief \u3042\
    \u308B\u9802\u70B9\u306E\u6B21\u6570(\u51FA\u6B21\u6570)\u3092\u53D6\u5F97\u3059\
    \u308B\u3002\n     * @note \u6709\u5411\u30B0\u30E9\u30D5\u306B\u304A\u3044\u3066\
    \u3001\u7B2C2\u5F15\u6570\u3092true\u306B\u3059\u308C\u3070\u5165\u6B21\u6570\u3092\
    \u5F97\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\n     * @param v \u9802\
    \u70B9\u756A\u53F7\n     * @param isIn (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u3068\
    \u304D\u306E\u307F\u6709\u52B9)\u5165\u6B21\u6570\u3092\u53D6\u5F97\u3059\u308B\
    \u304B (default = false)\n     * @return int \u9802\u70B9v\u306E\u6307\u5B9A\u3057\
    \u305F\u5024\n     */\n    inline int degree(Vertex v, bool isIn = false){\n \
    \       if(isDirected && isIn) return indegree[v];\n        return (int)connect[v].size();\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u3092\u9802\u70B9root\u3092\
    \u6839\u3068\u3057\u305F\u7121\u5411\u6839\u4ED8\u304D\u6728\u3068\u307F\u306A\
    \u3057\u305F\u3068\u304D\u3001\u5404\u9802\u70B9\u306E\u89AA\u9802\u70B9\u306E\
    \u756A\u53F7\u3068\u3001\u305D\u308C\u3092\u7D50\u3076\u8FBA\u756A\u53F7\u3092\
    \u53D6\u5F97\u3059\u308B\u3002\n     * @attention \u30B0\u30E9\u30D5\u304C\u7121\
    \u5411\u6728\u3067\u306A\u3044\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\
    \u7FA9\u3067\u3042\u308B\u3002\n     * @param root \u6728\u306E\u6839\u3068\u3059\
    \u308B\u9802\u70B9\u756A\u53F7\n     * @return vector<pair<Vertex, EdgeNum>> \u5404\
    \u9802\u70B9\u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7\u3068\u89AA\u3078\u306E\
    \u8FBA\u756A\u53F7\uFF08\u9802\u70B9root\u306B\u5BFE\u3057\u3066\u306F\u3069\u3061\
    \u3089\u3082-1\u3068\u3059\u308B\uFF09\n     */\n    vector<pair<Vertex, EdgeNum>>\
    \ get_parent(Vertex root){\n        assert(isTree);\n        vector<pair<Vertex,\
    \ EdgeNum>> ret(sz, pair<Vertex, EdgeNum>(-1, -1));\n        stack<pair<Vertex,\
    \ Vertex>> st;\n        st.emplace(root, -1);\n        while(!st.empty()){\n \
    \           auto [v, parent] = st.top();\n            st.pop();\n            for(auto\
    \ &idx : connect[v]){\n                if(edges[idx].to == parent) continue;\n\
    \                ret[edges[idx].to] = pair<Vertex, EdgeNum>(v, rev[idx]);\n  \
    \              st.emplace(edges[idx].to, v);\n            }\n        }\n     \
    \   return ret;\n    }\n\n    void pr(){\n        for(auto &e:edges){\n      \
    \      cerr<<e.from+1<<\" \"<<e.to+1<<endl;\n        }\n    }\n};\n\ntemplate<typename\
    \ T>\nusing Tree = Graph<T>;\n#line 11 \"library/Graph/StronglyConnectedComponents.hpp\"\
    \n\n/**\n * @brief  \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u3092\u884C\u3046\
    \u3002\n */\ntemplate<typename CostType>\nstruct StronglyConnectedComponents{\n\
    \    vector<int> belong; // \u9802\u70B9\u304C\u3069\u306E\u5F37\u9023\u7D50\u6210\
    \u5206\u306B\u6240\u5C5E\u3059\u308B\u304B\n    vector<vector<Vertex>> sc; //\
    \ \u5404\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u9802\u70B9\
    \n\n    private:\n    Graph<CostType> &G, rG;\n    vector<int> order, visited;\n\
    \    vector<int> tmp;\n\n    void dfs(int v){\n        visited[v] = 1;\n     \
    \   for(auto &e : G.get_edges(v)){\n            if(visited[e.to] == 0) dfs(e.to);\n\
    \        }\n        order.push_back(v);\n    }\n\n    void rdfs(int v, int k){\n\
    \        visited[v] = 0;\n        belong[v] = k;\n        tmp.push_back(v);\n\
    \        for(auto &e : rG.get_edges(v)){\n            if(visited[e.to] == 1) rdfs(e.to,\
    \ k);\n        }\n    }\n\n    public:\n    StronglyConnectedComponents(Graph<CostType>\
    \ &G) : G(G){\n        rG = G.reverse();\n        visited.resize(G.size(), 0);\n\
    \        belong.resize(G.size(), -1);\n        for(int i = 0; i < G.size(); ++i){\n\
    \            if(visited[i] == 0) dfs(i);\n        }\n        int k = 0;\n    \
    \    for(int i = order.size() - 1; i >= 0; --i){\n            if(visited[order[i]]\
    \ == 1){\n                rdfs(order[i], k++);\n                sc.push_back(tmp);\n\
    \                tmp.clear();\n            }\n        }\n    }\n\n    /**\n  \
    \   * @brief  2\u3064\u306E\u9802\u70B9\u304C\u540C\u3058\u5F37\u9023\u7D50\u6210\
    \u5206\u306B\u6240\u5C5E\u3059\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\
    \n     * @param  u: \u5224\u5B9A\u3057\u305F\u3044\u9802\u70B9u\n     * @param\
    \  v: \u5224\u5B9A\u3057\u305F\u3044\u9802\u70B9v\n     * @retval \u540C\u3058\
    \u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u306A\u3089true\u3001\
    \u305D\u3046\u3067\u306A\u3051\u308C\u3070false\n     */\n    bool same(Vertex\
    \ u, Vertex v){\n        return belong[u] == belong[v];\n    }\n\n    /**\n  \
    \   * @brief \u9802\u70B9v\u304C\u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\
    \u3092\u8FD4\u3059\u3002\n     * @param v \u8ABF\u3079\u305F\u3044\u9802\u70B9\
    v\n     * @return vector<Vertex> \u9802\u70B9v\u304C\u5C5E\u3059\u308B\u5F37\u9023\
    \u7D50\u6210\u5206\n     */\n    vector<Vertex> get(Vertex v){\n        return\
    \ sc[belong[v]];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Strongly Connected Components - \u5F37\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\n */\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#include \"GraphTemplate.hpp\"\n\n/**\n * @brief  \u5F37\u9023\u7D50\
    \u6210\u5206\u5206\u89E3\u3092\u884C\u3046\u3002\n */\ntemplate<typename CostType>\n\
    struct StronglyConnectedComponents{\n    vector<int> belong; // \u9802\u70B9\u304C\
    \u3069\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\u304B\
    \n    vector<vector<Vertex>> sc; // \u5404\u5F37\u9023\u7D50\u6210\u5206\u306B\
    \u6240\u5C5E\u3059\u308B\u9802\u70B9\n\n    private:\n    Graph<CostType> &G,\
    \ rG;\n    vector<int> order, visited;\n    vector<int> tmp;\n\n    void dfs(int\
    \ v){\n        visited[v] = 1;\n        for(auto &e : G.get_edges(v)){\n     \
    \       if(visited[e.to] == 0) dfs(e.to);\n        }\n        order.push_back(v);\n\
    \    }\n\n    void rdfs(int v, int k){\n        visited[v] = 0;\n        belong[v]\
    \ = k;\n        tmp.push_back(v);\n        for(auto &e : rG.get_edges(v)){\n \
    \           if(visited[e.to] == 1) rdfs(e.to, k);\n        }\n    }\n\n    public:\n\
    \    StronglyConnectedComponents(Graph<CostType> &G) : G(G){\n        rG = G.reverse();\n\
    \        visited.resize(G.size(), 0);\n        belong.resize(G.size(), -1);\n\
    \        for(int i = 0; i < G.size(); ++i){\n            if(visited[i] == 0) dfs(i);\n\
    \        }\n        int k = 0;\n        for(int i = order.size() - 1; i >= 0;\
    \ --i){\n            if(visited[order[i]] == 1){\n                rdfs(order[i],\
    \ k++);\n                sc.push_back(tmp);\n                tmp.clear();\n  \
    \          }\n        }\n    }\n\n    /**\n     * @brief  2\u3064\u306E\u9802\u70B9\
    \u304C\u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\u308B\
    \u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     * @param  u: \u5224\u5B9A\u3057\
    \u305F\u3044\u9802\u70B9u\n     * @param  v: \u5224\u5B9A\u3057\u305F\u3044\u9802\
    \u70B9v\n     * @retval \u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\
    \u5C5E\u3059\u308B\u306A\u3089true\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070\
    false\n     */\n    bool same(Vertex u, Vertex v){\n        return belong[u] ==\
    \ belong[v];\n    }\n\n    /**\n     * @brief \u9802\u70B9v\u304C\u5C5E\u3059\u308B\
    \u5F37\u9023\u7D50\u6210\u5206\u3092\u8FD4\u3059\u3002\n     * @param v \u8ABF\
    \u3079\u305F\u3044\u9802\u70B9v\n     * @return vector<Vertex> \u9802\u70B9v\u304C\
    \u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\n     */\n    vector<Vertex>\
    \ get(Vertex v){\n        return sc[belong[v]];\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/StronglyConnectedComponents.hpp
  requiredBy: []
  timestamp: '2023-09-16 09:30:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ/AOJ-GRL-3-C.test.cpp
documentation_of: library/Graph/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/library/Graph/StronglyConnectedComponents.hpp
- /library/library/Graph/StronglyConnectedComponents.hpp.html
title: "Strongly Connected Components - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---