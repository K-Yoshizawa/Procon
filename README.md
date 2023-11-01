[![Actions Status](https://github.com/K-Yoshizawa/procon/workflows/verify/badge.svg)](https://github.com/K-Yoshizawa/procon/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://K-Yoshizawa.github.io/Procon/)
[![lX57](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fatcoder%2Fjson%2FlX57)](https://atcoder.jp/users/lX57)
[![log_K](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fcodeforces%2Fjson%2Flog_K)](https://codeforces.com/profile/log_K)

# log K's Procon Library

## 更新履歴

### Ver 2.4.1 (2023/11/02)
- 【追加】Binary Indexed Tree
- 【改修】K-th Multiset
- Kruskal法にドキュメントを追加

### Ver 2.4.0 (2023/10/30)
- 【追加】0-1 Knapsack - 0-1 ナップザック問題
- 【追加】Slide-Min - スライド最小値
- 【改修】Template : デバッグ出力の改良、あまり使わないテンプレートを分離

### Ver 2.3.0 (2023/10/21)
- 【追加】Z-Algorithm - Z-アルゴリズム
- 【追加】Manacher - 回文検索
- 【改修】Euler Tour : 新ライブラリに対応
- 【改修】Template : `vector` の最小値、最大値を取得する関数を追加

### Ver 2.2.0 (2023/10/11)
- 【追加】Matrix - 行列演算
- 【修正】modint : include文を入れた

### Ver 2.1.0 (2023/10/10)
- ドキュメント整備を飽きるまでやった
- 【改修】Kruskal : 新ライブラリに対応
- 【実験】Graph Template : 参照返しにして壊れないか実験

### Ver 2.0.0 (2023/10/10)
- 今まで `latest` フォルダにあったライブラリ群を `library` に統合しました

### Ver 1.15.1 (2023/10/10)
- 【改修】Template : bitseqに逆順出力のオプションを追加
- 【修正】Compress : 要らない行の削除

### Ver 1.15.0 (2023/10/04)
- 【追加】Dinic - Dinic法
- 【改修】Bipartite Matching : 使用するフローアルゴリズムをDinic法に変更（でもyosupo-judgeはTLEします（え））
- 【修正】Lowest Common Ancestor : ちゃんと冒頭のやつ書いてなかった

### Ver 1.14.1 (2023/10/04)
- 【改修】Heavy Light Decomposition : 辺周りの処理を削除（工夫すると要らないねという話　詳しくはverifyのAOJ-GRL-5-D/Eを参照）

### Ver 1.14.0 (2023/10/03)
- 【追加】新 Cumulative Sum 2D - 二次元累積和
- 【追加】新 Heavy Light Decomposition - HL分解 (辺周りの処理に改良の余地あり(そもそも要る？))

### Ver 1.13.0 (2023/10/02)
- 【改修】新グラフテンプレートからフロー関連を削除と、それに伴う既存ライブラリの修正
- 【追加】Flow Template - フローテンプレート
- 【追加】新 Segment Tree - セグメント木
- 【追加】新 Lazy Segment Tree - 遅延評価セグメント木

### Ver 1.12.0 (2023/09/01)
- 【改修】新グラフテンプレートにフロー関連の関数を追加
- 【改修】新Dijkstraをポテンシャルに対応
- 【準備】Ford-Fulkerson, Primal Dualを新グラフテンプレートに対応

### Ver 1.11.0 (2023/08/31)
- 【修正】新グラフテンプレートのverifyミスを修正
- 【準備】Dijkstra, Bellman Ford, Warshall Floydを新グラフテンプレートに対応

### Ver 1.10.0 (2023/08/31)
- 【準備】グラフ系ライブラリの大規模改修をしたい人になりました

### Ver 1.9.4 (2023/08/30)
- ちょっとしたリファクタリング

### Ver 1.9.3 (2023/08/24)
- 【修正】Graph Template : INFの値を修正（オーバーフロー対策）
- 【改修】Compress : オフセットの初期値を指定できるようにした
- 【改修】Cumulative Sum 2D : 頭がバグらないようにした？
- 一部のファイルの体裁を整えてみた

### Ver 1.9.2 (2023/08/23)
- 更新サボりすぎており、とりあえず上げる

### Ver 1.9.1 (2023/08/08)
- AtCoderの新ジャッジに対応してbashファイルの再構築

### Ver 1.9.0 (2023/07/24)
- 【修正】Template : bitseqの演算ミスを修正
- 【追加】Cumulative Sum 2D - 二次元累積和

### Ver 1.8.3 (2023/07/12)
- 【その他】トップページに載せる部分を分離

### Ver 1.8.2 (2023/07/12)
- 【改修】Template : デバッグ出力ちょっと改良した
- 【改修】Dijkstra : 復元するとき頂点番号の代わりに辺番号を取得するような改良(正直ちょっと遅くなるから微妙な気がする)

### Ver 1.8.1 (2023/07/11)
- 【改修】Template : デバッグ出力書いた
- 【改修】Segment Tree : ドキュメントを書いた
- 【改修】Heavy Light Decomposition : なんか色々改修したけど覚えてないし多分verify直してない

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
- 【改修】Graph Template - 無向木において、各頂点の親頂点と親と結ぶ辺番号を取得する関数get_parentを追加

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