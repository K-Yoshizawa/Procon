---
title: Lowest Common Ancestor - 最小共通祖先
documentation_of: ../Library/Tree/LowestCommonAncestor.hpp
---

# Lowest Common Ancestor - 最小共通祖先

頂点数 $V$ の木 $T$ 上の2つの頂点の最小共通祖先を効率的に求めるデータ構造です。

ダブリングを用いて前処理を行い、各クエリを高速に処理します。

## Function

### Constructor

```
LowestCommonAncestor(Graph<WeightType> &tree)
```

- 木 $T$ を頂点数 $V$ の `tree` で初期化し、前処理を行います。

**制約**

- `tree` は木

**計算量**

- $\textrm{O}(V \log V)$

---

### Query

```
Vertex Query(Vertex u, Vertex v)
```

- 頂点 $u$ と頂点 $v$ の最小共通祖先を返します。

**制約**

- $0 \le u, v \lt V$

**計算量**

- $\textrm{O}(\log V)$

---
