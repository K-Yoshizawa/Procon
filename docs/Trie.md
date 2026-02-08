---
title: Trie - トライ木
documentation_of: ../Library/String/Trie.hpp
---

# Trie - トライ木

文字列の集合を効率的に管理するデータ構造です。複数の文字列の共通接頭辞を共有することで省スペース化を図ります。

## Function

### Constructor

```
Trie(vector<string> &S_)
```

- 文字列の配列 $S$ からトライ木を構築します。
- 各文字列は英小文字のみで構成されている必要があります。

**制約**

- $1 \le \sum \lvert S_i \rvert \le 5 \times 10^5$
- 各文字列は英小文字のみで構成される

**計算量**

- $\textrm{O}(\sum \lvert S_i \rvert)$

---

### Build

```
Graph<int32_t> Build() const
```

- トライ木をグラフ構造として返します。
- 各ノードは頂点として、親子関係は辺として表現されます。
- 返されるグラフは無向グラフです。

**計算量**

- $\textrm{O}(V)$ （$V$ はトライ木の頂点数）

---

### operator[]

```
vector<int> &operator[](const int i)
```

- 文字列 $S_i$ に対応するトライ木上のノード列を返します。
- 返される配列の各要素は、文字列の各文字に対応するノード番号です。
- 配列のサイズは $\lvert S_i \rvert + 1$ で、最初の要素（インデックス0）は根ノード（0）です。

**制約**

- $0 \le i < \lvert S \rvert$

**計算量**

- $\textrm{O}(1)$

---
