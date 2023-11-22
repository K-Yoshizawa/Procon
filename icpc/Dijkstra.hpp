#include "Template.hpp"

using Edge = pair<int, ll>;
using GR = vector<vector<Edge>>;

ll INF = (1LL << 31) - 1;

vl dijkstra(GR &g, int s){
    using p = pair<ll, int>;
    vl ret(g.size(), INF);
    ret[s] = 0;
    priority_queue<p, vector<p>, greater<p>> que;
    que.push({0, s});
    while(que.size()){
        auto [d, v] = que.top(); que.pop();
        if(ret[v] < d) continue;
        for(auto [t, c] : g[v]){
            if(d + c < ret[t]){
                ret[t] = d + c;
                que.push({ret[t], t});
            }
        }
    }
    return ret;
}