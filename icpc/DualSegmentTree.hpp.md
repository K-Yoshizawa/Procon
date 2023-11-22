---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DSL-2-D.test.cpp
    title: verify_icpc/AOJ-DSL-2-D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4F5C\u7528\u7D20\u306E\u5727\u7E2E\u90E8\u5206\u3002\u554F\u984C\
      \u306B\u3088\u3063\u3066\u66F8\u304D\u63DB\u3048\u308B\u3002"
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\n#line 2 \"icpc/DualSegmentTree.hpp\"\
    \n\nstruct segtree{\n    int sz, ofs;\n    vl laz;\n    ll oe;\n\n    /**\n  \
    \   * @brief \u4F5C\u7528\u7D20\u306E\u5727\u7E2E\u90E8\u5206\u3002\u554F\u984C\
    \u306B\u3088\u3063\u3066\u66F8\u304D\u63DB\u3048\u308B\u3002\n     * @note \u3053\
    \u308C\u306F Range Update Query \u306E\u5727\u7E2E\n     */\n    ll composite(ll\
    \ x, ll y){\n        return y;\n    }\n\n    void eval(int i){\n        if(laz[i]\
    \ == oe) return;\n        if(i < sz){\n            laz[i * 2] = composite(laz[i\
    \ * 2], laz[i]);\n            laz[i * 2 + 1] = composite(laz[i * 2 + 1], laz[i]);\n\
    \            laz[i] = oe;\n        }\n    }\n\n    void subupdate(int ul, int\
    \ ur, ll x, int l, int r, int i){\n        eval(i);\n        if(ul <= l && r <=\
    \ ur){\n            laz[i] = composite(laz[i], x);\n            eval(i);\n   \
    \     }\n        else if(ul < r && l < ur){\n            int m = (l + r) / 2;\n\
    \            subupdate(ul, ur, x, l, m, i * 2);\n            subupdate(ul, ur,\
    \ x, m, r, i * 2 + 1);\n        }\n    }\n\n    ll subquery(int i, int l, int\
    \ r, int c){\n        eval(c);\n        if(i == l && r - l == 1) return laz[c];\n\
    \        int m = (l + r) / 2;\n        if(i < m) return subquery(i, l, m, c *\
    \ 2);\n        else return subquery(i, m, r, c * 2 + 1);\n    }\n\n    /**\n \
    \    * @note oe \u306F\u4F5C\u7528\u7D20\u306E\u5358\u4F4D\u5143\u3002\u554F\u984C\
    \u306B\u3088\u3063\u3066\u66F8\u304D\u63DB\u3048\u308B\u3002\n     * @note \u3053\
    \u308C\u306F Range Minimum Query \u306E\u5358\u4F4D\u5143\n     */\n    segtree(vl\
    \ &init) : oe((1LL << 31) - 1){\n        sz = 1;\n        while(sz < init.size())\
    \ sz <<= 1;\n        ofs = sz - 1;\n        laz.resize(sz * 2, oe);\n        for(int\
    \ i = 0; i < init.size(); ++i) laz[sz + i] = init[i];\n    }\n\n    void update(int\
    \ l, int r, ll v){\n        subupdate(l, r, v, 1, sz + 1, 1);\n    }\n\n    ll\
    \ query(int i){\n        return subquery(i, 1, sz + 1, 1);\n    }\n};\n"
  code: "#include \"Template.hpp\"\n\nstruct segtree{\n    int sz, ofs;\n    vl laz;\n\
    \    ll oe;\n\n    /**\n     * @brief \u4F5C\u7528\u7D20\u306E\u5727\u7E2E\u90E8\
    \u5206\u3002\u554F\u984C\u306B\u3088\u3063\u3066\u66F8\u304D\u63DB\u3048\u308B\
    \u3002\n     * @note \u3053\u308C\u306F Range Update Query \u306E\u5727\u7E2E\n\
    \     */\n    ll composite(ll x, ll y){\n        return y;\n    }\n\n    void\
    \ eval(int i){\n        if(laz[i] == oe) return;\n        if(i < sz){\n      \
    \      laz[i * 2] = composite(laz[i * 2], laz[i]);\n            laz[i * 2 + 1]\
    \ = composite(laz[i * 2 + 1], laz[i]);\n            laz[i] = oe;\n        }\n\
    \    }\n\n    void subupdate(int ul, int ur, ll x, int l, int r, int i){\n   \
    \     eval(i);\n        if(ul <= l && r <= ur){\n            laz[i] = composite(laz[i],\
    \ x);\n            eval(i);\n        }\n        else if(ul < r && l < ur){\n \
    \           int m = (l + r) / 2;\n            subupdate(ul, ur, x, l, m, i * 2);\n\
    \            subupdate(ul, ur, x, m, r, i * 2 + 1);\n        }\n    }\n\n    ll\
    \ subquery(int i, int l, int r, int c){\n        eval(c);\n        if(i == l &&\
    \ r - l == 1) return laz[c];\n        int m = (l + r) / 2;\n        if(i < m)\
    \ return subquery(i, l, m, c * 2);\n        else return subquery(i, m, r, c *\
    \ 2 + 1);\n    }\n\n    /**\n     * @note oe \u306F\u4F5C\u7528\u7D20\u306E\u5358\
    \u4F4D\u5143\u3002\u554F\u984C\u306B\u3088\u3063\u3066\u66F8\u304D\u63DB\u3048\
    \u308B\u3002\n     * @note \u3053\u308C\u306F Range Minimum Query \u306E\u5358\
    \u4F4D\u5143\n     */\n    segtree(vl &init) : oe((1LL << 31) - 1){\n        sz\
    \ = 1;\n        while(sz < init.size()) sz <<= 1;\n        ofs = sz - 1;\n   \
    \     laz.resize(sz * 2, oe);\n        for(int i = 0; i < init.size(); ++i) laz[sz\
    \ + i] = init[i];\n    }\n\n    void update(int l, int r, ll v){\n        subupdate(l,\
    \ r, v, 1, sz + 1, 1);\n    }\n\n    ll query(int i){\n        return subquery(i,\
    \ 1, sz + 1, 1);\n    }\n};"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/DualSegmentTree.hpp
  requiredBy: []
  timestamp: '2023-11-23 01:27:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-DSL-2-D.test.cpp
documentation_of: icpc/DualSegmentTree.hpp
layout: document
redirect_from:
- /library/icpc/DualSegmentTree.hpp
- /library/icpc/DualSegmentTree.hpp.html
title: "\u4F5C\u7528\u7D20\u306E\u5727\u7E2E\u90E8\u5206\u3002\u554F\u984C\u306B\u3088\
  \u3063\u3066\u66F8\u304D\u63DB\u3048\u308B\u3002"
---
