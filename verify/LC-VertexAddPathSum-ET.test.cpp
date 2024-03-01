#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../library/Tree/EulerTour.hpp"
#include "../library/Tree/LowestCommonAncestor.hpp"
#include "../library/DataStructure/SegmentTree.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    vector<long long> a(N);
    for(auto &ai : a) cin >> ai;
    Graph<long long> G(N);
    G.input(N - 1, false, true);

    EulerTour et(G);
    auto [in, out] = et.get();
    vector<long long> b(N * 2, 0);
    for(int i = 0; i < N; ++i){
        b[in[i]] = a[i], b[out[i]] = -a[i];
    }
    LowestCommonAncestor lca(G);
    SegmentTree<long long> seg(b, [&](long long l, long long r){return l + r;}, 0LL, true);

    while(Q--){
        int query; cin >> query;
        if(query == 0){
            long long p, x; cin >> p >> x;
            long long y = a[p] + x;
            a[p] += x;
            seg.update(in[p], y);
            seg.update(out[p], -y);
        }
        else{
            int u, v; cin >> u >> v;
            int t = lca.get(u, v);
            cout << seg.query(in[t], in[u] + 1) + seg.query(in[t], in[v] + 1) - a[t] << endl;
        }
    }
}