---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/AOJ-GRL-5-E.test.cpp
    title: verify/AOJ-GRL-5-E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Heavy Light Decomposition - HL\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"library/Tree/HeavyLightDecomposition.hpp\"\n\n/**\n * @brief\
    \ Heavy Light Decomposition - HL\u5206\u89E3\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 1.2\n * @date 2023-08-24\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing EdgeNum = int;\nusing Vertex = int;\n\n/**\n * @brief \u30B0\u30E9\u30D5\
    \u306E\u8FBA\n */\ntemplate<typename CostType = int>\nstruct Edge{\n    Vertex\
    \ from, to;\n    CostType cost;\n\n    Edge(Vertex from, Vertex to, CostType cost)\
    \ : from(from), to(to), cost(cost){}\n};\n\n/**\n * @brief \u30B0\u30E9\u30D5\u3092\
    \u8868\u3059\u30AF\u30E9\u30B9\u3002\n * @note \u8FBA\u96C6\u5408\u306B\u3088\u3063\
    \u3066\u5B9F\u73FE\u3057\u3066\u3044\u308B\u3002\n * @tparam CostType \u8FBA\u306E\
    \u91CD\u307F\u306E\u578B\u3002\n */\ntemplate<typename CostType = int>\nclass\
    \ Graph{\n    private:\n    int sz;\n    bool dir;\n    vector<int> indegree;\n\
    \n    public:\n    vector<Edge<CostType>> edges;\n    vector<vector<EdgeNum>>\
    \ connect;\n    vector<EdgeNum> rev; // \u5F62\u5F0F\u4E0A\u7121\u5411\u30B0\u30E9\
    \u30D5\u3067\u3082\u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u306E\u3067\
    \u3001\u8FBA\u306E\u8FFD\u52A0\u6642\u306B\u9006\u8FBA\u306E\u8FBA\u756A\u53F7\
    \u3092\u8A18\u9332\u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\n    CostType\
    \ INF;\n\n    /**\n     * @brief Construct a new Graph object\n     * @param VertexNum\
    \ \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\n     * @param isDirected \u6709\u5411\
    \u30B0\u30E9\u30D5\u3068\u3057\u3066\u4F5C\u6210\u3059\u308B\u304B\n     */\n\
    \    Graph(int VertexNum, bool isDirected = false) : sz(VertexNum), dir(isDirected),\
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
    \ t, w));\n        connect[s].push_back(e);\n        ++indegree[t];\n        if(!dir){\n\
    \            edges.push_back(Edge<CostType>(t, s, w));\n            connect[t].push_back(e\
    \ + 1);\n            rev.emplace_back(e + 1);\n            rev.emplace_back(e);\n\
    \        }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3057\u305F\u8FBA\u756A\
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
    \u30B0\u30E9\u30D5\n     */\n    Graph<CostType> reverse(){\n        assert(dir);\n\
    \        Graph<CostType> ret(sz, true);\n        for(auto &e : edges){\n     \
    \       ret.add(e.to, e.from, e.cost);\n        }\n        return ret;\n    }\n\
    \n    inline size_t size(){\n        return sz;\n    }\n\n    inline bool directed(){\n\
    \        return dir;\n    }\n\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\
    \u306E\u6B21\u6570(\u51FA\u6B21\u6570)\u3092\u53D6\u5F97\u3059\u308B\u3002\n \
    \    * @note \u6709\u5411\u30B0\u30E9\u30D5\u306B\u304A\u3044\u3066\u3001\u7B2C\
    2\u5F15\u6570\u3092true\u306B\u3059\u308C\u3070\u5165\u6B21\u6570\u3092\u5F97\u308B\
    \u3053\u3068\u304C\u3067\u304D\u308B\u3002\n     * @param v \u9802\u70B9\u756A\
    \u53F7\n     * @param isIn (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u3068\u304D\u306E\
    \u307F\u6709\u52B9)\u5165\u6B21\u6570\u3092\u53D6\u5F97\u3059\u308B\u304B (option,\
    \ default = false)\n     * @return int \u9802\u70B9v\u306E\u6307\u5B9A\u3057\u305F\
    \u5024\n     */\n    inline int degree(Vertex v, bool isIn = false){\n       \
    \ if(dir && isIn) return indegree[v];\n        return (int)connect[v].size();\n\
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
    \ get_parent(Vertex root){\n        vector<pair<Vertex, EdgeNum>> ret(sz, pair<Vertex,\
    \ EdgeNum>(-1, -1));\n        stack<pair<Vertex, Vertex>> st;\n        st.emplace(root,\
    \ -1);\n        while(!st.empty()){\n            auto [v, parent] = st.top();\n\
    \            st.pop();\n            for(auto &idx : connect[v]){\n           \
    \     if(edges[idx].to == parent) continue;\n                ret[edges[idx].to]\
    \ = pair<Vertex, EdgeNum>(v, rev[idx]);\n                st.emplace(edges[idx].to,\
    \ v);\n            }\n        }\n        return ret;\n    }\n};\n#line 8 \"library/Tree/HeavyLightDecomposition.hpp\"\
    \n\ntemplate<typename CostType>\nstruct HeavyLightDecompsition{\n    using Column\
    \ = int;\n    \n    private:\n    int sz;\n    Vertex root;\n    Graph<CostType>\
    \ &G;\n    vector<int> subtree_size; // \u9802\u70B9i\u3092\u6839\u3068\u3059\u308B\
    \u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\n    vector<pair<Vertex, EdgeNum>>\
    \ relation; // \u6728\u306E\u89AA\u5B50\u95A2\u4FC2\n    vector<vector<Vertex>>\
    \ column_vertex; // \u5404\u5217\u306B\u542B\u307E\u308C\u308B\u9802\u70B9\u30EA\
    \u30B9\u30C8\n    vector<pair<Column, int>> column_index; // \u5404\u9802\u70B9\
    \u306E\u9802\u70B9\u30EA\u30B9\u30C8\u5185\u306E\u4F4D\u7F6E\n    vector<int>\
    \ offset; // 1\u5217\u306B\u4E26\u3079\u305F\u3068\u304D\u3001\u5404\u5217\u306E\
    \u5148\u982D\u306E\u9802\u70B9\u306E\u4F4D\u7F6E (0-index)\n\n    /**\n     *\
    \ @brief \u9802\u70B9i\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\
    \u70B9\u6570\u3092\u6C42\u3081\u308BDFS\n     * @param v \u6839\u3068\u306A\u308B\
    \u9802\u70B9\u756A\u53F7\n     * @param pre \u89AA\u306E\u9802\u70B9\n     * @return\
    \ int \u9802\u70B9\u306E\u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\n     */\n\
    \    int dfs1(Vertex v, Vertex pre){\n        int res = 0;\n        for(auto &e\
    \ : G.get_edges(v)){\n            if(e.to == pre) continue;\n            res +=\
    \ dfs1(e.to, v);\n        }\n        return subtree_size[v] = res + 1;\n    }\n\
    \n    void dfs2(Vertex v, Vertex pre, Column col){\n        if(column_vertex.size()\
    \ == col) column_vertex.emplace_back(vector<Vertex>{});\n        column_index[v]\
    \ = pair<Column, int>(col, column_vertex[col].size());\n        column_vertex[col].push_back(v);\n\
    \        Vertex next = -1;\n        int max_subtree = 0;\n        for(auto &e\
    \ : G.get_edges(v)){\n            if(e.to == pre) continue;\n            if(max_subtree\
    \ < subtree_size[e.to]){\n                next = e.to;\n                max_subtree\
    \ = subtree_size[e.to];\n            }\n        }\n        if(next != -1) dfs2(next,\
    \ v, col);\n        for(auto &e : G.get_edges(v)){\n            if(e.to == pre\
    \ || e.to == next) continue;\n            dfs2(e.to, v, column_vertex.size());\n\
    \        }\n        return;\n    }\n\n    /**\n     * @brief 1\u5217\u306B\u4E26\
    \u3079\u305F\u3068\u304D\u306E\u9802\u70B9v\u306E\u4F4D\u7F6E\n     * @param v\
    \ \u4F4D\u7F6E\u3092\u77E5\u308A\u305F\u3044\u9802\u70B9\u756A\u53F7\n     * @return\
    \ int \u5217\u306B\u304A\u3051\u308B\u4F4D\u7F6E(0-index)\n     */\n    inline\
    \ int locate(Vertex v){\n        auto [i, j] = column_index[v];\n        return\
    \ offset[i] + j;\n    }\n    \n    public:\n    HeavyLightDecompsition(Graph<CostType>\
    \ &G, Vertex root = 0) : G(G), sz(G.size()), root(root){\n        subtree_size.resize(sz,\
    \ -1);\n        dfs1(root, -1);\n        column_index.resize(sz, pair<Column,\
    \ int>(-1, -1));\n        dfs2(root, -1, 0);\n        offset.resize(column_vertex.size(),\
    \ 0);\n        for(int i = 1; i < column_vertex.size(); ++i){\n            offset[i]\
    \ = offset[i - 1] + column_vertex[i - 1].size();\n        }\n        relation\
    \ = G.get_parent(root);\n    }\n\n    /**\n     * @brief \u9802\u70B9u\u304B\u3089\
    \u9802\u70B9v\u307E\u3067\u306E\u533A\u9593\u306E\u4E00\u89A7\u3092\u53D6\u5F97\
    \u3059\u308B\u3002\n     * @note \u533A\u9593\u306F\u534A\u958B\u533A\u9593\u3068\
    \u3057\u3066\u4E0E\u3048\u3089\u308C\u3001\u9802\u70B9u\u3092\u7701\u7565\u3059\
    \u308B\u3068\u6839\u3068\u3059\u308B\n     * @param v: \u5B50\u306E\u65B9\u306E\
    \u9802\u70B9\u756A\u53F7(0-index)\n     * @param u: \u89AA\u306E\u65B9\u306E\u9802\
    \u70B9\u756A\u53F7(0-index, option default = root)\n     * @retval \u534A\u958B\
    \u533A\u9593\u306E\u4E00\u89A7\n     */\n    vector<pair<int, int>> get_segment(Vertex\
    \ v, Vertex u = -1){\n        if(u == -1) u = root;\n        auto [uc, ui] = column_index[u];\n\
    \        vector<pair<int, int>> ret;\n        Vertex now = v;\n        while(1){\n\
    \            auto [c, i] = column_index[now];\n            if(uc == c){\n    \
    \            ret.emplace_back(offset[uc] + ui, offset[c] + i + 1);\n         \
    \       break;\n            }\n            else ret.emplace_back(offset[c], offset[c]\
    \ + i + 1);\n            Vertex front = column_vertex[c][0];\n            now\
    \ = relation[front].first;\n        }\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u30921\u5217\u306B\u4E26\u3079\u305F\u3068\u304D\
    \u306E\u5404\u9802\u70B9\u306B\u5BFE\u5FDC\u3059\u308B\u5024\u306E\u914D\u5217\
    \u3092\u8FD4\u3059\n     * @note \u30BB\u30B0\u6728\u3068\u304B\u306E\u521D\u671F\
    \u914D\u5217\n     * @return vector<CostType> \n     */\n    vector<CostType>\
    \ get_data(){\n        vector<CostType> ret(sz, 0);\n        for(int i = 0; i\
    \ < column_vertex.size(); ++i){\n            for(int j = 0; j < column_vertex[i].size();\
    \ ++j){\n                Vertex v = column_vertex[i][j];\n                EdgeNum\
    \ e = relation[v].second;\n                if(e == -1) continue;\n           \
    \     ret[locate(v)] = G.get_edge(e).cost;\n            }\n        }\n       \
    \ return ret;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Heavy Light Decomposition - HL\u5206\u89E3\
    \n */\n\n#include \"../Graph/GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct HeavyLightDecompsition{\n    using Column = int;\n    \n    private:\n\
    \    int sz;\n    Vertex root;\n    Graph<CostType> &G;\n    vector<int> subtree_size;\
    \ // \u9802\u70B9i\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\
    \u70B9\u6570\n    vector<pair<Vertex, EdgeNum>> relation; // \u6728\u306E\u89AA\
    \u5B50\u95A2\u4FC2\n    vector<vector<Vertex>> column_vertex; // \u5404\u5217\u306B\
    \u542B\u307E\u308C\u308B\u9802\u70B9\u30EA\u30B9\u30C8\n    vector<pair<Column,\
    \ int>> column_index; // \u5404\u9802\u70B9\u306E\u9802\u70B9\u30EA\u30B9\u30C8\
    \u5185\u306E\u4F4D\u7F6E\n    vector<int> offset; // 1\u5217\u306B\u4E26\u3079\
    \u305F\u3068\u304D\u3001\u5404\u5217\u306E\u5148\u982D\u306E\u9802\u70B9\u306E\
    \u4F4D\u7F6E (0-index)\n\n    /**\n     * @brief \u9802\u70B9i\u3092\u6839\u3068\
    \u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\u3092\u6C42\u3081\u308B\
    DFS\n     * @param v \u6839\u3068\u306A\u308B\u9802\u70B9\u756A\u53F7\n     *\
    \ @param pre \u89AA\u306E\u9802\u70B9\n     * @return int \u9802\u70B9\u306E\u90E8\
    \u5206\u6728\u306E\u9802\u70B9\u6570\n     */\n    int dfs1(Vertex v, Vertex pre){\n\
    \        int res = 0;\n        for(auto &e : G.get_edges(v)){\n            if(e.to\
    \ == pre) continue;\n            res += dfs1(e.to, v);\n        }\n        return\
    \ subtree_size[v] = res + 1;\n    }\n\n    void dfs2(Vertex v, Vertex pre, Column\
    \ col){\n        if(column_vertex.size() == col) column_vertex.emplace_back(vector<Vertex>{});\n\
    \        column_index[v] = pair<Column, int>(col, column_vertex[col].size());\n\
    \        column_vertex[col].push_back(v);\n        Vertex next = -1;\n       \
    \ int max_subtree = 0;\n        for(auto &e : G.get_edges(v)){\n            if(e.to\
    \ == pre) continue;\n            if(max_subtree < subtree_size[e.to]){\n     \
    \           next = e.to;\n                max_subtree = subtree_size[e.to];\n\
    \            }\n        }\n        if(next != -1) dfs2(next, v, col);\n      \
    \  for(auto &e : G.get_edges(v)){\n            if(e.to == pre || e.to == next)\
    \ continue;\n            dfs2(e.to, v, column_vertex.size());\n        }\n   \
    \     return;\n    }\n\n    /**\n     * @brief 1\u5217\u306B\u4E26\u3079\u305F\
    \u3068\u304D\u306E\u9802\u70B9v\u306E\u4F4D\u7F6E\n     * @param v \u4F4D\u7F6E\
    \u3092\u77E5\u308A\u305F\u3044\u9802\u70B9\u756A\u53F7\n     * @return int \u5217\
    \u306B\u304A\u3051\u308B\u4F4D\u7F6E(0-index)\n     */\n    inline int locate(Vertex\
    \ v){\n        auto [i, j] = column_index[v];\n        return offset[i] + j;\n\
    \    }\n    \n    public:\n    HeavyLightDecompsition(Graph<CostType> &G, Vertex\
    \ root = 0) : G(G), sz(G.size()), root(root){\n        subtree_size.resize(sz,\
    \ -1);\n        dfs1(root, -1);\n        column_index.resize(sz, pair<Column,\
    \ int>(-1, -1));\n        dfs2(root, -1, 0);\n        offset.resize(column_vertex.size(),\
    \ 0);\n        for(int i = 1; i < column_vertex.size(); ++i){\n            offset[i]\
    \ = offset[i - 1] + column_vertex[i - 1].size();\n        }\n        relation\
    \ = G.get_parent(root);\n    }\n\n    /**\n     * @brief \u9802\u70B9u\u304B\u3089\
    \u9802\u70B9v\u307E\u3067\u306E\u533A\u9593\u306E\u4E00\u89A7\u3092\u53D6\u5F97\
    \u3059\u308B\u3002\n     * @note \u533A\u9593\u306F\u534A\u958B\u533A\u9593\u3068\
    \u3057\u3066\u4E0E\u3048\u3089\u308C\u3001\u9802\u70B9u\u3092\u7701\u7565\u3059\
    \u308B\u3068\u6839\u3068\u3059\u308B\n     * @param v: \u5B50\u306E\u65B9\u306E\
    \u9802\u70B9\u756A\u53F7(0-index)\n     * @param u: \u89AA\u306E\u65B9\u306E\u9802\
    \u70B9\u756A\u53F7(0-index, option default = root)\n     * @retval \u534A\u958B\
    \u533A\u9593\u306E\u4E00\u89A7\n     */\n    vector<pair<int, int>> get_segment(Vertex\
    \ v, Vertex u = -1){\n        if(u == -1) u = root;\n        auto [uc, ui] = column_index[u];\n\
    \        vector<pair<int, int>> ret;\n        Vertex now = v;\n        while(1){\n\
    \            auto [c, i] = column_index[now];\n            if(uc == c){\n    \
    \            ret.emplace_back(offset[uc] + ui, offset[c] + i + 1);\n         \
    \       break;\n            }\n            else ret.emplace_back(offset[c], offset[c]\
    \ + i + 1);\n            Vertex front = column_vertex[c][0];\n            now\
    \ = relation[front].first;\n        }\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u30921\u5217\u306B\u4E26\u3079\u305F\u3068\u304D\
    \u306E\u5404\u9802\u70B9\u306B\u5BFE\u5FDC\u3059\u308B\u5024\u306E\u914D\u5217\
    \u3092\u8FD4\u3059\n     * @note \u30BB\u30B0\u6728\u3068\u304B\u306E\u521D\u671F\
    \u914D\u5217\n     * @return vector<CostType> \n     */\n    vector<CostType>\
    \ get_data(){\n        vector<CostType> ret(sz, 0);\n        for(int i = 0; i\
    \ < column_vertex.size(); ++i){\n            for(int j = 0; j < column_vertex[i].size();\
    \ ++j){\n                Vertex v = column_vertex[i][j];\n                EdgeNum\
    \ e = relation[v].second;\n                if(e == -1) continue;\n           \
    \     ret[locate(v)] = G.get_edge(e).cost;\n            }\n        }\n       \
    \ return ret;\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2023-08-24 15:24:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/AOJ-GRL-5-E.test.cpp
documentation_of: library/Tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/library/Tree/HeavyLightDecomposition.hpp
- /library/library/Tree/HeavyLightDecomposition.hpp.html
title: "Heavy Light Decomposition - HL\u5206\u89E3"
---
