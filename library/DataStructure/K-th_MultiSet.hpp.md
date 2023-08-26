---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/yuki-0649.test.cpp
    title: verify/yukicoder/yuki-0649.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "K-th MultiSet - K\u756A\u76EE\u306E\u5024\u306B\u95A2\u3059\u308B\
      \u30C7\u30FC\u30BF\u69CB\u9020"
    links: []
  bundledCode: "#line 2 \"library/DataStructure/K-th_MultiSet.hpp\"\n\n/**\n * @brief\
    \ K-th MultiSet - K\u756A\u76EE\u306E\u5024\u306B\u95A2\u3059\u308B\u30C7\u30FC\
    \u30BF\u69CB\u9020\n */\n\n#include <set>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct Kth_MultiSet{\n    private:\n    int K;\n    bool greater;\n    multiset<T>\
    \ small, large;\n    T __sum;\n\n    void balance(){\n        if(greater){\n \
    \           while(large.size() < K && small.size()){\n                auto itr\
    \ = --(small.end());\n                __sum += (*itr);\n                large.insert(*itr);\n\
    \                small.erase(itr);\n            }\n            if(small.empty()\
    \ || large.empty()) return;\n            while(1){\n                auto si =\
    \ --(small.end());\n                auto li = large.begin();\n               \
    \ T sv = (*si), lv = (*li);\n                if(sv <= lv) break;\n           \
    \     __sum += (sv - lv);\n                small.erase(si), large.erase(li);\n\
    \                small.insert(lv), large.insert(sv);\n            }\n        }\n\
    \        else{\n            while(small.size() < K && large.size()){\n       \
    \         auto itr = large.begin();\n                __sum += (*itr);\n      \
    \          small.insert(*itr);\n                large.erase(itr);\n          \
    \  }\n            if(small.empty() || large.empty()) return;\n            while(1){\n\
    \                auto si = --(small.end());\n                auto li = large.begin();\n\
    \                T sv = (*si), lv = (*li);\n                if(sv <= lv) break;\n\
    \                __sum -= (sv - lv);\n                small.erase(si), large.erase(li);\n\
    \                small.insert(lv), large.insert(sv);\n            }\n        }\n\
    \    }\n\n    public:\n    Kth_MultiSet(int K, bool greater = false) : K(K), greater(greater),\
    \ __sum(0){}\n\n    /**\n     * @brief \u5024value\u3092\u8FFD\u52A0\u3059\u308B\
    \u3002\n     * @param value \u8FFD\u52A0\u3057\u305F\u3044\u5024\n     */\n  \
    \  void insert(T value){\n        if(greater) small.insert(value);\n        else\
    \ large.insert(value);\n        balance();\n    }\n\n    void erase(T value){\n\
    \        if(greater){\n            auto itr = large.find(value);\n           \
    \ if(itr != large.end()){\n                __sum -= value;\n                large.erase(itr);\n\
    \            }\n            else{\n                assert(small.find(value) !=\
    \ small.end());\n                small.erase(small.find(value));\n           \
    \ }\n        }\n        else{\n            auto itr = small.find(value);\n   \
    \         if(itr != small.end()){\n                __sum -= value;\n         \
    \       small.erase(itr);\n            }\n            else{\n                assert(large.find(value)\
    \ != large.end());\n                large.erase(large.find(value));\n        \
    \    }\n        }\n        balance();\n    }\n\n    inline T sum(){\n        return\
    \ __sum;\n    }\n\n    inline bool exist(){\n        return greater ? large.size()\
    \ == K : small.size() == K;\n    }\n\n    inline T get(){\n        assert(exist());\n\
    \        return greater ? *(large.begin()) : *(--(small.end()));\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief K-th MultiSet - K\u756A\u76EE\u306E\u5024\u306B\
    \u95A2\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\n */\n\n#include <set>\nusing\
    \ namespace std;\n\ntemplate<typename T>\nstruct Kth_MultiSet{\n    private:\n\
    \    int K;\n    bool greater;\n    multiset<T> small, large;\n    T __sum;\n\n\
    \    void balance(){\n        if(greater){\n            while(large.size() < K\
    \ && small.size()){\n                auto itr = --(small.end());\n           \
    \     __sum += (*itr);\n                large.insert(*itr);\n                small.erase(itr);\n\
    \            }\n            if(small.empty() || large.empty()) return;\n     \
    \       while(1){\n                auto si = --(small.end());\n              \
    \  auto li = large.begin();\n                T sv = (*si), lv = (*li);\n     \
    \           if(sv <= lv) break;\n                __sum += (sv - lv);\n       \
    \         small.erase(si), large.erase(li);\n                small.insert(lv),\
    \ large.insert(sv);\n            }\n        }\n        else{\n            while(small.size()\
    \ < K && large.size()){\n                auto itr = large.begin();\n         \
    \       __sum += (*itr);\n                small.insert(*itr);\n              \
    \  large.erase(itr);\n            }\n            if(small.empty() || large.empty())\
    \ return;\n            while(1){\n                auto si = --(small.end());\n\
    \                auto li = large.begin();\n                T sv = (*si), lv =\
    \ (*li);\n                if(sv <= lv) break;\n                __sum -= (sv -\
    \ lv);\n                small.erase(si), large.erase(li);\n                small.insert(lv),\
    \ large.insert(sv);\n            }\n        }\n    }\n\n    public:\n    Kth_MultiSet(int\
    \ K, bool greater = false) : K(K), greater(greater), __sum(0){}\n\n    /**\n \
    \    * @brief \u5024value\u3092\u8FFD\u52A0\u3059\u308B\u3002\n     * @param value\
    \ \u8FFD\u52A0\u3057\u305F\u3044\u5024\n     */\n    void insert(T value){\n \
    \       if(greater) small.insert(value);\n        else large.insert(value);\n\
    \        balance();\n    }\n\n    void erase(T value){\n        if(greater){\n\
    \            auto itr = large.find(value);\n            if(itr != large.end()){\n\
    \                __sum -= value;\n                large.erase(itr);\n        \
    \    }\n            else{\n                assert(small.find(value) != small.end());\n\
    \                small.erase(small.find(value));\n            }\n        }\n \
    \       else{\n            auto itr = small.find(value);\n            if(itr !=\
    \ small.end()){\n                __sum -= value;\n                small.erase(itr);\n\
    \            }\n            else{\n                assert(large.find(value) !=\
    \ large.end());\n                large.erase(large.find(value));\n           \
    \ }\n        }\n        balance();\n    }\n\n    inline T sum(){\n        return\
    \ __sum;\n    }\n\n    inline bool exist(){\n        return greater ? large.size()\
    \ == K : small.size() == K;\n    }\n\n    inline T get(){\n        assert(exist());\n\
    \        return greater ? *(large.begin()) : *(--(small.end()));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/K-th_MultiSet.hpp
  requiredBy: []
  timestamp: '2023-06-18 02:21:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/yuki-0649.test.cpp
documentation_of: library/DataStructure/K-th_MultiSet.hpp
layout: document
redirect_from:
- /library/library/DataStructure/K-th_MultiSet.hpp
- /library/library/DataStructure/K-th_MultiSet.hpp.html
title: "K-th MultiSet - K\u756A\u76EE\u306E\u5024\u306B\u95A2\u3059\u308B\u30C7\u30FC\
  \u30BF\u69CB\u9020"
---
