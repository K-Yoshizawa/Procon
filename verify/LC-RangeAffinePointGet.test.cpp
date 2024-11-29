#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../Library/Template.hpp"
#include "../Library/modint.hpp"
#include "../Library/DataStructure/DualSegmentTree.hpp"

struct OperatorMonoid{
    mint b, c;
    OperatorMonoid(mint b_ = 1, mint c_ = 0) : b(b_), c(c_){}
    static OperatorMonoid Composite(OperatorMonoid &l, OperatorMonoid &r){
        return OperatorMonoid(r.b * l.b, r.b * l.c + r.c);
    }
};

int main(){
    int N, Q; cin >> N >> Q;
    vector<mint> a(N); cin >> a;

    DualSegmentTree<OperatorMonoid> seg(
        N,
        [](OperatorMonoid l, OperatorMonoid r){return OperatorMonoid::Composite(l, r);},
        OperatorMonoid(),
        true
    );
    while(Q--){
        int t; cin >> t;
        if(t == 0){
            int l, r, b, c; cin >> l >> r >> b >> c;
            seg.Update(l, r, OperatorMonoid(b, c));
        }
        else{
            int i; cin >> i;
            OperatorMonoid op = seg.Query(i);
            cout << op.b * a[i] + op.c << endl;
        }
    }
}