---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-G.test.cpp
    title: verify/AOJ-DSL-2-G.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-RangeAddRangeMin.test.cpp
    title: verify/LC-RangeAddRangeMin.test.cpp
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
    \n    LazySegmentTree(\n        vector<Monoid> &A,\n        F merge,\n       \
    \ G mapping,\n        H composite,\n        const Monoid &e_m,\n        const\
    \ OperatorMonoid &e_o,\n        bool zero_index = false\n    ) : f(merge), g(mapping),\
    \ h(composite), m1_(e_m), om1_(e_o), zero_index_(zero_index){\n        size_ =\
    \ 1;\n        while(size_ < (int)A.size()) size_ <<= 1;\n        offset_ = size_\
    \ - 1;\n        data_.resize(2 * size_, m1_);\n        lazy_.resize(2 * size_,\
    \ om1_);\n        is_identity_.resize(2 * size_, true);\n        for(int i = 0;\
    \ i < (int)A.size(); ++i){\n            data_[size_ + i] = A[i];\n        }\n\
    \        for(int i = offset_; i >= 1; --i){\n            data_[i] = f(data_[i\
    \ * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n    void Apply(int l, int\
    \ r, OperatorMonoid x){\n        Validate(l + zero_index_);\n        Validate(r\
    \ + zero_index_ - 1);\n        RecursiveApply(l + zero_index_, r + zero_index_,\
    \ x, 1, size_ + 1, 1);\n    }\n\n    Monoid Fold(int l, int r){\n        Validate(l\
    \ + zero_index_);\n        Validate(r + zero_index_ - 1);\n        return RecursiveFold(l\
    \ + zero_index_, r + zero_index_, 1, size_ + 1, 1);\n    }\n\n    Monoid operator[](const\
    \ int &k){\n        Validate(k + zero_index_);\n        return Fold(k, k + 1);\n\
    \    }\n\n    private:\n    int size_, offset_, zero_index_;\n    vector<Monoid>\
    \ data_;\n    vector<OperatorMonoid> lazy_;\n    vector<bool> is_identity_;\n\
    \    const F f;\n    const G g;\n    const H h;\n    const Monoid m1_;\n    const\
    \ OperatorMonoid om1_;\n\n    inline void Validate(int x){\n        assert(1 <=\
    \ x && x <= size_);\n    }\n\n    void Evaluate(int k){\n        if(is_identity_[k])\
    \ return;\n        if(k < size_){\n            lazy_[k * 2 + 0] = h(lazy_[k *\
    \ 2 + 0], lazy_[k]);\n            is_identity_[k * 2 + 0] = false;\n         \
    \   lazy_[k * 2 + 1] = h(lazy_[k * 2 + 1], lazy_[k]);\n            is_identity_[k\
    \ * 2 + 1] = false;\n        }\n        data_[k] = g(data_[k], lazy_[k]);\n  \
    \      lazy_[k] = om1_;\n        is_identity_[k] = true;\n    }\n\n    void RecursiveApply(int\
    \ ul, int ur, OperatorMonoid x, int left, int right, int cell){\n        Evaluate(cell);\n\
    \        if(ul <= left && right <= ur){\n            lazy_[cell] = h(lazy_[cell],\
    \ x);\n            is_identity_[cell] = false;\n            Evaluate(cell);\n\
    \        }\n        else if(ul < right && left < ur){\n            int mid = (left\
    \ + right) / 2;\n            RecursiveApply(ul, ur, x, left, mid, cell * 2 + 0);\n\
    \            RecursiveApply(ul, ur, x, mid, right, cell * 2 + 1);\n          \
    \  data_[cell] = f(data_[cell * 2 + 0], data_[cell * 2 + 1]);\n        }\n   \
    \ }\n\n    Monoid RecursiveFold(int ql, int qr, int left, int right, int cell){\n\
    \        Evaluate(cell);\n        if(qr <= left || right <= ql){\n           \
    \ return m1_;\n        }\n        if(ql <= left && right <= qr){\n           \
    \ return data_[cell];\n        }\n        int mid = (left + right) / 2;\n    \
    \    Monoid ans_left = RecursiveFold(ql, qr, left, mid, cell * 2 + 0);\n     \
    \   Monoid ans_right = RecursiveFold(ql, qr, mid, right, cell * 2 + 1);\n    \
    \    return f(ans_left, ans_right);\n    }\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename Monoid, typename OperatorMonoid\
    \ = Monoid>\nclass LazySegmentTree{\n    public:\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n    using G = function<Monoid(Monoid, OperatorMonoid)>;\n    using\
    \ H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n\n    LazySegmentTree(\n\
    \        vector<Monoid> &A,\n        F merge,\n        G mapping,\n        H composite,\n\
    \        const Monoid &e_m,\n        const OperatorMonoid &e_o,\n        bool\
    \ zero_index = false\n    ) : f(merge), g(mapping), h(composite), m1_(e_m), om1_(e_o),\
    \ zero_index_(zero_index){\n        size_ = 1;\n        while(size_ < (int)A.size())\
    \ size_ <<= 1;\n        offset_ = size_ - 1;\n        data_.resize(2 * size_,\
    \ m1_);\n        lazy_.resize(2 * size_, om1_);\n        is_identity_.resize(2\
    \ * size_, true);\n        for(int i = 0; i < (int)A.size(); ++i){\n         \
    \   data_[size_ + i] = A[i];\n        }\n        for(int i = offset_; i >= 1;\
    \ --i){\n            data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n     \
    \   }\n    }\n\n    void Apply(int l, int r, OperatorMonoid x){\n        Validate(l\
    \ + zero_index_);\n        Validate(r + zero_index_ - 1);\n        RecursiveApply(l\
    \ + zero_index_, r + zero_index_, x, 1, size_ + 1, 1);\n    }\n\n    Monoid Fold(int\
    \ l, int r){\n        Validate(l + zero_index_);\n        Validate(r + zero_index_\
    \ - 1);\n        return RecursiveFold(l + zero_index_, r + zero_index_, 1, size_\
    \ + 1, 1);\n    }\n\n    Monoid operator[](const int &k){\n        Validate(k\
    \ + zero_index_);\n        return Fold(k, k + 1);\n    }\n\n    private:\n   \
    \ int size_, offset_, zero_index_;\n    vector<Monoid> data_;\n    vector<OperatorMonoid>\
    \ lazy_;\n    vector<bool> is_identity_;\n    const F f;\n    const G g;\n   \
    \ const H h;\n    const Monoid m1_;\n    const OperatorMonoid om1_;\n\n    inline\
    \ void Validate(int x){\n        assert(1 <= x && x <= size_);\n    }\n\n    void\
    \ Evaluate(int k){\n        if(is_identity_[k]) return;\n        if(k < size_){\n\
    \            lazy_[k * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);\n            is_identity_[k\
    \ * 2 + 0] = false;\n            lazy_[k * 2 + 1] = h(lazy_[k * 2 + 1], lazy_[k]);\n\
    \            is_identity_[k * 2 + 1] = false;\n        }\n        data_[k] = g(data_[k],\
    \ lazy_[k]);\n        lazy_[k] = om1_;\n        is_identity_[k] = true;\n    }\n\
    \n    void RecursiveApply(int ul, int ur, OperatorMonoid x, int left, int right,\
    \ int cell){\n        Evaluate(cell);\n        if(ul <= left && right <= ur){\n\
    \            lazy_[cell] = h(lazy_[cell], x);\n            is_identity_[cell]\
    \ = false;\n            Evaluate(cell);\n        }\n        else if(ul < right\
    \ && left < ur){\n            int mid = (left + right) / 2;\n            RecursiveApply(ul,\
    \ ur, x, left, mid, cell * 2 + 0);\n            RecursiveApply(ul, ur, x, mid,\
    \ right, cell * 2 + 1);\n            data_[cell] = f(data_[cell * 2 + 0], data_[cell\
    \ * 2 + 1]);\n        }\n    }\n\n    Monoid RecursiveFold(int ql, int qr, int\
    \ left, int right, int cell){\n        Evaluate(cell);\n        if(qr <= left\
    \ || right <= ql){\n            return m1_;\n        }\n        if(ql <= left\
    \ && right <= qr){\n            return data_[cell];\n        }\n        int mid\
    \ = (left + right) / 2;\n        Monoid ans_left = RecursiveFold(ql, qr, left,\
    \ mid, cell * 2 + 0);\n        Monoid ans_right = RecursiveFold(ql, qr, mid, right,\
    \ cell * 2 + 1);\n        return f(ans_left, ans_right);\n    }\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2026-02-12 01:36:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-RangeAddRangeMin.test.cpp
  - verify/AOJ-DSL-2-G.test.cpp
  - verify/LC-RangeAffineRangeSum.test.cpp
documentation_of: Library/DataStructure/LazySegmentTree.hpp
layout: document
title: "Lazy Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\
  \u6728"
---

# Lazy Segment Tree - 遅延評価セグメント木

長さ $N$ の列 $A = (A_1, \dots, A_N)$ に対し、区間更新・区間取得クエリを効率的に行うことができるデータ構造です。

数列 $A$ の要素はモノイド $M$ である必要があり、更新操作もモノイド $O$ である必要があります。以下、モノイドの単位元を $e_M$、操作モノイドの単位元を $e_O$ とします。

## Function

### Constructor

```
LazySegmentTree(
    vector<Monoid> &A,
    F merge,
    G mapping,
    H composite,
    const Monoid &e_m,
    const OperatorMonoid &e_o,
    bool zero_index = false
)
```

- セグメント木を配列 $A$ で初期化します。以降、セグメント木の長さを $N = \lvert A \rvert$ で表します。
- `merge` には $2$ つのモノイドに対する二項演算 $\oplus : M \times M \rightarrow M$ を渡します。
    - 本ドキュメントでは `merge` の計算量を定数時間としています。
- `mapping` には遅延評価を適用する二項演算 $\otimes : M \times O \rightarrow M$ を渡します。
    - 本ドキュメントでは `mapping` の計算量を定数時間としています。
- `composite` には遅延評価を合成する二項演算 $\odot : O \times O \rightarrow O$ を渡します。
    - 本ドキュメントでは `composite` の計算量を定数時間としています。
- `e_m` にはモノイド $M$ の単位元 $e_M$ を渡します。
- `e_o` には操作モノイド $O$ の単位元 $e_O$ を渡します。
- `zero_index` に `true` を指定すると、セグメント木にアクセスする添え字を 0-index でアクセスすることができます。デフォルトでは 1-index です。
    - 本ドキュメントでは添え字に関する制約は 1-index で示します。

**制約**

- $1 \le N \le 10^6$
- $A_i \in M$
- `merge` は二項演算 $\oplus : M \times M \rightarrow M$ を行う関数
- `mapping` は二項演算 $\otimes : M \times O \rightarrow M$ を行う関数
- `composite` は二項演算 $\odot : O \times O \rightarrow O$ を行う関数
- $e_M$ は $M$ の単位元
- $e_O$ は $O$ の単位元

**計算量**

- $\textrm{O}(N)$

---

### Apply

```
void Apply(int l, int r, OperatorMonoid x)
```

- 半開区間 $[l, r)$ に対して区間更新クエリを実行します。
- すなわち、$l \le i \lt r$ について $A_i \leftarrow A_i \otimes x$ を行います。

**制約**

- $1 \le l \le N$
- $l \le r \le N + 1$
- $x \in O$

**計算量**

- $\textrm{O}(\log N)$

---

### Fold

```
Monoid Fold(int l, int r)
```

- 半開区間 $[l, r)$ に対して区間取得クエリを実行します。
- すなわち、$A_l \oplus A_{l+1} \oplus \dots \oplus A_{r - 1}$ を計算した結果を返します。

**制約**

- $1 \le l \le N$
- $l \le r \le N + 1$

**計算量**

- $\textrm{O}(\log N)$

---

### operator[]

```
Monoid operator[](const int &k)
```

- $A_k$ を取得します。

**制約**

- $1 \le k \le N$

**計算量**

- $\textrm{O}(\log N)$

---
