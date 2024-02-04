---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/MergeSortTree.hpp
    title: "Merge-Sort Tree - \u9818\u57DF\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"verify/LC-RectangleSum-MST.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#line 1 \"library/DataStructure/MergeSortTree.hpp\"\
    \n/**\n * @file MergeSortTree.hpp\n * @brief Merge-Sort Tree - \u9818\u57DF\u6728\
    \n * @version 1.0\n * @date 2024-02-04\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <typename T>\nstruct MergeSortTree{\n    private:\n\
    \    vector<vector<T>> m_data, m_cum, m_weight;\n    int m_size, m_offset;\n\n\
    \    void build(vector<T> &V, vector<T> &W){\n        m_size = 1;\n        while(m_size\
    \ < V.size()) m_size <<= 1;\n        m_offset = m_size - 1;\n        m_data.resize(2\
    \ * m_size);\n        m_weight.resize(2 * m_size);\n        for(int i = 0; i <\
    \ (int)V.size(); ++i){\n            m_data[m_size + i].push_back(V[i]);\n    \
    \        m_weight[m_size + i].push_back(W[i]);\n        }\n        for(int i =\
    \ m_offset; i >= 1; --i){\n            int l = i * 2, r = i * 2 + 1, x = 0, y\
    \ = 0;\n            while(x < m_data[l].size() or y < m_data[r].size()){\n   \
    \             if(x == m_data[l].size()){\n                    m_data[i].push_back(m_data[r][y]);\n\
    \                    m_weight[i].push_back(m_weight[r][y++]);\n              \
    \      continue;\n                }\n                if(y == m_data[r].size()){\n\
    \                    m_data[i].push_back(m_data[l][x]);\n                    m_weight[i].push_back(m_weight[l][x++]);\n\
    \                    continue;\n                }\n                if(m_data[l][x]\
    \ < m_data[r][y]){\n                    m_data[i].push_back(m_data[l][x]);\n \
    \                   m_weight[i].push_back(m_weight[l][x++]);\n               \
    \ }\n                else{\n                    m_data[i].push_back(m_data[r][y]);\n\
    \                    m_weight[i].push_back(m_weight[r][y++]);\n              \
    \  }\n            }\n        }\n        m_cum.resize(2 * m_size);\n        for(int\
    \ i = 0; i < m_cum.size(); ++i){\n            m_cum[i].resize(m_data[i].size()\
    \ + 1, 0);\n            for(int j = 0; j < m_data[i].size(); ++j){\n         \
    \       m_cum[i][j + 1] += m_cum[i][j];\n                m_cum[i][j + 1] += m_weight[i][j];\n\
    \            }\n        }\n    }\n\n    T query(int ql, int qr, int left, int\
    \ right, int cell, T x){\n        if(qr <= left || right <= ql) return 0;\n  \
    \      if(ql <= left && right <= qr){\n            int index = upper_bound(m_data[cell].begin(),\
    \ m_data[cell].end(), x) - m_data[cell].begin();\n            return m_cum[cell][index];\n\
    \        }\n        int mid = (left + right) / 2;\n        T al = query(ql, qr,\
    \ left, mid, 2 * cell, x);\n        T ar = query(ql, qr, mid, right, 2 * cell\
    \ + 1, x);\n        return al + ar;\n    }\n\n    public:\n    MergeSortTree(vector<T>\
    \ &V){\n        build(V, vector<T>(V.size(), 1));\n    }\n\n    MergeSortTree(vector<T>\
    \ &V, vector<T> &W){\n        build(V, W);\n    }\n\n    /**\n     * @brief `[left,\
    \ right)` \u306B\u542B\u307E\u308C\u308B `x` \u4EE5\u4E0B\u306E\u5024\u306E `w`\
    \ \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\u3002\n     * @param left \u534A\u958B\
    \u533A\u9593\u306E\u5DE6\u7AEF(1-index)\n     * @param right \u534A\u958B\u533A\
    \u9593\u306E\u53F3\u7AEF(1-index)\n     * @param x \u5883\u754C\u5024\n     *\
    \ @return T \u30AF\u30A8\u30EA\u306E\u7B54\u3048\n     */\n    T query(int left,\
    \ int right, T x){\n        return query(left, right, 1, m_size + 1, 1, x);\n\
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
    \ d = 1; i < m_size * 2; d <<= 1){\n            for(int j = 0; j < d; ++i, ++j){\n\
    \                cerr << j << \" {\";\n                for(int k = 0; k < m_data[i].size();\
    \ ++k){\n                    cerr << m_data[i][k] << (k + 1 == m_data[i].size()\
    \ ? \"} \" : \", \");\n                }\n                cerr << endl;\n    \
    \            cerr << \"  {\";\n                for(int k = 0; k <= m_data[i].size();\
    \ ++k){\n                    cerr << m_cum[i][k] << (k == m_data[i].size() ? \"\
    } \" : \", \");\n                }\n                cerr << endl;\n          \
    \  }\n            cerr << \"========================================\\n\";\n \
    \       }\n    }\n};\n#line 4 \"verify/LC-RectangleSum-MST.test.cpp\"\n\nint main(){\n\
    \    int N, Q; cin >> N >> Q;\n    vector<tuple<long long, long long, long long>>\
    \ p(N);\n    for(int i = 0; i < N; ++i){\n        long long x, y, w; cin >> x\
    \ >> y >> w;\n        p[i] = {x, y, w};\n    }\n    sort(p.begin(), p.end());\n\
    \    vector<long long> x, y, w;\n    transform(p.begin(), p.end(), back_inserter(x),\
    \ [](auto t){return get<0>(t);});\n    transform(p.begin(), p.end(), back_inserter(y),\
    \ [](auto t){return get<1>(t);});\n    transform(p.begin(), p.end(), back_inserter(w),\
    \ [](auto t){return get<2>(t);});\n    vector<long long> l(Q), d(Q), r(Q), u(Q);\n\
    \    for(int i = 0; i < Q; ++i) cin >> l[i] >> d[i] >> r[i] >> u[i];\n\n    MergeSortTree<long\
    \ long> mst(y, w);\n    for(int i = 0; i < Q; ++i){\n        int left = lower_bound(x.begin(),\
    \ x.end(), l[i]) - x.begin() + 1;\n        int right = lower_bound(x.begin(),\
    \ x.end(), r[i]) - x.begin() + 1;\n        cout << mst.rect_query(left, right,\
    \ d[i], u[i]) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../library/DataStructure/MergeSortTree.hpp\"\n\nint main(){\n    int N, Q;\
    \ cin >> N >> Q;\n    vector<tuple<long long, long long, long long>> p(N);\n \
    \   for(int i = 0; i < N; ++i){\n        long long x, y, w; cin >> x >> y >> w;\n\
    \        p[i] = {x, y, w};\n    }\n    sort(p.begin(), p.end());\n    vector<long\
    \ long> x, y, w;\n    transform(p.begin(), p.end(), back_inserter(x), [](auto\
    \ t){return get<0>(t);});\n    transform(p.begin(), p.end(), back_inserter(y),\
    \ [](auto t){return get<1>(t);});\n    transform(p.begin(), p.end(), back_inserter(w),\
    \ [](auto t){return get<2>(t);});\n    vector<long long> l(Q), d(Q), r(Q), u(Q);\n\
    \    for(int i = 0; i < Q; ++i) cin >> l[i] >> d[i] >> r[i] >> u[i];\n\n    MergeSortTree<long\
    \ long> mst(y, w);\n    for(int i = 0; i < Q; ++i){\n        int left = lower_bound(x.begin(),\
    \ x.end(), l[i]) - x.begin() + 1;\n        int right = lower_bound(x.begin(),\
    \ x.end(), r[i]) - x.begin() + 1;\n        cout << mst.rect_query(left, right,\
    \ d[i], u[i]) << endl;\n    }\n}"
  dependsOn:
  - library/DataStructure/MergeSortTree.hpp
  isVerificationFile: true
  path: verify/LC-RectangleSum-MST.test.cpp
  requiredBy: []
  timestamp: '2024-02-04 22:07:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-RectangleSum-MST.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-RectangleSum-MST.test.cpp
- /verify/verify/LC-RectangleSum-MST.test.cpp.html
title: verify/LC-RectangleSum-MST.test.cpp
---
