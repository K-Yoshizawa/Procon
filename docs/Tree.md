---
title: Tree - 木
documentation_of: ../Library/Tree/Tree.hpp
---

# Tree - 木

グラフテンプレートを木として用いるときに便利なライブラリ群です。

本ドキュメントにおいて、木 $T$ の頂点数は $n$ とし、頂点は 0-index でラベリングされているものとします。

---

### CalculateTreeDepth

```
vector<int> CalculateTreeDepth(Graph<CostType> &T, Vertex r = 0)
```

- 木 $T$ について、頂点 $r$ を根としたときの各頂点の深さを求めます。
- 頂点 $r$ の深さは $0$ とします。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---
