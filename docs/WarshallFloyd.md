---
title: Warshall Floyd - ワーシャルフロイド法
documentation_of: ../Library/Graph/WarshallFloyd.hpp
---

# Warshall Floyd - ワーシャルフロイド法

頂点数 $V$ 辺数 $E$ のグラフにおける全点対最短経路問題をワーシャルフロイド法を用いて解きます。

## Function

### Constructor

```
(1) WarshallFloyd(Graph<WeightType> &graph)
(2) WarshallFloyd(vector<vector<WeightType>> &A)
```

- (1) グラフ $G$ を頂点数 $V$ 辺数 $E$ の `graph` で初期化します。
- (2) グラフ $G$ を $V \times V$ の隣接行列 $A$ で初期化をします。
    - 厳密には、行列 $A$ は次の要件を満たす $N \times N$ 行列である必要があります。
    - $A_{i, j}$ は頂点 $i$ から頂点 $j$ に辺が存在するときその辺の重み(重みなしグラフの場合は $1$)、存在しないとき $\infty$

**制約**

**計算量**

- $\textrm{O}(V^3)$

---

### Reachable

```
inline bool Reachable(const Vertex &s, const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ に到達可能であるかを判定します。

**制約**

- $0 \le s, t \lt V$

**計算量**

- $\textrm{O}(1)$

---

### Distance

```
inline WeightType Distance(const Vertex &s, const Vertex &t) const
```

- 頂点 $s$ から頂点 $t$ への最短経路長を返します。
- 頂点 $t$ に到達不能であるとき、`INF` を返します。

**制約**

- $0 \le s, t \lt V$

**計算量**

- $\textrm{O}(1)$

---

### NegativeCycle

```
inline bool NegativeCycle() const
```

- $G$ が負閉路を含むかを判定します。

**計算量**

- $\textrm{O}(1)$

---

### operator[]

```
(1) vector<WeightType> &operator[](const Vertex &s)
(1) const vector<WeightType> &operator[](const Vertex &s) const 
```

- 頂点 $s$ を始点とする各頂点への最短経路長の配列を返します。
- `wf[s][t]` は `Distance(s, t)` と同値です。

**制約**

- $0 \le s \lt V$

**計算量**

- $\textrm{O}(1)$

