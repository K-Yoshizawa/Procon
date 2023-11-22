#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../icpc/LazySegmentTree.hpp"

int main(){
    int n, q; cin >> n >> q;
    long long INF = (1LL << 31) - 1;
    vector<long long> Init_Data(n, INF);
    segtree seg(Init_Data);
    while(q--){
        int com; cin >> com;
        if(com == 0){
            int s, t, x; cin >> s >> t >> x, ++s, ++t;
            seg.update(s, t + 1, x);
        }
        if(com == 1){
            int s, t; cin >> s >> t, ++s, ++t;
            cout << seg.query(s, t + 1) << endl;
        }
    }
}