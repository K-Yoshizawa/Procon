#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include "../latest/Graph/FordFulkerson.hpp"

int main(){
    int V, E;
    cin >> V >> E;
    Flow<int> G(V);
    for(int i = 0; i < E; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        G.add(u, v, c);
    }

    // G.print_incidentlist(false);
    // cerr << "Check" << endl;

    FordFulkerson<int> ff(G);
    cout << ff.solve(0, V - 1) << endl;
}