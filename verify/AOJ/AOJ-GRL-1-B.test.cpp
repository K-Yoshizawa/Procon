#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include <bits/stdc++.h>

#include "../../library/Graph/BellmanFord.hpp"

using namespace std;

int main(){
    int V, E, r;
    cin >> V >> E >> r;
    Graph<int> G(V, true);
    for(int i = 0; i < E; ++i){
        int s, t, d;
        cin >> s >> t >> d;
        G.add(s, t, d);
    }

    auto ans = BellmanFord(G, r);
    if(ans[r] == -1){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        for(auto &d : ans){
            if(d == G.INF){
                cout << "INF" <<endl;
            }
            else{
                cout << d << endl;
            }
        }
    }
}