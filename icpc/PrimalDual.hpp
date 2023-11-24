#include "Template.hpp"

struct Edge{
    int to, rev;
    ll cap, cost;
};

struct mincostflow{
    vector<vector<Edge>> G;
    vl pt, mc;
    vi pv, pe;

    mincostflow(int sz) : G(sz){}

    void add(int s, int t, ll cap, ll cost){
        int cs = G[s].size(), ct = G[t].size();
        G[s].push_back(Edge{t, ct, cap, cost});
        G[t].push_back(Edge{s, cs, 0, -cost});
    }

    ll solve(int s, int t, ll f){
        int V = G.size();
        ll INF = numeric_limits<ll>::max() / 2;
        ll ret = 0;
        using p = pair<ll, int>;
        priority_queue<p, vector<p>, greater<p>> que;
        pt.assign(V, 0);
        pv.assign(V, -1);
        pe.assign(V, -1);
        while(f){
            mc.assign(V, INF);
            que.emplace(0, s);
            mc[s] = 0;
            while(que.size()){
                auto [d, v] = que.top();
                que.pop();
                if(mc[v] < d) continue;
                for(int i = 0; i < G[v].size(); ++i){
                    auto &e = G[v][i];
                    ll nc = mc[v] + e.cost + pt[v] - pt[e.to];
                    if(e.cap and mc[e.to] > nc){
                        mc[e.to] = nc;
                        pv[e.to] = v, pe[e.to] = i;
                        que.emplace(mc[e.to], e.to);
                    }
                }
            }
            if(mc[t] == INF) return -1;
            for(int i = 0; i < V; ++i) pt[i] += mc[i];
            ll af = f;
            for(int i = t; i != s; i = pv[i]){
                af = min(af, G[pv[i]][pe[i]].cap);
            }
            f -= af;
            ret += af * pt[t];
            for(int i = t; i != s; i = pv[i]){
                auto &e = G[pv[i]][pe[i]];
                e.cap -= af;
                G[i][e.rev].cap += af;
            }
        }
        return ret;
    }
};