/**
 * @file Knapsack01.hpp
 * @author log K (lX57)
 * @brief 0-1 Knapsack - 0-1 ナップザック問題
 * @version 1.0
 * @date 2023-10-30
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
T Knapsack01_NW(const T W, const vector<T> &v, const vector<T> &w){
    assert(v.size() == w.size());
    int N = v.size();
    vector dp(N + 1, vector(W + 1, -1));
    dp[0][0] = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= W; ++j){
            if(dp[i][j] == -1) continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j + w[i] <= W){
                dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
            }
        }
    }
    return *max_element(dp[N].begin(), dp[N].end());
}

template<typename T>
T Knapsack01_NV(const T W, const vector<T> &v, const vector<T> &w){
    assert(v.size() == w.size());
    int N = v.size();
    int V = accumulate(v.begin(), v.end(), 0);
    T INF = numeric_limits<T>::max() / 2;
    vector dp(N + 1, vector(V + 1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= V; ++j){
            if(dp[i][j] == -1) continue;
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if(dp[i][j] + w[i] <= W){
                dp[i + 1][j + v[i]] = min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
            }
        }
    }
    T ret = 0;
    for(int j = 0; j <= V; ++j) if(dp[N][j] != INF) ret = j;
    return ret;
}