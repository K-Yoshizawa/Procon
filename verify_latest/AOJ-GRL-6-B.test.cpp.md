---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/Dijkstra.hpp
    title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/FlowTemplate.hpp
    title: "Flow Template - \u30D5\u30ED\u30FC\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/PrimalDual.hpp
    title: "Primal Dual - \u6700\u5C0F\u8CBB\u7528\u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"verify_latest/AOJ-GRL-6-B.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\n\n#line 1\
    \ \"latest/Graph/PrimalDual.hpp\"\n/**\n * @file PrimalDual.hpp\n * @author log\
    \ K (lX57)\n * @brief Primal Dual - \u6700\u5C0F\u8CBB\u7528\u6D41\n * @version\
    \ 1.0\n * @date 2023-09-01\n */\n\n#line 2 \"latest/Graph/FlowTemplate.hpp\"\n\
    \n/**\n * @file FlowTemplate.hpp\n * @author log K (lX57)\n * @brief Flow Template\
    \ - \u30D5\u30ED\u30FC\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 0.1\n\
    \ * @date 2023-09-29\n */\n\n#line 2 \"latest/Graph/GraphTemplate.hpp\"\n\n/**\n\
    \ * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph Template\
    \ - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 2.1\n\
    \ * @date 2023-08-31\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    using Vertex = int;\nusing EdgeID = int;\nusing EdgeIndex = int;\n\ntemplate<typename\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 12 \"latest/Graph/FlowTemplate.hpp\"\
    \n\n#define LOGK_FLOW\n\ntemplate<typename CostType>\nstruct Flow : public Graph<CostType>{\n\
    \    using Graph<CostType>::Graph;\n\n    vector<vector<int>> __Rev;\n\n    public:\n\
    \    void add(Vertex Source, Vertex To, CostType Capacity = 1, CostType Cost =\
    \ 1){\n        assert(0 <= Source && Source < this->__CntVertex);\n        assert(0\
    \ <= To && To < this->__CntVertex);\n        EdgeIndex sidx = this->__IL[Source].size(),\
    \ tidx = this->__IL[To].size();\n        Edge<CostType> es{this->__CntEdge, Source,\
    \ To, Cost, Capacity, sidx, tidx};\n        Edge<CostType> et{this->__CntEdge,\
    \ To, Source, -Cost, 0, tidx, sidx};\n        this->__ES.push_back(es);\n    \
    \    this->__RES.push_back(et);\n        this->__IL[Source].push_back(es), this->__AL[Source].push_back(To);\n\
    \        this->__IL[To].push_back(et), this->__AL[To].push_back(Source);\n   \
    \     ++this->__CntEdge;\n        if(__Rev.empty()) __Rev.resize(this->__CntVertex);\n\
    \        __Rev[Source].push_back(0), __Rev[To].push_back(1);\n    }\n\n    void\
    \ update(Vertex Source, EdgeIndex Index, CostType Amount){\n        Vertex To\
    \ = this->__IL[Source][Index].to;\n        EdgeIndex RIndex = this->__IL[Source][Index].tidx;\n\
    \        this->__IL[Source][Index].cap -= Amount;\n        this->__IL[To][RIndex].cap\
    \ += Amount;\n    }\n\n    EdgeSet<CostType> get(){\n        EdgeSet<CostType>\
    \ ret;\n        for(Vertex i = 0; i < this->__CntVertex; ++i){\n            for(EdgeIndex\
    \ j = 0; j < this->__IL[i].size(); ++j){\n                if(!__Rev[i][j]){\n\
    \                    ret.push_back(this->__IL[i][j]);\n                }\n   \
    \         }\n        }\n        return ret;\n    }\n};\n#line 1 \"latest/Graph/Dijkstra.hpp\"\
    \n/**\n * @file Dijkstra.hpp\n * @author log_K (lX57)\n * @brief Dijkstra - \u5358\
    \u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2\n * @version 2.1\n * @date 2023-08-31\n\
    \ */\n\n#line 10 \"latest/Graph/Dijkstra.hpp\"\n\ntemplate<typename CostType>\n\
    struct Dijkstra{\n    private:\n    Graph<CostType> &G;\n    vector<CostType>\
    \ __Dist, __Potential;\n    vector<Vertex> __PrevVertex;\n    vector<Edge<CostType>>\
    \ __PrevEdge;\n    Vertex __Start;\n\n    void __solve(){\n        __Dist.assign(G.vsize(),\
    \ G.INF);\n        __PrevVertex.assign(G.vsize(), -1);\n        __PrevEdge.assign(G.vsize(),\
    \ Edge<CostType>());\n        using p = pair<CostType, Vertex>;\n        priority_queue<p,\
    \ vector<p>, greater<p>> que;\n        que.emplace(__Potential[__Start], __Start);\n\
    \        __Dist[__Start] = __Potential[__Start];\n        while(que.size()){\n\
    \            auto [d, v] = que.top(); que.pop();\n            if(__Dist[v] < d)\
    \ continue;\n            for(auto e : G.get_incident(v)){\n                if(e.cap\
    \ > 0 && d + e.cost + __Potential[e.src] - __Potential[e.to] < __Dist[e.to]){\n\
    \                    __Dist[e.to] = d + e.cost + __Potential[e.src] - __Potential[e.to];\n\
    \                    __PrevVertex[e.to] = v;\n                    __PrevEdge[e.to]\
    \ = e;\n                    que.emplace(__Dist[e.to], e.to);\n               \
    \ }\n            }\n        }\n        for(Vertex i = 0; i < G.vsize(); ++i){\n\
    \            if(__Dist[i] != G.INF) __Dist[i] += __Potential[i] - __Potential[__Start];\n\
    \        }\n    }\n\n    public:\n    Dijkstra(Graph<CostType> &G) : G(G), __Dist(G.vsize()),\
    \ __Potential(G.vsize(), 0), __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Start(-1){}\n\
    \    \n    Dijkstra(Graph<CostType> &G, Vertex Start) : G(G), __Dist(G.vsize()),\
    \ __PrevVertex(G.vsize()), __PrevEdge(G.vsize()), __Potential(G.vsize(), 0), __Start(Start){\n\
    \        __solve();\n    }\n\n    void update_potential(vector<CostType> Potential){\n\
    \        assert(__Potential.size() == Potential.size());\n        __Potential\
    \ = Potential;\n    }\n\n    void rebuild(){\n        __solve();\n    }\n\n  \
    \  void build(Vertex Start){\n        assert(0 <= Start && Start < G.vsize());\n\
    \        if(Start != __Start){\n            __Start = Start;\n            __solve();\n\
    \        }\n    }\n\n    vector<CostType> all(Vertex Start){\n        assert(0\
    \ <= Start && Start < G.vsize());\n        if(Start != __Start) build(Start);\n\
    \        return __Dist;\n    }\n\n    CostType dist(Vertex Start, Vertex Goal){\n\
    \        assert(0 <= Start && Start < G.vsize());\n        assert(0 <= Goal &&\
    \ Goal < G.vsize());\n        if(Start != __Start){\n            __Start = Start;\n\
    \            __solve();\n        }\n        return __Dist[Goal];\n    }\n\n  \
    \  EdgeSet<CostType> restore_edge(Vertex Goal){\n        EdgeSet<CostType> ret;\n\
    \        Vertex now = Goal;\n        while(__PrevEdge[now].ID != -1){\n      \
    \      ret.push_back(__PrevEdge[now]);\n            now = __PrevEdge[now].src;\n\
    \        }\n        reverse(ret.begin(), ret.end());\n        return ret;\n  \
    \  }\n\n    void print(bool DisplayINF = true, char Delimiter = ' '){\n      \
    \  cout << (DisplayINF && __Dist[0] == G.INF ? \"INF\" : to_string(__Dist[0]));\n\
    \        for(int i = 1; i < (int)__Dist.size(); ++i){\n            cout << Delimiter\
    \ << (DisplayINF && __Dist[i] == G.INF ? \"INF\" : to_string(__Dist[i]));\n  \
    \      }\n        cout << endl;\n    }\n};\n#line 11 \"latest/Graph/PrimalDual.hpp\"\
    \n\ntemplate<typename CostType>\nstruct PrimalDual{\n    private:\n    Flow<CostType>\
    \ &G;\n    vector<CostType> Potential;\n\n    public:\n    PrimalDual(Flow<CostType>\
    \ &G) : G(G), Potential(G.vsize()){}\n\n    CostType solve(Vertex Start, Vertex\
    \ Goal, CostType F){\n        CostType ret = 0;\n        Potential.assign(G.vsize(),\
    \ 0);\n\n        while(F > 0){\n            Dijkstra<CostType> dk(G);\n      \
    \      dk.update_potential(Potential);\n            vector<CostType> Dist = dk.all(Start);\n\
    \            if(Dist[Goal] == G.INF) return -1;\n            auto path = dk.restore_edge(Goal);\n\
    \            CostType f = F;\n            for(auto e : path){\n              \
    \  f = min(f, e.cap);\n            }\n            F -= f;\n            ret +=\
    \ f * Dist[Goal];\n            for(auto e : path){\n                G.update(e.src,\
    \ e.sidx, f);\n            }\n            for(int i = 0; i < Dist.size(); ++i){\n\
    \                CostType RawDist = Dist[i] -= Potential[i] - Potential[Start];\n\
    \                Potential[i] = min(Potential[i] + RawDist, G.INF);\n        \
    \    }\n        }\n        return ret;\n    }\n};\n#line 4 \"verify_latest/AOJ-GRL-6-B.test.cpp\"\
    \n\nint main(){\n    int V, E, F;\n    cin >> V >> E >> F;\n    Flow<int> G(V);\n\
    \    for(int i = 0; i < E; ++i){\n        Vertex u, v;\n        int c, d;\n  \
    \      cin >> u >> v >> c >> d;\n        G.add(u, v, c, d);\n    }\n\n    PrimalDual<int>\
    \ pd(G);\n\n    cout << pd.solve(0, V - 1, F) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \n\n#include \"../latest/Graph/PrimalDual.hpp\"\n\nint main(){\n    int V, E,\
    \ F;\n    cin >> V >> E >> F;\n    Flow<int> G(V);\n    for(int i = 0; i < E;\
    \ ++i){\n        Vertex u, v;\n        int c, d;\n        cin >> u >> v >> c >>\
    \ d;\n        G.add(u, v, c, d);\n    }\n\n    PrimalDual<int> pd(G);\n\n    cout\
    \ << pd.solve(0, V - 1, F) << endl;\n}"
  dependsOn:
  - latest/Graph/PrimalDual.hpp
  - latest/Graph/FlowTemplate.hpp
  - latest/Graph/GraphTemplate.hpp
  - latest/Graph/Dijkstra.hpp
  isVerificationFile: true
  path: verify_latest/AOJ-GRL-6-B.test.cpp
  requiredBy: []
  timestamp: '2023-09-30 19:29:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_latest/AOJ-GRL-6-B.test.cpp
layout: document
redirect_from:
- /verify/verify_latest/AOJ-GRL-6-B.test.cpp
- /verify/verify_latest/AOJ-GRL-6-B.test.cpp.html
title: verify_latest/AOJ-GRL-6-B.test.cpp
---
