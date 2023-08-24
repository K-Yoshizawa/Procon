---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':question:'
    path: library/DataStructure/BinaryIndexedTreeDouble.hpp
    title: "Binary Indexed Tree (Double) - Range Add Query\u5BFE\u5FDC\u7248"
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':x:'
    path: library/Tree/HeavyLightDecomposition.hpp
    title: "Heavy Light Decomposition - HL\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
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
  code: "#define IGNORE\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \n\n#include \"../library/DataStructure/BinaryIndexedTreeDouble.hpp\"\n#include\
    \ \"../library/Tree/HeavyLightDecomposition.hpp\"\n\nint main(){\n    int n;\n\
    \    cin >> n;\n    Graph<long long> G(n);\n    for(int i = 0; i < n; ++i){\n\
    \        int k;\n        cin >> k;\n        for(int j = 0; j < k; ++j){\n    \
    \        int c;\n            cin >> c;\n            G.add(i, c, 0);\n        }\n\
    \    }\n\n    HeavyLightDecompsition<long long> HLD(G);\n    BinaryIndexedTreeDouble<long\
    \ long> BIT(n);\n\n    auto relation = G.get_parent(0);\n\n    int q;\n    cin\
    \ >> q;\n    while(q--){\n        int query;\n        cin >> query;\n        if(query\
    \ == 0){\n            int v, w;\n            cin >> v >> w;\n            auto\
    \ seg = HLD.get_segment(v);\n            for(auto &[s, t] : seg){\n          \
    \      BIT.add(s, t, w);\n            }\n            BIT.add(1, 2, -1);\n    \
    \    }\n        else{\n            int u;\n            cin >> u;\n           \
    \ auto seg = HLD.get_segment(u);\n            long long ans = 0;\n           \
    \ for(auto &[s, t] : seg){\n                ans += BIT.query(s, t);\n        \
    \    }\n            cout << ans << endl;\n        }\n    }\n}"
  dependsOn:
  - library/DataStructure/BinaryIndexedTreeDouble.hpp
  - library/DataStructure/BinaryIndexedTree.hpp
  - library/Tree/HeavyLightDecomposition.hpp
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: true
  path: verify/AOJ-GRL-5-E.test.cpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/AOJ-GRL-5-E.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-GRL-5-E.test.cpp
- /verify/verify/AOJ-GRL-5-E.test.cpp.html
title: verify/AOJ-GRL-5-E.test.cpp
---
