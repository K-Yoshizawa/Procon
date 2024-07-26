---
title: Graph - グラフ
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

## Graph - グラフ

### Abstract

グラフを頂点集合(隣接リスト)で表現するもの。

### Member Variable

- private
    - `vertex_` : グラフの頂点数 $V$
    - `edge_` : グラフの辺数 $E$
    - `adjacent_list_` : 隣接リスト形式で表されたグラフ本体
    - `directed_flag_` : 有向グラフであるかのフラグ
    - `inf_` : 十分大きな定数
- public

### Function

- `Graph(int vertex_size, bool directed = false)` : 頂点数 $V$ = `vertex_size` のグラフ $G$ を作成する。 `directed` を `true` に設定すると有向グラフとして作成する。
- `get_vertex_size()` : $G$ の頂点数 $V$ を返す。
- `get_edge_size()` : $G$ の辺数 $E$ を返す。
- `get_inf()` : $G$ の十分大きな定数 `INF` を返す。
- `add(Vertex s, Vertex t, CostType c = 1)` : $G$ において、 $2$ 頂点 `s` `t` 間に重み `c` の辺を張る。有向グラフの場合は `s` から `t` への有向辺が、無向グラフの場合は `s` `t` 間の無向辺が張られる。
    - 引数 :
        - `s` : 始点の頂点(有向辺)
        - `t` : 終点の頂点(有向辺)
        - `c = 1` : 重み
    - 要件 : `s` および `t` は 0-index であること。
- `input(int edge_count, bool weighted_graph = false, bool one_index = true)` : $G$ に $E =$ `edge_count` 本の辺を入力させる。
    - 引数 :
        - `edge_count` : 入力する辺数 $E$
        - `weighted_graph = false` : 読み込む辺が重み付きかを設定する。 `true` にすれば重み付き辺を読み込むことができる。
        - `one_index = true` : 読み込む辺が 1-index として与えられるかを設定する。 `false` にすれば 0-index として読み込む。
- `operator[v]` : 頂点 `v` に接続している辺集合を返す。

## 補助関数

- `convert_to_matrix(Graph<CostType> &G, CostType not_adjacent_value = 0)` : $G$ を隣接行列に変換した $V \times V$ 行列を返す。
    - 引数 :
        - `G` : 頂点数 $V$ のグラフ
        - `not_adjacent_value = 0` : $2$ 頂点 $u, v$ が隣接していないときに設定する値
    - 注意 :
        - 自己ループや多重辺が含まれるグラフにおける動作は未定義である。
- `reverse(Graph<CostType> &G)` : $G$ の辺を逆転させた有向グラフ $G^R$ を返す。
    - 引数 :
        - `G` : 頂点数 $V$ のグラフ
    - 注意 :
        - 無向グラフに対する動作は未定義である。
- `convert_to_edge_set(Graph<CostType> &G, bool sorted = true)` : $G$ の辺集合を返す。
    - 引数 :
        - `G` : 頂点数 $V$ のグラフ
        - `bool sorted = true` : 辺集合をソートした状態で返すかを設定する。設定した場合、辺の重みの昇順にソートされた状態で返される。