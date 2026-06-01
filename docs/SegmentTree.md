---
title: Segment Tree - セグメント木
documentation_of: ../Library/DataStructure/SegmentTree.hpp
---

# Segment Tree - セグメント木

長さ $N$ の列 $A = (A_1, \dots, A_N)$ に対し、次の $2$ 種類のクエリを効率的に処理することができるデータ構造です。

- 一点更新クエリ : $\textrm{O}(\log N)$
- 区間積クエリ : $\textrm{O}(\log N)$

列 $A$ の要素はモノイド $M$ である必要があります。

## Function

### Constructor

```
SegmentTree(
    vector<Monoid> &A,
    MergeFunction f,
    const Monoid &e,
    bool zero_index = false
)
```

- セグメント木を配列 $A$ で初期化します。以降、$N = \lvert A \rvert$ とします。
- $f$ は $2$ つのモノイドに対する二項演算 $\oplus : M \times M \rightarrow M$ を表します。
    - 本ドキュメントでは $f$ の計算量を定数時間としています。
    - 区間最小値 : `[](int x, int y){return min(x, y);}`
    - 区間総和 : `[](int x, int y){return x + y;}`
- $e$ は $M$ の単位元を表し、任意の $x \in M$ に対し $x \oplus e = e \oplus x = x$ を満たす必要があります。
- `zero_index` に `true` を指定すると、セグメント木にアクセスする添え字を 0-index でアクセスすることができます。デフォルトでは 1-index です。
    - 本ドキュメントでは添え字に関する制約は 1-index で示します。

**制約**

- $1 \le N \le 10^6$
- $A_i \in M$
- $f$ は二項演算 $\oplus : M \times M \rightarrow M$ を行う関数
- $e$ は $M$ の単位元

**計算量**

- 時間計算量 : $\textrm{O}(N)$
- 空間計算量 : $\textrm{O}(N)$

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

- 半開区間 $[l, r)$ に対して区間積クエリを実行します。
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

最終更新 : Ver.6.0.0

---