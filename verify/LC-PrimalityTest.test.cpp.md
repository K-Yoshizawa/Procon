---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/MillerRabin.hpp
    title: Library/Math/MillerRabin.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Montgomery.hpp
    title: Library/Math/Montgomery.hpp
  - icon: ':question:'
    path: Library/Template.hpp
    title: Library/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"verify/LC-PrimalityTest.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\
    \n\n#line 2 \"Library/Template.hpp\"\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n\
    \ * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bit>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include <cstdint>\n\
    #include <deque>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\nusing namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\
    \nconstexpr const ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 4 \"Library/Template.hpp\"\
    \n\ninline bool YnPrint(bool flag){cout << (flag ? \"Yes\" : \"No\") << '\\n';\
    \ return flag;}\ninline bool YNPrint(bool flag){cout << (flag ? \"YES\" : \"NO\"\
    ) << '\\n'; return flag;}\ntemplate<typename Container>\ninline void Sort(Container\
    \ &container){sort(container.begin(), container.end());}\ntemplate<typename Container>\n\
    inline void ReverseSort(Container &container){sort(container.rbegin(), container.rend());}\n\
    template<typename Container>\ninline void Reverse(Container &container){reverse(container.begin(),\
    \ container.end());}\ntemplate<typename Value>\ninline int PopCount(const Value\
    \ &value){return __builtin_popcount(value);}\ntemplate<typename Value>\ninline\
    \ Value Floor(Value numerator, Value denominator){if(denominator < 0) numerator\
    \ *= -1, denominator *= -1; return numerator < 0 ? (numerator + 1) / denominator\
    \ - 1 : numerator / denominator;}\ntemplate<typename Value>\ninline Value Ceil(Value\
    \ numerator, Value denominator){if(denominator < 0) numerator *= -1, denominator\
    \ *= -1; return numerator > 0 ? (numerator - 1) / denominator + 1 : numerator\
    \ / denominator;}\ntemplate<typename Value>\ninline int LowerBoundIndex(const\
    \ vector<Value> &container, const Value &value){return distance(container.begin(),\
    \ lower_bound(container.begin(), container.end(), value));}\ntemplate<typename\
    \ Value>\ninline int UpperBoundIndex(const vector<Value> &container, const Value\
    \ &value){return distance(container.begin(), upper_bound(container.begin(), container.end(),\
    \ value));}\ntemplate<typename Value>\ninline bool Between(const Value &lower,\
    \ const Value &x, const Value &higher){return lower <= x && x <= higher;}\ntemplate<typename\
    \ Value>\ninline bool InGrid(const Value &y, const Value &x, const Value &ymax,\
    \ const Value &xmax){return Between(0, y, ymax - 1) && Between(0, x, xmax - 1);}\n\
    template<typename Value>\ninline Value Median(const Value &a, const Value &b,\
    \ const Value &c){return Between(b, a, c) || Between(c, a, b) ? a : (Between(a,\
    \ b, c) || Between(c, b, a) ? b : c);}\ntemplate<typename Value>\ninline Value\
    \ Except(Value &src, Value &cond, Value &excp){return (src == cond ? excp : src);}\n\
    \ntemplate<class Value>\nbool chmin(Value &src, const Value &cmp){if(src > cmp){src\
    \ = cmp; return true;} return false;}\ntemplate<class Value>\nbool chmax(Value\
    \ &src, const Value &cmp){if(src < cmp){src = cmp; return true;} return false;}\n\
    template<typename Value>\ninline Value min(vector<Value> &v){return *min_element((v).begin(),\
    \ (v).end());}\ntemplate<typename Value>\ninline Value max(vector<Value> &v){return\
    \ *max_element((v).begin(), (v).end());}\n\nconst int dx4[4] = {1, 0, -1, 0};\n\
    const int dy4[4] = {0, -1, 0, 1};\nconst int dx8[8] = {1, 1, 0, -1, -1, -1, 0,\
    \ 1};\nconst int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};\n\nvector<pair<int, int>>\
    \ adjacent(int current_y, int current_x, int max_y, int max_x, bool dir_8 = false){\n\
    \    vector<pair<int, int>> ret;\n    for(int d = 0; d < 4 * (1 + dir_8); ++d){\n\
    \        int next_y = current_y + (dir_8 ? dy8[d] : dy4[d]);\n        int next_x\
    \ = current_x + (dir_8 ? dx8[d] : dx4[d]);\n        if(InGrid(next_y, next_x,\
    \ max_y, max_x)){\n            ret.emplace_back(next_y, next_x);\n        }\n\
    \    }\n    return ret;\n}\n\ntemplate <typename T1, typename T2>\nostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p){\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\n\ntemplate <typename T1, typename T2>\nistream &operator>>(istream &is,\
    \ pair<T1, T2> &p){\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, vector<T> &v){\n    for (int\
    \ i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1 != v.size() ? \" \"\
    \ : \"\");\n    }\n    return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, vector<vector<T>> &v){\n    for (int i = 0; i < v.size(); ++i){\n     \
    \   os << v[i] << (i + 1 != v.size() ? \"\\n\" : \"\");\n    }\n    return os;\n\
    }\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v){\n\
    \    for (int i = 0; i < v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, set<T> &v){\n    for (auto &u\
    \ : v){\n        os << u << \" \";\n    }\n    return os;\n}\n\ntemplate<typename\
    \ T1, typename T2>\nvector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2>\
    \ &v2){\n    assert(v1.size() == v2.size());\n    vector<pair<T1, T2>> v;\n  \
    \  for(int i = 0; i < v1.size(); ++i) v.push_back({v1[i], v2[i]});\n    return\
    \ v;\n}\n\ntemplate<typename T1, typename T2>\npair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1,\
    \ T2>> &v){\n    vector<T1> v1;\n    vector<T2> v2;\n    transform(v.begin(),\
    \ v.end(), back_inserter(v1), [](auto p){return p.first;});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v2), [](auto p){return p.second;});\n    return {v1,\
    \ v2};\n}\n\ntemplate<typename T1, typename T2, typename T3>\ntuple<vector<T1>,\
    \ vector<T2>, vector<T3>> DisassembleVectorTuple(vector<tuple<T1, T2, T3>> &v){\n\
    \    vector<T1> v1;\n    vector<T2> v2;\n    vector<T3> v3;\n    transform(v.begin(),\
    \ v.end(), back_inserter(v1), [](auto p){return get<0>(p);});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v2), [](auto p){return get<1>(p);});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v3), [](auto p){return get<2>(p);});\n    return {v1,\
    \ v2, v3};\n}\n\ntemplate<typename T1 = int, typename T2 = T1>\npair<vector<T1>,\
    \ vector<T2>> InputVectorPair(int size){\n    vector<pair<T1, T2>> v(size);\n\
    \    for(auto &[p, q] : v) cin >> p >> q;\n    return DisassembleVectorPair(v);\n\
    }\n\ntemplate<typename T1 = int, typename T2 = T1, typename T3 = T1>\ntuple<vector<T1>,\
    \ vector<T2>, vector<T3>> InputVectorTuple(int size){\n    vector<tuple<T1, T2,\
    \ T3>> v(size);\n    for(auto &[p, q, r] : v) cin >> p >> q >> r;\n    return\
    \ DisassembleVectorTuple(v);\n}\n#line 2 \"Library/Math/Montgomery.hpp\"\n\nstruct\
    \ Montgomery{\n    using mont = Montgomery;\n    using u64 = uint64_t;\n    using\
    \ u128 = __uint128_t;\n\n    static void SetMod(const u64 m){\n        assert(m\
    \ < (1LL << 62));\n        assert(m & 1);\n        mod = m;\n        inv_mod =\
    \ m;\n        for(int i = 0; i < 5; ++i){\n            inv_mod *= 2 - m * inv_mod;\n\
    \        }\n        r2 = -u128(m) % m;\n    }\n\n    u64 val;\n\n    Montgomery()\
    \ : val(0){}\n\n    Montgomery(long long x) : val(Reduct((u128(x) + mod) * r2)){}\n\
    \n    inline u64 Get() const {\n        u64 res = Reduct(val);\n        return\
    \ res >= mod ? res - mod : res;\n    }\n\n    mont &operator+=(const mont &r){\n\
    \        if((val += r.val) >= 2 * mod) val -= 2 * mod;\n        return (*this);\n\
    \    }\n\n    mont &operator-=(const mont &r){\n        if((val += 2 * mod - r.val)\
    \ >= 2 * mod) val -= 2 * mod;\n        return (*this);\n    }\n\n    mont &operator*=(const\
    \ mont &r){\n        val = Reduct(u128(val) * r.val);\n        return (*this);\n\
    \    }\n\n    mont &operator/=(const mont &r){\n        (*this) *= r.Inverse();\n\
    \        return (*this);\n    }\n\n    mont Inverse() const {\n        return\
    \ Power(mod - 2);\n    }\n\n    mont Power(long long k) const {\n        mont\
    \ ret(1), mul(*this);\n        while(k){\n            if(k & 1) ret *= mul;\n\
    \            mul *= mul;\n            k >>= 1;\n        }\n        return ret;\n\
    \    }\n\n    mont operator-() const {\n        return mont() - mont(*this);\n\
    \    }\n\n    mont operator+(const mont &r) const {\n        return mont(*this)\
    \ += r;\n    }\n\n    mont operator-(const mont &r) const {\n        return mont(*this)\
    \ -= r;\n    }\n\n    mont operator*(const mont &r) const {\n        return mont(*this)\
    \ *= r;\n    }\n\n    bool operator==(const mont &r) const {\n        return (val\
    \ >= mod ? val - mod : val) == (r.val >= mod ? r.val - mod : r.val);\n    }\n\n\
    \    bool operator!=(const mont &r) const {\n        return (val >= mod ? val\
    \ - mod : val) != (r.val >= mod ? r.val - mod : r.val);\n    }\n\n    private:\n\
    \    static u64 mod;\n    static u64 inv_mod;\n    static u64 r2;\n\n    static\
    \ u64 Reduct(const u128 x){\n        return (x + u128(u64(x) * u64(-inv_mod))\
    \ * mod) >> 64;\n    }\n};\n\ntypename Montgomery::u64 Montgomery::mod, Montgomery::inv_mod,\
    \ Montgomery::r2;\n#line 2 \"Library/Math/MillerRabin.hpp\"\n\nbool MillerRabin(const\
    \ long long N){\n    if(N <= 1) return false;\n    if(N == 2) return true;\n \
    \   if(!(N & 1)) return false;\n    vector<long long> as;\n    if(N < 4759123141LL)\
    \ as = {2, 7, 61};\n    else as = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\
    \    Montgomery::SetMod(N);\n    long long s = 0, d = N - 1;\n    while(!(d &\
    \ 1)) ++s, d >>= 1;\n    for(const auto &a : as){\n        Montgomery x = Montgomery(a).Power(d);\n\
    \        if(x != 1 && x != 0){\n            long long t;\n            for(t =\
    \ 0; t < s; ++t){\n                if(x == N - 1) break;\n                x *=\
    \ x;\n            }\n            if(t == s) return false;\n        }\n    }\n\
    \    return true;\n}\n#line 5 \"verify/LC-PrimalityTest.test.cpp\"\n\nint main(){\n\
    \    cin.tie(0)->sync_with_stdio(false);\n    int Q; cin >> Q;\n    while(Q--){\n\
    \        long long N; cin >> N;\n        YnPrint(MillerRabin(N));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ \"../Library/Template.hpp\"\n#include \"../Library/Math/MillerRabin.hpp\"\n\n\
    int main(){\n    cin.tie(0)->sync_with_stdio(false);\n    int Q; cin >> Q;\n \
    \   while(Q--){\n        long long N; cin >> N;\n        YnPrint(MillerRabin(N));\n\
    \    }\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/Math/MillerRabin.hpp
  - Library/Math/Montgomery.hpp
  isVerificationFile: true
  path: verify/LC-PrimalityTest.test.cpp
  requiredBy: []
  timestamp: '2026-06-01 15:49:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-PrimalityTest.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-PrimalityTest.test.cpp
- /verify/verify/LC-PrimalityTest.test.cpp.html
title: verify/LC-PrimalityTest.test.cpp
---
