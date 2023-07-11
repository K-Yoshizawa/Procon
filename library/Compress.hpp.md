---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yuki-1995.test.cpp
    title: verify/yuki-1995.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Compress - \u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 2 \"library/Compress.hpp\"\n\n/**\n * @brief Compress - \u5EA7\
    \u6A19\u5727\u7E2E\n */\n\n#include <vector>\n#include <map>\n#include <algorithm>\n\
    using namespace std;\n\nstruct Compress{\n    int sz;\n    vector<int> to_val;\n\
    \    map<int, int> to_index;\n\n    /**\n     * @brief  \u914D\u5217V\u3067\u69CB\
    \u7BC9\u3059\u308B\u3002\n     */\n    Compress(vector<int> &V){\n        for(auto\
    \ &v : V){\n            to_val.emplace_back(v);\n        }\n        sort(to_val.begin(),\
    \ to_val.end());\n        auto border = unique(to_val.begin(), to_val.end());\n\
    \        to_val.erase(border, to_val.end());\n        sz = to_val.size();\n  \
    \      for(int i = 0; i < sz; ++i){\n            to_index[to_val[i]] = i;\n  \
    \      }\n    }\n\n    // \u5024\u3092\u5BFE\u5FDC\u3059\u308B\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u306B\n    inline int vi(int value){\n        return to_index[value];\n\
    \    }\n\n    // \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u5BFE\u5FDC\u3059\u308B\
    \u5024\u306B\n    inline int iv(int index){\n        return to_val[index];\n \
    \   }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Compress - \u5EA7\u6A19\u5727\u7E2E\n */\n\
    \n#include <vector>\n#include <map>\n#include <algorithm>\nusing namespace std;\n\
    \nstruct Compress{\n    int sz;\n    vector<int> to_val;\n    map<int, int> to_index;\n\
    \n    /**\n     * @brief  \u914D\u5217V\u3067\u69CB\u7BC9\u3059\u308B\u3002\n\
    \     */\n    Compress(vector<int> &V){\n        for(auto &v : V){\n         \
    \   to_val.emplace_back(v);\n        }\n        sort(to_val.begin(), to_val.end());\n\
    \        auto border = unique(to_val.begin(), to_val.end());\n        to_val.erase(border,\
    \ to_val.end());\n        sz = to_val.size();\n        for(int i = 0; i < sz;\
    \ ++i){\n            to_index[to_val[i]] = i;\n        }\n    }\n\n    // \u5024\
    \u3092\u5BFE\u5FDC\u3059\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u306B\n   \
    \ inline int vi(int value){\n        return to_index[value];\n    }\n\n    //\
    \ \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u5BFE\u5FDC\u3059\u308B\u5024\u306B\
    \n    inline int iv(int index){\n        return to_val[index];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/Compress.hpp
  requiredBy: []
  timestamp: '2023-06-26 11:08:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yuki-1995.test.cpp
documentation_of: library/Compress.hpp
layout: document
redirect_from:
- /library/library/Compress.hpp
- /library/library/Compress.hpp.html
title: "Compress - \u5EA7\u6A19\u5727\u7E2E"
---
