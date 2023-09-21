---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/BipartiteMatching.hpp
    title: latest/Graph/BipartiteMatching.hpp
  - icon: ':heavy_check_mark:'
    path: latest/Graph/FordFulkerson.hpp
    title: "Ford-Fulkerson - \u6700\u5927\u6D41"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A
  bundledCode: "#line 1 \"verify_latest/AOJ-GRL-7-A.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A\"\n\n#line 1\
    \ \"latest/Graph/FordFulkerson.hpp\"\n/**\n * @file FordFulkerson.hpp\n * @author\
    \ log K (lX57)\n * @brief Ford-Fulkerson - \u6700\u5927\u6D41\n * @version 2.0\n\
    \ * @date 2023-09-01\n */\n\n#line 2 \"latest/Graph/GraphTemplate.hpp\"\n\n/**\n\
    \ * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph Template\
    \ - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 2.1\n\
    \ * @date 2023-08-31\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    using Vertex = int;\nusing EdgeID = int;\n\ntemplate<typename CostType>\nstruct\
    \ Edge{\n    Vertex from, to;\n    CostType cost, cap;\n\n    Edge(Vertex from,\
    \ Vertex to, CostType cost) : from(from), to(to), cost(cost), cap(1){}\n    Edge(Vertex\
    \ from, Vertex to, CostType cap, CostType cost) : from(from), to(to), cost(cost),\
    \ cap(cap){}\n\n    Vertex getto(Vertex v){\n        assert(v == from || v ==\
    \ to);\n        return from ^ to ^ v;\n    }\n\n    void swap(){\n        Vertex\
    \ tmp = from;\n        from = to;\n        to = tmp;\n    }\n};\n\ntemplate<typename\
    \ CostType>\nstruct Graph{\n    private:\n    int __CntVertex, __CntEdge;\n  \
    \  bool __isDirected;\n    vector<Edge<CostType>> __EdgeSet, __RevEdgeSet;\n \
    \   vector<vector<pair<EdgeID, bool>>> __IncidentList;\n    vector<pair<int, int>>\
    \ __EdgePlace;\n\n    vector<CostType> __Flow;\n\n    public:\n    CostType INF;\n\
    \n    Graph(int VertexSize, bool isDirected = false) : __CntVertex(VertexSize),\
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
    \        __IncidentList[Sink].push_back({__CntEdge, true});\n        __Flow.push_back(0);\n\
    \        ++__CntEdge;\n    }\n\n    void update_flow(EdgeID edge_id, bool isReverse,\
    \ CostType Decrease){\n        if(isReverse) Decrease *= -1;\n        __EdgeSet[edge_id].cap\
    \ -= Decrease;\n        __RevEdgeSet[edge_id].cap += Decrease;\n        __Flow[edge_id]\
    \ += Decrease;\n    }\n\n    vector<Edge<CostType>> get_flow(){\n        vector<Edge<CostType>>\
    \ ret;\n        for(EdgeID i = 0; i < __CntEdge; ++i){\n            if(__Flow[i]\
    \ > 0){\n                ret.push_back(__EdgeSet[i]);\n            }\n       \
    \ }\n        return ret;\n    }\n\n    vector<vector<CostType>> matrix(CostType\
    \ NotAdjacent = numeric_limits<CostType>::max() / 2){\n        vector ret(__CntVertex,\
    \ vector(__CntVertex, NotAdjacent));\n        for(Vertex v = 0; v < __CntVertex;\
    \ ++v){\n            ret[v][v] = 0;\n            for(auto [eid, rev] : __IncidentList[v]){\n\
    \                if(!rev) ret[v][__EdgeSet[eid].to] = __EdgeSet[eid].cost;\n \
    \               else ret[v][__RevEdgeSet[eid].to] = __RevEdgeSet[eid].cost;\n\
    \            }\n        }\n        return ret;\n    }\n\n    inline int vsize(){\n\
    \        return __CntVertex;\n    }\n\n    inline int esize(){\n        return\
    \ __CntEdge;\n    }\n\n    inline Edge<CostType> get_edge(EdgeID edge_id, bool\
    \ isReverse){\n        return (isReverse ? __RevEdgeSet[edge_id] : __EdgeSet[edge_id]);\n\
    \    }\n\n    inline vector<Edge<CostType>>& get_edgeset(){\n        return __EdgeSet;\n\
    \    }\n\n    vector<Edge<CostType>> get_incident(Vertex v){\n        assert(0\
    \ <= v && v < __CntVertex);\n        vector<Edge<CostType>> ret;\n        for(auto\
    \ [eid, rev] : __IncidentList[v]){\n            Edge<CostType> e = __EdgeSet[eid];\n\
    \            if(rev) e = __RevEdgeSet[eid];\n            ret.push_back(e);\n \
    \       }\n        return ret;\n    }\n\n    vector<pair<EdgeID, bool>> get_raw_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        return __IncidentList[v];\n\
    \    }\n\n    vector<pair<Vertex, EdgeID>> convert_rootedtree(Vertex Root = 0){\n\
    \        assert(0 <= Root && Root < __CntVertex);\n        vector<pair<Vertex,\
    \ EdgeID>> ret(__CntVertex, {-1, -1});\n        vector<int> visited(__CntVertex,\
    \ 0);\n        queue<Vertex> que;\n        que.push(Root);\n        while(que.size()){\n\
    \            Vertex now = que.front(); que.pop();\n            if(visited[now])\
    \ continue;\n            visited[now] = 1;\n            for(int i = 0; i < __IncidentList[now].size();\
    \ ++i){\n                auto [eid, rev] = __IncidentList[now][i];\n         \
    \       Edge<CostType> e = get_edge(eid, rev);\n                if(visited[e.to])\
    \ continue;\n                que.push(e.to);\n                ret[e.to] = {now,\
    \ eid};\n                if(rev){\n                    __IncidentList[e.from][__EdgePlace[eid].second].second\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"latest/Graph/FordFulkerson.hpp\"\
    \n\ntemplate<typename CostType>\nstruct FordFulkerson{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<int> __used;\n\n    CostType __dfs(Vertex pos, Vertex goal,\
    \ CostType F){\n        if(pos == goal) return F;\n        __used[pos] = 1;\n\
    \        for(auto [eid, rev] : G.get_raw_incident(pos)){\n            auto e =\
    \ G.get_edge(eid, rev);\n            if(e.cap == 0 || __used[e.to]) continue;\n\
    \            CostType flow = __dfs(e.to, goal, min(F, e.cap));\n            if(flow\
    \ >= 1){\n                G.update_flow(eid, rev, flow);\n                return\
    \ flow;\n            }\n        }\n        return 0;\n    }\n\n    public:\n \
    \   FordFulkerson(Graph<CostType> &G) : G(G), __used(G.vsize(), 0){}\n\n    CostType\
    \ solve(Vertex Source, Vertex Sink){\n        CostType ans = 0;\n        while(1){\n\
    \            __used.assign(G.vsize(), 0);\n            CostType F = __dfs(Source,\
    \ Sink, G.INF);\n            if(F == 0) break;\n            ans += F;\n      \
    \  }\n        return ans;\n    }\n\n    vector<Edge<CostType>> get_flow(){\n \
    \       return G.get_flow();\n    }\n};\n#line 2 \"latest/Graph/BipartiteMatching.hpp\"\
    \n\nstruct BipartiteMatching{\n    private:\n    Graph<int> G, H;\n    int __L,\
    \ __R;\n    Vertex __S, __T;\n    vector<pair<Vertex, Vertex>> __Matching;\n\n\
    \    bool __SubGraph;\n    set<pair<Vertex, Vertex>> remain_edge;\n    vector<int>\
    \ mark_L, mark_R;\n    int ML, MR;\n\n    public:\n    BipartiteMatching(int L,\
    \ int R, int src_flow = 1, int sink_flow = 1, bool MakeSubGraph = false) : __L(L),\
    \ __R(R), __S(L + R), __T(L + R + 1), __SubGraph(MakeSubGraph){\n        G = Graph<int>(__L\
    \ + __R + 2, true);\n        for(Vertex l = 0; l < __L; ++l) G.add_flow(__S, l,\
    \ src_flow);\n        for(Vertex r = __L; r < __L + __R; ++r) G.add_flow(r, __T,\
    \ sink_flow);\n    }\n\n    void add_flow(int l, int r, int flow = 1){\n     \
    \   G.add_flow(l, __L + r, flow);\n        remain_edge.insert({l, __L + r});\n\
    \    }\n\n    int solve(bool MakeSubGraph = false){\n        FordFulkerson<int>\
    \ ff(G);\n        int ret = ff.solve(__S, __T);\n        for(auto e : ff.get_flow())\
    \ if(e.from != __S && e.to != __T) __Matching.push_back({e.from, e.to - __L});\n\
    \        if(MakeSubGraph){\n            H = Graph<int>(__L + __R, true);\n   \
    \         mark_L.resize(__L, 1), mark_R.resize(__R, 0);\n            for(auto\
    \ [l, r] : __Matching){\n                H.add(r, l);\n                remain_edge.erase({l,\
    \ r});\n                mark_L[l] = 0;\n            }\n            for(auto [l,\
    \ r] : remain_edge){\n                H.add(l, r);\n            }\n          \
    \  for(Vertex l = 0; l < __L; ++l){\n                if(!mark_L[l]) continue;\n\
    \                queue<Vertex> que;\n                que.push(l);\n          \
    \      while(que.size()){\n                    Vertex now = que.front();\n   \
    \                 que.pop();\n                    for(auto e : H.get_incident(now)){\n\
    \                        if(e.to < __L && !mark_L[e.to]){\n                  \
    \          mark_L[e.to] = 1;\n                            que.push(e.to);\n  \
    \                      }\n                        if(e.to >= __L && !mark_R[e.to\
    \ - __L]){\n                            mark_R[e.to - __L] = 1;\n            \
    \                que.push(e.to);\n                        }\n                \
    \    }\n                }\n            }\n            ML = accumulate(mark_L.begin(),\
    \ mark_L.end(), 0);\n            MR = accumulate(mark_R.begin(), mark_R.end(),\
    \ 0);\n        }\n        return ret;\n    }\n\n    vector<pair<Vertex, Vertex>>\
    \ get_matching(){\n        return __Matching;\n    }\n    \n    int MinimumVertexCover(){\n\
    \        return __L - ML + MR;\n    }\n\n    int MaximumIndependentSet(){\n  \
    \      return ML + __R - MR;\n    }\n};\n#line 4 \"verify_latest/AOJ-GRL-7-A.test.cpp\"\
    \n\nint main(){\n    int X, Y, E;\n    cin >> X >> Y >> E;\n    BipartiteMatching\
    \ bm(X, Y);\n    for(int i = 0; i < E; ++i){\n        int x, y; cin >> x >> y;\n\
    \        bm.add_flow(x, y);\n    }\n    cout << bm.solve() << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A\"\
    \n\n#include \"../latest/Graph/BipartiteMatching.hpp\"\n\nint main(){\n    int\
    \ X, Y, E;\n    cin >> X >> Y >> E;\n    BipartiteMatching bm(X, Y);\n    for(int\
    \ i = 0; i < E; ++i){\n        int x, y; cin >> x >> y;\n        bm.add_flow(x,\
    \ y);\n    }\n    cout << bm.solve() << endl;\n}"
  dependsOn:
  - latest/Graph/BipartiteMatching.hpp
  - latest/Graph/FordFulkerson.hpp
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify_latest/AOJ-GRL-7-A.test.cpp
  requiredBy: []
  timestamp: '2023-09-22 02:20:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_latest/AOJ-GRL-7-A.test.cpp
layout: document
redirect_from:
- /verify/verify_latest/AOJ-GRL-7-A.test.cpp
- /verify/verify_latest/AOJ-GRL-7-A.test.cpp.html
title: verify_latest/AOJ-GRL-7-A.test.cpp
---
