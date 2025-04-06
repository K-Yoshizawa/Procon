---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/SegmentTree.hpp
    title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/HeavyLightDecomposition.hpp
    title: "Heavy Light Decomposition - HL\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"verify/LC-VertexAddSubtreeSum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line 2 \"Library/Template.hpp\"\
    \n\n/**\n * @file Template.hpp\n * @author log K (lX57)\n * @brief Template -\
    \ \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 1.10\n * @date 2025-03-16\n\
    \ */\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (1LL << 30) -\
    \ 1;\n#line 12 \"Library/Template.hpp\"\n\ninline bool YnPrint(bool flag){cout\
    \ << (flag ? \"Yes\" : \"No\") << '\\n'; return flag;}\ninline bool YNPrint(bool\
    \ flag){cout << (flag ? \"YES\" : \"NO\") << '\\n'; return flag;}\ntemplate<typename\
    \ Container>\ninline void Sort(Container &container){sort(container.begin(), container.end());}\n\
    template<typename Container>\ninline void ReverseSort(Container &container){sort(container.rbegin(),\
    \ container.rend());}\ntemplate<typename Container>\ninline void Reverse(Container\
    \ &container){reverse(container.begin(), container.end());}\ntemplate<typename\
    \ Value>\ninline int PopCount(const Value &value){return __builtin_popcount(value);}\n\
    template<typename Value>\ninline Value Ceil(const Value &numerator, const Value\
    \ &denominator){return (numerator + denominator - 1) / denominator;}\ntemplate<typename\
    \ Value>\ninline int LowerBoundIndex(const vector<Value> &container, const Value\
    \ &value){return distance(container.begin(), lower_bound(container.begin(), container.end(),\
    \ value));}\ntemplate<typename Value>\ninline int UpperBoundIndex(const vector<Value>\
    \ &container, const Value &value){return distance(container.begin(), upper_bound(container.begin(),\
    \ container.end(), value));}\ntemplate<typename Value>\ninline bool Between(const\
    \ Value &lower, const Value &x, const Value &higher){return lower <= x && x <=\
    \ higher;}\ntemplate<typename Value>\ninline bool InGrid(const Value &y, const\
    \ Value &x, const Value &ymax, const Value &xmax){return Between(0, y, ymax -\
    \ 1) && Between(0, x, xmax - 1);}\ntemplate<typename Value>\ninline Value Median(const\
    \ Value &a, const Value &b, const Value &c){return Between(b, a, c) || Between(c,\
    \ a, b) ? a : (Between(a, b, c) || Between(c, b, a) ? b : c);}\ntemplate<typename\
    \ Value>\ninline Value Except(Value &src, Value &cond, Value &excp){return (src\
    \ == cond ? excp : src);}\n\ntemplate<class Value>\nbool chmin(Value &src, const\
    \ Value &cmp){if(src > cmp){src = cmp; return true;} return false;}\ntemplate<class\
    \ Value>\nbool chmax(Value &src, const Value &cmp){if(src < cmp){src = cmp; return\
    \ true;} return false;}\ntemplate<typename Value>\ninline Value min(vector<Value>\
    \ &v){return *min_element((v).begin(), (v).end());}\ntemplate<typename Value>\n\
    inline Value max(vector<Value> &v){return *max_element((v).begin(), (v).end());}\n\
    \nconst int dx4[4] = {1, 0, -1, 0};\nconst int dy4[4] = {0, -1, 0, 1};\nconst\
    \ int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};\nconst int dy8[8] = {0, -1, -1, -1,\
    \ 0, 1, 1, 1};\n\nvector<pair<int, int>> adjacent(int current_y, int current_x,\
    \ int max_y, int max_x, bool dir_8 = false){\n    vector<pair<int, int>> ret;\n\
    \    for(int d = 0; d < 4 * (1 + dir_8); ++d){\n        int next_y = current_y\
    \ + (dir_8 ? dy8[d] : dy4[d]);\n        int next_x = current_x + (dir_8 ? dx8[d]\
    \ : dx4[d]);\n        if(InGrid(next_y, next_x, max_y, max_x)){\n            ret.emplace_back(next_y,\
    \ next_x);\n        }\n    }\n    return ret;\n}\n\ntemplate <typename T1, typename\
    \ T2>\nostream &operator<<(ostream &os, const pair<T1, T2> &p){\n    os << p.first\
    \ << \" \" << p.second;\n    return os;\n}\n\ntemplate <typename T1, typename\
    \ T2>\nistream &operator>>(istream &is, pair<T1, T2> &p){\n    is >> p.first >>\
    \ p.second;\n    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, vector<T> &v){\n    for (int i = 0; i < v.size(); ++i){\n        os <<\
    \ v[i] << (i + 1 != v.size() ? \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, vector<vector<T>> &v){\n    for\
    \ (int i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1 != v.size() ?\
    \ \"\\n\" : \"\");\n    }\n    return os;\n}\n\ntemplate <typename T>\nistream\
    \ &operator>>(istream &is, vector<T> &v){\n    for (int i = 0; i < v.size(); ++i)\
    \ is >> v[i];\n    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, set<T> &v){\n    for (auto &u : v){\n        os << u << \" \";\n    }\n\
    \    return os;\n}\n\ntemplate<typename T1, typename T2>\nvector<pair<T1, T2>>\
    \ AssembleVectorPair(vector<T1> &v1, vector<T2> &v2){\n    assert(v1.size() ==\
    \ v2.size());\n    vector<pair<T1, T2>> v;\n    for(int i = 0; i < v1.size();\
    \ ++i) v.push_back({v1[i], v2[i]});\n    return v;\n}\n\ntemplate<typename T1,\
    \ typename T2>\npair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1,\
    \ T2>> &v){\n    vector<T1> v1;\n    vector<T2> v2;\n    transform(v.begin(),\
    \ v.end(), back_inserter(v1), [](auto p){return p.first;});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v2), [](auto p){return p.second;});\n    return {v1,\
    \ v2};\n}\n\ntemplate<typename T1, typename T2, typename T3>\ntuple<vector<T1>,\
    \ vector<T2>, vector<T3>> DisassembleVectorTuple(vector<tuple<T1, T2, T3>> &v){\n\
    \    vector<T1> v1;\n    vector<T2> v2;\n    vector<T3> v3;\n    transform(v.begin(),\
    \ v.end(), back_inserter(v1), [](auto p){return get<0>(p);});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v2), [](auto p){return get<1>(p);});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v3), [](auto p){return get<2>(p);});\n    return {v1,\
    \ v2, v3};\n}\n\ntemplate<typename T1 = int, typename T2 = T1>\npair<vector<T1>,\
    \ vector<T2>> InputVectorPair(int size){\n    vector<pair<T1, T2>> v(size);\n\
    \    for(auto &[p, q] : v) cin >> p >> q;\n    return DisassembleVectorPair(v);\n\
    }\n\ntemplate<typename T1 = int, typename T2 = T1, typename T3 = T1>\ntuple<vector<T1>,\
    \ vector<T2>, vector<T3>> InputVectorTuple(int size){\n    vector<tuple<T1, T2,\
    \ T3>> v(size);\n    for(auto &[p, q, r] : v) cin >> p >> q >> r;\n    return\
    \ DisassembleVectorTuple(v);\n}\n#line 1 \"Library/Tree/HeavyLightDecomposition.hpp\"\
    \n/**\n * @file HeavyLightDecomposition.hpp\n * @author log K (lX57)\n * @brief\
    \ Heavy Light Decomposition - HL\u5206\u89E3\n * @version 4.0\n * @date 2024-09-04\n\
    \ */\n\n#line 2 \"Library/Tree/Tree.hpp\"\n\n/**\n * @file Tree.hpp\n * @brief\
    \ Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 1.0\n * @date\
    \ 2024-09-02\n */\n\n#line 11 \"Library/Tree/Tree.hpp\"\n\nusing Vertex = int;\n\
    \ntemplate<typename CostType = int32_t>\nclass RootedTree{\n    public:\n    struct\
    \ Node{\n        Node(Vertex parent = -1) : parent(parent){}\n\n        Vertex\
    \ parent{-1};\n        CostType cost{};\n        vector<Vertex> children{};\n\
    \    };\n\n    /**\n     * @brief \u9802\u70B9 `root_vertex` \u3092\u6839\u3068\
    \u3059\u308B\u9802\u70B9\u6570 `vertex_size` \u306E\u6839\u4ED8\u304D\u6728\u3092\
    \u69CB\u7BC9\u3059\u308B\u3002\n     * @note \u6839\u304C\u5165\u529B\u3067\u4E0E\
    \u3048\u3089\u308C\u306A\u308C\u306A\u3044\u304C\u5F8C\u3067\u5206\u304B\u308B\
    \u3001\u307F\u305F\u3044\u306A\u72B6\u6CC1\u306E\u6642\u306F `root_vertex = -1`\
    \ \u3068\u3059\u308B\u3068\u3088\u3044\n     * @param vertex_size \u9802\u70B9\
    \u6570\n     * @param root_vertex \u6839\u3068\u3059\u308B\u9802\u70B9 (default\
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
    \ root);\n    return ret;\n}\n#line 10 \"Library/Tree/HeavyLightDecomposition.hpp\"\
    \n\nstruct PathSegment{\n    PathSegment() = default;\n    Vertex head_vertex;\
    \ // `head_vertex` : \u30D1\u30B9\u306E\u6700\u3082\u6839\u306B\u8FD1\u3044\u9802\
    \u70B9\u306E\u9802\u70B9\u756A\u53F7\n    Vertex tail_vertex; // `tail_vertex`\
    \ : \u30D1\u30B9\u306E\u6700\u3082\u8449\u306B\u8FD1\u3044\u9802\u70B9\u306E\u9802\
    \u70B9\u756A\u53F7\n    int head_index; // `head_index` : `head_vertex` \u306E\
    \u884C\u304D\u304B\u3051\u9806\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u756A\
    \u53F7 (0-index, \u534A\u958B\u533A\u9593)\n    int tail_index; // `tail_index`\
    \ : `tail_vertex` \u306E\u884C\u304D\u304B\u3051\u9806\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u756A\u53F7 (0-index, \u534A\u958B\u533A\u9593)\n    bool highest;\
    \ // \u3053\u306E `PathSegment` \u304C\u6700\u3082\u6839\u306B\u8FD1\u3044(\u3064\
    \u307E\u308A LCA \u3092\u542B\u3093\u3067\u3044\u308B)\u30D1\u30B9\u3067\u3042\
    \u308B\u3053\u3068\u3092\u8868\u3059\u3002\u8FBA\u5C5E\u6027\u306E\u30AF\u30A8\
    \u30EA\u3067 LCA \u3092\u9664\u304F\u305F\u3081\u306B\u4F7F\u7528\u3002\n    bool\
    \ reverse; // \u30AF\u30A8\u30EA\u3067\u6295\u3052\u305F `from -> to` \u306B\u5BFE\
    \u3057\u3066\u3001`from` \u5074\u304C `tail_vertex` \u3067\u3042\u308B\u3053\u3068\
    \u3092\u8868\u3059\u3002\u53EF\u9006\u6027\u306E\u306A\u3044\u30AF\u30A8\u30EA\
    \u3067\u4F7F\u7528\u3002\n    friend ostream &operator<<(ostream &os, const PathSegment\
    \ &p){\n        return os << \"# Path (\" << p.head_vertex << \" -> \" << p.tail_vertex\
    \ << \", \" << p.head_index << \" -> \" << p.tail_index << \", \" << boolalpha\
    \ << p.highest << \", \" << p.reverse << \")\";\n    }\n};\n\ntemplate<typename\
    \ CostType>\nclass HeavyLightDecomposition{\n    public:\n    HeavyLightDecomposition(RootedTree<CostType>\
    \ &tree) : tree_(tree){\n        vertex_size_ = tree_.get_vertex_size();\n   \
    \     vector<int> subtree_size = CalculateSubtreeSize(tree_);\n        vertex_depth_\
    \ = CalculateTreeDepth(tree_);\n        for(int i = 0; i < vertex_size_; ++i){\n\
    \            auto &children = tree_.get_child(i);\n            nth_element(children.begin(),\
    \ children.begin(), children.end(), [&](Vertex i, Vertex j){\n               \
    \ return subtree_size[i] > subtree_size[j];\n            });\n        }\n    \
    \    Vertex root = tree_.get_root();\n        heavy_path_head_.push_back(root);\n\
    \        heavy_path_depth_.push_back(0);\n        belong_heavy_path_index_.resize(vertex_size_,\
    \ -1);\n        belong_heavy_path_index_[root] = 0;\n        preorder_index_.resize(vertex_size_,\
    \ -1);\n        postorder_index_.resize(vertex_size_, -1);\n        vertex_order_.resize(vertex_size_);\n\
    \        int timer = 0;\n        dfs(root, 0, 0, timer);\n    }\n\n    /**\n \
    \    * @brief \u9802\u70B9 `u` \u3068\u9802\u70B9 `v` \u306E\u6700\u5C0F\u5171\
    \u901A\u7956\u5148\u3092\u8FD4\u3059\u3002\n     * @param u \u9802\u70B9\u756A\
    \u53F7 (0-index)\n     * @param v \u9802\u70B9\u756A\u53F7 (0-index)\n     * @return\
    \ Vertex \u6700\u5C0F\u5171\u901A\u7956\u5148\u306E\u9802\u70B9\u756A\u53F7 (0-index)\n\
    \     */\n    Vertex LowestCommonAncestor(Vertex u, Vertex v){\n        if(path_depth(u)\
    \ < path_depth(v)) swap(u, v);\n        while(path_depth(u) != path_depth(v)){\n\
    \            u = tree_.get_parent(head(u));\n        }\n        while(belong(u)\
    \ != belong(v)){\n            u = tree_.get_parent(head(u));\n            v =\
    \ tree_.get_parent(head(v));\n        }\n        return vertex_depth(u) < vertex_depth(v)\
    \ ? u : v;\n    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E\u7956\u5148\
    \u3067\u3042\u3063\u3066\u3001\u6DF1\u3055\u304C `level` \u3067\u3042\u308B\u9802\
    \u70B9\u3092\u8FD4\u3059\u3002\n     * @note \u305D\u306E\u3088\u3046\u306A\u9802\
    \u70B9\u304C\u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u3001`-1` \u3092\u8FD4\u3059\
    \u3002\n     * @param v \u9802\u70B9\u756A\u53F7 (0-index)\n     * @param level\
    \ \u6DF1\u3055 (0-index)\n     * @return Vertex \u7B54\u3048\u3068\u306A\u308B\
    \u9802\u70B9 (\u307E\u305F\u306F `-1`)\n     */\n    Vertex LevelAncestor(Vertex\
    \ v, int level){\n        if(level < 0 || vertex_depth(v) < level) return -1;\n\
    \        Vertex u = head(v);\n        while(1){\n            if(vertex_depth(u)\
    \ <= level){\n                int delta = level - vertex_depth(u);\n         \
    \       return order(preorder(u) + delta);\n            }\n            u = tree_.get_parent(u);\n\
    \        }\n    }\n\n    /**\n     * @brief \u9802\u70B9 `from` \u304B\u3089\u9802\
    \u70B9 `to` \u3078\u306E\u6700\u77ED\u8DEF\u306B\u304A\u3044\u3066\u3001`from`\
    \ \u304B\u3089 `dist` \u500B\u79FB\u52D5\u3057\u305F\u9802\u70B9\u756A\u53F7\u3092\
    \u6C42\u3081\u308B\u3002\n     * @note \u6700\u77ED\u8DEF\u306E\u9577\u3055\u3092\
    \ `k` \u3068\u3057\u3066\u3001`dist < 0` \u307E\u305F\u306F `k < dist` \u306E\u3068\
    \u304D `-1` \u3092\u8FD4\u3059\u3002\n     * @param from \u59CB\u70B9\u306E\u9802\
    \u70B9\u756A\u53F7 (0-index)\n     * @param to \u7D42\u70B9\u306E\u9802\u70B9\u756A\
    \u53F7 (0-index)\n     * @param dist \u79FB\u52D5\u3059\u308B\u9802\u70B9\u6570\
    \n     * @return Vertex \u7B54\u3048\u306E\u9802\u70B9\u756A\u53F7 (0-index) \u307E\
    \u305F\u306F `-1`\n     */\n    Vertex Jump(Vertex from, Vertex to, int dist){\n\
    \        Vertex lca = LowestCommonAncestor(from, to);\n        int dist_from_lca\
    \ = vertex_depth(from) - vertex_depth(lca);\n        int dist_lca_to = vertex_depth(to)\
    \ - vertex_depth(lca);\n        if(dist < 0 or dist > dist_from_lca + dist_lca_to)\
    \ return -1;\n        if(dist <= dist_from_lca){\n            return LevelAncestor(from,\
    \ vertex_depth(from) - dist);\n        }\n        else{\n            return LevelAncestor(to,\
    \ vertex_depth(lca) + dist - dist_from_lca);\n        }\n    }\n\n    /**\n  \
    \   * @brief \u9802\u70B9 `from` \u304B\u3089\u9802\u70B9 `to` \u3078\u306E\u30D1\
    \u30B9\u3092\u5206\u89E3\u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059\u3002\n   \
    \  * @note \u53EF\u9006\u6027\u306E\u306A\u3044\u30AF\u30A8\u30EA\u306B\u5BFE\u3057\
    \u3066\u3082\u5BFE\u5FDC\u3002\u8A73\u3057\u304F\u306F `PathSegment` \u306E `reverse`\
    \ \u3092\u53C2\u7167\u3002\n     * @param from \u59CB\u70B9\u306E\u9802\u70B9\u756A\
    \u53F7 (0-index)\n     * @param to \u7D42\u70B9\u306E\u9802\u70B9\u756A\u53F7\
    \ (0-index)\n     * @return vector<PathSegment> \u5206\u89E3\u3057\u305F\u7D50\
    \u679C\n     */\n    vector<PathSegment> PathQuery(Vertex from, Vertex to){\n\
    \        vector<PathSegment> ret;\n        Vertex lca = LowestCommonAncestor(from,\
    \ to);\n        while(belong(from) != belong(lca)){\n            PathSegment path;\n\
    \            Vertex h = head(from);\n            path.head_vertex = h, path.tail_vertex\
    \ = from;\n            path.head_index = preorder(h), path.tail_index = preorder(from)\
    \ + 1;\n            path.highest = false, path.reverse = true;\n            ret.push_back(path);\n\
    \            from = tree_.get_parent(h);\n        }\n        if(from != lca){\n\
    \            PathSegment path;\n            path.head_vertex = lca, path.tail_vertex\
    \ = from;\n            path.head_index = preorder(lca), path.tail_index = preorder(from)\
    \ + 1;\n            path.highest = true, path.reverse = true;\n            ret.push_back(path);\n\
    \        }\n        int size = ret.size();\n        while(belong(to) != belong(lca)){\n\
    \            PathSegment path;\n            Vertex h = head(to);\n           \
    \ path.head_vertex = h, path.tail_vertex = to;\n            path.head_index =\
    \ preorder(h), path.tail_index = preorder(to) + 1;\n            path.highest =\
    \ false, path.reverse = false;\n            ret.push_back(path);\n           \
    \ to = tree_.get_parent(h);\n        }\n        if(to != lca){\n            PathSegment\
    \ path;\n            path.head_vertex = lca, path.tail_vertex = to;\n        \
    \    path.head_index = preorder(lca), path.tail_index = preorder(to) + 1;\n  \
    \          path.highest = true, path.reverse = false;\n            ret.push_back(path);\n\
    \        }\n        if(from == lca && to == lca){\n            PathSegment path;\n\
    \            path.head_vertex = path.tail_vertex = lca;\n            path.head_index\
    \ = preorder(lca), path.tail_index = preorder(lca) + 1;\n            path.highest\
    \ = true, path.reverse = false;\n            ret.push_back(path);\n        }\n\
    \        reverse(ret.begin() + size, ret.end());\n        return ret;\n    }\n\
    \n    /**\n     * @brief \u9802\u70B9 `v` \u3092\u6839\u3068\u3059\u308B\u90E8\
    \u5206\u6728\u306B\u5BFE\u5FDC\u3057\u305F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \u3092\u534A\u958B\u533A\u9593\u3067\u8FD4\u3059\u3002\n     * @param v \u9802\
    \u70B9\u756A\u53F7 (0-index)\n     * @return pair<int, int> \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9 (0-index, \u534A\u958B\u533A\u9593)\n     */\n    pair<int,\
    \ int> SubtreeQuery(Vertex v) const {\n        return make_pair(preorder(v), postorder(v)\
    \ + 1);\n    }\n\n    /**\n     * @brief \u9802\u70B9 `i` \u306B\u8F09\u305B\u308B\
    \u30C7\u30FC\u30BF\u3092\u683C\u7D0D\u3057\u305F\u914D\u5217 `data[i]` \u3092\u3001\
    \u9802\u70B9\u306E\u884C\u304D\u304B\u3051\u9806\u306B\u306A\u308B\u3088\u3046\
    \u306B\u4E26\u3079\u66FF\u3048\u308B\u3002\n     * @note \u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\u306A\u3069\u306B\u8F09\u305B\u308B\u524D\u306B\u4F7F\u7528\u3059\
    \u308B\u3002\n     * @param data \u5404\u9802\u70B9\u306B\u8F09\u305B\u308B\u30C7\
    \u30FC\u30BF\n     */\n    template<typename T>\n    void SortVertex(vector<T>\
    \ &data){\n        assert(data.size() == vertex_size_);\n        vector<T> sub(data.size());\n\
    \        for(int i = 0; i < vertex_size_; ++i){\n            sub[preorder(i)]\
    \ = data[i];\n        }\n        swap(data, sub);\n    }\n\n    int operator[](Vertex\
    \ v){\n        return preorder(v);\n    }\n\n    const int operator[](Vertex v)\
    \ const {\n        return preorder(v);\n    }\n\n    private:\n    int dfs(Vertex\
    \ v, int h, int d, int &t){\n        preorder_index_[v] = t;\n        vertex_order_[t]\
    \ = v;\n        int ret = t;\n        ++t;\n        auto cs = tree_.get_child(v);\n\
    \        if(!cs.empty()){\n            int c = cs.size();\n            belong_heavy_path_index_[cs.front()]\
    \ = h;\n            ret = max(ret, dfs(cs.front(), h, d, t));\n            for(int\
    \ i = 1; i < c; ++i){\n                int nh = (int)heavy_path_head_.size();\n\
    \                heavy_path_head_.push_back(cs[i]);\n                heavy_path_depth_.push_back(d\
    \ + 1);\n                belong_heavy_path_index_[cs[i]] = nh;\n             \
    \   ret = max(ret, dfs(cs[i], nh, d + 1, t));\n            }\n        }\n    \
    \    postorder_index_[v] = ret;\n        return ret;\n    }\n\n    Vertex head(Vertex\
    \ v) const {\n        return heavy_path_head_[belong_heavy_path_index_[v]];\n\
    \    }\n\n    int path_depth(Vertex v) const {\n        return heavy_path_depth_[belong_heavy_path_index_[v]];\n\
    \    }\n\n    int vertex_depth(Vertex v) const {\n        return vertex_depth_[v];\n\
    \    }\n\n    int belong(Vertex v) const {\n        return belong_heavy_path_index_[v];\n\
    \    }\n\n    Vertex order(int idx) const {\n        return vertex_order_[idx];\n\
    \    }\n\n    int preorder(Vertex v) const {\n        return preorder_index_[v];\n\
    \    }\n\n    int postorder(Vertex v) const {\n        return postorder_index_[v];\n\
    \    }\n\n    RootedTree<CostType> &tree_;\n\n    int vertex_size_;\n    vector<Vertex>\
    \ heavy_path_head_, vertex_order_;\n    vector<int> belong_heavy_path_index_,\
    \ belong_heavy_path_order_, heavy_path_depth_;\n    vector<int> preorder_index_,\
    \ postorder_index_;\n    vector<int> vertex_depth_;\n};\n#line 1 \"Library/DataStructure/SegmentTree.hpp\"\
    \n/**\n * @file SegmentTree.hpp\n * @author log K (lX57)\n * @brief Segment Tree\
    \ - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @version 3.0\n * @date 2024-09-04\n\
    \ */\n\n#line 10 \"Library/DataStructure/SegmentTree.hpp\"\n\ntemplate<typename\
    \ Monoid>\nclass SegmentTree{\n    public:\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\
    \u8981\u7D20\u6570 `size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param\
    \ size \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\n     * @param\
    \ merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param\
    \ monoid_identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param\
    \ zero_index 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\u304B (default\
    \ = `false`)\n     */\n    SegmentTree(int size, F merge, const Monoid &monoid_identity,\
    \ bool zero_index = false) :\n            f(merge), id_(monoid_identity), zero_index_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < size) size_ <<= 1;\n        offset_\
    \ = size_ - 1;\n        data_.resize(2 * size_, id_);\n    }\n\n    /**\n    \
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\
    \n     * @attention \u5FC5\u305A `Set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\u5165\
    \u3057\u3066\u304B\u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n     */\n\
    \    void Build(){\n        for(int i = offset_; i >= 1; --i){\n            data_[i]\
    \ = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n    /**\n    \
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\u5024\u3092\u4EE3\
    \u5165\u3059\u308B\u3002\n     * @param index \u4EE3\u5165\u5148\u306E\u8981\u7D20\
    \u756A\u53F7 (default = 1-index)\n     * @param value \u4EE3\u5165\u3059\u308B\
    \u5024\n     */\n    void Set(int index, Monoid value){\n        Validate(index\
    \ + zero_index_);\n        data_[offset_ + index + zero_index_] = value;\n   \
    \ }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u914D\
    \u5217 `init_data` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param init_data\
    \ \u521D\u671F\u30C7\u30FC\u30BF\u306E\u914D\u5217\n     * @param merge \u533A\
    \u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param monoid_identity\
    \ \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param zero_index 0-index\u3068\
    \u3057\u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(vector<Monoid>\
    \ &init_data, F merge, const Monoid &monoid_identity, bool zero_index = false)\
    \ :\n            f(merge), id_(monoid_identity), zero_index_(zero_index){\n  \
    \      size_ = 1;\n        while(size_ < (int)init_data.size()) size_ <<= 1;\n\
    \        offset_ = size_ - 1;\n        data_.resize(2 * size_, id_);\n       \
    \ for(int i = 0; i < (int)init_data.size(); ++i){\n            data_[size_ + i]\
    \ = init_data[i];\n        }\n        Build();\n    }\n\n    /**\n     * @brief\
    \ \u4E00\u70B9\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\
    \n     * @param index \u66F4\u65B0\u5148\u306E\u8981\u7D20\u756A\u53F7 (default\
    \ = 1-index)\n     * @param value \u66F4\u65B0\u3059\u308B\u5024\n     */\n  \
    \  void Update(int index, Monoid value){\n        Validate(index + zero_index_);\n\
    \        int k = offset_ + index + zero_index_;\n        data_[k] = value;\n \
    \       while(k >>= 1){\n            data_[k] = f(data_[2 * k], data_[2 * k +\
    \ 1]);\n        }\n    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[left,\
    \ Right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\
    \u884C\u3046\u3002\n     * @param left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\
    \n     * @param right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid Query(int left,\
    \ int right){\n        if(left == right) return id_;\n        Validate(left +\
    \ zero_index_);\n        Validate(right + zero_index_ - 1);\n        int l = left\
    \ + zero_index_ + offset_, r = right + zero_index_ + offset_;\n        Monoid\
    \ al = id_, ar = id_;\n        while(l < r){\n            if(l & 1) al = f(al,\
    \ data_[l++]);\n            if(r & 1) ar = f(data_[--r], ar);\n            l >>=\
    \ 1, r >>= 1;\n        }\n        return f(al, ar);\n    }\n\n    /**\n     *\
    \ @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\
    \u308B\u3002\n     * @param k \u53D6\u5F97\u5148\u306E\u8981\u7D20\u756A\u53F7\
    \ (default = 1-index)\n     * @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\
    \n     */\n    Monoid get_value(int k){\n        Validate(k + zero_index_);\n\
    \        return data_[offset_ + k + zero_index_];\n    }\n\n    Monoid operator[](const\
    \ int &k){\n        return get_value(k);\n    }\n\n    private:\n    int size_,\
    \ offset_, zero_index_;\n    vector<Monoid> data_;\n    const F f;\n    const\
    \ Monoid id_;\n\n    inline void Validate(int x) const {\n        assert(1 <=\
    \ x && x <= size_);\n    }\n};\n#line 6 \"verify/LC-VertexAddSubtreeSum.test.cpp\"\
    \n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<ll> a(N); cin >> a;\n\
    \    RootedTree T(N);\n    T.InputRootedTreeFormat(false, false);\n\n    HeavyLightDecomposition\
    \ hld(T);\n    hld.SortVertex(a);\n    SegmentTree<ll> seg(a, [](ll l, ll r){return\
    \ l + r;}, 0LL, true);\n    while(Q--){\n        int t; cin >> t;\n        if(t\
    \ == 0){\n            int p, x; cin >> p >> x;\n            seg.Update(hld[p],\
    \ seg[hld[p]] + x);\n        }\n        else{\n            int u; cin >> u;\n\
    \            auto [l, r] = hld.SubtreeQuery(u);\n            cout << seg.Query(l,\
    \ r) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/Tree/HeavyLightDecomposition.hpp\"\
    \n#include \"../Library/DataStructure/SegmentTree.hpp\"\n\nint main(){\n    int\
    \ N, Q; cin >> N >> Q;\n    vector<ll> a(N); cin >> a;\n    RootedTree T(N);\n\
    \    T.InputRootedTreeFormat(false, false);\n\n    HeavyLightDecomposition hld(T);\n\
    \    hld.SortVertex(a);\n    SegmentTree<ll> seg(a, [](ll l, ll r){return l +\
    \ r;}, 0LL, true);\n    while(Q--){\n        int t; cin >> t;\n        if(t ==\
    \ 0){\n            int p, x; cin >> p >> x;\n            seg.Update(hld[p], seg[hld[p]]\
    \ + x);\n        }\n        else{\n            int u; cin >> u;\n            auto\
    \ [l, r] = hld.SubtreeQuery(u);\n            cout << seg.Query(l, r) << endl;\n\
    \        }\n    }\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/Tree/HeavyLightDecomposition.hpp
  - Library/Tree/Tree.hpp
  - Library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify/LC-VertexAddSubtreeSum.test.cpp
  requiredBy: []
  timestamp: '2025-03-20 00:50:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-VertexAddSubtreeSum.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-VertexAddSubtreeSum.test.cpp
- /verify/verify/LC-VertexAddSubtreeSum.test.cpp.html
title: verify/LC-VertexAddSubtreeSum.test.cpp
---
