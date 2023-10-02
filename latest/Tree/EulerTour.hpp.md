---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"latest/Tree/EulerTour.hpp\"\n\n\n#line 2 \"latest/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 2.2\n * @date 2023-10-02\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing Vertex = int;\nusing EdgeID = int;\nusing EdgeIndex = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    EdgeID ID{-1};\n    Vertex src, to;\n    CostType\
    \ cost, cap;\n    EdgeIndex sidx, tidx;\n\n    Edge() = default;\n\n    void print(){\n\
    \        cerr << \"Edge \" << ID << \" : (\" << src << \" -> \" << to << \"),\
    \ Cost = \" << cost << \", Capacity = \" << cap << \", Place = [\" << sidx <<\
    \ \", \" << tidx << \"]\" << endl;\n    }\n};\n\ntemplate<typename CostType>\n\
    using EdgeSet = vector<Edge<CostType>>;\ntemplate<typename CostType>\nusing IncidentList\
    \ = vector<vector<Edge<CostType>>>;\nusing AdjacentList = vector<vector<Vertex>>;\n\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 4 \"latest/Tree/EulerTour.hpp\"\
    \n\ntemplate<typename CostType>\nstruct EulerTour{\n    private:\n    int __Size,\
    \ __Offset, __Counter;\n    Vertex __Root;\n    Graph<CostType> &G;\n    vector<int>\
    \ __Arrival, __Departure;\n\n    void __dfs(Vertex now, Vertex parent){\n    \
    \    __Arrival[now] = __Counter++;\n        for(auto &e : G[now]){\n         \
    \   if(e.to == parent) continue;\n            __dfs(e.to, now);\n        }\n \
    \       __Departure[now] = __Counter++;\n    }\n\n    public:\n    EulerTour(Graph<CostType>\
    \ &G, Vertex Root = 0, int Offset = 1) : G(G), __Size(G.vsize()), __Root(Root),\
    \ __Arrival(G.vsize()), __Departure(G.vsize()), __Offset(Offset){\n        __Counter\
    \ = __Offset;\n        __dfs(__Root, -1);\n    }\n\n    vector<int> get_arrival_list(){\n\
    \        return __Arrival;\n    }\n\n    vector<int> get_departure_list(){\n \
    \       return __Departure;\n    }\n\n    pair<int, int> get_way(Vertex Target){\n\
    \        assert(0 <= Target && Target < G.vsize());\n        return {__Arrival[__Root],\
    \ __Arrival[Target]};\n    }\n\n    pair<int, int> get_around(Vertex Target){\n\
    \        assert(0 <= Target && Target < G.vsize());\n        return {__Arrival[Target],\
    \ __Departure[Target]};\n    }\n};\n"
  code: "\n\n#include \"../Graph/GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct EulerTour{\n    private:\n    int __Size, __Offset, __Counter;\n    Vertex\
    \ __Root;\n    Graph<CostType> &G;\n    vector<int> __Arrival, __Departure;\n\n\
    \    void __dfs(Vertex now, Vertex parent){\n        __Arrival[now] = __Counter++;\n\
    \        for(auto &e : G[now]){\n            if(e.to == parent) continue;\n  \
    \          __dfs(e.to, now);\n        }\n        __Departure[now] = __Counter++;\n\
    \    }\n\n    public:\n    EulerTour(Graph<CostType> &G, Vertex Root = 0, int\
    \ Offset = 1) : G(G), __Size(G.vsize()), __Root(Root), __Arrival(G.vsize()), __Departure(G.vsize()),\
    \ __Offset(Offset){\n        __Counter = __Offset;\n        __dfs(__Root, -1);\n\
    \    }\n\n    vector<int> get_arrival_list(){\n        return __Arrival;\n   \
    \ }\n\n    vector<int> get_departure_list(){\n        return __Departure;\n  \
    \  }\n\n    pair<int, int> get_way(Vertex Target){\n        assert(0 <= Target\
    \ && Target < G.vsize());\n        return {__Arrival[__Root], __Arrival[Target]};\n\
    \    }\n\n    pair<int, int> get_around(Vertex Target){\n        assert(0 <= Target\
    \ && Target < G.vsize());\n        return {__Arrival[Target], __Departure[Target]};\n\
    \    }\n};"
  dependsOn:
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: latest/Tree/EulerTour.hpp
  requiredBy: []
  timestamp: '2023-10-03 01:00:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: latest/Tree/EulerTour.hpp
layout: document
redirect_from:
- /library/latest/Tree/EulerTour.hpp
- /library/latest/Tree/EulerTour.hpp.html
title: latest/Tree/EulerTour.hpp
---
