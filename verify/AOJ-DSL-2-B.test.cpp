#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/SegmentTree.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, q; cin >> n >> q;

    vector<int> a(n, 0);
    SegmentTree<int> seg(a, [](int l, int r){return l + r;}, 0, false);
    seg.Build();
    while(q--){
        int com, x, y; cin >> com >> x >> y;
        if(com == 0){
            seg.Apply(x, seg[x] + y);
        }
        else{
            cout << seg.Fold(x, y + 1) << '\n';
        }
    }
}