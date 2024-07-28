---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/UnionFind.hpp
    title: "UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
  - icon: ':heavy_check_mark:'
    path: library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-MinimumSpanningTree.test.cpp
    title: verify/LC-MinimumSpanningTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
    links:
    - https://judge.yosupo.jp/problem/minimum_spanning_tree
  bundledCode: "#line 1 \"library/Graph/Kruskal.hpp\"\n/**\n * @file Kruskal.hpp\n\
    \ * @brief Kruskal - \u6700\u5C0F\u5168\u57DF\u6728\n * @version 4.0\n * @date\
    \ 2024-07-19\n */\n\n#line 2 \"library/Graph/Graph.hpp\"\n\n/**\n * @file Graph.hpp\n\
    \ * @brief Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n *\
    \ @version 0.1\n * @date 2024-06-14\n */\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing Vertex = int;\n\ntemplate<typename CostType>\nstruct Edge{\n \
    \   int from{-1}, to{-1}, id{-1};\n    CostType cost{1};\n\n    Edge() = default;\n\
    \    Edge(int from, int to, CostType cost, int id = -1) : from(from), to(to),\
    \ cost(cost), id(id){}\n};\n\ntemplate<typename CostType = int32_t>\nclass Graph{\n\
    \    protected:\n    using ED = Edge<CostType>;\n\n    size_t vertex_{0}, edge_{0};\n\
    \    vector<vector<ED>> adjacent_list_;\n\n    bool directed_flag_;\n    CostType\
    \ inf_{numeric_limits<CostType>::max() / 4};\n\n    inline void validate(int vertex){\n\
    \        assert(0 <= vertex && vertex < vertex_);\n    }\n\n    public:\n    Graph()\
    \ = default;\n\n    /**\n     * @brief \u9802\u70B9\u6570 `vertex_size` \u306E\
    \u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @param vertex_size\
    \ \u9802\u70B9\u6570\n     * @param directed `true` \u306E\u5834\u5408\u3001\u6709\
    \u5411\u30B0\u30E9\u30D5\u3068\u3057\u3066\u69CB\u7BC9\u3059\u308B `(default =\
    \ false)`\n     */\n    Graph(int vertex_size, bool directed = false) : \n   \
    \     vertex_(vertex_size), adjacent_list_(vertex_size),\n        directed_flag_(directed){}\n\
    \n    /**\n     * @brief \u30B0\u30E9\u30D5 G \u306E\u9802\u70B9\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\u3002\n     * @return size_t \u30B0\u30E9\u30D5 G \u306E\u9802\
    \u70B9\u6570\n     */\n    size_t get_vertex_size() const {\n        return vertex_;\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5 G \u306E\u8FBA\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\u3002\n     * @return size_t \u30B0\u30E9\u30D5 G \u306E\
    \u8FBA\u6570\n     */\n    size_t get_edge_size() const {\n        return edge_;\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5 G \u306B\u5BFE\u3059\u308B\
    \u5341\u5206\u5927\u304D\u306A\u5024(`INF`)\u3092\u53D6\u5F97\u3059\u308B\u3002\
    \n     * @note `numeric_limits<CostType>::max() / 4` \u3092\u63A1\u7528\u3057\u3066\
    \u3044\u308B\u3002\n     * @return CostType `INF`\n     */\n    CostType get_inf()\
    \ const {\n        return inf_;\n    }\n\n    /**\n     * @brief 2\u9802\u70B9\
    \ `s` `t` \u9593\u306B\u91CD\u307F `c` \u306E\u8FBA\u3092\u5F35\u308B\u3002\u6709\
    \u5411\u30B0\u30E9\u30D5\u306E\u5834\u5408\u306F `s` \u304B\u3089 `t` \u3078\u306E\
    \u6709\u5411\u8FBA\u304C\u3001\u7121\u5411\u30B0\u30E9\u30D5\u306E\u5834\u5408\
    \u306F `s` `t` \u9593\u306E\u7121\u5411\u8FBA\u304C\u5F35\u3089\u308C\u308B\u3002\
    \n     * @param s \u59CB\u70B9\u306E\u9802\u70B9(\u6709\u5411\u8FBA)\n     * @param\
    \ t \u7D42\u70B9\u306E\u9802\u70B9(\u6709\u5411\u8FBA)\n     * @param c \u91CD\
    \u307F `(default = 1)`\n     */\n    void add_edge(Vertex s, Vertex t, CostType\
    \ c = 1){\n        validate(s);\n        validate(t);\n        int edge_id = edge_++;\n\
    \        adjacent_list_[s].push_back(Edge(s, t, c, edge_id));\n        if(!directed_flag_){\n\
    \            adjacent_list_[t].push_back(Edge(t, s, c, edge_id));\n        }\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u306B\u6307\u5B9A\u3057\u305F\
    \u8FBA\u6570\u306E\u60C5\u5831\u3092\u5165\u529B\u3059\u308B\u3002\n     * @note\
    \ \u5165\u529B\u5F62\u5F0F\u304C `u v w` \u307E\u305F\u306F `u v` \u306E\u5F62\
    \u5F0F\u3067\u8868\u3055\u308C\u308B\u5165\u529B\u5F62\u5F0F\u306B\u5BFE\u5FDC\
    \u3057\u3066\u3044\u308B\u3002\n     * @param edge_count \u8FBA\u6570 E\n    \
    \ * @param weighted_graph \u91CD\u307F\u4ED8\u304D\u8FBA\u3067\u3042\u308B\u304B\
    \ `(default = true)`\n     * @param one_index \u9802\u70B9\u304C1-index\u3067\u3042\
    \u308B\u304B `(default = true)`\n     */\n    void input(int edge_count, bool\
    \ weighted_graph = true, bool one_index = true){\n        for(int i = 0; i < edge_count;\
    \ ++i){\n            int s, t; cin >> s >> t;\n            if(one_index) --s,\
    \ --t;\n            CostType w = 1;\n            if(weighted_graph) cin >> w;\n\
    \            add_edge(s, t, w);\n        }\n    }\n\n    vector<ED> &operator[](Vertex\
    \ v){\n        return adjacent_list_[v];\n    }\n\n    const vector<ED> &operator[](Vertex\
    \ v) const {\n        return adjacent_list_[v];\n    }\n};\n\n/**\n * @brief \u30B0\
    \u30E9\u30D5\u306E\u96A3\u63A5\u884C\u5217\u3092\u8FD4\u3059\u3002\n * @note verify\
    \ : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_A\n *\
    \ @note \u8A08\u7B97\u91CF : O(V + E)\n * @param G \u9802\u70B9\u6570 V \u306E\
    \u30B0\u30E9\u30D5\n * @param not_adjacent_value 2\u9802\u70B9 u, v \u9593\u306B\
    \u8FBA\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u5024 `(default =\
    \ 0)`\n * @attention \u81EA\u5DF1\u30EB\u30FC\u30D7\u3084\u591A\u91CD\u8FBA\u304C\
    \u542B\u307E\u308C\u308B\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u306F\u672A\
    \u5B9A\u7FA9\n * @return vector<vector<CostType>> V \xD7 V \u306E\u96A3\u63A5\u884C\
    \u5217\n */\ntemplate<typename CostType>\nvector<vector<CostType>> convert_to_matrix(Graph<CostType>\
    \ &G, CostType not_adjacent_value = 0){\n    size_t V = G.get_vertex_size();\n\
    \    vector<vector<CostType>> ret(V, vector<CostType>(V, not_adjacent_value));\n\
    \    for(int i = 0; i < V; ++i){\n        for(Edge<CostType> &e : G[i]){\n   \
    \         ret[i][e.to] = e.cost;\n        }\n    }\n    return ret;\n}\n\n/**\n\
    \ * @brief \u30B0\u30E9\u30D5\u306E\u8FBA\u3092\u9006\u9806\u306B\u3057\u305F\u30B0\
    \u30E9\u30D5\u3092\u8FD4\u3059\u3002\n * @param G \u9802\u70B9\u6570 V \u306E\u30B0\
    \u30E9\u30D5\n * @attention \u7121\u5411\u30B0\u30E9\u30D5\u306B\u5BFE\u3059\u308B\
    \u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9\n * @return Graph<CostType> G \u306E\u8FBA\
    \u3092\u9006\u306B\u3057\u305F\u30B0\u30E9\u30D5\n */\ntemplate<typename CostType>\n\
    Graph<CostType> reverse(Graph<CostType> &G){\n    size_t V = G.get_vertex_size();\n\
    \    Graph<CostType> ret(V, true);\n    for(int i = 0; i < V; ++i){\n        for(Edge<CostType>\
    \ &e : G[i]){\n            ret.add_edge(e.to, e.from, e.cost);\n        }\n  \
    \  }\n    return ret;\n}\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u8FBA\u96C6\
    \u5408\u3092\u8FD4\u3059\u3002\n * @param G \u9802\u70B9\u6570 V \u306E\u30B0\u30E9\
    \u30D5\n * @param sorted \u8FBA\u96C6\u5408\u3092\u30B3\u30B9\u30C8\u3067\u30BD\
    \u30FC\u30C8\u3057\u305F\u72B6\u614B\u3067\u8FD4\u3059\u304B (default = true)\n\
    \ * @return vector<Edge<CostType>> G \u306E\u8FBA\u96C6\u5408\n */\ntemplate<typename\
    \ CostType>\nvector<Edge<CostType>> convert_to_edge_set(Graph<CostType> &G, bool\
    \ sorted = true){\n    vector<Edge<CostType>> ret;\n    vector<bool> picked(G.get_edge_size(),\
    \ false);\n    for(int v = 0; v < G.get_vertex_size(); ++v){\n        for(Edge<CostType>\
    \ e : G[v]){\n            if(!picked[e.id]) ret.push_back(e);\n            picked[e.id]\
    \ = true;\n        }\n    }\n    if(sorted){\n        sort(ret.begin(), ret.end(),\
    \ [&](Edge<CostType> &l, Edge<CostType> &r){\n            return l.cost < r.cost;\n\
    \        });\n    }\n    return ret;\n}\n#line 2 \"library/DataStructure/UnionFind.hpp\"\
    \n\n/**\n * @file UnionFind.hpp\n * @author log K (lX57)\n * @brief UnionFind\
    \ - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\n * @version 3.0\n * @date\
    \ 2024-04-26\n */\n\n#line 12 \"library/DataStructure/UnionFind.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename T = int>\nstruct UnionFind{\n    private:\n    vector<int>\
    \ data_;\n\n    public:\n    /**\n     * @brief \u8981\u7D20\u6570 `Size` \u3067\
    UnionFind\u3092\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Size \u8981\
    \u7D20\u6570\n     */\n    UnionFind(int Size) : data_(Size, -1){}\n\n    /**\n\
    \     * @brief \u8981\u7D20 `k` \u306E\u89AA\u3092\u8FD4\u3059\u3002\u3064\u3044\
    \u3067\u306B\u7D4C\u8DEF\u5727\u7E2E\u3092\u3059\u308B\u3002\n     * @param k\
    \ \u63A2\u7D22\u3059\u308B\u8981\u7D20\n     * @return int \u89AA\u8981\u7D20\u306E\
    \u756A\u53F7\n     */\n    int find(int k){\n        if(data_[k] < 0) return k;\n\
    \        int r = find(data_[k]);\n        return data_[k] = r;\n    }\n\n    /**\n\
    \     * @brief \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u304C\u540C\u3058\u96C6\
    \u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \u3002\n     */\n    bool same(int x, int y){\n        return find(x) == find(y);\n\
    \    }\n\n    /**\n     * @brief \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u3092\
    \u4F75\u5408\u3059\u308B\u3002\n     * @return \u4F75\u5408\u6E08\u306E\u5834\u5408\
    \u306F `false` \u3092\u8FD4\u3059\u3002\n     */\n    bool unite(int x, int y){\n\
    \        x = find(x), y = find(y);\n        if(x == y) return false;\n       \
    \ if(data_[x] > data_[y]) swap(x, y);\n        data_[x] += data_[y];\n       \
    \ data_[y] = x;\n        return true;\n    }\n\n    vector<vector<int>> group(){\n\
    \        vector<vector<int>> ret(data_.size());\n        for(int i = 0; i < data_.size();\
    \ ++i){\n            ret[find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](vector<int> &v){\n            return v.empty();\n        }), end(ret));\n\
    \        return ret;\n    }\n\n    int size(int k){\n        int v = find(k);\n\
    \        return -data_[v];\n    }\n};\n#line 10 \"library/Graph/Kruskal.hpp\"\n\
    \ntemplate<typename CostType, bool ReverseFlag = false>\nstruct Kruskal{\n   \
    \ private:\n    Graph<CostType> &G;\n    vector<int> remain_edge_id_;\n    CostType\
    \ minimum_cost_;\n\n    public:\n    /**\n     * @brief \u30B0\u30E9\u30D5\u3092\
    \u57FA\u306B\u6700\u5C0F\u5168\u57DF\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\
    \n     * @param G_ \u9802\u70B9\u6570 V \u306E\u30B0\u30E9\u30D5\n     */\n  \
    \  Kruskal(Graph<CostType> &G_) : G(G_){\n        minimum_cost_ = 0;\n       \
    \ UnionFind uf(G.get_vertex_size());\n        auto es = convert_to_edge_set(G);\n\
    \        if(ReverseFlag) reverse(es.begin(), es.end());\n        for(Edge<CostType>\
    \ &e : es){\n            int i = e.id;\n            if(uf.same(e.from, e.to))\
    \ continue;\n            uf.unite(e.from, e.to);\n            remain_edge_id_.push_back(i);\n\
    \            minimum_cost_ += e.cost;\n        }\n    }\n\n    /**\n     * @brief\
    \ \u6700\u5C0F\u5168\u57DF\u6728\u306B\u542B\u307E\u308C\u308B\u8FBA\u756A\u53F7\
    \u3092\u8FD4\u3059\u3002\n     * @note verify : https://judge.yosupo.jp/problem/minimum_spanning_tree\n\
    \     * @return vector<int>& \u8FBA\u756A\u53F7\u306E\u30D9\u30AF\u30C8\u30EB\n\
    \     */\n    vector<int> &get_edge_id(){\n        return remain_edge_id_;\n \
    \   }\n\n    /**\n     * @brief \u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\u30B9\
    \u30C8\u3092\u8FD4\u3059\u3002\n     * @note verify : https://judge.yosupo.jp/problem/minimum_spanning_tree\n\
    \     * @return CostType \u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\
    \n     */\n    CostType get_value(){\n        return minimum_cost_;\n    }\n};\n"
  code: "/**\n * @file Kruskal.hpp\n * @brief Kruskal - \u6700\u5C0F\u5168\u57DF\u6728\
    \n * @version 4.0\n * @date 2024-07-19\n */\n\n#include \"Graph.hpp\"\n#include\
    \ \"../DataStructure/UnionFind.hpp\"\n\ntemplate<typename CostType, bool ReverseFlag\
    \ = false>\nstruct Kruskal{\n    private:\n    Graph<CostType> &G;\n    vector<int>\
    \ remain_edge_id_;\n    CostType minimum_cost_;\n\n    public:\n    /**\n    \
    \ * @brief \u30B0\u30E9\u30D5\u3092\u57FA\u306B\u6700\u5C0F\u5168\u57DF\u6728\u3092\
    \u69CB\u7BC9\u3059\u308B\u3002\n     * @param G_ \u9802\u70B9\u6570 V \u306E\u30B0\
    \u30E9\u30D5\n     */\n    Kruskal(Graph<CostType> &G_) : G(G_){\n        minimum_cost_\
    \ = 0;\n        UnionFind uf(G.get_vertex_size());\n        auto es = convert_to_edge_set(G);\n\
    \        if(ReverseFlag) reverse(es.begin(), es.end());\n        for(Edge<CostType>\
    \ &e : es){\n            int i = e.id;\n            if(uf.same(e.from, e.to))\
    \ continue;\n            uf.unite(e.from, e.to);\n            remain_edge_id_.push_back(i);\n\
    \            minimum_cost_ += e.cost;\n        }\n    }\n\n    /**\n     * @brief\
    \ \u6700\u5C0F\u5168\u57DF\u6728\u306B\u542B\u307E\u308C\u308B\u8FBA\u756A\u53F7\
    \u3092\u8FD4\u3059\u3002\n     * @note verify : https://judge.yosupo.jp/problem/minimum_spanning_tree\n\
    \     * @return vector<int>& \u8FBA\u756A\u53F7\u306E\u30D9\u30AF\u30C8\u30EB\n\
    \     */\n    vector<int> &get_edge_id(){\n        return remain_edge_id_;\n \
    \   }\n\n    /**\n     * @brief \u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\u30B9\
    \u30C8\u3092\u8FD4\u3059\u3002\n     * @note verify : https://judge.yosupo.jp/problem/minimum_spanning_tree\n\
    \     * @return CostType \u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\
    \n     */\n    CostType get_value(){\n        return minimum_cost_;\n    }\n};"
  dependsOn:
  - library/Graph/Graph.hpp
  - library/DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: library/Graph/Kruskal.hpp
  requiredBy: []
  timestamp: '2024-07-29 03:16:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-MinimumSpanningTree.test.cpp
documentation_of: library/Graph/Kruskal.hpp
layout: document
redirect_from:
- /library/library/Graph/Kruskal.hpp
- /library/library/Graph/Kruskal.hpp.html
title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
---
