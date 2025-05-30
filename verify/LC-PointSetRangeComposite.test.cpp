#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/SegmentTree.hpp"
#include "../Library/modint.hpp"

struct Affine{
    Affine(mint a = 1, mint b = 0) : a(a), b(b){}
    mint Value(mint x) const {
        return a * x + b;
    }
    static Affine Merge(Affine l, Affine r){
        return Affine(l.a * r.a, l.b * r.a + r.b);
    }
    mint a, b;
};

int main(){
    int N, Q; cin >> N >> Q;
    vector<Affine> init_data;
    for(int i = 0; i < N; ++i){
        int a, b; cin >> a >> b;
        init_data.push_back(Affine(a, b));
    }

    SegmentTree<Affine> seg(init_data, [](Affine l, Affine r){return Affine::Merge(l, r);}, Affine(), true);
    while(Q--){
        int t; cin >> t;
        if(t == 0){
            int p, c, d; cin >> p >> c >> d;
            seg.Set(p, Affine(c, d));
        }
        else{
            int l, r, x; cin >> l >> r >> x;
            cout << seg.Prod(l, r).Value(x) << endl;
        }
    }
}