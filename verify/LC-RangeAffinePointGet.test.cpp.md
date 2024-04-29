---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/DualSegmentTree.hpp
    title: "Dual Segment Tree - \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"verify/LC-RangeAffinePointGet.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\n#line 2 \"library/modint.hpp\"\
    \n/**\n * @file modint.hpp\n * @author log K (lX57)\n * @brief modint\n * @version\
    \ 1.0\n * @date 2023-08-24\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nconst int mod998 = 998244353;\nconst int mod107 = 1000000007;\n\ntemplate< int\
    \ mod >\nstruct ModInt {\n    int x;\n\n    ModInt() : x(0) {}\n\n    ModInt(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n    ModInt &operator+=(const\
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
    \ >;\nusing vvm107 = vector< vector< modint107 > >;\n#line 1 \"library/DataStructure/DualSegmentTree.hpp\"\
    \n/**\n * @file DualSegmentTree.hpp\n * @author log K (lX57)\n * @brief Dual Segment\
    \ Tree - \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @version 1.0\n *\
    \ @date 2023-11-08\n */\n\n#line 10 \"library/DataStructure/DualSegmentTree.hpp\"\
    \nusing namespace std;\n\ntemplate<typename OperatorMonoid>\nstruct DualSegmentTree{\n\
    \    private:\n    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n\
    \n    int size_, offset_, zeroindex_;\n    vector<OperatorMonoid> lazy_;\n   \
    \ const H h;\n    const OperatorMonoid om1_;\n\n    inline void check_(int x){\n\
    \        assert(1 <= x && x <= size_);\n    }\n\n    void eval_(int k){\n    \
    \    if(lazy_[k] == om1_) return;\n        if(k < size_){\n            lazy_[k\
    \ * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);\n            lazy_[k * 2 + 1] = h(lazy_[k\
    \ * 2 + 1], lazy_[k]);\n            lazy_[k] = om1_;\n        }\n    }\n\n   \
    \ void update_(int ul, int ur, OperatorMonoid x, int left, int right, int cell){\n\
    \        eval_(cell);\n        if(ul <= left && right <= ur){\n            lazy_[cell]\
    \ = h(lazy_[cell], x);\n            eval_(cell);\n        }\n        else if(ul\
    \ < right && left < ur){\n            int mid = (left + right) / 2;\n        \
    \    update_(ul, ur, x, left, mid, cell * 2 + 0);\n            update_(ul, ur,\
    \ x, mid, right, cell * 2 + 1);\n        }\n    }\n    \n    OperatorMonoid query_(int\
    \ k, int left, int right, int cell){\n        eval_(cell);\n        if(k == left\
    \ && right - left == 1) return lazy_[cell];\n        int mid = (left + right)\
    \ / 2;\n        if(k < mid) return query_(k, left, mid, cell * 2 + 0);\n     \
    \   else return query_(k, mid, right, cell * 2 + 1);\n    }\n\n    public:\n \
    \   /**\n     * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\
    \u7D20\u6570 `Size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param\
    \ Size \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\
    \n     * @param Composite \u9045\u5EF6\u8A55\u4FA1\u306E\u5408\u6210\u3092\u884C\
    \u3046\u6F14\u7B97\n     * @param OperatorMonoid_Identity \u64CD\u4F5C\u30E2\u30CE\
    \u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\u3057\
    \u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    DualSegmentTree(int\
    \ Size, H Composite,\n    const OperatorMonoid &OperatorMonoid_Identity, bool\
    \ ZeroIndex = false)\n    : h(Composite), om1_(OperatorMonoid_Identity), zeroindex_(ZeroIndex){\n\
    \        size_ = 1;\n        while(size_ < Size) size_ <<= 1;\n        offset_\
    \ = size_ - 1;\n        lazy_.resize(2 * size_, om1_);\n    }\n    \n    /**\n\
    \     * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\
    \u6570 `Size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Init_Data\
    \ \u521D\u671F\u30C7\u30FC\u30BF\u306E\u914D\u5217\n     * @param Composite \u9045\
    \u5EF6\u8A55\u4FA1\u306E\u5408\u6210\u3092\u884C\u3046\u6F14\u7B97\n     * @param\
    \ OperatorMonoid_Identity \u64CD\u4F5C\u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B (default = `false`)\n     */\n    DualSegmentTree(vector<OperatorMonoid>\
    \ &Init_Data, H Composite,\n    const OperatorMonoid &OperatorMonoid_Identity,\
    \ bool ZeroIndex = false)\n    : h(Composite), om1_(OperatorMonoid_Identity),\
    \ zeroindex_(ZeroIndex){\n        size_ = 1;\n        while(size_ < (int)Init_Data.size())\
    \ size_ <<= 1;\n        offset_ = size_ - 1;\n        lazy_.resize(2 * size_,\
    \ om1_);\n        for(int i = 0; i < (int)Init_Data.size(); ++i){\n          \
    \  lazy_[size_ + i] = Init_Data[i];\n        }\n    }\n\n    /**\n     * @brief\
    \ \u534A\u958B\u533A\u9593 `[Left, Right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\
    \u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\n     * @param\
    \ Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n     * @param Right \u534A\u958B\
    \u533A\u9593\u306E\u53F3\u7AEF\n     * @param OP \u66F4\u65B0\u64CD\u4F5C\n  \
    \   */\n    void update(int Left, int Right, OperatorMonoid OP){\n        check_(Left\
    \ + zeroindex_);\n        check_(Right + zeroindex_ - 1);\n        update_(Left\
    \ + zeroindex_, Right + zeroindex_, OP, 1, size_ + 1, 1);\n    }\n\n    /**\n\
    \     * @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\u5F97\
    \u3059\u308B\u3002\n     * @param k \u53D6\u5F97\u5148\u306E\u8981\u7D20\u756A\
    \u53F7 (default = 1-index)\n     * @return OperatorMonoid \u53D6\u5F97\u3057\u305F\
    \u7D50\u679C\n     */\n    OperatorMonoid query(int k){\n        check_(k + zeroindex_);\n\
    \        return query_(k + zeroindex_, 1, size_ + 1, 1);\n    }\n\n    OperatorMonoid\
    \ operator[](const int &k){\n        return query(k);\n    }\n};\n#line 5 \"verify/LC-RangeAffinePointGet.test.cpp\"\
    \n\nstruct Monoid{\n    modint998 b, c;\n\n    Monoid() : b(1), c(0) {}\n    Monoid(modint998\
    \ b, modint998 c) : b(b), c(c) {}\n\n    bool operator==(const Monoid &r){\n \
    \       return b == r.b and c == r.c;\n    }\n\n    static Monoid Composite(Monoid\
    \ l, Monoid r){\n        return Monoid(l.b * r.b, r.b * l.c + r.c);\n    }\n};\n\
    \nint main(){\n    int N, Q; cin >> N >> Q;\n    vm998 a(N);\n    for(int i =\
    \ 0; i < N; ++i) cin >> a[i];\n\n    DualSegmentTree<Monoid> seg(N,\n        [&](Monoid\
    \ l, Monoid r){return Monoid::Composite(l, r);},\n        Monoid(), true);\n \
    \   \n    while(Q--){\n        int query; cin >> query;\n        if(query == 0){\n\
    \            int l, r, b, c; cin >> l >> r >> b >> c;\n            seg.update(l,\
    \ r, Monoid(b, c));\n        }\n        else{\n            int i; cin >> i;\n\
    \            Monoid ret = seg[i];\n            cout << ret.b * a[i] + ret.c <<\
    \ endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include \"../library/modint.hpp\"\n#include \"../library/DataStructure/DualSegmentTree.hpp\"\
    \n\nstruct Monoid{\n    modint998 b, c;\n\n    Monoid() : b(1), c(0) {}\n    Monoid(modint998\
    \ b, modint998 c) : b(b), c(c) {}\n\n    bool operator==(const Monoid &r){\n \
    \       return b == r.b and c == r.c;\n    }\n\n    static Monoid Composite(Monoid\
    \ l, Monoid r){\n        return Monoid(l.b * r.b, r.b * l.c + r.c);\n    }\n};\n\
    \nint main(){\n    int N, Q; cin >> N >> Q;\n    vm998 a(N);\n    for(int i =\
    \ 0; i < N; ++i) cin >> a[i];\n\n    DualSegmentTree<Monoid> seg(N,\n        [&](Monoid\
    \ l, Monoid r){return Monoid::Composite(l, r);},\n        Monoid(), true);\n \
    \   \n    while(Q--){\n        int query; cin >> query;\n        if(query == 0){\n\
    \            int l, r, b, c; cin >> l >> r >> b >> c;\n            seg.update(l,\
    \ r, Monoid(b, c));\n        }\n        else{\n            int i; cin >> i;\n\
    \            Monoid ret = seg[i];\n            cout << ret.b * a[i] + ret.c <<\
    \ endl;\n        }\n    }\n}"
  dependsOn:
  - library/modint.hpp
  - library/DataStructure/DualSegmentTree.hpp
  isVerificationFile: true
  path: verify/LC-RangeAffinePointGet.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 18:47:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-RangeAffinePointGet.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-RangeAffinePointGet.test.cpp
- /verify/verify/LC-RangeAffinePointGet.test.cpp.html
title: verify/LC-RangeAffinePointGet.test.cpp
---
