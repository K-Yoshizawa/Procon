---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  - icon: ':x:'
    path: verify/LC-VertexAddPathSum.test.cpp
    title: verify/LC-VertexAddPathSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
    title: verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
  - icon: ':x:'
    path: verify/LC-VertexAddSubtreeSum.test.cpp
    title: verify/LC-VertexAddSubtreeSum.test.cpp
  - icon: ':x:'
    path: verify/LC-VertexSetPathComposite.test.cpp
    title: verify/LC-VertexSetPathComposite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (1LL << 30) -\
    \ 1;\n#line 2 \"Library/DataStructure/SegmentTree.hpp\"\n\ntemplate<typename Monoid>\n\
    class SegmentTree{\n    public:\n    using F = function<Monoid(Monoid, Monoid)>;\n\
    \n    SegmentTree(\n        int n,\n        F merge,\n        const Monoid &e,\n\
    \        bool zero_index = false\n    ) : f(merge), id_(e), zero_index_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < n) size_ <<= 1;\n        offset_ =\
    \ size_ - 1;\n        data_.resize(2 * size_, id_);\n    }\n    \n    SegmentTree(\n\
    \        vector<Monoid> &A, \n        F merge, \n        const Monoid &e, \n \
    \       bool zero_index = false\n    ) : f(merge), id_(e), zero_index_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < (int)A.size()) size_ <<= 1;\n     \
    \   offset_ = size_ - 1;\n        data_.resize(2 * size_, id_);\n        for(int\
    \ i = 0; i < (int)A.size(); ++i){\n            data_[size_ + i] = A[i];\n    \
    \    }\n        Build();\n    }\n\n    void Build(){\n        for(int i = offset_;\
    \ i >= 1; --i){\n            data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n\
    \        }\n    }\n\n    void Set(int i, Monoid v){\n        Validate(i + zero_index_);\n\
    \        int k = offset_ + i + zero_index_;\n        data_[k] = v;\n        while(k\
    \ >>= 1){\n            data_[k] = f(data_[2 * k], data_[2 * k + 1]);\n       \
    \ }\n    }\n\n    Monoid Prod(int l, int r){\n        if(l == r) return id_;\n\
    \        Validate(l + zero_index_);\n        Validate(r + zero_index_ - 1);\n\
    \        int lh = l + zero_index_ + offset_, rh = r + zero_index_ + offset_;\n\
    \        Monoid al = id_, ar = id_;\n        while(lh < rh){\n            if(lh\
    \ & 1) al = f(al, data_[lh++]);\n            if(rh & 1) ar = f(data_[--rh], ar);\n\
    \            lh >>= 1, rh >>= 1;\n        }\n        return f(al, ar);\n    }\n\
    \n    Monoid operator[](const int &i){\n        Validate(i + zero_index_);\n \
    \       return data_[offset_ + i + zero_index_];\n    }\n\n    private:\n    int\
    \ size_, offset_, zero_index_;\n    vector<Monoid> data_;\n    const F f;\n  \
    \  const Monoid id_;\n\n    inline void Validate(int x) const {\n        assert(1\
    \ <= x && x <= size_);\n    }\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename Monoid>\nclass SegmentTree{\n\
    \    public:\n    using F = function<Monoid(Monoid, Monoid)>;\n\n    SegmentTree(\n\
    \        int n,\n        F merge,\n        const Monoid &e,\n        bool zero_index\
    \ = false\n    ) : f(merge), id_(e), zero_index_(zero_index){\n        size_ =\
    \ 1;\n        while(size_ < n) size_ <<= 1;\n        offset_ = size_ - 1;\n  \
    \      data_.resize(2 * size_, id_);\n    }\n    \n    SegmentTree(\n        vector<Monoid>\
    \ &A, \n        F merge, \n        const Monoid &e, \n        bool zero_index\
    \ = false\n    ) : f(merge), id_(e), zero_index_(zero_index){\n        size_ =\
    \ 1;\n        while(size_ < (int)A.size()) size_ <<= 1;\n        offset_ = size_\
    \ - 1;\n        data_.resize(2 * size_, id_);\n        for(int i = 0; i < (int)A.size();\
    \ ++i){\n            data_[size_ + i] = A[i];\n        }\n        Build();\n \
    \   }\n\n    void Build(){\n        for(int i = offset_; i >= 1; --i){\n     \
    \       data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n\
    \    void Set(int i, Monoid v){\n        Validate(i + zero_index_);\n        int\
    \ k = offset_ + i + zero_index_;\n        data_[k] = v;\n        while(k >>= 1){\n\
    \            data_[k] = f(data_[2 * k], data_[2 * k + 1]);\n        }\n    }\n\
    \n    Monoid Prod(int l, int r){\n        if(l == r) return id_;\n        Validate(l\
    \ + zero_index_);\n        Validate(r + zero_index_ - 1);\n        int lh = l\
    \ + zero_index_ + offset_, rh = r + zero_index_ + offset_;\n        Monoid al\
    \ = id_, ar = id_;\n        while(lh < rh){\n            if(lh & 1) al = f(al,\
    \ data_[lh++]);\n            if(rh & 1) ar = f(data_[--rh], ar);\n           \
    \ lh >>= 1, rh >>= 1;\n        }\n        return f(al, ar);\n    }\n\n    Monoid\
    \ operator[](const int &i){\n        Validate(i + zero_index_);\n        return\
    \ data_[offset_ + i + zero_index_];\n    }\n\n    private:\n    int size_, offset_,\
    \ zero_index_;\n    vector<Monoid> data_;\n    const F f;\n    const Monoid id_;\n\
    \n    inline void Validate(int x) const {\n        assert(1 <= x && x <= size_);\n\
    \    }\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2025-05-30 15:32:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/LC-VertexAddPathSum.test.cpp
  - verify/LC-PointSetRangeComposite.test.cpp
  - verify/AOJ-DSL-2-A.test.cpp
  - verify/AOJ-DSL-2-B.test.cpp
  - verify/LC-PointAddRangeSum.test.cpp
  - verify/LC-VertexSetPathComposite.test.cpp
  - verify/LC-VertexAddSubtreeSum.test.cpp
  - verify/LC-VertexAddSubtreeSum-EulerTour.test.cpp
documentation_of: Library/DataStructure/SegmentTree.hpp
layout: document
title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

# Segment Tree - セグメント木

長さ $N$ の数列 $A = (A_1, \dots, A_N)$ に対し、一点更新・区間取得クエリを効率的に行うことができるデータ構造です。

数列 $A$ の要素はモノイド $M$ である必要があります。以下、モノイドの単位元を $e$ とします。

## Function

### Constructor

```
(1) SegmentTree(int n, F merge, const Monoid &e, bool zero_index = false)
(2) SegmentTree(vector<Monoid> &A, F merge, const Monoid &e, bool zero_index = false)
```

- (1) セグメント木の数列 $A$ を長さ $n$ で初期化します。初期値はすべて $e$ です。
- (2) セグメント木を数列 $A$ で初期化します。
- `merge` には $2$ つのモノイドに対する二項演算 $\oplus : M \times M \rightarrow M$ を渡します。いくつかの例を示します。
    - 区間最小値 : `[](int x, int y){return min(x, y);}`
    - 区間総和 : `[](int x, int y){return x + y;}`
- `zero_index` に `true` を指定すると、セグメント木にアクセスする添え字を 0-index でアクセスすることができます。デフォルトでは 1-index です。
    - 本ドキュメントでは添え字に関する制約は 1-index で示します。

**制約**

- (1) $1 \le n \le 10^6$
- (2) $1 \le |A| \le 10^6$
- `merge` は $M \times M \rightarrow M$ の関数
- $e$ は $M$ の単位元

**計算量**

- $\textrm{O}(n)$

---

### Set

```
void Set(int i, Monoid v)
```

- $A_i$ に初期値 $v$ を代入します。
- `Update()` と異なり、**一点更新ではない**点に注意してください。
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
void Update(int i, Monoid v)
```

- $A_i$ に対して一点更新クエリを実行します。$A_i$ は $v$ で更新されます。

**制約**

- $1 \le i \le n$
- $v \in M$

**計算量**

- $\textrm{O}(\log n)$

---

### Prod

```
Monoid Prod(int l, int r)
```

- 半開区間 $[l, r)$ に対して区間取得クエリを実行します。

**制約**

- $1 \le l \le n$
- $l \le r \le n + 1$

**計算量**

- $\textrm{O}(\log n)$

---

### operator[]

```
Monoid operator[](const int &i)
```

- $A_i$ を取得します。

**制約**

- $1 \le i \le n$

**計算量**

- $\textrm{O}(1)$

---

