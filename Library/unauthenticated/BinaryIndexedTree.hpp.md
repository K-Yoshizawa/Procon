---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 1 \"Library/unauthenticated/BinaryIndexedTree.hpp\"\n/**\n *\
    \ @file BinaryIndexedTree.hpp\n * @author log K (lX57)\n * @brief Binary Indexed\
    \ Tree\n * @version 2.0\n * @date 2023-11-01\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct BinaryIndexedTree{\n    private:\n\
    \    int size_;\n    vector<T> data_;\n    bool zeroindex_;\n\n    public:\n \
    \   /**\n     * @brief Binary Indexed Tree \u3092\u8981\u7D20\u6570 `Size` \u3067\
    \u521D\u671F\u5316\u3059\u308B\n     * @param Size \u8981\u7D20\u6570\n     *\
    \ @param ZeroIndex `0-index` \u3067\u6271\u3044\u305F\u3044\u304B (default = `false`)\n\
    \     */\n    BinaryIndexedTree(int Size, bool ZeroIndex = false) : size_(Size),\
    \ zeroindex_(ZeroIndex){\n        data_.resize(size_ + 1, 0);\n    }\n\n    T\
    \ sum(int i){\n        T ret = 0;\n        i += zeroindex_;\n        for(; i >\
    \ 0; i -= i & -i) ret += data_[i];\n        return ret;\n    }\n\n    void add(int\
    \ i, T x){\n        i += zeroindex_;\n        for(; i <= size_; i += i & -i) data_[i]\
    \ += x;\n    }\n\n    T query(int l, int r){\n        l += zeroindex_, r += zeroindex_;\n\
    \        return sum(r) - sum(l - 1);\n    }\n};\n"
  code: "/**\n * @file BinaryIndexedTree.hpp\n * @author log K (lX57)\n * @brief Binary\
    \ Indexed Tree\n * @version 2.0\n * @date 2023-11-01\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct BinaryIndexedTree{\n    private:\n\
    \    int size_;\n    vector<T> data_;\n    bool zeroindex_;\n\n    public:\n \
    \   /**\n     * @brief Binary Indexed Tree \u3092\u8981\u7D20\u6570 `Size` \u3067\
    \u521D\u671F\u5316\u3059\u308B\n     * @param Size \u8981\u7D20\u6570\n     *\
    \ @param ZeroIndex `0-index` \u3067\u6271\u3044\u305F\u3044\u304B (default = `false`)\n\
    \     */\n    BinaryIndexedTree(int Size, bool ZeroIndex = false) : size_(Size),\
    \ zeroindex_(ZeroIndex){\n        data_.resize(size_ + 1, 0);\n    }\n\n    T\
    \ sum(int i){\n        T ret = 0;\n        i += zeroindex_;\n        for(; i >\
    \ 0; i -= i & -i) ret += data_[i];\n        return ret;\n    }\n\n    void add(int\
    \ i, T x){\n        i += zeroindex_;\n        for(; i <= size_; i += i & -i) data_[i]\
    \ += x;\n    }\n\n    T query(int l, int r){\n        l += zeroindex_, r += zeroindex_;\n\
    \        return sum(r) - sum(l - 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/unauthenticated/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2024-09-04 01:04:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/BinaryIndexedTree.hpp
- /library/Library/unauthenticated/BinaryIndexedTree.hpp.html
title: Binary Indexed Tree
---
