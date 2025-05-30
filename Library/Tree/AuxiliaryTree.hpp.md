---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Tree/EulerTour.hpp
    title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/LowestCommonAncestor.hpp
    title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
  - icon: ':question:'
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Auxiliary Tree - \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\
      \u3061\u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\
      \u3066\u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\
      \u306A\u6728"
    links: []
  bundledCode: "#line 1 \"Library/Tree/AuxiliaryTree.hpp\"\n/**\n * @file AuxiliaryTree.hpp\n\
    \ * @brief Auxiliary Tree - \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\
    \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\
    \u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\
    \u6728\n * @version 2.0\n * @date 2024-10-31\n */\n\n#line 2 \"Library/Tree/Tree.hpp\"\
    \n\n/**\n * @file Tree.hpp\n * @brief Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8\n * @version 1.0\n * @date 2024-09-02\n */\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr\
    \ const ll INF = (1LL << 62) - (1LL << 30) - 1;\n#line 11 \"Library/Tree/Tree.hpp\"\
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
    \ root);\n    return ret;\n}\n#line 2 \"Library/Tree/EulerTour.hpp\"\n\n/**\n\
    \ * @file EulerTour.hpp\n * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\
    \u30A2\u30FC\n * @version 4.0\n * @date 2024-10-31\n */\n\n#line 12 \"Library/Tree/EulerTour.hpp\"\
    \n\ntemplate<typename CostType>\nclass EulerTour{\n    public:\n    using F =\
    \ function<CostType(CostType)>;\n\n    EulerTour(){}\n\n    /**\n     * @brief\
    \ \u6728 `T` \u306B\u304A\u3051\u308B\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
    \u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @param one_index `1-index` \u3068\
    \u3057\u3066\u6271\u3044\u305F\u3044\u304B `(default = false)`\n     */\n    EulerTour(RootedTree<CostType>\
    \ &T, bool one_index = false) :\n            T(T),\n            vertex_size_(T.get_vertex_size()),\n\
    \            in_time_(T.get_vertex_size()),\n            out_time_(T.get_vertex_size()),\n\
    \            one_index_(one_index){\n        dfs(T.get_root());\n    }\n\n   \
    \ /**\n     * @brief \u9802\u70B9 `v` \u306B\u5165\u3063\u305F\u6642\u523B\u3092\
    \u8FD4\u3059\u3002\n     * @note \u6642\u523B\u306F `0-index` \u3067\u8FD4\u308B\
    \u3002\n     * @return int \u9802\u70B9 `v` \u306B\u5165\u3063\u305F\u6642\u523B\
    \n     */\n    int get_in(const Vertex v) const {\n        return in_time_.at(v\
    \ - one_index_);\n    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u304B\u3089\
    \u51FA\u305F\u6642\u523B\u3092\u8FD4\u3059\u3002\n     * @note \u6642\u523B\u306F\
    \ `0-index` \u3067\u8FD4\u308B\u3002\n     * @return int \u9802\u70B9 `v` \u304B\
    \u3089\u51FA\u305F\u6642\u523B\n     */\n    int get_out(const Vertex v) const\
    \ {\n        return out_time_.at(v - one_index_);\n    }\n\n    /**\n     * @brief\
    \ \u9802\u70B9 `v` \u306B\u5165\u3063\u305F\u6642\u523B\u3068\u51FA\u305F\u6642\
    \u523B\u306E\u4E21\u65B9\u3092\u8FD4\u3059\u3002\n     * @note \u6642\u523B\u306F\
    \ `0-index` \u3067\u8FD4\u308B\u3002\n     * @return pair<int, int> \u9802\u70B9\
    \ `v` \u306B\u5165\u3063\u305F\u6642\u523B\u3068\u51FA\u305F\u6642\u523B\n   \
    \  */\n    pair<int, int> get_pair(const Vertex v) const {\n        return make_pair(in_time_.at(v\
    \ - one_index_), out_time_.at(v - one_index_));\n    }\n\n    /**\n     * @brief\
    \ \u914D\u5217 `value` \u3092\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u306B\u57FA\
    \u3065\u3044\u3066\u5909\u63DB\u3057\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\
    \n     * @note \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\u306E\u521D\u671F\
    \u914D\u5217\u3068\u3057\u3066\u6E21\u3059\u5834\u5408\u306B\u306A\u3069\u306B\
    \u7528\u3044\u308B\u3002\n     * @tparam Type \u6E21\u3059\u30C7\u30FC\u30BF\u306E\
    \u578B\n     * @param value \u5909\u63DB\u3059\u308B\u914D\u5217\n     * @param\
    \ in_converter \u9802\u70B9 `v` \u306B\u5165\u308B\u6642\u523B\u306B\u5BFE\u3059\
    \u308B\u30C7\u30FC\u30BF\u3092\u5909\u63DB\u3059\u308B\u95A2\u6570\n     * @param\
    \ out_converter \u9802\u70B9 `v` \u304B\u3089\u51FA\u308B\u6642\u523B\u306B\u5BFE\
    \u3059\u308B\u30C7\u30FC\u30BF\u3092\u5909\u63DB\u3059\u308B\u95A2\u6570\n   \
    \  * @return vector<Type> \u5909\u63DB\u3057\u305F\u9577\u3055 `2 * |V|` \u306E\
    \u914D\u5217\n     */\n    template<typename Type>\n    vector<Type> ConvertVector(const\
    \ vector<Type> &value, const F in_converter, const F out_converter){\n       \
    \ vector<Type> ret(2 * vertex_size_);\n        for(int i = 0; i < vertex_size_;\
    \ ++i){\n            int in_idx = in_time_.at(i), out_idx = out_time_.at(i);\n\
    \            ret[in_idx] = in_converter(value.at(i));\n            ret[out_idx]\
    \ = out_converter(value.at(i));\n        }\n        return ret;\n    }\n\n   \
    \ private:\n    int time_{0}, one_index_, vertex_size_;\n\n    RootedTree<CostType>\
    \ &T;\n    vector<int> in_time_, out_time_;\n\n    void dfs(Vertex v){\n     \
    \   in_time_[v] = time_++;\n        for(Vertex c : T.get_child(v)){\n        \
    \    dfs(c);\n        }\n        out_time_[v] = time_++;\n    }\n};\n#line 2 \"\
    Library/Tree/LowestCommonAncestor.hpp\"\n\n/**\n * @file LowestCommonAncestor.hpp\n\
    \ * @brief Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148\n * @version\
    \ 4.0\n * @date 2024-09-03\n */\n\n#line 11 \"Library/Tree/LowestCommonAncestor.hpp\"\
    \n\ntemplate<typename CostType>\nstruct LowestCommonAncestor{\n    public:\n \
    \   LowestCommonAncestor(){}\n\n    LowestCommonAncestor(RootedTree<CostType>\
    \ &tree) :\n            tree_(tree), depth_(CalculateTreeDepth(tree)){\n     \
    \   int V = tree.get_vertex_size();\n        height_ = 1;\n        while((1 <<\
    \ height_) < V) ++height_;\n        parent_.resize(height_, vector<Vertex>(V,\
    \ -1));\n        for(Vertex v = 0; v < V; ++v){\n            parent_[0][v] = tree.get_parent(v);\n\
    \        }\n        for(int k = 0; k + 1 < height_; ++k){\n            for(Vertex\
    \ v = 0; v < V; ++v){\n                if(parent_[k][v] < 0) parent_[k + 1][v]\
    \ = -1;\n                else parent_[k + 1][v] = parent_[k][parent_[k][v]];\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief \u9802\u70B9 `u` \u3068\
    \u9802\u70B9 `v` \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u3092\u8FD4\u3059\u3002\
    \n     * @param u \u9802\u70B9\u756A\u53F7 (0-index)\n     * @param v \u9802\u70B9\
    \u756A\u53F7 (0-index)\n     * @return Vertex \u9802\u70B9 `u` \u3068\u9802\u70B9\
    \ `v` \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\n     */\n    Vertex Query(Vertex\
    \ u, Vertex v){\n        if(depth_[u] < depth_[v]) swap(u, v);\n        for(int\
    \ k = 0; k < height_; ++k){\n            if((depth_[u] - depth_[v]) >> k & 1){\n\
    \                u = parent_[k][u];\n            }\n        }\n        if(u ==\
    \ v) return u;\n        for(int k = height_ - 1; k >= 0; --k){\n            if(parent_[k][u]\
    \ != parent_[k][v]){\n                u = parent_[k][u];\n                v =\
    \ parent_[k][v];\n            }\n        }\n        return parent_[0][u];\n  \
    \  }\n\n    private:\n    RootedTree<CostType> &tree_;\n    int height_;\n   \
    \ vector<int> depth_;\n    vector<vector<Vertex>> parent_;\n};\n#line 11 \"Library/Tree/AuxiliaryTree.hpp\"\
    \n\ntemplate<typename CostType>\nclass AuxiliaryTree{\n    public:\n    /**\n\
    \     * @brief \u6728 `tree` \u3092\u5143\u306B\u88DC\u52A9\u6728\u3092\u5B9A\u7FA9\
    \u3059\u308B\u3002\n     * @param tree \u9802\u70B9\u6570 `U` \u306E\u6728\n \
    \    */\n    AuxiliaryTree(RootedTree<CostType> &tree) :\n            T(tree),\
    \ lca_(tree), et_(tree), edge_cum_(CalculateTreeCumlativeSum(tree)){\n    }\n\n\
    \    /**\n     * @brief \u69CB\u7BC9\u3059\u308B\u88DC\u52A9\u6728\u306B\u542B\
    \u3080\u9802\u70B9\u96C6\u5408\u3092\u30BB\u30C3\u30C8\u3059\u308B\u3002\n   \
    \  * @note \u5B9F\u969B\u306B\u306F\u3001\u3053\u306E\u9802\u70B9\u96C6\u5408\u306B\
    \ LCA \u3092\u52A0\u3048\u305F\u9802\u70B9\u96C6\u5408\u304C\u4FDD\u5B58\u3055\
    \u308C\u308B\u3002\n     * @note \u8A08\u7B97\u91CF : O(V log V)\n     * @param\
    \ vertex_set \u88DC\u52A9\u6728\u306B\u542B\u3080\u8981\u7D20\u6570 `V` \u306E\
    \u9802\u70B9\u96C6\u5408 (0-index)\n     */\n    void Set(const vector<Vertex>\
    \ &vertex_set){\n        auxiliary_tree_vertex_set_ = vertex_set;\n        auxiliary_tree_size_\
    \ = auxiliary_tree_vertex_set_.size();\n        sort(auxiliary_tree_vertex_set_.begin(),\
    \ auxiliary_tree_vertex_set_.end(), [&](int i, int j){\n            return et_.get_in(i)\
    \ < et_.get_in(j);\n        });\n        for(int i = 0; i < auxiliary_tree_size_\
    \ - 1; ++i){\n            auxiliary_tree_vertex_set_.push_back(lca_.Query(auxiliary_tree_vertex_set_[i],\
    \ auxiliary_tree_vertex_set_[i + 1]));\n        }\n        sort(auxiliary_tree_vertex_set_.begin(),\
    \ auxiliary_tree_vertex_set_.end(), [&](int i, int j){\n            return et_.get_in(i)\
    \ < et_.get_in(j);\n        });\n        auxiliary_tree_vertex_set_.erase(unique(auxiliary_tree_vertex_set_.begin(),\
    \ auxiliary_tree_vertex_set_.end()), auxiliary_tree_vertex_set_.end());\n    \
    \    auxiliary_tree_size_ = auxiliary_tree_vertex_set_.size();\n    }\n\n    /**\n\
    \     * @brief \u88DC\u52A9\u6728\u3092\u751F\u6210\u3059\u308B\u3002\n     *\
    \ @attention \u4E88\u3081\u9802\u70B9\u96C6\u5408\u3092 `Set()` \u3092\u7528\u3044\
    \u3066\u30BB\u30C3\u30C8\u3057\u3066\u304A\u304F\u5FC5\u8981\u304C\u3042\u308B\
    \u3002\n     * @note \u8A08\u7B97\u91CF : O(V log V)\n     * @return RootedTree<CostType>\
    \ \u751F\u6210\u3055\u308C\u305F\u9802\u70B9\u6570 \n     */\n    RootedTree<CostType>\
    \ Build(){\n        RootedTree<CostType> ret(auxiliary_tree_size_);\n        stack<Vertex>\
    \ st, idx;\n        st.push(auxiliary_tree_vertex_set_.front());\n        idx.push(0);\n\
    \        for(int i = 1; i < auxiliary_tree_size_; ++i){\n            while(et_.get_out(st.top())\
    \ < et_.get_in(auxiliary_tree_vertex_set_[i])) st.pop(), idx.pop();\n        \
    \    if(st.size()){\n                CostType cost = edge_cum_[auxiliary_tree_vertex_set_[i]]\
    \ - edge_cum_[st.top()];\n                ret.AddEdge(idx.top(), i, cost);\n \
    \           }\n            st.push(auxiliary_tree_vertex_set_[i]);\n         \
    \   idx.push(i);\n        }\n        return ret;\n    }\n\n    /**\n     * @brief\
    \ \u5143\u306E\u6728\u3068\u88DC\u52A9\u6728\u306B\u30C7\u30FC\u30BF\u3092\u5BFE\
    \u5FDC\u3055\u305B\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\n     * @tparam Type\
    \ \u30C7\u30FC\u30BF\u306E\u578B\n     * @param data \u9577\u3055 `U` \u306E\u30C7\
    \u30FC\u30BF\n     * @return vector<Type> \u9577\u3055 `O(V log V)` \u306E\u5909\
    \u63DB\u5F8C\u306E\u30C7\u30FC\u30BF\n     */\n    template<typename Type>\n \
    \   vector<Type> ConvertData(const vector<Type> &data) const {\n        vector<Type>\
    \ ret(auxiliary_tree_size_);\n        for(int i = 0; i < auxiliary_tree_size_;\
    \ ++i){\n            ret[i] = data[auxiliary_tree_vertex_set_[i]];\n        }\n\
    \        return ret;\n    }\n\n    private:\n    RootedTree<CostType> &T;\n  \
    \  LowestCommonAncestor<CostType> lca_;\n    EulerTour<CostType> et_;\n    vector<CostType>\
    \ edge_cum_;\n\n    vector<Vertex> auxiliary_tree_vertex_set_;\n    size_t auxiliary_tree_size_;\n\
    \    vector<Vertex> convert_to_;\n};\n"
  code: "/**\n * @file AuxiliaryTree.hpp\n * @brief Auxiliary Tree - \u6307\u5B9A\u3055\
    \u308C\u305F\u9802\u70B9\u305F\u3061\u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \u95A2\u4FC2\u3092\u4FDD\u3063\u3066\u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\
    \u304D\u308B\u88DC\u52A9\u7684\u306A\u6728\n * @version 2.0\n * @date 2024-10-31\n\
    \ */\n\n#include \"Tree.hpp\"\n#include \"EulerTour.hpp\"\n#include \"LowestCommonAncestor.hpp\"\
    \n\ntemplate<typename CostType>\nclass AuxiliaryTree{\n    public:\n    /**\n\
    \     * @brief \u6728 `tree` \u3092\u5143\u306B\u88DC\u52A9\u6728\u3092\u5B9A\u7FA9\
    \u3059\u308B\u3002\n     * @param tree \u9802\u70B9\u6570 `U` \u306E\u6728\n \
    \    */\n    AuxiliaryTree(RootedTree<CostType> &tree) :\n            T(tree),\
    \ lca_(tree), et_(tree), edge_cum_(CalculateTreeCumlativeSum(tree)){\n    }\n\n\
    \    /**\n     * @brief \u69CB\u7BC9\u3059\u308B\u88DC\u52A9\u6728\u306B\u542B\
    \u3080\u9802\u70B9\u96C6\u5408\u3092\u30BB\u30C3\u30C8\u3059\u308B\u3002\n   \
    \  * @note \u5B9F\u969B\u306B\u306F\u3001\u3053\u306E\u9802\u70B9\u96C6\u5408\u306B\
    \ LCA \u3092\u52A0\u3048\u305F\u9802\u70B9\u96C6\u5408\u304C\u4FDD\u5B58\u3055\
    \u308C\u308B\u3002\n     * @note \u8A08\u7B97\u91CF : O(V log V)\n     * @param\
    \ vertex_set \u88DC\u52A9\u6728\u306B\u542B\u3080\u8981\u7D20\u6570 `V` \u306E\
    \u9802\u70B9\u96C6\u5408 (0-index)\n     */\n    void Set(const vector<Vertex>\
    \ &vertex_set){\n        auxiliary_tree_vertex_set_ = vertex_set;\n        auxiliary_tree_size_\
    \ = auxiliary_tree_vertex_set_.size();\n        sort(auxiliary_tree_vertex_set_.begin(),\
    \ auxiliary_tree_vertex_set_.end(), [&](int i, int j){\n            return et_.get_in(i)\
    \ < et_.get_in(j);\n        });\n        for(int i = 0; i < auxiliary_tree_size_\
    \ - 1; ++i){\n            auxiliary_tree_vertex_set_.push_back(lca_.Query(auxiliary_tree_vertex_set_[i],\
    \ auxiliary_tree_vertex_set_[i + 1]));\n        }\n        sort(auxiliary_tree_vertex_set_.begin(),\
    \ auxiliary_tree_vertex_set_.end(), [&](int i, int j){\n            return et_.get_in(i)\
    \ < et_.get_in(j);\n        });\n        auxiliary_tree_vertex_set_.erase(unique(auxiliary_tree_vertex_set_.begin(),\
    \ auxiliary_tree_vertex_set_.end()), auxiliary_tree_vertex_set_.end());\n    \
    \    auxiliary_tree_size_ = auxiliary_tree_vertex_set_.size();\n    }\n\n    /**\n\
    \     * @brief \u88DC\u52A9\u6728\u3092\u751F\u6210\u3059\u308B\u3002\n     *\
    \ @attention \u4E88\u3081\u9802\u70B9\u96C6\u5408\u3092 `Set()` \u3092\u7528\u3044\
    \u3066\u30BB\u30C3\u30C8\u3057\u3066\u304A\u304F\u5FC5\u8981\u304C\u3042\u308B\
    \u3002\n     * @note \u8A08\u7B97\u91CF : O(V log V)\n     * @return RootedTree<CostType>\
    \ \u751F\u6210\u3055\u308C\u305F\u9802\u70B9\u6570 \n     */\n    RootedTree<CostType>\
    \ Build(){\n        RootedTree<CostType> ret(auxiliary_tree_size_);\n        stack<Vertex>\
    \ st, idx;\n        st.push(auxiliary_tree_vertex_set_.front());\n        idx.push(0);\n\
    \        for(int i = 1; i < auxiliary_tree_size_; ++i){\n            while(et_.get_out(st.top())\
    \ < et_.get_in(auxiliary_tree_vertex_set_[i])) st.pop(), idx.pop();\n        \
    \    if(st.size()){\n                CostType cost = edge_cum_[auxiliary_tree_vertex_set_[i]]\
    \ - edge_cum_[st.top()];\n                ret.AddEdge(idx.top(), i, cost);\n \
    \           }\n            st.push(auxiliary_tree_vertex_set_[i]);\n         \
    \   idx.push(i);\n        }\n        return ret;\n    }\n\n    /**\n     * @brief\
    \ \u5143\u306E\u6728\u3068\u88DC\u52A9\u6728\u306B\u30C7\u30FC\u30BF\u3092\u5BFE\
    \u5FDC\u3055\u305B\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\n     * @tparam Type\
    \ \u30C7\u30FC\u30BF\u306E\u578B\n     * @param data \u9577\u3055 `U` \u306E\u30C7\
    \u30FC\u30BF\n     * @return vector<Type> \u9577\u3055 `O(V log V)` \u306E\u5909\
    \u63DB\u5F8C\u306E\u30C7\u30FC\u30BF\n     */\n    template<typename Type>\n \
    \   vector<Type> ConvertData(const vector<Type> &data) const {\n        vector<Type>\
    \ ret(auxiliary_tree_size_);\n        for(int i = 0; i < auxiliary_tree_size_;\
    \ ++i){\n            ret[i] = data[auxiliary_tree_vertex_set_[i]];\n        }\n\
    \        return ret;\n    }\n\n    private:\n    RootedTree<CostType> &T;\n  \
    \  LowestCommonAncestor<CostType> lca_;\n    EulerTour<CostType> et_;\n    vector<CostType>\
    \ edge_cum_;\n\n    vector<Vertex> auxiliary_tree_vertex_set_;\n    size_t auxiliary_tree_size_;\n\
    \    vector<Vertex> convert_to_;\n};"
  dependsOn:
  - Library/Tree/Tree.hpp
  - Library/Common.hpp
  - Library/Tree/EulerTour.hpp
  - Library/Tree/LowestCommonAncestor.hpp
  isVerificationFile: false
  path: Library/Tree/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '2025-03-20 00:50:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Tree/AuxiliaryTree.hpp
layout: document
redirect_from:
- /library/Library/Tree/AuxiliaryTree.hpp
- /library/Library/Tree/AuxiliaryTree.hpp.html
title: "Auxiliary Tree - \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\u306E\
  \u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\u6728\u3092\
  \u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\u6728"
---
