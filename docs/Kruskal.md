---
title: Kruskal - 最小全域木
documentation_of: ../library/Graph/Kruskal.hpp
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

最小全域木問題をKruskal法を用いて求める。

## Function

- `Kruskal(Graph G)` : 最小全域木問題を解く。$O(E \log V)$
- `get()` : 最小全域木のコストを返す。
