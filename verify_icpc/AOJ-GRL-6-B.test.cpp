#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include "../icpc/PrimalDual.hpp"

int main(){
    int V, E, F; cin >> V >> E >> F;
    mincostflow G(V);
    for(int i = 0; i < E; ++i){
        int u, v, c, d; cin >> u >> v >> c >> d;
        G.add(u, v, c, d);
    }
    cout << G.solve(0, V - 1, F) << endl;
}