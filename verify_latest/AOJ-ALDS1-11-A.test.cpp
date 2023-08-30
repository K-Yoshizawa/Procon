#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_A"

#include "../latest/Graph/GraphTemplate.hpp"

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    Graph<int> G(n, true);
    for(int i = 0; i < n; ++i){
        Vertex u; int k; cin >> u >> k, --u;
        for(int j = 0; j < k; ++j){
            Vertex v; cin >> v, --v;
            G.add(u, v);
        }
    }
    G.print_matrix(0, false);
}