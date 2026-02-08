---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-0560.test.cpp
    title: verify/AOJ-0560.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-5-B.test.cpp
    title: verify/AOJ-DSL-5-B.test.cpp
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
    \ 1;\n#line 2 \"Library/DataStructure/CumulativeSum2D.hpp\"\n\ntemplate<typename\
    \ T = int32_t>\nstruct CumulativeSum2D{\n    private:\n    int height_, width_;\n\
    \    vector<vector<T>> data_;\n\n    void Validate(const int y, const int x) const\
    \ {\n        assert(0 <= y && y < height_ - 1);\n        assert(0 <= x && x <\
    \ width_ - 1);\n    }\n\n    public:\n    CumulativeSum2D(const int height, const\
    \ int width, const T init_value = 0) : height_(height + 1), width_(width + 1){\n\
    \        data_.resize(height_);\n        for(int i = 0; i < height_; ++i){\n \
    \           data_.at(i).resize(width_, init_value);\n        }\n    }\n\n    void\
    \ Build(){\n        for(int i = 1; i < height_; ++i){\n            for(int j =\
    \ 0; j < width_; ++j){\n                data_[i][j] += data_[i - 1][j];\n    \
    \        }\n        }\n        for(int i = 0; i < height_; ++i){\n           \
    \ for(int j = 1; j < width_; ++j){\n                data_[i][j] += data_[i][j\
    \ - 1];\n            }\n        }\n    }\n\n    void Set(const int y, const int\
    \ x, const T value){\n        Validate(y, x);\n        data_[y][x] = value;\n\
    \    }\n\n    void Add(const int y, const int x, const T value){\n        Add(y,\
    \ x, y, x, value);\n    }\n\n    void Add(const int y1, const int x1, const int\
    \ y2, const int x2, const T value){\n        Validate(y1, x1);\n        Validate(y2,\
    \ x2);\n        data_[y1][x1] += value;\n        data_[y2 + 1][x1] -= value;\n\
    \        data_[y1][x2 + 1] -= value;\n        data_[y2 + 1][x2 + 1] += value;\n\
    \    }\n\n    T Sum(const int y, const int x) const {\n        Validate(y, x);\n\
    \        return data_[y][x];\n    }\n\n    T Sum(const int y1, const int x1, const\
    \ int y2, const int x2) const {\n        Validate(y1, x1);\n        Validate(y2,\
    \ x2);\n        T ret = Sum(y2, x2);\n        if(y1 > 0) ret -= Sum(y1 - 1, x2);\n\
    \        if(x1 > 0) ret -= Sum(y2, x1 - 1);\n        if(y1 > 0 && x1 > 0) ret\
    \ += Sum(y1 - 1, x1 - 1);\n        return ret;\n    }\n\n    T Max() const {\n\
    \        T ret = data_[0][0];\n        for(int i = 0; i < height_; ++i){\n   \
    \         for(int j = 0; j < width_; ++j){\n                ret = max(ret, data_[i][j]);\n\
    \            }\n        }\n        return ret;\n    }\n\n    T Min() const {\n\
    \        T ret = data_[0][0];\n        for(int i = 0; i < height_; ++i){\n   \
    \         for(int j = 0; j < width_; ++j){\n                ret = min(ret, data_[i][j]);\n\
    \            }\n        }\n        return ret;\n    }\n\n    vector<T> &operator[](const\
    \ int k){\n        return data_.at(k);\n    }\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename T = int32_t>\nstruct CumulativeSum2D{\n\
    \    private:\n    int height_, width_;\n    vector<vector<T>> data_;\n\n    void\
    \ Validate(const int y, const int x) const {\n        assert(0 <= y && y < height_\
    \ - 1);\n        assert(0 <= x && x < width_ - 1);\n    }\n\n    public:\n   \
    \ CumulativeSum2D(const int height, const int width, const T init_value = 0) :\
    \ height_(height + 1), width_(width + 1){\n        data_.resize(height_);\n  \
    \      for(int i = 0; i < height_; ++i){\n            data_.at(i).resize(width_,\
    \ init_value);\n        }\n    }\n\n    void Build(){\n        for(int i = 1;\
    \ i < height_; ++i){\n            for(int j = 0; j < width_; ++j){\n         \
    \       data_[i][j] += data_[i - 1][j];\n            }\n        }\n        for(int\
    \ i = 0; i < height_; ++i){\n            for(int j = 1; j < width_; ++j){\n  \
    \              data_[i][j] += data_[i][j - 1];\n            }\n        }\n   \
    \ }\n\n    void Set(const int y, const int x, const T value){\n        Validate(y,\
    \ x);\n        data_[y][x] = value;\n    }\n\n    void Add(const int y, const\
    \ int x, const T value){\n        Add(y, x, y, x, value);\n    }\n\n    void Add(const\
    \ int y1, const int x1, const int y2, const int x2, const T value){\n        Validate(y1,\
    \ x1);\n        Validate(y2, x2);\n        data_[y1][x1] += value;\n        data_[y2\
    \ + 1][x1] -= value;\n        data_[y1][x2 + 1] -= value;\n        data_[y2 +\
    \ 1][x2 + 1] += value;\n    }\n\n    T Sum(const int y, const int x) const {\n\
    \        Validate(y, x);\n        return data_[y][x];\n    }\n\n    T Sum(const\
    \ int y1, const int x1, const int y2, const int x2) const {\n        Validate(y1,\
    \ x1);\n        Validate(y2, x2);\n        T ret = Sum(y2, x2);\n        if(y1\
    \ > 0) ret -= Sum(y1 - 1, x2);\n        if(x1 > 0) ret -= Sum(y2, x1 - 1);\n \
    \       if(y1 > 0 && x1 > 0) ret += Sum(y1 - 1, x1 - 1);\n        return ret;\n\
    \    }\n\n    T Max() const {\n        T ret = data_[0][0];\n        for(int i\
    \ = 0; i < height_; ++i){\n            for(int j = 0; j < width_; ++j){\n    \
    \            ret = max(ret, data_[i][j]);\n            }\n        }\n        return\
    \ ret;\n    }\n\n    T Min() const {\n        T ret = data_[0][0];\n        for(int\
    \ i = 0; i < height_; ++i){\n            for(int j = 0; j < width_; ++j){\n  \
    \              ret = min(ret, data_[i][j]);\n            }\n        }\n      \
    \  return ret;\n    }\n\n    vector<T> &operator[](const int k){\n        return\
    \ data_.at(k);\n    }\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/CumulativeSum2D.hpp
  requiredBy: []
  timestamp: '2026-02-08 19:33:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-DSL-5-B.test.cpp
  - verify/AOJ-0560.test.cpp
documentation_of: Library/DataStructure/CumulativeSum2D.hpp
layout: document
title: "Cumulative Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
---

# Cumulative Sum 2D - 二次元累積和

$H \times W$ の二次元配列 $A$ に対し、長方形領域の総和を効率的に計算するデータ構造です。

## Function

### Constructor

```
CumulativeSum2D(const int height, const int width, const T init_value = 0)
```

- 高さ $h$ `= height`、幅 $w$ `= width` の二次元累積和を初期化します。

**制約**

- $1 \le h, w \le 10^3$

**計算量**

- $\textrm{O}(hw)$

---

### Set

```
void Set(const int y, const int x, const T value)
```

- 座標 $(y, x)$ に値 $v$ を代入します。$A_{y,x} \leftarrow v$
- **0-index** で座標を指定します。

**制約**

- $0 \le y < h$
- $0 \le x < w$

**計算量**

- $\textrm{O}(1)$

---

### Add (一点加算)

```
void Add(const int y, const int x, const T value)
```

- 座標 $(y, x)$ に値 $v$ を加算します。$A_{y,x} \leftarrow A_{y,x} + v$
- **0-index** で座標を指定します。

**制約**

- $0 \le y < h$
- $0 \le x < w$

**計算量**

- $\textrm{O}(1)$

---

### Add (領域加算)

```
void Add(const int y1, const int x1, const int y2, const int x2, const T value)
```

- 長方形領域 $[y_1, y_2] \times [x_1, x_2]$ に値 $v$ を加算します。
- **0-index、閉区間** で座標を指定します。

**制約**

- $0 \le y_1 \le y_2 < h$
- $0 \le x_1 \le x_2 < w$

**計算量**

- $\textrm{O}(1)$

---

### Build

```
void Build()
```

- 累積和の構築を行います。
- `Set()` や `Add()` で値を設定した後、この関数を呼び出してください。

**計算量**

- $\textrm{O}(hw)$

---

### Sum (矩形領域)

```
(1) T Sum(const int y, const int x) const
(2) T Sum(const int y1, const int x1, const int y2, const int x2) const
```

- (1) 長方形領域 $[0, y] \times [0, x]$ の総和を返します。
- (2) 長方形領域 $[y_1, y_2] \times [x_1, x_2]$ の総和を返します。
- **0-index、閉区間** で座標を指定します。

**制約**

- (1) $0 \le y < h$, $0 \le x < w$
- (2) $0 \le y_1 \le y_2 < h$, $0 \le x_1 \le x_2 < w$

**計算量**

- $\textrm{O}(1)$

---

### Max

```
T Max() const
```

- 配列内の最大値を返します。

**計算量**

- $\textrm{O}(hw)$

---

### Min

```
T Min() const
```

- 配列内の最小値を返します。

**計算量**

- $\textrm{O}(hw)$

---

### operator[]

```
vector<T> &operator[](const int k)
```

- $k$ 行目の配列への参照を返します。
- **0-index** でアクセスします。

**制約**

- $0 \le k < h$

**計算量**

- $\textrm{O}(1)$

---
