#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A"

#include <bits/stdc++.h>

#include "../library/Graph/BipartiteMatching.hpp"

using namespace std;

int main(){
    int X, Y, E;
    cin >> X >> Y >> E;
    BipartiteMatching bm(X, Y);
    for(int i = 0; i < E; ++i){
        int x, y;
        cin >> x >> y;
        bm.add(x, y);
    }

    cout << bm.solve() << endl;
}