---
title: Euler Tour - オイラーツアー
documentation_of: ../Library/Tree/EulerTour.hpp
---

# Euler Tour - オイラーツアー

根付き木に対して、各頂点の行きがけ時刻と帰りがけ時刻を計算するデータ構造です。

オイラーツアーを用いることで、部分木クエリや木上のパスクエリをセグメント木などで効率的に処理できます。

## Function

### Constructor

```
EulerTour(RootedTree<CostType> &T, bool one_index = false)
```

- 木 `T` におけるオイラーツアーを構築します。
- `one_index` に `true` を指定すると、頂点番号を 1-index として扱います。デフォルトは 0-index です。

**制約**

- $1 \le \lvert V \rvert \le 10^6$

**計算量**

- $\textrm{O}(\lvert V \rvert)$

---

### GetIn

```
int GetIn(const Vertex v) const
```

- 頂点 $v$ に入った時刻（行きがけ時刻）を返します。
- 時刻は 0-index で返されます。

**計算量**

- $\textrm{O}(1)$

---

### GetOut

```
int GetOut(const Vertex v) const
```

- 頂点 $v$ から出た時刻（帰りがけ時刻）を返します。
- 時刻は 0-index で返されます。

**計算量**

- $\textrm{O}(1)$

---

### GetPair

```
pair<int, int> GetPair(const Vertex v) const
```

- 頂点 $v$ に入った時刻と出た時刻の両方を返します。
- 時刻は 0-index で返されます。

**計算量**

- $\textrm{O}(1)$

---

### ConvertVector

```
template<typename Type>
vector<Type> ConvertVector(const vector<Type> &value, const F in_converter, const F out_converter)
```

- 配列 `value` をオイラーツアーに基づいて変換した配列を返します。
- セグメント木などの初期配列として使用することを想定しています。
- `in_converter` は頂点 $v$ に入る時刻に対するデータを変換する関数です。
- `out_converter` は頂点 $v$ から出る時刻に対するデータを変換する関数です。

**制約**

- `value` のサイズは $\lvert V \rvert$

**計算量**

- $\textrm{O}(\lvert V \rvert)$

**戻り値**

- 長さ $2 \lvert V \rvert$ の配列

---
