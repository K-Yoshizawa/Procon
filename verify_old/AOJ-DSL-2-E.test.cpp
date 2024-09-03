#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include "../library/DataStructure/DualSegmentTree.hpp"

int main(){
    int n, q; cin >> n >> q;
    vector<long long> Init_Data(n, 0);
    DualSegmentTree<long long> seg(Init_Data,
        [&](long long l, long long r){return l + r;},
        0);
    while(q--){
        int query; cin >> query;
        if(query == 0){
            long long s, t, x; cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
        else{
            int i; cin >> i;
            cout << seg[i] << endl;
        }
    }
}