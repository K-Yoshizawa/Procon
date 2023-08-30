---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"latest/Template.hpp\"\n\n/**\n * @file Template.hpp\n *\
    \ @author log K (lX57)\n * @brief Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @version 2.0\n * @date 2023-08-30\n */\n\n#include <bits/stdc++.h>\n#define\
    \ ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define\
    \ SORT(x) sort(ALL(x))\n#define RSORT(x) sort(RALL(x))\n#define REVERSE(x) reverse(ALL(x))\n\
    #define SETPRE(digit) fixed << setprecision(digit)\n#define popcount(x) __builtin_popcount(x)\n\
    #define ACC(x) accumulate((x).begin(), (x).end(), 0LL)\n#define LOWERBOUND_IDX(x,val)\
    \ (int)(lower_bound((x).begin(), (x).end(), val) - (x).begin())\n#define UPPERBOUND_IDX(x,val)\
    \ (int)(upper_bound((x).begin(), (x).end(), val) - (x).begin())\nusing namespace\
    \ std;\n\ninline string Yn(bool flag){return (flag) ? \"Yes\" : \"No\";}\ninline\
    \ bool YnPrint(bool flag){cout << Yn(flag) << endl;return flag;}\ninline string\
    \ YN(bool flag){return (flag) ? \"YES\" : \"NO\";}\ninline bool YNPrint(bool flag){cout\
    \ << YN(flag) << endl;return flag;}\ntemplate<class T>\nbool minin(T &src, const\
    \ T &cmp){if(src > cmp){src = cmp; return true;}return false;}\ntemplate<class\
    \ T>\nbool maxin(T &src, const T &cmp){if(src < cmp){src = cmp; return true;}return\
    \ false;}\ntemplate<typename T>\ninline bool between(T min, T x, T max){return\
    \ min <= x && x <= max;}\ntemplate<typename T>\ninline bool ingrid(T y, T x, T\
    \ ymax, T xmax){return between(0, y, ymax - 1) && between(0, x, xmax - 1);}\n\
    template<typename T>\ninline T median(T a, T b, T c){return between(b, a, c) ||\
    \ between(c, a, b) ? a : (between(a, b, c) || between(c, b, a) ? b : c);}\ntemplate<typename\
    \ T>\ninline T except(T src, T cond, T excp){return (src == cond ? excp : src);}\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    \nconst int INF_INT = numeric_limits<int>::max() / 2;\nconst long long INF_LL\
    \ = numeric_limits<long long>::max() / 2LL;\n\ntemplate <typename T>\nusing vec\
    \ = vector<T>;\ntemplate <typename T>\nusing mat = vector<vector<T>>;\nusing vi\
    \ = vector<int>;\nusing vvi = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vl\
    \ = vector<ll>;\nusing vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing pi\
    \ = pair<int, int>;\nusing pll = pair<ll, ll>;\nusing pd = pair<double, double>;\n\
    using ti3 = tuple<int, int, int>;\nusing tl3 = tuple<ll, ll, ll>;\nusing ti4 =\
    \ tuple<int, int, int, int>;\nusing tl4 = tuple<ll, ll, ll, ll>;\ntemplate <typename\
    \ T>\nusing pq = priority_queue<T>;\ntemplate <typename T>\nusing rpq = priority_queue<T,\
    \ vec<T>, greater<T>>;\n\ntemplate <typename T1, typename T2>\nistream &operator>>(istream\
    \ &is, pair<T1, T2> &p){\n    is >> p.first >> p.second;\n    return is;\n}\n\n\
    template <typename T>\nostream &operator<<(ostream &os, vector<T> &v){\n    for\
    \ (int i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1 != v.size() ?\
    \ \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, vector<vector<T>> &v){\n    for (int i = 0; i < v.size(); ++i){\n     \
    \   os << v[i] << \"\\n\";\n    }\n    return os;\n}\n\ntemplate <typename T>\n\
    istream &operator>>(istream &is, vector<T> &v){\n    for (int i = 0; i < v.size();\
    \ ++i) is >> v[i];\n    return is;\n}\n\ntemplate<class... T>\nvoid input(T&...\
    \ vars){\n    (cin >> ... >> vars);\n}\n\nvoid print(){\n    cout << '\\n';\n\
    }\n\ntemplate<class T, class... Ts>\nvoid print(const T& a, const Ts&... b){\n\
    \    cout << a;\n    (cout << ... << (cout << ' ', b));\n    cout << '\\n';\n\
    }\n\n#ifndef ONLINE_JUDGE\nvoid dprint(){\n    cerr << '\\n';\n}\n\ntemplate<class\
    \ T, class... Ts>\nvoid dprint(const T& a, const Ts&... b){\n    cerr << a;\n\
    \    (cerr << ... << (cerr << ' ', b));\n    cerr << '\\n';\n}\n#else\n#define\
    \ dprint(...) 42\n#endif\n\ntemplate <typename T>\nT ceil(T x, T y){\n    return\
    \ (x + y - 1) / y;\n}\n\n// Usual Template End ==================================================================================\n"
  code: "#pragma once\n\n/**\n * @file Template.hpp\n * @author log K (lX57)\n * @brief\
    \ Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 2.0\n * @date 2023-08-30\n\
    \ */\n\n#include <bits/stdc++.h>\n#define ALL(x) (x).begin(), (x).end()\n#define\
    \ RALL(x) (x).rbegin(), (x).rend()\n#define SORT(x) sort(ALL(x))\n#define RSORT(x)\
    \ sort(RALL(x))\n#define REVERSE(x) reverse(ALL(x))\n#define SETPRE(digit) fixed\
    \ << setprecision(digit)\n#define popcount(x) __builtin_popcount(x)\n#define ACC(x)\
    \ accumulate((x).begin(), (x).end(), 0LL)\n#define LOWERBOUND_IDX(x,val) (int)(lower_bound((x).begin(),\
    \ (x).end(), val) - (x).begin())\n#define UPPERBOUND_IDX(x,val) (int)(upper_bound((x).begin(),\
    \ (x).end(), val) - (x).begin())\nusing namespace std;\n\ninline string Yn(bool\
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
    \ T cond, T excp){return (src == cond ? excp : src);}\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\n\nconst int INF_INT\
    \ = numeric_limits<int>::max() / 2;\nconst long long INF_LL = numeric_limits<long\
    \ long>::max() / 2LL;\n\ntemplate <typename T>\nusing vec = vector<T>;\ntemplate\
    \ <typename T>\nusing mat = vector<vector<T>>;\nusing vi = vector<int>;\nusing\
    \ vvi = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vl = vector<ll>;\nusing\
    \ vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing pi = pair<int, int>;\nusing\
    \ pll = pair<ll, ll>;\nusing pd = pair<double, double>;\nusing ti3 = tuple<int,\
    \ int, int>;\nusing tl3 = tuple<ll, ll, ll>;\nusing ti4 = tuple<int, int, int,\
    \ int>;\nusing tl4 = tuple<ll, ll, ll, ll>;\ntemplate <typename T>\nusing pq =\
    \ priority_queue<T>;\ntemplate <typename T>\nusing rpq = priority_queue<T, vec<T>,\
    \ greater<T>>;\n\ntemplate <typename T1, typename T2>\nistream &operator>>(istream\
    \ &is, pair<T1, T2> &p){\n    is >> p.first >> p.second;\n    return is;\n}\n\n\
    template <typename T>\nostream &operator<<(ostream &os, vector<T> &v){\n    for\
    \ (int i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1 != v.size() ?\
    \ \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, vector<vector<T>> &v){\n    for (int i = 0; i < v.size(); ++i){\n     \
    \   os << v[i] << \"\\n\";\n    }\n    return os;\n}\n\ntemplate <typename T>\n\
    istream &operator>>(istream &is, vector<T> &v){\n    for (int i = 0; i < v.size();\
    \ ++i) is >> v[i];\n    return is;\n}\n\ntemplate<class... T>\nvoid input(T&...\
    \ vars){\n    (cin >> ... >> vars);\n}\n\nvoid print(){\n    cout << '\\n';\n\
    }\n\ntemplate<class T, class... Ts>\nvoid print(const T& a, const Ts&... b){\n\
    \    cout << a;\n    (cout << ... << (cout << ' ', b));\n    cout << '\\n';\n\
    }\n\n#ifndef ONLINE_JUDGE\nvoid dprint(){\n    cerr << '\\n';\n}\n\ntemplate<class\
    \ T, class... Ts>\nvoid dprint(const T& a, const Ts&... b){\n    cerr << a;\n\
    \    (cerr << ... << (cerr << ' ', b));\n    cerr << '\\n';\n}\n#else\n#define\
    \ dprint(...) 42\n#endif\n\ntemplate <typename T>\nT ceil(T x, T y){\n    return\
    \ (x + y - 1) / y;\n}\n\n// Usual Template End =================================================================================="
  dependsOn: []
  isVerificationFile: false
  path: latest/Template.hpp
  requiredBy: []
  timestamp: '2023-08-31 01:23:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: latest/Template.hpp
layout: document
redirect_from:
- /library/latest/Template.hpp
- /library/latest/Template.hpp.html
title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
