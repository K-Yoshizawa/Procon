---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    #include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cmath>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const\
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 2 \"Library/DataStructure/DualSegmentTree.hpp\"\
    \n\ntemplate<typename Monoid, typename OperatorMonoid>\nclass DualSegmentTree{\n\
    \    public:\n    using Mapping = function<Monoid(Monoid, OperatorMonoid)>;\n\
    \    using Composite = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n\
    \    \n    DualSegmentTree(\n        vector<Monoid> &A, \n        Mapping g, \n\
    \        Composite h, \n        const OperatorMonoid &e, \n        bool zero_index\
    \ = false\n    ) : g(g), h(h), e(e), zero_index_(zero_index){\n        size_ =\
    \ 1;\n        while(size_ < (int)A.size()) size_ <<= 1;\n        offset_ = size_\
    \ - 1;\n        data_.resize(2 * size_);\n        lazy_.resize(2 * size_, e);\n\
    \        is_identity_.resize(2 * size_, true);\n        for(int i = 0; i < (int)A.size();\
    \ ++i){\n            data_[size_ + i] = A[i];\n        }\n    }\n\n    void Apply(int\
    \ l, int r, OperatorMonoid x){\n        Validate(l + zero_index_);\n        Validate(r\
    \ + zero_index_ - 1);\n        RecursiveApply(l + zero_index_, r + zero_index_,\
    \ x, 1, size_ + 1, 1);\n    }\n\n    Monoid Fold(int k){\n        Validate(k +\
    \ zero_index_);\n        return RecursiveFold(k + zero_index_, 1, size_ + 1, 1);\n\
    \    }\n\n    Monoid operator[](const int &k){\n        Validate(k + zero_index_);\n\
    \        return Fold(k);\n    }\n\n    private:\n    int size_, offset_, zero_index_;\n\
    \    vector<Monoid> data_;\n    vector<OperatorMonoid> lazy_;\n    vector<bool>\
    \ is_identity_;\n    const Mapping g;\n    const Composite h;\n    const OperatorMonoid\
    \ e;\n\n    inline void Validate(int x){\n        assert(1 <= x && x <= size_);\n\
    \    }\n\n    void Evaluate(int k){\n        if(is_identity_[k]) return;\n   \
    \     if(k < size_){\n            lazy_[k * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);\n\
    \            is_identity_[k * 2 + 0] = false;\n            lazy_[k * 2 + 1] =\
    \ h(lazy_[k * 2 + 1], lazy_[k]);\n            is_identity_[k * 2 + 1] = false;\n\
    \        }\n        data_[k] = g(data_[k], lazy_[k]);\n        lazy_[k] = e;\n\
    \        is_identity_[k] = true;\n    }\n\n    void RecursiveApply(int ul, int\
    \ ur, OperatorMonoid x, int left, int right, int cell){\n        Evaluate(cell);\n\
    \        if(ul <= left && right <= ur){\n            lazy_[cell] = h(lazy_[cell],\
    \ x);\n            is_identity_[cell] = false;\n            Evaluate(cell);\n\
    \        }\n        else if(ul < right && left < ur){\n            int mid = (left\
    \ + right) / 2;\n            RecursiveApply(ul, ur, x, left, mid, cell * 2 + 0);\n\
    \            RecursiveApply(ul, ur, x, mid, right, cell * 2 + 1);\n        }\n\
    \    }\n    \n    Monoid RecursiveFold(int q, int left, int right, int cell){\n\
    \        Evaluate(cell);\n        if(q == left && right - left == 1) return data_[cell];\n\
    \        int mid = (left + right) / 2;\n        if(q < mid) return RecursiveFold(q,\
    \ left, mid, cell * 2 + 0);\n        else return RecursiveFold(q, mid, right,\
    \ cell * 2 + 1);\n    }\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename Monoid, typename OperatorMonoid>\n\
    class DualSegmentTree{\n    public:\n    using Mapping = function<Monoid(Monoid,\
    \ OperatorMonoid)>;\n    using Composite = function<OperatorMonoid(OperatorMonoid,\
    \ OperatorMonoid)>;\n    \n    DualSegmentTree(\n        vector<Monoid> &A, \n\
    \        Mapping g, \n        Composite h, \n        const OperatorMonoid &e,\
    \ \n        bool zero_index = false\n    ) : g(g), h(h), e(e), zero_index_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < (int)A.size()) size_ <<= 1;\n     \
    \   offset_ = size_ - 1;\n        data_.resize(2 * size_);\n        lazy_.resize(2\
    \ * size_, e);\n        is_identity_.resize(2 * size_, true);\n        for(int\
    \ i = 0; i < (int)A.size(); ++i){\n            data_[size_ + i] = A[i];\n    \
    \    }\n    }\n\n    void Apply(int l, int r, OperatorMonoid x){\n        Validate(l\
    \ + zero_index_);\n        Validate(r + zero_index_ - 1);\n        RecursiveApply(l\
    \ + zero_index_, r + zero_index_, x, 1, size_ + 1, 1);\n    }\n\n    Monoid Fold(int\
    \ k){\n        Validate(k + zero_index_);\n        return RecursiveFold(k + zero_index_,\
    \ 1, size_ + 1, 1);\n    }\n\n    Monoid operator[](const int &k){\n        Validate(k\
    \ + zero_index_);\n        return Fold(k);\n    }\n\n    private:\n    int size_,\
    \ offset_, zero_index_;\n    vector<Monoid> data_;\n    vector<OperatorMonoid>\
    \ lazy_;\n    vector<bool> is_identity_;\n    const Mapping g;\n    const Composite\
    \ h;\n    const OperatorMonoid e;\n\n    inline void Validate(int x){\n      \
    \  assert(1 <= x && x <= size_);\n    }\n\n    void Evaluate(int k){\n       \
    \ if(is_identity_[k]) return;\n        if(k < size_){\n            lazy_[k * 2\
    \ + 0] = h(lazy_[k * 2 + 0], lazy_[k]);\n            is_identity_[k * 2 + 0] =\
    \ false;\n            lazy_[k * 2 + 1] = h(lazy_[k * 2 + 1], lazy_[k]);\n    \
    \        is_identity_[k * 2 + 1] = false;\n        }\n        data_[k] = g(data_[k],\
    \ lazy_[k]);\n        lazy_[k] = e;\n        is_identity_[k] = true;\n    }\n\n\
    \    void RecursiveApply(int ul, int ur, OperatorMonoid x, int left, int right,\
    \ int cell){\n        Evaluate(cell);\n        if(ul <= left && right <= ur){\n\
    \            lazy_[cell] = h(lazy_[cell], x);\n            is_identity_[cell]\
    \ = false;\n            Evaluate(cell);\n        }\n        else if(ul < right\
    \ && left < ur){\n            int mid = (left + right) / 2;\n            RecursiveApply(ul,\
    \ ur, x, left, mid, cell * 2 + 0);\n            RecursiveApply(ul, ur, x, mid,\
    \ right, cell * 2 + 1);\n        }\n    }\n    \n    Monoid RecursiveFold(int\
    \ q, int left, int right, int cell){\n        Evaluate(cell);\n        if(q ==\
    \ left && right - left == 1) return data_[cell];\n        int mid = (left + right)\
    \ / 2;\n        if(q < mid) return RecursiveFold(q, left, mid, cell * 2 + 0);\n\
    \        else return RecursiveFold(q, mid, right, cell * 2 + 1);\n    }\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/DualSegmentTree.hpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-RangeAffinePointGet.test.cpp
