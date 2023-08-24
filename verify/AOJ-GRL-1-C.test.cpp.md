---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':x:'
    path: library/Graph/WarshallFloyd.hpp
    title: "Warshall-Floyd - \u5168\u70B9\u9593\u6700\u77ED\u8DDD\u96E2"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
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
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../library/Graph/WarshallFloyd.hpp\"\
    \n\nusing namespace std;\n\nint main(){\n    int V, E;\n    cin >> V >> E;\n \
    \   Graph<int> G(V, true);\n    for(int i = 0; i < E; ++i){\n        int s, t,\
    \ d;\n        cin >> s >> t >> d;\n        G.add(s, t, d);\n    }\n\n    WarshallFloyd<int>\
    \ wf(G);\n    if(wf.negative){\n        cout << \"NEGATIVE CYCLE\\n\";\n    }\n\
    \    else{\n        for(auto &i : wf.dist){\n            for(int j = 0; j < i.size();\
    \ ++j){\n                if(i[j] == G.INF) cout << \"INF\";\n                else\
    \ cout << i[j];\n                if(j != i.size() - 1) cout << \" \";\n      \
    \      }\n            cout << endl;\n        }\n    }\n}"
  dependsOn:
  - library/Graph/WarshallFloyd.hpp
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-1-C.test.cpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/AOJ-GRL-1-C.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-1-C.test.cpp
- /verify/verify/AOJ-GRL-1-C.test.cpp.html
title: verify/AOJ-GRL-1-C.test.cpp
---
