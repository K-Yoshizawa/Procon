---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/Tree/Tree.hpp
    title: "Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/Tree/TreeDiameter.hpp
    title: "Tree Diameter - \u6728\u306E\u76F4\u5F84"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"verify/LC-TreeDiameter.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n\n#line 1 \"library/Tree/TreeDiameter.hpp\"\n/**\n * @file TreeDiameter.hpp\n\
    \ * @brief Tree Diameter - \u6728\u306E\u76F4\u5F84\n * @version 2.0\n * @date\
    \ 2024-07-29\n */\n\n#line 2 \"library/Tree/Tree.hpp\"\n\n/**\n * @file Tree.hpp\n\
    \ * @brief Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 0.1\n\
    \ * @date 2024-07-29\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #line 2 \"library/Graph/Graph.hpp\"\n\n/**\n * @file Graph.hpp\n * @brief Graph\
    \ - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 0.1\n\
    \ * @date 2024-06-14\n */\n\n#line 11 \"library/Graph/Graph.hpp\"\nusing namespace\
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
    \        });\n    }\n    return ret;\n}\n#line 14 \"library/Tree/Tree.hpp\"\n\n\
    template<typename CostType = int32_t>\nclass Tree : public Graph<CostType>{\n\
    \    public:\n    using Graph<CostType>::Graph;\n\n    void input(bool weighted_graph\
    \ = true, bool one_index = true){\n        for(int i = 0; i < this->get_vertex_size()\
    \ - 1; ++i){\n            int s, t; cin >> s >> t;\n            if(one_index)\
    \ --s, --t;\n            CostType w = 1;\n            if(weighted_graph) cin >>\
    \ w;\n            this->add_edge(s, t, w);\n        }\n    }\n\n    void input(const\
    \ vector<Vertex> &A, const vector<Vertex> &B, const vector<CostType> &C, bool\
    \ one_index = true){\n        assert(A.size() == this->get_vertex_size() - 1);\n\
    \        assert(B.size() == this->get_vertex_size() - 1);\n        assert(C.size()\
    \ == this->get_vertex_size() - 1);\n        for(int i = 0; i < this->get_vertex_size()\
    \ - 1; ++i){\n            int s = A[i], t = B[i];\n            if(one_index) --s,\
    \ --t;\n            this->add_edge(s, t, C[i]);\n        }\n    }\n};\n\ntemplate<typename\
    \ CostType>\nstruct TreeEdge{\n    Vertex vertex;\n    CostType cost;\n    TreeEdge(Vertex\
    \ v = -1, CostType c = 1) : vertex(v), cost(c){}\n};\n\ntemplate<typename CostType\
    \ = int32_t>\nclass RootedTree{\n    private:\n    size_t vertex_size_;\n    Vertex\
    \ root_vertex_{0};\n    vector<TreeEdge<CostType>> parent_;\n    vector<vector<TreeEdge<CostType>>>\
    \ children_;\n\n    public:\n    /**\n     * @brief \u9802\u70B9\u6570 `vertex`\
    \ \u3067\u9802\u70B9 `root = 0` \u3092\u6839\u3068\u3059\u308B\u6839\u4ED8\u304D\
    \u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention `input()` \u3067\
    \u5165\u529B\u3092\u53D7\u3051\u53D6\u308B\u5F62\u5F0F\u306E\u3068\u304D\u306E\
    \u307F\u4F7F\u7528\u53EF\u80FD\n     * @param vertex \u9802\u70B9\u6570\n    \
    \ * @param root \u6839\u306E\u9802\u70B9 `(default = 0)`\n     */\n    RootedTree(int\
    \ vertex, int root = 0) : \n        vertex_size_(vertex), root_vertex_(root),\n\
    \        parent_(vertex_size_), children_(vertex_size_){}\n\n    /**\n     * @brief\
    \ \u30B0\u30E9\u30D5 `G` \u304B\u3089\u9802\u70B9 `root = 0` \u3092\u6839\u3068\
    \u3059\u308B\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n   \
    \  * @attention `G` \u306F\u6728\u3067\u306A\u304F\u3066\u306F\u306A\u3089\u306A\
    \u3044\n     * @param G \u69CB\u7BC9\u5143\u306E\u30B0\u30E9\u30D5\n     * @param\
    \ root \u6839\u306E\u9802\u70B9 `(default = 0)`\n     */\n    RootedTree(Graph<CostType>\
    \ &G, Vertex root = 0) :\n        vertex_size_(G.get_vertex_size()), root_vertex_(root),\n\
    \        parent_(vertex_size_), children_(vertex_size_){\n        auto dfs = [&](auto\
    \ self, Vertex v, Vertex p) -> void {\n            for(Edge<CostType> &e : G[v]){\n\
    \                if(e.to == p) continue;\n                parent_[e.to] = TreeEdge<CostType>(v,\
    \ e.cost);\n                children_[v].push_back(TreeEdge<CostType>(e.to, e.cost));\n\
    \                self(self, e.to, v);\n            }\n        };\n        dfs(dfs,\
    \ root_vertex_, -1);\n    }\n\n    size_t get_vertex_size() const {\n        return\
    \ vertex_size_;\n    }\n\n    Vertex get_root() const {\n        return root_vertex_;\n\
    \    }\n\n    TreeEdge<CostType> get_parent(Vertex v) const {\n        return\
    \ parent_[v];\n    }\n\n    void input(bool weighted_edge = false, bool one_index\
    \ = true){\n        for(Vertex v = 1; v < vertex_size_; ++v){\n            Vertex\
    \ p; cin >> p;\n            if(one_index) --p;\n            CostType c = 1;\n\
    \            if(weighted_edge) cin >> c;\n            parent_[v] = TreeEdge<CostType>(p,\
    \ c);\n            children_[p].push_back(TreeEdge<CostType>(v, c));\n       \
    \ }\n    }\n\n    vector<TreeEdge<CostType>> &operator[](Vertex v){\n        return\
    \ children_[v];\n    }\n\n    const vector<TreeEdge<CostType>> &operator[](Vertex\
    \ v) const {\n        return children_[v];\n    }\n};\n\ntemplate<typename CostType>\n\
    vector<int> calculate_subtree_size(RootedTree<CostType> &T){\n    vector<int>\
    \ ret(T.get_vertex_size(), 1);\n    auto dfs = [&](auto self, Vertex v) -> void\
    \ {\n        for(TreeEdge<CostType> &e : T[v]){\n            self(self, e.vertex);\n\
    \            ret[v] += ret[e.vertex];\n        }\n        return;\n    };\n  \
    \  dfs(dfs, T.get_root());\n    return ret;\n}\n\ntemplate<typename CostType>\n\
    vector<int> calculate_depth(RootedTree<CostType> &T){\n    vector<int> ret(T.get_vertex_size(),\
    \ 0);\n    auto dfs = [&](auto self, Vertex v) -> void {\n        for(TreeEdge<CostType>\
    \ &e : T[v]){\n            ret[e.vertex] = ret[v] + 1;\n            self(self,\
    \ e.vertex);\n        }\n        return;\n    };\n    dfs(dfs, T.get_root());\n\
    \    return ret;\n}\n#line 9 \"library/Tree/TreeDiameter.hpp\"\n\ntemplate<typename\
    \ CostType>\nclass TreeDiameter{\n    private:\n    Tree<CostType> &T;\n    vector<Vertex>\
    \ diameter_path_;\n    CostType diameter_cost_;\n    vector<CostType> branch_cost_;\n\
    \    \n    void build(){\n        // \u76F4\u5F84\u69CB\u7BC9\u30D1\u30FC\u30C8\
    \n        vector<CostType> dist(T.get_vertex_size(), 0);\n        vector<Vertex>\
    \ parent(T.get_vertex_size(), -1);\n        auto dfs1 = [&](auto self, Vertex\
    \ current_vertex, Vertex prev_vertex) -> void {\n            for(Edge<CostType>\
    \ &e : T[current_vertex]){\n                if(e.to == prev_vertex) continue;\n\
    \                dist[e.to] = dist[current_vertex] + e.cost;\n               \
    \ parent[e.to] = current_vertex;\n                self(self, e.to, current_vertex);\n\
    \            }\n        };\n        Vertex start = 0;\n        dfs1(dfs1, start,\
    \ -1);\n        start = distance(dist.begin(), max_element(dist.begin(), dist.end()));\n\
    \        dist.assign(T.get_vertex_size(), 0);\n        parent.assign(T.get_vertex_size(),\
    \ -1);\n        dfs1(dfs1, start, -1);\n        auto itr = max_element(dist.begin(),\
    \ dist.end());\n        diameter_cost_ = *itr;\n        vector<bool> included_diameter(T.get_vertex_size(),\
    \ false);\n        Vertex current = distance(dist.begin(), itr);\n        diameter_path_.push_back(current);\n\
    \        included_diameter[current] = true;\n        while(parent[current] !=\
    \ -1){\n            current = parent[current];\n            diameter_path_.push_back(current);\n\
    \            included_diameter[current] = true;\n        }\n\n        // \u679D\
    \u69CB\u7BC9\u30D1\u30FC\u30C8\n        branch_cost_.resize(T.get_vertex_size(),\
    \ 0);\n        auto dfs2 = [&](auto self, Vertex current_vertex, Vertex prev_vertex)\
    \ -> void {\n            for(Edge<CostType> &e : T[current_vertex]){\n       \
    \         if(e.to == prev_vertex) continue;\n                if(included_diameter[e.to])\
    \ continue;\n                branch_cost_[e.to] = branch_cost_[current_vertex]\
    \ + e.cost;\n                self(self, e.to, current_vertex);\n            }\n\
    \        };\n        for(auto &v : diameter_path_){\n            dfs2(dfs2, v,\
    \ -1);\n        }\n    }\n\n    public:\n    TreeDiameter(Tree<CostType> &T) :\
    \ T(T){\n        build();\n    }\n\n    vector<Vertex> &get_path(){\n        return\
    \ diameter_path_;\n    }\n\n    pair<Vertex, Vertex> get_endpoints() const {\n\
    \        return {diameter_path_.front(), diameter_path_.back()};\n    }\n\n  \
    \  CostType get_cost() const {\n        return diameter_cost_;\n    }\n\n    vector<CostType>\
    \ &get_branch_cost(){\n        return branch_cost_;\n    }\n};\n#line 4 \"verify/LC-TreeDiameter.test.cpp\"\
    \n\nint main(){\n    int N; cin >> N;\n    Tree<int64_t> T(N);\n    T.input(true,\
    \ false);\n\n    TreeDiameter td(T);\n    auto ans = td.get_path();\n    cout\
    \ << td.get_cost() << \" \" << ans.size() << endl;\n    for(auto v : ans){\n \
    \       cout << v << \" \";\n    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../library/Tree/TreeDiameter.hpp\"\n\nint main(){\n    int N; cin >> N;\n\
    \    Tree<int64_t> T(N);\n    T.input(true, false);\n\n    TreeDiameter td(T);\n\
    \    auto ans = td.get_path();\n    cout << td.get_cost() << \" \" << ans.size()\
    \ << endl;\n    for(auto v : ans){\n        cout << v << \" \";\n    }\n    cout\
    \ << endl;\n}"
  dependsOn:
  - library/Tree/TreeDiameter.hpp
  - library/Tree/Tree.hpp
  - library/Graph/Graph.hpp
  isVerificationFile: true
  path: verify/LC-TreeDiameter.test.cpp
  requiredBy: []
  timestamp: '2024-07-29 03:11:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-TreeDiameter.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-TreeDiameter.test.cpp
- /verify/verify/LC-TreeDiameter.test.cpp.html
title: verify/LC-TreeDiameter.test.cpp
---
