#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../Library/Template.hpp"
#include "../Library/Tree/LowestCommonAncestor.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    RootedTree T(N);
    T.InputRootedTreeFormat(false, false);

    LowestCommonAncestor lca(T);
    while(Q--){
        int u, v; cin >> u >> v;
        cout << lca.Query(u, v) << endl;
    }
}