---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/String/ZAlgorithm.hpp
    title: library/String/ZAlgorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/LC-ZAlgorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#line 1 \"library/String/ZAlgorithm.hpp\"\n\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nvector<int> Z_Algorithm(string S){\n    vector<int> Z(S.size(),\
    \ 0);\n    Z[0] = S.size();\n    int i = 1, j = 0;\n    while(i < S.size()){\n\
    \        while(i + j < S.size() && S[j] == S[i + j]) ++j;\n        Z[i] = j;\n\
    \        if(j == 0){\n            ++i;\n            continue;\n        }\n   \
    \     int k = 1;\n        while(k < j && k + Z[k] < j){\n            Z[i + k]\
    \ = Z[k];\n            ++k;\n        }\n        i += k;\n        j -= k;\n   \
    \ }\n    return Z;\n}\n#line 4 \"verify/LC-ZAlgorithm.test.cpp\"\n\nint main(){\n\
    \    string S; cin >> S;\n    auto Z = Z_Algorithm(S);\n    for(auto z : Z){\n\
    \        cout << z << \" \";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../library/String/ZAlgorithm.hpp\"\n\nint main(){\n    string S; cin >> S;\n\
    \    auto Z = Z_Algorithm(S);\n    for(auto z : Z){\n        cout << z << \" \"\
    ;\n    }\n}"
  dependsOn:
  - library/String/ZAlgorithm.hpp
  isVerificationFile: true
  path: verify/LC-ZAlgorithm.test.cpp
  requiredBy: []
  timestamp: '2023-10-21 20:52:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-ZAlgorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-ZAlgorithm.test.cpp
- /verify/verify/LC-ZAlgorithm.test.cpp.html
title: verify/LC-ZAlgorithm.test.cpp
---
