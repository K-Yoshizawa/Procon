#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../library/Tree/TreeDiameter.hpp"

using ll = long long;

int main(){
    int N; cin >> N;
    Graph<ll> G(N);
    for(int i = 0; i < N - 1; ++i){
        int a, b, c; cin >> a >> b >> c;
        G.add(a, b, c);
    }

    TreeDiameter td(G);
    ll X = td.dist();
    auto u = td.path();
    ll Y = u.size();
    cout << X << " " << Y << endl;
    for(auto &v : u){
        cout << v << " ";
    }
    cout << endl;
}