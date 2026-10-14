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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/Tree/HeavyLightDecomposition.hpp\"\
    \n#include \"../Library/DataStructure/SegmentTree.hpp\"\n#include \"../Library/ModInt.hpp\"\
    \n\nstruct Affine{\n    Affine() = default;\n    Affine(mint a, mint b) : a(a),\
    \ b(b){}\n    mint a{1}, b{0};\n    static Affine left_merge(Affine l, Affine\
    \ r){\n        return Affine(r.a * l.a, r.a * l.b + r.b);\n    }\n    static Affine\
    \ right_merge(Affine l, Affine r){\n        return Affine(l.a * r.a, l.a * r.b\
    \ + l.b);\n    }\n    friend ostream &operator<<(ostream &os, const Affine &p)\
    \ {\n        return os << \"{\" << p.a << \", \" << p.b << \"}\";\n    }\n};\n\
    \nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n    int N, Q; cin >> N\
    \ >> Q;\n    vector<Affine> init_data;\n    for(int i = 0; i < N; ++i){\n    \
    \    mint a, b; cin >> a >> b;\n        init_data.push_back(Affine(a, b));\n \
    \   }\n    auto T = InputTree(N, 0);\n\n    HeavyLightDecomposition hld(T);\n\
    \    hld.SortVertex(init_data);\n    SegmentTree<Affine> seg1(init_data, [](Affine\
    \ l, Affine r){return Affine::left_merge(l, r);}, Affine(), true);\n    SegmentTree<Affine>\
    \ seg2(init_data, [](Affine l, Affine r){return Affine::right_merge(l, r);}, Affine(),\
    \ true);\n    while(Q--){\n        int t; cin >> t;\n        if(t == 0){\n   \
    \         int p, c, d; cin >> p >> c >> d;\n            seg1.Apply(hld[p], Affine(c,\
    \ d));\n            seg2.Apply(hld[p], Affine(c, d));\n        }\n        else{\n\
    \            int u, v, x; cin >> u >> v >> x;\n            Affine ans;\n     \
    \       for(auto &path : hld.PathQuery(u, v)){\n                if(path.reverse)\
    \ ans = Affine::left_merge(ans, seg2.Fold(path.head_index, path.tail_index));\n\
    \                else ans = Affine::left_merge(ans, seg1.Fold(path.head_index,\
    \ path.tail_index));\n            }\n            cout << ans.a * x + ans.b <<\
    \ '\\n';\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/LC-VertexSetPathComposite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/LC-VertexSetPathComposite.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-VertexSetPathComposite.test.cpp
- /verify/verify/LC-VertexSetPathComposite.test.cpp.html
title: verify/LC-VertexSetPathComposite.test.cpp
---
