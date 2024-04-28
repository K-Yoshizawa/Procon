---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Other/Compress.hpp
    title: "Compress - \u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: library/Other/Mo.hpp
    title: Mo's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"verify/LC-StaticRangeFrequency.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\n#line 1 \"library/Other/Compress.hpp\"\
    \n/**\n * @file Compress.hpp\n * @author log_K (lX57)\n * @brief Compress - \u5EA7\
    \u6A19\u5727\u7E2E\n * @version 2.0\n * @date 2024-02-04\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct Compress{\n    private:\n\
    \    size_t m_size;\n    int m_offset;\n    vector<T> m_value;\n\n    public:\n\
    \    /**\n     * @brief \u914D\u5217 `value` \u3092\u521D\u671F\u5024\u3068\u3057\
    \u3066\u767B\u9332\u3059\u308B\u3002\n     * @param values \u521D\u671F\u914D\u5217\
    \n     * @param offset \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u5148\u982D\u306E\u5024\
    \ (default = 0)\n     */\n    Compress(vector<T> &values, int offset = 0) : m_value(values),\
    \ m_offset(offset){}\n\n    /**\n     * @brief \u5EA7\u6A19\u5727\u7E2E\u3092\u5B9F\
    \u884C\u3059\u308B\u3002\n     */\n    void build(){\n        sort(m_value.begin(),\
    \ m_value.end());\n        m_value.erase(unique(m_value.begin(), m_value.end()),\
    \ m_value.end());\n        m_size = m_value.size();\n    }\n\n    vector<int>\
    \ convert(vector<T> &v){\n        vector<int> ret;\n        for(auto x : v) ret.push_back(to_index(x));\n\
    \        return ret;\n    }\n\n    /**\n     * @brief \u914D\u5217\u306B\u5024\
    \u3092\u52A0\u3048\u308B\u3002\n     * @param value \u52A0\u3048\u308B\u5024\n\
    \     */\n    void add(T value){\n        m_value.push_back(value);\n    }\n\n\
    \    /**\n     * @brief `value` \u3092\u5BFE\u5FDC\u3059\u308B `index` \u306B\u5909\
    \u63DB\u3059\u308B\u3002\n     */\n    int to_index(T value){\n        int ret\
    \ = (int)(lower_bound(m_value.begin(), m_value.end(), value) - m_value.begin());\n\
    \        assert(ret < m_size);\n        return ret + m_offset;\n    }\n\n    /**\n\
    \     * @brief `index` \u3092\u5BFE\u5FDC\u3059\u308B `value` \u306B\u5909\u63DB\
    \u3059\u308B\u3002 \n     */\n    T to_value(int index){\n        return m_value.at(index\
    \ - m_offset);\n    }\n\n    int operator[](T value){\n        return to_index(value);\n\
    \    }\n\n    size_t size(){\n        return m_size;\n    }\n};\n#line 1 \"library/Other/Mo.hpp\"\
    \n/**\n * @file Mo.hpp\n * @author log K (lX57)\n * @brief Mo's Algorithm\n *\
    \ @version 1.0\n * @date 2024-02-08\n */\n\n#line 10 \"library/Other/Mo.hpp\"\n\
    using namespace std;\n\nstruct Mo{\n    private:\n    using q = pair<int, int>;\n\
    \    using f = function<void(int)>;\n    int m_querysize, m_rootq, m_blocksize;\n\
    \    vector<q> m_query;\n    vector<vector<int>> m_index;\n\n    public:\n   \
    \ /**\n     * @brief \u533A\u9593\u9577 `Segment_Size` \u306E\u914D\u5217\u306B\
    \u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\u767B\u9332\u3059\u308B\u3002\n   \
    \  * @param Segment_Size \u914D\u5217\u306E\u533A\u9593\u9577\n     * @param Query_Left\
    \ \u30AF\u30A8\u30EA `[l, r)` \u306E\u534A\u958B\u533A\u9593\u5DE6\u7AEF\u306E\
    \u914D\u5217\n     * @param Query_Right \u30AF\u30A8\u30EA `[l, r)` \u306E\u534A\
    \u958B\u533A\u9593\u53F3\u7AEF\u306E\u914D\u5217\n     */\n    Mo(int Segment_Size,\
    \ vector<int> &Query_Left, vector<int> &Query_Right){\n        Segment_Size =\
    \ max(1, Segment_Size);\n        m_querysize = (int)Query_Left.size();\n     \
    \   m_rootq = max(1, (int)sqrt(m_querysize));\n        m_blocksize = (Segment_Size\
    \ + m_rootq - 1) / m_rootq;\n        m_query.resize(m_querysize);\n        m_index.resize(m_blocksize);\n\
    \        for(int i = 0; i < m_querysize; ++i){\n            m_query[i] = {Query_Left[i],\
    \ Query_Right[i]};\n            m_index[Query_Left[i] / m_rootq].push_back(i);\n\
    \        }\n        bool odd = true;\n        for(auto &v : m_index){\n      \
    \      if(odd){\n                sort(v.begin(), v.end(), [&](int i, int j){\n\
    \                    return Query_Right[i] < Query_Right[j];\n               \
    \ });\n            }\n            else{\n                sort(v.begin(), v.end(),\
    \ [&](int i, int j){\n                    return Query_Right[i] > Query_Right[j];\n\
    \                });\n            }\n            odd = ~odd;\n        }\n    }\n\
    \n    /**\n     * @brief \u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\
    \n     * @param add \u533A\u9593\u306B\u542B\u3081\u308B\u3068\u304D\u306E\u51E6\
    \u7406\u3002\u5F15\u6570\u306B\u306F\u914D\u5217\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u756A\u53F7(0-index)\u304C\u6E21\u3055\u308C\u308B\u3002\n     *\
    \ @param sub \u533A\u9593\u304B\u3089\u9664\u304F\u3068\u304D\u306E\u51E6\u7406\
    \u3002\u5F15\u6570\u306B\u306F\u914D\u5217\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u756A\u53F7(0-index)\u304C\u6E21\u3055\u308C\u308B\u3002\n     * @param\
    \ out \u30AF\u30A8\u30EA\u306E\u7B54\u3048\u3092\u6C42\u3081\u308B\u3068\u304D\
    \u306E\u51E6\u7406\u3002\u5F15\u6570\u306B\u306F\u30AF\u30A8\u30EA\u306E\u756A\
    \u53F7(0-index)\u304C\u6E21\u3055\u308C\u308B\u3002\n     */\n    void run(f add,\
    \ f sub, f out){\n        int left = 0, right = 0;\n        for(auto &m : m_index){\n\
    \            for(auto i : m){\n                auto [l, r] = m_query[i];\n   \
    \             while(right < r) add(right++);\n                while(right > r)\
    \ sub(--right);\n                while(left < l) sub(left++);\n              \
    \  while(left > l) add(--left);\n                out(i);\n            }\n    \
    \    }\n    }\n};\n#line 5 \"verify/LC-StaticRangeFrequency.test.cpp\"\n\nusing\
    \ ll = long long;\n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<ll>\
    \ a(N);\n    for(int i = 0; i < N; ++i) cin >> a[i];\n    vector<int> l(Q), r(Q);\n\
    \    vector<ll> x(Q);\n    for(int i = 0; i < Q; ++i) cin >> l[i] >> r[i] >> x[i];\n\
    \n    Compress<ll> cp(a);\n    for(int i = 0; i < Q; ++i) cp.add(x[i]);\n    cp.build();\n\
    \    for(int i = 0; i < N; ++i) a[i] = cp[a[i]];\n\n    vector<int> cnt(cp.size(),\
    \ 0);\n    Mo mo(N, l, r);\n    vector<int> ans(Q);\n    auto add = [&](int i){\n\
    \        ++cnt[a[i]];\n    };\n    auto sub = [&](int i){\n        --cnt[a[i]];\n\
    \    };\n    auto out = [&](int i){\n        ans[i] = cnt[cp[x[i]]];\n    };\n\
    \    mo.run(add, sub, out);\n\n    for(auto a : ans) cout << a << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include \"library/Other/Compress.hpp\"\n#include \"library/Other/Mo.hpp\"\
    \n\nusing ll = long long;\n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<ll>\
    \ a(N);\n    for(int i = 0; i < N; ++i) cin >> a[i];\n    vector<int> l(Q), r(Q);\n\
    \    vector<ll> x(Q);\n    for(int i = 0; i < Q; ++i) cin >> l[i] >> r[i] >> x[i];\n\
    \n    Compress<ll> cp(a);\n    for(int i = 0; i < Q; ++i) cp.add(x[i]);\n    cp.build();\n\
    \    for(int i = 0; i < N; ++i) a[i] = cp[a[i]];\n\n    vector<int> cnt(cp.size(),\
    \ 0);\n    Mo mo(N, l, r);\n    vector<int> ans(Q);\n    auto add = [&](int i){\n\
    \        ++cnt[a[i]];\n    };\n    auto sub = [&](int i){\n        --cnt[a[i]];\n\
    \    };\n    auto out = [&](int i){\n        ans[i] = cnt[cp[x[i]]];\n    };\n\
    \    mo.run(add, sub, out);\n\n    for(auto a : ans) cout << a << endl;\n}"
  dependsOn:
  - library/Other/Compress.hpp
  - library/Other/Mo.hpp
  isVerificationFile: true
  path: verify/LC-StaticRangeFrequency.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 00:45:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-StaticRangeFrequency.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-StaticRangeFrequency.test.cpp
- /verify/verify/LC-StaticRangeFrequency.test.cpp.html
title: verify/LC-StaticRangeFrequency.test.cpp
---
