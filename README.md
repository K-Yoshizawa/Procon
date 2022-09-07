# Reborn_K's Procon Library

## Library

現在実装しているライブラリは次の通り。

### グラフ系統

 - グラフテンプレート (最終更新：2022/09/08)
 - 全頂点最短距離
    - Dijkstra法 (最終更新：2022/09/06)([検証済 \[AOJ GRL 1 A\]](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A))
    - Bellman-Ford法 (最終更新：2022/09/06)([検証済 \[AOJ GRL 1 B\]](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B))
    - Warshall-Floyd法 (最終更新：2022/09/08)([検証済 \[AOJ GRL 1 C\]](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C))
 - 最小全域木
    - Prim法 (最終更新：2022/09/04)([検証済 \[AOJ GRL 2 A\]](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A))
    - Kruskal法 (最終更新：2022/09/04)([検証済 \[AOJ GRL 2 A\]](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A))
 - 木の直径 (最終更新：2022/09/05)([検証済 \[AOJ GRL 5 A\]](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A))
 - 橋と関節点(Low Link) (最終更新：2022/09/06)([検証済 \[AOJ GRL 3 A\]](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A) [検証済 \[AOJ GRL 3 B\]](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B))

### 未分類系統

 - modint (最終更新：2022/09/04)(拝借)
 - セグメント木 (最終更新：2022/09/04)(未検証)
 - UnionFind (最終更新：2022/09/04)(拝借)

## Version

### ver 1.2.2 (2022/09/08)
 - グラフテンプレートの軽微な修正。
 - WarshallFloyd法の引数に無向グラフか有向グラフかどちらかを指定する変数を追加。

### ver 1.2.1 (2022/09/06)
 - Dijkstra法をよりシンプルな形に改善。AOJによる再検証を完了。

### ver 1.2.0 (2022/09/06)
 - BellmanFord法、WarshallFloyd法を実装、AOJによる検証を完了
 - LowLinkを実装、AOJによる検証を完了

### ver 1.1.0 (2022/09/05)
 - Dijkstra法、Prim法、Kruskal法のAOJによる検証を完了
 - 木の直径(TreeDiamiter)を実装、AOJによる検証を完了

### ver 1.0.0 (2022/09/04)
 - セグメント木
 - UnionFind
 - グラフテンプレート
 - Dijkstra法
 - Prim法
 - Kruskal法

## 参考サイト
 - [Luzhiled's memo | C++による競技プログラミングのライブラリです](https://ei1333.github.io/luzhiled/)
 - [木の直径を求めるアルゴリズム | アルゴリズムロジック](https://algo-logic.info/tree-diameter/)
 - [ラムダ式のサンプル](https://perogram.hateblo.jp/entry/2020/06/22/111303)
 - [無向グラフの Bridge (Cut edge) を線形時間で求める](https://medium.com/@yukihira/%E7%84%A1%E5%90%91%E3%82%B0%E3%83%A9%E3%83%95%E3%81%AE-bridge-cut-edge-%E3%82%92%E7%B7%9A%E5%BD%A2%E6%99%82%E9%96%93%E3%81%A7%E6%B1%82%E3%82%81%E3%82%8B-b57d4e5458da)
 - [グラフにおける橋(bridge)を検出するアルゴリズム | アルゴリズムロジック](https://algo-logic.info/bridge-lowlink/)
 - [Bridges and Articulation points Algorithm | Graph Theory](https://www.youtube.com/watch?v=aZXi1unBdJA&t=715s)