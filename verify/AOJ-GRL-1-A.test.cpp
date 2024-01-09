#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../library/Graph/Dijkstra.hpp"

int main(){
    int V, E, r; cin >> V >> E >> r;
    GraphV<long long> G(V, true);
    G.input(E, true, true);

    Dijkstra dk(G);
    for(auto &d : dk.solve(r)){
        if(d == G.INF) cout << "INF" << endl;
        else cout << d << endl;
    }
}