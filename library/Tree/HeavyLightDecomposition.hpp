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
    Vertex m_root;
    int m_timer{0};

    Graph<CostType> &G;
    vector<int> m_subtreesize; // 頂点 `i` を根とする部分木の頂点数
    vector<int> m_depth; // 頂点 `i` の根からの深さ
    vector<Vertex> m_parentvertex; // 頂点 `i` の親の頂点（根の場合は `-1` ）
    // vector<EdgeID> m_parentedge; // 頂点 `i` とその親を結ぶ辺番号（根の場合は `-1` ）
    vector<Vertex> m_childvertex; // 辺 `i` が結ぶ2頂点のうち、子の方の頂点
    vector<int> m_in, m_out; // 頂点 `i` の行きがけ / 帰りがけの順番 (Euler-Tour)

    vector<vector<Vertex>> m_column; // 各列に含まれる頂点
    vector<pair<ColumnIndex, int>> m_vertexindex; // `Columns` 内における各頂点の位置情報「列 `first` の根から `second(0-index)` 番目にある」
    vector<int> m_offset; // 1列に並べたときの各列の先頭の位置（0-index）

    int m_dfs1(Vertex now, Vertex par){
        int ret = 0;
        for(Edge<CostType> e : G[now]){
            if(e.to == par) continue;
            m_depth[e.to] = m_depth[now] + 1;
            m_parentvertex[e.to] = now;
            // m_parentedge[e.to] = e.ID;
            // m_childvertex[e.ID] = e.to;
            ret += m_dfs1(e.to, now);
        }
        return m_subtreesize[now] = ret + 1;
    }

    void m_dfs2(Vertex now, Vertex par, ColumnIndex col){
        m_in[now] = m_timer++;

        // 新しい列の場合は列を増やす
        if(m_column.size() == col) m_column.emplace_back(vector<Vertex>{});

        // 列に頂点を追加
        m_vertexindex[now] = {col, m_column[col].size()};
        m_column[col].push_back(now);

        // Heavyな辺を探索
        Edge<CostType> heavy;
        int maxsubtree = 0;
        for(Edge<CostType> e : G[now]){
            if(e.to == par) continue;
            if(maxsubtree < m_subtreesize[e.to]){
                heavy = e;
                maxsubtree = m_subtreesize[e.to];
            }
        }

        if(maxsubtree){
            // Heavyな辺が存在する場合、今の列に追加する形で再帰を行う
            m_dfs2(heavy.to, now, col);
        }

        // Lightな辺に対して新しい列を生やしつつ再帰を行う
        for(Edge<CostType> e : G[now]){
            if(e.to == par || e.to == heavy.to) continue;
            m_dfs2(e.to, now, m_column.size());
        }

        m_out[now] = m_timer++;
    }

    /**
     * @brief 頂点 `v` が存在する列の先頭の頂点
     */
    Vertex m_head(Vertex v){
        auto [i, j] = m_vertexindex[v];
        return m_column[i][0];
    }

    public:
    HeavyLightDecomposition(Graph<CostType> &G, Vertex Root = 0) : G(G), m_root(Root){
        m_subtreesize.resize(G.size(), 0);
        m_depth.resize(G.size(), 0);
        m_parentvertex.resize(G.size(), -1);
        // m_parentedge.resize(G.size(), -1);
        // m_childvertex.resize(G.esize(), -1);
        m_dfs1(m_root, -1);
        m_vertexindex.resize(G.size());
        m_in.resize(G.size());
        m_out.resize(G.size());
        m_dfs2(m_root, -1, 0);
        m_offset.resize(m_column.size(), 0);
        for(int i = 1; i < m_column.size(); ++i){
            m_offset[i] = m_offset[i - 1] + m_column[i - 1].size();
        }
    }

    /**
     * @brief 木に含まれる全頂点について、HLDの列を1列に並べた列 `L` 内における位置を返す。
     * @return vector<int> 「頂点 `i` が `L_{ret[i]}` にある」という情報
     */
    vector<int> get_vertex_locations(){
        vector<int> ret(G.size(), -1);
        for(Vertex i = 0; i < G.size(); ++i){
            ret[i] = m_offset[m_vertexindex[i].first] + m_vertexindex[i].second;
        }
        return ret;
    }

    /**
     * @brief 頂点 `v` と頂点 `u` のLCAを求める。
     */
    Vertex lca(Vertex v, Vertex u){
        while(1){
            Vertex hv = m_head(v), hu = m_head(u);
            if(m_depth[hv] > m_depth[hu]) swap(v, u), swap(hv, hu);
            if(hv == hu) return (m_depth[v] < m_depth[u] ? v : u);
            u = m_parentvertex[hu];
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
        if(u == -1) u = m_root;
        while(1){
            Vertex hv = m_head(v), hu = m_head(u);
            if(m_depth[hv] > m_depth[hu]) swap(v, u), swap(hv, hu);
            if(hv == hu){
                if(m_depth[v] > m_depth[u]) swap(v, u);
                auto [vc, vi] = m_vertexindex[v];
                auto [uc, ui] = m_vertexindex[u];
                ret.push_back({m_offset[vc] + vi, m_offset[uc] + ui + 1});
                return ret;
            }
            auto [uc, ui] = m_vertexindex[u];
            ret.push_back({m_offset[uc], m_offset[uc] + ui + 1});
            u = m_parentvertex[hu];
        }
    }

    pair<int, int> subtree_query(Vertex v){
        return {m_in[v], m_out[v]};
    }

    void print_columns(){

    }
};