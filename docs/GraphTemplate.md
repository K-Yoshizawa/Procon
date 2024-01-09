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

## GraphV - 頂点集合グラフ

### Abstract

グラフを頂点集合(隣接リスト)で表現するもの。

### Variable

- private
    - `m_vertex_size` : グラフの頂点数
    - `m_edge_size` : グラフの辺数
    - `m_is_directed` : 有向グラフであるかのフラグ
    - `m_adj` : 隣接リスト形式で表されたグラフ本体
    - `m_indegree` : 各頂点の入次数(有向グラフのみ利用可能)
- public
    - `INF` : 無限大を表す値で、デフォルトでは `numeric_limits<CostType>::max() >> 2` が入る

### Function

- `GraphV(int vertex_size, bool directed = false)` : 頂点数 $V$ = `vertex_size` のグラフ $G$ を作成する。 `directed` を `true` に設定すると有向グラフとして作成する。
- `add(Vertex from, Vertex to, CostType cost = 1)` : $G$ に頂点 `from` から頂点 `to` に重み `cost` の辺を張る。
    - 引数 :
        - `from` : 辺の始点
        - `to` : 辺の終点
        - `cost = 1` : 辺の重み、省略すれば重み1として扱われる。
    - 要件 : `from` および `to` は 0-index であること。
- `input(int edge_size, bool weighted = false, bool zero_index = false)` : $G$ に $E$ = `edge_size` 本の辺を入力させる。
    - 計算量 : $\textrm{O}(E)$
    - 引数 :
        - `weighted = false` : 読み込む辺が重み付きかを設定する。 `true` にすれば重み付き辺を読み込むことができる。
        - `zero_index = false` : 読み込む辺が 0-indexとして与えられるかを設定する。 `true` にすれば0-indexとして読み込む。
- `size()` : 頂点数 $V$ (= `m_vertex_size`)を返す。
- `outdegree(Vertex v)` : 頂点 `v` の出次数を返す。無向グラフの場合は単に頂点 `v` の次数を返す。
- `indegree(Vertex v)` : 頂点 `v` の入次数を返す。無向グラフの場合は単に頂点 `v` の次数を返す。
- `source()` : $G$ の源点(入次数が0である頂点)を返す。無向グラフの場合は $G$ の孤立点(次数が0である頂点)を返す。
    - 計算量 : $\textrm{O}(V)$
- `sink()` : $G$ の沈点(出次数が0である頂点)を返す。無向グラフの場合は $G$ の孤立点(次数が0である頂点)を返す。
    - 計算量 : $\textrm{O}(V)$
- `leaf()` : $G$ の葉頂点(次数が1である頂点)を返す。有向グラフの場合は入次数が1である頂点を返す。
    - 計算量 : $\textrm{O}(V)$
- `get_adj(Vertex v)` : 頂点 `v` の隣接リストを返す。
- `reverse()` : $G$ の有向辺をすべて反転させたグラフ $G^\prime$ を返す。
    - 計算量 : $\textrm{O}(E)$
    - 要件 : $G$ が有向グラフであること。
- `sort()` : $G$ をトポロジカルソートした頂点列を返す。
    - 計算量 : $\textrm{O}(V)$
    - 要件 : $G$ が有向グラフであること。   
- `operator[]` : `get_adj(v)` を返す。
