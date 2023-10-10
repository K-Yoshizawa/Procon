---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/Tree/LowestCommonAncestor.hpp
    title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"verify/AOJ-GRL-5-C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#line 1 \"library/Tree/LowestCommonAncestor.hpp\"\n/**\n * @file LowestCommonAncestor.hpp\n\
    \ * @author log K (lX57)\n * @brief Lowest Common Ancestor - \u6700\u5C0F\u5171\
    \u901A\u7956\u5148\n * @version 2.0\n * @date 2023-10-04\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"library/Tree/LowestCommonAncestor.hpp\"\
    \n\ntemplate<typename CostType>\nstruct LowestCommonAncestor{\n    private:\n\
    \    Graph<CostType> &G;\n    int __Height;\n    vector<int> __Depth;\n    vector<vector<Vertex>>\
    \ __Parent;\n\n    void __dfs(Vertex v, Vertex p, int d){\n        __Parent[0][v]\
    \ = p;\n        __Depth[v] = d;\n        for(auto &e : G.get_incident(v)){\n \
    \           if(e.to != p) __dfs(e.to, v, d + 1);\n        }\n    }\n\n    public:\n\
    \    LowestCommonAncestor(Graph<CostType> &G, Vertex Root) : G(G), __Height(32){\n\
    \        __Depth.resize(G.vsize());\n        __Parent.resize(__Height, vector<Vertex>(G.vsize(),\
    \ -1));\n        __dfs(Root, -1, 0);\n        for(int k = 0; k + 1 < __Height;\
    \ ++k){\n            for(Vertex v = 0; v < G.vsize(); ++v){\n                if(__Parent[k][v]\
    \ < 0) __Parent[k + 1][v] = -1;\n                else __Parent[k + 1][v] = __Parent[k][__Parent[k][v]];\n\
    \            }\n        }\n    }\n\n    Vertex get(Vertex u, Vertex v){\n    \
    \    if(__Depth[u] > __Depth[v]) swap(u, v);\n        for(int k = 0; k < __Height;\
    \ ++k){\n            if((__Depth[v] - __Depth[u]) >> k & 1){\n               \
    \ v = __Parent[k][v];\n            }\n        }\n        if(u == v) return u;\n\
    \        for(int k = __Height - 1; k >= 0; --k){\n            if(__Parent[k][u]\
    \ != __Parent[k][v]){\n                u = __Parent[k][u];\n                v\
    \ = __Parent[k][v];\n            }\n        }\n        return __Parent[0][u];\n\
    \    }\n};\n#line 4 \"verify/AOJ-GRL-5-C.test.cpp\"\n\nint main(){\n    int n;\
    \ cin >> n;\n    Graph<int> G(n);\n    for(int i = 0; i <= n - 1; ++i){\n    \
    \    int k; cin >> k;\n        for(int j = 0; j < k; ++j){\n            int c;\
    \ cin >> c;\n            G.add(i, c);\n        }\n    }\n\n    LowestCommonAncestor<int>\
    \ lca(G, 0);\n    int q; cin >> q;\n    while(q--){\n        int u, v; cin >>\
    \ u >> v;\n        cout << lca.get(u, v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#include \"../library/Tree/LowestCommonAncestor.hpp\"\n\nint main(){\n   \
    \ int n; cin >> n;\n    Graph<int> G(n);\n    for(int i = 0; i <= n - 1; ++i){\n\
    \        int k; cin >> k;\n        for(int j = 0; j < k; ++j){\n            int\
    \ c; cin >> c;\n            G.add(i, c);\n        }\n    }\n\n    LowestCommonAncestor<int>\
    \ lca(G, 0);\n    int q; cin >> q;\n    while(q--){\n        int u, v; cin >>\
    \ u >> v;\n        cout << lca.get(u, v) << endl;\n    }\n}"
  dependsOn:
  - library/Tree/LowestCommonAncestor.hpp
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-5-C.test.cpp
  requiredBy: []
  timestamp: '2023-10-10 13:58:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-GRL-5-C.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-5-C.test.cpp
- /verify/verify/AOJ-GRL-5-C.test.cpp.html
title: verify/AOJ-GRL-5-C.test.cpp
---
