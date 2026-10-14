---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Library/ModInt.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/DataStructure/SegmentTree.hpp\"\
    \n#include \"../Library/ModInt.hpp\"\n\nstruct Affine{\n    Affine(mint a = 1,\
    \ mint b = 0) : a(a), b(b){}\n    mint Value(mint x) const {\n        return a\
    \ * x + b;\n    }\n    static Affine Merge(Affine l, Affine r){\n        return\
    \ Affine(l.a * r.a, l.b * r.a + r.b);\n    }\n    mint a, b;\n};\n\nint main(){\n\
    \    cin.tie(0)->sync_with_stdio(false);\n    int N, Q; cin >> N >> Q;\n    vector<Affine>\
    \ init_data;\n    for(int i = 0; i < N; ++i){\n        int a, b; cin >> a >> b;\n\
    \        init_data.push_back(Affine(a, b));\n    }\n\n    SegmentTree<Affine>\
    \ seg(init_data, [](Affine l, Affine r){return Affine::Merge(l, r);}, Affine(),\
    \ true);\n    while(Q--){\n        int t; cin >> t;\n        if(t == 0){\n   \
    \         int p, c, d; cin >> p >> c >> d;\n            seg.Apply(p, Affine(c,\
    \ d));\n        }\n        else{\n            int l, r, x; cin >> l >> r >> x;\n\
    \            cout << seg.Fold(l, r).Value(x) << '\\n';\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/LC-PointSetRangeComposite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/LC-PointSetRangeComposite.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-PointSetRangeComposite.test.cpp
- /verify/verify/LC-PointSetRangeComposite.test.cpp.html
title: verify/LC-PointSetRangeComposite.test.cpp
---
