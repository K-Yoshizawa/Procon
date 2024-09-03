#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../library/Tree/TreeDiameter.hpp"

int main(){
    int N; cin >> N;
    Tree<int64_t> T(N);
    T.input(true, false);

    TreeDiameter td(T);
    auto ans = td.get_path();
    cout << td.get_cost() << " " << ans.size() << endl;
    for(auto v : ans){
        cout << v << " ";
    }
    cout << endl;
}