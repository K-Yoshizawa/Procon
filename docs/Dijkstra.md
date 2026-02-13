---
title: Dijkstra - ダイクストラ法
documentation_of: ../Library/Graph/Dijkstra.hpp
---

# Dijkstra - ダイクストラ法

頂点数 $V$ 辺数 $E$ のグラフにおける単一始点最短経路問題をダイクストラ法を用いて解きます。

## Function

### Constructor

```
Dijkstra(Graph<WeightType> &graph, Vertex s = -1)
```

- グラフ $G$ を頂点数 $V$ 辺数 $E$ の `graph` で初期化します。
- 始点頂点 $s$ を指定すると、初期化後に `Solve(s)` を呼び出します。

**制約**

- $-1 \le s \lt V$

**計算量**

- $\textrm{O}(V)$

---

### Reachable

```
inline bool Reachable(const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ に到達可能であるかを判定します。

**制約**

- $0 \le t \lt V$
- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

---

### Distance

```
inline WeightType Distance(const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ への最短経路長を返します。
- 頂点 $t$ に到達不能であるとき、`INF` を返します。

**制約**

- $0 \le t \lt V$
- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

---

### Path

```
vector<Edge<WeightType>> Path(const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ への最短経路を辺の列として返します。
- 最短経路が複数ある場合、そのうちの $1$ つを返します。
- 頂点 $t$ に到達不能であるとき空列を返します。

**制約**

- $0 \le t \lt V$
- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(V)$

---

### Solve

```
void Solve(Vertex s)
```

- 頂点 $s$ を始点とした単一始点最短経路問題を解きます。

**制約**

- $0 \le s \lt V$

**計算量**

- $\textrm{O}((V + E) \log V)$

---

### operator[]

```
(1) WeightType operator[](const Vertex &t)
(2) const WeightType operator[](const Vertex &t) const 
```

- `Distance(t)` を返します。

**制約**

- $0 \le t \lt V$
- `Solve(s)` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

