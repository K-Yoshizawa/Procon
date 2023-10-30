---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-3-D.test.cpp
    title: verify/AOJ-DSL-3-D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Slide-Min - \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
    links: []
  bundledCode: "#line 1 \"library/DataStructure/SlideMin.hpp\"\n/**\n * @file SlideMin.hpp\n\
    \ * @author log K (lX57)\n * @brief Slide-Min - \u30B9\u30E9\u30A4\u30C9\u6700\
    \u5C0F\u5024\n * @version 1.0\n * @date 2023-10-30\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nvector<T> SlideMin(vector<T> A,\
    \ int K){\n    int N = A.size();\n    deque<int> Q;\n    vector<T> B;\n    for(int\
    \ i = 0; i < N; ++i){\n        while(Q.size() and A[Q.back()] >= A[i]) Q.pop_back();\n\
    \        Q.push_back(i);\n        if(Q.front() == i - K) Q.pop_front();\n    \
    \    if(i - K + 1 >= 0) B.push_back(A[Q.front()]);\n    }\n    return B;\n}\n"
  code: "/**\n * @file SlideMin.hpp\n * @author log K (lX57)\n * @brief Slide-Min\
    \ - \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\n * @version 1.0\n * @date 2023-10-30\n\
    \ */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>\n\
    vector<T> SlideMin(vector<T> A, int K){\n    int N = A.size();\n    deque<int>\
    \ Q;\n    vector<T> B;\n    for(int i = 0; i < N; ++i){\n        while(Q.size()\
    \ and A[Q.back()] >= A[i]) Q.pop_back();\n        Q.push_back(i);\n        if(Q.front()\
    \ == i - K) Q.pop_front();\n        if(i - K + 1 >= 0) B.push_back(A[Q.front()]);\n\
    \    }\n    return B;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/SlideMin.hpp
  requiredBy: []
  timestamp: '2023-10-30 14:15:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DSL-3-D.test.cpp
documentation_of: library/DataStructure/SlideMin.hpp
layout: document
redirect_from:
- /library/library/DataStructure/SlideMin.hpp
- /library/library/DataStructure/SlideMin.hpp.html
title: "Slide-Min - \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
---
