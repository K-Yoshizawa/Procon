---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DynamicPrograming/LongestIncreasingSubsequence.hpp
    title: "Longest Increasing Subsequence - \u6700\u9577\u90E8\u5206\u5897\u52A0\u5217"
  - icon: ':question:'
    path: library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D
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
    \ library/Template.hpp: line 9: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D\"\
    \n\n#include \"../library/Template.hpp\"\n\n#include \"../library/DynamicPrograming/LongestIncreasingSubsequence.hpp\"\
    \n\nint main(){\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    cin >>\
    \ a;\n    cout << LongestIncreasingSubsequence(a) << endl;\n}"
  dependsOn:
  - library/Template.hpp
  - library/DynamicPrograming/LongestIncreasingSubsequence.hpp
  isVerificationFile: true
  path: verify/AOJ-DPL-1-D.test.cpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DPL-1-D.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DPL-1-D.test.cpp
- /verify/verify/AOJ-DPL-1-D.test.cpp.html
title: verify/AOJ-DPL-1-D.test.cpp
---
