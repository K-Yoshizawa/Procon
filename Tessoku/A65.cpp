#include <bits/stdc++.h>
using namespace std;

using edge = pair<int, long long>; // (頂点番号, 距離)
using weighted_graph = vector<vector<edge>>;
using unweighted_graph = vector<vector<int>>;
using rpq = priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>;

int main(){
    int N; cin >> N;
    unweighted_graph g(N);
    vector<int> in(N, 0);
    for(int i = 0; i < N - 1; ++i){
        int A; cin >> A; --A;
        g[i].push_back(A);
        ++in[A];
    }

    vector<int> ans(N, 0);
    vector<bool> check(N, false);
    int remain = N;
    while(remain > 0){
        int v = 0;
        while(in[v] != 0 || check[v]) ++v;
        ans[g[v][0]] += ans[v] + 1;
        --in[g[v][0]];
        check[v] = true;
        --remain;
    }

    for(auto &v : ans){
        cout << v << " ";
    }
}