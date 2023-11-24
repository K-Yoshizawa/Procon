---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/Combination.hpp
    title: icpc/Combination.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/ModInt.hpp
    title: icpc/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D
  bundledCode: "#line 1 \"verify_icpc/AOJ-DPL-5-D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D\"\
    \n\n#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
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
    using vm107 = vector<m107>;\nusing vvm107 = vector<vector<m107>>;\n#line 2 \"\
    icpc/Combination.hpp\"\n\ntemplate<typename T>\nstruct combination{\n    vector<T>\
    \ fn, rn, in;\n\n    combination(int sz) : fn(sz + 1), rn(sz + 1), in(sz + 1){\n\
    \        fn[0] = rn[sz] = in[0] = 1;\n        for(int i = 1; i <= sz; ++i) fn[i]\
    \ = fn[i - 1] * i;\n        rn[sz] /= fn[sz];\n        for(int i = sz - 1; i >=\
    \ 0; --i) rn[i] = rn[i + 1] * (i + 1);\n        for(int i = 1; i <= sz; ++i) in[i]\
    \ = rn[i] * fn[i - 1];\n    }\n\n    T fact(int k){return fn[k];}\n    T rfact(int\
    \ k){return rn[k];}\n    T inv(int k){return in[k];}\n\n    T P(int n, int r){\n\
    \        if(r < 0 or n < r) return 0;\n        return fact(n) * rfact(n - r);\n\
    \    }\n    T C(int n, int r){\n        if(r < 0 or n < r) return 0;\n       \
    \ return fact(n) * rfact(r) * rfact(n - r);\n    }\n    T H(int n, int r){\n \
    \       if(n < 0 or r < 0) return 0;\n        return r == 0 ? 1 : C(n + r - 1,\
    \ r);\n    }\n};\n#line 5 \"verify_icpc/AOJ-DPL-5-D.test.cpp\"\n\nint main(){\n\
    \    int n, k;\n    cin >> n >> k;\n\n    combination<m107> comb(2010);\n    cout\
    \ << comb.H(k, n) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D\"\
    \n\n#include \"../icpc/ModInt.hpp\"\n#include \"../icpc/Combination.hpp\"\n\n\
    int main(){\n    int n, k;\n    cin >> n >> k;\n\n    combination<m107> comb(2010);\n\
    \    cout << comb.H(k, n) << endl;\n}"
  dependsOn:
  - icpc/ModInt.hpp
  - icpc/Template.hpp
  - icpc/Combination.hpp
  isVerificationFile: true
  path: verify_icpc/AOJ-DPL-5-D.test.cpp
  requiredBy: []
  timestamp: '2023-11-24 19:51:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_icpc/AOJ-DPL-5-D.test.cpp
layout: document
redirect_from:
- /verify/verify_icpc/AOJ-DPL-5-D.test.cpp
- /verify/verify_icpc/AOJ-DPL-5-D.test.cpp.html
title: verify_icpc/AOJ-DPL-5-D.test.cpp
---
