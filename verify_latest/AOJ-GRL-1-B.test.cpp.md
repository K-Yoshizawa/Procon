---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/Graph/BellmanFord.hpp
    title: "BellmanFord - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"verify_latest/AOJ-GRL-1-B.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 1 \"latest/Graph/BellmanFord.hpp\"\n/**\n * @file BellmanFord.hpp\n\
    \ * @author log_K (lX57)\n * @brief BellmanFord - \u5358\u4E00\u59CB\u70B9\u6700\
    \u77ED\u8DDD\u96E2\n * @version 2.0\n * @date 2023-08-31\n */\n\n#line 2 \"latest/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 2.0\n * @date 2023-08-31\n */\n\n#line 12 \"latest/Graph/GraphTemplate.hpp\"\
    \nusing namespace std;\n\nusing Vertex = int;\nusing EdgeID = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    Vertex from, to;\n    CostType cost;\n\n    Edge(Vertex\
    \ from, Vertex to, CostType cost) : from(from), to(to), cost(cost){}\n\n    Vertex\
    \ getto(Vertex v){\n        assert(v == from || v == to);\n        return from\
    \ ^ to ^ v;\n    }\n};\n\ntemplate<typename CostType>\nstruct Graph{\n    private:\n\
    \    int __CntVertex, __CntEdge;\n    bool __isDirected;\n    vector<Edge<CostType>>\
    \ __EdgeSet, __RevEdgeSet;\n    vector<vector<EdgeID>> __IncidentList;\n\n   \
    \ public:\n    CostType INF;\n\n    Graph(int VertexSize, bool isDirected = false)\
    \ : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0), __IncidentList(VertexSize),\
    \ INF(numeric_limits<CostType>::max() / 2){}\n\n    Graph() = default;\n\n   \
    \ void add(Vertex s, Vertex t, CostType w = 1){\n        assert(0 <= s && s <\
    \ __CntVertex);\n        assert(0 <= t && t < __CntVertex);\n        __EdgeSet.push_back(Edge<CostType>(s,\
    \ t, w));\n        __IncidentList[s].push_back(__CntEdge);\n        __RevEdgeSet.push_back(Edge<CostType>(t,\
    \ s, w));\n        if(!__isDirected) __IncidentList[t].push_back(__CntEdge);\n\
    \        ++__CntEdge;\n    }\n\n    vector<vector<CostType>> matrix(CostType NotAdjacent\
    \ = numeric_limits<CostType>::max() / 2){\n        vector ret(__CntVertex, vector(__CntVertex,\
    \ NotAdjacent));\n        for(Vertex v = 0; v < __CntVertex; ++v){\n         \
    \   ret[v][v] = 0;\n            for(EdgeID &eid : __IncidentList[v]){\n      \
    \          ret[v][__EdgeSet[eid].getto(v)] = __EdgeSet[eid].cost;\n          \
    \  }\n        }\n        return ret;\n    }\n\n    inline int vsize(){\n     \
    \   return __CntVertex;\n    }\n\n    inline int esize(){\n        return __CntEdge;\n\
    \    }\n\n    inline vector<Edge<CostType>>& get_edgeset(){\n        return __EdgeSet;\n\
    \    }\n\n    vector<Edge<CostType>> get_incident(Vertex v){\n        assert(0\
    \ <= v && v < __CntVertex);\n        vector<Edge<CostType>> ret;\n        for(auto\
    \ &eid : __IncidentList[v]){\n            Edge<CostType> e = __EdgeSet[eid];\n\
    \            if(e.to == v) swap(e.from, e.to);\n            ret.push_back(e);\n\
    \        }\n        return ret;\n    }\n\n    void print_edgeset(bool OneIndex\
    \ = true){\n        for(int e = 0; e < __CntEdge; ++e){\n            cout << e\
    \ + OneIndex << \" : (\" << __EdgeSet[e].from + OneIndex << (__isDirected ? \"\
    \ -> \" : \" <-> \") << __EdgeSet[e].to + OneIndex << \") = \" << __EdgeSet[e].cost\
    \ << endl;\n        }\n    }\n\n    void print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max()\
    \ / 2, bool DisplayINF = true){\n        auto mat = matrix(NotAdjacent);\n   \
    \     for(int i = 0; i < __CntVertex; ++i){\n            cout << (DisplayINF &&\
    \ mat[i][0] == NotAdjacent ? \"INF\" : to_string(mat[i][0]));\n            for(int\
    \ j = 1; j < __CntVertex; ++j){\n                cout << \" \" << (DisplayINF\
    \ && mat[i][j] == NotAdjacent ? \"INF\" : to_string(mat[i][j]));\n           \
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"latest/Graph/BellmanFord.hpp\"\
    \n\ntemplate<typename CostType>\nvector<CostType> BellmanFord(Graph<CostType>\
    \ &G, Vertex Start){\n    vector<CostType> ret(G.vsize(), G.INF);\n    ret[Start]\
    \ = 0;\n    int updatecount = 0;\n    while(1){\n        if(updatecount == G.vsize()){\n\
    \            return vector<CostType>{};\n        }\n        bool update = false;\n\
    \        for(Edge<CostType> &e : G.get_edgeset()){\n            if(ret[e.from]\
    \ == G.INF) continue;\n            if(ret[e.to] > ret[e.from] + e.cost){\n   \
    \             ret[e.to] = ret[e.from] + e.cost;\n                update = true;\n\
    \            }\n        }\n        if(!update) break;\n        ++updatecount;\n\
    \    }\n    return ret;\n}\n#line 6 \"verify_latest/AOJ-GRL-1-B.test.cpp\"\n\n\
    using namespace std;\n\nint main(){\n    int V, E, r;\n    cin >> V >> E >> r;\n\
    \    Graph<int> G(V, true);\n    for(int i = 0; i < E; ++i){\n        int s, t,\
    \ d;\n        cin >> s >> t >> d;\n        G.add(s, t, d);\n    }\n\n    auto\
    \ ans = BellmanFord(G, r);\n    if(ans.empty()){\n        cout << \"NEGATIVE CYCLE\"\
    \ << endl;\n    }\n    else{\n        for(auto &d : ans){\n            if(d ==\
    \ G.INF){\n                cout << \"INF\" <<endl;\n            }\n          \
    \  else{\n                cout << d << endl;\n            }\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../latest/Graph/BellmanFord.hpp\"\n\
    \nusing namespace std;\n\nint main(){\n    int V, E, r;\n    cin >> V >> E >>\
    \ r;\n    Graph<int> G(V, true);\n    for(int i = 0; i < E; ++i){\n        int\
    \ s, t, d;\n        cin >> s >> t >> d;\n        G.add(s, t, d);\n    }\n\n  \
    \  auto ans = BellmanFord(G, r);\n    if(ans.empty()){\n        cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n    }\n    else{\n        for(auto &d : ans){\n          \
    \  if(d == G.INF){\n                cout << \"INF\" <<endl;\n            }\n \
    \           else{\n                cout << d << endl;\n            }\n       \
    \ }\n    }\n}"
  dependsOn:
  - latest/Graph/BellmanFord.hpp
  - latest/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify_latest/AOJ-GRL-1-B.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 15:07:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_latest/AOJ-GRL-1-B.test.cpp
layout: document
redirect_from:
- /verify/verify_latest/AOJ-GRL-1-B.test.cpp
- /verify/verify_latest/AOJ-GRL-1-B.test.cpp.html
title: verify_latest/AOJ-GRL-1-B.test.cpp
---
