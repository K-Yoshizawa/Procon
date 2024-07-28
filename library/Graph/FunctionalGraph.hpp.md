---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Functional Graph
    links:
    - https://atcoder.jp/contests/abc167/submissions/54652615
    - https://atcoder.jp/contests/abc179/submissions/54652566
    - https://atcoder.jp/contests/abc311/submissions/54652396
  bundledCode: "#line 1 \"library/Graph/FunctionalGraph.hpp\"\n/**\n * @file FunctionalGraph.hpp\n\
    \ * @brief Functional Graph\n * @version 0.1\n * @date 2024-06-16\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\n\ntemplate<typename\
    \ CostType = int32_t>\nclass FunctionalGraph{\n    Vertex size_;\n    vector<Vertex>\
    \ to_;\n    vector<CostType> cost_;\n\n    const int kLog_{63};\n    vector<vector<Vertex>>\
    \ next_;\n    vector<vector<CostType>> cost_sum_;\n\n    vector<int> belong_cycle_;\n\
    \    vector<vector<Vertex>> cycle_;\n\n    void build(){\n        next_.resize(size_,\
    \ vector<Vertex>(kLog_, -1));\n        cost_sum_.resize(size_, vector<CostType>(kLog_,\
    \ 0));\n        for(int v = 0; v < size_; ++v){\n            next_[v][0] = to_[v];\n\
    \            cost_sum_[v][0] = cost_[v];\n        }\n        for(int i = 0; i\
    \ < kLog_ - 1; ++i){\n            for(int v = 0; v < size_; ++v){\n          \
    \      next_[v][i + 1] = next_[next_[v][i]][i];\n                cost_sum_[v][i\
    \ + 1] = cost_sum_[next_[v][i]][i] + cost_sum_[v][i];\n            }\n       \
    \ }\n        belong_cycle_.resize(size_, -1);\n        vector<int> state(size_,\
    \ 0);\n        vector<Vertex> history;\n        auto dfs = [&](auto self, int\
    \ v) -> void {\n            if(state[v] == 2) return;\n            history.push_back(v);\n\
    \            state[v] = 1;\n            int u = to_[v];\n            if(state[u]\
    \ == 1){\n                int c = cycle_.size();\n                cycle_.push_back(vector<Vertex>{});\n\
    \                for(int i = history.size() - 1;; --i){\n                    cycle_.back().push_back(history[i]);\n\
    \                    belong_cycle_[history[i]] = c;\n                    if(history[i]\
    \ == u) break;\n                }\n                reverse(cycle_.back().begin(),\
    \ cycle_.back().end());\n            }\n            else{\n                self(self,\
    \ u);\n            }\n            history.pop_back();\n            state[v] =\
    \ 2;\n        };\n        for(int v = 0; v < size_; ++v){\n            dfs(dfs,\
    \ v);\n        }\n    }\n\n    public:\n    FunctionalGraph(){}\n\n    /**\n \
    \    * @brief \u91CD\u307F\u306A\u3057 Functional Graph \u306E\u69CB\u7BC9\n \
    \    * @param to \u5404\u9802\u70B9 v \u304C\u63A5\u7D9A\u3057\u3066\u3044\u308B\
    \u9802\u70B9 u\n     * @param one_index \u9802\u70B9\u756A\u53F7\u304C 1-index\
    \ \u3067\u3042\u308B\u304B `(default = true)`\n     */\n    FunctionalGraph(vector<Vertex>\
    \ &to, bool one_index = true) :\n    size_(to.size()), to_(to), cost_(to.size(),\
    \ 1){\n        for(auto &u : to_) u -= (int)one_index;\n        build();\n   \
    \ }\n\n    /**\n     * @brief \u91CD\u307F\u3042\u308A Functional Graph \u306E\
    \u69CB\u7BC9\n     * @param to \u5404\u9802\u70B9 v \u304C\u63A5\u7D9A\u3057\u3066\
    \u3044\u308B\u9802\u70B9 u\n     * @param cost \u5404\u9802\u70B9 v \u304C\u63A5\
    \u7D9A\u3057\u3066\u3044\u308B\u9802\u70B9 u \u306E\u8FBA\u306E\u91CD\u307F\n\
    \     * @param one_index \u9802\u70B9\u756A\u53F7\u304C 1-index \u3067\u3042\u308B\
    \u304B `(default = true)`\n     */\n    FunctionalGraph(vector<Vertex> &to, vector<CostType>\
    \ &cost, bool one_index = true) :\n    size_(to.size()), to_(to), cost_(cost){\n\
    \        for(auto &u : to_) u -= (int)one_index;\n        build();\n    }\n\n\
    \    /**\n     * @brief \u5404\u30B5\u30A4\u30AF\u30EB\u3092\u69CB\u6210\u3059\
    \u308B\u9802\u70B9\u306E\u4E00\u89A7\u3092\u8FD4\u3059\u3002\n     * @note \u30B5\
    \u30A4\u30AF\u30EB\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\u7A7A\
    \u5217\u304C\u8FD4\u308B\u306E\u3067\u3001`size()` \u3067\u30B5\u30A4\u30AF\u30EB\
    \u306E\u500B\u6570\u3092\u53D6\u5F97\u3067\u304D\u308B\u3002\n     * @note verify\
    \ : https://atcoder.jp/contests/abc311/submissions/54652396\n     * @return vector<vector<Vertex>>\
    \ \u5404\u30B5\u30A4\u30AF\u30EB\u3092\u69CB\u6210\u3059\u308B\u9802\u70B9\u306E\
    \u4E00\u89A7\n     */\n    vector<vector<Vertex>> get_cycle(){\n        return\
    \ cycle_;\n    }\n\n    /**\n     * @brief \u9802\u70B9 `start` \u304B\u3089 `step`\
    \ \u56DE\u79FB\u52D5\u3059\u308B\u5148\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\
    \u3002\n     * @note verify : https://atcoder.jp/contests/abc167/submissions/54652615\n\
    \     * @param start \u958B\u59CB\u9802\u70B9\n     * @param step \u79FB\u52D5\
    \u56DE\u6570\n     * @param one_index \u9802\u70B9\u756A\u53F7\u304C 1-index \u3067\
    \u3042\u308B\u304B `(default = true)`\n     * @return Vertex \u79FB\u52D5\u5148\
    \u306E\u9802\u70B9(`one_index` \u306B\u5FDC\u3058\u3066\u6574\u5F62\u3055\u308C\
    \u308B)\n     */\n    Vertex warp_where(Vertex start, int64_t step, bool one_index\
    \ = true){\n        Vertex ret = start - one_index;\n        int64_t n = step,\
    \ i = 0;\n        while(n){\n            if(n & 1){\n                ret = next_[ret][i];\n\
    \            }\n            n >>= 1, ++i;\n        }\n        return ret + one_index;\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `start` \u304B\u3089 `step` \u56DE\
    \u79FB\u52D5\u3059\u308B\u3068\u304D\u306E\u8FBA\u306E\u91CD\u307F\u306E\u7DCF\
    \u548C\u3092\u6C42\u3081\u308B\u3002\n     * @note verify : https://atcoder.jp/contests/abc179/submissions/54652566\n\
    \     * @param start \u958B\u59CB\u9802\u70B9\n     * @param step \u79FB\u52D5\
    \u56DE\u6570\n     * @param one_index \u9802\u70B9\u756A\u53F7\u304C 1-index \u3067\
    \u3042\u308B\u304B `(default = true)`\n     * @return CostType \u8FBA\u306E\u91CD\
    \u307F\u306E\u7DCF\u548C\n     */\n    CostType warp_distance(Vertex start, int64_t\
    \ step, bool one_index = true){\n        CostType ret = 0;\n        int64_t n\
    \ = step, i = 0;\n        Vertex v = start - one_index;\n        while(n){\n \
    \           if(n & 1){\n                ret += cost_sum_[v][i];\n            \
    \    v = next_[v][i];\n            }\n            n >>= 1, ++i;\n        }\n \
    \       return ret;\n    }\n};\n"
  code: "/**\n * @file FunctionalGraph.hpp\n * @brief Functional Graph\n * @version\
    \ 0.1\n * @date 2024-06-16\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing Vertex = int;\n\ntemplate<typename CostType = int32_t>\nclass FunctionalGraph{\n\
    \    Vertex size_;\n    vector<Vertex> to_;\n    vector<CostType> cost_;\n\n \
    \   const int kLog_{63};\n    vector<vector<Vertex>> next_;\n    vector<vector<CostType>>\
    \ cost_sum_;\n\n    vector<int> belong_cycle_;\n    vector<vector<Vertex>> cycle_;\n\
    \n    void build(){\n        next_.resize(size_, vector<Vertex>(kLog_, -1));\n\
    \        cost_sum_.resize(size_, vector<CostType>(kLog_, 0));\n        for(int\
    \ v = 0; v < size_; ++v){\n            next_[v][0] = to_[v];\n            cost_sum_[v][0]\
    \ = cost_[v];\n        }\n        for(int i = 0; i < kLog_ - 1; ++i){\n      \
    \      for(int v = 0; v < size_; ++v){\n                next_[v][i + 1] = next_[next_[v][i]][i];\n\
    \                cost_sum_[v][i + 1] = cost_sum_[next_[v][i]][i] + cost_sum_[v][i];\n\
    \            }\n        }\n        belong_cycle_.resize(size_, -1);\n        vector<int>\
    \ state(size_, 0);\n        vector<Vertex> history;\n        auto dfs = [&](auto\
    \ self, int v) -> void {\n            if(state[v] == 2) return;\n            history.push_back(v);\n\
    \            state[v] = 1;\n            int u = to_[v];\n            if(state[u]\
    \ == 1){\n                int c = cycle_.size();\n                cycle_.push_back(vector<Vertex>{});\n\
    \                for(int i = history.size() - 1;; --i){\n                    cycle_.back().push_back(history[i]);\n\
    \                    belong_cycle_[history[i]] = c;\n                    if(history[i]\
    \ == u) break;\n                }\n                reverse(cycle_.back().begin(),\
    \ cycle_.back().end());\n            }\n            else{\n                self(self,\
    \ u);\n            }\n            history.pop_back();\n            state[v] =\
    \ 2;\n        };\n        for(int v = 0; v < size_; ++v){\n            dfs(dfs,\
    \ v);\n        }\n    }\n\n    public:\n    FunctionalGraph(){}\n\n    /**\n \
    \    * @brief \u91CD\u307F\u306A\u3057 Functional Graph \u306E\u69CB\u7BC9\n \
    \    * @param to \u5404\u9802\u70B9 v \u304C\u63A5\u7D9A\u3057\u3066\u3044\u308B\
    \u9802\u70B9 u\n     * @param one_index \u9802\u70B9\u756A\u53F7\u304C 1-index\
    \ \u3067\u3042\u308B\u304B `(default = true)`\n     */\n    FunctionalGraph(vector<Vertex>\
    \ &to, bool one_index = true) :\n    size_(to.size()), to_(to), cost_(to.size(),\
    \ 1){\n        for(auto &u : to_) u -= (int)one_index;\n        build();\n   \
    \ }\n\n    /**\n     * @brief \u91CD\u307F\u3042\u308A Functional Graph \u306E\
    \u69CB\u7BC9\n     * @param to \u5404\u9802\u70B9 v \u304C\u63A5\u7D9A\u3057\u3066\
    \u3044\u308B\u9802\u70B9 u\n     * @param cost \u5404\u9802\u70B9 v \u304C\u63A5\
    \u7D9A\u3057\u3066\u3044\u308B\u9802\u70B9 u \u306E\u8FBA\u306E\u91CD\u307F\n\
    \     * @param one_index \u9802\u70B9\u756A\u53F7\u304C 1-index \u3067\u3042\u308B\
    \u304B `(default = true)`\n     */\n    FunctionalGraph(vector<Vertex> &to, vector<CostType>\
    \ &cost, bool one_index = true) :\n    size_(to.size()), to_(to), cost_(cost){\n\
    \        for(auto &u : to_) u -= (int)one_index;\n        build();\n    }\n\n\
    \    /**\n     * @brief \u5404\u30B5\u30A4\u30AF\u30EB\u3092\u69CB\u6210\u3059\
    \u308B\u9802\u70B9\u306E\u4E00\u89A7\u3092\u8FD4\u3059\u3002\n     * @note \u30B5\
    \u30A4\u30AF\u30EB\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\u7A7A\
    \u5217\u304C\u8FD4\u308B\u306E\u3067\u3001`size()` \u3067\u30B5\u30A4\u30AF\u30EB\
    \u306E\u500B\u6570\u3092\u53D6\u5F97\u3067\u304D\u308B\u3002\n     * @note verify\
    \ : https://atcoder.jp/contests/abc311/submissions/54652396\n     * @return vector<vector<Vertex>>\
    \ \u5404\u30B5\u30A4\u30AF\u30EB\u3092\u69CB\u6210\u3059\u308B\u9802\u70B9\u306E\
    \u4E00\u89A7\n     */\n    vector<vector<Vertex>> get_cycle(){\n        return\
    \ cycle_;\n    }\n\n    /**\n     * @brief \u9802\u70B9 `start` \u304B\u3089 `step`\
    \ \u56DE\u79FB\u52D5\u3059\u308B\u5148\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\
    \u3002\n     * @note verify : https://atcoder.jp/contests/abc167/submissions/54652615\n\
    \     * @param start \u958B\u59CB\u9802\u70B9\n     * @param step \u79FB\u52D5\
    \u56DE\u6570\n     * @param one_index \u9802\u70B9\u756A\u53F7\u304C 1-index \u3067\
    \u3042\u308B\u304B `(default = true)`\n     * @return Vertex \u79FB\u52D5\u5148\
    \u306E\u9802\u70B9(`one_index` \u306B\u5FDC\u3058\u3066\u6574\u5F62\u3055\u308C\
    \u308B)\n     */\n    Vertex warp_where(Vertex start, int64_t step, bool one_index\
    \ = true){\n        Vertex ret = start - one_index;\n        int64_t n = step,\
    \ i = 0;\n        while(n){\n            if(n & 1){\n                ret = next_[ret][i];\n\
    \            }\n            n >>= 1, ++i;\n        }\n        return ret + one_index;\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `start` \u304B\u3089 `step` \u56DE\
    \u79FB\u52D5\u3059\u308B\u3068\u304D\u306E\u8FBA\u306E\u91CD\u307F\u306E\u7DCF\
    \u548C\u3092\u6C42\u3081\u308B\u3002\n     * @note verify : https://atcoder.jp/contests/abc179/submissions/54652566\n\
    \     * @param start \u958B\u59CB\u9802\u70B9\n     * @param step \u79FB\u52D5\
    \u56DE\u6570\n     * @param one_index \u9802\u70B9\u756A\u53F7\u304C 1-index \u3067\
    \u3042\u308B\u304B `(default = true)`\n     * @return CostType \u8FBA\u306E\u91CD\
    \u307F\u306E\u7DCF\u548C\n     */\n    CostType warp_distance(Vertex start, int64_t\
    \ step, bool one_index = true){\n        CostType ret = 0;\n        int64_t n\
    \ = step, i = 0;\n        Vertex v = start - one_index;\n        while(n){\n \
    \           if(n & 1){\n                ret += cost_sum_[v][i];\n            \
    \    v = next_[v][i];\n            }\n            n >>= 1, ++i;\n        }\n \
    \       return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/Graph/FunctionalGraph.hpp
  requiredBy: []
  timestamp: '2024-06-17 03:05:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Graph/FunctionalGraph.hpp
layout: document
redirect_from:
- /library/library/Graph/FunctionalGraph.hpp
- /library/library/Graph/FunctionalGraph.hpp.html
title: Functional Graph
---
