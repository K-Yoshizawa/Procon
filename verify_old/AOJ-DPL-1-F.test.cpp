#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_F"

#include "../library/DynamicPrograming/Knapsack01.hpp"

int main(){
    long long N, W; cin >> N >> W;
    vector<long long> v(N), w(N);
    for(int i = 0; i < N; ++i) cin >> v[i] >> w[i];

    cout << Knapsack01_NV(W, v, w) << endl;
}