#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A"

#include <bits/stdc++.h>
using namespace std;

#include "../library/Graph/CycleDetection.hpp"

int main(){
    int V, E;
    cin >> V >> E;
    Graph<int> G(V, true);
    for(int i = 0; i < E; ++i){
        int s, t;
        cin >> s >> t;
        G.add(s, t);
    }

    CycleDetection<int> cd(G);
    cout << cd.exist() << endl;
}