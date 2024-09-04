#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include "../Library/modint.hpp"
#include "../Library/DataStructure/WeightedUnionFind.hpp"

int main(){
    int N, Q; cin >> N >> Q;

    WeightedUnionFind<mint> uf(N);
    while(Q--){
        int t, u, v; cin >> t >> u >> v;
        if(t == 0){
            int x; cin >> x;
            if(uf.Same(u, v)){
                cout << (uf.Diff(v, u) == x) << endl;
            }
            else{
                cout << uf.Relate(v, u, x) << endl;
            }
        }
        else{
            if(uf.Same(u, v)){
                cout << uf.Diff(v, u) << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }
}