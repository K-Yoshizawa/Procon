---
title: Red-Black Tree - 平衡二分探索木 (赤黒木)
documentation_of: ../Library/DataStructure/RedBlackTree.hpp
---

# Red-Black Tree - 平衡二分探索木 (赤黒木)

集合を管理するデータ構造です。

## Function

### Constructor

```
RedBlackTree(int N = 500010)
```

- 平衡二分探索木 $S$ を初期化します。
- $N$ は集合の最大要素数です。基本的に気にする必要はありません。
- `T` は `numeric_limits` が定義されている型であることを想定しています。

**制約**

- $1 \le N \le 10^6$

---

### Insert

```
void Insert(T x)
```

- $S$ に要素 $x$ を挿入します。
- $x \in S$ の場合は何もしません。

**計算量**

- $\textrm{O}(\log N)$

---

### Erase

```
void Erase(T x)
```

- $S$ から要素 $x$ を削除します。
- $x \notin S$ の場合は何もしません。

**計算量**

- $\textrm{O}(\log N)$

---

### Contains

```
bool Contains(T x)
```

- $x \in S$ であるかを判定します。

**計算量**

- $\textrm{O}(\log N)$

---

### Size

```
int Size()
```

- 現在の $S$ の要素数を返します。

**計算量**

- $\textrm{O}(1)$

---

### KthElement

```
T KthElement(int k, T e = T{})
```

- $S$ に含まれる要素のうち $k$ 番目に小さい要素を返します。
- $k \lt 1$ または $k \gt |S|$ の場合は $e$ を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### CountLess

```
int CountLess(T x)
```

- $S$ に含まれる要素のうち $x$ **より小さい**要素の個数を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### CountLessEqual

```
int CountLessEqual(T x)
```

- $S$ に含まれる要素のうち $x$ **以下**の要素の個数を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### CountGreater

```
int CountGreater(T x)
```

- $S$ に含まれる要素のうち $x$ **より大きい**要素の個数を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### CountGreaterEqual

```
int CountGreaterEqual(T x)
```

- $S$ に含まれる要素のうち $x$ **以上**の要素の個数を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### MaximumLess(T x, T inf = numeric_limits<T>::min())

```
T MaximumLess(T x, T inf = numeric_limits<T>::min())
```

- $S$ に含まれる要素のうち $x$ **より小さい**要素のうち最大のものを返します。
- そのような要素が存在しない場合は $-\infty$ を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### MaximumLessEqual(T x, T inf = numeric_limits<T>::min())

```
T MaximumLessEqual(T x, T inf = numeric_limits<T>::min())
```

- $S$ に含まれる要素のうち $x$ **以下**の要素のうち最大のものを返します。
- そのような要素が存在しない場合は $-\infty$ を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### MinimumGreater(T x, T inf = numeric_limits<T>::max())

```
T MinimumGreater(T x, T inf = numeric_limits<T>::max())
```

- $S$ に含まれる要素のうち $x$ **より大きい**要素のうち最小のものを返します。
- そのような要素が存在しない場合は $\infty$ を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### MinimumGreaterEqual(T x, T inf = numeric_limits<T>::max())

```
T MinimumGreaterEqual(T x, T inf = numeric_limits<T>::max())
```

- $S$ に含まれる要素のうち $x$ **以上**の要素のうち最小のものを返します。
- そのような要素が存在しない場合は $\infty$ を返します。

**計算量**

- $\textrm{O}(\log N)$

---
