#include <bits/stdc++.h>
using namespace std;

using unweighted_graph = vector<vector<int>>;

int main(){
    int N, M; cin >> N >> M;
    unweighted_graph g(N);
    for(int i = 0; i < M; ++i){
        int A, B; cin >> A >> B;
        g[A - 1].push_back(B);
        g[B - 1].push_back(A);
    }

    int ans = 0, friends = 0;
    for(int i = 0; i < N; ++i){
        if(friends < g[i].size()){
            friends = g[i].size();
            ans = i + 1;
        }
    }
    cout << ans << endl;
}