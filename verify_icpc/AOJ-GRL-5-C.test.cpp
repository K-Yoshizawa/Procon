#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../icpc/HeavyLightDecomposition.hpp"

int main(){
    int n; cin >> n;
    Graph G(n);
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int c; cin >> c;
            G[i].push_back({c, 1});
            G[c].push_back({i, 1});
        }
    }

    hld HLD(G);
    int q; cin >> q;
    for(int i = 0; i < q; ++i){
        int u, v; cin >> u >> v;
        cout << HLD.lca(u, v) << endl;
    }
}