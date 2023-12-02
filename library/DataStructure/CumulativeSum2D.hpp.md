---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-5-B.test.cpp
    title: verify/AOJ-DSL-5-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Cumulative Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 1 \"library/DataStructure/CumulativeSum2D.hpp\"\n/**\n * @file\
    \ CumulativeSum2D.hpp\n * @author log K (lX57)\n * @brief Cumulative Sum 2D -\
    \ \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\n * @version 2.0\n * @date 2023-12-03\n\
    \ */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>\n\
    class CumulativeSum2D{\n    int __Y, __X;\n    vector<vector<T>> __Data;\n\n \
    \   public:\n    /**\n     * @brief \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\u3092\
    \ `Init` \u3067\u521D\u671F\u5316\u3059\u308B\n     * @attention \u3053\u306E\u6642\
    \u70B9\u3067\u306F\u69CB\u7BC9\u3055\u308C\u3066\u3044\u306A\u3044\u306E\u3067\
    \u6CE8\u610F\n     * @param Init \u521D\u671F\u914D\u5217\n     */\n    CumulativeSum2D(vector<vector<T>>\
    \ &Init){\n        __Y = Init.size(), __X = Init[0].size();\n        __Data.resize(__Y,\
    \ vector<T>(__X));\n        for(int i = 0; i < __Y; ++i){\n            for(int\
    \ j = 0; j < __X; ++j){\n                __Data[i][j] = Init[i][j];\n        \
    \    }\n        }\n    }\n\n    /**\n     * @brief \u4E8C\u6B21\u5143\u7D2F\u7A4D\
    \u548C\u3092\u69CB\u7BC9\u3059\u308B\n     */\n    void build(){\n        for(int\
    \ i = 0; i < __Y; ++i){\n            for(int j = 1; j < __X; ++j){\n         \
    \       __Data[i][j] += __Data[i][j - 1];\n            }\n        }\n        for(int\
    \ i = 1; i < __Y; ++i){\n            for(int j = 0; j < __X; ++j){\n         \
    \       __Data[i][j] += __Data[i - 1][j];\n            }\n        }\n    }\n\n\
    \    /**\n     * @brief `(y, x)` \u306B\u5024 `value` \u3092\u52A0\u7B97\u3059\
    \u308B\n     * @attention `y, x` \u306F0-index\n     */\n    void add(int y, int\
    \ x, T value){\n        __Data[y][x] += value;\n    }\n\n    /**\n     * @brief\
    \ `(y1, x1)` \u3092\u5DE6\u4E0A\u3001 `(y2, x2)` \u3092\u53F3\u4E0B\u3068\u3059\
    \u308B\u9577\u65B9\u5F62\u9818\u57DF\u306B\u5024 `value` \u3092\u52A0\u7B97\u3059\
    \u308B\n     * @attention `y1, x1, y2, x2` \u306F0-index\u3067\u3001\u9818\u57DF\
    \u306F `[y1, y2] and [x1, x2]` \u3092\u6307\u3059\n     */\n    void add(int y1,\
    \ int x1, int y2, int x2, T value){\n        __Data[y1][x1] += value;\n      \
    \  if(y2 + 1 < __Y) __Data[y2 + 1][x1] -= value;\n        if(x2 + 1 < __X) __Data[y1][x2\
    \ + 1] -= value;\n        if(y2 + 1 < __Y and x2 + 1 < __X) __Data[y2 + 1][x2\
    \ + 1] += value;\n    }\n\n    /**\n     * @brief `(0, 0)` \u3092\u5DE6\u4E0A\u3001\
    \ `(y, x)` \u3092\u53F3\u4E0B\u3068\u3059\u308B\u9577\u65B9\u5F62\u9818\u57DF\u306E\
    \u7D2F\u7A4D\u5024\u3092\u6C42\u3081\u308B\n     * @attention `y, x` \u306F0-index\u3067\
    \u3001\u9818\u57DF\u306F `[0, y] and [0, x]` \u3092\u6307\u3059\n     */\n   \
    \ T query(int y, int x){\n        return __Data[y][x];\n    }\n\n    /**\n   \
    \  * @brief `(y1, x1)` \u3092\u5DE6\u4E0A\u3001 `(y2, x2)` \u3092\u53F3\u4E0B\u3068\
    \u3059\u308B\u9577\u65B9\u5F62\u9818\u57DF\u306E\u7D2F\u7A4D\u5024\u3092\u6C42\
    \u3081\u308B\n     * @attention `y1, x1, y2, x2` \u306F0-index\u3067\u3001\u9818\
    \u57DF\u306F `[y1, y2] and [x1, x2]` \u3092\u6307\u3059\n     */\n    T query(int\
    \ y1, int x1, int y2, int x2){\n        T ret = __Data[y2][x2];\n        if(y1\
    \ > 0) ret -= __Data[y1 - 1][x2];\n        if(x1 > 0) ret -= __Data[y2][x1 - 1];\n\
    \        if(y1 > 0 and x1 > 0) ret += __Data[y1 - 1][x1 - 1];\n        return\
    \ ret;\n    }\n\n    /**\n     * @brief \u9818\u57DF\u5168\u4F53\u306B\u6BD4\u8F03\
    \u95A2\u6570\u3092\u9069\u7528\u3055\u305B\u3001\u305D\u306E\u7D50\u679C\u3092\
    \u5F97\u308B\n     * @param compare \u6BD4\u8F03\u95A2\u6570 : \u5F15\u6570\u306F\
    \ `src, cmp` \u3067\u623B\u308A\u5024\u306F `T`\n     */\n    T search(function<T(T,\
    \ T)> compare){\n        T ret = __Data[0][0];\n        for(int i = 0; i < __Y;\
    \ ++i){\n            for(int j = 0; j < __X; ++j){\n                ret = compare(ret,\
    \ __Data[i][j]);\n            }\n        }\n        return ret;\n    }\n\n   \
    \ /**\n     * @brief \u9818\u57DF\u5168\u4F53\u306E\u6761\u4EF6\u3092\u6E80\u305F\
    \u3059\u30DE\u30B9\u306E\u6570\u3092\u6570\u3048\u308B\n     * @param condition\
    \ \u95A2\u6570 : \u5F15\u6570\u306F `T` \u3067\u623B\u308A\u5024\u306F `bool`\n\
    \     */\n    int count(function<bool(T)> condition){\n        int ret = 0;\n\
    \        for(int i = 0; i < __Y; ++i){\n            for(int j = 0; j < __X; ++j){\n\
    \                ret += condition(__Data[i][j]);\n            }\n        }\n \
    \       return ret;\n    }\n};\n"
  code: "/**\n * @file CumulativeSum2D.hpp\n * @author log K (lX57)\n * @brief Cumulative\
    \ Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\n * @version 2.0\n * @date 2023-12-03\n\
    \ */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>\n\
    class CumulativeSum2D{\n    int __Y, __X;\n    vector<vector<T>> __Data;\n\n \
    \   public:\n    /**\n     * @brief \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\u3092\
    \ `Init` \u3067\u521D\u671F\u5316\u3059\u308B\n     * @attention \u3053\u306E\u6642\
    \u70B9\u3067\u306F\u69CB\u7BC9\u3055\u308C\u3066\u3044\u306A\u3044\u306E\u3067\
    \u6CE8\u610F\n     * @param Init \u521D\u671F\u914D\u5217\n     */\n    CumulativeSum2D(vector<vector<T>>\
    \ &Init){\n        __Y = Init.size(), __X = Init[0].size();\n        __Data.resize(__Y,\
    \ vector<T>(__X));\n        for(int i = 0; i < __Y; ++i){\n            for(int\
    \ j = 0; j < __X; ++j){\n                __Data[i][j] = Init[i][j];\n        \
    \    }\n        }\n    }\n\n    /**\n     * @brief \u4E8C\u6B21\u5143\u7D2F\u7A4D\
    \u548C\u3092\u69CB\u7BC9\u3059\u308B\n     */\n    void build(){\n        for(int\
    \ i = 0; i < __Y; ++i){\n            for(int j = 1; j < __X; ++j){\n         \
    \       __Data[i][j] += __Data[i][j - 1];\n            }\n        }\n        for(int\
    \ i = 1; i < __Y; ++i){\n            for(int j = 0; j < __X; ++j){\n         \
    \       __Data[i][j] += __Data[i - 1][j];\n            }\n        }\n    }\n\n\
    \    /**\n     * @brief `(y, x)` \u306B\u5024 `value` \u3092\u52A0\u7B97\u3059\
    \u308B\n     * @attention `y, x` \u306F0-index\n     */\n    void add(int y, int\
    \ x, T value){\n        __Data[y][x] += value;\n    }\n\n    /**\n     * @brief\
    \ `(y1, x1)` \u3092\u5DE6\u4E0A\u3001 `(y2, x2)` \u3092\u53F3\u4E0B\u3068\u3059\
    \u308B\u9577\u65B9\u5F62\u9818\u57DF\u306B\u5024 `value` \u3092\u52A0\u7B97\u3059\
    \u308B\n     * @attention `y1, x1, y2, x2` \u306F0-index\u3067\u3001\u9818\u57DF\
    \u306F `[y1, y2] and [x1, x2]` \u3092\u6307\u3059\n     */\n    void add(int y1,\
    \ int x1, int y2, int x2, T value){\n        __Data[y1][x1] += value;\n      \
    \  if(y2 + 1 < __Y) __Data[y2 + 1][x1] -= value;\n        if(x2 + 1 < __X) __Data[y1][x2\
    \ + 1] -= value;\n        if(y2 + 1 < __Y and x2 + 1 < __X) __Data[y2 + 1][x2\
    \ + 1] += value;\n    }\n\n    /**\n     * @brief `(0, 0)` \u3092\u5DE6\u4E0A\u3001\
    \ `(y, x)` \u3092\u53F3\u4E0B\u3068\u3059\u308B\u9577\u65B9\u5F62\u9818\u57DF\u306E\
    \u7D2F\u7A4D\u5024\u3092\u6C42\u3081\u308B\n     * @attention `y, x` \u306F0-index\u3067\
    \u3001\u9818\u57DF\u306F `[0, y] and [0, x]` \u3092\u6307\u3059\n     */\n   \
    \ T query(int y, int x){\n        return __Data[y][x];\n    }\n\n    /**\n   \
    \  * @brief `(y1, x1)` \u3092\u5DE6\u4E0A\u3001 `(y2, x2)` \u3092\u53F3\u4E0B\u3068\
    \u3059\u308B\u9577\u65B9\u5F62\u9818\u57DF\u306E\u7D2F\u7A4D\u5024\u3092\u6C42\
    \u3081\u308B\n     * @attention `y1, x1, y2, x2` \u306F0-index\u3067\u3001\u9818\
    \u57DF\u306F `[y1, y2] and [x1, x2]` \u3092\u6307\u3059\n     */\n    T query(int\
    \ y1, int x1, int y2, int x2){\n        T ret = __Data[y2][x2];\n        if(y1\
    \ > 0) ret -= __Data[y1 - 1][x2];\n        if(x1 > 0) ret -= __Data[y2][x1 - 1];\n\
    \        if(y1 > 0 and x1 > 0) ret += __Data[y1 - 1][x1 - 1];\n        return\
    \ ret;\n    }\n\n    /**\n     * @brief \u9818\u57DF\u5168\u4F53\u306B\u6BD4\u8F03\
    \u95A2\u6570\u3092\u9069\u7528\u3055\u305B\u3001\u305D\u306E\u7D50\u679C\u3092\
    \u5F97\u308B\n     * @param compare \u6BD4\u8F03\u95A2\u6570 : \u5F15\u6570\u306F\
    \ `src, cmp` \u3067\u623B\u308A\u5024\u306F `T`\n     */\n    T search(function<T(T,\
    \ T)> compare){\n        T ret = __Data[0][0];\n        for(int i = 0; i < __Y;\
    \ ++i){\n            for(int j = 0; j < __X; ++j){\n                ret = compare(ret,\
    \ __Data[i][j]);\n            }\n        }\n        return ret;\n    }\n\n   \
    \ /**\n     * @brief \u9818\u57DF\u5168\u4F53\u306E\u6761\u4EF6\u3092\u6E80\u305F\
    \u3059\u30DE\u30B9\u306E\u6570\u3092\u6570\u3048\u308B\n     * @param condition\
    \ \u95A2\u6570 : \u5F15\u6570\u306F `T` \u3067\u623B\u308A\u5024\u306F `bool`\n\
    \     */\n    int count(function<bool(T)> condition){\n        int ret = 0;\n\
    \        for(int i = 0; i < __Y; ++i){\n            for(int j = 0; j < __X; ++j){\n\
    \                ret += condition(__Data[i][j]);\n            }\n        }\n \
    \       return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/CumulativeSum2D.hpp
  requiredBy: []
  timestamp: '2023-12-03 07:05:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DSL-5-B.test.cpp
documentation_of: library/DataStructure/CumulativeSum2D.hpp
layout: document
title: "Cumulative Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
---

## Abstract

長方形領域に対する累積和を処理するライブラリ。
構築時に元サイズの外側に1マス拡大する。

## Function

- set : 単一要素に値を代入する。
- add : 長方形領域に値を加算する。
- build : 累積和配列を構築する。
- query : 長方形領域の累積和を取得する。
- max / min : 累積和配列全体の最大値 / 最小値を取得する。
