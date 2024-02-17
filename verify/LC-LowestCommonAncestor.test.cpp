#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../library/Tree/LowestCommonAncestor.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    Graph G(N);
    for(int i = 1; i < N; ++i){
        int p; cin >> p;
        G.add(i, p);
    }

    LowestCommonAncestor lca(G, 0);
    while(Q--){
        int u, v; cin >> u >> v;
        cout << lca.get(u, v) << endl;
    }
}