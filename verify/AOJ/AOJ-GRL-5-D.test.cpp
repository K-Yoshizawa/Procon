#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include "../../library/Tree/EulerTour.hpp"

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
    EulerTour<long long> et(G);
    int q;
    cin >> q;
    while(q--){
        int com;
        cin >> com;
        if(com == 0){
            long long v, w;
            cin >> v >> w;
            et.add(v, w);
        }
        else{
            int u;
            cin >> u;
            cout << et.query(u) << endl;
        }
    }
}