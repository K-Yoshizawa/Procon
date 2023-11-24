#include "Template.hpp"

using Edge = pair<int, ll>;
using Graph = vector<vector<Edge>>;

pair<vi, vvi> scc(Graph &G, Graph &rG){
    vi vis(G.size(), 0), ord;
    vi belong(G.size(), -1);
    vvi sc;
    auto dfs = [&](auto self, int v) -> void {
        vis[v] = 1;
        for(auto [to, cost] : G[v]){
            if(!vis[to]) self(self, to);
        }
        ord.push_back(v);
    };
    auto rdfs = [&](auto self, int v, int k) -> void {
        vis[v] = 0;
        belong[v] = k;
        if(sc.size() == k) sc.push_back(vi{});
        sc[k].push_back(v);
        for(auto [to, cost] : rG[v]){
            if(vis[to]) self(self, to, k);
        }
    };
    for(int i = 0; i < G.size(); ++i){
        if(!vis[i]) dfs(dfs, i);
    }
    while(ord.size()){
        int i = ord.back();
        ord.pop_back();
        if(vis[i]){
            rdfs(rdfs, i, sc.size());
        }
    }
    return {belong, sc};
}