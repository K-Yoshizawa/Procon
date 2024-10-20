---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/unauthenticated/ZAlgorithm.hpp\"\n\n\n#include <bits/stdc++.h>\n\
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
  path: Library/unauthenticated/ZAlgorithm.hpp
  requiredBy: []
  timestamp: '2024-09-04 01:04:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/ZAlgorithm.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/ZAlgorithm.hpp
- /library/Library/unauthenticated/ZAlgorithm.hpp.html
title: Library/unauthenticated/ZAlgorithm.hpp
---
