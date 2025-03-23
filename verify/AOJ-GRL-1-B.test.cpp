#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include "../Library/Template.hpp"
#include "../Library/Graph/BellmanFord.hpp"

int main(){
    int V, E, r; cin >> V >> E >> r;
    auto G = InputGraph<ll>(V, E, 0, true, true);
    
    BellmanFord bf(G, r);
    if(bf.Negative()){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for(int i = 0; i < V; ++i){
        if(bf.Reachable(i)){
            cout << bf.Distance(i) << endl;
        }
        else{
            cout << "INF" << endl;
        }
    }
}