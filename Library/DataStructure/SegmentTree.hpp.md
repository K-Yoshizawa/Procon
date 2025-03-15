---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-A.test.cpp
    title: verify/AOJ-DSL-2-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-B.test.cpp
    title: verify/AOJ-DSL-2-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-PointAddRangeSum.test.cpp
    title: verify/LC-PointAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-PointSetRangeComposite.test.cpp
    title: verify/LC-PointSetRangeComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexAddPathSum.test.cpp
    title: verify/LC-VertexAddPathSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
    title: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexAddSubtreeSum.test.cpp
    title: verify/LC-VertexAddSubtreeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexSetPathComposite.test.cpp
    title: verify/LC-VertexSetPathComposite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"Library/DataStructure/SegmentTree.hpp\"\n/**\n * @file SegmentTree.hpp\n\
    \ * @author log K (lX57)\n * @brief Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n * @version 3.0\n * @date 2024-09-04\n */\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n#line 10 \"Library/DataStructure/SegmentTree.hpp\"\n\ntemplate<typename\
    \ Monoid>\nclass SegmentTree{\n    public:\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\
    \u8981\u7D20\u6570 `size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param\
    \ size \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\n     * @param\
    \ merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param\
    \ monoid_identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param\
    \ zero_index 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\u304B (default\
    \ = `false`)\n     */\n    SegmentTree(int size, F merge, const Monoid &monoid_identity,\
    \ bool zero_index = false) :\n            f(merge), id_(monoid_identity), zero_index_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < size) size_ <<= 1;\n        offset_\
    \ = size_ - 1;\n        data_.resize(2 * size_, id_);\n    }\n\n    /**\n    \
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\
    \n     * @attention \u5FC5\u305A `Set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\u5165\
    \u3057\u3066\u304B\u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n     */\n\
    \    void Build(){\n        for(int i = offset_; i >= 1; --i){\n            data_[i]\
    \ = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n    /**\n    \
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\u5024\u3092\u4EE3\
    \u5165\u3059\u308B\u3002\n     * @param index \u4EE3\u5165\u5148\u306E\u8981\u7D20\
    \u756A\u53F7 (default = 1-index)\n     * @param value \u4EE3\u5165\u3059\u308B\
    \u5024\n     */\n    void Set(int index, Monoid value){\n        Validate(index\
    \ + zero_index_);\n        data_[offset_ + index + zero_index_] = value;\n   \
    \ }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u914D\
    \u5217 `init_data` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param init_data\
    \ \u521D\u671F\u30C7\u30FC\u30BF\u306E\u914D\u5217\n     * @param merge \u533A\
    \u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param monoid_identity\
    \ \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param zero_index 0-index\u3068\
    \u3057\u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(vector<Monoid>\
    \ &init_data, F merge, const Monoid &monoid_identity, bool zero_index = false)\
    \ :\n            f(merge), id_(monoid_identity), zero_index_(zero_index){\n  \
    \      size_ = 1;\n        while(size_ < (int)init_data.size()) size_ <<= 1;\n\
    \        offset_ = size_ - 1;\n        data_.resize(2 * size_, id_);\n       \
    \ for(int i = 0; i < (int)init_data.size(); ++i){\n            data_[size_ + i]\
    \ = init_data[i];\n        }\n        Build();\n    }\n\n    /**\n     * @brief\
    \ \u4E00\u70B9\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\
    \n     * @param index \u66F4\u65B0\u5148\u306E\u8981\u7D20\u756A\u53F7 (default\
    \ = 1-index)\n     * @param value \u66F4\u65B0\u3059\u308B\u5024\n     */\n  \
    \  void Update(int index, Monoid value){\n        Validate(index + zero_index_);\n\
    \        int k = offset_ + index + zero_index_;\n        data_[k] = value;\n \
    \       while(k >>= 1){\n            data_[k] = f(data_[2 * k], data_[2 * k +\
    \ 1]);\n        }\n    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[left,\
    \ Right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\
    \u884C\u3046\u3002\n     * @param left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\
    \n     * @param right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid Query(int left,\
    \ int right){\n        if(left == right) return id_;\n        Validate(left +\
    \ zero_index_);\n        Validate(right + zero_index_ - 1);\n        int l = left\
    \ + zero_index_ + offset_, r = right + zero_index_ + offset_;\n        Monoid\
    \ al = id_, ar = id_;\n        while(l < r){\n            if(l & 1) al = f(al,\
    \ data_[l++]);\n            if(r & 1) ar = f(data_[--r], ar);\n            l >>=\
    \ 1, r >>= 1;\n        }\n        return f(al, ar);\n    }\n\n    /**\n     *\
    \ @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\
    \u308B\u3002\n     * @param k \u53D6\u5F97\u5148\u306E\u8981\u7D20\u756A\u53F7\
    \ (default = 1-index)\n     * @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\
    \n     */\n    Monoid get_value(int k){\n        Validate(k + zero_index_);\n\
    \        return data_[offset_ + k + zero_index_];\n    }\n\n    Monoid operator[](const\
    \ int &k){\n        return get_value(k);\n    }\n\n    private:\n    int size_,\
    \ offset_, zero_index_;\n    vector<Monoid> data_;\n    const F f;\n    const\
    \ Monoid id_;\n\n    inline void Validate(int x) const {\n        assert(1 <=\
    \ x && x <= size_);\n    }\n};\n"
  code: "/**\n * @file SegmentTree.hpp\n * @author log K (lX57)\n * @brief Segment\
    \ Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @version 3.0\n * @date 2024-09-04\n\
    \ */\n\n#include \"../Common.hpp\"\n\ntemplate<typename Monoid>\nclass SegmentTree{\n\
    \    public:\n    using F = function<Monoid(Monoid, Monoid)>;\n\n    /**\n   \
    \  * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\u6570 `size`\
    \ \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param size \u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\n     * @param merge \u533A\u9593\u53D6\
    \u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param monoid_identity \u30E2\u30CE\
    \u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param zero_index 0-index\u3068\u3057\
    \u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(int\
    \ size, F merge, const Monoid &monoid_identity, bool zero_index = false) :\n \
    \           f(merge), id_(monoid_identity), zero_index_(zero_index){\n       \
    \ size_ = 1;\n        while(size_ < size) size_ <<= 1;\n        offset_ = size_\
    \ - 1;\n        data_.resize(2 * size_, id_);\n    }\n\n    /**\n     * @brief\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n \
    \    * @attention \u5FC5\u305A `Set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\u5165\
    \u3057\u3066\u304B\u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n     */\n\
    \    void Build(){\n        for(int i = offset_; i >= 1; --i){\n            data_[i]\
    \ = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n    /**\n    \
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\u5024\u3092\u4EE3\
    \u5165\u3059\u308B\u3002\n     * @param index \u4EE3\u5165\u5148\u306E\u8981\u7D20\
    \u756A\u53F7 (default = 1-index)\n     * @param value \u4EE3\u5165\u3059\u308B\
    \u5024\n     */\n    void Set(int index, Monoid value){\n        Validate(index\
    \ + zero_index_);\n        data_[offset_ + index + zero_index_] = value;\n   \
    \ }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u914D\
    \u5217 `init_data` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param init_data\
    \ \u521D\u671F\u30C7\u30FC\u30BF\u306E\u914D\u5217\n     * @param merge \u533A\
    \u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param monoid_identity\
    \ \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param zero_index 0-index\u3068\
    \u3057\u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(vector<Monoid>\
    \ &init_data, F merge, const Monoid &monoid_identity, bool zero_index = false)\
    \ :\n            f(merge), id_(monoid_identity), zero_index_(zero_index){\n  \
    \      size_ = 1;\n        while(size_ < (int)init_data.size()) size_ <<= 1;\n\
    \        offset_ = size_ - 1;\n        data_.resize(2 * size_, id_);\n       \
    \ for(int i = 0; i < (int)init_data.size(); ++i){\n            data_[size_ + i]\
    \ = init_data[i];\n        }\n        Build();\n    }\n\n    /**\n     * @brief\
    \ \u4E00\u70B9\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\
    \n     * @param index \u66F4\u65B0\u5148\u306E\u8981\u7D20\u756A\u53F7 (default\
    \ = 1-index)\n     * @param value \u66F4\u65B0\u3059\u308B\u5024\n     */\n  \
    \  void Update(int index, Monoid value){\n        Validate(index + zero_index_);\n\
    \        int k = offset_ + index + zero_index_;\n        data_[k] = value;\n \
    \       while(k >>= 1){\n            data_[k] = f(data_[2 * k], data_[2 * k +\
    \ 1]);\n        }\n    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[left,\
    \ Right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\
    \u884C\u3046\u3002\n     * @param left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\
    \n     * @param right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid Query(int left,\
    \ int right){\n        if(left == right) return id_;\n        Validate(left +\
    \ zero_index_);\n        Validate(right + zero_index_ - 1);\n        int l = left\
    \ + zero_index_ + offset_, r = right + zero_index_ + offset_;\n        Monoid\
    \ al = id_, ar = id_;\n        while(l < r){\n            if(l & 1) al = f(al,\
    \ data_[l++]);\n            if(r & 1) ar = f(data_[--r], ar);\n            l >>=\
    \ 1, r >>= 1;\n        }\n        return f(al, ar);\n    }\n\n    /**\n     *\
    \ @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\
    \u308B\u3002\n     * @param k \u53D6\u5F97\u5148\u306E\u8981\u7D20\u756A\u53F7\
    \ (default = 1-index)\n     * @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\
    \n     */\n    Monoid get_value(int k){\n        Validate(k + zero_index_);\n\
    \        return data_[offset_ + k + zero_index_];\n    }\n\n    Monoid operator[](const\
    \ int &k){\n        return get_value(k);\n    }\n\n    private:\n    int size_,\
    \ offset_, zero_index_;\n    vector<Monoid> data_;\n    const F f;\n    const\
    \ Monoid id_;\n\n    inline void Validate(int x) const {\n        assert(1 <=\
    \ x && x <= size_);\n    }\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2024-10-20 22:40:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DSL-2-A.test.cpp
  - verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
  - verify/LC-VertexAddSubtreeSum.test.cpp
  - verify/LC-PointSetRangeComposite.test.cpp
  - verify/LC-PointAddRangeSum.test.cpp
  - verify/LC-VertexAddPathSum.test.cpp
  - verify/AOJ-DSL-2-B.test.cpp
  - verify/LC-VertexSetPathComposite.test.cpp
documentation_of: Library/DataStructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/SegmentTree.hpp
- /library/Library/DataStructure/SegmentTree.hpp.html
title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
