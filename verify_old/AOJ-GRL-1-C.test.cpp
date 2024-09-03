#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../library/Graph/WarshallFloyd.hpp"

int main(){
    int V, E; cin >> V >> E;
    Graph<int64_t> G(V, true);
    G.input(E, true, false);
    
    WarshallFloyd wf(G);
    wf.print();
}