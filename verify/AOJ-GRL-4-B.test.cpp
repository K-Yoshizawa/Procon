#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#include "../library/Graph/GraphTemplate.hpp"

int main(){
    int V, E; cin >> V >> E;
    GraphV G(V, true);
    G.input(E, false, true);

    for(auto &v : G.sort()){
        cout << v << endl;
    }
}