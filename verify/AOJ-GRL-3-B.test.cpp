#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B"

#include "../Library/Template.hpp"
#include "../Library/Graph/LowLink.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int V, E; cin >> V >> E;
    auto G = InputGraph<ll>(V, E, 0, false, false);
    
    LowLink llk(G);
    auto ans = llk.Bridge();
    Sort(ans);
    for(const auto [s, t] : ans) cout << s << ' ' << t << '\n';
}