---
title: Strongly Connected Components - 強連結成分分解
documentation_of: ../../latest/Graph/StronglyConnectedComponents.hpp
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

有向グラフ $G$ に対して強連結成分分解を行う。

### Variable

- private
    - `m_belong` : 各頂点が所属する連結成分番号を表す。
    - `m_member` : 各連結成分の持つ頂点列を表す。

### Function

- `StronglyConnectedComponents(GraphV &G)` : 有向グラフ $G$ に対して強連結成分分解を行う。
- `where(Vertex v)` : 頂点 `v` が所属する連結成分番号を返す。
- `same(Vertex u, Vertex v)` : 頂点 `u` と頂点 `v` が同じ連結成分に含まれるかを判定する。
- `get()` : `m_member` を返す。
- `build()` : 強連結成分分解を行って圧縮されたグラフを返す。
    - 計算量 : $\textrm{O}(V + E)$
    - 戻り値 : 圧縮されたグラフ。このグラフは頂点0を始点としてトポロジカルソートされている。
- `operator[]` : `where` と同じ働きをする。
