#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include "../library/DataStructure/LazySegmentTree.hpp"

int main(){
    int n, q;
    cin >> n >> q;
    LazySegmentTree<int> lst(n, [](int a, int b){return min(a, b);},
                                [](int a, int b){return a + b;},
                                [](int a, int b){return a + b;},
                                numeric_limits<int>::max(), 0);
    for(int i = 0; i < n; ++i) lst.set(i, 0);
    lst.build();
    while(q--){
        int query;
        cin >> query;
        if(query == 0){
            int s, t, x;
            cin >> s >> t >> x;
            lst.update(s, t + 1, x);
        }
        else{
            int s, t;
            cin >> s >> t;
            cout << lst.query(s, t + 1) << endl;
        }
    }
}