---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-StaticRangeFrequency.test.cpp
    title: verify/LC-StaticRangeFrequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Mo's Algorithm
    links: []
  bundledCode: "#line 1 \"library/Other/Mo.hpp\"\n/**\n * @file Mo.hpp\n * @author\
    \ log K (lX57)\n * @brief Mo's Algorithm\n * @version 1.0\n * @date 2024-02-08\n\
    \ */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct Mo{\n    private:\n\
    \    using q = pair<int, int>;\n    using f = function<void(int)>;\n    int m_querysize,\
    \ m_rootq, m_blocksize;\n    vector<q> m_query;\n    vector<vector<int>> m_index;\n\
    \n    public:\n    /**\n     * @brief \u533A\u9593\u9577 `Segment_Size` \u306E\
    \u914D\u5217\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\u767B\u9332\u3059\
    \u308B\u3002\n     * @param Segment_Size \u914D\u5217\u306E\u533A\u9593\u9577\n\
    \     * @param Query_Left \u30AF\u30A8\u30EA `[l, r)` \u306E\u534A\u958B\u533A\
    \u9593\u5DE6\u7AEF\u306E\u914D\u5217\n     * @param Query_Right \u30AF\u30A8\u30EA\
    \ `[l, r)` \u306E\u534A\u958B\u533A\u9593\u53F3\u7AEF\u306E\u914D\u5217\n    \
    \ */\n    Mo(int Segment_Size, vector<int> &Query_Left, vector<int> &Query_Right){\n\
    \        Segment_Size = max(1, Segment_Size);\n        m_querysize = (int)Query_Left.size();\n\
    \        m_rootq = max(1, (int)sqrt(m_querysize));\n        m_blocksize = (Segment_Size\
    \ + m_rootq - 1) / m_rootq;\n        m_query.resize(m_querysize);\n        m_index.resize(m_blocksize);\n\
    \        for(int i = 0; i < m_querysize; ++i){\n            m_query[i] = {Query_Left[i],\
    \ Query_Right[i]};\n            m_index[Query_Left[i] / m_rootq].push_back(i);\n\
    \        }\n        bool odd = true;\n        for(auto &v : m_index){\n      \
    \      if(odd){\n                sort(v.begin(), v.end(), [&](int i, int j){\n\
    \                    return Query_Right[i] < Query_Right[j];\n               \
    \ });\n            }\n            else{\n                sort(v.begin(), v.end(),\
    \ [&](int i, int j){\n                    return Query_Right[i] > Query_Right[j];\n\
    \                });\n            }\n            odd = ~odd;\n        }\n    }\n\
    \n    /**\n     * @brief \u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\
    \n     * @param add \u533A\u9593\u306B\u542B\u3081\u308B\u3068\u304D\u306E\u51E6\
    \u7406\u3002\u5F15\u6570\u306B\u306F\u914D\u5217\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u756A\u53F7(0-index)\u304C\u6E21\u3055\u308C\u308B\u3002\n     *\
    \ @param sub \u533A\u9593\u304B\u3089\u9664\u304F\u3068\u304D\u306E\u51E6\u7406\
    \u3002\u5F15\u6570\u306B\u306F\u914D\u5217\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u756A\u53F7(0-index)\u304C\u6E21\u3055\u308C\u308B\u3002\n     * @param\
    \ out \u30AF\u30A8\u30EA\u306E\u7B54\u3048\u3092\u6C42\u3081\u308B\u3068\u304D\
    \u306E\u51E6\u7406\u3002\u5F15\u6570\u306B\u306F\u30AF\u30A8\u30EA\u306E\u756A\
    \u53F7(0-index)\u304C\u6E21\u3055\u308C\u308B\u3002\n     */\n    void run(f add,\
    \ f sub, f out){\n        int left = 0, right = 0;\n        for(auto &m : m_index){\n\
    \            for(auto i : m){\n                auto [l, r] = m_query[i];\n   \
    \             while(right < r) add(right++);\n                while(right > r)\
    \ sub(--right);\n                while(left < l) sub(left++);\n              \
    \  while(left > l) add(--left);\n                out(i);\n            }\n    \
    \    }\n    }\n};\n"
  code: "/**\n * @file Mo.hpp\n * @author log K (lX57)\n * @brief Mo's Algorithm\n\
    \ * @version 1.0\n * @date 2024-02-08\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct Mo{\n    private:\n    using q = pair<int, int>;\n\
    \    using f = function<void(int)>;\n    int m_querysize, m_rootq, m_blocksize;\n\
    \    vector<q> m_query;\n    vector<vector<int>> m_index;\n\n    public:\n   \
    \ /**\n     * @brief \u533A\u9593\u9577 `Segment_Size` \u306E\u914D\u5217\u306B\
    \u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\u767B\u9332\u3059\u308B\u3002\n   \
    \  * @param Segment_Size \u914D\u5217\u306E\u533A\u9593\u9577\n     * @param Query_Left\
    \ \u30AF\u30A8\u30EA `[l, r)` \u306E\u534A\u958B\u533A\u9593\u5DE6\u7AEF\u306E\
    \u914D\u5217\n     * @param Query_Right \u30AF\u30A8\u30EA `[l, r)` \u306E\u534A\
    \u958B\u533A\u9593\u53F3\u7AEF\u306E\u914D\u5217\n     */\n    Mo(int Segment_Size,\
    \ vector<int> &Query_Left, vector<int> &Query_Right){\n        Segment_Size =\
    \ max(1, Segment_Size);\n        m_querysize = (int)Query_Left.size();\n     \
    \   m_rootq = max(1, (int)sqrt(m_querysize));\n        m_blocksize = (Segment_Size\
    \ + m_rootq - 1) / m_rootq;\n        m_query.resize(m_querysize);\n        m_index.resize(m_blocksize);\n\
    \        for(int i = 0; i < m_querysize; ++i){\n            m_query[i] = {Query_Left[i],\
    \ Query_Right[i]};\n            m_index[Query_Left[i] / m_rootq].push_back(i);\n\
    \        }\n        bool odd = true;\n        for(auto &v : m_index){\n      \
    \      if(odd){\n                sort(v.begin(), v.end(), [&](int i, int j){\n\
    \                    return Query_Right[i] < Query_Right[j];\n               \
    \ });\n            }\n            else{\n                sort(v.begin(), v.end(),\
    \ [&](int i, int j){\n                    return Query_Right[i] > Query_Right[j];\n\
    \                });\n            }\n            odd = ~odd;\n        }\n    }\n\
    \n    /**\n     * @brief \u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\
    \n     * @param add \u533A\u9593\u306B\u542B\u3081\u308B\u3068\u304D\u306E\u51E6\
    \u7406\u3002\u5F15\u6570\u306B\u306F\u914D\u5217\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u756A\u53F7(0-index)\u304C\u6E21\u3055\u308C\u308B\u3002\n     *\
    \ @param sub \u533A\u9593\u304B\u3089\u9664\u304F\u3068\u304D\u306E\u51E6\u7406\
    \u3002\u5F15\u6570\u306B\u306F\u914D\u5217\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u756A\u53F7(0-index)\u304C\u6E21\u3055\u308C\u308B\u3002\n     * @param\
    \ out \u30AF\u30A8\u30EA\u306E\u7B54\u3048\u3092\u6C42\u3081\u308B\u3068\u304D\
    \u306E\u51E6\u7406\u3002\u5F15\u6570\u306B\u306F\u30AF\u30A8\u30EA\u306E\u756A\
    \u53F7(0-index)\u304C\u6E21\u3055\u308C\u308B\u3002\n     */\n    void run(f add,\
    \ f sub, f out){\n        int left = 0, right = 0;\n        for(auto &m : m_index){\n\
    \            for(auto i : m){\n                auto [l, r] = m_query[i];\n   \
    \             while(right < r) add(right++);\n                while(right > r)\
    \ sub(--right);\n                while(left < l) sub(left++);\n              \
    \  while(left > l) add(--left);\n                out(i);\n            }\n    \
    \    }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/Other/Mo.hpp
  requiredBy: []
  timestamp: '2024-02-08 00:45:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-StaticRangeFrequency.test.cpp
documentation_of: library/Other/Mo.hpp
layout: document
redirect_from:
- /library/library/Other/Mo.hpp
- /library/library/Other/Mo.hpp.html
title: Mo's Algorithm
---
