#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../Library/Template.hpp"
#include "../Library/Tree/HeavyLightDecomposition.hpp"
#include "../Library/DataStructure/SegmentTree.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    vector<ll> a(N); cin >> a;
    auto T = InputTree(N, 0);

    HeavyLightDecomposition hld(T);
    hld.SortVertex(a);
    SegmentTree<ll> seg(a, [](ll l, ll r){return l + r;}, 0LL, true);
    while(Q--){
        int t; cin >> t;
        if(t == 0){
            int p, x; cin >> p >> x;
            seg.Set(hld[p], seg[hld[p]] + x);
        }
        else{
            int u, v; cin >> u >> v;
            ll ans = 0;
            for(auto &path : hld.PathQuery(u, v)){
                ans += seg.Product(path.head_index, path.tail_index);
            }
            cout << ans << '\n';
        }
    }
}