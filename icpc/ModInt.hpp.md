---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DPL-5-A.test.cpp
    title: verify_icpc/AOJ-DPL-5-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DPL-5-B.test.cpp
    title: verify_icpc/AOJ-DPL-5-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DPL-5-D.test.cpp
    title: verify_icpc/AOJ-DPL-5-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DPL-5-E.test.cpp
    title: verify_icpc/AOJ-DPL-5-E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\nusing pi = pair<int, int>;\n\
    #line 2 \"icpc/ModInt.hpp\"\n\nconst int mod998 = 998244353;\nconst int mod107\
    \ = 1000000007;\n\ntemplate< int mod >\nstruct ModInt {\n    int x;\n\n    ModInt()\
    \ : x(0) {}\n\n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)\
    \ % mod) {}\n\n    ModInt &operator+=(const ModInt &p) {\n        if((x += p.x)\
    \ >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator-=(const\
    \ ModInt &p) {\n        if((x += mod - p.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n\n    ModInt &operator*=(const ModInt &p) {\n        x = (int)\
    \ (1LL * x * p.x % mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const\
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
    \ get_mod() { return mod; }\n};\n\nusing m998 = ModInt< mod998 >;\nusing m107\
    \ = ModInt< mod107 >;\n\nusing vm998 = vector<m998>;\nusing vvm998 = vector<vector<m998>>;\n\
    using vm107 = vector<m107>;\nusing vvm107 = vector<vector<m107>>;\n"
  code: "#include \"Template.hpp\"\n\nconst int mod998 = 998244353;\nconst int mod107\
    \ = 1000000007;\n\ntemplate< int mod >\nstruct ModInt {\n    int x;\n\n    ModInt()\
    \ : x(0) {}\n\n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)\
    \ % mod) {}\n\n    ModInt &operator+=(const ModInt &p) {\n        if((x += p.x)\
    \ >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator-=(const\
    \ ModInt &p) {\n        if((x += mod - p.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n\n    ModInt &operator*=(const ModInt &p) {\n        x = (int)\
    \ (1LL * x * p.x % mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const\
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
    \ get_mod() { return mod; }\n};\n\nusing m998 = ModInt< mod998 >;\nusing m107\
    \ = ModInt< mod107 >;\n\nusing vm998 = vector<m998>;\nusing vvm998 = vector<vector<m998>>;\n\
    using vm107 = vector<m107>;\nusing vvm107 = vector<vector<m107>>;"
  dependsOn:
  - icpc/Template.hpp
  isVerificationFile: false
  path: icpc/ModInt.hpp
  requiredBy: []
  timestamp: '2023-11-24 19:51:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-DPL-5-B.test.cpp
  - verify_icpc/AOJ-DPL-5-A.test.cpp
  - verify_icpc/AOJ-DPL-5-E.test.cpp
  - verify_icpc/AOJ-DPL-5-D.test.cpp
documentation_of: icpc/ModInt.hpp
layout: document
redirect_from:
- /library/icpc/ModInt.hpp
- /library/icpc/ModInt.hpp.html
title: icpc/ModInt.hpp
---
