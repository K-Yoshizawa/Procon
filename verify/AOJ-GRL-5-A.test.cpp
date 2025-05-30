#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include "../Library/Tree/TreeDiameter.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    Graph<int> T = InputTree(n, 0, true);

    TreeDiameter td(T);
    cout << td.Diameter() << endl;
}