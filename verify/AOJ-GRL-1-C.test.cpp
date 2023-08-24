#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include <bits/stdc++.h>

#include "../library/Graph/WarshallFloyd.hpp"

using namespace std;

int main(){
    int V, E;
    cin >> V >> E;
    Graph<long long> G(V, true);
    for(int i = 0; i < E; ++i){
        int s, t, d;
        cin >> s >> t >> d;
        G.add(s, t, d);
    }

    WarshallFloyd<long long> wf(G);
    if(wf.negative){
        cout << "NEGATIVE CYCLE\n";
    }
    else{
        for(auto &i : wf.dist){
            for(int j = 0; j < i.size(); ++j){
                if(i[j] == G.INF) cout << "INF";
                else cout << i[j];
                if(j != i.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }
}