---
title: Dijkstra - ダイクストラ法
documentation_of: ../library/Graph/Dijkstra.hpp
---

<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [['$', '$'] ],
 inlineMath: [['$', '$'] ],
 }
 });
</script>

### Abstract

グラフ $G$ に対する単一始点最短距離問題をダイクストラ法によって解く。

### Variable

- private
    - `m_dist` : 始点から各頂点への最短距離を表す。到達不可能の場合 `G.INF` が格納される。
    - `m_potential` : 各頂点のポテンシャルを表す。適切に設定することで負辺が存在するグラフに対してダイクストラ法を適用することができる。
    - `m_prev_vertex` : 各頂点の最短距離をとるパスにおいてその頂点の前に通る頂点番号。パスが存在しない場合、あるいは始点の場合は `-1` が格納される。

### Function

- `Dijkstra(GraphV &G)` : ダイクストラ法をグラフ $G$ で初期化する。
- `solve(Vertex s)` : グラフ $G$ に対して、頂点 `s` を始点として単一始点最短距離問題を解く。
    - 計算量 : $\textrm{O}(E \log V)$
    - 要件 : `s` は 0-index であること。
    - 戻り値 : 始点 `s` から各頂点への最短距離が格納された配列 `m_dist`
- `get()` : 各頂点への最短距離が格納された配列 `m_dist`
- `shortest_path(Vertex t)` : 頂点 `t` までの最短経路を取得する。
    - 計算量 : $\textrm{O}(V)$
    - 戻り値 : 頂点 `t` までの最短経路を頂点列として返す。経路が存在しない場合は空配列を返す。
- `operator[]` : 頂点 `v` までの最短距離を返す。