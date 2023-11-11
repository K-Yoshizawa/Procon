#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../library/DataStructure/UnionFind.hpp"

int main(){
    int N, Q; cin >> N >> Q;

    UnionFind uf(N);
    while(Q--){
        int t, u, v; cin >> t >> u >> v;
        if(t == 0) uf.unite(u, v);
        else cout << uf.same(u, v) << endl;
    }
}