---
title: Low Link - 関節点と橋
documentation_of: ../Library/Graph/LowLink.hpp
---

# Low Link - 関節点と橋

頂点数 $V$ 辺数 $E$ の無向グラフの関節点と橋を検出します。

- **関節点**: その頂点を取り除くとグラフの連結成分数が増加する頂点
- **橋**: その辺を取り除くとグラフの連結成分数が増加する辺

## Function

### Constructor

```
LowLink(Graph<CostType> &graph)
```

- グラフ $G$ を頂点数 $V$ 辺数 $E$ の `graph` で初期化し、関節点と橋を事前計算します。

**制約**

- $G$ は無向グラフ

**計算量**

- $\textrm{O}(V + E)$

---

### ArticulationPoint

```
vector<Vertex> &ArticulationPoint()
```

- グラフに含まれるすべての関節点のリストを返します。

**計算量**

- $\textrm{O}(1)$

---

### Bridge

```
vector<pair<Vertex, Vertex>> &Bridge()
```

- グラフに含まれるすべての橋のリストを返します。
- 各橋は頂点ペア $(u, v)$ として表現され、$u < v$ となるように正規化されています。

**計算量**

- $\textrm{O}(1)$

---

### EulerTour

```
pair<int, int> EulerTour(const Vertex v) const
```

- DFS における頂点 $v$ の入時刻と出時刻を返します。

**計算量**

- $\textrm{O}(1)$

---
