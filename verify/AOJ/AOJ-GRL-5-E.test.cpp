#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"
#define IGNORE

#include "../../library/DataStructure/BinaryIndexedTreeDouble.hpp"
#include "../../library/Tree/HeavyLightDecomposition.hpp"

int main(){
    int n;
    cin >> n;
    Graph<long long> G(n);
    for(int i = 0; i < n; ++i){
        int k;
        cin >> k;
        for(int j = 0; j < k; ++j){
            int c;
            cin >> c;
            G.add(i, c, 0);
        }
    }

    HeavyLightDecompsition<long long> HLD(G);
    BinaryIndexedTreeDouble<long long> BIT(n);

    auto relation = G.get_parent(0);

    int q;
    cin >> q;
    while(q--){
        int query;
        cin >> query;
        if(query == 0){
            int v, w;
            cin >> v >> w;
            auto seg = HLD.get_segment(v);
            for(auto &[s, t] : seg){
                BIT.add(s, t, w);
            }
            BIT.add(1, 2, -1);
        }
        else{
            int u;
            cin >> u;
            auto seg = HLD.get_segment(u);
            long long ans = 0;
            for(auto &[s, t] : seg){
                ans += BIT.query(s, t);
            }
            cout << ans << endl;
        }
    }
}