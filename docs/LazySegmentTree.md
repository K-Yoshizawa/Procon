---
title: Lazy Segment Tree - 遅延評価セグメント木
documentation_of: ../Library/DataStructure/LazySegmentTree.hpp
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
- `mapping` には遅延評価を適用する演算 $f : M \times O \rightarrow M$ を渡します。
- `composite` には遅延評価を合成する演算 $\odot : O \times O \rightarrow O$ を渡します。
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
