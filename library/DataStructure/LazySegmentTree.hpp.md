---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-D-Lazy.test.cpp
    title: verify/AOJ-DSL-2-D-Lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-E-Lazy.test.cpp
    title: verify/AOJ-DSL-2-E-Lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-F.test.cpp
    title: verify/AOJ-DSL-2-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-G.test.cpp
    title: verify/AOJ-DSL-2-G.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-H.test.cpp
    title: verify/AOJ-DSL-2-H.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-2-I.test.cpp
    title: verify/AOJ-DSL-2-I.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-RangeAffineRangeSum.test.cpp
    title: verify/LC-RangeAffineRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_old/AOJ-GRL-5-E.test.cpp
    title: verify_old/AOJ-GRL-5-E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Lazy Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"library/DataStructure/LazySegmentTree.hpp\"\n/**\n * @file\
    \ LazySegmentTree.hpp\n * @author log K (lX57)\n * @brief Lazy Segment Tree -\
    \ \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @version 2.0\n\
    \ * @date 2023-10-02\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    template<typename Monoid, typename OperatorMonoid = Monoid>\nstruct LazySegmentTree{\n\
    \    private:\n    using F = function<Monoid(Monoid, Monoid)>;\n    using G =\
    \ function<Monoid(Monoid, OperatorMonoid)>;\n    using H = function<OperatorMonoid(OperatorMonoid,\
    \ OperatorMonoid)>;\n\n    int __Size, __Offset, __ZeroIndex;\n    vector<Monoid>\
    \ __Data;\n    vector<OperatorMonoid> __Lazy;\n    const F f;\n    const G g;\n\
    \    const H h;\n    const Monoid __M1;\n    const OperatorMonoid __OM1;\n\n \
    \   inline void __Check(int x){\n        assert(1 <= x && x <= __Size);\n    }\n\
    \n    void __eval(int k){\n        if(__Lazy[k] == __OM1) return;\n        if(k\
    \ < __Size){\n            __Lazy[k * 2 + 0] = h(__Lazy[k * 2 + 0], __Lazy[k]);\n\
    \            __Lazy[k * 2 + 1] = h(__Lazy[k * 2 + 1], __Lazy[k]);\n        }\n\
    \        __Data[k] = g(__Data[k], __Lazy[k]);\n        __Lazy[k] = __OM1;\n  \
    \  }\n\n    void __update(int ul, int ur, OperatorMonoid x, int left, int right,\
    \ int cell){\n        __eval(cell);\n        if(ul <= left && right <= ur){\n\
    \            __Lazy[cell] = h(__Lazy[cell], x);\n            __eval(cell);\n \
    \       }\n        else if(ul < right && left < ur){\n            int mid = (left\
    \ + right) / 2;\n            __update(ul, ur, x, left, mid, cell * 2 + 0);\n \
    \           __update(ul, ur, x, mid, right, cell * 2 + 1);\n            __Data[cell]\
    \ = f(__Data[cell * 2 + 0], __Data[cell * 2 + 1]);\n        }\n    }\n\n    Monoid\
    \ __query(int ql, int qr, int left, int right, int cell){\n        __eval(cell);\n\
    \        if(qr <= left || right <= ql){\n            return __M1;\n        }\n\
    \        if(ql <= left && right <= qr){\n            return __Data[cell];\n  \
    \      }\n        int mid = (left + right) / 2;\n        Monoid ans_left = __query(ql,\
    \ qr, left, mid, cell * 2 + 0);\n        Monoid ans_right = __query(ql, qr, mid,\
    \ right, cell * 2 + 1);\n        return f(ans_left, ans_right);\n    }\n\n   \
    \ public:\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\
    \u7D20\u6570 `Size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param\
    \ Size \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\n     * @param\
    \ Merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param\
    \ Mapping \u9045\u5EF6\u8A55\u4FA1\u306E\u9069\u7528\u3092\u884C\u3046\u6F14\u7B97\
    \n     * @param Composite \u9045\u5EF6\u8A55\u4FA1\u306E\u5408\u6210\u3092\u884C\
    \u3046\u6F14\u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\u30C9\u306E\
    \u5358\u4F4D\u5143\n     * @param OperatorMonoid_Identity \u64CD\u4F5C\u30E2\u30CE\
    \u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\u3057\
    \u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    LazySegmentTree(int\
    \ Size, F Merge, G Mapping, H Composite,\n    const Monoid &Monoid_Identity, const\
    \ OperatorMonoid &OperatorMonoid_Identity, bool ZeroIndex = false)\n    : f(Merge),\
    \ g(Mapping), h(Composite), __M1(Monoid_Identity), __OM1(OperatorMonoid_Identity),\
    \ __ZeroIndex(ZeroIndex){\n        __Size = 1;\n        while(__Size < Size) __Size\
    \ <<= 1;\n        __Offset = __Size - 1;\n        __Data.resize(2 * __Size, __M1);\n\
    \        __Lazy.resize(2 * __Size, __OM1);\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention\
    \ \u5FC5\u305A `set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\
    \u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n     */\n    void build(){\n\
    \        for(int i = __Offset; i >= 1; --i){\n            __Data[i] = f(__Data[i\
    \ * 2 + 0], __Data[i * 2 + 1]);\n        }\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\
    \u308B\u3002\n     * @param Index \u4EE3\u5165\u5148\u306E\u8981\u7D20\u756A\u53F7\
    \ (default = 1-index)\n     * @param Value \u4EE3\u5165\u3059\u308B\u5024\n  \
    \   */\n    void set(int Index, Monoid Value){\n        __Check(Index + __ZeroIndex);\n\
    \        __Data[__Offset + Index + __ZeroIndex] = Value;\n    }\n\n    /**\n \
    \    * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u914D\u5217 `Init_Data`\
    \ \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Init_Data \u521D\u671F\
    \u30C7\u30FC\u30BF\u306E\u914D\u5217\n     * @param Merge \u533A\u9593\u53D6\u5F97\
    \u3092\u884C\u3046\u6F14\u7B97\n     * @param Mapping \u9045\u5EF6\u8A55\u4FA1\
    \u306E\u9069\u7528\u3092\u884C\u3046\u6F14\u7B97\n     * @param Composite \u9045\
    \u5EF6\u8A55\u4FA1\u306E\u5408\u6210\u3092\u884C\u3046\u6F14\u7B97\n     * @param\
    \ Monoid_Identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param\
    \ OperatorMonoid_Identity \u64CD\u4F5C\u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B (default = `false`)\n     */\n    LazySegmentTree(vector<Monoid> &Init_Data,\
    \ F Merge, G Mapping, H Composite,\n    const Monoid &Monoid_Identity, const OperatorMonoid\
    \ &OperatorMonoid_Identity, bool ZeroIndex = false)\n    : f(Merge), g(Mapping),\
    \ h(Composite), __M1(Monoid_Identity), __OM1(OperatorMonoid_Identity), __ZeroIndex(ZeroIndex){\n\
    \        __Size = 1;\n        while(__Size < (int)Init_Data.size()) __Size <<=\
    \ 1;\n        __Offset = __Size - 1;\n        __Data.resize(2 * __Size, __M1);\n\
    \        __Lazy.resize(2 * __Size, __OM1);\n        for(int i = 0; i < (int)Init_Data.size();\
    \ ++i){\n            __Data[__Size + i] = Init_Data[i];\n        }\n        build();\n\
    \    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[left, Right)` \u306B\
    \u5BFE\u3057\u3066\u533A\u9593\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\
    \u3059\u308B\u3002\n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\
    \n     * @param Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @param\
    \ OP \u66F4\u65B0\u64CD\u4F5C\n     */\n    void update(int Left, int Right, OperatorMonoid\
    \ OP){\n        __Check(Left + __ZeroIndex);\n        __Check(Right + __ZeroIndex\
    \ - 1);\n        __update(Left + __ZeroIndex, Right + __ZeroIndex, OP, 1, __Size\
    \ + 1, 1);\n    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[Left, Right)`\
    \ \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\u884C\
    \u3046\u3002\n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n\
    \     * @param Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid query(int Left,\
    \ int Right){\n        __Check(Left + __ZeroIndex);\n        __Check(Right + __ZeroIndex\
    \ - 1);\n        return __query(Left + __ZeroIndex, Right + __ZeroIndex, 1, __Size\
    \ + 1, 1);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\
    \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param k \u53D6\u5F97\
    \u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     * @return Monoid\
    \ \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid get(int k){\n    \
    \    __Check(k + __ZeroIndex);\n        return query(k, k + 1);\n    }\n\n   \
    \ Monoid operator[](const int &k){\n        return get(k);\n    }\n\n    void\
    \ print(){\n        int cnt = 1, i = 1, depth = 1;\n        while(1){\n      \
    \      if(i >= __Size * 2) break;\n            cerr << depth++ << \" : \";\n \
    \           for(int c = 0; c < cnt; ++c){\n                cerr << __Data[i++]\
    \ << \" \";\n            }\n            cerr << endl;\n            cnt <<= 1;\n\
    \        }\n    }\n};\n"
  code: "/**\n * @file LazySegmentTree.hpp\n * @author log K (lX57)\n * @brief Lazy\
    \ Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n\
    \ * @version 2.0\n * @date 2023-10-02\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate<typename Monoid, typename OperatorMonoid = Monoid>\n\
    struct LazySegmentTree{\n    private:\n    using F = function<Monoid(Monoid, Monoid)>;\n\
    \    using G = function<Monoid(Monoid, OperatorMonoid)>;\n    using H = function<OperatorMonoid(OperatorMonoid,\
    \ OperatorMonoid)>;\n\n    int __Size, __Offset, __ZeroIndex;\n    vector<Monoid>\
    \ __Data;\n    vector<OperatorMonoid> __Lazy;\n    const F f;\n    const G g;\n\
    \    const H h;\n    const Monoid __M1;\n    const OperatorMonoid __OM1;\n\n \
    \   inline void __Check(int x){\n        assert(1 <= x && x <= __Size);\n    }\n\
    \n    void __eval(int k){\n        if(__Lazy[k] == __OM1) return;\n        if(k\
    \ < __Size){\n            __Lazy[k * 2 + 0] = h(__Lazy[k * 2 + 0], __Lazy[k]);\n\
    \            __Lazy[k * 2 + 1] = h(__Lazy[k * 2 + 1], __Lazy[k]);\n        }\n\
    \        __Data[k] = g(__Data[k], __Lazy[k]);\n        __Lazy[k] = __OM1;\n  \
    \  }\n\n    void __update(int ul, int ur, OperatorMonoid x, int left, int right,\
    \ int cell){\n        __eval(cell);\n        if(ul <= left && right <= ur){\n\
    \            __Lazy[cell] = h(__Lazy[cell], x);\n            __eval(cell);\n \
    \       }\n        else if(ul < right && left < ur){\n            int mid = (left\
    \ + right) / 2;\n            __update(ul, ur, x, left, mid, cell * 2 + 0);\n \
    \           __update(ul, ur, x, mid, right, cell * 2 + 1);\n            __Data[cell]\
    \ = f(__Data[cell * 2 + 0], __Data[cell * 2 + 1]);\n        }\n    }\n\n    Monoid\
    \ __query(int ql, int qr, int left, int right, int cell){\n        __eval(cell);\n\
    \        if(qr <= left || right <= ql){\n            return __M1;\n        }\n\
    \        if(ql <= left && right <= qr){\n            return __Data[cell];\n  \
    \      }\n        int mid = (left + right) / 2;\n        Monoid ans_left = __query(ql,\
    \ qr, left, mid, cell * 2 + 0);\n        Monoid ans_right = __query(ql, qr, mid,\
    \ right, cell * 2 + 1);\n        return f(ans_left, ans_right);\n    }\n\n   \
    \ public:\n    /**\n     * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\
    \u7D20\u6570 `Size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param\
    \ Size \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\n     * @param\
    \ Merge \u533A\u9593\u53D6\u5F97\u3092\u884C\u3046\u6F14\u7B97\n     * @param\
    \ Mapping \u9045\u5EF6\u8A55\u4FA1\u306E\u9069\u7528\u3092\u884C\u3046\u6F14\u7B97\
    \n     * @param Composite \u9045\u5EF6\u8A55\u4FA1\u306E\u5408\u6210\u3092\u884C\
    \u3046\u6F14\u7B97\n     * @param Monoid_Identity \u30E2\u30CE\u30A4\u30C9\u306E\
    \u5358\u4F4D\u5143\n     * @param OperatorMonoid_Identity \u64CD\u4F5C\u30E2\u30CE\
    \u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\u3057\
    \u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    LazySegmentTree(int\
    \ Size, F Merge, G Mapping, H Composite,\n    const Monoid &Monoid_Identity, const\
    \ OperatorMonoid &OperatorMonoid_Identity, bool ZeroIndex = false)\n    : f(Merge),\
    \ g(Mapping), h(Composite), __M1(Monoid_Identity), __OM1(OperatorMonoid_Identity),\
    \ __ZeroIndex(ZeroIndex){\n        __Size = 1;\n        while(__Size < Size) __Size\
    \ <<= 1;\n        __Offset = __Size - 1;\n        __Data.resize(2 * __Size, __M1);\n\
    \        __Lazy.resize(2 * __Size, __OM1);\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention\
    \ \u5FC5\u305A `set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\
    \u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n     */\n    void build(){\n\
    \        for(int i = __Offset; i >= 1; --i){\n            __Data[i] = f(__Data[i\
    \ * 2 + 0], __Data[i * 2 + 1]);\n        }\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\
    \u308B\u3002\n     * @param Index \u4EE3\u5165\u5148\u306E\u8981\u7D20\u756A\u53F7\
    \ (default = 1-index)\n     * @param Value \u4EE3\u5165\u3059\u308B\u5024\n  \
    \   */\n    void set(int Index, Monoid Value){\n        __Check(Index + __ZeroIndex);\n\
    \        __Data[__Offset + Index + __ZeroIndex] = Value;\n    }\n\n    /**\n \
    \    * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u914D\u5217 `Init_Data`\
    \ \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Init_Data \u521D\u671F\
    \u30C7\u30FC\u30BF\u306E\u914D\u5217\n     * @param Merge \u533A\u9593\u53D6\u5F97\
    \u3092\u884C\u3046\u6F14\u7B97\n     * @param Mapping \u9045\u5EF6\u8A55\u4FA1\
    \u306E\u9069\u7528\u3092\u884C\u3046\u6F14\u7B97\n     * @param Composite \u9045\
    \u5EF6\u8A55\u4FA1\u306E\u5408\u6210\u3092\u884C\u3046\u6F14\u7B97\n     * @param\
    \ Monoid_Identity \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param\
    \ OperatorMonoid_Identity \u64CD\u4F5C\u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B (default = `false`)\n     */\n    LazySegmentTree(vector<Monoid> &Init_Data,\
    \ F Merge, G Mapping, H Composite,\n    const Monoid &Monoid_Identity, const OperatorMonoid\
    \ &OperatorMonoid_Identity, bool ZeroIndex = false)\n    : f(Merge), g(Mapping),\
    \ h(Composite), __M1(Monoid_Identity), __OM1(OperatorMonoid_Identity), __ZeroIndex(ZeroIndex){\n\
    \        __Size = 1;\n        while(__Size < (int)Init_Data.size()) __Size <<=\
    \ 1;\n        __Offset = __Size - 1;\n        __Data.resize(2 * __Size, __M1);\n\
    \        __Lazy.resize(2 * __Size, __OM1);\n        for(int i = 0; i < (int)Init_Data.size();\
    \ ++i){\n            __Data[__Size + i] = Init_Data[i];\n        }\n        build();\n\
    \    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[left, Right)` \u306B\
    \u5BFE\u3057\u3066\u533A\u9593\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\
    \u3059\u308B\u3002\n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\
    \n     * @param Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @param\
    \ OP \u66F4\u65B0\u64CD\u4F5C\n     */\n    void update(int Left, int Right, OperatorMonoid\
    \ OP){\n        __Check(Left + __ZeroIndex);\n        __Check(Right + __ZeroIndex\
    \ - 1);\n        __update(Left + __ZeroIndex, Right + __ZeroIndex, OP, 1, __Size\
    \ + 1, 1);\n    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[Left, Right)`\
    \ \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\u884C\
    \u3046\u3002\n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n\
    \     * @param Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid query(int Left,\
    \ int Right){\n        __Check(Left + __ZeroIndex);\n        __Check(Right + __ZeroIndex\
    \ - 1);\n        return __query(Left + __ZeroIndex, Right + __ZeroIndex, 1, __Size\
    \ + 1, 1);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\
    \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param k \u53D6\u5F97\
    \u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     * @return Monoid\
    \ \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid get(int k){\n    \
    \    __Check(k + __ZeroIndex);\n        return query(k, k + 1);\n    }\n\n   \
    \ Monoid operator[](const int &k){\n        return get(k);\n    }\n\n    void\
    \ print(){\n        int cnt = 1, i = 1, depth = 1;\n        while(1){\n      \
    \      if(i >= __Size * 2) break;\n            cerr << depth++ << \" : \";\n \
    \           for(int c = 0; c < cnt; ++c){\n                cerr << __Data[i++]\
    \ << \" \";\n            }\n            cerr << endl;\n            cnt <<= 1;\n\
    \        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2023-11-06 01:36:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_old/AOJ-GRL-5-E.test.cpp
  - verify/AOJ-DSL-2-E-Lazy.test.cpp
  - verify/LC-RangeAffineRangeSum.test.cpp
  - verify/AOJ-DSL-2-H.test.cpp
  - verify/AOJ-DSL-2-D-Lazy.test.cpp
  - verify/AOJ-DSL-2-I.test.cpp
  - verify/AOJ-DSL-2-G.test.cpp
  - verify/AOJ-DSL-2-F.test.cpp
documentation_of: library/DataStructure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/library/DataStructure/LazySegmentTree.hpp
- /library/library/DataStructure/LazySegmentTree.hpp.html
title: "Lazy Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\
  \u6728"
---
