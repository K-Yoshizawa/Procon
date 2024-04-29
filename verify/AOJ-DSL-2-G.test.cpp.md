---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/LazySegmentTree.hpp
    title: "Lazy Segment Tree - \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"verify/AOJ-DSL-2-G.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#line 1 \"library/DataStructure/LazySegmentTree.hpp\"\n/**\n * @file LazySegmentTree.hpp\n\
    \ * @author log K (lX57)\n * @brief Lazy Segment Tree - \u9045\u5EF6\u8A55\u4FA1\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @version 2.0\n * @date 2023-10-02\n */\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename Monoid,\
    \ typename OperatorMonoid = Monoid>\nstruct LazySegmentTree{\n    private:\n \
    \   using F = function<Monoid(Monoid, Monoid)>;\n    using G = function<Monoid(Monoid,\
    \ OperatorMonoid)>;\n    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;\n\
    \n    int size_, offset_, zeroindex_;\n    vector<Monoid> data_;\n    vector<OperatorMonoid>\
    \ lazy_;\n    const F f;\n    const G g;\n    const H h;\n    const Monoid m1_;\n\
    \    const OperatorMonoid om1_;\n\n    inline void check_(int x){\n        assert(1\
    \ <= x && x <= size_);\n    }\n\n    void eval_(int k){\n        if(lazy_[k] ==\
    \ om1_) return;\n        if(k < size_){\n            lazy_[k * 2 + 0] = h(lazy_[k\
    \ * 2 + 0], lazy_[k]);\n            lazy_[k * 2 + 1] = h(lazy_[k * 2 + 1], lazy_[k]);\n\
    \        }\n        data_[k] = g(data_[k], lazy_[k]);\n        lazy_[k] = om1_;\n\
    \    }\n\n    void update_(int ul, int ur, OperatorMonoid x, int left, int right,\
    \ int cell){\n        eval_(cell);\n        if(ul <= left && right <= ur){\n \
    \           lazy_[cell] = h(lazy_[cell], x);\n            eval_(cell);\n     \
    \   }\n        else if(ul < right && left < ur){\n            int mid = (left\
    \ + right) / 2;\n            update_(ul, ur, x, left, mid, cell * 2 + 0);\n  \
    \          update_(ul, ur, x, mid, right, cell * 2 + 1);\n            data_[cell]\
    \ = f(data_[cell * 2 + 0], data_[cell * 2 + 1]);\n        }\n    }\n\n    Monoid\
    \ query_(int ql, int qr, int left, int right, int cell){\n        eval_(cell);\n\
    \        if(qr <= left || right <= ql){\n            return m1_;\n        }\n\
    \        if(ql <= left && right <= qr){\n            return data_[cell];\n   \
    \     }\n        int mid = (left + right) / 2;\n        Monoid ans_left = query_(ql,\
    \ qr, left, mid, cell * 2 + 0);\n        Monoid ans_right = query_(ql, qr, mid,\
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
    \ g(Mapping), h(Composite), m1_(Monoid_Identity), om1_(OperatorMonoid_Identity),\
    \ zeroindex_(ZeroIndex){\n        size_ = 1;\n        while(size_ < Size) size_\
    \ <<= 1;\n        offset_ = size_ - 1;\n        data_.resize(2 * size_, m1_);\n\
    \        lazy_.resize(2 * size_, om1_);\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @attention\
    \ \u5FC5\u305A `set()` \u3067\u521D\u671F\u5024\u3092\u4EE3\u5165\u3057\u3066\u304B\
    \u3089\u547C\u3073\u51FA\u3059\u3053\u3068\uFF01\n     */\n    void build(){\n\
    \        for(int i = offset_; i >= 1; --i){\n            data_[i] = f(data_[i\
    \ * 2 + 0], data_[i * 2 + 1]);\n        }\n    }\n\n    /**\n     * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u306E\u521D\u671F\u5024\u3092\u4EE3\u5165\u3059\
    \u308B\u3002\n     * @param Index \u4EE3\u5165\u5148\u306E\u8981\u7D20\u756A\u53F7\
    \ (default = 1-index)\n     * @param Value \u4EE3\u5165\u3059\u308B\u5024\n  \
    \   */\n    void set(int Index, Monoid Value){\n        check_(Index + zeroindex_);\n\
    \        data_[offset_ + Index + zeroindex_] = Value;\n    }\n\n    /**\n    \
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u914D\u5217 `Init_Data`\
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
    \ h(Composite), m1_(Monoid_Identity), om1_(OperatorMonoid_Identity), zeroindex_(ZeroIndex){\n\
    \        size_ = 1;\n        while(size_ < (int)Init_Data.size()) size_ <<= 1;\n\
    \        offset_ = size_ - 1;\n        data_.resize(2 * size_, m1_);\n       \
    \ lazy_.resize(2 * size_, om1_);\n        for(int i = 0; i < (int)Init_Data.size();\
    \ ++i){\n            data_[size_ + i] = Init_Data[i];\n        }\n        build();\n\
    \    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[left, Right)` \u306B\
    \u5BFE\u3057\u3066\u533A\u9593\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\
    \u3059\u308B\u3002\n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\
    \n     * @param Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @param\
    \ OP \u66F4\u65B0\u64CD\u4F5C\n     */\n    void update(int Left, int Right, OperatorMonoid\
    \ OP){\n        check_(Left + zeroindex_);\n        check_(Right + zeroindex_\
    \ - 1);\n        update_(Left + zeroindex_, Right + zeroindex_, OP, 1, size_ +\
    \ 1, 1);\n    }\n\n    /**\n     * @brief \u534A\u958B\u533A\u9593 `[Left, Right)`\
    \ \u306B\u5BFE\u3057\u3066\u533A\u9593\u53D6\u5F97\u30AF\u30A8\u30EA\u3092\u884C\
    \u3046\u3002\n     * @param Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n\
    \     * @param Right \u534A\u958B\u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ Monoid \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid query(int Left,\
    \ int Right){\n        check_(Left + zeroindex_);\n        check_(Right + zeroindex_\
    \ - 1);\n        return query_(Left + zeroindex_, Right + zeroindex_, 1, size_\
    \ + 1, 1);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\
    \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param k \u53D6\u5F97\
    \u5148\u306E\u8981\u7D20\u756A\u53F7 (default = 1-index)\n     * @return Monoid\
    \ \u53D6\u5F97\u3057\u305F\u7D50\u679C\n     */\n    Monoid get(int k){\n    \
    \    check_(k + zeroindex_);\n        return query(k, k + 1);\n    }\n\n    Monoid\
    \ operator[](const int &k){\n        return get(k);\n    }\n\n    void print(){\n\
    \        int cnt = 1, i = 1, depth = 1;\n        while(1){\n            if(i >=\
    \ size_ * 2) break;\n            cerr << depth++ << \" : \";\n            for(int\
    \ c = 0; c < cnt; ++c){\n                cerr << data_[i++] << \" \";\n      \
    \      }\n            cerr << endl;\n            cnt <<= 1;\n        }\n    }\n\
    };\n#line 4 \"verify/AOJ-DSL-2-G.test.cpp\"\n\nstruct Data{\n    long long val{0};\n\
    \    long long len{1};\n\n    Data() : val(0), len(1){}\n    Data(int val, int\
    \ len) : val(val), len(len){}\n\n    bool operator==(const Data& y){\n       \
    \ return val == y.val && len == y.len;\n    }\n    \n    friend ostream &operator<<(ostream\
    \ &os, const Data &p) {\n        return os << \"{\" << p.val << \", \" << p.len\
    \ << \"}\";\n    }\n\n    static Data Merge(const Data& x, const Data& y){\n \
    \       Data ret;\n        ret.val = x.val + y.val;\n        ret.len = x.len +\
    \ y.len;\n        return ret;\n    }\n\n    static Data Mapping(const Data& x,\
    \ const int y){\n        Data ret;\n        ret.val = x.val + y * x.len;\n   \
    \     ret.len = x.len;\n        return ret;\n    }\n};\n\nint main(){\n    int\
    \ n, q; cin >> n >> q;\n    vector<Data> Init_Data(n, Data(0, 1));\n    LazySegmentTree<Data,\
    \ int> seg(Init_Data,\n        [](const Data l, const Data r){return Data::Merge(l,\
    \ r);},\n        [](const Data l, const int r){return Data::Mapping(l, r);},\n\
    \        [](const int l, const int r){return l + r;},\n        Data(), 0\n   \
    \ );\n    while(q--){\n        int query; cin >> query;\n        if(query == 0){\n\
    \            int s, t, x; cin >> s >> t >> x;\n            seg.update(s, t + 1,\
    \ x);\n        }\n        if(query == 1){\n            int s, t; cin >> s >> t;\n\
    \            cout << seg.query(s, t + 1).val << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#include \"../library/DataStructure/LazySegmentTree.hpp\"\n\nstruct Data{\n\
    \    long long val{0};\n    long long len{1};\n\n    Data() : val(0), len(1){}\n\
    \    Data(int val, int len) : val(val), len(len){}\n\n    bool operator==(const\
    \ Data& y){\n        return val == y.val && len == y.len;\n    }\n    \n    friend\
    \ ostream &operator<<(ostream &os, const Data &p) {\n        return os << \"{\"\
    \ << p.val << \", \" << p.len << \"}\";\n    }\n\n    static Data Merge(const\
    \ Data& x, const Data& y){\n        Data ret;\n        ret.val = x.val + y.val;\n\
    \        ret.len = x.len + y.len;\n        return ret;\n    }\n\n    static Data\
    \ Mapping(const Data& x, const int y){\n        Data ret;\n        ret.val = x.val\
    \ + y * x.len;\n        ret.len = x.len;\n        return ret;\n    }\n};\n\nint\
    \ main(){\n    int n, q; cin >> n >> q;\n    vector<Data> Init_Data(n, Data(0,\
    \ 1));\n    LazySegmentTree<Data, int> seg(Init_Data,\n        [](const Data l,\
    \ const Data r){return Data::Merge(l, r);},\n        [](const Data l, const int\
    \ r){return Data::Mapping(l, r);},\n        [](const int l, const int r){return\
    \ l + r;},\n        Data(), 0\n    );\n    while(q--){\n        int query; cin\
    \ >> query;\n        if(query == 0){\n            int s, t, x; cin >> s >> t >>\
    \ x;\n            seg.update(s, t + 1, x);\n        }\n        if(query == 1){\n\
    \            int s, t; cin >> s >> t;\n            cout << seg.query(s, t + 1).val\
    \ << endl;\n        }\n    }\n}"
  dependsOn:
  - library/DataStructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-2-G.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 18:47:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-2-G.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-2-G.test.cpp
- /verify/verify/AOJ-DSL-2-G.test.cpp.html
title: verify/AOJ-DSL-2-G.test.cpp
---
