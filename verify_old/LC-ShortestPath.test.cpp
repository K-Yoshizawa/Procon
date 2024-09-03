#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../library/Graph/Dijkstra.hpp"

int main(){
    int N, M, s, t; cin >> N >> M >> s >> t;
    Graph<int64_t> G(N, true);
    G.input(M, true, false);

    Dijkstra dk(G);
    if(dk.reachable(s, t)){
        auto route = dk.restore(s, t);
        cout << dk[t] << " " << route.size() - 1 << endl;
        for(int i = 0; i < route.size() - 1; ++i){
            cout << route[i] << " " << route[i + 1] << endl;
        }
    }
    else{
        cout << -1 << endl;
    }
}