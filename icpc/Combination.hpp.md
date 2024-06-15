---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DPL-5-B.test.cpp
    title: verify_icpc/AOJ-DPL-5-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DPL-5-D.test.cpp
    title: verify_icpc/AOJ-DPL-5-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DPL-5-E.test.cpp
    title: verify_icpc/AOJ-DPL-5-E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\nusing pi = pair<int, int>;\n\
    #line 2 \"icpc/Combination.hpp\"\n\ntemplate<typename T>\nstruct combination{\n\
    \    vector<T> fn, rn, in;\n\n    combination(int sz) : fn(sz + 1), rn(sz + 1),\
    \ in(sz + 1){\n        fn[0] = rn[sz] = in[0] = 1;\n        for(int i = 1; i <=\
    \ sz; ++i) fn[i] = fn[i - 1] * i;\n        rn[sz] /= fn[sz];\n        for(int\
    \ i = sz - 1; i >= 0; --i) rn[i] = rn[i + 1] * (i + 1);\n        for(int i = 1;\
    \ i <= sz; ++i) in[i] = rn[i] * fn[i - 1];\n    }\n\n    T fact(int k){return\
    \ fn[k];}\n    T rfact(int k){return rn[k];}\n    T inv(int k){return in[k];}\n\
    \n    T P(int n, int r){\n        if(r < 0 or n < r) return 0;\n        return\
    \ fact(n) * rfact(n - r);\n    }\n    T C(int n, int r){\n        if(r < 0 or\
    \ n < r) return 0;\n        return fact(n) * rfact(r) * rfact(n - r);\n    }\n\
    \    T H(int n, int r){\n        if(n < 0 or r < 0) return 0;\n        return\
    \ r == 0 ? 1 : C(n + r - 1, r);\n    }\n};\n"
  code: "#include \"Template.hpp\"\n\ntemplate<typename T>\nstruct combination{\n\
    \    vector<T> fn, rn, in;\n\n    combination(int sz) : fn(sz + 1), rn(sz + 1),\
    \ in(sz + 1){\n        fn[0] = rn[sz] = in[0] = 1;\n        for(int i = 1; i <=\
    \ sz; ++i) fn[i] = fn[i - 1] * i;\n        rn[sz] /= fn[sz];\n        for(int\
    \ i = sz - 1; i >= 0; --i) rn[i] = rn[i + 1] * (i + 1);\n        for(int i = 1;\
    \ i <= sz; ++i) in[i] = rn[i] * fn[i - 1];\n    }\n\n    T fact(int k){return\
    \ fn[k];}\n    T rfact(int k){return rn[k];}\n    T inv(int k){return in[k];}\n\
    \n    T P(int n, int r){\n        if(r < 0 or n < r) return 0;\n        return\
    \ fact(n) * rfact(n - r);\n    }\n    T C(int n, int r){\n        if(r < 0 or\
    \ n < r) return 0;\n        return fact(n) * rfact(r) * rfact(n - r);\n    }\n\
    \    T H(int n, int r){\n        if(n < 0 or r < 0) return 0;\n        return\
    \ r == 0 ? 1 : C(n + r - 1, r);\n    }\n};"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/Combination.hpp
  requiredBy: []
  timestamp: '2023-11-24 19:51:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-DPL-5-B.test.cpp
  - verify_icpc/AOJ-DPL-5-D.test.cpp
  - verify_icpc/AOJ-DPL-5-E.test.cpp
documentation_of: icpc/Combination.hpp
layout: document
redirect_from:
- /library/icpc/Combination.hpp
- /library/icpc/Combination.hpp.html
title: icpc/Combination.hpp
---
