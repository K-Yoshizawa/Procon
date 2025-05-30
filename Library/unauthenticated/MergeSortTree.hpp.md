---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Merge-Sort Tree - \u9818\u57DF\u6728"
    links: []
  bundledCode: "#line 1 \"Library/unauthenticated/MergeSortTree.hpp\"\n/**\n * @file\
    \ MergeSortTree.hpp\n * @brief Merge-Sort Tree - \u9818\u57DF\u6728\n * @version\
    \ 1.0\n * @date 2024-02-04\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate <typename T>\nstruct MergeSortTree{\n    private:\n    vector<vector<T>>\
    \ data_, cum_, weight_;\n    int size_, offset_;\n\n    void build_(vector<T>\
    \ &V, vector<T> &W){\n        size_ = 1;\n        while(size_ < V.size()) size_\
    \ <<= 1;\n        offset_ = size_ - 1;\n        data_.resize(2 * size_);\n   \
    \     weight_.resize(2 * size_);\n        for(int i = 0; i < (int)V.size(); ++i){\n\
    \            data_[size_ + i].push_back(V[i]);\n            weight_[size_ + i].push_back(W[i]);\n\
    \        }\n        for(int i = offset_; i >= 1; --i){\n            int l = i\
    \ * 2, r = i * 2 + 1, x = 0, y = 0;\n            while(x < data_[l].size() or\
    \ y < data_[r].size()){\n                if(x == data_[l].size()){\n         \
    \           data_[i].push_back(data_[r][y]);\n                    weight_[i].push_back(weight_[r][y++]);\n\
    \                    continue;\n                }\n                if(y == data_[r].size()){\n\
    \                    data_[i].push_back(data_[l][x]);\n                    weight_[i].push_back(weight_[l][x++]);\n\
    \                    continue;\n                }\n                if(data_[l][x]\
    \ < data_[r][y]){\n                    data_[i].push_back(data_[l][x]);\n    \
    \                weight_[i].push_back(weight_[l][x++]);\n                }\n \
    \               else{\n                    data_[i].push_back(data_[r][y]);\n\
    \                    weight_[i].push_back(weight_[r][y++]);\n                }\n\
    \            }\n        }\n        cum_.resize(2 * size_);\n        for(int i\
    \ = 0; i < cum_.size(); ++i){\n            cum_[i].resize(data_[i].size() + 1,\
    \ 0);\n            for(int j = 0; j < data_[i].size(); ++j){\n               \
    \ cum_[i][j + 1] += cum_[i][j];\n                cum_[i][j + 1] += weight_[i][j];\n\
    \            }\n        }\n    }\n\n    T query_(int ql, int qr, int left, int\
    \ right, int cell, T x){\n        if(qr <= left || right <= ql) return 0;\n  \
    \      if(ql <= left && right <= qr){\n            int index = upper_bound(data_[cell].begin(),\
    \ data_[cell].end(), x) - data_[cell].begin();\n            return cum_[cell][index];\n\
    \        }\n        int mid = (left + right) / 2;\n        T al = query_(ql, qr,\
    \ left, mid, 2 * cell, x);\n        T ar = query_(ql, qr, mid, right, 2 * cell\
    \ + 1, x);\n        return al + ar;\n    }\n\n    public:\n    MergeSortTree(vector<T>\
    \ &V){\n        build_(V, vector<T>(V.size(), 1));\n    }\n\n    MergeSortTree(vector<T>\
    \ &V, vector<T> &W){\n        build_(V, W);\n    }\n\n    /**\n     * @brief `[left,\
    \ right)` \u306B\u542B\u307E\u308C\u308B `x` \u4EE5\u4E0B\u306E\u5024\u306E `w`\
    \ \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\u3002\n     * @param left \u534A\u958B\
    \u533A\u9593\u306E\u5DE6\u7AEF(1-index)\n     * @param right \u534A\u958B\u533A\
    \u9593\u306E\u53F3\u7AEF(1-index)\n     * @param x \u5883\u754C\u5024\n     *\
    \ @return T \u30AF\u30A8\u30EA\u306E\u7B54\u3048\n     */\n    T query(int left,\
    \ int right, T x){\n        return query_(left, right, 1, size_ + 1, 1, x);\n\
    \    }\n\n    /**\n     * @brief `[left, right) x [lower, upper)` \u306B\u542B\
    \u307E\u308C\u308B `w` \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\u3002\n    \
    \ * @param left x\u8EF8\u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF(1-index)\n \
    \    * @param right x\u8EF8\u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF(1-index)\n\
    \     * @param lower y\u8EF8\u534A\u958B\u533A\u9593\u306E\u4E0B\u7AEF(1-index)\n\
    \     * @param upper y\u8EF8\u534A\u958B\u533A\u9593\u306E\u4E0A\u7AEF(1-index)\n\
    \     * @return T \n     */\n    T rect_query(int left, int right, T lower, T\
    \ upper){\n        return query(left, right, upper - 1) - query(left, right, lower\
    \ - 1);\n    }\n\n    /**\n     * @brief MST\u306E\u4E2D\u8EAB\u3092\u51FA\u529B\
    \u3059\u308B\n     */\n    void print(){\n        int i = 1;\n        for(int\
    \ d = 1; i < size_ * 2; d <<= 1){\n            for(int j = 0; j < d; ++i, ++j){\n\
    \                cerr << j << \" {\";\n                for(int k = 0; k < data_[i].size();\
    \ ++k){\n                    cerr << data_[i][k] << (k + 1 == data_[i].size()\
    \ ? \"} \" : \", \");\n                }\n                cerr << '\\n';\n   \
    \             cerr << \"  {\";\n                for(int k = 0; k <= data_[i].size();\
    \ ++k){\n                    cerr << cum_[i][k] << (k == data_[i].size() ? \"\
    } \" : \", \");\n                }\n                cerr << '\\n';\n         \
    \   }\n            cerr << \"========================================\\n\";\n\
    \        }\n    }\n};\n"
  code: "/**\n * @file MergeSortTree.hpp\n * @brief Merge-Sort Tree - \u9818\u57DF\
    \u6728\n * @version 1.0\n * @date 2024-02-04\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T>\nstruct MergeSortTree{\n    private:\n\
    \    vector<vector<T>> data_, cum_, weight_;\n    int size_, offset_;\n\n    void\
    \ build_(vector<T> &V, vector<T> &W){\n        size_ = 1;\n        while(size_\
    \ < V.size()) size_ <<= 1;\n        offset_ = size_ - 1;\n        data_.resize(2\
    \ * size_);\n        weight_.resize(2 * size_);\n        for(int i = 0; i < (int)V.size();\
    \ ++i){\n            data_[size_ + i].push_back(V[i]);\n            weight_[size_\
    \ + i].push_back(W[i]);\n        }\n        for(int i = offset_; i >= 1; --i){\n\
    \            int l = i * 2, r = i * 2 + 1, x = 0, y = 0;\n            while(x\
    \ < data_[l].size() or y < data_[r].size()){\n                if(x == data_[l].size()){\n\
    \                    data_[i].push_back(data_[r][y]);\n                    weight_[i].push_back(weight_[r][y++]);\n\
    \                    continue;\n                }\n                if(y == data_[r].size()){\n\
    \                    data_[i].push_back(data_[l][x]);\n                    weight_[i].push_back(weight_[l][x++]);\n\
    \                    continue;\n                }\n                if(data_[l][x]\
    \ < data_[r][y]){\n                    data_[i].push_back(data_[l][x]);\n    \
    \                weight_[i].push_back(weight_[l][x++]);\n                }\n \
    \               else{\n                    data_[i].push_back(data_[r][y]);\n\
    \                    weight_[i].push_back(weight_[r][y++]);\n                }\n\
    \            }\n        }\n        cum_.resize(2 * size_);\n        for(int i\
    \ = 0; i < cum_.size(); ++i){\n            cum_[i].resize(data_[i].size() + 1,\
    \ 0);\n            for(int j = 0; j < data_[i].size(); ++j){\n               \
    \ cum_[i][j + 1] += cum_[i][j];\n                cum_[i][j + 1] += weight_[i][j];\n\
    \            }\n        }\n    }\n\n    T query_(int ql, int qr, int left, int\
    \ right, int cell, T x){\n        if(qr <= left || right <= ql) return 0;\n  \
    \      if(ql <= left && right <= qr){\n            int index = upper_bound(data_[cell].begin(),\
    \ data_[cell].end(), x) - data_[cell].begin();\n            return cum_[cell][index];\n\
    \        }\n        int mid = (left + right) / 2;\n        T al = query_(ql, qr,\
    \ left, mid, 2 * cell, x);\n        T ar = query_(ql, qr, mid, right, 2 * cell\
    \ + 1, x);\n        return al + ar;\n    }\n\n    public:\n    MergeSortTree(vector<T>\
    \ &V){\n        build_(V, vector<T>(V.size(), 1));\n    }\n\n    MergeSortTree(vector<T>\
    \ &V, vector<T> &W){\n        build_(V, W);\n    }\n\n    /**\n     * @brief `[left,\
    \ right)` \u306B\u542B\u307E\u308C\u308B `x` \u4EE5\u4E0B\u306E\u5024\u306E `w`\
    \ \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\u3002\n     * @param left \u534A\u958B\
    \u533A\u9593\u306E\u5DE6\u7AEF(1-index)\n     * @param right \u534A\u958B\u533A\
    \u9593\u306E\u53F3\u7AEF(1-index)\n     * @param x \u5883\u754C\u5024\n     *\
    \ @return T \u30AF\u30A8\u30EA\u306E\u7B54\u3048\n     */\n    T query(int left,\
    \ int right, T x){\n        return query_(left, right, 1, size_ + 1, 1, x);\n\
    \    }\n\n    /**\n     * @brief `[left, right) x [lower, upper)` \u306B\u542B\
    \u307E\u308C\u308B `w` \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\u3002\n    \
    \ * @param left x\u8EF8\u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF(1-index)\n \
    \    * @param right x\u8EF8\u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF(1-index)\n\
    \     * @param lower y\u8EF8\u534A\u958B\u533A\u9593\u306E\u4E0B\u7AEF(1-index)\n\
    \     * @param upper y\u8EF8\u534A\u958B\u533A\u9593\u306E\u4E0A\u7AEF(1-index)\n\
    \     * @return T \n     */\n    T rect_query(int left, int right, T lower, T\
    \ upper){\n        return query(left, right, upper - 1) - query(left, right, lower\
    \ - 1);\n    }\n\n    /**\n     * @brief MST\u306E\u4E2D\u8EAB\u3092\u51FA\u529B\
    \u3059\u308B\n     */\n    void print(){\n        int i = 1;\n        for(int\
    \ d = 1; i < size_ * 2; d <<= 1){\n            for(int j = 0; j < d; ++i, ++j){\n\
    \                cerr << j << \" {\";\n                for(int k = 0; k < data_[i].size();\
    \ ++k){\n                    cerr << data_[i][k] << (k + 1 == data_[i].size()\
    \ ? \"} \" : \", \");\n                }\n                cerr << '\\n';\n   \
    \             cerr << \"  {\";\n                for(int k = 0; k <= data_[i].size();\
    \ ++k){\n                    cerr << cum_[i][k] << (k == data_[i].size() ? \"\
    } \" : \", \");\n                }\n                cerr << '\\n';\n         \
    \   }\n            cerr << \"========================================\\n\";\n\
    \        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/unauthenticated/MergeSortTree.hpp
  requiredBy: []
  timestamp: '2025-05-30 19:43:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/MergeSortTree.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/MergeSortTree.hpp
- /library/Library/unauthenticated/MergeSortTree.hpp.html
title: "Merge-Sort Tree - \u9818\u57DF\u6728"
---
