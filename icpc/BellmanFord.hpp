#include "Template.hpp"

using Edge = tuple<int, int, ll>;
using ES = vector<Edge>;

ll INF = (1LL << 31) - 1;

vl bellmanford(ES &e, int st, int v){
    using p = pair<ll, int>;
    vl ret(v, INF);
    ret[st] = 0;
    int cnt = 0;
    while(1){
        if(cnt == v) return vl{};
        bool f = false;
        for(auto [s, t, d] : e){
            if(ret[s] == INF) continue;
            if(ret[s] + d < ret[t]){
                ret[t] = ret[s] + d;
                f = true;
            }
        }
        if(!f) break;
        ++cnt;
    }
    return ret;
}