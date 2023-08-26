#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../library/DataStructure/BinaryIndexedTreeDouble.hpp"

int main(){
    int n, q;
    cin >> n >> q;
    BinaryIndexedTreeDouble<long long> bit(n);
    while(q--){
        int query;
        cin >> query;
        if(query == 0){
            int s, t, x;
            cin >> s >> t >> x;
            bit.add(s, t + 1, x);
        }
        else{
            int s, t;
            cin >> s >> t;
            cout << bit.query(s, t + 1) << endl;
        }
    }
}