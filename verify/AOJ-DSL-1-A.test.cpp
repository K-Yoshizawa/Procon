#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include "../Library/DataStructure/UnionFind.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, q; cin >> n >> q;

    UnionFind uf(n);
    while(q--){
        int com, x, y; cin >> com >> x >> y;
        if(com == 0) uf.Unite(x, y);
        else cout << (uf.Same(x, y) ? 1 : 0) << '\n';
    }
}