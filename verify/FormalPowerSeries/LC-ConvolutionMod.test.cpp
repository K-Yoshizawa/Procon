#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../Library/FormalPowerSeries/FormalPowerSeries.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int N, M; cin >> N >> M;
    FormalPowerSeries A(N), B(M);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    for(int i = 0; i < M; ++i){
        cin >> B[i];
    }

    auto C = A * B;
    for(auto &c : C){
        cout << c << ' ';
    }
    cout << '\n';
}