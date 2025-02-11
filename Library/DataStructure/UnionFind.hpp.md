---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Kruskal.hpp
    title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-1-A.test.cpp
    title: verify/AOJ-DSL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-MinimumSpanningTree.test.cpp
    title: verify/LC-MinimumSpanningTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-Unionfind.test.cpp
    title: verify/LC-Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/UnionFind.hpp\"\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n#line 4 \"Library/DataStructure/UnionFind.hpp\"\n\nclass\
    \ UnionFind{\n    public:\n    UnionFind(size_t n) : data_(n, -1){}\n\n    int\
    \ Find(const int k){\n        if(data_[k] < 0) return k;\n        int r = Find(data_[k]);\n\
    \        return data_[k] = r;\n    }\n\n    bool Same(const int x, const int y){\n\
    \        return Find(x) == Find(y);\n    }\n\n    bool Unite(int x, int y){\n\
    \        x = Find(x), y = Find(y);\n        if(x == y) return false;\n       \
    \ if(data_[x] > data_[y]) swap(x, y);\n        data_[x] += data_[y];\n       \
    \ data_[y] = x;\n        return true;\n    }\n    \n    size_t Size(int k){\n\
    \        int v = Find(k);\n        return -data_[v];\n    }\n\n    vector<vector<int>>\
    \ Group(){\n        vector<vector<int>> ret(data_.size());\n        for(int i\
    \ = 0; i < data_.size(); ++i){\n            ret[Find(i)].emplace_back(i);\n  \
    \      }\n        ret.erase(remove_if(begin(ret), end(ret), [&](vector<int> &v){\n\
    \            return v.empty();\n        }), end(ret));\n        return ret;\n\
    \    }\n\n    private:\n    vector<int> data_;\n};\n"
  code: "#pragma once\n\n#include \"../Common.hpp\"\n\nclass UnionFind{\n    public:\n\
    \    UnionFind(size_t n) : data_(n, -1){}\n\n    int Find(const int k){\n    \
    \    if(data_[k] < 0) return k;\n        int r = Find(data_[k]);\n        return\
    \ data_[k] = r;\n    }\n\n    bool Same(const int x, const int y){\n        return\
    \ Find(x) == Find(y);\n    }\n\n    bool Unite(int x, int y){\n        x = Find(x),\
    \ y = Find(y);\n        if(x == y) return false;\n        if(data_[x] > data_[y])\
    \ swap(x, y);\n        data_[x] += data_[y];\n        data_[y] = x;\n        return\
    \ true;\n    }\n    \n    size_t Size(int k){\n        int v = Find(k);\n    \
    \    return -data_[v];\n    }\n\n    vector<vector<int>> Group(){\n        vector<vector<int>>\
    \ ret(data_.size());\n        for(int i = 0; i < data_.size(); ++i){\n       \
    \     ret[Find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](vector<int> &v){\n            return v.empty();\n        }), end(ret));\n\
    \        return ret;\n    }\n\n    private:\n    vector<int> data_;\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/UnionFind.hpp
  requiredBy:
  - Library/Graph/Kruskal.hpp
  timestamp: '2025-02-12 02:16:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-MinimumSpanningTree.test.cpp
  - verify/LC-Unionfind.test.cpp
  - verify/AOJ-DSL-1-A.test.cpp
documentation_of: Library/DataStructure/UnionFind.hpp
layout: document
title: "Union-Find - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
---

# Union-Find - 素集合データ構造

$n$ 頂点の無向グラフに対し、

- $2$ 頂点を結ぶ辺の追加
- $2$ 頂点が連結であるかの判定

をならし $\textrm{O}(\alpha(n))$ 時間で処理することができるデータ構造です。

## Function

### Constructor

```
UnionFind(size_t n)
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
- 内部処理として経路圧縮を行います。

**制約**

- $0 \le k \lt n$

**計算量**

- ならし $\textrm{O}(\alpha(n))$

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

- ならし $\textrm{O}(\alpha(n))$

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

- ならし $\textrm{O}(\alpha(n))$

---

### Size

```
size_t Size(int k)
```

- 頂点 $k$ の属する連結成分の頂点数を返します。

**制約**

- $0 \le k \lt n$

**計算量**

- ならし $\textrm{O}(\alpha(n))$

---

### Group

```
vector<vector<int>> Group()
```

- すべての連結成分に含まれる頂点の一覧を返します。

**計算量**

- ならし $\textrm{O}(n \alpha(n))$

---