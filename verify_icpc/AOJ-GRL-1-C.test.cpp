#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../icpc/WarshallFloyd.hpp"

int main(){
    int V, E; cin >> V >> E;
    vvl g(V, vl(V, INF));
    for(int i = 0; i < E; ++i){
        int s, t, d; cin >> s >> t >> d;
        g[s][t] = d;
    }

    if(warshallfloyd(g)){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        for(auto i : g){
            (i[0] == INF ? cout << "INF" : cout << i[0]);
            for(int j = 1; j < V; ++j){
                cout << " ";
                (i[j] == INF ? cout << "INF" : cout << i[j]);
            }
            cout << endl;
        }
    }
}