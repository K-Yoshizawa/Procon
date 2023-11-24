#include "Template.hpp"

using Edge = pair<int, ll>;
using Graph = vector<vector<Edge>>;

struct hld{
    Graph &G;
    vi subtree, depth, ofs, pv;

    int timer = 1;
    vi in, out;
    
    vvi column;
    vector<pi> loc;

    int dfs1(int v, int p){
        int ret = 0;
        for(auto [to, cost] : G[v]){
            if(to == p) continue;
            depth[to] = depth[v] + 1;
            pv[to] = v;
            ret += dfs1(to, v);
        }
        return subtree[v] = ret + 1;
    }

    void dfs2(int v, int p, int c){
        in[v] = timer++;
        if(column.size() == c) column.emplace_back(vi{});
        loc[v] = {c, column[c].size()};
        column[c].push_back(v);
        Edge heavy;
        int mst = 0;
        for(auto [to, cost] : G[v]){
            if(to == p) continue;
            if(mst < subtree[to]){
                heavy = {to, cost};
                mst = subtree[to];
            }
        }
        if(mst) dfs2(heavy.first, v, c);
        for(auto [to, cost] : G[v]){
            if(to == p or to == heavy.first) continue;
            dfs2(to, v, column.size());
        }
        out[v] = timer++;
    }

    int head(int v){
        auto [i, j] = loc[v];
        return column[i][0];
    }

    hld(Graph &G) : G(G){
        int V = G.size();
        subtree.resize(V, 0);
        depth.resize(V, 0);
        pv.resize(V, -1);
        dfs1(0, -1);
        loc.resize(V);
        in.resize(V);
        out.resize(V);
        dfs2(0, -1, 0);
        ofs.resize(column.size(), 1);
        for(int i = 1; i < column.size(); ++i){
            ofs[i] = ofs[i - 1] + column[i - 1].size();
        }
    }

    vi location(){
        vi ret(G.size(), -1);
        for(int i = 0; i < G.size(); ++i){
            ret[i] = ofs[loc[i].first] + loc[i].second;
        }
        return ret;
    }

    int lca(int u, int v){
        while(1){
            int hu = head(u), hv = head(v);
            if(depth[hu] > depth[hv]) swap(u, v), swap(hu, hv);
            if(hu == hv) return (depth[u] < depth[v] ? u : v);
            v = pv[hv];
        }
    }

    vector<pi> pathquery(int u, int v = 0){
        vector<pi> ret;
        while(1){
            int hu = head(u), hv = head(v);
            if(depth[hu] > depth[hv]) swap(u, v), swap(hu, hv);
            if(hu == hv){
                if(depth[u] > depth[v]) swap(u, v);
                auto [uc, ui] = loc[u];
                auto [vc, vi] = loc[v];
                ret.push_back({ofs[uc] + ui, ofs[vc] + vi + 1});
                return ret;
            }
            auto [vc, vi] = loc[v];
            ret.push_back({ofs[vc], ofs[vc] + vi + 1});
            v = pv[hv];
        }
    }

    pi subtreequery(int v){
        return {in[v], out[v]};
    }
};