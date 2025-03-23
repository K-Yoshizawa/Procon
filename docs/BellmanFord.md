---
title: Bellman Ford - ベルマンフォード法
documentation_of: ../Library/Graph/BellmanFord.hpp
---

# Bellman Ford - ベルマンフォード法

$N$ 頂点 $M$ 辺のグラフにおける単一始点最短経路問題をベルマンフォード法を用いて解きます。

## Function

### Constructor

```
BellmanFord(Graph<CostType> &graph, Vertex s = -1)
```

- $N$ 頂点 $M$ 辺のグラフで初期化をします。
- `s` を指定すると、初期化後に `Solve(s)` を呼び出します。

**制約**

- $-1 \le s \le N$

**計算量**

- $\textrm{O}(N)$

---

### Reachable

```
inline bool Reachable(const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ に到達可能であるかを判定します。

**制約**

- $0 \le t \lt N$
- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

---

### Distance

```
inline CostType Distance(const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ への最短経路長を返します。
- 頂点 $t$ に到達不能であるとき、`INF` を返します。

**制約**

- $0 \le t \lt N$
- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

---

### Negative

```
inline bool Negative() const
```

- $G$ が負閉路を含むかを判定します。

**制約**

- `Solve()` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

---

### Solve

```
void Solve(Vertex s)
```

- 頂点 $s$ を始点とした単一始点最短経路問題を解きます。

**制約**

- $0 \le s \lt N$

**計算量**

- $\textrm{O}(NM)$

---

### operator[]

```
(1) CostType operator[](const Vertex &t)
(1) const CostType operator[](const Vertex &t) const 
```

- `Distance(t)` を返します。

**制約**

- $0 \le t \lt N$
- `Solve(s)` が $1$ 回以上呼び出されている

**計算量**

- $\textrm{O}(1)$

