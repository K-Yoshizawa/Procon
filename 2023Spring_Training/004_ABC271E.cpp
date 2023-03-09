#include <bits/stdc++.h>
using namespace std;

/**
 *  Problem : ABC271E - Subsequence Path
 *  Date    : 2023 / 02 / 08
 *  Solve   : Editorial
 */

using ll = long long int;
ll INF = LLONG_MAX / 2;

struct edge{
    int A, B;
    ll C;
};

int main(){
    int N, M, K; cin >> N >> M >> K;
    vector<edge> r(M + 1);
    for(int i = 1; i <= M; ++i){
        cin >> r[i].A >> r[i].B >> r[i].C;
    }
    vector<int> E(K);
    for(int i = 0; i < K; ++i){
        cin >> E[i];
    }

    vector<ll> dp(N + 1, INF);
    dp[1] = 0;
    for(int i = 0; i < K; ++i){
        dp[r[E[i]].B] = min(dp[r[E[i]].A] + r[E[i]].C, dp[r[E[i]].B]);
        /*
        fprintf(stderr, "E_i = %d : ", E[i]);
        for(int j = 1; j <= N; ++j){
            fprintf(stderr, "%lld ", dp[j]);
        }
        fprintf(stderr, "\n");
        */
    }
    if(dp[N] == INF) cout << -1 << endl;
    else cout << dp[N] << endl;
}