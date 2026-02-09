---
title: Kruskal - クラスカル法
documentation_of: ../Library/Graph/Kruskal.hpp
---

# Kruskal - クラスカル法

無向連結グラフの最小全域木(Minimum Spanning Tree)をクラスカル法により求めます。

辺を重みの小さい順にソートし、Union-Find を用いて閉路を作らないように辺を追加していきます。

## Function

### Constructor

```
Kruskal(Graph<CostType> &graph)
```

- $N$ 頂点 $M$ 辺の無向連結グラフ $G$ を `graph` で初期化し、$G$ の最小全域木をクラスカル法により構築します。
- $G$ が無向グラフでない場合や、連結でない場合の挙動は未定義です。

**制約**

- $G$ は無向グラフ
- $G$ は連結
- $1 \le N \le 10^5$
- $0 \le M \le 10^5$

**計算量**

- $\textrm{O}(M \log M)$

---

### GetEdgeSet

```
vector<Edge<CostType>> &GetEdgeSet()
```

- 最小全域木を構成する辺集合を返します。

**計算量**

- $\textrm{O}(1)$

---

### GetCost

```
CostType GetCost() const
```

- 最小全域木の総コスト(辺の重みの総和)を返します。

**計算量**

- $\textrm{O}(1)$

---
