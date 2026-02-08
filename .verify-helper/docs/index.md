[![lX57](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fatcoder%2Fjson%2FlX57)](https://atcoder.jp/users/lX57)
[![log_K](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fcodeforces%2Fjson%2Flog_K)](https://codeforces.com/profile/log_K)

# log K's Procon Library

log K / lX57 が競技プログラミングで使用しているライブラリです。

---

## 使用方法

各ライブラリのドキュメントには以下の情報が含まれています：

- **概要**: ライブラリの説明
- **関数/メソッド**: 使用可能な関数やメソッドの詳細
- **制約**: 入力の制約条件
- **計算量**: 時間計算量と空間計算量

### コード例

各ライブラリは `#include` でインクルードして使用します：

```cpp
#include "Library/DataStructure/SegmentTree.hpp"
```

---

## 命名規則

本ライブラリでは以下の命名規則を採用しています：

- **クラス名**: PascalCase (例: `SegmentTree`)
- **メソッド名**: PascalCase (例: `Build`, `Product`)
- **関数名**: PascalCase (例: `InputTree`, `CalculateTreeDepth`)
- **変数名（private）**: snake_case with trailing underscore (例: `size_`, `data_`)
- **パラメータ名**: snake_case (例: `merge`, `zero_index`)

---

## 注意事項

- `Library/unauthenticated` に含まれているファイルは、自動テストによる verify ができていないライブラリや、現在は使われていないライブラリです。
- すべてのライブラリは C++17 以降での使用を想定しています。
- セグメント木などのデータ構造は、デフォルトで 1-index ですが、`zero_index = true` を指定することで 0-index でも使用できます。

---

## ライセンス

このライブラリは競技プログラミングでの使用を目的として作成されています。