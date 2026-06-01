---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-0723.test.cpp
    title: verify/AOJ-0723.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-PersistentUnionfind.test.cpp
    title: verify/LC-PersistentUnionfind.test.cpp
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
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 2 \"Library/DataStructure/RollbackUnionFind.hpp\"\
    \n\nclass RollbackUnionFind{\n    public:\n    RollbackUnionFind(size_t N) : data_(N,\
    \ -1), record_(0){}\n\n    int Find(const int k) const {\n        if(data_[k]\
    \ < 0) return k;\n        return Find(data_[k]);\n    }\n\n    bool Same(const\
    \ int x, const int y) const {\n        return Find(x) == Find(y);\n    }\n\n \
    \   bool Unite(int x, int y){\n        x = Find(x), y = Find(y);\n        history_.push({x,\
    \ data_[x]});\n        history_.push({y, data_[y]});\n        if(x == y) return\
    \ false;\n        if(data_[x] > data_[y]) swap(x, y);\n        data_[x] += data_[y];\n\
    \        data_[y] = x;\n        return true;\n    }\n    \n    int Size(const\
    \ int k) const {\n        return -data_[Find(k)];\n    }\n    \n    vector<vector<int>>\
    \ Group() const {\n        vector<vector<int>> ret(data_.size());\n        for(int\
    \ i = 0; i < data_.size(); ++i){\n            ret[Find(i)].emplace_back(i);\n\
    \        }\n        ret.erase(remove_if(begin(ret), end(ret), [&](vector<int>\
    \ &v){\n            return v.empty();\n        }), end(ret));\n        return\
    \ ret;\n    }\n\n    void Record(){\n        record_ = history_.size();\n    }\n\
    \n    void Undo(){\n        auto [y, dy] = history_.top();\n        history_.pop();\n\
    \        data_[y] = dy;\n        auto [x, dx] = history_.top();\n        history_.pop();\n\
    \        data_[x] = dx;\n    }\n\n    void Rollback(){\n        int state = record_;\n\
    \        while(state < (int)history_.size()) Undo();\n    }\n    \n    private:\n\
    \    vector<int> data_;\n    stack<pair<int, int>> history_;\n    int record_;\n\
    };\n"
  code: "#include \"../Common.hpp\"\n\nclass RollbackUnionFind{\n    public:\n   \
    \ RollbackUnionFind(size_t N) : data_(N, -1), record_(0){}\n\n    int Find(const\
    \ int k) const {\n        if(data_[k] < 0) return k;\n        return Find(data_[k]);\n\
    \    }\n\n    bool Same(const int x, const int y) const {\n        return Find(x)\
    \ == Find(y);\n    }\n\n    bool Unite(int x, int y){\n        x = Find(x), y\
    \ = Find(y);\n        history_.push({x, data_[x]});\n        history_.push({y,\
    \ data_[y]});\n        if(x == y) return false;\n        if(data_[x] > data_[y])\
    \ swap(x, y);\n        data_[x] += data_[y];\n        data_[y] = x;\n        return\
    \ true;\n    }\n    \n    int Size(const int k) const {\n        return -data_[Find(k)];\n\
    \    }\n    \n    vector<vector<int>> Group() const {\n        vector<vector<int>>\
    \ ret(data_.size());\n        for(int i = 0; i < data_.size(); ++i){\n       \
    \     ret[Find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](vector<int> &v){\n            return v.empty();\n        }), end(ret));\n\
    \        return ret;\n    }\n\n    void Record(){\n        record_ = history_.size();\n\
    \    }\n\n    void Undo(){\n        auto [y, dy] = history_.top();\n        history_.pop();\n\
    \        data_[y] = dy;\n        auto [x, dx] = history_.top();\n        history_.pop();\n\
    \        data_[x] = dx;\n    }\n\n    void Rollback(){\n        int state = record_;\n\
    \        while(state < (int)history_.size()) Undo();\n    }\n    \n    private:\n\
    \    vector<int> data_;\n    stack<pair<int, int>> history_;\n    int record_;\n\
    };"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/RollbackUnionFind.hpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-0723.test.cpp
  - verify/LC-PersistentUnionfind.test.cpp
documentation_of: Library/DataStructure/RollbackUnionFind.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/RollbackUnionFind.hpp
- /library/Library/DataStructure/RollbackUnionFind.hpp.html
title: Library/DataStructure/RollbackUnionFind.hpp
---
