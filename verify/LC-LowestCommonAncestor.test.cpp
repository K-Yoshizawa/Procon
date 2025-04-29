#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../Library/Tree/LowestCommonAncestor.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    auto T = InputRootedTreeParent(N, 0);

    LowestCommonAncestor lca(T);
    while(Q--){
        int u, v; cin >> u >> v;
        cout << lca.Query(u, v) << '\n';
    }
}