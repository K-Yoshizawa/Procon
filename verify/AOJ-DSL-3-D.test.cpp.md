---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/SlideMin.hpp
    title: "Slide-Min - \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D
  bundledCode: "#line 1 \"verify/AOJ-DSL-3-D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D\"\
    \n\n#line 1 \"library/DataStructure/SlideMin.hpp\"\n/**\n * @file SlideMin.hpp\n\
    \ * @author log K (lX57)\n * @brief Slide-Min - \u30B9\u30E9\u30A4\u30C9\u6700\
    \u5C0F\u5024\n * @version 1.0\n * @date 2023-10-30\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nvector<T> SlideMin(vector<T> A,\
    \ int K){\n    int N = A.size();\n    deque<int> Q;\n    vector<T> B;\n    for(int\
    \ i = 0; i < N; ++i){\n        while(Q.size() and A[Q.back()] >= A[i]) Q.pop_back();\n\
    \        Q.push_back(i);\n        if(Q.front() == i - K) Q.pop_front();\n    \
    \    if(i - K + 1 >= 0) B.push_back(A[Q.front()]);\n    }\n    return B;\n}\n\
    #line 4 \"verify/AOJ-DSL-3-D.test.cpp\"\n\nint main(){\n    int N, L; cin >> N\
    \ >> L;\n    vector<int> a(N);\n    for(int i = 0; i < N; ++i) cin >> a[i];\n\n\
    \    vector<int> b = SlideMin(a, L);\n    \n    cout << b[0];\n    for(int i =\
    \ 1; i < b.size(); ++i) cout << \" \" << b[i];\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D\"\
    \n\n#include \"../library/DataStructure/SlideMin.hpp\"\n\nint main(){\n    int\
    \ N, L; cin >> N >> L;\n    vector<int> a(N);\n    for(int i = 0; i < N; ++i)\
    \ cin >> a[i];\n\n    vector<int> b = SlideMin(a, L);\n    \n    cout << b[0];\n\
    \    for(int i = 1; i < b.size(); ++i) cout << \" \" << b[i];\n    cout << endl;\n\
    }"
  dependsOn:
  - library/DataStructure/SlideMin.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-3-D.test.cpp
  requiredBy: []
  timestamp: '2023-10-30 14:15:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-3-D.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-3-D.test.cpp
- /verify/verify/AOJ-DSL-3-D.test.cpp.html
title: verify/AOJ-DSL-3-D.test.cpp
---
