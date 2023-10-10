#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"

#include "../library/DataStructure/LazySegmentTree.hpp"

int main(){
    int n, q; cin >> n >> q;
    long long INF = (1LL << 31) - 1;
    vector<long long> Init_Data(n, INF);
    LazySegmentTree<long long> seg(Init_Data,
        [](long long x, long long y){
            return min(x, y);
        },
        [](long long x, long long y){
            return y;
        },
        [](long long x, long long y){
            return y;
        },
        INF, INF, true
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