---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Longest Increasing Subsequence - \u6700\u9577\u90E8\u5206\u5897\
      \u52A0\u5217"
    links: []
  bundledCode: "#line 2 \"library/DynamicPrograming/LongestIncreasingSubsequence.hpp\"\
    \n\n/**\n * @brief Longest Increasing Subsequence - \u6700\u9577\u90E8\u5206\u5897\
    \u52A0\u5217\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n/**\n *\
    \ @brief \u914D\u5217X\u306B\u5BFE\u3057\u3066\u6700\u9577\u90E8\u5206\u5897\u52A0\
    \u5217\u306E\u9577\u3055\u3092\u6C42\u3081\u308B\u3002\n * @param X \u6C42\u3081\
    \u305F\u3044\u914D\u5217X\n * @param strict \u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\
    \u304B\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u304B\uFF08default = true\uFF09\n *\
    \ @return int \u6700\u9577\u90E8\u5206\u5897\u52A0\u5217\u306E\u9577\u3055\n */\n\
    template<typename T>\nint LongestIncreasingSubsequence(const vector<T> &X, bool\
    \ strict = true){\n    int N = X.size();\n    vector<int> L;\n    for(auto &x\
    \ : X){\n        vector<int>::iterator itr;\n        if(strict) itr = lower_bound(L.begin(),\
    \ L.end(), x);\n        else itr = upper_bound(L.begin(), L.end(), x);\n     \
    \   if(itr == L.end()) L.emplace_back(x);\n        else *itr = x;\n    }\n   \
    \ return L.size();\n}\n"
  code: "#pragma once\n\n/**\n * @brief Longest Increasing Subsequence - \u6700\u9577\
    \u90E8\u5206\u5897\u52A0\u5217\n */\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n/**\n * @brief \u914D\u5217X\u306B\u5BFE\u3057\u3066\u6700\u9577\u90E8\
    \u5206\u5897\u52A0\u5217\u306E\u9577\u3055\u3092\u6C42\u3081\u308B\u3002\n * @param\
    \ X \u6C42\u3081\u305F\u3044\u914D\u5217X\n * @param strict \u72ED\u7FA9\u5358\
    \u8ABF\u5897\u52A0\u304B\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u304B\uFF08default\
    \ = true\uFF09\n * @return int \u6700\u9577\u90E8\u5206\u5897\u52A0\u5217\u306E\
    \u9577\u3055\n */\ntemplate<typename T>\nint LongestIncreasingSubsequence(const\
    \ vector<T> &X, bool strict = true){\n    int N = X.size();\n    vector<int> L;\n\
    \    for(auto &x : X){\n        vector<int>::iterator itr;\n        if(strict)\
    \ itr = lower_bound(L.begin(), L.end(), x);\n        else itr = upper_bound(L.begin(),\
    \ L.end(), x);\n        if(itr == L.end()) L.emplace_back(x);\n        else *itr\
    \ = x;\n    }\n    return L.size();\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/DynamicPrograming/LongestIncreasingSubsequence.hpp
  requiredBy: []
  timestamp: '2023-06-27 02:19:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/DynamicPrograming/LongestIncreasingSubsequence.hpp
layout: document
redirect_from:
- /library/library/DynamicPrograming/LongestIncreasingSubsequence.hpp
- /library/library/DynamicPrograming/LongestIncreasingSubsequence.hpp.html
title: "Longest Increasing Subsequence - \u6700\u9577\u90E8\u5206\u5897\u52A0\u5217"
---
