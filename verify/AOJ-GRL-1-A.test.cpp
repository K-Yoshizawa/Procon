#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../Library/Template.hpp"
#include "../Library/Graph/Dijkstra.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int V, E, r; cin >> V >> E >> r;
    auto G = InputGraph<ll>(V, E, 0, true, true);
    
    Dijkstra dk(G, r);
    for(int i = 0; i < V; ++i){
        if(dk.Reachable(i)){
            cout << dk.Distance(i) << '\n';
        }
        else{
            cout << "INF" << '\n';
        }
    }
}