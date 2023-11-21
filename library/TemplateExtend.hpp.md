---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/Template.hpp\"\n/**\n * @file Template.hpp\n * @author\
    \ log K (lX57)\n * @brief Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n *\
    \ @version 1.5\n * @date 2023-10-30\n */\n\n#include <bits/stdc++.h>\n#define\
    \ ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define\
    \ SORT(x) sort(ALL(x))\n#define RSORT(x) sort(RALL(x))\n#define REVERSE(x) reverse(ALL(x))\n\
    #define SETPRE(digit) fixed << setprecision(digit)\n#define POPCOUNT(x) __builtin_popcount(x)\n\
    #define SUM(x) reduce((x).begin(), (x).end())\n#define IOTA(x) iota((x).begin(),\
    \ (x).end(), 0)\n#define LOWERBOUND_IDX(x,val) (int)(lower_bound((x).begin(),\
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
    \ T cond, T excp){return (src == cond ? excp : src);}\ntemplate<typename T>\n\
    inline T min(vector<T> &v){return *min_element((v).begin(), (v).end());}\ntemplate<typename\
    \ T>\ninline T max(vector<T> &v){return *max_element((v).begin(), (v).end());}\n\
    vector<int> make_sequence(int Size){\n    vector<int> ret(Size);\n    IOTA(ret);\n\
    \    return ret;\n}\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\n\nconst long double PI = acosl(-1);\nconst long double\
    \ PI2 = PI * 2;\nconst long double PI_2 = PI / 2;\n\nconst int INF_INT = numeric_limits<int>::max()\
    \ / 2;\nconst long long INF_LL = numeric_limits<long long>::max() / 2LL;\n\ntemplate\
    \ <typename T>\nusing vec = vector<T>;\ntemplate <typename T>\nusing mat = vector<vector<T>>;\n\
    using vi = vector<int>;\nusing vvi = vector<vi>;\nusing vvvi = vector<vvi>;\n\
    using vl = vector<ll>;\nusing vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing\
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
    \ v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate<class... T>\nvoid\
    \ input(T&... vars){\n    (cin >> ... >> vars);\n}\n\nvoid print(){\n    cout\
    \ << '\\n';\n}\n\ntemplate<class T, class... Ts>\nvoid print(const T& a, const\
    \ Ts&... b){\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n    cout\
    \ << '\\n';\n}\n\n#ifdef LOGK\nvoid dprint(){\n    cerr << '\\n';\n}\n\ntemplate<class\
    \ T, class... Ts>\nvoid dprint(const T& a, const Ts&... b){\n    cerr << \"Debug\
    \ : \" << a;\n    (cerr << ... << (cerr << \" \", b));\n    cerr << '\\n';\n}\n\
    #else\n#define dprint(...) 42\n#endif\n\ntemplate <typename T>\nT ceil(T x, T\
    \ y){\n    return (x + y - 1) / y;\n}\n#line 2 \"library/TemplateExtend.hpp\"\n\
    \ntemplate <typename T>\ninline long long EuclideanDist2(const pair<T, T> &p1,\
    \ const pair<T, T> &p2){\n    long long dx = (long long)p1.first - (long long)p2.first;\n\
    \    long long dy = (long long)p1.second - (long long)p2.second;\n    return dx\
    \ * dx + dy * dy;\n}\n\ntemplate <typename T>\ninline long long EuclideanDist2(const\
    \ pair<T, T> &p){\n    return EuclideanDist2(p, make_pair(0, 0));\n}\n\ntemplate\
    \ <typename T>\ninline long double EuclideanDist(const pair<T, T> &p1, const pair<T,\
    \ T> &p2){\n    return sqrtl((long double)EuclideanDist2(p1, p2));\n}\n\ntemplate\
    \ <typename T>\ninline long double EuclideanDist(const pair<T, T> &p){\n    return\
    \ sqrtl((long double)EuclideanDist2(p));\n}\n\ntemplate<typename T>\ninline long\
    \ long ManhattanDist(const pair<T, T> &p1, const pair<T, T> &p2){\n    return\
    \ abs(p1.first - p2.first) + abs(p1.second - p2.second);\n}\n\nll modpow(ll a,\
    \ ll b, ll m){\n    ll p = 1, q = a;\n    for (int i = 0; i < 63; ++i)\n    {\n\
    \        if ((b & (1LL << i)) != 0)\n        {\n            p *= q;\n        \
    \    p %= m;\n        }\n        q *= q;\n        q %= m;\n    }\n    return p;\n\
    }\n\ntemplate<typename T>\nT gcd(T a, T b) {\n    if(a < 0) a = -a;\n    if(b\
    \ < 0) b = -b;\n    if(b == 0) return a;\n    else return gcd(b, a % b);\n}\n\n\
    ull lcm(ull a, ull b) {\n    return a * b / gcd(a, b);\n}\n\nstring bitseq(long\
    \ long x, int mini_len = 1, bool rev = false){\n    string ret = \"\";\n    while(x){\n\
    \        ret.push_back('0' + (x & 1));\n        x >>= 1;\n    }\n    while(ret.size()<mini_len)\
    \ ret.push_back('0');\n    if(!rev) reverse(ret.begin(), ret.end());\n    return\
    \ ret;\n}\n"
  code: "#include \"Template.hpp\"\n\ntemplate <typename T>\ninline long long EuclideanDist2(const\
    \ pair<T, T> &p1, const pair<T, T> &p2){\n    long long dx = (long long)p1.first\
    \ - (long long)p2.first;\n    long long dy = (long long)p1.second - (long long)p2.second;\n\
    \    return dx * dx + dy * dy;\n}\n\ntemplate <typename T>\ninline long long EuclideanDist2(const\
    \ pair<T, T> &p){\n    return EuclideanDist2(p, make_pair(0, 0));\n}\n\ntemplate\
    \ <typename T>\ninline long double EuclideanDist(const pair<T, T> &p1, const pair<T,\
    \ T> &p2){\n    return sqrtl((long double)EuclideanDist2(p1, p2));\n}\n\ntemplate\
    \ <typename T>\ninline long double EuclideanDist(const pair<T, T> &p){\n    return\
    \ sqrtl((long double)EuclideanDist2(p));\n}\n\ntemplate<typename T>\ninline long\
    \ long ManhattanDist(const pair<T, T> &p1, const pair<T, T> &p2){\n    return\
    \ abs(p1.first - p2.first) + abs(p1.second - p2.second);\n}\n\nll modpow(ll a,\
    \ ll b, ll m){\n    ll p = 1, q = a;\n    for (int i = 0; i < 63; ++i)\n    {\n\
    \        if ((b & (1LL << i)) != 0)\n        {\n            p *= q;\n        \
    \    p %= m;\n        }\n        q *= q;\n        q %= m;\n    }\n    return p;\n\
    }\n\ntemplate<typename T>\nT gcd(T a, T b) {\n    if(a < 0) a = -a;\n    if(b\
    \ < 0) b = -b;\n    if(b == 0) return a;\n    else return gcd(b, a % b);\n}\n\n\
    ull lcm(ull a, ull b) {\n    return a * b / gcd(a, b);\n}\n\nstring bitseq(long\
    \ long x, int mini_len = 1, bool rev = false){\n    string ret = \"\";\n    while(x){\n\
    \        ret.push_back('0' + (x & 1));\n        x >>= 1;\n    }\n    while(ret.size()<mini_len)\
    \ ret.push_back('0');\n    if(!rev) reverse(ret.begin(), ret.end());\n    return\
    \ ret;\n}"
  dependsOn:
  - library/Template.hpp
  isVerificationFile: false
  path: library/TemplateExtend.hpp
  requiredBy: []
  timestamp: '2023-11-21 13:10:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/TemplateExtend.hpp
layout: document
redirect_from:
- /library/library/TemplateExtend.hpp
- /library/library/TemplateExtend.hpp.html
title: library/TemplateExtend.hpp
---
