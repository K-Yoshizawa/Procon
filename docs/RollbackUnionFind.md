---
title: Graph - グラフ
documentation_of: ../Library/DataStructure/RollbackUnionFind.hpp
---

<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [['$', '$'] ],
 displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
 }
 });
</script>

# Rollback Union-Find - Rollback 可能 Union-Find

通常の Union-Find に加え、次の操作を可能としたデータ構造。

- 最後の `Unite` 操作の取り消し
- 予め記録した状態への復元

## Function

### Constructor

```
RollbackUnionFind(size_t n)
```

- $n$ 頂点 $0$ 辺の無向グラフを構築します。
- 頂点には $0, 1, \dots, n - 1$ の番号が振られているとします。

**制約**

- $0 \le n \le 10^6$

**計算量**

- $\textrm{O}(n)$

---

### Find

```
int Find(const int k)
```

- 頂点 $k$ が属する連結成分の代表頂点を取得します。
- 内部処理として経路圧縮を**行いません**。

**制約**

- $0 \le k \lt n$

**計算量**

- $\textrm{O}(\log n)$

---

### Same

```
bool Same(const int x, const int y)
```

- 頂点 $x$ と頂点 $y$ が連結であるかを判定します。
- 頂点 $x$ と頂点 $y$ が連結であるとき `true` を返します。

**制約**

- $0 \le x, y \lt n$

**計算量**

- $\textrm{O}(\log n)$

---

### Unite

```
bool Unite(int x, int y)
```

- 頂点 $x$ と頂点 $y$ の間に辺 $(x, y)$ を追加します。
- 辺 $(x, y)$ の追加により頂点 $x$ と頂点 $y$ が連結になったとき `true` を返します。

**制約**

- $0 \le x, y \lt n$

**計算量**

- $\textrm{O}(\log n)$$

---

### Size

```
size_t Size(int k)
```

- 頂点 $k$ の属する連結成分の頂点数を返します。

**制約**

- $0 \le k \lt n$

**計算量**

- $\textrm{O}(\log n)$

---

### Group

```
vector<vector<int>> Group()
```

- すべての連結成分に含まれる頂点の一覧を返します。

**計算量**

- $\textrm{O}(n \log n)$

---

### Record

```
void Record()
```

- 現在のグラフの状態を記録します。
- 複数回呼び出した場合、最後に呼び出されたときの状態が記録されます。

**計算量**

- $\textrm{O}(1)$

---

### Undo

```
void Undo()
```

- 最後の `Unite` 操作を取り消します。
- $1$ 回も操作を行っていない状態で呼び出したときの挙動は未定義です。

**計算量**

- $\textrm{O}(1)$

---

### Rollback

```
void Rollback()
```

- `Record` で記録した状態まで `Unite` 操作を取り消します。
- `Record` を $1$ 度も呼び出していない場合はすべての操作を取り消します。
- 現在の状態が記録した状態より過去の状態である場合の挙動は未定義です。

**計算量**

- 取り消す `Unite` 操作の回数を $k$ として、$\textrm{O}(k)$

---