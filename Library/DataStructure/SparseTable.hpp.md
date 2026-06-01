---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/LC-StaricRMQ.test.cpp
    title: verify/LC-StaricRMQ.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/SparseTable.hpp\"\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bit>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 4 \"Library/DataStructure/SparseTable.hpp\"\n\ntemplate<typename Ordered>\n\
    class SparseTable{\n    public:\n    SparseTable(const vector<Ordered> &A) : N((int)A.size()){\n\
    \        int row = 0;\n        while(1 << (row + 1) <= N) ++row;\n        data_.resize(row\
    \ + 1, vector<Ordered>(N + 1));\n        for(int i = 0; i < N; ++i) data_[0][i]\
    \ = A[i];\n        for(int k = 0; k < row; ++k){\n            for(int i = 0; i\
    \ + (1 << k) <= N; ++i){\n                data_[k + 1][i] = min(data_[k][i], data_[k][i\
    \ + (1 << k)]);\n            }\n        }\n    }\n\n    inline Ordered Fold(int\
    \ l, int r) const {\n        assert(0 <= l && l < r && r <= N);\n        int k\
    \ = bit_width((uint32_t)r - l) - 1;\n        return min(data_[k][l], data_[k][r\
    \ - (1 << k)]);\n    }\n\n    private:\n    vector<vector<Ordered>> data_;\n \
    \   int N;\n};\n"
  code: "#pragma once\n\n#include \"../Common.hpp\"\n\ntemplate<typename Ordered>\n\
    class SparseTable{\n    public:\n    SparseTable(const vector<Ordered> &A) : N((int)A.size()){\n\
    \        int row = 0;\n        while(1 << (row + 1) <= N) ++row;\n        data_.resize(row\
    \ + 1, vector<Ordered>(N + 1));\n        for(int i = 0; i < N; ++i) data_[0][i]\
    \ = A[i];\n        for(int k = 0; k < row; ++k){\n            for(int i = 0; i\
    \ + (1 << k) <= N; ++i){\n                data_[k + 1][i] = min(data_[k][i], data_[k][i\
    \ + (1 << k)]);\n            }\n        }\n    }\n\n    inline Ordered Fold(int\
    \ l, int r) const {\n        assert(0 <= l && l < r && r <= N);\n        int k\
    \ = bit_width((uint32_t)r - l) - 1;\n        return min(data_[k][l], data_[k][r\
    \ - (1 << k)]);\n    }\n\n    private:\n    vector<vector<Ordered>> data_;\n \
    \   int N;\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/SparseTable.hpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/LC-StaricRMQ.test.cpp
documentation_of: Library/DataStructure/SparseTable.hpp
layout: document
title: Sparse Table
---

# Sparse Table

長さ $N$ の**静的な**列 $A = (A_0, \dots, A_{N - 1})$ について、半開区間 $[l, r)$ に対して $\min_{k \in [l, r)} A_k$ を効率的に計算することができるデータ構造です。

## Function

### Constructor

```
SparseTable(const vector<Ordered> &A)
```

- 長さ $N$ の列 $A$ を渡し、Sparse Table を構築します。

**制約**

- $1 \le N \le 10^6$

**計算量**

- 時間計算量 : $\textrm{O}(N \log N)$
- 空間計算量 : $\textrm{O}(N \log N)$

---

### Fold

```
inline Ordered Fold(int l, int r) const
```

- 半開区間 $[l, r)$ に対して $\displaystyle \underset{k \in [l, r)}{\min}\ A_k$ を返します。

**制約**

- $0 \le l < r \le N$

**計算量**

- $\textrm{O}(1)$

---

最終更新 : Ver.6.0.0

---