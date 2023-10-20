---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/SegmentTree.hpp
    title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/Tree/EulerTour.hpp
    title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
  bundledCode: "#line 1 \"verify/AOJ-GRL-5-D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D\"\
    \n\n#line 1 \"library/Tree/EulerTour.hpp\"\n/**\n * @file EulerTour.hpp\n * @author\
    \ log K (lX57)\n * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
    \n * @version 2.0\n * @date 2023-10-20\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
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
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"library/Tree/EulerTour.hpp\"\
    \n\ntemplate<typename CostType>\nstruct EulerTour{\n    private:\n    Graph<CostType>\
    \ &G;\n    Vertex __Root;\n    vector<int> __In, __Out;\n    int __timer;\n\n\
    \    void __dfs(Vertex now, Vertex par){\n        __In[now] = __timer++;\n   \
    \     for(auto e : G.get_incident(now)){\n            if(e.to == par) continue;\n\
    \            __dfs(e.to, now);\n        }\n        __Out[now] = __timer++;\n \
    \   }\n\n    public:\n    /**\n     * @brief Euler Tour\u3092\u69CB\u7BC9\u3059\
    \u308B\u3002\n     * @param G \u69CB\u7BC9\u3059\u308B\u30B0\u30E9\u30D5\n   \
    \  * @param Root \u6839\u3068\u3059\u308B\u9802\u70B9\u756A\u53F7 (default = `0`)\n\
    \     * @note `timer` \u306F `1` \u304B\u3089\u59CB\u307E\u308B(\u30BB\u30B0\u6728\
    \u306A\u3069\u306B1-index\u3067\u8F09\u305B\u3089\u308C\u308B)\n     */\n    EulerTour(Graph<CostType>\
    \ &G, Vertex Root = 0) : G(G), __Root(Root), __In(G.vsize(), -1), __Out(G.vsize(),\
    \ -1){\n        __timer = 1;\n        __dfs(__Root, -1);\n    }\n\n    int in(Vertex\
    \ v){\n        assert(0 <= v && v < G.vsize());\n        return __In[v];\n   \
    \ }\n\n    int out(Vertex v){\n        assert(0 <= v && v < G.vsize());\n    \
    \    return __Out[v];\n    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E\
    \ `in` \u3068 `out` \u3092\u540C\u6642\u306B\u53D6\u5F97\u3059\u308B\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7\n     * @return pair<int, int> `{in(v), out(v)}`\n\
    \     */\n    pair<int, int> operator[](Vertex v){\n        return make_pair(in(v),\
    \ out(v));\n    }\n};\n#line 1 \"library/DataStructure/SegmentTree.hpp\"\n/**\n\
    \ * @file SegmentTree.hpp\n * @author log K (lX57)\n * @brief Segment Tree - \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n * @version 2.0\n * @date 2023-10-02\n */\n\n\
    #line 10 \"library/DataStructure/SegmentTree.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ Monoid>\nstruct SegmentTree{\n    private:\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n\n    int __Size, __Offset, __ZeroIndex;\n    vector<Monoid> __Data;\n\
    \    const F f;\n    const Monoid __M1;\n\n    inline void __Check(int x){\n \
    \       assert(1 <= x && x <= __Size);\n    }\n\n    Monoid __query(int ql, int\
    \ qr, int left, int right, int cell){\n        if(qr <= left || right <= ql){\n\
    \            return __M1;\n        }\n        if(ql <= left && right <= qr){\n\
    \            return __Data[cell];\n        }\n        int mid = (left + right)\
    \ / 2;\n        Monoid ans_left = __query(ql, qr, left, mid, 2 * cell);\n    \
    \    Monoid ans_right = __query(ql, qr, mid, right, 2 * cell + 1);\n        return\
    \ f(ans_left, ans_right);\n    }\n\n    public:\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\u6570 `Size` \u3067\u521D\u671F\
    \u5316\u3059\u308B\u3002\n     * @param Size \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u306E\u8981\u7D20\u6570\n     * @param Merge \u533A\u9593\u53D6\u5F97\u3092\u884C\
    \u3046\u6F14\u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\u30C9\u306E\
    \u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\
    \u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(int Size, F Merge,\
    \ const Monoid &Monoid_Identity, bool ZeroIndex = false)\n    : f(Merge), __M1(Monoid_Identity),\
    \ __ZeroIndex(ZeroIndex){\n        __Size = 1;\n        while(__Size < Size) __Size\
    \ <<= 1;\n        __Offset = __Size - 1;\n        __Data.resize(2 * __Size, __M1);\n\
    \    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\
    \u7BC9\u3059\u308B\u3002\n     * @attention \u5FC5\u305A `set()` \u3067\u521D\u671F\
    \u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\u3089\u547C\u3073\u51FA\u3059\u3053\
    \u3068\uFF01\n     */\n    void build(){\n        for(int i = __Offset; i >= 1;\
    \ --i){\n            __Data[i] = f(__Data[i * 2 + 0], __Data[i * 2 + 1]);\n  \
    \      }\n    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u306E\u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\u308B\u3002\n     * @param Index\
    \ \u4EE3\u5165\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     *\
    \ @param Value \u4EE3\u5165\u3059\u308B\u5024\n     */\n    void set(int Index,\
    \ Monoid Value){\n        __Check(Index + __ZeroIndex);\n        __Data[__Offset\
    \ + Index + __ZeroIndex] = Value;\n    }\n\n    /**\n     * @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u3092\u914D\u5217 `Init_Data` \u3067\u521D\u671F\u5316\
    \u3059\u308B\u3002\n     * @param Init_Data \u521D\u671F\u30C7\u30FC\u30BF\u306E\
    \u914D\u5217\n     * @param Merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\
    \u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B (default = `false`)\n     */\n    SegmentTree(vector<Monoid> &Init_Data,\
    \ F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\n    : f(Merge),\
    \ __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){\n        __Size = 1;\n      \
    \  while(__Size < (int)Init_Data.size()) __Size <<= 1;\n        __Offset = __Size\
    \ - 1;\n        __Data.resize(2 * __Size, __M1);\n        for(int i = 0; i < (int)Init_Data.size();\
    \ ++i){\n            __Data[__Size + i] = Init_Data[i];\n        }\n        build();\n\
    \    }\n\n    /**\n     * @brief \u4E00\u70B9\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\
    \u51E6\u7406\u3059\u308B\u3002\n     * @param Index \u66F4\u65B0\u5148\u306E\u8981\
    \u7D20\u756A\u53F7 (default = 1-index)\n     * @param Value \u66F4\u65B0\u3059\
    \u308B\u5024\n     */\n    void update(int Index, Monoid Value){\n        __Check(Index\
    \ + __ZeroIndex);\n        int k = __Offset + Index + __ZeroIndex;\n        __Data[k]\
    \ = Value;\n        while(k >>= 1){\n            __Data[k] = f(__Data[2 * k],\
    \ __Data[2 * k + 1]);\n        }\n    }\n\n    /**\n     * @brief \u534A\u958B\
    \u533A\u9593 `[Left, Right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\
    \u30A8\u30EA\u3092\u884C\u3046\u3002\n     * @param Left \u534A\u958B\u533A\u9593\
    \u306E\u5DE6\u7AEF\n     * @param Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\
    \n     * @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid\
    \ query(int Left, int Right){\n        __Check(Left + __ZeroIndex);\n        __Check(Right\
    \ + __ZeroIndex - 1);\n        return __query(Left + __ZeroIndex, Right + __ZeroIndex,\
    \ 1, __Size + 1, 1);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u756A\u53F7\
    \ `k` \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param k\
    \ \u53D6\u5F97\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     *\
    \ @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid get(int\
    \ k){\n        __Check(k + __ZeroIndex);\n        return __Data[__Offset + k +\
    \ __ZeroIndex];\n    }\n\n    Monoid operator[](const int &k){\n        return\
    \ get(k);\n    }\n};\n#line 5 \"verify/AOJ-GRL-5-D.test.cpp\"\n\nint main(){\n\
    \    int n; cin >> n;\n    Graph<int> G(n);\n    for(int i = 0; i < n; ++i){\n\
    \        int k; cin >> k;\n        for(int j = 0; j < k; ++j){\n            int\
    \ c; cin >> c;\n            G.add(i, c, 0);\n        }\n    }\n    EulerTour<int>\
    \ et(G, 0);\n    vector<long long> Init_Data(2 * n, 0);\n    SegmentTree<long\
    \ long> seg(Init_Data,\n        [](int l, int r){return l + r;},\n        0, false);\n\
    \    \n    int q; cin >> q;\n    while(q--){\n        int query; cin >> query;\n\
    \        if(query == 0){\n            int v, w; cin >> v >> w;\n            auto\
    \ [in, out] = et[v];\n            seg.update(in, seg.get(in) + w);\n         \
    \   seg.update(out, seg.get(out) - w);\n        }\n        else{\n           \
    \ int u; cin >> u;\n            cout << seg.query(1, et.in(u) + 1) << endl;\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D\"\
    \n\n#include \"../library/Tree/EulerTour.hpp\"\n#include \"../library/DataStructure/SegmentTree.hpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    Graph<int> G(n);\n    for(int i = 0;\
    \ i < n; ++i){\n        int k; cin >> k;\n        for(int j = 0; j < k; ++j){\n\
    \            int c; cin >> c;\n            G.add(i, c, 0);\n        }\n    }\n\
    \    EulerTour<int> et(G, 0);\n    vector<long long> Init_Data(2 * n, 0);\n  \
    \  SegmentTree<long long> seg(Init_Data,\n        [](int l, int r){return l +\
    \ r;},\n        0, false);\n    \n    int q; cin >> q;\n    while(q--){\n    \
    \    int query; cin >> query;\n        if(query == 0){\n            int v, w;\
    \ cin >> v >> w;\n            auto [in, out] = et[v];\n            seg.update(in,\
    \ seg.get(in) + w);\n            seg.update(out, seg.get(out) - w);\n        }\n\
    \        else{\n            int u; cin >> u;\n            cout << seg.query(1,\
    \ et.in(u) + 1) << endl;\n        }\n    }\n}"
  dependsOn:
  - library/Tree/EulerTour.hpp
  - library/Graph/GraphTemplate.hpp
  - library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-5-D.test.cpp
  requiredBy: []
  timestamp: '2023-10-20 15:07:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-GRL-5-D.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-5-D.test.cpp
- /verify/verify/AOJ-GRL-5-D.test.cpp.html
title: verify/AOJ-GRL-5-D.test.cpp
---
