---
title: Ford-Fulkerson - 最大流
documentation_of: ../library/Graph/FordFulkerson.hpp
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

最小費用流問題をPrimal Dual法を用いて求める。

## Variable



## Function

- `PrimalDual(Graph G)` : `Graph`で初期化する。
- `solve(Vertex Start, Vertex Goal, CostType F)` : 頂点`Start`から頂点`Goal`へ流量`F`を流した時の最小費用流を求める。流せない場合、`-1`を返す。$O(FE \log V)$