#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include "../Library/Template.hpp"
#include "../Library/Tree/TreeDiameter.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    RootedTree T(n);
    T.InputGraphFormat(true, false);

    TreeDiameter td(T);
    cout << td.get_diameter() << '\n';
}