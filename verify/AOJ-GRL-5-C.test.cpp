#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../Library/Tree/LowestCommonAncestor.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    auto T = InputRootedTreeChild(n, 0);

    LowestCommonAncestor lca(T);
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        cout << lca.Query(u, v) << '\n';
    }
}