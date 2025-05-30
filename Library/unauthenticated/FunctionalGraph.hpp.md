---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Functional Graph
    links:
    - https://atcoder.jp/contests/abc167/submissions/59194517
    - https://atcoder.jp/contests/abc179/submissions/59194689
    - https://atcoder.jp/contests/abc311/submissions/59194783
    - https://atcoder.jp/contests/abc377/submissions/59194861
  bundledCode: "#line 1 \"Library/unauthenticated/FunctionalGraph.hpp\"\n/**\n * @file\
    \ FunctionalGraph.hpp\n * @brief Functional Graph\n * @version 2.0\n * @date 2024-10-27\n\
    \ */\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 9 \"Library/unauthenticated/FunctionalGraph.hpp\"\n\ntemplate<typename\
    \ CostType = int32_t>\nclass FunctionalGraph{\n    public:\n    /**\n     * @brief\
    \ \u91CD\u307F\u306A\u3057 Functional Graph \u306E\u69CB\u7BC9\u3092\u884C\u3046\
    \u3002\n     * @param to \u5404\u9802\u70B9 i \u304C\u63A5\u7D9A\u3057\u3066\u3044\
    \u308B\u9802\u70B9\n     * @param one_index \u9802\u70B9\u756A\u53F7\u3092 1-index\
    \ \u3068\u3057\u3066\u6271\u3046\u304B `(default = true)`\n     * @param doubling_size\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u306E\u30C6\u30FC\u30D6\u30EB\u30B5\u30A4\u30BA\
    \ `(default = 60)`\n     */\n    FunctionalGraph(vector<int> &to, bool one_index\
    \ = true, int doubling_size = 60) :\n        vertex_size_((int)to.size()), doubling_size_(doubling_size),\
    \ one_index_(one_index){\n        vector<CostType> cost(vertex_size_, 1);\n  \
    \      Build(to, cost);\n    }\n    \n    /**\n     * @brief \u91CD\u307F\u3042\
    \u308A Functional Graph \u306E\u69CB\u7BC9\u3092\u884C\u3046\u3002\n     * @param\
    \ to \u5404\u9802\u70B9 i \u304C\u63A5\u7D9A\u3057\u3066\u3044\u308B\u9802\u70B9\
    \n     * @param cost \u5404\u9802\u70B9 i \u304C\u63A5\u7D9A\u3057\u3066\u3044\
    \u308B\u9802\u70B9\u3078\u306E\u8FBA\u306E\u91CD\u307F\n     * @param one_index\
    \ \u9802\u70B9\u756A\u53F7\u3092 1-index \u3068\u3057\u3066\u6271\u3046\u304B\
    \ `(default = true)`\n     * @param doubling_size \u30C0\u30D6\u30EA\u30F3\u30B0\
    \u306E\u30C6\u30FC\u30D6\u30EB\u30B5\u30A4\u30BA `(default = 60)`\n     */\n \
    \   FunctionalGraph(vector<int> &to, vector<CostType> &cost, bool one_index =\
    \ true, int doubling_size = 60) :\n        vertex_size_((int)to.size()), doubling_size_(doubling_size),\
    \ one_index_(one_index){\n        Build(to, cost);\n    }\n\n    /**\n     * @brief\
    \ \u5404\u30B5\u30A4\u30AF\u30EB\u3092\u69CB\u6210\u3059\u308B\u9802\u70B9\u306E\
    \u4E00\u89A7\u3092\u8FD4\u3059\u3002\n     * @note verify : https://atcoder.jp/contests/abc311/submissions/59194783\n\
    \     * @return vector<vector<int>> \u5404\u30B5\u30A4\u30AF\u30EB\u3092\u69CB\
    \u6210\u3059\u308B\u9802\u70B9\u306E\u4E00\u89A7\n     */\n    vector<vector<int>>\
    \ &get_cycle(){\n        return cycle_;\n    }\n\n    /**\n     * @brief \u9802\
    \u70B9 `start` \u304B\u3089 `step` \u56DE\u79FB\u52D5\u3059\u308B\u5148\u306E\u9802\
    \u70B9\u3092\u6C42\u3081\u308B\u3002\n     * @note verify : https://atcoder.jp/contests/abc167/submissions/59194517\n\
    \     * @param start \u958B\u59CB\u9802\u70B9\n     * @param step \u79FB\u52D5\
    \u56DE\u6570\n     * @return int \u79FB\u52D5\u5148\u306E\u9802\u70B9\n     */\n\
    \    int Jump(int start, int64_t step){\n        int ret = start - one_index_;\n\
    \        int64_t k = step, d = 0;\n        while(k){\n            if(k & 1) ret\
    \ = next_to_[d][ret];\n            k >>= 1, ++d;\n        }\n        return ret\
    \ + one_index_;\n    }\n\n    /**\n     * @brief \u9802\u70B9 `start` \u304B\u3089\
    \ `step` \u56DE\u79FB\u52D5\u3059\u308B\u3068\u304D\u306E\u8FBA\u306E\u91CD\u307F\
    \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\u3002\n     * @note verify : https://atcoder.jp/contests/abc179/submissions/59194689\n\
    \     * @param start \u958B\u59CB\u9802\u70B9\n     * @param step \u79FB\u52D5\
    \u56DE\u6570\n     * @return CostType \u8FBA\u306E\u91CD\u307F\u306E\u7DCF\u548C\
    \n     */\n    CostType JumpCost(int start, int64_t step){\n        CostType ret\
    \ = 0;\n        int64_t k = step, d = 0;\n        int v = start - one_index_;\n\
    \        while(k){\n            if(k & 1){\n                ret += next_cost_[d][v];\n\
    \                v = next_to_[d][v];\n            }\n            k >>= 1, ++d;\n\
    \        }\n        return ret;\n    }\n\n    /**\n     * @brief \u9802\u70B9\
    \ `v` \u304C\u5C5E\u3059\u308B\u30B5\u30A4\u30AF\u30EB\u306E\u30B5\u30A4\u30BA\
    \u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @note verify : https://atcoder.jp/contests/abc377/submissions/59194861\n\
    \     * @param v \u9802\u70B9\u756A\u53F7\n     * @return int \u9802\u70B9\u304C\
    \u5C5E\u3059\u308B\u30B5\u30A4\u30AF\u30EB\u306E\u30B5\u30A4\u30BA\u3001\u305F\
    \u3060\u3057\u30B5\u30A4\u30AF\u30EB\u306B\u5C5E\u3057\u3066\u3044\u306A\u3044\
    \u5834\u5408\u306F 0 \u3092\u8FD4\u3059\n     */\n    int CycleSize(int v){\n\
    \        int i = v - one_index_;\n        if(belong_cycle_[i] == -1) return 0;\n\
    \        return (int)cycle_[belong_cycle_[i]].size();\n    }\n\n    private:\n\
    \    int vertex_size_, doubling_size_, one_index_;\n\n    vector<vector<int>>\
    \ next_to_;\n    vector<vector<CostType>> next_cost_;\n\n    vector<int> belong_cycle_;\n\
    \    vector<vector<int>> cycle_;\n\n    void Build(vector<int> &to, vector<CostType>\
    \ &cost){\n        next_to_.resize(doubling_size_, vector<int>(vertex_size_, -1));\n\
    \        next_cost_.resize(doubling_size_, vector<CostType>(vertex_size_, 0));\n\
    \        for(int i = 0; i < vertex_size_; ++i){\n            next_to_[0][i] =\
    \ to[i] - (int)one_index_;\n            next_cost_[0][i] = cost[i];\n        }\n\
    \        for(int i = 1; i < doubling_size_; ++i){\n            for(int j = 0;\
    \ j < vertex_size_; ++j){\n                next_to_[i][j] = next_to_[i - 1][next_to_[i\
    \ - 1][j]];\n                next_cost_[i][j] = next_cost_[i - 1][next_to_[i -\
    \ 1][j]] + next_cost_[i - 1][j];\n            }\n        }\n\n        belong_cycle_.resize(vertex_size_,\
    \ -1);\n        vector<int> state(vertex_size_, 0);\n        vector<int> history;\n\
    \        auto dfs = [&](auto self, int v) -> void {\n            if(state[v] ==\
    \ 2) return;\n            history.push_back(v);\n            state[v] = 1;\n \
    \           int u = next_to_[0][v];\n            if(state[u] == 1){\n        \
    \        int cycle_idx = cycle_.size();\n                cycle_.push_back({});\n\
    \                for(int i = history.size() - 1;; --i){\n                    cycle_.back().push_back(history[i]\
    \ + one_index_);\n                    belong_cycle_[history[i]] = cycle_idx;\n\
    \                    if(history[i] == u) break;\n                }\n         \
    \       reverse(cycle_.back().begin(), cycle_.back().end());\n            }\n\
    \            else{\n                self(self, u);\n            }\n          \
    \  history.pop_back();\n            state[v] = 2;\n        };\n        for(int\
    \ i = 0; i < vertex_size_; ++i) dfs(dfs, i);\n    }\n};\n"
  code: "/**\n * @file FunctionalGraph.hpp\n * @brief Functional Graph\n * @version\
    \ 2.0\n * @date 2024-10-27\n */\n\n#include \"../Common.hpp\"\n\ntemplate<typename\
    \ CostType = int32_t>\nclass FunctionalGraph{\n    public:\n    /**\n     * @brief\
    \ \u91CD\u307F\u306A\u3057 Functional Graph \u306E\u69CB\u7BC9\u3092\u884C\u3046\
    \u3002\n     * @param to \u5404\u9802\u70B9 i \u304C\u63A5\u7D9A\u3057\u3066\u3044\
    \u308B\u9802\u70B9\n     * @param one_index \u9802\u70B9\u756A\u53F7\u3092 1-index\
    \ \u3068\u3057\u3066\u6271\u3046\u304B `(default = true)`\n     * @param doubling_size\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u306E\u30C6\u30FC\u30D6\u30EB\u30B5\u30A4\u30BA\
    \ `(default = 60)`\n     */\n    FunctionalGraph(vector<int> &to, bool one_index\
    \ = true, int doubling_size = 60) :\n        vertex_size_((int)to.size()), doubling_size_(doubling_size),\
    \ one_index_(one_index){\n        vector<CostType> cost(vertex_size_, 1);\n  \
    \      Build(to, cost);\n    }\n    \n    /**\n     * @brief \u91CD\u307F\u3042\
    \u308A Functional Graph \u306E\u69CB\u7BC9\u3092\u884C\u3046\u3002\n     * @param\
    \ to \u5404\u9802\u70B9 i \u304C\u63A5\u7D9A\u3057\u3066\u3044\u308B\u9802\u70B9\
    \n     * @param cost \u5404\u9802\u70B9 i \u304C\u63A5\u7D9A\u3057\u3066\u3044\
    \u308B\u9802\u70B9\u3078\u306E\u8FBA\u306E\u91CD\u307F\n     * @param one_index\
    \ \u9802\u70B9\u756A\u53F7\u3092 1-index \u3068\u3057\u3066\u6271\u3046\u304B\
    \ `(default = true)`\n     * @param doubling_size \u30C0\u30D6\u30EA\u30F3\u30B0\
    \u306E\u30C6\u30FC\u30D6\u30EB\u30B5\u30A4\u30BA `(default = 60)`\n     */\n \
    \   FunctionalGraph(vector<int> &to, vector<CostType> &cost, bool one_index =\
    \ true, int doubling_size = 60) :\n        vertex_size_((int)to.size()), doubling_size_(doubling_size),\
    \ one_index_(one_index){\n        Build(to, cost);\n    }\n\n    /**\n     * @brief\
    \ \u5404\u30B5\u30A4\u30AF\u30EB\u3092\u69CB\u6210\u3059\u308B\u9802\u70B9\u306E\
    \u4E00\u89A7\u3092\u8FD4\u3059\u3002\n     * @note verify : https://atcoder.jp/contests/abc311/submissions/59194783\n\
    \     * @return vector<vector<int>> \u5404\u30B5\u30A4\u30AF\u30EB\u3092\u69CB\
    \u6210\u3059\u308B\u9802\u70B9\u306E\u4E00\u89A7\n     */\n    vector<vector<int>>\
    \ &get_cycle(){\n        return cycle_;\n    }\n\n    /**\n     * @brief \u9802\
    \u70B9 `start` \u304B\u3089 `step` \u56DE\u79FB\u52D5\u3059\u308B\u5148\u306E\u9802\
    \u70B9\u3092\u6C42\u3081\u308B\u3002\n     * @note verify : https://atcoder.jp/contests/abc167/submissions/59194517\n\
    \     * @param start \u958B\u59CB\u9802\u70B9\n     * @param step \u79FB\u52D5\
    \u56DE\u6570\n     * @return int \u79FB\u52D5\u5148\u306E\u9802\u70B9\n     */\n\
    \    int Jump(int start, int64_t step){\n        int ret = start - one_index_;\n\
    \        int64_t k = step, d = 0;\n        while(k){\n            if(k & 1) ret\
    \ = next_to_[d][ret];\n            k >>= 1, ++d;\n        }\n        return ret\
    \ + one_index_;\n    }\n\n    /**\n     * @brief \u9802\u70B9 `start` \u304B\u3089\
    \ `step` \u56DE\u79FB\u52D5\u3059\u308B\u3068\u304D\u306E\u8FBA\u306E\u91CD\u307F\
    \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\u3002\n     * @note verify : https://atcoder.jp/contests/abc179/submissions/59194689\n\
    \     * @param start \u958B\u59CB\u9802\u70B9\n     * @param step \u79FB\u52D5\
    \u56DE\u6570\n     * @return CostType \u8FBA\u306E\u91CD\u307F\u306E\u7DCF\u548C\
    \n     */\n    CostType JumpCost(int start, int64_t step){\n        CostType ret\
    \ = 0;\n        int64_t k = step, d = 0;\n        int v = start - one_index_;\n\
    \        while(k){\n            if(k & 1){\n                ret += next_cost_[d][v];\n\
    \                v = next_to_[d][v];\n            }\n            k >>= 1, ++d;\n\
    \        }\n        return ret;\n    }\n\n    /**\n     * @brief \u9802\u70B9\
    \ `v` \u304C\u5C5E\u3059\u308B\u30B5\u30A4\u30AF\u30EB\u306E\u30B5\u30A4\u30BA\
    \u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @note verify : https://atcoder.jp/contests/abc377/submissions/59194861\n\
    \     * @param v \u9802\u70B9\u756A\u53F7\n     * @return int \u9802\u70B9\u304C\
    \u5C5E\u3059\u308B\u30B5\u30A4\u30AF\u30EB\u306E\u30B5\u30A4\u30BA\u3001\u305F\
    \u3060\u3057\u30B5\u30A4\u30AF\u30EB\u306B\u5C5E\u3057\u3066\u3044\u306A\u3044\
    \u5834\u5408\u306F 0 \u3092\u8FD4\u3059\n     */\n    int CycleSize(int v){\n\
    \        int i = v - one_index_;\n        if(belong_cycle_[i] == -1) return 0;\n\
    \        return (int)cycle_[belong_cycle_[i]].size();\n    }\n\n    private:\n\
    \    int vertex_size_, doubling_size_, one_index_;\n\n    vector<vector<int>>\
    \ next_to_;\n    vector<vector<CostType>> next_cost_;\n\n    vector<int> belong_cycle_;\n\
    \    vector<vector<int>> cycle_;\n\n    void Build(vector<int> &to, vector<CostType>\
    \ &cost){\n        next_to_.resize(doubling_size_, vector<int>(vertex_size_, -1));\n\
    \        next_cost_.resize(doubling_size_, vector<CostType>(vertex_size_, 0));\n\
    \        for(int i = 0; i < vertex_size_; ++i){\n            next_to_[0][i] =\
    \ to[i] - (int)one_index_;\n            next_cost_[0][i] = cost[i];\n        }\n\
    \        for(int i = 1; i < doubling_size_; ++i){\n            for(int j = 0;\
    \ j < vertex_size_; ++j){\n                next_to_[i][j] = next_to_[i - 1][next_to_[i\
    \ - 1][j]];\n                next_cost_[i][j] = next_cost_[i - 1][next_to_[i -\
    \ 1][j]] + next_cost_[i - 1][j];\n            }\n        }\n\n        belong_cycle_.resize(vertex_size_,\
    \ -1);\n        vector<int> state(vertex_size_, 0);\n        vector<int> history;\n\
    \        auto dfs = [&](auto self, int v) -> void {\n            if(state[v] ==\
    \ 2) return;\n            history.push_back(v);\n            state[v] = 1;\n \
    \           int u = next_to_[0][v];\n            if(state[u] == 1){\n        \
    \        int cycle_idx = cycle_.size();\n                cycle_.push_back({});\n\
    \                for(int i = history.size() - 1;; --i){\n                    cycle_.back().push_back(history[i]\
    \ + one_index_);\n                    belong_cycle_[history[i]] = cycle_idx;\n\
    \                    if(history[i] == u) break;\n                }\n         \
    \       reverse(cycle_.back().begin(), cycle_.back().end());\n            }\n\
    \            else{\n                self(self, u);\n            }\n          \
    \  history.pop_back();\n            state[v] = 2;\n        };\n        for(int\
    \ i = 0; i < vertex_size_; ++i) dfs(dfs, i);\n    }\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/unauthenticated/FunctionalGraph.hpp
  requiredBy: []
  timestamp: '2025-04-30 01:32:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/FunctionalGraph.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/FunctionalGraph.hpp
- /library/Library/unauthenticated/FunctionalGraph.hpp.html
title: Functional Graph
---
