---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Cumulative Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/DataStructure/CumulativeSum2D.hpp: line 9: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @file CumulativeSum2D.hpp\n * @author log K (lX57)\n * @brief Cumulative\
    \ Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\n * @version 1.1\n * @date 2023-08-24\n\
    \ */\n\n#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n/**\n\
    \ * @attention \u914D\u5217\u306F\u5916\u5074\u306B1\u8981\u7D20\u5927\u304D\u304F\
    \u3068\u3063\u3066\u5B9F\u88C5\u3057\u3066\u3044\u308B\u3053\u3068\u306B\u6CE8\
    \u610F\u3059\u308B\u3053\u3068 \n */\ntemplate<typename T>\nstruct CumulativeSum2D{\n\
    \    private:\n    int Y, X;\n    vector<vector<T>> cum;\n\n    public:\n    /**\n\
    \     * @brief  \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\u306E\u521D\u671F\u5316\n\
    \     * @param  Y_size \u7E26\u306E\u30B5\u30A4\u30BA\n     * @param  X_size \u6A2A\
    \u306E\u30B5\u30A4\u30BA\n     * @param  init \u521D\u671F\u5024\n     */\n  \
    \  CumulativeSum2D(int Y_size, int X_size, T init = 0) : Y(Y_size), X(X_size){\n\
    \        cum.resize(Y + 2, vector<T>(X + 2, init));\n        for(int i = 0; i\
    \ <= Y; ++i) cum[i][0] = cum[i][X + 1] = 0;\n        for(int j = 0; j <= X; ++j)\
    \ cum[0][j] = cum[Y + 1][j] = 0;\n    }\n\n    /**\n     * @brief  (y, x)\u8981\
    \u7D20\u306Bvalue\u3092\u30BB\u30C3\u30C8\u3059\u308B\u3002\n     * @attention\
    \ build\u524D\u306B\u547C\u3073\u51FA\u3059\u3053\u3068\n     * @param  x \u8981\
    \u7D20\u306E\u6DFB\u5B57 (0-index)\n     * @param  y \u8981\u7D20\u306E\u6DFB\u5B57\
    \ (0-index)\n     * @param  value \u30BB\u30C3\u30C8\u3059\u308B\u5024\n     */\n\
    \    void set(int x, int y, T value){\n        assert(0 <= x && x < X && 0 <=\
    \ y && y < Y);\n        cum[y + 1][x + 1] = value;\n    }\n\n    /**\n     * @brief\
    \ (sy, sx)\u3092\u5DE6\u4E0A\u3001(ty, tx)\u3092\u53F3\u4E0B\u3068\u3059\u308B\
    \u9577\u65B9\u5F62\u9818\u57DF\u306B\u5BFE\u3057\u3066value\u3092\u52A0\u7B97\u3059\
    \u308B\u3002\n     * @note (sy, sx)\u3068(ty, tx)\u306F\u305D\u308C\u305E\u308C\
    \u9577\u65B9\u5F62\u306E\u9685\uFF08\u534A\u958B\u533A\u9593\uFF09\n     * @param\
    \ sx \u5DE6\u4E0A\u30DE\u30B9\u306Ex\u5EA7\u6A19 (0-index)\n     * @param sy \u5DE6\
    \u4E0A\u30DE\u30B9\u306Ey\u5EA7\u6A19 (0-index)\n     * @param tx \u53F3\u4E0B\
    \u30DE\u30B9\u306Ex\u5EA7\u6A19 (0-index)\n     * @param ty \u53F3\u4E0B\u30DE\
    \u30B9\u306Ey\u5EA7\u6A19 (0-index)\n     * @param value \u52A0\u7B97\u3059\u308B\
    \u5024\n     */\n    void add(int sx, int sy, int tx, int ty, T value){\n    \
    \    assert(0 <= sx && sx < X && 0 <= sy && sy < Y);\n        assert(0 <= tx &&\
    \ tx < X && 0 <= ty && ty < Y);\n        ++sx, ++sy, ++tx, ++ty;\n        cum[sy][sx]\
    \ += value;\n        cum[sy][tx] -= value;\n        cum[ty][sx] -= value;\n  \
    \      cum[ty][tx] += value;\n    }\n\n    /**\n     * @brief \u7D2F\u7A4D\u548C\
    \u914D\u5217\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention set\u3067\u521D\
    \u671F\u5024\u306E\u5165\u529B\u3092\u6E08\u307E\u305B\u3066\u304A\u304F\u3053\
    \u3068\n     */\n    void build(){\n        for(int i = 1; i <= Y; ++i){\n   \
    \         for(int j = 1; j <= X; ++j){\n                cum[i][j] += cum[i][j\
    \ - 1];\n            }\n        }\n        for(int j = 1; j <= X; ++j){\n    \
    \        for(int i = 1; i <= Y; ++i){\n                cum[i][j] += cum[i - 1][j];\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief (sy, sx)\u3092\u5DE6\
    \u4E0A\u3001(ty, tx)\u3092\u53F3\u4E0B\u3068\u3059\u308B\u9577\u65B9\u5F62\u9818\
    \u57DF\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\u89E3\u304F\u3002\n   \
    \  * @note (sy, sx)\u3068(ty, tx)\u306F\u305D\u308C\u305E\u308C\u9577\u65B9\u5F62\
    \u306E\u9685\uFF08\u534A\u958B\u533A\u9593\uFF09\n     * @param sx \u5DE6\u4E0A\
    \u30DE\u30B9\u306Ex\u5EA7\u6A19 (0-index)\n     * @param sy \u5DE6\u4E0A\u30DE\
    \u30B9\u306Ey\u5EA7\u6A19 (0-index)\n     * @param tx \u53F3\u4E0B\u30DE\u30B9\
    \u306Ex\u5EA7\u6A19 (0-index)\n     * @param ty \u53F3\u4E0B\u30DE\u30B9\u306E\
    y\u5EA7\u6A19 (0-index)\n     * @return T \u30AF\u30A8\u30EA\u306E\u7D50\u679C\
    \n     */\n    T query(int sx, int sy, int tx, int ty){\n        assert(0 <= sx\
    \ && sx < X && 0 <= sy && sy < Y);\n        assert(0 <= tx && tx < X && 0 <= ty\
    \ && ty < Y);\n        ++sx, ++sy, ++tx, ++ty;\n        return cum[ty][tx] - cum[ty][sx\
    \ - 1] - cum[sy - 1][tx] + cum[sy - 1][sx - 1];\n    }\n\n    /**\n     * @brief\
    \ \u7D2F\u7A4D\u548C\u914D\u5217\u5168\u4F53\u306E\u6700\u5927\u5024\u3092\u6C42\
    \u3081\u308B\u3002\n     * @return T \u6700\u5927\u5024\n     */\n    T max(){\n\
    \        T ret = numeric_limits<T>::min() / 2;\n        for(int i = 1; i <= Y;\
    \ ++i){\n            for(int j = 1; j <= X; ++j){\n                ret = std::max(ret,\
    \ cum[i][j]);\n            }\n        }\n        return ret;\n    }\n    \n  \
    \  /**\n     * @brief \u7D2F\u7A4D\u548C\u914D\u5217\u5168\u4F53\u306E\u6700\u5C0F\
    \u5024\u3092\u6C42\u3081\u308B\u3002\n     * @return T \u6700\u5C0F\u5024\n  \
    \   */\n    T min(){\n        T ret = numeric_limits<T>::max() / 2;\n        for(int\
    \ i = 1; i <= Y; ++i){\n            for(int j = 1; j <= X; ++j){\n           \
    \     ret = std::min(ret, cum[i][j]);\n            }\n        }\n        return\
    \ ret;\n    }\n\n    bool test(int y, int x, function<bool(T)> func){\n      \
    \  ++y, ++x;\n        return func(cum[y][x]);\n    }\n\n    /**\n     * @brief\
    \ \u6E21\u3057\u305F\u95A2\u6570\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u8981\
    \u7D20\u306E\u6570\u3092\u6570\u3048\u308B\n     * @param func \u6761\u4EF6\u5224\
    \u5B9A\u306E\u95A2\u6570\n     * @return int \u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u8981\u7D20\u306E\u6570\n     */\n    int count_if(function<bool(T)> func){\n\
    \        int ret = 0;\n        for(int i = 1; i <= Y; ++i){\n            for(int\
    \ j = 1; j <= X; ++j){\n                if(func(cum[i][j])) ++ret;\n         \
    \   }\n        }\n        return ret;\n    }\n\n    void print(bool edge = false){\n\
    \        for(int i = !edge; i <= Y + edge; ++i){\n            for(int j = !edge;\
    \ j <= X + edge; ++j){\n                cerr << cum[i][j] << \" \";\n        \
    \    }\n            cerr << endl;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/CumulativeSum2D.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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
