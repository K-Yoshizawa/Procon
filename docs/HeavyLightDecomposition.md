---
title: Heavy Light Decomposition - 重軽分解
documentation_of: ../Library/Tree/HeavyLightDecomposition.hpp
---

# Heavy Light Decomposition - 重軽分解

$n$ 頂点の根付き木 $T$ を $\textrm{O}(\log n)$ 個のパスの集合に分解します。

## Function

### Constructor

```
HeavyLightDecomposition(Graph<CostType> &tree, Vertex r = 0)
```

- 頂点 $r$ を根とする根付き木 $T$ に対して重軽分解を行います。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---

### LowestCommonAncestor

```
Vertex LowestCommonAncestor(Vertex u, Vertex v) const
```

- 頂点 $u$ と頂点 $v$ の最小共通祖先の頂点を求めます。

**制約**

- $0 \le u, v \lt n$

**計算量**

- $\textrm{O}(\log n)$

---
