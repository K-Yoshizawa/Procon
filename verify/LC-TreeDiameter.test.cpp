#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../Library/Template.hpp"
#include "../Library/Tree/TreeDiameter.hpp"

int main(){
    int n; cin >> n;
    RootedTree<ll> T(n);
    T.InputGraphFormat(true, false);

    TreeDiameter td(T);
    auto us = td.get_diameter_path();
    ll X = td.get_diameter(), Y = us.size();
    cout << X << " " << Y << endl;
    for(auto u : us){
        cout << u << " ";
    }
    cout << endl;
}