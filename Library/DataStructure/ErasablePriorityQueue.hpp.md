---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n#include <algorithm>\n#include <array>\n\
    #include <bit>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 2 \"Library/DataStructure/ErasablePriorityQueue.hpp\"\n\ntemplate<typename\
    \ T>\nclass ErasablePriorityQueue{\n    public:\n    ErasablePriorityQueue() =\
    \ default;\n\n    void Push(T x){\n        que_.push({x, priority_--});\n    }\n\
    \n    void Pop(){\n        Normalize();\n        if(!Empty()) que_.pop();\n  \
    \  }\n\n    void Erase(T value){\n        erase_.push({value, priority_--});\n\
    \    }\n\n    T Top(){\n        Normalize();\n        if(Empty()) return null_;\n\
    \        else return que_.top().first;\n    }\n\n    bool Empty(){\n        Normalize();\n\
    \        return que_.empty();\n    }\n\n    private:\n    using P = pair<T, int>;\n\
    \    priority_queue<P> que_, erase_;\n    int priority_{0};\n    T null_{numeric_limits<T>::min()};\n\
    \n    void Normalize(){\n        while(!que_.empty() && !erase_.empty()){\n  \
    \          P x = que_.top(), y = erase_.top();\n            if(x.first < y.first\
    \ || x.first == y.first && x.second < y.second){\n                erase_.pop();\n\
    \                continue;\n            }\n            if(x.first == y.first &&\
    \ x.second > y.second){\n                que_.pop();\n                erase_.pop();\n\
    \                continue;\n            }\n            if(x.first > y.first){\n\
    \                break;\n            }\n        }\n    }\n};\n"
  code: "#include \"../Common.hpp\"\n\ntemplate<typename T>\nclass ErasablePriorityQueue{\n\
    \    public:\n    ErasablePriorityQueue() = default;\n\n    void Push(T x){\n\
    \        que_.push({x, priority_--});\n    }\n\n    void Pop(){\n        Normalize();\n\
    \        if(!Empty()) que_.pop();\n    }\n\n    void Erase(T value){\n       \
    \ erase_.push({value, priority_--});\n    }\n\n    T Top(){\n        Normalize();\n\
    \        if(Empty()) return null_;\n        else return que_.top().first;\n  \
    \  }\n\n    bool Empty(){\n        Normalize();\n        return que_.empty();\n\
    \    }\n\n    private:\n    using P = pair<T, int>;\n    priority_queue<P> que_,\
    \ erase_;\n    int priority_{0};\n    T null_{numeric_limits<T>::min()};\n\n \
    \   void Normalize(){\n        while(!que_.empty() && !erase_.empty()){\n    \
    \        P x = que_.top(), y = erase_.top();\n            if(x.first < y.first\
    \ || x.first == y.first && x.second < y.second){\n                erase_.pop();\n\
    \                continue;\n            }\n            if(x.first == y.first &&\
    \ x.second > y.second){\n                que_.pop();\n                erase_.pop();\n\
    \                continue;\n            }\n            if(x.first > y.first){\n\
    \                break;\n            }\n        }\n    }\n};"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/ErasablePriorityQueue.hpp
  requiredBy: []
  timestamp: '2026-10-14 19:08:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/DataStructure/ErasablePriorityQueue.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/ErasablePriorityQueue.hpp
- /library/Library/DataStructure/ErasablePriorityQueue.hpp.html
title: Library/DataStructure/ErasablePriorityQueue.hpp
---
