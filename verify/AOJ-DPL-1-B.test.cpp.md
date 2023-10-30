---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DynamicPrograming/Knapsack01.hpp
    title: "0-1 Knapsack - 0-1 \u30CA\u30C3\u30D7\u30B6\u30C3\u30AF\u554F\u984C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B
  bundledCode: "#line 1 \"verify/AOJ-DPL-1-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B\"\
    \n\n#line 1 \"library/DynamicPrograming/Knapsack01.hpp\"\n/**\n * @file Knapsack01.hpp\n\
    \ * @author log K (lX57)\n * @brief 0-1 Knapsack - 0-1 \u30CA\u30C3\u30D7\u30B6\
    \u30C3\u30AF\u554F\u984C\n * @version 1.0\n * @date 2023-10-30\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>\nT Knapsack01_NW(const\
    \ T W, const vector<T> &v, const vector<T> &w){\n    assert(v.size() == w.size());\n\
    \    int N = v.size();\n    vector dp(N + 1, vector(W + 1, -1));\n    dp[0][0]\
    \ = 0;\n    for(int i = 0; i < N; ++i){\n        for(int j = 0; j <= W; ++j){\n\
    \            if(dp[i][j] == -1) continue;\n            dp[i + 1][j] = max(dp[i\
    \ + 1][j], dp[i][j]);\n            if(j + w[i] <= W){\n                dp[i +\
    \ 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);\n            }\n \
    \       }\n    }\n    return *max_element(dp[N].begin(), dp[N].end());\n}\n\n\
    template<typename T>\nT Knapsack01_NV(const T W, const vector<T> &v, const vector<T>\
    \ &w){\n    assert(v.size() == w.size());\n    int N = v.size();\n    int V =\
    \ accumulate(v.begin(), v.end(), 0);\n    T INF = numeric_limits<T>::max() / 2;\n\
    \    vector dp(N + 1, vector(V + 1, INF));\n    dp[0][0] = 0;\n    for(int i =\
    \ 0; i < N; ++i){\n        for(int j = 0; j <= V; ++j){\n            if(dp[i][j]\
    \ == -1) continue;\n            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);\n\
    \            if(dp[i][j] + w[i] <= W){\n                dp[i + 1][j + v[i]] =\
    \ min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);\n            }\n        }\n    }\n\
    \    T ret = 0;\n    for(int j = 0; j <= V; ++j) if(dp[N][j] != INF) ret = j;\n\
    \    return ret;\n}\n#line 4 \"verify/AOJ-DPL-1-B.test.cpp\"\n\nint main(){\n\
    \    int N, W; cin >> N >> W;\n    vector<int> v(N), w(N);\n    for(int i = 0;\
    \ i < N; ++i) cin >> v[i] >> w[i];\n\n    cout << Knapsack01_NW(W, v, w) << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B\"\
    \n\n#include \"../library/DynamicPrograming/Knapsack01.hpp\"\n\nint main(){\n\
    \    int N, W; cin >> N >> W;\n    vector<int> v(N), w(N);\n    for(int i = 0;\
    \ i < N; ++i) cin >> v[i] >> w[i];\n\n    cout << Knapsack01_NW(W, v, w) << endl;\n\
    }"
  dependsOn:
  - library/DynamicPrograming/Knapsack01.hpp
  isVerificationFile: true
  path: verify/AOJ-DPL-1-B.test.cpp
  requiredBy: []
  timestamp: '2023-10-30 14:15:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DPL-1-B.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DPL-1-B.test.cpp
- /verify/verify/AOJ-DPL-1-B.test.cpp.html
title: verify/AOJ-DPL-1-B.test.cpp
---
