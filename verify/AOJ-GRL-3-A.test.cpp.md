---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/LowLink.hpp
    title: "LowLink - \u6A4B\u3068\u95A2\u7BC0\u70B9"
  - icon: ':question:'
    path: Library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_3_A
  bundledCode: "#line 1 \"verify/AOJ-GRL-3-A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_3_A\"\
    \n\n#line 2 \"Library/Template.hpp\"\n\n/**\n * @file Template.hpp\n * @author\
    \ log K (lX57)\n * @brief Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n *\
    \ @version 1.10\n * @date 2025-03-16\n */\n\n#line 2 \"Library/Common.hpp\"\n\n\
    /**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n#line 12 \"Library/Template.hpp\"\n\ninline bool YnPrint(bool\
    \ flag){cout << (flag ? \"Yes\" : \"No\") << '\\n'; return flag;}\ninline bool\
    \ YNPrint(bool flag){cout << (flag ? \"YES\" : \"NO\") << '\\n'; return flag;}\n\
    template<typename Container>\ninline void Sort(Container &container){sort(container.begin(),\
    \ container.end());}\ntemplate<typename Container>\ninline void ReverseSort(Container\
    \ &container){sort(container.rbegin(), container.rend());}\ntemplate<typename\
    \ Container>\ninline void Reverse(Container &container){reverse(container.begin(),\
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
    \ DisassembleVectorTuple(v);\n}\n#line 2 \"Library/Graph/LowLink.hpp\"\n\n/**\n\
    \ * @file LowLink.hpp\n * @brief LowLink - \u6A4B\u3068\u95A2\u7BC0\u70B9\n *\
    \ @version 1.0\n * @date 2024-09-02\n */\n\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n\n/**\n * @file Graph.hpp\n * @brief Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n * @version 1.0\n * @date 2024-09-01\n */\n\n#line 11 \"Library/Graph/Graph.hpp\"\
    \n\nusing Vertex = int;\n\ntemplate<typename CostType>\nstruct Edge{\n    Edge()\
    \ = default;\n    Edge(int from, int to, CostType cost, int id = -1) : from(from),\
    \ to(to), cost(cost), id(id){}\n\t\n    int from{-1}, to{-1}, id{-1};\n    CostType\
    \ cost{1};\n};\n\ntemplate<typename CostType = int32_t>\nclass Graph{\n    public:\n\
    \    Graph() = default;\n\n    /**\n     * @brief \u9802\u70B9\u6570 `vertex_size`\
    \ \u306E\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @param\
    \ vertex_size \u9802\u70B9\u6570\n     * @param directed `true` \u306E\u5834\u5408\
    \u3001\u6709\u5411\u30B0\u30E9\u30D5\u3068\u3057\u3066\u69CB\u7BC9\u3059\u308B\
    \ `(default = false)`\n     */\n    Graph(int vertex_size, bool directed = false)\
    \ : \n        vertex_(vertex_size), adjacent_list_(vertex_size),\n        directed_flag_(directed){}\n\
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
    \u307F `(default = 1)`\n     * @param id \u8FBA\u306E\u756A\u53F7\u3092\u660E\u793A\
    \u7684\u306B\u6307\u5B9A\u3059\u308B `(default = -1)`\n     */\n    void AddEdge(Vertex\
    \ s, Vertex t, CostType c = 1, int id = -1){\n        Validate(s);\n        Validate(t);\n\
    \        int edge_id = edge_++;\n        if(id != -1) edge_id = id;\n        adjacent_list_[s].push_back(Edge(s,\
    \ t, c, edge_id));\n        if(!directed_flag_){\n            adjacent_list_[t].push_back(Edge(t,\
    \ s, c, edge_id));\n        }\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\
    \u306B\u6307\u5B9A\u3057\u305F\u8FBA\u6570\u306E\u60C5\u5831\u3092\u5165\u529B\
    \u3059\u308B\u3002\n     * @note \u5165\u529B\u5F62\u5F0F\u304C `u v w` \u307E\
    \u305F\u306F `u v` \u306E\u5F62\u5F0F\u3067\u8868\u3055\u308C\u308B\u5165\u529B\
    \u5F62\u5F0F\u306B\u5BFE\u5FDC\u3057\u3066\u3044\u308B\u3002\n     * @param edge_count\
    \ \u8FBA\u6570 E\n     * @param weighted_graph \u91CD\u307F\u4ED8\u304D\u8FBA\u3067\
    \u3042\u308B\u304B `(default = true)`\n     * @param one_index \u9802\u70B9\u304C\
    1-index\u3067\u3042\u308B\u304B `(default = true)`\n     */\n    void InputGraph(int\
    \ edge_count, bool weighted_graph = true, bool one_index = true){\n        for(int\
    \ i = 0; i < edge_count; ++i){\n            int s, t; cin >> s >> t;\n       \
    \     if(one_index) --s, --t;\n            CostType w = 1;\n            if(weighted_graph)\
    \ cin >> w;\n            AddEdge(s, t, w);\n        }\n    }\n\n    vector<Edge<CostType>>\
    \ &operator[](Vertex v){\n        return adjacent_list_[v];\n    }\n\n    const\
    \ vector<Edge<CostType>> &operator[](Vertex v) const {\n        return adjacent_list_[v];\n\
    \    }\n\n    inline void Validate(int vertex) const {\n        assert(0 <= vertex\
    \ && vertex < vertex_);\n    }\n\n    private:\n    size_t vertex_{0}, edge_{0};\n\
    \    vector<vector<Edge<CostType>>> adjacent_list_;\n\n    bool directed_flag_;\n\
    \    CostType inf_{numeric_limits<CostType>::max() / 4};\n};\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u884C\u5217\u3092\u8FD4\u3059\u3002\n *\
    \ @note verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_A\n\
    \ * @note \u8A08\u7B97\u91CF : O(V + E)\n * @note \u591A\u91CD\u8FBA\u306B\u3064\
    \u3044\u3066\u306F\u3001\u6700\u3082\u91CD\u307F\u304C\u5C0F\u3055\u3044\u8FBA\
    \u3092\u63A1\u7528\n * @param graph \u9802\u70B9\u6570 V \u306E\u30B0\u30E9\u30D5\
    \n * @param not_adjacent_value 2\u9802\u70B9 u, v \u9593\u306B\u8FBA\u304C\u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408\u306E\u5024 `(default = 0)`\n * @attention\
    \ \u81EA\u5DF1\u30EB\u30FC\u30D7\u304C\u542B\u307E\u308C\u308B\u30B0\u30E9\u30D5\
    \u306B\u3064\u3044\u3066\u306F\u672A\u5B9A\u7FA9\n * @return vector<vector<CostType>>\
    \ V \xD7 V \u306E\u96A3\u63A5\u884C\u5217\n */\ntemplate<typename CostType>\n\
    vector<vector<CostType>> GraphConvertMatrix(const Graph<CostType> &graph, CostType\
    \ not_adjacent_value = 0){\n    size_t V = graph.get_vertex_size();\n    vector<vector<CostType>>\
    \ ret(V, vector<CostType>(V, not_adjacent_value));\n    for(int i = 0; i < V;\
    \ ++i){\n        for(const Edge<CostType> &e : graph[i]){\n            if(ret[i][e.to]\
    \ == not_adjacent_value || ret[i][e.to] > e.cost){\n                ret[i][e.to]\
    \ = e.cost;\n            }\n        }\n    }\n    return ret;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u306E\u8FBA\u3092\u9006\u9806\u306B\u3057\u305F\u30B0\u30E9\
    \u30D5\u3092\u8FD4\u3059\u3002\n * @param graph \u9802\u70B9\u6570 V \u306E\u30B0\
    \u30E9\u30D5\n * @attention \u7121\u5411\u30B0\u30E9\u30D5\u306B\u5BFE\u3059\u308B\
    \u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9\n * @return Graph<CostType> G \u306E\u8FBA\
    \u3092\u9006\u306B\u3057\u305F\u30B0\u30E9\u30D5\n */\ntemplate<typename CostType>\n\
    Graph<CostType> GraphReverse(const Graph<CostType> &graph){\n    size_t V = graph.get_vertex_size();\n\
    \    Graph<CostType> ret(V, true);\n    for(int i = 0; i < V; ++i){\n        for(const\
    \ Edge<CostType> &e : graph[i]){\n            ret.AddEdge(e.to, e.from, e.cost);\n\
    \        }\n    }\n    return ret;\n}\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\
    \u8FBA\u96C6\u5408\u3092\u8FD4\u3059\u3002\n * @param graph \u9802\u70B9\u6570\
    \ V \u306E\u30B0\u30E9\u30D5\n * @param sorted \u8FBA\u96C6\u5408\u3092\u30B3\u30B9\
    \u30C8\u3067\u30BD\u30FC\u30C8\u3057\u305F\u72B6\u614B\u3067\u8FD4\u3059\u304B\
    \ `(default = false)`\n * @return vector<Edge<CostType>> G \u306E\u8FBA\u96C6\u5408\
    \n */\ntemplate<typename CostType>\nvector<Edge<CostType>> GraphConvertEdgeSet(const\
    \ Graph<CostType> &graph, bool sorted = false){\n    vector<Edge<CostType>> ret;\n\
    \    set<int> picked;\n    for(int v = 0; v < graph.get_vertex_size(); ++v){\n\
    \        for(Edge<CostType> e : graph[v]){\n            if(!picked.contains(e.id)){\n\
    \t\t\t\tret.emplace_back(e);\n                picked.insert(e.id);\n\t\t\t}\n\
    \        }\n    }\n    if(sorted){\n        sort(ret.begin(), ret.end(), [&](Edge<CostType>\
    \ &l, Edge<CostType> &r){\n            return l.cost < r.cost;\n        });\n\
    \    }\n    return ret;\n}\n#line 11 \"Library/Graph/LowLink.hpp\"\n\ntemplate<typename\
    \ CostType>\nclass LowLink{\n    public:\n    LowLink(Graph<CostType> &graph)\
    \ :\n            graph_(graph), ord_(graph.get_vertex_size()), low_(graph.get_vertex_size()),\n\
    \            child_(graph.get_vertex_size()), state_(graph.get_vertex_size(),\
    \ 0){\n        for(int i = 0; i < graph.get_vertex_size(); ++i){\n           \
    \ if(!state_[i]) dfs(i, -1, 0);\n        }\n        BuildArticulationVertex();\n\
    \        BuildBridge();\n    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E\
    \ `ord[v]` \u3092\u8FD4\u3059\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\
    \ (0-index)\n     * @return int \n     */\n    int get_ord(Vertex v) const {\n\
    \        graph_.Validate(v);\n        return ord_[v];\n    }\n\n    /**\n    \
    \ * @brief \u9802\u70B9 `v` \u306E `low[v]` \u3092\u8FD4\u3059\u3002\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7 (0-index)\n     * @return int \n     */\n    int\
    \ get_low(Vertex v) const {\n        graph_.Validate(v);\n        return low_[v];\n\
    \    }\n\n    /**\n     * @brief \u95A2\u7BC0\u70B9\u3092\u5217\u6319\u3059\u308B\
    \u3002\n     * @note \u95A2\u7BC0\u70B9 : \u305D\u306E\u9802\u70B9\u3092\u9664\
    \u304F\u3068\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\u308B\u3088\u3046\u306A\
    \u9802\u70B9\n     * @return vector<Vertex> \u95A2\u7BC0\u70B9\u306E\u9802\u70B9\
    \u756A\u53F7 (0-index)\n     */\n    vector<Vertex> &get_articulation_vertex(){\n\
    \        return articulation_vertex_;\n    }\n\n    /**\n     * @brief \u6A4B\u3092\
    \u5217\u6319\u3059\u308B\u3002\n     * @note \u6A4B : \u305D\u306E\u8FBA\u3092\
    \u9664\u304F\u3068\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\u308B\u3088\u3046\
    \u306A\u9802\u70B9\n     * @return vector<Edge<CostType>> \u6A4B\u3067\u3042\u308B\
    \u8FBA\n     */\n    vector<Edge<CostType>> &get_bridge(){\n        return bridge_;\n\
    \    }\n\n    private:\n    bool dfs(Vertex v, int p, int order){\n        if(state_[v]\
    \ != 0) return false;\n        // cerr << \"# (v, p, order) = (\" << v << \",\
    \ \" << p << \", \" << order << \")\" << endl;\n        state_[v] = 1 + (p ==\
    \ -1);\n        ord_[v] = low_[v] = order;\n        for(Edge<CostType> &e : graph_[v]){\n\
    \            if(e.id == p) continue;\n            child_[v].push_back(e.to);\n\
    \            if(dfs(e.to, e.id, order + 1)){\n                low_[v] = min(low_[v],\
    \ low_[e.to]);\n            }\n            else{\n                child_[v].pop_back();\n\
    \                low_[v] = min(low_[v], ord_[e.to]);\n            }\n        }\n\
    \        return true;\n    }\n\n    void BuildArticulationVertex(){\n        for(int\
    \ u = 0; u < graph_.get_vertex_size(); ++u){\n            if(state_[u] == 2){\n\
    \                if(child_[u].size() > 1) articulation_vertex_.push_back(u);\n\
    \                continue;\n            }\n            bool exist = false;\n \
    \           for(Vertex v : child_[u]){\n                exist |= (get_ord(u) <=\
    \ get_low(v));\n            }\n            if(exist) articulation_vertex_.push_back(u);\n\
    \        }\n    }\n\n    void BuildBridge(){\n        auto es = GraphConvertEdgeSet(graph_,\
    \ false);\n        for(Edge<CostType> e : es){\n            Vertex u = e.from,\
    \ v = e.to;\n            if(get_ord(u) >= get_ord(v)) swap(u, v);\n          \
    \  if(get_ord(u) < get_low(v)) bridge_.push_back(e);\n        }\n    }\n\n   \
    \ Graph<CostType> &graph_;\n    vector<int> ord_, low_, state_;\n    vector<vector<Vertex>>\
    \ child_;\n\n    vector<Vertex> articulation_vertex_;\n    vector<Edge<CostType>>\
    \ bridge_;\n};\n#line 5 \"verify/AOJ-GRL-3-A.test.cpp\"\n\nint main(){\n    int\
    \ V, E; cin >> V >> E;\n    Graph<ll> G(V);\n    G.InputGraph(E, false, false);\n\
    \    \n    LowLink lol(G);\n    auto ans = lol.get_articulation_vertex();\n  \
    \  for(auto v : ans){\n        cout << v << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_3_A\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/Graph/LowLink.hpp\"\
    \n\nint main(){\n    int V, E; cin >> V >> E;\n    Graph<ll> G(V);\n    G.InputGraph(E,\
    \ false, false);\n    \n    LowLink lol(G);\n    auto ans = lol.get_articulation_vertex();\n\
    \    for(auto v : ans){\n        cout << v << endl;\n    }\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/Graph/LowLink.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-3-A.test.cpp
  requiredBy: []
  timestamp: '2025-03-16 02:46:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-GRL-3-A.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-3-A.test.cpp
- /verify/verify/AOJ-GRL-3-A.test.cpp.html
title: verify/AOJ-GRL-3-A.test.cpp
---
