---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Auxiliary Tree - \u88DC\u52A9\u6728"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Graph/GraphTemplate.hpp:\
    \ line -1: no such header\n"
  code: "/**\n * @file AuxiliaryTree.hpp\n * @brief Auxiliary Tree - \u88DC\u52A9\u6728\
    \n * @version 1.0\n * @date 2024-02-11\n */\n\n#include \"EulerTour.hpp\"\n#include\
    \ \"LowestCommonAncestor.hpp\"\n\ntemplate<typename CostType>\nstruct AuxiliaryTree{\n\
    \    private:\n    Graph<CostType> &G;\n    vector<int> aux_, ori_, par_;\n  \
    \  EulerTour<CostType> et_;\n    LowestCommonAncestor<CostType> lca_;\n\n    public:\n\
    \    AuxiliaryTree(Graph<CostType> &G, Vertex Root = 0) : G(G), et_(G, Root),\
    \ lca_(G, Root){\n        int n = G.size();\n        aux_.resize(n, -1);\n   \
    \     ori_.resize(n, -1);\n        par_.resize(n, -1);\n    }\n\n    /**\n   \
    \  * @brief \u9802\u70B9\u96C6\u5408 `vs` \u3092\u542B\u3080\u88DC\u52A9\u6728\
    \ `T'` \u3092\u751F\u6210\u3059\u308B\u3002\n     * @param vs \u9802\u70B9\u96C6\
    \u5408\n     * @return Graph<CostType> \u751F\u6210\u3057\u305F\u88DC\u52A9\u6728\
    \ `T'`\n     */\n    Graph<CostType> build(vector<Vertex> &vs){\n        int m\
    \ = vs.size();\n        sort(vs.begin(), vs.end(), [&](int i, int j){\n      \
    \      return et_.in(i) < et_.in(j);\n        });\n        for(int i = 0; i <\
    \ m - 1; ++i){\n            vs.push_back(lca_.get(vs[i], vs[i + 1]));\n      \
    \  }\n        sort(vs.begin(), vs.end(), [&](int i, int j){\n            return\
    \ et_.in(i) < et_.in(j);\n        });\n        vs.erase(unique(vs.begin(), vs.end()),\
    \ vs.end());\n        m = vs.size();\n        for(int i = 0; i < m; ++i) aux_[vs[i]]\
    \ = i, ori_[i] = vs[i];\n        stack<Vertex> st;\n        st.push(vs[0]);\n\
    \        for(int i = 1; i < m; ++i){\n            while(et_.out(st.top()) < et_.in(vs[i]))\
    \ st.pop();\n            if(st.size()) par_[vs[i]] = st.top();\n            st.push(vs[i]);\n\
    \        }\n        Graph ret(m);\n        for(int i = 1; i < m; ++i){\n     \
    \       ret.add(aux_[par_[vs[i]]], aux_[vs[i]]);\n        }\n        return ret;\n\
    \    }\n\n    /**\n     * @brief \u88DC\u52A9\u6728 `T'` \u306B\u304A\u3051\u308B\
    \u9802\u70B9 `v` \u304C\u5143\u306E\u6728 `T` \u306E\u3069\u306E\u9802\u70B9\u306B\
    \u5BFE\u5FDC\u3059\u308B\u304B\u3092\u8FD4\u3059\u95A2\u6570\n     * @param v\
    \ \u6700\u5F8C\u306B\u751F\u6210\u3057\u305F\u88DC\u52A9\u6728 `T'` \u306B\u304A\
    \u3051\u308B\u9802\u70B9 (0-index)\n     * @return int \u5143\u306E\u6728 `T`\
    \ \u306B\u304A\u3051\u308B\u9802\u70B9\u756A\u53F7 (0-index)\n     */\n    int\
    \ recall(int v){\n        return ori_[v];\n    }\n\n    int operator[](int v){\n\
    \        return recall(v);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/unauthenticated/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/AuxiliaryTree.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/AuxiliaryTree.hpp
- /library/Library/unauthenticated/AuxiliaryTree.hpp.html
title: "Auxiliary Tree - \u88DC\u52A9\u6728"
---
