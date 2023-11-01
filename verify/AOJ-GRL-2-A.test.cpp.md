---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/UnionFind.hpp
    title: "UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/Graph/Kruskal.hpp
    title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"verify/AOJ-GRL-2-A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#line 1 \"library/Graph/Kruskal.hpp\"\n/**\n * @file Kruskal.hpp\n * @author\
    \ log K (lX57)\n * @brief Kruskal - \u6700\u5C0F\u5168\u57DF\u6728\n * @version\
    \ 2.0\n * @date 2023-11-01\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
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
    \   return __IL[v].size();\n    }\n\n    inline EdgeSet<CostType> &get_edgeset(){\n\
    \        return __ES;\n    }\n\n    inline IncidentList<CostType> &get_incidentlist(){\n\
    \        return __IL;\n    }\n\n    inline vector<Edge<CostType>> &get_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        return __IL[v];\n \
    \   }\n\n    inline AdjacentList &get_adjacentlist(){\n        return __AL;\n\
    \    }\n\n    inline vector<Vertex> &get_adjacent(Vertex v){\n        assert(0\
    \ <= v && v < __CntVertex);\n        return __AL[v];\n    }\n\n    vector<Edge<CostType>>\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 2 \"library/DataStructure/UnionFind.hpp\"\
    \n\n/**\n * @brief UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\
    \n */\n\n#line 8 \"library/DataStructure/UnionFind.hpp\"\nusing namespace std;\n\
    \n/**\n * @brief Union-Find\n */\nstruct UnionFind{\n    vector<int> data;\n \n\
    \    UnionFind(size_t sz) : data(sz, -1) {}\n \n    /**\n     * @brief \u8981\u7D20\
    x\u3068\u8981\u7D20y\u3092\u4F75\u5408\u3059\u308B\n     * @param x \u4F75\u5408\
    \u3059\u308B\u8981\u7D20x\n     * @param y \u4F75\u5408\u3059\u308B\u8981\u7D20\
    y\n     * @return true \u8981\u7D20x\u3068\u8981\u7D20y\u304C\u307E\u3060\u672A\
    \u4F75\u5408\u3060\u3063\u305F\u5834\u5408\n     * @return false \u8981\u7D20\
    x\u3068\u8981\u7D20y\u304C\u4F75\u5408\u6E08\u3060\u3063\u305F\u5834\u5408\n \
    \    */\n    bool unite(int x, int y){\n        x = find(x), y = find(y);\n  \
    \      if(x == y) return false;\n        if(data[x] > data[y]) swap(x, y);\n \
    \       data[x] += data[y];\n        data[y] = x;\n        return true;\n    }\n\
    \ \n    /**\n     * @brief \u8981\u7D20k\u304C\u542B\u307E\u308C\u308B\u96C6\u5408\
    \u306E\u8981\u7D20\u3092\u8ABF\u3079\u308B\u3002\n     * @param k \u8ABF\u3079\
    \u305F\u3044\u8981\u7D20k\n     * @return int \u542B\u307E\u308C\u308B\u96C6\u5408\
    \u306E\u89AA\n     */\n    int find(int k){\n        if(data[k] < 0) return (k);\n\
    \        return data[k] = find(data[k]);\n    }\n \n    /**\n     * @brief \u8981\
    \u7D20k\u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\
    \u6C42\u3081\u308B\u3002\n     * @param k \u8ABF\u3079\u305F\u3044\u8981\u7D20\
    k\n     * @return int \u96C6\u5408\u306E\u8981\u7D20\u6570\n     */\n    int size(int\
    \ k){\n        return -data[find(k)];\n    }\n \n    /**\n     * @brief \u8981\
    \u7D20x\u3001\u8981\u7D20y\u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\
    \u304B\u5224\u5B9A\u3059\u308B\u3002\n     * @param x \u5224\u5B9A\u3059\u308B\
    \u8981\u7D20x\n     * @param y \u5224\u5B9A\u3059\u308B\u8981\u7D20y\n     * @return\
    \ true \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\u5834\u5408\
    \n     * @return false \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u306A\
    \u3044\u5834\u5408\n     */\n    bool same(int x, int y){\n        return find(x)\
    \ == find(y);\n    }\n\n    /**\n     * @brief  \u3059\u3079\u3066\u306E\u9023\
    \u7D50\u6210\u5206\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @retval vector<vector<int>>\
    \ \n     */\n    vector<vector<int>> groups() {\n        int n = (int) data.size();\n\
    \        vector<vector<int>> ret(n);\n        for(int i = 0; i < n; i++) {\n \
    \           ret[find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](const vector< int > &v) {\n            return v.empty();\n   \
    \     }), end(ret));\n        return ret;\n    }\n};\n#line 11 \"library/Graph/Kruskal.hpp\"\
    \n\ntemplate<typename CostType>\nstruct Kruskal{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<EdgeID> __RemainEdge;\n    CostType __Cost;\n\n    public:\n\
    \    Kruskal(Graph<CostType> &G) : G(G), __Cost(0){\n        UnionFind uf(G.vsize());\n\
    \        auto es = G.get_edgeset();\n        vector<EdgeID> eid(G.esize());\n\
    \        iota(eid.begin(), eid.end(), 0);\n        sort(eid.begin(), eid.end(),\
    \ [&](EdgeID l, EdgeID r){return es[l].cost < es[r].cost;});\n        for(EdgeID\
    \ i : eid){\n            if(uf.same(es[i].src, es[i].to)) continue;\n        \
    \    uf.unite(es[i].src, es[i].to);\n            __RemainEdge.push_back(i);\n\
    \            __Cost += es[i].cost;\n        }\n    }\n\n    CostType get(){\n\
    \        return __Cost;\n    }\n};\n#line 4 \"verify/AOJ-GRL-2-A.test.cpp\"\n\n\
    int main(){\n    int V, E; cin >> V >> E;\n    Graph<int> G(V);\n    for(int i\
    \ = 0; i < E; ++i){\n        int s, t, w; cin >> s >> t >> w;\n        G.add(s,\
    \ t, w);\n    }\n\n    Kruskal<int> kr(G);\n    cout << kr.get() << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#include \"../library/Graph/Kruskal.hpp\"\n\nint main(){\n    int V, E; cin\
    \ >> V >> E;\n    Graph<int> G(V);\n    for(int i = 0; i < E; ++i){\n        int\
    \ s, t, w; cin >> s >> t >> w;\n        G.add(s, t, w);\n    }\n\n    Kruskal<int>\
    \ kr(G);\n    cout << kr.get() << endl;\n}"
  dependsOn:
  - library/Graph/Kruskal.hpp
  - library/Graph/GraphTemplate.hpp
  - library/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-2-A.test.cpp
  requiredBy: []
  timestamp: '2023-11-02 01:25:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-GRL-2-A.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-2-A.test.cpp
- /verify/verify/AOJ-GRL-2-A.test.cpp.html
title: verify/AOJ-GRL-2-A.test.cpp
---
