---
title: Z Algorithm
documentation_of: ../Library/String/ZAlgorithm.hpp
---

# Z Algorithm

文字列 $S$ について、$S$ の $i$ 文字目以降のみを取り出した部分文字列を $S[i]$ とします。

このとき、$0 \le i \lt \lvert S \rvert$ を満たす整数 $i$ に対して、$S$ と $S[i+1]$ の最長共通接頭辞 (Longest Common Prefix) の長さを $\textrm{O}(\lvert S \rvert)$ 時間で求めることができます。

```
vector<int> Z_Algorithm(string S)
```

- 長さ $\lvert S \rvert$ の文字列 $S$ に対して、上記の値を格納した配列 `Z` を返します。
- `Z[i]` は、$S$ と $S[i+1]$ の最長共通接頭辞の長さを表します。

**制約**

- $1 \le \lvert S \rvert \le 10^6$
- $S$ は $1$ バイト文字からなる。

**計算量**

- $\textrm{O}(\lvert S \rvert)$

---
