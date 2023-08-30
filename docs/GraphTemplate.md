---
title: Graph Template - グラフテンプレート
documentation_of: ../latest/Graph/GraphTemplate.hpp
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

グラフを扱うための基本テンプレート。

## Variable

- private
    - `CntVertex, CntEdge` : 頂点数、辺数
    - `isDirected` : 有向グラフか否か
    - `EdgeSet, RevEdgeSet` : 辺集合、逆辺集合
    - `IncidentList` : 各頂点の接続リスト
- public
    - `INF` : 無限大、自動で`numeric_limits<CostType>::max() / 2`となる

## Function

- `Graph(int VertexSize, bool isDirected)` : 頂点数`VertexSize`で初期化する。このとき有向グラフとして作成するかを選択できる。デフォルトでは無向グラフを生成する。
- `add(Vertex s, Vertex t, CostType w)` : 頂点`s`から頂点`t`に重み`w`の辺を追加する。`w`は省略可能。
- `matrix(CostType NotAdjacent)` : 隣接行列を生成して返す。隣接していない頂点への距離を`NotAdjacent`で指定可能。$O(E)$
- `print_edgeset(bool OneIndex)` : 主にデバッグ用。辺集合の中身を出力する。$O(E)$
- `print_matrix(CostType NotAdjacent, bool DisplayINF)` : 隣接行列を出力する。隣接していない頂点への距離を`INF`として表示することも可能。$O(V^2)$
