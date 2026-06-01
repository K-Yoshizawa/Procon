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
    #include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cmath>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const\
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 2 \"Library/DataStructure/CumulativeSum2D.hpp\"\
    \n\ntemplate<typename T = int32_t>\nstruct CumulativeSum2D{\n    private:\n  \
    \  int height_, width_;\n    vector<vector<T>> data_;\n\n    void Validate(const\
    \ int y, const int x) const {\n        assert(0 <= y && y < height_ - 1);\n  \
    \      assert(0 <= x && x < width_ - 1);\n    }\n\n    public:\n    CumulativeSum2D(const\
    \ int height, const int width, const T init_value = 0) : height_(height + 1),\
    \ width_(width + 1){\n        data_.resize(height_);\n        for(int i = 0; i\
    \ < height_; ++i){\n            data_.at(i).resize(width_, init_value);\n    \
    \    }\n    }\n\n    void Build(){\n        for(int i = 1; i < height_; ++i){\n\
    \            for(int j = 0; j < width_; ++j){\n                data_[i][j] +=\
    \ data_[i - 1][j];\n            }\n        }\n        for(int i = 0; i < height_;\
    \ ++i){\n            for(int j = 1; j < width_; ++j){\n                data_[i][j]\
    \ += data_[i][j - 1];\n            }\n        }\n    }\n\n    void Set(const int\
    \ y, const int x, const T value){\n        Validate(y, x);\n        data_[y][x]\
    \ = value;\n    }\n\n    void Add(const int y, const int x, const T value){\n\
    \        Add(y, x, y, x, value);\n    }\n\n    void Add(const int y1, const int\
    \ x1, const int y2, const int x2, const T value){\n        Validate(y1, x1);\n\
    \        Validate(y2, x2);\n        data_[y1][x1] += value;\n        data_[y2\
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
    \ data_.at(k);\n    }\n};\n"
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
  timestamp: '2026-04-12 14:16:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-0560.test.cpp
  - verify/AOJ-DSL-5-B.test.cpp
documentation_of: Library/DataStructure/CumulativeSum2D.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/CumulativeSum2D.hpp
- /library/Library/DataStructure/CumulativeSum2D.hpp.html
title: Library/DataStructure/CumulativeSum2D.hpp
---
