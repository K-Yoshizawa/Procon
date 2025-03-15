---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-LongestIncreasingSubsequence.test.cpp
    title: verify/LC-LongestIncreasingSubsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Longest Increasing Subsequence - \u6700\u9577\u5897\u52A0\u90E8\
      \u5206\u5217"
    links: []
  bundledCode: "#line 1 \"Library/Other/LongestIncreasingSubsequence.hpp\"\n/**\n\
    \ * @file LongestIncreasingSubsequence.hpp\n * @brief Longest Increasing Subsequence\
    \ - \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\n * @author ei1333 (Original)\n\
    \ * @version 2.0\n * @date 2024-10-29\n */\n\n#line 2 \"Library/Common.hpp\"\n\
    \n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n#line 10 \"Library/Other/LongestIncreasingSubsequence.hpp\"\n\
    \n/**\n * @brief \u914D\u5217 `data` \u306E\u6700\u9577\u5897\u52A0\u90E8\u5206\
    \u5217\u3092\u6C42\u3081\u308B\u3002\n * @tparam Strict \u72ED\u7FA9\u5358\u8ABF\
    \u5897\u52A0\u3067\u3042\u308B\u304B\n * @param data \u6C42\u3081\u308B\u914D\u5217\
    \n * @return vector<T> \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E 1 \u3064\
    \u3067\u3001\u5404\u8981\u7D20\u3092 `data` \u306B\u304A\u3051\u308B\u6DFB\u3048\
    \u5B57\u3067\u8868\u3057\u305F\u914D\u5217\n * @note \u8FD4\u308A\u5024\u306E\u914D\
    \u5217\u306E\u9577\u3055\u304C\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\
    \u9577\u3055\u3067\u3042\u308B\u3002\n */\ntemplate<bool Strict, typename T>\n\
    vector<T> LongestIncreasingSubsequence(const vector<T> &data){\n    int N = (int)data.size();\n\
    \    T inf = numeric_limits<T>::min();\n    vector<T> L, pre, S;\n    for(auto\
    \ &x : data){\n        typename vector<T>::iterator itr;\n        if(Strict) itr\
    \ = lower_bound(L.begin(), L.end(), x);\n        else itr = upper_bound(L.begin(),\
    \ L.end(), x);\n        if(itr == L.begin()) pre.emplace_back(inf);\n        else\
    \ pre.emplace_back(*prev(itr));\n        if(itr == L.end()) L.emplace_back(x);\n\
    \        else *itr = x;\n    }\n    T x = L.back();\n    for(int i = N - 1; x\
    \ != inf;){\n        while(data[i] != x) --i;\n        S.emplace_back(i);\n  \
    \      x = pre[i];\n    }\n    reverse(S.begin(), S.end());\n    return S;\n}\n"
  code: "/**\n * @file LongestIncreasingSubsequence.hpp\n * @brief Longest Increasing\
    \ Subsequence - \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\n * @author ei1333\
    \ (Original)\n * @version 2.0\n * @date 2024-10-29\n */\n\n#include \"../Common.hpp\"\
    \n\n/**\n * @brief \u914D\u5217 `data` \u306E\u6700\u9577\u5897\u52A0\u90E8\u5206\
    \u5217\u3092\u6C42\u3081\u308B\u3002\n * @tparam Strict \u72ED\u7FA9\u5358\u8ABF\
    \u5897\u52A0\u3067\u3042\u308B\u304B\n * @param data \u6C42\u3081\u308B\u914D\u5217\
    \n * @return vector<T> \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E 1 \u3064\
    \u3067\u3001\u5404\u8981\u7D20\u3092 `data` \u306B\u304A\u3051\u308B\u6DFB\u3048\
    \u5B57\u3067\u8868\u3057\u305F\u914D\u5217\n * @note \u8FD4\u308A\u5024\u306E\u914D\
    \u5217\u306E\u9577\u3055\u304C\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\
    \u9577\u3055\u3067\u3042\u308B\u3002\n */\ntemplate<bool Strict, typename T>\n\
    vector<T> LongestIncreasingSubsequence(const vector<T> &data){\n    int N = (int)data.size();\n\
    \    T inf = numeric_limits<T>::min();\n    vector<T> L, pre, S;\n    for(auto\
    \ &x : data){\n        typename vector<T>::iterator itr;\n        if(Strict) itr\
    \ = lower_bound(L.begin(), L.end(), x);\n        else itr = upper_bound(L.begin(),\
    \ L.end(), x);\n        if(itr == L.begin()) pre.emplace_back(inf);\n        else\
    \ pre.emplace_back(*prev(itr));\n        if(itr == L.end()) L.emplace_back(x);\n\
    \        else *itr = x;\n    }\n    T x = L.back();\n    for(int i = N - 1; x\
    \ != inf;){\n        while(data[i] != x) --i;\n        S.emplace_back(i);\n  \
    \      x = pre[i];\n    }\n    reverse(S.begin(), S.end());\n    return S;\n}"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Other/LongestIncreasingSubsequence.hpp
  requiredBy: []
  timestamp: '2024-10-30 02:03:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-LongestIncreasingSubsequence.test.cpp
documentation_of: Library/Other/LongestIncreasingSubsequence.hpp
layout: document
redirect_from:
- /library/Library/Other/LongestIncreasingSubsequence.hpp
- /library/Library/Other/LongestIncreasingSubsequence.hpp.html
title: "Longest Increasing Subsequence - \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
---
