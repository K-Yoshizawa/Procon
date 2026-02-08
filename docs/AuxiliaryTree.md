---
title: Auxiliary Tree - 補助木
documentation_of: ../Library/Tree/AuxiliaryTree.hpp
---

# Auxiliary Tree - 補助木

木上の指定された頂点集合に対して、それらの頂点と最小共通祖先（LCA）のみを含む圧縮された木を構築するデータ構造です。

元の木の頂点数を $U$、指定する頂点集合のサイズを $V$ とすると、補助木の頂点数は $\textrm{O}(V)$ になります。

## Function

### Constructor

```
AuxiliaryTree(RootedTree<CostType> &tree)
```

- 木 `tree` を元に補助木を構築するための準備を行います。
- 内部で LCA、オイラーツアー、累積和を事前計算します。

**制約**

- $1 \le U \le 10^5$

**計算量**

- $\textrm{O}(U \log U)$

---

### Set

```
void Set(const vector<Vertex> &vertex_set)
```

- 構築する補助木に含める頂点集合をセットします。
- 実際には、この頂点集合とそれらの LCA を加えた頂点集合が保存されます。
- **0-index** で頂点を指定します。

**制約**

- $1 \le V \le U$
- 各頂点は元の木に存在する

**計算量**

- $\textrm{O}(V \log V)$

---

### Build

```
RootedTree<CostType> Build()
```

- 補助木を生成して返します。
- 事前に `Set()` で頂点集合をセットしておく必要があります。
- 元の木の辺の重みは累積和として保持されます。

**計算量**

- $\textrm{O}(V \log V)$

---

### ConvertData

```
template<typename Type>
vector<Type> ConvertData(const vector<Type> &data) const
```

- 元の木のデータ配列を補助木用のデータ配列に変換します。
- 元の木の頂点 $i$ のデータを、補助木での対応する頂点のデータに写像します。

**制約**

- `data` のサイズは $U$

**計算量**

- $\textrm{O}(V)$

---
