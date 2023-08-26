#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../../library/DataStructure/SegmentTree.hpp"

int main(){
    int N, Q;
    cin >> N >> Q;
    SegmentTree<long long> seg(N, [](auto x, auto y){return x + y;}, 0LL);
    for(int i = 1; i <= N; ++i){
        long long a;
        cin >> a;
        seg.set(i, a);
    }
    seg.build();
    for(int i = 0; i < Q; ++i){
        int q;
        cin >> q;
        if(q == 0){
            int p, x;
            cin >> p >> x;
            seg.update(p + 1, seg.get(p + 1) + x);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << seg.query(l + 1, r + 1) << endl;
        }
    }
}