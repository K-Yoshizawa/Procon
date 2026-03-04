---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-RectangleSum.test.cpp
    title: verify/LC-RectangleSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 2 \"Library/Other/Compress.hpp\"\n\ntemplate<typename T>\nclass Compress{\n\
    \    public:\n    Compress(vector<T> &A, bool unique_flag = true) : data_(A){\n\
    \        sort(data_.begin(), data_.end());\n        if(unique_flag) data_.erase(unique(data_.begin(),\
    \ data_.end()), data_.end());\n        n_ = (int)data_.size();\n    }\n\n    int\
    \ Index(const T x) const {\n        int ret = distance(data_.begin(), lower_bound(data_.begin(),\
    \ data_.end(), x));\n        assert(ret < n_ && data_[ret] == x);\n        return\
    \ ret;\n    }\n\n    int LowerBound(const T x) const {\n        int ret = distance(data_.begin(),\
    \ lower_bound(data_.begin(), data_.end(), x));\n        return ret;\n    }\n\n\
    \    int UpperBound(const T x) const {\n        int ret = distance(data_.begin(),\
    \ upper_bound(data_.begin(), data_.end(), x));\n        return ret;\n    }\n\n\
    \    size_t Size() const {\n        return n_;\n    }\n\n    T operator[](const\
    \ int k) const {\n        return data_.at(k);\n    }\n\n    private:\n    size_t\
    \ n_;\n    vector<T> data_;\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename T>\nclass Compress{\n   \
    \ public:\n    Compress(vector<T> &A, bool unique_flag = true) : data_(A){\n \
    \       sort(data_.begin(), data_.end());\n        if(unique_flag) data_.erase(unique(data_.begin(),\
    \ data_.end()), data_.end());\n        n_ = (int)data_.size();\n    }\n\n    int\
    \ Index(const T x) const {\n        int ret = distance(data_.begin(), lower_bound(data_.begin(),\
    \ data_.end(), x));\n        assert(ret < n_ && data_[ret] == x);\n        return\
    \ ret;\n    }\n\n    int LowerBound(const T x) const {\n        int ret = distance(data_.begin(),\
    \ lower_bound(data_.begin(), data_.end(), x));\n        return ret;\n    }\n\n\
    \    int UpperBound(const T x) const {\n        int ret = distance(data_.begin(),\
    \ upper_bound(data_.begin(), data_.end(), x));\n        return ret;\n    }\n\n\
    \    size_t Size() const {\n        return n_;\n    }\n\n    T operator[](const\
    \ int k) const {\n        return data_.at(k);\n    }\n\n    private:\n    size_t\
    \ n_;\n    vector<T> data_;\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Other/Compress.hpp
  requiredBy: []
  timestamp: '2026-02-12 16:49:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-RectangleSum.test.cpp
documentation_of: Library/Other/Compress.hpp
layout: document
redirect_from:
- /library/Library/Other/Compress.hpp
- /library/Library/Other/Compress.hpp.html
title: Library/Other/Compress.hpp
---
