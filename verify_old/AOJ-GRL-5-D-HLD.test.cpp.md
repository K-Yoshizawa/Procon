---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../old/Tree/HeavyLightDecomposition.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D\"\
    \n\n#include \"../old/Tree/HeavyLightDecomposition.hpp\"\n#include \"../library/DataStructure/SegmentTree.hpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    Graph<long long> G(n);\n    for(int\
    \ i = 0; i < n; ++i){\n        int k; cin >> k;\n        for(int j = 0; j < k;\
    \ ++j){\n            int c; cin >> c;\n            G.add(i, c);\n        }\n \
    \   }\n\n    HeavyLightDecomposition<long long> HLD(G);\n    auto vdic = HLD.get_vertex_locations();\n\
    \    vector<long long> Init_Data(n, 0);\n    SegmentTree<long long> seg(Init_Data,\
    \ [](long long x, long long y){return x + y;}, 0LL, true);\n\n    int q; cin >>\
    \ q;\n    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n       \
    \     int v, w; cin >> v >> w;\n            seg.update(vdic[v], seg[vdic[v]] +\
    \ w);\n        }\n        else{\n            int u; cin >> u;\n            auto\
    \ ret = HLD.path_query(0, u);\n            long long ans = 0LL;\n            for(auto\
    \ [l, r] : ret){\n                ans += seg.query(l, r);\n            }\n   \
    \         cout << ans << endl;\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify_old/AOJ-GRL-5-D-HLD.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify_old/AOJ-GRL-5-D-HLD.test.cpp
layout: document
redirect_from:
- /verify/verify_old/AOJ-GRL-5-D-HLD.test.cpp
- /verify/verify_old/AOJ-GRL-5-D-HLD.test.cpp.html
title: verify_old/AOJ-GRL-5-D-HLD.test.cpp
---
