---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DynamicPrograming/LongestIncreasingSubsequence.hpp
    title: "Longest Increasing Subsequence - \u6700\u9577\u90E8\u5206\u5897\u52A0\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D
  bundledCode: "#line 1 \"verify/AOJ/AOJ-DPL-1-D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D\"\
    \n\n#include <bits/stdc++.h>\n\n#line 2 \"library/DynamicPrograming/LongestIncreasingSubsequence.hpp\"\
    \n\n/**\n * @brief Longest Increasing Subsequence - \u6700\u9577\u90E8\u5206\u5897\
    \u52A0\u5217\n */\n\n#line 8 \"library/DynamicPrograming/LongestIncreasingSubsequence.hpp\"\
    \nusing namespace std;\n\n/**\n * @brief \u914D\u5217X\u306B\u5BFE\u3057\u3066\
    \u6700\u9577\u90E8\u5206\u5897\u52A0\u5217\u306E\u9577\u3055\u3092\u6C42\u3081\
    \u308B\u3002\n * @param X \u6C42\u3081\u305F\u3044\u914D\u5217X\n * @param strict\
    \ \u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\u304B\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\
    \u304B\uFF08default = true\uFF09\n * @return int \u6700\u9577\u90E8\u5206\u5897\
    \u52A0\u5217\u306E\u9577\u3055\n */\ntemplate<typename T>\nint LongestIncreasingSubsequence(const\
    \ vector<T> &X, bool strict = true){\n    int N = X.size();\n    vector<int> L;\n\
    \    for(auto &x : X){\n        vector<int>::iterator itr;\n        if(strict)\
    \ itr = lower_bound(L.begin(), L.end(), x);\n        else itr = upper_bound(L.begin(),\
    \ L.end(), x);\n        if(itr == L.end()) L.emplace_back(x);\n        else *itr\
    \ = x;\n    }\n    return L.size();\n}\n#line 6 \"verify/AOJ/AOJ-DPL-1-D.test.cpp\"\
    \n\nint main(){\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    for(auto\
    \ &aa : a) cin >> aa;\n    cout << LongestIncreasingSubsequence(a) << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../library/DynamicPrograming/LongestIncreasingSubsequence.hpp\"\
    \n\nint main(){\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    for(auto\
    \ &aa : a) cin >> aa;\n    cout << LongestIncreasingSubsequence(a) << endl;\n}"
  dependsOn:
  - library/DynamicPrograming/LongestIncreasingSubsequence.hpp
  isVerificationFile: true
  path: verify/AOJ/AOJ-DPL-1-D.test.cpp
  requiredBy: []
  timestamp: '2023-08-30 10:46:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ/AOJ-DPL-1-D.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ/AOJ-DPL-1-D.test.cpp
- /verify/verify/AOJ/AOJ-DPL-1-D.test.cpp.html
title: verify/AOJ/AOJ-DPL-1-D.test.cpp
---
