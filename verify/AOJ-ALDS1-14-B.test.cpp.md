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
    \ <bits/stdc++.h>\nusing namespace std;\n\nstruct RollingHash{\n    using Hash\
    \ = uint64_t;\n    using HashTable = vector<Hash>;\n\n    private:\n    using\
    \ u64 = uint64_t;\n    using u128 = __uint128_t;\n\n    static const u64 MOD =\
    \ (1UL << 61) - 1;\n\n    static Hash base;\n    static HashTable power;\n\n \
    \   static inline u64 add(u64 a, u64 b){\n        if((a += b) >= MOD) a -= MOD;\n\
    \        return a;\n    }\n\n    static inline u64 mul(u64 a, u64 b){\n      \
    \  u128 c = u128(a) * b;\n        return add(c >> 61, c & MOD);\n    }\n\n   \
    \ public:\n    /**\n     * @brief \u30CF\u30C3\u30B7\u30E5\u306E\u30D9\u30FC\u30B9\
    \u3092\u69CB\u7BC9\u3059\u308B\u3002\u540C\u6642\u306B\u90E8\u5206\u6587\u5B57\
    \u5217\u7528\u306E `power` \u914D\u5217\u3082\u521D\u671F\u5316\u3059\u308B\u3002\
    \n     * @attention \u5FC5\u305A\u6700\u521D\u306B\u547C\u3073\u51FA\u3059\u3053\
    \u3068\n     * @param MaxLength power\u306E\u914D\u5217\u9577\u3001\u6587\u5B57\
    \u5217\u3068\u3057\u3066\u3042\u308A\u5F97\u308B\u6700\u5927\u9577 `(default =\
    \ 10^6)`\n     */\n    static void generate_base(const int MaxLength = 1000020){\n\
    \        random_device rnd;\n        mt19937 mt(rnd());\n        uniform_int_distribution<u64>\
    \ dist(1, MOD - 1);\n        base = dist(mt);\n        power.resize(MaxLength);\n\
    \        power[0] = 1;\n        for(int i = 1; i <= MaxLength; ++i){\n       \
    \     power[i] = mul(power[i - 1], base);\n        }\n    }\n\n    /**\n     *\
    \ @brief \u6587\u5B57\u5217 `S` \u306B\u5BFE\u3059\u308B\u30CF\u30C3\u30B7\u30E5\
    \u30C6\u30FC\u30D6\u30EB\u3092\u4F5C\u6210\u3059\u308B\u3002\n     * @note \u6587\
    \u5B57\u5217\u81EA\u4F53\u306E\u30CF\u30C3\u30B7\u30E5\u306F `HashTable.back()`\
    \ \u306E\u5024\n     * @param S \u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\
    \u3092\u4F5C\u6210\u3059\u308B\u6587\u5B57\u5217\n     * @return HashTable \u30CF\
    \u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u30011-index\u3067 i \u756A\u76EE\u306E\
    \u8981\u7D20\u306F\u5148\u982D\u304B\u3089 i \u6587\u5B57\u306E\u90E8\u5206\u6587\
    \u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u8868\u3059\u3002\n   \
    \  */\n    HashTable build(string S){\n        HashTable ret;\n        u64 x =\
    \ 0;\n        ret.push_back(0);\n        for(auto c : S){\n            x = add(mul(x,\
    \ base), c);\n            ret.push_back(x);\n        }\n        return ret;\n\
    \    }\n\n    /**\n     * @brief \u6587\u5B57 `c` \u306B\u5BFE\u3059\u308B\u30CF\
    \u30C3\u30B7\u30E5\u5024\u3092\u8FD4\u3059\u3002\n     * @note \u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\u3068\u304B\u3067\u4F7F\u3048\u308B\u3002\n     */\n    Hash\
    \ build(char c){\n        return add(0, c);\n    }\n\n    /**\n     * @brief \u30CF\
    \u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB `hash` \u306B\u304A\u3044\u3066\u3001\
    \u90E8\u5206\u6587\u5B57\u5217 `[l, r]` \u306E\u30CF\u30C3\u30B7\u30E5\u3092\u53D6\
    \u5F97\u3059\u308B\n     * @attention `l`, `r` \u306F 1-index\n     * @return\
    \ \u90E8\u5206\u6587\u5B57\u5217 `[l, r]` \u306E\u30CF\u30C3\u30B7\u30E5\u5024\
    \ \n     */\n    Hash substr(HashTable &hash, int l, int r){\n        return add(hash[r],\
    \ MOD - mul(hash[l - 1], power[r - l + 1]));\n    }\n\n    /**\n     * @brief\
    \ \u30CF\u30C3\u30B7\u30E5\u3067\u8868\u3055\u308C\u305F2\u3064\u306E\u6587\u5B57\
    \u5217\u3092\u3053\u306E\u9806\u756A\u3067\u9023\u7D50\u3057\u305F\u30CF\u30C3\
    \u30B7\u30E5\u5024\u3092\u8FD4\u3059\u3002\n     * @param l \u9023\u7D50\u3059\
    \u308B\u5DE6\u5074\u306E\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5024\
    \n     * @param r \u9023\u7D50\u3059\u308B\u53F3\u5074\u306E\u6587\u5B57\u5217\
    \u306E\u30CF\u30C3\u30B7\u30E5\u5024\n     * @param r_len \u53F3\u5074\u306E\u6587\
    \u5B57\u5217\u306E\u9577\u3055\n     * @return Hash \u9023\u7D50\u3057\u305F\u6587\
    \u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5024\n     */\n    Hash connect(Hash\
    \ l, Hash r, int r_len){\n        return add(mul(l, power[r_len]), r);\n    }\n\
    };\n\ntypename RollingHash::Hash RollingHash::base;\ntypename RollingHash::HashTable\
    \ RollingHash::power;\nusing Hash = RollingHash::Hash;\nusing HashTable = RollingHash::HashTable;\n\
    #line 4 \"verify/AOJ-ALDS1-14-B.test.cpp\"\n\nint main(){\n    string T, P; cin\
    \ >> T >> P;\n\n    RollingHash::generate_base();\n    RollingHash rh;\n    HashTable\
    \ ht_T = rh.build(T);\n    Hash hash_P = rh.build(P).back();\n    for(int i =\
    \ 0; i < (int)T.size() - (int)P.size() + 1; ++i){\n        if(rh.substr(ht_T,\
    \ i + 1, i + P.size()) == hash_P){\n            cout << i << endl;\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#include \"../library/String/RollingHash.hpp\"\n\nint main(){\n    string\
    \ T, P; cin >> T >> P;\n\n    RollingHash::generate_base();\n    RollingHash rh;\n\
    \    HashTable ht_T = rh.build(T);\n    Hash hash_P = rh.build(P).back();\n  \
    \  for(int i = 0; i < (int)T.size() - (int)P.size() + 1; ++i){\n        if(rh.substr(ht_T,\
    \ i + 1, i + P.size()) == hash_P){\n            cout << i << endl;\n        }\n\
    \    }\n}"
  dependsOn:
  - library/String/RollingHash.hpp
  isVerificationFile: true
  path: verify/AOJ-ALDS1-14-B.test.cpp
  requiredBy: []
  timestamp: '2024-03-10 17:58:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-ALDS1-14-B.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-ALDS1-14-B.test.cpp
- /verify/verify/AOJ-ALDS1-14-B.test.cpp.html
title: verify/AOJ-ALDS1-14-B.test.cpp
---
