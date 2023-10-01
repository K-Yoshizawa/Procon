#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../latest/DataStructure/SegmentTree.hpp"
#include "../library/modint.hpp"

struct Data{
    modint998 a, b;

    Data() : a(1), b(0){}
    Data(int a, int b) : a(a), b(b){} 

    static Data op(const Data& left, const Data& right){
        Data res;
        res.a = left.a * right.a;
        res.b = right.a * left.b + right.b;
        return res;
    }
};

int main(){
    int N, Q; cin >> N >> Q;
    vector<Data> Init_Data;
    for(int i = 0; i < N; ++i){
        int a, b; cin >> a >> b;
        Init_Data.push_back(Data(a, b));
    }
    SegmentTree<Data> seg(Init_Data, [](Data l, Data r){return Data::op(l, r);}, Data(), true);
    while(Q--){
        int q; cin >> q;
        if(q == 0){
            int p, c, d; cin >> p >> c >> d;
            seg.update(p, Data(c, d));
        }
        if(q == 1){
            int l, r, x; cin >> l >> r >> x;
            Data ret = seg.query(l, r);
            cout << ret.a * x + ret.b << endl;
        }
    }
}
