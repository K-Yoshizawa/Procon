#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include "../icpc/BellmanFord.hpp"

int main(){
    int V, E, r; cin >> V >> E >> r;
    ES ed;
    for(int i = 0; i < E; ++i){
        int s, t, d; cin >> s >> t >> d;
        ed.push_back({s, t, d});
    }

    auto dist = bellmanford(ed, r, V);
    if(dist.empty()) cout << "NEGATIVE CYCLE" << endl;
    else{
        for(auto d : dist){
            (d == INF ? cout << "INF" << endl : cout << d << endl);
        }
    }
}