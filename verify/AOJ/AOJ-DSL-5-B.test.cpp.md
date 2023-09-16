---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/CumulativeSum2D.hpp
    title: "Cumulative Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/DataStructure/CumulativeSum2D.hpp: line 9: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n\n#include \"../../library/DataStructure/CumulativeSum2D.hpp\"\n\nint main(){\n\
    \    int N; cin >> N;\n    CumulativeSum2D<int> cum(1001, 1001);\n    for(int\
    \ i = 0; i < N; ++i){\n        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;\n\
    \        cum.add(x1, y1, x2, y2, 1);\n    }\n    cum.build();\n    cout << cum.max()\
    \ << endl;\n}\n"
  dependsOn:
  - library/DataStructure/CumulativeSum2D.hpp
  isVerificationFile: true
  path: verify/AOJ/AOJ-DSL-5-B.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 12:21:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ/AOJ-DSL-5-B.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ/AOJ-DSL-5-B.test.cpp
- /verify/verify/AOJ/AOJ-DSL-5-B.test.cpp.html
title: verify/AOJ/AOJ-DSL-5-B.test.cpp
---
