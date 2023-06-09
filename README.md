[![Actions Status](https://github.com/K-Yoshizawa/procon/workflows/verify/badge.svg)](https://github.com/K-Yoshizawa/procon/actions)
 [![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://K-Yoshizawa.github.io/Procon/)
[![Reborn_K](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fatcoder%2Fjson%2FReborn_K)](https://atcoder.jp/users/Reborn_K)

# Reborn_K's Procon Library

## これはなに
Reborn_Kの競技プログラミング用のライブラリ。
絶賛改修中。

## 更新履歴

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