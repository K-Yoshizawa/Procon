---
title: Lowest Common Ancestor - 最小共通祖先
documentation_of: ../Library/Tree/LowestCommonAncestor.hpp
---

# Lowest Common Ancestor - 最小共通祖先

頂点数 $V$ の木 $T$ 上について、任意の $2$ 頂点の最小共通祖先を効率的に求めます。

## Function

### Constructor

```
LowestCommonAncestor(Graph<WeightType> &T)
```

- 頂点数が $V$ で、頂点 $0$ を根とする根付き木 $T$ に対して前処理を行います。

**制約**

- $T$ は木

**計算量**

- 時間計算量 : $\textrm{O}(V \log V)$
- 空間計算量 : $\textrm{O}(V \log V)$

---

### Query

```
Vertex Query(Vertex u, Vertex v)
```

- 頂点 $u$ と頂点 $v$ の最小共通祖先を返します。

**制約**

- $0 \le u, v \lt V$

**計算量**

- $\textrm{O}(1)$

---

最終更新 : Ver.6.0.0

---