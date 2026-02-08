---
title: Template - ユーティリティ関数群
documentation_of: ../Library/Template.hpp
---

# Template - ユーティリティ関数群

競技プログラミングで頻繁に使用するユーティリティ関数をまとめたテンプレートライブラリです。

## Function

### 出力関数

#### YnPrint

```
inline bool YnPrint(bool flag)
```

- `flag` が `true` のとき `Yes`、`false` のとき `No` を出力します。
- 戻り値として `flag` をそのまま返します。

**計算量**

- $\textrm{O}(1)$

---

#### YNPrint

```
inline bool YNPrint(bool flag)
```

- `flag` が `true` のとき `YES`、`false` のとき `NO` を出力します。
- 戻り値として `flag` をそのまま返します。

**計算量**

- $\textrm{O}(1)$

---

### コンテナ操作

#### Sort

```
template<typename Container>
inline void Sort(Container &container)
```

- コンテナを昇順にソートします。

**計算量**

- $\textrm{O}(N \log N)$

---

#### ReverseSort

```
template<typename Container>
inline void ReverseSort(Container &container)
```

- コンテナを降順にソートします。

**計算量**

- $\textrm{O}(N \log N)$

---

#### Reverse

```
template<typename Container>
inline void Reverse(Container &container)
```

- コンテナの要素を反転します。

**計算量**

- $\textrm{O}(N)$

---

### ビット操作

#### PopCount

```
template<typename Value>
inline int PopCount(const Value &value)
```

- `value` のビット表現において、`1` のビットの個数を返します。

**計算量**

- $\textrm{O}(1)$

---

### 除算操作

#### Floor

```
template<typename Value>
inline Value Floor(Value numerator, Value denominator)
```

- `numerator / denominator` の結果を負の無限大方向に切り捨てた値を返します。
- 負の数に対しても正しく動作します。

**計算量**

- $\textrm{O}(1)$

---

#### Ceil

```
template<typename Value>
inline Value Ceil(Value numerator, Value denominator)
```

- `numerator / denominator` の結果を正の無限大方向に切り上げた値を返します。
- 負の数に対しても正しく動作します。

**計算量**

- $\textrm{O}(1)$

---

### 二分探索

#### LowerBoundIndex

```
template<typename Value>
inline int LowerBoundIndex(const vector<Value> &container, const Value &value)
```

- ソート済みコンテナにおいて、`value` 以上の最小の要素のインデックスを返します。

**計算量**

- $\textrm{O}(\log N)$

---

#### UpperBoundIndex

```
template<typename Value>
inline int UpperBoundIndex(const vector<Value> &container, const Value &value)
```

- ソート済みコンテナにおいて、`value` より大きい最小の要素のインデックスを返します。

**計算量**

- $\textrm{O}(\log N)$

---

### 範囲チェック

#### Between

```
template<typename Value>
inline bool Between(const Value &lower, const Value &x, const Value &higher)
```

- $lower \le x \le higher$ が成り立つかを判定します。

**計算量**

- $\textrm{O}(1)$

---

#### InGrid

```
template<typename Value>
inline bool InGrid(const Value &y, const Value &x, const Value &ymax, const Value &xmax)
```

- 座標 $(y, x)$ が $[0, ymax) \times [0, xmax)$ の範囲内にあるかを判定します。

**計算量**

- $\textrm{O}(1)$

---

### その他のユーティリティ

#### Median

```
template<typename Value>
inline Value Median(const Value &a, const Value &b, const Value &c)
```

- 3つの値 $a, b, c$ の中央値を返します。

**計算量**

- $\textrm{O}(1)$

---

#### Except

```
template<typename Value>
inline Value Except(Value &src, Value &cond, Value &excp)
```

- `src == cond` のとき `excp` を返し、そうでなければ `src` を返します。

**計算量**

- $\textrm{O}(1)$

---

### 更新系関数

#### chmin

