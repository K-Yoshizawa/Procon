---
title: Graph Template - グラフテンプレート
documentation_of: ../library/Graph/GraphTemplate.hpp
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
    - `ES, RES` : 辺集合、逆辺集合
    - `IL` : 接続リスト　各頂点に対して接続している辺を持つ
    - `AL` : 隣接リスト　各頂点に対して隣接している頂点を持つ
- public
    - `INF` : 無限大、自動で`numeric_limits<CostType>::max() / 2`となる

## Function

- `Graph(int VertexSize, bool isDirected)` : 頂点数 `VertexSize` で初期化する。このとき有向グラフとして作成するかを選択できる。デフォルトでは無向グラフを生成する。
- `add(Vertex Source, Vertex To, CostType Cost)` : 頂点 `Source` から頂点 `To` に重み `Cost` の辺を追加する。`Cost` は省略可能で、省略すると `1` になる。
- `matrix(CostType NotAdjacent)` : 隣接行列を生成して返す。隣接していない頂点への距離を`NotAdjacent`で指定可能。$O(E)$
- `vsize(), esize()` : 頂点数、辺数を返す。
- `incsize(Vertex v)` : 頂点 `v` の次数(出次数)を返す。
- `get_edgeset()` : 辺集合を返す。
- `get_incidentlist()` : 接続リストを返す。
- `get_incident(Vertex v)` : 頂点 `v` の接続リストを返す。
- `get_adjacentlist()` : 隣接リストを返す。
- `get_adjacent(Vertex v)` : 頂点 `v` の隣接リストを返す。
- `print_edgeset(bool OneIndex)` : 主にデバッグ用。辺集合の中身を出力する。$O(E)$
- `print_incidentlist(bool OneIndex)` : 主にデバッグ用。接続リストの中身を出力する。$O(E)$
- `print_matrix(CostType NotAdjacent, bool DisplayINF)` : 隣接行列を出力する。隣接していない頂点への距離を `INF` として表示することも可能。$O(V^2)$
