#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include <bits/stdc++.h>

#include "../../library/Tree/TreeDiamiter.hpp"

int main(){
    int n;
    cin >> n;
    Tree<int> T(n, false, true);
    T.input(n - 1, true, false);

    TreeDiamiter<int> td(T);
    cout << td.diamiter << endl;
}