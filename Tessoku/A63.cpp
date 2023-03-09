#include <bits/stdc++.h>
using namespace std;

using unweighted_graph = vector<vector<int>>;

int main(){
    int N, M; cin >> N >> M;
    unweighted_graph g(N);
    for(int i = 0; i < M; ++i){
        int A, B; cin >> A >> B;
        --A, --B;
        g[A].push_back(B);
        g[B].push_back(A);
    }

    int INF = 100100;
    vector<int> ans(N, INF); ans[0] = 0;
    queue<int> que; que.push(0);
    while(!que.empty()){
        int now = que.front(); que.pop();
        int d = ans[now];
        for(auto next : g[now]){
            if(d + 1 < ans[next]){
                que.push(next);
                ans[next] = d + 1;
            }
        }
    }

    for(auto dist : ans){
        if(dist == INF) cout << -1 << endl;
        else cout << dist << endl;
    }
}