#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../library/DataStructure/SegmentTree.hpp"

int main(){
    int n, q; cin >> n >> q;
    vector<long long> Init_Data(n, 0);
    SegmentTree<long long> seg(Init_Data,[](long long a, long long b){return a + b;}, 0);
    while(q--){
        int com, x, y; cin >> com >> x >> y;
        if(com == 0){
            seg.update(x, seg.get(x) + y);
        }
        if(com == 1){
            cout << seg.query(x, y + 1) << endl;
        }
    }
}