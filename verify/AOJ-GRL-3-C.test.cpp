#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include "../library/Graph/StronglyConnectedComponents.hpp"

int main(){
    int V, E; cin >> V >> E;
    GraphV G(V, true);
    G.input(E, false, true);

    StronglyConnectedComponents scc(G);
    int Q; cin >> Q;
    while(Q--){
        int u, v; cin >> u >> v;
        cout << scc.same(u, v) << endl;
    }
}