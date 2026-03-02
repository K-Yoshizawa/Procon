#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include "../Library/Template.hpp"
#include "../Library/Graph/BellmanFord.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int V, E, r; cin >> V >> E >> r;
    auto G = InputGraph<ll>(V, E, 0, true, true);
    
    BellmanFord bf(G, r);
    if(bf.NegativeCycle()){
        cout << "NEGATIVE CYCLE" << '\n';
        return 0;
    }
    for(int i = 0; i < V; ++i){
        if(bf.Reachable(i)){
            cout << bf.Distance(i) << '\n';
        }
        else{
            cout << "INF" << '\n';
        }
    }
}