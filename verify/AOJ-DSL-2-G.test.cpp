#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/LazySegmentTree.hpp"

using OperatorMonoid = int;

struct Monoid{
    long long val, len;

    Monoid(long long v = 0) : val(v), len(1){}
    Monoid(long long v, long long l) : val(v), len(l){}

    static Monoid Merge(const Monoid &l, const Monoid &r){
        return Monoid(l.val + r.val, l.len + r.len);
    }

    static Monoid Mapping(const Monoid &m, const OperatorMonoid o){
        return Monoid(m.val + o * m.len, m.len);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, q; cin >> n >> q;

    vector<Monoid> a(n, Monoid());
    LazySegmentTree<Monoid, OperatorMonoid> seg(
        a,
        [&](Monoid l, Monoid r){return Monoid::Merge(l, r);},
        [&](Monoid m, OperatorMonoid o){return Monoid::Mapping(m, o);},
        [&](OperatorMonoid l, OperatorMonoid r){return l + r;},
        Monoid(),
        0
    );
    while(q--){
        int com, s, t, x; cin >> com >> s >> t;
        if(com == 0){
            cin >> x;
            seg.Apply(s, t + 1, x);
        }
        else{
            cout << seg.Fold(s, t + 1).val << '\n';
        }
    }
}