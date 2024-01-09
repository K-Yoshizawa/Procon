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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../old/DataStructure/LazySegmentTree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \n\n#include \"../old/Tree/HeavyLightDecomposition.hpp\"\n#include \"../old/DataStructure/LazySegmentTree.hpp\"\
    \n\nstruct Data{\n    long long val{0};\n    long long len{1};\n\n    Data() :\
    \ val(0), len(1){}\n    Data(int val, int len) : val(val), len(len){}\n\n    bool\
    \ operator==(const Data& y){\n        return val == y.val && len == y.len;\n \
    \   }\n\n    static Data Merge(const Data& x, const Data& y){\n        Data ret;\n\
    \        ret.val = x.val + y.val;\n        ret.len = x.len + y.len;\n        return\
    \ ret;\n    }\n\n    static Data Mapping(const Data& x, const long long y){\n\
    \        Data ret;\n        ret.val = x.val + y * x.len;\n        ret.len = x.len;\n\
    \        return ret;\n    }\n};\n\nint main(){\n    int n; cin >> n;\n    Graph<long\
    \ long> G(n);\n    for(int i = 0; i < n; ++i){\n        int k; cin >> k;\n   \
    \     for(int j = 0; j < k; ++j){\n            int c; cin >> c;\n            G.add(i,\
    \ c);\n        }\n    }\n\n    HeavyLightDecomposition<long long> HLD(G);\n  \
    \  auto vdic = HLD.get_vertex_locations();\n    vector<Data> Init_Data(n, Data());\n\
    \    LazySegmentTree<Data, long long> seg(Init_Data,\n        [](const Data l,\
    \ const Data r){return Data::Merge(l, r);},\n        [](const Data l, const long\
    \ long r){return Data::Mapping(l, r);},\n        [](const long long l, const long\
    \ long r){return l + r;},\n        Data(), 0, true\n    );\n\n    int q; cin >>\
    \ q;\n    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n       \
    \     int v, w; cin >> v >> w;\n            auto ret = HLD.path_query(0, v);\n\
    \            for(auto [l, r] : ret){\n                seg.update(l, r, w);\n \
    \           }\n            seg.update(0, 1, -w);\n        }\n        else{\n \
    \           int u; cin >> u;\n            auto ret = HLD.path_query(0, u);\n \
    \           long long ans = 0LL;\n            for(auto [l, r] : ret){\n      \
    \          ans += seg.query(l, r).val;\n            }\n            cout << ans\
    \ << endl;\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify_old/AOJ-GRL-5-E.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify_old/AOJ-GRL-5-E.test.cpp
layout: document
redirect_from:
- /verify/verify_old/AOJ-GRL-5-E.test.cpp
- /verify/verify_old/AOJ-GRL-5-E.test.cpp.html
title: verify_old/AOJ-GRL-5-E.test.cpp
---
