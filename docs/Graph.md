---
title: Graph - グラフテンプレート
documentation_of: ../Library/Graph/Graph.hpp
---

# Graph - グラフテンプレート

$n$ 頂点の無向 / 有向グラフを扱うテンプレートです。

## Function

### Constructor

```
Graph<CostType>(int n)
```

- $n$ 頂点 $0$ 辺のグラフを構築します。
- 頂点には $0, 1, \dots, n - 1$ の番号が振られているとします。
- `CostType` は辺の重みの型を表します。省略した場合は `int32_t` となります。

**制約**

- $0 \le n \le 10^6$

**計算量**

- $\textrm{O}(n)$

---

### AddUndirectedEdge

```
void AddUndirectedEdge(Vertex u, Vertex v, CostType w = 1)
```

- $2$ 頂点 $u, v$ 間に重み $w$ の無向辺を張ります。
- 重み $w$ は省略することが可能です。省略した場合は重みは $1$ となります。

**制約**

- $0 \le u, v \lt n$
- $w$ は `CostType` 型で表現できる値であること

**計算量**

- $\textrm{O}(1)$

---

### AddDirectedEdge

```
void AddDirectedEdge(Vertex u, Vertex v, CostType w = 1)
```

- 頂点 $u$ から頂点 $v$ に重み $w$ の有向辺を張ります。
- 重み $w$ は省略することが可能です。省略した場合は重みは $1$ となります。

**制約**

- $0 \le u, v \lt n$
- $w$ は `CostType` 型で表現できる値であること

**計算量**

- $\textrm{O}(1)$

---

### VertexSize

```
inline size_t VertexSize() const
```

- グラフ $G$ の頂点数を取得します。

**計算量**

- $\textrm{O}(1)$

---

### operator[]

```
(1) vector<Edge<CostType>> &operator[](const int v)
(1) const vector<Edge<CostType>> &operator[](const int v) const
```

- 頂点 $v$ から出次している辺の一覧を取得します。

```
(1) for(auto e : G[u])
(2) for(int v : G[u])
```

- (1) $G$ の頂点 $u$ から出次している**辺**の一覧(`std::vector<Edge<CostType>>`)を取得します。
- (2) $G$ の頂点 $u$ に隣接している頂点 $v$ の一覧(`std::vector<Vertex>`)を取得します。

**制約**

- $0 \le v \lt n$

**計算量**

- $\textrm{O}(1)$

