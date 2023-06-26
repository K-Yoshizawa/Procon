[![Actions Status](https://github.com/K-Yoshizawa/procon/workflows/verify/badge.svg)](https://github.com/K-Yoshizawa/procon/actions)
 [![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://K-Yoshizawa.github.io/Procon/)
[![lX57](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fatcoder%2Fjson%2FlX57)](https://atcoder.jp/users/lX57)

# log K's Procon Library

## これはなに
lX57の競技プログラミング用のライブラリ。
絶賛改修中。

## 更新履歴

### Ver 1.8.0 (2023/06/27)
- 【追加】Longest Increasing Subsequence - 最長部分増加列
- 【改修】Strongly Connected Components : ある頂点の属する強連結成分を取得する関数を追加

### Ver 1.7.2 (2023/06/26)
- 改名したんでした

### Ver 1.7.1 (2023/06/26)
- 【改修】Template : modintを分離

### Ver 1.7.0 (2023/06/18)
- 【追加】K-th MultiSet - K番目の値に関するデータ構造

### Ver 1.6.1 (2023/06/13)
- 【改修】Euler Tour : 一点更新クエリの追加

### Ver 1.6.0 (2023/06/13)
- 【追加】Heavy Light Decomposition - HL分解
- 一部テキストの軽微な修正

### Ver 1.5.1 (2023/06/13)
- 【追加】Lazy Segment Tree - 遅延評価セグメント木
- 【追加】Lowest Common Ancestor - 最小共通祖先
- 【追加】Binary Indexed Tree Double - Range Add Query対応BIT
- 【修正】Binary Indexed Tree : 範囲外参照するバグを修正

### Ver 1.4.0 (2023/06/12)
- 【追加】Segment Tree - セグメント木
- 【追加】Binary Indexed Tree - BIT
- 【追加】Euler Tour - オイラーツアー
- 【改修】Graph Template … 無向木において、各頂点の親頂点と親と結ぶ辺番号を取得する関数get_parentを追加

### Ver 1.3.2
- Warshall Floydのhppがバグってました

### Ver 1.3.1
- Dijkstraのverifyがバグってました
- ついでに木の直径を実装しました

### Ver 1.3.0
- Union-Findを実装というか移植
- Warshall-Floydを実装というか改修
- Kruskal法を実装
- Ford-Fulkerson法を実装というか写経
- Bipartite Matchingを実装

### Ver 1.2.0
- 頂点集合で管理するグラフ？知らない子です（消した）
- 代わりに辺集合で管理するグラフを作った（GraphTemplate.hpp）
- それに伴って既存のやつらを修正した（少なくて助かったね）
- ベルマンフォード法を実装（BellmanFord.hpp）

### Ver 1.1.0
- 強連結成分分解を整備
- 有向グラフの閉路検出を整備

### Ver 1.0.0
- 作り直し。verify-helperを使ってみる。
- 頂点集合で管理するグラフとダイクストラ法を試しに整備。