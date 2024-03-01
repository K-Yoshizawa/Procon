#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../library/Tree/HeavyLightDecomposition.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    Graph G(N);
    for(int i = 1; i < N; ++i){
        int p; cin >> p;
        G.add(i, p);
    }

    HeavyLightDecomposition hld(G);
    while(Q--){
        int u, v; cin >> u >> v;
        cout << hld.lca(u, v) << endl;
    }
}