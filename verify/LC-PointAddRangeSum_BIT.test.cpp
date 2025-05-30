#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/BinaryIndexedTree.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    BinaryIndexedTree<ll> BIT(N);
    for(int i = 1; i <= N; ++i){
        ll a; cin >> a;
        BIT.Add(i, a);
    }

    while(Q--){
        int t; cin >> t;
        if(t == 0){
            int p, x; cin >> p >> x, ++p;
            BIT.Add(p, x);
        }
        else{
            int l, r; cin >> l >> r, ++l;
            cout << BIT.Sum(l, r) << '\n';
        }
    }
}