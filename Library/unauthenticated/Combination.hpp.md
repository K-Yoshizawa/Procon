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
  bundledCode: "#line 1 \"Library/unauthenticated/Combination.hpp\"\n/**\n * @file\
    \ Combination.hpp\n * @author log K (lX57) (Original Author : ei1333)\n * @brief\
    \ Combination - \u7D44\u5408\u305B\n * @version 1.0\n * @date 2023-10-31\n */\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>\nstruct\
    \ Combination{\n    private:\n    vector<T> fact_, rfact_, inv_;\n\n    inline\
    \ T fact(int k){return fact_[k];}\n\n    inline T rfact(int k){return rfact_[k];}\n\
    \n    inline T inv(int k){return inv_[k];}\n\n    public:\n    Combination(int\
    \ Size) : fact_(Size + 1), rfact_(Size + 1), inv_(Size + 1){\n        fact_[0]\
    \ = rfact_[Size] = inv_[0] = 1;\n        for(int i = 1; i <= Size; ++i) fact_[i]\
    \ = fact_[i - 1] * i;\n        rfact_[Size] /= fact_[Size];\n        for(int i\
    \ = Size - 1; i >= 0; --i) rfact_[i] = rfact_[i + 1] * (i + 1);\n        for(int\
    \ i = 1; i <= Size; ++i) inv_[i] = rfact_[i] * fact_[i - 1];\n    }\n\n    T P(int\
    \ n, int r){\n        if(r < 0 or n < r) return 0;\n        return fact(n) * rfact(n\
    \ - r);\n    }\n\n    T C(int n, int r){\n        if(r < 0 or n < r) return 0;\n\
    \        return fact(n) * rfact(r) * rfact(n - r);\n    }\n\n    T H(int n, int\
    \ r){\n        if(n < 0 or r < 0) return 0;\n        return r == 0 ? 1 : C(n +\
    \ r - 1, r);\n    }\n};\n"
  code: "/**\n * @file Combination.hpp\n * @author log K (lX57) (Original Author :\
    \ ei1333)\n * @brief Combination - \u7D44\u5408\u305B\n * @version 1.0\n * @date\
    \ 2023-10-31\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct Combination{\n    private:\n    vector<T> fact_, rfact_, inv_;\n\n\
    \    inline T fact(int k){return fact_[k];}\n\n    inline T rfact(int k){return\
    \ rfact_[k];}\n\n    inline T inv(int k){return inv_[k];}\n\n    public:\n   \
    \ Combination(int Size) : fact_(Size + 1), rfact_(Size + 1), inv_(Size + 1){\n\
    \        fact_[0] = rfact_[Size] = inv_[0] = 1;\n        for(int i = 1; i <= Size;\
    \ ++i) fact_[i] = fact_[i - 1] * i;\n        rfact_[Size] /= fact_[Size];\n  \
    \      for(int i = Size - 1; i >= 0; --i) rfact_[i] = rfact_[i + 1] * (i + 1);\n\
    \        for(int i = 1; i <= Size; ++i) inv_[i] = rfact_[i] * fact_[i - 1];\n\
    \    }\n\n    T P(int n, int r){\n        if(r < 0 or n < r) return 0;\n     \
    \   return fact(n) * rfact(n - r);\n    }\n\n    T C(int n, int r){\n        if(r\
    \ < 0 or n < r) return 0;\n        return fact(n) * rfact(r) * rfact(n - r);\n\
    \    }\n\n    T H(int n, int r){\n        if(n < 0 or r < 0) return 0;\n     \
    \   return r == 0 ? 1 : C(n + r - 1, r);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/unauthenticated/Combination.hpp
  requiredBy: []
  timestamp: '2024-09-04 01:04:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/Combination.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/Combination.hpp
- /library/Library/unauthenticated/Combination.hpp.html
title: "Combination - \u7D44\u5408\u305B"
---
