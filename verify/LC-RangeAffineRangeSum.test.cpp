#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../library/DataStructure/LazySegmentTree.hpp"
#include "../library/modint.hpp"

struct Data{
    modint998 val;
    int len;

    Data() : val(0), len(1){}
    Data(int val, int len) : val(val), len(len){}

    static Data Merge(const Data& left, const Data& right){
        Data res;
        res.val = left.val + right.val;
        res.len = left.len + right.len;
        return res;
    }
};

struct Oper{
    modint998 b{1}, c{0};

    Oper(){}
    Oper(int b, int c) : b(b), c(c){}

    static Data mapping(const Data& left, const Oper& right){
        Data res;
        res.val = left.val * right.b + right.c * left.len;
        res.len = left.len;
        return res;
    }

    static Oper composite(const Oper& left, const Oper& right){
        Oper res;
        res.b = left.b * right.b;
        res.c = right.b * left.c + right.c;
        return res;
    }
};

int main(){
    int N, Q; cin >> N >> Q;
    vector<Data> Init_Data;
    for(int i = 0; i < N; ++i){
        int a; cin >> a;
        Init_Data.push_back({a, 1});
    }
    LazySegmentTree<Data, Oper> seg(Init_Data,
        [](Data x, Data y){return Data::Merge(x, y);},
        [](Data x, Oper y){return Oper::mapping(x, y);},
        [](Oper x, Oper y){return Oper::composite(x, y);},
        Data(), Oper(), true
    );
    while(Q--){
        int q; cin >> q;
        if(q == 0){
            int l, r, b, c; cin >> l >> r >> b >> c;
            seg.update(l, r, Oper(b, c));
        }
        if(q == 1){
            int l, r; cin >> l >> r;
            cout << seg.query(l, r).val << endl;
        }
    }
}
