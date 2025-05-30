#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include "../Library/Template.hpp"
#include "../Library/Graph/StronglyConnectedComponents.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int V, E; cin >> V >> E;
    auto G = InputGraph<ll>(V, E, 0, false, true);
    
    StronglyConnectedComponents scc(G);
    int Q; cin >> Q;
    while(Q--){
        int u, v; cin >> u >> v;
        cout << (scc.BelongComponent(u) == scc.BelongComponent(v)) << '\n';
    }
}