---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/DataStructure/SegmentTree.hpp
    title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':question:'
    path: Library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':x:'
    path: Library/Tree/EulerTour.hpp
    title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  - icon: ':question:'
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line\
    \ 2 \"Library/Template.hpp\"\n\n/**\n * @file Template.hpp\n * @author log K (lX57)\n\
    \ * @brief Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 1.10\n\
    \ * @date 2025-03-16\n */\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n\
    \ */\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n#line 12 \"Library/Template.hpp\"\
    \n\ninline bool YnPrint(bool flag){cout << (flag ? \"Yes\" : \"No\") << '\\n';\
    \ return flag;}\ninline bool YNPrint(bool flag){cout << (flag ? \"YES\" : \"NO\"\
    ) << '\\n'; return flag;}\ntemplate<typename Container>\ninline void Sort(Container\
    \ &container){sort(container.begin(), container.end());}\ntemplate<typename Container>\n\
    inline void ReverseSort(Container &container){sort(container.rbegin(), container.rend());}\n\
    template<typename Container>\ninline void Reverse(Container &container){reverse(container.begin(),\
    \ container.end());}\ntemplate<typename Value>\ninline int PopCount(const Value\
    \ &value){return __builtin_popcount(value);}\ntemplate<typename Value>\ninline\
    \ Value Ceil(const Value &numerator, const Value &denominator){return (numerator\
    \ + denominator - 1) / denominator;}\ntemplate<typename Value>\ninline int LowerBoundIndex(const\
    \ vector<Value> &container, const Value &value){return distance(container.begin(),\
    \ lower_bound(container.begin(), container.end(), value));}\ntemplate<typename\
    \ Value>\ninline int UpperBoundIndex(const vector<Value> &container, const Value\
    \ &value){return distance(container.begin(), upper_bound(container.begin(), container.end(),\
    \ value));}\ntemplate<class Value>\nbool ChangeMin(Value &src, const Value &cmp){if(src\
    \ > cmp){src = cmp; return true;} return false;}\ntemplate<class Value>\nbool\
    \ ChangeMax(Value &src, const Value &cmp){if(src < cmp){src = cmp; return true;}\
    \ return false;}\ntemplate<typename Value>\ninline bool Between(const Value &lower,\
    \ const Value &x, const Value &higher){return lower <= x && x <= higher;}\ntemplate<typename\
    \ Value>\ninline bool InGrid(const Value &y, const Value &x, const Value &ymax,\
    \ const Value &xmax){return Between(0, y, ymax - 1) && Between(0, x, xmax - 1);}\n\
    template<typename Value>\ninline Value Median(const Value &a, const Value &b,\
    \ const Value &c){return Between(b, a, c) || Between(c, a, b) ? a : (Between(a,\
    \ b, c) || Between(c, b, a) ? b : c);}\ntemplate<typename Value>\ninline Value\
    \ Except(Value &src, Value &cond, Value &excp){return (src == cond ? excp : src);}\n\
    \ntemplate<typename Value>\ninline Value min(vector<Value> &v){return *min_element((v).begin(),\
    \ (v).end());}\ntemplate<typename Value>\ninline Value max(vector<Value> &v){return\
    \ *max_element((v).begin(), (v).end());}\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\
    \nconst int INF_INT = numeric_limits<int>::max() >> 2;\nconst ll INF_LL = numeric_limits<ll>::max()\
    \ >> 2;\n\nconst int dx4[4] = {1, 0, -1, 0};\nconst int dy4[4] = {0, -1, 0, 1};\n\
    const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};\nconst int dy8[8] = {0, -1, -1,\
    \ -1, 0, 1, 1, 1};\n\nvector<pair<int, int>> adjacent(int current_y, int current_x,\
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
    \ DisassembleVectorTuple(v);\n}\n#line 2 \"Library/Tree/EulerTour.hpp\"\n\n/**\n\
    \ * @file EulerTour.hpp\n * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\
    \u30A2\u30FC\n * @version 4.0\n * @date 2024-10-31\n */\n\n#line 2 \"Library/Tree/Tree.hpp\"\
    \n\n/**\n * @file Tree.hpp\n * @brief Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8\n * @version 1.0\n * @date 2024-09-02\n */\n\n#line 11 \"Library/Tree/Tree.hpp\"\
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
    \ root);\n    return ret;\n}\n#line 12 \"Library/Tree/EulerTour.hpp\"\n\ntemplate<typename\
    \ CostType>\nclass EulerTour{\n    public:\n    using F = function<CostType(CostType)>;\n\
    \n    EulerTour(){}\n\n    /**\n     * @brief \u6728 `T` \u306B\u304A\u3051\u308B\
    \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u3092\u69CB\u7BC9\u3059\u308B\u3002\
    \n     * @param one_index `1-index` \u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B `(default = false)`\n     */\n    EulerTour(RootedTree<CostType> &T, bool\
    \ one_index = false) :\n            T(T),\n            vertex_size_(T.get_vertex_size()),\n\
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
    \    dfs(c);\n        }\n        out_time_[v] = time_++;\n    }\n};\n#line 1 \"\
    Library/DataStructure/SegmentTree.hpp\"\n/**\n * @file SegmentTree.hpp\n * @author\
    \ log K (lX57)\n * @brief Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n\
    \ * @version 3.0\n * @date 2024-09-04\n */\n\n#line 10 \"Library/DataStructure/SegmentTree.hpp\"\
    \n\ntemplate<typename Monoid>\nclass SegmentTree{\n    public:\n    using F =\
    \ function<Monoid(Monoid, Monoid)>;\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\u3092\u8981\u7D20\u6570 `size` \u3067\u521D\u671F\u5316\u3059\
    \u308B\u3002\n     * @param size \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\
    \u7D20\u6570\n     * @param merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\
    \u7B97\n     * @param monoid_identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param zero_index 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B (default = `false`)\n     */\n    SegmentTree(int size, F merge, const\
    \ Monoid &monoid_identity, bool zero_index = false) :\n            f(merge), id_(monoid_identity),\
    \ zero_index_(zero_index){\n        size_ = 1;\n        while(size_ < size) size_\
    \ <<= 1;\n        offset_ = size_ - 1;\n        data_.resize(2 * size_, id_);\n\
    \    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\
    \u7BC9\u3059\u308B\u3002\n     * @attention \u5FC5\u305A `Set()` \u3067\u521D\u671F\
    \u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\u3089\u547C\u3073\u51FA\u3059\u3053\
    \u3068\uFF01\n     */\n    void Build(){\n        for(int i = offset_; i >= 1;\
    \ --i){\n            data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n     \
    \   }\n    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\
    \u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\u308B\u3002\n     * @param index \u4EE3\
    \u5165\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     * @param\
    \ value \u4EE3\u5165\u3059\u308B\u5024\n     */\n    void Set(int index, Monoid\
    \ value){\n        Validate(index + zero_index_);\n        data_[offset_ + index\
    \ + zero_index_] = value;\n    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\u3092\u914D\u5217 `init_data` \u3067\u521D\u671F\u5316\u3059\u308B\
    \u3002\n     * @param init_data \u521D\u671F\u30C7\u30FC\u30BF\u306E\u914D\u5217\
    \n     * @param merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n\
    \     * @param monoid_identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\
    \n     * @param zero_index 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\u304B\
    \ (default = `false`)\n     */\n    SegmentTree(vector<Monoid> &init_data, F merge,\
    \ const Monoid &monoid_identity, bool zero_index = false) :\n            f(merge),\
    \ id_(monoid_identity), zero_index_(zero_index){\n        size_ = 1;\n       \
    \ while(size_ < (int)init_data.size()) size_ <<= 1;\n        offset_ = size_ -\
    \ 1;\n        data_.resize(2 * size_, id_);\n        for(int i = 0; i < (int)init_data.size();\
    \ ++i){\n            data_[size_ + i] = init_data[i];\n        }\n        Build();\n\
    \    }\n\n    /**\n     * @brief \u4E00\u70B9\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\
    \u51E6\u7406\u3059\u308B\u3002\n     * @param index \u66F4\u65B0\u5148\u306E\u8981\
    \u7D20\u756A\u53F7 (default = 1-index)\n     * @param value \u66F4\u65B0\u3059\
    \u308B\u5024\n     */\n    void Update(int index, Monoid value){\n        Validate(index\
    \ + zero_index_);\n        int k = offset_ + index + zero_index_;\n        data_[k]\
    \ = value;\n        while(k >>= 1){\n            data_[k] = f(data_[2 * k], data_[2\
    \ * k + 1]);\n        }\n    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593\
    \ `[left, Right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\
    \u30EA\u3092\u884C\u3046\u3002\n     * @param left \u534A\u958B\u533A\u9593\u306E\
    \u5DE6\u7AEF\n     * @param right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n\
    \     * @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid\
    \ Query(int left, int right){\n        if(left == right) return id_;\n       \
    \ Validate(left + zero_index_);\n        Validate(right + zero_index_ - 1);\n\
    \        int l = left + zero_index_ + offset_, r = right + zero_index_ + offset_;\n\
    \        Monoid al = id_, ar = id_;\n        while(l < r){\n            if(l &\
    \ 1) al = f(al, data_[l++]);\n            if(r & 1) ar = f(data_[--r], ar);\n\
    \            l >>= 1, r >>= 1;\n        }\n        return f(al, ar);\n    }\n\n\
    \    /**\n     * @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\u3059\u308B\u3002\n     * @param k \u53D6\u5F97\u5148\u306E\u8981\u7D20\
    \u756A\u53F7 (default = 1-index)\n     * @return Monoid \u53D6\u5F97\u3057\u305F\
    \u7D50\u679C\n     */\n    Monoid get_value(int k){\n        Validate(k + zero_index_);\n\
    \        return data_[offset_ + k + zero_index_];\n    }\n\n    Monoid operator[](const\
    \ int &k){\n        return get_value(k);\n    }\n\n    private:\n    int size_,\
    \ offset_, zero_index_;\n    vector<Monoid> data_;\n    const F f;\n    const\
    \ Monoid id_;\n\n    inline void Validate(int x) const {\n        assert(1 <=\
    \ x && x <= size_);\n    }\n};\n#line 6 \"verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp\"\
    \n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vl a(N); cin >> a;\n    RootedTree\
    \ T(N);\n    T.InputRootedTreeFormat(false, false);\n\n    EulerTour et(T);\n\
    \    auto A = et.ConvertVector(a, [](ll x){return x;}, [](ll x){return 0;});\n\
    \    SegmentTree<ll> seg(A, [](ll l, ll r){return l + r;}, 0LL, true);\n    while(Q--){\n\
    \        int t; cin >> t;\n        if(t == 0){\n            int u, x; cin >> u\
    \ >> x;\n            seg.Update(et.get_in(u), seg[et.get_in(u)] + x);\n      \
    \  }\n        else{\n            int u; cin >> u;\n            auto [l, r] = et.get_pair(u);\n\
    \            cout << seg.Query(l, r) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/Tree/EulerTour.hpp\"\
    \n#include \"../Library/DataStructure/SegmentTree.hpp\"\n\nint main(){\n    int\
    \ N, Q; cin >> N >> Q;\n    vl a(N); cin >> a;\n    RootedTree T(N);\n    T.InputRootedTreeFormat(false,\
    \ false);\n\n    EulerTour et(T);\n    auto A = et.ConvertVector(a, [](ll x){return\
    \ x;}, [](ll x){return 0;});\n    SegmentTree<ll> seg(A, [](ll l, ll r){return\
    \ l + r;}, 0LL, true);\n    while(Q--){\n        int t; cin >> t;\n        if(t\
    \ == 0){\n            int u, x; cin >> u >> x;\n            seg.Update(et.get_in(u),\
    \ seg[et.get_in(u)] + x);\n        }\n        else{\n            int u; cin >>\
    \ u;\n            auto [l, r] = et.get_pair(u);\n            cout << seg.Query(l,\
    \ r) << endl;\n        }\n    }\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/Tree/EulerTour.hpp
  - Library/Tree/Tree.hpp
  - Library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
  requiredBy: []
  timestamp: '2025-03-16 02:46:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
- /verify/verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp.html
title: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
---
