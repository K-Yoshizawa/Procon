---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/LC-RangeAffineRangeSum.test.cpp
    title: verify/LC-RangeAffineRangeSum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Lazy Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"Library/DataStructure/LazySegmentTree.hpp\"\n/**\n * @file\
    \ LazySegmentTree.hpp\n * @author log K (lX57)\n * @brief Lazy Segment Tree -\
    \ \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @version 2.0\n\
    \ * @date 2023-10-02\n */\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n\
    \ */\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n#line 10 \"Library/DataStructure/LazySegmentTree.hpp\"\
    \n\ntemplate<typename Monoid, typename OperatorMonoid = Monoid>\nclass LazySegmentTree{\n\
    \    public:\n    using F = function<Monoid(Monoid, Monoid)>;\n    using G = function<Monoid(Monoid,\
    \ OperatorMonoid)>;\n    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n\
    \n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\
    \u6570 `size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param size \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\n     * @param merge \u533A\
    \u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param mapping \u9045\
    \u5EF6\u8A55\u4FA1\u306E\u9069\u7528\u3092\u884C\u3046\u6F14\u7B97\n     * @param\
    \ composite \u9045\u5EF6\u8A55\u4FA1\u306E\u5408\u6210\u3092\u884C\u3046\u6F14\
    \u7B97\n     * @param monoid_identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param operator_identity \u64CD\u4F5C\u30E2\u30CE\u30A4\u30C9\u306E\
    \u5358\u4F4D\u5143\n     * @param zero_index 0-index\u3068\u3057\u3066\u6271\u3044\
    \u305F\u3044\u304B (default = `false`)\n     */\n    LazySegmentTree(int size,\
    \ F merge, G mapping, H composite,\n    const Monoid &monoid_identity, const OperatorMonoid\
    \ &operator_identity, bool zero_index = false)\n    : f(merge), g(mapping), h(composite),\
    \ m1_(monoid_identity), om1_(operator_identity), zeroindex_(zero_index){\n   \
    \     size_ = 1;\n        while(size_ < size) size_ <<= 1;\n        offset_ =\
    \ size_ - 1;\n        data_.resize(2 * size_, m1_);\n        lazy_.resize(2 *\
    \ size_, om1_);\n        is_identity_.resize(2 * size_, true);\n    }\n\n    /**\n\
    \     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\
    \u3002\n     * @attention \u5FC5\u305A `Set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\
    \u5165\u3057\u3066\u304B\u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n   \
    \  */\n    void Build(){\n        for(int i = offset_; i >= 1; --i){\n       \
    \     data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n\
    \    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\
    \u5024\u3092\u4EE3\u5165\u3059\u308B\u3002\n     * @param index \u4EE3\u5165\u5148\
    \u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     * @param value \u4EE3\
    \u5165\u3059\u308B\u5024\n     */\n    void Set(int index, Monoid value){\n  \
    \      Validate(index + zeroindex_);\n        data_[offset_ + index + zeroindex_]\
    \ = value;\n    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u3092\u914D\u5217 `init_data` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n  \
    \   * @param init_data \u521D\u671F\u30C7\u30FC\u30BF\u306E\u914D\u5217\n    \
    \ * @param merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n    \
    \ * @param mapping \u9045\u5EF6\u8A55\u4FA1\u306E\u9069\u7528\u3092\u884C\u3046\
    \u6F14\u7B97\n     * @param composite \u9045\u5EF6\u8A55\u4FA1\u306E\u5408\u6210\
    \u3092\u884C\u3046\u6F14\u7B97\n     * @param monoid_identity \u30E2\u30CE\u30A4\
    \u30C9\u306E\u5358\u4F4D\u5143\n     * @param operator_identity \u64CD\u4F5C\u30E2\
    \u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param zero_index 0-index\u3068\
    \u3057\u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    LazySegmentTree(vector<Monoid>\
    \ &init_data, F merge, G mapping, H composite,\n    const Monoid &monoid_identity,\
    \ const OperatorMonoid &operator_identity, bool zero_index = false)\n    : f(merge),\
    \ g(mapping), h(composite), m1_(monoid_identity), om1_(operator_identity), zeroindex_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < (int)init_data.size()) size_ <<= 1;\n\
    \        offset_ = size_ - 1;\n        data_.resize(2 * size_, m1_);\n       \
    \ lazy_.resize(2 * size_, om1_);\n        is_identity_.resize(2 * size_, true);\n\
    \        for(int i = 0; i < (int)init_data.size(); ++i){\n            data_[size_\
    \ + i] = init_data[i];\n        }\n        Build();\n    }\n\n    /**\n     *\
    \ @brief \u534A\u958B\u533A\u9593 `[left, right)` \u306B\u5BFE\u3057\u3066\u533A\
    \u9593\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\n   \
    \  * @param left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n     * @param right\
    \ \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @param OP \u66F4\u65B0\u64CD\
    \u4F5C\n     */\n    void Update(int left, int right, OperatorMonoid operation){\n\
    \        Validate(left + zeroindex_);\n        Validate(right + zeroindex_ - 1);\n\
    \        RecursiveUpdate(left + zeroindex_, right + zeroindex_, operation, 1,\
    \ size_ + 1, 1);\n    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[left,\
    \ right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\
    \u884C\u3046\u3002\n     * @param left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\
    \n     * @param right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid Query(int left,\
    \ int right){\n        Validate(left + zeroindex_);\n        Validate(right +\
    \ zeroindex_ - 1);\n        return RecursiveQuery(left + zeroindex_, right + zeroindex_,\
    \ 1, size_ + 1, 1);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u756A\u53F7\
    \ `k` \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param k\
    \ \u53D6\u5F97\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     *\
    \ @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid get_value(int\
    \ k){\n        Validate(k + zeroindex_);\n        return Query(k, k + 1);\n  \
    \  }\n\n    Monoid operator[](const int &k){\n        return get_value(k);\n \
    \   }\n\n    private:\n    int size_, offset_, zeroindex_;\n    vector<Monoid>\
    \ data_;\n    vector<OperatorMonoid> lazy_;\n    vector<bool> is_identity_;\n\
    \    const F f;\n    const G g;\n    const H h;\n    const Monoid m1_;\n    const\
    \ OperatorMonoid om1_;\n\n    inline void Validate(int x){\n        assert(1 <=\
    \ x && x <= size_);\n    }\n\n    void Evaluate(int k){\n        if(is_identity_[k])\
    \ return;\n        if(k < size_){\n            lazy_[k * 2 + 0] = h(lazy_[k *\
    \ 2 + 0], lazy_[k]);\n            is_identity_[k * 2 + 0] = false;\n         \
    \   lazy_[k * 2 + 1] = h(lazy_[k * 2 + 1], lazy_[k]);\n            is_identity_[k\
    \ * 2 + 1] = false;\n        }\n        data_[k] = g(data_[k], lazy_[k]);\n  \
    \      lazy_[k] = om1_;\n        is_identity_[k] = true;\n    }\n\n    void RecursiveUpdate(int\
    \ ul, int ur, OperatorMonoid x, int left, int right, int cell){\n        Evaluate(cell);\n\
    \        if(ul <= left && right <= ur){\n            lazy_[cell] = h(lazy_[cell],\
    \ x);\n            is_identity_[cell] = false;\n            Evaluate(cell);\n\
    \        }\n        else if(ul < right && left < ur){\n            int mid = (left\
    \ + right) / 2;\n            RecursiveUpdate(ul, ur, x, left, mid, cell * 2 +\
    \ 0);\n            RecursiveUpdate(ul, ur, x, mid, right, cell * 2 + 1);\n   \
    \         data_[cell] = f(data_[cell * 2 + 0], data_[cell * 2 + 1]);\n       \
    \ }\n    }\n\n    Monoid RecursiveQuery(int ql, int qr, int left, int right, int\
    \ cell){\n        Evaluate(cell);\n        if(qr <= left || right <= ql){\n  \
    \          return m1_;\n        }\n        if(ql <= left && right <= qr){\n  \
    \          return data_[cell];\n        }\n        int mid = (left + right) /\
    \ 2;\n        Monoid ans_left = RecursiveQuery(ql, qr, left, mid, cell * 2 + 0);\n\
    \        Monoid ans_right = RecursiveQuery(ql, qr, mid, right, cell * 2 + 1);\n\
    \        return f(ans_left, ans_right);\n    }\n};\n"
  code: "/**\n * @file LazySegmentTree.hpp\n * @author log K (lX57)\n * @brief Lazy\
    \ Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n\
    \ * @version 2.0\n * @date 2023-10-02\n */\n\n#include \"../Common.hpp\"\n\ntemplate<typename\
    \ Monoid, typename OperatorMonoid = Monoid>\nclass LazySegmentTree{\n    public:\n\
    \    using F = function<Monoid(Monoid, Monoid)>;\n    using G = function<Monoid(Monoid,\
    \ OperatorMonoid)>;\n    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n\
    \n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\
    \u6570 `size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param size \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\n     * @param merge \u533A\
    \u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param mapping \u9045\
    \u5EF6\u8A55\u4FA1\u306E\u9069\u7528\u3092\u884C\u3046\u6F14\u7B97\n     * @param\
    \ composite \u9045\u5EF6\u8A55\u4FA1\u306E\u5408\u6210\u3092\u884C\u3046\u6F14\
    \u7B97\n     * @param monoid_identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param operator_identity \u64CD\u4F5C\u30E2\u30CE\u30A4\u30C9\u306E\
    \u5358\u4F4D\u5143\n     * @param zero_index 0-index\u3068\u3057\u3066\u6271\u3044\
    \u305F\u3044\u304B (default = `false`)\n     */\n    LazySegmentTree(int size,\
    \ F merge, G mapping, H composite,\n    const Monoid &monoid_identity, const OperatorMonoid\
    \ &operator_identity, bool zero_index = false)\n    : f(merge), g(mapping), h(composite),\
    \ m1_(monoid_identity), om1_(operator_identity), zeroindex_(zero_index){\n   \
    \     size_ = 1;\n        while(size_ < size) size_ <<= 1;\n        offset_ =\
    \ size_ - 1;\n        data_.resize(2 * size_, m1_);\n        lazy_.resize(2 *\
    \ size_, om1_);\n        is_identity_.resize(2 * size_, true);\n    }\n\n    /**\n\
    \     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\
    \u3002\n     * @attention \u5FC5\u305A `Set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\
    \u5165\u3057\u3066\u304B\u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n   \
    \  */\n    void Build(){\n        for(int i = offset_; i >= 1; --i){\n       \
    \     data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n\
    \    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\
    \u5024\u3092\u4EE3\u5165\u3059\u308B\u3002\n     * @param index \u4EE3\u5165\u5148\
    \u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     * @param value \u4EE3\
    \u5165\u3059\u308B\u5024\n     */\n    void Set(int index, Monoid value){\n  \
    \      Validate(index + zeroindex_);\n        data_[offset_ + index + zeroindex_]\
    \ = value;\n    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u3092\u914D\u5217 `init_data` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n  \
    \   * @param init_data \u521D\u671F\u30C7\u30FC\u30BF\u306E\u914D\u5217\n    \
    \ * @param merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n    \
    \ * @param mapping \u9045\u5EF6\u8A55\u4FA1\u306E\u9069\u7528\u3092\u884C\u3046\
    \u6F14\u7B97\n     * @param composite \u9045\u5EF6\u8A55\u4FA1\u306E\u5408\u6210\
    \u3092\u884C\u3046\u6F14\u7B97\n     * @param monoid_identity \u30E2\u30CE\u30A4\
    \u30C9\u306E\u5358\u4F4D\u5143\n     * @param operator_identity \u64CD\u4F5C\u30E2\
    \u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param zero_index 0-index\u3068\
    \u3057\u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    LazySegmentTree(vector<Monoid>\
    \ &init_data, F merge, G mapping, H composite,\n    const Monoid &monoid_identity,\
    \ const OperatorMonoid &operator_identity, bool zero_index = false)\n    : f(merge),\
    \ g(mapping), h(composite), m1_(monoid_identity), om1_(operator_identity), zeroindex_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < (int)init_data.size()) size_ <<= 1;\n\
    \        offset_ = size_ - 1;\n        data_.resize(2 * size_, m1_);\n       \
    \ lazy_.resize(2 * size_, om1_);\n        is_identity_.resize(2 * size_, true);\n\
    \        for(int i = 0; i < (int)init_data.size(); ++i){\n            data_[size_\
    \ + i] = init_data[i];\n        }\n        Build();\n    }\n\n    /**\n     *\
    \ @brief \u534A\u958B\u533A\u9593 `[left, right)` \u306B\u5BFE\u3057\u3066\u533A\
    \u9593\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\n   \
    \  * @param left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n     * @param right\
    \ \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @param OP \u66F4\u65B0\u64CD\
    \u4F5C\n     */\n    void Update(int left, int right, OperatorMonoid operation){\n\
    \        Validate(left + zeroindex_);\n        Validate(right + zeroindex_ - 1);\n\
    \        RecursiveUpdate(left + zeroindex_, right + zeroindex_, operation, 1,\
    \ size_ + 1, 1);\n    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[left,\
    \ right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\
    \u884C\u3046\u3002\n     * @param left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\
    \n     * @param right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid Query(int left,\
    \ int right){\n        Validate(left + zeroindex_);\n        Validate(right +\
    \ zeroindex_ - 1);\n        return RecursiveQuery(left + zeroindex_, right + zeroindex_,\
    \ 1, size_ + 1, 1);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u756A\u53F7\
    \ `k` \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param k\
    \ \u53D6\u5F97\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     *\
    \ @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid get_value(int\
    \ k){\n        Validate(k + zeroindex_);\n        return Query(k, k + 1);\n  \
    \  }\n\n    Monoid operator[](const int &k){\n        return get_value(k);\n \
    \   }\n\n    private:\n    int size_, offset_, zeroindex_;\n    vector<Monoid>\
    \ data_;\n    vector<OperatorMonoid> lazy_;\n    vector<bool> is_identity_;\n\
    \    const F f;\n    const G g;\n    const H h;\n    const Monoid m1_;\n    const\
    \ OperatorMonoid om1_;\n\n    inline void Validate(int x){\n        assert(1 <=\
    \ x && x <= size_);\n    }\n\n    void Evaluate(int k){\n        if(is_identity_[k])\
    \ return;\n        if(k < size_){\n            lazy_[k * 2 + 0] = h(lazy_[k *\
    \ 2 + 0], lazy_[k]);\n            is_identity_[k * 2 + 0] = false;\n         \
    \   lazy_[k * 2 + 1] = h(lazy_[k * 2 + 1], lazy_[k]);\n            is_identity_[k\
    \ * 2 + 1] = false;\n        }\n        data_[k] = g(data_[k], lazy_[k]);\n  \
    \      lazy_[k] = om1_;\n        is_identity_[k] = true;\n    }\n\n    void RecursiveUpdate(int\
    \ ul, int ur, OperatorMonoid x, int left, int right, int cell){\n        Evaluate(cell);\n\
    \        if(ul <= left && right <= ur){\n            lazy_[cell] = h(lazy_[cell],\
    \ x);\n            is_identity_[cell] = false;\n            Evaluate(cell);\n\
    \        }\n        else if(ul < right && left < ur){\n            int mid = (left\
    \ + right) / 2;\n            RecursiveUpdate(ul, ur, x, left, mid, cell * 2 +\
    \ 0);\n            RecursiveUpdate(ul, ur, x, mid, right, cell * 2 + 1);\n   \
    \         data_[cell] = f(data_[cell * 2 + 0], data_[cell * 2 + 1]);\n       \
    \ }\n    }\n\n    Monoid RecursiveQuery(int ql, int qr, int left, int right, int\
    \ cell){\n        Evaluate(cell);\n        if(qr <= left || right <= ql){\n  \
    \          return m1_;\n        }\n        if(ql <= left && right <= qr){\n  \
    \          return data_[cell];\n        }\n        int mid = (left + right) /\
    \ 2;\n        Monoid ans_left = RecursiveQuery(ql, qr, left, mid, cell * 2 + 0);\n\
    \        Monoid ans_right = RecursiveQuery(ql, qr, mid, right, cell * 2 + 1);\n\
    \        return f(ans_left, ans_right);\n    }\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2024-11-29 17:05:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/LC-RangeAffineRangeSum.test.cpp
documentation_of: Library/DataStructure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/LazySegmentTree.hpp
- /library/Library/DataStructure/LazySegmentTree.hpp.html
title: "Lazy Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\
  \u6728"
---
