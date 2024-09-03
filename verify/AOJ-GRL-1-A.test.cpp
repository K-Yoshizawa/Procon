#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../Library/Template.hpp"
#include "../Library/Graph/Dijkstra.hpp"

int main(){
    int V, E, r; cin >> V >> E >> r;
    Graph<ll> G(V, true);
    G.InputGraph(E, true, false);
    
    Dijkstra dk(G);
    dk.Solve(r);
    for(int i = 0; i < V; ++i){
        if(dk.Reachable(i)){
            cout << dk.Distance(i) << endl;
        }
        else{
            cout << "INF" << endl;
        }
    }
}