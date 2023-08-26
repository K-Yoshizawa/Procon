#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../library/DataStructure/SegmentTree.hpp"

int main(){
    int n, q;
    cin >> n >> q;

    SegmentTree<int> RMQ(n, SEG_MIN<int>, numeric_limits<int>::max());
    RMQ.build();
    while(q--){
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0){
            RMQ.update(x, y);
        }
        else{
            cout << RMQ.query(x, y + 1) << endl;
        }
    }
}