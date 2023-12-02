---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/String/RollingHash.hpp
    title: "Rolling Hash - \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"verify/AOJ-ALDS1-14-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#line 1 \"library/String/RollingHash.hpp\"\n/**\n * @file RollingHash.hpp\n\
    \ * @author log K (lX57)\n * @brief Rolling Hash - \u30ED\u30FC\u30EA\u30F3\u30B0\
    \u30CF\u30C3\u30B7\u30E5\n * @version 1.0\n * @date 2023-12-03\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nnamespace rh{\n    const ulong MASK30\
    \ = (1UL << 30) - 1;\n    const ulong MASK31 = (1UL << 31) - 1;\n    const ulong\
    \ MOD = (1UL << 61) - 1;\n    const ulong MASK61 = MOD;\n    const ulong POSITIVIZER\
    \ = MOD * 4;\n    vector<ulong> base;\n    vector<vector<ulong>> pow;\n\n    ulong\
    \ Mod(ulong x){\n        ulong xu = x >> 61, xd = x & MASK61;\n        ulong res\
    \ = xu + xd;\n        if(res >= MOD) res -= MOD;\n        return res;\n    }\n\
    \n    ulong Mul(ulong a, ulong b){\n        ulong au = a >> 31, ad = a & MASK31;\n\
    \        ulong bu = b >> 31, bd = b & MASK31;\n        ulong m = ad * bu + au\
    \ * bd;\n        ulong mu = m >> 30, md = m & MASK30;\n        return au * bu\
    \ * 2 + mu + (md << 31) + ad * bd;\n    }\n};\n\n/**\n * @brief \u30ED\u30FC\u30EA\
    \u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u306E\u57FA\u5E95\u3092\u751F\u6210\u3059\
    \u308B\n * @attention \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u3092\
    \u4F7F\u3046\u524D\u306B\u5FC5\u305A\u547C\u3073\u51FA\u3059\u3053\u3068\n * @param\
    \ N \u6587\u5B57\u5217\u306E\u6700\u5927\u6587\u5B57\u6570 (default = 1e6 + 10)\n\
    \ * @param Cnt \u751F\u6210\u3059\u308B\u57FA\u5E95\u306E\u6570 (default = 3)\n\
    \ */\nvoid RollingHash_createbase(int N = 1000010, int Cnt = 3){\n    random_device\
    \ rnd;\n    mt19937 mt(rnd());\n    uniform_int_distribution<ulong> dist(1, rh::MOD\
    \ - 1);\n    for(int i = 0; i < Cnt; ++i) rh::base.push_back(dist(mt));\n    rh::pow.resize(Cnt,\
    \ vector<ulong>(N + 1, 1UL));\n    for(int i = 0; i < Cnt; ++i){\n        for(int\
    \ j = 1; j <= N; ++j){\n            rh::pow[i][j] = rh::Mod(rh::Mul(rh::pow[i][j\
    \ - 1], rh::base[i]));\n        }\n    }\n}\n\nstruct RollingHash{\n    private:\n\
    \    vector<vector<ulong>> __PrefixHash;\n    bool __ValidPrefixHash{false};\n\
    \    vector<ulong> __Hash;\n    int __Hashsize, __Length;\n\n    public:\n   \
    \ RollingHash() : __Hashsize(rh::base.size()), __Hash(rh::base.size(), 0), __Length(0){}\n\
    \n    /**\n     * @brief \u6587\u5B57\u5217 `S` \u304B\u3089\u30CF\u30C3\u30B7\
    \u30E5\u3092\u751F\u6210\u3059\u308B\n     * @note \u3053\u306E\u5834\u5408\u306B\
    \u9650\u308A\u3001 `PrefixHash` \u304C\u8A08\u7B97\u3055\u308C\u3001 `substr`\
    \ \u3092\u4F7F\u3046\u3053\u3068\u304C\u3067\u304D\u308B\n     */\n    RollingHash(string\
    \ S) : __Hashsize(rh::base.size()), __Length(S.size()){\n        __PrefixHash.resize(__Hashsize);\n\
    \        for(int i = 0; i < __Hashsize; ++i){\n            ulong x = 0, b = rh::base[i];\n\
    \            __PrefixHash[i].push_back(0);\n            for(auto c : S){\n   \
    \             x = rh::Mod(rh::Mul(x, b) + c);\n                __PrefixHash[i].push_back(x);\n\
    \            }\n            __Hash.push_back(x);\n        }\n        __ValidPrefixHash\
    \ = true;\n    }\n\n    /**\n     * @brief \u6587\u5B57 `c` \u304B\u3089\u30CF\
    \u30C3\u30B7\u30E5\u3092\u751F\u6210\u3059\u308B\n     */\n    RollingHash(char\
    \ c) : __Hashsize(rh::base.size()), __Length(1){\n        __Hash.resize(__Hashsize,\
    \ c);\n    }\n\n    /**\n     * @brief \u521D\u671F\u306E\u30CF\u30C3\u30B7\u30E5\
    \u5024\u3068\u6587\u5B57\u5217\u9577\u304B\u3089\u30CF\u30C3\u30B7\u30E5\u3092\
    \u751F\u6210\u3059\u308B\n     */\n    RollingHash(vector<ulong> &InitHash, int\
    \ Length) : __Hashsize(rh::base.size()), __Hash(InitHash), __Length(Length){}\n\
    \n    inline ulong get(int i) const {\n        return __Hash[i];\n    }\n\n  \
    \  inline int length(){\n        return __Length;\n    }\n\n    /**\n     * @brief\
    \ \u6587\u5B57\u5217\u306E\u90E8\u5206\u6587\u5B57\u5217 `[l, r]` \u306E\u30CF\
    \u30C3\u30B7\u30E5\u3092\u53D6\u5F97\u3059\u308B\n     * @attention `l, r` \u306F\
    1-index\n     */\n    RollingHash substr(int l, int r){\n        assert(__ValidPrefixHash);\n\
    \        vector<ulong> ret;\n        for(int i = 0; i < __Hashsize; ++i){\n  \
    \          ret.push_back(rh::Mod(__PrefixHash[i][r] + rh::POSITIVIZER - rh::Mul(__PrefixHash[i][l\
    \ - 1], rh::pow[i][r - l + 1])));\n        }\n        return RollingHash(ret,\
    \ r - l + 1);\n    }\n\n    /**\n     * @brief \u30CF\u30C3\u30B7\u30E5 `l` \u3068\
    \u30CF\u30C3\u30B7\u30E5 `r` \u3092\u3053\u306E\u9806\u306B\u9023\u7D50\u3059\u308B\
    \n     */\n    static RollingHash connect(RollingHash &l, RollingHash &r){\n \
    \       vector<ulong> ret;\n        for(int i = 0; i < rh::base.size(); ++i){\n\
    \            ret.push_back(rh::Mod(rh::Mul(l.get(i), rh::pow[i][r.length()]) +\
    \ r.get(i)));\n        }\n        return RollingHash(ret, l.length() + r.length());\n\
    \    }\n\n    bool operator==(const RollingHash& r) const {\n        bool ret\
    \ = true;\n        for(int i = 0; i < rh::base.size(); ++i){\n            ret\
    \ &= get(i) == r.get(i);\n        }\n        return ret;\n    }\n};\n#line 4 \"\
    verify/AOJ-ALDS1-14-B.test.cpp\"\n\nint main(){\n    string T, P; cin >> T >>\
    \ P;\n\n    RollingHash_createbase();\n    RollingHash RHT(T), RHP(P);\n    for(int\
    \ i = 0; i < (int)T.size() - (int)P.size() + 1; ++i){\n        if(RHT.substr(i\
    \ + 1, i + P.size()) == RHP){\n            cout << i << endl;\n        }\n   \
    \ }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#include \"../library/String/RollingHash.hpp\"\n\nint main(){\n    string\
    \ T, P; cin >> T >> P;\n\n    RollingHash_createbase();\n    RollingHash RHT(T),\
    \ RHP(P);\n    for(int i = 0; i < (int)T.size() - (int)P.size() + 1; ++i){\n \
    \       if(RHT.substr(i + 1, i + P.size()) == RHP){\n            cout << i <<\
    \ endl;\n        }\n    }\n}"
  dependsOn:
  - library/String/RollingHash.hpp
  isVerificationFile: true
  path: verify/AOJ-ALDS1-14-B.test.cpp
  requiredBy: []
  timestamp: '2023-12-03 07:05:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-ALDS1-14-B.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-ALDS1-14-B.test.cpp
- /verify/verify/AOJ-ALDS1-14-B.test.cpp.html
title: verify/AOJ-ALDS1-14-B.test.cpp
---
