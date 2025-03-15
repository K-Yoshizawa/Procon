---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-5-B.test.cpp
    title: verify/AOJ-GRL-5-B.test.cpp
  - icon: ':x:'
    path: verify/LC-TreePathCompositeSum.test.cpp
    title: verify/LC-TreePathCompositeSum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Rerooting DP - \u5168\u65B9\u4F4D\u6728 DP"
    links: []
  bundledCode: "#line 1 \"Library/Tree/RerootingDP.hpp\"\n/**\n * @file RerootingDP.hpp\n\
    \ * @brief Rerooting DP - \u5168\u65B9\u4F4D\u6728 DP\n * @version 1.0\n * @date\
    \ 2024-09-03\n */\n\n#line 2 \"Library/Tree/Tree.hpp\"\n\n/**\n * @file Tree.hpp\n\
    \ * @brief Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 1.0\n\
    \ * @date 2024-09-02\n */\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n\
    \ */\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n#line 11 \"Library/Tree/Tree.hpp\"\
    \n\nusing Vertex = int;\n\ntemplate<typename CostType = int32_t>\nclass RootedTree{\n\
    \    public:\n    struct Node{\n        Node(Vertex parent = -1) : parent(parent){}\n\
    \n        Vertex parent{-1};\n        CostType cost{};\n        vector<Vertex>\
    \ children{};\n    };\n\n    /**\n     * @brief \u9802\u70B9 `root_vertex` \u3092\
    \u6839\u3068\u3059\u308B\u9802\u70B9\u6570 `vertex_size` \u306E\u6839\u4ED8\u304D\
    \u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @note \u6839\u304C\u5165\u529B\
    \u3067\u4E0E\u3048\u3089\u308C\u306A\u308C\u306A\u3044\u304C\u5F8C\u3067\u5206\
    \u304B\u308B\u3001\u307F\u305F\u3044\u306A\u72B6\u6CC1\u306E\u6642\u306F `root_vertex\
    \ = -1` \u3068\u3059\u308B\u3068\u3088\u3044\n     * @param vertex_size \u9802\
    \u70B9\u6570\n     * @param root_vertex \u6839\u3068\u3059\u308B\u9802\u70B9 (default\
    \ = 0)\n     */\n    RootedTree(int vertex_size = 0, Vertex root_vertex = 0) :\n\
    \            vertex_size_(vertex_size), root_vertex_(root_vertex),\n         \
    \   node_(vertex_size){}\n\n    /**\n     * @brief \u6728\u306E\u9802\u70B9\u6570\
    \u3092\u8FD4\u3059\u3002\n     * @return int \u6728\u306E\u9802\u70B9\u6570\n\
    \     */\n    int get_vertex_size() const {\n        return vertex_size_;\n  \
    \  }\n\n    /**\n     * @brief \u6728\u306E\u6839\u306E\u9802\u70B9\u3092\u8FD4\
    \u3059\u3002\n     * @return Vertex \u6728\u306E\u6839\u306E\u9802\u70B9\u756A\
    \u53F7 (0-index)\n     */\n    Vertex get_root() const {\n        return root_vertex_;\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E\u89AA\u306E\u9802\u70B9\
    \u756A\u53F7\u3092\u8FD4\u3059\u3002\n     * @note `v` \u304C\u6839\u306E\u5834\
    \u5408\u3001`-1` \u304C\u8FD4\u3055\u308C\u308B\u3002\n     * @param v \u5B50\u306E\
    \u9802\u70B9\u756A\u53F7 (0-index)\n     * @return Vertex \u89AA\u306E\u9802\u70B9\
    \u756A\u53F7 (0-index)\n     */\n    Vertex get_parent(Vertex v) const {\n   \
    \     Validate(v);\n        return node_[v].parent;\n    }\n\n    /**\n     *\
    \ @brief \u9802\u70B9 `v` \u306E\u5B50\u306E\u9802\u70B9\u756A\u53F7\u5217\u3092\
    \u8FD4\u3059\u3002\n     * @note \u9802\u70B9\u756A\u53F7\u5217\u306F\u5165\u529B\
    \u9806\u306B\u8FD4\u3055\u308C\u308B\u3002\n     * @param v \u89AA\u306E\u9802\
    \u70B9\u756A\u53F7 (0-index)\n     * @return vector<Vertex> \u5B50\u306E\u9802\
    \u70B9\u756A\u53F7\u5217 (0-index)\n     */\n    vector<Vertex> &get_child(Vertex\
    \ v){\n        Validate(v);\n        return node_[v].children;\n    }\n\n    /**\n\
    \     * @brief \u9802\u70B9 `v` \u3068\u305D\u306E\u89AA\u3092\u7D50\u3076\u8FBA\
    \u306E\u91CD\u307F\u3092\u8FD4\u3059\u3002\n     * @attention `v` \u304C\u6839\
    \u306E\u5834\u5408\u306E\u8FD4\u308A\u5024\u306F\u672A\u5B9A\u7FA9\u3067\u3042\
    \u308B\u3002\n     * @param v \u9802\u70B9\u756A\u53F7 (0-index)\n     * @return\
    \ CostType \u8FBA\u306E\u91CD\u307F\n     */\n    CostType get_cost(Vertex v){\n\
    \        Validate(v);\n        return node_[v].cost;\n    }\n\n    /**\n     *\
    \ @brief \u9802\u70B9 `parent` \u304B\u3089\u9802\u70B9 `child` \u3078\u306E\u91CD\
    \u3055 `cost` \u306E\u8FBA\u3092\u5F35\u308B\u3002\n     * @note `cost` \u3092\
    \u7701\u7565\u3059\u308B\u3053\u3068\u3067\u91CD\u307F\u306A\u3057\u8FBA\u3092\
    \u5F35\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\n     * @param parent \u89AA\
    \u306E\u9802\u70B9\u756A\u53F7 (0-index)\n     * @param child \u5B50\u306E\u9802\
    \u70B9\u756A\u53F7 (0-index)\n     * @param cost \u8FBA\u306E\u91CD\u307F (default\
    \ = 1)\n     */\n    void AddEdge(Vertex parent, Vertex child, CostType cost =\
    \ 1){\n        Validate(parent);\n        Validate(child);\n        node_[parent].children.push_back(child);\n\
    \        node_[child].parent = parent;\n        node_[child].cost = cost;\n  \
    \  }\n\n    /**\n     * @brief `u v w` \u306E\u3088\u3046\u306A\u5165\u529B\u5F62\
    \u5F0F\u3092\u53D7\u3051\u53D6\u308B\u3002\n     * @param weighted \u91CD\u307F\
    \u4ED8\u304D\u306E\u6728\u3067\u3042\u308B\u304B (default = true)\n     * @param\
    \ one_index \u5165\u529B\u3055\u308C\u308B\u9802\u70B9\u756A\u53F7\u304C 1-index\
    \ \u304B\u3069\u3046\u304B (default = true)\n     */\n    void InputGraphFormat(bool\
    \ weighted = true, bool one_index = true){\n        vector<vector<pair<Vertex,\
    \ CostType>>> graph(vertex_size_);\n        for(int i = 0; i < vertex_size_ -\
    \ 1; ++i){\n            int u, v; cin >> u >> v;\n            if(one_index) --u,\
    \ --v;\n            CostType w = 1;\n            if(weighted) cin >> w;\n    \
    \        graph[u].emplace_back(v, w);\n            graph[v].emplace_back(u, w);\n\
    \        }\n        auto rec = [&](auto self, Vertex v, Vertex p) -> void {\n\
    \            for(auto [u, w] : graph[v]){\n                if(u == p) continue;\n\
    \                AddEdge(v, u, w);\n                self(self, u, v);\n      \
    \      }\n        };\n        rec(rec, root_vertex_, -1);\n    }\n\n    /**\n\
    \     * @brief `p_1 p_2 ... p_N` \u306E\u3088\u3046\u306A\u5165\u529B\u5F62\u5F0F\
    \u3092\u53D7\u3051\u53D6\u308B\u3002\n     * @attention weighted \u306E\u51E6\u7406\
    \u3092\u66F8\u3044\u3066\u3044\u306A\u3044\u306E\u3067\u3001`weighted` \u306E\u30D1\
    \u30E9\u30E1\u30FC\u30BF\u306B\u610F\u5473\u306F\u306A\u3044\n     * @param weighted\
    \ \u91CD\u307F\u4ED8\u304D\u306E\u6728\u3067\u3042\u308B\u304B (default = true)\n\
    \     * @param one_index \u5165\u529B\u3055\u308C\u308B\u9802\u70B9\u756A\u53F7\
    \u304C 1-index \u304B\u3069\u3046\u304B (default = true)\n     */\n    void InputRootedTreeFormat(bool\
    \ weighted = true, bool one_index = true){\n        assert(root_vertex_ == 0);\n\
    \        for(int i = 1; i < vertex_size_; ++i){\n            int p; cin >> p;\n\
    \            if(one_index) --p;\n            AddEdge(p, i);\n        }\n    }\n\
    \n    /**\n     * @brief \u9802\u70B9 `v` \u304C\u6839\u306E\u9802\u70B9\u304B\
    \u5224\u5B9A\u3059\u308B\u3002\n     * @param v \u5224\u5B9A\u3059\u308B\u9802\
    \u70B9\u756A\u53F7 (0-index)\n     */\n    bool RootVertex(Vertex v){\n      \
    \  Validate(v);\n        return node_[v].parent == -1;\n    }\n    \n    /**\n\
    \     * @brief \u9802\u70B9 `v` \u304C\u8449\u306E\u9802\u70B9\u304B\u5224\u5B9A\
    \u3059\u308B\u3002\n     * @param v \u5224\u5B9A\u3059\u308B\u9802\u70B9\u756A\
    \u53F7 (0-index)\n     */\n    bool LeafVertex(Vertex v){\n        Validate(v);\n\
    \        return node_[v].children.empty();\n    }\n\n    /**\n     * @brief \u6728\
    \u306E\u6839\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\u3002\n     * @attention\
    \ \u57FA\u672C\u7684\u306B\u306F\u4E0D\u8981\u3067\u3001\u6839\u306E\u9802\u70B9\
    \u756A\u53F7\u304C\u4E0E\u3048\u3089\u308C\u3066\u3044\u306A\u3044\u5834\u5408\
    \u306B\u7528\u3044\u308B\u3002\n     * @note Verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A\n\
    \     * @return Vertex \u6839\u306E\u9802\u70B9\u756A\u53F7\n     */\n    Vertex\
    \ FindRoot(){\n        for(int i = 0; i < vertex_size_; ++i){\n            if(RootVertex(i)){\n\
    \                root_vertex_ = i;\n                return i;\n            }\n\
    \        }\n        assert(false);\n    }\n\n    /**\n     * @brief \u6728\u306E\
    \u6839\u3092\u5909\u66F4\u3057\u3066\u518D\u69CB\u7BC9\u3059\u308B\u3002\n   \
    \  * @param root \u65B0\u3057\u3044\u6839\u306E\u9802\u70B9\u756A\u53F7 (0-index)\n\
    \     */\n    void Rerooting(Vertex root){\n        if(root == root_vertex_) return;\n\
    \        vector<Node> new_node_(vertex_size_);\n        auto rec = [&](auto self,\
    \ Vertex v, Vertex p, CostType c) -> void {\n            new_node_[v].parent =\
    \ p;\n            new_node_[v].cost = c;\n            if(node_[v].parent != p\
    \ && node_[v].parent != -1){\n                new_node_[v].children.push_back(node_[v].parent);\n\
    \                self(self, node_[v].parent, v, node_[v].cost);\n            }\n\
    \            for(Vertex u : node_[v].children){\n                if(u != p){\n\
    \                    new_node_[v].children.push_back(u);\n                   \
    \ self(self, u, v, node_[u].cost);\n                }\n            }\n       \
    \ };\n        rec(rec, root, -1, 0);\n        swap(new_node_, node_);\n      \
    \  root_vertex_ = root;\n    }\n\n    void Print(bool one_index = true) const\
    \ {\n        for(int i = 0; i < vertex_size_; ++i){\n            // fprintf(stderr,\
    \ \"# Vertex %d : parent = %d (cost = %d), children = [\", i + int(one_index),\
    \ get_parent(i) + int(one_index), node_[i].cost);\n            fprintf(stderr,\
    \ \"# Vertex %d : parent = %d (cost = \", i + int(one_index), get_parent(i) +\
    \ int(one_index));\n            cerr << node_[i].cost;\n            fprintf(stderr,\
    \ \"), children = [\");\n            for(int j = 0; j < node_[i].children.size();\
    \ ++j){\n                fprintf(stderr, \"%d\", node_[i].children[j] + int(one_index));\n\
    \                if(j + 1 < node_[i].children.size()){\n                    fprintf(stderr,\
    \ \", \");\n                }\n            }\n            fprintf(stderr, \"]\\\
    n\");\n        }\n    }\n\n    private:\n    inline void Validate(Vertex v) const\
    \ {\n        assert(0 <= v && v < vertex_size_);\n    }\n\n    int vertex_size_,\
    \ root_vertex_{-1};\n    vector<Node> node_;\n};\n\n/**\n * @brief \u6728 `tree`\
    \ \u306E\u5404\u9802\u70B9\u306E\u6DF1\u3055\u3092\u6C42\u3081\u308B\u3002\n *\
    \ @note \u6839\u306E\u9802\u70B9\u306F\u6DF1\u3055 0 \u3067\u3042\u308B\u3002\n\
    \ * @note Verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A\n\
    \ * @param tree \u6728\n * @param root \u6839\u306E\u9802\u70B9\u756A\u53F7 (default\
    \ = 0)\n * @return vector<int> \u5404\u9802\u70B9\u306E\u6DF1\u3055\n */\ntemplate<typename\
    \ CostType>\nvector<int> CalculateTreeDepth(RootedTree<CostType> &tree){\n   \
    \ int V = tree.get_vertex_size();\n    vector<int> ret(V, 0);\n    auto rec =\
    \ [&](auto self, Vertex v, int d) -> void {\n        ret[v] = d;\n        for(Vertex\
    \ u : tree.get_child(v)){\n            self(self, u, d + 1);\n        }\n    };\n\
    \    Vertex root = tree.get_root();\n    if(root < 0) root = tree.FindRoot();\n\
    \    rec(rec, root, 0);\n    return ret;\n}\n\n/**\n * @brief \u6728\u306E\u6839\
    \u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u8FBA\u306E\u91CD\u307F\u306E\u7D2F\
    \u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\u3002\n * @param tree \u6728\n * @return\
    \ vector<CostType> \u6839\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u91CD\u307F\
    \u306E\u7D2F\u7A4D\u548C\n */\ntemplate<typename CostType>\nvector<CostType> CalculateTreeCumlativeSum(RootedTree<CostType>\
    \ &tree){\n    Vertex root = tree.get_root();\n    int V = tree.get_vertex_size();\n\
    \    vector<CostType> ret(V, 0);\n    auto rec = [&](auto self, Vertex v, CostType\
    \ s) -> void {\n        ret[v] = s + tree.get_cost(v);\n        for(Vertex u :\
    \ tree.get_child(v)){\n            self(self, u, ret[v]);\n        }\n    };\n\
    \    rec(rec, root, 0);\n    return ret;\n}\n\n/**\n * @brief \u5404\u9802\u70B9\
    \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u3092\
    \u6C42\u3081\u308B\u3002\n * @param tree \u6728\n * @return vector<int> \u5404\
    \u9802\u70B9\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\
    \u30BA\n */\ntemplate<typename CostType>\nvector<int> CalculateSubtreeSize(RootedTree<CostType>\
    \ &tree){\n    Vertex root = tree.get_root();\n    int V = tree.get_vertex_size();\n\
    \    vector<int> ret(V, 1);\n    auto rec = [&](auto self, Vertex v) -> int {\n\
    \        for(Vertex u : tree.get_child(v)){\n            ret[v] += self(self,\
    \ u);\n        }\n        return ret[v];\n    };\n    rec(rec, root);\n    return\
    \ ret;\n}\n\n/**\n * @brief \u5404\u9802\u70B9\u3092\u884C\u304D\u304B\u3051\u9806\
    \u306B\u4E26\u3079\u305F\u3068\u304D\u306B\u4F55\u756A\u76EE\u306B\u76F8\u5F53\
    \u3059\u308B\u304B\u306E\u914D\u5217\u3092\u6C42\u3081\u308B\u3002\n * @param\
    \ tree \u6728\n * @return vector<int> \u5404\u9802\u70B9\u304C\u884C\u304D\u304B\
    \u3051\u9806\u3067\u4F55\u756A\u76EE\u306B\u306A\u308B\u304B (0-index)\n */\n\
    template<typename CostType>\nvector<int> CalculatePreOrder(RootedTree<CostType>\
    \ &tree){\n    Vertex root = tree.get_root();\n    int V = tree.get_vertex_size(),\
    \ time_stamp = 0;\n    vector<int> ret(V, -1);\n    auto rec = [&](auto self,\
    \ Vertex v) -> void {\n        ret[v] = time_stamp++;\n        for(Vertex u :\
    \ tree.get_child()){\n            self(self, u);\n        }\n    };\n    rec(rec,\
    \ root);\n    return ret;\n}\n#line 9 \"Library/Tree/RerootingDP.hpp\"\n\ntemplate<typename\
    \ CostType, typename Monoid>\nclass RerootingDP{\n    public:\n    using F = function<Monoid(Monoid,\
    \ Monoid, Vertex)>;\n    using G = function<Monoid(Monoid, CostType, Vertex)>;\n\
    \    using H = function<Monoid(Monoid, Vertex)>;\n    using Fsub = function<Monoid(Monoid,\
    \ Monoid)>;\n    using Gsub = function<Monoid(Monoid, CostType)>;\n\n    /**\n\
    \     * @brief \u6728 `tree` \u306B\u5BFE\u3057\u3066\u5168\u65B9\u4F4D\u6728\
    DP\u3092\u884C\u3046\u3002(\u8FBA\u5C5E\u6027\u306E\u307F)\n     * @param tree\
    \ \u6839\u4ED8\u304D\u6728\n     * @param merge `(Monoid, Monoid) -> Monoid` :\
    \ `Monoid` \u540C\u58EB\u306B\u95A2\u3059\u308B\u4E8C\u9805\u6F14\u7B97\u3002\n\
    \     * @param add `(Monoid, CostType) -> Monoid` : `Monoid` \u3068 `CostType`\
    \ \u306B\u95A2\u3059\u308B\u4E8C\u9805\u6F14\u7B97\u3002\n     * @param monoid_identity\
    \ `Monoid` \u306E\u5358\u4F4D\u5143\u3002\n     */\n    RerootingDP(RootedTree<CostType>\
    \ &tree, Fsub merge, Gsub add, const Monoid monoid_identity) :\n            tree_(tree),\
    \ V(tree.get_vertex_size()), merge_sub_(merge), add_sub_(add), id_(monoid_identity){\n\
    \        merge_ = [&](Monoid x, Monoid y, Vertex i){return merge_sub_(x, y);};\n\
    \        add_ = [&](Monoid x, CostType y, Vertex i){return add_sub_(x, y);};\n\
    \        finalize_ = [](Monoid x, Vertex i){return x;};\n        solve();\n  \
    \  }\n\n    /**\n     * @brief \u6728 `tree` \u306B\u5BFE\u3057\u3066\u5168\u65B9\
    \u4F4D\u6728DP\u3092\u884C\u3046\u3002(\u9802\u70B9\u5C5E\u6027\u3092\u542B\u3080\
    )\n     * @param tree \u6839\u4ED8\u304D\u6728\n     * @param merge `(Monoid,\
    \ Monoid, Vertex) -> Monoid` : `Monoid` \u540C\u58EB\u306B\u95A2\u3059\u308B\u4E8C\
    \u9805\u6F14\u7B97\u3002\n     * @param add `(Monoid, CostType, Vertex) -> Monoid`\
    \ : `Monoid` \u3068 `CostType` \u306B\u95A2\u3059\u308B\u4E8C\u9805\u6F14\u7B97\
    \u3002\n     * @param finalize `(Monoid, Vertex) -> Monoid` : `Monoid` \u306B\u9802\
    \u70B9 `Vertex` \u304C\u6839\u306E\u3068\u304D\u306E\u51E6\u7406\u3002\n     *\
    \ @param monoid_identity `Monoid` \u306E\u5358\u4F4D\u5143\u3002\n     */\n  \
    \  RerootingDP(RootedTree<CostType> &tree, F merge, G add, H finalize, const Monoid\
    \ monoid_identity) :\n            tree_(tree), V(tree.get_vertex_size()), merge_(merge),\
    \ add_(add), finalize_(finalize), id_(monoid_identity){\n        solve();\n  \
    \  }\n\n    /**\n     * @brief \u5168\u9802\u70B9\u306B\u95A2\u3059\u308BDP\u306E\
    \u914D\u5217\u3092\u53D6\u5F97\u3059\u308B\u3002\n     */\n    vector<Monoid>\
    \ &get_all_answer(){\n        return dp_;\n    }\n\n    Monoid operator[](Vertex\
    \ v){\n        return dp_[v];\n    }\n\n    const Monoid operator[](Vertex v)\
    \ const {\n        return dp_[v];\n    }\n\n    void Print() const {\n       \
    \ cerr << \"# dp table :\";\n        for(int i = 0; i < V; ++i){\n           \
    \ cerr << \" \" << dp_[i];\n        }\n        cerr << endl;\n        cerr <<\
    \ \"# subtree_dp table\" << endl;\n        for(int i = 0; i < V; ++i){\n     \
    \       cerr << \"# vertex \" << i << endl;\n            cerr << \"#    subtree_dp\
    \ :\";\n            for(int j = 0; j < subtree_dp_[i].size(); ++j){\n        \
    \        cerr << \" \" << subtree_dp_[i][j];\n            }\n            cerr\
    \ << endl;\n            cerr << \"#    left_cum   :\";\n            for(int j\
    \ = 0; j < left_cum_[i].size(); ++j){\n                cerr << \" \" << left_cum_[i][j];\n\
    \            }\n            cerr << endl;\n            cerr << \"#    right_cum\
    \  :\";\n            for(int j = 0; j < right_cum_[i].size(); ++j){\n        \
    \        cerr << \" \" << right_cum_[i][j];\n            }\n            cerr <<\
    \ endl;\n        }\n    }\n\n    private:\n    RootedTree<CostType> &tree_;\n\n\
    \    Monoid dfs(Vertex v, bool root = false){\n        Monoid ret = id_;\n   \
    \     for(auto u : tree_.get_child(v)){\n            Monoid res = dfs(u);\n  \
    \          subtree_dp_[v].push_back(res);\n            ret = merge_(ret, res,\
    \ v);\n        }\n        if(root) ret = finalize_(ret, v);\n        else ret\
    \ = add_(ret, tree_.get_cost(v), v);\n        return ret;\n    }\n\n    void solve(){\n\
    \        dp_.resize(V, id_);\n        subtree_dp_.resize(V, vector<Monoid>{id_});\n\
    \        left_cum_.resize(V);\n        right_cum_.resize(V);\n        Vertex root\
    \ = tree_.get_root();\n\n        dp_[root] = dfs(root, true);\n        int root_size\
    \ = subtree_dp_[root].size();\n        left_cum_[root].resize(root_size + 1);\n\
    \        left_cum_[root].front() = id_;\n        for(int i = 1; i < root_size;\
    \ ++i){\n            left_cum_[root][i] = merge_(left_cum_[root][i - 1], subtree_dp_[root][i],\
    \ root);\n        }\n        right_cum_[root].resize(root_size + 1);\n       \
    \ right_cum_[root].back() = id_;\n        for(int i = root_size - 1; i - 1 >=\
    \ 0; --i){\n            right_cum_[root][i] = merge_(right_cum_[root][i + 1],\
    \ subtree_dp_[root][i], root);\n        }\n\n        queue<tuple<int, int, int>>\
    \ que;\n        for(int i = 0; i < tree_.get_child(root).size(); ++i){\n     \
    \       que.push({tree_.get_child(root)[i], root, i + 1});\n        }\n      \
    \  while(que.size()){\n            auto [v, p, idx] = que.front(); que.pop();\n\
    \            Monoid ret = id_;\n            ret = merge_(ret, left_cum_[p][idx\
    \ - 1], v);\n            ret = merge_(ret, right_cum_[p][idx + 1], v);\n     \
    \       ret = add_(ret, tree_.get_cost(v), p);\n            subtree_dp_[v].push_back(ret);\n\
    \            for(int i = 1; i + 1 < subtree_dp_[v].size(); ++i){\n           \
    \     ret = merge_(ret, subtree_dp_[v][i], v);\n            }\n            dp_[v]\
    \ = finalize_(ret, v);\n            int c = subtree_dp_[v].size();\n         \
    \   left_cum_[v].resize(c + 1);\n            left_cum_[v][0] = id_;\n        \
    \    for(int i = 1; i < c; ++i){\n                left_cum_[v][i] = merge_(left_cum_[v][i\
    \ - 1], subtree_dp_[v][i], v);\n            }\n            right_cum_[v].resize(c\
    \ + 1);\n            right_cum_[v].back() = id_;\n            for(int i = c -\
    \ 1; i - 1 >= 0; --i){\n                right_cum_[v][i] = merge_(right_cum_[v][i\
    \ + 1], subtree_dp_[v][i], v);\n            }\n            for(int i = 0; i <\
    \ tree_.get_child(v).size(); ++i){\n                que.push({tree_.get_child(v)[i],\
    \ v, i + 1});\n            }\n        }\n    }\n    \n    int V;\n    vector<Monoid>\
    \ dp_;\n    vector<vector<Monoid>> subtree_dp_, left_cum_, right_cum_;\n\n   \
    \ const Monoid id_;\n\n    F merge_;\n    G add_;\n    H finalize_;\n    const\
    \ Fsub merge_sub_;\n    const Gsub add_sub_;\n};\n"
  code: "/**\n * @file RerootingDP.hpp\n * @brief Rerooting DP - \u5168\u65B9\u4F4D\
    \u6728 DP\n * @version 1.0\n * @date 2024-09-03\n */\n\n#include \"Tree.hpp\"\n\
    \ntemplate<typename CostType, typename Monoid>\nclass RerootingDP{\n    public:\n\
    \    using F = function<Monoid(Monoid, Monoid, Vertex)>;\n    using G = function<Monoid(Monoid,\
    \ CostType, Vertex)>;\n    using H = function<Monoid(Monoid, Vertex)>;\n    using\
    \ Fsub = function<Monoid(Monoid, Monoid)>;\n    using Gsub = function<Monoid(Monoid,\
    \ CostType)>;\n\n    /**\n     * @brief \u6728 `tree` \u306B\u5BFE\u3057\u3066\
    \u5168\u65B9\u4F4D\u6728DP\u3092\u884C\u3046\u3002(\u8FBA\u5C5E\u6027\u306E\u307F\
    )\n     * @param tree \u6839\u4ED8\u304D\u6728\n     * @param merge `(Monoid,\
    \ Monoid) -> Monoid` : `Monoid` \u540C\u58EB\u306B\u95A2\u3059\u308B\u4E8C\u9805\
    \u6F14\u7B97\u3002\n     * @param add `(Monoid, CostType) -> Monoid` : `Monoid`\
    \ \u3068 `CostType` \u306B\u95A2\u3059\u308B\u4E8C\u9805\u6F14\u7B97\u3002\n \
    \    * @param monoid_identity `Monoid` \u306E\u5358\u4F4D\u5143\u3002\n     */\n\
    \    RerootingDP(RootedTree<CostType> &tree, Fsub merge, Gsub add, const Monoid\
    \ monoid_identity) :\n            tree_(tree), V(tree.get_vertex_size()), merge_sub_(merge),\
    \ add_sub_(add), id_(monoid_identity){\n        merge_ = [&](Monoid x, Monoid\
    \ y, Vertex i){return merge_sub_(x, y);};\n        add_ = [&](Monoid x, CostType\
    \ y, Vertex i){return add_sub_(x, y);};\n        finalize_ = [](Monoid x, Vertex\
    \ i){return x;};\n        solve();\n    }\n\n    /**\n     * @brief \u6728 `tree`\
    \ \u306B\u5BFE\u3057\u3066\u5168\u65B9\u4F4D\u6728DP\u3092\u884C\u3046\u3002(\u9802\
    \u70B9\u5C5E\u6027\u3092\u542B\u3080)\n     * @param tree \u6839\u4ED8\u304D\u6728\
    \n     * @param merge `(Monoid, Monoid, Vertex) -> Monoid` : `Monoid` \u540C\u58EB\
    \u306B\u95A2\u3059\u308B\u4E8C\u9805\u6F14\u7B97\u3002\n     * @param add `(Monoid,\
    \ CostType, Vertex) -> Monoid` : `Monoid` \u3068 `CostType` \u306B\u95A2\u3059\
    \u308B\u4E8C\u9805\u6F14\u7B97\u3002\n     * @param finalize `(Monoid, Vertex)\
    \ -> Monoid` : `Monoid` \u306B\u9802\u70B9 `Vertex` \u304C\u6839\u306E\u3068\u304D\
    \u306E\u51E6\u7406\u3002\n     * @param monoid_identity `Monoid` \u306E\u5358\u4F4D\
    \u5143\u3002\n     */\n    RerootingDP(RootedTree<CostType> &tree, F merge, G\
    \ add, H finalize, const Monoid monoid_identity) :\n            tree_(tree), V(tree.get_vertex_size()),\
    \ merge_(merge), add_(add), finalize_(finalize), id_(monoid_identity){\n     \
    \   solve();\n    }\n\n    /**\n     * @brief \u5168\u9802\u70B9\u306B\u95A2\u3059\
    \u308BDP\u306E\u914D\u5217\u3092\u53D6\u5F97\u3059\u308B\u3002\n     */\n    vector<Monoid>\
    \ &get_all_answer(){\n        return dp_;\n    }\n\n    Monoid operator[](Vertex\
    \ v){\n        return dp_[v];\n    }\n\n    const Monoid operator[](Vertex v)\
    \ const {\n        return dp_[v];\n    }\n\n    void Print() const {\n       \
    \ cerr << \"# dp table :\";\n        for(int i = 0; i < V; ++i){\n           \
    \ cerr << \" \" << dp_[i];\n        }\n        cerr << endl;\n        cerr <<\
    \ \"# subtree_dp table\" << endl;\n        for(int i = 0; i < V; ++i){\n     \
    \       cerr << \"# vertex \" << i << endl;\n            cerr << \"#    subtree_dp\
    \ :\";\n            for(int j = 0; j < subtree_dp_[i].size(); ++j){\n        \
    \        cerr << \" \" << subtree_dp_[i][j];\n            }\n            cerr\
    \ << endl;\n            cerr << \"#    left_cum   :\";\n            for(int j\
    \ = 0; j < left_cum_[i].size(); ++j){\n                cerr << \" \" << left_cum_[i][j];\n\
    \            }\n            cerr << endl;\n            cerr << \"#    right_cum\
    \  :\";\n            for(int j = 0; j < right_cum_[i].size(); ++j){\n        \
    \        cerr << \" \" << right_cum_[i][j];\n            }\n            cerr <<\
    \ endl;\n        }\n    }\n\n    private:\n    RootedTree<CostType> &tree_;\n\n\
    \    Monoid dfs(Vertex v, bool root = false){\n        Monoid ret = id_;\n   \
    \     for(auto u : tree_.get_child(v)){\n            Monoid res = dfs(u);\n  \
    \          subtree_dp_[v].push_back(res);\n            ret = merge_(ret, res,\
    \ v);\n        }\n        if(root) ret = finalize_(ret, v);\n        else ret\
    \ = add_(ret, tree_.get_cost(v), v);\n        return ret;\n    }\n\n    void solve(){\n\
    \        dp_.resize(V, id_);\n        subtree_dp_.resize(V, vector<Monoid>{id_});\n\
    \        left_cum_.resize(V);\n        right_cum_.resize(V);\n        Vertex root\
    \ = tree_.get_root();\n\n        dp_[root] = dfs(root, true);\n        int root_size\
    \ = subtree_dp_[root].size();\n        left_cum_[root].resize(root_size + 1);\n\
    \        left_cum_[root].front() = id_;\n        for(int i = 1; i < root_size;\
    \ ++i){\n            left_cum_[root][i] = merge_(left_cum_[root][i - 1], subtree_dp_[root][i],\
    \ root);\n        }\n        right_cum_[root].resize(root_size + 1);\n       \
    \ right_cum_[root].back() = id_;\n        for(int i = root_size - 1; i - 1 >=\
    \ 0; --i){\n            right_cum_[root][i] = merge_(right_cum_[root][i + 1],\
    \ subtree_dp_[root][i], root);\n        }\n\n        queue<tuple<int, int, int>>\
    \ que;\n        for(int i = 0; i < tree_.get_child(root).size(); ++i){\n     \
    \       que.push({tree_.get_child(root)[i], root, i + 1});\n        }\n      \
    \  while(que.size()){\n            auto [v, p, idx] = que.front(); que.pop();\n\
    \            Monoid ret = id_;\n            ret = merge_(ret, left_cum_[p][idx\
    \ - 1], v);\n            ret = merge_(ret, right_cum_[p][idx + 1], v);\n     \
    \       ret = add_(ret, tree_.get_cost(v), p);\n            subtree_dp_[v].push_back(ret);\n\
    \            for(int i = 1; i + 1 < subtree_dp_[v].size(); ++i){\n           \
    \     ret = merge_(ret, subtree_dp_[v][i], v);\n            }\n            dp_[v]\
    \ = finalize_(ret, v);\n            int c = subtree_dp_[v].size();\n         \
    \   left_cum_[v].resize(c + 1);\n            left_cum_[v][0] = id_;\n        \
    \    for(int i = 1; i < c; ++i){\n                left_cum_[v][i] = merge_(left_cum_[v][i\
    \ - 1], subtree_dp_[v][i], v);\n            }\n            right_cum_[v].resize(c\
    \ + 1);\n            right_cum_[v].back() = id_;\n            for(int i = c -\
    \ 1; i - 1 >= 0; --i){\n                right_cum_[v][i] = merge_(right_cum_[v][i\
    \ + 1], subtree_dp_[v][i], v);\n            }\n            for(int i = 0; i <\
    \ tree_.get_child(v).size(); ++i){\n                que.push({tree_.get_child(v)[i],\
    \ v, i + 1});\n            }\n        }\n    }\n    \n    int V;\n    vector<Monoid>\
    \ dp_;\n    vector<vector<Monoid>> subtree_dp_, left_cum_, right_cum_;\n\n   \
    \ const Monoid id_;\n\n    F merge_;\n    G add_;\n    H finalize_;\n    const\
    \ Fsub merge_sub_;\n    const Gsub add_sub_;\n};"
  dependsOn:
  - Library/Tree/Tree.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Tree/RerootingDP.hpp
  requiredBy: []
  timestamp: '2024-11-01 01:18:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/LC-TreePathCompositeSum.test.cpp
  - verify/AOJ-GRL-5-B.test.cpp
documentation_of: Library/Tree/RerootingDP.hpp
layout: document
redirect_from:
- /library/Library/Tree/RerootingDP.hpp
- /library/Library/Tree/RerootingDP.hpp.html
title: "Rerooting DP - \u5168\u65B9\u4F4D\u6728 DP"
---
