---
title: Fenwick Tree
documentation_of: ../Library/DataStructure/FenwickTree.hpp
---

# Fenwick Tree

長さ $N$ の配列 $A = (A_1, \dots, A_N)$ に対し、一点加算・区間和取得クエリを効率的に行うことができるデータ構造です。

## Function

### Constructor

```
FenwickTree(int N)
```

- 数列 $A$ を長さ $N$ で初期化します。初期値はすべて $0$ です。

**制約**

- $1 \le N \le 10^6$

**計算量**

- $\textrm{O}(N)$

---

### Add

```
void Add(int i, ValueType v)
```

- $A_i$ に値 $v$ を加算します。

**制約**

- $1 \le i \le N$

**計算量**

- $\textrm{O}(\log N)$

---

### Sum

```
(1) ValueType Sum(int i)
(2) ValueType Sum(int l, int r)
```

- (1) 区間 $[1, i]$ の総和、すなわち $\sum_{k=1}^{i} A_k$ を計算します。
- (2) 区間 $[l, r]$ の総和、すなわち $\sum_{k=l}^{r} A_k$ を計算します。

**制約**

- (1) $1 \le i \le N$
- (2) $1 \le l \le r \le N$

**計算量**

- $\textrm{O}(\log N)$

---

最終更新 : Ver.6.0.0