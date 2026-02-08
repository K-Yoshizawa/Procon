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
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 2 \"Library/DataStructure/DualSegmentTree.hpp\"\n\ntemplate<typename\
    \ OperatorMonoid>\nclass DualSegmentTree{\n    public:\n    using H = function<OperatorMonoid(OperatorMonoid,\
    \ OperatorMonoid)>;\n    \n    DualSegmentTree(int size, H composite, const OperatorMonoid\
    \ &operator_identity, bool zero_index = false)\n    : h(composite), om1_(operator_identity),\
    \ zeroindex_(zero_index){\n        size_ = 1;\n        while(size_ < size) size_\
    \ <<= 1;\n        offset_ = size_ - 1;\n        lazy_.resize(2 * size_, om1_);\n\
    \        is_identity_.resize(2 * size_, true);\n    }\n\n    void Set(int index,\
    \ OperatorMonoid value){\n        Validate(index + zeroindex_);\n        lazy_[offset_\
    \ + index + zeroindex_] = value;\n    }\n\n    void Update(int left, int right,\
    \ OperatorMonoid operation){\n        Validate(left + zeroindex_);\n        Validate(right\
    \ + zeroindex_ - 1);\n        RecursiveUpdate(left + zeroindex_, right + zeroindex_,\
    \ operation, 1, size_ + 1, 1);\n    }\n\n    OperatorMonoid Product(int index){\n\
    \        Validate(index + zeroindex_);\n        return RecursiveProduct(index\
    \ + zeroindex_, 1, size_ + 1, 1);\n    }\n\n    private:\n    int size_, offset_,\
    \ zeroindex_;\n    vector<OperatorMonoid> lazy_;\n    vector<bool> is_identity_;\n\
    \    const H h;\n    const OperatorMonoid om1_;\n\n    inline void Validate(int\
    \ x){\n        assert(1 <= x && x <= size_);\n    }\n\n    void Evaluate(int k){\n\
    \        if(is_identity_[k]) return;\n        if(k < size_){\n            lazy_[k\
    \ * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);\n            is_identity_[k * 2 +\
    \ 0] = false;\n            lazy_[k * 2 + 1] = h(lazy_[k * 2 + 1], lazy_[k]);\n\
    \            is_identity_[k * 2 + 1] = false;\n            lazy_[k] = om1_;\n\
    \            is_identity_[k] = true;\n        }\n    }\n\n    void RecursiveUpdate(int\
    \ ul, int ur, OperatorMonoid x, int left, int right, int cell){\n        Evaluate(cell);\n\
    \        if(ul <= left && right <= ur){\n            lazy_[cell] = h(lazy_[cell],\
    \ x);\n            is_identity_[cell] = false;\n            Evaluate(cell);\n\
    \        }\n        else if(ul < right && left < ur){\n            int mid = (left\
    \ + right) / 2;\n            RecursiveUpdate(ul, ur, x, left, mid, cell * 2 +\
    \ 0);\n            RecursiveUpdate(ul, ur, x, mid, right, cell * 2 + 1);\n   \
    \     }\n    }\n    \n    OperatorMonoid RecursiveProduct(int q, int left, int\
    \ right, int cell){\n        Evaluate(cell);\n        if(q == left && right -\
    \ left == 1) return lazy_[cell];\n        int mid = (left + right) / 2;\n    \
    \    if(q < mid) return RecursiveProduct(q, left, mid, cell * 2 + 0);\n      \
    \  else return RecursiveProduct(q, mid, right, cell * 2 + 1);\n    }\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename OperatorMonoid>\nclass DualSegmentTree{\n\
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
  timestamp: '2026-02-08 19:12:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-RangeAffinePointGet.test.cpp
documentation_of: Library/DataStructure/DualSegmentTree.hpp
layout: document
title: "Dual Segment Tree - \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

# Dual Segment Tree - 双対セグメント木

長さ $N$ の数列 $A = (A_1, \dots, A_N)$ に対し、区間更新・一点取得クエリを効率的に行うことができるデータ構造です。

更新操作はモノイド $O$ である必要があります。以下、操作モノイドの単位元を $e_O$ とします。

## Function

### Constructor

```
DualSegmentTree(int size, H composite, const OperatorMonoid &operator_identity, bool zero_index = false)
```

- セグメント木の数列 $A$ を長さ $n$ で初期化します。初期値はすべて $e_O$ です。
- `composite` には遅延評価を合成する演算 $\odot : O \times O \rightarrow O$ を渡します。
    - 区間加算 : `[](int x, int y){return x + y;}`
    - 区間代入 : `[](int x, int y){return y;}`
- `operator_identity` には操作モノイド $O$ の単位元 $e_O$ を渡します。
- `zero_index` に `true` を指定すると、セグメント木にアクセスする添え字を 0-index でアクセスすることができます。デフォルトでは 1-index です。
    - 本ドキュメントでは添え字に関する制約は 1-index で示します。

**制約**

- $1 \le n \le 10^6$
- `composite` は $O \times O \rightarrow O$ の関数
- $e_O$ は $O$ の単位元

**計算量**

- $\textrm{O}(n)$

---

### Set

```
void Set(int index, OperatorMonoid value)
```

- $A_i$ に初期値 $v$ を代入します。（`index` が $i$ に対応）
- 初期値を設定するために使用します。

**制約**

- $1 \le i \le n$
- $v \in O$

**計算量**

- $\textrm{O}(1)$

---

### Update

```
void Update(int left, int right, OperatorMonoid operation)
```

- 半開区間 $[l, r)$ に対して区間更新クエリを実行します。（`left` が $l$、`right` が $r$ に対応）
- 区間内の各要素に対して `operation` を適用します。

**制約**

- $1 \le l \le n$
- $l \le r \le n + 1$
- $operation \in O$

**計算量**

- $\textrm{O}(\log n)$

---

### Product

```
OperatorMonoid Product(int index)
```

- $A_i$ を取得します。（`index` が $i$ に対応）
- これまでに適用されたすべての操作の合成結果を返します。

**制約**

- $1 \le i \le n$

**計算量**

- $\textrm{O}(\log n)$

---
