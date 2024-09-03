#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../library/Tree/HeavyLightDecomposition.hpp"
#include "../library/DataStructure/SegmentTree.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    vector<long long> a(N);
    for(auto &ai : a) cin >> ai;
    Graph<long long> G(N);
    G.input(N - 1, false, true);

    HeavyLightDecomposition<long long> hld(G);
    vector<long long> init(N * 2);
    auto loc = hld.get_vertex_locations();
    for(int i = 0; i < N; ++i){
        init[loc[i]] = a[i];
    }
    SegmentTree<long long> seg(init,
        [&](long long l, long long r){return l + r;},
        0, true);

    while(Q--){
        int query; cin >> query;
        if(query == 0){
            long long p, x; cin >> p >> x;
            seg.update(loc[p], seg[loc[p]] + x);
        }
        else{
            int u, v; cin >> u >> v;
            long long ans = 0;
            for(auto [l, r] : hld.path_query(u, v)){
                ans += seg.query(l, r);
            }
            cout << ans << endl;
        }
    }
}