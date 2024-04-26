---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/DataStructure/UnionFind.hpp
    title: "UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"verify/AOJ-DSL-1-A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#line 2 \"library/DataStructure/UnionFind.hpp\"\n\n/**\n * @file UnionFind.hpp\n\
    \ * @author log K (lX57)\n * @brief UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020\n * @version 3.0\n * @date 2024-04-26\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T = int>\nstruct UnionFind{\n    private:\n\
    \    vector<int> m_data;\n\n    public:\n    /**\n     * @brief \u8981\u7D20\u6570\
    \ `Size` \u3067UnionFind\u3092\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param\
    \ Size \u8981\u7D20\u6570\n     */\n    UnionFind(int Size) : m_data(Size, -1){}\n\
    \n    /**\n     * @brief \u8981\u7D20 `k` \u306E\u89AA\u3092\u8FD4\u3059\u3002\
    \u3064\u3044\u3067\u306B\u7D4C\u8DEF\u5727\u7E2E\u3092\u3059\u308B\u3002\n   \
    \  * @param k \u63A2\u7D22\u3059\u308B\u8981\u7D20\n     * @return int \u89AA\u8981\
    \u7D20\u306E\u756A\u53F7\n     */\n    int find(int k){\n        if(m_data[k]\
    \ < 0) return k;\n        int r = find(m_data[k]);\n        return m_data[k] =\
    \ r;\n    }\n\n    /**\n     * @brief \u8981\u7D20 `x` \u3068\u8981\u7D20 `y`\
    \ \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\u304B\u3092\
    \u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool same(int x, int y){\n      \
    \  return find(x) == find(y);\n    }\n\n    /**\n     * @brief \u8981\u7D20 `x`\
    \ \u3068\u8981\u7D20 `y` \u3092\u4F75\u5408\u3059\u308B\u3002\n     * @return\
    \ \u4F75\u5408\u6E08\u306E\u5834\u5408\u306F `false` \u3092\u8FD4\u3059\u3002\n\
    \     */\n    bool unite(int x, int y){\n        x = find(x), y = find(y);\n \
    \       if(x == y) return false;\n        if(m_data[x] > m_data[y]) swap(x, y);\n\
    \        m_data[x] += m_data[y];\n        m_data[y] = x;\n        return true;\n\
    \    }\n\n    vector<vector<int>> group(){\n        vector<vector<int>> ret(m_data.size());\n\
    \        for(int i = 0; i < m_data.size(); ++i){\n            ret[find(i)].emplace_back(i);\n\
    \        }\n        ret.erase(remove_if(begin(ret), end(ret), [&](vector<int>\
    \ &v){\n            return v.empty();\n        }), end(ret));\n        return\
    \ ret;\n    }\n};\n#line 4 \"verify/AOJ-DSL-1-A.test.cpp\"\n\nint main(){\n  \
    \  int n, q; cin >> n >> q;\n\n    UnionFind uf(n);\n    while(q--){\n       \
    \ int com, x, y; cin >> com >> x >> y;\n        if(com == 0) uf.unite(x, y);\n\
    \        else cout << (uf.same(x, y) ? 1 : 0) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include \"../library/DataStructure/UnionFind.hpp\"\n\nint main(){\n    int\
    \ n, q; cin >> n >> q;\n\n    UnionFind uf(n);\n    while(q--){\n        int com,\
    \ x, y; cin >> com >> x >> y;\n        if(com == 0) uf.unite(x, y);\n        else\
    \ cout << (uf.same(x, y) ? 1 : 0) << endl;\n    }\n}"
  dependsOn:
  - library/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-1-A.test.cpp
  requiredBy: []
  timestamp: '2024-04-26 23:46:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-1-A.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-1-A.test.cpp
- /verify/verify/AOJ-DSL-1-A.test.cpp.html
title: verify/AOJ-DSL-1-A.test.cpp
---
