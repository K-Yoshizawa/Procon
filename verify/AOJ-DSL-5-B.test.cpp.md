---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/CumulativeSum2D.hpp
    title: "Cumulative Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
  bundledCode: "#line 1 \"verify/AOJ-DSL-5-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n\n#line 1 \"library/DataStructure/CumulativeSum2D.hpp\"\n/**\n * @file CumulativeSum2D.hpp\n\
    \ * @author log K (lX57)\n * @brief Cumulative Sum 2D - \u4E8C\u6B21\u5143\u7D2F\
    \u7A4D\u548C\n * @version 2.0\n * @date 2023-12-03\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct CumulativeSum2D{\n    private:\n\
    \    int Y_, X_;\n    vector<vector<T>> data_;\n\n    public:\n    /**\n     *\
    \ @brief \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\u3092 `Init` \u3067\u521D\u671F\u5316\
    \u3059\u308B\n     * @attention \u3053\u306E\u6642\u70B9\u3067\u306F\u69CB\u7BC9\
    \u3055\u308C\u3066\u3044\u306A\u3044\u306E\u3067\u6CE8\u610F\n     * @param Init\
    \ \u521D\u671F\u914D\u5217\n     */\n    CumulativeSum2D(vector<vector<T>> &Init){\n\
    \        Y_ = Init.size(), X_ = Init[0].size();\n        data_.resize(Y_, vector<T>(X_));\n\
    \        for(int i = 0; i < Y_; ++i){\n            for(int j = 0; j < X_; ++j){\n\
    \                data_[i][j] = Init[i][j];\n            }\n        }\n    }\n\n\
    \    /**\n     * @brief \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\
    \u3059\u308B\n     */\n    void build(){\n        for(int i = 0; i < Y_; ++i){\n\
    \            for(int j = 1; j < X_; ++j){\n                data_[i][j] += data_[i][j\
    \ - 1];\n            }\n        }\n        for(int i = 1; i < Y_; ++i){\n    \
    \        for(int j = 0; j < X_; ++j){\n                data_[i][j] += data_[i\
    \ - 1][j];\n            }\n        }\n    }\n\n    /**\n     * @brief `(y, x)`\
    \ \u306B\u5024 `Value` \u3092\u52A0\u7B97\u3059\u308B\n     * @attention `y, x`\
    \ \u306F0-index\n     */\n    void add(int y, int x, T Value){\n        data_[y][x]\
    \ += Value;\n    }\n\n    /**\n     * @brief `(y1, x1)` \u3092\u5DE6\u4E0A\u3001\
    \ `(y2, x2)` \u3092\u53F3\u4E0B\u3068\u3059\u308B\u9577\u65B9\u5F62\u9818\u57DF\
    \u306B\u5024 `Value` \u3092\u52A0\u7B97\u3059\u308B\n     * @attention `y1, x1,\
    \ y2, x2` \u306F0-index\u3067\u3001\u9818\u57DF\u306F `[y1, y2] and [x1, x2]`\
    \ \u3092\u6307\u3059\n     */\n    void add(int y1, int x1, int y2, int x2, T\
    \ Value){\n        data_[y1][x1] += Value;\n        if(y2 + 1 < Y_) data_[y2 +\
    \ 1][x1] -= Value;\n        if(x2 + 1 < X_) data_[y1][x2 + 1] -= Value;\n    \
    \    if(y2 + 1 < Y_ and x2 + 1 < X_) data_[y2 + 1][x2 + 1] += Value;\n    }\n\n\
    \    /**\n     * @brief `(0, 0)` \u3092\u5DE6\u4E0A\u3001 `(y, x)` \u3092\u53F3\
    \u4E0B\u3068\u3059\u308B\u9577\u65B9\u5F62\u9818\u57DF\u306E\u7D2F\u7A4D\u5024\
    \u3092\u6C42\u3081\u308B\n     * @attention `y, x` \u306F0-index\u3067\u3001\u9818\
    \u57DF\u306F `[0, y] and [0, x]` \u3092\u6307\u3059\n     */\n    T query(int\
    \ y, int x){\n        return data_[y][x];\n    }\n\n    /**\n     * @brief `(y1,\
    \ x1)` \u3092\u5DE6\u4E0A\u3001 `(y2, x2)` \u3092\u53F3\u4E0B\u3068\u3059\u308B\
    \u9577\u65B9\u5F62\u9818\u57DF\u306E\u7D2F\u7A4D\u5024\u3092\u6C42\u3081\u308B\
    \n     * @attention `y1, x1, y2, x2` \u306F0-index\u3067\u3001\u9818\u57DF\u306F\
    \ `[y1, y2] and [x1, x2]` \u3092\u6307\u3059\n     */\n    T query(int y1, int\
    \ x1, int y2, int x2){\n        T ret = data_[y2][x2];\n        if(y1 > 0) ret\
    \ -= data_[y1 - 1][x2];\n        if(x1 > 0) ret -= data_[y2][x1 - 1];\n      \
    \  if(y1 > 0 and x1 > 0) ret += data_[y1 - 1][x1 - 1];\n        return ret;\n\
    \    }\n\n    /**\n     * @brief \u9818\u57DF\u5168\u4F53\u306B\u6BD4\u8F03\u95A2\
    \u6570\u3092\u9069\u7528\u3055\u305B\u3001\u305D\u306E\u7D50\u679C\u3092\u5F97\
    \u308B\n     * @param Compare \u6BD4\u8F03\u95A2\u6570 : \u5F15\u6570\u306F `src,\
    \ cmp` \u3067\u623B\u308A\u5024\u306F `T`\n     */\n    T search(function<T(T,\
    \ T)> Compare){\n        T ret = data_[0][0];\n        for(int i = 0; i < Y_;\
    \ ++i){\n            for(int j = 0; j < X_; ++j){\n                ret = Compare(ret,\
    \ data_[i][j]);\n            }\n        }\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u9818\u57DF\u5168\u4F53\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u30DE\u30B9\u306E\u6570\u3092\u6570\u3048\u308B\n     * @param Condition \u95A2\
    \u6570 : \u5F15\u6570\u306F `T` \u3067\u623B\u308A\u5024\u306F `bool`\n     */\n\
    \    int count(function<bool(T)> Condition){\n        int ret = 0;\n        for(int\
    \ i = 0; i < Y_; ++i){\n            for(int j = 0; j < X_; ++j){\n           \
    \     ret += Condition(data_[i][j]);\n            }\n        }\n        return\
    \ ret;\n    }\n};\n#line 4 \"verify/AOJ-DSL-5-B.test.cpp\"\n\nint main(){\n  \
    \  int N; cin >> N;\n    vector<vector<int>> Init(1010, vector<int>(1010, 0));\n\
    \n    CumulativeSum2D<int> cum(Init);\n    for(int i = 0; i < N; ++i){\n     \
    \   int x1, y1, x2, y2;\n        cin >> x1 >> y1 >> x2 >> y2, --x2, --y2;\n  \
    \      cum.add(y1, x1, y2, x2, 1);\n    }\n    cum.build();\n    cout << cum.search([](int\
    \ s, int t){return max(s, t);}) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n\n#include \"../library/DataStructure/CumulativeSum2D.hpp\"\n\nint main(){\n\
    \    int N; cin >> N;\n    vector<vector<int>> Init(1010, vector<int>(1010, 0));\n\
    \n    CumulativeSum2D<int> cum(Init);\n    for(int i = 0; i < N; ++i){\n     \
    \   int x1, y1, x2, y2;\n        cin >> x1 >> y1 >> x2 >> y2, --x2, --y2;\n  \
    \      cum.add(y1, x1, y2, x2, 1);\n    }\n    cum.build();\n    cout << cum.search([](int\
    \ s, int t){return max(s, t);}) << endl;\n}"
  dependsOn:
  - library/DataStructure/CumulativeSum2D.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-5-B.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 18:59:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-5-B.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-5-B.test.cpp
- /verify/verify/AOJ-DSL-5-B.test.cpp.html
title: verify/AOJ-DSL-5-B.test.cpp
---
