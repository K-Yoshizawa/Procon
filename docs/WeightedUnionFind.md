---
title: Weighted Union-Find - 重み付き素集合データ構造
documentation_of: ../Library/DataStructure/WeightedUnionFind.hpp
---

# Weighted Union-Find - 重み付き素集合データ構造

$N$ 頂点からなる無向グラフに対して、辺の重みを管理しながら連結成分を管理するデータ構造です。

各要素間の重み（ポテンシャル）をアーベル群 $A$ で管理します。

## Function

### Constructor

```
WeightedUnionFind(int n)
```

- 頂点数 $n$ で重み付き Union Find を初期化します。
- 初期状態では、すべての頂点は独立しており、各頂点の重みは $0$ です。

**制約**

- $1 \le n \le 10^6$

**計算量**

- $\textrm{O}(n)$

---

### Find

```
int Find(const int k)
```

- 頂点 $k$ が属する連結成分の代表元を返します。
- 経路圧縮を行いながら、頂点 $k$ までの重みを更新します。

**制約**

- $0 \le k < n$

**計算量**

- $\textrm{O}(\alpha(n))$ （$\alpha$ はアッカーマン関数の逆関数）

---

### Weight

```
Abel Weight(const int k)
```

- 頂点 $k$ の代表元からの重み（ポテンシャル）を返します。

**制約**

- $0 \le k < n$

**計算量**

- $\textrm{O}(\alpha(n))$

---

### Diff

```
Abel Diff(const int x, const int y)
```

- 頂点 $x$ から頂点 $y$ への重みの差分 `Weight(y) - Weight(x)` を返します。

**制約**

- $0 \le x, y < n$

**計算量**

- $\textrm{O}(\alpha(n))$

---

### Same

```
bool Same(const int x, const int y)
```

- 頂点 $x$ と頂点 $y$ が同じ連結成分に属するかを判定します。

**制約**

- $0 \le x, y < n$

**計算量**

- $\textrm{O}(\alpha(n))$

---

### Unite

```
bool Unite(int x, int y, Abel w)
```

- 頂点 $x$ と頂点 $y$ を重み $w$ の辺で連結します。
- `Weight(y) - Weight(x) = w` となるように連結されます。
- 既に連結されている場合は `false` を返し、新たに連結された場合は `true` を返します。

**制約**

- $0 \le x, y < n$
- $w \in A$

**計算量**

- $\textrm{O}(\alpha(n))$

---