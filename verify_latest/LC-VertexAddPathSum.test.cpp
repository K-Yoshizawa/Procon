#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../latest/Tree/HeavyLightDecomposition.hpp"
#include "../latest/DataStructure/SegmentTree.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    vector<long long> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];

    vector<long long> Init_Data(N);
    Graph<long long> G(N);
    for(int i = 0; i < N - 1; ++i){
        int u, v; cin >> u >> v;
        G.add(u, v);
    }
    HeavyLightDecomposition<long long> HLD(G);
    for(int i = 0; i < N; ++i){
        Init_Data[HLD.get_vertex_locate(i)] = a[i];
    }

    SegmentTree<long long> seg(Init_Data, [](long long l, long long r){return l + r;}, 0, true);
    while(Q--){
        int query; cin >> query;
        if(query == 0){
            long long p, x; cin >> p >> x;
            int lp = HLD.get_vertex_locate(p);
            seg.update(lp, seg[lp] + x);
        }
        else{
            int u, v; cin >> u >> v;
            auto path = HLD.get_vertex_segment(u, v);
            long long ans = 0;
            for(auto [l, r] : path){
                ans += seg.query(l, r);
            }
            cout << ans << endl;
        }
    }

}