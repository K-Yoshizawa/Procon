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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../old/Tree/HeavyLightDecomposition.hpp\"\n#include \"../library/DataStructure/SegmentTree.hpp\"\
    \n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<long long> a(N), p(N);\n\
    \    Graph<int> G(N);\n    for(int i = 0; i < N; ++i) cin >> a[i];\n    for(int\
    \ i = 1; i < N; ++i){\n        cin >> p[i];\n        G.add(i, p[i]);\n    }\n\n\
    \    HeavyLightDecomposition<int> HLD(G);\n    vector<long long> Init_Data(2 *\
    \ N, 0);\n    for(int i = 0; i < N; ++i){\n        Init_Data[HLD.subtree_query(i).first]\
    \ = a[i];\n    }\n    SegmentTree<long long> seg(Init_Data,\n        [](long long\
    \ l, long long r){return l + r;},\n        0, true);\n\n    while(Q--){\n    \
    \    int q; cin >> q;\n        if(q == 0){\n            int u, x; cin >> u >>\
    \ x;\n            int i = HLD.subtree_query(u).first;\n            seg.update(i,\
    \ seg[i] + x);\n        }\n        else{\n            int u; cin >> u;\n     \
    \       auto [in, out] = HLD.subtree_query(u);\n            cout << seg.query(in,\
    \ out) << endl;\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify_old/LC-VertexAddSubtreeSum-HLD.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify_old/LC-VertexAddSubtreeSum-HLD.test.cpp
layout: document
redirect_from:
- /verify/verify_old/LC-VertexAddSubtreeSum-HLD.test.cpp
- /verify/verify_old/LC-VertexAddSubtreeSum-HLD.test.cpp.html
title: verify_old/LC-VertexAddSubtreeSum-HLD.test.cpp
---
