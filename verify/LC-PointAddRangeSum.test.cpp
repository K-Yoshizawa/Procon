#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/SegmentTree.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    vector<ll> a(N); cin >> a;

    SegmentTree<ll> seg(a, [](ll l, ll r){return l + r;}, 0LL, true);
    while(Q--){
        int t; cin >> t;
        if(t == 0){
            int p, x; cin >> p >> x;
            seg.Set(p, seg[p] + x);
        }
        else{
            int l, r; cin >> l >> r;
            cout << seg.Product(l, r) << '\n';
        }
    }
}