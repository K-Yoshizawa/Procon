#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"

#include "../library/DataStructure/LazySegmentTree.hpp"
#include "../library/modint.hpp"

struct Monoid{
    modint998 a, b;
    int len;

    Monoid() : a(1), b(0), len(0){}
    Monoid(int a, int b) : a(a), b(b), len(1){}

    static Monoid Merge(Monoid& l, Monoid& r){
        Monoid ret;
        ret.a = l.a * r.a;
        ret.b = r.a * l.b + r.b;
        ret.len = l.len + r.len;
        return ret;
    }
};

struct Operate{
    modint998 c{1}, d{0};

    Operate(){}
    Operate(int c, int d) : c(c), d(d){}

    static Monoid mapping(Monoid& l, Operate& r){
        Monoid ret;
        ret.a = r.c.pow(l.len);
        ret.b = (r.c.pow(l.len) - 1) * r.d / (r.c - 1);
        ret.len = l.len;
        return ret;
    }

    static Operate composite(Operate& l, Operate& r){
        Operate ret;
        ret.c = r.c;
        ret.d = r.d;
        return ret;
    }
};

int main(){
    int N, Q; cin >> N >> Q;
    vector<Monoid> Init;
    for(int i = 0; i < N; ++i){
        int a, b; cin >> a >> b;
        Init.push_back({a, b});
    }
    LazySegmentTree<Monoid, Operate> seg(Init,
        [](Monoid x, Monoid y){return Monoid::Merge(x, y);},
        [](Monoid x, Operate y){return Operate::mapping(x, y);},
        [](Operate x, Operate y){return Operate::composite(x, y);},
        Monoid(), Operate(), true
    );
    while(Q--){
        int q; cin >> q;
        if(q == 0){
            int l, r, c, d; cin >> l >> r >> c >> d;
            seg.update(l, r, Operate(c, d));
        }
        if(q == 1){
            int l, r, x; cin >> l >> r >> x;
            auto f = seg.query(l, r);
            cout << f.a * x + f.b << endl;
        }
    }
}
