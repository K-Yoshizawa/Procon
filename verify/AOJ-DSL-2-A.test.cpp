#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/SegmentTree.hpp"

int main(){
    int n, q; cin >> n >> q;

    int inf = (1LL << 31) - 1;
    SegmentTree<int> seg(n, [](int l, int r){return min(l, r);}, inf, true);
    seg.Build();
    while(q--){
        int com, x, y; cin >> com >> x >> y;
        if(com == 0){
            seg.Set(x, y);
        }
        else{
            cout << seg.Prod(x, y + 1) << endl;
        }
    }
}