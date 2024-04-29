/**
 * @file HeavyLightDecomposition.hpp
 * @author log K (lX57)
 * @brief Heavy Light Decomposition - HL分解
 * @version 3.0
 * @date 2023-10-04
 */

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct HeavyLightDecomposition{
    using ColumnIndex = int;

    private:
    Vertex root_;
    int timer_{0};

    Graph<CostType> &G;
    vector<int> subtree_size_; // 頂点 `i` を根とする部分木の頂点数
    vector<int> depth_; // 頂点 `i` の根からの深さ
    vector<Vertex> parent_vertex_; // 頂点 `i` の親の頂点（根の場合は `-1` ）
    // vector<EdgeID> m_parentedge; // 頂点 `i` とその親を結ぶ辺番号（根の場合は `-1` ）
    vector<Vertex> child_vertex_; // 辺 `i` が結ぶ2頂点のうち、子の方の頂点
    vector<int> in_, out_; // 頂点 `i` の行きがけ / 帰りがけの順番 (Euler-Tour)

    vector<vector<Vertex>> column_; // 各列に含まれる頂点
    vector<pair<ColumnIndex, int>> vertex_index_; // `Columns` 内における各頂点の位置情報「列 `first` の根から `second(0-index)` 番目にある」
    vector<int> offset_; // 1列に並べたときの各列の先頭の位置（0-index）

    int dfs1_(Vertex now, Vertex par){
        int ret = 0;
        for(Edge<CostType> e : G[now]){
            if(e.to == par) continue;
            depth_[e.to] = depth_[now] + 1;
            parent_vertex_[e.to] = now;
            // m_parentedge[e.to] = e.ID;
            // child_vertex_[e.ID] = e.to;
            ret += dfs1_(e.to, now);
        }
        return subtree_size_[now] = ret + 1;
    }

    void dfs2_(Vertex now, Vertex par, ColumnIndex col){
        in_[now] = timer_++;

        // 新しい列の場合は列を増やす
        if(column_.size() == col) column_.emplace_back(vector<Vertex>{});

        // 列に頂点を追加
        vertex_index_[now] = {col, column_[col].size()};
        column_[col].push_back(now);

        // Heavyな辺を探索
        Edge<CostType> heavy;
        int maxsubtree = 0;
        for(Edge<CostType> e : G[now]){
            if(e.to == par) continue;
            if(maxsubtree < subtree_size_[e.to]){
                heavy = e;
                maxsubtree = subtree_size_[e.to];
            }
        }

        if(maxsubtree){
            // Heavyな辺が存在する場合、今の列に追加する形で再帰を行う
            dfs2_(heavy.to, now, col);
        }

        // Lightな辺に対して新しい列を生やしつつ再帰を行う
        for(Edge<CostType> e : G[now]){
            if(e.to == par || e.to == heavy.to) continue;
            dfs2_(e.to, now, column_.size());
        }

        out_[now] = timer_++;
    }

    /**
     * @brief 頂点 `v` が存在する列の先頭の頂点
     */
    Vertex head_(Vertex v){
        auto [i, j] = vertex_index_[v];
        return column_[i][0];
    }

    public:
    HeavyLightDecomposition(Graph<CostType> &G, Vertex Root = 0) : G(G), root_(Root){
        subtree_size_.resize(G.size(), 0);
        depth_.resize(G.size(), 0);
        parent_vertex_.resize(G.size(), -1);
        // m_parentedge.resize(G.size(), -1);
        // child_vertex_.resize(G.esize(), -1);
        dfs1_(root_, -1);
        vertex_index_.resize(G.size());
        in_.resize(G.size());
        out_.resize(G.size());
        dfs2_(root_, -1, 0);
        offset_.resize(column_.size(), 0);
        for(int i = 1; i < column_.size(); ++i){
            offset_[i] = offset_[i - 1] + column_[i - 1].size();
        }
    }

    /**
     * @brief 木に含まれる全頂点について、HLDの列を1列に並べた列 `L` 内における位置を返す。
     * @return vector<int> 「頂点 `i` が `L_{ret[i]}` にある」という情報
     */
    vector<int> get_vertex_locations(){
        vector<int> ret(G.size(), -1);
        for(Vertex i = 0; i < G.size(); ++i){
            ret[i] = offset_[vertex_index_[i].first] + vertex_index_[i].second;
        }
        return ret;
    }

    /**
     * @brief 頂点 `v` と頂点 `u` のLCAを求める。
     */
    Vertex lca(Vertex v, Vertex u){
        while(1){
            Vertex hv = head_(v), hu = head_(u);
            if(depth_[hv] > depth_[hu]) swap(v, u), swap(hv, hu);
            if(hv == hu) return (depth_[v] < depth_[u] ? v : u);
            u = parent_vertex_[hu];
        }
    }

    /**
     * @brief 頂点 `v` と頂点 `u` を結ぶパスに該当する区間を返す。
     * @param v 頂点 `v`
     * @param u 頂点 `u` (option, default = `root`)
     * @return vector<pair<int, int>> 区間の一覧(半開区間, 0-index)
     */
    vector<pair<int, int>> path_query(Vertex v, Vertex u = -1){
        vector<pair<int, int>> ret;
        if(u == -1) u = root_;
        while(1){
            Vertex hv = head_(v), hu = head_(u);
            if(depth_[hv] > depth_[hu]) swap(v, u), swap(hv, hu);
            if(hv == hu){
                if(depth_[v] > depth_[u]) swap(v, u);
                auto [vc, vi] = vertex_index_[v];
                auto [uc, ui] = vertex_index_[u];
                ret.push_back({offset_[vc] + vi, offset_[uc] + ui + 1});
                return ret;
            }
            auto [uc, ui] = vertex_index_[u];
            ret.push_back({offset_[uc], offset_[uc] + ui + 1});
            u = parent_vertex_[hu];
        }
    }

    pair<int, int> subtree_query(Vertex v){
        return {in_[v], out_[v]};
    }

    void print_columns(){

    }
};