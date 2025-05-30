---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Other/LongestIncreasingSubsequence.hpp
    title: "Longest Increasing Subsequence - \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"verify/LC-LongestIncreasingSubsequence.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\n\
    \n#line 2 \"Library/Template.hpp\"\n\n/**\n * @file Template.hpp\n * @author log\
    \ K (lX57)\n * @brief Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 1.10\n * @date 2025-03-16\n */\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n *\
    \ @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cstdint>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr const ll INF = (1LL\
    \ << 62) - (1LL << 30) - 1;\n#line 12 \"Library/Template.hpp\"\n\ninline bool\
    \ YnPrint(bool flag){cout << (flag ? \"Yes\" : \"No\") << '\\n'; return flag;}\n\
    inline bool YNPrint(bool flag){cout << (flag ? \"YES\" : \"NO\") << '\\n'; return\
    \ flag;}\ntemplate<typename Container>\ninline void Sort(Container &container){sort(container.begin(),\
    \ container.end());}\ntemplate<typename Container>\ninline void ReverseSort(Container\
    \ &container){sort(container.rbegin(), container.rend());}\ntemplate<typename\
    \ Container>\ninline void Reverse(Container &container){reverse(container.begin(),\
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
    \ DisassembleVectorTuple(v);\n}\n#line 1 \"Library/Other/LongestIncreasingSubsequence.hpp\"\
    \n/**\n * @file LongestIncreasingSubsequence.hpp\n * @brief Longest Increasing\
    \ Subsequence - \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\n * @author ei1333\
    \ (Original)\n * @version 2.0\n * @date 2024-10-29\n */\n\n#line 10 \"Library/Other/LongestIncreasingSubsequence.hpp\"\
    \n\n/**\n * @brief \u914D\u5217 `data` \u306E\u6700\u9577\u5897\u52A0\u90E8\u5206\
    \u5217\u3092\u6C42\u3081\u308B\u3002\n * @tparam Strict \u72ED\u7FA9\u5358\u8ABF\
    \u5897\u52A0\u3067\u3042\u308B\u304B\n * @param data \u6C42\u3081\u308B\u914D\u5217\
    \n * @return vector<T> \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E 1 \u3064\
    \u3067\u3001\u5404\u8981\u7D20\u3092 `data` \u306B\u304A\u3051\u308B\u6DFB\u3048\
    \u5B57\u3067\u8868\u3057\u305F\u914D\u5217\n * @note \u8FD4\u308A\u5024\u306E\u914D\
    \u5217\u306E\u9577\u3055\u304C\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\
    \u9577\u3055\u3067\u3042\u308B\u3002\n */\ntemplate<bool Strict, typename T>\n\
    vector<T> LongestIncreasingSubsequence(const vector<T> &data){\n    int N = (int)data.size();\n\
    \    T inf = numeric_limits<T>::min();\n    vector<T> L, pre, S;\n    for(auto\
    \ &x : data){\n        typename vector<T>::iterator itr;\n        if(Strict) itr\
    \ = lower_bound(L.begin(), L.end(), x);\n        else itr = upper_bound(L.begin(),\
    \ L.end(), x);\n        if(itr == L.begin()) pre.emplace_back(inf);\n        else\
    \ pre.emplace_back(*prev(itr));\n        if(itr == L.end()) L.emplace_back(x);\n\
    \        else *itr = x;\n    }\n    T x = L.back();\n    for(int i = N - 1; x\
    \ != inf;){\n        while(data[i] != x) --i;\n        S.emplace_back(i);\n  \
    \      x = pre[i];\n    }\n    reverse(S.begin(), S.end());\n    return S;\n}\n\
    #line 5 \"verify/LC-LongestIncreasingSubsequence.test.cpp\"\n\nint main(){\n \
    \   cin.tie(0)->sync_with_stdio(false);\n    int N; cin >> N;\n    vector<int>\
    \ A(N); cin >> A;\n\n    auto ans = LongestIncreasingSubsequence<true>(A);\n \
    \   cout << ans.size() << '\\n';\n    for(auto i : ans){\n        cout << i <<\
    \ \" \";\n    }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/Other/LongestIncreasingSubsequence.hpp\"\
    \n\nint main(){\n    cin.tie(0)->sync_with_stdio(false);\n    int N; cin >> N;\n\
    \    vector<int> A(N); cin >> A;\n\n    auto ans = LongestIncreasingSubsequence<true>(A);\n\
    \    cout << ans.size() << '\\n';\n    for(auto i : ans){\n        cout << i <<\
    \ \" \";\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/Other/LongestIncreasingSubsequence.hpp
  isVerificationFile: true
  path: verify/LC-LongestIncreasingSubsequence.test.cpp
  requiredBy: []
  timestamp: '2025-05-30 19:43:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-LongestIncreasingSubsequence.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-LongestIncreasingSubsequence.test.cpp
- /verify/verify/LC-LongestIncreasingSubsequence.test.cpp.html
title: verify/LC-LongestIncreasingSubsequence.test.cpp
---
