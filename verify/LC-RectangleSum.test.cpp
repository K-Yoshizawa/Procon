#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../Library/Template.hpp"
#include "../Library/Other/Compress.hpp"
#include "../Library/DataStructure/MergeSortTree.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    vector<tuple<ll, ll, ll>> points(N);
    for(int i = 0; i < N; ++i){
        ll x, y, w; cin >> x >> y >> w;
        points.emplace_back(x, y, w);
    }
    Sort(points);

    auto [x, y, w] = DisassembleVectorTuple(points);
    Compress cp(x, false);
    MergeSortTree<ll> mst(y, w, true);
    while(Q--){
        ll l, d, r, u; cin >> l >> d >> r >> u;
        int li = cp.LowerBound(l), ri = cp.LowerBound(r);
        cout << mst.SumBetween(li, ri, d, u - 1) << '\n';
    }
}