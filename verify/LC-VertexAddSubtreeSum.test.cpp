#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../library/Tree/EulerTour.hpp"
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

    EulerTour<int> ET(G);
    vector<long long> Init_Data(2 * N, 0);
    for(int i = 0; i < N; ++i){
        Init_Data[ET.in(i) - 1] = a[i];
    }
    SegmentTree<long long> seg(Init_Data,
        [](long long l, long long r){return l + r;},
        0, false);

    while(Q--){
        int q; cin >> q;
        if(q == 0){
            int u, x; cin >> u >> x;
            seg.update(ET.in(u), seg[ET.in(u)] + x);
        }
        else{
            int u; cin >> u;
            auto [in, out] = ET[u];
            cout << seg.query(ET.in(u), ET.out(u)) << endl;
        }
    }
}