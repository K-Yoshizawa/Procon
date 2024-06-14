#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../library/DataStructure/LazySegmentTree.hpp"

using ll = int64_t;

struct Monoid{
    ll a{0}, len{0};
    Monoid(){}
    Monoid(ll a) : a(a), len(1){}
    static Monoid merge(Monoid &l, Monoid &r){
        Monoid ret;
        ret.a = l.a + r.a;
        ret.len = l.len + r.len;
        return ret;
    }
};

struct Operate{
    ll x{0};
    Operate(){}
    Operate(ll x) : x(x){}
    static Monoid mapping(Monoid &l, Operate &r){
        Monoid ret;
        ret.a = l.a + l.len * r.x;
        ret.len = l.len;
        return ret;
    }
    static Operate composite(Operate &l, Operate &r){
        Operate ret;
        ret.x = l.x + r.x;
        return ret;
    }
};

int main(){
    int n, q; cin >> n >> q;
    vector<Monoid> Init(n, Monoid(0));
    LazySegmentTree<Monoid, Operate> seg(Init,
        [](Monoid l, Monoid r){return Monoid::merge(l, r);},
        [](Monoid l, Operate r){return Operate::mapping(l, r);},
        [](Operate l, Operate r){return Operate::composite(l, r);},
        Monoid(), Operate()
    );
    while(q--){
        int query; cin >> query;
        if(query == 0){
            int s, t, x; cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
        if(query == 1){
            int s, t; cin >> s >> t;
            cout << seg.query(s, t + 1).a << endl;
        }
    }
}