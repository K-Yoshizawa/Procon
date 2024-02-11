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
  - icon: ':heavy_check_mark:'
    path: library/Tree/LowestCommonAncestor.hpp
    title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"verify/LC-VertexAddPathSum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 1 \"library/Tree/EulerTour.hpp\"\
    \n/**\n * @file EulerTour.hpp\n * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\
    \u30C4\u30A2\u30FC\n * @version 3.0\n * @date 2024-02-11\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @brief Graph Template - \u30B0\u30E9\u30D5\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 3.0\n * @date 2024-01-09\n */\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    public:\n    Vertex from, to;\n    CostType cost;\n\
    \    int loc{-1}, id{-1};\n\n    Edge() = default;\n    Edge(Vertex from, Vertex\
    \ to, CostType cost) : from(from), to(to), cost(cost){}\n\n    operator int(){\n\
    \        return to;\n    }\n};\n\ntemplate<typename CostType = int>\nstruct Graph{\n\
    \    private:\n    int m_vertex_size{0}, m_edge_size{0};\n    bool m_is_directed{false};\n\
    \    vector<vector<Edge<CostType>>> m_adj;\n    vector<int> m_indegree;\n\n  \
    \  public:\n    CostType INF{numeric_limits<CostType>::max() >> 2};\n\n    Graph()\
    \ = default;\n    Graph(int vertex_size, bool directed = false) : m_vertex_size(vertex_size),\
    \ m_is_directed(directed){\n        m_adj.resize(vertex_size);\n        m_indegree.resize(vertex_size,\
    \ 0);\n    }\n\n    void add(Vertex from, Vertex to, CostType cost = 1){\n   \
    \     assert(0 <= from and from < m_vertex_size);\n        assert(0 <= to and\
    \ to < m_vertex_size);\n        Edge<CostType> e1(from, to, cost);\n        e1.loc\
    \ = m_adj[from].size();\n        e1.id = m_edge_size;\n        m_adj[from].push_back(e1);\n\
    \        ++m_edge_size;\n        if(m_is_directed){\n            ++m_indegree[to];\n\
    \            return;\n        }\n        Edge<CostType> e2(to, from, cost);\n\
    \        e2.loc = m_adj[to].size();\n        e2.id = e1.id;\n        m_adj[to].push_back(e2);\n\
    \    }\n\n    void input(int edge_size, bool weighted = false, bool zero_index\
    \ = false){\n        for(int i = 0; i < edge_size; ++i){\n            Vertex s,\
    \ t; cin >> s >> t;\n            if(!zero_index) --s, --t;\n            CostType\
    \ c = 1;\n            if(weighted) cin >> c;\n            add(s, t, c);\n    \
    \    }\n    }\n\n    size_t size(){\n        return m_vertex_size;\n    }\n\n\
    \    int outdegree(Vertex v){\n        return (int)m_adj.at(v).size();\n    }\n\
    \n    int indegree(Vertex v){\n        if(m_is_directed) return m_indegree.at(v);\n\
    \        else return (int)m_adj.at(v).size();\n    }\n\n    vector<Vertex> source(){\n\
    \        assert(m_is_directed);\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 0) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Vertex> sink(){\n       \
    \ vector<Vertex> ret;\n        for(int i = 0; i < m_vertex_size; ++i){\n     \
    \       if(outdegree(i) == 0) ret.push_back(i);\n        }\n        return ret;\n\
    \    }\n\n    vector<Vertex> leaf(){\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 1) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Edge<CostType>> &get_adj(Vertex\
    \ v){\n        return m_adj.at(v);\n    }\n\n    Graph<CostType> reverse(){\n\
    \        assert(m_is_directed);\n        Graph ret(m_vertex_size, true);\n   \
    \     for(auto es : m_adj){\n            for(auto e : es){\n                ret.add(e.to,\
    \ e.from, e.cost);\n            }\n        }\n        return ret;\n    }\n\n \
    \   vector<Vertex> topological_sort(){\n        assert(m_is_directed);\n     \
    \   vector<Vertex> ret;\n        queue<Vertex> que;\n        vector<int> cnt(m_vertex_size,\
    \ 0);\n        for(auto v : source()) que.push(v);\n        while(que.size()){\n\
    \            Vertex v = que.front(); que.pop();\n            ret.push_back(v);\n\
    \            for(int u : m_adj[v]){\n                if(++cnt[u] == indegree(u))\
    \ que.push(u);\n            }\n        }\n        return ret;\n    }\n\n    vector<Edge<CostType>>\
    \ edge_set(){\n        vector<Edge<CostType>> ret;\n        vector<int> es(m_edge_size,\
    \ 0);\n        for(int i = 0; i < m_vertex_size; ++i){\n            for(auto e\
    \ : m_adj[i]){\n                if(es[e.id]) continue;\n                es[e.id]\
    \ = 1;\n                ret.push_back(e);\n            }\n        }\n        sort(ret.begin(),\
    \ ret.end(), [&](Edge<CostType> &l, Edge<CostType> &r){\n            return l.cost\
    \ < r.cost;\n        });\n        return ret;\n    }\n\n    void print(){\n  \
    \      for(int i = 0; i < m_vertex_size; ++i){\n            cout << \"Vertex \"\
    \ << i << \" : \";\n            if(m_adj[i].empty()){\n                cout <<\
    \ \"<none>\" << endl;\n                continue;\n            }\n            for(auto\
    \ &e : m_adj[i]){\n                cout << \"{\" << e.to << \", \" << e.cost <<\
    \ \"} \";\n            }\n            cout << endl;\n        }\n    }\n\n    vector<Edge<CostType>>\
    \ &operator[](Vertex v){\n        return get_adj(v);\n    }\n};\n#line 9 \"library/Tree/EulerTour.hpp\"\
    \n\ntemplate<typename CostType>\nstruct EulerTour{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<int> m_in, m_out;\n\n    void m_dfs(Vertex v, Vertex p, int\
    \ &t){\n        m_in[v] = t++;\n        for(auto &e : G[v]){\n            if(e.to\
    \ == p) continue;\n            m_dfs(e.to, v, t);\n        }\n        m_out[v]\
    \ = t++;\n    }\n\n    public:\n    EulerTour(Graph<CostType> &G, Vertex Root\
    \ = 0, int Offset = 0) : G(G){\n        m_in.resize(G.size());\n        m_out.resize(G.size());\n\
    \        m_dfs(Root, -1, Offset);\n    }\n\n    int in(Vertex v){\n        assert(0\
    \ <= v && v < G.size());\n        return m_in[v];\n    }\n\n    int out(Vertex\
    \ v){\n        assert(0 <= v && v < G.size());\n        return m_out[v];\n   \
    \ }\n\n    pair<vector<int>, vector<int>> get(){\n        return make_pair(m_in,\
    \ m_out);\n    }\n\n    pair<int, int> operator[](Vertex v){\n        return make_pair(in(v),\
    \ out(v));\n    }\n};\n#line 1 \"library/Tree/LowestCommonAncestor.hpp\"\n/**\n\
    \ * @file LowestCommonAncestor.hpp\n * @author log K (lX57)\n * @brief Lowest\
    \ Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148\n * @version 3.0\n *\
    \ @date 2024-02-11\n */\n\n#line 10 \"library/Tree/LowestCommonAncestor.hpp\"\n\
    \ntemplate<typename CostType>\nstruct LowestCommonAncestor{\n    private:\n  \
    \  Graph<CostType> &G;\n    int m_height;\n    vector<int> m_depth;\n    vector<vector<Vertex>>\
    \ m_parent;\n\n    void m_dfs(Vertex v, Vertex p, int d){\n        m_parent[0][v]\
    \ = p;\n        m_depth[v] = d;\n        for(auto &e : G[v]){\n            if(e.to\
    \ != p) m_dfs(e.to, v, d + 1);\n        }\n    }\n\n    public:\n    LowestCommonAncestor(Graph<CostType>\
    \ &G, Vertex Root = 0) : G(G), m_height(32){\n        m_depth.resize(G.size());\n\
    \        m_parent.resize(m_height, vector<Vertex>(G.size(), -1));\n        m_dfs(Root,\
    \ -1, 0);\n        for(int k = 0; k + 1 < m_height; ++k){\n            for(Vertex\
    \ v = 0; v < G.size(); ++v){\n                if(m_parent[k][v] < 0) m_parent[k\
    \ + 1][v] = -1;\n                else m_parent[k + 1][v] = m_parent[k][m_parent[k][v]];\n\
    \            }\n        }\n    }\n\n    Vertex get(Vertex u, Vertex v){\n    \
    \    if(m_depth[u] > m_depth[v]) swap(u, v);\n        for(int k = 0; k < m_height;\
    \ ++k){\n            if((m_depth[v] - m_depth[u]) >> k & 1){\n               \
    \ v = m_parent[k][v];\n            }\n        }\n        if(u == v) return u;\n\
    \        for(int k = m_height - 1; k >= 0; --k){\n            if(m_parent[k][u]\
    \ != m_parent[k][v]){\n                u = m_parent[k][u];\n                v\
    \ = m_parent[k][v];\n            }\n        }\n        return m_parent[0][u];\n\
    \    }\n};\n#line 1 \"library/DataStructure/SegmentTree.hpp\"\n/**\n * @file SegmentTree.hpp\n\
    \ * @author log K (lX57)\n * @brief Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n * @version 2.0\n * @date 2023-10-02\n */\n\n#line 10 \"library/DataStructure/SegmentTree.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Monoid>\nstruct SegmentTree{\n   \
    \ private:\n    using F = function<Monoid(Monoid, Monoid)>;\n\n    int __Size,\
    \ __Offset, __ZeroIndex;\n    vector<Monoid> __Data;\n    const F f;\n    const\
    \ Monoid __M1;\n\n    inline void __Check(int x){\n        assert(1 <= x && x\
    \ <= __Size);\n    }\n\n    Monoid __query(int ql, int qr, int left, int right,\
    \ int cell){\n        if(qr <= left || right <= ql){\n            return __M1;\n\
    \        }\n        if(ql <= left && right <= qr){\n            return __Data[cell];\n\
    \        }\n        int mid = (left + right) / 2;\n        Monoid ans_left = __query(ql,\
    \ qr, left, mid, 2 * cell);\n        Monoid ans_right = __query(ql, qr, mid, right,\
    \ 2 * cell + 1);\n        return f(ans_left, ans_right);\n    }\n\n    public:\n\
    \    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\
    \u6570 `Size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Size \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\n     * @param Merge \u533A\
    \u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param Monoid_Identity\
    \ \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\
    \u3057\u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(int\
    \ Size, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\n    :\
    \ f(Merge), __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){\n        __Size = 1;\n\
    \        while(__Size < Size) __Size <<= 1;\n        __Offset = __Size - 1;\n\
    \        __Data.resize(2 * __Size, __M1);\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention\
    \ \u5FC5\u305A `set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\
    \u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n     */\n    void build(){\n\
    \        for(int i = __Offset; i >= 1; --i){\n            __Data[i] = f(__Data[i\
    \ * 2 + 0], __Data[i * 2 + 1]);\n        }\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\
    \u308B\u3002\n     * @param Index \u4EE3\u5165\u5148\u306E\u8981\u7D20\u756A\u53F7\
    \ (default = 1-index)\n     * @param Value \u4EE3\u5165\u3059\u308B\u5024\n  \
    \   */\n    void set(int Index, Monoid Value){\n        __Check(Index + __ZeroIndex);\n\
    \        __Data[__Offset + Index + __ZeroIndex] = Value;\n    }\n\n    /**\n \
    \    * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u914D\u5217 `Init_Data`\
    \ \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Init_Data \u521D\u671F\
    \u30C7\u30FC\u30BF\u306E\u914D\u5217\n     * @param Merge \u533A\u9593\u53D6\u5F97\
    \u3092\u884C\u3046\u6F14\u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\
    \u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\
    \u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(vector<Monoid>\
    \ &Init_Data, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\n\
    \    : f(Merge), __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){\n        __Size\
    \ = 1;\n        while(__Size < (int)Init_Data.size()) __Size <<= 1;\n        __Offset\
    \ = __Size - 1;\n        __Data.resize(2 * __Size, __M1);\n        for(int i =\
    \ 0; i < (int)Init_Data.size(); ++i){\n            __Data[__Size + i] = Init_Data[i];\n\
    \        }\n        build();\n    }\n\n    /**\n     * @brief \u4E00\u70B9\u66F4\
    \u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\n     * @param Index\
    \ \u66F4\u65B0\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     *\
    \ @param Value \u66F4\u65B0\u3059\u308B\u5024\n     */\n    void update(int Index,\
    \ Monoid Value){\n        __Check(Index + __ZeroIndex);\n        int k = __Offset\
    \ + Index + __ZeroIndex;\n        __Data[k] = Value;\n        while(k >>= 1){\n\
    \            __Data[k] = f(__Data[2 * k], __Data[2 * k + 1]);\n        }\n   \
    \ }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[Left, Right)` \u306B\u5BFE\
    \u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\u884C\u3046\u3002\
    \n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n     * @param\
    \ Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return Monoid \u53D6\
    \u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid query(int Left, int Right){\n\
    \        __Check(Left + __ZeroIndex);\n        __Check(Right + __ZeroIndex - 1);\n\
    \        return __query(Left + __ZeroIndex, Right + __ZeroIndex, 1, __Size + 1,\
    \ 1);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\u8981\
    \u7D20\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param k \u53D6\u5F97\u5148\
    \u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     * @return Monoid \u53D6\
    \u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid get(int k){\n        __Check(k\
    \ + __ZeroIndex);\n        return __Data[__Offset + k + __ZeroIndex];\n    }\n\
    \n    Monoid operator[](const int &k){\n        return get(k);\n    }\n};\n\n\
    namespace logk{\n    template<typename T>\n    SegmentTree<T> SegmentTreeRMQ(vector<T>\
    \ &InitData, T INF = 0, bool ZeroIndex = false){\n        if(INF == 0) INF = numeric_limits<T>::max()\
    \ >> 1;\n        return SegmentTree<T>(InitData, [](T l, T r){return min(l, r);},\
    \ INF, ZeroIndex);\n    }\n}\n#line 6 \"verify/LC-VertexAddPathSum.test.cpp\"\n\
    \nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n   \
    \ for(auto &ai : a) cin >> ai;\n    Graph<long long> G(N);\n    G.input(N - 1,\
    \ false, true);\n\n    EulerTour et(G);\n    auto [in, out] = et.get();\n    vector<long\
    \ long> b(N * 2, 0);\n    for(int i = 0; i < N; ++i){\n        b[in[i]] = a[i],\
    \ b[out[i]] = -a[i];\n    }\n    LowestCommonAncestor lca(G);\n    SegmentTree<long\
    \ long> seg(b, [&](long long l, long long r){return l + r;}, 0LL, true);\n\n \
    \   while(Q--){\n        int query; cin >> query;\n        if(query == 0){\n \
    \           long long p, x; cin >> p >> x;\n            long long y = a[p] + x;\n\
    \            a[p] += x;\n            seg.update(in[p], y);\n            seg.update(out[p],\
    \ -y);\n        }\n        else{\n            int u, v; cin >> u >> v;\n     \
    \       int t = lca.get(u, v);\n            cout << seg.query(in[t], in[u] + 1)\
    \ + seg.query(in[t], in[v] + 1) - a[t] << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../library/Tree/EulerTour.hpp\"\n#include \"../library/Tree/LowestCommonAncestor.hpp\"\
    \n#include \"../library/DataStructure/SegmentTree.hpp\"\n\nint main(){\n    int\
    \ N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n    for(auto &ai : a) cin\
    \ >> ai;\n    Graph<long long> G(N);\n    G.input(N - 1, false, true);\n\n   \
    \ EulerTour et(G);\n    auto [in, out] = et.get();\n    vector<long long> b(N\
    \ * 2, 0);\n    for(int i = 0; i < N; ++i){\n        b[in[i]] = a[i], b[out[i]]\
    \ = -a[i];\n    }\n    LowestCommonAncestor lca(G);\n    SegmentTree<long long>\
    \ seg(b, [&](long long l, long long r){return l + r;}, 0LL, true);\n\n    while(Q--){\n\
    \        int query; cin >> query;\n        if(query == 0){\n            long long\
    \ p, x; cin >> p >> x;\n            long long y = a[p] + x;\n            a[p]\
    \ += x;\n            seg.update(in[p], y);\n            seg.update(out[p], -y);\n\
    \        }\n        else{\n            int u, v; cin >> u >> v;\n            int\
    \ t = lca.get(u, v);\n            cout << seg.query(in[t], in[u] + 1) + seg.query(in[t],\
    \ in[v] + 1) - a[t] << endl;\n        }\n    }\n}"
  dependsOn:
  - library/Tree/EulerTour.hpp
  - library/Graph/GraphTemplate.hpp
  - library/Tree/LowestCommonAncestor.hpp
  - library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify/LC-VertexAddPathSum.test.cpp
  requiredBy: []
  timestamp: '2024-02-11 17:55:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-VertexAddPathSum.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-VertexAddPathSum.test.cpp
- /verify/verify/LC-VertexAddPathSum.test.cpp.html
title: verify/LC-VertexAddPathSum.test.cpp
---
