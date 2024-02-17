#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

#include "../library/Graph/Kruskal.hpp"

int main(){
    int N, M; cin >> N >> M;
    Graph<long long> G(N);
    G.input(M, true, true);

    Kruskal kr(G);
    auto ans = kr.get();
    cout << kr.val() << endl;
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;
}