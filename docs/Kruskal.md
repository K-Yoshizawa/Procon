---
title: Kruskal's Algorithm - クラスカル法
documentation_of: ../Library/Graph/Kruskal.hpp
---

# Kruskal's Algorithm - クラスカル法

グラフの最小全域木（Minimum Spanning Tree, MST）をクラスカル法により求めます。

辺を重みの小さい順にソートし、Union-Find を用いて閉路を作らないように辺を追加していきます。

## Function

### Constructor

```
Kruskal(Graph<CostType> &graph)
```

- 無向グラフ `graph` の最小全域木を構築します。
- グラフが連結でない場合は、最小全域森（Minimum Spanning Forest）を構築します。

**制約**

- $G$ は無向グラフ
- $1 \le \lvert V \rvert \le 10^5$
- $0 \le \lvert E \rvert \le 10^5$

**計算量**

- $\textrm{O}(\lvert E \rvert \log \lvert E \rvert)$

---

### GetEdgeSet

```
vector<Edge<CostType>> &GetEdgeSet()
```

- 最小全域木（または最小全域森）を構成する辺のリストを返します。

**計算量**

- $\textrm{O}(1)$

---

### GetCost

```
CostType GetCost() const
```

- 最小全域木（または最小全域森）の総コスト（辺の重みの合計）を返します。

**計算量**

- $\textrm{O}(1)$

---
