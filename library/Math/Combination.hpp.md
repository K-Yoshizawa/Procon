---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Combination - \u7D44\u5408\u305B"
    links: []
  bundledCode: "#line 1 \"library/Math/Combination.hpp\"\n/**\n * @file Combination.hpp\n\
    \ * @author log K (lX57) (Original Author : ei1333)\n * @brief Combination - \u7D44\
    \u5408\u305B\n * @version 1.0\n * @date 2023-10-31\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct Combination{\n    private:\n\
    \    vector<T> __fact, __rfact, __inv;\n\n    inline T fact(int k){return __fact[k];}\n\
    \n    inline T rfact(int k){return __rfact[k];}\n\n    inline T inv(int k){return\
    \ __inv[k];}\n\n    public:\n    Combination(int Size) : __fact(Size + 1), __rfact(Size\
    \ + 1), __inv(Size + 1){\n        __fact[0] = __rfact[Size] = __inv[0] = 1;\n\
    \        for(int i = 1; i <= Size; ++i) __fact[i] = __fact[i - 1] * i;\n     \
    \   __rfact[Size] /= __fact[Size];\n        for(int i = Size - 1; i >= 0; --i)\
    \ __rfact[i] = __rfact[i + 1] * (i + 1);\n        for(int i = 1; i <= Size; ++i)\
    \ __inv[i] = __rfact[i] * __fact[i - 1];\n    }\n\n    T P(int n, int r){\n  \
    \      if(r < 0 or n < r) return 0;\n        return fact(n) * rfact(n - r);\n\
    \    }\n\n    T C(int n, int r){\n        if(r < 0 or n < r) return 0;\n     \
    \   return fact(n) * rfact(r) * rfact(n - r);\n    }\n\n    T H(int n, int r){\n\
    \        if(n < 0 or r < 0) return 0;\n        return r == 0 ? 1 : C(n + r - 1,\
    \ r);\n    }\n};\n"
  code: "/**\n * @file Combination.hpp\n * @author log K (lX57) (Original Author :\
    \ ei1333)\n * @brief Combination - \u7D44\u5408\u305B\n * @version 1.0\n * @date\
    \ 2023-10-31\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct Combination{\n    private:\n    vector<T> __fact, __rfact, __inv;\n\
    \n    inline T fact(int k){return __fact[k];}\n\n    inline T rfact(int k){return\
    \ __rfact[k];}\n\n    inline T inv(int k){return __inv[k];}\n\n    public:\n \
    \   Combination(int Size) : __fact(Size + 1), __rfact(Size + 1), __inv(Size +\
    \ 1){\n        __fact[0] = __rfact[Size] = __inv[0] = 1;\n        for(int i =\
    \ 1; i <= Size; ++i) __fact[i] = __fact[i - 1] * i;\n        __rfact[Size] /=\
    \ __fact[Size];\n        for(int i = Size - 1; i >= 0; --i) __rfact[i] = __rfact[i\
    \ + 1] * (i + 1);\n        for(int i = 1; i <= Size; ++i) __inv[i] = __rfact[i]\
    \ * __fact[i - 1];\n    }\n\n    T P(int n, int r){\n        if(r < 0 or n < r)\
    \ return 0;\n        return fact(n) * rfact(n - r);\n    }\n\n    T C(int n, int\
    \ r){\n        if(r < 0 or n < r) return 0;\n        return fact(n) * rfact(r)\
    \ * rfact(n - r);\n    }\n\n    T H(int n, int r){\n        if(n < 0 or r < 0)\
    \ return 0;\n        return r == 0 ? 1 : C(n + r - 1, r);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/Math/Combination.hpp
  requiredBy: []
  timestamp: '2023-11-02 01:25:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Math/Combination.hpp
layout: document
redirect_from:
- /library/library/Math/Combination.hpp
- /library/library/Math/Combination.hpp.html
title: "Combination - \u7D44\u5408\u305B"
---
