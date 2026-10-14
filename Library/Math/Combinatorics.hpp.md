---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':x:'
    path: Library/Math/FactorialTable.hpp
    title: Library/Math/FactorialTable.hpp
  - icon: ':x:'
    path: Library/Math/ModInt.hpp
    title: Library/Math/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/Math/AOJ-DPL-5-B.test.cpp
    title: verify/Math/AOJ-DPL-5-B.test.cpp
  - icon: ':x:'
    path: verify/Math/AOJ-DPL-5-D.test.cpp
    title: verify/Math/AOJ-DPL-5-D.test.cpp
  - icon: ':x:'
    path: verify/Math/AOJ-DPL-5-E.test.cpp
    title: verify/Math/AOJ-DPL-5-E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Math/Combinatorics.hpp\"\n\n#line 2 \"Library/Common.hpp\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n\
    #include <cassert>\n#include <cmath>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const\
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 2 \"Library/Math/FactorialTable.hpp\"\
    \n\n#line 2 \"Library/Math/ModInt.hpp\"\n\n#line 4 \"Library/Math/ModInt.hpp\"\
    \n\ntemplate< int mod >\nstruct ModInt {\n    int x;\n\n    ModInt() : x(0) {}\n\
    \n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n\
    \    ModInt &operator+=(const ModInt &p) {\n        if((x += p.x) >= mod) x -=\
    \ mod;\n        return *this;\n    }\n\n    ModInt &operator-=(const ModInt &p)\
    \ {\n        if((x += mod - p.x) >= mod) x -= mod;\n        return *this;\n  \
    \  }\n\n    ModInt &operator*=(const ModInt &p) {\n        x = (int) (1LL * x\
    \ * p.x % mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.Inverse();\n        return *this;\n    }\n\n\
    \    ModInt operator-() const { return ModInt(-x); }\n\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n\n    bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n\n    bool operator!=(const ModInt &p)\
    \ const { return x != p.x; }\n\n    ModInt Inverse() const {\n        int a =\
    \ x, b = mod, u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n\
    \            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n\
    \        return ModInt(u);\n    }\n\n    ModInt Power(int64_t n) const {\n   \
    \     if(n == 0) return ModInt(1);\n        ModInt ret(1), mul(x);\n        while(n\
    \ > 0) {\n            if(n & 1) ret *= mul;\n            mul *= mul;\n       \
    \     n >>= 1;\n        }\n        return ret;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, ModInt &a) {\n        int64_t t;\n        is >> t;\n\
    \        a = ModInt< mod >(t);\n        return (is);\n    }\n\n    static int\
    \ get_mod() { return mod; }\n};\n\nconst int MOD998244353 = 998244353;\nconst\
    \ int MOD1000000007 = 1000000007;\nusing mint = ModInt<MOD998244353>;\nusing mmint\
    \ = ModInt<MOD1000000007>;\n#line 5 \"Library/Math/FactorialTable.hpp\"\n\ntemplate<typename\
    \ T = mint>\nclass FactorialTable{\n    public:\n    FactorialTable(int N) : fact_(N\
    \ + 1), ifact_(N + 1), inv_(N + 1){\n        fact_[0] = ifact_[N] = inv_[0] =\
    \ 1;\n        for(int i = 1; i <= N; ++i) fact_[i] = fact_[i - 1] * i;\n     \
    \   ifact_[N] /= fact_[N];\n        for(int i = N - 1; i >= 0; --i) ifact_[i]\
    \ = ifact_[i + 1] * (i + 1);\n        for(int i = 1; i <= N; ++i) inv_[i] = ifact_[i]\
    \ * fact_[i - 1];\n    }\n\n    inline T Factorial(int x) const {\n        return\
    \ fact_.at(x);\n    }\n\n    inline T InverseFactorial(int x) const {\n      \
    \  return ifact_.at(x);\n    }\n\n    inline T Inverse(int x) const {\n      \
    \  return inv_.at(x);\n    }\n\n    private:\n    vector<T> fact_, ifact_, inv_;\n\
    };\n#line 5 \"Library/Math/Combinatorics.hpp\"\n\ntemplate<typename T = mint>\n\
    class Combinatorics{\n    public:\n    Combinatorics(int N = 500010) : ft_(N){}\n\
    \n    inline T Permutation(int n, int r) const {\n        if(r < 0 or n < r) return\
    \ 0;\n        return ft_.Factorial(n) * ft_.InverseFactorial(n - r);\n    }\n\n\
    \    inline T Combination(int n, int r) const {\n        if(r < 0 or n < r) return\
    \ 0;\n        return ft_.Factorial(n) * ft_.InverseFactorial(r) * ft_.InverseFactorial(n\
    \ - r);\n    }\n\n    inline T Homogeneous(int n, int r) const {\n        if(n\
    \ < 0 or r < 0) return 0;\n        return r == 0 ? 1 : Combination(n + r - 1,\
    \ r);\n    }\n\n    private:\n    FactorialTable<T> ft_;\n};\n"
  code: "#pragma once\n\n#include \"../Common.hpp\"\n#include \"FactorialTable.hpp\"\
    \n\ntemplate<typename T = mint>\nclass Combinatorics{\n    public:\n    Combinatorics(int\
    \ N = 500010) : ft_(N){}\n\n    inline T Permutation(int n, int r) const {\n \
    \       if(r < 0 or n < r) return 0;\n        return ft_.Factorial(n) * ft_.InverseFactorial(n\
    \ - r);\n    }\n\n    inline T Combination(int n, int r) const {\n        if(r\
    \ < 0 or n < r) return 0;\n        return ft_.Factorial(n) * ft_.InverseFactorial(r)\
    \ * ft_.InverseFactorial(n - r);\n    }\n\n    inline T Homogeneous(int n, int\
    \ r) const {\n        if(n < 0 or r < 0) return 0;\n        return r == 0 ? 1\
    \ : Combination(n + r - 1, r);\n    }\n\n    private:\n    FactorialTable<T> ft_;\n\
    };"
  dependsOn:
  - Library/Common.hpp
  - Library/Math/FactorialTable.hpp
  - Library/Math/ModInt.hpp
  isVerificationFile: false
  path: Library/Math/Combinatorics.hpp
  requiredBy: []
  timestamp: '2026-06-21 14:35:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/Math/AOJ-DPL-5-D.test.cpp
  - verify/Math/AOJ-DPL-5-E.test.cpp
  - verify/Math/AOJ-DPL-5-B.test.cpp
documentation_of: Library/Math/Combinatorics.hpp
layout: document
redirect_from:
- /library/Library/Math/Combinatorics.hpp
- /library/Library/Math/Combinatorics.hpp.html
title: Library/Math/Combinatorics.hpp
---
