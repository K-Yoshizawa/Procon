#pragma once

/**
 * @brief Heavy Light Decomposition - HL分解
 */

#include "../Graph/GraphTemplate.hpp"
#include "../DataStructure/BinaryIndexedTreeDouble.hpp"

template<typename CostType>
struct HeavyLightDecompsition{
    using Column = int;
    
    private:
    int sz;
    Graph<CostType> &G;
    vector<int> subtree_size; // 頂点iを根とする部分木の頂点数
    vector<pair<Vertex, EdgeNum>> relation; // 木の親子関係
    vector<vector<Vertex>> column_vertex; // 各列に含まれる頂点リスト
    vector<pair<Column, int>> column_index; // 各頂点の頂点リスト内の位置
    vector<int> offset; // 1列に並べたとき、各列の先頭の頂点の位置 (1-index)

    BinaryIndexedTreeDouble<CostType> BIT; // BITの配列の要素は「その要素が示す頂点の親との結ぶ辺の重み」を表す

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
     * @brief 根から頂点vまでの区間の一覧を取得する。
     * @note 区間は半開区間として与えられる
     * @param v: 頂点番号(0-index)
     * @retval 半開区間の一覧
     */
    vector<pair<int, int>> get_segment(Vertex v){
        vector<pair<int, int>> ret;
        Vertex now = v;
        while(now != -1){
            auto [c, i] = column_index[now];
            ret.emplace_back(offset[c], offset[c] + i + 1);
            Vertex front = column_vertex[c][0];
            now = relation[front].first;
        }
        return ret;
    }

    inline int locate(Vertex v){
        auto [i, j] = column_index[v];
        return offset[i] + j;
    }
    
    public:
    HeavyLightDecompsition(Graph<CostType> &G, Vertex root = 0) : G(G), sz(G.size()), BIT(G.size()){
        subtree_size.resize(sz, -1);
        dfs1(root, -1);
        column_index.resize(sz, pair<Column, int>(-1, -1));
        dfs2(root, -1, 0);
        offset.resize(column_vertex.size(), 1);
        for(int i = 1; i < column_vertex.size(); ++i){
            offset[i] = offset[i - 1] + column_vertex[i - 1].size();
        }
        relation = G.get_parent(root);
    }

    CostType query(Vertex v){
        auto seg = get_segment(v);
        CostType ret = 0;
        for(auto &[s, t] : seg){
            ret += BIT.query(s, t);
        }
        return ret;
    }

    void add(Vertex v, CostType x){
        auto seg = get_segment(v);
        for(auto &[s, t] : seg){
            BIT.add(s, t, x);
        }
        BIT.add(1, 2, -x);
    }
};