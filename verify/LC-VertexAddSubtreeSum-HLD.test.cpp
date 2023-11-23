#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../library/Tree/HeavyLightDecomposition.hpp"
#include "../library/DataStructure/SegmentTree.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    vector<long long> a(N), p(N);
    Graph<int> G(N);
    for(int i = 0; i < N; ++i) cin >> a[i];
    for(int i = 1; i < N; ++i){
        cin >> p[i];
        G.add(i, p[i]);
    }

    HeavyLightDecomposition<int> HLD(G);
    vector<long long> Init_Data(2 * N, 0);
    for(int i = 0; i < N; ++i){
        Init_Data[HLD.subtree_query(i).first] = a[i];
    }
    SegmentTree<long long> seg(Init_Data,
        [](long long l, long long r){return l + r;},
        0, true);

    while(Q--){
        int q; cin >> q;
        if(q == 0){
            int u, x; cin >> u >> x;
            int i = HLD.subtree_query(u).first;
            seg.update(i, seg[i] + x);
        }
        else{
            int u; cin >> u;
            auto [in, out] = HLD.subtree_query(u);
            cout << seg.query(in, out) << endl;
        }
    }
}