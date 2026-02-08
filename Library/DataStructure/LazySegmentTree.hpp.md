---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-RangeAffineRangeSum.test.cpp
    title: verify/LC-RangeAffineRangeSum.test.cpp
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
    \ 1;\n#line 2 \"Library/DataStructure/LazySegmentTree.hpp\"\n\ntemplate<typename\
    \ Monoid, typename OperatorMonoid = Monoid>\nclass LazySegmentTree{\n    public:\n\
    \    using F = function<Monoid(Monoid, Monoid)>;\n    using G = function<Monoid(Monoid,\
    \ OperatorMonoid)>;\n    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n\
    \n    LazySegmentTree(int size, F merge, G mapping, H composite,\n    const Monoid\
    \ &monoid_identity, const OperatorMonoid &operator_identity, bool zero_index =\
    \ false)\n    : f(merge), g(mapping), h(composite), m1_(monoid_identity), om1_(operator_identity),\
    \ zeroindex_(zero_index){\n        size_ = 1;\n        while(size_ < size) size_\
    \ <<= 1;\n        offset_ = size_ - 1;\n        data_.resize(2 * size_, m1_);\n\
    \        lazy_.resize(2 * size_, om1_);\n        is_identity_.resize(2 * size_,\
    \ true);\n    }\n\n\n    void Build(){\n        for(int i = offset_; i >= 1; --i){\n\
    \            data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n        }\n  \
    \  }\n\n    void Set(int index, Monoid value){\n        Validate(index + zeroindex_);\n\
    \        data_[offset_ + index + zeroindex_] = value;\n    }\n\n    LazySegmentTree(vector<Monoid>\
    \ &init_data, F merge, G mapping, H composite,\n    const Monoid &monoid_identity,\
    \ const OperatorMonoid &operator_identity, bool zero_index = false)\n    : f(merge),\
    \ g(mapping), h(composite), m1_(monoid_identity), om1_(operator_identity), zeroindex_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < (int)init_data.size()) size_ <<= 1;\n\
    \        offset_ = size_ - 1;\n        data_.resize(2 * size_, m1_);\n       \
    \ lazy_.resize(2 * size_, om1_);\n        is_identity_.resize(2 * size_, true);\n\
    \        for(int i = 0; i < (int)init_data.size(); ++i){\n            data_[size_\
    \ + i] = init_data[i];\n        }\n        Build();\n    }\n\n    void Update(int\
    \ left, int right, OperatorMonoid operation){\n        Validate(left + zeroindex_);\n\
    \        Validate(right + zeroindex_ - 1);\n        RecursiveUpdate(left + zeroindex_,\
    \ right + zeroindex_, operation, 1, size_ + 1, 1);\n    }\n\n    Monoid Product(int\
    \ left, int right){\n        Validate(left + zeroindex_);\n        Validate(right\
    \ + zeroindex_ - 1);\n        return RecursiveProduct(left + zeroindex_, right\
    \ + zeroindex_, 1, size_ + 1, 1);\n    }\n\n    Monoid GetValue(int k){\n    \
    \    Validate(k + zeroindex_);\n        return Product(k, k + 1);\n    }\n\n \
    \   Monoid operator[](const int &k){\n        return GetValue(k);\n    }\n\n \
    \   private:\n    int size_, offset_, zeroindex_;\n    vector<Monoid> data_;\n\
    \    vector<OperatorMonoid> lazy_;\n    vector<bool> is_identity_;\n    const\
    \ F f;\n    const G g;\n    const H h;\n    const Monoid m1_;\n    const OperatorMonoid\
    \ om1_;\n\n    inline void Validate(int x){\n        assert(1 <= x && x <= size_);\n\
    \    }\n\n    void Evaluate(int k){\n        if(is_identity_[k]) return;\n   \
    \     if(k < size_){\n            lazy_[k * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);\n\
    \            is_identity_[k * 2 + 0] = false;\n            lazy_[k * 2 + 1] =\
    \ h(lazy_[k * 2 + 1], lazy_[k]);\n            is_identity_[k * 2 + 1] = false;\n\
    \        }\n        data_[k] = g(data_[k], lazy_[k]);\n        lazy_[k] = om1_;\n\
    \        is_identity_[k] = true;\n    }\n\n    void RecursiveUpdate(int ul, int\
    \ ur, OperatorMonoid x, int left, int right, int cell){\n        Evaluate(cell);\n\
    \        if(ul <= left && right <= ur){\n            lazy_[cell] = h(lazy_[cell],\
    \ x);\n            is_identity_[cell] = false;\n            Evaluate(cell);\n\
    \        }\n        else if(ul < right && left < ur){\n            int mid = (left\
    \ + right) / 2;\n            RecursiveUpdate(ul, ur, x, left, mid, cell * 2 +\
    \ 0);\n            RecursiveUpdate(ul, ur, x, mid, right, cell * 2 + 1);\n   \
    \         data_[cell] = f(data_[cell * 2 + 0], data_[cell * 2 + 1]);\n       \
    \ }\n    }\n\n    Monoid RecursiveProduct(int ql, int qr, int left, int right,\
    \ int cell){\n        Evaluate(cell);\n        if(qr <= left || right <= ql){\n\
    \            return m1_;\n        }\n        if(ql <= left && right <= qr){\n\
    \            return data_[cell];\n        }\n        int mid = (left + right)\
    \ / 2;\n        Monoid ans_left = RecursiveProduct(ql, qr, left, mid, cell * 2\
    \ + 0);\n        Monoid ans_right = RecursiveProduct(ql, qr, mid, right, cell\
    \ * 2 + 1);\n        return f(ans_left, ans_right);\n    }\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename Monoid, typename OperatorMonoid\
    \ = Monoid>\nclass LazySegmentTree{\n    public:\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n    using G = function<Monoid(Monoid, OperatorMonoid)>;\n    using\
    \ H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n\n    LazySegmentTree(int\
    \ size, F merge, G mapping, H composite,\n    const Monoid &monoid_identity, const\
    \ OperatorMonoid &operator_identity, bool zero_index = false)\n    : f(merge),\
    \ g(mapping), h(composite), m1_(monoid_identity), om1_(operator_identity), zeroindex_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < size) size_ <<= 1;\n        offset_\
    \ = size_ - 1;\n        data_.resize(2 * size_, m1_);\n        lazy_.resize(2\
    \ * size_, om1_);\n        is_identity_.resize(2 * size_, true);\n    }\n\n\n\
    \    void Build(){\n        for(int i = offset_; i >= 1; --i){\n            data_[i]\
    \ = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n    void Set(int\
    \ index, Monoid value){\n        Validate(index + zeroindex_);\n        data_[offset_\
    \ + index + zeroindex_] = value;\n    }\n\n    LazySegmentTree(vector<Monoid>\
    \ &init_data, F merge, G mapping, H composite,\n    const Monoid &monoid_identity,\
    \ const OperatorMonoid &operator_identity, bool zero_index = false)\n    : f(merge),\
    \ g(mapping), h(composite), m1_(monoid_identity), om1_(operator_identity), zeroindex_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < (int)init_data.size()) size_ <<= 1;\n\
    \        offset_ = size_ - 1;\n        data_.resize(2 * size_, m1_);\n       \
    \ lazy_.resize(2 * size_, om1_);\n        is_identity_.resize(2 * size_, true);\n\
    \        for(int i = 0; i < (int)init_data.size(); ++i){\n            data_[size_\
    \ + i] = init_data[i];\n        }\n        Build();\n    }\n\n    void Update(int\
    \ left, int right, OperatorMonoid operation){\n        Validate(left + zeroindex_);\n\
    \        Validate(right + zeroindex_ - 1);\n        RecursiveUpdate(left + zeroindex_,\
    \ right + zeroindex_, operation, 1, size_ + 1, 1);\n    }\n\n    Monoid Product(int\
    \ left, int right){\n        Validate(left + zeroindex_);\n        Validate(right\
    \ + zeroindex_ - 1);\n        return RecursiveProduct(left + zeroindex_, right\
    \ + zeroindex_, 1, size_ + 1, 1);\n    }\n\n    Monoid GetValue(int k){\n    \
    \    Validate(k + zeroindex_);\n        return Product(k, k + 1);\n    }\n\n \
    \   Monoid operator[](const int &k){\n        return GetValue(k);\n    }\n\n \
    \   private:\n    int size_, offset_, zeroindex_;\n    vector<Monoid> data_;\n\
    \    vector<OperatorMonoid> lazy_;\n    vector<bool> is_identity_;\n    const\
    \ F f;\n    const G g;\n    const H h;\n    const Monoid m1_;\n    const OperatorMonoid\
    \ om1_;\n\n    inline void Validate(int x){\n        assert(1 <= x && x <= size_);\n\
    \    }\n\n    void Evaluate(int k){\n        if(is_identity_[k]) return;\n   \
    \     if(k < size_){\n            lazy_[k * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);\n\
    \            is_identity_[k * 2 + 0] = false;\n            lazy_[k * 2 + 1] =\
    \ h(lazy_[k * 2 + 1], lazy_[k]);\n            is_identity_[k * 2 + 1] = false;\n\
    \        }\n        data_[k] = g(data_[k], lazy_[k]);\n        lazy_[k] = om1_;\n\
    \        is_identity_[k] = true;\n    }\n\n    void RecursiveUpdate(int ul, int\
    \ ur, OperatorMonoid x, int left, int right, int cell){\n        Evaluate(cell);\n\
    \        if(ul <= left && right <= ur){\n            lazy_[cell] = h(lazy_[cell],\
    \ x);\n            is_identity_[cell] = false;\n            Evaluate(cell);\n\
    \        }\n        else if(ul < right && left < ur){\n            int mid = (left\
    \ + right) / 2;\n            RecursiveUpdate(ul, ur, x, left, mid, cell * 2 +\
    \ 0);\n            RecursiveUpdate(ul, ur, x, mid, right, cell * 2 + 1);\n   \
    \         data_[cell] = f(data_[cell * 2 + 0], data_[cell * 2 + 1]);\n       \
    \ }\n    }\n\n    Monoid RecursiveProduct(int ql, int qr, int left, int right,\
    \ int cell){\n        Evaluate(cell);\n        if(qr <= left || right <= ql){\n\
    \            return m1_;\n        }\n        if(ql <= left && right <= qr){\n\
    \            return data_[cell];\n        }\n        int mid = (left + right)\
    \ / 2;\n        Monoid ans_left = RecursiveProduct(ql, qr, left, mid, cell * 2\
    \ + 0);\n        Monoid ans_right = RecursiveProduct(ql, qr, mid, right, cell\
    \ * 2 + 1);\n        return f(ans_left, ans_right);\n    }\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2026-02-08 19:36:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-RangeAffineRangeSum.test.cpp
