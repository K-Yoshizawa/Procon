#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../library/Graph/Dijkstra.hpp"

int main(){
    int N, M, s, t; cin >> N >> M >> s >> t;
    GraphV<long long> G(N, true);
    G.input(M, true, true);

    Dijkstra dk(G);
    if(dk.solve(s)[t] == G.INF){
        cout << -1 << endl;
        return 0;
    }
    auto ans = dk.shortest_path(t);
    cout << dk[t] << " " << ans.size() - 1 << endl;
    for(int i = 0; i < ans.size() - 1; ++i){
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
}