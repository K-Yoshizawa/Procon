#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"

#include "../latest/DataStructure/LazySegmentTree.hpp"

long long INF = 1e12;

struct Data{
    long long val{0};
    long long len{1};

    Data() : val(0), len(1){}
    Data(int val, int len) : val(val), len(len){}

    bool operator==(const Data& y){
        return val == y.val && len == y.len;
    }
    
    friend ostream &operator<<(ostream &os, const Data &p) {
        return os << "{" << p.val << ", " << p.len << "}";
    }

    static Data Merge(const Data& x, const Data& y){
        Data ret;
        ret.val = x.val + y.val;
        ret.len = x.len + y.len;
        return ret;
    }

    static Data Mapping(const Data& x, const int y){
        Data ret;
        if(y != INF) ret.val = y * x.len;
        ret.len = x.len;
        return ret;
    }
};

int main(){
    int n, q; cin >> n >> q;
    vector<Data> Init_Data(n, Data(0, 1));
    LazySegmentTree<Data, long long> seg(Init_Data,
        [](const Data l, const Data r){return Data::Merge(l, r);},
        [](const Data l, const long long r){return Data::Mapping(l, r);},
        [](const long long l, const long long r){return r;},
        Data(), INF, true
    );
    while(q--){
        int query; cin >> query;
        if(query == 0){
            int s, t, x; cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
        if(query == 1){
            int s, t; cin >> s >> t;
            cout << seg.query(s, t + 1).val << endl;
        }
    }
}