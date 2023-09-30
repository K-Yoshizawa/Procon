---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/Graph/Kruskal.hpp
    title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ/AOJ-DSL-1-A.test.cpp
    title: verify/AOJ/AOJ-DSL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ/AOJ-GRL-2-A.test.cpp
    title: verify/AOJ/AOJ-GRL-2-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC/LC-Unionfind.test.cpp
    title: verify/LC/LC-Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
    links: []
  bundledCode: "#line 2 \"library/DataStructure/UnionFind.hpp\"\n\n/**\n * @brief\
    \ UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n/**\n * @brief Union-Find\n */\nstruct\
    \ UnionFind{\n    vector<int> data;\n \n    UnionFind(size_t sz) : data(sz, -1)\
    \ {}\n \n    /**\n     * @brief \u8981\u7D20x\u3068\u8981\u7D20y\u3092\u4F75\u5408\
    \u3059\u308B\n     * @param x \u4F75\u5408\u3059\u308B\u8981\u7D20x\n     * @param\
    \ y \u4F75\u5408\u3059\u308B\u8981\u7D20y\n     * @return true \u8981\u7D20x\u3068\
    \u8981\u7D20y\u304C\u307E\u3060\u672A\u4F75\u5408\u3060\u3063\u305F\u5834\u5408\
    \n     * @return false \u8981\u7D20x\u3068\u8981\u7D20y\u304C\u4F75\u5408\u6E08\
    \u3060\u3063\u305F\u5834\u5408\n     */\n    bool unite(int x, int y){\n     \
    \   x = find(x), y = find(y);\n        if(x == y) return false;\n        if(data[x]\
    \ > data[y]) swap(x, y);\n        data[x] += data[y];\n        data[y] = x;\n\
    \        return true;\n    }\n \n    /**\n     * @brief \u8981\u7D20k\u304C\u542B\
    \u307E\u308C\u308B\u96C6\u5408\u306E\u8981\u7D20\u3092\u8ABF\u3079\u308B\u3002\
    \n     * @param k \u8ABF\u3079\u305F\u3044\u8981\u7D20k\n     * @return int \u542B\
    \u307E\u308C\u308B\u96C6\u5408\u306E\u89AA\n     */\n    int find(int k){\n  \
    \      if(data[k] < 0) return (k);\n        return data[k] = find(data[k]);\n\
    \    }\n \n    /**\n     * @brief \u8981\u7D20k\u304C\u542B\u307E\u308C\u308B\u96C6\
    \u5408\u306E\u8981\u7D20\u6570\u3092\u6C42\u3081\u308B\u3002\n     * @param k\
    \ \u8ABF\u3079\u305F\u3044\u8981\u7D20k\n     * @return int \u96C6\u5408\u306E\
    \u8981\u7D20\u6570\n     */\n    int size(int k){\n        return -data[find(k)];\n\
    \    }\n \n    /**\n     * @brief \u8981\u7D20x\u3001\u8981\u7D20y\u304C\u540C\
    \u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\u3002\
    \n     * @param x \u5224\u5B9A\u3059\u308B\u8981\u7D20x\n     * @param y \u5224\
    \u5B9A\u3059\u308B\u8981\u7D20y\n     * @return true \u540C\u3058\u96C6\u5408\u306B\
    \u5C5E\u3057\u3066\u3044\u308B\u5834\u5408\n     * @return false \u540C\u3058\u96C6\
    \u5408\u306B\u5C5E\u3057\u3066\u3044\u306A\u3044\u5834\u5408\n     */\n    bool\
    \ same(int x, int y){\n        return find(x) == find(y);\n    }\n\n    /**\n\
    \     * @brief  \u3059\u3079\u3066\u306E\u9023\u7D50\u6210\u5206\u3092\u53D6\u5F97\
    \u3059\u308B\u3002\n     * @retval vector<vector<int>> \n     */\n    vector<vector<int>>\
    \ groups() {\n        int n = (int) data.size();\n        vector<vector<int>>\
    \ ret(n);\n        for(int i = 0; i < n; i++) {\n            ret[find(i)].emplace_back(i);\n\
    \        }\n        ret.erase(remove_if(begin(ret), end(ret), [&](const vector<\
    \ int > &v) {\n            return v.empty();\n        }), end(ret));\n       \
    \ return ret;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    /**\n * @brief Union-Find\n */\nstruct UnionFind{\n    vector<int> data;\n \n\
    \    UnionFind(size_t sz) : data(sz, -1) {}\n \n    /**\n     * @brief \u8981\u7D20\
    x\u3068\u8981\u7D20y\u3092\u4F75\u5408\u3059\u308B\n     * @param x \u4F75\u5408\
    \u3059\u308B\u8981\u7D20x\n     * @param y \u4F75\u5408\u3059\u308B\u8981\u7D20\
    y\n     * @return true \u8981\u7D20x\u3068\u8981\u7D20y\u304C\u307E\u3060\u672A\
    \u4F75\u5408\u3060\u3063\u305F\u5834\u5408\n     * @return false \u8981\u7D20\
    x\u3068\u8981\u7D20y\u304C\u4F75\u5408\u6E08\u3060\u3063\u305F\u5834\u5408\n \
    \    */\n    bool unite(int x, int y){\n        x = find(x), y = find(y);\n  \
    \      if(x == y) return false;\n        if(data[x] > data[y]) swap(x, y);\n \
    \       data[x] += data[y];\n        data[y] = x;\n        return true;\n    }\n\
    \ \n    /**\n     * @brief \u8981\u7D20k\u304C\u542B\u307E\u308C\u308B\u96C6\u5408\
    \u306E\u8981\u7D20\u3092\u8ABF\u3079\u308B\u3002\n     * @param k \u8ABF\u3079\
    \u305F\u3044\u8981\u7D20k\n     * @return int \u542B\u307E\u308C\u308B\u96C6\u5408\
    \u306E\u89AA\n     */\n    int find(int k){\n        if(data[k] < 0) return (k);\n\
    \        return data[k] = find(data[k]);\n    }\n \n    /**\n     * @brief \u8981\
    \u7D20k\u304C\u542B\u307E\u308C\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\
    \u6C42\u3081\u308B\u3002\n     * @param k \u8ABF\u3079\u305F\u3044\u8981\u7D20\
    k\n     * @return int \u96C6\u5408\u306E\u8981\u7D20\u6570\n     */\n    int size(int\
    \ k){\n        return -data[find(k)];\n    }\n \n    /**\n     * @brief \u8981\
    \u7D20x\u3001\u8981\u7D20y\u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\
    \u304B\u5224\u5B9A\u3059\u308B\u3002\n     * @param x \u5224\u5B9A\u3059\u308B\
    \u8981\u7D20x\n     * @param y \u5224\u5B9A\u3059\u308B\u8981\u7D20y\n     * @return\
    \ true \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\u5834\u5408\
    \n     * @return false \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u306A\
    \u3044\u5834\u5408\n     */\n    bool same(int x, int y){\n        return find(x)\
    \ == find(y);\n    }\n\n    /**\n     * @brief  \u3059\u3079\u3066\u306E\u9023\
    \u7D50\u6210\u5206\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @retval vector<vector<int>>\
    \ \n     */\n    vector<vector<int>> groups() {\n        int n = (int) data.size();\n\
    \        vector<vector<int>> ret(n);\n        for(int i = 0; i < n; i++) {\n \
    \           ret[find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](const vector< int > &v) {\n            return v.empty();\n   \
    \     }), end(ret));\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/UnionFind.hpp
  requiredBy:
  - library/Graph/Kruskal.hpp
  timestamp: '2023-06-09 17:48:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ/AOJ-DSL-1-A.test.cpp
  - verify/AOJ/AOJ-GRL-2-A.test.cpp
  - verify/LC/LC-Unionfind.test.cpp
documentation_of: library/DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/library/DataStructure/UnionFind.hpp
- /library/library/DataStructure/UnionFind.hpp.html
title: "UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
---
