#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../library/Graph/WarshallFloyd.hpp"

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
    if(wf.negative()){
        cout << "NEGATIVE CYCLE\n";
    }
    else{
        wf.print();
    }
}