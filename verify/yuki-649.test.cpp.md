---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/K-th_MultiSet.hpp
    title: library/DataStructure/K-th_MultiSet.hpp
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
    \n\n#line 1 \"library/DataStructure/K-th_MultiSet.hpp\"\n#include <bits/stdc++.h>\n\
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
    \ __Sum;\n    }\n};\n#line 4 \"verify/yuki-649.test.cpp\"\n\nint main(){\n   \
    \ int Q, K; cin >> Q >> K;\n    Kth_MultiSet<long long> st(K);\n    while(Q--){\n\
    \        int query; cin >> query;\n        if(query == 1){\n            long long\
    \ v; cin >> v;\n            st.insert(v);\n        }\n        else{\n        \
    \    long long v = -1;\n            if(st.exist()){\n                v = st.get();\n\
    \                st.erase(v);\n            }\n            cout << v << endl;\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/649\"\n\n#include \"../library/DataStructure/K-th_MultiSet.hpp\"\
    \n\nint main(){\n    int Q, K; cin >> Q >> K;\n    Kth_MultiSet<long long> st(K);\n\
    \    while(Q--){\n        int query; cin >> query;\n        if(query == 1){\n\
    \            long long v; cin >> v;\n            st.insert(v);\n        }\n  \
    \      else{\n            long long v = -1;\n            if(st.exist()){\n   \
    \             v = st.get();\n                st.erase(v);\n            }\n   \
    \         cout << v << endl;\n        }\n    }\n}"
  dependsOn:
  - library/DataStructure/K-th_MultiSet.hpp
  isVerificationFile: true
  path: verify/yuki-649.test.cpp
  requiredBy: []
  timestamp: '2023-11-02 01:25:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yuki-649.test.cpp
layout: document
redirect_from:
- /verify/verify/yuki-649.test.cpp
- /verify/verify/yuki-649.test.cpp.html
title: verify/yuki-649.test.cpp
---
