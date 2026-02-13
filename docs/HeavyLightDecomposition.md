---
title: Heavy Light Decomposition - 重軽分解
documentation_of: ../Library/Tree/HeavyLightDecomposition.hpp
---

**Attention:** このドキュメントは未完成です。

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

### LevelAncestor

```
Vertex LevelAncestor(Vertex v, int k)
```

- 頂点 $v$ から $k$ 回親の頂点を辿った先の頂点を求めます。

**制約**

- $0 \le v \lt n$
- 頂点 $v$ の深さを $d$ としたとき、$0 \le k \le d$

**計算量**

- $\textrm{O}(\log n)$

---

### Jump

```
int Jump(Vertex u, Vertex v, int k)
```

- 頂点 $u$ から頂点 $v$ への $T$ 上の最短パスを通る順に並べた頂点列 $p = (p_0, \dots, p_d)$ において、頂点 $p_k$ を返します。ここで、$d$ は頂点 $u$ から頂点 $v$ への $T$ 上の最短パス長です。
- $k \lt 0$ または $d \lt k$ のとき、`-1` を返します。

**制約**

- $0 \le u, v \lt n$

**計算量**

- $\textrm{O}(\log n)$

---

### PathQuery

```
vector<PathSegment> PathQuery(Vertex u, Vertex v)
```

- 頂点 $u$ から頂点 $v$ へのパスを Heavy Path に分解した `PathSegment` の集合を返します。
- `PathSegment` $P$ は次の要素からなる構造体です。
    - `head_vertex` : $P$ のうち最も根に近い頂点番号
    - `tail_vertex` : $P$ のうち最も葉に近い頂点番号
    - `head_index` : `head_vertex` の行きかけ順序 (0-index)
    - `tail_index` : `tail_vertex` の行きかけ順序 (0-index)
    - `highest` : $P$ が最も根に近いパスであること (すなわち、$\textrm{LCA}(u, v)$ を含むこと) を表す真偽値
    - `reverse` : 頂点 $u$ が `tail_vertex` であることを表す真偽値
- Segment Tree などと併せて使用することを想定しています。基本的には `SortVertex()` によって並べ替えたデータを乗せた Segment Tree に対して半開区間 `[head_index, tail_index)` のクエリを実行すればよいです。
- クエリが辺属性である場合、すなわち頂点 $x$ に対するデータの代わりに、頂点 $x$ とその親の頂点を繋ぐ辺に対するデータを表す場合、$\textrm{LCA}(u, v)$ に対するデータを集計しないようにする必要があります。
    - `highest` フラグを確認することで解決できます。より具体的には、`highest` フラグが真であるとき、`[head_index + 1, tail_index)` を代わりに実行すればよいです。(要 verify)
- Segment Tree などに乗せたデータが可換性を持たないとき、パスの向きに注意する必要があります。
    - 二方向の演算で集計できるように、$2$ 本の Segment Tree を持ちつつ、`reverse` フラグを確認することで解決できます。より具体的には、`reverse` フラグの真偽によってクエリを実行するデータ構造を変更すればよいです。実装例は [Vertex Set Path Composite](https://k-yoshizawa.github.io/Procon/verify/LC-VertexSetPathComposite.test.cpp) を参照してください。

**制約**

- $0 \le u, v \lt n$

**計算量**

- $\textrm{O}(\log n)$

---

### SubtreeQuery

```
pair<int, int> SubtreeQuery(Vertex v) const
```

- 頂点 $v$ を根とする部分木に対応する区間を半開区間で返します。

**制約**

- $0 \le v \lt n$

**計算量**

- $\textrm{O}(1)$

---

### SortVertex

```
void SortVertex(vector<T> &A)
```

- 長さ $n$ の数列 $A = (A_1, \dots, A_n)$ を、頂点の行きかけ順序になるように並べ替えます。

**制約**

- $|A| = n$

**計算量**

- $\textrm{O}(n)$

---

