---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/DualSegmentTree.hpp
    title: "Dual Segment Tree - \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: Library/modint.hpp
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
    \ \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\n#line 2 \"Library/Template.hpp\"\
    \n\n/**\n * @file Template.hpp\n * @author log K (lX57)\n * @brief Template -\
    \ \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 1.10\n * @date 2025-03-16\n\
    \ */\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file Common.hpp\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (1LL << 30) -\
    \ 1;\n#line 12 \"Library/Template.hpp\"\n\ninline bool YnPrint(bool flag){cout\
    \ << (flag ? \"Yes\" : \"No\") << '\\n'; return flag;}\ninline bool YNPrint(bool\
    \ flag){cout << (flag ? \"YES\" : \"NO\") << '\\n'; return flag;}\ntemplate<typename\
    \ Container>\ninline void Sort(Container &container){sort(container.begin(), container.end());}\n\
    template<typename Container>\ninline void ReverseSort(Container &container){sort(container.rbegin(),\
    \ container.rend());}\ntemplate<typename Container>\ninline void Reverse(Container\
    \ &container){reverse(container.begin(), container.end());}\ntemplate<typename\
    \ Value>\ninline int PopCount(const Value &value){return __builtin_popcount(value);}\n\
    template<typename Value>\ninline Value Ceil(const Value &numerator, const Value\
    \ &denominator){return (numerator + denominator - 1) / denominator;}\ntemplate<typename\
    \ Value>\ninline int LowerBoundIndex(const vector<Value> &container, const Value\
    \ &value){return distance(container.begin(), lower_bound(container.begin(), container.end(),\
    \ value));}\ntemplate<typename Value>\ninline int UpperBoundIndex(const vector<Value>\
    \ &container, const Value &value){return distance(container.begin(), upper_bound(container.begin(),\
    \ container.end(), value));}\ntemplate<typename Value>\ninline bool Between(const\
    \ Value &lower, const Value &x, const Value &higher){return lower <= x && x <=\
    \ higher;}\ntemplate<typename Value>\ninline bool InGrid(const Value &y, const\
    \ Value &x, const Value &ymax, const Value &xmax){return Between(0, y, ymax -\
    \ 1) && Between(0, x, xmax - 1);}\ntemplate<typename Value>\ninline Value Median(const\
    \ Value &a, const Value &b, const Value &c){return Between(b, a, c) || Between(c,\
    \ a, b) ? a : (Between(a, b, c) || Between(c, b, a) ? b : c);}\ntemplate<typename\
    \ Value>\ninline Value Except(Value &src, Value &cond, Value &excp){return (src\
    \ == cond ? excp : src);}\n\ntemplate<class Value>\nbool chmin(Value &src, const\
    \ Value &cmp){if(src > cmp){src = cmp; return true;} return false;}\ntemplate<class\
    \ Value>\nbool chmax(Value &src, const Value &cmp){if(src < cmp){src = cmp; return\
    \ true;} return false;}\ntemplate<typename Value>\ninline Value min(vector<Value>\
    \ &v){return *min_element((v).begin(), (v).end());}\ntemplate<typename Value>\n\
    inline Value max(vector<Value> &v){return *max_element((v).begin(), (v).end());}\n\
    \nconst int dx4[4] = {1, 0, -1, 0};\nconst int dy4[4] = {0, -1, 0, 1};\nconst\
    \ int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};\nconst int dy8[8] = {0, -1, -1, -1,\
    \ 0, 1, 1, 1};\n\nvector<pair<int, int>> adjacent(int current_y, int current_x,\
    \ int max_y, int max_x, bool dir_8 = false){\n    vector<pair<int, int>> ret;\n\
    \    for(int d = 0; d < 4 * (1 + dir_8); ++d){\n        int next_y = current_y\
    \ + (dir_8 ? dy8[d] : dy4[d]);\n        int next_x = current_x + (dir_8 ? dx8[d]\
    \ : dx4[d]);\n        if(InGrid(next_y, next_x, max_y, max_x)){\n            ret.emplace_back(next_y,\
    \ next_x);\n        }\n    }\n    return ret;\n}\n\ntemplate <typename T1, typename\
    \ T2>\nostream &operator<<(ostream &os, const pair<T1, T2> &p){\n    os << p.first\
    \ << \" \" << p.second;\n    return os;\n}\n\ntemplate <typename T1, typename\
    \ T2>\nistream &operator>>(istream &is, pair<T1, T2> &p){\n    is >> p.first >>\
    \ p.second;\n    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, vector<T> &v){\n    for (int i = 0; i < v.size(); ++i){\n        os <<\
    \ v[i] << (i + 1 != v.size() ? \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, vector<vector<T>> &v){\n    for\
    \ (int i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1 != v.size() ?\
    \ \"\\n\" : \"\");\n    }\n    return os;\n}\n\ntemplate <typename T>\nistream\
    \ &operator>>(istream &is, vector<T> &v){\n    for (int i = 0; i < v.size(); ++i)\
    \ is >> v[i];\n    return is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, set<T> &v){\n    for (auto &u : v){\n        os << u << \" \";\n    }\n\
    \    return os;\n}\n\ntemplate<typename T1, typename T2>\nvector<pair<T1, T2>>\
    \ AssembleVectorPair(vector<T1> &v1, vector<T2> &v2){\n    assert(v1.size() ==\
    \ v2.size());\n    vector<pair<T1, T2>> v;\n    for(int i = 0; i < v1.size();\
    \ ++i) v.push_back({v1[i], v2[i]});\n    return v;\n}\n\ntemplate<typename T1,\
    \ typename T2>\npair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1,\
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
    \ DisassembleVectorTuple(v);\n}\n#line 2 \"Library/modint.hpp\"\n\n/**\n * @file\
    \ modint.hpp\n * @author log K (lX57)\n * @brief modint\n * @version 1.0\n * @date\
    \ 2023-08-24\n */\n\n#line 12 \"Library/modint.hpp\"\nusing namespace std;\n\n\
    const int mod998 = 998244353;\nconst int mod107 = 1000000007;\n\ntemplate< int\
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
    \    }\n\n    static int get_mod() { return mod; }\n};\n\nusing mint = ModInt<mod998>;\n\
    using mint107 = ModInt<mod107>;\n\nusing vm = vector<mint>;\nusing vvm = vector<vector<mint>>;\n\
    using vm107 = vector<mint107>;\nusing vvm107 = vector<vector<mint107>>;\n#line\
    \ 1 \"Library/DataStructure/DualSegmentTree.hpp\"\n/**\n * @file DualSegmentTree.hpp\n\
    \ * @brief Dual Segment Tree - \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n * @version 2.0\n * @date 2024-11-29\n */\n\n#line 9 \"Library/DataStructure/DualSegmentTree.hpp\"\
    \n\ntemplate<typename OperatorMonoid>\nclass DualSegmentTree{\n    public:\n \
    \   using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n    \n\
    \    DualSegmentTree(int size, H composite, const OperatorMonoid &operator_identity,\
    \ bool zero_index = false)\n    : h(composite), om1_(operator_identity), zeroindex_(zero_index){\n\
    \        size_ = 1;\n        while(size_ < size) size_ <<= 1;\n        offset_\
    \ = size_ - 1;\n        lazy_.resize(2 * size_, om1_);\n        is_identity_.resize(2\
    \ * size_, true);\n    }\n\n    void Set(int index, OperatorMonoid value){\n \
    \       Validate(index + zeroindex_);\n        lazy_[offset_ + index + zeroindex_]\
    \ = value;\n    }\n\n    void Update(int left, int right, OperatorMonoid operation){\n\
    \        Validate(left + zeroindex_);\n        Validate(right + zeroindex_ - 1);\n\
    \        RecursiveUpdate(left + zeroindex_, right + zeroindex_, operation, 1,\
    \ size_ + 1, 1);\n    }\n\n    OperatorMonoid Query(int index){\n        Validate(index\
    \ + zeroindex_);\n        return RecursiveQuery(index + zeroindex_, 1, size_ +\
    \ 1, 1);\n    }\n\n    private:\n    int size_, offset_, zeroindex_;\n    vector<OperatorMonoid>\
    \ lazy_;\n    vector<bool> is_identity_;\n    const H h;\n    const OperatorMonoid\
    \ om1_;\n\n    inline void Validate(int x){\n        assert(1 <= x && x <= size_);\n\
    \    }\n\n    void Evaluate(int k){\n        if(is_identity_[k]) return;\n   \
    \     if(k < size_){\n            lazy_[k * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);\n\
    \            is_identity_[k * 2 + 0] = false;\n            lazy_[k * 2 + 1] =\
    \ h(lazy_[k * 2 + 1], lazy_[k]);\n            is_identity_[k * 2 + 1] = false;\n\
    \            lazy_[k] = om1_;\n            is_identity_[k] = true;\n        }\n\
    \    }\n\n    void RecursiveUpdate(int ul, int ur, OperatorMonoid x, int left,\
    \ int right, int cell){\n        Evaluate(cell);\n        if(ul <= left && right\
    \ <= ur){\n            lazy_[cell] = h(lazy_[cell], x);\n            is_identity_[cell]\
    \ = false;\n            Evaluate(cell);\n        }\n        else if(ul < right\
    \ && left < ur){\n            int mid = (left + right) / 2;\n            RecursiveUpdate(ul,\
    \ ur, x, left, mid, cell * 2 + 0);\n            RecursiveUpdate(ul, ur, x, mid,\
    \ right, cell * 2 + 1);\n        }\n    }\n    \n    OperatorMonoid RecursiveQuery(int\
    \ q, int left, int right, int cell){\n        Evaluate(cell);\n        if(q ==\
    \ left && right - left == 1) return lazy_[cell];\n        int mid = (left + right)\
    \ / 2;\n        if(q < mid) return RecursiveQuery(q, left, mid, cell * 2 + 0);\n\
    \        else return RecursiveQuery(q, mid, right, cell * 2 + 1);\n    }\n};\n\
    #line 6 \"verify/LC-RangeAffinePointGet.test.cpp\"\n\nstruct OperatorMonoid{\n\
    \    mint b, c;\n    OperatorMonoid(mint b_ = 1, mint c_ = 0) : b(b_), c(c_){}\n\
    \    static OperatorMonoid Composite(OperatorMonoid &l, OperatorMonoid &r){\n\
    \        return OperatorMonoid(r.b * l.b, r.b * l.c + r.c);\n    }\n};\n\nint\
    \ main(){\n    int N, Q; cin >> N >> Q;\n    vector<mint> a(N); cin >> a;\n\n\
    \    DualSegmentTree<OperatorMonoid> seg(\n        N,\n        [](OperatorMonoid\
    \ l, OperatorMonoid r){return OperatorMonoid::Composite(l, r);},\n        OperatorMonoid(),\n\
    \        true\n    );\n    while(Q--){\n        int t; cin >> t;\n        if(t\
    \ == 0){\n            int l, r, b, c; cin >> l >> r >> b >> c;\n            seg.Update(l,\
    \ r, OperatorMonoid(b, c));\n        }\n        else{\n            int i; cin\
    \ >> i;\n            OperatorMonoid op = seg.Query(i);\n            cout << op.b\
    \ * a[i] + op.c << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/modint.hpp\"\n\
    #include \"../Library/DataStructure/DualSegmentTree.hpp\"\n\nstruct OperatorMonoid{\n\
    \    mint b, c;\n    OperatorMonoid(mint b_ = 1, mint c_ = 0) : b(b_), c(c_){}\n\
    \    static OperatorMonoid Composite(OperatorMonoid &l, OperatorMonoid &r){\n\
    \        return OperatorMonoid(r.b * l.b, r.b * l.c + r.c);\n    }\n};\n\nint\
    \ main(){\n    int N, Q; cin >> N >> Q;\n    vector<mint> a(N); cin >> a;\n\n\
    \    DualSegmentTree<OperatorMonoid> seg(\n        N,\n        [](OperatorMonoid\
    \ l, OperatorMonoid r){return OperatorMonoid::Composite(l, r);},\n        OperatorMonoid(),\n\
    \        true\n    );\n    while(Q--){\n        int t; cin >> t;\n        if(t\
    \ == 0){\n            int l, r, b, c; cin >> l >> r >> b >> c;\n            seg.Update(l,\
    \ r, OperatorMonoid(b, c));\n        }\n        else{\n            int i; cin\
    \ >> i;\n            OperatorMonoid op = seg.Query(i);\n            cout << op.b\
    \ * a[i] + op.c << endl;\n        }\n    }\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/modint.hpp
  - Library/DataStructure/DualSegmentTree.hpp
  isVerificationFile: true
  path: verify/LC-RangeAffinePointGet.test.cpp
  requiredBy: []
  timestamp: '2025-03-20 00:50:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-RangeAffinePointGet.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-RangeAffinePointGet.test.cpp
- /verify/verify/LC-RangeAffinePointGet.test.cpp.html
title: verify/LC-RangeAffinePointGet.test.cpp
---
