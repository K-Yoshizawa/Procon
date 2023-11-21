---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/Graph/Kruskal.hpp
    title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-1-A.test.cpp
    title: verify/AOJ-DSL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-1-B.test.cpp
    title: verify/AOJ-DSL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-2-A.test.cpp
    title: verify/AOJ-GRL-2-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-Unionfind.test.cpp
    title: verify/LC-Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
    links: []
  bundledCode: "#line 2 \"library/DataStructure/UnionFind.hpp\"\n\n/**\n * @file UnionFind.hpp\n\
    \ * @author log K (lX57)\n * @brief UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020\n * @version 2.0\n * @date 2023-11-12\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T = int>\nstruct UnionFind{\n    private:\n\
    \    vector<int> __Data;\n    vector<T> __Weight;\n\n    T __weight(int k){\n\
    \        find(k);\n        return __Weight[k];\n    }\n\n    public:\n    /**\n\
    \     * @brief \u8981\u7D20\u6570 `Size`, \u521D\u671F\u91CD\u307F `Init_Weight`\
    \ \u3067UnionFind\u3092\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Size\
    \ \u8981\u7D20\u6570\n     * @param Init_Weight \u91CD\u307F\u4ED8\u304DUnionFind\u306E\
    \u521D\u671F\u91CD\u307F (option, default = 0)\n     */\n    UnionFind(int Size,\
    \ T Init_Weight = 0) : __Data(Size, -1), __Weight(Size, Init_Weight) {}\n\n  \
    \  /**\n     * @brief \u8981\u7D20 `k` \u306E\u89AA\u3092\u8FD4\u3059\u3002\u3064\
    \u3044\u3067\u306B\u7D4C\u8DEF\u5727\u7E2E\u3092\u3059\u308B\u3002\n     * @param\
    \ k \u63A2\u7D22\u3059\u308B\u8981\u7D20\n     * @return int \u89AA\u8981\u7D20\
    \u306E\u756A\u53F7\n     */\n    int find(int k){\n        if(__Data[k] < 0) return\
    \ k;\n        int r = find(__Data[k]);\n        __Weight[k] += __Weight[__Data[k]];\n\
    \        return __Data[k] = r;\n    }\n\n    /**\n     * @brief \u8981\u7D20 `x`\
    \ \u3068\u8981\u7D20 `y` \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\
    \u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool same(int\
    \ x, int y){\n        return find(x) == find(y);\n    }\n\n    /**\n     * @brief\
    \ `Weight(y) - Weight(x)` \u3092\u8A08\u7B97\u3059\u308B\u3002\n     * @return\
    \ T `Weight(y) - Weight(x)` \u306E\u5024\n     */\n    T diff(int x, int y){\n\
    \        return __weight(y) - __weight(x);\n    }\n\n    /**\n     * @brief \u8981\
    \u7D20 `x` \u3068\u8981\u7D20 `y` \u3092\u4F75\u5408\u3059\u308B\u3002\u91CD\u307F\
    \u3092\u4ED8\u4E0E\u3059\u308B\u3053\u3068\u3082\u3067\u304D\u308B\u3002\n   \
    \  * @param w `Weight(y) - Weight(x) = w` \u3068\u3044\u3046\u5236\u7D04\u6761\
    \u4EF6 (option, default = 0)\n     * @return \u4F75\u5408\u6E08\u306E\u5834\u5408\
    \u306F `false` \u3092\u8FD4\u3059\u3002\n     */\n    bool unite(int x, int y,\
    \ T w = 0){\n        w += __weight(x) - __weight(y);\n        x = find(x), y =\
    \ find(y);\n        if(x == y) return false;\n        if(__Data[x] > __Data[y])\
    \ swap(x, y), w = -w;\n        __Data[x] += __Data[y];\n        __Data[y] = x;\n\
    \        __Weight[y] = w;\n        return true;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file UnionFind.hpp\n * @author log K (lX57)\n *\
    \ @brief UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\n * @version\
    \ 2.0\n * @date 2023-11-12\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate<typename T = int>\nstruct UnionFind{\n    private:\n    vector<int>\
    \ __Data;\n    vector<T> __Weight;\n\n    T __weight(int k){\n        find(k);\n\
    \        return __Weight[k];\n    }\n\n    public:\n    /**\n     * @brief \u8981\
    \u7D20\u6570 `Size`, \u521D\u671F\u91CD\u307F `Init_Weight` \u3067UnionFind\u3092\
    \u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Size \u8981\u7D20\u6570\n\
    \     * @param Init_Weight \u91CD\u307F\u4ED8\u304DUnionFind\u306E\u521D\u671F\
    \u91CD\u307F (option, default = 0)\n     */\n    UnionFind(int Size, T Init_Weight\
    \ = 0) : __Data(Size, -1), __Weight(Size, Init_Weight) {}\n\n    /**\n     * @brief\
    \ \u8981\u7D20 `k` \u306E\u89AA\u3092\u8FD4\u3059\u3002\u3064\u3044\u3067\u306B\
    \u7D4C\u8DEF\u5727\u7E2E\u3092\u3059\u308B\u3002\n     * @param k \u63A2\u7D22\
    \u3059\u308B\u8981\u7D20\n     * @return int \u89AA\u8981\u7D20\u306E\u756A\u53F7\
    \n     */\n    int find(int k){\n        if(__Data[k] < 0) return k;\n       \
    \ int r = find(__Data[k]);\n        __Weight[k] += __Weight[__Data[k]];\n    \
    \    return __Data[k] = r;\n    }\n\n    /**\n     * @brief \u8981\u7D20 `x` \u3068\
    \u8981\u7D20 `y` \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\
    \u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool same(int x, int\
    \ y){\n        return find(x) == find(y);\n    }\n\n    /**\n     * @brief `Weight(y)\
    \ - Weight(x)` \u3092\u8A08\u7B97\u3059\u308B\u3002\n     * @return T `Weight(y)\
    \ - Weight(x)` \u306E\u5024\n     */\n    T diff(int x, int y){\n        return\
    \ __weight(y) - __weight(x);\n    }\n\n    /**\n     * @brief \u8981\u7D20 `x`\
    \ \u3068\u8981\u7D20 `y` \u3092\u4F75\u5408\u3059\u308B\u3002\u91CD\u307F\u3092\
    \u4ED8\u4E0E\u3059\u308B\u3053\u3068\u3082\u3067\u304D\u308B\u3002\n     * @param\
    \ w `Weight(y) - Weight(x) = w` \u3068\u3044\u3046\u5236\u7D04\u6761\u4EF6 (option,\
    \ default = 0)\n     * @return \u4F75\u5408\u6E08\u306E\u5834\u5408\u306F `false`\
    \ \u3092\u8FD4\u3059\u3002\n     */\n    bool unite(int x, int y, T w = 0){\n\
    \        w += __weight(x) - __weight(y);\n        x = find(x), y = find(y);\n\
    \        if(x == y) return false;\n        if(__Data[x] > __Data[y]) swap(x, y),\
    \ w = -w;\n        __Data[x] += __Data[y];\n        __Data[y] = x;\n        __Weight[y]\
    \ = w;\n        return true;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/UnionFind.hpp
  requiredBy:
  - library/Graph/Kruskal.hpp
  timestamp: '2023-11-12 02:50:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-2-A.test.cpp
  - verify/LC-Unionfind.test.cpp
  - verify/AOJ-DSL-1-A.test.cpp
  - verify/AOJ-DSL-1-B.test.cpp
documentation_of: library/DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/library/DataStructure/UnionFind.hpp
- /library/library/DataStructure/UnionFind.hpp.html
title: "UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
---
