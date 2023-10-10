#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include "../library/Tree/HeavyLightDecomposition.hpp"
#include "../library/DataStructure/SegmentTree.hpp"

int main(){
    int n; cin >> n;
    Graph<long long> G(n);
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int c; cin >> c;
            G.add(i, c);
        }
    }

    HeavyLightDecomposition<long long> HLD(G);
    auto vdic = HLD.get_vertex_locations();
    vector<long long> Init_Data(n, 0);
    SegmentTree<long long> seg(Init_Data, [](long long x, long long y){return x + y;}, 0LL, true);

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int v, w; cin >> v >> w;
            seg.update(vdic[v], seg[vdic[v]] + w);
        }
        else{
            int u; cin >> u;
            auto ret = HLD.get_vertex_segment(0, u);
            long long ans = 0LL;
            for(auto [l, r] : ret){
                ans += seg.query(l, r);
            }
            cout << ans << endl;
        }
    }
}