---
title: Tree - 木
documentation_of: ../Library/Tree/Tree.hpp
---

# Tree - 木

グラフテンプレートを木として用いるときに便利なライブラリ群です。

本ドキュメントにおいて、木 $T$ の頂点数は $n$ とし、頂点は 0-index でラベリングされているものとします。

---

### InputTree

```
Graph<CostType> InputTree(int N, int padding = -1, bool weighted = false)
```

- 木 $T$ を標準入力から読み込みます。
- 入力形式は以下の 2 つの形式のどちらかであることを想定しています。

```
u v
```

```
u v w
```

**制約**

- $0 \le n \le 10^{6}$

**計算量**

- $\textrm{O}(n)$

---

### InputRootedTreeChild

```
Graph<CostType> InputRootedTreeChild(int N, int padding = -1)
```

- 木 $T$ を標準入力から読み込みます。
- 入力形式は以下の形式であることを想定しています。

```
k c_0 c_1 ... c_k
```

**制約**

- $0 \le n \le 10^{6}$

**計算量**

- $\textrm{O}(n)$

---

### InputRootedTreeParent

```
Graph<CostType> InputRootedTreeParent(int N, int padding = -1)
```

- 木 $T$ を標準入力から読み込みます。
- 入力形式は以下の形式であることを想定しています。

```
p_1 p_2 ... p_{N - 1}
```

**制約**

- $0 \le n \le 10^{6}$

**計算量**

- $\textrm{O}(n)$

---

### CalculateTreeParent

```
vector<int> CalculateTreeParent(Graph<CostType> &T, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の親を求めます。
- 頂点 $r$ の親は $-1$ とします。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---

### CalculateTreeCost

```
vector<CostType> CalculateTreeCost(Graph<CostType> &T, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の親と結ぶ辺の重みを求めます。
- 頂点 $r$ の重みについては未定義です。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---

### CalculateTreeDepth

```
vector<int> CalculateTreeDepth(Graph<CostType> &T, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の深さを求めます。
- 頂点 $r$ の深さは $0$ とします。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---

### CalculateTreeDistance

```
vector<CostType> CalculateTreeDistance(Graph<CostType> &T, Vertex r = 0)
```

- 木 $T$ について、頂点 $r$ を始点としたときの各頂点までの距離を求めます。
- 頂点 $r$ の距離は $0$ とします。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---

### CalculateSubtreeSize

```
vector<int> CalculateSubtreeSize(Graph<CostType> &tree, Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点を根とする部分木の大きさを求めます。
- 葉を根とする部分木の大きさは $1$ とします。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---

### RootedTreeAdjacentList

```
vector<vector<Vertex>> RootedTreeAdjacentList(const Graph<CostType> &T, const Vertex r = 0)
```

- 頂点 $r$ を根とした根付き木 $T$ について、各頂点の子の頂点の隣接リストを作成します。

**制約**

- $0 \le r \lt n$

**計算量**

- $\textrm{O}(n)$

---
