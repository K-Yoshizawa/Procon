#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include "../old/Tree/EulerTour.hpp"
#include "../library/DataStructure/SegmentTree.hpp"

int main(){
    int n; cin >> n;
    Graph<int> G(n);
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int c; cin >> c;
            G.add(i, c, 0);
        }
    }
    EulerTour<int> et(G, 0);
    vector<long long> Init_Data(2 * n, 0);
    SegmentTree<long long> seg(Init_Data,
        [](int l, int r){return l + r;},
        0, false);
    
    int q; cin >> q;
    while(q--){
        int query; cin >> query;
        if(query == 0){
            int v, w; cin >> v >> w;
            auto [in, out] = et[v];
            seg.update(in, seg.get(in) + w);
            seg.update(out, seg.get(out) - w);
        }
        else{
            int u; cin >> u;
            cout << seg.query(1, et.in(u) + 1) << endl;
        }
    }
}