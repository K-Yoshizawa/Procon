/**
 * @file EulerTour.hpp
 * @brief Euler Tour - オイラーツアー
 * @version 3.0
 * @date 2024-02-11
 */

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct EulerTour{
    private:
    Graph<CostType> &G;
    vector<int> in_, out_;

    void dfs_(Vertex v, Vertex p, int &t){
        in_[v] = t++;
        for(auto &e : G[v]){
            if(e.to == p) continue;
            dfs_(e.to, v, t);
        }
        out_[v] = t++;
    }

    public:
    /**
     * @brief Construct a new Euler Tour object
     * @param G 木
     * @param Root 根の頂点番号(0-index)
     * @param Offset タイムスタンプの初期値
     */
    EulerTour(Graph<CostType> &G, Vertex Root = 0, int Offset = 0) : G(G){
        in_.resize(G.size());
        out_.resize(G.size());
        dfs_(Root, -1, Offset);
    }

    int in(Vertex v){
        assert(0 <= v && v < G.size());
        return in_[v];
    }

    int out(Vertex v){
        assert(0 <= v && v < G.size());
        return out_[v];
    }

    pair<vector<int>, vector<int>> get(){
        return make_pair(in_, out_);
    }

    pair<int, int> operator[](Vertex v){
        return make_pair(in(v), out(v));
    }
};