#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/SegmentTree.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    vl a(N); cin >> a;

    SegmentTree<ll> seg(a, [](ll l, ll r){return l + r;}, 0LL, true);
    while(Q--){
        int t; cin >> t;
        if(t == 0){
            int p, x; cin >> p >> x;
            seg.Update(p, seg[p] + x);
        }
        else{
            int l, r; cin >> l >> r;
            cout << seg.Query(l, r) << endl;
        }
    }
}