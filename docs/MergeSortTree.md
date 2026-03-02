---
title: Merge Sort Tree - 領域木
documentation_of: ../Library/DataStructure/MergeSortTree.hpp
---

# Merge Sort Tree - 領域木

長さ $N$ の列 $A = (A_1, \dots, A_N)$ および各要素に対応する要素からなる $B = (B_1, \dots, B_N)$ に対し、区間に対するクエリを効率的に行うことができるデータ構造です。

列 $A$ の型を `DataType`、列 $B$ の型を `WeightType` とします。

## Function

### Constructor

```
(1) MergeSortTree(
        const vector<DataType> &A,
        const vector<WeightType> &B,
        bool zero_index = false
    )
(2) MergeSortTree(
        const vector<DataType> &A,
        bool zero_index = false
    )
```

- (1) 長さ $N$ の配列 $A, B$ を用いて領域木を初期化します。
- (2) 長さ $N$ の配列 $A$ を用いて領域木を初期化します。$B$ は $A$ と同一になります。

**制約**

- $1 \le N \le 5 \times 10^5$
- (1) $\lvert A \rvert = \lvert B \rvert$

**計算量**

- $\textrm{O}(N)$

---

### CountAtMost

```
int CountAtMost(int l, int r, DataType x) const
```

- $i \in [l, r)$ かつ $A_i \le x$ を満たすような整数 $i$ の個数を返します。

**制約**

- $0 \le l \lt N$
- $l \le r \le N$

**計算量**

- $\textrm{O}((\log N)^2)$

---

### CountAtLeast

```
int CountAtLeast(int l, int r, DataType x) const
```

- $i \in [l, r)$ かつ $A_i \ge x$ を満たすような整数 $i$ の個数を返します。

**制約**

- $0 \le l \lt N$
- $l \le r \le N$

**計算量**

- $\textrm{O}((\log N)^2)$

---

### CountBetween

```
int CountBetween(int l, int r, DataType p, DataType q) const
```

- $i \in [l, r)$ かつ $p \le A_i \le q$ を満たすような整数 $i$ の個数を返します。

**制約**

- $0 \le l \lt N$
- $l \le r \le N$
- $p \le q$

**計算量**

- $\textrm{O}((\log N)^2)$

---

### SumAtMost

```
WeightType SumAtMost(int l, int r, DataType x) const
```

- $i \in [l, r)$ かつ $A_i \le x$ を満たすようなすべての整数 $i$ について、$B_i$ の総和を返します。

**制約**

- $0 \le l \lt N$
- $l \le r \le N$

**計算量**

- $\textrm{O}((\log N)^2)$

---

### SumAtLeast

```
WeightType SumAtLeast(int l, int r, DataType x) const
```

- $i \in [l, r)$ かつ $A_i \ge x$ を満たすようなすべての整数 $i$ について、$B_i$ の総和を返します。

**制約**

- $0 \le l \lt N$
- $l \le r \le N$

**計算量**

- $\textrm{O}((\log N)^2)$

---

### SumBetween

```
WeightType SumBetween(int l, int r, DataType p, DataType q) const
```

- $i \in [l, r)$ かつ $p \le A_i \le q$ を満たすようなすべての整数 $i$ について、$B_i$ の総和を返します。

**制約**

- $0 \le l \lt N$
- $l \le r \le N$
- $p \le q$

**計算量**

- $\textrm{O}((\log N)^2)$

---
