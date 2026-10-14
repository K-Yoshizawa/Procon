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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/ModInt.hpp\"\n\
    #include \"../Library/DataStructure/DualSegmentTree.hpp\"\n\nstruct OperatorMonoid{\n\
    \    mint b, c;\n    OperatorMonoid(mint b_ = 1, mint c_ = 0) : b(b_), c(c_){}\n\
    \    static OperatorMonoid Composite(OperatorMonoid &l, OperatorMonoid &r){\n\
    \        return OperatorMonoid(r.b * l.b, r.b * l.c + r.c);\n    }\n};\n\nint\
    \ main(){\n    cin.tie(0)->sync_with_stdio(false);\n    int N, Q; cin >> N >>\
    \ Q;\n    vector<mint> a(N); cin >> a;\n\n    DualSegmentTree<mint, OperatorMonoid>\
    \ seg(\n        a,\n        [](mint v, OperatorMonoid x){return x.b * v + x.c;},\n\
    \        [](OperatorMonoid l, OperatorMonoid r){return OperatorMonoid::Composite(l,\
    \ r);},\n        OperatorMonoid(),\n        true\n    );\n    while(Q--){\n  \
    \      int t; cin >> t;\n        if(t == 0){\n            int l, r, b, c; cin\
    \ >> l >> r >> b >> c;\n            seg.Apply(l, r, OperatorMonoid(b, c));\n \
    \       }\n        else{\n            int i; cin >> i;\n            cout << seg.Fold(i)\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/LC-RangeAffinePointGet.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/LC-RangeAffinePointGet.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-RangeAffinePointGet.test.cpp
- /verify/verify/LC-RangeAffinePointGet.test.cpp.html
title: verify/LC-RangeAffinePointGet.test.cpp
---
