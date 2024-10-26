---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/SegmentTree.hpp
    title: "Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"verify/AOJ-DSL-2-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#line 2 \"Library/Template.hpp\"\n\n/**\n * @file Template.hpp\n * @author\
    \ log K (lX57)\n * @brief Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n *\
    \ @version 1.9\n * @date 2024-10-27\n */\n\n#line 2 \"Library/Common.hpp\"\n\n\
    /**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n#line 12 \"Library/Template.hpp\"\n#define ALL(x) (x).begin(),\
    \ (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define SORT(x) sort(ALL(x))\n\
    #define RSORT(x) sort(RALL(x))\n#define REVERSE(x) reverse(ALL(x))\n#define SETPRE(digit)\
    \ fixed << setprecision(digit)\n#define POPCOUNT(x) __builtin_popcount(x)\n#define\
    \ SUM(x) reduce((x).begin(), (x).end())\n#define CEIL(nume, deno) ((nume) + (deno)\
    \ - 1) / (deno)\n#define IOTA(x) iota((x).begin(), (x).end(), 0)\n#define LOWERBOUND_IDX(arr,\
    \ val) distance((arr).begin(), lower_bound((arr).begin(), (arr).end(), val))\n\
    #define UPPERBOUND_IDX(arr, val) distance((arr).begin(), upper_bound((arr).begin(),\
    \ (arr).end(), val))\n\ninline string Yn(bool flag){return (flag) ? \"Yes\" :\
    \ \"No\";}\ninline bool YnPrint(bool flag){cout << Yn(flag) << endl;return flag;}\n\
    inline string YN(bool flag){return (flag) ? \"YES\" : \"NO\";}\ninline bool YNPrint(bool\
    \ flag){cout << YN(flag) << endl;return flag;}\ntemplate<class T>\nbool chmin(T\
    \ &src, const T &cmp){if(src > cmp){src = cmp; return true;}return false;}\ntemplate<class\
    \ T>\nbool chmax(T &src, const T &cmp){if(src < cmp){src = cmp; return true;}return\
    \ false;}\ntemplate<typename T>\ninline bool between(T min, T x, T max){return\
    \ min <= x && x <= max;}\ntemplate<typename T>\ninline bool ingrid(T y, T x, T\
    \ ymax, T xmax){return between(0, y, ymax - 1) && between(0, x, xmax - 1);}\n\
    template<typename T>\ninline T median(T a, T b, T c){return between(b, a, c) ||\
    \ between(c, a, b) ? a : (between(a, b, c) || between(c, b, a) ? b : c);}\ntemplate<typename\
    \ T>\ninline T except(T src, T cond, T excp){return (src == cond ? excp : src);}\n\
    template<typename T>\ninline T min(vector<T> &v){return *min_element((v).begin(),\
    \ (v).end());}\ntemplate<typename T>\ninline T max(vector<T> &v){return *max_element((v).begin(),\
    \ (v).end());}\nvector<int> make_sequence(int Size){\n    vector<int> ret(Size);\n\
    \    IOTA(ret);\n    return ret;\n}\ntemplate<typename T>\nvoid make_unique(vector<T>\
    \ &v){\n    sort(v.begin(), v.end());\n    auto itr = unique(v.begin(), v.end());\n\
    \    v.erase(itr, v.end());\n}\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\
    using ld = long double;\n\nconst int INF_INT = numeric_limits<int>::max() >> 2;\n\
    const ll INF_LL = numeric_limits<ll>::max() >> 2;\n\nusing vi = vector<int>;\n\
    using vvi = vector<vi>;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing\
    \ pi = pair<int, int>;\nusing pl = pair<ll, ll>;\nusing vs = vector<string>;\n\
    template <typename T>\nusing pq = priority_queue<T>;\ntemplate <typename T>\n\
    using rpq = priority_queue<T, vector<T>, greater<T>>;\n\nconst int dx4[4] = {1,\
    \ 0, -1, 0};\nconst int dy4[4] = {0, -1, 0, 1};\nconst int dx8[8] = {1, 1, 0,\
    \ -1, -1, -1, 0, 1};\nconst int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};\n\nvector<pair<int,\
    \ int>> adjacent(int current_y, int current_x, int max_y, int max_x, bool dir_8\
    \ = false){\n    vector<pair<int, int>> ret;\n    for(int d = 0; d < 4 * (1 +\
    \ dir_8); ++d){\n        int next_y = current_y + (dir_8 ? dy8[d] : dy4[d]);\n\
    \        int next_x = current_x + (dir_8 ? dx8[d] : dx4[d]);\n        if(0 <=\
    \ next_y and next_y < max_y and 0 <= next_x and next_x < max_x){\n           \
    \ ret.emplace_back(next_y, next_x);\n        }\n    }\n    return ret;\n}\n\n\
    template <typename T1, typename T2>\nostream &operator<<(ostream &os, const pair<T1,\
    \ T2> &p){\n    os << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate\
    \ <typename T1, typename T2>\nistream &operator>>(istream &is, pair<T1, T2> &p){\n\
    \    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <typename T>\n\
    ostream &operator<<(ostream &os, vector<T> &v){\n    for (int i = 0; i < v.size();\
    \ ++i){\n        os << v[i] << (i + 1 != v.size() ? \" \" : \"\");\n    }\n  \
    \  return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, vector<vector<T>>\
    \ &v){\n    for (int i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1\
    \ != v.size() ? \"\\n\" : \"\");\n    }\n    return os;\n}\n\ntemplate <typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v){\n    for (int i = 0; i <\
    \ v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate <typename T>\nostream\
    \ &operator<<(ostream &os, set<T> &v){\n    for (auto &u : v){\n        os <<\
    \ u << \" \";\n    }\n    return os;\n}\n\ntemplate<typename T1, typename T2>\n\
    vector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2> &v2){\n   \
    \ assert(v1.size() == v2.size());\n    vector<pair<T1, T2>> v;\n    for(int i\
    \ = 0; i < v1.size(); ++i) v.push_back({v1[i], v2[i]});\n    return v;\n}\n\n\
    template<typename T1, typename T2>\npair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1,\
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
    \ DisassembleVectorTuple(v);\n}\n\nll modpow(ll a, ll x, ll m){\n    ll ret =\
    \ 1, cur = a % m, rem = x;\n    while(rem){\n        if(rem & 1) ret = (ret *\
    \ cur) % m;\n        rem >>= 1, cur = (cur * cur) % m;\n    }\n    return ret;\n\
    }\n\n#ifdef LOGK\n#define VARIABLE(var) cerr << \"# \" << #var << \" = \" << var\
    \ << endl;\n#else\n#define VARIABLE(...) 42\n#endif\n\n// ==============================================================\n\
    // \n// Main Program Start\n// \n// ==============================================================\n\
    #line 1 \"Library/DataStructure/SegmentTree.hpp\"\n/**\n * @file SegmentTree.hpp\n\
    \ * @author log K (lX57)\n * @brief Segment Tree - \u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n * @version 3.0\n * @date 2024-09-04\n */\n\n#line 10 \"Library/DataStructure/SegmentTree.hpp\"\
    \n\ntemplate<typename Monoid>\nclass SegmentTree{\n    public:\n    using F =\
    \ function<Monoid(Monoid, Monoid)>;\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\u3092\u8981\u7D20\u6570 `size` \u3067\u521D\u671F\u5316\u3059\
    \u308B\u3002\n     * @param size \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\
    \u7D20\u6570\n     * @param merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\
    \u7B97\n     * @param monoid_identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param zero_index 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B (default = `false`)\n     */\n    SegmentTree(int size, F merge, const\
    \ Monoid &monoid_identity, bool zero_index = false) :\n            f(merge), id_(monoid_identity),\
    \ zero_index_(zero_index){\n        size_ = 1;\n        while(size_ < size) size_\
    \ <<= 1;\n        offset_ = size_ - 1;\n        data_.resize(2 * size_, id_);\n\
    \    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\
    \u7BC9\u3059\u308B\u3002\n     * @attention \u5FC5\u305A `Set()` \u3067\u521D\u671F\
    \u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\u3089\u547C\u3073\u51FA\u3059\u3053\
    \u3068\uFF01\n     */\n    void Build(){\n        for(int i = offset_; i >= 1;\
    \ --i){\n            data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);\n     \
    \   }\n    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\
    \u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\u308B\u3002\n     * @param index \u4EE3\
    \u5165\u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     * @param\
    \ value \u4EE3\u5165\u3059\u308B\u5024\n     */\n    void Set(int index, Monoid\
    \ value){\n        Validate(index + zero_index_);\n        data_[offset_ + index\
    \ + zero_index_] = value;\n    }\n\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\u3092\u914D\u5217 `init_data` \u3067\u521D\u671F\u5316\u3059\u308B\
    \u3002\n     * @param init_data \u521D\u671F\u30C7\u30FC\u30BF\u306E\u914D\u5217\
    \n     * @param merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n\
    \     * @param monoid_identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\
    \n     * @param zero_index 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\u304B\
    \ (default = `false`)\n     */\n    SegmentTree(vector<Monoid> &init_data, F merge,\
    \ const Monoid &monoid_identity, bool zero_index = false) :\n            f(merge),\
    \ id_(monoid_identity), zero_index_(zero_index){\n        size_ = 1;\n       \
    \ while(size_ < (int)init_data.size()) size_ <<= 1;\n        offset_ = size_ -\
    \ 1;\n        data_.resize(2 * size_, id_);\n        for(int i = 0; i < (int)init_data.size();\
    \ ++i){\n            data_[size_ + i] = init_data[i];\n        }\n        Build();\n\
    \    }\n\n    /**\n     * @brief \u4E00\u70B9\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\
    \u51E6\u7406\u3059\u308B\u3002\n     * @param index \u66F4\u65B0\u5148\u306E\u8981\
    \u7D20\u756A\u53F7 (default = 1-index)\n     * @param value \u66F4\u65B0\u3059\
    \u308B\u5024\n     */\n    void Update(int index, Monoid value){\n        Validate(index\
    \ + zero_index_);\n        int k = offset_ + index + zero_index_;\n        data_[k]\
    \ = value;\n        while(k >>= 1){\n            data_[k] = f(data_[2 * k], data_[2\
    \ * k + 1]);\n        }\n    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593\
    \ `[left, Right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\
    \u30EA\u3092\u884C\u3046\u3002\n     * @param left \u534A\u958B\u533A\u9593\u306E\
    \u5DE6\u7AEF\n     * @param right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n\
    \     * @return Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid\
    \ Query(int left, int right){\n        if(left == right) return id_;\n       \
    \ Validate(left + zero_index_);\n        Validate(right + zero_index_ - 1);\n\
    \        int l = left + zero_index_ + offset_, r = right + zero_index_ + offset_;\n\
    \        Monoid al = id_, ar = id_;\n        while(l < r){\n            if(l &\
    \ 1) al = f(al, data_[l++]);\n            if(r & 1) ar = f(data_[--r], ar);\n\
    \            l >>= 1, r >>= 1;\n        }\n        return f(al, ar);\n    }\n\n\
    \    /**\n     * @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\u3059\u308B\u3002\n     * @param k \u53D6\u5F97\u5148\u306E\u8981\u7D20\
    \u756A\u53F7 (default = 1-index)\n     * @return Monoid \u53D6\u5F97\u3057\u305F\
    \u7D50\u679C\n     */\n    Monoid get_value(int k){\n        Validate(k + zero_index_);\n\
    \        return data_[offset_ + k + zero_index_];\n    }\n\n    Monoid operator[](const\
    \ int &k){\n        return get_value(k);\n    }\n\n    private:\n    int size_,\
    \ offset_, zero_index_;\n    vector<Monoid> data_;\n    const F f;\n    const\
    \ Monoid id_;\n\n    inline void Validate(int x) const {\n        assert(1 <=\
    \ x && x <= size_);\n    }\n};\n#line 5 \"verify/AOJ-DSL-2-B.test.cpp\"\n\nint\
    \ main(){\n    int n, q; cin >> n >> q;\n\n    SegmentTree<int> seg(n, [](int\
    \ l, int r){return l + r;}, 0, false);\n    seg.Build();\n    while(q--){\n  \
    \      int com, x, y; cin >> com >> x >> y;\n        if(com == 0){\n         \
    \   seg.Update(x, seg[x] + y);\n        }\n        else{\n            cout <<\
    \ seg.Query(x, y + 1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/DataStructure/SegmentTree.hpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n\n    SegmentTree<int> seg(n, [](int\
    \ l, int r){return l + r;}, 0, false);\n    seg.Build();\n    while(q--){\n  \
    \      int com, x, y; cin >> com >> x >> y;\n        if(com == 0){\n         \
    \   seg.Update(x, seg[x] + y);\n        }\n        else{\n            cout <<\
    \ seg.Query(x, y + 1) << endl;\n        }\n    }\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-2-B.test.cpp
  requiredBy: []
  timestamp: '2024-10-27 03:42:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-2-B.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-2-B.test.cpp
- /verify/verify/AOJ-DSL-2-B.test.cpp.html
title: verify/AOJ-DSL-2-B.test.cpp
---
