---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Slide-Min - \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
    links: []
  bundledCode: "#line 1 \"Library/unauthenticated/SlideMin.hpp\"\n/**\n * @file SlideMin.hpp\n\
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
  path: Library/unauthenticated/SlideMin.hpp
  requiredBy: []
  timestamp: '2024-09-04 01:04:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/SlideMin.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/SlideMin.hpp
- /library/Library/unauthenticated/SlideMin.hpp.html
title: "Slide-Min - \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
---
