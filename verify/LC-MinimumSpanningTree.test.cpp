#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

#include "../Library/Template.hpp"
#include "../Library/Graph/Kruskal.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, M; cin >> N >> M;
    auto G = InputGraph<ll>(N, M, 0, true, false);

    Kruskal kr(G);
    cout << kr.GetCost() << '\n';
    for(auto e : kr.GetEdgeSet()){
        cout << e.idx << ' ';
    }
    cout << '\n';
}