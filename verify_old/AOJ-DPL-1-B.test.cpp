#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B"

#include "../library/DynamicPrograming/Knapsack01.hpp"

int main(){
    int N, W; cin >> N >> W;
    vector<int> v(N), w(N);
    for(int i = 0; i < N; ++i) cin >> v[i] >> w[i];

    cout << Knapsack01_NW(W, v, w) << endl;
}