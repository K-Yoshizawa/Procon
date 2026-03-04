---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/MergeSortTree.hpp
    title: "Merge Sort Tree - \u9818\u57DF\u6728"
  - icon: ':heavy_check_mark:'
    path: Library/Template.hpp
    title: "Template - \u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\u30A3\u95A2\u6570\u7FA4"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum_with_upper_bound
    links:
    - https://judge.yosupo.jp/problem/static_range_sum_with_upper_bound
  bundledCode: "#line 1 \"verify/LC-StaticRangeSumWithUpperBound.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum_with_upper_bound\"\
    \n\n#line 2 \"Library/Template.hpp\"\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n\
    \ * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const\
    \ ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 4 \"Library/Template.hpp\"\n\n\
    inline bool YnPrint(bool flag){cout << (flag ? \"Yes\" : \"No\") << '\\n'; return\
    \ flag;}\ninline bool YNPrint(bool flag){cout << (flag ? \"YES\" : \"NO\") <<\
    \ '\\n'; return flag;}\ntemplate<typename Container>\ninline void Sort(Container\
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
    \ DisassembleVectorTuple(v);\n}\n#line 2 \"Library/DataStructure/MergeSortTree.hpp\"\
    \n\ntemplate <typename DataType, typename WeightType = DataType>\nclass MergeSortTree{\n\
    \    public:\n    MergeSortTree(\n        const vector<DataType> &A,\n       \
    \ const vector<WeightType> &B,\n        bool zero_index = false\n    ) : zero_index_(zero_index){\n\
    \        Build(A, B);\n    }\n    \n    MergeSortTree(\n        const vector<DataType>\
    \ &A,\n        bool zero_index = false\n    ) : zero_index_(zero_index){\n   \
    \     Build(A, A);\n    }\n\n    int CountAtMost(int l, int r, DataType x) const\
    \ {\n        if(l >= r) return 0;\n        Validate(l + zero_index_);\n      \
    \  Validate(r + zero_index_ - 1);\n        int lh = l + zero_index_ + offset_,\
    \ rh = r + zero_index_ + offset_;\n        int lcnt = 0, rcnt = 0;\n        while(lh\
    \ < rh){\n            if(lh & 1){\n                lcnt += distance(data_[lh].begin(),\
    \ upper_bound(data_[lh].begin(), data_[lh].end(), x));\n                ++lh;\n\
    \            }\n            if(rh & 1){\n                --rh;\n             \
    \   rcnt += distance(data_[rh].begin(), upper_bound(data_[rh].begin(), data_[rh].end(),\
    \ x));\n            }\n            lh >>= 1, rh >>= 1;\n        }\n        return\
    \ lcnt + rcnt;\n    }\n\n    int CountAtLeast(int l, int r, DataType x) const\
    \ {\n        if(l >= r) return 0;\n        return r - l - CountAtMost(l, r, x\
    \ - 1);\n    }\n\n    int CountBetween(int l, int r, DataType p, DataType q) const\
    \ {\n        return CountAtMost(l, r, q) - CountAtMost(l, r, p - 1);\n    }\n\n\
    \    WeightType SumAtMost(int l, int r, DataType x) const {\n        if(l >= r)\
    \ return 0;\n        Validate(l + zero_index_);\n        Validate(r + zero_index_\
    \ - 1);\n        int lh = l + zero_index_ + offset_, rh = r + zero_index_ + offset_;\n\
    \        WeightType lval = 0, rval = 0;\n        while(lh < rh){\n           \
    \ if(lh & 1){\n                int idx = distance(data_[lh].begin(), upper_bound(data_[lh].begin(),\
    \ data_[lh].end(), x));\n                lval += prefix_sum_[lh][idx];\n     \
    \           ++lh;\n            }\n            if(rh & 1){\n                --rh;\n\
    \                int idx = distance(data_[rh].begin(), upper_bound(data_[rh].begin(),\
    \ data_[rh].end(), x));\n                rval += prefix_sum_[rh][idx];\n     \
    \       }\n            lh >>= 1, rh >>= 1;\n        }\n        return lval + rval;\n\
    \    }\n\n    WeightType SumAtLeast(int l, int r, DataType x) const {\n      \
    \  if(l >= r) return 0;\n        Validate(l + zero_index_);\n        Validate(r\
    \ + zero_index_ - 1);\n        int lh = l + zero_index_ + offset_, rh = r + zero_index_\
    \ + offset_;\n        WeightType lval = 0, rval = 0;\n        while(lh < rh){\n\
    \            if(lh & 1){\n                int idx = distance(data_[lh].begin(),\
    \ lower_bound(data_[lh].begin(), data_[lh].end(), x));\n                lval +=\
    \ prefix_sum_[lh].back() - prefix_sum_[lh][idx];\n                ++lh;\n    \
    \        }\n            if(rh & 1){\n                --rh;\n                int\
    \ idx = distance(data_[rh].begin(), lower_bound(data_[rh].begin(), data_[rh].end(),\
    \ x));\n                rval += prefix_sum_[rh].back() - prefix_sum_[rh][idx];\n\
    \            }\n            lh >>= 1, rh >>= 1;\n        }\n        return lval\
    \ + rval;\n    }\n\n    WeightType SumBetween(int l, int r, DataType p, DataType\
    \ q) const {\n        return SumAtMost(l, r, q) - SumAtMost(l, r, p - 1);\n  \
    \  }\n    \n    private:\n    int n_, offset_, zero_index_;\n    vector<vector<DataType>>\
    \ data_;\n    vector<vector<WeightType>> weight_, prefix_sum_;\n\n    void Build(const\
    \ vector<DataType> &data, const vector<WeightType> &weight){\n        n_ = 1;\n\
    \        while(n_ < (int)data.size()) n_ <<= 1;\n        offset_ = n_ - 1;\n \
    \       data_.resize(2 * n_);\n        weight_.resize(2 * n_);\n        prefix_sum_.resize(2\
    \ * n_);\n        for(int i = 0; i < (int)data.size(); ++i){\n            data_[n_\
    \ + i].emplace_back(data[i]);\n            weight_[n_ + i].emplace_back(weight[i]);\n\
    \            prefix_sum_[n_ + i].emplace_back(0);\n            prefix_sum_[n_\
    \ + i].emplace_back(weight[i]);\n        }\n        for(int i = offset_; i >=\
    \ 1; --i){\n            int l = i * 2 + 0, r = i * 2 + 1, li = 0, ri = 0, j =\
    \ 0;\n            int ls = (int)data_[l].size(), rs = (int)data_[r].size();\n\
    \            data_[i].resize(ls + rs);\n            weight_[i].resize(ls + rs);\n\
    \            prefix_sum_[i].resize(ls + rs + 1);\n            while(li < ls ||\
    \ ri < rs){\n                if(ri == rs || li != ls && data_[l][li] < data_[r][ri]){\n\
    \                    data_[i][j] = data_[l][li];\n                    weight_[i][j]\
    \ = weight_[l][li];\n                    prefix_sum_[i][j + 1] = prefix_sum_[i][j]\
    \ + weight_[i][j];\n                    ++j, ++li;\n                }\n      \
    \          else{\n                    data_[i][j] = data_[r][ri];\n          \
    \          weight_[i][j] = weight_[r][ri];\n                    prefix_sum_[i][j\
    \ + 1] = prefix_sum_[i][j] + weight_[i][j];\n                    ++j, ++ri;\n\
    \                }\n            }\n        }\n    }\n    \n    inline void Validate(int\
    \ x) const {\n        assert(1 <= x && x <= n_);\n    }\n};\n#line 5 \"verify/LC-StaticRangeSumWithUpperBound.test.cpp\"\
    \n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n\n    int N, Q; cin\
    \ >> N >> Q;\n    vector<ll> a(N); cin >> a;\n\n    MergeSortTree<ll> mst(a, true);\n\
    \    while(Q--){\n        ll l, r, x; cin >> l >> r >> x;\n        cout << mst.CountAtMost(l,\
    \ r, x) << ' ' << mst.SumAtMost(l, r, x) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum_with_upper_bound\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/DataStructure/MergeSortTree.hpp\"\
    \n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n\n    int N, Q; cin\
    \ >> N >> Q;\n    vector<ll> a(N); cin >> a;\n\n    MergeSortTree<ll> mst(a, true);\n\
    \    while(Q--){\n        ll l, r, x; cin >> l >> r >> x;\n        cout << mst.CountAtMost(l,\
    \ r, x) << ' ' << mst.SumAtMost(l, r, x) << '\\n';\n    }\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/DataStructure/MergeSortTree.hpp
  isVerificationFile: true
  path: verify/LC-StaticRangeSumWithUpperBound.test.cpp
  requiredBy: []
  timestamp: '2026-02-12 16:49:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-StaticRangeSumWithUpperBound.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-StaticRangeSumWithUpperBound.test.cpp
- /verify/verify/LC-StaticRangeSumWithUpperBound.test.cpp.html
title: verify/LC-StaticRangeSumWithUpperBound.test.cpp
---
