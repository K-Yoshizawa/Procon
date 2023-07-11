#pragma once

/**
 * @brief Heavy Light Decomposition - HL分解
 */

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct HeavyLightDecompsition{
    using Column = int;
    
    private:
    int sz;
    Vertex root;
    Graph<CostType> &G;
    vector<int> subtree_size; // 頂点iを根とする部分木の頂点数
    vector<pair<Vertex, EdgeNum>> relation; // 木の親子関係
    vector<vector<Vertex>> column_vertex; // 各列に含まれる頂点リスト
    vector<pair<Column, int>> column_index; // 各頂点の頂点リスト内の位置
    vector<int> offset; // 1列に並べたとき、各列の先頭の頂点の位置 (0-index)

    /**
     * @brief 頂点iを根とする部分木の頂点数を求めるDFS
     * @param v 根となる頂点番号
     * @param pre 親の頂点
     * @return int 頂点の部分木の頂点数
     */
    int dfs1(Vertex v, Vertex pre){
        int res = 0;
        for(auto &e : G.get_edges(v)){
            if(e.to == pre) continue;
            res += dfs1(e.to, v);
        }
        return subtree_size[v] = res + 1;
    }

    void dfs2(Vertex v, Vertex pre, Column col){
        if(column_vertex.size() == col) column_vertex.emplace_back(vector<Vertex>{});
        column_index[v] = pair<Column, int>(col, column_vertex[col].size());
        column_vertex[col].push_back(v);
        Vertex next = -1;
        int max_subtree = 0;
        for(auto &e : G.get_edges(v)){
            if(e.to == pre) continue;
            if(max_subtree < subtree_size[e.to]){
                next = e.to;
                max_subtree = subtree_size[e.to];
            }
        }
        if(next != -1) dfs2(next, v, col);
        for(auto &e : G.get_edges(v)){
            if(e.to == pre || e.to == next) continue;
            dfs2(e.to, v, column_vertex.size());
        }
        return;
    }

    /**
     * @brief 1列に並べたときの頂点vの位置
     * @param v 位置を知りたい頂点番号
     * @return int 列における位置(0-index)
     */
    inline int locate(Vertex v){
        auto [i, j] = column_index[v];
        return offset[i] + j;
    }
    
    public:
    HeavyLightDecompsition(Graph<CostType> &G, Vertex root = 0) : G(G), sz(G.size()), root(root){
        subtree_size.resize(sz, -1);
        dfs1(root, -1);
        column_index.resize(sz, pair<Column, int>(-1, -1));
        dfs2(root, -1, 0);
        offset.resize(column_vertex.size(), 0);
        for(int i = 1; i < column_vertex.size(); ++i){
            offset[i] = offset[i - 1] + column_vertex[i - 1].size();
        }
        relation = G.get_parent(root);
    }

    /**
     * @brief 頂点uから頂点vまでの区間の一覧を取得する。
     * @note 区間は半開区間として与えられ、頂点uを省略すると根とする
     * @param v: 子の方の頂点番号(0-index)
     * @param u: 親の方の頂点番号(0-index, option default = root)
     * @retval 半開区間の一覧
     */
    vector<pair<int, int>> get_segment(Vertex v, Vertex u = -1){
        if(u == -1) u = root;
        auto [uc, ui] = column_index[u];
        vector<pair<int, int>> ret;
        Vertex now = v;
        while(1){
            auto [c, i] = column_index[now];
            if(uc == c){
                ret.emplace_back(offset[uc] + ui, offset[c] + i + 1);
                break;
            }
            else ret.emplace_back(offset[c], offset[c] + i + 1);
            Vertex front = column_vertex[c][0];
            now = relation[front].first;
        }
        return ret;
    }

    /**
     * @brief グラフを1列に並べたときの各頂点に対応する値の配列を返す
     * @note セグ木とかの初期配列
     * @return vector<CostType> 
     */
    vector<CostType> get_data(){
        vector<CostType> ret(sz, 0);
        for(int i = 0; i < column_vertex.size(); ++i){
            for(int j = 0; j < column_vertex[i].size(); ++j){
                Vertex v = column_vertex[i][j];
                EdgeNum e = relation[v].second;
                if(e == -1) continue;
                ret[locate(v)] = G.get_edge(e).cost;
            }
        }
        return ret;
    }
};