documentation_of: Library/DataStructure/LazySegmentTree.hpp
layout: document
title: "Lazy Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\
  \u6728"
---

# Lazy Segment Tree - 遅延評価セグメント木

長さ $N$ の数列 $A = (A_1, \dots, A_N)$ に対し、区間更新・区間取得クエリを効率的に行うことができるデータ構造です。

数列 $A$ の要素はモノイド $M$ である必要があり、更新操作もモノイド $O$ である必要があります。以下、モノイドの単位元を $e_M$、操作モノイドの単位元を $e_O$ とします。

## Function

### Constructor

```
(1) LazySegmentTree(int size, F merge, G mapping, H composite,
                    const Monoid &monoid_identity, const OperatorMonoid &operator_identity, 
                    bool zero_index = false)
(2) LazySegmentTree(vector<Monoid> &init_data, F merge, G mapping, H composite,
                    const Monoid &monoid_identity, const OperatorMonoid &operator_identity, 
                    bool zero_index = false)
```

- (1) セグメント木の数列 $A$ を長さ $n$ で初期化します。初期値はすべて $e_M$ です。
- (2) セグメント木を数列 $A$ で初期化します。
- `merge` には $2$ つのモノイドに対する二項演算 $\oplus : M \times M \rightarrow M$ を渡します。
    - 区間最小値 : `[](int x, int y){return min(x, y);}`
    - 区間総和 : `[](int x, int y){return x + y;}`
