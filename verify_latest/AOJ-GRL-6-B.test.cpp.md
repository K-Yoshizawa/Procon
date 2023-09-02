---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: latest/Graph/Dijkstra.hpp
    title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
  - icon: ':x:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':x:'
    path: latest/Graph/PrimalDual.hpp
    title: "Primal Dual - \u6700\u5C0F\u8CBB\u7528\u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"verify_latest/AOJ-GRL-6-B.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\n\n#line 1\
    \ \"latest/Graph/PrimalDual.hpp\"\n/**\n * @file PrimalDual.hpp\n * @author log\
    \ K (lX57)\n * @brief Primal Dual - \u6700\u5C0F\u8CBB\u7528\u6D41\n * @version\
    \ 1.0\n * @date 2023-09-01\n */\n\n#line 1 \"latest/Graph/Dijkstra.hpp\"\n/**\n\
    \ * @file Dijkstra.hpp\n * @author log_K (lX57)\n * @brief Dijkstra - \u5358\u4E00\
    \u59CB\u70B9\u6700\u77ED\u8DDD\u96E2\n * @version 2.1\n * @date 2023-08-31\n */\n\
    \n#line 2 \"latest/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
    \ * @author log K (lX57)\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\n * @version 2.1\n * @date 2023-08-31\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\nusing EdgeID =\
    \ int;\n\ntemplate<typename CostType>\nstruct Edge{\n    Vertex from, to;\n  \
    \  CostType cost, cap;\n\n    Edge(Vertex from, Vertex to, CostType cost) : from(from),\
    \ to(to), cost(cost), cap(1){}\n    Edge(Vertex from, Vertex to, CostType cap,\
    \ CostType cost) : from(from), to(to), cost(cost), cap(cap){}\n\n    Vertex getto(Vertex\
    \ v){\n        assert(v == from || v == to);\n        return from ^ to ^ v;\n\
    \    }\n\n    void swap(){\n        Vertex tmp = from;\n        from = to;\n \
    \       to = tmp;\n    }\n};\n\ntemplate<typename CostType>\nstruct Graph{\n \
    \   private:\n    int __CntVertex, __CntEdge;\n    bool __isDirected;\n    vector<Edge<CostType>>\
    \ __EdgeSet, __RevEdgeSet;\n    vector<vector<pair<EdgeID, bool>>> __IncidentList;\n\
    \    vector<pair<int, int>> __EdgePlace;\n\n    public:\n    CostType INF;\n\n\
    \    Graph(int VertexSize, bool isDirected = false) : __CntVertex(VertexSize),\
    \ __isDirected(isDirected), __CntEdge(0), __IncidentList(VertexSize), INF(numeric_limits<CostType>::max()\
    \ / 2){}\n\n    Graph() = default;\n\n    void add(Vertex s, Vertex t, CostType\
    \ w = 1){\n        assert(0 <= s && s < __CntVertex);\n        assert(0 <= t &&\
    \ t < __CntVertex);\n        __EdgePlace.push_back({(int)__IncidentList[s].size(),\
    \ (int)__IncidentList[t].size()});\n        __EdgeSet.push_back(Edge<CostType>(s,\
    \ t, w));\n        __IncidentList[s].push_back({__CntEdge, false});\n        __RevEdgeSet.push_back(Edge<CostType>(t,\
    \ s, w));\n        if(!__isDirected) __IncidentList[t].push_back({__CntEdge, true});\n\
    \        ++__CntEdge;\n    }\n\n    void add_flow(Vertex Source, Vertex Sink,\
    \ CostType Capacity, CostType Cost = 1){\n        assert(0 <= Source && Source\
    \ < __CntVertex);\n        assert(0 <= Sink && Sink < __CntVertex);\n        __EdgeSet.push_back(Edge<CostType>(Source,\
    \ Sink, Capacity, Cost));\n        __IncidentList[Source].push_back({__CntEdge,\
    \ false});\n        __RevEdgeSet.push_back(Edge<CostType>(Sink, Source, 0, -Cost));\n\
    \        __IncidentList[Sink].push_back({__CntEdge, true});\n        ++__CntEdge;\n\
    \    }\n\n    void update_flow(EdgeID edge_id, bool isReverse, CostType Decrease){\n\
    \        if(isReverse) Decrease *= -1;\n        __EdgeSet[edge_id].cap -= Decrease;\n\
    \        __RevEdgeSet[edge_id].cap += Decrease;\n    }\n\n    vector<vector<CostType>>\
    \ matrix(CostType NotAdjacent = numeric_limits<CostType>::max() / 2){\n      \
    \  vector ret(__CntVertex, vector(__CntVertex, NotAdjacent));\n        for(Vertex\
    \ v = 0; v < __CntVertex; ++v){\n            ret[v][v] = 0;\n            for(auto\
    \ [eid, rev] : __IncidentList[v]){\n                if(!rev) ret[v][__EdgeSet[eid].to]\
    \ = __EdgeSet[eid].cost;\n                else ret[v][__RevEdgeSet[eid].to] =\
    \ __RevEdgeSet[eid].cost;\n            }\n        }\n        return ret;\n   \
    \ }\n\n    inline int vsize(){\n        return __CntVertex;\n    }\n\n    inline\
    \ int esize(){\n        return __CntEdge;\n    }\n\n    inline Edge<CostType>\
    \ get_edge(EdgeID edge_id, bool isReverse){\n        return (isReverse ? __RevEdgeSet[edge_id]\
    \ : __EdgeSet[edge_id]);\n    }\n\n    inline vector<Edge<CostType>>& get_edgeset(){\n\
    \        return __EdgeSet;\n    }\n\n    vector<Edge<CostType>> get_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        vector<Edge<CostType>>\
    \ ret;\n        for(auto [eid, rev] : __IncidentList[v]){\n            Edge<CostType>\
    \ e = __EdgeSet[eid];\n            if(rev) e = __RevEdgeSet[eid];\n          \
    \  ret.push_back(e);\n        }\n        return ret;\n    }\n\n    vector<pair<EdgeID,\
    \ bool>> get_raw_incident(Vertex v){\n        assert(0 <= v && v < __CntVertex);\n\
    \        return __IncidentList[v];\n    }\n\n    vector<pair<Vertex, EdgeID>>\
    \ convert_rootedtree(Vertex Root = 0){\n        assert(0 <= Root && Root < __CntVertex);\n\
    \        vector<pair<Vertex, EdgeID>> ret(__CntVertex, {-1, -1});\n        vector<int>\
    \ visited(__CntVertex, 0);\n        queue<Vertex> que;\n        que.push(Root);\n\
    \        while(que.size()){\n            Vertex now = que.front(); que.pop();\n\
    \            if(visited[now]) continue;\n            visited[now] = 1;\n     \
    \       for(int i = 0; i < __IncidentList[now].size(); ++i){\n               \
    \ auto [eid, rev] = __IncidentList[now][i];\n                Edge<CostType> e\
    \ = get_edge(eid, rev);\n                if(visited[e.to]) continue;\n       \
    \         que.push(e.to);\n                ret[e.to] = {now, eid};\n         \
    \       if(rev){\n                    __IncidentList[e.from][__EdgePlace[eid].second].second\
    \ = false;\n                    __IncidentList[e.to][__EdgePlace[eid].first].second\
    \ = true;\n                    __EdgeSet[eid].swap();\n                    __RevEdgeSet[eid].swap();\n\
    \                    swap(__EdgePlace[eid].first, __EdgePlace[eid].second);\n\
    \                }\n            }\n        }\n        return ret;\n    }\n\n \
    \   vector<Edge<CostType>> operator[](Vertex v){\n        return get_incident(v);\n\
    \    }\n\n    void print_edgeset(bool OneIndex = true){\n        for(int e = 0;\
    \ e < __CntEdge; ++e){\n            cout << e + OneIndex << \" : (\" << __EdgeSet[e].from\
    \ + OneIndex << (__isDirected ? \" -> \" : \" <-> \") << __EdgeSet[e].to + OneIndex\
    \ << \") = \" << __EdgeSet[e].cost << \" (\" << __EdgeSet[e].cap << \")\" << endl;\n\
    \        }\n    }\n\n    void print_incidentlist(bool OneIndex = true){\n    \
    \    for(int i = 0; i < __CntVertex; ++i){\n            cout << i + OneIndex <<\
    \ \" :\";\n            for(int j = 0; j < __IncidentList[i].size(); ++j){\n  \
    \              cout << \" (\" << __IncidentList[i][j].first << \" / \" << __IncidentList[i][j].second\
    \ << \")\";\n            }\n            cout << endl;\n        }\n    }\n\n  \
    \  void print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max() /\
    \ 2, bool DisplayINF = true){\n        auto mat = matrix(NotAdjacent);\n     \
    \   for(int i = 0; i < __CntVertex; ++i){\n            cout << (DisplayINF &&\
    \ mat[i][0] == NotAdjacent ? \"INF\" : to_string(mat[i][0]));\n            for(int\
    \ j = 1; j < __CntVertex; ++j){\n                cout << \" \" << (DisplayINF\
    \ && mat[i][j] == NotAdjacent ? \"INF\" : to_string(mat[i][j]));\n           \
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"latest/Graph/Dijkstra.hpp\"\
    \n\ntemplate<typename CostType>\nstruct Dijkstra{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<CostType> __Dist, __Potential;\n    vector<Vertex> __PrevVertex;\n\
    \    vector<pair<EdgeID, bool>> __PrevEdge;\n    Vertex __Start;\n\n    void __solve(){\n\
    \        __Dist.assign(G.vsize(), G.INF);\n        __PrevVertex.assign(G.vsize(),\
    \ -1);\n        __PrevEdge.assign(G.vsize(), {-1, false});\n        using p =\
    \ pair<CostType, Vertex>;\n        priority_queue<p, vector<p>, greater<p>> que;\n\
    \        que.emplace(__Potential[__Start], __Start);\n        __Dist[__Start]\
    \ = __Potential[__Start];\n        while(que.size()){\n            auto [d, v]\
    \ = que.top(); que.pop();\n            if(__Dist[v] < d) continue;\n         \
    \   for(auto [eid, rev] : G.get_raw_incident(v)){\n                Edge<CostType>\
    \ e = G.get_edge(eid, rev);\n                if(e.cap > 0 && d + e.cost + __Potential[e.from]\
    \ - __Potential[e.to] < __Dist[e.to]){\n                    __Dist[e.to] = d +\
    \ e.cost + __Potential[e.from] - __Potential[e.to];\n                    __PrevVertex[e.to]\
    \ = v;\n                    __PrevEdge[e.to] = {eid, rev};\n                 \
    \   que.emplace(__Dist[e.to], e.to);\n                }\n            }\n     \
    \   }\n        for(Vertex i = 0; i < G.vsize(); ++i){\n            if(__Dist[i]\
    \ != G.INF) __Dist[i] += __Potential[i] - __Potential[__Start];\n        }\n \
    \   }\n\n    public:\n    Dijkstra(Graph<CostType> &G) : G(G), __Dist(G.vsize()),\
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
    \  vector<pair<CostType, bool>> restore_edge(Vertex Goal){\n        vector<pair<CostType,\
    \ bool>> ret;\n        Vertex now = Goal;\n        while(__PrevEdge[now].first\
    \ != -1){\n            ret.push_back(__PrevEdge[now]);\n            auto [eid,\
    \ rev] = __PrevEdge[now];\n            now = G.get_edge(eid, rev).from;\n    \
    \    }\n        reverse(ret.begin(), ret.end());\n        return ret;\n    }\n\
    \n    void print(bool DisplayINF = true, char Delimiter = ' '){\n        cout\
    \ << (DisplayINF && __Dist[0] == G.INF ? \"INF\" : to_string(__Dist[0]));\n  \
    \      for(int i = 1; i < (int)__Dist.size(); ++i){\n            cout << Delimiter\
    \ << (DisplayINF && __Dist[i] == G.INF ? \"INF\" : to_string(__Dist[i]));\n  \
    \      }\n        cout << endl;\n    }\n};\n#line 10 \"latest/Graph/PrimalDual.hpp\"\
    \n\ntemplate<typename CostType>\nstruct PrimalDual{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<CostType> Potential;\n\n    public:\n    PrimalDual(Graph<CostType>\
    \ &G) : G(G), Potential(G.vsize()){}\n\n    CostType solve(Vertex Start, Vertex\
    \ Goal, CostType F){\n        CostType ret = 0;\n        Potential.assign(G.vsize(),\
    \ 0);\n\n        while(F > 0){\n            Dijkstra<CostType> dk(G);\n      \
    \      dk.update_potential(Potential);\n            vector<CostType> Dist = dk.all(Start);\n\
    \            if(Dist[Goal] == G.INF) return -1;\n            auto path = dk.restore_edge(Goal);\n\
    \            CostType f = F;\n            for(auto [eid, rev] : path){\n     \
    \           auto e = G.get_edge(eid, rev);\n                f = min(f, e.cap);\n\
    \            }\n            F -= f;\n            ret += f * Dist[Goal];\n    \
    \        for(auto [eid, rev] : path){\n                G.update_flow(eid, rev,\
    \ f);\n            }\n            for(int i = 0; i < Dist.size(); ++i){\n    \
    \            CostType RawDist = Dist[i] -= Potential[i] - Potential[Start];\n\
    \                Potential[i] = min(Potential[i] + RawDist, G.INF);\n        \
    \    }\n        }\n        return ret;\n    }\n};\n#line 4 \"verify_latest/AOJ-GRL-6-B.test.cpp\"\
    \n\nint main(){\n    int V, E, F;\n    cin >> V >> E >> F;\n    Graph<int> G(V,\
    \ true);\n    for(int i = 0; i < E; ++i){\n        Vertex u, v;\n        int c,\
    \ d;\n        cin >> u >> v >> c >> d;\n        G.add_flow(u, v, c, d);\n    }\n\
    \n    PrimalDual<int> pd(G);\n\n    cout << pd.solve(0, V - 1, F) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \n\n#include \"../latest/Graph/PrimalDual.hpp\"\n\nint main(){\n    int V, E,\
    \ F;\n    cin >> V >> E >> F;\n    Graph<int> G(V, true);\n    for(int i = 0;\
    \ i < E; ++i){\n        Vertex u, v;\n        int c, d;\n        cin >> u >> v\
    \ >> c >> d;\n        G.add_flow(u, v, c, d);\n    }\n\n    PrimalDual<int> pd(G);\n\
    \n    cout << pd.solve(0, V - 1, F) << endl;\n}"
  dependsOn:
  - latest/Graph/PrimalDual.hpp
  - latest/Graph/Dijkstra.hpp
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify_latest/AOJ-GRL-6-B.test.cpp
  requiredBy: []
  timestamp: '2023-09-02 20:49:48+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify_latest/AOJ-GRL-6-B.test.cpp
layout: document
redirect_from:
- /verify/verify_latest/AOJ-GRL-6-B.test.cpp
- /verify/verify_latest/AOJ-GRL-6-B.test.cpp.html
title: verify_latest/AOJ-GRL-6-B.test.cpp
---
