---
title: Union-Find - 素集合データ構造
documentation_of: ../Library/DataStructure/UnionFind.hpp
---

# Union-Find - 素集合データ構造

$n$ 頂点の無向グラフに対し、

- $2$ 頂点を結ぶ辺の追加
- $2$ 頂点が連結であるかの判定

をならし $\textrm{O}(\alpha(n))$ 時間で処理することができるデータ構造です。

## Function

### Constructor

```
UnionFind(size_t n)
```

- $n$ 頂点 $0$ 辺の無向グラフを構築します。
- 頂点には $0, 1, \dots, n - 1$ の番号が振られているとします。

**制約**

- $0 \le n \le 10^6$

**計算量**

- $\textrm{O}(n)$

---

### Find

```
int Find(const int k)
```

- 頂点 $k$ が属する連結成分の代表頂点を取得します。
- 内部処理として経路圧縮を行います。

**制約**

- $0 \le k \lt n$

**計算量**

- ならし $\textrm{O}(\alpha(n))$

---

### Same

```
bool Same(const int x, const int y)
```

- 頂点 $x$ と頂点 $y$ が連結であるかを判定します。
- 頂点 $x$ と頂点 $y$ が連結であるとき `true` を返します。

**制約**

- $0 \le x, y \lt n$

**計算量**

- ならし $\textrm{O}(\alpha(n))$

---

### Unite

```
bool Unite(int x, int y)
```

- 頂点 $x$ と頂点 $y$ の間に辺 $(x, y)$ を追加します。
- 辺 $(x, y)$ の追加により頂点 $x$ と頂点 $y$ が連結になったとき `true` を返します。

**制約**

- $0 \le x, y \lt n$

**計算量**

- ならし $\textrm{O}(\alpha(n))$

---

### Size

```
size_t Size(int k)
```

- 頂点 $k$ の属する連結成分の頂点数を返します。

**制約**

- $0 \le k \lt n$

**計算量**

- ならし $\textrm{O}(\alpha(n))$

---

### Group

```
vector<vector<int>> Group()
```

- すべての連結成分に含まれる頂点の一覧を返します。

**計算量**

- ならし $\textrm{O}(n \alpha(n))$

---