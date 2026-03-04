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
  bundledCode: "#line 2 \"Library/String/ZAlgorithm.hpp\"\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\nconstexpr\
    \ const ll INF = (1LL << 62) - (3LL << 30) - 1;\n#line 4 \"Library/String/ZAlgorithm.hpp\"\
    \n\nvector<int> ZAlgorithm(string S){\n    vector<int> Z(S.size(), 0);\n    Z[0]\
    \ = S.size();\n    int i = 1, j = 0;\n    while(i < S.size()){\n        while(i\
    \ + j < S.size() && S[j] == S[i + j]) ++j;\n        Z[i] = j;\n        if(j ==\
    \ 0){\n            ++i;\n            continue;\n        }\n        int k = 1;\n\
    \        while(k < j && k + Z[k] < j){\n            Z[i + k] = Z[k];\n       \
    \     ++k;\n        }\n        i += k;\n        j -= k;\n    }\n    return Z;\n\
    }\n"
  code: "#pragma once\n\n#include \"../Common.hpp\"\n\nvector<int> ZAlgorithm(string\
    \ S){\n    vector<int> Z(S.size(), 0);\n    Z[0] = S.size();\n    int i = 1, j\
    \ = 0;\n    while(i < S.size()){\n        while(i + j < S.size() && S[j] == S[i\
    \ + j]) ++j;\n        Z[i] = j;\n        if(j == 0){\n            ++i;\n     \
    \       continue;\n        }\n        int k = 1;\n        while(k < j && k + Z[k]\
    \ < j){\n            Z[i + k] = Z[k];\n            ++k;\n        }\n        i\
    \ += k;\n        j -= k;\n    }\n    return Z;\n}"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/String/ZAlgorithm.hpp
  requiredBy: []
  timestamp: '2026-02-08 19:36:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/String/ZAlgorithm.hpp
layout: document
title: Z Algorithm
---

# Z Algorithm

文字列 $S$ について、$S$ の $i$ 文字目以降のみを取り出した部分文字列を $S[i]$ とします。

このとき、$0 \le i \lt \lvert S \rvert$ を満たす整数 $i$ に対して、$S$ と $S[i+1]$ の最長共通接頭辞 (Longest Common Prefix) の長さを $\textrm{O}(\lvert S \rvert)$ 時間で求めることができます。

```
vector<int> ZAlgorithm(string S)
```

- 長さ $\lvert S \rvert$ の文字列 $S$ に対して、上記の値を格納した配列 `Z` を返します。
- `Z[i]` は、$S$ と $S[i+1]$ の最長共通接頭辞の長さを表します。

**制約**

- $1 \le \lvert S \rvert \le 10^6$
- $S$ は $1$ バイト文字からなる。

**計算量**

- $\textrm{O}(\lvert S \rvert)$

---
