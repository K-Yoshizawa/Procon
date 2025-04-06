---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/WeightedUnionFind.hpp
    title: "Weighted Union-Find - \u91CD\u307F\u4ED8\u304D\u7D20\u96C6\u5408\u30C7\
      \u30FC\u30BF\u69CB\u9020"
  - icon: ':heavy_check_mark:'
    path: Library/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential
  bundledCode: "#line 1 \"verify/LC-UnionfindWithPotential.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\n\n#line 2 \"Library/modint.hpp\"\
    \n\n/**\n * @file modint.hpp\n * @author log K (lX57)\n * @brief modint\n * @version\
    \ 1.0\n * @date 2023-08-24\n */\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file\
    \ Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cstdint>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const ll INF = (1LL\
    \ << 62) - (1LL << 30) - 1;\n#line 12 \"Library/modint.hpp\"\nusing namespace\
    \ std;\n\nconst int mod998 = 998244353;\nconst int mod107 = 1000000007;\n\ntemplate<\
    \ int mod >\nstruct ModInt {\n    int x;\n\n    ModInt() : x(0) {}\n\n    ModInt(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n    ModInt &operator+=(const\
    \ ModInt &p) {\n        if((x += p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n\n    ModInt &operator-=(const ModInt &p) {\n        if((x += mod - p.x)\
    \ >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (int) (1LL * x * p.x % mod);\n        return *this;\n\
    \    }\n\n    ModInt &operator/=(const ModInt &p) {\n        *this *= p.inverse();\n\
    \        return *this;\n    }\n\n    ModInt operator-() const { return ModInt(-x);\
    \ }\n\n    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p;\
    \ }\n\n    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p;\
    \ }\n\n    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p;\
    \ }\n\n    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p;\
    \ }\n\n    bool operator==(const ModInt &p) const { return x == p.x; }\n\n   \
    \ bool operator!=(const ModInt &p) const { return x != p.x; }\n\n    ModInt inverse()\
    \ const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while(b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return ModInt(u);\n    }\n\n    ModInt pow(int64_t\
    \ n) const {\n        if(n == 0) return ModInt(1);\n        ModInt ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, const ModInt &p) {\n        return os << p.x;\n\
    \    }\n\n    friend istream &operator>>(istream &is, ModInt &a) {\n        int64_t\
    \ t;\n        is >> t;\n        a = ModInt< mod >(t);\n        return (is);\n\
    \    }\n\n    static int get_mod() { return mod; }\n};\n\nusing mint = ModInt<mod998>;\n\
    using mint107 = ModInt<mod107>;\n\nusing vm = vector<mint>;\nusing vvm = vector<vector<mint>>;\n\
    using vm107 = vector<mint107>;\nusing vvm107 = vector<vector<mint107>>;\n#line\
    \ 2 \"Library/DataStructure/WeightedUnionFind.hpp\"\n\ntemplate<typename Abel\
    \ = int32_t>\nclass WeightedUnionFind{\n    public:\n    WeightedUnionFind(int\
    \ n) : data_(n, -1), weight_(n, Abel{}){}\n\n    int Find(const int k){\n    \
    \    if(data_[k] < 0) return k;\n        int r = Find(data_[k]);\n        weight_[k]\
    \ += weight_[data_[k]];\n        return data_[k] = r;\n    }\n\n    Abel Weight(const\
    \ int k){\n        Find(k);\n        return weight_[k];\n    }\n\n    Abel Diff(const\
    \ int x, const int y){\n        return Weight(y) - Weight(x);\n    }\n\n    bool\
    \ Same(const int x, const int y){\n        return Find(x) == Find(y);\n    }\n\
    \n    bool Unite(int x, int y, Abel w){\n        w += Weight(x) - Weight(y);\n\
    \        x = Find(x), y = Find(y);\n        if(x == y) return false;\n       \
    \ if(data_[x] > data_[y]) swap(x, y), w = -w;\n        data_[x] += data_[y];\n\
    \        data_[y] = x;\n        weight_[y] = w;\n        return true;\n    }\n\
    \n    private:\n    vector<int> data_;\n    vector<Abel> weight_;\n};\n#line 5\
    \ \"verify/LC-UnionfindWithPotential.test.cpp\"\n\nint main(){\n    int N, Q;\
    \ cin >> N >> Q;\n\n    WeightedUnionFind<mint> uf(N);\n    while(Q--){\n    \
    \    int t, u, v; cin >> t >> u >> v;\n        if(t == 0){\n            int x;\
    \ cin >> x;\n            if(uf.Same(u, v)){\n                cout << (uf.Diff(u,\
    \ v) == x) << endl;\n            }\n            else{\n                cout <<\
    \ uf.Unite(u, v, x) << endl;\n            }\n        }\n        else{\n      \
    \      if(uf.Same(u, v)){\n                cout << uf.Diff(u, v) << endl;\n  \
    \          }\n            else{\n                cout << -1 << endl;\n       \
    \     }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include \"../Library/modint.hpp\"\n#include \"../Library/DataStructure/WeightedUnionFind.hpp\"\
    \n\nint main(){\n    int N, Q; cin >> N >> Q;\n\n    WeightedUnionFind<mint> uf(N);\n\
    \    while(Q--){\n        int t, u, v; cin >> t >> u >> v;\n        if(t == 0){\n\
    \            int x; cin >> x;\n            if(uf.Same(u, v)){\n              \
    \  cout << (uf.Diff(u, v) == x) << endl;\n            }\n            else{\n \
    \               cout << uf.Unite(u, v, x) << endl;\n            }\n        }\n\
    \        else{\n            if(uf.Same(u, v)){\n                cout << uf.Diff(u,\
    \ v) << endl;\n            }\n            else{\n                cout << -1 <<\
    \ endl;\n            }\n        }\n    }\n}"
  dependsOn:
  - Library/modint.hpp
  - Library/Common.hpp
  - Library/DataStructure/WeightedUnionFind.hpp
  isVerificationFile: true
  path: verify/LC-UnionfindWithPotential.test.cpp
  requiredBy: []
  timestamp: '2025-03-20 00:50:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-UnionfindWithPotential.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-UnionfindWithPotential.test.cpp
- /verify/verify/LC-UnionfindWithPotential.test.cpp.html
title: verify/LC-UnionfindWithPotential.test.cpp
---
