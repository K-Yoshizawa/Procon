#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B"

#include "../Library/Template.hpp"
#include "../Library/Tree/RerootingDP.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    RootedTree T(n);
    T.InputGraphFormat(true, false);

    RerootingDP<int, int> dp(
        T,
        [](int l, int r){return max(l, r);},
        [](int l, int r){return l + r;},
        0);
    for(int i = 0; i < n; ++i){
        cout << dp[i] << '\n';
    }
}