---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/String/ZAlgorithm.hpp\"\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bit>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 4 \"Library/String/ZAlgorithm.hpp\"\n\nvector<int> ZAlgorithm(string\
    \ S){\n    vector<int> Z(S.size(), 0);\n    Z[0] = S.size();\n    int i = 1, j\
    \ = 0;\n    while(i < S.size()){\n        while(i + j < S.size() && S[j] == S[i\
    \ + j]) ++j;\n        Z[i] = j;\n        if(j == 0){\n            ++i;\n     \
    \       continue;\n        }\n        int k = 1;\n        while(k < j && k + Z[k]\
    \ < j){\n            Z[i + k] = Z[k];\n            ++k;\n        }\n        i\
    \ += k;\n        j -= k;\n    }\n    return Z;\n}\n"
  code: "#pragma once\n\n#include \"../Common.hpp\"\n\nvector<int> ZAlgorithm(string\
    \ S){\n    vector<int> Z(S.size(), 0);\n    Z[0] = S.size();\n    int i = 1, j\
    \ = 0;\n    while(i < S.size()){\n        while(i + j < S.size() && S[j] == S[i\
    \ + j]) ++j;\n        Z[i] = j;\n        if(j == 0){\n            ++i;\n     \
    \       continue;\n        }\n        int k = 1;\n        while(k < j && k + Z[k]\
    \ < j){\n            Z[i + k] = Z[k];\n            ++k;\n        }\n        i\
    \ += k;\n        j -= k;\n    }\n    return Z;\n}"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/String/ZAlgorithm.hpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/String/ZAlgorithm.hpp
layout: document
redirect_from:
- /library/Library/String/ZAlgorithm.hpp
- /library/Library/String/ZAlgorithm.hpp.html
title: Library/String/ZAlgorithm.hpp
---
