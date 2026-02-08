---
title: Cumulative Sum 2D - 二次元累積和
documentation_of: ../Library/DataStructure/CumulativeSum2D.hpp
---

# Cumulative Sum 2D - 二次元累積和

$H \times W$ の二次元配列 $A$ に対し、長方形領域の総和を効率的に計算するデータ構造です。

## Function

### Constructor

```
CumulativeSum2D(const int height, const int width, const T init_value = 0)
```

- 高さ $h$、幅 $w$ の二次元累積和を初期化します。
- `init_value` は使用されません（後方互換性のために残されています）。

**制約**

- $1 \le h, w \le 10^3$

**計算量**

- $\textrm{O}(hw)$

---

### Set

```
void Set(const int y, const int x, const T value)
```

- 座標 $(y, x)$ に値 $v$ を代入します。$A_{y,x} \leftarrow v$
- **0-index** で座標を指定します。

**制約**

- $0 \le y < h$
- $0 \le x < w$

**計算量**

- $\textrm{O}(1)$

---

### Add (一点加算)

```
void Add(const int y, const int x, const T value)
```

- 座標 $(y, x)$ に値 $v$ を加算します。$A_{y,x} \leftarrow A_{y,x} + v$
- **0-index** で座標を指定します。

**制約**

- $0 \le y < h$
- $0 \le x < w$

**計算量**

- $\textrm{O}(1)$

---

### Add (領域加算)

```
void Add(const int y1, const int x1, const int y2, const int x2, const T value)
```

- 長方形領域 $[y_1, y_2] \times [x_1, x_2]$ に値 $v$ を加算します。
- **0-index、閉区間** で座標を指定します。

**制約**

- $0 \le y_1 \le y_2 < h$
- $0 \le x_1 \le x_2 < w$

**計算量**

- $\textrm{O}(1)$

---

### Build

```
void Build()
```

- 累積和の構築を行います。
- `Set()` や `Add()` で値を設定した後、この関数を呼び出してください。

**計算量**

- $\textrm{O}(hw)$

---

### Sum (矩形領域)

```
(1) T Sum(const int y, const int x) const
(2) T Sum(const int y1, const int x1, const int y2, const int x2) const
```

- (1) 長方形領域 $[0, y] \times [0, x]$ の総和を返します。
- (2) 長方形領域 $[y_1, y_2] \times [x_1, x_2]$ の総和を返します。
- **0-index、閉区間** で座標を指定します。

**制約**

- (1) $0 \le y < h$, $0 \le x < w$
- (2) $0 \le y_1 \le y_2 < h$, $0 \le x_1 \le x_2 < w$

**計算量**

- $\textrm{O}(1)$

---

### Max

```
T Max() const
```

- 配列内の最大値を返します。

**計算量**

- $\textrm{O}(hw)$

---

### Min

```
T Min() const
```

- 配列内の最小値を返します。

**計算量**

- $\textrm{O}(hw)$

---

### operator[]

```
vector<T> &operator[](const int k)
```

- $k$ 行目の配列への参照を返します。
- **0-index** でアクセスします。

**制約**

- $0 \le k < h$

**計算量**

- $\textrm{O}(1)$

---
