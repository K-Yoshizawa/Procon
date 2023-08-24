---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/CycleDetection.hpp
    title: "Cycle Detection (Directed) - \u9589\u8DEF\u691C\u51FA\uFF08\u6709\u5411\
      \u30B0\u30E9\u30D5\uFF09"
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/Graph/GraphTemplate.hpp: line 9: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../library/Graph/CycleDetection.hpp\"\
    \n\nint main(){\n    int V, E;\n    cin >> V >> E;\n    Graph<int> G(V, true);\n\
    \    for(int i = 0; i < E; ++i){\n        int s, t;\n        cin >> s >> t;\n\
    \        G.add(s, t);\n    }\n\n    CycleDetection<int> cd(G);\n    cout << cd.exist()\
    \ << endl;\n}"
  dependsOn:
  - library/Graph/CycleDetection.hpp
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-4-A.test.cpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-GRL-4-A.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-4-A.test.cpp
- /verify/verify/AOJ-GRL-4-A.test.cpp.html
title: verify/AOJ-GRL-4-A.test.cpp
---
