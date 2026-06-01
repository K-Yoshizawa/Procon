---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-RectangleSum.test.cpp
    title: verify/LC-RectangleSum.test.cpp
  - icon: ':x:'
    path: verify/LC-StaticRangeSumWithUpperBound.test.cpp
    title: verify/LC-StaticRangeSumWithUpperBound.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cmath>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const\
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 2 \"Library/DataStructure/MergeSortTree.hpp\"\
    \n\ntemplate <typename DataType, typename WeightType = DataType>\nclass MergeSortTree{\n\
    \    public:\n    MergeSortTree(\n        const vector<DataType> &A,\n       \
    \ const vector<WeightType> &B,\n        bool zero_index = false\n    ) : zero_index_(zero_index){\n\
    \        Build(A, B);\n    }\n    \n    MergeSortTree(\n        const vector<DataType>\
    \ &A,\n        bool zero_index = false\n    ) : zero_index_(zero_index){\n   \
    \     Build(A, A);\n    }\n\n    int CountAtMost(int l, int r, DataType x) const\
    \ {\n        if(l >= r) return 0;\n        Validate(l + zero_index_);\n      \
    \  Validate(r + zero_index_ - 1);\n        int lh = l + zero_index_ + offset_,\
    \ rh = r + zero_index_ + offset_;\n        int lcnt = 0, rcnt = 0;\n        while(lh\
    \ < rh){\n            if(lh & 1){\n                lcnt += distance(data_[lh].begin(),\
    \ upper_bound(data_[lh].begin(), data_[lh].end(), x));\n                ++lh;\n\
    \            }\n            if(rh & 1){\n                --rh;\n             \
    \   rcnt += distance(data_[rh].begin(), upper_bound(data_[rh].begin(), data_[rh].end(),\
    \ x));\n            }\n            lh >>= 1, rh >>= 1;\n        }\n        return\
    \ lcnt + rcnt;\n    }\n\n    int CountAtLeast(int l, int r, DataType x) const\
    \ {\n        if(l >= r) return 0;\n        return r - l - CountAtMost(l, r, x\
    \ - 1);\n    }\n\n    int CountBetween(int l, int r, DataType p, DataType q) const\
    \ {\n        return CountAtMost(l, r, q) - CountAtMost(l, r, p - 1);\n    }\n\n\
    \    WeightType SumAtMost(int l, int r, DataType x) const {\n        if(l >= r)\
    \ return 0;\n        Validate(l + zero_index_);\n        Validate(r + zero_index_\
    \ - 1);\n        int lh = l + zero_index_ + offset_, rh = r + zero_index_ + offset_;\n\
    \        WeightType lval = 0, rval = 0;\n        while(lh < rh){\n           \
    \ if(lh & 1){\n                int idx = distance(data_[lh].begin(), upper_bound(data_[lh].begin(),\
    \ data_[lh].end(), x));\n                lval += prefix_sum_[lh][idx];\n     \
    \           ++lh;\n            }\n            if(rh & 1){\n                --rh;\n\
    \                int idx = distance(data_[rh].begin(), upper_bound(data_[rh].begin(),\
    \ data_[rh].end(), x));\n                rval += prefix_sum_[rh][idx];\n     \
    \       }\n            lh >>= 1, rh >>= 1;\n        }\n        return lval + rval;\n\
    \    }\n\n    WeightType SumAtLeast(int l, int r, DataType x) const {\n      \
    \  if(l >= r) return 0;\n        Validate(l + zero_index_);\n        Validate(r\
    \ + zero_index_ - 1);\n        int lh = l + zero_index_ + offset_, rh = r + zero_index_\
    \ + offset_;\n        WeightType lval = 0, rval = 0;\n        while(lh < rh){\n\
    \            if(lh & 1){\n                int idx = distance(data_[lh].begin(),\
    \ lower_bound(data_[lh].begin(), data_[lh].end(), x));\n                lval +=\
    \ prefix_sum_[lh].back() - prefix_sum_[lh][idx];\n                ++lh;\n    \
    \        }\n            if(rh & 1){\n                --rh;\n                int\
    \ idx = distance(data_[rh].begin(), lower_bound(data_[rh].begin(), data_[rh].end(),\
    \ x));\n                rval += prefix_sum_[rh].back() - prefix_sum_[rh][idx];\n\
    \            }\n            lh >>= 1, rh >>= 1;\n        }\n        return lval\
    \ + rval;\n    }\n\n    WeightType SumBetween(int l, int r, DataType p, DataType\
    \ q) const {\n        return SumAtMost(l, r, q) - SumAtMost(l, r, p - 1);\n  \
    \  }\n    \n    private:\n    int n_, offset_, zero_index_;\n    vector<vector<DataType>>\
    \ data_;\n    vector<vector<WeightType>> weight_, prefix_sum_;\n\n    void Build(const\
    \ vector<DataType> &data, const vector<WeightType> &weight){\n        n_ = 1;\n\
    \        while(n_ < (int)data.size()) n_ <<= 1;\n        offset_ = n_ - 1;\n \
    \       data_.resize(2 * n_);\n        weight_.resize(2 * n_);\n        prefix_sum_.resize(2\
    \ * n_);\n        for(int i = 0; i < (int)data.size(); ++i){\n            data_[n_\
    \ + i].emplace_back(data[i]);\n            weight_[n_ + i].emplace_back(weight[i]);\n\
    \            prefix_sum_[n_ + i].emplace_back(0);\n            prefix_sum_[n_\
    \ + i].emplace_back(weight[i]);\n        }\n        for(int i = offset_; i >=\
    \ 1; --i){\n            int l = i * 2 + 0, r = i * 2 + 1, li = 0, ri = 0, j =\
    \ 0;\n            int ls = (int)data_[l].size(), rs = (int)data_[r].size();\n\
    \            data_[i].resize(ls + rs);\n            weight_[i].resize(ls + rs);\n\
    \            prefix_sum_[i].resize(ls + rs + 1);\n            while(li < ls ||\
    \ ri < rs){\n                if(ri == rs || li != ls && data_[l][li] < data_[r][ri]){\n\
    \                    data_[i][j] = data_[l][li];\n                    weight_[i][j]\
    \ = weight_[l][li];\n                    prefix_sum_[i][j + 1] = prefix_sum_[i][j]\
    \ + weight_[i][j];\n                    ++j, ++li;\n                }\n      \
    \          else{\n                    data_[i][j] = data_[r][ri];\n          \
    \          weight_[i][j] = weight_[r][ri];\n                    prefix_sum_[i][j\
    \ + 1] = prefix_sum_[i][j] + weight_[i][j];\n                    ++j, ++ri;\n\
    \                }\n            }\n        }\n    }\n    \n    inline void Validate(int\
    \ x) const {\n        assert(1 <= x && x <= n_);\n    }\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate <typename DataType, typename WeightType\
    \ = DataType>\nclass MergeSortTree{\n    public:\n    MergeSortTree(\n       \
    \ const vector<DataType> &A,\n        const vector<WeightType> &B,\n        bool\
    \ zero_index = false\n    ) : zero_index_(zero_index){\n        Build(A, B);\n\
    \    }\n    \n    MergeSortTree(\n        const vector<DataType> &A,\n       \
    \ bool zero_index = false\n    ) : zero_index_(zero_index){\n        Build(A,\
    \ A);\n    }\n\n    int CountAtMost(int l, int r, DataType x) const {\n      \
    \  if(l >= r) return 0;\n        Validate(l + zero_index_);\n        Validate(r\
    \ + zero_index_ - 1);\n        int lh = l + zero_index_ + offset_, rh = r + zero_index_\
    \ + offset_;\n        int lcnt = 0, rcnt = 0;\n        while(lh < rh){\n     \
    \       if(lh & 1){\n                lcnt += distance(data_[lh].begin(), upper_bound(data_[lh].begin(),\
    \ data_[lh].end(), x));\n                ++lh;\n            }\n            if(rh\
    \ & 1){\n                --rh;\n                rcnt += distance(data_[rh].begin(),\
    \ upper_bound(data_[rh].begin(), data_[rh].end(), x));\n            }\n      \
    \      lh >>= 1, rh >>= 1;\n        }\n        return lcnt + rcnt;\n    }\n\n\
    \    int CountAtLeast(int l, int r, DataType x) const {\n        if(l >= r) return\
    \ 0;\n        return r - l - CountAtMost(l, r, x - 1);\n    }\n\n    int CountBetween(int\
    \ l, int r, DataType p, DataType q) const {\n        return CountAtMost(l, r,\
    \ q) - CountAtMost(l, r, p - 1);\n    }\n\n    WeightType SumAtMost(int l, int\
    \ r, DataType x) const {\n        if(l >= r) return 0;\n        Validate(l + zero_index_);\n\
    \        Validate(r + zero_index_ - 1);\n        int lh = l + zero_index_ + offset_,\
    \ rh = r + zero_index_ + offset_;\n        WeightType lval = 0, rval = 0;\n  \
    \      while(lh < rh){\n            if(lh & 1){\n                int idx = distance(data_[lh].begin(),\
    \ upper_bound(data_[lh].begin(), data_[lh].end(), x));\n                lval +=\
    \ prefix_sum_[lh][idx];\n                ++lh;\n            }\n            if(rh\
    \ & 1){\n                --rh;\n                int idx = distance(data_[rh].begin(),\
    \ upper_bound(data_[rh].begin(), data_[rh].end(), x));\n                rval +=\
    \ prefix_sum_[rh][idx];\n            }\n            lh >>= 1, rh >>= 1;\n    \
    \    }\n        return lval + rval;\n    }\n\n    WeightType SumAtLeast(int l,\
    \ int r, DataType x) const {\n        if(l >= r) return 0;\n        Validate(l\
    \ + zero_index_);\n        Validate(r + zero_index_ - 1);\n        int lh = l\
    \ + zero_index_ + offset_, rh = r + zero_index_ + offset_;\n        WeightType\
    \ lval = 0, rval = 0;\n        while(lh < rh){\n            if(lh & 1){\n    \
    \            int idx = distance(data_[lh].begin(), lower_bound(data_[lh].begin(),\
    \ data_[lh].end(), x));\n                lval += prefix_sum_[lh].back() - prefix_sum_[lh][idx];\n\
    \                ++lh;\n            }\n            if(rh & 1){\n             \
    \   --rh;\n                int idx = distance(data_[rh].begin(), lower_bound(data_[rh].begin(),\
    \ data_[rh].end(), x));\n                rval += prefix_sum_[rh].back() - prefix_sum_[rh][idx];\n\
    \            }\n            lh >>= 1, rh >>= 1;\n        }\n        return lval\
    \ + rval;\n    }\n\n    WeightType SumBetween(int l, int r, DataType p, DataType\
    \ q) const {\n        return SumAtMost(l, r, q) - SumAtMost(l, r, p - 1);\n  \
    \  }\n    \n    private:\n    int n_, offset_, zero_index_;\n    vector<vector<DataType>>\
    \ data_;\n    vector<vector<WeightType>> weight_, prefix_sum_;\n\n    void Build(const\
    \ vector<DataType> &data, const vector<WeightType> &weight){\n        n_ = 1;\n\
    \        while(n_ < (int)data.size()) n_ <<= 1;\n        offset_ = n_ - 1;\n \
    \       data_.resize(2 * n_);\n        weight_.resize(2 * n_);\n        prefix_sum_.resize(2\
    \ * n_);\n        for(int i = 0; i < (int)data.size(); ++i){\n            data_[n_\
    \ + i].emplace_back(data[i]);\n            weight_[n_ + i].emplace_back(weight[i]);\n\
    \            prefix_sum_[n_ + i].emplace_back(0);\n            prefix_sum_[n_\
    \ + i].emplace_back(weight[i]);\n        }\n        for(int i = offset_; i >=\
    \ 1; --i){\n            int l = i * 2 + 0, r = i * 2 + 1, li = 0, ri = 0, j =\
    \ 0;\n            int ls = (int)data_[l].size(), rs = (int)data_[r].size();\n\
    \            data_[i].resize(ls + rs);\n            weight_[i].resize(ls + rs);\n\
    \            prefix_sum_[i].resize(ls + rs + 1);\n            while(li < ls ||\
    \ ri < rs){\n                if(ri == rs || li != ls && data_[l][li] < data_[r][ri]){\n\
    \                    data_[i][j] = data_[l][li];\n                    weight_[i][j]\
    \ = weight_[l][li];\n                    prefix_sum_[i][j + 1] = prefix_sum_[i][j]\
    \ + weight_[i][j];\n                    ++j, ++li;\n                }\n      \
    \          else{\n                    data_[i][j] = data_[r][ri];\n          \
    \          weight_[i][j] = weight_[r][ri];\n                    prefix_sum_[i][j\
    \ + 1] = prefix_sum_[i][j] + weight_[i][j];\n                    ++j, ++ri;\n\
    \                }\n            }\n        }\n    }\n    \n    inline void Validate(int\
    \ x) const {\n        assert(1 <= x && x <= n_);\n    }\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/MergeSortTree.hpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/LC-StaticRangeSumWithUpperBound.test.cpp
  - verify/LC-RectangleSum.test.cpp
documentation_of: Library/DataStructure/MergeSortTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/MergeSortTree.hpp
- /library/Library/DataStructure/MergeSortTree.hpp.html
title: Library/DataStructure/MergeSortTree.hpp
---
