---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/String/Manacher.hpp
    title: library/String/Manacher.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/LC-EnumeratePalindromes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n#line 1 \"library/String/Manacher.hpp\"\
    \n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int> Manacher(string\
    \ S, bool NeedEven = true, char Dummy = '$'){\n    string T = S;\n    if(NeedEven){\n\
    \        T = S[0];\n        for(int i = 1; i < S.size(); ++i){\n            T.push_back(Dummy);\n\
    \            T.push_back(S[i]);\n        }\n    }\n    vector<int> ret(T.size(),\
    \ 0);\n    int i = 0, j = 0;\n    while(i < T.size()){\n        while(i - j >=\
    \ 0 && i + j < T.size() && T[i - j] == T[i + j]) ++j;\n        ret[i] = j;\n \
    \       int k = 1;\n        while(i - k >= 0 && k + ret[i - k] < j){\n       \
    \     ret[i + k] = ret[i - k], ++k;\n        }\n        i += k;\n        j -=\
    \ k;\n    }\n    if(NeedEven){\n        for(int i = 0; i < T.size(); ++i){\n \
    \           if(i % 2) ret[i] = ret[i] / 2 * 2;\n            else ret[i] = (ret[i]\
    \ + 1) / 2 * 2 - 1;\n        }\n    }\n    else{\n        for(int i = 0; i < T.size();\
    \ ++i){\n            ret[i] = ret[i] * 2 - 1;\n        }\n    }\n    return ret;\n\
    }\n#line 4 \"verify/LC-EnumeratePalindromes.test.cpp\"\n\nint main(){\n    string\
    \ S; cin >> S;\n    auto ans = Manacher(S);\n    for(auto a : ans){\n        cout\
    \ << a << \" \";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../library/String/Manacher.hpp\"\n\nint main(){\n    string S;\
    \ cin >> S;\n    auto ans = Manacher(S);\n    for(auto a : ans){\n        cout\
    \ << a << \" \";\n    }\n}"
  dependsOn:
  - library/String/Manacher.hpp
  isVerificationFile: true
  path: verify/LC-EnumeratePalindromes.test.cpp
  requiredBy: []
  timestamp: '2023-10-21 20:52:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-EnumeratePalindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-EnumeratePalindromes.test.cpp
- /verify/verify/LC-EnumeratePalindromes.test.cpp.html
title: verify/LC-EnumeratePalindromes.test.cpp
---
