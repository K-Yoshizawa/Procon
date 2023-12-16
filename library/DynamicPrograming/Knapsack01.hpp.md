---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DPL-1-B.test.cpp
    title: verify/AOJ-DPL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DPL-1-F.test.cpp
    title: verify/AOJ-DPL-1-F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "0-1 Knapsack - 0-1 \u30CA\u30C3\u30D7\u30B6\u30C3\u30AF\u554F\
      \u984C"
    links: []
  bundledCode: "#line 1 \"library/DynamicPrograming/Knapsack01.hpp\"\n/**\n * @file\
    \ Knapsack01.hpp\n * @author log K (lX57)\n * @brief 0-1 Knapsack - 0-1 \u30CA\
    \u30C3\u30D7\u30B6\u30C3\u30AF\u554F\u984C\n * @version 1.0\n * @date 2023-10-30\n\
    \ */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>\n\
    T Knapsack01_NW(const T W, const vector<T> &v, const vector<T> &w){\n    assert(v.size()\
    \ == w.size());\n    int N = v.size();\n    vector dp(N + 1, vector(W + 1, -1));\n\
    \    dp[0][0] = 0;\n    for(int i = 0; i < N; ++i){\n        for(int j = 0; j\
    \ <= W; ++j){\n            if(dp[i][j] == -1) continue;\n            dp[i + 1][j]\
    \ = max(dp[i + 1][j], dp[i][j]);\n            if(j + w[i] <= W){\n           \
    \     dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);\n     \
    \       }\n        }\n    }\n    return *max_element(dp[N].begin(), dp[N].end());\n\
    }\n\ntemplate<typename T>\nT Knapsack01_NV(const T W, const vector<T> &v, const\
    \ vector<T> &w){\n    assert(v.size() == w.size());\n    int N = v.size();\n \
    \   int V = accumulate(v.begin(), v.end(), 0);\n    T INF = numeric_limits<T>::max()\
    \ / 2;\n    vector dp(N + 1, vector(V + 1, INF));\n    dp[0][0] = 0;\n    for(int\
    \ i = 0; i < N; ++i){\n        for(int j = 0; j <= V; ++j){\n            if(dp[i][j]\
    \ == -1) continue;\n            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);\n\
    \            if(dp[i][j] + w[i] <= W){\n                dp[i + 1][j + v[i]] =\
    \ min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);\n            }\n        }\n    }\n\
    \    T ret = 0;\n    for(int j = 0; j <= V; ++j) if(dp[N][j] != INF) ret = j;\n\
    \    return ret;\n}\n"
  code: "/**\n * @file Knapsack01.hpp\n * @author log K (lX57)\n * @brief 0-1 Knapsack\
    \ - 0-1 \u30CA\u30C3\u30D7\u30B6\u30C3\u30AF\u554F\u984C\n * @version 1.0\n *\
    \ @date 2023-10-30\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    template<typename T>\nT Knapsack01_NW(const T W, const vector<T> &v, const vector<T>\
    \ &w){\n    assert(v.size() == w.size());\n    int N = v.size();\n    vector dp(N\
    \ + 1, vector(W + 1, -1));\n    dp[0][0] = 0;\n    for(int i = 0; i < N; ++i){\n\
    \        for(int j = 0; j <= W; ++j){\n            if(dp[i][j] == -1) continue;\n\
    \            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);\n            if(j + w[i]\
    \ <= W){\n                dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j]\
    \ + v[i]);\n            }\n        }\n    }\n    return *max_element(dp[N].begin(),\
    \ dp[N].end());\n}\n\ntemplate<typename T>\nT Knapsack01_NV(const T W, const vector<T>\
    \ &v, const vector<T> &w){\n    assert(v.size() == w.size());\n    int N = v.size();\n\
    \    int V = accumulate(v.begin(), v.end(), 0);\n    T INF = numeric_limits<T>::max()\
    \ / 2;\n    vector dp(N + 1, vector(V + 1, INF));\n    dp[0][0] = 0;\n    for(int\
    \ i = 0; i < N; ++i){\n        for(int j = 0; j <= V; ++j){\n            if(dp[i][j]\
    \ == -1) continue;\n            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);\n\
    \            if(dp[i][j] + w[i] <= W){\n                dp[i + 1][j + v[i]] =\
    \ min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);\n            }\n        }\n    }\n\
    \    T ret = 0;\n    for(int j = 0; j <= V; ++j) if(dp[N][j] != INF) ret = j;\n\
    \    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/DynamicPrograming/Knapsack01.hpp
  requiredBy: []
  timestamp: '2023-10-30 14:15:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DPL-1-F.test.cpp
  - verify/AOJ-DPL-1-B.test.cpp
documentation_of: library/DynamicPrograming/Knapsack01.hpp
layout: document
redirect_from:
- /library/library/DynamicPrograming/Knapsack01.hpp
- /library/library/DynamicPrograming/Knapsack01.hpp.html
title: "0-1 Knapsack - 0-1 \u30CA\u30C3\u30D7\u30B6\u30C3\u30AF\u554F\u984C"
---
