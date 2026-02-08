---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-PointAddRangeSum_BIT.test.cpp
    title: verify/LC-PointAddRangeSum_BIT.test.cpp
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
    \ 1;\n#line 2 \"Library/DataStructure/BinaryIndexedTree.hpp\"\n\ntemplate<typename\
    \ T>\nstruct BinaryIndexedTree{\n    public:\n    BinaryIndexedTree(int n) : size_(n){\n\
    \        data_.resize(size_ + 1, 0);\n    }\n\n    T Sum(int i){\n        T ret\
    \ = 0;\n        for(; i > 0; i -= i & -i) ret += data_[i];\n        return ret;\n\
    \    }\n    \n    T Sum(int l, int r){\n        return Sum(r) - Sum(l - 1);\n\
    \    }\n\n    void Add(int i, T v){\n        for(; i <= size_; i += i & -i) data_[i]\
    \ += v;\n    }\n\n    private:\n    int size_;\n    vector<T> data_;\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename T>\nstruct BinaryIndexedTree{\n\
    \    public:\n    BinaryIndexedTree(int n) : size_(n){\n        data_.resize(size_\
    \ + 1, 0);\n    }\n\n    T Sum(int i){\n        T ret = 0;\n        for(; i >\
    \ 0; i -= i & -i) ret += data_[i];\n        return ret;\n    }\n    \n    T Sum(int\
    \ l, int r){\n        return Sum(r) - Sum(l - 1);\n    }\n\n    void Add(int i,\
    \ T v){\n        for(; i <= size_; i += i & -i) data_[i] += v;\n    }\n\n    private:\n\
    \    int size_;\n    vector<T> data_;\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2025-05-30 20:02:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-PointAddRangeSum_BIT.test.cpp
documentation_of: Library/DataStructure/BinaryIndexedTree.hpp
layout: document
title: "Binary Indexed Tree (Fenwick Tree) - \u4E8C\u5206\u7D22\u5F15\u6728"
---

# Binary Indexed Tree (Fenwick Tree) - 二分索引木

長さ $N$ の数列 $A = (A_1, \dots, A_N)$ に対し、一点加算・区間和取得クエリを効率的に行うことができるデータ構造です。

## Function

### Constructor

```
BinaryIndexedTree(int n)
```

- 数列 $A$ を長さ $n$ で初期化します。初期値はすべて $0$ です。

**制約**

- $1 \le n \le 10^6$

**計算量**

- $\textrm{O}(n)$

---

### Add

```
void Add(int i, T v)
```

- $A_i$ に値 $v$ を加算します。$A_i \leftarrow A_i + v$

**制約**

- $1 \le i \le n$

**計算量**

- $\textrm{O}(\log n)$

---

### Sum

```
(1) T Sum(int i)
(2) T Sum(int l, int r)
```

- (1) 区間 $[1, i]$ の総和を返します。$\sum_{k=1}^{i} A_k$ を計算します。
- (2) 区間 $[l, r]$ の総和を返します。$\sum_{k=l}^{r} A_k$ を計算します。

**制約**

- (1) $1 \le i \le n$
- (2) $1 \le l \le r \le n$

**計算量**

- $\textrm{O}(\log n)$

---
