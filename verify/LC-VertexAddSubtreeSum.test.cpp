#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../Library/Template.hpp"
#include "../Library/Tree/HeavyLightDecomposition.hpp"
#include "../Library/DataStructure/SegmentTree.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    vector<ll> a(N); cin >> a;
    RootedTree T(N);
    T.InputRootedTreeFormat(false, false);

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
            int u; cin >> u;
            auto [l, r] = hld.SubtreeQuery(u);
            cout << seg.Product(l, r) << '\n';
        }
    }
}