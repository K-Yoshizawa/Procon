#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../Library/Template.hpp"
#include "../Library/Graph/WarshallFloyd.hpp"

int main(){
    int V, E; cin >> V >> E;
    auto G = InputGraph<ll>(V, E, 0, true, true);
    
    WarshallFloyd wf(G);
    if(wf.Negative()){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            if(wf.Reachable(i, j)){
                cout << wf[i][j];
            }
            else{
                cout << "INF";
            }
            cout << " \n"[j + 1 == V];
        }
    }
}