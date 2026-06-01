---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':question:'
    path: Library/DataStructure/UnionFind.hpp
    title: Library/DataStructure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/LC-Unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 2 \"Library/DataStructure/UnionFind.hpp\"\n\n#line 2 \"Library/Common.hpp\"\
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
    \    }\n\n    private:\n    vector<int> data_;\n};\n#line 4 \"verify/LC-Unionfind.test.cpp\"\
    \n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n    int N, Q; cin >>\
    \ N >> Q;\n\n    UnionFind uf(N);\n    while(Q--){\n        int t, u, v; cin >>\
    \ t >> u >> v;\n        if(t == 0) uf.Unite(u, v);\n        else cout << uf.Same(u,\
    \ v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../Library/DataStructure/UnionFind.hpp\"\n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n\
    \    int N, Q; cin >> N >> Q;\n\n    UnionFind uf(N);\n    while(Q--){\n     \
    \   int t, u, v; cin >> t >> u >> v;\n        if(t == 0) uf.Unite(u, v);\n   \
    \     else cout << uf.Same(u, v) << '\\n';\n    }\n}"
  dependsOn:
  - Library/DataStructure/UnionFind.hpp
  - Library/Common.hpp
  isVerificationFile: true
  path: verify/LC-Unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/LC-Unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-Unionfind.test.cpp
- /verify/verify/LC-Unionfind.test.cpp.html
title: verify/LC-Unionfind.test.cpp
---
