#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../latest/Graph/BipartiteMatching.hpp"

int main(){
    int L, R, M;
    cin >> L >> R >> M;
    BipartiteMatching bm(L, R);
    for(int i = 0; i < M; ++i){
        int a, b; cin >> a >> b;
        bm.add(a, b);
    }

    int K = bm.solve();
    cout << K << endl;
    for(auto [c, d] : bm.get_matching()){
        cout << c << " " << d << endl;
    }
}