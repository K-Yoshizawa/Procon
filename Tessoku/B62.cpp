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

    vector<int> prev(N, -1); prev[0] = -2;
    queue<int> que; que.push(0);
    while(!que.empty()){
        int now = que.front(); que.pop();
        for(int i = 0; i < g[now].size(); ++i){
            int next = g[now][i];
            if(prev[next] != -1) continue;
            prev[next] = now;
            que.push(next);
        }
    }

    vector<int> ans;
    int v = N - 1;
    while(v != -2){
        ans.push_back(v + 1);
        v = prev[v];
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
}