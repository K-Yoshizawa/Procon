---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/AOJ/AOJ-GRL-5-D.cpp
    title: verify/AOJ/AOJ-GRL-5-D.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
    links: []
  bundledCode: "#line 2 \"library/Tree/EulerTour.hpp\"\n\n/**\n * @brief Euler Tour\
    \ - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 1.2\n * @date 2023-08-24\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing EdgeNum = int;\nusing Vertex = int;\n\n/**\n * @brief \u30B0\u30E9\u30D5\
    \u306E\u8FBA\n */\ntemplate<typename CostType = int>\nstruct Edge{\n    Vertex\
    \ from, to;\n    CostType cost;\n\n    Edge(Vertex from, Vertex to, CostType cost)\
    \ : from(from), to(to), cost(cost){}\n};\n\n/**\n * @brief \u30B0\u30E9\u30D5\u3092\
    \u8868\u3059\u30AF\u30E9\u30B9\u3002\n * @note \u8FBA\u96C6\u5408\u306B\u3088\u3063\
    \u3066\u5B9F\u73FE\u3057\u3066\u3044\u308B\u3002\n * @tparam CostType \u8FBA\u306E\
    \u91CD\u307F\u306E\u578B\u3002\n */\ntemplate<typename CostType = int>\nclass\
    \ Graph{\n    private:\n    int sz;\n    bool isDirected, isTree;\n    vector<int>\
    \ indegree;\n\n    public:\n    vector<Edge<CostType>> edges; // \u30B0\u30E9\u30D5\
    \u306E\u8FBA\u96C6\u5408\n    vector<vector<EdgeNum>> connect; // \u5404\u9802\
    \u70B9\u3092\u7AEF\u70B9\u3068\u3059\u308B\u8FBA\u306E\u756A\u53F7\u4E00\u89A7\
    \n    vector<EdgeNum> rev; // \u7121\u5411\u30B0\u30E9\u30D5\u3092\u6709\u5411\
    \u8FBA*2\u3068\u3057\u3066\u8FFD\u52A0\u3059\u308B\u306E\u3067\u3001\u8FBA\u306E\
    \u8FFD\u52A0\u6642\u306B\u9006\u8FBA\u306E\u8FBA\u756A\u53F7\u3092\u8A18\u9332\
    \u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\n    CostType INF;\n\n    /**\n\
    \     * @brief Construct a new Graph object\n     * @param VertexNum \u30B0\u30E9\
    \u30D5\u306E\u9802\u70B9\u6570\n     * @param isDirected \u6709\u5411\u30B0\u30E9\
    \u30D5\u3068\u3057\u3066\u4F5C\u6210\u3059\u308B\u304B(default = false)\n    \
    \ * @param isTree \u6728\u3068\u3057\u3066\u4F5C\u6210\u3059\u308B\u304B(default\
    \ = false)\n     */\n    Graph(int VertexNum, bool isDirected = false, bool isTree\
    \ = false) : sz(VertexNum), isDirected(isDirected), isTree(isTree), connect(VertexNum),\
    \ indegree(VertexNum), INF(numeric_limits<CostType>::max() / 2){}\n\n    Graph()\
    \ = default;\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u306B\u9802\u70B9s\u3068\
    \u9802\u70B9t\u9593\u306E\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\n     * @note\
    \ \u6709\u5411\u30B0\u30E9\u30D5\u306A\u3089\u3070\u9802\u70B9s\u304B\u3089\u9802\
    \u70B9t\u3078\u306E\u6709\u5411\u8FBA\u3092\u3001\u7121\u5411\u30B0\u30E9\u30D5\
    \u306A\u3089\u3070\u9802\u70B9s\u3068\u9802\u70B9t\u3092\u7D50\u3076\u7121\u5411\
    \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\n     * @param s \u9802\u70B9s\n  \
    \   * @param t \u9802\u70B9t\n     * @param w \u8FBA\u306E\u91CD\u307F (option,\
    \ default = 1)\n     */\n    void add(Vertex s, Vertex t, CostType w = 1){\n \
    \       assert(0 <= s && s < sz);\n        assert(0 <= t && t < sz);\n       \
    \ EdgeNum e = edges.size();\n        edges.push_back(Edge<CostType>(s, t, w));\n\
    \        connect[s].push_back(e);\n        ++indegree[t];\n        if(!isDirected){\n\
    \            edges.push_back(Edge<CostType>(t, s, w));\n            connect[t].push_back(e\
    \ + 1);\n            rev.emplace_back(e + 1);\n            rev.emplace_back(e);\n\
    \        }\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u3078\u306E\u5165\
    \u529B\u51E6\u7406\u3092\u884C\u3046\u3002\n     * @param amount \u8FBA\u306E\u6570\
    \n     * @param isWeighted \u91CD\u307F\u3064\u304D\u30B0\u30E9\u30D5\u304B\uFF1F\
    (default = true)\n     * @param isOne_index 1-index\u304B\uFF1F(default = true)\n\
    \     */\n    void input(int amount, bool isWeighted = true, bool isOne_index\
    \ = true){\n        for(int i = 0; i < amount; ++i){\n            Vertex s, t;\
    \ cin >> s >> t;\n            if(isOne_index) --s, --t;\n            CostType\
    \ w = 1;\n            if(isWeighted) cin >> w;\n            add(s, t, w);\n  \
    \      }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3057\u305F\u8FBA\u756A\
    \u53F7\u306E\u8FBA\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param idx \u8FBA\
    \u756A\u53F7\n     * @return Edge<CostType> \u8FBA\u60C5\u5831\n     */\n    Edge<CostType>\
    \ get_edge(EdgeNum idx){\n        int e = edges.size();\n        assert(0 <= idx\
    \ && idx < e);\n        return edges[idx];\n    }\n\n    /**\n     * @brief \u6307\
    \u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\u8FBA\
    \u306E\u4E00\u89A7\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param v \u9802\
    \u70B9\u756A\u53F7\n     * @return vector<Edge<CostType>> \u6307\u5B9A\u3057\u305F\
    \u9802\u70B9\u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\u8FBA\u306E\u4E00\u89A7\
    \n     */\n    vector<Edge<CostType>> get_edges(Vertex v){\n        assert(0 <=\
    \ v && v < sz);\n        vector<Edge<CostType>> ret;\n        for(auto &idx :\
    \ connect[v]) ret.push_back(get_edge(idx));\n        return ret;\n    }\n\n  \
    \  /**\n     * @brief \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\u63A5\
    \u7D9A\u3059\u308B\u8FBA\u756A\u53F7\u306E\u4E00\u89A7\u3092\u53D6\u5F97\u3059\
    \u308B\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return vector<EdgeNum>\
    \ \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\
    \u8FBA\u756A\u53F7\u306E\u4E00\u89A7\n     */\n    vector<EdgeNum> get_list(Vertex\
    \ v){\n        assert(0 <= v && v < sz);\n        return connect[v];\n    }\n\n\
    \    /**\n     * @brief \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\u30D5\
    \u3092\u4F5C\u6210\u3059\u308B\u3002\n     * @attention \u3053\u306E\u64CD\u4F5C\
    \u306F\u6709\u5411\u30B0\u30E9\u30D5\u306B\u306E\u307F\u53EF\u80FD\u3067\u3042\
    \u308B\u3002\n     * @return Graph<CostType> \u9006\u8FBA\u3092\u5F35\u3063\u305F\
    \u30B0\u30E9\u30D5\n     */\n    Graph<CostType> reverse(){\n        assert(isDirected);\n\
    \        Graph<CostType> ret(sz, true, isTree);\n        for(auto &e : edges){\n\
    \            ret.add(e.to, e.from, e.cost);\n        }\n        return ret;\n\
    \    }\n\n    inline size_t size(){\n        return sz;\n    }\n\n    inline bool\
    \ directed(){\n        return isDirected;\n    }\n\n    /**\n     * @brief \u3042\
    \u308B\u9802\u70B9\u306E\u6B21\u6570(\u51FA\u6B21\u6570)\u3092\u53D6\u5F97\u3059\
    \u308B\u3002\n     * @note \u6709\u5411\u30B0\u30E9\u30D5\u306B\u304A\u3044\u3066\
    \u3001\u7B2C2\u5F15\u6570\u3092true\u306B\u3059\u308C\u3070\u5165\u6B21\u6570\u3092\
    \u5F97\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\n     * @param v \u9802\
    \u70B9\u756A\u53F7\n     * @param isIn (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u3068\
    \u304D\u306E\u307F\u6709\u52B9)\u5165\u6B21\u6570\u3092\u53D6\u5F97\u3059\u308B\
    \u304B (default = false)\n     * @return int \u9802\u70B9v\u306E\u6307\u5B9A\u3057\
    \u305F\u5024\n     */\n    inline int degree(Vertex v, bool isIn = false){\n \
    \       if(isDirected && isIn) return indegree[v];\n        return (int)connect[v].size();\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u3092\u9802\u70B9root\u3092\
    \u6839\u3068\u3057\u305F\u7121\u5411\u6839\u4ED8\u304D\u6728\u3068\u307F\u306A\
    \u3057\u305F\u3068\u304D\u3001\u5404\u9802\u70B9\u306E\u89AA\u9802\u70B9\u306E\
    \u756A\u53F7\u3068\u3001\u305D\u308C\u3092\u7D50\u3076\u8FBA\u756A\u53F7\u3092\
    \u53D6\u5F97\u3059\u308B\u3002\n     * @attention \u30B0\u30E9\u30D5\u304C\u7121\
    \u5411\u6728\u3067\u306A\u3044\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\
    \u7FA9\u3067\u3042\u308B\u3002\n     * @param root \u6728\u306E\u6839\u3068\u3059\
    \u308B\u9802\u70B9\u756A\u53F7\n     * @return vector<pair<Vertex, EdgeNum>> \u5404\
    \u9802\u70B9\u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7\u3068\u89AA\u3078\u306E\
    \u8FBA\u756A\u53F7\uFF08\u9802\u70B9root\u306B\u5BFE\u3057\u3066\u306F\u3069\u3061\
    \u3089\u3082-1\u3068\u3059\u308B\uFF09\n     */\n    vector<pair<Vertex, EdgeNum>>\
    \ get_parent(Vertex root){\n        assert(isTree);\n        vector<pair<Vertex,\
    \ EdgeNum>> ret(sz, pair<Vertex, EdgeNum>(-1, -1));\n        stack<pair<Vertex,\
    \ Vertex>> st;\n        st.emplace(root, -1);\n        while(!st.empty()){\n \
    \           auto [v, parent] = st.top();\n            st.pop();\n            for(auto\
    \ &idx : connect[v]){\n                if(edges[idx].to == parent) continue;\n\
    \                ret[edges[idx].to] = pair<Vertex, EdgeNum>(v, rev[idx]);\n  \
    \              st.emplace(edges[idx].to, v);\n            }\n        }\n     \
    \   return ret;\n    }\n\n    void pr(){\n        for(auto &e:edges){\n      \
    \      cerr<<e.from+1<<\" \"<<e.to+1<<endl;\n        }\n    }\n};\n\ntemplate<typename\
    \ T>\nusing Tree = Graph<T>;\n#line 2 \"library/DataStructure/BinaryIndexedTree.hpp\"\
    \n\n/**\n * @brief Binary Indexed Tree\n */\n\n#line 8 \"library/DataStructure/BinaryIndexedTree.hpp\"\
    \nusing namespace std;\n\n/**\n * @brief \u533A\u9593\u306B\u5BFE\u3059\u308B\u4E00\
    \u70B9\u66F4\u65B0\u30FB\u533A\u9593\u548C\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\
    \u3057\u3066\u9AD8\u901F\u304B\u3064\u7C21\u6613\u306B\u5B9F\u88C5\u3067\u304D\
    \u308B\u30C7\u30FC\u30BF\u69CB\u9020\u3002 \n */\ntemplate<typename T>\nstruct\
    \ BinaryIndexedTree{\n    private:\n    vector<T> data;\n\n    public:\n    /**\n\
    \     * @brief Binary Indexed Tree\u3092\u8981\u7D20\u6570size\u3001\u50240\u3067\
    \u521D\u671F\u5316\u3059\u308B\u3002\n     * @param size \u914D\u5217\u306E\u8981\
    \u7D20\u6570\n     */\n    BinaryIndexedTree(int size){\n        data.resize(++size,\
    \ 0);\n    }\n\n    BinaryIndexedTree() = default;\n\n    /**\n     * @brief 1-index\u3067\
    \u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\u5BFE\u3057\u3066\u3001\u914D\u5217\
    \u306E\u6700\u521D\u304B\u3089i\u307E\u3067\u306E\u9589\u533A\u9593\u306E\u548C\
    \u3092\u6C42\u3081\u308B\u3002\n     * @param i \u6C42\u3081\u305F\u3044\u9589\
    \u533A\u9593\u53F3\u7AEF(1-index)\n     * @return T \u533A\u9593\u548C\n     */\n\
    \    T sum(int i){\n        T ret = 0;\n        while(i > 0){\n            ret\
    \ += data[i];\n            i -= i & -i;\n        }\n        return ret;\n    }\n\
    \n    /**\n     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\
    \u5BFE\u3057\u3066\u3001data[i]\u306Bx\u3092\u52A0\u3048\u308B\u3002\n     * @param\
    \ i \u52A0\u3048\u308B\u5834\u6240\n     * @param x \u52A0\u3048\u308B\u5024\n\
    \     */\n    void add(int i, T x){\n        while(i < data.size()){\n       \
    \     data[i] += x;\n            i += i & -i;\n        }\n    }\n\n    /**\n \
    \    * @brief 0-index\u3067\u8868\u3055\u308C\u308B\u534A\u958B\u533A\u9593[l,\
    \ r)\u306E\u533A\u9593\u548C\u3092\u6C42\u3081\u308B\u3002\n     * @param l \u533A\
    \u9593\u306E\u5DE6\u7AEF\n     * @param r \u533A\u9593\u306E\u53F3\u7AEF\n   \
    \  * @return T \u533A\u9593\u548C\n     */\n    T query(int l, int r){\n     \
    \   return sum(r) - sum(l);\n    }\n};\n#line 9 \"library/Tree/EulerTour.hpp\"\
    \n\ntemplate<typename CostType>\nstruct EulerTour{\n    private:\n    int sz,\
    \ k;\n    using Tour = int;\n    Graph<CostType> &G;\n    vector<Tour> arrival,\
    \ departure; // \u9802\u70B9i\u306B\u8A2A\u308C\u305F\u6642\u9593 / \u9802\u70B9\
    i\u304B\u3089\u53BB\u308B\u6642\u9593 : BIT\u306B\u4E57\u305B\u308B\u3053\u3068\
    \u3092\u60F3\u5B9A\u3057\u3066\u3044\u308B\u305F\u3081\u3001\u30AF\u30A8\u30EA\
    \u51E6\u7406\u3092\u7C21\u6613\u306B\u3059\u308B\u305F\u3081\u306B1-index\u3067\
    \u8A18\u9332\u3059\u308B\n    BinaryIndexedTree<CostType> BIT;\n    vector<pair<Vertex,\
    \ EdgeNum>> relation;\n\n    void dfs1(int v, int pre){\n        arrival[v] =\
    \ k++;\n        for(auto &e : G.get_edges(v)){\n            if(e.to == pre) continue;\n\
    \            dfs1(e.to, v);\n        }\n        departure[v] = k++;\n    }\n\n\
    \    void dfs2(int v, int pre, CostType value){\n        BIT.add(arrival[v], value);\n\
    \        for(auto &e : G.get_edges(v)){\n            if(e.to == pre) continue;\n\
    \            dfs2(e.to, v, e.cost);\n        }\n        BIT.add(departure[v],\
    \ -value);\n    }\n\n    public:\n    /**\n     * @brief \u9802\u70B9root\u3092\
    \u6839\u3068\u3057\u305F\u6728G\u3067\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
    \u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention G\u304C\u6728\u3067\u306A\
    \u3044\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9\n     * @param G\
    \ \u6728\n     * @param root \u6839 (option, default = 0)\n     */\n    EulerTour(Graph<CostType>\
    \ &G, Vertex root = 0) : G(G), sz(G.size()), BIT(G.size() * 2), k(1){\n      \
    \  arrival.resize(sz, -1);\n        departure.resize(sz, -1);\n        dfs1(root,\
    \ -1);\n        dfs2(0, -1, 0);\n        relation = G.get_parent(root);\n    }\n\
    \n    /**\n     * @brief \u6839\u304B\u3089\u9802\u70B9v\u3078\u306E\u8DDD\u96E2\
    \u3092BIT\u3092\u7528\u3044\u3066\u53D6\u5F97\u3059\u308B\u3002\n     * @param\
    \ v \u53D6\u5F97\u3057\u305F\u3044\u9802\u70B9\u756A\u53F7v\n     * @return CostType\
    \ \u6839\u304B\u3089\u9802\u70B9v\u3078\u306E\u8DDD\u96E2\n     */\n    CostType\
    \ query(Vertex v){\n        return BIT.sum(arrival[v]);\n    }\n\n    /**\n  \
    \   * @brief \u9802\u70B9child\u3068\u305D\u306E\u89AA\u3092\u7D50\u3076\u8FBA\
    \u306E\u91CD\u307F\u3092x\u5897\u52A0\u3055\u305B\u308B\u4E00\u70B9\u66F4\u65B0\
    \u30AF\u30A8\u30EA\n     * @param child \u5B50\u306E\u9802\u70B9\u3092\u8868\u3059\
    \u9802\u70B9\u756A\u53F7\n     * @param x \u5897\u52A0\u3055\u305B\u308B\u91CD\
    \u307F\n     */\n    void add(Vertex child, CostType x){\n        auto [parent,\
    \ ed] = relation[child];\n        G.edges[ed].cost += x;\n        G.edges[G.rev[ed]].cost\
    \ += x;\n        BIT.add(arrival[child], x);\n        BIT.add(departure[child],\
    \ -x);\n    }\n\n    void update(Vertex child, CostType x){\n        auto [parent,\
    \ ed] = relation[child];\n        CostType diff = x - G.edges[ed].cost;\n    \
    \    G.edges[ed].cost += diff;\n        G.edges[G.rev[ed]].cost += diff;\n   \
    \     BIT.add(arrival[child], diff);\n        BIT.add(departure[child], -diff);\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\
    \u30A2\u30FC\n */\n\n#include \"../Graph/GraphTemplate.hpp\"\n#include \"../DataStructure/BinaryIndexedTree.hpp\"\
    \n\ntemplate<typename CostType>\nstruct EulerTour{\n    private:\n    int sz,\
    \ k;\n    using Tour = int;\n    Graph<CostType> &G;\n    vector<Tour> arrival,\
    \ departure; // \u9802\u70B9i\u306B\u8A2A\u308C\u305F\u6642\u9593 / \u9802\u70B9\
    i\u304B\u3089\u53BB\u308B\u6642\u9593 : BIT\u306B\u4E57\u305B\u308B\u3053\u3068\
    \u3092\u60F3\u5B9A\u3057\u3066\u3044\u308B\u305F\u3081\u3001\u30AF\u30A8\u30EA\
    \u51E6\u7406\u3092\u7C21\u6613\u306B\u3059\u308B\u305F\u3081\u306B1-index\u3067\
    \u8A18\u9332\u3059\u308B\n    BinaryIndexedTree<CostType> BIT;\n    vector<pair<Vertex,\
    \ EdgeNum>> relation;\n\n    void dfs1(int v, int pre){\n        arrival[v] =\
    \ k++;\n        for(auto &e : G.get_edges(v)){\n            if(e.to == pre) continue;\n\
    \            dfs1(e.to, v);\n        }\n        departure[v] = k++;\n    }\n\n\
    \    void dfs2(int v, int pre, CostType value){\n        BIT.add(arrival[v], value);\n\
    \        for(auto &e : G.get_edges(v)){\n            if(e.to == pre) continue;\n\
    \            dfs2(e.to, v, e.cost);\n        }\n        BIT.add(departure[v],\
    \ -value);\n    }\n\n    public:\n    /**\n     * @brief \u9802\u70B9root\u3092\
    \u6839\u3068\u3057\u305F\u6728G\u3067\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
    \u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention G\u304C\u6728\u3067\u306A\
    \u3044\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9\n     * @param G\
    \ \u6728\n     * @param root \u6839 (option, default = 0)\n     */\n    EulerTour(Graph<CostType>\
    \ &G, Vertex root = 0) : G(G), sz(G.size()), BIT(G.size() * 2), k(1){\n      \
    \  arrival.resize(sz, -1);\n        departure.resize(sz, -1);\n        dfs1(root,\
    \ -1);\n        dfs2(0, -1, 0);\n        relation = G.get_parent(root);\n    }\n\
    \n    /**\n     * @brief \u6839\u304B\u3089\u9802\u70B9v\u3078\u306E\u8DDD\u96E2\
    \u3092BIT\u3092\u7528\u3044\u3066\u53D6\u5F97\u3059\u308B\u3002\n     * @param\
    \ v \u53D6\u5F97\u3057\u305F\u3044\u9802\u70B9\u756A\u53F7v\n     * @return CostType\
    \ \u6839\u304B\u3089\u9802\u70B9v\u3078\u306E\u8DDD\u96E2\n     */\n    CostType\
    \ query(Vertex v){\n        return BIT.sum(arrival[v]);\n    }\n\n    /**\n  \
    \   * @brief \u9802\u70B9child\u3068\u305D\u306E\u89AA\u3092\u7D50\u3076\u8FBA\
    \u306E\u91CD\u307F\u3092x\u5897\u52A0\u3055\u305B\u308B\u4E00\u70B9\u66F4\u65B0\
    \u30AF\u30A8\u30EA\n     * @param child \u5B50\u306E\u9802\u70B9\u3092\u8868\u3059\
    \u9802\u70B9\u756A\u53F7\n     * @param x \u5897\u52A0\u3055\u305B\u308B\u91CD\
    \u307F\n     */\n    void add(Vertex child, CostType x){\n        auto [parent,\
    \ ed] = relation[child];\n        G.edges[ed].cost += x;\n        G.edges[G.rev[ed]].cost\
    \ += x;\n        BIT.add(arrival[child], x);\n        BIT.add(departure[child],\
    \ -x);\n    }\n\n    void update(Vertex child, CostType x){\n        auto [parent,\
    \ ed] = relation[child];\n        CostType diff = x - G.edges[ed].cost;\n    \
    \    G.edges[ed].cost += diff;\n        G.edges[G.rev[ed]].cost += diff;\n   \
    \     BIT.add(arrival[child], diff);\n        BIT.add(departure[child], -diff);\n\
    \    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  - library/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: false
  path: library/Tree/EulerTour.hpp
  requiredBy:
  - verify/AOJ/AOJ-GRL-5-D.cpp
  timestamp: '2023-09-16 09:30:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Tree/EulerTour.hpp
layout: document
redirect_from:
- /library/library/Tree/EulerTour.hpp
- /library/library/Tree/EulerTour.hpp.html
title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
---