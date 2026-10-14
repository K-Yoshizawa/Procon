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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/ModInt.hpp\"\n\
    #include \"../Library/Tree/RerootingDP.hpp\"\n\nstruct Affine{\n    Affine() =\
    \ default;\n    Affine(mint b, mint c) : b(b), c(c){}\n    mint b{1}, c{0};\n\
    \    friend ostream &operator<<(ostream &os, const Affine &p) {\n        return\
    \ os << \"{\" << p.b << \", \" << p.c << \"}\";\n    }\n};\n\nstruct Monoid{\n\
    \    Monoid() = default;\n    Monoid(mint v, mint c) : val(v), cnt(c){}\n    mint\
    \ val{0}, cnt{0};\n    friend ostream &operator<<(ostream &os, const Monoid &p)\
    \ {\n        return os << \"{\" << p.val << \", \" << p.cnt << \"}\";\n    }\n\
    };\n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n    int N; cin >>\
    \ N;\n    vector<mint> a(N); cin >> a;\n    Graph<Affine> T(N);\n    for(int i\
    \ = 0; i < N - 1; ++i){\n        int u, v; cin >> u >> v;\n        mint b, c;\
    \ cin >> b >> c;\n        T.AddUndirectedEdge(u, v, Affine(b, c));\n    }\n\n\
    \    RerootingDP<Affine, Monoid> dp(\n        T,\n        [](Monoid l, Monoid\
    \ r, Vertex i){\n            return Monoid(l.val + r.val, l.cnt + r.cnt);\n  \
    \      },\n        [&](Monoid x, Affine m, Vertex i){\n            return Monoid(m.b\
    \ * (a[i] + x.val) + (x.cnt + 1) * m.c, x.cnt + 1);\n        },\n        [&](Monoid\
    \ x, Vertex i){\n            return Monoid(x.val + a[i], x.cnt + 1);\n       \
    \ },\n        Monoid()\n    );\n    for(int i = 0; i < N; ++i){\n        cout\
    \ << dp[i].val << \" \";\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/LC-TreePathCompositeSum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/LC-TreePathCompositeSum.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-TreePathCompositeSum.test.cpp
- /verify/verify/LC-TreePathCompositeSum.test.cpp.html
title: verify/LC-TreePathCompositeSum.test.cpp
---
