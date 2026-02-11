---
title: Lazy Segment Tree - 遅延評価セグメント木
documentation_of: ../Library/DataStructure/LazySegmentTree.hpp
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
