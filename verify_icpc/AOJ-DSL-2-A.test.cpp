#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../icpc/SegmentTree.hpp"

int main(){
    int n, q; cin >> n >> q;
    long long INF = (1LL << 31) - 1;
    vector<long long> Init_Data(n, INF);
    segtree seg(Init_Data);
    while(q--){
        int com, x, y; cin >> com >> x >> y;
        if(com == 0){
            ++x;
            seg.update(x, y);
        }
        if(com == 1){
            ++x, ++y;
            cout << seg.query(x, y + 1) << endl;
        }
    }
}