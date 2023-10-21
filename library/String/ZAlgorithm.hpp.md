---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-ZAlgorithm.test.cpp
    title: verify/LC-ZAlgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/String/ZAlgorithm.hpp\"\n\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nvector<int> Z_Algorithm(string S){\n    vector<int> Z(S.size(),\
    \ 0);\n    Z[0] = S.size();\n    int i = 1, j = 0;\n    while(i < S.size()){\n\
    \        while(i + j < S.size() && S[j] == S[i + j]) ++j;\n        Z[i] = j;\n\
    \        if(j == 0){\n            ++i;\n            continue;\n        }\n   \
    \     int k = 1;\n        while(k < j && k + Z[k] < j){\n            Z[i + k]\
    \ = Z[k];\n            ++k;\n        }\n        i += k;\n        j -= k;\n   \
    \ }\n    return Z;\n}\n"
  code: "\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int> Z_Algorithm(string\
    \ S){\n    vector<int> Z(S.size(), 0);\n    Z[0] = S.size();\n    int i = 1, j\
    \ = 0;\n    while(i < S.size()){\n        while(i + j < S.size() && S[j] == S[i\
    \ + j]) ++j;\n        Z[i] = j;\n        if(j == 0){\n            ++i;\n     \
    \       continue;\n        }\n        int k = 1;\n        while(k < j && k + Z[k]\
    \ < j){\n            Z[i + k] = Z[k];\n            ++k;\n        }\n        i\
    \ += k;\n        j -= k;\n    }\n    return Z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/String/ZAlgorithm.hpp
  requiredBy: []
  timestamp: '2023-10-21 20:52:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-ZAlgorithm.test.cpp
documentation_of: library/String/ZAlgorithm.hpp
layout: document
redirect_from:
- /library/library/String/ZAlgorithm.hpp
- /library/library/String/ZAlgorithm.hpp.html
title: library/String/ZAlgorithm.hpp
---
