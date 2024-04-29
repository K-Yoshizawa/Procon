/**
 * @file StronglyConnectedComponents.hpp
 * @brief Strongly Connected Components - 強連結成分分解
 * @version 3.1
 * @date 2024-02-11
 */

#include "GraphTemplate.hpp"

template<typename CostType>
struct StronglyConnectedComponents{
    private:
    Graph<CostType> &G;
    Graph<CostType> rG;
    vector<int> visited_, order_, belong_;
    vector<vector<Vertex>> member_;

    void f_dfs(Vertex v){
        visited_[v] = 1;
        for(auto &e : G[v]){
            if(!visited_[e.to]) f_dfs(e.to);
        }
        order_.push_back(v);
    }

    void f_rdfs(Vertex v, int k){
        visited_[v] = 0;
        belong_[v] = k;
        member_[k].push_back(v);
        for(auto &e : rG[v]){
            if(visited_[e.to]) f_rdfs(e.to, k);
        }
    }

    public:
    StronglyConnectedComponents(Graph<CostType> &G) : G(G){
        rG = G.reverse();
        visited_.resize(G.size(), 0);
        belong_.resize(G.size(), -1);
        for(int i = 0; i < G.size(); ++i){
            if(!visited_[i]) f_dfs(i);
        }
        int k = 0;
        for(int i = order_.size() - 1; i >= 0; --i){
            if(visited_[order_[i]]){
                member_.push_back(vector<CostType>{});
                f_rdfs(order_[i], k++);
            }
        }
    }

    int where(Vertex v){
        return belong_.at(v);
    }

    bool same(Vertex u, Vertex v){
        return where(u) == where(v);
    }

    vector<vector<Vertex>> &get(){
        return member_;
    }

    Graph<CostType> build(){
        Graph<CostType> ret(member_.size(), true);
        for(int i = 0; i < G.size(); ++i){
            int from = where(i);
            for(auto &e : G[i]){
                int to = where(e.to);
                if(from == to) continue;
                ret.add(from, to, e.cost);
            }
        }
        return ret;
    }

    int operator[](Vertex v){
        return where(v);
    }

    void print(){
        for(int i = 0; i < member_.size(); ++i){
            cout << "Component " << i << " : ";
            for(auto v : member_[i]){
                cout << v << " ";
            }
            cout << endl;
        }
    }
};