#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A"

#include "../Library/Template.hpp"
#include "../Library/Graph/CycleDetection.hpp"

int main(){
    int V, E; cin >> V >> E;
    auto G = InputGraph<ll>(V, E, 0, false, true);
    
    cout << !(CycleDetection(G).empty()) << endl;
}