#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../library/DataStructure/SegmentTree.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    vector<long long> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];
    SegmentTree<long long> seg(a, [](long long x, long long y){return x + y;}, 0, true);
    for(int query = 0; query < Q; ++query){
        int q; cin >> q;
        if(q == 0){
            int p, x; cin >> p >> x;
            seg.update(p, seg[p] + x);
        }
        else{
            int l, r; cin >> l >> r;
            cout << seg.query(l, r) << endl;
        }
    }
}