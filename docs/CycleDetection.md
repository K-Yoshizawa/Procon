---
title: Cycle Detection - 閉路検出
documentation_of: ../Library/Graph/CycleDetection.hpp
---

# Cycle Detection - 閉路検出

頂点数 $V$ 辺数 $E$ の**無向**グラフに含まれる閉路を検出し、閉路を構成する辺のリストを返します。

```
vector<Edge<WeightType>> CycleDetection(Graph<WeightType> &G)
```

- グラフ $G$ に含まれる閉路を1つ検出し、その閉路を構成する辺のリストを返します。
- 閉路が存在しない場合は空の配列を返します。
- 複数の閉路が存在する場合、そのうちの $1$ つを返します。

**制約**

- $G$ は無向グラフ

**計算量**

- $\textrm{O}(V + E)$

**戻り値**

- 閉路を構成する辺のリスト(閉路上の順序で格納)
- 閉路が存在しない場合は空の配列

---
