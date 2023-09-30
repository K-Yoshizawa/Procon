---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/WarshallFloyd.hpp
    title: "Warshall Floyd - \u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DDD\u96E2"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"verify_latest/AOJ-GRL-1-C.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\n\n#line 1\
    \ \"latest/Graph/WarshallFloyd.hpp\"\n/**\n * @file WarshallFloyd.hpp\n * @author\
    \ log_K (lX57)\n * @brief WarshallFloyd - \u5168\u70B9\u5BFE\u9593\u6700\u77ED\
    \u7D4C\u8DEF\n * @version 2.0\n * @date 2023-08-31\n */\n\n#line 2 \"latest/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 2.1\n * @date 2023-08-31\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"latest/Graph/WarshallFloyd.hpp\"\
    \n\ntemplate<typename CostType>\nstruct WarshallFloyd{\n    private:\n    bool\
    \ __NegativeCycle;\n    int __Size;\n    CostType __INF;\n    vector<vector<CostType>>\
    \ __Dist;\n\n    void __solve(){\n        for(int k = 0; k < __Size; ++k){\n \
    \           for(int i = 0; i < __Size; ++i){\n                for(int j = 0; j\
    \ < __Size; ++j){\n                    if(__Dist[i][k] == __INF || __Dist[k][j]\
    \ == __INF) continue;\n                    __Dist[i][j] = min(__Dist[i][j], __Dist[i][k]\
    \ + __Dist[k][j]);\n                }\n            }\n        }\n        __NegativeCycle\
    \ = false;\n        for(int i = 0; i < __Size; ++i) __NegativeCycle |= __Dist[i][i]\
    \ < 0;\n    }\n\n    public:\n    WarshallFloyd(Graph<CostType> &G) : __Size(G.vsize()),\
    \ __INF(G.INF), __Dist(G.matrix()){\n        __solve();\n    }\n\n    WarshallFloyd(vector<vector<CostType>>\
    \ &M) : __Size((int)M.size()), __INF(numeric_limits<CostType>::max() / 2), __Dist(M){\n\
    \        __solve();\n    }\n\n    inline bool negative(){\n        return __NegativeCycle;\n\
    \    }\n\n    CostType dist(Vertex Start, Vertex Goal){\n        assert(0 <= Start\
    \ && Start < __Size);\n        assert(0 <= Goal && Goal < __Size);\n        return\
    \ __Dist[Start][Goal];\n    }\n    \n    void print(CostType NotAdjacent = numeric_limits<CostType>::max()\
    \ / 2, bool DisplayINF = true){\n        for(int i = 0; i < __Size; ++i){\n  \
    \          cout << (DisplayINF && __Dist[i][0] == NotAdjacent ? \"INF\" : to_string(__Dist[i][0]));\n\
    \            for(int j = 1; j < __Size; ++j){\n                cout << \" \" <<\
    \ (DisplayINF && __Dist[i][j] == NotAdjacent ? \"INF\" : to_string(__Dist[i][j]));\n\
    \            }\n            cout << endl;\n        }\n    }\n};\n#line 4 \"verify_latest/AOJ-GRL-1-C.test.cpp\"\
    \n\nint main(){\n    int V, E;\n    cin >> V >> E;\n    Graph<long long> G(V,\
    \ true);\n    for(int i = 0; i < E; ++i){\n        int s, t, d;\n        cin >>\
    \ s >> t >> d;\n        G.add(s, t, d);\n    }\n\n    WarshallFloyd<long long>\
    \ wf(G);\n    if(wf.negative()){\n        cout << \"NEGATIVE CYCLE\\n\";\n   \
    \ }\n    else{\n        wf.print();\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include \"../latest/Graph/WarshallFloyd.hpp\"\n\nint main(){\n    int V,\
    \ E;\n    cin >> V >> E;\n    Graph<long long> G(V, true);\n    for(int i = 0;\
    \ i < E; ++i){\n        int s, t, d;\n        cin >> s >> t >> d;\n        G.add(s,\
    \ t, d);\n    }\n\n    WarshallFloyd<long long> wf(G);\n    if(wf.negative()){\n\
    \        cout << \"NEGATIVE CYCLE\\n\";\n    }\n    else{\n        wf.print();\n\
    \    }\n}"
  dependsOn:
  - latest/Graph/WarshallFloyd.hpp
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify_latest/AOJ-GRL-1-C.test.cpp
  requiredBy: []
  timestamp: '2023-09-30 19:29:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_latest/AOJ-GRL-1-C.test.cpp
layout: document
redirect_from:
- /verify/verify_latest/AOJ-GRL-1-C.test.cpp
- /verify/verify_latest/AOJ-GRL-1-C.test.cpp.html
title: verify_latest/AOJ-GRL-1-C.test.cpp
---
