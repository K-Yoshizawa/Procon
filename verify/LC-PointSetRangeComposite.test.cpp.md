---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/SegmentTree.hpp
    title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: library/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/LC-PointSetRangeComposite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#line 1 \"\
    library/DataStructure/SegmentTree.hpp\"\n/**\n * @file SegmentTree.hpp\n * @author\
    \ log K (lX57)\n * @brief Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n\
    \ * @version 2.2\n * @date 2023-10-02\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate<typename Monoid>\nstruct SegmentTree{\n    private:\n\
    \    using F = function<Monoid(Monoid, Monoid)>;\n\n    int size_, offset_, zeroindex_;\n\
    \    vector<Monoid> data_;\n    const F f;\n    const Monoid m1_;\n\n    inline\
    \ void check_(int x){\n        assert(1 <= x && x <= size_);\n    }\n\n    public:\n\
    \    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\
    \u6570 `Size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Size \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\n     * @param Merge \u533A\
    \u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param Monoid_Identity\
    \ \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\
    \u3057\u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(int\
    \ Size, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\n    :\
    \ f(Merge), m1_(Monoid_Identity), zeroindex_(ZeroIndex){\n        size_ = 1;\n\
    \        while(size_ < Size) size_ <<= 1;\n        offset_ = size_ - 1;\n    \
    \    data_.resize(2 * size_, m1_);\n    }\n\n    /**\n     * @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention\
    \ \u5FC5\u305A `set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\
    \u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n     */\n    void build(){\n\
    \        for(int i = offset_; i >= 1; --i){\n            data_[i] = f(data_[i\
    \ * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\
    \u308B\u3002\n     * @param Index \u4EE3\u5165\u5148\u306E\u8981\u7D20\u756A\u53F7\
    \ (default = 1-index)\n     * @param Value \u4EE3\u5165\u3059\u308B\u5024\n  \
    \   */\n    void set(int Index, Monoid Value){\n        check_(Index + zeroindex_);\n\
    \        data_[offset_ + Index + zeroindex_] = Value;\n    }\n\n    /**\n    \
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u914D\u5217 `Init_Data`\
    \ \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Init_Data \u521D\u671F\
    \u30C7\u30FC\u30BF\u306E\u914D\u5217\n     * @param Merge \u533A\u9593\u53D6\u5F97\
    \u3092\u884C\u3046\u6F14\u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\
    \u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\
    \u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    SegmentTree(vector<Monoid>\
    \ &Init_Data, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\n\
    \    : f(Merge), m1_(Monoid_Identity), zeroindex_(ZeroIndex){\n        size_ =\
    \ 1;\n        while(size_ < (int)Init_Data.size()) size_ <<= 1;\n        offset_\
    \ = size_ - 1;\n        data_.resize(2 * size_, m1_);\n        for(int i = 0;\
    \ i < (int)Init_Data.size(); ++i){\n            data_[size_ + i] = Init_Data[i];\n\
    \        }\n        build();\n    }\n\n    /**\n     * @brief \u4E00\u70B9\u66F4\
    \u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\n     * @param Index\
    \ \u66F4\u65B0\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     *\
    \ @param Value \u66F4\u65B0\u3059\u308B\u5024\n     */\n    void update(int Index,\
    \ Monoid Value){\n        check_(Index + zeroindex_);\n        int k = offset_\
    \ + Index + zeroindex_;\n        data_[k] = Value;\n        while(k >>= 1){\n\
    \            data_[k] = f(data_[2 * k], data_[2 * k + 1]);\n        }\n    }\n\
    \n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[Left, Right)` \u306B\u5BFE\
    \u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\u884C\u3046\u3002\
    \n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n     * @param\
    \ Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return Monoid \u53D6\
    \u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid query(int Left, int Right){\n\
    \        if(Left == Right) return m1_;\n        check_(Left + zeroindex_);\n \
    \       check_(Right + zeroindex_ - 1);\n        int l = Left + zeroindex_ + offset_,\
    \ r = Right + zeroindex_ + offset_;\n        Monoid al = m1_, ar = m1_;\n    \
    \    while(l < r){\n            if(l & 1) al = f(al, data_[l++]);\n          \
    \  if(r & 1) ar = f(data_[--r], ar);\n            l >>= 1, r >>= 1;\n        }\n\
    \        return f(al, ar);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u756A\
    \u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param\
    \ k \u53D6\u5F97\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n   \
    \  * @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid\
    \ get(int k){\n        check_(k + zeroindex_);\n        return data_[offset_ +\
    \ k + zeroindex_];\n    }\n\n    Monoid operator[](const int &k){\n        return\
    \ get(k);\n    }\n};\n#line 2 \"library/modint.hpp\"\n/**\n * @file modint.hpp\n\
    \ * @author log K (lX57)\n * @brief modint\n * @version 1.0\n * @date 2023-08-24\n\
    \ */\n\n#line 11 \"library/modint.hpp\"\nusing namespace std;\n\nconst int mod998\
    \ = 998244353;\nconst int mod107 = 1000000007;\n\ntemplate< int mod >\nstruct\
    \ ModInt {\n    int x;\n\n    ModInt() : x(0) {}\n\n    ModInt(int64_t y) : x(y\
    \ >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n    ModInt &operator+=(const\
    \ ModInt &p) {\n        if((x += p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n\n    ModInt &operator-=(const ModInt &p) {\n        if((x += mod - p.x)\
    \ >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (int) (1LL * x * p.x % mod);\n        return *this;\n\
    \    }\n\n    ModInt &operator/=(const ModInt &p) {\n        *this *= p.inverse();\n\
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
    \ >;\nusing vvm107 = vector< vector< modint107 > >;\n#line 5 \"verify/LC-PointSetRangeComposite.test.cpp\"\
    \n\nstruct Data{\n    modint998 a, b;\n\n    Data() : a(1), b(0){}\n    Data(int\
    \ a, int b) : a(a), b(b){} \n\n    static Data op(const Data& left, const Data&\
    \ right){\n        Data res;\n        res.a = left.a * right.a;\n        res.b\
    \ = right.a * left.b + right.b;\n        return res;\n    }\n};\n\nint main(){\n\
    \    int N, Q; cin >> N >> Q;\n    vector<Data> Init_Data;\n    for(int i = 0;\
    \ i < N; ++i){\n        int a, b; cin >> a >> b;\n        Init_Data.push_back(Data(a,\
    \ b));\n    }\n    SegmentTree<Data> seg(Init_Data, [](Data l, Data r){return\
    \ Data::op(l, r);}, Data(), true);\n    while(Q--){\n        int q; cin >> q;\n\
    \        if(q == 0){\n            int p, c, d; cin >> p >> c >> d;\n         \
    \   seg.update(p, Data(c, d));\n        }\n        if(q == 1){\n            int\
    \ l, r, x; cin >> l >> r >> x;\n            Data ret = seg.query(l, r);\n    \
    \        cout << ret.a * x + ret.b << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../library/DataStructure/SegmentTree.hpp\"\n#include \"../library/modint.hpp\"\
    \n\nstruct Data{\n    modint998 a, b;\n\n    Data() : a(1), b(0){}\n    Data(int\
    \ a, int b) : a(a), b(b){} \n\n    static Data op(const Data& left, const Data&\
    \ right){\n        Data res;\n        res.a = left.a * right.a;\n        res.b\
    \ = right.a * left.b + right.b;\n        return res;\n    }\n};\n\nint main(){\n\
    \    int N, Q; cin >> N >> Q;\n    vector<Data> Init_Data;\n    for(int i = 0;\
    \ i < N; ++i){\n        int a, b; cin >> a >> b;\n        Init_Data.push_back(Data(a,\
    \ b));\n    }\n    SegmentTree<Data> seg(Init_Data, [](Data l, Data r){return\
    \ Data::op(l, r);}, Data(), true);\n    while(Q--){\n        int q; cin >> q;\n\
    \        if(q == 0){\n            int p, c, d; cin >> p >> c >> d;\n         \
    \   seg.update(p, Data(c, d));\n        }\n        if(q == 1){\n            int\
    \ l, r, x; cin >> l >> r >> x;\n            Data ret = seg.query(l, r);\n    \
    \        cout << ret.a * x + ret.b << endl;\n        }\n    }\n}\n"
  dependsOn:
  - library/DataStructure/SegmentTree.hpp
  - library/modint.hpp
  isVerificationFile: true
  path: verify/LC-PointSetRangeComposite.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 18:47:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-PointSetRangeComposite.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-PointSetRangeComposite.test.cpp
- /verify/verify/LC-PointSetRangeComposite.test.cpp.html
title: verify/LC-PointSetRangeComposite.test.cpp
---
