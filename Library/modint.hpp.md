---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-PointSetRangeComposite.test.cpp
    title: verify/LC-PointSetRangeComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-RangeAffinePointGet.test.cpp
    title: verify/LC-RangeAffinePointGet.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-RangeAffineRangeSum.test.cpp
    title: verify/LC-RangeAffineRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-TreePathCompositeSum.test.cpp
    title: verify/LC-TreePathCompositeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-UnionfindWithPotential.test.cpp
    title: verify/LC-UnionfindWithPotential.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-VertexSetPathComposite.test.cpp
    title: verify/LC-VertexSetPathComposite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: modint
    links: []
  bundledCode: "#line 2 \"Library/modint.hpp\"\n\n/**\n * @file modint.hpp\n * @author\
    \ log K (lX57)\n * @brief modint\n * @version 1.0\n * @date 2023-08-24\n */\n\n\
    #line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cstdint>\n\
    #include <deque>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\nusing namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\
    \nconstexpr const ll INF = (1LL << 62) - (1LL << 30) - 1;\n#line 12 \"Library/modint.hpp\"\
    \nusing namespace std;\n\nconst int mod998 = 998244353;\nconst int mod107 = 1000000007;\n\
    \ntemplate< int mod >\nstruct ModInt {\n    int x;\n\n    ModInt() : x(0) {}\n\
    \n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n\
    \    ModInt &operator+=(const ModInt &p) {\n        if((x += p.x) >= mod) x -=\
    \ mod;\n        return *this;\n    }\n\n    ModInt &operator-=(const ModInt &p)\
    \ {\n        if((x += mod - p.x) >= mod) x -= mod;\n        return *this;\n  \
    \  }\n\n    ModInt &operator*=(const ModInt &p) {\n        x = (int) (1LL * x\
    \ * p.x % mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n\n\
    \    ModInt operator-() const { return ModInt(-x); }\n\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n\n    bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n\n    bool operator!=(const ModInt &p)\
    \ const { return x != p.x; }\n\n    ModInt inverse() const {\n        int a =\
    \ x, b = mod, u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n\
    \            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n\
    \        return ModInt(u);\n    }\n\n    ModInt pow(int64_t n) const {\n     \
    \   if(n == 0) return ModInt(1);\n        ModInt ret(1), mul(x);\n        while(n\
    \ > 0) {\n            if(n & 1) ret *= mul;\n            mul *= mul;\n       \
    \     n >>= 1;\n        }\n        return ret;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, ModInt &a) {\n        int64_t t;\n        is >> t;\n\
    \        a = ModInt< mod >(t);\n        return (is);\n    }\n\n    static int\
    \ get_mod() { return mod; }\n};\n\nusing mint = ModInt<mod998>;\nusing mint107\
    \ = ModInt<mod107>;\n\nusing vm = vector<mint>;\nusing vvm = vector<vector<mint>>;\n\
    using vm107 = vector<mint107>;\nusing vvm107 = vector<vector<mint107>>;\n"
  code: "#pragma once\n\n/**\n * @file modint.hpp\n * @author log K (lX57)\n * @brief\
    \ modint\n * @version 1.0\n * @date 2023-08-24\n */\n\n#include \"Common.hpp\"\
    \nusing namespace std;\n\nconst int mod998 = 998244353;\nconst int mod107 = 1000000007;\n\
    \ntemplate< int mod >\nstruct ModInt {\n    int x;\n\n    ModInt() : x(0) {}\n\
    \n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n\
    \    ModInt &operator+=(const ModInt &p) {\n        if((x += p.x) >= mod) x -=\
    \ mod;\n        return *this;\n    }\n\n    ModInt &operator-=(const ModInt &p)\
    \ {\n        if((x += mod - p.x) >= mod) x -= mod;\n        return *this;\n  \
    \  }\n\n    ModInt &operator*=(const ModInt &p) {\n        x = (int) (1LL * x\
    \ * p.x % mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n\n\
    \    ModInt operator-() const { return ModInt(-x); }\n\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n\n    bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n\n    bool operator!=(const ModInt &p)\
    \ const { return x != p.x; }\n\n    ModInt inverse() const {\n        int a =\
    \ x, b = mod, u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n\
    \            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n\
    \        return ModInt(u);\n    }\n\n    ModInt pow(int64_t n) const {\n     \
    \   if(n == 0) return ModInt(1);\n        ModInt ret(1), mul(x);\n        while(n\
    \ > 0) {\n            if(n & 1) ret *= mul;\n            mul *= mul;\n       \
    \     n >>= 1;\n        }\n        return ret;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, ModInt &a) {\n        int64_t t;\n        is >> t;\n\
    \        a = ModInt< mod >(t);\n        return (is);\n    }\n\n    static int\
    \ get_mod() { return mod; }\n};\n\nusing mint = ModInt<mod998>;\nusing mint107\
    \ = ModInt<mod107>;\n\nusing vm = vector<mint>;\nusing vvm = vector<vector<mint>>;\n\
    using vm107 = vector<mint107>;\nusing vvm107 = vector<vector<mint107>>;"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/modint.hpp
  requiredBy: []
  timestamp: '2025-03-20 00:50:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-RangeAffineRangeSum.test.cpp
  - verify/LC-UnionfindWithPotential.test.cpp
  - verify/LC-RangeAffinePointGet.test.cpp
  - verify/LC-TreePathCompositeSum.test.cpp
  - verify/LC-PointSetRangeComposite.test.cpp
  - verify/LC-VertexSetPathComposite.test.cpp
documentation_of: Library/modint.hpp
layout: document
redirect_from:
- /library/Library/modint.hpp
- /library/Library/modint.hpp.html
title: modint
---
