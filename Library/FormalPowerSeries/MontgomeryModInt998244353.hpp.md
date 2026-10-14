---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/FormalPowerSeries/Convolution.hpp
    title: Library/FormalPowerSeries/Convolution.hpp
  - icon: ':heavy_check_mark:'
    path: Library/FormalPowerSeries/FormalPowerSeries.hpp
    title: Library/FormalPowerSeries/FormalPowerSeries.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/FormalPowerSeries/LC-ConvolutionMod.test.cpp
    title: verify/FormalPowerSeries/LC-ConvolutionMod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/FormalPowerSeries/LC-ExpFormalPowerSeries.test.cpp
    title: verify/FormalPowerSeries/LC-ExpFormalPowerSeries.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/FormalPowerSeries/LC-InvFormalPowerSeries.test.cpp
    title: verify/FormalPowerSeries/LC-InvFormalPowerSeries.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/FormalPowerSeries/LC-LogFormalPowerSeries.test.cpp
    title: verify/FormalPowerSeries/LC-LogFormalPowerSeries.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/FormalPowerSeries/MontgomeryModInt998244353.hpp\"\
    \n\n#line 2 \"Library/Common.hpp\"\n\n#include <algorithm>\n#include <array>\n\
    #include <bit>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 4 \"Library/FormalPowerSeries/MontgomeryModInt998244353.hpp\"\n\n\
    class MontgomeryModInt998244353{\n    using i32 = int32_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n    public:\n    using ModInt = MontgomeryModInt998244353;\n\
    \n    constexpr MontgomeryModInt998244353() : x(0){}\n\n    constexpr MontgomeryModInt998244353(int64_t\
    \ y) : x(MontgomeryReduction(u64(y) * R2)){}\n\n    constexpr ModInt &operator+=(const\
    \ ModInt &r){\n        if(i32(x += r.x - 2 * MOD) < 0) x += 2 * MOD;\n       \
    \ return (*this);\n    }\n\n    constexpr ModInt &operator-=(const ModInt &r){\n\
    \        if(i32(x -= r.x) < 0) x += 2 * MOD;\n        return (*this);\n    }\n\
    \n    constexpr ModInt &operator*=(const ModInt &r){\n        x = MontgomeryReduction(u64(x)\
    \ * r.x);\n        return (*this);\n    }\n\n    constexpr ModInt &operator/=(const\
    \ ModInt &r){\n        (*this) *= r.Inverse();\n        return (*this);\n    }\n\
    \n    constexpr ModInt operator+(const ModInt &r) const {return ModInt(*this)\
    \ += r;}\n    constexpr ModInt operator-(const ModInt &r) const {return ModInt(*this)\
    \ -= r;}\n    constexpr ModInt operator/(const ModInt &r) const {return ModInt(*this)\
    \ /= r;}\n    constexpr ModInt operator*(const ModInt &r) const {return ModInt(*this)\
    \ *= r;}\n\n    constexpr bool operator==(const ModInt &r) const {return Value()\
    \ == r.Value();}\n    constexpr bool operator!=(const ModInt &r) const {return\
    \ Value() != r.Value();}\n    \n    constexpr ModInt operator+() const {return\
    \ ModInt(*this);}\n    constexpr ModInt operator-() const {return ModInt() - ModInt(*this);}\n\
    \n    constexpr ModInt Power(int64_t k) const {\n        ModInt ret(1), mul(*this);\n\
    \        while(k){\n            if(k & 1) ret *= mul;\n            mul *= mul;\n\
    \            k >>= 1;\n        }\n        return ret;\n    }\n\n    constexpr\
    \ ModInt Inverse() const {\n        return Power(MOD - 2);\n    }\n\n    constexpr\
    \ uint32_t Value() const {\n        uint32_t ret = MontgomeryReduction(x);\n \
    \       return ret >= MOD ? ret - MOD : ret;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &r){\n        return os << r.Value();\n    }\n\n    friend\
    \ istream &operator>>(istream &is, ModInt &r){\n        int64_t y; is >> y;\n\
    \        r = MontgomeryModInt998244353(y);\n        return is;\n    }\n\n    private:\n\
    \    static constexpr u32 MontgomeryReduction(const u64 &T){\n        return (T\
    \ + u64(u32(T) * INV) * MOD) >> 32;\n    }\n\n    u32 x;\n\n    static constexpr\
    \ u32 MOD = 998244353;\n    static constexpr u32 INV = 998244351;\n    static\
    \ constexpr u32 R2 = 932051910;\n};\n\nusing mint = MontgomeryModInt998244353;\n"
  code: "#pragma once\n\n#include \"../Common.hpp\"\n\nclass MontgomeryModInt998244353{\n\
    \    using i32 = int32_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \    public:\n    using ModInt = MontgomeryModInt998244353;\n\n    constexpr MontgomeryModInt998244353()\
    \ : x(0){}\n\n    constexpr MontgomeryModInt998244353(int64_t y) : x(MontgomeryReduction(u64(y)\
    \ * R2)){}\n\n    constexpr ModInt &operator+=(const ModInt &r){\n        if(i32(x\
    \ += r.x - 2 * MOD) < 0) x += 2 * MOD;\n        return (*this);\n    }\n\n   \
    \ constexpr ModInt &operator-=(const ModInt &r){\n        if(i32(x -= r.x) < 0)\
    \ x += 2 * MOD;\n        return (*this);\n    }\n\n    constexpr ModInt &operator*=(const\
    \ ModInt &r){\n        x = MontgomeryReduction(u64(x) * r.x);\n        return\
    \ (*this);\n    }\n\n    constexpr ModInt &operator/=(const ModInt &r){\n    \
    \    (*this) *= r.Inverse();\n        return (*this);\n    }\n\n    constexpr\
    \ ModInt operator+(const ModInt &r) const {return ModInt(*this) += r;}\n    constexpr\
    \ ModInt operator-(const ModInt &r) const {return ModInt(*this) -= r;}\n    constexpr\
    \ ModInt operator/(const ModInt &r) const {return ModInt(*this) /= r;}\n    constexpr\
    \ ModInt operator*(const ModInt &r) const {return ModInt(*this) *= r;}\n\n   \
    \ constexpr bool operator==(const ModInt &r) const {return Value() == r.Value();}\n\
    \    constexpr bool operator!=(const ModInt &r) const {return Value() != r.Value();}\n\
    \    \n    constexpr ModInt operator+() const {return ModInt(*this);}\n    constexpr\
    \ ModInt operator-() const {return ModInt() - ModInt(*this);}\n\n    constexpr\
    \ ModInt Power(int64_t k) const {\n        ModInt ret(1), mul(*this);\n      \
    \  while(k){\n            if(k & 1) ret *= mul;\n            mul *= mul;\n   \
    \         k >>= 1;\n        }\n        return ret;\n    }\n\n    constexpr ModInt\
    \ Inverse() const {\n        return Power(MOD - 2);\n    }\n\n    constexpr uint32_t\
    \ Value() const {\n        uint32_t ret = MontgomeryReduction(x);\n        return\
    \ ret >= MOD ? ret - MOD : ret;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &r){\n        return os << r.Value();\n    }\n\n    friend\
    \ istream &operator>>(istream &is, ModInt &r){\n        int64_t y; is >> y;\n\
    \        r = MontgomeryModInt998244353(y);\n        return is;\n    }\n\n    private:\n\
    \    static constexpr u32 MontgomeryReduction(const u64 &T){\n        return (T\
    \ + u64(u32(T) * INV) * MOD) >> 32;\n    }\n\n    u32 x;\n\n    static constexpr\
    \ u32 MOD = 998244353;\n    static constexpr u32 INV = 998244351;\n    static\
    \ constexpr u32 R2 = 932051910;\n};\n\nusing mint = MontgomeryModInt998244353;"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/FormalPowerSeries/MontgomeryModInt998244353.hpp
  requiredBy:
  - Library/FormalPowerSeries/Convolution.hpp
  - Library/FormalPowerSeries/FormalPowerSeries.hpp
  timestamp: '2026-06-21 14:35:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/FormalPowerSeries/LC-ConvolutionMod.test.cpp
  - verify/FormalPowerSeries/LC-ExpFormalPowerSeries.test.cpp
  - verify/FormalPowerSeries/LC-LogFormalPowerSeries.test.cpp
  - verify/FormalPowerSeries/LC-InvFormalPowerSeries.test.cpp
documentation_of: Library/FormalPowerSeries/MontgomeryModInt998244353.hpp
layout: document
redirect_from:
- /library/Library/FormalPowerSeries/MontgomeryModInt998244353.hpp
- /library/Library/FormalPowerSeries/MontgomeryModInt998244353.hpp.html
title: Library/FormalPowerSeries/MontgomeryModInt998244353.hpp
---
