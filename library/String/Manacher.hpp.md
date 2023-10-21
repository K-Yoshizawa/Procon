---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-EnumeratePalindromes.test.cpp
    title: verify/LC-EnumeratePalindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/String/Manacher.hpp\"\n\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nvector<int> Manacher(string S, bool NeedEven = true, char\
    \ Dummy = '$'){\n    string T = S;\n    if(NeedEven){\n        T = S[0];\n   \
    \     for(int i = 1; i < S.size(); ++i){\n            T.push_back(Dummy);\n  \
    \          T.push_back(S[i]);\n        }\n    }\n    vector<int> ret(T.size(),\
    \ 0);\n    int i = 0, j = 0;\n    while(i < T.size()){\n        while(i - j >=\
    \ 0 && i + j < T.size() && T[i - j] == T[i + j]) ++j;\n        ret[i] = j;\n \
    \       int k = 1;\n        while(i - k >= 0 && k + ret[i - k] < j){\n       \
    \     ret[i + k] = ret[i - k], ++k;\n        }\n        i += k;\n        j -=\
    \ k;\n    }\n    if(NeedEven){\n        for(int i = 0; i < T.size(); ++i){\n \
    \           if(i % 2) ret[i] = ret[i] / 2 * 2;\n            else ret[i] = (ret[i]\
    \ + 1) / 2 * 2 - 1;\n        }\n    }\n    else{\n        for(int i = 0; i < T.size();\
    \ ++i){\n            ret[i] = ret[i] * 2 - 1;\n        }\n    }\n    return ret;\n\
    }\n"
  code: "\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int> Manacher(string\
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
    }"
  dependsOn: []
  isVerificationFile: false
  path: library/String/Manacher.hpp
  requiredBy: []
  timestamp: '2023-10-21 20:52:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-EnumeratePalindromes.test.cpp
documentation_of: library/String/Manacher.hpp
layout: document
redirect_from:
- /library/library/String/Manacher.hpp
- /library/library/String/Manacher.hpp.html
title: library/String/Manacher.hpp
---
