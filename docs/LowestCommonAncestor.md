---
title: Lowest Common Ancestor - 最小共通祖先
documentation_of: ../Library/Tree/LowestCommonAncestor.hpp
---

# Lowest Common Ancestor - 最小共通祖先

木上の2つの頂点の最小共通祖先（LCA）を効率的に求めるデータ構造です。

ダブリングを用いて前処理を行い、各クエリを高速に処理します。

## Function

### Constructor

```
LowestCommonAncestor(Graph<CostType> &tree)
```

- 木 `tree` に対して LCA を求めるための前処理を行います。

**制約**

- $1 \le N \le 10^5$

**計算量**

- $\textrm{O}(N \log N)$

---

### Query

```
Vertex Query(Vertex u, Vertex v)
```

- 頂点 $u$ と頂点 $v$ の最小共通祖先を返します。
- **0-index** で頂点を指定します。

**制約**

- $0 \le u, v < N$

**計算量**

- $\textrm{O}(\log N)$

---
