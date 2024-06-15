---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/Graph/Kruskal.hpp
    title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
  - icon: ':warning:'
    path: old/Graph/Kruskal.hpp
    title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-1-A.test.cpp
    title: verify/AOJ-DSL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-MinimumSpanningTree.test.cpp
    title: verify/LC-MinimumSpanningTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-Unionfind.test.cpp
    title: verify/LC-Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
    links: []
  bundledCode: "#line 2 \"library/DataStructure/UnionFind.hpp\"\n\n/**\n * @file UnionFind.hpp\n\
    \ * @author log K (lX57)\n * @brief UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020\n * @version 3.0\n * @date 2024-04-26\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T = int>\nstruct UnionFind{\n    private:\n\
    \    vector<int> data_;\n\n    public:\n    /**\n     * @brief \u8981\u7D20\u6570\
    \ `Size` \u3067UnionFind\u3092\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param\
    \ Size \u8981\u7D20\u6570\n     */\n    UnionFind(int Size) : data_(Size, -1){}\n\
    \n    /**\n     * @brief \u8981\u7D20 `k` \u306E\u89AA\u3092\u8FD4\u3059\u3002\
    \u3064\u3044\u3067\u306B\u7D4C\u8DEF\u5727\u7E2E\u3092\u3059\u308B\u3002\n   \
    \  * @param k \u63A2\u7D22\u3059\u308B\u8981\u7D20\n     * @return int \u89AA\u8981\
    \u7D20\u306E\u756A\u53F7\n     */\n    int find(int k){\n        if(data_[k] <\
    \ 0) return k;\n        int r = find(data_[k]);\n        return data_[k] = r;\n\
    \    }\n\n    /**\n     * @brief \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u304C\
    \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\u304B\u3092\u5224\
    \u5B9A\u3059\u308B\u3002\n     */\n    bool same(int x, int y){\n        return\
    \ find(x) == find(y);\n    }\n\n    /**\n     * @brief \u8981\u7D20 `x` \u3068\
    \u8981\u7D20 `y` \u3092\u4F75\u5408\u3059\u308B\u3002\n     * @return \u4F75\u5408\
    \u6E08\u306E\u5834\u5408\u306F `false` \u3092\u8FD4\u3059\u3002\n     */\n   \
    \ bool unite(int x, int y){\n        x = find(x), y = find(y);\n        if(x ==\
    \ y) return false;\n        if(data_[x] > data_[y]) swap(x, y);\n        data_[x]\
    \ += data_[y];\n        data_[y] = x;\n        return true;\n    }\n\n    vector<vector<int>>\
    \ group(){\n        vector<vector<int>> ret(data_.size());\n        for(int i\
    \ = 0; i < data_.size(); ++i){\n            ret[find(i)].emplace_back(i);\n  \
    \      }\n        ret.erase(remove_if(begin(ret), end(ret), [&](vector<int> &v){\n\
    \            return v.empty();\n        }), end(ret));\n        return ret;\n\
    \    }\n\n    int size(int k){\n        int v = find(k);\n        return -data_[v];\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @file UnionFind.hpp\n * @author log K (lX57)\n *\
    \ @brief UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\n * @version\
    \ 3.0\n * @date 2024-04-26\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate<typename T = int>\nstruct UnionFind{\n    private:\n    vector<int>\
    \ data_;\n\n    public:\n    /**\n     * @brief \u8981\u7D20\u6570 `Size` \u3067\
    UnionFind\u3092\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Size \u8981\
    \u7D20\u6570\n     */\n    UnionFind(int Size) : data_(Size, -1){}\n\n    /**\n\
    \     * @brief \u8981\u7D20 `k` \u306E\u89AA\u3092\u8FD4\u3059\u3002\u3064\u3044\
    \u3067\u306B\u7D4C\u8DEF\u5727\u7E2E\u3092\u3059\u308B\u3002\n     * @param k\
    \ \u63A2\u7D22\u3059\u308B\u8981\u7D20\n     * @return int \u89AA\u8981\u7D20\u306E\
    \u756A\u53F7\n     */\n    int find(int k){\n        if(data_[k] < 0) return k;\n\
    \        int r = find(data_[k]);\n        return data_[k] = r;\n    }\n\n    /**\n\
    \     * @brief \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u304C\u540C\u3058\u96C6\
    \u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \u3002\n     */\n    bool same(int x, int y){\n        return find(x) == find(y);\n\
    \    }\n\n    /**\n     * @brief \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u3092\
    \u4F75\u5408\u3059\u308B\u3002\n     * @return \u4F75\u5408\u6E08\u306E\u5834\u5408\
    \u306F `false` \u3092\u8FD4\u3059\u3002\n     */\n    bool unite(int x, int y){\n\
    \        x = find(x), y = find(y);\n        if(x == y) return false;\n       \
    \ if(data_[x] > data_[y]) swap(x, y);\n        data_[x] += data_[y];\n       \
    \ data_[y] = x;\n        return true;\n    }\n\n    vector<vector<int>> group(){\n\
    \        vector<vector<int>> ret(data_.size());\n        for(int i = 0; i < data_.size();\
    \ ++i){\n            ret[find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](vector<int> &v){\n            return v.empty();\n        }), end(ret));\n\
    \        return ret;\n    }\n\n    int size(int k){\n        int v = find(k);\n\
    \        return -data_[v];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/UnionFind.hpp
  requiredBy:
  - library/Graph/Kruskal.hpp
  - old/Graph/Kruskal.hpp
  timestamp: '2024-06-15 11:32:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-MinimumSpanningTree.test.cpp
  - verify/LC-Unionfind.test.cpp
  - verify/AOJ-DSL-1-A.test.cpp
documentation_of: library/DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/library/DataStructure/UnionFind.hpp
- /library/library/DataStructure/UnionFind.hpp.html
title: "UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
---
