#include "Template.hpp"

struct Edge{
    int to, rev;
    ll cap;
};

struct flow{
    vector<vector<Edge>> G;
    vi dist, iter;

    void bfs(int s){
        dist.assign(G.size(), -1);
        dist[s] = 0;
        queue<int> que;
        que.push(s);
        while(que.size()){
            int v = que.front();
            que.pop();
            for(auto e : G[v]){
                if(e.cap and dist[e.to] < 0){
                    dist[e.to] = dist[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    ll dfs(int v, int t, ll f){
        if(v == t) return f;
        for(int &i = iter[v]; i < G[v].size(); ++i){
            auto &e = G[v][i];
            if(e.cap and dist[v] < dist[e.to]){
                ll d = dfs(e.to, t, min(f, e.cap));
                if(d){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow(int sz) : G(sz), dist(sz), iter(sz){}

    void add(int s, int t, ll c){
        int cs = G[s].size(), ct = G[t].size();
        G[s].push_back(Edge{t, ct, c});
        G[t].push_back(Edge{s, cs, 0});
    }

    ll solve(int s, int t){
        ll ret = 0;
        ll INF = numeric_limits<ll>::max() / 2;
        while(1){
            bfs(s);
            if(dist[t] < 0) return ret;
            iter.assign(G.size(), 0);
            ll f;
            while(f = dfs(s, t, INF)) ret += f;
        }
    }
};