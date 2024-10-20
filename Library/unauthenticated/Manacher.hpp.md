---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/unauthenticated/Manacher.hpp\"\n\n\n#include <bits/stdc++.h>\n\
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
  path: Library/unauthenticated/Manacher.hpp
  requiredBy: []
  timestamp: '2024-09-04 01:04:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/Manacher.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/Manacher.hpp
- /library/Library/unauthenticated/Manacher.hpp.html
title: Library/unauthenticated/Manacher.hpp
---
