---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/KthMultiSet.hpp
    title: library/DataStructure/KthMultiSet.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/649
    links:
    - https://yukicoder.me/problems/no/649
  bundledCode: "#line 1 \"verify/yuki-649.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/649\"\
    \n\n#line 1 \"library/DataStructure/KthMultiSet.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename Data, typename Value = Data>\nstruct\
    \ KthMultiSet{\n    using F = function<Value(Value, Data)>;\n    using G = function<bool(Data,\
    \ Data)>;\n\n    private:\n    int K_;\n    multiset<Data> P_, Q_;\n    F add_,\
    \ sub_;\n    G require_;\n    Value sum_;\n\n    void balance(){\n        while(P_.size()\
    \ < K_ && Q_.size()){\n            auto itr = Q_.begin();\n            sum_ =\
    \ add_(sum_, *itr);\n            P_.insert(*itr);\n            Q_.erase(itr);\n\
    \        }\n        if(P_.empty() || Q_.empty()) return;\n        while(1){\n\
    \            auto si = --(P_.end());\n            auto li = Q_.begin();\n    \
    \        Data sv = (*si), lv = (*li);\n            if(require_(sv, lv)) break;\n\
    \            sum_ = add_(sub_(sum_, sv), lv);\n            P_.erase(si), Q_.erase(li);\n\
    \            P_.insert(lv), Q_.insert(sv);\n        }\n    }\n\n    public:\n\
    \    KthMultiSet(int K, \n        F Add = [](Value x, Data y){return x + y;},\
    \ \n        F Sub = [](Value x, Data y){return x - y;},\n        G Require = [](Data\
    \ x, Data y){return x <= y;})\n        : K_(K), add_(Add), sub_(Sub), require_(Require),\
    \ sum_(){}\n\n    void insert(Data data){\n        Q_.insert(data);\n        balance();\n\
    \    }\n\n    void erase(Data value){\n        auto itr = P_.find(value);\n  \
    \      if(itr != P_.end()){\n            sum_ = sub_(sum_, value);\n         \
    \   P_.erase(itr);\n        }\n        else{\n            assert(Q_.find(value)\
    \ != Q_.end());\n            Q_.erase(Q_.find(value));\n        }\n        balance();\n\
    \    }\n\n    inline bool exist(){\n        return P_.size() == K_;\n    }\n\n\
    \    inline Data get(){\n        assert(exist());\n        return *(--(P_.end()));\n\
    \    }\n\n    inline Value sum(){\n        return sum_;\n    }\n};\n#line 4 \"\
    verify/yuki-649.test.cpp\"\n\nint main(){\n    int Q, K; cin >> Q >> K;\n    KthMultiSet<long\
    \ long> st(K);\n    while(Q--){\n        int query; cin >> query;\n        if(query\
    \ == 1){\n            long long v; cin >> v;\n            st.insert(v);\n    \
    \    }\n        else{\n            long long v = -1;\n            if(st.exist()){\n\
    \                v = st.get();\n                st.erase(v);\n            }\n\
    \            cout << v << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/649\"\n\n#include \"../library/DataStructure/KthMultiSet.hpp\"\
    \n\nint main(){\n    int Q, K; cin >> Q >> K;\n    KthMultiSet<long long> st(K);\n\
    \    while(Q--){\n        int query; cin >> query;\n        if(query == 1){\n\
    \            long long v; cin >> v;\n            st.insert(v);\n        }\n  \
    \      else{\n            long long v = -1;\n            if(st.exist()){\n   \
    \             v = st.get();\n                st.erase(v);\n            }\n   \
    \         cout << v << endl;\n        }\n    }\n}"
  dependsOn:
  - library/DataStructure/KthMultiSet.hpp
  isVerificationFile: true
  path: verify/yuki-649.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 18:47:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yuki-649.test.cpp
layout: document
redirect_from:
- /verify/verify/yuki-649.test.cpp
- /verify/verify/yuki-649.test.cpp.html
title: verify/yuki-649.test.cpp
---
