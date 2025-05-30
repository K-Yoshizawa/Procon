---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-0723.test.cpp
    title: verify/AOJ-0723.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-PersistentUnionfind.test.cpp
    title: verify/LC-PersistentUnionfind.test.cpp
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
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (1LL << 30) -\
    \ 1;\n#line 2 \"Library/DataStructure/RollbackUnionFind.hpp\"\n\nclass RollbackUnionFind{\n\
    \    public:\n    RollbackUnionFind(size_t n) : data_(n, -1), record_(0){}\n\n\
    \    int Find(const int k) const {\n        if(data_[k] < 0) return k;\n     \
    \   return Find(data_[k]);\n    }\n\n    bool Same(const int x, const int y) const\
    \ {\n        return Find(x) == Find(y);\n    }\n\n    bool Unite(int x, int y){\n\
    \        x = Find(x), y = Find(y);\n        history_.push({x, data_[x]});\n  \
    \      history_.push({y, data_[y]});\n        if(x == y) return false;\n     \
    \   if(data_[x] > data_[y]) swap(x, y);\n        data_[x] += data_[y];\n     \
    \   data_[y] = x;\n        return true;\n    }\n    \n    int Size(const int k)\
    \ const {\n        return -data_[Find(k)];\n    }\n    \n    vector<vector<int>>\
    \ Group() const {\n        vector<vector<int>> ret(data_.size());\n        for(int\
    \ i = 0; i < data_.size(); ++i){\n            ret[Find(i)].emplace_back(i);\n\
    \        }\n        ret.erase(remove_if(begin(ret), end(ret), [&](vector<int>\
    \ &v){\n            return v.empty();\n        }), end(ret));\n        return\
    \ ret;\n    }\n\n    void Record(){\n        record_ = history_.size();\n    }\n\
    \n    void Undo(){\n        auto [y, dy] = history_.top();\n        history_.pop();\n\
    \        data_[y] = dy;\n        auto [x, dx] = history_.top();\n        history_.pop();\n\
    \        data_[x] = dx;\n    }\n\n    void Rollback(){\n        int state = record_;\n\
    \        while(state < (int)history_.size()) Undo();\n    }\n    \n    private:\n\
    \    vector<int> data_;\n    stack<pair<int, int>> history_;\n    int record_;\n\
    };\n"
  code: "#include \"../Common.hpp\"\n\nclass RollbackUnionFind{\n    public:\n   \
    \ RollbackUnionFind(size_t n) : data_(n, -1), record_(0){}\n\n    int Find(const\
    \ int k) const {\n        if(data_[k] < 0) return k;\n        return Find(data_[k]);\n\
    \    }\n\n    bool Same(const int x, const int y) const {\n        return Find(x)\
    \ == Find(y);\n    }\n\n    bool Unite(int x, int y){\n        x = Find(x), y\
    \ = Find(y);\n        history_.push({x, data_[x]});\n        history_.push({y,\
    \ data_[y]});\n        if(x == y) return false;\n        if(data_[x] > data_[y])\
    \ swap(x, y);\n        data_[x] += data_[y];\n        data_[y] = x;\n        return\
    \ true;\n    }\n    \n    int Size(const int k) const {\n        return -data_[Find(k)];\n\
    \    }\n    \n    vector<vector<int>> Group() const {\n        vector<vector<int>>\
    \ ret(data_.size());\n        for(int i = 0; i < data_.size(); ++i){\n       \
    \     ret[Find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](vector<int> &v){\n            return v.empty();\n        }), end(ret));\n\
    \        return ret;\n    }\n\n    void Record(){\n        record_ = history_.size();\n\
    \    }\n\n    void Undo(){\n        auto [y, dy] = history_.top();\n        history_.pop();\n\
    \        data_[y] = dy;\n        auto [x, dx] = history_.top();\n        history_.pop();\n\
    \        data_[x] = dx;\n    }\n\n    void Rollback(){\n        int state = record_;\n\
    \        while(state < (int)history_.size()) Undo();\n    }\n    \n    private:\n\
    \    vector<int> data_;\n    stack<pair<int, int>> history_;\n    int record_;\n\
    };"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/RollbackUnionFind.hpp
  requiredBy: []
  timestamp: '2025-03-20 00:50:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-0723.test.cpp
  - verify/LC-PersistentUnionfind.test.cpp
documentation_of: Library/DataStructure/RollbackUnionFind.hpp
layout: document
title: "Rollback Union-Find - Rollback \u53EF\u80FD Union-Find"
---

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