---
title: Segment Tree - セグメント木
documentation_of: ../Library/DataStructure/SegmentTree.hpp
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
- (2) $1 \le \lvert A \rvert \le 10^6$
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

### Product

```
Monoid Product(int l, int r)
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

