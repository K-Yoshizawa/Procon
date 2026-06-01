---
title: Sparse Table
documentation_of: ../Library/DataStructure/SparseTable.hpp
---

# Sparse Table

長さ $N$ の**静的な**列 $A = (A_0, \dots, A_{N - 1})$ について、半開区間 $[l, r)$ に対して $\min_{k \in [l, r)} A_k$ を効率的に計算することができるデータ構造です。

## Function

### Constructor

```
SparseTable(const vector<Ordered> &A)
```

- 長さ $N$ の列 $A$ を渡し、Sparse Table を構築します。

**制約**

- $1 \le N \le 10^6$

**計算量**

- 時間計算量 : $\textrm{O}(N \log N)$
- 空間計算量 : $\textrm{O}(N \log N)$

---

### Fold

```
inline Ordered Fold(int l, int r) const
```

- 半開区間 $[l, r)$ に対して $\displaystyle \underset{k \in [l, r)}{\min}\ A_k$ を返します。

**制約**

- $0 \le l < r \le N$

**計算量**

- $\textrm{O}(1)$

---

最終更新 : Ver.6.0.0

---