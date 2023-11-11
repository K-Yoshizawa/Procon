#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include "../library/DataStructure/UnionFind.hpp"

int main(){
    int n, q; cin >> n >> q;

    UnionFind<long long> uf(n);
    while(q--){
        int query; cin >> query;
        if(query == 0){
            int x, y, z; cin >> x >> y >> z;
            uf.unite(x, y, z);
        }
        else{
            int x, y; cin >> x >> y;
            if(!uf.same(x, y)) cout << "?" << endl;
            else cout << uf.diff(x, y) << endl;
        }
    }
}