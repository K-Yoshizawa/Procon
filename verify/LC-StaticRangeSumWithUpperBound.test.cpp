#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum_with_upper_bound"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/MergeSortTree.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    vector<ll> a(N); cin >> a;

    MergeSortTree<ll> mst(a, true);
    while(Q--){
        ll l, r, x; cin >> l >> r >> x;
        cout << mst.CountAtMost(l, r, x) << ' ' << mst.SumAtMost(l, r, x) << '\n';
    }
}