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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include \"../Library/ModInt.hpp\"\n#include \"../Library/DataStructure/WeightedUnionFind.hpp\"\
    \n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n    int N, Q; cin >>\
    \ N >> Q;\n\n    WeightedUnionFind<mint> uf(N);\n    while(Q--){\n        int\
    \ t, u, v; cin >> t >> u >> v;\n        if(t == 0){\n            int x; cin >>\
    \ x;\n            if(uf.Same(u, v)){\n                cout << (uf.Diff(u, v) ==\
    \ x) << '\\n';\n            }\n            else{\n                cout << uf.Unite(u,\
    \ v, x) << '\\n';\n            }\n        }\n        else{\n            if(uf.Same(u,\
    \ v)){\n                cout << uf.Diff(u, v) << '\\n';\n            }\n     \
    \       else{\n                cout << -1 << '\\n';\n            }\n        }\n\
    \    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/LC-UnionfindWithPotential.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/LC-UnionfindWithPotential.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-UnionfindWithPotential.test.cpp
- /verify/verify/LC-UnionfindWithPotential.test.cpp.html
title: verify/LC-UnionfindWithPotential.test.cpp
---