documentation_of: Library/DataStructure/DualSegmentTree.hpp
layout: document
title: "Dual Segment Tree - \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

# Dual Segment Tree - 双対セグメント木

長さ $N$ の数列 $A = (A_1, \dots, A_N)$ に対し、次の $2$ 種類のクエリを効率的に処理することができるデータ構造です。

- 区間更新クエリ : $\textrm{O}(\log N)$
- 一点取得クエリ : $\textrm{O}(\log N)$

数列 $A$ の要素はモノイド $M$ であり、更新操作もモノイド $O$ である必要があります。

## Function

### Constructor

```
DualSegmentTree(
    vector<Monoid> &A, 
    Mapping g, 
    Composite h, 
    const OperatorMonoid &e, 
    bool zero_index = false
)
```

- セグメント木を配列 $A$ で初期化します。以降、$N = \lvert A \rvert$ とします。
- $g$ は遅延評価を適用する二項演算 $\otimes : M \times O \rightarrow M$ を表します。
- $h$ は遅延評価を合成する二項演算 $\odot : O \times O \rightarrow O$ を表します。
- `e` には操作モノイド $O$ の単位元 $e$ を渡します。
- `zero_index` に `true` を指定すると、セグメント木にアクセスする添え字を 0-index でアクセスすることができます。デフォルトでは 1-index です。
    - 本ドキュメントでは添え字に関する制約は 1-index で示します。

**制約**

- $1 \le N \le 10^6$
- $A_i \in M$
- $g$ は二項演算 $\otimes : M \times O \rightarrow M$ を行う `function<Monoid(Monoid, OperatorMonoid)>` 型
- $h$ は二項演算 $\odot : O \times O \rightarrow O$ を行う `function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>` 型
- $e$ は $O$ の単位元

**計算量**

- 時間計算量 : $\textrm{O}(N)$
- 空間計算量 : $\textrm{O}(N)$

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
Monoid Fold(int k)
```

- $A_k$ を取得します。

**制約**

- $1 \le k \le N$

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

最終更新 : Ver.6.0.0

---