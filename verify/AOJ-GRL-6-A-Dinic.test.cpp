#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include "../library/Graph/Dinic.hpp"

int main(){
    int V, E;
    cin >> V >> E;
    Flow<int> G(V);
    for(int i = 0; i < E; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        G.add(u, v, c);
    }

    Dinic<int> dn(G);
    cout << dn.solve(0, V - 1) << endl;
}