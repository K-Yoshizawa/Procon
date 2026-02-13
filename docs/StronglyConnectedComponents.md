---
title: Strongly Connected Components - 強連結成分分解
documentation_of: ../Library/Graph/StronglyConnectedComponents.hpp
---

# Strongly Connected Components - 強連結成分分解

頂点数 $V$ 辺数 $E$ の有向グラフを強連結成分に分解します。

強連結成分とは、その成分内の任意の2頂点間に互いに到達可能な経路が存在する極大な部分グラフです。

## Function

### Constructor

```
StronglyConnectedComponents(Graph<WeightType> &graph)
```

- 有向グラフ $G$ を頂点数 $V$ 辺数 $E$ の `graph` で初期化し、強連結成分に分解します。
- 各成分はトポロジカル順序でソートされます。

**制約**

- $G$ は有向グラフ

**計算量**

- $\textrm{O}(V + E)$

---

### Components

```
vector<vector<Vertex>> &Components()
```

- 強連結成分のリストを返します。
- 各成分は頂点のリストとして表現されます。
- 成分はトポロジカル順序でソートされています。

**計算量**

- $\textrm{O}(1)$

---

### ComponentCount

```
int ComponentCount() const
```

- 強連結成分の個数を返します。

**計算量**

- $\textrm{O}(1)$

---

### BelongComponent

```
int BelongComponent(const Vertex &v) const
```

- 頂点 $v$ が属する強連結成分の番号を返します。
- 成分番号はトポロジカル順序に対応します。

**制約**

- $0 \le v \lt V$

**計算量**

- $\textrm{O}(1)$

---

### TopologicalSort

```
vector<Vertex> TopologicalSort() const
```

- 強連結成分のトポロジカルソート順に頂点を並べた配列を返します。
- DAG（有向非巡回グラフ）においてトポロジカルソートとして使用できます。

**計算量**

- $\textrm{O}(V)$

---

### ContractedGraph

```
Graph<WeightType> ContractedGraph() const
```

- 各強連結成分を1つの頂点に縮約したグラフを返します。
- 縮約後のグラフは DAG（有向非巡回グラフ）になります。
- 同一成分内の辺は削除されます。

**計算量**

- $\textrm{O}(V + E)$

---

### operator[]

```
int operator[](const Vertex &v)
const int operator[](const Vertex &v) const
```

- 頂点 $v$ が属する強連結成分の番号を返します。
- `BelongComponent(v)` と同等です。

**制約**

- $0 \le v \lt V$

**計算量**

- $\textrm{O}(1)$

---
