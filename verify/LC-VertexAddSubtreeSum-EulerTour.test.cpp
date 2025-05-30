#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../Library/Template.hpp"
#include "../Library/Tree/EulerTour.hpp"
#include "../Library/DataStructure/SegmentTree.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    vector<ll> a(N); cin >> a;
    RootedTree T(N);
    T.InputRootedTreeFormat(false, false);

    EulerTour et(T);
    auto A = et.ConvertVector(a, [](ll x){return x;}, [](ll x){return 0;});
    SegmentTree<ll> seg(A, [](ll l, ll r){return l + r;}, 0LL, true);
    while(Q--){
        int t; cin >> t;
        if(t == 0){
            int u, x; cin >> u >> x;
            seg.Set(et.get_in(u), seg[et.get_in(u)] + x);
        }
        else{
            int u; cin >> u;
            auto [l, r] = et.get_pair(u);
            cout << seg.Prod(l, r) << endl;
        }
    }
}