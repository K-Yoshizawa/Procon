---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: latest/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_A
  bundledCode: "#line 1 \"verify_latest/AOJ-ALDS1-11-A.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_A\"\n\n\
    #line 2 \"latest/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n\
    \ * @author log K (lX57)\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\n * @version 2.1\n * @date 2023-08-31\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\nusing EdgeID =\
    \ int;\nusing EdgeIndex = int;\n\ntemplate<typename CostType>\nstruct Edge{\n\
    \    Vertex from, to;\n    CostType cost, cap;\n    EdgeID ID;\n    EdgeIndex\
    \ fidx, tidx;\n\n    Edge() : ID(-1){}\n\n    Edge(Vertex from, Vertex to, CostType\
    \ cap, CostType cost, EdgeID ID, EdgeIndex fidx, EdgeIndex tidx) \n        : from(from),\
    \ to(to), cost(cost), cap(cap), ID(ID), fidx(fidx), tidx(tidx){}\n\n    Vertex\
    \ getto(Vertex v){\n        assert(v == from || v == to);\n        return from\
    \ ^ to ^ v;\n    }\n\n    void swap(){\n        Vertex tmp = from;\n        from\
    \ = to;\n        to = tmp;\n    }\n\n    void print(){\n        cerr << \"Edge\
    \ \" << ID << \" : (\" << from << \" -> \" << to << \"), Cost = \" << cost <<\
    \ \", Capacity = \" << cap << \", Place = [\" << fidx << \", \" << tidx << \"\
    ]\" << endl;\n    }\n};\n\ntemplate<typename CostType>\nstruct Graph{\n    private:\n\
    \    int __CntVertex, __CntEdge;\n    bool __isDirected;\n    vector<Edge<CostType>>\
    \ __EdgeSet, __RevEdgeSet;\n    vector<vector<Edge<CostType>>> __IncidentList;\n\
    \    vector<pair<int, int>> __EdgePlace;\n\n    vector<CostType> __Flow;\n\n \
    \   public:\n    CostType INF;\n\n    Graph(int VertexSize, bool isDirected =\
    \ false) : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0), __IncidentList(VertexSize),\
    \ INF(numeric_limits<CostType>::max() / 2){}\n\n    Graph() = default;\n\n   \
    \ void add(Vertex s, Vertex t, CostType w = 1){\n        assert(0 <= s && s <\
    \ __CntVertex);\n        assert(0 <= t && t < __CntVertex);\n        EdgeIndex\
    \ sidx = __IncidentList[s].size(), tidx = __IncidentList[t].size();\n        Edge<CostType>\
    \ es(s, t, 1, w, __CntEdge, sidx, tidx);\n        Edge<CostType> et(t, s, 1, w,\
    \ __CntEdge, tidx, sidx);\n        __EdgeSet.push_back(es);\n        __IncidentList[s].push_back(es);\n\
    \        __RevEdgeSet.push_back(et);\n        if(!__isDirected) __IncidentList[t].push_back(et);\n\
    \        ++__CntEdge;\n    }\n\n    void add_flow(Vertex Source, Vertex Sink,\
    \ CostType Capacity, CostType Cost = 1){\n        assert(0 <= Source && Source\
    \ < __CntVertex);\n        assert(0 <= Sink && Sink < __CntVertex);\n        EdgeIndex\
    \ sidx = __IncidentList[Source].size(), tidx = __IncidentList[Sink].size();\n\
    \        Edge<CostType> es(Source, Sink, Cost, Capacity, __CntEdge, sidx, tidx);\n\
    \        Edge<CostType> et(Sink, Source, -Cost, 0, __CntEdge, tidx, sidx);\n \
    \       __EdgeSet.push_back(es);\n        __IncidentList[Source].push_back(es);\n\
    \        __RevEdgeSet.push_back(et);\n        __IncidentList[Sink].push_back(et);\n\
    \        __Flow.push_back(0);\n        ++__CntEdge;\n    }\n\n    void update_flow(Vertex\
    \ Source, EdgeID edge_id, CostType Decrease){\n        if(__EdgeSet[edge_id].from\
    \ != Source) Decrease *= -1;\n        __EdgeSet[edge_id].cap -= Decrease;\n  \
    \      __RevEdgeSet[edge_id].cap += Decrease;\n        __Flow[edge_id] += Decrease;\n\
    \    }\n\n    vector<Edge<CostType>> get_flow(){\n        vector<Edge<CostType>>\
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
    \ __CntEdge;\n    }\n\n    inline int incsize(Vertex v){\n        return __IncidentList[v].size();\n\
    \    }\n\n    inline Edge<CostType> get_edge(EdgeID edge_id, bool isReverse){\n\
    \        return (isReverse ? __RevEdgeSet[edge_id] : __EdgeSet[edge_id]);\n  \
    \  }\n\n    inline vector<Edge<CostType>>& get_edgeset(){\n        return __EdgeSet;\n\
    \    }\n\n    vector<Edge<CostType>> get_incident(Vertex v){\n        assert(0\
    \ <= v && v < __CntVertex);\n        return __IncidentList[v];\n    }\n\n    EdgeIndex\
    \ get_place(EdgeID ID, Vertex From){\n        if(__EdgeSet[ID].from == From) return\
    \ __EdgePlace[ID].first;\n        else return __EdgePlace[ID].second;\n    }\n\
    \n    vector<pair<Vertex, EdgeID>> convert_rootedtree(Vertex Root = 0){\n    \
    \    assert(0 <= Root && Root < __CntVertex);\n        vector<pair<Vertex, EdgeID>>\
    \ ret(__CntVertex, {-1, -1});\n        vector<int> visited(__CntVertex, 0);\n\
    \        queue<Vertex> que;\n        que.push(Root);\n        while(que.size()){\n\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 4 \"verify_latest/AOJ-ALDS1-11-A.test.cpp\"\
    \n\n#line 6 \"verify_latest/AOJ-ALDS1-11-A.test.cpp\"\nusing namespace std;\n\n\
    int main(){\n    int n; cin >> n;\n    Graph<int> G(n, true);\n    for(int i =\
    \ 0; i < n; ++i){\n        Vertex u; int k; cin >> u >> k, --u;\n        for(int\
    \ j = 0; j < k; ++j){\n            Vertex v; cin >> v, --v;\n            G.add(u,\
    \ v);\n        }\n    }\n    G.print_matrix(0, false);\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_A\"\
    \n\n#include \"../latest/Graph/GraphTemplate.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main(){\n    int n; cin >> n;\n    Graph<int> G(n,\
    \ true);\n    for(int i = 0; i < n; ++i){\n        Vertex u; int k; cin >> u >>\
    \ k, --u;\n        for(int j = 0; j < k; ++j){\n            Vertex v; cin >> v,\
    \ --v;\n            G.add(u, v);\n        }\n    }\n    G.print_matrix(0, false);\n\
    }"
  dependsOn:
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify_latest/AOJ-ALDS1-11-A.test.cpp
  requiredBy: []
  timestamp: '2023-09-30 17:57:32+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify_latest/AOJ-ALDS1-11-A.test.cpp
layout: document
redirect_from:
- /verify/verify_latest/AOJ-ALDS1-11-A.test.cpp
- /verify/verify_latest/AOJ-ALDS1-11-A.test.cpp.html
title: verify_latest/AOJ-ALDS1-11-A.test.cpp
---
