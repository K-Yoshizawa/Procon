---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Compress - \u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 1 \"library/Other/Compress.hpp\"\n/**\n * @file Compress.hpp\n\
    \ * @author log K (lX57)\n * @brief Compress - \u5EA7\u6A19\u5727\u7E2E\n * @version\
    \ 1.1\n * @date 2023-08-24\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate<typename T>\nstruct Compress{\n    int sz, offset;\n    vector<T> to_val;\n\
    \    map<T, int> to_index;\n\n    /**\n     * @brief \u914D\u5217V\u3092\u7528\
    \u3044\u3066\u5EA7\u6A19\u5727\u7E2E\u914D\u5217\u3092\u751F\u6210\u3059\u308B\
    \u3002\n     * @param V \u751F\u6210\u5143\u306E\u914D\u5217\n     * @param start\
    \ \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u5024\u306E\u5148\u982D\u306E\u5024\u3002\
    (default = 0)\n     */\n    Compress(vector<T> &V, int start = 0) : offset(start){\n\
    \        for(auto &v : V){\n            to_val.emplace_back(v);\n        }\n \
    \       sort(to_val.begin(), to_val.end());\n        auto border = unique(to_val.begin(),\
    \ to_val.end());\n        to_val.erase(border, to_val.end());\n        sz = to_val.size();\n\
    \        for(int i = 0; i < sz; ++i){\n            to_index[to_val[i]] = i + offset;\n\
    \        }\n    }\n\n    /**\n     * @brief \u5024\u3092\u5BFE\u5FDC\u3059\u308B\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u306B\u5909\u63DB\u3059\u308B\u3002\n   \
    \  * @param value \u5909\u63DB\u3059\u308B\u5024\n     * @return int \u5909\u63DB\
    \u3055\u308C\u305F\u5024(\u30AA\u30D5\u30BB\u30C3\u30C8\u306E\u5B58\u5728\u306B\
    \u6CE8\u610F)\n     */\n    inline int vi(T value){\n        return to_index[value];\n\
    \    }\n\n    /**\n     * @brief \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u5BFE\
    \u5FDC\u3059\u308B\u5024\u306B\u5909\u63DB\u3059\u308B\u3002\n     * @param index\
    \ \u5909\u63DB\u3059\u308B\u5024(\u30AA\u30D5\u30BB\u30C3\u30C8\u306E\u5B58\u5728\
    \u306B\u6CE8\u610F)\n     * @return T \u5909\u63DB\u3055\u308C\u305F\u5024\n \
    \    */\n    inline T iv(int index){\n        return to_val[index - offset];\n\
    \    }\n};\n"
  code: "/**\n * @file Compress.hpp\n * @author log K (lX57)\n * @brief Compress -\
    \ \u5EA7\u6A19\u5727\u7E2E\n * @version 1.1\n * @date 2023-08-24\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>\nstruct Compress{\n\
    \    int sz, offset;\n    vector<T> to_val;\n    map<T, int> to_index;\n\n   \
    \ /**\n     * @brief \u914D\u5217V\u3092\u7528\u3044\u3066\u5EA7\u6A19\u5727\u7E2E\
    \u914D\u5217\u3092\u751F\u6210\u3059\u308B\u3002\n     * @param V \u751F\u6210\
    \u5143\u306E\u914D\u5217\n     * @param start \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\
    \u5024\u306E\u5148\u982D\u306E\u5024\u3002(default = 0)\n     */\n    Compress(vector<T>\
    \ &V, int start = 0) : offset(start){\n        for(auto &v : V){\n           \
    \ to_val.emplace_back(v);\n        }\n        sort(to_val.begin(), to_val.end());\n\
    \        auto border = unique(to_val.begin(), to_val.end());\n        to_val.erase(border,\
    \ to_val.end());\n        sz = to_val.size();\n        for(int i = 0; i < sz;\
    \ ++i){\n            to_index[to_val[i]] = i + offset;\n        }\n    }\n\n \
    \   /**\n     * @brief \u5024\u3092\u5BFE\u5FDC\u3059\u308B\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u306B\u5909\u63DB\u3059\u308B\u3002\n     * @param value \u5909\u63DB\
    \u3059\u308B\u5024\n     * @return int \u5909\u63DB\u3055\u308C\u305F\u5024(\u30AA\
    \u30D5\u30BB\u30C3\u30C8\u306E\u5B58\u5728\u306B\u6CE8\u610F)\n     */\n    inline\
    \ int vi(T value){\n        return to_index[value];\n    }\n\n    /**\n     *\
    \ @brief \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u5BFE\u5FDC\u3059\u308B\u5024\
    \u306B\u5909\u63DB\u3059\u308B\u3002\n     * @param index \u5909\u63DB\u3059\u308B\
    \u5024(\u30AA\u30D5\u30BB\u30C3\u30C8\u306E\u5B58\u5728\u306B\u6CE8\u610F)\n \
    \    * @return T \u5909\u63DB\u3055\u308C\u305F\u5024\n     */\n    inline T iv(int\
    \ index){\n        return to_val[index - offset];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/Other/Compress.hpp
  requiredBy: []
  timestamp: '2023-10-10 13:39:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Other/Compress.hpp
layout: document
redirect_from:
- /library/library/Other/Compress.hpp
- /library/library/Other/Compress.hpp.html
title: "Compress - \u5EA7\u6A19\u5727\u7E2E"
---
