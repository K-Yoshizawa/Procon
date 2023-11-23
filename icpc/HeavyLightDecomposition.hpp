#include "Template.hpp"

using Edge = pair<int, ll>;
using Graph = vector<vector<Edge>>;

struct hld{
    Graph &G;
    vi subtree, depth;
    
    int dfs1(int v, int p){
        int ret = 0;
        for(auto [to, cost] : G[v]){
            if(to == p) continue;
            
        }
    }
};