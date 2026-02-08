---
title: Graph Utilities - グラフユーティリティ
documentation_of: ../Library/Graph/GraphMisc.hpp
---

# Graph Utilities - グラフユーティリティ

グラフ構造を変換・操作するためのユーティリティ関数群です。

## Function

### ConvertEdgeSet

```
template<typename CostType>
vector<Edge<CostType>> ConvertEdgeSet(const Graph<CostType> &G)
```

- グラフ $G$ の辺集合を配列として取得します。
- 無向グラフの場合、各辺は1回のみ含まれます（重複排除）。

**制約**

- $1 \le \lvert V \rvert \le 10^5$
- $0 \le \lvert E \rvert \le 10^5$

**計算量**

- $\textrm{O}(\lvert V \rvert + \lvert E \rvert)$

**戻り値**

- グラフの辺のリスト

---

### ConvertDistanceMatrix

```
template<typename CostType>
vector<vector<CostType>> ConvertDistanceMatrix(const Graph<CostType> &G)
```

- グラフ $G$ を距離行列（隣接行列）に変換します。
- 辺が存在しない場合は `INF` が設定されます。
- 自己ループは距離 $0$ として設定されます。

**制約**

- $1 \le \lvert V \rvert \le 10^3$（メモリ制約に注意）

**計算量**

- $\textrm{O}(\lvert V \rvert^2)$

**戻り値**

- $\lvert V \rvert \times \lvert V \rvert$ の距離行列

---

### ReverseGraph

```
template<typename CostType>
Graph<CostType> ReverseGraph(const Graph<CostType> &G)
```

- 有向グラフ $G$ のすべての辺の向きを反転したグラフを返します。
- 辺 $(u, v)$ は辺 $(v, u)$ になります。

**制約**

- $1 \le \lvert V \rvert \le 10^5$
- $0 \le \lvert E \rvert \le 10^5$

**計算量**

- $\textrm{O}(\lvert V \rvert + \lvert E \rvert)$

**戻り値**

- 辺を反転したグラフ

---
