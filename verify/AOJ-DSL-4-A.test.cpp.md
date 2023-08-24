---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/CumulativeSum2D.hpp
    title: "Cumulative Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
  - icon: ':question:'
    path: library/Other/Compress.hpp
    title: "Compress - \u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/4/DSL_4_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/4/DSL_4_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/Other/Compress.hpp: line 9: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/4/DSL_4_A\"\
    \n\n#include \"../library/Other/Compress.hpp\"\n#include \"../library/DataStructure/CumulativeSum2D.hpp\"\
    \n\nint main(){\n    int N; cin >> N;\n    vector<int> X, Y;\n    for(int i =\
    \ 0; i < N; ++i){\n        int x1, y1, x2, y2;\n        cin >> x1 >> y1 >> x2\
    \ >> y2;\n        X.push_back(x1), X.push_back(x2);\n        Y.push_back(y1),\
    \ Y.push_back(y2);\n    }\n\n    Compress<int> cpx(X), cpy(Y);\n    CumulativeSum2D<int>\
    \ cum(2 * N, 2 * N);\n    for(int i = 0; i < N; ++i){\n        cum.add(cpx.vi(X[i\
    \ * 2]), cpy.vi(Y[i * 2]), cpx.vi(X[i * 2 + 1]), cpy.vi(Y[i * 2 + 1]), 1);\n \
    \   }\n    cum.build();\n    long long ans = 0;\n    for(int i = 0; i < 2 * N;\
    \ ++i){\n        for(int j = 0; j < 2 * N; ++j){\n            if(cum.test(i, j,\
    \ [](auto x){return x > 0;})){\n                ans += ((long long)cpy.iv(i +\
    \ 1) - cpy.iv(i)) * (cpx.iv(j + 1) - cpx.iv(j));\n            }\n        }\n \
    \   }\n    cout << ans << endl;\n}"
  dependsOn:
  - library/Other/Compress.hpp
  - library/DataStructure/CumulativeSum2D.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-4-A.test.cpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-4-A.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-4-A.test.cpp
- /verify/verify/AOJ-DSL-4-A.test.cpp.html
title: verify/AOJ-DSL-4-A.test.cpp
---
