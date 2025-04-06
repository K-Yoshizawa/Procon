#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../Library/Template.hpp"
#include "../Library/Graph/Dijkstra.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, M, s, t; cin >> N >> M >> s >> t;
    auto G = InputGraph<ll>(N, M, 0, true, true);

    Dijkstra<ll> dk(G, s);
    if(!dk.Reachable(t)){
        cout << -1 << '\n';
    }
    else{
        auto p = dk.Path(t);
        cout << dk[t] << ' ' << p.size() << '\n';
        for(auto e : p){
            cout << e.from << ' ' << e.to << '\n';
        }
    }
}