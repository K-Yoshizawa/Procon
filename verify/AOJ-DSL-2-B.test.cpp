#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../library/DataStructure/BinaryIndexedTree.hpp"

int main(){
    int n, q; cin >> n >> q;
    vector<long long> Init_Data(n, 0);
    BinaryIndexedTree<long long> BIT(n);
    while(q--){
        int com, x, y; cin >> com >> x >> y;
        if(com == 0){
            BIT.add(x, y);
        }
        if(com == 1){
            cout << BIT.query(x, y) << endl;
        }
    }
}