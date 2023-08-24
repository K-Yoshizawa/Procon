---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/Tree/EulerTour.hpp
    title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
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
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D\"\
    \n\n#include \"../library/Tree/EulerTour.hpp\"\n\nint main(){\n    int n;\n  \
    \  cin >> n;\n    Graph<long long> G(n);\n    for(int i = 0; i < n; ++i){\n  \
    \      int k;\n        cin >> k;\n        for(int j = 0; j < k; ++j){\n      \
    \      int c;\n            cin >> c;\n            G.add(i, c, 0);\n        }\n\
    \    }\n    EulerTour<long long> et(G);\n    int q;\n    cin >> q;\n    while(q--){\n\
    \        int com;\n        cin >> com;\n        if(com == 0){\n            long\
    \ long v, w;\n            cin >> v >> w;\n            et.add(v, w);\n        }\n\
    \        else{\n            int u;\n            cin >> u;\n            cout <<\
    \ et.query(u) << endl;\n        }\n    }\n}"
  dependsOn:
  - library/Tree/EulerTour.hpp
  - library/Graph/GraphTemplate.hpp
  - library/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-5-D.test.cpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-GRL-5-D.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-5-D.test.cpp
- /verify/verify/AOJ-GRL-5-D.test.cpp.html
title: verify/AOJ-GRL-5-D.test.cpp
---
