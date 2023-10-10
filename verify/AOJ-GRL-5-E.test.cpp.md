---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/LazySegmentTree.hpp
    title: "Lazy Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728"
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/Tree/HeavyLightDecomposition.hpp
    title: "Heavy Light Decomposition - HL\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
  bundledCode: "#line 1 \"verify/AOJ-GRL-5-E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \n\n#line 1 \"library/Tree/HeavyLightDecomposition.hpp\"\n/**\n * @file HeavyLightDecomposition.hpp\n\
    \ * @author log K (lX57)\n * @brief Heavy Light Decomposition - HL\u5206\u89E3\
    \n * @version 2.0\n * @date 2023-10-04\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"library/Tree/HeavyLightDecomposition.hpp\"\
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
    \   u = __ParentVertex[hu];\n        }\n    }\n};\n#line 1 \"library/DataStructure/LazySegmentTree.hpp\"\
    \n/**\n * @file LazySegmentTree.hpp\n * @author log K (lX57)\n * @brief Lazy Segment\
    \ Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @version\
    \ 2.0\n * @date 2023-10-02\n */\n\n#line 10 \"library/DataStructure/LazySegmentTree.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Monoid, typename OperatorMonoid =\
    \ Monoid>\nstruct LazySegmentTree{\n    private:\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n    using G = function<Monoid(Monoid, OperatorMonoid)>;\n    using\
    \ H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n\n    int __Size,\
    \ __Offset, __ZeroIndex;\n    vector<Monoid> __Data;\n    vector<OperatorMonoid>\
    \ __Lazy;\n    const F f;\n    const G g;\n    const H h;\n    const Monoid __M1;\n\
    \    const OperatorMonoid __OM1;\n\n    inline void __Check(int x){\n        assert(1\
    \ <= x && x <= __Size);\n    }\n\n    void __eval(int k){\n        if(__Lazy[k]\
    \ == __OM1) return;\n        if(k < __Size){\n            __Lazy[k * 2 + 0] =\
    \ h(__Lazy[k * 2 + 0], __Lazy[k]);\n            __Lazy[k * 2 + 1] = h(__Lazy[k\
    \ * 2 + 1], __Lazy[k]);\n        }\n        __Data[k] = g(__Data[k], __Lazy[k]);\n\
    \        __Lazy[k] = __OM1;\n    }\n\n    void __update(int ul, int ur, OperatorMonoid\
    \ x, int left, int right, int cell){\n        __eval(cell);\n        if(ul <=\
    \ left && right <= ur){\n            __Lazy[cell] = h(__Lazy[cell], x);\n    \
    \        __eval(cell);\n        }\n        else if(ul < right && left < ur){\n\
    \            int mid = (left + right) / 2;\n            __update(ul, ur, x, left,\
    \ mid, cell * 2 + 0);\n            __update(ul, ur, x, mid, right, cell * 2 +\
    \ 1);\n            __Data[cell] = f(__Data[cell * 2 + 0], __Data[cell * 2 + 1]);\n\
    \        }\n    }\n\n    Monoid __query(int ql, int qr, int left, int right, int\
    \ cell){\n        __eval(cell);\n        if(qr <= left || right <= ql){\n    \
    \        return __M1;\n        }\n        if(ql <= left && right <= qr){\n   \
    \         return __Data[cell];\n        }\n        int mid = (left + right) /\
    \ 2;\n        Monoid ans_left = __query(ql, qr, left, mid, cell * 2 + 0);\n  \
    \      Monoid ans_right = __query(ql, qr, mid, right, cell * 2 + 1);\n       \
    \ return f(ans_left, ans_right);\n    }\n\n    public:\n    /**\n     * @brief\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\u6570 `Size` \u3067\u521D\
    \u671F\u5316\u3059\u308B\u3002\n     * @param Size \u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\u306E\u8981\u7D20\u6570\n     * @param Merge \u533A\u9593\u53D6\u5F97\u3092\
    \u884C\u3046\u6F14\u7B97\n     * @param Mapping \u9045\u5EF6\u8A55\u4FA1\u306E\
    \u9069\u7528\u3092\u884C\u3046\u6F14\u7B97\n     * @param Composite \u9045\u5EF6\
    \u8A55\u4FA1\u306E\u5408\u6210\u3092\u884C\u3046\u6F14\u7B97\n     * @param Monoid_Identity\
    \ \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param OperatorMonoid_Identity\
    \ \u64CD\u4F5C\u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param\
    \ ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\u304B (default =\
    \ `false`)\n     */\n    LazySegmentTree(int Size, F Merge, G Mapping, H Composite,\n\
    \    const Monoid &Monoid_Identity, const OperatorMonoid &OperatorMonoid_Identity,\
    \ bool ZeroIndex = false)\n    : f(Merge), g(Mapping), h(Composite), __M1(Monoid_Identity),\
    \ __OM1(OperatorMonoid_Identity), __ZeroIndex(ZeroIndex){\n        __Size = 1;\n\
    \        while(__Size < Size) __Size <<= 1;\n        __Offset = __Size - 1;\n\
    \        __Data.resize(2 * __Size, __M1);\n        __Lazy.resize(2 * __Size, __OM1);\n\
    \    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\
    \u7BC9\u3059\u308B\u3002\n     * @attention \u5FC5\u305A `set()` \u3067\u521D\u671F\
    \u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\u3089\u547C\u3073\u51FA\u3059\u3053\
    \u3068\uFF01\n     */\n    void build(){\n        for(int i = __Offset; i >= 1;\
    \ --i){\n            __Data[i] = f(__Data[i * 2 + 0], __Data[i * 2 + 1]);\n  \
    \      }\n    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u306E\u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\u308B\u3002\n     * @param Index\
    \ \u4EE3\u5165\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     *\
    \ @param Value \u4EE3\u5165\u3059\u308B\u5024\n     */\n    void set(int Index,\
    \ Monoid Value){\n        __Check(Index + __ZeroIndex);\n        __Data[__Offset\
    \ + Index + __ZeroIndex] = Value;\n    }\n\n    /**\n     * @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u3092\u914D\u5217 `Init_Data` \u3067\u521D\u671F\u5316\
    \u3059\u308B\u3002\n     * @param Init_Data \u521D\u671F\u30C7\u30FC\u30BF\u306E\
    \u914D\u5217\n     * @param Merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\
    \u7B97\n     * @param Mapping \u9045\u5EF6\u8A55\u4FA1\u306E\u9069\u7528\u3092\
    \u884C\u3046\u6F14\u7B97\n     * @param Composite \u9045\u5EF6\u8A55\u4FA1\u306E\
    \u5408\u6210\u3092\u884C\u3046\u6F14\u7B97\n     * @param Monoid_Identity \u30E2\
    \u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param OperatorMonoid_Identity\
    \ \u64CD\u4F5C\u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param\
    \ ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\u304B (default =\
    \ `false`)\n     */\n    LazySegmentTree(vector<Monoid> &Init_Data, F Merge, G\
    \ Mapping, H Composite,\n    const Monoid &Monoid_Identity, const OperatorMonoid\
    \ &OperatorMonoid_Identity, bool ZeroIndex = false)\n    : f(Merge), g(Mapping),\
    \ h(Composite), __M1(Monoid_Identity), __OM1(OperatorMonoid_Identity), __ZeroIndex(ZeroIndex){\n\
    \        __Size = 1;\n        while(__Size < (int)Init_Data.size()) __Size <<=\
    \ 1;\n        __Offset = __Size - 1;\n        __Data.resize(2 * __Size, __M1);\n\
    \        __Lazy.resize(2 * __Size, __OM1);\n        for(int i = 0; i < (int)Init_Data.size();\
    \ ++i){\n            __Data[__Size + i] = Init_Data[i];\n        }\n        build();\n\
    \    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[left, Right)` \u306B\
    \u5BFE\u3057\u3066\u533A\u9593\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\
    \u3059\u308B\u3002\n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\
    \n     * @param Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @param\
    \ OP \u66F4\u65B0\u64CD\u4F5C\n     */\n    void update(int Left, int Right, OperatorMonoid\
    \ OP){\n        __Check(Left + __ZeroIndex);\n        __Check(Right + __ZeroIndex\
    \ - 1);\n        __update(Left + __ZeroIndex, Right + __ZeroIndex, OP, 1, __Size\
    \ + 1, 1);\n    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[Left, Right)`\
    \ \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\u884C\
    \u3046\u3002\n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n\
    \     * @param Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid query(int Left,\
    \ int Right){\n        __Check(Left + __ZeroIndex);\n        __Check(Right + __ZeroIndex\
    \ - 1);\n        return __query(Left + __ZeroIndex, Right + __ZeroIndex, 1, __Size\
    \ + 1, 1);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\
    \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param k \u53D6\u5F97\
    \u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     * @return Monoid\
    \ \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid get(int k){\n    \
    \    __Check(k + __ZeroIndex);\n        return __Data[__Offset + k + __ZeroIndex];\n\
    \    }\n\n    Monoid operator[](const int &k){\n        return get(k);\n    }\n\
    };\n#line 5 \"verify/AOJ-GRL-5-E.test.cpp\"\n\nstruct Data{\n    long long val{0};\n\
    \    long long len{1};\n\n    Data() : val(0), len(1){}\n    Data(int val, int\
    \ len) : val(val), len(len){}\n\n    bool operator==(const Data& y){\n       \
    \ return val == y.val && len == y.len;\n    }\n\n    static Data Merge(const Data&\
    \ x, const Data& y){\n        Data ret;\n        ret.val = x.val + y.val;\n  \
    \      ret.len = x.len + y.len;\n        return ret;\n    }\n\n    static Data\
    \ Mapping(const Data& x, const long long y){\n        Data ret;\n        ret.val\
    \ = x.val + y * x.len;\n        ret.len = x.len;\n        return ret;\n    }\n\
    };\n\nint main(){\n    int n; cin >> n;\n    Graph<long long> G(n);\n    for(int\
    \ i = 0; i < n; ++i){\n        int k; cin >> k;\n        for(int j = 0; j < k;\
    \ ++j){\n            int c; cin >> c;\n            G.add(i, c);\n        }\n \
    \   }\n\n    HeavyLightDecomposition<long long> HLD(G);\n    auto vdic = HLD.get_vertex_locations();\n\
    \    vector<Data> Init_Data(n, Data());\n    LazySegmentTree<Data, long long>\
    \ seg(Init_Data,\n        [](const Data l, const Data r){return Data::Merge(l,\
    \ r);},\n        [](const Data l, const long long r){return Data::Mapping(l, r);},\n\
    \        [](const long long l, const long long r){return l + r;},\n        Data(),\
    \ 0, true\n    );\n\n    int q; cin >> q;\n    while(q--){\n        int t; cin\
    \ >> t;\n        if(t == 0){\n            int v, w; cin >> v >> w;\n         \
    \   auto ret = HLD.get_vertex_segment(0, v);\n            for(auto [l, r] : ret){\n\
    \                seg.update(l, r, w);\n            }\n            seg.update(0,\
    \ 1, -w);\n        }\n        else{\n            int u; cin >> u;\n          \
    \  auto ret = HLD.get_vertex_segment(0, u);\n            long long ans = 0LL;\n\
    \            for(auto [l, r] : ret){\n                ans += seg.query(l, r).val;\n\
    \            }\n            cout << ans << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \n\n#include \"../library/Tree/HeavyLightDecomposition.hpp\"\n#include \"../library/DataStructure/LazySegmentTree.hpp\"\
    \n\nstruct Data{\n    long long val{0};\n    long long len{1};\n\n    Data() :\
    \ val(0), len(1){}\n    Data(int val, int len) : val(val), len(len){}\n\n    bool\
    \ operator==(const Data& y){\n        return val == y.val && len == y.len;\n \
    \   }\n\n    static Data Merge(const Data& x, const Data& y){\n        Data ret;\n\
    \        ret.val = x.val + y.val;\n        ret.len = x.len + y.len;\n        return\
    \ ret;\n    }\n\n    static Data Mapping(const Data& x, const long long y){\n\
    \        Data ret;\n        ret.val = x.val + y * x.len;\n        ret.len = x.len;\n\
    \        return ret;\n    }\n};\n\nint main(){\n    int n; cin >> n;\n    Graph<long\
    \ long> G(n);\n    for(int i = 0; i < n; ++i){\n        int k; cin >> k;\n   \
    \     for(int j = 0; j < k; ++j){\n            int c; cin >> c;\n            G.add(i,\
    \ c);\n        }\n    }\n\n    HeavyLightDecomposition<long long> HLD(G);\n  \
    \  auto vdic = HLD.get_vertex_locations();\n    vector<Data> Init_Data(n, Data());\n\
    \    LazySegmentTree<Data, long long> seg(Init_Data,\n        [](const Data l,\
    \ const Data r){return Data::Merge(l, r);},\n        [](const Data l, const long\
    \ long r){return Data::Mapping(l, r);},\n        [](const long long l, const long\
    \ long r){return l + r;},\n        Data(), 0, true\n    );\n\n    int q; cin >>\
    \ q;\n    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n       \
    \     int v, w; cin >> v >> w;\n            auto ret = HLD.get_vertex_segment(0,\
    \ v);\n            for(auto [l, r] : ret){\n                seg.update(l, r, w);\n\
    \            }\n            seg.update(0, 1, -w);\n        }\n        else{\n\
    \            int u; cin >> u;\n            auto ret = HLD.get_vertex_segment(0,\
    \ u);\n            long long ans = 0LL;\n            for(auto [l, r] : ret){\n\
    \                ans += seg.query(l, r).val;\n            }\n            cout\
    \ << ans << endl;\n        }\n    }\n}"
  dependsOn:
  - library/Tree/HeavyLightDecomposition.hpp
  - library/Graph/GraphTemplate.hpp
  - library/DataStructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-5-E.test.cpp
  requiredBy: []
  timestamp: '2023-10-10 13:58:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-GRL-5-E.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-5-E.test.cpp
- /verify/verify/AOJ-GRL-5-E.test.cpp.html
title: verify/AOJ-GRL-5-E.test.cpp
---