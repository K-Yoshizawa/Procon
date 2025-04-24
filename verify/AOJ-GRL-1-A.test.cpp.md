---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Dijkstra.hpp
    title: "Dijkstra - \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: Library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"verify/AOJ-GRL-1-A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#line 2 \"Library/Template.hpp\"\n\n/**\n * @file Template.hpp\n * @author\
    \ log K (lX57)\n * @brief Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n *\
    \ @version 1.10\n * @date 2025-03-16\n */\n\n#line 2 \"Library/Common.hpp\"\n\n\
    /**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const\
    \ ll INF = (1LL << 62) - (1LL << 30) - 1;\n#line 12 \"Library/Template.hpp\"\n\
    \ninline bool YnPrint(bool flag){cout << (flag ? \"Yes\" : \"No\") << '\\n'; return\
    \ flag;}\ninline bool YNPrint(bool flag){cout << (flag ? \"YES\" : \"NO\") <<\
    \ '\\n'; return flag;}\ntemplate<typename Container>\ninline void Sort(Container\
    \ &container){sort(container.begin(), container.end());}\ntemplate<typename Container>\n\
    inline void ReverseSort(Container &container){sort(container.rbegin(), container.rend());}\n\
    template<typename Container>\ninline void Reverse(Container &container){reverse(container.begin(),\
    \ container.end());}\ntemplate<typename Value>\ninline int PopCount(const Value\
    \ &value){return __builtin_popcount(value);}\ntemplate<typename Value>\ninline\
    \ Value Floor(const Value &numerator, const Value &denominator){if(denominator\
    \ < 0) numerator *= -1, denominator *= -1; return numerator < 0 ? (numerator +\
    \ 1) / denominator - 1 : numerator / denominator;}\ntemplate<typename Value>\n\
    inline Value Ceil(const Value &numerator, const Value &denominator){if(denominator\
    \ < 0) numerator *= -1, denominator *= -1; return numerator > 0 ? (numerator -\
    \ 1) / denominator + 1 : numerator / denominator;}\ntemplate<typename Value>\n\
    inline int LowerBoundIndex(const vector<Value> &container, const Value &value){return\
    \ distance(container.begin(), lower_bound(container.begin(), container.end(),\
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
    \ DisassembleVectorTuple(v);\n}\n#line 2 \"Library/Graph/Dijkstra.hpp\"\n\n#line\
    \ 2 \"Library/Graph/Graph.hpp\"\n\n#line 4 \"Library/Graph/Graph.hpp\"\n\nusing\
    \ Vertex = int;\n\ntemplate<typename CostType = int32_t>\nstruct Edge{\n    public:\n\
    \    Edge() = default;\n\n    Edge(Vertex from_, Vertex to_, CostType cost_ =\
    \ 1, int idx_ = -1) :\n        from(from_), to(to_), cost(cost_), idx(idx_){}\n\
    \    \n    bool operator<(const Edge<CostType> &e) const {return cost < e.cost;}\n\
    \n    operator int() const {return to;}\n\n    Vertex from, to;\n    CostType\
    \ cost;\n    int idx;\n};\n\ntemplate<typename CostType = int32_t>\nclass Graph{\n\
    \    public:\n    Graph() = default;\n\n    Graph(int n) : vertex_size_(n), edge_size_(0),\
    \ adjacent_list_(n){}\n    \n    inline void AddUndirectedEdge(Vertex u, Vertex\
    \ v, CostType w = 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<CostType>(u,\
    \ v, w, idx));\n        adjacent_list_[v].push_back(Edge<CostType>(v, u, w, idx));\n\
    \    }\n    \n    inline void AddDirectedEdge(Vertex u, Vertex v, CostType w =\
    \ 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<CostType>(u,\
    \ v, w, idx));\n    }\n\n    inline size_t VertexSize() const {\n        return\
    \ vertex_size_;\n    }\n\n    inline size_t EdgeSize() const {\n        return\
    \ edge_size_;\n    }\n\n    inline vector<Edge<CostType>> &operator[](const int\
    \ v){\n        return adjacent_list_[v];\n    }\n\n    inline const vector<Edge<CostType>>\
    \ &operator[](const int v) const {\n        return adjacent_list_[v];\n    }\n\
    \    \n    private:\n    size_t vertex_size_, edge_size_;\n    vector<vector<Edge<CostType>>>\
    \ adjacent_list_;\n};\n\ntemplate<typename CostType = int32_t>\nGraph<CostType>\
    \ InputGraph(int N, int M, int padding = -1, bool weighted = false, bool directed\
    \ = false){\n    Graph<CostType> G(N);\n    for(int i = 0; i < M; ++i){\n    \
    \    Vertex u, v; CostType w = 1;\n        cin >> u >> v, u += padding, v += padding;\n\
    \        if(weighted) cin >> w;\n        if(directed) G.AddDirectedEdge(u, v,\
    \ w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n#line\
    \ 4 \"Library/Graph/Dijkstra.hpp\"\n\ntemplate<typename CostType>\nclass Dijkstra{\n\
    \    public:\n    Dijkstra(Graph<CostType> &graph, Vertex s = -1) :\n        G(graph),\
    \ n(graph.VertexSize()), dist_(n), prev_edge_(n){\n        if(s != -1) Solve(s);\n\
    \    }\n\n    inline bool Reachable(const Vertex &t) const {\n        return dist_[t]\
    \ != inf;\n    }\n\n    inline CostType Distance(const Vertex &t) const {\n  \
    \      return dist_[t];\n    }\n\n    vector<Edge<CostType>> Path(const Vertex\
    \ &t) const {\n        if(!Reachable(t)) return vector<Edge<CostType>>{};\n  \
    \      vector<Edge<CostType>> ret;\n        int v = t;\n        while(1){\n  \
    \          if(prev_edge_[v].from == -1) break;\n            ret.push_back(prev_edge_[v]);\n\
    \            v = prev_edge_[v].from;\n        }\n        reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n    void Solve(Vertex s){\n     \
    \   using P = pair<CostType, Vertex>;\n        fill(dist_.begin(), dist_.end(),\
    \ inf);\n        dist_[s] = CostType(0);\n        fill(prev_edge_.begin(), prev_edge_.end(),\
    \ Edge<CostType>{});\n        prev_edge_[s] = Edge<CostType>(-1, -1);\n      \
    \  priority_queue<P, vector<P>, greater<P>> que;\n        que.emplace(CostType(0),\
    \ s);\n        while(que.size()){\n            auto [d, u] = que.top(); que.pop();\n\
    \            if(dist_[u] != d) continue;\n            for(const Edge<CostType>\
    \ &e : G[u]){\n                if(dist_[e.to] > d + e.cost){\n               \
    \     dist_[e.to] = d + e.cost;\n                    prev_edge_[e.to] = e;\n \
    \                   que.emplace(dist_[e.to], e.to);\n                }\n     \
    \       }\n        }\n    }\n\n    inline CostType operator[](const Vertex &t){\n\
    \        return dist_[t];\n    }\n\n    inline const CostType operator[](const\
    \ Vertex &t) const {\n        return dist_[t];\n    }\n\n    private:\n    Graph<CostType>\
    \ &G;\n    int n;\n    Vertex source_;\n    CostType inf{CostType(INF)};\n   \
    \ vector<CostType> dist_;\n    vector<Edge<CostType>> prev_edge_;\n};\n#line 5\
    \ \"verify/AOJ-GRL-1-A.test.cpp\"\n\nint main(){\n    int V, E, r; cin >> V >>\
    \ E >> r;\n    auto G = InputGraph<ll>(V, E, 0, true, true);\n    \n    Dijkstra\
    \ dk(G, r);\n    for(int i = 0; i < V; ++i){\n        if(dk.Reachable(i)){\n \
    \           cout << dk.Distance(i) << endl;\n        }\n        else{\n      \
    \      cout << \"INF\" << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/Graph/Dijkstra.hpp\"\
    \n\nint main(){\n    int V, E, r; cin >> V >> E >> r;\n    auto G = InputGraph<ll>(V,\
    \ E, 0, true, true);\n    \n    Dijkstra dk(G, r);\n    for(int i = 0; i < V;\
    \ ++i){\n        if(dk.Reachable(i)){\n            cout << dk.Distance(i) << endl;\n\
    \        }\n        else{\n            cout << \"INF\" << endl;\n        }\n \
    \   }\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/Graph/Dijkstra.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-1-A.test.cpp
  requiredBy: []
  timestamp: '2025-04-25 02:08:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-GRL-1-A.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-1-A.test.cpp
- /verify/verify/AOJ-GRL-1-A.test.cpp.html
title: verify/AOJ-GRL-1-A.test.cpp
---
