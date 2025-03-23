#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../Library/Template.hpp"
#include "../Library/Graph/StronglyConnectedComponents.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, M; cin >> N >> M;
    auto G = InputGraph(N, M, 0, false, true);
    
    StronglyConnectedComponents scc(G);
    cout << scc.ComponentCount() << '\n';
    for(const auto &vs : scc.Components()){
        cout << vs.size();
        for(const auto &v : vs){
            cout << ' ' << v;
        }
        cout << '\n';
    }
}