#include <bits/stdc++.h>
using namespace std;

using edge = pair<int, long long>; // (頂点番号, 距離)
using weighted_graph = vector<vector<edge>>;
using unweighted_graph = vector<vector<int>>;
using rpq = priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>;

int main(){
    int N, M; cin >> N >> M;
    weighted_graph g(N);
    for(int i = 0; i < M; ++i){
        int A, B, C; cin >> A >> B >> C;
        --A, --B;
        g[A].push_back(edge(B, C));
        g[B].push_back(edge(A, C));
    }

    const long long INF = LLONG_MAX / 2LL;
    vector<long long> ans(N, INF); ans[0] = 0;
    rpq que; que.emplace(0LL, 0);
    while(!que.empty()){
        auto info = que.top(); que.pop();
        long long dist = info.first; int now = info.second;
        if(ans[now] != dist) continue;
        for(auto &e : g[now]){
            int next = e.first; long long nd = e.second;
            if(dist + nd < ans[next]){
                ans[next] = dist + nd;
                que.emplace(dist + nd, next);
            }
        }
    }

    for(auto &v : ans){
        if(v != INF) cout << v << endl;
        else cout << -1 << endl;
    }
}