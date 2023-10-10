#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../library/Tree/HeavyLightDecomposition.hpp"

int main(){
    int n; cin >> n;
    Graph<int> G(n);
    for(int i = 0; i <= n - 1; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int c; cin >> c;
            G.add(i, c);
        }
    }

    HeavyLightDecomposition<int> HLD(G);
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        cout << HLD.lca(u, v) << endl;
    }
}