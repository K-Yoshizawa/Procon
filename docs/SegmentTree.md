---
title: Segment Tree - セグメント木
documentation_of: ../Library/DataStructure/SegmentTree.hpp
---

# Segment Tree - セグメント木

長さ $N$ の列 $A = (A_1, \dots, A_N)$ に対し、一点更新・区間取得クエリを効率的に行うことができるデータ構造です。

数列 $A$ の要素はモノイド $M$ である必要があります。以下、モノイドの単位元を $e$ とします。

## Function

### Constructor

```
SegmentTree(
    vector<Monoid> &A,
    F merge,
    const Monoid &e,
    bool zero_index = false
)
```

- セグメント木を配列 $A$ で初期化します。以降、セグメント木の長さを $N = \lvert A \rvert$ で表します。
- `merge` には $2$ つのモノイドに対する二項演算 $\oplus : M \times M \rightarrow M$ を渡します。
    - 本ドキュメントでは `merge` の計算量を定数時間としています。
    - 区間最小値 : `[](int x, int y){return min(x, y);}`
    - 区間総和 : `[](int x, int y){return x + y;}`
- `zero_index` に `true` を指定すると、セグメント木にアクセスする添え字を 0-index でアクセスすることができます。デフォルトでは 1-index です。
    - 本ドキュメントでは添え字に関する制約は 1-index で示します。

**制約**

- $1 \le N \le 10^6$
- $A_i \in M$
- `merge` は二項演算 $\oplus : M \times M \rightarrow M$ を行う関数
- $e$ は $M$ の単位元

**計算量**

- $\textrm{O}(N)$

---

### Apply

```
void Apply(int k, Monoid x)
```

- $A_k$ に対して一点更新クエリを実行します。
- すなわち、$A_k \leftarrow x$ を行います。

**制約**

- $1 \le k \le N$
- $x \in M$

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

- $\textrm{O}(1)$

---

