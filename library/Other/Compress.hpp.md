---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Compress - \u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 1 \"library/Other/Compress.hpp\"\n/**\n * @file Compress.hpp\n\
    \ * @author log_K (lX57)\n * @brief Compress - \u5EA7\u6A19\u5727\u7E2E\n * @version\
    \ 2.0\n * @date 2024-02-04\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate<typename T>\nstruct Compress{\n    private:\n    size_t m_size;\n \
    \   int m_offset;\n    vector<T> m_value;\n\n    public:\n    Compress(vector<T>\
    \ &value, int offset = 0) : m_value(value){\n        sort(m_value.begin(), m_value.end());\n\
    \        m_value.erase(unique(m_value.begin(), m_value.end()), m_value.end());\n\
    \        m_size = m_value.size();\n    }\n\n    int to_index(T value){\n     \
    \   int ret = (int)(lower_bound(m_value.begin(), m_value.end(), value) - m_value.begin());\n\
    \        assert(ret < m_size);\n        return ret;\n    }\n\n    T to_value(int\
    \ index){\n        return m_value.at(index);\n    }\n\n    int operator[](T value){\n\
    \        return to_index(value);\n    }\n};\n"
  code: "/**\n * @file Compress.hpp\n * @author log_K (lX57)\n * @brief Compress -\
    \ \u5EA7\u6A19\u5727\u7E2E\n * @version 2.0\n * @date 2024-02-04\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>\nstruct Compress{\n\
    \    private:\n    size_t m_size;\n    int m_offset;\n    vector<T> m_value;\n\
    \n    public:\n    Compress(vector<T> &value, int offset = 0) : m_value(value){\n\
    \        sort(m_value.begin(), m_value.end());\n        m_value.erase(unique(m_value.begin(),\
    \ m_value.end()), m_value.end());\n        m_size = m_value.size();\n    }\n\n\
    \    int to_index(T value){\n        int ret = (int)(lower_bound(m_value.begin(),\
    \ m_value.end(), value) - m_value.begin());\n        assert(ret < m_size);\n \
    \       return ret;\n    }\n\n    T to_value(int index){\n        return m_value.at(index);\n\
    \    }\n\n    int operator[](T value){\n        return to_index(value);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: library/Other/Compress.hpp
  requiredBy: []
  timestamp: '2024-02-04 22:07:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Other/Compress.hpp
layout: document
redirect_from:
- /library/library/Other/Compress.hpp
- /library/library/Other/Compress.hpp.html
title: "Compress - \u5EA7\u6A19\u5727\u7E2E"
---
