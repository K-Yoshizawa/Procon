---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Kruskal.hpp
    title: Library/Graph/Kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-1-A.test.cpp
    title: verify/AOJ-DSL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-MinimumSpanningTree.test.cpp
    title: verify/LC-MinimumSpanningTree.test.cpp
  - icon: ':x:'
    path: verify/LC-Unionfind.test.cpp
    title: verify/LC-Unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/UnionFind.hpp\"\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bit>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 4 \"Library/DataStructure/UnionFind.hpp\"\n\nclass UnionFind{\n  \
    \  public:\n    UnionFind(size_t N) : data_(N, -1){}\n\n    int Find(const int\
    \ k){\n        if(data_[k] < 0) return k;\n        int r = Find(data_[k]);\n \
    \       return data_[k] = r;\n    }\n\n    bool Same(const int x, const int y){\n\
    \        return Find(x) == Find(y);\n    }\n\n    bool Unite(int x, int y){\n\
    \        x = Find(x), y = Find(y);\n        if(x == y) return false;\n       \
    \ if(data_[x] > data_[y]) swap(x, y);\n        data_[x] += data_[y];\n       \
    \ data_[y] = x;\n        return true;\n    }\n    \n    size_t Size(int k){\n\
    \        int v = Find(k);\n        return -data_[v];\n    }\n\n    vector<vector<int>>\
    \ Group(){\n        vector<vector<int>> ret(data_.size());\n        for(int i\
    \ = 0; i < data_.size(); ++i){\n            ret[Find(i)].emplace_back(i);\n  \
    \      }\n        ret.erase(remove_if(begin(ret), end(ret), [&](vector<int> &v){\n\
    \            return v.empty();\n        }), end(ret));\n        return ret;\n\
    \    }\n\n    private:\n    vector<int> data_;\n};\n"
  code: "#pragma once\n\n#include \"../Common.hpp\"\n\nclass UnionFind{\n    public:\n\
    \    UnionFind(size_t N) : data_(N, -1){}\n\n    int Find(const int k){\n    \
    \    if(data_[k] < 0) return k;\n        int r = Find(data_[k]);\n        return\
    \ data_[k] = r;\n    }\n\n    bool Same(const int x, const int y){\n        return\
    \ Find(x) == Find(y);\n    }\n\n    bool Unite(int x, int y){\n        x = Find(x),\
    \ y = Find(y);\n        if(x == y) return false;\n        if(data_[x] > data_[y])\
    \ swap(x, y);\n        data_[x] += data_[y];\n        data_[y] = x;\n        return\
    \ true;\n    }\n    \n    size_t Size(int k){\n        int v = Find(k);\n    \
    \    return -data_[v];\n    }\n\n    vector<vector<int>> Group(){\n        vector<vector<int>>\
    \ ret(data_.size());\n        for(int i = 0; i < data_.size(); ++i){\n       \
    \     ret[Find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](vector<int> &v){\n            return v.empty();\n        }), end(ret));\n\
    \        return ret;\n    }\n\n    private:\n    vector<int> data_;\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/UnionFind.hpp
  requiredBy:
  - Library/Graph/Kruskal.hpp
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/AOJ-DSL-1-A.test.cpp
  - verify/LC-Unionfind.test.cpp
  - verify/LC-MinimumSpanningTree.test.cpp
documentation_of: Library/DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/UnionFind.hpp
- /library/Library/DataStructure/UnionFind.hpp.html
title: Library/DataStructure/UnionFind.hpp
---
