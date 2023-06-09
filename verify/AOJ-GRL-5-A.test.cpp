#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include <bits/stdc++.h>

#include "../library/Tree/TreeDiamiter.hpp"

int main(){
    int n;
    cin >> n;
    Graph<int> G(n);
    for(int i = 0; i < n - 1; ++i){
        int s, t, w;
        cin >> s >> t >> w;
        G.add(s, t, w);
    }

    TreeDiamiter<int> td(G);
    cout << td.diamiter << endl;
}