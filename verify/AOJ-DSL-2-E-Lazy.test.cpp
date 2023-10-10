#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include "../library/DataStructure/LazySegmentTree.hpp"

int main(){
    int n, q; cin >> n >> q;
    vector<long long> Init_Data(n, 0);
    LazySegmentTree<long long> seg(Init_Data,
        [](const long long l, const long long r){return min(l, r);},
        [](const long long l, const int r){return l + r;},
        [](const int l, const int r){return l + r;},
        1e12, 0, false
    );
    while(q--){
        int query; cin >> query;
        if(query == 0){
            int s, t, x; cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
        if(query == 1){
            int i; cin >> i;
            cout << seg.query(i, i + 1) << endl;
        }
    }
}