/**
 * @file StronglyConnectedComponents.hpp
 * @brief Strongly Connected Components - 強連結成分分解
 * @version 3.1
 * @date 2024-02-11
 */

#include "Graph.hpp"

template<typename CostType>
struct StronglyConnectedComponents{
    private:
    Graph<CostType> &G;
    Graph<CostType> rG;

    size_t V;
    vector<vector<Vertex>> components_;
    vector<int> belong_;

    void dfs1(Vertex v, vector<int> &label, int &nex, vector<bool> &state){
        state[v] = true;
        for(auto &e : G[v]){
            if(state[e.to]) continue;
            dfs1(e.to, label, nex, state);
        }
        label[v] = nex++;
        return;
    }

    void dfs2(Vertex v, vector<int> &label, int component, vector<bool> &state){
        components_[component].push_back(v);
        belong_[v] = component;
        state[v] = false;
        for(auto &e : rG[v]){
            if(!state[e.to]) continue;
            dfs2(e.to, label, component, state);
        }
        return;
    }

    public:
    /**
     * @brief 有向グラフ G を強連結成分分解する。
     */
    StronglyConnectedComponents(Graph<CostType> &G) : G(G), V(G.get_vertex_size()){
        rG = reverse(G);
        vector<int> label(V, -1);
        vector<bool> state(V, false);
        int nex = 0;
        vector<Vertex> vs(V);
        iota(vs.begin(), vs.end(), 0);
        for(auto v : vs){
            if(!state[v]) dfs1(v, label, nex, state);
        }
        sort(vs.begin(), vs.end(), [&](Vertex u, Vertex v){
            return label[u] > label[v];
        });
        belong_.resize(V, -1);
        for(auto v : vs){
            if(state[v]){
                int c = components_.size();
                components_.push_back(vector<Vertex>{});
                dfs2(v, label, c, state);
            }
        }
    }

    /**
     * @brief 強連結成分を取得する。
     * @note 強連結成分はトポロジカル順に並んでいる。
     * @return vector<vector<Vertex>>& 強連結成分の一覧
     */
    vector<vector<Vertex>> &get_components(){
        return components_;
    }

    /**
     * @brief 強連結成分の数を取得する。
     * @return size_t 強連結成分の数
     */
    size_t get_components_size(){
        return components_.size();
    }

    /**
     * @brief グラフ G の頂点 `v` がどの強連結成分に属するかを返す。
     * @param v グラフ G の頂点
     * @return int 所属する強連結成分の番号
     */
    int where(Vertex v){
        return belong_[v];
    }
};