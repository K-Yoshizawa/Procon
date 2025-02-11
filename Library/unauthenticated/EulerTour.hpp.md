---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.1/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.1/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.1/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.1/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Graph/GraphTemplate.hpp:\
    \ line -1: no such header\n"
  code: "/**\n * @file EulerTour.hpp\n * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\
    \u30C4\u30A2\u30FC\n * @version 3.0\n * @date 2024-02-11\n */\n\n#include \"../Graph/GraphTemplate.hpp\"\
    \n\ntemplate<typename CostType>\nstruct EulerTour{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<int> in_, out_;\n\n    void dfs_(Vertex v, Vertex p, int &t){\n\
    \        in_[v] = t++;\n        for(auto &e : G[v]){\n            if(e.to == p)\
    \ continue;\n            dfs_(e.to, v, t);\n        }\n        out_[v] = t++;\n\
    \    }\n\n    public:\n    /**\n     * @brief Construct a new Euler Tour object\n\
    \     * @param G \u6728\n     * @param Root \u6839\u306E\u9802\u70B9\u756A\u53F7\
    (0-index)\n     * @param Offset \u30BF\u30A4\u30E0\u30B9\u30BF\u30F3\u30D7\u306E\
    \u521D\u671F\u5024\n     */\n    EulerTour(Graph<CostType> &G, Vertex Root = 0,\
    \ int Offset = 0) : G(G){\n        in_.resize(G.size());\n        out_.resize(G.size());\n\
    \        dfs_(Root, -1, Offset);\n    }\n\n    int in(Vertex v){\n        assert(0\
    \ <= v && v < G.size());\n        return in_[v];\n    }\n\n    int out(Vertex\
    \ v){\n        assert(0 <= v && v < G.size());\n        return out_[v];\n    }\n\
    \n    pair<vector<int>, vector<int>> get(){\n        return make_pair(in_, out_);\n\
    \    }\n\n    pair<int, int> operator[](Vertex v){\n        return make_pair(in(v),\
    \ out(v));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/unauthenticated/EulerTour.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/EulerTour.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/EulerTour.hpp
- /library/Library/unauthenticated/EulerTour.hpp.html
title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
---
