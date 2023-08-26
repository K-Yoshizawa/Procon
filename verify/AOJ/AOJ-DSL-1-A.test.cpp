#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include <bits/stdc++.h>

#include "../../library/DataStructure/UnionFind.hpp"

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    while(q--){
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0) uf.unite(x, y);
        else cout << uf.same(x, y) << endl;
    }
}