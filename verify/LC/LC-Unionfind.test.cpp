#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "../../library/DataStructure/UnionFind.hpp"

int main(){
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    for(int i = 0; i < Q; ++i){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0){
            uf.unite(u, v);
        }
        else{
            cout << (uf.same(u, v) ? 1 : 0) << endl;
        }
    }
}