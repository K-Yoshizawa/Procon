---
title: Lazy Segment Tree - 遅延評価セグメント木
documentation_of: ../Library/DataStructure/LazySegmentTree.hpp
---

# Lazy Segment Tree - 遅延評価セグメント木

長さ $N$ の列 $A = (A_1, \dots, A_N)$ に対し、次の $2$ 種類のクエリを効率的に処理することができるデータ構造です。

- 区間更新クエリ : $\textrm{O}(\log N)$
- 区間積クエリ : $\textrm{O}(\log N)$

数列 $A$ の要素はモノイド $M$ であり、更新操作もモノイド $O$ である必要があります。

## Function

### Constructor

```
LazySegmentTree(
    vector<Monoid> &A,
    Merge f,
    Mapping g,
    Composite h,
    const Monoid &e_m,
    const OperatorMonoid &e_o,
    bool zero_index = false
)
```

- セグメント木を配列 $A$ で初期化します。以降、$N = \lvert A \rvert$ とします。
- $f$ は $2$ つのモノイド $M$ に対する二項演算 $\oplus : M \times M \rightarrow M$ を表します。
- $g$ は遅延評価を適用する二項演算 $\otimes : M \times O \rightarrow M$ を表します。
- $h$ は遅延評価を合成する二項演算 $\odot : O \times O \rightarrow O$ を表します。
- `e_m` にはモノイド $M$ の単位元 $e_M$ を表します。
- `e_o` には操作モノイド $O$ の単位元 $e_O$ を表します。
- `zero_index` に `true` を指定すると、セグメント木にアクセスする添え字を 0-index でアクセスすることができます。デフォルトでは 1-index です。
    - 本ドキュメントでは添え字に関する制約は 1-index で示します。

**制約**

- $1 \le N \le 10^6$
- $A_i \in M$
- $f$ は二項演算 $\oplus : M \times M \rightarrow M$ を行う `function<Monoid(Monoid, Monoid)>` 型
- $g$ は二項演算 $\otimes : M \times O \rightarrow M$ を行う `function<Monoid(Monoid, OperatorMonoid)>` 型
- $h$ は二項演算 $\odot : O \times O \rightarrow O$ を行う `function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>` 型
- $e_M$ は $M$ の単位元
- $e_O$ は $O$ の単位元

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

最終更新 : Ver.6.0.0

---