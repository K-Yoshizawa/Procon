#include "bits/stdc++.h"
using namespace std;

/**
 * @brief グラフ辺テンプレート。直接使うことは少ない気がする。
 * 
 * @tparam T 重みの型
 */
template<typename T = int>
struct Edge{
    int from, to;                           // 始点、終点
    T cost;                                 // 重み
    int edge_idx, vertex_idx, vertex_ridx;  // 辺集合でのインデックス、頂点集合でのインデックス、逆辺の頂点集合でのインデックス

    /**
     * @brief  単純な辺の追加。あまり使わないかも？
     * @note   
     * @param  to: 終点
     * @param  cost: 辺の重み
     * @param  edge_idx: 省略可、辺集合でのインデックス
     */
    Edge(int to, T cost = 1, int edge_idx = -1) : from(-1), to(to), cost(cost), edge_idx(edge_idx) {}

    /**
     * @brief  辺の追加。主に使うのはこっち。
     * @note   
     * @param  from: 始点
     * @param  to: 終点
     * @param  cost: 辺の重み
     * @param  edge_idx: 省略可、辺集合でのインデックス
     * @param  vertex_idx: 省略可、頂点集合でのインデックス
     * @param  vertex_ridx: 省略可、逆辺の頂点集合でのインデックス
     */
    Edge(int from, int to, T cost, int edge_idx = -1, int vertex_idx = -1, int vertex_ridx = -1) : 
        from(from), to(to), cost(cost), edge_idx(edge_idx), vertex_idx(vertex_idx), vertex_ridx(vertex_ridx) {}

    bool operator<(const Edge<T> &e) const { return cost < e.cost; }
};

/**
 * @brief グラフ本体。頂点集合と辺集合の2つを保持している。
 * 
 * @tparam T グラフ辺の重みの型
 */
template<typename T = int>
struct Graph{
    vector<vector<Edge<T>>> vertex; // 頂点集合
    vector<Edge<T>> edges;          // 辺集合

    Graph(int V) : vertex(V) {}
    Graph() = default;

    /**
     * @brief 無向辺の追加
     * 
     * @param v 辺が結ぶ頂点1
     * @param u 辺が結ぶ頂点2
     * @param cost 辺の重み(省略可、デフォルトは1)
     */
    void nd_add(int v, int u, T cost = 1){
        int edge_idx = edges.size();
        int from_idx = vertex[v].size();
        int to_idx = vertex[u].size();
        vertex[v].push_back(Edge<T>(u, cost, edge_idx, from_idx, to_idx));
        vertex[u].push_back(Edge<T>(v, cost, edge_idx, to_idx, from_idx));
        edges.push_back(Edge<T>(v, u, cost, edge_idx));
    }

    /**
     * @brief 有向辺の追加
     * 
     * @param from 出次する頂点
     * @param to 入次する頂点
     * @param cost 辺の重み(省略可、デフォルトは1)
     */
    void d_add(int from, int to, T cost = 1){
        int edge_idx = edges.size();
        int from_idx = vertex[from].size();
        vertex[from].push_back(Edge<T>(from, to, cost, edge_idx, from_idx));
        edges.push_back(Edge<T>(from, to, cost, edge_idx, from_idx));
    }

    /**
     * @brief  逆辺を追加する。
     * @note   今のところの使用用途、最大流くらい…
     * @param  cost: 省略可、逆辺のコスト
     * @retval 辺集合における双方の辺のインデックスの対応関係
     */
    vector<int> add_reverse(T cost = 0){
        int E = edges.size();
        vector<int> ret(2 * E);
        for(int i = 0; i < E; ++i){
            auto &e = edges[i];
            d_add(e.to, e.from, cost);
            int idx = e.vertex_idx;
            int ridx = edges[i + E].vertex_idx;
            e.vertex_ridx = ridx;
            edges[i + E].vertex_ridx = idx;
            vertex[e.from][e.vertex_idx].vertex_ridx = ridx;
            vertex[e.to][ridx].vertex_ridx = idx;
            ret[i] = i + E;
            ret[i + E] = i;
        }
        return ret;
    }
};

/**
 * @brief 最大流を計算量O(FE)で求める。ただしFは最大フローである。
 */
template<typename T = int>
struct FordFulkerson{
    private:
    int V, E;
    Graph<T> &G;
    vector<vector<Edge<T>>> Gv;
    vector<Edge<T>> Ge;
    vector<int> rev;
    vector<bool> used;    

    T dfs(int s, int t, T flow){
        if(s == t) return flow;
        used[s] = true;
        for(int i = 0; i < Gv[s].size(); ++i){
            if(Gv[s][i].cost == 0) continue;
            if(used[Gv[s][i].to]) continue;
            T tflow = dfs(Gv[s][i].to, t, min(flow, Gv[s][i].cost));
            if(tflow > 0){
                Gv[s][i].cost -= tflow;
                Gv[Gv[s][i].to][Gv[s][i].vertex_ridx].cost += tflow;
                Ge[Gv[s][i].edge_idx].cost -= tflow;
                Ge[rev[Gv[s][i].edge_idx]].cost += tflow;
                return tflow;
            }
        }
        return 0;
    }

    public:
    FordFulkerson(Graph<T> &g) : G(g), V(g.vertex.size()), E(g.edges.size()){
        rev = G.add_reverse();
        Gv = G.vertex;
        Ge = G.edges;
        used.resize(V, false);
    }

    /**
     * @brief  始点sから終点tまでの最大フローを求める。
     * @note   0-index
     * @param  s: 始点の頂点番号
     * @param  t: 終点の頂点番号
     * @retval 最大フロー
     */
    T build(int s, int t){
        T ret = 0;
        while(true){
            for(int i = 0; i < V; ++i) used[i] = false;
            T f = dfs(s, t, numeric_limits<T>::max());
            if(f == 0) break;
            ret += f;
        }
        return ret;
    }
};

int main(void){
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for(int i = 0; i < E; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        g.d_add(u, v, c);
    }

    FordFulkerson ff(g);
    cout << ff.build(0, V - 1) << endl;
}