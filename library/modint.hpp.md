---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: modint
    links: []
  bundledCode: "#line 2 \"library/modint.hpp\"\n\n/**\n * @brief modint\n */\n\nconst\
    \ int mod998 = 998244353;\nconst int mod107 = 1000000007;\n\ntemplate< int mod\
    \ >\nstruct ModInt {\n    int x;\n\n    ModInt() : x(0) {}\n\n    ModInt(int64_t\
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
    \    }\n\n    static int get_mod() { return mod; }\n};\n\nusing modint998 = ModInt<\
    \ mod998 >;\nusing modint107 = ModInt< mod107 >;\n"
  code: "#pragma once\n\n/**\n * @brief modint\n */\n\nconst int mod998 = 998244353;\n\
    const int mod107 = 1000000007;\n\ntemplate< int mod >\nstruct ModInt {\n    int\
    \ x;\n\n    ModInt() : x(0) {}\n\n    ModInt(int64_t y) : x(y >= 0 ? y % mod :\
    \ (mod - (-y) % mod) % mod) {}\n\n    ModInt &operator+=(const ModInt &p) {\n\
    \        if((x += p.x) >= mod) x -= mod;\n        return *this;\n    }\n\n   \
    \ ModInt &operator-=(const ModInt &p) {\n        if((x += mod - p.x) >= mod) x\
    \ -= mod;\n        return *this;\n    }\n\n    ModInt &operator*=(const ModInt\
    \ &p) {\n        x = (int) (1LL * x * p.x % mod);\n        return *this;\n   \
    \ }\n\n    ModInt &operator/=(const ModInt &p) {\n        *this *= p.inverse();\n\
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
    \    }\n\n    static int get_mod() { return mod; }\n};\n\nusing modint998 = ModInt<\
    \ mod998 >;\nusing modint107 = ModInt< mod107 >;"
  dependsOn: []
  isVerificationFile: false
  path: library/modint.hpp
  requiredBy: []
  timestamp: '2023-06-26 10:02:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/modint.hpp
layout: document
redirect_from:
- /library/library/modint.hpp
- /library/library/modint.hpp.html
title: modint
---
