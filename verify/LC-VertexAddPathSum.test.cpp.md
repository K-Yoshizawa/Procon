---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../library/Tree/HeavyLightDecomposition.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../library/Tree/HeavyLightDecomposition.hpp\"\n#include \"../library/DataStructure/SegmentTree.hpp\"\
    \n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n \
    \   for(int i = 0; i < N; ++i) cin >> a[i];\n\n    vector<long long> Init_Data(N);\n\
    \    Graph<long long> G(N);\n    for(int i = 0; i < N - 1; ++i){\n        int\
    \ u, v; cin >> u >> v;\n        G.add(u, v);\n    }\n    HeavyLightDecomposition<long\
    \ long> HLD(G);\n    for(int i = 0; i < N; ++i){\n        Init_Data[HLD.get_vertex_locate(i)]\
    \ = a[i];\n    }\n\n    SegmentTree<long long> seg(Init_Data, [](long long l,\
    \ long long r){return l + r;}, 0, true);\n    while(Q--){\n        int query;\
    \ cin >> query;\n        if(query == 0){\n            long long p, x; cin >> p\
    \ >> x;\n            int lp = HLD.get_vertex_locate(p);\n            seg.update(lp,\
    \ seg[lp] + x);\n        }\n        else{\n            int u, v; cin >> u >> v;\n\
    \            auto path = HLD.path_query(u, v);\n            long long ans = 0;\n\
    \            for(auto [l, r] : path){\n                ans += seg.query(l, r);\n\
    \            }\n            cout << ans << endl;\n        }\n    }\n\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/LC-VertexAddPathSum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/LC-VertexAddPathSum.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-VertexAddPathSum.test.cpp
- /verify/verify/LC-VertexAddPathSum.test.cpp.html
title: verify/LC-VertexAddPathSum.test.cpp
---
