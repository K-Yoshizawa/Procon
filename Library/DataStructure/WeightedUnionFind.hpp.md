---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-1-B.test.cpp
    title: verify/AOJ-DSL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-UnionfindWithPotential.test.cpp
    title: verify/LC-UnionfindWithPotential.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 2 \"Library/DataStructure/WeightedUnionFind.hpp\"\n\ntemplate<typename\
    \ Abel = int32_t>\nclass WeightedUnionFind{\n    public:\n    WeightedUnionFind(int\
    \ n) : data_(n, -1), weight_(n, Abel{}){}\n\n    int Find(const int k){\n    \
    \    if(data_[k] < 0) return k;\n        int r = Find(data_[k]);\n        weight_[k]\
    \ += weight_[data_[k]];\n        return data_[k] = r;\n    }\n\n    Abel Weight(const\
    \ int k){\n        Find(k);\n        return weight_[k];\n    }\n\n    Abel Diff(const\
    \ int x, const int y){\n        return Weight(y) - Weight(x);\n    }\n\n    bool\
    \ Same(const int x, const int y){\n        return Find(x) == Find(y);\n    }\n\
    \n    bool Unite(int x, int y, Abel w){\n        w += Weight(x) - Weight(y);\n\
    \        x = Find(x), y = Find(y);\n        if(x == y) return false;\n       \
    \ if(data_[x] > data_[y]) swap(x, y), w = -w;\n        data_[x] += data_[y];\n\
    \        data_[y] = x;\n        weight_[y] = w;\n        return true;\n    }\n\
    \n    private:\n    vector<int> data_;\n    vector<Abel> weight_;\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename Abel = int32_t>\nclass WeightedUnionFind{\n\
    \    public:\n    WeightedUnionFind(int n) : data_(n, -1), weight_(n, Abel{}){}\n\
    \n    int Find(const int k){\n        if(data_[k] < 0) return k;\n        int\
    \ r = Find(data_[k]);\n        weight_[k] += weight_[data_[k]];\n        return\
    \ data_[k] = r;\n    }\n\n    Abel Weight(const int k){\n        Find(k);\n  \
    \      return weight_[k];\n    }\n\n    Abel Diff(const int x, const int y){\n\
    \        return Weight(y) - Weight(x);\n    }\n\n    bool Same(const int x, const\
    \ int y){\n        return Find(x) == Find(y);\n    }\n\n    bool Unite(int x,\
    \ int y, Abel w){\n        w += Weight(x) - Weight(y);\n        x = Find(x), y\
    \ = Find(y);\n        if(x == y) return false;\n        if(data_[x] > data_[y])\
    \ swap(x, y), w = -w;\n        data_[x] += data_[y];\n        data_[y] = x;\n\
    \        weight_[y] = w;\n        return true;\n    }\n\n    private:\n    vector<int>\
    \ data_;\n    vector<Abel> weight_;\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/WeightedUnionFind.hpp
  requiredBy: []
  timestamp: '2025-04-30 01:32:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DSL-1-B.test.cpp
  - verify/LC-UnionfindWithPotential.test.cpp
documentation_of: Library/DataStructure/WeightedUnionFind.hpp
layout: document
title: "Weighted Union-Find - \u91CD\u307F\u4ED8\u304D\u7D20\u96C6\u5408\u30C7\u30FC\
  \u30BF\u69CB\u9020"
---

# Weighted Union-Find - 重み付き素集合データ構造

$N$ 頂点からなる無向グラフに対して、辺の重みを管理しながら連結成分を管理するデータ構造です。

各要素間の重み（ポテンシャル）をアーベル群 $A$ で管理します。

## Function

### Constructor

```
WeightedUnionFind(int n)
```

- 頂点数 $n$ で重み付き Union Find を初期化します。
- 初期状態では、すべての頂点は独立しており、各頂点の重みは $0$ です。

**制約**

- $1 \le n \le 10^6$

**計算量**

- $\textrm{O}(n)$

---

### Find

```
int Find(const int k)
```

- 頂点 $k$ が属する連結成分の代表元を返します。
- 経路圧縮を行いながら、頂点 $k$ までの重みを更新します。

**制約**

- $0 \le k < n$

**計算量**

- $\textrm{O}(\alpha(n))$ （$\alpha$ はアッカーマン関数の逆関数）

---

### Weight

```
Abel Weight(const int k)
```

- 頂点 $k$ の代表元からの重み（ポテンシャル）を返します。

**制約**

- $0 \le k < n$

**計算量**

- $\textrm{O}(\alpha(n))$

---

### Diff

```
Abel Diff(const int x, const int y)
```

- 頂点 $x$ から頂点 $y$ への重みの差分 `Weight(y) - Weight(x)` を返します。

**制約**

- $0 \le x, y < n$

**計算量**

- $\textrm{O}(\alpha(n))$

---

### Same

```
bool Same(const int x, const int y)
```

- 頂点 $x$ と頂点 $y$ が同じ連結成分に属するかを判定します。

**制約**

- $0 \le x, y < n$

**計算量**

- $\textrm{O}(\alpha(n))$

---

### Unite

```
bool Unite(int x, int y, Abel w)
```

- 頂点 $x$ と頂点 $y$ を重み $w$ の辺で連結します。
- `Weight(y) - Weight(x) = w` となるように連結されます。
- 既に連結されている場合は `false` を返し、新たに連結された場合は `true` を返します。

**制約**

- $0 \le x, y < n$
- $w \in A$

**計算量**

- $\textrm{O}(\alpha(n))$

---