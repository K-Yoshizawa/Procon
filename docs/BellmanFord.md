---
title: Bellman Ford - ベルマンフォード法
documentation_of: ../Library/Graph/BellmanFord.hpp
---

# Bellman Ford - ベルマンフォード法

頂点数 $V$ 辺数 $E$ のグラフにおける単一始点最短経路問題をベルマンフォード法を用いて解きます。

## Function

### Constructor

```
BellmanFord(Graph<WeightType> &graph, Vertex s = -1)
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

### NegativeCycle

```
inline bool NegativeCycle() const
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

- $0 \le s \lt V$

**計算量**

- $\textrm{O}(VE)$

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

