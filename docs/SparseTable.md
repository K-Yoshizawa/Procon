---
title: Sparse Table
documentation_of: ../Library/DataStructure/SparseTable.hpp
---

# Sparse Table

冪等モノイド $(M, *)$ の元からなる長さ $N$ の**静的な**列 $A = (A_0, \dots, A_{N - 1})$ について、半開区間 $[l, r)$ に対して $A_l * A_{l + 1} * \dots * A_{r - 1}$ を効率的に計算することができるデータ構造です。

## Function

### Constructor

```
SparseTable(
    const vector<IMonoid> &A,
    const function<IMonoid(IMonoid, IMonoid)> f = [](IMonoid x, IMonoid y){
        return min(x, y);
    }
)
```

- 冪等モノイド $(M, *)$ の元からなる長さ $N$ の列 $A$ と二項演算 $f : M * M \rightarrow M$ を渡し、Sparse Table を構築します。
- 二項演算 $f$ は省略可能であり、その場合は `min` が渡されます。

**制約**

- $1 \le N \le 10^6$
- $(M, *)$ は冪等モノイドであり、$A$ の各要素は $M$ の元

**計算量**

- $\textrm{O}(N \log N)$

---

### Query

```
inline IMonoid Query(const int &l, const int &r) const 
```

- 半開区間 $[l, r)$ に対して $A_l * A_{l + 1} * \dots * A_{r - 1}$ を返します。

**制約**

- $0 \le l < r \le N$

**計算量**

- $\textrm{O}(1)$

---
