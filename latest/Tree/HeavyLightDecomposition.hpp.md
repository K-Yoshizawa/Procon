---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-5-C-HLD.test.cpp
    title: verify_latest/AOJ-GRL-5-C-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-5-D-HLD.test.cpp
    title: verify_latest/AOJ-GRL-5-D-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-5-E.test.cpp
    title: verify_latest/AOJ-GRL-5-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_latest/LC-VertexAddPathSum.test.cpp
    title: verify_latest/LC-VertexAddPathSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Heavy Light Decomposition - HL\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"latest/Tree/HeavyLightDecomposition.hpp\"\n/**\n * @file\
    \ HeavyLightDecomposition.hpp\n * @author log K (lX57)\n * @brief Heavy Light\
    \ Decomposition - HL\u5206\u89E3\n * @version 2.0\n * @date 2023-10-04\n */\n\n\
    #line 2 \"latest/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
    \ * @author log K (lX57)\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\n * @version 2.2\n * @date 2023-10-02\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\nusing EdgeID =\
    \ int;\nusing EdgeIndex = int;\n\ntemplate<typename CostType>\nstruct Edge{\n\
    \    EdgeID ID{-1};\n    Vertex src, to;\n    CostType cost, cap;\n    EdgeIndex\
    \ sidx, tidx;\n\n    Edge() = default;\n    Edge(EdgeID ID, Vertex src, Vertex\
    \ to, CostType cost, CostType cap, EdgeIndex sidx, EdgeIndex tidx) :\n       \
    \ ID(ID), src(src), to(to), cost(cost), cap(cap), sidx(sidx), tidx(tidx){}\n\n\
    \    void print(){\n        cerr << \"Edge \" << ID << \" : (\" << src << \" ->\
    \ \" << to << \"), Cost = \" << cost << \", Capacity = \" << cap << \", Place\
    \ = [\" << sidx << \", \" << tidx << \"]\" << endl;\n    }\n};\n\ntemplate<typename\
    \ CostType>\nusing EdgeSet = vector<Edge<CostType>>;\ntemplate<typename CostType>\n\
    using IncidentList = vector<vector<Edge<CostType>>>;\nusing AdjacentList = vector<vector<Vertex>>;\n\
    \ntemplate<typename CostType>\nstruct Graph{\n    protected:\n    int __CntVertex,\
    \ __CntEdge;\n    bool __isDirected;\n    EdgeSet<CostType> __ES, __RES;\n   \
    \ IncidentList<CostType> __IL;\n    AdjacentList __AL;\n\n    public:\n    CostType\
    \ INF;\n\n    Graph(int VertexSize, bool isDirected = false) : __CntVertex(VertexSize),\
    \ __isDirected(isDirected), __CntEdge(0), __IL(VertexSize), __AL(VertexSize),\
    \ INF(numeric_limits<CostType>::max() / 2){}\n\n    Graph() = default;\n\n   \
    \ void add(Vertex Source, Vertex To, CostType Cost = 1){\n        assert(0 <=\
    \ Source && Source < __CntVertex);\n        assert(0 <= To && To < __CntVertex);\n\
    \        EdgeIndex sidx = __IL[Source].size(), tidx = __IL[To].size();\n     \
    \   Edge<CostType> es{__CntEdge, Source, To, Cost, 1, sidx, tidx};\n        Edge<CostType>\
    \ et{__CntEdge, To, Source, Cost, 1, tidx, sidx};\n        __ES.push_back(es);\n\
    \        __RES.push_back(et);\n        __IL[Source].push_back(es), __AL[Source].push_back(To);\n\
    \        if(!__isDirected) __IL[To].push_back(et), __AL[To].push_back(Source);\n\
    \        ++__CntEdge;\n    }\n\n    vector<vector<CostType>> matrix(CostType NotAdjacent\
    \ = numeric_limits<CostType>::max() / 2){\n        vector ret(__CntVertex, vector(__CntVertex,\
    \ NotAdjacent));\n        for(Vertex v = 0; v < __CntVertex; ++v){\n         \
    \   ret[v][v] = 0;\n            for(auto e : __IL[v]){\n                ret[v][e.to]\
    \ = e.cost;\n            }\n        }\n        return ret;\n    }\n\n    inline\
    \ int vsize(){\n        return __CntVertex;\n    }\n\n    inline int esize(){\n\
    \        return __CntEdge;\n    }\n\n    inline int incsize(Vertex v){\n     \
    \   return __IL[v].size();\n    }\n\n    inline EdgeSet<CostType> get_edgeset(){\n\
    \        return __ES;\n    }\n\n    inline IncidentList<CostType> get_incidentlist(){\n\
    \        return __IL;\n    }\n\n    inline vector<Edge<CostType>> get_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        return __IL[v];\n \
    \   }\n\n    inline AdjacentList get_adjacentlist(){\n        return __AL;\n \
    \   }\n\n    inline vector<Vertex> get_adjacent(Vertex v){\n        assert(0 <=\
    \ v && v < __CntVertex);\n        return __AL[v];\n    }\n\n    vector<Edge<CostType>>\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"latest/Tree/HeavyLightDecomposition.hpp\"\
    \n\ntemplate<typename CostType>\nstruct HeavyLightDecomposition{\n    using ColumnIndex\
    \ = int;\n    using ColumnData = pair<bool, int>; // `{isVertex, ID(Vertex or\
    \ EdgeID)}`\n\n    private:\n    Vertex __Root;\n\n    Graph<CostType> &G;\n \
    \   vector<int> __SubtreeSize; // \u9802\u70B9 `i` \u3092\u6839\u3068\u3059\u308B\
    \u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\n    vector<int> __Depth; // \u9802\
    \u70B9 `i` \u306E\u6839\u304B\u3089\u306E\u6DF1\u3055\n    vector<Vertex> __ParentVertex;\
    \ // \u9802\u70B9 `i` \u306E\u89AA\u306E\u9802\u70B9\uFF08\u6839\u306E\u5834\u5408\
    \u306F `-1` \uFF09\n    vector<EdgeID> __ParentEdge; // \u9802\u70B9 `i` \u3068\
    \u305D\u306E\u89AA\u3092\u7D50\u3076\u8FBA\u756A\u53F7\uFF08\u6839\u306E\u5834\
    \u5408\u306F `-1` \uFF09\n    vector<Vertex> __ChildVertex; // \u8FBA `i` \u304C\
    \u7D50\u30762\u9802\u70B9\u306E\u3046\u3061\u3001\u5B50\u306E\u65B9\u306E\u9802\
    \u70B9\n\n    vector<vector<ColumnData>> __Columns; // \u5404\u5217\u306B\u542B\
    \u307E\u308C\u308B\u9802\u70B9/\u8FBA\u306E\u30C7\u30FC\u30BF\n    vector<pair<ColumnIndex,\
    \ int>> __VertexIndex, __EdgeIndex; // `Columns` \u5185\u306B\u304A\u3051\u308B\
    \u5404\u9802\u70B9/\u8FBA\u306E\u4F4D\u7F6E\u60C5\u5831\n    vector<int> __Offset;\
    \ // 1\u5217\u306B\u4E26\u3079\u305F\u3068\u304D\u306E\u5404\u5217\u306E\u5148\
    \u982D\u306E\u4F4D\u7F6E\uFF080-index\uFF09\n\n    int __dfs1(Vertex now, Vertex\
    \ par){\n        int ret = 0;\n        for(Edge<CostType> e : G.get_incident(now)){\n\
    \            if(e.to == par) continue;\n            __Depth[e.to] = __Depth[now]\
    \ + 1;\n            __ParentVertex[e.to] = now;\n            __ParentEdge[e.to]\
    \ = e.ID;\n            __ChildVertex[e.ID] = e.to;\n            ret += __dfs1(e.to,\
    \ now);\n        }\n        return __SubtreeSize[now] = ret + 1;\n    }\n\n  \
    \  void __dfs2(Vertex now, Vertex par, ColumnIndex col){\n        // \u65B0\u3057\
    \u3044\u5217\u306E\u5834\u5408\u306F\u5217\u3092\u5897\u3084\u3059\n        if(__Columns.size()\
    \ == col) __Columns.emplace_back(vector<ColumnData>{});\n\n        // \u5217\u306B\
    \u9802\u70B9\u3092\u8FFD\u52A0\n        __VertexIndex[now] = {col, __Columns[col].size()};\n\
    \        __Columns[col].push_back({true, now});\n\n        Edge<CostType> heavy;\n\
    \        int maxsubtree = 0;\n        for(Edge<CostType> e : G.get_incident(now)){\n\
    \            if(e.to == par) continue;\n            if(maxsubtree < __SubtreeSize[e.to]){\n\
    \                heavy = e;\n                maxsubtree = __SubtreeSize[e.to];\n\
    \            }\n        }\n\n        if(maxsubtree){\n            // heavy\u306A\
    \u8FBA\u304C\u5B58\u5728\u3059\u308B\u5834\u5408\u3001\u4ECA\u306E\u5217\u306B\
    \u8FFD\u52A0\u3059\u308B\u5F62\u3067\u518D\u5E30\u3092\u884C\u3046\n         \
    \   __dfs2(heavy.to, now, col);\n        }\n\n        // light\u306A\u8FBA\u306B\
    \u5BFE\u3057\u3066\u65B0\u3057\u3044\u5217\u3092\u751F\u3084\u3057\u3064\u3064\
    \u518D\u5E30\u3092\u884C\u3046\n        for(Edge<CostType> e : G.get_incident(now)){\n\
    \            if(e.to == par || e.to == heavy.to) continue;\n            __dfs2(e.to,\
    \ now, __Columns.size());\n        }\n    }\n\n    Vertex __gethead(Vertex v){\n\
    \        auto [i, j] = __VertexIndex[v];\n        return __Columns[i][0].second;\n\
    \    }\n\n    public:\n    HeavyLightDecomposition(Graph<CostType> &G, Vertex\
    \ Root = 0) : G(G), __Root(Root){\n        __SubtreeSize.resize(G.vsize(), 0);\n\
    \        __Depth.resize(G.vsize(), 0);\n        __ParentVertex.resize(G.vsize(),\
    \ -1);\n        __ParentEdge.resize(G.vsize(), -1);\n        __ChildVertex.resize(G.esize(),\
    \ -1);\n        __dfs1(__Root, -1);\n        #ifdef LOGK\n            cerr <<\
    \ \"[HLD] DFS 1 Complete.\" << endl;\n        #endif\n        __VertexIndex.resize(G.vsize());\n\
    \        __dfs2(__Root, -1, 0);\n        #ifdef LOGK\n            cerr << \"[HLD]\
    \ DFS 2 Complete.\" << endl;\n        #endif\n        __Offset.resize(__Columns.size(),\
    \ 0);\n        for(int i = 1; i < __Columns.size(); ++i){\n            __Offset[i]\
    \ = __Offset[i - 1] + __Columns[i - 1].size();\n        }\n    }\n\n    int get_vertex_locate(Vertex\
    \ v){\n        return __Offset[__VertexIndex[v].first] + __VertexIndex[v].second;\n\
    \    }\n\n    vector<int> get_vertex_locations(){\n        vector<int> ret(G.vsize(),\
    \ -1);\n        for(Vertex i = 0; i < G.vsize(); ++i){\n            ret[i] = __Offset[__VertexIndex[i].first]\
    \ + __VertexIndex[i].second;\n        }\n        return ret;\n    }\n\n    vector<int>\
    \ get_edge_locations(){\n        vector<int> ret(G.esize(), -1);\n        for(EdgeID\
    \ e = 0; e < G.esize(); ++e){\n            Vertex i = __ChildVertex[e];\n    \
    \        ret[e] = __Offset[__VertexIndex[i].first] + __VertexIndex[i].second;\n\
    \        }\n        return ret;\n    }\n\n    Vertex lca(Vertex v, Vertex u){\n\
    \        #ifdef LOGK\n            cerr << \"LCA Query [\" << v << \", \" << u\
    \ << \"]\" << endl;\n        #endif\n        while(1){\n            Vertex hv\
    \ = __gethead(v), hu = __gethead(u);\n            if(__Depth[hv] > __Depth[hu])\
    \ swap(v, u), swap(hv, hu);\n            #ifdef LOGK\n                cerr <<\
    \ \" - Head of [\" << v << \", \" << u << \"] -> [\" << hv << \", \" << hu <<\
    \ \"]\" << endl;\n            #endif\n            if(hv == hu) return (__Depth[v]\
    \ < __Depth[u] ? v : u);\n            u = __ParentVertex[hu];\n        }\n   \
    \ }\n\n    vector<pair<int, int>> get_vertex_segment(Vertex v, Vertex u = -1){\n\
    \        vector<pair<int, int>> ret;\n        if(u == -1) u = __Root;\n      \
    \  while(1){\n            Vertex hv = __gethead(v), hu = __gethead(u);\n     \
    \       if(__Depth[hv] > __Depth[hu]) swap(v, u), swap(hv, hu);\n            if(hv\
    \ == hu){\n                if(__Depth[v] > __Depth[u]) swap(v, u);\n         \
    \       auto [vc, vi] = __VertexIndex[v];\n                auto [uc, ui] = __VertexIndex[u];\n\
    \                ret.push_back({__Offset[vc] + vi, __Offset[uc] + ui + 1});\n\
    \                return ret;\n            }\n            auto [uc, ui] = __VertexIndex[u];\n\
    \            ret.push_back({__Offset[uc], __Offset[uc] + ui + 1});\n         \
    \   u = __ParentVertex[hu];\n        }\n    }\n};\n"
  code: "/**\n * @file HeavyLightDecomposition.hpp\n * @author log K (lX57)\n * @brief\
    \ Heavy Light Decomposition - HL\u5206\u89E3\n * @version 2.0\n * @date 2023-10-04\n\
    \ */\n\n#include \"../Graph/GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct HeavyLightDecomposition{\n    using ColumnIndex = int;\n    using ColumnData\
    \ = pair<bool, int>; // `{isVertex, ID(Vertex or EdgeID)}`\n\n    private:\n \
    \   Vertex __Root;\n\n    Graph<CostType> &G;\n    vector<int> __SubtreeSize;\
    \ // \u9802\u70B9 `i` \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\
    \u70B9\u6570\n    vector<int> __Depth; // \u9802\u70B9 `i` \u306E\u6839\u304B\u3089\
    \u306E\u6DF1\u3055\n    vector<Vertex> __ParentVertex; // \u9802\u70B9 `i` \u306E\
    \u89AA\u306E\u9802\u70B9\uFF08\u6839\u306E\u5834\u5408\u306F `-1` \uFF09\n   \
    \ vector<EdgeID> __ParentEdge; // \u9802\u70B9 `i` \u3068\u305D\u306E\u89AA\u3092\
    \u7D50\u3076\u8FBA\u756A\u53F7\uFF08\u6839\u306E\u5834\u5408\u306F `-1` \uFF09\
    \n    vector<Vertex> __ChildVertex; // \u8FBA `i` \u304C\u7D50\u30762\u9802\u70B9\
    \u306E\u3046\u3061\u3001\u5B50\u306E\u65B9\u306E\u9802\u70B9\n\n    vector<vector<ColumnData>>\
    \ __Columns; // \u5404\u5217\u306B\u542B\u307E\u308C\u308B\u9802\u70B9/\u8FBA\u306E\
    \u30C7\u30FC\u30BF\n    vector<pair<ColumnIndex, int>> __VertexIndex, __EdgeIndex;\
    \ // `Columns` \u5185\u306B\u304A\u3051\u308B\u5404\u9802\u70B9/\u8FBA\u306E\u4F4D\
    \u7F6E\u60C5\u5831\n    vector<int> __Offset; // 1\u5217\u306B\u4E26\u3079\u305F\
    \u3068\u304D\u306E\u5404\u5217\u306E\u5148\u982D\u306E\u4F4D\u7F6E\uFF080-index\uFF09\
    \n\n    int __dfs1(Vertex now, Vertex par){\n        int ret = 0;\n        for(Edge<CostType>\
    \ e : G.get_incident(now)){\n            if(e.to == par) continue;\n         \
    \   __Depth[e.to] = __Depth[now] + 1;\n            __ParentVertex[e.to] = now;\n\
    \            __ParentEdge[e.to] = e.ID;\n            __ChildVertex[e.ID] = e.to;\n\
    \            ret += __dfs1(e.to, now);\n        }\n        return __SubtreeSize[now]\
    \ = ret + 1;\n    }\n\n    void __dfs2(Vertex now, Vertex par, ColumnIndex col){\n\
    \        // \u65B0\u3057\u3044\u5217\u306E\u5834\u5408\u306F\u5217\u3092\u5897\
    \u3084\u3059\n        if(__Columns.size() == col) __Columns.emplace_back(vector<ColumnData>{});\n\
    \n        // \u5217\u306B\u9802\u70B9\u3092\u8FFD\u52A0\n        __VertexIndex[now]\
    \ = {col, __Columns[col].size()};\n        __Columns[col].push_back({true, now});\n\
    \n        Edge<CostType> heavy;\n        int maxsubtree = 0;\n        for(Edge<CostType>\
    \ e : G.get_incident(now)){\n            if(e.to == par) continue;\n         \
    \   if(maxsubtree < __SubtreeSize[e.to]){\n                heavy = e;\n      \
    \          maxsubtree = __SubtreeSize[e.to];\n            }\n        }\n\n   \
    \     if(maxsubtree){\n            // heavy\u306A\u8FBA\u304C\u5B58\u5728\u3059\
    \u308B\u5834\u5408\u3001\u4ECA\u306E\u5217\u306B\u8FFD\u52A0\u3059\u308B\u5F62\
    \u3067\u518D\u5E30\u3092\u884C\u3046\n            __dfs2(heavy.to, now, col);\n\
    \        }\n\n        // light\u306A\u8FBA\u306B\u5BFE\u3057\u3066\u65B0\u3057\
    \u3044\u5217\u3092\u751F\u3084\u3057\u3064\u3064\u518D\u5E30\u3092\u884C\u3046\
    \n        for(Edge<CostType> e : G.get_incident(now)){\n            if(e.to ==\
    \ par || e.to == heavy.to) continue;\n            __dfs2(e.to, now, __Columns.size());\n\
    \        }\n    }\n\n    Vertex __gethead(Vertex v){\n        auto [i, j] = __VertexIndex[v];\n\
    \        return __Columns[i][0].second;\n    }\n\n    public:\n    HeavyLightDecomposition(Graph<CostType>\
    \ &G, Vertex Root = 0) : G(G), __Root(Root){\n        __SubtreeSize.resize(G.vsize(),\
    \ 0);\n        __Depth.resize(G.vsize(), 0);\n        __ParentVertex.resize(G.vsize(),\
    \ -1);\n        __ParentEdge.resize(G.vsize(), -1);\n        __ChildVertex.resize(G.esize(),\
    \ -1);\n        __dfs1(__Root, -1);\n        #ifdef LOGK\n            cerr <<\
    \ \"[HLD] DFS 1 Complete.\" << endl;\n        #endif\n        __VertexIndex.resize(G.vsize());\n\
    \        __dfs2(__Root, -1, 0);\n        #ifdef LOGK\n            cerr << \"[HLD]\
    \ DFS 2 Complete.\" << endl;\n        #endif\n        __Offset.resize(__Columns.size(),\
    \ 0);\n        for(int i = 1; i < __Columns.size(); ++i){\n            __Offset[i]\
    \ = __Offset[i - 1] + __Columns[i - 1].size();\n        }\n    }\n\n    int get_vertex_locate(Vertex\
    \ v){\n        return __Offset[__VertexIndex[v].first] + __VertexIndex[v].second;\n\
    \    }\n\n    vector<int> get_vertex_locations(){\n        vector<int> ret(G.vsize(),\
    \ -1);\n        for(Vertex i = 0; i < G.vsize(); ++i){\n            ret[i] = __Offset[__VertexIndex[i].first]\
    \ + __VertexIndex[i].second;\n        }\n        return ret;\n    }\n\n    vector<int>\
    \ get_edge_locations(){\n        vector<int> ret(G.esize(), -1);\n        for(EdgeID\
    \ e = 0; e < G.esize(); ++e){\n            Vertex i = __ChildVertex[e];\n    \
    \        ret[e] = __Offset[__VertexIndex[i].first] + __VertexIndex[i].second;\n\
    \        }\n        return ret;\n    }\n\n    Vertex lca(Vertex v, Vertex u){\n\
    \        #ifdef LOGK\n            cerr << \"LCA Query [\" << v << \", \" << u\
    \ << \"]\" << endl;\n        #endif\n        while(1){\n            Vertex hv\
    \ = __gethead(v), hu = __gethead(u);\n            if(__Depth[hv] > __Depth[hu])\
    \ swap(v, u), swap(hv, hu);\n            #ifdef LOGK\n                cerr <<\
    \ \" - Head of [\" << v << \", \" << u << \"] -> [\" << hv << \", \" << hu <<\
    \ \"]\" << endl;\n            #endif\n            if(hv == hu) return (__Depth[v]\
    \ < __Depth[u] ? v : u);\n            u = __ParentVertex[hu];\n        }\n   \
    \ }\n\n    vector<pair<int, int>> get_vertex_segment(Vertex v, Vertex u = -1){\n\
    \        vector<pair<int, int>> ret;\n        if(u == -1) u = __Root;\n      \
    \  while(1){\n            Vertex hv = __gethead(v), hu = __gethead(u);\n     \
    \       if(__Depth[hv] > __Depth[hu]) swap(v, u), swap(hv, hu);\n            if(hv\
    \ == hu){\n                if(__Depth[v] > __Depth[u]) swap(v, u);\n         \
    \       auto [vc, vi] = __VertexIndex[v];\n                auto [uc, ui] = __VertexIndex[u];\n\
    \                ret.push_back({__Offset[vc] + vi, __Offset[uc] + ui + 1});\n\
    \                return ret;\n            }\n            auto [uc, ui] = __VertexIndex[u];\n\
    \            ret.push_back({__Offset[uc], __Offset[uc] + ui + 1});\n         \
    \   u = __ParentVertex[hu];\n        }\n    }\n};"
  dependsOn:
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: latest/Tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2023-10-04 21:46:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_latest/AOJ-GRL-5-D-HLD.test.cpp
  - verify_latest/LC-VertexAddPathSum.test.cpp
  - verify_latest/AOJ-GRL-5-E.test.cpp
  - verify_latest/AOJ-GRL-5-C-HLD.test.cpp
documentation_of: latest/Tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/latest/Tree/HeavyLightDecomposition.hpp
- /library/latest/Tree/HeavyLightDecomposition.hpp.html
title: "Heavy Light Decomposition - HL\u5206\u89E3"
---
