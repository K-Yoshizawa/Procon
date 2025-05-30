#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../Library/DataStructure/RollbackUnionFind.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    using qs = tuple<int, int, int, int>;
    vector<vector<qs>> G(Q + 1);
    for(int i = 1; i <= Q; ++i){
        int t, k, u, v; cin >> t >> k >> u >> v, ++k;
        G[k].push_back({t, i, u, v});
    }

    RollbackUnionFind uf(N);
    vector<int> ans(Q + 1, -1);
    auto dfs = [&](auto self, const qs &query) -> void {
        auto [t, i, u, v] = query;
        if(t == 1){
            ans[i] = uf.Same(u, v);
        }
        else{
            if(t == 0) uf.Unite(u, v);
            for(auto nquery : G[i]) self(self, nquery);
            if(t == 0) uf.Undo();
        }
    };
    dfs(dfs, {-1, 0, 0, 0});
    for(auto a : ans){
        if(a != -1) cout << a << '\n';
    }
}