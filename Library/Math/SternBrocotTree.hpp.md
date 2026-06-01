---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cmath>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const\
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 2 \"Library/Math/SternBrocotTree.hpp\"\
    \n\nstruct SBTR{\n    using i64 = int64_t;\n    using u64 = uint64_t;\n    using\
    \ u128 = __uint128_t;\n\n    i64 nume;\n    u64 deno;\n\n    SBTR(i64 n = 0, u64\
    \ d = 1) : nume(n), deno(d){}\n\n    SBTR &operator+=(const SBTR &r){\n      \
    \  nume += r.nume;\n        deno += r.deno;\n        return (*this);\n    }\n\n\
    \    SBTR &operator*=(const u64 &r){\n        nume *= r;\n        deno *= r;\n\
    \        return (*this);\n    }\n\n    SBTR operator+(const SBTR &r) const {\n\
    \        return SBTR(*this) += r;\n    }\n\n    SBTR operator*(const u64 &r) const\
    \ {\n        return SBTR(*this) *= r;\n    }\n\n    bool operator==(const SBTR\
    \ &r) const {\n        return u128(nume) * r.deno == u128(deno) * r.nume;\n  \
    \  }\n\n    bool operator!=(const SBTR &r) const {\n        return u128(nume)\
    \ * r.deno != u128(deno) * r.nume;\n    }\n\n    bool operator<(const SBTR &r)\
    \ const {\n        return u128(nume) * r.deno < u128(deno) * r.nume;\n    }\n\n\
    \    bool operator>(const SBTR &r) const {\n        return u128(nume) * r.deno\
    \ > u128(deno) * r.nume;\n    }\n\n    bool operator<=(const SBTR &r) const {\n\
    \        return u128(nume) * r.deno <= u128(deno) * r.nume;\n    }\n\n    bool\
    \ operator>=(const SBTR &r) const {\n        return u128(nume) * r.deno >= u128(deno)\
    \ * r.nume;\n    }\n\n    bool operator<(const u64 &r) const {\n        return\
    \ nume < r || deno < r;\n    }\n\n    bool operator>(const u64 &r) const {\n \
    \       return nume > r || deno > r;\n    }\n\n    bool operator<=(const u64 &r)\
    \ const {\n        return nume <= r || deno <= r;\n    }\n\n    bool operator>=(const\
    \ u64 &r) const {\n        return nume >= r || deno >= r;\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, const SBTR &p) {\n        return os << p.nume\
    \ << ' ' << p.deno;\n    }\n};\n\nclass SternBrocotTree{\n    public:\n    using\
    \ u64 = uint64_t;\n    using u128 = __uint128_t;\n    using Rational = pair<u64,\
    \ u64>;\n\n    SternBrocotTree() : l(0, 1), r(1, 0) {}\n\n    inline void Reset(){\n\
    \        l = SBTR(0, 1), r = SBTR(1, 0);\n    }\n\n    inline SBTR Current() const\
    \ {\n        return l + r;\n    }\n\n    inline void Move(const char d, const\
    \ u64 x){\n        if(d == 'L') MoveLeft(x);\n        if(d == 'R') MoveRight(x);\n\
    \    }\n\n    inline void MoveLeft(u64 x){\n        r += l * x;\n    }\n\n   \
    \ inline void MoveRight(u64 x){\n        l += r * x;\n    }\n\n    tuple<char,\
    \ u64, bool> MoveStraightLimited(const u64 n, const u64 d, const u64 k, const\
    \ bool floor = false){\n        SBTR t(n, d), c = Current();\n        if(t < c){\n\
    \            u128 xn = u128(c.nume) * d - u128(c.deno) * n;\n            u128\
    \ xd = u128(l.deno) * n - u128(l.nume) * d;\n            u64 x = floor ? xn /\
    \ xd : (xn - 1) / xd + 1;\n            bool f = false;\n            if(c + l *\
    \ x > k) x = min((k - c.nume) / l.nume, (k - c.deno) / l.deno), f = true;\n  \
    \          MoveLeft(x);\n            return {'L', x, f};\n        }\n        else{\n\
    \            u128 xn = u128(c.deno) * n - u128(c.nume) * d;\n            u128\
    \ xd = u128(r.nume) * d - u128(r.deno) * n;\n            u64 x = floor ? xn /\
    \ xd : (xn - 1) / xd + 1;\n            bool f = false;\n            if(c + r *\
    \ x > k) x = min((k - c.nume) / r.nume, (k - c.deno) / r.deno), f = true;\n  \
    \          MoveRight(x);\n            return {'R', x, f};\n        }\n    }\n\n\
    \    pair<char, u64> MoveStraight(const u64 n, const u64 d, const bool floor =\
    \ false){\n        SBTR t(n, d), c = Current();\n        if(t < c){\n        \
    \    u128 xn = u128(c.nume) * d - u128(c.deno) * n;\n            u128 xd = u128(l.deno)\
    \ * n - u128(l.nume) * d;\n            u64 x = floor ? xn / xd : (xn - 1) / xd\
    \ + 1;\n            MoveLeft(x);\n            return {'L', x};\n        }\n  \
    \      else{\n            u128 xn = u128(c.deno) * n - u128(c.nume) * d;\n   \
    \         u128 xd = u128(r.nume) * d - u128(r.deno) * n;\n            u64 x =\
    \ floor ? xn / xd : (xn - 1) / xd + 1;\n            MoveRight(x);\n          \
    \  return {'R', x};\n        }\n    }\n\n    vector<pair<char, u64>> Encode(const\
    \ u64 n, const u64 d){\n        vector<pair<char, u64>> ret;\n        SBTR t(n,\
    \ d);\n        Reset();\n        while(1){\n            auto c = Current();\n\
    \            if(t == c) break;\n            ret.emplace_back(MoveStraight(n, d));\n\
    \        }\n        return ret;\n    }\n\n    SBTR Decode(const vector<pair<char,\
    \ u64>> &p){\n        Reset();\n        for(const auto &[c, n] : p){\n       \
    \     Move(c, n);\n        }\n        return Current();\n    }\n\n    SBTR LowestCommonAncestor(const\
    \ u64 an, const u64 ad, const u64 bn, const u64 bd){\n        auto ap = Encode(an,\
    \ ad);\n        auto bp = Encode(bn, bd);\n        Reset();\n        if(ap.empty()\
    \ || bp.empty()) return Current();\n        if(ap.front().first != bp.front().first)\
    \ return Current();\n        for(int i = 0; i < min(ap.size(), bp.size()); ++i){\n\
    \            if(ap[i] == bp[i]){\n                Move(ap[i].first, ap[i].second);\n\
    \            }\n            else{\n                Move(ap[i].first, min(ap[i].second,\
    \ bp[i].second));\n                break;\n            }\n        }\n        return\
    \ Current();\n    }\n\n    SBTR Ancestor(const u64 k, const u64 n, const u64 d){\n\
    \        auto p = Encode(n, d);\n        vector<u64> pref(p.size() + 1);\n   \
    \     for(int i = 0; i < p.size(); ++i){\n            pref[i + 1] = pref[i] +\
    \ p[i].second;\n        }\n        if(k > pref.back() || k < 0) return SBTR(-1);\n\
    \        int t = distance(pref.begin(), upper_bound(pref.begin(), pref.end(),\
    \ k)) - 1;\n        Reset();\n        for(int i = 0; i < t; ++i){\n          \
    \  Move(p[i].first, p[i].second);\n        }\n        Move(p[t].first, k - pref[t]);\n\
    \        return Current();\n    }\n\n    pair<SBTR, SBTR> Range(const u64 n, const\
    \ u64 d){\n        Encode(n, d);\n        return {l, r};\n    }\n\n    private:\n\
    \    SBTR l, r;\n};\n"
  code: "#include \"../Common.hpp\"\n\nstruct SBTR{\n    using i64 = int64_t;\n  \
    \  using u64 = uint64_t;\n    using u128 = __uint128_t;\n\n    i64 nume;\n   \
    \ u64 deno;\n\n    SBTR(i64 n = 0, u64 d = 1) : nume(n), deno(d){}\n\n    SBTR\
    \ &operator+=(const SBTR &r){\n        nume += r.nume;\n        deno += r.deno;\n\
    \        return (*this);\n    }\n\n    SBTR &operator*=(const u64 &r){\n     \
    \   nume *= r;\n        deno *= r;\n        return (*this);\n    }\n\n    SBTR\
    \ operator+(const SBTR &r) const {\n        return SBTR(*this) += r;\n    }\n\n\
    \    SBTR operator*(const u64 &r) const {\n        return SBTR(*this) *= r;\n\
    \    }\n\n    bool operator==(const SBTR &r) const {\n        return u128(nume)\
    \ * r.deno == u128(deno) * r.nume;\n    }\n\n    bool operator!=(const SBTR &r)\
    \ const {\n        return u128(nume) * r.deno != u128(deno) * r.nume;\n    }\n\
    \n    bool operator<(const SBTR &r) const {\n        return u128(nume) * r.deno\
    \ < u128(deno) * r.nume;\n    }\n\n    bool operator>(const SBTR &r) const {\n\
    \        return u128(nume) * r.deno > u128(deno) * r.nume;\n    }\n\n    bool\
    \ operator<=(const SBTR &r) const {\n        return u128(nume) * r.deno <= u128(deno)\
    \ * r.nume;\n    }\n\n    bool operator>=(const SBTR &r) const {\n        return\
    \ u128(nume) * r.deno >= u128(deno) * r.nume;\n    }\n\n    bool operator<(const\
    \ u64 &r) const {\n        return nume < r || deno < r;\n    }\n\n    bool operator>(const\
    \ u64 &r) const {\n        return nume > r || deno > r;\n    }\n\n    bool operator<=(const\
    \ u64 &r) const {\n        return nume <= r || deno <= r;\n    }\n\n    bool operator>=(const\
    \ u64 &r) const {\n        return nume >= r || deno >= r;\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, const SBTR &p) {\n        return os << p.nume\
    \ << ' ' << p.deno;\n    }\n};\n\nclass SternBrocotTree{\n    public:\n    using\
    \ u64 = uint64_t;\n    using u128 = __uint128_t;\n    using Rational = pair<u64,\
    \ u64>;\n\n    SternBrocotTree() : l(0, 1), r(1, 0) {}\n\n    inline void Reset(){\n\
    \        l = SBTR(0, 1), r = SBTR(1, 0);\n    }\n\n    inline SBTR Current() const\
    \ {\n        return l + r;\n    }\n\n    inline void Move(const char d, const\
    \ u64 x){\n        if(d == 'L') MoveLeft(x);\n        if(d == 'R') MoveRight(x);\n\
    \    }\n\n    inline void MoveLeft(u64 x){\n        r += l * x;\n    }\n\n   \
    \ inline void MoveRight(u64 x){\n        l += r * x;\n    }\n\n    tuple<char,\
    \ u64, bool> MoveStraightLimited(const u64 n, const u64 d, const u64 k, const\
    \ bool floor = false){\n        SBTR t(n, d), c = Current();\n        if(t < c){\n\
    \            u128 xn = u128(c.nume) * d - u128(c.deno) * n;\n            u128\
    \ xd = u128(l.deno) * n - u128(l.nume) * d;\n            u64 x = floor ? xn /\
    \ xd : (xn - 1) / xd + 1;\n            bool f = false;\n            if(c + l *\
    \ x > k) x = min((k - c.nume) / l.nume, (k - c.deno) / l.deno), f = true;\n  \
    \          MoveLeft(x);\n            return {'L', x, f};\n        }\n        else{\n\
    \            u128 xn = u128(c.deno) * n - u128(c.nume) * d;\n            u128\
    \ xd = u128(r.nume) * d - u128(r.deno) * n;\n            u64 x = floor ? xn /\
    \ xd : (xn - 1) / xd + 1;\n            bool f = false;\n            if(c + r *\
    \ x > k) x = min((k - c.nume) / r.nume, (k - c.deno) / r.deno), f = true;\n  \
    \          MoveRight(x);\n            return {'R', x, f};\n        }\n    }\n\n\
    \    pair<char, u64> MoveStraight(const u64 n, const u64 d, const bool floor =\
    \ false){\n        SBTR t(n, d), c = Current();\n        if(t < c){\n        \
    \    u128 xn = u128(c.nume) * d - u128(c.deno) * n;\n            u128 xd = u128(l.deno)\
    \ * n - u128(l.nume) * d;\n            u64 x = floor ? xn / xd : (xn - 1) / xd\
    \ + 1;\n            MoveLeft(x);\n            return {'L', x};\n        }\n  \
    \      else{\n            u128 xn = u128(c.deno) * n - u128(c.nume) * d;\n   \
    \         u128 xd = u128(r.nume) * d - u128(r.deno) * n;\n            u64 x =\
    \ floor ? xn / xd : (xn - 1) / xd + 1;\n            MoveRight(x);\n          \
    \  return {'R', x};\n        }\n    }\n\n    vector<pair<char, u64>> Encode(const\
    \ u64 n, const u64 d){\n        vector<pair<char, u64>> ret;\n        SBTR t(n,\
    \ d);\n        Reset();\n        while(1){\n            auto c = Current();\n\
    \            if(t == c) break;\n            ret.emplace_back(MoveStraight(n, d));\n\
    \        }\n        return ret;\n    }\n\n    SBTR Decode(const vector<pair<char,\
    \ u64>> &p){\n        Reset();\n        for(const auto &[c, n] : p){\n       \
    \     Move(c, n);\n        }\n        return Current();\n    }\n\n    SBTR LowestCommonAncestor(const\
    \ u64 an, const u64 ad, const u64 bn, const u64 bd){\n        auto ap = Encode(an,\
    \ ad);\n        auto bp = Encode(bn, bd);\n        Reset();\n        if(ap.empty()\
    \ || bp.empty()) return Current();\n        if(ap.front().first != bp.front().first)\
    \ return Current();\n        for(int i = 0; i < min(ap.size(), bp.size()); ++i){\n\
    \            if(ap[i] == bp[i]){\n                Move(ap[i].first, ap[i].second);\n\
    \            }\n            else{\n                Move(ap[i].first, min(ap[i].second,\
    \ bp[i].second));\n                break;\n            }\n        }\n        return\
    \ Current();\n    }\n\n    SBTR Ancestor(const u64 k, const u64 n, const u64 d){\n\
    \        auto p = Encode(n, d);\n        vector<u64> pref(p.size() + 1);\n   \
    \     for(int i = 0; i < p.size(); ++i){\n            pref[i + 1] = pref[i] +\
    \ p[i].second;\n        }\n        if(k > pref.back() || k < 0) return SBTR(-1);\n\
    \        int t = distance(pref.begin(), upper_bound(pref.begin(), pref.end(),\
    \ k)) - 1;\n        Reset();\n        for(int i = 0; i < t; ++i){\n          \
    \  Move(p[i].first, p[i].second);\n        }\n        Move(p[t].first, k - pref[t]);\n\
    \        return Current();\n    }\n\n    pair<SBTR, SBTR> Range(const u64 n, const\
    \ u64 d){\n        Encode(n, d);\n        return {l, r};\n    }\n\n    private:\n\
    \    SBTR l, r;\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Math/SternBrocotTree.hpp
  requiredBy: []
  timestamp: '2026-04-12 14:16:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Math/SternBrocotTree.hpp
layout: document
redirect_from:
- /library/Library/Math/SternBrocotTree.hpp
- /library/Library/Math/SternBrocotTree.hpp.html
title: Library/Math/SternBrocotTree.hpp
---