```
template<class Value>
bool chmin(Value &src, const Value &cmp)
```

- `src > cmp` のとき、`src` を `cmp` で更新して `true` を返します。
- そうでなければ何もせず `false` を返します。

**計算量**

- $\textrm{O}(1)$

---

#### chmax

```
template<class Value>
bool chmax(Value &src, const Value &cmp)
```

- `src < cmp` のとき、`src` を `cmp` で更新して `true` を返します。
- そうでなければ何もせず `false` を返します。

**計算量**

- $\textrm{O}(1)$

---

### 最小値・最大値

#### min

```
template<typename Value>
inline Value min(vector<Value> &v)
```

- 配列 `v` の最小値を返します。

**計算量**

- $\textrm{O}(N)$

---

#### max

```
template<typename Value>
inline Value max(vector<Value> &v)
```

- 配列 `v` の最大値を返します。

**計算量**

- $\textrm{O}(N)$

---

## 定数

### 方向ベクトル

```
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, -1, 0, 1};
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
```

- グリッド上での4方向・8方向移動のための方向ベクトルです。
- 4方向: 右、上、左、下
- 8方向: 右、右上、上、左上、左、左下、下、右下

---

### adjacent

```
vector<pair<int, int>> adjacent(int current_y, int current_x, int max_y, int max_x, bool dir_8 = false)
```

- 座標 $(current\_y, current\_x)$ に隣接する有効な座標のリストを返します。
- `dir_8` が `true` のとき8方向、`false` のとき4方向の隣接座標を返します。
- グリッドサイズは $[0, max\_y) \times [0, max\_x)$ です。

**計算量**

- $\textrm{O}(1)$

---

## ストリーム演算子のオーバーロード

### pair の入出力

```
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
```

- `pair` の入出力を簡潔に記述できるようにします。
- 出力形式: `first second`
- 入力形式: `first second`

---

### vector の入出力

```
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)

template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> &v)

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
```

- `vector` の入出力を簡潔に記述できるようにします。
- 1次元ベクトル出力: 要素をスペース区切りで出力
- 2次元ベクトル出力: 各行を改行区切りで出力
- 入力: サイズ分の要素を読み込み

---

### set の出力

```
template <typename T>
ostream &operator<<(ostream &os, set<T> &v)
```

- `set` の要素をスペース区切りで出力します。

---

## ベクトル操作

### AssembleVectorPair

```
template<typename T1, typename T2>
vector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2> &v2)
```

- 2つのベクトル `v1`, `v2` を `pair` のベクトルに変換します。

**制約**

- `v1.size() == v2.size()`

**計算量**

- $\textrm{O}(N)$

---

### DisassembleVectorPair

```
template<typename T1, typename T2>
pair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1, T2>> &v)
```

- `pair` のベクトルを2つの独立したベクトルに分解します。

**計算量**

- $\textrm{O}(N)$

---

### DisassembleVectorTuple

```
template<typename T1, typename T2, typename T3>
tuple<vector<T1>, vector<T2>, vector<T3>> DisassembleVectorTuple(vector<tuple<T1, T2, T3>> &v)
```

- `tuple` のベクトルを3つの独立したベクトルに分解します。

**計算量**

- $\textrm{O}(N)$

---

## 入力補助

### InputVectorPair

```
template<typename T1 = int, typename T2 = T1>
pair<vector<T1>, vector<T2>> InputVectorPair(int size)
```

- `size` 個の `pair` を標準入力から読み込み、2つのベクトルとして返します。

**計算量**

- $\textrm{O}(N)$

---

### InputVectorTuple

```
template<typename T1 = int, typename T2 = T1, typename T3 = T1>
tuple<vector<T1>, vector<T2>, vector<T3>> InputVectorTuple(int size)
```

- `size` 個の `tuple` を標準入力から読み込み、3つのベクトルとして返します。

**計算量**

- $\textrm{O}(N)$

---
