#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../../library/DataStructure/BinaryIndexedTree.hpp"

int main(){
    int N, Q;
    cin >> N >> Q;
    BinaryIndexedTree<long long> bit(N);
    for(int i = 1; i <= N; ++i){
        long long a;
        cin >> a;
        bit.add(i, a);
    }
    for(int i = 0; i < Q; ++i){
        int q;
        cin >> q;
        if(q == 0){
            int p, x;
            cin >> p >> x;
            bit.add(p + 1, x);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << bit.query(l, r) << endl;
        }
    }
}