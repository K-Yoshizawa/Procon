#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../library/Graph/StronglyConnectedComponents.hpp"

int main(){
    int N, M; cin >> N >> M;
    Graph G(N, true);
    for(int i = 0; i < M; ++i){
        int a, b; cin >> a >> b;
        G.add_edge(a, b);
    }

    StronglyConnectedComponents scc(G);
    auto ans = scc.get_components();
    cout << ans.size() << endl;
    for(auto &vs : ans){
        cout << vs.size();
        for(auto &v : vs){
            cout << " " << v;
        }
        cout << endl;
    }
}