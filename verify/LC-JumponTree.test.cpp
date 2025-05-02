#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "../Library/Tree/HeavyLightDecomposition.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    Graph T = InputTree(N, 0);

    HeavyLightDecomposition hld(T);
    while(Q--){
        int s, t, i; cin >> s >> t >> i;
        cout << hld.Jump(s, t, i) << '\n';
    }
}