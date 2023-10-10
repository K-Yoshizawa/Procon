---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Prime Factorize - \u7D20\u56E0\u6570\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"library/Math/PrimeFactorize.hpp\"\n\n/**\n * @brief Prime\
    \ Factorize - \u7D20\u56E0\u6570\u5206\u89E3\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/**\n * @brief \u6574\u6570x\u3092\u7D20\u56E0\u6570\u5206\
    \u89E3\u3057\u3001\u305D\u306E\u7D50\u679C\u3092\u8FD4\u3059\n * @param x \u7D20\
    \u56E0\u6570\u5206\u89E3\u3059\u308B\u6574\u6570\n * @return vector<pair<long\
    \ long, int>> \u7D20\u56E0\u6570\u3068\u542B\u307E\u308C\u308B\u500B\u6570\u306E\
    \u4E00\u89A7\n */\nvector<pair<long long, int>> PrimeFactorize(long long x){\n\
    \    if(x < 0) x = -x;\n    long long y = x;\n    vector<pair<long long, int>>\
    \ ret;\n    for(long long div = 2; div * div <= x; ++div){\n        int cnt =\
    \ 0;\n        while(y % div == 0) ++cnt, y /= div;\n        if(cnt != 0) ret.push_back({div,\
    \ cnt});\n    }\n    if(y != 1) ret.push_back({y, 1});\n    return ret;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Prime Factorize - \u7D20\u56E0\u6570\u5206\
    \u89E3\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n/**\n * @brief\
    \ \u6574\u6570x\u3092\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001\u305D\u306E\u7D50\
    \u679C\u3092\u8FD4\u3059\n * @param x \u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\
    \u6574\u6570\n * @return vector<pair<long long, int>> \u7D20\u56E0\u6570\u3068\
    \u542B\u307E\u308C\u308B\u500B\u6570\u306E\u4E00\u89A7\n */\nvector<pair<long\
    \ long, int>> PrimeFactorize(long long x){\n    if(x < 0) x = -x;\n    long long\
    \ y = x;\n    vector<pair<long long, int>> ret;\n    for(long long div = 2; div\
    \ * div <= x; ++div){\n        int cnt = 0;\n        while(y % div == 0) ++cnt,\
    \ y /= div;\n        if(cnt != 0) ret.push_back({div, cnt});\n    }\n    if(y\
    \ != 1) ret.push_back({y, 1});\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/Math/PrimeFactorize.hpp
  requiredBy: []
  timestamp: '2023-08-23 13:10:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Math/PrimeFactorize.hpp
layout: document
redirect_from:
- /library/library/Math/PrimeFactorize.hpp
- /library/library/Math/PrimeFactorize.hpp.html
title: "Prime Factorize - \u7D20\u56E0\u6570\u5206\u89E3"
---
