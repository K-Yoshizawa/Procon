#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/WeightedUnionFind.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, q; cin >> n >> q;

    WeightedUnionFind<ll> uf(n);
    while(q--){
        int query; cin >> query;
        if(query == 0){
            int x, y, z; cin >> x >> y >> z;
            uf.Unite(x, y, z);
        }
        else{
            int x, y; cin >> x >> y;
            if(!uf.Same(x, y)) cout << "?" << '\n';
            else cout << uf.Diff(x, y) << '\n';
        }
    }
}