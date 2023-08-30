---
data:
  _extendedDependsOn:
  - icon: ':x:'
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
    \u30D7\u30EC\u30FC\u30C8\n * @version 2.0\n * @date 2023-08-31\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\nusing EdgeID =\
    \ int;\n\ntemplate<typename CostType>\nstruct Edge{\n    Vertex from, to;\n  \
    \  CostType cost;\n\n    Edge(Vertex from, Vertex to, CostType cost) : from(from),\
    \ to(to), cost(cost){}\n\n    Vertex getto(Vertex v){\n        assert(v == from\
    \ || v == to);\n        return from ^ to ^ v;\n    }\n};\n\ntemplate<typename\
    \ CostType>\nstruct Graph{\n    private:\n    int __CntVertex, __CntEdge;\n  \
    \  bool __isDirected;\n    vector<Edge<CostType>> __EdgeSet, __RevEdgeSet;\n \
    \   vector<vector<EdgeID>> __IncidentList;\n\n    public:\n    CostType INF;\n\
    \n    Graph(int VertexSize, bool isDirected = false) : __CntVertex(VertexSize),\
    \ __isDirected(isDirected), __CntEdge(0), __IncidentList(VertexSize), INF(numeric_limits<CostType>::max()\
    \ / 2){}\n\n    Graph() = default;\n\n    void add(Vertex s, Vertex t, CostType\
    \ w = 1){\n        assert(0 <= s && s < __CntVertex);\n        assert(0 <= t &&\
    \ t < __CntVertex);\n        __EdgeSet.push_back(Edge<CostType>(s, t, w));\n \
    \       __IncidentList[s].push_back(__CntEdge);\n        __RevEdgeSet.push_back(Edge<CostType>(t,\
    \ s, w));\n        if(!__isDirected) __IncidentList[t].push_back(__CntEdge);\n\
    \        ++__CntEdge;\n    }\n\n    vector<vector<CostType>> matrix(CostType NotAdjacent\
    \ = numeric_limits<CostType>::max() / 2){\n        vector ret(__CntVertex, vector(__CntVertex,\
    \ NotAdjacent));\n        for(Vertex v = 0; v < __CntVertex; ++v){\n         \
    \   for(EdgeID &eid : __IncidentList[v]){\n                ret[v][__EdgeSet[eid].getto(v)]\
    \ = __EdgeSet[eid].cost;\n            }\n        }\n        return ret;\n    }\n\
    \n    void print_edgeset(bool OneIndex = true){\n        for(int e = 0; e < __CntEdge;\
    \ ++e){\n            cout << e + OneIndex << \" : (\" << __EdgeSet[e].from + OneIndex\
    \ << (__isDirected ? \" -> \" : \" <-> \") << __EdgeSet[e].to + OneIndex << \"\
    ) = \" << __EdgeSet[e].cost << endl;\n        }\n    }\n\n    void print_matrix(CostType\
    \ NotAdjacent = numeric_limits<CostType>::max() / 2, bool DisplayINF = true){\n\
    \        auto mat = matrix(NotAdjacent);\n        for(int i = 0; i < __CntVertex;\
    \ ++i){\n            cout << (DisplayINF && mat[i][j] == NotAdjacent ? \"INF\"\
    \ : to_string(mat[i][0]));\n            for(int j = 1; j < __CntVertex; ++j){\n\
    \                cout << \" \" << (DisplayINF && mat[i][j] == NotAdjacent ? \"\
    INF\" : to_string(mat[i][j]));\n            }\n            cout << endl;\n   \
    \     }\n    }\n};\n#line 4 \"verify_latest/AOJ-ALDS1-11-A.test.cpp\"\n\n#line\
    \ 6 \"verify_latest/AOJ-ALDS1-11-A.test.cpp\"\nusing namespace std;\n\nint main(){\n\
    \    int n; cin >> n;\n    Graph<int> G(n, true);\n    for(int i = 0; i < n; ++i){\n\
    \        Vertex u; int k; cin >> u >> k, --u;\n        for(int j = 0; j < k; ++j){\n\
    \            Vertex v; cin >> v, --v;\n            G.add(u, v);\n        }\n \
    \   }\n    G.print_matrix(0, false);\n}\n"
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
  timestamp: '2023-08-31 01:23:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify_latest/AOJ-ALDS1-11-A.test.cpp
layout: document
redirect_from:
- /verify/verify_latest/AOJ-ALDS1-11-A.test.cpp
- /verify/verify_latest/AOJ-ALDS1-11-A.test.cpp.html
title: verify_latest/AOJ-ALDS1-11-A.test.cpp
---
