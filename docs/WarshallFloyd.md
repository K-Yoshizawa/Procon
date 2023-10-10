---
title: Warshall Floyd - 全点対間最短距離
documentation_of: ../library/Graph/WarshallFloyd.hpp
---

<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [['$', '$'] ],
 displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
 }
 });
</script>

## Abstract

全点対間最短距離問題をWarshall Floyd法を用いて求める。

## Variable

- private
    - `NegativeCycle` : 負の閉路が存在するか
    - `Size` : 頂点数
    - `Dist` : 隣接行列形式で表された最短距離。`Dist[i][j]`は頂点`i`から頂点`j`への最短距離を表している。

## Function

- `WarshallFloyd(Graph G)` : `Graph`で初期化し、全点対間最短距離問題を解く。$O(V^3)$
- `WarshallFloyd(vector<vector<CostType>> M)` : 隣接行列`M`で初期化し、全点対間最短距離問題を解く。$O(V^3)$
- `negative()` : 負閉路を含むかを返す。
- `dist(Vertex Start, Vertex Goal)` : 頂点`Start`から頂点`Goal`への最短距離を返す。$O(1)$
- `print(CostType NotAdjacent, bool DisplayINF)` : 隣接行列を出力する。隣接していない頂点への距離を`INF`として表示することも可能。$O(V^2)$
