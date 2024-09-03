#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include "../library/Graph/BellmanFord.hpp"

using namespace std;

int main(){
    int V, E, r; cin >> V >> E >> r;
    Graph G(V, true);
    G.input(E, true, false);
    
    BellmanFord bf(G, r);
    bf.print('\n');
}