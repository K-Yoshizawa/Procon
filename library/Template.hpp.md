---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/TemplateExtend.hpp
    title: library/TemplateExtend.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"library/Template.hpp\"\n/**\n * @file Template.hpp\n * @author\
    \ log K (lX57)\n * @brief Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n *\
    \ @version 1.8\n * @date 2024-06-16\n */\n\n#include <bits/stdc++.h>\n#define\
    \ ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define\
    \ SORT(x) sort(ALL(x))\n#define RSORT(x) sort(RALL(x))\n#define REVERSE(x) reverse(ALL(x))\n\
    #define SETPRE(digit) fixed << setprecision(digit)\n#define POPCOUNT(x) __builtin_popcount(x)\n\
    #define SUM(x) reduce((x).begin(), (x).end())\n#define CEIL(nume, deno) ((nume)\
    \ + (deno) - 1) / (deno)\n#define IOTA(x) iota((x).begin(), (x).end(), 0)\n#define\
    \ LOWERBOUND_IDX(arr, val) (int)(lower_bound((arr).begin(), (arr).end(), val)\
    \ - (arr).begin())\n#define UPPERBOUND_IDX(arr, val) (int)(upper_bound((arr).begin(),\
    \ (arr).end(), val) - (arr).begin())\nusing namespace std;\n\ninline string Yn(bool\
    \ flag){return (flag) ? \"Yes\" : \"No\";}\ninline bool YnPrint(bool flag){cout\
    \ << Yn(flag) << endl;return flag;}\ninline string YN(bool flag){return (flag)\
    \ ? \"YES\" : \"NO\";}\ninline bool YNPrint(bool flag){cout << YN(flag) << endl;return\
    \ flag;}\ntemplate<class T>\nbool minin(T &src, const T &cmp){if(src > cmp){src\
    \ = cmp; return true;}return false;}\ntemplate<class T>\nbool maxin(T &src, const\
    \ T &cmp){if(src < cmp){src = cmp; return true;}return false;}\ntemplate<typename\
    \ T>\ninline bool between(T min, T x, T max){return min <= x && x <= max;}\ntemplate<typename\
    \ T>\ninline bool ingrid(T y, T x, T ymax, T xmax){return between(0, y, ymax -\
    \ 1) && between(0, x, xmax - 1);}\ntemplate<typename T>\ninline T median(T a,\
    \ T b, T c){return between(b, a, c) || between(c, a, b) ? a : (between(a, b, c)\
    \ || between(c, b, a) ? b : c);}\ntemplate<typename T>\ninline T except(T src,\
    \ T cond, T excp){return (src == cond ? excp : src);}\ntemplate<typename T>\n\
    inline T min(vector<T> &v){return *min_element((v).begin(), (v).end());}\ntemplate<typename\
    \ T>\ninline T max(vector<T> &v){return *max_element((v).begin(), (v).end());}\n\
    vector<int> make_sequence(int Size){\n    vector<int> ret(Size);\n    IOTA(ret);\n\
    \    return ret;\n}\ntemplate<typename T>\nvoid make_unique(vector<T> &v){\n \
    \   sort(v.begin(), v.end());\n    auto itr = unique(v.begin(), v.end());\n  \
    \  v.erase(itr, v.end());\n}\n\nusing ll = int64_t;\nusing ull = uint64_t;\nusing\
    \ ld = long double;\n\nconst long double PI = acosl(-1);\nconst long double PI2\
    \ = PI * 2;\nconst long double PI_2 = PI / 2;\n\nconst int INF_INT = numeric_limits<int>::max()\
    \ >> 2;\nconst ll INF_LL = numeric_limits<ll>::max() >> 2;\n\ntemplate <typename\
    \ T>\nusing vec = vector<T>;\ntemplate <typename T>\nusing mat = vector<vector<T>>;\n\
    using vi = vector<int>;\nusing vvi = vector<vi>;\nusing vvvi = vector<vvi>;\n\
    using vl = vector<ll>;\nusing vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing\
    \ vd = vector<double>;\nusing vvd = vector<vd>;\nusing vvvd = vector<vvd>;\nusing\
    \ pi = pair<int, int>;\nusing pl = pair<ll, ll>;\nusing pd = pair<double, double>;\n\
    using vpi = vector<pi>;\nusing vpl = vector<pl>;\nusing vpd = vector<pd>;\nusing\
    \ vvpi = vector<vpi>;\nusing vvpl = vector<vpl>;\nusing vvpd = vector<vpd>;\n\
    using ti3 = tuple<int, int, int>;\nusing tl3 = tuple<ll, ll, ll>;\nusing ti4 =\
    \ tuple<int, int, int, int>;\nusing tl4 = tuple<ll, ll, ll, ll>;\nusing vs = vector<string>;\n\
    template <typename T>\nusing pq = priority_queue<T>;\ntemplate <typename T>\n\
    using rpq = priority_queue<T, vec<T>, greater<T>>;\n\nconst int dx4[4] = {1, 0,\
    \ -1, 0};\nconst int dy4[4] = {0, -1, 0, 1};\nconst int dx8[8] = {1, 1, 0, -1,\
    \ -1, -1, 0, 1};\nconst int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};\n\ntemplate\
    \ <typename T1, typename T2>\nostream &operator<<(ostream &os, const pair<T1,\
    \ T2> &p){\n    os << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate\
    \ <typename T1, typename T2>\nistream &operator>>(istream &is, pair<T1, T2> &p){\n\
    \    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <typename T>\n\
    ostream &operator<<(ostream &os, vector<T> &v){\n    for (int i = 0; i < v.size();\
    \ ++i){\n        os << v[i] << (i + 1 != v.size() ? \" \" : \"\");\n    }\n  \
    \  return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, vector<vector<T>>\
    \ &v){\n    for (int i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1\
    \ != v.size() ? \"\\n\" : \"\");\n    }\n    return os;\n}\n\ntemplate <typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v){\n    for (int i = 0; i <\
    \ v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate<typename T1, typename\
    \ T2>\nvector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2> &v2){\n\
    \    assert(v1.size() == v2.size());\n    vector<pair<T1, T2>> v;\n    for(int\
    \ i = 0; i < v1.size(); ++i) v.push_back({v1[i], v2[i]});\n    return v;\n}\n\n\
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
    \ DisassembleVectorTuple(v);\n}\n\n#ifdef LOGK\n#define DEBUG(fmt, ...) fprintf(stderr,\
    \ \"[Debug]    \" fmt __VA_OPT__(,) __VA_ARGS__)\n#define VARIABLE(var) cerr <<\
    \ \"# \" << #var << \" = \" << var << endl;\n#else\n#define DEBUG(...) 42\n#define\
    \ VARIABLE(...) 42\n#endif\n\n// ==============================================================\n\
    // \n// Main Program Start\n// \n// ==============================================================\n"
  code: "#pragma once\n/**\n * @file Template.hpp\n * @author log K (lX57)\n * @brief\
    \ Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 1.8\n * @date 2024-06-16\n\
    \ */\n\n#include <bits/stdc++.h>\n#define ALL(x) (x).begin(), (x).end()\n#define\
    \ RALL(x) (x).rbegin(), (x).rend()\n#define SORT(x) sort(ALL(x))\n#define RSORT(x)\
    \ sort(RALL(x))\n#define REVERSE(x) reverse(ALL(x))\n#define SETPRE(digit) fixed\
    \ << setprecision(digit)\n#define POPCOUNT(x) __builtin_popcount(x)\n#define SUM(x)\
    \ reduce((x).begin(), (x).end())\n#define CEIL(nume, deno) ((nume) + (deno) -\
    \ 1) / (deno)\n#define IOTA(x) iota((x).begin(), (x).end(), 0)\n#define LOWERBOUND_IDX(arr,\
    \ val) (int)(lower_bound((arr).begin(), (arr).end(), val) - (arr).begin())\n#define\
    \ UPPERBOUND_IDX(arr, val) (int)(upper_bound((arr).begin(), (arr).end(), val)\
    \ - (arr).begin())\nusing namespace std;\n\ninline string Yn(bool flag){return\
    \ (flag) ? \"Yes\" : \"No\";}\ninline bool YnPrint(bool flag){cout << Yn(flag)\
    \ << endl;return flag;}\ninline string YN(bool flag){return (flag) ? \"YES\" :\
    \ \"NO\";}\ninline bool YNPrint(bool flag){cout << YN(flag) << endl;return flag;}\n\
    template<class T>\nbool minin(T &src, const T &cmp){if(src > cmp){src = cmp; return\
    \ true;}return false;}\ntemplate<class T>\nbool maxin(T &src, const T &cmp){if(src\
    \ < cmp){src = cmp; return true;}return false;}\ntemplate<typename T>\ninline\
    \ bool between(T min, T x, T max){return min <= x && x <= max;}\ntemplate<typename\
    \ T>\ninline bool ingrid(T y, T x, T ymax, T xmax){return between(0, y, ymax -\
    \ 1) && between(0, x, xmax - 1);}\ntemplate<typename T>\ninline T median(T a,\
    \ T b, T c){return between(b, a, c) || between(c, a, b) ? a : (between(a, b, c)\
    \ || between(c, b, a) ? b : c);}\ntemplate<typename T>\ninline T except(T src,\
    \ T cond, T excp){return (src == cond ? excp : src);}\ntemplate<typename T>\n\
    inline T min(vector<T> &v){return *min_element((v).begin(), (v).end());}\ntemplate<typename\
    \ T>\ninline T max(vector<T> &v){return *max_element((v).begin(), (v).end());}\n\
    vector<int> make_sequence(int Size){\n    vector<int> ret(Size);\n    IOTA(ret);\n\
    \    return ret;\n}\ntemplate<typename T>\nvoid make_unique(vector<T> &v){\n \
    \   sort(v.begin(), v.end());\n    auto itr = unique(v.begin(), v.end());\n  \
    \  v.erase(itr, v.end());\n}\n\nusing ll = int64_t;\nusing ull = uint64_t;\nusing\
    \ ld = long double;\n\nconst long double PI = acosl(-1);\nconst long double PI2\
    \ = PI * 2;\nconst long double PI_2 = PI / 2;\n\nconst int INF_INT = numeric_limits<int>::max()\
    \ >> 2;\nconst ll INF_LL = numeric_limits<ll>::max() >> 2;\n\ntemplate <typename\
    \ T>\nusing vec = vector<T>;\ntemplate <typename T>\nusing mat = vector<vector<T>>;\n\
    using vi = vector<int>;\nusing vvi = vector<vi>;\nusing vvvi = vector<vvi>;\n\
    using vl = vector<ll>;\nusing vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing\
    \ vd = vector<double>;\nusing vvd = vector<vd>;\nusing vvvd = vector<vvd>;\nusing\
    \ pi = pair<int, int>;\nusing pl = pair<ll, ll>;\nusing pd = pair<double, double>;\n\
    using vpi = vector<pi>;\nusing vpl = vector<pl>;\nusing vpd = vector<pd>;\nusing\
    \ vvpi = vector<vpi>;\nusing vvpl = vector<vpl>;\nusing vvpd = vector<vpd>;\n\
    using ti3 = tuple<int, int, int>;\nusing tl3 = tuple<ll, ll, ll>;\nusing ti4 =\
    \ tuple<int, int, int, int>;\nusing tl4 = tuple<ll, ll, ll, ll>;\nusing vs = vector<string>;\n\
    template <typename T>\nusing pq = priority_queue<T>;\ntemplate <typename T>\n\
    using rpq = priority_queue<T, vec<T>, greater<T>>;\n\nconst int dx4[4] = {1, 0,\
    \ -1, 0};\nconst int dy4[4] = {0, -1, 0, 1};\nconst int dx8[8] = {1, 1, 0, -1,\
    \ -1, -1, 0, 1};\nconst int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};\n\ntemplate\
    \ <typename T1, typename T2>\nostream &operator<<(ostream &os, const pair<T1,\
    \ T2> &p){\n    os << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate\
    \ <typename T1, typename T2>\nistream &operator>>(istream &is, pair<T1, T2> &p){\n\
    \    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <typename T>\n\
    ostream &operator<<(ostream &os, vector<T> &v){\n    for (int i = 0; i < v.size();\
    \ ++i){\n        os << v[i] << (i + 1 != v.size() ? \" \" : \"\");\n    }\n  \
    \  return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, vector<vector<T>>\
    \ &v){\n    for (int i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1\
    \ != v.size() ? \"\\n\" : \"\");\n    }\n    return os;\n}\n\ntemplate <typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v){\n    for (int i = 0; i <\
    \ v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate<typename T1, typename\
    \ T2>\nvector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2> &v2){\n\
    \    assert(v1.size() == v2.size());\n    vector<pair<T1, T2>> v;\n    for(int\
    \ i = 0; i < v1.size(); ++i) v.push_back({v1[i], v2[i]});\n    return v;\n}\n\n\
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
    \ DisassembleVectorTuple(v);\n}\n\n#ifdef LOGK\n#define DEBUG(fmt, ...) fprintf(stderr,\
    \ \"[Debug]    \" fmt __VA_OPT__(,) __VA_ARGS__)\n#define VARIABLE(var) cerr <<\
    \ \"# \" << #var << \" = \" << var << endl;\n#else\n#define DEBUG(...) 42\n#define\
    \ VARIABLE(...) 42\n#endif\n\n// ==============================================================\n\
    // \n// Main Program Start\n// \n// =============================================================="
  dependsOn: []
  isVerificationFile: false
  path: library/Template.hpp
  requiredBy:
  - library/TemplateExtend.hpp
  timestamp: '2024-07-26 22:56:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Template.hpp
layout: document
redirect_from:
- /library/library/Template.hpp
- /library/library/Template.hpp.html
title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
