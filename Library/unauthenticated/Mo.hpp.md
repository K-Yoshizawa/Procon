---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Mo's Algorithm
    links: []
  bundledCode: "#line 1 \"Library/unauthenticated/Mo.hpp\"\n/**\n * @file Mo.hpp\n\
    \ * @author log K (lX57)\n * @brief Mo's Algorithm\n * @version 1.0\n * @date\
    \ 2024-02-08\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct\
    \ Mo{\n    private:\n    using q = pair<int, int>;\n    using f = function<void(int)>;\n\
    \    int querysize_, rootq_, blocksize_;\n    vector<q> query_;\n    vector<vector<int>>\
    \ index_;\n\n    public:\n    /**\n     * @brief \u533A\u9593\u9577 `Segment_Size`\
    \ \u306E\u914D\u5217\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\u767B\u9332\
    \u3059\u308B\u3002\n     * @param Segment_Size \u914D\u5217\u306E\u533A\u9593\u9577\
    \n     * @param Query_Left \u30AF\u30A8\u30EA `[l, r)` \u306E\u534A\u958B\u533A\
    \u9593\u5DE6\u7AEF\u306E\u914D\u5217\n     * @param Query_Right \u30AF\u30A8\u30EA\
    \ `[l, r)` \u306E\u534A\u958B\u533A\u9593\u53F3\u7AEF\u306E\u914D\u5217\n    \
    \ */\n    Mo(int Segment_Size, vector<int> &Query_Left, vector<int> &Query_Right){\n\
    \        Segment_Size = max(1, Segment_Size);\n        querysize_ = (int)Query_Left.size();\n\
    \        rootq_ = max(1, (int)sqrt(querysize_));\n        blocksize_ = (Segment_Size\
    \ + rootq_ - 1) / rootq_;\n        query_.resize(querysize_);\n        index_.resize(blocksize_);\n\
    \        for(int i = 0; i < querysize_; ++i){\n            query_[i] = {Query_Left[i],\
    \ Query_Right[i]};\n            index_[Query_Left[i] / rootq_].push_back(i);\n\
    \        }\n        bool odd = true;\n        for(auto &v : index_){\n       \
    \     if(odd){\n                sort(v.begin(), v.end(), [&](int i, int j){\n\
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
    \ f sub, f out){\n        int left = 0, right = 0;\n        for(auto &m : index_){\n\
    \            for(auto i : m){\n                auto [l, r] = query_[i];\n    \
    \            while(right < r) add(right++);\n                while(right > r)\
    \ sub(--right);\n                while(left < l) sub(left++);\n              \
    \  while(left > l) add(--left);\n                out(i);\n            }\n    \
    \    }\n    }\n};\n"
  code: "/**\n * @file Mo.hpp\n * @author log K (lX57)\n * @brief Mo's Algorithm\n\
    \ * @version 1.0\n * @date 2024-02-08\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct Mo{\n    private:\n    using q = pair<int, int>;\n\
    \    using f = function<void(int)>;\n    int querysize_, rootq_, blocksize_;\n\
    \    vector<q> query_;\n    vector<vector<int>> index_;\n\n    public:\n    /**\n\
    \     * @brief \u533A\u9593\u9577 `Segment_Size` \u306E\u914D\u5217\u306B\u5BFE\
    \u3059\u308B\u30AF\u30A8\u30EA\u3092\u767B\u9332\u3059\u308B\u3002\n     * @param\
    \ Segment_Size \u914D\u5217\u306E\u533A\u9593\u9577\n     * @param Query_Left\
    \ \u30AF\u30A8\u30EA `[l, r)` \u306E\u534A\u958B\u533A\u9593\u5DE6\u7AEF\u306E\
    \u914D\u5217\n     * @param Query_Right \u30AF\u30A8\u30EA `[l, r)` \u306E\u534A\
    \u958B\u533A\u9593\u53F3\u7AEF\u306E\u914D\u5217\n     */\n    Mo(int Segment_Size,\
    \ vector<int> &Query_Left, vector<int> &Query_Right){\n        Segment_Size =\
    \ max(1, Segment_Size);\n        querysize_ = (int)Query_Left.size();\n      \
    \  rootq_ = max(1, (int)sqrt(querysize_));\n        blocksize_ = (Segment_Size\
    \ + rootq_ - 1) / rootq_;\n        query_.resize(querysize_);\n        index_.resize(blocksize_);\n\
    \        for(int i = 0; i < querysize_; ++i){\n            query_[i] = {Query_Left[i],\
    \ Query_Right[i]};\n            index_[Query_Left[i] / rootq_].push_back(i);\n\
    \        }\n        bool odd = true;\n        for(auto &v : index_){\n       \
    \     if(odd){\n                sort(v.begin(), v.end(), [&](int i, int j){\n\
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
    \ f sub, f out){\n        int left = 0, right = 0;\n        for(auto &m : index_){\n\
    \            for(auto i : m){\n                auto [l, r] = query_[i];\n    \
    \            while(right < r) add(right++);\n                while(right > r)\
    \ sub(--right);\n                while(left < l) sub(left++);\n              \
    \  while(left > l) add(--left);\n                out(i);\n            }\n    \
    \    }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/unauthenticated/Mo.hpp
  requiredBy: []
  timestamp: '2024-09-04 01:04:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/Mo.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/Mo.hpp
- /library/Library/unauthenticated/Mo.hpp.html
title: Mo's Algorithm
---
