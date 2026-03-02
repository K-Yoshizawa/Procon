---
title: Tree Diameter - 木の直径
documentation_of: ../Library/Tree/TreeDiameter.hpp
---

# Tree Diameter - 木の直径

頂点数 $V$ の木 $T$ の直径に関するライブラリです。

## Function

### Constructor

```
TreeDiameter(Graph<WeightType> &tree)
```

- 木 $T$ を頂点数 $V$ の `tree` で初期化し、その直径を求めます。

**制約**

- `tree` は木

**計算量**

- $\textrm{O}(V)$

---

### Diameter

```
WeightType Diameter() const
```

- 木 $T$ の直径を返します。

**計算量**

- $\textrm{O}(1)$

---

### Height

```
WeightType Height(Vertex v) const
```

- 木 $T$ について、頂点 $v$ を根としたときの木の高さを返します。
  - 木の高さとは、根から最も遠い葉までの距離を指します。

**制約**

- $0 \le v \lt V$

**計算量**

- $\textrm{O}(1)$

---

### EndPoints

```
pair<Vertex, Vertex> EndPoints() const 
```

- 木 $T$ の直径の端点の頂点を返します。

**計算量**

- $\textrm{O}(1)$

---

### Path

```
vector<Vertex> &Path()
```

- 木 $T$ の直径を成すパスの頂点列を返します。

**計算量**

- $\textrm{O}(1)$

---
