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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/modint.hpp: line 9: #pragma once found in a non-first line\n"
  code: "/**\n * @file modint.hpp\n * @author log K (lX57)\n * @brief modint\n * @version\
    \ 1.0\n * @date 2023-08-24\n */\n\n#pragma once\n\nconst int mod998 = 998244353;\n\
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
    \ mod998 >;\nusing modint107 = ModInt< mod107 >;\n\nusing vm998 = vector< modint998\
    \ >;\nusing vvm998 = vector< vector< modint998 > >;\nusing vm107 = vector< modint107\
    \ >;\nusing vvm107 = vector< vector< modint107 > >;"
  dependsOn: []
  isVerificationFile: false
  path: library/modint.hpp
  requiredBy: []
  timestamp: '2023-08-24 13:17:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/modint.hpp
layout: document
redirect_from:
- /library/library/modint.hpp
- /library/library/modint.hpp.html
title: modint
---
