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
    \ \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\n * @date 2023-07-24\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct CumulativeSum2D{\n    private:\n\
    \    int Y, X;\n    vector<vector<T>> cum;\n\n    public:\n    /**\n     * @brief\
    \  \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\u306E\u521D\u671F\u5316\n     * @param\
    \  Y_size \u7E26\u306E\u30B5\u30A4\u30BA\n     * @param  X_size \u6A2A\u306E\u30B5\
    \u30A4\u30BA\n     * @param  init \u521D\u671F\u5024\n     */\n    CumulativeSum2D(int\
    \ Y_size, int X_size, T init = 0) : Y(Y_size), X(X_size){\n        cum.resize(Y\
    \ + 2, vector<T>(X + 2, init));\n        for(int i = 0; i <= Y; ++i) cum[i][0]\
    \ = cum[i][X + 1] = 0;\n        for(int j = 0; j <= X; ++j) cum[0][j] = cum[Y\
    \ + 1][j] = 0;\n    }\n\n    /**\n     * @brief  (y, x)\u8981\u7D20\u306Bvalue\u3092\
    \u30BB\u30C3\u30C8\u3059\u308B\u3002\n     * @attention build\u524D\u306B\u547C\
    \u3073\u51FA\u3059\u3053\u3068\n     * @param  x \u8981\u7D20\u306E\u6DFB\u5B57\
    \ (0-index)\n     * @param  y \u8981\u7D20\u306E\u6DFB\u5B57 (0-index)\n     *\
    \ @param  value \u30BB\u30C3\u30C8\u3059\u308B\u5024\n     */\n    void set(int\
    \ x, int y, T value){\n        assert(0 <= x && x < X && 0 <= y && y < Y);\n \
    \       cum[y + 1][x + 1] = value;\n    }\n\n    /**\n     * @brief (sy, sx)\u3092\
    \u5DE6\u4E0A\u3001(ty, tx)\u3092\u53F3\u4E0B\u3068\u3059\u308B\u9577\u65B9\u5F62\
    \u9818\u57DF\u306B\u5BFE\u3057\u3066value\u3092\u52A0\u7B97\u3059\u308B\u3002\n\
    \     * @note (sy, sx)\u3068(ty, tx)\u306F\u305D\u308C\u305E\u308C\u9577\u65B9\
    \u5F62\"\u5185\u90E8\"\u306E\u9685\uFF08\u9589\u533A\u9593\uFF09\n     * @param\
    \ sx \u5DE6\u4E0A\u30DE\u30B9\u306Ex\u5EA7\u6A19 (0-index)\n     * @param sy \u5DE6\
    \u4E0A\u30DE\u30B9\u306Ey\u5EA7\u6A19 (0-index)\n     * @param tx \u53F3\u4E0B\
    \u30DE\u30B9\u306Ex\u5EA7\u6A19 (0-index)\n     * @param ty \u53F3\u4E0B\u30DE\
    \u30B9\u306Ey\u5EA7\u6A19 (0-index)\n     * @param value \u52A0\u7B97\u3059\u308B\
    \u5024\n     */\n    void add(int sx, int sy, int tx, int ty, T value){\n    \
    \    assert(0 <= sx && sx < X && 0 <= sy && sy < Y);\n        assert(0 <= tx &&\
    \ tx < X && 0 <= ty && ty < Y);\n        cum[sy + 1][sx + 1] += value;\n     \
    \   cum[sy + 1][tx + 2] -= value;\n        cum[ty + 2][sx + 1] -= value;\n   \
    \     cum[ty + 2][tx + 2] += value;\n    }\n\n    /**\n     * @brief \u7D2F\u7A4D\
    \u548C\u914D\u5217\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention set\u3067\
    \u521D\u671F\u5024\u306E\u5165\u529B\u3092\u6E08\u307E\u305B\u3066\u304A\u304F\
    \u3053\u3068\n     */\n    void build(){\n        for(int i = 1; i <= Y; ++i){\n\
    \            for(int j = 1; j <= X; ++j){\n                cum[i][j] += cum[i][j\
    \ - 1];\n            }\n        }\n        for(int j = 1; j <= X; ++j){\n    \
    \        for(int i = 1; i <= Y; ++i){\n                cum[i][j] += cum[i - 1][j];\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief (sy, sx)\u3092\u5DE6\
    \u4E0A\u3001(ty, tx)\u3092\u53F3\u4E0B\u3068\u3059\u308B\u9577\u65B9\u5F62\u9818\
    \u57DF\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\u89E3\u304F\u3002\n   \
    \  * @note (sy, sx)\u3068(ty, tx)\u306F\u305D\u308C\u305E\u308C\u9577\u65B9\u5F62\
    \"\u5185\u90E8\"\u306E\u9685\uFF08\u9589\u533A\u9593\uFF09\n     * @param sx \u5DE6\
    \u4E0A\u30DE\u30B9\u306Ex\u5EA7\u6A19 (0-index)\n     * @param sy \u5DE6\u4E0A\
    \u30DE\u30B9\u306Ey\u5EA7\u6A19 (0-index)\n     * @param tx \u53F3\u4E0B\u30DE\
    \u30B9\u306Ex\u5EA7\u6A19 (0-index)\n     * @param ty \u53F3\u4E0B\u30DE\u30B9\
    \u306Ey\u5EA7\u6A19 (0-index)\n     * @return T \u30AF\u30A8\u30EA\u306E\u7D50\
    \u679C\n     */\n    T query(int sx, int sy, int tx, int ty){\n        assert(0\
    \ <= sx && sx < X && 0 <= sy && sy < Y);\n        assert(0 <= tx && tx < X &&\
    \ 0 <= ty && ty < Y);\n        return cum[ty + 1][tx + 1] - cum[ty + 1][sx] -\
    \ cum[sy][tx + 1] + cum[sy][sx];\n    }\n\n    /**\n     * @brief \u7D2F\u7A4D\
    \u548C\u914D\u5217\u5168\u4F53\u306E\u6700\u5927\u5024\u3092\u6C42\u3081\u308B\
    \u3002\n     * @return T \u6700\u5927\u5024\n     */\n    T max(){\n        T\
    \ ret = numeric_limits<T>::min();\n        for(int i = 1; i <= Y; ++i){\n    \
    \        for(int j = 1; j <= X; ++j){\n                ret = std::max(ret, cum[i][j]);\n\
    \            }\n        }\n        return ret;\n    }\n    \n    /**\n     * @brief\
    \ \u7D2F\u7A4D\u548C\u914D\u5217\u5168\u4F53\u306E\u6700\u5C0F\u5024\u3092\u6C42\
    \u3081\u308B\u3002\n     * @return T \u6700\u5C0F\u5024\n     */\n    T min(){\n\
    \        T ret = numeric_limits<T>::max();\n        for(int i = 1; i <= Y; ++i){\n\
    \            for(int j = 1; j <= X; ++j){\n                ret = std::min(ret,\
    \ cum[i][j]);\n            }\n        }\n        return ret;\n    }\n};\n"
  code: "/**\n * @file CumulativeSum2D.hpp\n * @author log K (lX57)\n * @brief Cumulative\
    \ Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\n * @date 2023-07-24\n */\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>\nstruct\
    \ CumulativeSum2D{\n    private:\n    int Y, X;\n    vector<vector<T>> cum;\n\n\
    \    public:\n    /**\n     * @brief  \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\u306E\
    \u521D\u671F\u5316\n     * @param  Y_size \u7E26\u306E\u30B5\u30A4\u30BA\n   \
    \  * @param  X_size \u6A2A\u306E\u30B5\u30A4\u30BA\n     * @param  init \u521D\
    \u671F\u5024\n     */\n    CumulativeSum2D(int Y_size, int X_size, T init = 0)\
    \ : Y(Y_size), X(X_size){\n        cum.resize(Y + 2, vector<T>(X + 2, init));\n\
    \        for(int i = 0; i <= Y; ++i) cum[i][0] = cum[i][X + 1] = 0;\n        for(int\
    \ j = 0; j <= X; ++j) cum[0][j] = cum[Y + 1][j] = 0;\n    }\n\n    /**\n     *\
    \ @brief  (y, x)\u8981\u7D20\u306Bvalue\u3092\u30BB\u30C3\u30C8\u3059\u308B\u3002\
    \n     * @attention build\u524D\u306B\u547C\u3073\u51FA\u3059\u3053\u3068\n  \
    \   * @param  x \u8981\u7D20\u306E\u6DFB\u5B57 (0-index)\n     * @param  y \u8981\
    \u7D20\u306E\u6DFB\u5B57 (0-index)\n     * @param  value \u30BB\u30C3\u30C8\u3059\
    \u308B\u5024\n     */\n    void set(int x, int y, T value){\n        assert(0\
    \ <= x && x < X && 0 <= y && y < Y);\n        cum[y + 1][x + 1] = value;\n   \
    \ }\n\n    /**\n     * @brief (sy, sx)\u3092\u5DE6\u4E0A\u3001(ty, tx)\u3092\u53F3\
    \u4E0B\u3068\u3059\u308B\u9577\u65B9\u5F62\u9818\u57DF\u306B\u5BFE\u3057\u3066\
    value\u3092\u52A0\u7B97\u3059\u308B\u3002\n     * @note (sy, sx)\u3068(ty, tx)\u306F\
    \u305D\u308C\u305E\u308C\u9577\u65B9\u5F62\"\u5185\u90E8\"\u306E\u9685\uFF08\u9589\
    \u533A\u9593\uFF09\n     * @param sx \u5DE6\u4E0A\u30DE\u30B9\u306Ex\u5EA7\u6A19\
    \ (0-index)\n     * @param sy \u5DE6\u4E0A\u30DE\u30B9\u306Ey\u5EA7\u6A19 (0-index)\n\
    \     * @param tx \u53F3\u4E0B\u30DE\u30B9\u306Ex\u5EA7\u6A19 (0-index)\n    \
    \ * @param ty \u53F3\u4E0B\u30DE\u30B9\u306Ey\u5EA7\u6A19 (0-index)\n     * @param\
    \ value \u52A0\u7B97\u3059\u308B\u5024\n     */\n    void add(int sx, int sy,\
    \ int tx, int ty, T value){\n        assert(0 <= sx && sx < X && 0 <= sy && sy\
    \ < Y);\n        assert(0 <= tx && tx < X && 0 <= ty && ty < Y);\n        cum[sy\
    \ + 1][sx + 1] += value;\n        cum[sy + 1][tx + 2] -= value;\n        cum[ty\
    \ + 2][sx + 1] -= value;\n        cum[ty + 2][tx + 2] += value;\n    }\n\n   \
    \ /**\n     * @brief \u7D2F\u7A4D\u548C\u914D\u5217\u3092\u69CB\u7BC9\u3059\u308B\
    \u3002\n     * @attention set\u3067\u521D\u671F\u5024\u306E\u5165\u529B\u3092\u6E08\
    \u307E\u305B\u3066\u304A\u304F\u3053\u3068\n     */\n    void build(){\n     \
    \   for(int i = 1; i <= Y; ++i){\n            for(int j = 1; j <= X; ++j){\n \
    \               cum[i][j] += cum[i][j - 1];\n            }\n        }\n      \
    \  for(int j = 1; j <= X; ++j){\n            for(int i = 1; i <= Y; ++i){\n  \
    \              cum[i][j] += cum[i - 1][j];\n            }\n        }\n    }\n\n\
    \    /**\n     * @brief (sy, sx)\u3092\u5DE6\u4E0A\u3001(ty, tx)\u3092\u53F3\u4E0B\
    \u3068\u3059\u308B\u9577\u65B9\u5F62\u9818\u57DF\u306B\u5BFE\u3059\u308B\u30AF\
    \u30A8\u30EA\u3092\u89E3\u304F\u3002\n     * @note (sy, sx)\u3068(ty, tx)\u306F\
    \u305D\u308C\u305E\u308C\u9577\u65B9\u5F62\"\u5185\u90E8\"\u306E\u9685\uFF08\u9589\
    \u533A\u9593\uFF09\n     * @param sx \u5DE6\u4E0A\u30DE\u30B9\u306Ex\u5EA7\u6A19\
    \ (0-index)\n     * @param sy \u5DE6\u4E0A\u30DE\u30B9\u306Ey\u5EA7\u6A19 (0-index)\n\
    \     * @param tx \u53F3\u4E0B\u30DE\u30B9\u306Ex\u5EA7\u6A19 (0-index)\n    \
    \ * @param ty \u53F3\u4E0B\u30DE\u30B9\u306Ey\u5EA7\u6A19 (0-index)\n     * @return\
    \ T \u30AF\u30A8\u30EA\u306E\u7D50\u679C\n     */\n    T query(int sx, int sy,\
    \ int tx, int ty){\n        assert(0 <= sx && sx < X && 0 <= sy && sy < Y);\n\
    \        assert(0 <= tx && tx < X && 0 <= ty && ty < Y);\n        return cum[ty\
    \ + 1][tx + 1] - cum[ty + 1][sx] - cum[sy][tx + 1] + cum[sy][sx];\n    }\n\n \
    \   /**\n     * @brief \u7D2F\u7A4D\u548C\u914D\u5217\u5168\u4F53\u306E\u6700\u5927\
    \u5024\u3092\u6C42\u3081\u308B\u3002\n     * @return T \u6700\u5927\u5024\n  \
    \   */\n    T max(){\n        T ret = numeric_limits<T>::min();\n        for(int\
    \ i = 1; i <= Y; ++i){\n            for(int j = 1; j <= X; ++j){\n           \
    \     ret = std::max(ret, cum[i][j]);\n            }\n        }\n        return\
    \ ret;\n    }\n    \n    /**\n     * @brief \u7D2F\u7A4D\u548C\u914D\u5217\u5168\
    \u4F53\u306E\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\u3002\n     * @return T\
    \ \u6700\u5C0F\u5024\n     */\n    T min(){\n        T ret = numeric_limits<T>::max();\n\
    \        for(int i = 1; i <= Y; ++i){\n            for(int j = 1; j <= X; ++j){\n\
    \                ret = std::min(ret, cum[i][j]);\n            }\n        }\n \
    \       return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/CumulativeSum2D.hpp
  requiredBy: []
  timestamp: '2023-07-24 01:32:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DSL-5-B.test.cpp
documentation_of: library/DataStructure/CumulativeSum2D.hpp
layout: document
redirect_from:
- /library/library/DataStructure/CumulativeSum2D.hpp
- /library/library/DataStructure/CumulativeSum2D.hpp.html
title: "Cumulative Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
---
