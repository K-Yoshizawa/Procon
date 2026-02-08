---
title: Dual Segment Tree - 双対セグメント木
documentation_of: ../Library/DataStructure/DualSegmentTree.hpp
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
