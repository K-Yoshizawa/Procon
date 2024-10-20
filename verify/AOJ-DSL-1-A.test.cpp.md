---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/UnionFind.hpp
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
    \n\n#line 2 \"Library/DataStructure/UnionFind.hpp\"\n\n/**\n * @file UnionFind.hpp\n\
    \ * @author log K (lX57)\n * @brief UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020\n * @version 4.0\n * @date 2024-09-05\n */\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n#line 12 \"Library/DataStructure/UnionFind.hpp\"\n\nclass\
    \ UnionFind{\n    public:\n    /**\n     * @brief \u8981\u7D20\u6570 `size` \u3067\
    UnionFind\u3092\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param size \u8981\
    \u7D20\u6570\n     */\n    UnionFind(int size) : data_(size, -1){}\n\n    /**\n\
    \     * @brief \u8981\u7D20 `k` \u306E\u89AA\u3092\u8FD4\u3059\u3002\n     * @param\
    \ k \u63A2\u7D22\u3059\u308B\u8981\u7D20\n     * @return int \u89AA\u8981\u7D20\
    \u306E\u756A\u53F7\n     */\n    int Find(int k){\n        if(data_[k] < 0) return\
    \ k;\n        int r = Find(data_[k]);\n        return data_[k] = r;\n    }\n\n\
    \    /**\n     * @brief \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u304C\u540C\u3058\
    \u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\u3002\n     * @param x \u8981\u7D20\u756A\u53F7 (0-index)\n     * @param\
    \ y \u8981\u7D20\u756A\u53F7 (0-index)\n     */\n    bool Same(int x, int y){\n\
    \        return Find(x) == Find(y);\n    }\n\n    /**\n     * @brief \u8981\u7D20\
    \ `x` \u3068\u8981\u7D20 `y` \u3092\u4F75\u5408\u3059\u308B\u3002\n     * @param\
    \ x \u8981\u7D20\u756A\u53F7 (0-index)\n     * @param y \u8981\u7D20\u756A\u53F7\
    \ (0-index)\n     * @return true \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u3092\
    \u4F75\u5408\u3057\u305F (\u5143\u3005\u672A\u4F75\u5408\u3060\u3063\u305F)\n\
    \     * @return false \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u304C\u65E2\u306B\
    \u4F75\u5408\u6E08\u3060\u3063\u305F\n     */\n    bool Unite(int x, int y){\n\
    \        x = Find(x), y = Find(y);\n        if(x == y) return false;\n       \
    \ if(data_[x] > data_[y]) swap(x, y);\n        data_[x] += data_[y];\n       \
    \ data_[y] = x;\n        return true;\n    }\n\n    /**\n     * @brief \u5404\u96C6\
    \u5408\u306B\u6240\u5C5E\u3059\u308B\u8981\u7D20\u3092\u5217\u6319\u3059\u308B\
    \u3002\n     * @return vector<vector<int>> \u5404\u96C6\u5408\u306B\u6240\u5C5E\
    \u3059\u308B\u8981\u7D20\u306E\u4E00\u89A7\n     */\n    vector<vector<int>> Group(){\n\
    \        vector<vector<int>> ret(data_.size());\n        for(int i = 0; i < data_.size();\
    \ ++i){\n            ret[Find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](vector<int> &v){\n            return v.empty();\n        }), end(ret));\n\
    \        return ret;\n    }\n\n    /**\n     * @brief \u8981\u7D20 `k` \u304C\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\u6C42\u3081\u308B\u3002\
    \n     * @param k \u8981\u7D20\u756A\u53F7 (0-index)\n     * @return int \u96C6\
    \u5408\u306E\u8981\u7D20\u6570\n     */\n    int Size(int k){\n        int v =\
    \ Find(k);\n        return -data_[v];\n    }\n\n    private:\n    vector<int>\
    \ data_;\n};\n#line 4 \"verify/AOJ-DSL-1-A.test.cpp\"\n\nint main(){\n    int\
    \ n, q; cin >> n >> q;\n\n    UnionFind uf(n);\n    while(q--){\n        int com,\
    \ x, y; cin >> com >> x >> y;\n        if(com == 0) uf.Unite(x, y);\n        else\
    \ cout << (uf.Same(x, y) ? 1 : 0) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include \"../Library/DataStructure/UnionFind.hpp\"\n\nint main(){\n    int\
    \ n, q; cin >> n >> q;\n\n    UnionFind uf(n);\n    while(q--){\n        int com,\
    \ x, y; cin >> com >> x >> y;\n        if(com == 0) uf.Unite(x, y);\n        else\
    \ cout << (uf.Same(x, y) ? 1 : 0) << endl;\n    }\n}"
  dependsOn:
  - Library/DataStructure/UnionFind.hpp
  - Library/Common.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-1-A.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 07:46:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-1-A.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-1-A.test.cpp
- /verify/verify/AOJ-DSL-1-A.test.cpp.html
title: verify/AOJ-DSL-1-A.test.cpp
---
