---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_latest/LC-PointAddRangeSum.test.cpp
    title: verify_latest/LC-PointAddRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"latest/DataStructure/SegmentTree.hpp\"\n\n\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename Monoid>\nstruct SegmentTree{\n    private:\n\
    \    using F = function<Monoid(Monoid, Monoid)>;\n\n    int __Size, __Offset,\
    \ __ZeroIndex;\n    vector<Monoid> __Data;\n    const F f;\n    const Monoid __M1;\n\
    \n    inline void __Check(int x){\n        assert(1 <= x && x <= __Size);\n  \
    \  }\n\n    Monoid __query(int ql, int qr, int left, int right, int cell){\n \
    \       if(qr <= left || right <= ql){\n            return __M1;\n        }\n\
    \        if(ql <= left && right <= qr){\n            return __Data[cell];\n  \
    \      }\n        int mid = (left + right) / 2;\n        Monoid ans_left = __query(ql,\
    \ qr, left, mid, 2 * cell);\n        Monoid ans_right = __query(ql, qr, mid, right,\
    \ 2 * cell + 1);\n        return f(ans_left, ans_right);\n    }\n\n    public:\n\
    \    SegmentTree(int Size, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex\
    \ = false) : f(Merge), __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){\n      \
    \  __Size = 1;\n        while(__Size < Size) __Size <<= 1;\n        __Offset =\
    \ __Size - 1;\n        __Data.resize(2 * __Size, __M1);\n    }\n\n    void build(){\n\
    \        for(int i = __Offset; i >= 1; --i){\n            __Data[i] = f(__Data[i\
    \ * 2 + 0], __Data[i * 2 + 1]);\n        }\n    }\n\n    void set(int Index, Monoid\
    \ Value){\n        __Check(Index + __ZeroIndex);\n        __Data[__Offset + Index\
    \ + __ZeroIndex] = Value;\n    }\n\n    SegmentTree(vector<Monoid> &Init_Data,\
    \ F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false) : f(Merge),\
    \ __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){\n        __Size = 1;\n      \
    \  while(__Size < (int)Init_Data.size()) __Size <<= 1;\n        __Offset = __Size\
    \ - 1;\n        __Data.resize(2 * __Size, __M1);\n        for(int i = 0; i < (int)Init_Data.size();\
    \ ++i){\n            __Data[__Size + i] = Init_Data[i];\n        }\n        build();\n\
    \    }\n\n    void update(int Index, Monoid Value){\n        __Check(Index + __ZeroIndex);\n\
    \        int k = __Offset + Index + __ZeroIndex;\n        __Data[k] = Value;\n\
    \        while(k >>= 1){\n            __Data[k] = f(__Data[2 * k], __Data[2 *\
    \ k + 1]);\n        }\n    }\n\n    Monoid query(int Left, int Right){\n     \
    \   __Check(Left + __ZeroIndex);\n        __Check(Right + __ZeroIndex - 1);\n\
    \        return __query(Left + __ZeroIndex, Right + __ZeroIndex, 1, __Size + 1,\
    \ 1);\n    }\n\n    Monoid get(int k){\n        __Check(k + __ZeroIndex);\n  \
    \      return __Data[__Offset + k + __ZeroIndex];\n    }\n\n    Monoid operator[](const\
    \ int &k){\n        return get(k);\n    }\n};\n"
  code: "\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename\
    \ Monoid>\nstruct SegmentTree{\n    private:\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n\n    int __Size, __Offset, __ZeroIndex;\n    vector<Monoid> __Data;\n\
    \    const F f;\n    const Monoid __M1;\n\n    inline void __Check(int x){\n \
    \       assert(1 <= x && x <= __Size);\n    }\n\n    Monoid __query(int ql, int\
    \ qr, int left, int right, int cell){\n        if(qr <= left || right <= ql){\n\
    \            return __M1;\n        }\n        if(ql <= left && right <= qr){\n\
    \            return __Data[cell];\n        }\n        int mid = (left + right)\
    \ / 2;\n        Monoid ans_left = __query(ql, qr, left, mid, 2 * cell);\n    \
    \    Monoid ans_right = __query(ql, qr, mid, right, 2 * cell + 1);\n        return\
    \ f(ans_left, ans_right);\n    }\n\n    public:\n    SegmentTree(int Size, F Merge,\
    \ const Monoid &Monoid_Identity, bool ZeroIndex = false) : f(Merge), __M1(Monoid_Identity),\
    \ __ZeroIndex(ZeroIndex){\n        __Size = 1;\n        while(__Size < Size) __Size\
    \ <<= 1;\n        __Offset = __Size - 1;\n        __Data.resize(2 * __Size, __M1);\n\
    \    }\n\n    void build(){\n        for(int i = __Offset; i >= 1; --i){\n   \
    \         __Data[i] = f(__Data[i * 2 + 0], __Data[i * 2 + 1]);\n        }\n  \
    \  }\n\n    void set(int Index, Monoid Value){\n        __Check(Index + __ZeroIndex);\n\
    \        __Data[__Offset + Index + __ZeroIndex] = Value;\n    }\n\n    SegmentTree(vector<Monoid>\
    \ &Init_Data, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)\
    \ : f(Merge), __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){\n        __Size =\
    \ 1;\n        while(__Size < (int)Init_Data.size()) __Size <<= 1;\n        __Offset\
    \ = __Size - 1;\n        __Data.resize(2 * __Size, __M1);\n        for(int i =\
    \ 0; i < (int)Init_Data.size(); ++i){\n            __Data[__Size + i] = Init_Data[i];\n\
    \        }\n        build();\n    }\n\n    void update(int Index, Monoid Value){\n\
    \        __Check(Index + __ZeroIndex);\n        int k = __Offset + Index + __ZeroIndex;\n\
    \        __Data[k] = Value;\n        while(k >>= 1){\n            __Data[k] =\
    \ f(__Data[2 * k], __Data[2 * k + 1]);\n        }\n    }\n\n    Monoid query(int\
    \ Left, int Right){\n        __Check(Left + __ZeroIndex);\n        __Check(Right\
    \ + __ZeroIndex - 1);\n        return __query(Left + __ZeroIndex, Right + __ZeroIndex,\
    \ 1, __Size + 1, 1);\n    }\n\n    Monoid get(int k){\n        __Check(k + __ZeroIndex);\n\
    \        return __Data[__Offset + k + __ZeroIndex];\n    }\n\n    Monoid operator[](const\
    \ int &k){\n        return get(k);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: latest/DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2023-09-02 20:49:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_latest/LC-PointAddRangeSum.test.cpp
documentation_of: latest/DataStructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/latest/DataStructure/SegmentTree.hpp
- /library/latest/DataStructure/SegmentTree.hpp.html
title: latest/DataStructure/SegmentTree.hpp
---
