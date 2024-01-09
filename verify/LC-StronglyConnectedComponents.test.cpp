#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../library/Graph/StronglyConnectedComponents.hpp"

int main(){
    int N, M; cin >> N >> M;
    GraphV G(N, true);
    G.input(M, false, true);

    StronglyConnectedComponents scc(G);
    auto ans = scc.get();
    cout << ans.size() << endl;
    for(auto &vs : ans){
        cout << vs.size();
        for(auto &v : vs){
            cout << " " << v;
        }
        cout << endl;
    }
}