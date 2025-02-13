---
title: Segment Tree - セグメント木
documentation_of: ../Library/DataStructure/SegmentTree.hpp
---

# Segment Tree - セグメント木

モノイド $(S, \circ : S \times S \rightarrow S, e \in S)$、つまり

- 結合法則 : $\forall x, y, z \in S : (x \circ y) \circ z = x \circ (y \circ z)$
- 単位元の存在 : $\forall x \in S : e \circ x = x \circ e = x$

を満たす代数構造に対し使用できるデータ構造です。

長さ $n$ の $S$ の数列 $a = (a_0, \dots, a_{n - 1})$ に対し、

- $a_i$ を $x$ に変更
- 半開区間 $[l, r)$ に対し $a_l \circ a_{l + 1} \circ \cdots \circ a_{r - 1}$ を取得

を $\textrm{O}(\log n)$ 時間で処理することができるデータ構造です。

以降の計算量は二項演算 $\circ$ が定数時間で計算可能な場合の計算量を表します。
二項演算 $\circ$ の計算量が $\textrm{O}(f(n))$ 時間である場合、以降の計算量はすべて $\textrm{O}(f(n))$ 倍されます。

## Function

### Constructor

```
(1) SegmentTree(const int n, F merge, const Monoid &monoid_identity)
(2) SegmentTree(vector<Monoid> &a, F merge, const Monoid &monoid_identity)
```

- (1) : 長さ $n$ の Segment Tree を構築します。すべての要素は $e$ で初期化されます。
- (2) : 長さ $n$ の配列 $a$ で Segment Tree を構築します。
- `merge` は二項演算 $\circ : S \times S \rightarrow S$ を表します。
- `monoid_identity` はモノイド $S$ の単位元 $e$ を表します。

**制約**

- $0 \le n \le 10^6$
- `merge` は `function<Monoid(Monoid, Monoid)>` 型

**計算量**

- $\textrm{O}(n)$

---

### Set

```
void Set(int k, Monoid x)
```

- $a_k$ に $x$ を代入します。

**制約**

- $0 \le k \lt n$
- $x \in S$

**計算量**

- $\textrm{O}(\log n)$

---

### Product

```
(1) Monoid Product(int l, int r)
(2) Monoid Product()
```

- (1) : 半開区間 $[l, r)$ に対し $a_l \circ a_{l + 1} \circ \cdots \circ a_{r - 1}$ を取得します。
- (2) : $a_0 \circ \dots \circ a_{n - 1}$ を取得します。

**制約**

- $0 \le l \lt r \le n$

**計算量**

- (1) : $\textrm{O}(\log n)$
- (2) : $\textrm{O}(1)$

---

### Get

```
Monoid Get(int k)
```

- $a_k$ を返します。

**制約**

- $0 \le k \lt n$

**計算量**

- $\textrm{O}(1)$

---