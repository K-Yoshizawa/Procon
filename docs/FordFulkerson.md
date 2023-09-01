---
title: Ford-Fulkerson - 最大流
documentation_of: ../latest/Graph/FordFulkerson.hpp
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

最大流問題をFord-Fulkerson法を用いて求める。

## Variable



## Function

- `FordFulkerson(Graph G)` : `Graph`で初期化する。
- `solve(Vertex Source, Vertex Sink)` : 頂点`Source`から頂点`Sink`への最大流を求める。$O(FE)$