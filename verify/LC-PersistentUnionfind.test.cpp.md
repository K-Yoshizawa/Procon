---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/RollbackUnionFind.hpp
    title: "Rollback Union-Find - Rollback \u53EF\u80FD Union-Find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"verify/LC-PersistentUnionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr\
    \ const ll INF = (1LL << 62) - (1LL << 30) - 1;\n#line 2 \"Library/DataStructure/RollbackUnionFind.hpp\"\
    \n\nclass RollbackUnionFind{\n    public:\n    RollbackUnionFind(size_t n) : data_(n,\
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
    };\n#line 4 \"verify/LC-PersistentUnionfind.test.cpp\"\n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n\
    \    int N, Q; cin >> N >> Q;\n    using qs = tuple<int, int, int, int>;\n   \
    \ vector<vector<qs>> G(Q + 1);\n    for(int i = 1; i <= Q; ++i){\n        int\
    \ t, k, u, v; cin >> t >> k >> u >> v, ++k;\n        G[k].push_back({t, i, u,\
    \ v});\n    }\n\n    RollbackUnionFind uf(N);\n    vector<int> ans(Q + 1, -1);\n\
    \    auto dfs = [&](auto self, const qs &query) -> void {\n        auto [t, i,\
    \ u, v] = query;\n        if(t == 1){\n            ans[i] = uf.Same(u, v);\n \
    \       }\n        else{\n            if(t == 0) uf.Unite(u, v);\n           \
    \ for(auto nquery : G[i]) self(self, nquery);\n            if(t == 0) uf.Undo();\n\
    \        }\n    };\n    dfs(dfs, {-1, 0, 0, 0});\n    for(auto a : ans){\n   \
    \     if(a != -1) cout << a << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"../Library/DataStructure/RollbackUnionFind.hpp\"\n\nint main(){\n\
    \    cin.tie(0)->sync_with_stdio(false);\n    int N, Q; cin >> N >> Q;\n    using\
    \ qs = tuple<int, int, int, int>;\n    vector<vector<qs>> G(Q + 1);\n    for(int\
    \ i = 1; i <= Q; ++i){\n        int t, k, u, v; cin >> t >> k >> u >> v, ++k;\n\
    \        G[k].push_back({t, i, u, v});\n    }\n\n    RollbackUnionFind uf(N);\n\
    \    vector<int> ans(Q + 1, -1);\n    auto dfs = [&](auto self, const qs &query)\
    \ -> void {\n        auto [t, i, u, v] = query;\n        if(t == 1){\n       \
    \     ans[i] = uf.Same(u, v);\n        }\n        else{\n            if(t == 0)\
    \ uf.Unite(u, v);\n            for(auto nquery : G[i]) self(self, nquery);\n \
    \           if(t == 0) uf.Undo();\n        }\n    };\n    dfs(dfs, {-1, 0, 0,\
    \ 0});\n    for(auto a : ans){\n        if(a != -1) cout << a << '\\n';\n    }\n\
    }"
  dependsOn:
  - Library/DataStructure/RollbackUnionFind.hpp
  - Library/Common.hpp
  isVerificationFile: true
  path: verify/LC-PersistentUnionfind.test.cpp
  requiredBy: []
  timestamp: '2025-05-30 19:43:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-PersistentUnionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-PersistentUnionfind.test.cpp
- /verify/verify/LC-PersistentUnionfind.test.cpp.html
title: verify/LC-PersistentUnionfind.test.cpp
---
