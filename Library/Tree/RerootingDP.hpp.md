---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u69CB\u9020"
  - icon: ':question:'
    path: Library/Tree/Tree.hpp
    title: Library/Tree/Tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/LC-TreePathCompositeSum.test.cpp
    title: verify/LC-TreePathCompositeSum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Tree/Tree.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n#include <cassert>\n\
    #include <cmath>\n#include <cstdint>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const ll INF = (1LL\
    \ << 62) - (3LL << 30) - 1;\n#line 4 \"Library/Graph/Graph.hpp\"\n\nusing Vertex\
    \ = int;\n\ntemplate<typename Ordered = int32_t>\nstruct Edge{\n    public:\n\
    \    Edge() = default;\n\n    Edge(Vertex from_, Vertex to_, Ordered weight_ =\
    \ 1, int idx_ = -1) :\n        from(from_), to(to_), cost(weight_), idx(idx_){}\n\
    \    \n    bool operator<(const Edge<Ordered> &e) const {return cost < e.cost;}\n\
    \n    operator int() const {return to;}\n\n    Vertex from, to;\n    Ordered cost;\n\
    \    int idx;\n};\n\ntemplate<typename Ordered = int32_t>\nclass Graph{\n    public:\n\
    \    Graph() = default;\n\n    Graph(int V) : edge_size_(0), adjacent_list_(V){}\n\
    \    \n    inline void AddUndirectedEdge(Vertex u, Vertex v, Ordered w = 1){\n\
    \        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<Ordered>(u,\
    \ v, w, idx));\n        adjacent_list_[v].push_back(Edge<Ordered>(v, u, w, idx));\n\
    \    }\n    \n    inline void AddDirectedEdge(Vertex u, Vertex v, Ordered w =\
    \ 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<Ordered>(u,\
    \ v, w, idx));\n    }\n\n    inline size_t VertexSize() const {\n        return\
    \ adjacent_list_.size();\n    }\n\n    inline size_t EdgeSize() const {\n    \
    \    return edge_size_;\n    }\n\n    inline vector<Edge<Ordered>> &operator[](const\
    \ Vertex v){\n        return adjacent_list_[v];\n    }\n\n    inline const vector<Edge<Ordered>>\
    \ &operator[](const Vertex v) const {\n        return adjacent_list_[v];\n   \
    \ }\n    \n    private:\n    size_t edge_size_;\n    vector<vector<Edge<Ordered>>>\
    \ adjacent_list_;\n};\n\ntemplate<typename Ordered = int32_t>\nGraph<Ordered>\
    \ InputGraph(int V, int E, int padding = -1, bool weighted = false, bool directed\
    \ = false){\n    Graph<Ordered> G(V);\n    for(int i = 0; i < E; ++i){\n     \
    \   Vertex u, v; Ordered w = 1;\n        cin >> u >> v, u += padding, v += padding;\n\
    \        if(weighted) cin >> w;\n        if(directed) G.AddDirectedEdge(u, v,\
    \ w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n#line\
    \ 4 \"Library/Tree/Tree.hpp\"\n\ntemplate<typename Ordered = int32_t>\nGraph<Ordered>\
    \ InputTree(int V, int padding = -1, bool weighted = false){\n    Graph<Ordered>\
    \ G(V);\n    for(int i = 0; i < V - 1; ++i){\n        Vertex u, v; Ordered w =\
    \ 1;\n        cin >> u >> v, u += padding, v += padding;\n        if(weighted)\
    \ cin >> w;\n        G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n\n\
    template<typename Ordered = int32_t>\nGraph<Ordered> InputRootedTreeChild(int\
    \ V, int padding = -1){\n    Graph<Ordered> G(V);\n    for(Vertex u = 0; u < V;\
    \ ++u){\n        int k; cin >> k;\n        for(int i = 0; i < k; ++i){\n     \
    \       Vertex v; cin >> v, v += padding;\n            G.AddUndirectedEdge(u,\
    \ v);\n        }\n    }\n    return G;\n}\n\ntemplate<typename Ordered = int32_t>\n\
    Graph<Ordered> InputRootedTreeParent(int V, int padding = -1){\n    Graph<Ordered>\
    \ G(V);\n    for(Vertex u = 1; u < V; ++u){\n        Vertex v; cin >> v, v +=\
    \ padding;\n        G.AddUndirectedEdge(u, v);\n    }\n    return G;\n}\n\ntemplate<typename\
    \ Ordered = int32_t>\nvector<vector<Vertex>> RootedTreeAdjacentList(const Graph<Ordered>\
    \ &T, const Vertex r = 0){\n    int V = T.VertexSize();\n    vector<vector<Vertex>>\
    \ ret(V);\n    auto rec = [&](auto &self, Vertex u, Vertex p) -> void {\n    \
    \    for(Vertex v : T[u]){\n            if(v == p) continue;\n            ret[u].push_back(v);\n\
    \            self(self, v, u);\n        }\n    };\n    rec(rec, r, -1);\n    return\
    \ ret;\n}\n\ntemplate<typename Ordered>\nvector<Vertex> CalculateTreeParent(Graph<Ordered>\
    \ &T, Vertex r = 0){\n    int V = T.VertexSize();\n    vector<Vertex> ret(V, -1);\n\
    \    auto rec = [&](auto &self, Vertex u) -> void {\n        for(Vertex v : T[u]){\n\
    \            if(v == ret[u]) continue;\n            ret[v] = u;\n            self(self,\
    \ v);\n        }\n    };\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ Ordered>\nvector<Ordered> CalculateTreeCost(Graph<Ordered> &T, Vertex r = 0){\n\
    \    int V = T.VertexSize();\n    vector<Ordered> ret(V);\n    auto rec = [&](auto\
    \ &self, Vertex u, Vertex p) -> void {\n        for(const Edge<Ordered> &e : T[u]){\n\
    \            Vertex v = e.to;\n            if(v == p) continue;\n            ret[v]\
    \ = e.cost;\n            self(self, v, u);\n        }\n    };\n    rec(rec, r,\
    \ -1);\n    return ret;\n}\n\ntemplate<typename Ordered>\nvector<int> CalculateTreeDepth(Graph<Ordered>\
    \ &T, Vertex r = 0){\n    int V = T.VertexSize();\n    vector<int> ret(V, 0);\n\
    \    auto rec = [&](auto &self, Vertex u, Vertex p, int d) -> void {\n       \
    \ ret[u] = d;\n        for(Vertex v : T[u]){\n            if(v == p) continue;\n\
    \            self(self, v, u, d + 1);\n        }\n    };\n    rec(rec, r, -1,\
    \ 0);\n    return ret;\n}\n\ntemplate<typename Ordered>\nvector<Ordered> CalculateTreeDistance(Graph<Ordered>\
    \ &T, Vertex r = 0){\n    int V = T.VertexSize();\n    vector<Ordered> ret(V,\
    \ Ordered(INF));\n    auto rec = [&](auto &self, Vertex u) -> void {\n       \
    \ for(const Edge<Ordered> &e : T[u]){\n            if(ret[e.to] > ret[u] + e.cost){\n\
    \                ret[e.to] = ret[u] + e.cost;\n                self(self, e.to);\n\
    \            }\n        }\n    };\n    ret[r] = 0;\n    rec(rec, r);\n    return\
    \ ret;\n}\n\ntemplate<typename Ordered>\nvector<int> CalculateSubtreeSize(Graph<Ordered>\
    \ &tree, Vertex r = 0){\n    int V = tree.VertexSize();\n    vector<int> ret(V,\
    \ 1);\n    auto rec = [&](auto self, Vertex u, Vertex p) -> int {\n        for(const\
    \ int v : tree[u]){\n            if(v == p) continue;\n            ret[u] += self(self,\
    \ v, u);\n        }\n        return ret[u];\n    };\n    rec(rec, r, -1);\n  \
    \  return ret;\n}\n#line 2 \"Library/Tree/RerootingDP.hpp\"\n\ntemplate<typename\
    \ Ordered, typename Monoid>\nclass RerootingDP{\n    public:\n    using F = function<Monoid(Monoid,\
    \ Monoid, Vertex)>;\n    using G = function<Monoid(Monoid, Ordered, Vertex)>;\n\
    \    using H = function<Monoid(Monoid, Vertex)>;\n    using Fsub = function<Monoid(Monoid,\
    \ Monoid)>;\n    using Gsub = function<Monoid(Monoid, Ordered)>;\n\n    RerootingDP(Graph<Ordered>\
    \ &T, Fsub merge, Gsub add, const Monoid monoid_identity, Vertex r = 0) :\n  \
    \          T(T), V(T.VertexSize()), parent(CalculateTreeParent(T, r)), cost(CalculateTreeCost(T,\
    \ r)), child(RootedTreeAdjacentList(T, r)),\n            merge_sub_(merge), add_sub_(add),\
    \ id_(monoid_identity){\n        merge_ = [&](Monoid x, Monoid y, Vertex i){return\
    \ merge_sub_(x, y);};\n        add_ = [&](Monoid x, Ordered y, Vertex i){return\
    \ add_sub_(x, y);};\n        finalize_ = [](Monoid x, Vertex i){return x;};\n\
    \        solve(r);\n    }\n\n    RerootingDP(Graph<Ordered> &T, F merge, G add,\
    \ H finalize, const Monoid monoid_identity, Vertex r = 0) :\n            T(T),\
    \ V(T.VertexSize()), parent(CalculateTreeParent(T, r)), cost(CalculateTreeCost(T,\
    \ r)), child(RootedTreeAdjacentList(T, r)),\n            merge_(merge), add_(add),\
    \ finalize_(finalize), id_(monoid_identity){\n        solve(r);\n    }\n\n   \
    \ vector<Monoid> &GetAllAnswer(){\n        return dp_;\n    }\n\n    Monoid operator[](Vertex\
    \ v){\n        return dp_[v];\n    }\n\n    const Monoid operator[](Vertex v)\
    \ const {\n        return dp_[v];\n    }\n\n    void Print() const {\n       \
    \ cerr << \"# dp table :\";\n        for(int i = 0; i < V; ++i){\n           \
    \ cerr << \" \" << dp_[i];\n        }\n        cerr << '\\n';\n        cerr <<\
    \ \"# subtree_dp table\" << '\\n';\n        for(int i = 0; i < V; ++i){\n    \
    \        cerr << \"# vertex \" << i << '\\n';\n            cerr << \"#    subtree_dp\
    \ :\";\n            for(int j = 0; j < subtree_dp_[i].size(); ++j){\n        \
    \        cerr << \" \" << subtree_dp_[i][j];\n            }\n            cerr\
    \ << '\\n';\n            cerr << \"#    left_cum   :\";\n            for(int j\
    \ = 0; j < left_cum_[i].size(); ++j){\n                cerr << \" \" << left_cum_[i][j];\n\
    \            }\n            cerr << '\\n';\n            cerr << \"#    right_cum\
    \  :\";\n            for(int j = 0; j < right_cum_[i].size(); ++j){\n        \
    \        cerr << \" \" << right_cum_[i][j];\n            }\n            cerr <<\
    \ '\\n';\n        }\n    }\n\n    private:\n    Graph<Ordered> &T;\n    int V;\n\
    \    vector<Vertex> parent;\n    vector<Ordered> cost;\n    vector<vector<Vertex>>\
    \ child;\n    \n    vector<Monoid> dp_;\n    vector<vector<Monoid>> subtree_dp_,\
    \ left_cum_, right_cum_;\n\n    const Monoid id_;\n\n    F merge_;\n    G add_;\n\
    \    H finalize_;\n    const Fsub merge_sub_;\n    const Gsub add_sub_;\n\n  \
    \  Monoid dfs(Vertex v, bool root = false){\n        Monoid ret = id_;\n     \
    \   for(auto u : child[v]){\n            Monoid res = dfs(u);\n            subtree_dp_[v].push_back(res);\n\
    \            ret = merge_(ret, res, v);\n        }\n        if(root) ret = finalize_(ret,\
    \ v);\n        else ret = add_(ret, cost[v], v);\n        return ret;\n    }\n\
    \n    void solve(Vertex r){\n        dp_.resize(V, id_);\n        subtree_dp_.resize(V,\
    \ vector<Monoid>{id_});\n        left_cum_.resize(V);\n        right_cum_.resize(V);\n\
    \n        dp_[r] = dfs(r, true);\n        int root_size = subtree_dp_[r].size();\n\
    \        left_cum_[r].resize(root_size + 1);\n        left_cum_[r].front() = id_;\n\
    \        for(int i = 1; i < root_size; ++i){\n            left_cum_[r][i] = merge_(left_cum_[r][i\
    \ - 1], subtree_dp_[r][i], r);\n        }\n        right_cum_[r].resize(root_size\
    \ + 1);\n        right_cum_[r].back() = id_;\n        for(int i = root_size -\
    \ 1; i - 1 >= 0; --i){\n            right_cum_[r][i] = merge_(right_cum_[r][i\
    \ + 1], subtree_dp_[r][i], r);\n        }\n\n        queue<tuple<int, int, int>>\
    \ que;\n        for(int i = 0; i < child[r].size(); ++i){\n            que.push({child[r][i],\
    \ r, i + 1});\n        }\n        while(que.size()){\n            auto [v, p,\
    \ idx] = que.front(); que.pop();\n            Monoid ret = id_;\n            ret\
    \ = merge_(ret, left_cum_[p][idx - 1], v);\n            ret = merge_(ret, right_cum_[p][idx\
    \ + 1], v);\n            ret = add_(ret, cost[v], p);\n            subtree_dp_[v].push_back(ret);\n\
    \            for(int i = 1; i + 1 < subtree_dp_[v].size(); ++i){\n           \
    \     ret = merge_(ret, subtree_dp_[v][i], v);\n            }\n            dp_[v]\
    \ = finalize_(ret, v);\n            int c = subtree_dp_[v].size();\n         \
    \   left_cum_[v].resize(c + 1);\n            left_cum_[v][0] = id_;\n        \
    \    for(int i = 1; i < c; ++i){\n                left_cum_[v][i] = merge_(left_cum_[v][i\
    \ - 1], subtree_dp_[v][i], v);\n            }\n            right_cum_[v].resize(c\
    \ + 1);\n            right_cum_[v].back() = id_;\n            for(int i = c -\
    \ 1; i - 1 >= 0; --i){\n                right_cum_[v][i] = merge_(right_cum_[v][i\
    \ + 1], subtree_dp_[v][i], v);\n            }\n            for(int i = 0; i <\
    \ child[v].size(); ++i){\n                que.push({child[v][i], v, i + 1});\n\
    \            }\n        }\n    }\n};\n"
  code: "#include \"Tree.hpp\"\n\ntemplate<typename Ordered, typename Monoid>\nclass\
    \ RerootingDP{\n    public:\n    using F = function<Monoid(Monoid, Monoid, Vertex)>;\n\
    \    using G = function<Monoid(Monoid, Ordered, Vertex)>;\n    using H = function<Monoid(Monoid,\
    \ Vertex)>;\n    using Fsub = function<Monoid(Monoid, Monoid)>;\n    using Gsub\
    \ = function<Monoid(Monoid, Ordered)>;\n\n    RerootingDP(Graph<Ordered> &T, Fsub\
    \ merge, Gsub add, const Monoid monoid_identity, Vertex r = 0) :\n           \
    \ T(T), V(T.VertexSize()), parent(CalculateTreeParent(T, r)), cost(CalculateTreeCost(T,\
    \ r)), child(RootedTreeAdjacentList(T, r)),\n            merge_sub_(merge), add_sub_(add),\
    \ id_(monoid_identity){\n        merge_ = [&](Monoid x, Monoid y, Vertex i){return\
    \ merge_sub_(x, y);};\n        add_ = [&](Monoid x, Ordered y, Vertex i){return\
    \ add_sub_(x, y);};\n        finalize_ = [](Monoid x, Vertex i){return x;};\n\
    \        solve(r);\n    }\n\n    RerootingDP(Graph<Ordered> &T, F merge, G add,\
    \ H finalize, const Monoid monoid_identity, Vertex r = 0) :\n            T(T),\
    \ V(T.VertexSize()), parent(CalculateTreeParent(T, r)), cost(CalculateTreeCost(T,\
    \ r)), child(RootedTreeAdjacentList(T, r)),\n            merge_(merge), add_(add),\
    \ finalize_(finalize), id_(monoid_identity){\n        solve(r);\n    }\n\n   \
    \ vector<Monoid> &GetAllAnswer(){\n        return dp_;\n    }\n\n    Monoid operator[](Vertex\
    \ v){\n        return dp_[v];\n    }\n\n    const Monoid operator[](Vertex v)\
    \ const {\n        return dp_[v];\n    }\n\n    void Print() const {\n       \
    \ cerr << \"# dp table :\";\n        for(int i = 0; i < V; ++i){\n           \
    \ cerr << \" \" << dp_[i];\n        }\n        cerr << '\\n';\n        cerr <<\
    \ \"# subtree_dp table\" << '\\n';\n        for(int i = 0; i < V; ++i){\n    \
    \        cerr << \"# vertex \" << i << '\\n';\n            cerr << \"#    subtree_dp\
    \ :\";\n            for(int j = 0; j < subtree_dp_[i].size(); ++j){\n        \
    \        cerr << \" \" << subtree_dp_[i][j];\n            }\n            cerr\
    \ << '\\n';\n            cerr << \"#    left_cum   :\";\n            for(int j\
    \ = 0; j < left_cum_[i].size(); ++j){\n                cerr << \" \" << left_cum_[i][j];\n\
    \            }\n            cerr << '\\n';\n            cerr << \"#    right_cum\
    \  :\";\n            for(int j = 0; j < right_cum_[i].size(); ++j){\n        \
    \        cerr << \" \" << right_cum_[i][j];\n            }\n            cerr <<\
    \ '\\n';\n        }\n    }\n\n    private:\n    Graph<Ordered> &T;\n    int V;\n\
    \    vector<Vertex> parent;\n    vector<Ordered> cost;\n    vector<vector<Vertex>>\
    \ child;\n    \n    vector<Monoid> dp_;\n    vector<vector<Monoid>> subtree_dp_,\
    \ left_cum_, right_cum_;\n\n    const Monoid id_;\n\n    F merge_;\n    G add_;\n\
    \    H finalize_;\n    const Fsub merge_sub_;\n    const Gsub add_sub_;\n\n  \
    \  Monoid dfs(Vertex v, bool root = false){\n        Monoid ret = id_;\n     \
    \   for(auto u : child[v]){\n            Monoid res = dfs(u);\n            subtree_dp_[v].push_back(res);\n\
    \            ret = merge_(ret, res, v);\n        }\n        if(root) ret = finalize_(ret,\
    \ v);\n        else ret = add_(ret, cost[v], v);\n        return ret;\n    }\n\
    \n    void solve(Vertex r){\n        dp_.resize(V, id_);\n        subtree_dp_.resize(V,\
    \ vector<Monoid>{id_});\n        left_cum_.resize(V);\n        right_cum_.resize(V);\n\
    \n        dp_[r] = dfs(r, true);\n        int root_size = subtree_dp_[r].size();\n\
    \        left_cum_[r].resize(root_size + 1);\n        left_cum_[r].front() = id_;\n\
    \        for(int i = 1; i < root_size; ++i){\n            left_cum_[r][i] = merge_(left_cum_[r][i\
    \ - 1], subtree_dp_[r][i], r);\n        }\n        right_cum_[r].resize(root_size\
    \ + 1);\n        right_cum_[r].back() = id_;\n        for(int i = root_size -\
    \ 1; i - 1 >= 0; --i){\n            right_cum_[r][i] = merge_(right_cum_[r][i\
    \ + 1], subtree_dp_[r][i], r);\n        }\n\n        queue<tuple<int, int, int>>\
    \ que;\n        for(int i = 0; i < child[r].size(); ++i){\n            que.push({child[r][i],\
    \ r, i + 1});\n        }\n        while(que.size()){\n            auto [v, p,\
    \ idx] = que.front(); que.pop();\n            Monoid ret = id_;\n            ret\
    \ = merge_(ret, left_cum_[p][idx - 1], v);\n            ret = merge_(ret, right_cum_[p][idx\
    \ + 1], v);\n            ret = add_(ret, cost[v], p);\n            subtree_dp_[v].push_back(ret);\n\
    \            for(int i = 1; i + 1 < subtree_dp_[v].size(); ++i){\n           \
    \     ret = merge_(ret, subtree_dp_[v][i], v);\n            }\n            dp_[v]\
    \ = finalize_(ret, v);\n            int c = subtree_dp_[v].size();\n         \
    \   left_cum_[v].resize(c + 1);\n            left_cum_[v][0] = id_;\n        \
    \    for(int i = 1; i < c; ++i){\n                left_cum_[v][i] = merge_(left_cum_[v][i\
    \ - 1], subtree_dp_[v][i], v);\n            }\n            right_cum_[v].resize(c\
    \ + 1);\n            right_cum_[v].back() = id_;\n            for(int i = c -\
    \ 1; i - 1 >= 0; --i){\n                right_cum_[v][i] = merge_(right_cum_[v][i\
    \ + 1], subtree_dp_[v][i], v);\n            }\n            for(int i = 0; i <\
    \ child[v].size(); ++i){\n                que.push({child[v][i], v, i + 1});\n\
    \            }\n        }\n    }\n};"
  dependsOn:
  - Library/Tree/Tree.hpp
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Tree/RerootingDP.hpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/LC-TreePathCompositeSum.test.cpp
documentation_of: Library/Tree/RerootingDP.hpp
layout: document
redirect_from:
- /library/Library/Tree/RerootingDP.hpp
- /library/Library/Tree/RerootingDP.hpp.html
title: Library/Tree/RerootingDP.hpp
---
