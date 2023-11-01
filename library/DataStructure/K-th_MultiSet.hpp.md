---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yuki-649.test.cpp
    title: verify/yuki-649.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/DataStructure/K-th_MultiSet.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename Data, typename Value = Data>\nstruct\
    \ Kth_MultiSet{\n    using F = function<Value(Value, Data)>;\n    using G = function<bool(Data,\
    \ Data)>;\n\n    private:\n    int __K;\n    multiset<Data> __P, __Q;\n    F __Add,\
    \ __Sub;\n    G __Require;\n    Value __Sum;\n\n    void balance(){\n        while(__P.size()\
    \ < __K && __Q.size()){\n            auto itr = __Q.begin();\n            __Sum\
    \ = __Add(__Sum, *itr);\n            __P.insert(*itr);\n            __Q.erase(itr);\n\
    \        }\n        if(__P.empty() || __Q.empty()) return;\n        while(1){\n\
    \            auto si = --(__P.end());\n            auto li = __Q.begin();\n  \
    \          Data sv = (*si), lv = (*li);\n            if(__Require(sv, lv)) break;\n\
    \            __Sum = __Add(__Sub(__Sum, sv), lv);\n            __P.erase(si),\
    \ __Q.erase(li);\n            __P.insert(lv), __Q.insert(sv);\n        }\n   \
    \ }\n\n    public:\n    Kth_MultiSet(int K, \n        F Add = [](Value x, Data\
    \ y){return x + y;}, \n        F Sub = [](Value x, Data y){return x - y;},\n \
    \       G Require = [](Data x, Data y){return x <= y;})\n        : __K(K), __Add(Add),\
    \ __Sub(Sub), __Require(Require), __Sum(){}\n\n    void insert(Data data){\n \
    \       __Q.insert(data);\n        balance();\n    }\n\n    void erase(Data value){\n\
    \        auto itr = __P.find(value);\n        if(itr != __P.end()){\n        \
    \    __Sum = __Sub(__Sum, value);\n            __P.erase(itr);\n        }\n  \
    \      else{\n            assert(__Q.find(value) != __Q.end());\n            __Q.erase(__Q.find(value));\n\
    \        }\n        balance();\n    }\n\n    inline bool exist(){\n        return\
    \ __P.size() == __K;\n    }\n\n    inline Data get(){\n        assert(exist());\n\
    \        return *(--(__P.end()));\n    }\n\n    inline Value sum(){\n        return\
    \ __Sum;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename Data,\
    \ typename Value = Data>\nstruct Kth_MultiSet{\n    using F = function<Value(Value,\
    \ Data)>;\n    using G = function<bool(Data, Data)>;\n\n    private:\n    int\
    \ __K;\n    multiset<Data> __P, __Q;\n    F __Add, __Sub;\n    G __Require;\n\
    \    Value __Sum;\n\n    void balance(){\n        while(__P.size() < __K && __Q.size()){\n\
    \            auto itr = __Q.begin();\n            __Sum = __Add(__Sum, *itr);\n\
    \            __P.insert(*itr);\n            __Q.erase(itr);\n        }\n     \
    \   if(__P.empty() || __Q.empty()) return;\n        while(1){\n            auto\
    \ si = --(__P.end());\n            auto li = __Q.begin();\n            Data sv\
    \ = (*si), lv = (*li);\n            if(__Require(sv, lv)) break;\n           \
    \ __Sum = __Add(__Sub(__Sum, sv), lv);\n            __P.erase(si), __Q.erase(li);\n\
    \            __P.insert(lv), __Q.insert(sv);\n        }\n    }\n\n    public:\n\
    \    Kth_MultiSet(int K, \n        F Add = [](Value x, Data y){return x + y;},\
    \ \n        F Sub = [](Value x, Data y){return x - y;},\n        G Require = [](Data\
    \ x, Data y){return x <= y;})\n        : __K(K), __Add(Add), __Sub(Sub), __Require(Require),\
    \ __Sum(){}\n\n    void insert(Data data){\n        __Q.insert(data);\n      \
    \  balance();\n    }\n\n    void erase(Data value){\n        auto itr = __P.find(value);\n\
    \        if(itr != __P.end()){\n            __Sum = __Sub(__Sum, value);\n   \
    \         __P.erase(itr);\n        }\n        else{\n            assert(__Q.find(value)\
    \ != __Q.end());\n            __Q.erase(__Q.find(value));\n        }\n       \
    \ balance();\n    }\n\n    inline bool exist(){\n        return __P.size() ==\
    \ __K;\n    }\n\n    inline Data get(){\n        assert(exist());\n        return\
    \ *(--(__P.end()));\n    }\n\n    inline Value sum(){\n        return __Sum;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/K-th_MultiSet.hpp
  requiredBy: []
  timestamp: '2023-11-02 01:25:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki-649.test.cpp
documentation_of: library/DataStructure/K-th_MultiSet.hpp
layout: document
redirect_from:
- /library/library/DataStructure/K-th_MultiSet.hpp
- /library/library/DataStructure/K-th_MultiSet.hpp.html
title: library/DataStructure/K-th_MultiSet.hpp
---
