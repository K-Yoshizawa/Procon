#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../library/DataStructure/SegmentTree.hpp"

int main(){
    int n, q; cin >> n >> q;
    long long INF = (1LL << 31) - 1;
    vector<long long> Init_Data(n, INF);
    SegmentTree<long long> seg = logk::SegmentTreeRMQ(Init_Data, INF, true);
    while(q--){
        int com, x, y; cin >> com >> x >> y;
        if(com == 0){
            seg.update(x, y);
        }
        if(com == 1){
            cout << seg.query(x, y + 1) << endl;
        }
    }
}