#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../Library/Tree/TreeDiameter.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    Graph T = InputTree<ll>(n, 0, true);

    TreeDiameter td(T);
    auto us = td.Path();
    ll X = td.Diameter(), Y = us.size();
    cout << X << " " << Y << endl;
    for(auto u : us){
        cout << u << " ";
    }
    cout << '\n';
}