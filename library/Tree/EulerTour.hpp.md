---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
    links: []
  bundledCode: "#line 2 \"library/Tree/EulerTour.hpp\"\n\n/**\n * @brief Euler Tour\
    \ - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 2.2\n * @date 2023-10-02\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing Vertex = int;\nusing EdgeID = int;\nusing EdgeIndex = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    EdgeID ID{-1};\n    Vertex src, to;\n    CostType\
    \ cost, cap;\n    EdgeIndex sidx, tidx;\n\n    Edge() = default;\n    Edge(EdgeID\
    \ ID, Vertex src, Vertex to, CostType cost, CostType cap, EdgeIndex sidx, EdgeIndex\
    \ tidx) :\n        ID(ID), src(src), to(to), cost(cost), cap(cap), sidx(sidx),\
    \ tidx(tidx){}\n\n    void print(){\n        cerr << \"Edge \" << ID << \" : (\"\
    \ << src << \" -> \" << to << \"), Cost = \" << cost << \", Capacity = \" << cap\
    \ << \", Place = [\" << sidx << \", \" << tidx << \"]\" << endl;\n    }\n};\n\n\
    template<typename CostType>\nusing EdgeSet = vector<Edge<CostType>>;\ntemplate<typename\
    \ CostType>\nusing IncidentList = vector<vector<Edge<CostType>>>;\nusing AdjacentList\
    \ = vector<vector<Vertex>>;\n\ntemplate<typename CostType>\nstruct Graph{\n  \
    \  protected:\n    int __CntVertex, __CntEdge;\n    bool __isDirected;\n    EdgeSet<CostType>\
    \ __ES, __RES;\n    IncidentList<CostType> __IL;\n    AdjacentList __AL;\n\n \
    \   public:\n    CostType INF;\n\n    Graph(int VertexSize, bool isDirected =\
    \ false) : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0), __IL(VertexSize),\
    \ __AL(VertexSize), INF(numeric_limits<CostType>::max() / 2){}\n\n    Graph()\
    \ = default;\n\n    void add(Vertex Source, Vertex To, CostType Cost = 1){\n \
    \       assert(0 <= Source && Source < __CntVertex);\n        assert(0 <= To &&\
    \ To < __CntVertex);\n        EdgeIndex sidx = __IL[Source].size(), tidx = __IL[To].size();\n\
    \        Edge<CostType> es{__CntEdge, Source, To, Cost, 1, sidx, tidx};\n    \
    \    Edge<CostType> et{__CntEdge, To, Source, Cost, 1, tidx, sidx};\n        __ES.push_back(es);\n\
    \        __RES.push_back(et);\n        __IL[Source].push_back(es), __AL[Source].push_back(To);\n\
    \        if(!__isDirected) __IL[To].push_back(et), __AL[To].push_back(Source);\n\
    \        ++__CntEdge;\n    }\n\n    vector<vector<CostType>> matrix(CostType NotAdjacent\
    \ = numeric_limits<CostType>::max() / 2){\n        vector ret(__CntVertex, vector(__CntVertex,\
    \ NotAdjacent));\n        for(Vertex v = 0; v < __CntVertex; ++v){\n         \
    \   ret[v][v] = 0;\n            for(auto e : __IL[v]){\n                ret[v][e.to]\
    \ = e.cost;\n            }\n        }\n        return ret;\n    }\n\n    inline\
    \ int vsize(){\n        return __CntVertex;\n    }\n\n    inline int esize(){\n\
    \        return __CntEdge;\n    }\n\n    inline int incsize(Vertex v){\n     \
    \   return __IL[v].size();\n    }\n\n    inline EdgeSet<CostType> &get_edgeset(){\n\
    \        return __ES;\n    }\n\n    inline IncidentList<CostType> &get_incidentlist(){\n\
    \        return __IL;\n    }\n\n    inline vector<Edge<CostType>> &get_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        return __IL[v];\n \
    \   }\n\n    inline AdjacentList &get_adjacentlist(){\n        return __AL;\n\
    \    }\n\n    inline vector<Vertex> &get_adjacent(Vertex v){\n        assert(0\
    \ <= v && v < __CntVertex);\n        return __AL[v];\n    }\n\n    vector<Edge<CostType>>\
    \ operator[](Vertex v){\n        return get_incident(v);\n    }\n\n    void print_edgeset(bool\
    \ OneIndex = true){\n        for(int e = 0; e < __CntEdge; ++e){\n           \
    \ cout << e + OneIndex << \" : (\" << __ES[e].from + OneIndex << (__isDirected\
    \ ? \" -> \" : \" <-> \") << __ES[e].to + OneIndex << \") = \" << __ES[e].cost\
    \ << \" (\" << __ES[e].cap << \")\" << endl;\n        }\n    }\n\n    void print_incidentlist(bool\
    \ OneIndex = true){\n        for(int i = 0; i < __CntVertex; ++i){\n         \
    \   cout << i + OneIndex << \" :\";\n            for(int j = 0; j < __IL[i].size();\
    \ ++j){\n                cout << \" (\" << __IL[i][j].to << \" / \" << __IL[i][j].cost\
    \ << \", \" << __IL[i][j].cap << \")\";\n            }\n            cout << endl;\n\
    \        }\n    }\n\n    void print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max()\
    \ / 2, bool DisplayINF = true){\n        auto mat = matrix(NotAdjacent);\n   \
    \     for(int i = 0; i < __CntVertex; ++i){\n            cout << (DisplayINF &&\
    \ mat[i][0] == NotAdjacent ? \"INF\" : to_string(mat[i][0]));\n            for(int\
    \ j = 1; j < __CntVertex; ++j){\n                cout << \" \" << (DisplayINF\
    \ && mat[i][j] == NotAdjacent ? \"INF\" : to_string(mat[i][j]));\n           \
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 2 \"library/DataStructure/BinaryIndexedTree.hpp\"\
    \n\n/**\n * @brief Binary Indexed Tree\n */\n\n#line 8 \"library/DataStructure/BinaryIndexedTree.hpp\"\
    \nusing namespace std;\n\n/**\n * @brief \u533A\u9593\u306B\u5BFE\u3059\u308B\u4E00\
    \u70B9\u66F4\u65B0\u30FB\u533A\u9593\u548C\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\
    \u3057\u3066\u9AD8\u901F\u304B\u3064\u7C21\u6613\u306B\u5B9F\u88C5\u3067\u304D\
    \u308B\u30C7\u30FC\u30BF\u69CB\u9020\u3002 \n */\ntemplate<typename T>\nstruct\
    \ BinaryIndexedTree{\n    private:\n    vector<T> data;\n\n    public:\n    /**\n\
    \     * @brief Binary Indexed Tree\u3092\u8981\u7D20\u6570size\u3001\u50240\u3067\
    \u521D\u671F\u5316\u3059\u308B\u3002\n     * @param size \u914D\u5217\u306E\u8981\
    \u7D20\u6570\n     */\n    BinaryIndexedTree(int size){\n        data.resize(++size,\
    \ 0);\n    }\n\n    BinaryIndexedTree() = default;\n\n    /**\n     * @brief 1-index\u3067\
    \u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\u5BFE\u3057\u3066\u3001\u914D\u5217\
    \u306E\u6700\u521D\u304B\u3089i\u307E\u3067\u306E\u9589\u533A\u9593\u306E\u548C\
    \u3092\u6C42\u3081\u308B\u3002\n     * @param i \u6C42\u3081\u305F\u3044\u9589\
    \u533A\u9593\u53F3\u7AEF(1-index)\n     * @return T \u533A\u9593\u548C\n     */\n\
    \    T sum(int i){\n        T ret = 0;\n        while(i > 0){\n            ret\
    \ += data[i];\n            i -= i & -i;\n        }\n        return ret;\n    }\n\
    \n    /**\n     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\
    \u5BFE\u3057\u3066\u3001data[i]\u306Bx\u3092\u52A0\u3048\u308B\u3002\n     * @param\
    \ i \u52A0\u3048\u308B\u5834\u6240\n     * @param x \u52A0\u3048\u308B\u5024\n\
    \     */\n    void add(int i, T x){\n        while(i < data.size()){\n       \
    \     data[i] += x;\n            i += i & -i;\n        }\n    }\n\n    /**\n \
    \    * @brief 0-index\u3067\u8868\u3055\u308C\u308B\u534A\u958B\u533A\u9593[l,\
    \ r)\u306E\u533A\u9593\u548C\u3092\u6C42\u3081\u308B\u3002\n     * @param l \u533A\
    \u9593\u306E\u5DE6\u7AEF\n     * @param r \u533A\u9593\u306E\u53F3\u7AEF\n   \
    \  * @return T \u533A\u9593\u548C\n     */\n    T query(int l, int r){\n     \
    \   return sum(r) - sum(l);\n    }\n};\n#line 9 \"library/Tree/EulerTour.hpp\"\
    \n\ntemplate<typename CostType>\nstruct EulerTour{\n    private:\n    int sz,\
    \ k;\n    using Tour = int;\n    Graph<CostType> &G;\n    vector<Tour> arrival,\
    \ departure; // \u9802\u70B9i\u306B\u8A2A\u308C\u305F\u6642\u9593 / \u9802\u70B9\
    i\u304B\u3089\u53BB\u308B\u6642\u9593 : BIT\u306B\u4E57\u305B\u308B\u3053\u3068\
    \u3092\u60F3\u5B9A\u3057\u3066\u3044\u308B\u305F\u3081\u3001\u30AF\u30A8\u30EA\
    \u51E6\u7406\u3092\u7C21\u6613\u306B\u3059\u308B\u305F\u3081\u306B1-index\u3067\
    \u8A18\u9332\u3059\u308B\n    BinaryIndexedTree<CostType> BIT;\n    vector<pair<Vertex,\
    \ EdgeNum>> relation;\n\n    void dfs1(int v, int pre){\n        arrival[v] =\
    \ k++;\n        for(auto &e : G.get_edges(v)){\n            if(e.to == pre) continue;\n\
    \            dfs1(e.to, v);\n        }\n        departure[v] = k++;\n    }\n\n\
    \    void dfs2(int v, int pre, CostType value){\n        BIT.add(arrival[v], value);\n\
    \        for(auto &e : G.get_edges(v)){\n            if(e.to == pre) continue;\n\
    \            dfs2(e.to, v, e.cost);\n        }\n        BIT.add(departure[v],\
    \ -value);\n    }\n\n    public:\n    /**\n     * @brief \u9802\u70B9root\u3092\
    \u6839\u3068\u3057\u305F\u6728G\u3067\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
    \u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention G\u304C\u6728\u3067\u306A\
    \u3044\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9\n     * @param G\
    \ \u6728\n     * @param root \u6839 (option, default = 0)\n     */\n    EulerTour(Graph<CostType>\
    \ &G, Vertex root = 0) : G(G), sz(G.size()), BIT(G.size() * 2), k(1){\n      \
    \  arrival.resize(sz, -1);\n        departure.resize(sz, -1);\n        dfs1(root,\
    \ -1);\n        dfs2(0, -1, 0);\n        relation = G.get_parent(root);\n    }\n\
    \n    /**\n     * @brief \u6839\u304B\u3089\u9802\u70B9v\u3078\u306E\u8DDD\u96E2\
    \u3092BIT\u3092\u7528\u3044\u3066\u53D6\u5F97\u3059\u308B\u3002\n     * @param\
    \ v \u53D6\u5F97\u3057\u305F\u3044\u9802\u70B9\u756A\u53F7v\n     * @return CostType\
    \ \u6839\u304B\u3089\u9802\u70B9v\u3078\u306E\u8DDD\u96E2\n     */\n    CostType\
    \ query(Vertex v){\n        return BIT.sum(arrival[v]);\n    }\n\n    /**\n  \
    \   * @brief \u9802\u70B9child\u3068\u305D\u306E\u89AA\u3092\u7D50\u3076\u8FBA\
    \u306E\u91CD\u307F\u3092x\u5897\u52A0\u3055\u305B\u308B\u4E00\u70B9\u66F4\u65B0\
    \u30AF\u30A8\u30EA\n     * @param child \u5B50\u306E\u9802\u70B9\u3092\u8868\u3059\
    \u9802\u70B9\u756A\u53F7\n     * @param x \u5897\u52A0\u3055\u305B\u308B\u91CD\
    \u307F\n     */\n    void add(Vertex child, CostType x){\n        auto [parent,\
    \ ed] = relation[child];\n        G.edges[ed].cost += x;\n        G.edges[G.rev[ed]].cost\
    \ += x;\n        BIT.add(arrival[child], x);\n        BIT.add(departure[child],\
    \ -x);\n    }\n\n    void update(Vertex child, CostType x){\n        auto [parent,\
    \ ed] = relation[child];\n        CostType diff = x - G.edges[ed].cost;\n    \
    \    G.edges[ed].cost += diff;\n        G.edges[G.rev[ed]].cost += diff;\n   \
    \     BIT.add(arrival[child], diff);\n        BIT.add(departure[child], -diff);\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\
    \u30A2\u30FC\n */\n\n#include \"../Graph/GraphTemplate.hpp\"\n#include \"../DataStructure/BinaryIndexedTree.hpp\"\
    \n\ntemplate<typename CostType>\nstruct EulerTour{\n    private:\n    int sz,\
    \ k;\n    using Tour = int;\n    Graph<CostType> &G;\n    vector<Tour> arrival,\
    \ departure; // \u9802\u70B9i\u306B\u8A2A\u308C\u305F\u6642\u9593 / \u9802\u70B9\
    i\u304B\u3089\u53BB\u308B\u6642\u9593 : BIT\u306B\u4E57\u305B\u308B\u3053\u3068\
    \u3092\u60F3\u5B9A\u3057\u3066\u3044\u308B\u305F\u3081\u3001\u30AF\u30A8\u30EA\
    \u51E6\u7406\u3092\u7C21\u6613\u306B\u3059\u308B\u305F\u3081\u306B1-index\u3067\
    \u8A18\u9332\u3059\u308B\n    BinaryIndexedTree<CostType> BIT;\n    vector<pair<Vertex,\
    \ EdgeNum>> relation;\n\n    void dfs1(int v, int pre){\n        arrival[v] =\
    \ k++;\n        for(auto &e : G.get_edges(v)){\n            if(e.to == pre) continue;\n\
    \            dfs1(e.to, v);\n        }\n        departure[v] = k++;\n    }\n\n\
    \    void dfs2(int v, int pre, CostType value){\n        BIT.add(arrival[v], value);\n\
    \        for(auto &e : G.get_edges(v)){\n            if(e.to == pre) continue;\n\
    \            dfs2(e.to, v, e.cost);\n        }\n        BIT.add(departure[v],\
    \ -value);\n    }\n\n    public:\n    /**\n     * @brief \u9802\u70B9root\u3092\
    \u6839\u3068\u3057\u305F\u6728G\u3067\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
    \u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention G\u304C\u6728\u3067\u306A\
    \u3044\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9\n     * @param G\
    \ \u6728\n     * @param root \u6839 (option, default = 0)\n     */\n    EulerTour(Graph<CostType>\
    \ &G, Vertex root = 0) : G(G), sz(G.size()), BIT(G.size() * 2), k(1){\n      \
    \  arrival.resize(sz, -1);\n        departure.resize(sz, -1);\n        dfs1(root,\
    \ -1);\n        dfs2(0, -1, 0);\n        relation = G.get_parent(root);\n    }\n\
    \n    /**\n     * @brief \u6839\u304B\u3089\u9802\u70B9v\u3078\u306E\u8DDD\u96E2\
    \u3092BIT\u3092\u7528\u3044\u3066\u53D6\u5F97\u3059\u308B\u3002\n     * @param\
    \ v \u53D6\u5F97\u3057\u305F\u3044\u9802\u70B9\u756A\u53F7v\n     * @return CostType\
    \ \u6839\u304B\u3089\u9802\u70B9v\u3078\u306E\u8DDD\u96E2\n     */\n    CostType\
    \ query(Vertex v){\n        return BIT.sum(arrival[v]);\n    }\n\n    /**\n  \
    \   * @brief \u9802\u70B9child\u3068\u305D\u306E\u89AA\u3092\u7D50\u3076\u8FBA\
    \u306E\u91CD\u307F\u3092x\u5897\u52A0\u3055\u305B\u308B\u4E00\u70B9\u66F4\u65B0\
    \u30AF\u30A8\u30EA\n     * @param child \u5B50\u306E\u9802\u70B9\u3092\u8868\u3059\
    \u9802\u70B9\u756A\u53F7\n     * @param x \u5897\u52A0\u3055\u305B\u308B\u91CD\
    \u307F\n     */\n    void add(Vertex child, CostType x){\n        auto [parent,\
    \ ed] = relation[child];\n        G.edges[ed].cost += x;\n        G.edges[G.rev[ed]].cost\
    \ += x;\n        BIT.add(arrival[child], x);\n        BIT.add(departure[child],\
    \ -x);\n    }\n\n    void update(Vertex child, CostType x){\n        auto [parent,\
    \ ed] = relation[child];\n        CostType diff = x - G.edges[ed].cost;\n    \
    \    G.edges[ed].cost += diff;\n        G.edges[G.rev[ed]].cost += diff;\n   \
    \     BIT.add(arrival[child], diff);\n        BIT.add(departure[child], -diff);\n\
    \    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  - library/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: false
  path: library/Tree/EulerTour.hpp
  requiredBy: []
  timestamp: '2023-10-10 14:21:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Tree/EulerTour.hpp
layout: document
redirect_from:
- /library/library/Tree/EulerTour.hpp
- /library/library/Tree/EulerTour.hpp.html
title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
---
