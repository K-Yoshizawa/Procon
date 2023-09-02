#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../latest/DataStructure/SegmentTree.hpp"
#include "../latest/Tree/EulerTour.hpp"
#include "../latest/Tree/LowestCommonAncestor.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    vector<long long> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];
    Graph<long long> G(N);
    for(int i = 0; i < N - 1; ++i){
        Vertex u, v; cin >> u >> v;
        G.add(u, v);
    }
    auto rel = G.convert_rootedtree();

    SegmentTree<long long> seg(N * 2, [](long long a, long long b){return a + b;}, 0, true);
    EulerTour<long long> et(G, 0, 0);
    LowestCommonAncestor<long long> lca(G);
    auto idx = et.get_arrival_list();
    auto odx = et.get_departure_list();
    for(int i = 0; i < N; ++i){
        seg.set(idx[i], a[i]);
        seg.set(odx[i], -a[i]);
    }
    seg.build();
    // cerr << "Check Point" << endl;
    while(Q--){
        // cerr << "Query Start" << endl;
        int q; cin >> q;
        if(q == 0){
            int p, x; cin >> p >> x;
            seg.update(idx[p], seg[idx[p]] + x);
        }
        else{
            int u, v; cin >> u >> v;
            Vertex w = lca.query(u, v);
            // cerr << " - LCA = " << w << endl;
            // cerr << " - Place = " << idx[u] << ", " << idx[v] << endl;
            long long ans = seg.query(0, idx[u] + 1) + seg.query(0, idx[v] + 1) - seg.query(0, idx[w] + 1);
            // cerr << " - Tmp Ans = " << ans << endl;
            if(w != 0) ans -= seg.query(0, idx[w]);
            cout << ans << endl;
        }
        // cerr << "Query End" << endl;
    }
}