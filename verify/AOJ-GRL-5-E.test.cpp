#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include "../library/Tree/HeavyLightDecomposition.hpp"

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

    auto relation = G.get_parent(0);

    int q;
    cin >> q;
    while(q--){
        int query;
        cin >> query;
        if(query == 0){
            int v, w;
            cin >> v >> w;
            HLD.add(v, w);
        }
        else{
            int u;
            cin >> u;
            cout << HLD.query(u) << endl;
        }
    }
}