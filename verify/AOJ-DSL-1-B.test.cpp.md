---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/WeightedUnionFind.hpp
    title: "Weighted UnionFind - \u91CD\u307F\u4ED8\u304D\u7D20\u96C6\u5408\u30C7\u30FC\
      \u30BF\u69CB\u9020"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
  bundledCode: "#line 1 \"verify/AOJ-DSL-1-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#line 2 \"library/DataStructure/WeightedUnionFind.hpp\"\n\n/**\n * @file WeightedUnionFind.hpp\n\
    \ * @author log K (lX57)\n * @brief Weighted UnionFind - \u91CD\u307F\u4ED8\u304D\
    \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\n * @version 1.0\n * @date 2024-04-26\n\
    \ */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T\
    \ = int>\nstruct WeightedUnionFind{\n    private:\n    vector<int> data_;\n  \
    \  vector<T> weight_;\n\n    T get_weight_(int k){\n        find(k);\n       \
    \ return weight_[k];\n    }\n\n    public:\n    /**\n     * @brief \u8981\u7D20\
    \u6570 `Size`, \u521D\u671F\u91CD\u307F `Init_Weight` \u3067WeightedUnionFind\u3092\
    \u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Size \u8981\u7D20\u6570\n\
    \     * @param Init_Weight \u91CD\u307F\u4ED8\u304DWeightedUnionFind\u306E\u521D\
    \u671F\u91CD\u307F (option, default = 0)\n     */\n    WeightedUnionFind(int Size,\
    \ T Init_Weight = 0) : data_(Size, -1), weight_(Size, Init_Weight) {}\n\n    /**\n\
    \     * @brief \u8981\u7D20 `k` \u306E\u89AA\u3092\u8FD4\u3059\u3002\u3064\u3044\
    \u3067\u306B\u7D4C\u8DEF\u5727\u7E2E\u3092\u3059\u308B\u3002\n     * @param k\
    \ \u63A2\u7D22\u3059\u308B\u8981\u7D20\n     * @return int \u89AA\u8981\u7D20\u306E\
    \u756A\u53F7\n     */\n    int find(int k){\n        if(data_[k] < 0) return k;\n\
    \        int r = find(data_[k]);\n        weight_[k] += weight_[data_[k]];\n \
    \       return data_[k] = r;\n    }\n\n    /**\n     * @brief \u8981\u7D20 `x`\
    \ \u3068\u8981\u7D20 `y` \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\
    \u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool same(int\
    \ x, int y){\n        return find(x) == find(y);\n    }\n\n    /**\n     * @brief\
    \ `Weight(y) - Weight(x)` \u3092\u8A08\u7B97\u3059\u308B\u3002\n     * @return\
    \ T `Weight(y) - Weight(x)` \u306E\u5024\n     */\n    T diff(int x, int y){\n\
    \        return get_weight_(y) - get_weight_(x);\n    }\n\n    /**\n     * @brief\
    \ \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u3092\u4F75\u5408\u3059\u308B\u3002\
    \u91CD\u307F\u3092\u4ED8\u4E0E\u3059\u308B\u3053\u3068\u3082\u3067\u304D\u308B\
    \u3002\n     * @param w `Weight(y) - Weight(x) = w` \u3068\u3044\u3046\u5236\u7D04\
    \u6761\u4EF6 (option, default = 0)\n     * @return \u4F75\u5408\u6E08\u306E\u5834\
    \u5408\u306F `false` \u3092\u8FD4\u3059\u3002\n     */\n    bool unite(int x,\
    \ int y, T w = 0){\n        w += get_weight_(x) - get_weight_(y);\n        x =\
    \ find(x), y = find(y);\n        if(x == y) return false;\n        if(data_[x]\
    \ > data_[y]) swap(x, y), w = -w;\n        data_[x] += data_[y];\n        data_[y]\
    \ = x;\n        weight_[y] = w;\n        return true;\n    }\n\n    vector<vector<int>>\
    \ group(){\n        vector<vector<int>> ret(data_.size());\n        for(int i\
    \ = 0; i < data_.size(); ++i){\n            ret[find(i)].emplace_back(i);\n  \
    \      }\n        ret.erase(remove_if(begin(ret), end(ret), [&](vector<int> &v){\n\
    \            return v.empty();\n        }), end(ret));\n        return ret;\n\
    \    }\n};\n#line 4 \"verify/AOJ-DSL-1-B.test.cpp\"\n\nint main(){\n    int n,\
    \ q; cin >> n >> q;\n\n    WeightedUnionFind<long long> uf(n);\n    while(q--){\n\
    \        int query; cin >> query;\n        if(query == 0){\n            int x,\
    \ y, z; cin >> x >> y >> z;\n            uf.unite(x, y, z);\n        }\n     \
    \   else{\n            int x, y; cin >> x >> y;\n            if(!uf.same(x, y))\
    \ cout << \"?\" << endl;\n            else cout << uf.diff(x, y) << endl;\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#include \"../library/DataStructure/WeightedUnionFind.hpp\"\n\nint main(){\n\
    \    int n, q; cin >> n >> q;\n\n    WeightedUnionFind<long long> uf(n);\n   \
    \ while(q--){\n        int query; cin >> query;\n        if(query == 0){\n   \
    \         int x, y, z; cin >> x >> y >> z;\n            uf.unite(x, y, z);\n \
    \       }\n        else{\n            int x, y; cin >> x >> y;\n            if(!uf.same(x,\
    \ y)) cout << \"?\" << endl;\n            else cout << uf.diff(x, y) << endl;\n\
    \        }\n    }\n}"
  dependsOn:
  - library/DataStructure/WeightedUnionFind.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-1-B.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 18:47:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-1-B.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-1-B.test.cpp
- /verify/verify/AOJ-DSL-1-B.test.cpp.html
title: verify/AOJ-DSL-1-B.test.cpp
---
