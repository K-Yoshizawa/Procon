---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Math/PrimeFactorize.hpp
    title: "Prime Factorize - \u7D20\u56E0\u6570\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"verify/AOJ/AOJ-NTL-1-A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#include <bits/stdc++.h>\n\n#line 2 \"library/Math/PrimeFactorize.hpp\"\n\n\
    /**\n * @brief Prime Factorize - \u7D20\u56E0\u6570\u5206\u89E3\n */\n\n#line\
    \ 8 \"library/Math/PrimeFactorize.hpp\"\nusing namespace std;\n\n/**\n * @brief\
    \ \u6574\u6570x\u3092\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001\u305D\u306E\u7D50\
    \u679C\u3092\u8FD4\u3059\n * @param x \u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\
    \u6574\u6570\n * @return vector<pair<long long, int>> \u7D20\u56E0\u6570\u3068\
    \u542B\u307E\u308C\u308B\u500B\u6570\u306E\u4E00\u89A7\n */\nvector<pair<long\
    \ long, int>> PrimeFactorize(long long x){\n    if(x < 0) x = -x;\n    long long\
    \ y = x;\n    vector<pair<long long, int>> ret;\n    for(long long div = 2; div\
    \ * div <= x; ++div){\n        int cnt = 0;\n        while(y % div == 0) ++cnt,\
    \ y /= div;\n        if(cnt != 0) ret.push_back({div, cnt});\n    }\n    if(y\
    \ != 1) ret.push_back({y, 1});\n    return ret;\n}\n#line 6 \"verify/AOJ/AOJ-NTL-1-A.test.cpp\"\
    \n\nint main(){\n    long long n; cin >> n;\n    auto ans = PrimeFactorize(n);\n\
    \    cout << n << \":\";\n    for(int i = 0; i < ans.size(); ++i){\n        for(int\
    \ j = 0; j < ans[i].second; ++j){\n            cout << \" \" << ans[i].first;\n\
    \        }\n    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../library/Math/PrimeFactorize.hpp\"\
    \n\nint main(){\n    long long n; cin >> n;\n    auto ans = PrimeFactorize(n);\n\
    \    cout << n << \":\";\n    for(int i = 0; i < ans.size(); ++i){\n        for(int\
    \ j = 0; j < ans[i].second; ++j){\n            cout << \" \" << ans[i].first;\n\
    \        }\n    }\n    cout << endl;\n}"
  dependsOn:
  - library/Math/PrimeFactorize.hpp
  isVerificationFile: true
  path: verify/AOJ/AOJ-NTL-1-A.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 12:21:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ/AOJ-NTL-1-A.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ/AOJ-NTL-1-A.test.cpp
- /verify/verify/AOJ/AOJ-NTL-1-A.test.cpp.html
title: verify/AOJ/AOJ-NTL-1-A.test.cpp
---
