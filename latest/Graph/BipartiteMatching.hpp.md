---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/FlowTemplate.hpp
    title: "Flow Template - \u30D5\u30ED\u30FC\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/FordFulkerson.hpp
    title: "Ford-Fulkerson - \u6700\u5927\u6D41"
  - icon: ':heavy_check_mark:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify_latest/pending/LC-BipartiteMatching.cpp
    title: verify_latest/pending/LC-BipartiteMatching.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_latest/AOJ-GRL-7-A.test.cpp
    title: verify_latest/AOJ-GRL-7-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"latest/Graph/FordFulkerson.hpp\"\n/**\n * @file FordFulkerson.hpp\n\
    \ * @author log K (lX57)\n * @brief Ford-Fulkerson - \u6700\u5927\u6D41\n * @version\
    \ 2.0\n * @date 2023-09-01\n */\n\n#line 2 \"latest/Graph/FlowTemplate.hpp\"\n\
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
    \         }\n        }\n        return ret;\n    }\n};\n#line 10 \"latest/Graph/FordFulkerson.hpp\"\
    \n\ntemplate<typename CostType>\nstruct FordFulkerson{\n    private:\n    Flow<CostType>\
    \ &G;\n    vector<int> __used;\n\n    CostType __dfs(Vertex pos, Vertex goal,\
    \ CostType F){\n        if(pos == goal) return F;\n        __used[pos] = 1;\n\
    \        for(auto e : G.get_incident(pos)){\n            if(e.cap == 0 || __used[e.to])\
    \ continue;\n            // cerr << \"[\" << e.src << \", \" << e.to << \"] (\"\
    \ << e.cap << \")\\n\";\n            CostType flow = __dfs(e.to, goal, min(F,\
    \ e.cap));\n            if(flow >= 1){\n                // cerr << \"Update [\"\
    \ << e.src << \", \" << e.to << \"] Flow = \" << flow << endl;\n             \
    \   G.update(e.src, e.sidx, flow);\n                return flow;\n           \
    \ }\n        }\n        return 0;\n    }\n\n    public:\n    FordFulkerson(Flow<CostType>\
    \ &G) : G(G), __used(G.vsize(), 0){}\n\n    CostType solve(Vertex Source, Vertex\
    \ Sink){\n        CostType ans = 0;\n        while(1){\n            __used.assign(G.vsize(),\
    \ 0);\n            CostType F = __dfs(Source, Sink, G.INF);\n            if(F\
    \ == 0) break;\n            ans += F;\n        }\n        return ans;\n    }\n\
    \n    vector<Edge<CostType>> get(){\n        return G.get();\n    }\n};\n#line\
    \ 2 \"latest/Graph/BipartiteMatching.hpp\"\n\nstruct BipartiteMatching{\n    private:\n\
    \    Flow<int> G, H;\n    int __L, __R;\n    Vertex __S, __T;\n    vector<pair<Vertex,\
    \ Vertex>> __Matching;\n\n    bool __SubGraph;\n    set<pair<Vertex, Vertex>>\
    \ remain_edge;\n    vector<int> mark_L, mark_R;\n    int ML, MR;\n\n    public:\n\
    \    BipartiteMatching(int L, int R, int src_flow = 1, int sink_flow = 1, bool\
    \ MakeSubGraph = false) : __L(L), __R(R), __S(L + R), __T(L + R + 1), __SubGraph(MakeSubGraph){\n\
    \        G = Flow<int>(__L + __R + 2);\n        for(Vertex l = 0; l < __L; ++l)\
    \ G.add(__S, l, src_flow);\n        for(Vertex r = __L; r < __L + __R; ++r) G.add(r,\
    \ __T, sink_flow);\n    }\n\n    void add(int l, int r, int flow = 1){\n     \
    \   G.add(l, __L + r, flow);\n        remain_edge.insert({l, __L + r});\n    }\n\
    \n    int solve(bool MakeSubGraph = false){\n        FordFulkerson<int> ff(G);\n\
    \        int ret = ff.solve(__S, __T);\n        for(auto e : ff.get()) if(e.src\
    \ != __S && e.to != __T) __Matching.push_back({e.src, e.to - __L});\n        if(MakeSubGraph){\n\
    \            H = Flow<int>(__L + __R);\n            mark_L.resize(__L, 1), mark_R.resize(__R,\
    \ 0);\n            for(auto [l, r] : __Matching){\n                H.add(r, l);\n\
    \                remain_edge.erase({l, r});\n                mark_L[l] = 0;\n\
    \            }\n            for(auto [l, r] : remain_edge){\n                H.add(l,\
    \ r);\n            }\n            for(Vertex l = 0; l < __L; ++l){\n         \
    \       if(!mark_L[l]) continue;\n                queue<Vertex> que;\n       \
    \         que.push(l);\n                while(que.size()){\n                 \
    \   Vertex now = que.front();\n                    que.pop();\n              \
    \      for(auto e : H.get_incident(now)){\n                        if(e.to < __L\
    \ && !mark_L[e.to]){\n                            mark_L[e.to] = 1;\n        \
    \                    que.push(e.to);\n                        }\n            \
    \            if(e.to >= __L && !mark_R[e.to - __L]){\n                       \
    \     mark_R[e.to - __L] = 1;\n                            que.push(e.to);\n \
    \                       }\n                    }\n                }\n        \
    \    }\n            ML = accumulate(mark_L.begin(), mark_L.end(), 0);\n      \
    \      MR = accumulate(mark_R.begin(), mark_R.end(), 0);\n        }\n        return\
    \ ret;\n    }\n\n    vector<pair<Vertex, Vertex>> get_matching(){\n        return\
    \ __Matching;\n    }\n    \n    int MinimumVertexCover(){\n        return __L\
    \ - ML + MR;\n    }\n\n    int MaximumIndependentSet(){\n        return ML + __R\
    \ - MR;\n    }\n};\n"
  code: "#include \"FordFulkerson.hpp\"\n\nstruct BipartiteMatching{\n    private:\n\
    \    Flow<int> G, H;\n    int __L, __R;\n    Vertex __S, __T;\n    vector<pair<Vertex,\
    \ Vertex>> __Matching;\n\n    bool __SubGraph;\n    set<pair<Vertex, Vertex>>\
    \ remain_edge;\n    vector<int> mark_L, mark_R;\n    int ML, MR;\n\n    public:\n\
    \    BipartiteMatching(int L, int R, int src_flow = 1, int sink_flow = 1, bool\
    \ MakeSubGraph = false) : __L(L), __R(R), __S(L + R), __T(L + R + 1), __SubGraph(MakeSubGraph){\n\
    \        G = Flow<int>(__L + __R + 2);\n        for(Vertex l = 0; l < __L; ++l)\
    \ G.add(__S, l, src_flow);\n        for(Vertex r = __L; r < __L + __R; ++r) G.add(r,\
    \ __T, sink_flow);\n    }\n\n    void add(int l, int r, int flow = 1){\n     \
    \   G.add(l, __L + r, flow);\n        remain_edge.insert({l, __L + r});\n    }\n\
    \n    int solve(bool MakeSubGraph = false){\n        FordFulkerson<int> ff(G);\n\
    \        int ret = ff.solve(__S, __T);\n        for(auto e : ff.get()) if(e.src\
    \ != __S && e.to != __T) __Matching.push_back({e.src, e.to - __L});\n        if(MakeSubGraph){\n\
    \            H = Flow<int>(__L + __R);\n            mark_L.resize(__L, 1), mark_R.resize(__R,\
    \ 0);\n            for(auto [l, r] : __Matching){\n                H.add(r, l);\n\
    \                remain_edge.erase({l, r});\n                mark_L[l] = 0;\n\
    \            }\n            for(auto [l, r] : remain_edge){\n                H.add(l,\
    \ r);\n            }\n            for(Vertex l = 0; l < __L; ++l){\n         \
    \       if(!mark_L[l]) continue;\n                queue<Vertex> que;\n       \
    \         que.push(l);\n                while(que.size()){\n                 \
    \   Vertex now = que.front();\n                    que.pop();\n              \
    \      for(auto e : H.get_incident(now)){\n                        if(e.to < __L\
    \ && !mark_L[e.to]){\n                            mark_L[e.to] = 1;\n        \
    \                    que.push(e.to);\n                        }\n            \
    \            if(e.to >= __L && !mark_R[e.to - __L]){\n                       \
    \     mark_R[e.to - __L] = 1;\n                            que.push(e.to);\n \
    \                       }\n                    }\n                }\n        \
    \    }\n            ML = accumulate(mark_L.begin(), mark_L.end(), 0);\n      \
    \      MR = accumulate(mark_R.begin(), mark_R.end(), 0);\n        }\n        return\
    \ ret;\n    }\n\n    vector<pair<Vertex, Vertex>> get_matching(){\n        return\
    \ __Matching;\n    }\n    \n    int MinimumVertexCover(){\n        return __L\
    \ - ML + MR;\n    }\n\n    int MaximumIndependentSet(){\n        return ML + __R\
    \ - MR;\n    }\n};"
  dependsOn:
  - latest/Graph/FordFulkerson.hpp
  - latest/Graph/FlowTemplate.hpp
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: latest/Graph/BipartiteMatching.hpp
  requiredBy:
  - verify_latest/pending/LC-BipartiteMatching.cpp
  timestamp: '2023-09-30 19:29:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_latest/AOJ-GRL-7-A.test.cpp
documentation_of: latest/Graph/BipartiteMatching.hpp
layout: document
redirect_from:
- /library/latest/Graph/BipartiteMatching.hpp
- /library/latest/Graph/BipartiteMatching.hpp.html
title: latest/Graph/BipartiteMatching.hpp
---
