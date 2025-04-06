#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A"

#include "../Library/Template.hpp"
#include "../Library/Graph/LowLink.hpp"

int main(){
    int V, E; cin >> V >> E;
    auto G = InputGraph<ll>(V, E, 0, false, false);
    
    LowLink llk(G);
    auto ans = llk.ArticulationVertex();
    Sort(ans);
    for(const int v : ans) cout << v << '\n';
}