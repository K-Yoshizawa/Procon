---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/unauthenticated/KthMultiSet.hpp\"\n#include <bits/stdc++.h>\n\
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
    \    }\n\n    inline Value sum(){\n        return sum_;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename Data,\
    \ typename Value = Data>\nstruct KthMultiSet{\n    using F = function<Value(Value,\
    \ Data)>;\n    using G = function<bool(Data, Data)>;\n\n    private:\n    int\
    \ K_;\n    multiset<Data> P_, Q_;\n    F add_, sub_;\n    G require_;\n    Value\
    \ sum_;\n\n    void balance(){\n        while(P_.size() < K_ && Q_.size()){\n\
    \            auto itr = Q_.begin();\n            sum_ = add_(sum_, *itr);\n  \
    \          P_.insert(*itr);\n            Q_.erase(itr);\n        }\n        if(P_.empty()\
    \ || Q_.empty()) return;\n        while(1){\n            auto si = --(P_.end());\n\
    \            auto li = Q_.begin();\n            Data sv = (*si), lv = (*li);\n\
    \            if(require_(sv, lv)) break;\n            sum_ = add_(sub_(sum_, sv),\
    \ lv);\n            P_.erase(si), Q_.erase(li);\n            P_.insert(lv), Q_.insert(sv);\n\
    \        }\n    }\n\n    public:\n    KthMultiSet(int K, \n        F Add = [](Value\
    \ x, Data y){return x + y;}, \n        F Sub = [](Value x, Data y){return x -\
    \ y;},\n        G Require = [](Data x, Data y){return x <= y;})\n        : K_(K),\
    \ add_(Add), sub_(Sub), require_(Require), sum_(){}\n\n    void insert(Data data){\n\
    \        Q_.insert(data);\n        balance();\n    }\n\n    void erase(Data value){\n\
    \        auto itr = P_.find(value);\n        if(itr != P_.end()){\n          \
    \  sum_ = sub_(sum_, value);\n            P_.erase(itr);\n        }\n        else{\n\
    \            assert(Q_.find(value) != Q_.end());\n            Q_.erase(Q_.find(value));\n\
    \        }\n        balance();\n    }\n\n    inline bool exist(){\n        return\
    \ P_.size() == K_;\n    }\n\n    inline Data get(){\n        assert(exist());\n\
    \        return *(--(P_.end()));\n    }\n\n    inline Value sum(){\n        return\
    \ sum_;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/unauthenticated/KthMultiSet.hpp
  requiredBy: []
  timestamp: '2024-09-04 01:04:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/KthMultiSet.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/KthMultiSet.hpp
- /library/Library/unauthenticated/KthMultiSet.hpp.html
title: Library/unauthenticated/KthMultiSet.hpp
---
