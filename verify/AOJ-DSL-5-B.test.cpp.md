---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/CumulativeSum2D.hpp
    title: "Cumulative Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
  bundledCode: "#line 1 \"verify/AOJ-DSL-5-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
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
    \ << endl;\n#else\n#define VARIABLE(...) 42\n#endif\n#line 1 \"Library/DataStructure/CumulativeSum2D.hpp\"\
    \n/**\n * @file CumulativeSum2D.hpp\n * @author log K (lX57)\n * @brief Cumulative\
    \ Sum 2D - \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\n * @version 3.0\n * @date 2024-10-21\n\
    \ */\n\n#line 10 \"Library/DataStructure/CumulativeSum2D.hpp\"\n\ntemplate<typename\
    \ T = int32_t>\nstruct CumulativeSum2D{\n    private:\n    int height_, width_;\n\
    \    vector<vector<T>> data_;\n\n    void Validate(const int y, const int x) const\
    \ {\n        assert(0 <= y && y < height_ - 1);\n        assert(0 <= x && x <\
    \ width_ - 1);\n    }\n\n    public:\n    CumulativeSum2D(const int height, const\
    \ int width, const T init_value = 0) : height_(height + 1), width_(width + 1){\n\
    \        data_.resize(height_);\n        for(int i = 0; i < height_; ++i){\n \
    \           data_.at(i).resize(width_);\n        }\n    }\n\n    void Build(){\n\
    \        for(int i = 1; i < height_; ++i){\n            for(int j = 0; j < width_;\
    \ ++j){\n                data_[i][j] += data_[i - 1][j];\n            }\n    \
    \    }\n        for(int i = 0; i < height_; ++i){\n            for(int j = 1;\
    \ j < width_; ++j){\n                data_[i][j] += data_[i][j - 1];\n       \
    \     }\n        }\n    }\n\n    /**\n     * @brief \u5EA7\u6A19 `(y, x)` \u306B\
    \u5024 `value` \u3092\u4EE3\u5165\u3059\u308B\u3002\n     * @attention \u5EA7\u6A19\
    \u6307\u5B9A\u306F 0-index\u3067\u884C\u3046\u3053\u3068\n     * @param value\
    \ \u4EE3\u5165\u3059\u308B\u5024\n     */\n    void Set(const int y, const int\
    \ x, const T value){\n        Validate(y, x);\n        data_[y][x] = value;\n\
    \    }\n\n    /**\n     * @brief \u5EA7\u6A19 `(y, x)` \u306B\u5024 `value` \u3092\
    \u52A0\u7B97\u3059\u308B\u3002\n     * @attention \u5EA7\u6A19\u6307\u5B9A\u306F\
    \ 0-index\u3067\u884C\u3046\u3053\u3068\n     * @param value \u52A0\u7B97\u3059\
    \u308B\u5024\n     */\n    void Add(const int y, const int x, const T value){\n\
    \        Add(y, x, y, x, value);\n    }\n\n    /**\n     * @brief \u9577\u65B9\
    \u5F62\u9818\u57DF `[y1, y2] \xD7 [x1, x2]` \u306B\u5024 `value` \u3092\u52A0\u7B97\
    \u3059\u308B\u3002\n     * @attention \u5EA7\u6A19\u6307\u5B9A\u306F 0-index,\
    \ \u9589\u533A\u9593\u3067\u884C\u3046\u3053\u3068\n     * @param y1 \u9577\u65B9\
    \u5F62\u9818\u57DF\u5DE6\u4E0A\u306E y \u5EA7\u6A19\n     * @param x1 \u9577\u65B9\
    \u5F62\u9818\u57DF\u5DE6\u4E0A\u306E x \u5EA7\u6A19\n     * @param y2 \u9577\u65B9\
    \u5F62\u9818\u57DF\u53F3\u4E0B\u306E y \u5EA7\u6A19\n     * @param x2 \u9577\u65B9\
    \u5F62\u9818\u57DF\u53F3\u4E0B\u306E x \u5EA7\u6A19\n     * @param value \u52A0\
    \u7B97\u3059\u308B\u5024\n     */\n    void Add(const int y1, const int x1, const\
    \ int y2, const int x2, const T value){\n        Validate(y1, x1);\n        Validate(y2,\
    \ x2);\n        data_[y1][x1] += value;\n        data_[y2 + 1][x1] -= value;\n\
    \        data_[y1][x2 + 1] -= value;\n        data_[y2 + 1][x2 + 1] += value;\n\
    \    }\n\n    /**\n     * @brief \u9577\u65B9\u5F62\u9818\u57DF `[0, y] \xD7 [0,\
    \ x]` \u306E\u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\u3002\n     * @attention\
    \ \u5EA7\u6A19\u6307\u5B9A\u306F 0-index, \u9589\u533A\u9593\u3067\u884C\u3046\
    \u3053\u3068\n     * @param y \u9577\u65B9\u5F62\u9818\u57DF\u53F3\u4E0B\u306E\
    \ y \u5EA7\u6A19\n     * @param x \u9577\u65B9\u5F62\u9818\u57DF\u53F3\u4E0B\u306E\
    \ x \u5EA7\u6A19\n     * @return T \n     */\n    T Sum(const int y, const int\
    \ x) const {\n        Validate(y, x);\n        return data_[y][x];\n    }\n\n\
    \    /**\n     * @brief \u9577\u65B9\u5F62\u9818\u57DF `[y1, y2] \xD7 [x1, x2]`\
    \ \u306E\u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\u3002\n     * @attention\
    \ \u5EA7\u6A19\u6307\u5B9A\u306F 0-index, \u9589\u533A\u9593\u3067\u884C\u3046\
    \u3053\u3068\n     * @param y1 \u9577\u65B9\u5F62\u9818\u57DF\u5DE6\u4E0A\u306E\
    \ y \u5EA7\u6A19\n     * @param x1 \u9577\u65B9\u5F62\u9818\u57DF\u5DE6\u4E0A\u306E\
    \ x \u5EA7\u6A19\n     * @param y2 \u9577\u65B9\u5F62\u9818\u57DF\u53F3\u4E0B\u306E\
    \ y \u5EA7\u6A19\n     * @param x2 \u9577\u65B9\u5F62\u9818\u57DF\u53F3\u4E0B\u306E\
    \ x \u5EA7\u6A19\n     * @param value \u52A0\u7B97\u3059\u308B\u5024\n     * @return\
    \ T \n     */\n    T Sum(const int y1, const int x1, const int y2, const int x2)\
    \ const {\n        Validate(y1, x1);\n        Validate(y2, x2);\n        T ret\
    \ = Sum(y2, x2);\n        if(y1 > 0) ret -= Sum(y1 - 1, x2);\n        if(x1 >\
    \ 0) ret -= Sum(y2, x1 - 1);\n        if(y1 > 0 && x1 > 0) ret += Sum(y1 - 1,\
    \ x1 - 1);\n        return ret;\n    }\n\n    T Max() const {\n        T ret =\
    \ data_[0][0];\n        for(int i = 0; i < height_; ++i){\n            for(int\
    \ j = 0; j < width_; ++j){\n                ret = max(ret, data_[i][j]);\n   \
    \         }\n        }\n        return ret;\n    }\n\n    T Min() const {\n  \
    \      T ret = data_[0][0];\n        for(int i = 0; i < height_; ++i){\n     \
    \       for(int j = 0; j < width_; ++j){\n                ret = min(ret, data_[i][j]);\n\
    \            }\n        }\n        return ret;\n    }\n\n    vector<T> &operator[](const\
    \ int k){\n        return data_.at(k);\n    }\n};\n#line 5 \"verify/AOJ-DSL-5-B.test.cpp\"\
    \n\nint main(){\n    int N; cin >> N;\n\n    CumulativeSum2D<int> cum(2000, 2000);\n\
    \    for(int i = 0; i < N; ++i){\n        int x1, y1, x2, y2; cin >> x1 >> y1\
    \ >> x2 >> y2;\n        cum.Add(y1, x1, y2 - 1, x2 - 1, 1);\n        // cerr <<\
    \ \"# i = \" << i + 1 << endl;\n        // cum.Print();\n    }\n    cum.Build();\n\
    \    // cum.Print();\n    cout << cum.Max() << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/DataStructure/CumulativeSum2D.hpp\"\
    \n\nint main(){\n    int N; cin >> N;\n\n    CumulativeSum2D<int> cum(2000, 2000);\n\
    \    for(int i = 0; i < N; ++i){\n        int x1, y1, x2, y2; cin >> x1 >> y1\
    \ >> x2 >> y2;\n        cum.Add(y1, x1, y2 - 1, x2 - 1, 1);\n        // cerr <<\
    \ \"# i = \" << i + 1 << endl;\n        // cum.Print();\n    }\n    cum.Build();\n\
    \    // cum.Print();\n    cout << cum.Max() << endl;\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/DataStructure/CumulativeSum2D.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-5-B.test.cpp
  requiredBy: []
  timestamp: '2024-11-11 17:34:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-5-B.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-5-B.test.cpp
- /verify/verify/AOJ-DSL-5-B.test.cpp.html
title: verify/AOJ-DSL-5-B.test.cpp
---