- `mapping` には遅延評価を適用する演算 $f : M \times O \rightarrow M$ を渡します。
    - 区間加算 : `[](int x, int y){return x + y;}`
    - 区間代入 : `[](int x, int y){return y;}`
- `composite` には遅延評価を合成する演算 $\odot : O \times O \rightarrow O$ を渡します。
    - 区間加算 : `[](int x, int y){return x + y;}`
    - 区間代入 : `[](int x, int y){return y;}`
- `monoid_identity` にはモノイド $M$ の単位元 $e_M$ を渡します。
- `operator_identity` には操作モノイド $O$ の単位元 $e_O$ を渡します。
- `zero_index` に `true` を指定すると、セグメント木にアクセスする添え字を 0-index でアクセスすることができます。デフォルトでは 1-index です。
    - 本ドキュメントでは添え字に関する制約は 1-index で示します。

**制約**

- (1) $1 \le n \le 10^6$
- (2) $1 \le \lvert A \rvert \le 10^6$
- `merge` は $M \times M \rightarrow M$ の関数
- `mapping` は $M \times O \rightarrow M$ の関数
- `composite` は $O \times O \rightarrow O$ の関数
- $e_M$ は $M$ の単位元
- $e_O$ は $O$ の単位元

**計算量**

- $\textrm{O}(n)$

---

### Set

```
void Set(int index, Monoid value)
```

- $A_i$ に初期値 $v$ を代入します。（`index` が $i$ に対応）
- `Update()` と異なり、**区間更新ではない**点に注意してください。
- `Build()` とセットで用いることを想定しています。すべての初期値を代入したら、`Build()` を呼び出してください。
- すべての要素に初期値が設定されている場合は、コンストラクタ(2)の方法を検討してください。

**制約**

- $1 \le i \le n$
- $v \in M$

**計算量**

- $\textrm{O}(1)$

---

### Build

```
void Build()
```

- セグメント木の構築を行います。
- `Set()` とセットで用いることを想定しています。この関数を呼び出す前に、`Set()` を用いてすべての初期値を代入してください。
- すべての要素に初期値が設定されている場合は、コンストラクタ(2)の方法を検討してください。

**計算量**

- $\textrm{O}(n)$

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
Monoid Product(int left, int right)
```

- 半開区間 $[l, r)$ に対して区間取得クエリを実行します。（`left` が $l$、`right` が $r$ に対応）

**制約**

- $1 \le l \le n$
- $l \le r \le n + 1$

**計算量**

- $\textrm{O}(\log n)$

---

### GetValue

```
Monoid GetValue(int k)
```

- $A_k$ を取得します。

**制約**

- $1 \le k \le n$

**計算量**

- $\textrm{O}(\log n)$

---

### operator[]

```
Monoid operator[](const int &k)
```

- $A_k$ を取得します。`GetValue(k)` と同等です。

**制約**

- $1 \le k \le n$

**計算量**

- $\textrm{O}(\log n)$

---
