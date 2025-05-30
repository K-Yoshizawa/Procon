#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../Library/Template.hpp"
#include "../Library/Tree/LowestCommonAncestor.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    RootedTree T(n);
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int c; cin >> c;
            T.AddEdge(i, c);
        }
    }

    LowestCommonAncestor lca(T);
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        cout << lca.Query(u, v) << '\n';
    }
}