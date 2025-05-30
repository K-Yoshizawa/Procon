#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../Library/Template.hpp"
#include "../Library/Tree/HeavyLightDecomposition.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    RootedTree T(N);
    T.InputRootedTreeFormat(false, false);

    HeavyLightDecomposition hld(T);
    while(Q--){
        int u, v; cin >> u >> v;
        cout << hld.LowestCommonAncestor(u, v) << '\n';
    }
}