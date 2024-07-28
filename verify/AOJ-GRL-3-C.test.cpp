#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include "../library/Graph/StronglyConnectedComponents.hpp"

int main(){
    int V, E; cin >> V >> E;
    Graph G(V, true);
    for(int i = 0; i < E; ++i){
        int s, t; cin >> s >> t;
        G.add_edge(s, t);
    }
    
    StronglyConnectedComponents scc(G);
    int Q; cin >> Q;
    for(int i = 0; i < Q; ++i){
        int u, v; cin >> u >> v;
        cout << (scc.where(u) == scc.where(v)) << endl;
    }
}