#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../library/modint.hpp"
#include "../library/DataStructure/DualSegmentTree.hpp"

struct Monoid{
    modint998 b, c;

    Monoid() : b(1), c(0) {}
    Monoid(modint998 b, modint998 c) : b(b), c(c) {}

    bool operator==(const Monoid &r){
        return b == r.b and c == r.c;
    }

    static Monoid Composite(Monoid l, Monoid r){
        return Monoid(l.b * r.b, r.b * l.c + r.c);
    }
};

int main(){
    int N, Q; cin >> N >> Q;
    vm998 a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];

    DualSegmentTree<Monoid> seg(N,
        [&](Monoid l, Monoid r){return Monoid::Composite(l, r);},
        Monoid(), true);
    
    while(Q--){
        int query; cin >> query;
        if(query == 0){
            int l, r, b, c; cin >> l >> r >> b >> c;
            seg.update(l, r, Monoid(b, c));
        }
        else{
            int i; cin >> i;
            Monoid ret = seg[i];
            cout << ret.b * a[i] + ret.c << endl;
        }
    }
}