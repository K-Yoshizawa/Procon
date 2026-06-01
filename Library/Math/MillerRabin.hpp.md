---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Montgomery.hpp
    title: Library/Math/Montgomery.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-PrimalityTest.test.cpp
    title: verify/LC-PrimalityTest.test.cpp
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
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 2 \"Library/Math/Montgomery.hpp\"\
    \n\nstruct Montgomery{\n    using mont = Montgomery;\n    using u64 = uint64_t;\n\
    \    using u128 = __uint128_t;\n\n    static void SetMod(const u64 m){\n     \
    \   assert(m < (1LL << 62));\n        assert(m & 1);\n        mod = m;\n     \
    \   inv_mod = m;\n        for(int i = 0; i < 5; ++i){\n            inv_mod *=\
    \ 2 - m * inv_mod;\n        }\n        r2 = -u128(m) % m;\n    }\n\n    u64 val;\n\
    \n    Montgomery() : val(0){}\n\n    Montgomery(long long x) : val(Reduct((u128(x)\
    \ + mod) * r2)){}\n\n    inline u64 Get() const {\n        u64 res = Reduct(val);\n\
    \        return res >= mod ? res - mod : res;\n    }\n\n    mont &operator+=(const\
    \ mont &r){\n        if((val += r.val) >= 2 * mod) val -= 2 * mod;\n        return\
    \ (*this);\n    }\n\n    mont &operator-=(const mont &r){\n        if((val +=\
    \ 2 * mod - r.val) >= 2 * mod) val -= 2 * mod;\n        return (*this);\n    }\n\
    \n    mont &operator*=(const mont &r){\n        val = Reduct(u128(val) * r.val);\n\
    \        return (*this);\n    }\n\n    mont &operator/=(const mont &r){\n    \
    \    (*this) *= r.Inverse();\n        return (*this);\n    }\n\n    mont Inverse()\
    \ const {\n        return Power(mod - 2);\n    }\n\n    mont Power(long long k)\
    \ const {\n        mont ret(1), mul(*this);\n        while(k){\n            if(k\
    \ & 1) ret *= mul;\n            mul *= mul;\n            k >>= 1;\n        }\n\
    \        return ret;\n    }\n\n    mont operator-() const {\n        return mont()\
    \ - mont(*this);\n    }\n\n    mont operator+(const mont &r) const {\n       \
    \ return mont(*this) += r;\n    }\n\n    mont operator-(const mont &r) const {\n\
    \        return mont(*this) -= r;\n    }\n\n    mont operator*(const mont &r)\
    \ const {\n        return mont(*this) *= r;\n    }\n\n    bool operator==(const\
    \ mont &r) const {\n        return (val >= mod ? val - mod : val) == (r.val >=\
    \ mod ? r.val - mod : r.val);\n    }\n\n    bool operator!=(const mont &r) const\
    \ {\n        return (val >= mod ? val - mod : val) != (r.val >= mod ? r.val -\
    \ mod : r.val);\n    }\n\n    private:\n    static u64 mod;\n    static u64 inv_mod;\n\
    \    static u64 r2;\n\n    static u64 Reduct(const u128 x){\n        return (x\
    \ + u128(u64(x) * u64(-inv_mod)) * mod) >> 64;\n    }\n};\n\ntypename Montgomery::u64\
    \ Montgomery::mod, Montgomery::inv_mod, Montgomery::r2;\n#line 2 \"Library/Math/MillerRabin.hpp\"\
    \n\nbool MillerRabin(const long long N){\n    if(N <= 1) return false;\n    if(N\
    \ == 2) return true;\n    if(!(N & 1)) return false;\n    vector<long long> as;\n\
    \    if(N < 4759123141LL) as = {2, 7, 61};\n    else as = {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022};\n    Montgomery::SetMod(N);\n    long long s =\
    \ 0, d = N - 1;\n    while(!(d & 1)) ++s, d >>= 1;\n    for(const auto &a : as){\n\
    \        Montgomery x = Montgomery(a).Power(d);\n        if(x != 1 && x != 0){\n\
    \            long long t;\n            for(t = 0; t < s; ++t){\n             \
    \   if(x == N - 1) break;\n                x *= x;\n            }\n          \
    \  if(t == s) return false;\n        }\n    }\n    return true;\n}\n"
  code: "#include \"Montgomery.hpp\"\n\nbool MillerRabin(const long long N){\n   \
    \ if(N <= 1) return false;\n    if(N == 2) return true;\n    if(!(N & 1)) return\
    \ false;\n    vector<long long> as;\n    if(N < 4759123141LL) as = {2, 7, 61};\n\
    \    else as = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n    Montgomery::SetMod(N);\n\
    \    long long s = 0, d = N - 1;\n    while(!(d & 1)) ++s, d >>= 1;\n    for(const\
    \ auto &a : as){\n        Montgomery x = Montgomery(a).Power(d);\n        if(x\
    \ != 1 && x != 0){\n            long long t;\n            for(t = 0; t < s; ++t){\n\
    \                if(x == N - 1) break;\n                x *= x;\n            }\n\
    \            if(t == s) return false;\n        }\n    }\n    return true;\n}"
  dependsOn:
  - Library/Math/Montgomery.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Math/MillerRabin.hpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-PrimalityTest.test.cpp
documentation_of: Library/Math/MillerRabin.hpp
layout: document
redirect_from:
- /library/Library/Math/MillerRabin.hpp
- /library/Library/Math/MillerRabin.hpp.html
title: Library/Math/MillerRabin.hpp
---
