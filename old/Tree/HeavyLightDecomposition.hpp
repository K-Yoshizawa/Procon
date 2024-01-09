/**
 * @file HeavyLightDecomposition.hpp
 * @author log K (lX57)
 * @brief Heavy Light Decomposition - HL分解
 * @version 2.0
 * @date 2023-10-04
 */

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct HeavyLightDecomposition{
    using ColumnIndex = int;

    private:
    Vertex __Root;
    int __Timer;

    Graph<CostType> &G;
    vector<int> __SubtreeSize; // 頂点 `i` を根とする部分木の頂点数
    vector<int> __Depth; // 頂点 `i` の根からの深さ
    vector<Vertex> __ParentVertex; // 頂点 `i` の親の頂点（根の場合は `-1` ）
    vector<EdgeID> __ParentEdge; // 頂点 `i` とその親を結ぶ辺番号（根の場合は `-1` ）
    vector<Vertex> __ChildVertex; // 辺 `i` が結ぶ2頂点のうち、子の方の頂点
    vector<int> __In, __Out; // 頂点 `i` の行きがけ / 帰りがけの順番 (Euler-Tour)

    vector<vector<Vertex>> __Columns; // 各列に含まれる頂点
    vector<pair<ColumnIndex, int>> __VertexIndex; // `Columns` 内における各頂点の位置情報
    vector<int> __Offset; // 1列に並べたときの各列の先頭の位置（0-index）

    int __dfs1(Vertex now, Vertex par){
        int ret = 0;
        for(Edge<CostType> e : G.get_incident(now)){
            if(e.to == par) continue;
            __Depth[e.to] = __Depth[now] + 1;
            __ParentVertex[e.to] = now;
            __ParentEdge[e.to] = e.ID;
            __ChildVertex[e.ID] = e.to;
            ret += __dfs1(e.to, now);
        }
        return __SubtreeSize[now] = ret + 1;
    }

    void __dfs2(Vertex now, Vertex par, ColumnIndex col){
        __In[now] = __Timer++;

        // 新しい列の場合は列を増やす
        if(__Columns.size() == col) __Columns.emplace_back(vector<Vertex>{});

        // 列に頂点を追加
        __VertexIndex[now] = {col, __Columns[col].size()};
        __Columns[col].push_back(now);

        // Heavyな辺を探索
        Edge<CostType> heavy;
        int maxsubtree = 0;
        for(Edge<CostType> e : G.get_incident(now)){
            if(e.to == par) continue;
            if(maxsubtree < __SubtreeSize[e.to]){
                heavy = e;
                maxsubtree = __SubtreeSize[e.to];
            }
        }

        if(maxsubtree){
            // Heavyな辺が存在する場合、今の列に追加する形で再帰を行う
            __dfs2(heavy.to, now, col);
        }

        // Lightな辺に対して新しい列を生やしつつ再帰を行う
        for(Edge<CostType> e : G.get_incident(now)){
            if(e.to == par || e.to == heavy.to) continue;
            __dfs2(e.to, now, __Columns.size());
        }

        __Out[now] = __Timer++;
    }

    Vertex __gethead(Vertex v){
        auto [i, j] = __VertexIndex[v];
        return __Columns[i][0];
    }

    public:
    HeavyLightDecomposition(Graph<CostType> &G, Vertex Root = 0) : G(G), __Root(Root), __Timer(0){
        __SubtreeSize.resize(G.vsize(), 0);
        __Depth.resize(G.vsize(), 0);
        __ParentVertex.resize(G.vsize(), -1);
        __ParentEdge.resize(G.vsize(), -1);
        __ChildVertex.resize(G.esize(), -1);
        __dfs1(__Root, -1);
        __VertexIndex.resize(G.vsize());
        __In.resize(G.vsize());
        __Out.resize(G.vsize());
        __dfs2(__Root, -1, 0);
        __Offset.resize(__Columns.size(), 0);
        for(int i = 1; i < __Columns.size(); ++i){
            __Offset[i] = __Offset[i - 1] + __Columns[i - 1].size();
        }
    }

    int get_vertex_locate(Vertex v){
        return __Offset[__VertexIndex[v].first] + __VertexIndex[v].second;
    }

    vector<int> get_vertex_locations(){
        vector<int> ret(G.vsize(), -1);
        for(Vertex i = 0; i < G.vsize(); ++i){
            ret[i] = __Offset[__VertexIndex[i].first] + __VertexIndex[i].second;
        }
        return ret;
    }

    Vertex lca(Vertex v, Vertex u){
        while(1){
            Vertex hv = __gethead(v), hu = __gethead(u);
            if(__Depth[hv] > __Depth[hu]) swap(v, u), swap(hv, hu);
            if(hv == hu) return (__Depth[v] < __Depth[u] ? v : u);
            u = __ParentVertex[hu];
        }
    }

    /**
     * @brief 頂点 `v` と頂点 `u` を結ぶパスに該当する区間を返す。
     * @param v 頂点 `v`
     * @param u 頂点 `u` (option, default = `root`)
     * @return vector<pair<int, int>> 区間の一覧(半開区間)
     */
    vector<pair<int, int>> path_query(Vertex v, Vertex u = -1){
        vector<pair<int, int>> ret;
        if(u == -1) u = __Root;
        while(1){
            Vertex hv = __gethead(v), hu = __gethead(u);
            if(__Depth[hv] > __Depth[hu]) swap(v, u), swap(hv, hu);
            if(hv == hu){
                if(__Depth[v] > __Depth[u]) swap(v, u);
                auto [vc, vi] = __VertexIndex[v];
                auto [uc, ui] = __VertexIndex[u];
                ret.push_back({__Offset[vc] + vi, __Offset[uc] + ui + 1});
                return ret;
            }
            auto [uc, ui] = __VertexIndex[u];
            ret.push_back({__Offset[uc], __Offset[uc] + ui + 1});
            u = __ParentVertex[hu];
        }
    }

    pair<int, int> subtree_query(Vertex v){
        return {__In[v], __Out[v]};
    }

    void print_columns(){

    }
};