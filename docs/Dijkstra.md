---
title: Dijkstra - 単一始点最短距離
documentation_of: ../library/Graph/Dijkstra.hpp
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

単一始点最短距離問題をDijkstra法を用いて求める。
負辺がある場合でも、ポテンシャルを適切に与えることで求めることが可能。

## Variable

- private
    - `Dist` : 始点`Start`からの距離(存在しない場合は`G.INF`)
    - `Potential` : ポテンシャル(初期値`0`)
    - `PrevVertex` : 各頂点の最短経路上における前の頂点(存在しない場合は`-1`)
    - `PrevEdge` : 各頂点の最短経路上における前の辺(存在しない場合は`-1`)
    - `Start` : 始点

## Function

- `Dijkstra(Graph G)` : `Graph`で初期化する。
- `Dijkstra(Graph G, Vertex Start)` : `Graph`で初期化し、頂点`Start`を始点として単一始点最短距離問題を解く。$O(E \log V)$
- `update_potential(vector<CostType> Potential)` : グラフのポテンシャル値を`Potential`で更新する。$O(V)$
- `build(Vertex Start)` : 頂点`Start`を始点として単一始点最短距離問題を解く。$O(E \log V)$
- `all(Vertex Start)` : 頂点`Start`を始点としたときの各頂点への最短経路を返す。$O(E \log V)$
- `dist(Vertex Start, Vertex Goal)` : 頂点`Start`から頂点`Goal`への最短距離を求める。頂点`Start`を始点とした最短距離が残っているなら$O(1)$、そうでなければ$O(E \log V)$
- `restore_edge(Vertex Goal)` : 頂点`Goal`から頂点`Start`への最短経路の辺を復元して返す。$O(V)$
- `print(bool DisplayINF, char Delimiter)` : 最短距離を文字`Delimiter`を区切り文字として出力する。$O(V)$
