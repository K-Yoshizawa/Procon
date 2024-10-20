---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Erasable Priority Queue - \u6D88\u305B\u308B Priority Queue"
    links: []
  bundledCode: "#line 1 \"Library/unauthenticated/ErasablePriorityQueue.hpp\"\n/**\n\
    \ * @file ErasablePriorityQueue.hpp\n * @brief Erasable Priority Queue - \u6D88\
    \u305B\u308B Priority Queue\n * @version 1.0\n * @date 2024-05-13\n */\n\ntemplate<typename\
    \ T>\nstruct ErasablePriorityQueue{\n    private:\n    using P = pair<T, int>;\n\
    \    priority_queue<P> que_, erase_;\n    int priority_{0};\n    T nullvalue_{numeric_limits<T>::min()};\n\
    \n    void normalize_(){\n        while(!que_.empty() and !erase_.empty()){\n\
    \            P x = que_.top(), y = erase_.top();\n            if(x.first < y.first\
    \ or x.first == y.first and x.second < y.second){\n                erase_.pop();\n\
    \                continue;\n            }\n            if(x.first == y.first and\
    \ x.second > y.second){\n                que_.pop();\n                erase_.pop();\n\
    \                continue;\n            }\n            if(x.first > y.first){\n\
    \                break;\n            }\n        }\n    }\n\n    public:\n    /**\n\
    \     * @brief \u8981\u7D20 `value` \u3092\u633F\u5165\u3059\u308B\u3002\n   \
    \  */\n    void push(T value){\n        que_.push({value, priority_--});\n   \
    \ }\n\n    /**\n     * @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u524A\u9664\
    \u3059\u308B\u3002\n     */\n    void pop(){\n        normalize_();\n        if(!empty())\
    \ que_.pop();\n    }\n\n    /**\n     * @brief \u8981\u7D20 `value` \u3092\u524A\
    \u9664\u3059\u308B\u3002\n     */\n    void erase(T value){\n        erase_.push({value,\
    \ priority_--});\n    }\n\n    /**\n     * @brief \u5148\u982D\u306E\u8981\u7D20\
    \u3092\u53D6\u5F97\u3059\u308B\u3002\n     */\n    T top(){\n        normalize_();\n\
    \        if(empty()) return nullvalue_;\n        else return que_.top().first;\n\
    \    }\n\n    /**\n     * @brief \u7A7A\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\
    \u3059\u308B\u3002\n     */\n    bool empty(){\n        return que_.empty();\n\
    \    }\n};\n"
  code: "/**\n * @file ErasablePriorityQueue.hpp\n * @brief Erasable Priority Queue\
    \ - \u6D88\u305B\u308B Priority Queue\n * @version 1.0\n * @date 2024-05-13\n\
    \ */\n\ntemplate<typename T>\nstruct ErasablePriorityQueue{\n    private:\n  \
    \  using P = pair<T, int>;\n    priority_queue<P> que_, erase_;\n    int priority_{0};\n\
    \    T nullvalue_{numeric_limits<T>::min()};\n\n    void normalize_(){\n     \
    \   while(!que_.empty() and !erase_.empty()){\n            P x = que_.top(), y\
    \ = erase_.top();\n            if(x.first < y.first or x.first == y.first and\
    \ x.second < y.second){\n                erase_.pop();\n                continue;\n\
    \            }\n            if(x.first == y.first and x.second > y.second){\n\
    \                que_.pop();\n                erase_.pop();\n                continue;\n\
    \            }\n            if(x.first > y.first){\n                break;\n \
    \           }\n        }\n    }\n\n    public:\n    /**\n     * @brief \u8981\u7D20\
    \ `value` \u3092\u633F\u5165\u3059\u308B\u3002\n     */\n    void push(T value){\n\
    \        que_.push({value, priority_--});\n    }\n\n    /**\n     * @brief \u5148\
    \u982D\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\u3002\n     */\n    void\
    \ pop(){\n        normalize_();\n        if(!empty()) que_.pop();\n    }\n\n \
    \   /**\n     * @brief \u8981\u7D20 `value` \u3092\u524A\u9664\u3059\u308B\u3002\
    \n     */\n    void erase(T value){\n        erase_.push({value, priority_--});\n\
    \    }\n\n    /**\n     * @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u53D6\u5F97\
    \u3059\u308B\u3002\n     */\n    T top(){\n        normalize_();\n        if(empty())\
    \ return nullvalue_;\n        else return que_.top().first;\n    }\n\n    /**\n\
    \     * @brief \u7A7A\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\
    \n     */\n    bool empty(){\n        return que_.empty();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/unauthenticated/ErasablePriorityQueue.hpp
  requiredBy: []
  timestamp: '2024-09-04 01:04:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/ErasablePriorityQueue.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/ErasablePriorityQueue.hpp
- /library/Library/unauthenticated/ErasablePriorityQueue.hpp.html
title: "Erasable Priority Queue - \u6D88\u305B\u308B Priority Queue"
---
