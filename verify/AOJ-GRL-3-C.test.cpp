#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include <bits/stdc++.h>

#include "../library/Graph/VGraph.hpp"
#include "../library/Graph/StronglyConnectedComponents.hpp"

using namespace std;

int main(){
    int V, E;
    cin >> V >> E;
    VGraph<int> G(V, true);
    for(int i = 0; i < E; ++i){
        int s, t;
        cin >> s >> t;
        G.add(s, t);
    }
    
    StronglyConnectedComponents<int> scc(G);

    int Q;
    cin >> Q;
    while(Q--){
        int u, v;
        cin >> u >> v;
        cout << scc.same(u, v) << endl;
    }
}