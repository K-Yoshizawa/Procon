---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-RangeAffinePointGet.test.cpp
    title: verify/LC-RangeAffinePointGet.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Dual Segment Tree - \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728"
    links: []
  bundledCode: "#line 1 \"Library/DataStructure/DualSegmentTree.hpp\"\n/**\n * @file\
    \ DualSegmentTree.hpp\n * @brief Dual Segment Tree - \u53CC\u5BFE\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\n * @version 2.0\n * @date 2024-11-29\n */\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr\
    \ const ll INF = (1LL << 62) - (1LL << 30) - 1;\n#line 9 \"Library/DataStructure/DualSegmentTree.hpp\"\
    \n\ntemplate<typename OperatorMonoid>\nclass DualSegmentTree{\n    public:\n \
    \   using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n    \n\
    \    DualSegmentTree(int size, H composite, const OperatorMonoid &operator_identity,\
    \ bool zero_index = false)\n    : h(composite), om1_(operator_identity), zeroindex_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < size) size_ <<= 1;\n        offset_\
    \ = size_ - 1;\n        lazy_.resize(2 * size_, om1_);\n        is_identity_.resize(2\
    \ * size_, true);\n    }\n\n    void Set(int index, OperatorMonoid value){\n \
    \       Validate(index + zeroindex_);\n        lazy_[offset_ + index + zeroindex_]\
    \ = value;\n    }\n\n    void Update(int left, int right, OperatorMonoid operation){\n\
    \        Validate(left + zeroindex_);\n        Validate(right + zeroindex_ - 1);\n\
    \        RecursiveUpdate(left + zeroindex_, right + zeroindex_, operation, 1,\
    \ size_ + 1, 1);\n    }\n\n    OperatorMonoid Product(int index){\n        Validate(index\
    \ + zeroindex_);\n        return RecursiveProduct(index + zeroindex_, 1, size_\
    \ + 1, 1);\n    }\n\n    private:\n    int size_, offset_, zeroindex_;\n    vector<OperatorMonoid>\
    \ lazy_;\n    vector<bool> is_identity_;\n    const H h;\n    const OperatorMonoid\
    \ om1_;\n\n    inline void Validate(int x){\n        assert(1 <= x && x <= size_);\n\
    \    }\n\n    void Evaluate(int k){\n        if(is_identity_[k]) return;\n   \
    \     if(k < size_){\n            lazy_[k * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);\n\
    \            is_identity_[k * 2 + 0] = false;\n            lazy_[k * 2 + 1] =\
    \ h(lazy_[k * 2 + 1], lazy_[k]);\n            is_identity_[k * 2 + 1] = false;\n\
    \            lazy_[k] = om1_;\n            is_identity_[k] = true;\n        }\n\
    \    }\n\n    void RecursiveUpdate(int ul, int ur, OperatorMonoid x, int left,\
    \ int right, int cell){\n        Evaluate(cell);\n        if(ul <= left && right\
    \ <= ur){\n            lazy_[cell] = h(lazy_[cell], x);\n            is_identity_[cell]\
    \ = false;\n            Evaluate(cell);\n        }\n        else if(ul < right\
    \ && left < ur){\n            int mid = (left + right) / 2;\n            RecursiveUpdate(ul,\
    \ ur, x, left, mid, cell * 2 + 0);\n            RecursiveUpdate(ul, ur, x, mid,\
    \ right, cell * 2 + 1);\n        }\n    }\n    \n    OperatorMonoid RecursiveProduct(int\
    \ q, int left, int right, int cell){\n        Evaluate(cell);\n        if(q ==\
    \ left && right - left == 1) return lazy_[cell];\n        int mid = (left + right)\
    \ / 2;\n        if(q < mid) return RecursiveProduct(q, left, mid, cell * 2 + 0);\n\
    \        else return RecursiveProduct(q, mid, right, cell * 2 + 1);\n    }\n};\n"
  code: "/**\n * @file DualSegmentTree.hpp\n * @brief Dual Segment Tree - \u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @version 2.0\n * @date 2024-11-29\n */\n\
    \n#include \"../Common.hpp\"\n\ntemplate<typename OperatorMonoid>\nclass DualSegmentTree{\n\
    \    public:\n    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n\
    \    \n    DualSegmentTree(int size, H composite, const OperatorMonoid &operator_identity,\
    \ bool zero_index = false)\n    : h(composite), om1_(operator_identity), zeroindex_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < size) size_ <<= 1;\n        offset_\
    \ = size_ - 1;\n        lazy_.resize(2 * size_, om1_);\n        is_identity_.resize(2\
    \ * size_, true);\n    }\n\n    void Set(int index, OperatorMonoid value){\n \
    \       Validate(index + zeroindex_);\n        lazy_[offset_ + index + zeroindex_]\
    \ = value;\n    }\n\n    void Update(int left, int right, OperatorMonoid operation){\n\
    \        Validate(left + zeroindex_);\n        Validate(right + zeroindex_ - 1);\n\
    \        RecursiveUpdate(left + zeroindex_, right + zeroindex_, operation, 1,\
    \ size_ + 1, 1);\n    }\n\n    OperatorMonoid Product(int index){\n        Validate(index\
    \ + zeroindex_);\n        return RecursiveProduct(index + zeroindex_, 1, size_\
    \ + 1, 1);\n    }\n\n    private:\n    int size_, offset_, zeroindex_;\n    vector<OperatorMonoid>\
    \ lazy_;\n    vector<bool> is_identity_;\n    const H h;\n    const OperatorMonoid\
    \ om1_;\n\n    inline void Validate(int x){\n        assert(1 <= x && x <= size_);\n\
    \    }\n\n    void Evaluate(int k){\n        if(is_identity_[k]) return;\n   \
    \     if(k < size_){\n            lazy_[k * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);\n\
    \            is_identity_[k * 2 + 0] = false;\n            lazy_[k * 2 + 1] =\
    \ h(lazy_[k * 2 + 1], lazy_[k]);\n            is_identity_[k * 2 + 1] = false;\n\
    \            lazy_[k] = om1_;\n            is_identity_[k] = true;\n        }\n\
    \    }\n\n    void RecursiveUpdate(int ul, int ur, OperatorMonoid x, int left,\
    \ int right, int cell){\n        Evaluate(cell);\n        if(ul <= left && right\
    \ <= ur){\n            lazy_[cell] = h(lazy_[cell], x);\n            is_identity_[cell]\
    \ = false;\n            Evaluate(cell);\n        }\n        else if(ul < right\
    \ && left < ur){\n            int mid = (left + right) / 2;\n            RecursiveUpdate(ul,\
    \ ur, x, left, mid, cell * 2 + 0);\n            RecursiveUpdate(ul, ur, x, mid,\
    \ right, cell * 2 + 1);\n        }\n    }\n    \n    OperatorMonoid RecursiveProduct(int\
    \ q, int left, int right, int cell){\n        Evaluate(cell);\n        if(q ==\
    \ left && right - left == 1) return lazy_[cell];\n        int mid = (left + right)\
    \ / 2;\n        if(q < mid) return RecursiveProduct(q, left, mid, cell * 2 + 0);\n\
    \        else return RecursiveProduct(q, mid, right, cell * 2 + 1);\n    }\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/DualSegmentTree.hpp
  requiredBy: []
  timestamp: '2025-05-30 19:43:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-RangeAffinePointGet.test.cpp
documentation_of: Library/DataStructure/DualSegmentTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/DualSegmentTree.hpp
- /library/Library/DataStructure/DualSegmentTree.hpp.html
title: "Dual Segment Tree - \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
