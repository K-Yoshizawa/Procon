---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: latest/DataStructure/CumulativeSum2D.hpp
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
  bundledCode: "#line 1 \"verify_latest/AOJ-DSL-5-B.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\n\n#line 1\
    \ \"latest/DataStructure/CumulativeSum2D.hpp\"\n/**\n * @file CumulativeSum2D.hpp\n\
    \ * @author log K (lX57)\n * @brief Cumulative Sum 2D - \u4E8C\u6B21\u5143\u7D2F\
    \u7A4D\u548C\n * @version 2.0\n * @date 2023-10-03\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct CumulativeSum2D{\n    private:\n\
    \    int __YSize, __XSize;\n    vector<vector<T>> __Data;\n\n    public:\n   \
    \ CumulativeSum2D(int Y, int X, T Init = 0) : __YSize(Y), __XSize(X){\n      \
    \  __Data.resize(__YSize + 1, vector<T>(__XSize + 1, Init));\n    }\n\n    void\
    \ add(int y, int x, T value = 1){\n        assert(0 <= y && y <= __YSize);\n \
    \       assert(0 <= x && x <= __XSize);\n        __Data[y][x] += value;\n    }\n\
    \n    void add(int sy, int sx, int ty, int tx, T value = 1){\n        add(sy,\
    \ sx, value);\n        add(sy, tx, -value);\n        add(ty, sx, -value);\n  \
    \      add(ty, tx, value);\n    }\n\n    void build(){\n        for(int i = 0;\
    \ i <= __YSize; ++i){\n            for(int j = 1; j <= __XSize; ++j){\n      \
    \          __Data[i][j] += __Data[i][j - 1];\n            }\n        }\n     \
    \   for(int j = 0; j <= __XSize; ++j){\n            for(int i = 1; i <= __YSize;\
    \ ++i){\n                __Data[i][j] += __Data[i - 1][j];\n            }\n  \
    \      }\n    }\n\n    CumulativeSum2D(vector<vector<T>> Init_Data) : __YSize(Init_Data.size()),\
    \ __XSize(Init_Data[0].size()){\n        __Data.resize(__YSize + 1);\n       \
    \ for(int i = 0; i < __YSize; ++i){\n            __Data[i].resize(__XSize + 1);\n\
    \            for(int j = 0; j < __XSize; ++j){\n                __Data[i][j] =\
    \ Init_Data[i][j];\n            }\n        }\n        __Data[__YSize].resize(__XSize,\
    \ 0);\n        build();\n    }\n\n    /**\n     * @brief `(0, 0)` \u3092\u5DE6\
    \u4E0A\u3001 `(y, x)` \u3092\u53F3\u4E0B\u3068\u3059\u308B\u9577\u65B9\u5F62\u9818\
    \u57DF\u306E\u5408\u8A08\u3092\u6C42\u3081\u308B\u3002\n     * @attention \u5EA7\
    \u6A19\u7CFB\u306F\u3059\u3079\u30660-index\u3067\u3042\u308B\n     * @return\
    \ T \u5408\u8A08\n     */\n    T sum(int y, int x){\n        assert(y <= __YSize);\n\
    \        assert(x <= __XSize);\n        if(y < 0 || x < 0) return 0;\n       \
    \ return __Data[y][x];\n    }\n\n    /**\n     * @brief `(sy, sx)` \u3092\u5DE6\
    \u4E0A\u3001 `(ty, tx)` \u3092\u53F3\u4E0B\u3068\u3059\u308B\u9577\u65B9\u5F62\
    \u9818\u57DF\u306E\u5408\u8A08\u3092\u6C42\u3081\u308B\u3002\n     * @attention\
    \ \u5EA7\u6A19\u7CFB\u306F\u3059\u3079\u30660-index\u3067\u3042\u308B\n     *\
    \ @return T \u5408\u8A08\n     */\n    T sum(int sy, int sx, int ty, int tx){\n\
    \        return sum(ty, tx) - sum(ty, sx - 1) - sum(sy - 1, tx) + sum(sy - 1,\
    \ sx - 1);\n    }\n\n    /**\n     * @brief \u7D2F\u7A4D\u548C\u914D\u5217\u5168\
    \u4F53\u306E\u6700\u5927\u5024\u3092\u53D6\u5F97\u3059\u308B\u3002\n     */\n\
    \    T max(){\n        T ret = __Data[0][0];\n        for(int i = 0; i <= __YSize;\
    \ ++i){\n            for(int j = 0; j <= __XSize; ++j){\n                ret =\
    \ std::max(ret, __Data[i][j]);\n            }\n        }\n        return ret;\n\
    \    }\n\n    /**\n     * @brief \u7D2F\u7A4D\u548C\u914D\u5217\u5168\u4F53\u306E\
    \u6700\u5C0F\u5024\u3092\u53D6\u5F97\u3059\u308B\u3002\n     */\n    T min(){\n\
    \        T ret = __Data[0][0];\n        for(int i = 0; i <= __YSize; ++i){\n \
    \           for(int j = 0; j <= __XSize; ++j){\n                ret = std::min(ret,\
    \ __Data[i][j]);\n            }\n        }\n        return ret;\n    }\n};\n#line\
    \ 4 \"verify_latest/AOJ-DSL-5-B.test.cpp\"\n\nint main(){\n    int N; cin >> N;\n\
    \    CumulativeSum2D<int> cum(1010, 1010);\n    for(int i = 0; i < N; ++i){\n\
    \        int x1, y1, x2, y2;\n        cin >> x1 >> y1 >> x2 >> y2;\n        cum.add(y1,\
    \ x1, y2, x2);\n    }\n    cum.build();\n    cout << cum.max() << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n\n#include \"../latest/DataStructure/CumulativeSum2D.hpp\"\n\nint main(){\n\
    \    int N; cin >> N;\n    CumulativeSum2D<int> cum(1010, 1010);\n    for(int\
    \ i = 0; i < N; ++i){\n        int x1, y1, x2, y2;\n        cin >> x1 >> y1 >>\
    \ x2 >> y2;\n        cum.add(y1, x1, y2, x2);\n    }\n    cum.build();\n    cout\
    \ << cum.max() << endl;\n}"
  dependsOn:
  - latest/DataStructure/CumulativeSum2D.hpp
  isVerificationFile: true
  path: verify_latest/AOJ-DSL-5-B.test.cpp
  requiredBy: []
  timestamp: '2023-10-04 00:54:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_latest/AOJ-DSL-5-B.test.cpp
layout: document
redirect_from:
- /verify/verify_latest/AOJ-DSL-5-B.test.cpp
- /verify/verify_latest/AOJ-DSL-5-B.test.cpp.html
title: verify_latest/AOJ-DSL-5-B.test.cpp
---
