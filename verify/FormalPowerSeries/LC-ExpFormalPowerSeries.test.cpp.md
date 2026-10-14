---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/FormalPowerSeries/Convolution.hpp
    title: Library/FormalPowerSeries/Convolution.hpp
  - icon: ':heavy_check_mark:'
    path: Library/FormalPowerSeries/FormalPowerSeries.hpp
    title: Library/FormalPowerSeries/FormalPowerSeries.hpp
  - icon: ':heavy_check_mark:'
    path: Library/FormalPowerSeries/MontgomeryModInt998244353.hpp
    title: Library/FormalPowerSeries/MontgomeryModInt998244353.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series
  bundledCode: "#line 1 \"verify/FormalPowerSeries/LC-ExpFormalPowerSeries.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\
    \n\n#line 2 \"Library/FormalPowerSeries/FormalPowerSeries.hpp\"\n\n#line 2 \"\
    Library/Common.hpp\"\n\n#include <algorithm>\n#include <array>\n#include <bit>\n\
    #include <bitset>\n#include <cassert>\n#include <cmath>\n#include <cstdint>\n\
    #include <deque>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\nusing namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\
    \nconstexpr const ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 2 \"Library/FormalPowerSeries/Convolution.hpp\"\
    \n\n#line 2 \"Library/FormalPowerSeries/MontgomeryModInt998244353.hpp\"\n\n#line\
    \ 4 \"Library/FormalPowerSeries/MontgomeryModInt998244353.hpp\"\n\nclass MontgomeryModInt998244353{\n\
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
    \ constexpr u32 R2 = 932051910;\n};\n\nusing mint = MontgomeryModInt998244353;\n\
    #line 5 \"Library/FormalPowerSeries/Convolution.hpp\"\n\nnamespace ntt {\n   \
    \ struct Info{\n        static constexpr int g = 3;\n        static constexpr\
    \ int rank2 = 23;\n\n        mint root[rank2 + 1], iroot[rank2 + 1];\n       \
    \ mint rate3[rank2 + 1], irate3[rank2 + 1];\n\n        Info(){\n            root[rank2]\
    \ = mint(g).Power((998244353 - 1) >> rank2);\n            iroot[rank2] = root[rank2].Inverse();\n\
    \            for(int i = rank2 - 1; i >= 0; --i){\n                root[i] = root[i\
    \ + 1] * root[i + 1];\n                iroot[i] = iroot[i + 1] * iroot[i + 1];\n\
    \            }\n            mint prod = 1, iprod = 1;\n            for (int i\
    \ = 0; i <= rank2 - 3; ++i) {\n                rate3[i]  = root[i + 3]  * prod;\n\
    \                irate3[i] = iroot[i + 3] * iprod;\n                prod  *= iroot[i\
    \ + 3];\n                iprod *= root[i + 3];\n            }\n        }\n   \
    \ };\n\n    inline const Info& info(){\n        static Info instance;\n      \
    \  return instance;\n    }\n\n    void ntt(vector<mint> &f){\n        const int\
    \ n = f.size();\n        const int h = countr_zero(static_cast<uint32_t>(n));\n\
    \        const auto& I = info();\n        int len = 0;\n        if(h & 1){\n \
    \           int p = 1 << (h - 1);\n            for(int i = 0; i < p; ++i){\n \
    \               mint r = f[i + p];\n                f[i + p] = f[i] - r;\n   \
    \             f[i] += r;\n            }\n            len++;\n        }\n     \
    \   for(; len + 1 < h; len += 2){\n            int p = 1 << (h - len - 2);\n \
    \           const mint imag = I.root[2];\n            for(int i = 0; i < p; ++i){\n\
    \                mint f0 = f[i], f1 = f[i + p], f2 = f[i + 2 * p], f3 = f[i +\
    \ 3 * p];\n                mint f1nf3imag = (f1 - f3) * imag;\n              \
    \  mint f0f2 = f0 + f2, f1f3 = f1 + f3, f0nf2 = f0 - f2;\n                f[i]\
    \ = f0f2 + f1f3;\n                f[i + p] = f0f2 - f1f3;\n                f[i\
    \ + 2 * p] = f0nf2 + f1nf3imag;\n                f[i + 3 * p] = f0nf2 - f1nf3imag;\n\
    \            }\n            mint rot = I.rate3[0];\n            for(int s = 1;\
    \ s < (1 << len); ++s){\n                int offset = s << (h - len);\n      \
    \          mint rot2 = rot * rot, rot3 = rot2 * rot;\n                for(int\
    \ i = 0; i < p; ++i){\n                    mint f0 = f[i + offset];\n        \
    \            mint f1 = f[i + offset + p] * rot;\n                    mint f2 =\
    \ f[i + offset + 2 * p] * rot2;\n                    mint f3 = f[i + offset +\
    \ 3 * p] * rot3;\n                    mint f1nf3imag = (f1 - f3) * imag;\n   \
    \                 mint f0f2 = f0 + f2, f1f3 = f1 + f3, f0nf2 = f0 - f2;\n    \
    \                f[i + offset] = f0f2 + f1f3;\n                    f[i + offset\
    \ + p] = f0f2 - f1f3;\n                    f[i + offset + 2 * p] = f0nf2 + f1nf3imag;\n\
    \                    f[i + offset + 3 * p] = f0nf2 - f1nf3imag;\n            \
    \    }\n                rot *= I.rate3[countr_zero(~static_cast<uint32_t>(s))];\n\
    \            }\n        }\n    }\n\n    void intt(vector<mint> &f, bool flag =\
    \ true){\n        const int n = f.size();\n        const int h = countr_zero(static_cast<uint32_t>(n));\n\
    \        const auto& I = info();\n        int len = h;\n        for(; len > 1;\
    \ len -= 2){\n            int p = 1 << (h - len);\n            const mint iimag\
    \ = I.iroot[2];\n            for(int i = 0; i < p; ++i){\n                mint\
    \ f0 = f[i], f1 = f[i + p], f2 = f[i + 2 * p], f3 = f[i + 3 * p];\n          \
    \      mint f2nf3iimag = (f2 - f3) * iimag;\n                mint f0nf1 = f0 -\
    \ f1, f0f1 = f0 + f1, f2f3 = f2 + f3;\n                f[i] = f0f1 + f2f3;\n \
    \               f[i + p] = f0nf1 + f2nf3iimag;\n                f[i + 2 * p] =\
    \ f0f1 - f2f3;\n                f[i + 3 * p] = f0nf1 - f2nf3iimag;\n         \
    \   }\n            mint irot = I.irate3[0];\n            for(int s = 1; s < (1\
    \ << (len - 2)); ++s){\n                int offset = s << (h - len + 2);\n   \
    \             mint irot2 = irot * irot, irot3 = irot2 * irot;\n              \
    \  for(int i = 0; i < p; ++i){\n                    mint f0 = f[i + offset];\n\
    \                    mint f1 = f[i + offset + p];\n                    mint f2\
    \ = f[i + offset + 2 * p];\n                    mint f3 = f[i + offset + 3 * p];\n\
    \                    mint f2nf3iimag = (f2 - f3) * iimag;\n                  \
    \  mint f0nf1 = f0 - f1, f0f1 = f0 + f1, f2f3 = f2 + f3;\n                   \
    \ f[i + offset] = f0f1 + f2f3;\n                    f[i + offset + p] = (f0nf1\
    \ + f2nf3iimag) * irot;\n                    f[i + offset + 2 * p] = (f0f1 - f2f3)\
    \ * irot2;\n                    f[i + offset + 3 * p] = (f0nf1 - f2nf3iimag) *\
    \ irot3;\n                }\n                irot *= I.irate3[countr_zero(~static_cast<uint32_t>(s))];\n\
    \            }\n        }\n        if(len >= 1){\n            int p = 1 << (h\
    \ - 1);\n            for(int i = 0; i < p; ++i){\n                mint fjp = f[i]\
    \ - f[i + p];\n                f[i] += f[i + p];\n                f[i + p] = fjp;\n\
    \            }\n        }\n        if(flag){\n            mint inv = mint(n).Inverse();\n\
    \            for(auto &x : f){\n                x *= inv;\n            }\n   \
    \     }\n    }\n\n    vector<mint> Convolution(vector<mint> A, vector<mint> B){\n\
    \        const int N = A.size(), M = B.size();\n        if(N == 0 || M == 0) return\
    \ {};\n\n        if(min(N, M) <= 60){\n            vector<mint> C(N + M - 1);\n\
    \            for(int i = 0; i < N; ++i){\n                for(int j = 0; j < M;\
    \ ++j){\n                    C[i + j] += A[i] * B[j];\n                }\n   \
    \         }\n            return C;\n        }\n\n        const int z = bit_ceil(static_cast<uint32_t>(N\
    \ + M - 1));\n        A.resize(z); ntt(A);\n        B.resize(z); ntt(B);\n   \
    \     const mint iz = mint(z).Inverse();\n        for(int i = 0; i < z; ++i){\n\
    \            A[i] *= B[i] * iz;\n        }\n        intt(A, false);\n        A.resize(N\
    \ + M - 1);\n        return A;\n    }\n};\n#line 5 \"Library/FormalPowerSeries/FormalPowerSeries.hpp\"\
    \n\nclass FormalPowerSeries : public vector<mint> {\n    public:\n    using vector<mint>::vector;\n\
    \    using FPS = FormalPowerSeries;\n\n    FPS Inverse(int N = -1) const {\n \
    \       assert(!this->empty() && (*this)[0] != mint(0));\n        if(N == -1){\n\
    \            N = this->size();\n        }\n        FPS res = {(*this)[0].Inverse()};\n\
    \        for(int i = 1; i < N; i <<= 1){\n            FPS t = (this->Prefix(i\
    \ << 1) * res).Prefix(i << 1);\n            for(auto &x : t){\n              \
    \  x = -x;\n            }\n            t[0] += mint(2);\n            res = (res\
    \ * t).Prefix(i << 1);\n        }\n        return res.Prefix(N);\n    }\n\n  \
    \  FPS Exp(int N = -1) const {\n        assert(this->empty() || (*this)[0] ==\
    \ mint(0));\n        if(N == -1){\n            N = this->size();\n        }\n\
    \        FPS res = {mint(1)};\n        for(int i = 1; i < N; i <<= 1){\n     \
    \       FPS t = this->Prefix(i << 1) - res.Log(i << 1);\n            t[0] += mint(1);\n\
    \            res = (res * t).Prefix(i << 1);\n        }\n        return res.Prefix(N);\n\
    \    }\n\n    FPS Log(int N = -1) const {\n        assert(!this->empty() && (*this)[0]\
    \ == mint(1));\n        if(N == -1){\n            N = this->size();\n        }\n\
    \        return (this->Prefix(N).Differential() * this->Inverse(N)).Prefix(N -\
    \ 1).Integral().Prefix(N);\n    }\n\n    FPS Differential() const {\n        const\
    \ int N = this->size();\n        FPS ret(max(0, N - 1));\n        for(int i =\
    \ 1; i < N; ++i){\n            ret[i - 1] = (*this)[i] * mint(i);\n        }\n\
    \        return ret;\n    }\n\n    FPS Integral() const {\n        const int N\
    \ = this->size();\n        FPS ret(N + 1);\n        vector<mint> inv(N + 1);\n\
    \        if(N >= 1){\n            inv[1] = 1;\n        }\n        for(int i =\
    \ 2; i <= N; ++i){\n            inv[i] = -inv[998244353 % i] * (998244353 / i);\n\
    \        }\n        for(int i = 0; i < N; ++i){\n            ret[i + 1] = (*this)[i]\
    \ * inv[i + 1];\n        }\n        return ret;\n    }\n\n    FPS &operator+=(const\
    \ mint &v){if (this->empty()) this->resize(1); (*this)[0] += v; return *this;}\n\
    \    FPS &operator-=(const mint &v){if (this->empty()) this->resize(1); (*this)[0]\
    \ -= v; return *this;}\n    FPS &operator*=(const mint &v){for (auto &x : *this)\
    \ x *= v; return *this;}\n    FPS &operator/=(const mint &v){return *this *= v.Inverse();}\n\
    \n    FPS &operator+=(const FPS &r){\n        if(r.size() > this->size()){\n \
    \           this->resize(r.size());\n        }\n        for(int i = 0; i < (int)r.size();\
    \ ++i){\n            (*this)[i] += r[i];\n        }\n        return *this;\n \
    \   }\n    FPS &operator-=(const FPS &r){\n        if(r.size() > this->size()){\n\
    \            this->resize(r.size());\n        }\n        for(int i = 0; i < (int)r.size();\
    \ ++i){\n            (*this)[i] -= r[i];\n        }\n        return *this;\n \
    \   }\n    FPS &operator*=(const FPS &r){\n        if(this->empty() || r.empty()){\n\
    \            this->clear(); return *this;\n        }\n        auto res = ntt::Convolution(*this,\
    \ r);\n        return *this = FPS(res.begin(), res.end());\n    }\n\n    FPS operator-()\
    \ const {FPS ret(*this); for (auto &x : ret) x = -x; return ret;}\n\n    FPS operator+(const\
    \ mint &v) const {return FPS(*this) += v;}\n    FPS operator-(const mint &v) const\
    \ {return FPS(*this) -= v;}\n    FPS operator*(const mint &v) const {return FPS(*this)\
    \ *= v;}\n    FPS operator/(const mint &v) const {return FPS(*this) /= v;}\n \
    \   FPS operator+(const FPS &r) const {return FPS(*this) += r;}\n    FPS operator-(const\
    \ FPS &r) const {return FPS(*this) -= r;}\n    FPS operator*(const FPS &r) const\
    \ {return FPS(*this) *= r;}\n\n    private:\n    FPS Prefix(int N) const {\n \
    \       FPS ret(this->begin(), this->begin() + min((int)this->size(), N));\n \
    \       ret.resize(N);\n        return ret;\n    }\n};\n#line 4 \"verify/FormalPowerSeries/LC-ExpFormalPowerSeries.test.cpp\"\
    \n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n\n    int N; cin >>\
    \ N;\n    FormalPowerSeries A(N);\n    for(int i = 0; i < N; ++i){\n        cin\
    \ >> A[i];\n    }\n\n    auto B = A.Exp();\n    for(auto &b : B){\n        cout\
    \ << b << ' ';\n    }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\
    \n\n#include \"../../Library/FormalPowerSeries/FormalPowerSeries.hpp\"\n\nint\
    \ main(){\n    cin.tie(0)->sync_with_stdio(false);\n\n    int N; cin >> N;\n \
    \   FormalPowerSeries A(N);\n    for(int i = 0; i < N; ++i){\n        cin >> A[i];\n\
    \    }\n\n    auto B = A.Exp();\n    for(auto &b : B){\n        cout << b << '\
    \ ';\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - Library/FormalPowerSeries/FormalPowerSeries.hpp
  - Library/Common.hpp
  - Library/FormalPowerSeries/Convolution.hpp
  - Library/FormalPowerSeries/MontgomeryModInt998244353.hpp
  isVerificationFile: true
  path: verify/FormalPowerSeries/LC-ExpFormalPowerSeries.test.cpp
  requiredBy: []
  timestamp: '2026-06-21 14:35:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/FormalPowerSeries/LC-ExpFormalPowerSeries.test.cpp
layout: document
redirect_from:
- /verify/verify/FormalPowerSeries/LC-ExpFormalPowerSeries.test.cpp
- /verify/verify/FormalPowerSeries/LC-ExpFormalPowerSeries.test.cpp.html
title: verify/FormalPowerSeries/LC-ExpFormalPowerSeries.test.cpp
---
