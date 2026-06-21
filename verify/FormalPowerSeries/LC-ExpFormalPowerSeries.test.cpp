#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../Library/FormalPowerSeries/FormalPowerSeries.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int N; cin >> N;
    FormalPowerSeries A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    auto B = A.Exp();
    for(auto &b : B){
        cout << b << ' ';
    }
    cout << '\n';
}