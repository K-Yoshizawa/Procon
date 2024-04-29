---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/Dijkstra.hpp
    title: "Dijkstra - \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/LC-ShortestPath.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
    \n\n#line 1 \"library/Graph/Dijkstra.hpp\"\n/**\n * @file Dijkstra.hpp\n * @brief\
    \ Dijkstra - \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @version 3.1\n * @date\
    \ 2024-02-11\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\n\n/**\n * @file\
    \ GraphTemplate.hpp\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\n * @version 3.0\n * @date 2024-01-09\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    public:\n    Vertex from, to;\n    CostType cost;\n\
    \    int loc{-1}, id{-1};\n\n    Edge() = default;\n    Edge(Vertex from, Vertex\
    \ to, CostType cost) : from(from), to(to), cost(cost){}\n\n    operator int(){\n\
    \        return to;\n    }\n};\n\ntemplate<typename CostType = int>\nstruct Graph{\n\
    \    private:\n    int vertex_size_{0}, edge_size_{0};\n    bool is_directed_{false},\
    \ is_weighted_{false};\n    vector<vector<Edge<CostType>>> adj_;\n    vector<int>\
    \ indegree_;\n\n    public:\n    CostType INF{numeric_limits<CostType>::max()\
    \ >> 2};\n\n    Graph() = default;\n\n    /**\n     * @brief `vertex_size` \u9802\
    \u70B9 `0` \u8FBA\u306E\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\u3002\n\
    \     * @note `directed` \u3092 `true` \u306B\u3059\u308B\u3068\u6709\u5411\u30B0\
    \u30E9\u30D5\u306B\u306A\u308B\u3002\n     * @param vertex_size \u9802\u70B9\u6570\
    \n     * @param directed \u6709\u5411\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\
    \u308B\u304B (option, default = `false`)\n     */\n    Graph(int vertex_size,\
    \ bool directed = false) : vertex_size_(vertex_size), is_directed_(directed){\n\
    \        adj_.resize(vertex_size);\n        indegree_.resize(vertex_size, 0);\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `from` \u304B\u3089\u9802\u70B9\
    \ `to` \u306B\u8FBA\u3092\u5F35\u308B\u3002\n     * @note `cost` \u3092\u6307\u5B9A\
    \u3059\u308B\u3053\u3068\u3067\u91CD\u307F\u3092\u3064\u3051\u308B\u3053\u3068\
    \u304C\u3067\u304D\u308B\u3002\n     * @param from \u9802\u70B9\u756A\u53F7\n\
    \     * @param to \u9802\u70B9\u756A\u53F7\n     * @param cost \u91CD\u307F (option,\
    \ default = `1`)\n     */\n    void add(Vertex from, Vertex to, CostType cost\
    \ = 1){\n        assert(0 <= from and from < vertex_size_);\n        assert(0\
    \ <= to and to < vertex_size_);\n        is_weighted_ |= cost > 1;\n        Edge<CostType>\
    \ e1(from, to, cost);\n        e1.loc = adj_[from].size();\n        e1.id = edge_size_;\n\
    \        adj_[from].push_back(e1);\n        ++edge_size_;\n        if(is_directed_){\n\
    \            ++indegree_[to];\n            return;\n        }\n        Edge<CostType>\
    \ e2(to, from, cost);\n        e2.loc = adj_[to].size();\n        e2.id = e1.id;\n\
    \        adj_[to].push_back(e2);\n    }\n\n    /**\n     * @brief \u30B0\u30E9\
    \u30D5\u306B `edge_size` \u672C\u306E\u8FBA\u3092\u5165\u529B\u3055\u305B\u308B\
    \u3002\n     * @param edge_size \u5165\u529B\u3059\u308B\u8FBA\u6570\n     * @param\
    \ weighted \u91CD\u307F\u4ED8\u304D\u8FBA\u304B (option, default = `false`)\n\
    \     * @param zero_index \u5165\u529B\u306E\u9802\u70B9\u756A\u53F7\u304C 0-index\
    \ \u304B (option, default = `false`)\n     */\n    void input(int edge_size, bool\
    \ weighted = false, bool zero_index = false){\n        is_weighted_ = weighted;\n\
    \        for(int i = 0; i < edge_size; ++i){\n            Vertex s, t; cin >>\
    \ s >> t;\n            if(!zero_index) --s, --t;\n            CostType c = 1;\n\
    \            if(weighted) cin >> c;\n            add(s, t, c);\n        }\n  \
    \  }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\u3092\
    \u8FD4\u3059\u3002\n     * @return size_t \u9802\u70B9\u6570\n     */\n    size_t\
    \ size(){\n        return vertex_size_;\n    }\n\n    /**\n     * @brief \u9802\
    \u70B9 `v` \u306E\u51FA\u6B21\u6570\u3092\u8FD4\u3059\u3002\n     * @param v \u9802\
    \u70B9\u756A\u53F7\n     * @return int \u9802\u70B9 `v` \u306E\u51FA\u6B21\u6570\
    \n     */\n    int outdegree(Vertex v){\n        return (int)adj_.at(v).size();\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E\u5165\u6B21\u6570\u3092\
    \u8FD4\u3059\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return int\
    \ \u9802\u70B9 `v` \u306E\u5165\u6B21\u6570\n     */\n    int indegree(Vertex\
    \ v){\n        if(is_directed_) return indegree_.at(v);\n        else return (int)adj_.at(v).size();\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u304C\u6709\u5411\u30B0\u30E9\
    \u30D5\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\u3002\n     */\n    bool is_directed(){\n\
    \        return is_directed_;\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\
    \u304C\u91CD\u307F\u4ED8\u304D\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\u3002\
    \n     */\n    bool is_weighted(){\n        return is_weighted_;\n    }\n\n  \
    \  vector<Vertex> source(){\n        assert(is_directed_);\n        vector<Vertex>\
    \ ret;\n        for(int i = 0; i < vertex_size_; ++i){\n            if(indegree(i)\
    \ == 0) ret.push_back(i);\n        }\n        return ret;\n    }\n\n    vector<Vertex>\
    \ sink(){\n        vector<Vertex> ret;\n        for(int i = 0; i < vertex_size_;\
    \ ++i){\n            if(outdegree(i) == 0) ret.push_back(i);\n        }\n    \
    \    return ret;\n    }\n\n    vector<Vertex> leaf(){\n        vector<Vertex>\
    \ ret;\n        for(int i = 0; i < vertex_size_; ++i){\n            if(indegree(i)\
    \ == 1) ret.push_back(i);\n        }\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u9802\u70B9 `v` \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u3092\u8FD4\
    \u3059\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return vector<Edge<CostType>>&\
    \ \u9802\u70B9 `v` \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\n     */\n    vector<Edge<CostType>>\
    \ &get_adj(Vertex v){\n        return adj_.at(v);\n    }\n\n    /**\n     * @brief\
    \ \u8FBA\u306E\u5411\u304D\u3092\u3059\u3079\u3066\u9006\u306B\u3057\u305F\u30B0\
    \u30E9\u30D5\u3092\u8FD4\u3059\u3002\n     * @attention \u6709\u5411\u30B0\u30E9\
    \u30D5\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u4EF6\u3068\u3059\u308B\u3002\
    \n     * @return Graph<CostType> \u9006\u8FBA\u30B0\u30E9\u30D5\n     */\n   \
    \ Graph<CostType> reverse(){\n        assert(is_directed_);\n        Graph ret(vertex_size_,\
    \ true);\n        for(auto es : adj_){\n            for(auto e : es){\n      \
    \          ret.add(e.to, e.from, e.cost);\n            }\n        }\n        return\
    \ ret;\n    }\n\n    /**\n     * @brief \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8\u3057\u305F\u9802\u70B9\u5217\u3092\u8FD4\u3059\u3002\n     * @attention\
    \ \u6709\u5411\u30B0\u30E9\u30D5\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u4EF6\
    \u3068\u3059\u308B\u3002\n     * @return vector<Vertex> \u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8\u3057\u305F\u9802\u70B9\u5217\n     */\n    vector<Vertex>\
    \ topological_sort(){\n        assert(is_directed_);\n        vector<Vertex> ret;\n\
    \        queue<Vertex> que;\n        vector<int> cnt(vertex_size_, 0);\n     \
    \   for(auto v : source()) que.push(v);\n        while(que.size()){\n        \
    \    Vertex v = que.front(); que.pop();\n            ret.push_back(v);\n     \
    \       for(int u : adj_[v]){\n                if(++cnt[u] == indegree(u)) que.push(u);\n\
    \            }\n        }\n        return ret;\n    }\n\n    /**\n     * @brief\
    \ \u30B0\u30E9\u30D5\u304B\u3089\u8FBA\u96C6\u5408\u3092\u4F5C\u6210\u3059\u308B\
    \u3002\n     * @note \u8FBA\u96C6\u5408\u306F\u91CD\u307F\u3067\u6607\u9806\u30BD\
    \u30FC\u30C8\u3055\u308C\u305F\u72B6\u614B\u3067\u8FD4\u3055\u308C\u308B\u3002\
    \n     * @return vector<Edge<CostType>> \u8FBA\u96C6\u5408\n     */\n    vector<Edge<CostType>>\
    \ edge_set(){\n        vector<Edge<CostType>> ret;\n        vector<int> es(edge_size_,\
    \ 0);\n        for(int i = 0; i < vertex_size_; ++i){\n            for(auto e\
    \ : adj_[i]){\n                if(es[e.id]) continue;\n                es[e.id]\
    \ = 1;\n                ret.push_back(e);\n            }\n        }\n        sort(ret.begin(),\
    \ ret.end(), [&](Edge<CostType> &l, Edge<CostType> &r){\n            return l.cost\
    \ < r.cost;\n        });\n        return ret;\n    }\n\n    vector<vector<CostType>>\
    \ matrix(){\n        int n = vertex_size_;\n        vector<vector<CostType>> ret(n,\
    \ vector<CostType>(n, INF));\n        for(int i = 0; i < n; ++i) ret[i][i] = 0;\n\
    \        for(int v = 0; v < n; ++v){\n            for(auto &e : adj_[v]){\n  \
    \              ret[v][e.to] = e.cost;\n            }\n        }\n        return\
    \ ret;\n    }\n\n    friend ostream &operator<<(ostream &os, Graph<CostType> &G){\n\
    \        for(int i = 0; i < G.size(); ++i){\n            os << \"Vertex \" <<\
    \ i << \" : \";\n            if(G[i].empty()){\n                os << \"<none>\"\
    \ << endl;\n                continue;\n            }\n            for(auto &e\
    \ : G[i]){\n                if(G.is_weighted()) os << \"{\" << e.to << \", \"\
    \ << e.cost << \"} \";\n                else os << e.to << \" \";\n          \
    \  }\n            if(i + 1 < G.size()) os << endl;\n        }\n        return\
    \ os;\n    }\n\n    vector<Edge<CostType>> &operator[](Vertex v){\n        return\
    \ get_adj(v);\n    }\n};\n#line 9 \"library/Graph/Dijkstra.hpp\"\n\ntemplate<typename\
    \ CostType>\nstruct Dijkstra{\n    private:\n    Graph<CostType> &G;\n    vector<CostType>\
    \ dist_, potential_;\n    vector<Vertex> prev_vertex_;\n\n    public:\n    Dijkstra(Graph<CostType>\
    \ &G) : G(G){\n        dist_.resize(G.size());\n        potential_.resize(G.size(),\
    \ 0);\n        prev_vertex_.resize(G.size(), -1);\n    }\n\n    vector<CostType>\
    \ &solve(Vertex s){\n        assert(0 <= s and s < G.size());\n        dist_.assign(G.size(),\
    \ G.INF);\n        using p = pair<CostType, Vertex>;\n        priority_queue<p,\
    \ vector<p>, greater<p>> que;\n        que.emplace(potential_[s], s);\n      \
    \  dist_[s] = potential_[s];\n        while(que.size()){\n            auto [d,\
    \ v] = que.top(); que.pop();\n            if(dist_[v] < d) continue;\n       \
    \     for(auto &e : G[v]){\n                if(d + e.cost + potential_[e.from]\
    \ - potential_[e.to] < dist_[e.to]){\n                    dist_[e.to] = d + e.cost\
    \ + potential_[e.from] - potential_[e.to];\n                    prev_vertex_[e.to]\
    \ = v;\n                    que.emplace(dist_[e.to], e.to);\n                }\n\
    \            }\n        }\n        for(Vertex i = 0; i < G.size(); ++i){\n   \
    \         if(dist_[i] != G.INF){\n                dist_[i] += potential_[i] -\
    \ potential_[s];\n            }\n        }\n        return dist_;\n    }\n\n \
    \   void update_potential(vector<CostType> &potential){\n        assert(potential.size()\
    \ == G.size());\n        potential_ = potential;\n    }\n\n    vector<CostType>\
    \ &get(){\n        return dist_;\n    }\n\n    vector<CostType> shortest_path(Vertex\
    \ t){\n        vector<CostType> ret{t};\n        Vertex now = t;\n        while(prev_vertex_[now]\
    \ != -1){\n            ret.push_back(prev_vertex_[now]);\n            now = prev_vertex_[now];\n\
    \        }\n        reverse(ret.begin(), ret.end());\n        return ret;\n  \
    \  }\n\n    CostType operator[](Vertex v){\n        return dist_.at(v);\n    }\n\
    };\n#line 4 \"verify/LC-ShortestPath.test.cpp\"\n\nint main(){\n    int N, M,\
    \ s, t; cin >> N >> M >> s >> t;\n    Graph<long long> G(N, true);\n    G.input(M,\
    \ true, true);\n\n    Dijkstra dk(G);\n    if(dk.solve(s)[t] == G.INF){\n    \
    \    cout << -1 << endl;\n        return 0;\n    }\n    auto ans = dk.shortest_path(t);\n\
    \    cout << dk[t] << \" \" << ans.size() - 1 << endl;\n    for(int i = 0; i <\
    \ ans.size() - 1; ++i){\n        cout << ans[i] << \" \" << ans[i + 1] << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../library/Graph/Dijkstra.hpp\"\n\nint main(){\n    int N, M, s, t; cin >>\
    \ N >> M >> s >> t;\n    Graph<long long> G(N, true);\n    G.input(M, true, true);\n\
    \n    Dijkstra dk(G);\n    if(dk.solve(s)[t] == G.INF){\n        cout << -1 <<\
    \ endl;\n        return 0;\n    }\n    auto ans = dk.shortest_path(t);\n    cout\
    \ << dk[t] << \" \" << ans.size() - 1 << endl;\n    for(int i = 0; i < ans.size()\
    \ - 1; ++i){\n        cout << ans[i] << \" \" << ans[i + 1] << endl;\n    }\n}"
  dependsOn:
  - library/Graph/Dijkstra.hpp
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify/LC-ShortestPath.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 19:12:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-ShortestPath.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-ShortestPath.test.cpp
- /verify/verify/LC-ShortestPath.test.cpp.html
title: verify/LC-ShortestPath.test.cpp
---
