#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include <bits/stdc++.h>

#include "../library/Graph/Dijkstra.hpp"

using namespace std;

int main(){
    int V, E, r;
    cin >> V >> E >> r;
    Graph<long long> G(V, true);
    for(int i = 0; i < E; ++i){
        int s, t;
        long long d;
        cin >> s >> t >> d;
        G.add(s, t, d);
    }

    Dijkstra<long long> ds(G);
    ds.build(r);
    for(int i = 0; i < V; ++i){
        if(ds.dist[i] == ds.INF){
            cout << "INF" << endl;
        }
        else{
            cout << ds.dist[i] << endl;
        }
    }
}