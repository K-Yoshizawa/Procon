#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../Library/Template.hpp"
#include "../Library/modint.hpp"
#include "../Library/DataStructure/LazySegmentTree.hpp"

struct Monoid{
    mint a;
    int len;
    Monoid(mint a_ = 0, int len_ = 1) : a(a_), len(len_){}
    static Monoid Merge(Monoid &l, Monoid &r){
        return Monoid(l.a + r.a, l.len + r.len);
    }
};

struct OperatorMonoid{
    mint b, c;
    OperatorMonoid(mint b_ = 1, mint c_ = 0) : b(b_), c(c_){}
    static Monoid Mapping(Monoid &m, OperatorMonoid &op){
        return Monoid(op.b * m.a + op.c * m.len, m.len);
    }
    static OperatorMonoid Composite(OperatorMonoid &l, OperatorMonoid &r){
        return OperatorMonoid(r.b * l.b, r.b * l.c + r.c);
    }
};

int main(){
    int N, Q; cin >> N >> Q;
    vector<Monoid> A(N);
    for(int i = 0; i < N; ++i){
        mint a; cin >> a;
        A[i] = Monoid(a);
    }

    LazySegmentTree<Monoid, OperatorMonoid> seg(A,
        [](Monoid l, Monoid r){return Monoid::Merge(l, r);},
        [](Monoid m, OperatorMonoid op){return OperatorMonoid::Mapping(m, op);},
        [](OperatorMonoid l, OperatorMonoid r){return OperatorMonoid::Composite(l, r);},
        Monoid(),
        OperatorMonoid(),
        true);
    while(Q--){
        int t; cin >> t;
        if(t == 0){
            int l, r, b, c; cin >> l >> r >> b >> c;
            seg.Update(l, r, OperatorMonoid(b, c));
        }
        else{
            int l, r; cin >> l >> r;
            cout << seg.Query(l, r).a << endl;
        }
    }
}