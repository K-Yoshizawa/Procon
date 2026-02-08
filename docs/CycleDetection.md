---
title: Cycle Detection - 閉路検出
documentation_of: ../Library/Graph/CycleDetection.hpp
---

# Cycle Detection - 閉路検出

無向グラフに含まれる閉路を検出し、閉路を構成する辺のリストを返します。

## Function

### CycleDetection

```
template<typename CostType>
vector<Edge<CostType>> CycleDetection(Graph<CostType> &G)
```

- グラフ $G$ に含まれる閉路を1つ検出し、その閉路を構成する辺のリストを返します。
- 閉路が存在しない場合は空の配列を返します。
- 複数の閉路が存在する場合、検出される閉路は不定です（DFS の探索順に依存）。

**制約**

- $G$ は無向グラフ
- $1 \le \lvert V \rvert \le 10^5$
- $0 \le \lvert E \rvert \le 10^5$

**計算量**

- $\textrm{O}(\lvert V \rvert + \lvert E \rvert)$

**戻り値**

- 閉路を構成する辺のリスト（閉路上の順序で格納）
- 閉路が存在しない場合は空の配列

---
