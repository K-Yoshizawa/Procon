---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u69CB\u9020"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/LowestCommonAncestor.hpp
    title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728"
  - icon: ':warning:'
    path: Library/unauthenticated/EulerTour.hpp
    title: Library/unauthenticated/EulerTour.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Tree/Tree.hpp\"\n\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 4 \"Library/Graph/Graph.hpp\"\n\nusing Vertex = int;\n\ntemplate<typename\
    \ WeightType = int32_t>\nstruct Edge{\n    public:\n    Edge() = default;\n\n\
    \    Edge(Vertex from_, Vertex to_, WeightType weight_ = 1, int idx_ = -1) :\n\
    \        from(from_), to(to_), cost(weight_), idx(idx_){}\n    \n    bool operator<(const\
    \ Edge<WeightType> &e) const {return cost < e.cost;}\n\n    operator int() const\
    \ {return to;}\n\n    Vertex from, to;\n    WeightType cost;\n    int idx;\n};\n\
    \ntemplate<typename WeightType = int32_t>\nclass Graph{\n    public:\n    Graph()\
    \ = default;\n\n    Graph(int V) : edge_size_(0), adjacent_list_(V){}\n    \n\
    \    inline void AddUndirectedEdge(Vertex u, Vertex v, WeightType w = 1){\n  \
    \      int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<WeightType>(u,\
    \ v, w, idx));\n        adjacent_list_[v].push_back(Edge<WeightType>(v, u, w,\
    \ idx));\n    }\n    \n    inline void AddDirectedEdge(Vertex u, Vertex v, WeightType\
    \ w = 1){\n        int idx = edge_size_++;\n        adjacent_list_[u].push_back(Edge<WeightType>(u,\
    \ v, w, idx));\n    }\n\n    inline size_t VertexSize() const {\n        return\
    \ adjacent_list_.size();\n    }\n\n    inline size_t EdgeSize() const {\n    \
    \    return edge_size_;\n    }\n\n    inline vector<Edge<WeightType>> &operator[](const\
    \ Vertex v){\n        return adjacent_list_[v];\n    }\n\n    inline const vector<Edge<WeightType>>\
    \ &operator[](const Vertex v) const {\n        return adjacent_list_[v];\n   \
    \ }\n    \n    private:\n    size_t edge_size_;\n    vector<vector<Edge<WeightType>>>\
    \ adjacent_list_;\n};\n\ntemplate<typename WeightType = int32_t>\nGraph<WeightType>\
    \ InputGraph(int N, int M, int padding = -1, bool weighted = false, bool directed\
    \ = false){\n    Graph<WeightType> G(N);\n    for(int i = 0; i < M; ++i){\n  \
    \      Vertex u, v; WeightType w = 1;\n        cin >> u >> v, u += padding, v\
    \ += padding;\n        if(weighted) cin >> w;\n        if(directed) G.AddDirectedEdge(u,\
    \ v, w);\n        else G.AddUndirectedEdge(u, v, w);\n    }\n    return G;\n}\n\
    #line 4 \"Library/Tree/Tree.hpp\"\n\ntemplate<typename WeightType = int32_t>\n\
    Graph<WeightType> InputTree(int V, int padding = -1, bool weighted = false){\n\
    \    Graph<WeightType> G(V);\n    for(int i = 0; i < V - 1; ++i){\n        Vertex\
    \ u, v; WeightType w = 1;\n        cin >> u >> v, u += padding, v += padding;\n\
    \        if(weighted) cin >> w;\n        G.AddUndirectedEdge(u, v, w);\n    }\n\
    \    return G;\n}\n\ntemplate<typename WeightType = int32_t>\nGraph<WeightType>\
    \ InputRootedTreeChild(int V, int padding = -1){\n    Graph<WeightType> G(V);\n\
    \    for(Vertex u = 0; u < V; ++u){\n        int k; cin >> k;\n        for(int\
    \ i = 0; i < k; ++i){\n            Vertex v; cin >> v, v += padding;\n       \
    \     G.AddUndirectedEdge(u, v);\n        }\n    }\n    return G;\n}\n\ntemplate<typename\
    \ WeightType = int32_t>\nGraph<WeightType> InputRootedTreeParent(int V, int padding\
    \ = -1){\n    Graph<WeightType> G(V);\n    for(Vertex u = 1; u < V; ++u){\n  \
    \      Vertex v; cin >> v, v += padding;\n        G.AddUndirectedEdge(u, v);\n\
    \    }\n    return G;\n}\n\ntemplate<typename WeightType = int32_t>\nvector<vector<Vertex>>\
    \ RootedTreeAdjacentList(const Graph<WeightType> &T, const Vertex r = 0){\n  \
    \  int V = T.VertexSize();\n    vector<vector<Vertex>> ret(V);\n    auto rec =\
    \ [&](auto &self, Vertex u, Vertex p) -> void {\n        for(Vertex v : T[u]){\n\
    \            if(v == p) continue;\n            ret[u].push_back(v);\n        \
    \    self(self, v, u);\n        }\n    };\n    rec(rec, r, -1);\n    return ret;\n\
    }\n\ntemplate<typename WeightType>\nvector<Vertex> CalculateTreeParent(Graph<WeightType>\
    \ &T, Vertex r = 0){\n    int V = T.VertexSize();\n    vector<Vertex> ret(V, -1);\n\
    \    auto rec = [&](auto &self, Vertex u) -> void {\n        for(Vertex v : T[u]){\n\
    \            if(v == ret[u]) continue;\n            ret[v] = u;\n            self(self,\
    \ v);\n        }\n    };\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ WeightType>\nvector<WeightType> CalculateTreeCost(Graph<WeightType> &T, Vertex\
    \ r = 0){\n    int V = T.VertexSize();\n    vector<WeightType> ret(V);\n    auto\
    \ rec = [&](auto &self, Vertex u, Vertex p) -> void {\n        for(const Edge<WeightType>\
    \ &e : T[u]){\n            Vertex v = e.to;\n            if(v == p) continue;\n\
    \            ret[v] = e.cost;\n            self(self, v, u);\n        }\n    };\n\
    \    rec(rec, r, -1);\n    return ret;\n}\n\ntemplate<typename WeightType>\nvector<int>\
    \ CalculateTreeDepth(Graph<WeightType> &T, Vertex r = 0){\n    int V = T.VertexSize();\n\
    \    vector<int> ret(V, 0);\n    auto rec = [&](auto &self, Vertex u, Vertex p,\
    \ int d) -> void {\n        ret[u] = d;\n        for(Vertex v : T[u]){\n     \
    \       if(v == p) continue;\n            self(self, v, u, d + 1);\n        }\n\
    \    };\n    rec(rec, r, -1, 0);\n    return ret;\n}\n\ntemplate<typename WeightType>\n\
    vector<WeightType> CalculateTreeDistance(Graph<WeightType> &T, Vertex r = 0){\n\
    \    int V = T.VertexSize();\n    vector<WeightType> ret(V, WeightType(INF));\n\
    \    auto rec = [&](auto &self, Vertex u) -> void {\n        for(const Edge<WeightType>\
    \ &e : T[u]){\n            if(ret[e.to] > ret[u] + e.cost){\n                ret[e.to]\
    \ = ret[u] + e.cost;\n                self(self, e.to);\n            }\n     \
    \   }\n    };\n    ret[r] = 0;\n    rec(rec, r);\n    return ret;\n}\n\ntemplate<typename\
    \ WeightType>\nvector<int> CalculateSubtreeSize(Graph<WeightType> &tree, Vertex\
    \ r = 0){\n    int V = tree.VertexSize();\n    vector<int> ret(V, 1);\n    auto\
    \ rec = [&](auto self, Vertex u, Vertex p) -> int {\n        for(const int v :\
    \ tree[u]){\n            if(v == p) continue;\n            ret[u] += self(self,\
    \ v, u);\n        }\n        return ret[u];\n    };\n    rec(rec, r, -1);\n  \
    \  return ret;\n}\n#line 2 \"Library/unauthenticated/EulerTour.hpp\"\n\n#line\
    \ 5 \"Library/unauthenticated/EulerTour.hpp\"\n\ntemplate<typename WeightType>\n\
    class EulerTour{\n    public:\n    using F = function<WeightType(CostType)>;\n\
    \n    EulerTour(){}\n\n    EulerTour(RootedTree<WeightType> &T, bool one_index\
    \ = false) :\n            T(T),\n            vertex_size_(T.get_vertex_size()),\n\
    \            in_time_(T.get_vertex_size()),\n            out_time_(T.get_vertex_size()),\n\
    \            one_index_(one_index){\n        dfs(T.get_root());\n    }\n\n   \
    \ int GetIn(const Vertex v) const {\n        return in_time_.at(v - one_index_);\n\
    \    }\n\n    int GetOut(const Vertex v) const {\n        return out_time_.at(v\
    \ - one_index_);\n    }\n\n    pair<int, int> GetPair(const Vertex v) const {\n\
    \        return make_pair(in_time_.at(v - one_index_), out_time_.at(v - one_index_));\n\
    \    }\n\n    template<typename Type>\n    vector<Type> ConvertVector(const vector<Type>\
    \ &value, const F in_converter, const F out_converter){\n        vector<Type>\
    \ ret(2 * vertex_size_);\n        for(int i = 0; i < vertex_size_; ++i){\n   \
    \         int in_idx = in_time_.at(i), out_idx = out_time_.at(i);\n          \
    \  ret[in_idx] = in_converter(value.at(i));\n            ret[out_idx] = out_converter(value.at(i));\n\
    \        }\n        return ret;\n    }\n\n    private:\n    int time_{0}, one_index_,\
    \ vertex_size_;\n\n    RootedTree<WeightType> &T;\n    vector<int> in_time_, out_time_;\n\
    \n    void dfs(Vertex v){\n        in_time_[v] = time_++;\n        for(Vertex\
    \ c : T.get_child(v)){\n            dfs(c);\n        }\n        out_time_[v] =\
    \ time_++;\n    }\n};\n#line 2 \"Library/Tree/LowestCommonAncestor.hpp\"\n\n#line\
    \ 4 \"Library/Tree/LowestCommonAncestor.hpp\"\n\ntemplate<typename WeightType>\n\
    struct LowestCommonAncestor{\n    public:\n    LowestCommonAncestor(Graph<WeightType>\
    \ &tree) : T(tree), depth_(CalculateTreeDepth(tree)){\n        int V = T.VertexSize();\n\
    \        height_ = 1;\n        while((1 << height_) < V) ++height_;\n        auto\
    \ par = CalculateTreeParent(T);\n        parent_.resize(height_, vector<Vertex>(V,\
    \ -1));\n        for(Vertex i = 0; i < V; ++i){\n            parent_[0][i] = par[i];\n\
    \        }\n        for(int k = 0; k + 1 < height_; ++k){\n            for(Vertex\
    \ i = 0; i < V; ++i){\n                if(parent_[k][i] < 0) parent_[k + 1][i]\
    \ = -1;\n                else parent_[k + 1][i] = parent_[k][parent_[k][i]];\n\
    \            }\n        }\n    }\n\n    Vertex Query(Vertex u, Vertex v){\n  \
    \      if(depth_[u] < depth_[v]) swap(u, v);\n        for(int k = 0; k < height_;\
    \ ++k){\n            if((depth_[u] - depth_[v]) >> k & 1){\n                u\
    \ = parent_[k][u];\n            }\n        }\n        if(u == v) return u;\n \
    \       for(int k = height_ - 1; k >= 0; --k){\n            if(parent_[k][u] !=\
    \ parent_[k][v]){\n                u = parent_[k][u];\n                v = parent_[k][v];\n\
    \            }\n        }\n        return parent_[0][u];\n    }\n\n    private:\n\
    \    Graph<WeightType> &T;\n    int height_;\n    vector<int> depth_;\n    vector<vector<Vertex>>\
    \ parent_;\n};\n#line 4 \"Library/unauthenticated/AuxiliaryTree.hpp\"\n\ntemplate<typename\
    \ WeightType>\nclass AuxiliaryTree{\n    public:\n    AuxiliaryTree(RootedTree<WeightType>\
    \ &tree) :\n            T(tree), lca_(tree), et_(tree), edge_cum_(CalculateTreeCumlativeSum(tree)){\n\
    \    }\n\n    void Set(const vector<Vertex> &vertex_set){\n        auxiliary_tree_vertex_set_\
    \ = vertex_set;\n        auxiliary_tree_size_ = auxiliary_tree_vertex_set_.size();\n\
    \        sort(auxiliary_tree_vertex_set_.begin(), auxiliary_tree_vertex_set_.end(),\
    \ [&](int i, int j){\n            return et_.get_in(i) < et_.get_in(j);\n    \
    \    });\n        for(int i = 0; i < auxiliary_tree_size_ - 1; ++i){\n       \
    \     auxiliary_tree_vertex_set_.push_back(lca_.Query(auxiliary_tree_vertex_set_[i],\
    \ auxiliary_tree_vertex_set_[i + 1]));\n        }\n        sort(auxiliary_tree_vertex_set_.begin(),\
    \ auxiliary_tree_vertex_set_.end(), [&](int i, int j){\n            return et_.get_in(i)\
    \ < et_.get_in(j);\n        });\n        auxiliary_tree_vertex_set_.erase(unique(auxiliary_tree_vertex_set_.begin(),\
    \ auxiliary_tree_vertex_set_.end()), auxiliary_tree_vertex_set_.end());\n    \
    \    auxiliary_tree_size_ = auxiliary_tree_vertex_set_.size();\n    }\n\n    RootedTree<WeightType>\
    \ Build(){\n        RootedTree<WeightType> ret(auxiliary_tree_size_);\n      \
    \  stack<Vertex> st, idx;\n        st.push(auxiliary_tree_vertex_set_.front());\n\
    \        idx.push(0);\n        for(int i = 1; i < auxiliary_tree_size_; ++i){\n\
    \            while(et_.get_out(st.top()) < et_.get_in(auxiliary_tree_vertex_set_[i]))\
    \ st.pop(), idx.pop();\n            if(st.size()){\n                WeightType\
    \ cost = edge_cum_[auxiliary_tree_vertex_set_[i]] - edge_cum_[st.top()];\n   \
    \             ret.AddEdge(idx.top(), i, cost);\n            }\n            st.push(auxiliary_tree_vertex_set_[i]);\n\
    \            idx.push(i);\n        }\n        return ret;\n    }\n\n    template<typename\
    \ Type>\n    vector<Type> ConvertData(const vector<Type> &data) const {\n    \
    \    vector<Type> ret(auxiliary_tree_size_);\n        for(int i = 0; i < auxiliary_tree_size_;\
    \ ++i){\n            ret[i] = data[auxiliary_tree_vertex_set_[i]];\n        }\n\
    \        return ret;\n    }\n\n    private:\n    RootedTree<WeightType> &T;\n\
    \    LowestCommonAncestor<WeightType> lca_;\n    EulerTour<WeightType> et_;\n\
    \    vector<WeightType> edge_cum_;\n\n    vector<Vertex> auxiliary_tree_vertex_set_;\n\
    \    size_t auxiliary_tree_size_;\n    vector<Vertex> convert_to_;\n};\n"
  code: "#include \"../Tree/Tree.hpp\"\n#include \"EulerTour.hpp\"\n#include \"../Tree/LowestCommonAncestor.hpp\"\
    \n\ntemplate<typename WeightType>\nclass AuxiliaryTree{\n    public:\n    AuxiliaryTree(RootedTree<WeightType>\
    \ &tree) :\n            T(tree), lca_(tree), et_(tree), edge_cum_(CalculateTreeCumlativeSum(tree)){\n\
    \    }\n\n    void Set(const vector<Vertex> &vertex_set){\n        auxiliary_tree_vertex_set_\
    \ = vertex_set;\n        auxiliary_tree_size_ = auxiliary_tree_vertex_set_.size();\n\
    \        sort(auxiliary_tree_vertex_set_.begin(), auxiliary_tree_vertex_set_.end(),\
    \ [&](int i, int j){\n            return et_.get_in(i) < et_.get_in(j);\n    \
    \    });\n        for(int i = 0; i < auxiliary_tree_size_ - 1; ++i){\n       \
    \     auxiliary_tree_vertex_set_.push_back(lca_.Query(auxiliary_tree_vertex_set_[i],\
    \ auxiliary_tree_vertex_set_[i + 1]));\n        }\n        sort(auxiliary_tree_vertex_set_.begin(),\
    \ auxiliary_tree_vertex_set_.end(), [&](int i, int j){\n            return et_.get_in(i)\
    \ < et_.get_in(j);\n        });\n        auxiliary_tree_vertex_set_.erase(unique(auxiliary_tree_vertex_set_.begin(),\
    \ auxiliary_tree_vertex_set_.end()), auxiliary_tree_vertex_set_.end());\n    \
    \    auxiliary_tree_size_ = auxiliary_tree_vertex_set_.size();\n    }\n\n    RootedTree<WeightType>\
    \ Build(){\n        RootedTree<WeightType> ret(auxiliary_tree_size_);\n      \
    \  stack<Vertex> st, idx;\n        st.push(auxiliary_tree_vertex_set_.front());\n\
    \        idx.push(0);\n        for(int i = 1; i < auxiliary_tree_size_; ++i){\n\
    \            while(et_.get_out(st.top()) < et_.get_in(auxiliary_tree_vertex_set_[i]))\
    \ st.pop(), idx.pop();\n            if(st.size()){\n                WeightType\
    \ cost = edge_cum_[auxiliary_tree_vertex_set_[i]] - edge_cum_[st.top()];\n   \
    \             ret.AddEdge(idx.top(), i, cost);\n            }\n            st.push(auxiliary_tree_vertex_set_[i]);\n\
    \            idx.push(i);\n        }\n        return ret;\n    }\n\n    template<typename\
    \ Type>\n    vector<Type> ConvertData(const vector<Type> &data) const {\n    \
    \    vector<Type> ret(auxiliary_tree_size_);\n        for(int i = 0; i < auxiliary_tree_size_;\
    \ ++i){\n            ret[i] = data[auxiliary_tree_vertex_set_[i]];\n        }\n\
    \        return ret;\n    }\n\n    private:\n    RootedTree<WeightType> &T;\n\
    \    LowestCommonAncestor<WeightType> lca_;\n    EulerTour<WeightType> et_;\n\
    \    vector<WeightType> edge_cum_;\n\n    vector<Vertex> auxiliary_tree_vertex_set_;\n\
    \    size_t auxiliary_tree_size_;\n    vector<Vertex> convert_to_;\n};"
  dependsOn:
  - Library/Tree/Tree.hpp
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  - Library/unauthenticated/EulerTour.hpp
  - Library/Tree/LowestCommonAncestor.hpp
  isVerificationFile: false
  path: Library/unauthenticated/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '2026-03-04 10:33:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/AuxiliaryTree.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/AuxiliaryTree.hpp
- /library/Library/unauthenticated/AuxiliaryTree.hpp.html
title: Library/unauthenticated/AuxiliaryTree.hpp
---
