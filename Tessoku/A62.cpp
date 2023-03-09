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

    vector<int> visited(N, 0); visited[0] = 1;
    queue<int> que; que.push(0);
    while(!que.empty()){
        int now = que.front(); que.pop();
        for(int i = 0; i < g[now].size(); ++i){
            int next = g[now][i];
            if(visited[next]) continue;
            visited[next] = 1;
            que.push(next);
        }
    }

    if(accumulate(visited.begin(), visited.end(), 0) == N){
        cout << "The graph is connected." << endl;
    }
    else{
        cout << "The graph is not connected." << endl;
    }
}