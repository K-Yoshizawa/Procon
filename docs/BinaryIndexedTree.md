---
title: Binary Indexed Tree (Fenwick Tree) - 二分索引木
documentation_of: ../Library/DataStructure/BinaryIndexedTree.hpp
---

# Binary Indexed Tree (Fenwick Tree) - 二分索引木

長さ $N$ の数列 $A = (A_1, \dots, A_N)$ に対し、一点加算・区間和取得クエリを効率的に行うことができるデータ構造です。

## Function

### Constructor

```
BinaryIndexedTree(int n)
```

- 数列 $A$ を長さ $n$ で初期化します。初期値はすべて $0$ です。

**制約**

- $1 \le n \le 10^6$

**計算量**

- $\textrm{O}(n)$

---

### Add

```
void Add(int i, T v)
```

- $A_i$ に値 $v$ を加算します。$A_i \leftarrow A_i + v$

**制約**

- $1 \le i \le n$

**計算量**

- $\textrm{O}(\log n)$

---

### Sum

```
(1) T Sum(int i)
(2) T Sum(int l, int r)
```

- (1) 区間 $[1, i]$ の総和を返します。$\sum_{k=1}^{i} A_k$ を計算します。
- (2) 区間 $[l, r]$ の総和を返します。$\sum_{k=l}^{r} A_k$ を計算します。

**制約**

- (1) $1 \le i \le n$
- (2) $1 \le l \le r \le n$

**計算量**

- $\textrm{O}(\log n)$

---
