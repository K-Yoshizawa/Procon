---
title: Low Link - 関節点と橋の検出
documentation_of: ../Library/Graph/LowLink.hpp
---

# Low Link - 関節点と橋の検出

無向グラフの関節点（articulation vertex）と橋（bridge）を検出するアルゴリズムです。

- **関節点**: その頂点を取り除くとグラフの連結成分数が増加する頂点
- **橋**: その辺を取り除くとグラフの連結成分数が増加する辺

DFS により各頂点の訪問順序（ord）と後退辺を考慮した最小到達順序（low）を計算することで、$\textrm{O}(\lvert V \rvert + \lvert E \rvert)$ で検出できます。

## Function

### Constructor

```
LowLink(Graph<CostType> &graph)
```

- 無向グラフ `graph` に対して Low Link アルゴリズムを実行します。
- 関節点と橋を事前計算します。

**制約**

- $G$ は無向グラフ
- $1 \le \lvert V \rvert \le 10^5$
- $0 \le \lvert E \rvert \le 10^5$

**計算量**

- $\textrm{O}(\lvert V \rvert + \lvert E \rvert)$

---

### ArticulationVertex

```
vector<Vertex> &ArticulationVertex()
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

- DFS における頂点 $v$ の入り時刻と出時刻を返します。
- 部分木判定などに使用できます。

**計算量**

- $\textrm{O}(1)$

---
