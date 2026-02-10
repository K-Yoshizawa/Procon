#define PROBLEM "https://judge.yosupo.jp/problem/range_add_range_min"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/LazySegmentTree.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    vector<long long> a(N); cin >> a;
    LazySegmentTree<long long> seg(
        a,
        [](long long l, long long r){return min(l, r);},
        [](long long m, long long o){return m + o;},
        [](long long l, long long r){return l + r;},
        1LL << 60,
        0LL,
        true
    );
    while(Q--){
        int query; cin >> query;
        if(query == 0){
            int l, r; long long x;
            cin >> l >> r >> x;
            seg.Update(l, r, x);
        }
        else{
            int l, r; cin >> l >> r;
            cout << seg.Product(l, r) << '\n';
        }
    }
}