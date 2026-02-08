---
title: Rerooting DP - 全方位木DP
documentation_of: ../Library/Tree/RerootingDP.hpp
---

# Rerooting DP - 全方位木DP

木のすべての頂点を根としたときの DP の値を効率的に計算するデータ構造です。

各頂点を根とした場合の DP を愚直に計算すると $\textrm{O}(N^2)$ かかりますが、全方位木 DP を用いることで $\textrm{O}(N)$ で計算できます。

## Function

### Constructor (辺属性のみ)

```
RerootingDP(Graph<CostType> &tree, Fsub merge, Gsub add, const Monoid monoid_identity, Vertex r = 0)
```

- 木 `tree` に対して全方位木 DP を行います（辺属性のみを考慮）。
- `merge`: `(Monoid, Monoid) -> Monoid` - モノイド同士の二項演算
- `add`: `(Monoid, CostType) -> Monoid` - モノイドと辺コストの二項演算
- `monoid_identity`: モノイドの単位元
- `r`: 初期の根（デフォルトは頂点 0）

**型定義**
- `Fsub = function<Monoid(Monoid, Monoid)>`
- `Gsub = function<Monoid(Monoid, CostType)>`

**制約**

- $1 \le N \le 10^5$
- `merge` と `add` はモノイドの演算を満たす

**計算量**

- $\textrm{O}(N)$

---

### Constructor (頂点属性を含む)

```
RerootingDP(Graph<CostType> &tree, F merge, G add, H finalize, const Monoid monoid_identity, Vertex r = 0)
```

- 木 `tree` に対して全方位木 DP を行います（頂点属性を含む）。
- `merge`: `(Monoid, Monoid, Vertex) -> Monoid` - モノイド同士の二項演算（頂点情報を利用）
- `add`: `(Monoid, CostType, Vertex) -> Monoid` - モノイドと辺コストの二項演算（頂点情報を利用）
- `finalize`: `(Monoid, Vertex) -> Monoid` - 頂点が根のときの最終処理
- `monoid_identity`: モノイドの単位元
- `r`: 初期の根（デフォルトは頂点 0）

**型定義**
- `F = function<Monoid(Monoid, Monoid, Vertex)>`
- `G = function<Monoid(Monoid, CostType, Vertex)>`
- `H = function<Monoid(Monoid, Vertex)>`

**制約**

- $1 \le N \le 10^5$
- `merge`, `add`, `finalize` はモノイドの演算を満たす

**計算量**

- $\textrm{O}(N)$

---

### get_all_answer

```
vector<Monoid> &get_all_answer()
```

- 全頂点に関する DP の結果の配列を取得します。
- 配列の $i$ 番目の要素は、頂点 $i$ を根としたときの DP の値です。

**計算量**

- $\textrm{O}(1)$

---

### operator[]

```
Monoid operator[](Vertex v)
const Monoid operator[](Vertex v) const
```

- 頂点 $v$ を根としたときの DP の値を返します。

**計算量**

- $\textrm{O}(1)$

---

### Print

```
void Print() const
```

- デバッグ用に DP テーブルの内容を標準エラー出力に出力します。

**計算量**

- $\textrm{O}(N)$

---
