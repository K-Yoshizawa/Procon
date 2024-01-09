#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include "../old/Graph/PrimalDual.hpp"

int main(){
    int V, E, F;
    cin >> V >> E >> F;
    Flow<int> G(V);
    for(int i = 0; i < E; ++i){
        Vertex u, v;
        int c, d;
        cin >> u >> v >> c >> d;
        G.add(u, v, c, d);
    }

    PrimalDual<int> pd(G);

    cout << pd.solve(0, V - 1, F) << endl;
}